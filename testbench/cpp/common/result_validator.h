// ====================================================================
// MAZE Network Node - Result Validation Logic
// ====================================================================
//
// Comprehensive validation framework for MAZE network node test results
// Includes pass/fail criteria, assertion checking, and detailed analysis
//
// ====================================================================

#ifndef RESULT_VALIDATOR_H
#define RESULT_VALIDATOR_H

#include "packet_generator.h"
#include "test_utils.h"
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <functional>

// ====================================================================
// Validation Result Structure
// ====================================================================
struct ValidationResult {
    bool passed;
    string test_name;
    string description;
    string error_message;
    vector<string> warnings;
    map<string, uint64_t> metrics;
    uint64_t validation_time_ms;

    ValidationResult(const string& name) : passed(false), test_name(name), validation_time_ms(0) {}
};

// ====================================================================
// Packet Tracking Structure
// ====================================================================
struct PacketTracker {
    MazePacket original_packet;
    uint64_t inject_cycle;
    uint64_t receive_cycle;
    string inject_interface;
    string receive_interface;
    bool received;
    bool corrupted;
    string error_details;

    PacketTracker(const MazePacket& pkt, uint64_t cycle, const string& interface)
        : original_packet(pkt), inject_cycle(cycle), inject_interface(interface),
          receive_cycle(0), receive_interface(""), received(false), corrupted(false) {}

    uint64_t get_latency() const {
        return received ? (receive_cycle - inject_cycle) : 0;
    }

    bool is_within_expected_latency(uint32_t expected_latency, uint32_t tolerance = 2) const {
        if (!received) return false;
        uint64_t actual_latency = get_latency();
        return (actual_latency >= expected_latency - tolerance) && (actual_latency <= expected_latency + tolerance);
    }
};

// ====================================================================
// Assertion Definition
// ====================================================================
struct Assertion {
    string name;
    string description;
    function<bool()> condition;
    string failure_message;
    bool enabled;

    Assertion(const string& n, const string& desc, function<bool()> cond, const string& fail_msg)
        : name(n), description(desc), condition(cond), failure_message(fail_msg), enabled(true) {}
};

// ====================================================================
// Validation Configuration
// ====================================================================
struct ValidationConfig {
    // Latency tolerances
    uint32_t unicast_latency_tolerance = 2;
    uint32_t multicast_latency_tolerance = 3;
    uint32_t broadcast_latency_tolerance = 4;
    uint32_t max_allowed_latency = 1000;  // Maximum acceptable latency

    // Performance thresholds
    double min_success_rate = 0.95;       // 95% minimum success rate
    double max_error_rate = 0.05;          // 5% maximum error rate
    double min_throughput_mpps = 0.1;      // Minimum throughput requirement

    // Timing constraints
    uint32_t pipeline_depth = 4;           // Expected pipeline stages
    uint32_t max_pipeline_latency = 10;    // Maximum pipeline latency

    // Routing validation
    bool enable_routing_validation = true;
    bool enable_qos_validation = true;
    bool enable_timing_validation = true;
    bool enable_interface_validation = true;

    // Detailed checking
    bool enable_corruption_check = true;
    bool enable_order_validation = false;  // Optional packet order checking
    bool enable_duplicate_detection = true;

    ValidationConfig() {}
};

// ====================================================================
// Main Result Validator Class
// ====================================================================
class ResultValidator {
private:
    ValidationConfig config_;
    TestUtils* test_utils_;
    Logger* logger_;

    // Packet tracking
    vector<unique_ptr<PacketTracker>> packet_trackers_;
    map<string, set<uint32_t>> test_id_to_packet_indices_;

    // Assertions
    vector<unique_ptr<Assertion>> assertions_;
    map<string, uint32_t> assertion_failures_;

    // Validation statistics
    uint64_t total_packets_tracked_;
    uint64_t packets_received_;
    uint64_t packets_dropped_;
    uint64_t packets_corrupted_;
    uint64_t packets_duplicated_;
    map<string, uint64_t> error_counts_;

    // Performance metrics
    double average_latency_;
    double min_latency_;
    double max_latency_;
    vector<uint64_t> latency_samples_;

    // Validation history
    vector<ValidationResult> validation_results_;

public:
    explicit ResultValidator(const ValidationConfig& config = ValidationConfig(),
                           TestUtils* test_utils = nullptr,
                           Logger* logger = nullptr)
        : config_(config), test_utils_(test_utils), logger_(logger),
          total_packets_tracked_(0), packets_received_(0), packets_dropped_(0),
          packets_corrupted_(0), packets_duplicated_(0),
          average_latency_(0.0), min_latency_(0.0), max_latency_(0.0) {

        if (logger_) {
            logger_->info("ResultValidator initialized");
        }

        // Initialize default assertions
        initialize_default_assertions();
    }

