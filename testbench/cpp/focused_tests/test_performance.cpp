// ====================================================================
// MAZE Network Node - Performance Tests
// ====================================================================
//
// Focused test suite for performance measurement and analysis
// Tests throughput, latency, and maximum load handling
//
// Usage:
//   ./test_performance [options]
//   Options:
//     --hp <num>     Node horizontal position [0-7] (default: 3)
//     --vp <num>     Node vertical position [0-7] (default: 2)
//     --vcd          Enable VCD waveform generation
//     --verbose      Enable verbose output
//     --packets <n>  Number of test packets (default: 1000)
//     --help         Show help message
//
// ====================================================================

#include <iostream>
#include <string>
#include <getopt.h>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "packet_utils.h"
#include "node_simulator.h"
#include "test_helpers.h"

using namespace std;

// ====================================================================
// Test Configuration
// ====================================================================

struct PerformanceTestConfig {
    uint32_t hp = 3;
    uint32_t vp = 2;
    bool enable_vcd = false;
    bool verbose = false;
    string vcd_file = "test_performance.vcd";
    uint32_t packet_count = 1000;
    uint32_t max_cycles = 20000;
};

// ====================================================================
// Performance Metrics Structure
// ====================================================================

struct PerformanceMetrics {
    uint32_t packets_sent = 0;
    uint32_t packets_received = 0;
    uint64_t total_cycles = 0;
    double execution_time_ms = 0.0;

    // Throughput metrics
    double throughput_pps = 0.0;        // Packets per second
    double throughput_gbps = 0.0;       // Gigabits per second

    // Latency metrics
    double avg_latency_cycles = 0.0;
    double min_latency_cycles = 0.0;
    double max_latency_cycles = 0.0;
    vector<double> latency_samples;

    // Efficiency metrics
    double pipeline_efficiency = 0.0;
    double bandwidth_utilization = 0.0;

    void reset() {
        packets_sent = 0;
        packets_received = 0;
        total_cycles = 0;
        execution_time_ms = 0.0;
        throughput_pps = 0.0;
        throughput_gbps = 0.0;
        avg_latency_cycles = 0.0;
        min_latency_cycles = 0.0;
        max_latency_cycles = 0.0;
        latency_samples.clear();
        pipeline_efficiency = 0.0;
        bandwidth_utilization = 0.0;
    }

    void calculate_throughput() {
        if (execution_time_ms > 0.0) {
            throughput_pps = packets_received / (execution_time_ms / 1000.0);
            // 23-bit packets = 23 bits per packet
            throughput_gbps = (throughput_pps * 23) / (1024.0 * 1024.0 * 1024.0);
        }
    }

    void calculate_latency() {
        if (!latency_samples.empty()) {
            avg_latency_cycles = 0.0;
            for (double latency : latency_samples) {
                avg_latency_cycles += latency;
            }
            avg_latency_cycles /= latency_samples.size();

            auto min_it = min_element(latency_samples.begin(), latency_samples.end());
            auto max_it = max_element(latency_samples.begin(), latency_samples.end());
            min_latency_cycles = *min_it;
            max_latency_cycles = *max_it;
        }
    }

    void calculate_efficiency() {
        // Pipeline efficiency: theoretical vs actual throughput
        if (total_cycles > 0 && packets_sent > 0) {
            double theoretical_max = (double)total_cycles / 4.0;  // 4-stage pipeline
            pipeline_efficiency = (double)packets_received / theoretical_max;
            pipeline_efficiency = min(pipeline_efficiency, 1.0);
        }

        // Bandwidth utilization based on packet rate
        const double max_packet_rate = 250000000.0;  // 250 MHz clock / 4 cycles per packet
        bandwidth_utilization = throughput_pps / max_packet_rate;
        bandwidth_utilization = min(bandwidth_utilization, 1.0);
    }

