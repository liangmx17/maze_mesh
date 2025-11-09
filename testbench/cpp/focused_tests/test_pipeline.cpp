// ====================================================================
// MAZE Network Node - Pipeline Timing Tests
// ====================================================================
//
// Focused test suite for pipeline timing validation
// Tests 4-stage pipeline operation, ready/valid handshaking, and backpressure
//
// Usage:
//   ./test_pipeline [options]
//   Options:
//     --hp <num>     Node horizontal position [0-7] (default: 3)
//     --vp <num>     Node vertical position [0-7] (default: 2)
//     --vcd          Enable VCD waveform generation
//     --verbose      Enable verbose output
//     --help         Show help message
//
// ====================================================================

#include <iostream>
#include <string>
#include <getopt.h>
#include <vector>
#include <chrono>
#include "packet_utils.h"
#include "node_simulator.h"
#include "test_helpers.h"

using namespace std;

// ====================================================================
// Test Configuration
// ====================================================================

struct PipelineTestConfig {
    uint32_t hp = 3;
    uint32_t vp = 2;
    bool enable_vcd = false;
    bool verbose = false;
    string vcd_file = "test_pipeline.vcd";
    uint32_t max_test_cycles = 3000;
};

// ====================================================================
// Pipeline Timing Analysis Structure
// ====================================================================

struct PipelineTimingData {
    uint64_t input_time;
    uint64_t output_time;
    uint32_t packet_id;
    uint32_t expected_latency;
    bool backpressure_applied;

    PipelineTimingData(uint64_t in_time, uint32_t pkt_id, uint32_t exp_latency = 4)
        : input_time(in_time), output_time(0), packet_id(pkt_id),
          expected_latency(exp_latency), backpressure_applied(false) {}

    uint64_t get_actual_latency() const {
        return (output_time > input_time) ? (output_time - input_time) : 0;
    }

    double get_latency_efficiency() const {
        uint64_t actual = get_actual_latency();
        return (expected_latency > 0) ? (double)expected_latency / actual : 0.0;
    }
};

class PipelineAnalyzer {
private:
    vector<PipelineTimingData> timing_data_;
    uint64_t min_latency_;
    uint64_t max_latency_;
    double avg_latency_;

public:
    PipelineAnalyzer() : min_latency_(UINT64_MAX), max_latency_(0), avg_latency_(0.0) {}

    void record_input(uint32_t packet_id, uint64_t cycle_time, uint32_t expected_latency = 4) {
        timing_data_.emplace_back(cycle_time, packet_id, expected_latency);
    }

    void record_output(uint32_t packet_id, uint64_t cycle_time) {
        for (auto& data : timing_data_) {
            if (data.packet_id == packet_id && data.output_time == 0) {
                data.output_time = cycle_time;
                update_statistics();
                break;
            }
        }
    }

    void apply_backpressure(uint32_t packet_id) {
        for (auto& data : timing_data_) {
            if (data.packet_id == packet_id) {
                data.backpressure_applied = true;
                break;
            }
        }
    }

    void update_statistics() {
        if (timing_data_.empty()) return;

        uint64_t total_latency = 0;
        uint32_t completed_packets = 0;
        min_latency_ = UINT64_MAX;
        max_latency_ = 0;

        for (const auto& data : timing_data_) {
            if (data.output_time > 0) {
                uint64_t latency = data.get_actual_latency();
                total_latency += latency;
                completed_packets++;

                if (latency < min_latency_) min_latency_ = latency;
                if (latency > max_latency_) max_latency_ = latency;
            }
        }

        avg_latency_ = (completed_packets > 0) ? (double)total_latency / completed_packets : 0.0;
    }

    void print_analysis() const {
        cout << "\n" << string(60, '-') << endl;
        cout << "Pipeline Timing Analysis" << endl;
        cout << string(60, '-') << endl;

        uint32_t completed_packets = 0;
        for (const auto& data : timing_data_) {
            if (data.output_time > 0) completed_packets++;
        }

        cout << "Total packets: " << timing_data_.size() << endl;
        cout << "Completed packets: " << completed_packets << endl;
        cout << "Completion rate: " << fixed << setprecision(1)
             << (timing_data_.size() > 0 ? 100.0 * completed_packets / timing_data_.size() : 0.0) << "%" << endl;

        if (completed_packets > 0) {
            cout << "Latency statistics:" << endl;
            cout << "  Minimum: " << min_latency_ << " cycles" << endl;
            cout << "  Maximum: " << max_latency_ << " cycles" << endl;
            cout << "  Average: " << fixed << setprecision(2) << avg_latency_ << " cycles" << endl;

            // Calculate efficiency (actual vs expected)
            double total_efficiency = 0.0;
            for (const auto& data : timing_data_) {
                if (data.output_time > 0) {
                    total_efficiency += data.get_latency_efficiency();
                }
            }
            double avg_efficiency = total_efficiency / completed_packets;

            cout << "Pipeline efficiency: " << fixed << setprecision(1)
                 << (100.0 * avg_efficiency) << "%" << endl;
        }

        cout << string(60, '-') << endl;
    }