    // ====================================================================
    // Packet Tracking Methods
    // ====================================================================

    void track_injected_packet(const MazePacket& packet, uint64_t cycle, const string& interface = "A") {
        auto tracker = make_unique<PacketTracker>(packet, cycle, interface);
        size_t index = packet_trackers_.size();

        packet_trackers_.push_back(move(tracker));
        test_id_to_packet_indices_[packet.test_id].insert(index);

        total_packets_tracked_++;

        if (test_utils_ && test_utils_->is_verbose(2)) {
            string msg = "Tracking injected packet: " + packet.to_string();
            if (logger_) logger_->debug(msg, packet.test_id);
        }
    }

    bool track_received_packet(const MazePacket& received_packet, uint64_t cycle, const string& interface = "B") {
        bool matched = false;

        // Search for matching injected packet
        for (auto& tracker : packet_trackers_) {
            if (!tracker->received && tracker->original_packet.equals(received_packet)) {
                // Found matching packet
                tracker->received = true;
                tracker->receive_cycle = cycle;
                tracker->receive_interface = interface;

                // Validate packet integrity
                if (config_.enable_corruption_check) {
                    tracker->corrupted = !validate_packet_integrity(tracker->original_packet, received_packet);
                }

                matched = true;
                packets_received_++;

                // Record latency
                uint64_t latency = tracker->get_latency();
                record_latency_sample(latency);

                if (test_utils_ && test_utils_->is_verbose(2)) {
                    string msg = "Packet received with latency " + to_string(latency) + " cycles on " + interface;
                    if (logger_) logger_->debug(msg, received_packet.test_id);
                }

                break;
            }
        }

        if (!matched) {
            // Unmatched received packet - possible duplicate or corrupted
            if (config_.enable_duplicate_detection) {
                packets_duplicated_++;
                if (logger_) logger_->warning("Received duplicate or unexpected packet");
            }
        }

        return matched;
    }

    // ====================================================================
    // Validation Methods
    // ====================================================================

    ValidationResult validate_basic_functionality() {
        ValidationResult result("Basic Functionality");
        result.description = "Validate basic packet routing and interface operation";

        Timer timer;
        timer.start();

        // Check packet success rate
        double success_rate = total_packets_tracked_ > 0 ?
                             (double)packets_received_ / total_packets_tracked_ : 0.0;

        if (success_rate < config_.min_success_rate) {
            result.passed = false;
            result.error_message = "Low success rate: " + to_string(success_rate * 100, 2) +
                                  "% (expected >= " + to_string(config_.min_success_rate * 100, 2) + "%)";
            error_counts_["low_success_rate"]++;
        } else {
            result.passed = true;
        }

        result.metrics["success_rate"] = (uint64_t)(success_rate * 1000); // Store as promille
        result.metrics["packets_tracked"] = total_packets_tracked_;
        result.metrics["packets_received"] = packets_received_;
        result.metrics["packets_dropped"] = packets_dropped_;

        timer.stop();
        result.validation_time_ms = timer.get_elapsed_ms();

        validation_results_.push_back(result);
        return result;
    }

    ValidationResult validate_qos_arbitration() {
        ValidationResult result("QoS Arbitration");
        result.description = "Validate QoS priority enforcement and arbitration fairness";

        Timer timer;
        timer.start();

        if (!config_.enable_qos_validation) {
            result.passed = true;
            result.warnings.push_back("QoS validation disabled in configuration");
            timer.stop();
            result.validation_time_ms = timer.get_elapsed_ms();
            return result;
        }

        // Analyze QoS-based latency patterns
        vector<uint64_t> high_qos_latencies;
        vector<uint64_t> low_qos_latencies;

        for (const auto& tracker : packet_trackers_) {
            if (tracker->received) {
                uint64_t latency = tracker->get_latency();
                if (tracker->original_packet.qos == 1) {
                    high_qos_latencies.push_back(latency);
                } else {
                    low_qos_latencies.push_back(latency);
                }
            }
        }

        // Check if high QoS packets have better average latency
        bool qos_priority_enforced = true;
        if (!high_qos_latencies.empty() && !low_qos_latencies.empty()) {
            double avg_high_qos = calculate_average(high_qos_latencies);
            double avg_low_qos = calculate_average(low_qos_latencies);

            // High QoS should have equal or better average latency
            if (avg_high_qos > avg_low_qos + 1.0) { // Allow 1 cycle tolerance
                qos_priority_enforced = false;
                result.warnings.push_back("High QoS packets have higher average latency than low QoS");
            }

            result.metrics["avg_high_qos_latency"] = (uint64_t)(avg_high_qos * 100);
            result.metrics["avg_low_qos_latency"] = (uint64_t)(avg_low_qos * 100);
        }

        result.passed = qos_priority_enforced && (packets_received_ >= total_packets_tracked_ * config_.min_success_rate);

        if (!result.passed) {
            result.error_message = "QoS arbitration validation failed";
            error_counts_["qos_arbitration_failure"]++;
        }

        result.metrics["high_qos_packets"] = high_qos_latencies.size();
        result.metrics["low_qos_packets"] = low_qos_latencies.size();

        timer.stop();
        result.validation_time_ms = timer.get_elapsed_ms();

        validation_results_.push_back(result);
        return result;
    }