    void print_metrics() const {
        cout << "\n" << string(70, '=') << endl;
        cout << "PERFORMANCE METRICS" << endl;
        cout << string(70, '=') << endl;

        cout << "Packet Statistics:" << endl;
        cout << "  Packets sent:     " << packets_sent << endl;
        cout << "  Packets received: " << packets_received << endl;
        cout << "  Success rate:     " << fixed << setprecision(2)
             << (packets_sent > 0 ? 100.0 * packets_received / packets_sent : 0.0) << "%" << endl;

        cout << "\nTiming:" << endl;
        cout << "  Execution time:   " << fixed << setprecision(2) << execution_time_ms << " ms" << endl;
        cout << "  Total cycles:     " << total_cycles << endl;

        cout << "\nThroughput:" << endl;
        cout << "  Packets/sec:      " << fixed << setprecision(0) << throughput_pps << endl;
        cout << "  Gigabits/sec:     " << fixed << setprecision(3) << throughput_gbps << endl;

        if (!latency_samples.empty()) {
            cout << "\nLatency (cycles):" << endl;
            cout << "  Average:          " << fixed << setprecision(2) << avg_latency_cycles << endl;
            cout << "  Minimum:          " << fixed << setprecision(2) << min_latency_cycles << endl;
            cout << "  Maximum:          " << fixed << setprecision(2) << max_latency_cycles << endl;
        }

        cout << "\nEfficiency:" << endl;
        cout << "  Pipeline eff.:     " << fixed << setprecision(1) << (100.0 * pipeline_efficiency) << "%" << endl;
        cout << "  Bandwidth util.:   " << fixed << setprecision(1) << (100.0 * bandwidth_utilization) << "%" << endl;

        cout << string(70, '=') << endl;
    }

    bool is_performance_acceptable() {
        calculate_throughput();
        calculate_latency();
        calculate_efficiency();

        // Define performance thresholds
        const double min_throughput_pps = 1000000.0;     // 1M packets/sec
        const double max_avg_latency_cycles = 20.0;     // 20 cycles average
        const double min_success_rate = 0.80;           // 80% success rate
        const double min_pipeline_efficiency = 0.60;    // 60% efficiency

        double success_rate = (packets_sent > 0) ? (double)packets_received / packets_sent : 0.0;

        bool acceptable = (success_rate >= min_success_rate) &&
                         (throughput_pps >= min_throughput_pps) &&
                         (avg_latency_cycles <= max_avg_latency_cycles) &&
                         (pipeline_efficiency >= min_pipeline_efficiency);

        if (getenv("VERBOSE")) {
            cout << "[PERF] Performance assessment:" << endl;
            cout << "  Success rate: " << fixed << setprecision(2) << (100.0 * success_rate) << "% (min " << (100.0 * min_success_rate) << "%)" << endl;
            cout << "  Throughput: " << fixed << setprecision(0) << throughput_pps << " pps (min " << min_throughput_pps << ")" << endl;
            cout << "  Avg latency: " << fixed << setprecision(2) << avg_latency_cycles << " cycles (max " << max_avg_latency_cycles << ")" << endl;
            cout << "  Pipeline eff.: " << fixed << setprecision(1) << (100.0 * pipeline_efficiency) << "% (min " << (100.0 * min_pipeline_efficiency) << "%)" << endl;
            cout << "  Overall: " << (acceptable ? "ACCEPTABLE" : "UNACCEPTABLE") << endl;
        }

        return acceptable;
    }
};

class PerformanceTestGenerator {
private:
    mt19937 rng_;
    uniform_int_distribution<> coord_dist_;
    uniform_int_distribution<> data_dist_;
    uniform_int_distribution<> qos_dist_;
    uniform_int_distribution<> type_dist_;

public:
    PerformanceTestGenerator(uint32_t seed = 12345) : rng_(seed), coord_dist_(0, 7),
                                                    data_dist_(0, 255), qos_dist_(0, 1),
                                                    type_dist_(0, 3) {}