    bool validate_pipeline_operation(uint32_t max_acceptable_latency = 20) const {
        uint32_t completed_packets = 0;
        uint32_t good_latency_packets = 0;

        for (const auto& data : timing_data_) {
            if (data.output_time > 0) {
                completed_packets++;
                uint64_t latency = data.get_actual_latency();
                if (latency <= max_acceptable_latency) {
                    good_latency_packets++;
                }
            }
        }

        // At least 80% completion and 90% good latency
        double completion_rate = (timing_data_.size() > 0) ?
            (double)completed_packets / timing_data_.size() : 0.0;
        double good_latency_rate = (completed_packets > 0) ?
            (double)good_latency_packets / completed_packets : 0.0;

        return (completion_rate >= 0.8) && (good_latency_rate >= 0.9);
    }
};

// ====================================================================
// Command Line Parsing
// ====================================================================

PipelineTestConfig parse_arguments(int argc, char* argv[]) {
    PipelineTestConfig config;

    static struct option long_options[] = {
        {"hp",       required_argument, 0, 'h'},
        {"vp",       required_argument, 0, 'v'},
        {"vcd",      no_argument,       0, 'c'},
        {"verbose",  no_argument,       0, 'V'},
        {"help",     no_argument,       0, 'H'},
        {0, 0, 0, 0}
    };

    int c;
    while ((c = getopt_long(argc, argv, "h:v:cVH", long_options, nullptr)) != -1) {
        switch (c) {
            case 'h':
                config.hp = stoul(optarg) % 8;
                break;
            case 'v':
                config.vp = stoul(optarg) % 8;
                break;
            case 'c':
                config.enable_vcd = true;
                break;
            case 'V':
                config.verbose = true;
                break;
            case 'H':
                cout << "MAZE Network Node - Pipeline Timing Tests" << endl;
                cout << "Usage: " << argv[0] << " [options]" << endl;
                cout << "Options:" << endl;
                cout << "  --hp <num>     Node horizontal position [0-7] (default: 3)" << endl;
                cout << "  --vp <num>     Node vertical position [0-7] (default: 2)" << endl;
                cout << "  --vcd          Enable VCD waveform generation" << endl;
                cout << "  --verbose      Enable verbose output" << endl;
                cout << "  --help         Show this help message" << endl;
                exit(0);
            case '?':
                cerr << "[ERROR] Unknown option. Use --help for usage information." << endl;
                exit(1);
            default:
                break;
        }
    }

    return config;
}

// ====================================================================
// Test Functions
// ====================================================================

// Test basic 4-stage pipeline timing
bool test_basic_pipeline_timing(NodeSimulator& sim, PipelineAnalyzer& analyzer) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing basic pipeline timing..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    vector<Packet> test_packets;
    uint32_t packet_count = 10;

    // Generate test packets with unique IDs
    for (uint32_t i = 0; i < packet_count; i++) {
        uint32_t packet_data = PacketUtils::create_unicast_packet(
            (i + 1) % 8, (i + 2) % 8, (i + 3) % 8, (i + 4) % 8, 0x40 + i);
        test_packets.push_back(PacketUtils::parse_packet(packet_data));
    }

    // Send packets with proper timing
    for (size_t i = 0; i < test_packets.size(); i++) {
        uint64_t send_time = sim.get_simulation_time();
        analyzer.record_input(i, send_time);

        if (getenv("VERBOSE")) {
            cout << "[SEND] Packet " << i << ": " << test_packets[i].description
                 << " at cycle " << send_time << endl;
        }

        sim.send_packet(test_packets[i].data);

        // Wait for pipeline acceptance (1 cycle per packet)
        sim.run_cycles(1);
    }

    // Allow pipeline to fully process
    sim.run_cycles(50);

    // Try to receive output packets and record timing
    for (uint32_t i = 0; i < packet_count; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 30)) {
            uint64_t recv_time = sim.get_simulation_time();
            analyzer.record_output(i, recv_time);

            if (getenv("VERBOSE")) {
                Packet output = PacketUtils::parse_packet(output_data);
                cout << "[RECV] Packet " << i << ": " << output.description
                     << " at cycle " << recv_time << endl;
            }
        }
    }

    // Validate pipeline timing
    bool test_passed = analyzer.validate_pipeline_operation();

    if (getenv("VERBOSE")) {
        analyzer.print_analysis();
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Basic pipeline timing test" << endl;
    }

    return test_passed;
}