    ValidationResult validate_routing_correctness() {
        ValidationResult result("Routing Correctness");
        result.description = "Validate packet routing and intermediate node selection";

        Timer timer;
        timer.start();

        if (!config_.enable_routing_validation) {
            result.passed = true;
            result.warnings.push_back("Routing validation disabled in configuration");
            timer.stop();
            result.validation_time_ms = timer.get_elapsed_ms();
            return result;
        }

        bool routing_correct = true;
        uint32_t routing_errors = 0;

        for (const auto& tracker : packet_trackers_) {
            if (tracker->received) {
                const MazePacket& packet = tracker->original_packet;

                // Validate unicast routing
                if (packet.type == 0) { // Unicast
                    // Check for local delivery handling
                    if (packet.is_local_delivery()) {
                        // Local delivery should go through B-port
                        if (tracker->receive_interface != "B") {
                            routing_errors++;
                            routing_correct = false;
                            if (logger_) logger_->warning("Local delivery packet didn't exit through B-port", packet.test_id);
                        }
                    } else {
                        // Network routing should respect latency bounds
                        uint32_t expected_latency = calculate_expected_latency(packet);
                        if (!tracker->is_within_expected_latency(expected_latency, config_.unicast_latency_tolerance)) {
                            routing_errors++;
                            routing_correct = false;
                            if (logger_) {
                                uint64_t actual_latency = tracker->get_latency();
                                string msg = "Unicast latency outside expected range: actual=" + to_string(actual_latency) +
                                           ", expected=" + to_string(expected_latency) + "±" + to_string(config_.unicast_latency_tolerance);
                                logger_->warning(msg, packet.test_id);
                            }
                        }
                    }
                }
            }
        }

        result.passed = routing_correct && (routing_errors == 0);

        if (!result.passed) {
            result.error_message = "Routing validation failed with " + to_string(routing_errors) + " errors";
            error_counts_["routing_errors"] += routing_errors;
        }

        result.metrics["routing_errors"] = routing_errors;
        result.metrics["packets_validated"] = packets_received_;

        timer.stop();
        result.validation_time_ms = timer.get_elapsed_ms();

        validation_results_.push_back(result);
        return result;
    }

    ValidationResult validate_timing_constraints() {
        ValidationResult result("Timing Constraints");
        result.description = "Validate pipeline timing and latency constraints";

        Timer timer;
        timer.start();

        if (!config_.enable_timing_validation) {
            result.passed = true;
            result.warnings.push_back("Timing validation disabled in configuration");
            timer.stop();
            result.validation_time_ms = timer.get_elapsed_ms();
            return result;
        }

        bool timing_valid = true;
        uint32_t timing_violations = 0;

        // Check minimum latency (pipeline depth)
        for (uint64_t latency : latency_samples_) {
            if (latency < config_.pipeline_depth) {
                timing_violations++;
                timing_valid = false;
                if (logger_) logger_->warning("Packet latency below pipeline depth: " + to_string(latency));
            }

            if (latency > config_.max_allowed_latency) {
                timing_violations++;
                timing_valid = false;
                if (logger_) logger_->warning("Packet latency exceeds maximum: " + to_string(latency));
            }
        }

        result.passed = timing_valid && (timing_violations == 0);

        if (!result.passed) {
            result.error_message = "Timing validation failed with " + to_string(timing_violations) + " violations";
            error_counts_["timing_violations"] += timing_violations;
        }

        result.metrics["timing_violations"] = timing_violations;
        result.metrics["avg_latency"] = (uint64_t)(average_latency_ * 100);
        result.metrics["min_latency"] = (uint64_t)(min_latency_);
        result.metrics["max_latency"] = (uint64_t)(max_latency_);

        timer.stop();
        result.validation_time_ms = timer.get_elapsed_ms();

        validation_results_.push_back(result);
        return result;
    }