    vector<Packet> generate_load_test_packets(uint32_t count) {
        vector<Packet> packets;
        packets.reserve(count);

        for (uint32_t i = 0; i < count; i++) {
            uint32_t src_x = coord_dist_(rng_);
            uint32_t src_y = coord_dist_(rng_);
            uint32_t tgt_x = coord_dist_(rng_);
            uint32_t tgt_y = coord_dist_(rng_);
            uint32_t data = data_dist_(rng_);
            QoSLevel qos = static_cast<QoSLevel>(qos_dist_(rng_));
            uint32_t type = type_dist_(rng_);

            uint32_t packet_data;
            switch (type) {
                case UNICAST:
                    packet_data = PacketUtils::create_unicast_packet(
                        src_x, src_y, tgt_x, tgt_y, data, qos);
                    break;
                case X_MULTICAST:
                    packet_data = PacketUtils::create_x_multicast_packet(
                        src_x, src_y, tgt_x, data, qos);
                    break;
                case Y_MULTICAST:
                    packet_data = PacketUtils::create_y_multicast_packet(
                        src_x, src_y, tgt_y, data, qos);
                    break;
                case BROADCAST:
                    packet_data = PacketUtils::create_broadcast_packet(
                        src_x, src_y, data, qos);
                    break;
                default:
                    packet_data = PacketUtils::create_unicast_packet(
                        src_x, src_y, tgt_x, tgt_y, data, qos);
            }

            packets.push_back(PacketUtils::parse_packet(packet_data));
        }

        return packets;
    }

    vector<Packet> generate_stress_test_packets(uint32_t count, double contention_factor = 1.0) {
        vector<Packet> packets;
        packets.reserve(count);

        // Create high contention by using similar target destinations
        uint32_t hot_tgt_x = coord_dist_(rng_);
        uint32_t hot_tgt_y = coord_dist_(rng_);

        for (uint32_t i = 0; i < count; i++) {
            uint32_t src_x = coord_dist_(rng_);
            uint32_t src_y = coord_dist_(rng_);
            uint32_t data = data_dist_(rng_);

            // 70% of packets go to hot target, 30% random
            uint32_t tgt_x, tgt_y;
            if ((double)rand() / RAND_MAX < contention_factor) {
                tgt_x = hot_tgt_x;
                tgt_y = hot_tgt_y;
            } else {
                tgt_x = coord_dist_(rng_);
                tgt_y = coord_dist_(rng_);
            }

            uint32_t packet_data = PacketUtils::create_unicast_packet(
                src_x, src_y, tgt_x, tgt_y, data, QOS_LOW);

            packets.push_back(PacketUtils::parse_packet(packet_data));
        }

        return packets;
    }

    vector<Packet> generate_qos_load_packets(uint32_t count, double high_qos_ratio = 0.3) {
        vector<Packet> packets;
        packets.reserve(count);

        for (uint32_t i = 0; i < count; i++) {
            uint32_t src_x = coord_dist_(rng_);
            uint32_t src_y = coord_dist_(rng_);
            uint32_t tgt_x = coord_dist_(rng_);
            uint32_t tgt_y = coord_dist_(rng_);
            uint32_t data = data_dist_(rng_);

            QoSLevel qos = ((double)rand() / RAND_MAX < high_qos_ratio) ? QOS_HIGH : QOS_LOW;

            uint32_t packet_data = PacketUtils::create_unicast_packet(
                src_x, src_y, tgt_x, tgt_y, data, qos);

            packets.push_back(PacketUtils::parse_packet(packet_data));
        }

        return packets;
    }
};

// ====================================================================
// Command Line Parsing
// ====================================================================