// Test ready/valid handshaking
bool test_ready_valid_handshake(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing ready/valid handshaking..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    uint32_t test_packet = PacketUtils::create_unicast_packet(1, 1, 6, 6, 0x77);

    // Test 1: Verify initial ready state
    sim.run_cycles(3);
    if (!sim.is_input_ready()) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Input not ready after reset" << endl;
        }
        return false;
    }

    // Test 2: Send packet and verify handshake
    uint64_t send_time = sim.get_simulation_time();
    if (!sim.send_packet(test_packet)) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Failed to send packet" << endl;
        }
        return false;
    }

    // Test 3: Verify output protocol
    bool output_received = false;
    for (int i = 0; i < 30; i++) {
        sim.step();
        if (sim.is_output_valid()) {
            sim.dut_->pkt_out_ready = 1;
            output_received = true;
            sim.step();
            sim.dut_->pkt_out_ready = 0;
            break;
        }
    }

    // Test 4: Verify ready after processing
    sim.run_cycles(5);
    bool ready_after = sim.is_input_ready();

    bool test_passed = output_received && ready_after && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[INFO] Handshake test: output_received=" << output_received
             << ", ready_after=" << ready_after << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Ready/valid handshake test" << endl;
    }

    return test_passed;
}

// Test backpressure handling
bool test_backpressure(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing backpressure handling..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    vector<Packet> test_packets;
    uint32_t packet_count = 8;

    // Create test packets
    for (uint32_t i = 0; i < packet_count; i++) {
        uint32_t packet_data = PacketUtils::create_unicast_packet(
            (i * 2) % 8, (i * 3) % 8, (i + 1) % 8, (i + 2) % 8, 0x80 + i);
        test_packets.push_back(PacketUtils::parse_packet(packet_data));
    }

    // Apply backpressure by not accepting output
    sim.dut_->pkt_out_ready = 0;

    // Send packets rapidly to create backpressure
    for (size_t i = 0; i < test_packets.size(); i++) {
        if (getenv("VERBOSE")) {
            cout << "[SEND] Packet " << i << " under backpressure" << endl;
        }

        sim.send_packet(test_packets[i].data);

        // Minimal spacing to create pressure
        sim.run_cycles(1);

        // Check if input becomes not ready (backpressure indication)
        if (!sim.is_input_ready()) {
            if (getenv("VERBOSE")) {
                cout << "[INFO] Backpressure detected at packet " << i << endl;
            }
        }
    }

    // Release backpressure
    sim.dut_->pkt_out_ready = 1;

    // Allow pipeline to drain
    sim.run_cycles(100);

    // Collect outputs
    vector<Packet> output_packets;
    for (int i = 0; i < 50; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 10)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    bool test_passed = sim.validate_node_state() && (output_packets.size() > 0);

    if (getenv("VERBOSE")) {
        cout << "[INFO] Backpressure test: " << test_packets.size() << " input, "
             << output_packets.size() << " output packets" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Backpressure test" << endl;
    }

    return test_passed;
}

// Test pipeline throughput
bool test_pipeline_throughput(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing pipeline throughput..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    uint32_t packet_count = 20;
    vector<Packet> test_packets;

    // Generate test packets
    for (uint32_t i = 0; i < packet_count; i++) {
        uint32_t packet_data = PacketUtils::create_unicast_packet(
            i % 8, (i + 1) % 8, (i + 2) % 8, (i + 3) % 8, 0x50 + i);
        test_packets.push_back(PacketUtils::parse_packet(packet_data));
    }

    auto start_time = chrono::high_resolution_clock::now();
    uint64_t start_cycles = sim.get_simulation_time();

    // Send packets continuously
    for (size_t i = 0; i < test_packets.size(); i++) {
        sim.send_packet(test_packets[i].data);
        sim.run_cycles(1);  // One cycle per packet for maximum throughput
    }

    // Wait for pipeline to drain
    sim.run_cycles(60);

    auto end_time = chrono::high_resolution_clock::now();
    uint64_t end_cycles = sim.get_simulation_time();

    // Count outputs
    vector<Packet> output_packets;
    for (int i = 0; i < 40; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 5)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    // Calculate throughput metrics
    double execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();
    uint64_t total_cycles = end_cycles - start_cycles;
    double throughput_pps = output_packets.size() / (execution_time_ms / 1000.0);
    double cycles_per_packet = (output_packets.size() > 0) ? (double)total_cycles / output_packets.size() : 0.0;

    bool test_passed = sim.validate_node_state() && (output_packets.size() >= packet_count * 0.8);

    if (getenv("VERBOSE")) {
        cout << "[INFO] Throughput metrics:" << endl;
        cout << "  Packets processed: " << output_packets.size() << "/" << packet_count << endl;
        cout << "  Execution time: " << fixed << setprecision(2) << execution_time_ms << " ms" << endl;
        cout << "  Total cycles: " << total_cycles << endl;
        cout << "  Throughput: " << fixed << setprecision(0) << throughput_pps << " packets/sec" << endl;
        cout << "  Cycles per packet: " << fixed << setprecision(2) << cycles_per_packet << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Pipeline throughput test" << endl;
    }

    return test_passed;
}