    ValidationResult validate_interface_protocol() {
        ValidationResult result("Interface Protocol");
        result.description = "Validate A/B/C interface protocol compliance";

        Timer timer;
        timer.start();

        if (!config_.enable_interface_validation) {
            result.passed = true;
            result.warnings.push_back("Interface validation disabled in configuration");
            timer.stop();
            result.validation_time_ms = timer.get_elapsed_ms();
            return result;
        }

        // Basic interface validation - would need more detailed simulation data
        bool interface_valid = true;

        // Check that packets were injected and received through appropriate interfaces
        map<string, uint32_t> inject_counts;
        map<string, uint32_t> receive_counts;

        for (const auto& tracker : packet_trackers_) {
            inject_counts[tracker->inject_interface]++;
            if (tracker->received) {
                receive_counts[tracker->receive_interface]++;
            }
        }

        // Basic sanity checks
        if (inject_counts["A"] == 0) {
            interface_valid = false;
            result.warnings.push_back("No packets injected through A interface");
        }

        result.passed = interface_valid;

        result.metrics["injections_A"] = inject_counts["A"];
        result.metrics["receives_B"] = receive_counts["B"];
        result.metrics["receives_C"] = receive_counts["C"];

        timer.stop();
        result.validation_time_ms = timer.get_elapsed_ms();

        validation_results_.push_back(result);
        return result;
    }

    // ====================================================================
    // Comprehensive Validation
    // ====================================================================

    bool run_all_validations() {
        if (logger_) logger_->info("Starting comprehensive validation");

        bool all_passed = true;

        // Run all validation checks
        auto basic_result = validate_basic_functionality();
        all_passed &= basic_result.passed;

        auto qos_result = validate_qos_arbitration();
        all_passed &= qos_result.passed;

        auto routing_result = validate_routing_correctness();
        all_passed &= routing_result.passed;

        auto timing_result = validate_timing_constraints();
        all_passed &= timing_result.passed;

        auto interface_result = validate_interface_protocol();
        all_passed &= interface_result.passed;

        // Run assertions
        bool assertions_passed = check_all_assertions();
        all_passed &= assertions_passed;

        if (logger_) {
            logger_->info("Comprehensive validation completed: " + string(all_passed ? "PASSED" : "FAILED"));
        }

        return all_passed;
    }

    // ====================================================================
    // Assertion Management
    // ====================================================================

    void add_assertion(const string& name, const string& description,
                      function<bool()> condition, const string& failure_message) {
        auto assertion = make_unique<Assertion>(name, description, condition, failure_message);
        assertions_.push_back(move(assertion));
    }

    bool check_all_assertions() {
        bool all_passed = true;

        for (const auto& assertion : assertions_) {
            if (assertion->enabled) {
                try {
                    bool result = assertion->condition();
                    if (!result) {
                        all_passed = false;
                        assertion_failures_[assertion->name]++;
                        if (logger_) logger_->error("Assertion failed: " + assertion->name + " - " + assertion->failure_message);
                    }
                } catch (const exception& e) {
                    all_passed = false;
                    assertion_failures_[assertion->name]++;
                    if (logger_) logger_->error("Assertion exception: " + assertion->name + " - " + e.what());
                }
            }
        }

        return all_passed;
    }

    // ====================================================================
    // Statistics and Reporting
    // ====================================================================

    void reset_validation() {
        packet_trackers_.clear();
        test_id_to_packet_indices_.clear();
        total_packets_tracked_ = 0;
        packets_received_ = 0;
        packets_dropped_ = 0;
        packets_corrupted_ = 0;
        packets_duplicated_ = 0;
        error_counts_.clear();
        assertion_failures_.clear();
        validation_results_.clear();
        latency_samples_.clear();
        average_latency_ = 0.0;
        min_latency_ = 0.0;
        max_latency_ = 0.0;
    }