PerformanceTestConfig parse_arguments(int argc, char* argv[]) {
    PerformanceTestConfig config;

    static struct option long_options[] = {
        {"hp",        required_argument, 0, 'h'},
        {"vp",        required_argument, 0, 'v'},
        {"vcd",       no_argument,       0, 'c'},
        {"verbose",   no_argument,       0, 'V'},
        {"packets",   required_argument, 0, 'p'},
        {"help",      no_argument,       0, 'H'},
        {0, 0, 0, 0}
    };

    int c;
    while ((c = getopt_long(argc, argv, "h:v:cVpH:", long_options, nullptr)) != -1) {
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
            case 'p':
                config.packet_count = stoul(optarg);
                if (config.packet_count > 10000) config.packet_count = 10000;
                if (config.packet_count < 100) config.packet_count = 100;
                break;
            case 'H':
                cout << "MAZE Network Node - Performance Tests" << endl;
                cout << "Usage: " << argv[0] << " [options]" << endl;
                cout << "Options:" << endl;
                cout << "  --hp <num>        Node horizontal position [0-7] (default: 3)" << endl;
                cout << "  --vp <num>        Node vertical position [0-7] (default: 2)" << endl;
                cout << "  --vcd             Enable VCD waveform generation" << endl;
                cout << "  --verbose         Enable verbose output" << endl;
                cout << "  --packets <n>     Number of test packets (100-10000, default: 1000)" << endl;
                cout << "  --help            Show this help message" << endl;
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
// Performance Test Functions
// ====================================================================

bool test_maximum_throughput(NodeSimulator& sim, PerformanceMetrics& metrics,
                             PerformanceTestGenerator& generator, uint32_t packet_count) {
    if (getenv("VERBOSE")) cout << "[PERF] Testing maximum throughput with " << packet_count << " packets..." << endl;

    metrics.reset();
    auto test_packets = generator.generate_load_test_packets(packet_count);

    sim.reset_sequence();
    sim.clear_inputs();

    auto start_time = chrono::high_resolution_clock::now();
    uint64_t start_cycles = sim.get_simulation_time();

    // Send packets as fast as possible
    for (size_t i = 0; i < test_packets.size(); i++) {
        if (sim.is_input_ready()) {
            sim.send_packet(test_packets[i].data);
            metrics.packets_sent++;
        }

        // Minimal spacing for maximum throughput
        sim.step();
    }

    // Wait for pipeline to drain
    sim.run_cycles(100);

    auto end_time = chrono::high_resolution_clock::now();
    uint64_t end_cycles = sim.get_simulation_time();

    // Collect outputs
    for (int i = 0; i < 200; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 5)) {
            metrics.packets_received++;
        }
    }

    metrics.total_cycles = end_cycles - start_cycles;
    metrics.execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();

    metrics.calculate_throughput();
    metrics.calculate_efficiency();

    if (getenv("VERBOSE")) {
        cout << "[PERF] Throughput test completed:" << endl;
        cout << "  Sent: " << metrics.packets_sent << ", Received: " << metrics.packets_received << endl;
        cout << "  Throughput: " << fixed << setprecision(0) << metrics.throughput_pps << " pps" << endl;
        cout << "  Efficiency: " << fixed << setprecision(1) << (100.0 * metrics.pipeline_efficiency) << "%" << endl;
    }

    return sim.validate_node_state() && (metrics.packets_received >= metrics.packets_sent * 0.8);
}