// Test pipeline bubble handling
bool test_pipeline_bubbles(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing pipeline bubble handling..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    uint32_t packet_count = 6;

    // Send packets with gaps (bubbles)
    for (uint32_t i = 0; i < packet_count; i++) {
        uint32_t packet_data = PacketUtils::create_unicast_packet(
            (i + 1) % 8, (i + 2) % 8, (i + 3) % 8, (i + 4) % 8, 0x60 + i);

        if (getenv("VERBOSE")) {
            cout << "[SEND] Packet " << i << " with bubble insertion" << endl;
        }

        sim.send_packet(packet_data);

        // Insert bubble cycles
        uint32_t bubble_cycles = (i % 3 == 0) ? 3 : 1;
        sim.run_cycles(bubble_cycles);
    }

    // Allow full processing
    sim.run_cycles(80);

    // Collect outputs
    vector<Packet> output_packets;
    for (int i = 0; i < 30; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 15)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    bool test_passed = sim.validate_node_state() && (output_packets.size() >= packet_count * 0.8);

    if (getenv("VERBOSE")) {
        cout << "[INFO] Bubble test: " << packet_count << " input, "
             << output_packets.size() << " output packets" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Pipeline bubble test" << endl;
    }

    return test_passed;
}

// ====================================================================
// Main Test Execution
// ====================================================================

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        PipelineTestConfig config = parse_arguments(argc, argv);

        // Set verbose flag
        if (config.verbose) {
            setenv("VERBOSE", "1", 1);
        }

        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - Pipeline Timing Tests" << endl;
        cout << "Node Position: (" << config.hp << ", " << config.vp << ")" << endl;
        cout << "Max Test Cycles: " << config.max_test_cycles << endl;
        if (config.enable_vcd) {
            cout << "VCD Output: " << config.vcd_file << endl;
        }
        cout << string(80, '=') << endl;

        // Configure and create simulator
        NodeSimConfig sim_config;
        sim_config.hp = config.hp;
        sim_config.vp = config.vp;
        sim_config.enable_vcd = config.enable_vcd;
        sim_config.vcd_file = config.vcd_file;
        sim_config.verbose = config.verbose;
        sim_config.max_cycles = config.max_test_cycles;

        NodeSimulator sim(sim_config);
        if (!sim.initialize()) {
            cerr << "[FATAL] Failed to initialize node simulator" << endl;
            return 1;
        }

        // Create pipeline analyzer
        PipelineAnalyzer analyzer;

        // Create test suite
        TestSuite suite("Pipeline Timing Tests", config.verbose);

        // Run pipeline tests
        bool basic_timing_result = suite.run_test("Basic Pipeline Timing",
                                                 "Test 4-stage pipeline operation and latency",
                                                 [&sim, &analyzer]() { return test_basic_pipeline_timing(sim, analyzer); });

        suite.run_test("Ready/Valid Handshake",
                      "Test proper ready/valid protocol implementation",
                      [&sim]() { return test_ready_valid_handshake(sim); });

        suite.run_test("Backpressure Handling",
                      "Test pipeline behavior under backpressure",
                      [&sim]() { return test_backpressure(sim); });

        suite.run_test("Pipeline Throughput",
                      "Test maximum pipeline throughput",
                      [&sim]() { return test_pipeline_throughput(sim); });

        suite.run_test("Pipeline Bubble Handling",
                      "Test pipeline behavior with bubble insertion",
                      [&sim]() { return test_pipeline_bubbles(sim); });

        // Print detailed timing analysis for basic timing test
        if (basic_timing_result && config.verbose) {
            analyzer.print_analysis();
        }

        // Print results
        suite.print_summary();

        // Save results
        suite.save_results("pipeline_test_results.txt");

        // Print final status
        cout << "\n" << string(80, '=') << endl;
        if (suite.all_passed()) {
            cout << "SUCCESS: All pipeline timing tests passed!" << endl;
            cout << "4-stage pipeline is operating correctly." << endl;
        } else {
            cout << "FAILURE: Some pipeline timing tests failed!" << endl;
            cout << "Please check pipeline implementation and timing." << endl;
        }
        cout << string(80, '=') << endl;

        // Print simulator statistics
        sim.print_stats();

        // Return appropriate exit code
        return suite.all_passed() ? 0 : 1;

    } catch (const exception& e) {
        cerr << "[FATAL] Exception in main: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "[FATAL] Unknown exception in main" << endl;
        return 1;
    }
}