    void print_validation_summary() const {
        cout << "\n" << string(80, '=') << endl;
        cout << "Validation Summary" << endl;
        cout << string(80, '=') << endl;

        cout << "Packet Tracking:" << endl;
        cout << "  Total Tracked:    " << total_packets_tracked_ << endl;
        cout << "  Successfully Received: " << packets_received_ << endl;
        cout << "  Dropped:          " << packets_dropped_ << endl;
        cout << "  Corrupted:        " << packets_corrupted_ << endl;
        cout << "  Duplicated:       " << packets_duplicated_ << endl;

        if (total_packets_tracked_ > 0) {
            double success_rate = (double)packets_received_ / total_packets_tracked_ * 100.0;
            cout << "  Success Rate:     " << fixed << setprecision(2) << success_rate << "%" << endl;
        }

        if (!latency_samples_.empty()) {
            cout << "\nLatency Analysis:" << endl;
            cout << "  Average:          " << fixed << setprecision(2) << average_latency_ << " cycles" << endl;
            cout << "  Minimum:          " << (uint64_t)min_latency_ << " cycles" << endl;
            cout << "  Maximum:          " << (uint64_t)max_latency_ << " cycles" << endl;
        }

        cout << "\nValidation Results:" << endl;
        for (const auto& result : validation_results_) {
            cout << "  " << setw(20) << left << result.test_name << ": "
                 << (result.passed ? "PASS" : "FAIL") << endl;
            if (!result.error_message.empty()) {
                cout << "    Error: " << result.error_message << endl;
            }
            for (const auto& warning : result.warnings) {
                cout << "    Warning: " << warning << endl;
            }
        }

        if (!assertion_failures_.empty()) {
            cout << "\nAssertion Failures:" << endl;
            for (const auto& failure : assertion_failures_) {
                cout << "  " << failure.first << ": " << failure.second << " failures" << endl;
            }
        }

        if (!error_counts_.empty()) {
            cout << "\nError Summary:" << endl;
            for (const auto& error : error_counts_) {
                cout << "  " << setw(25) << left << error.first << ": " << error.second << endl;
            }
        }

        cout << string(80, '=') << endl;
    }

    const vector<ValidationResult>& get_validation_results() const {
        return validation_results_;
    }

    // ====================================================================
    // Configuration
    // ====================================================================

    void set_config(const ValidationConfig& config) {
        config_ = config;
        if (logger_) logger_->info("Validation configuration updated");
    }

    const ValidationConfig& get_config() const {
        return config_;
    }

private:
    // ====================================================================
    // Helper Methods
    // ====================================================================

    void initialize_default_assertions() {
        // Basic functional assertions
        add_assertion("no_packet_loss", "No injected packets should be lost",
                      [this]() { return packets_received_ + packets_dropped_ >= total_packets_tracked_; },
                      "Packet loss detected");

        add_assertion("reasonable_latency", "All packets should have reasonable latency",
                      [this]() {
                          for (uint64_t latency : latency_samples_) {
                              if (latency > config_.max_allowed_latency) return false;
                          }
                          return true;
                      },
                      "Excessive packet latency detected");

        add_assertion("minimum_success_rate", "Success rate should meet minimum threshold",
                      [this]() {
                          double success_rate = total_packets_tracked_ > 0 ?
                                               (double)packets_received_ / total_packets_tracked_ : 0.0;
                          return success_rate >= config_.min_success_rate;
                      },
                      "Success rate below minimum threshold");
    }

    bool validate_packet_integrity(const MazePacket& original, const MazePacket& received) {
        // Check if packet fields match exactly
        return original.equals(received);
    }

    void record_latency_sample(uint64_t latency) {
        latency_samples_.push_back(latency);

        if (latency_samples_.size() == 1) {
            min_latency_ = max_latency_ = average_latency_ = (double)latency;
        } else {
            min_latency_ = min(min_latency_, (double)latency);
            max_latency_ = max(max_latency_, (double)latency);

            // Update running average
            average_latency_ = ((average_latency_ * (latency_samples_.size() - 1)) + latency) / latency_samples_.size();
        }
    }

    double calculate_average(const vector<uint64_t>& values) const {
        if (values.empty()) return 0.0;

        uint64_t sum = 0;
        for (uint64_t value : values) {
            sum += value;
        }
        return (double)sum / values.size();
    }

    uint32_t calculate_expected_latency(const MazePacket& packet) const {
        // Base pipeline latency
        uint32_t base_latency = config_.pipeline_depth;

        // Additional hops for network routing
        if (packet.type == 0) { // Unicast
            if (packet.is_local_delivery()) {
                return base_latency; // Local delivery
            } else {
                return base_latency + 2; // Two-hop routing
            }
        } else { // Multicast/Broadcast
            return base_latency + 1; // One-hop replication
        }
    }
};

#endif // RESULT_VALIDATOR_H