bool test_average_latency(NodeSimulator& sim, PerformanceMetrics& metrics,
                          PerformanceTestGenerator& generator, uint32_t packet_count) {
    if (getenv("VERBOSE")) cout << "[PERF] Testing average latency with " << packet_count << " packets..." << endl;

    metrics.reset();
    auto test_packets = generator.generate_qos_load_packets(packet_count, 0.5);

    sim.reset_sequence();
    sim.clear_inputs();

    vector<uint64_t> send_times;
    send_times.reserve(test_packets.size());

    auto start_time = chrono::high_resolution_clock::now();

    // Send packets with timing
    for (size_t i = 0; i < test_packets.size(); i++) {
        uint64_t send_time = sim.get_simulation_time();
        send_times.push_back(send_time);

        if (sim.is_input_ready()) {
            sim.send_packet(test_packets[i].data);
            metrics.packets_sent++;
        }

        // Small spacing to avoid complete saturation
        sim.run_cycles(2);
    }

    // Wait and collect outputs with latency measurement
    for (int i = 0; i < 300; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 8)) {
            uint64_t recv_time = sim.get_simulation_time();
            metrics.packets_received++;

            // Find corresponding send time (simplified matching)
            if (!send_times.empty()) {
                uint64_t send_time = send_times.front();
                send_times.erase(send_times.begin());

                double latency = static_cast<double>(recv_time - send_time);
                metrics.latency_samples.push_back(latency);
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();

    metrics.total_cycles = sim.get_simulation_time();
    metrics.execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();

    metrics.calculate_latency();
    metrics.calculate_efficiency();

    if (getenv("VERBOSE")) {
        cout << "[PERF] Latency test completed:" << endl;
        cout << "  Packets with latency data: " << metrics.latency_samples.size() << endl;
        cout << "  Average latency: " << fixed << setprecision(2) << metrics.avg_latency_cycles << " cycles" << endl;
        cout << "  Min/Max latency: " << fixed << setprecision(2)
             << metrics.min_latency_cycles << "/" << metrics.max_latency_cycles << " cycles" << endl;
    }

    return sim.validate_node_state() && !metrics.latency_samples.empty();
}

bool test_stress_conditions(NodeSimulator& sim, PerformanceMetrics& metrics,
                            PerformanceTestGenerator& generator, uint32_t packet_count) {
    if (getenv("VERBOSE")) cout << "[PERF] Testing stress conditions with high contention..." << endl;

    metrics.reset();
    auto test_packets = generator.generate_stress_test_packets(packet_count, 0.8);

    sim.reset_sequence();
    sim.clear_inputs();

    auto start_time = chrono::high_resolution_clock::now();

    // Apply backpressure initially
    sim.dut_->pkt_out_ready = 0;

    // Send packets rapidly to create stress
    for (size_t i = 0; i < test_packets.size(); i++) {
        if (sim.is_input_ready()) {
            sim.send_packet(test_packets[i].data);
            metrics.packets_sent++;
        }

        // Very minimal spacing
        sim.step();

        // Release backpressure after some packets
        if (i == packet_count / 3) {
            sim.dut_->pkt_out_ready = 1;
        }
    }

    // Extended processing time for stress conditions
    sim.run_cycles(200);

    auto end_time = chrono::high_resolution_clock::now();

    // Collect outputs
    for (int i = 0; i < 400; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 10)) {
            metrics.packets_received++;
        }
    }

    metrics.total_cycles = sim.get_simulation_time();
    metrics.execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();

    metrics.calculate_throughput();
    metrics.calculate_efficiency();

    if (getenv("VERBOSE")) {
        cout << "[PERF] Stress test completed:" << endl;
        cout << "  Success rate: " << fixed << setprecision(2)
             << (metrics.packets_sent > 0 ? 100.0 * metrics.packets_received / metrics.packets_sent : 0.0) << "%" << endl;
        cout << "  Throughput under stress: " << fixed << setprecision(0) << metrics.throughput_pps << " pps" << endl;
    }

    return sim.validate_node_state() && (metrics.packets_received >= metrics.packets_sent * 0.6);
}

bool test_qos_performance(NodeSimulator& sim, PerformanceMetrics& metrics,
                         PerformanceTestGenerator& generator, uint32_t packet_count) {
    if (getenv("VERBOSE")) cout << "[PERF] Testing QoS impact on performance..." << endl;

    metrics.reset();
    auto test_packets = generator.generate_qos_load_packets(packet_count, 0.4);

    sim.reset_sequence();
    sim.clear_inputs();

    uint32_t high_qos_sent = 0;
    uint32_t high_qos_received = 0;
    uint32_t low_qos_sent = 0;
    uint32_t low_qos_received = 0;

    auto start_time = chrono::high_resolution_clock::now();

    // Send packets with QoS tracking
    for (size_t i = 0; i < test_packets.size(); i++) {
        if (sim.is_input_ready()) {
            bool is_high_qos = PacketUtils::is_high_qos_packet(test_packets[i].data);
            if (is_high_qos) {
                high_qos_sent++;
            } else {
                low_qos_sent++;
            }

            sim.send_packet(test_packets[i].data);
            metrics.packets_sent++;
        }

        sim.run_cycles(1);
    }

    // Wait for processing
    sim.run_cycles(150);

    auto end_time = chrono::high_resolution_clock::now();

    // Collect outputs with QoS tracking
    for (int i = 0; i < 300; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 8)) {
            bool is_high_qos = PacketUtils::is_high_qos_packet(output_data);
            if (is_high_qos) {
                high_qos_received++;
            } else {
                low_qos_received++;
            }
            metrics.packets_received++;
        }
    }

    metrics.total_cycles = sim.get_simulation_time();
    metrics.execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();

    metrics.calculate_throughput();
    metrics.calculate_efficiency();

    if (getenv("VERBOSE")) {
        double high_qos_rate = (high_qos_sent > 0) ? 100.0 * high_qos_received / high_qos_sent : 0.0;
        double low_qos_rate = (low_qos_sent > 0) ? 100.0 * low_qos_received / low_qos_sent : 0.0;

        cout << "[PERF] QoS performance test completed:" << endl;
        cout << "  High QoS success rate: " << fixed << setprecision(2) << high_qos_rate << "%" << endl;
        cout << "  Low QoS success rate: " << fixed << setprecision(2) << low_qos_rate << "%" << endl;
        cout << "  Overall throughput: " << fixed << setprecision(0) << metrics.throughput_pps << " pps" << endl;
    }

    return sim.validate_node_state() && (metrics.packets_received >= metrics.packets_sent * 0.7);
}

// ====================================================================
// Main Test Execution
// ====================================================================

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        PerformanceTestConfig config = parse_arguments(argc, argv);

        // Set verbose flag
        if (config.verbose) {
            setenv("VERBOSE", "1", 1);
        }

        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - Performance Tests" << endl;
        cout << "Node Position: (" << config.hp << ", " << config.vp << ")" << endl;
        cout << "Test Packets: " << config.packet_count << endl;
        cout << "Max Cycles: " << config.max_cycles << endl;
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
        sim_config.max_cycles = config.max_cycles;

        NodeSimulator sim(sim_config);
        if (!sim.initialize()) {
            cerr << "[FATAL] Failed to initialize node simulator" << endl;
            return 1;
        }

        // Create performance test generator and metrics
        PerformanceTestGenerator generator(54321);
        PerformanceMetrics overall_metrics;

        // Create test suite
        TestSuite suite("Performance Tests", config.verbose);

        // Run performance tests
        bool throughput_result = suite.run_test("Maximum Throughput",
                                               "Test maximum packet throughput",
                                               [&sim, &overall_metrics, &generator, &config]() {
                                                   return test_maximum_throughput(sim, overall_metrics, generator, config.packet_count);
                                               });

        suite.run_test("Average Latency",
                      "Test average packet latency",
                      [&sim, &overall_metrics, &generator, &config]() {
                          return test_average_latency(sim, overall_metrics, generator, config.packet_count / 2);
                      });

        suite.run_test("Stress Conditions",
                      "Test performance under stress conditions",
                      [&sim, &overall_metrics, &generator, &config]() {
                          return test_stress_conditions(sim, overall_metrics, generator, config.packet_count);
                      });

        suite.run_test("QoS Performance",
                      "Test performance impact of QoS arbitration",
                      [&sim, &overall_metrics, &generator, &config]() {
                          return test_qos_performance(sim, overall_metrics, generator, config.packet_count);
                      });

        // Print detailed metrics for throughput test
        if (throughput_result && config.verbose) {
            overall_metrics.print_metrics();
        }

        // Evaluate overall performance
        bool performance_acceptable = overall_metrics.is_performance_acceptable();

        // Print results
        suite.print_summary();

        // Save results
        suite.save_results("performance_test_results.txt");

        // Print final status
        cout << "\n" << string(80, '=') << endl;
        if (suite.all_passed() && performance_acceptable) {
            cout << "SUCCESS: All performance tests passed!" << endl;
            cout << "Node performance meets requirements." << endl;
        } else if (suite.all_passed()) {
            cout << "WARNING: Tests passed but performance may need improvement." << endl;
            cout << "See detailed metrics above for specific areas." << endl;
        } else {
            cout << "FAILURE: Some performance tests failed!" << endl;
            cout << "Performance implementation needs attention." << endl;
        }
        cout << string(80, '=') << endl;

        // Print simulator statistics
        sim.print_stats();

        // Return appropriate exit code
        return (suite.all_passed() && performance_acceptable) ? 0 : 1;

    } catch (const exception& e) {
        cerr << "[FATAL] Exception in main: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "[FATAL] Unknown exception in main" << endl;
        return 1;
    }
}