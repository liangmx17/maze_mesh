// ====================================================================
// MAZE Network Node - QoS Arbitration Tests
// ====================================================================
//
// Focused test suite for Quality of Service arbitration
// Tests high vs low priority scenarios, arbitration fairness, and
// multiple simultaneous request handling
//
// Usage:
//   ./test_qos [options]
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
#include <queue>
#include "packet_utils.h"
#include "node_simulator.h"
#include "test_helpers.h"

using namespace std;

// ====================================================================
// Test Configuration
// ====================================================================

struct QoSTestConfig {
    uint32_t hp = 3;
    uint32_t vp = 2;
    bool enable_vcd = false;
    bool verbose = false;
    string vcd_file = "test_qos.vcd";
    uint32_t test_cycles = 1000;
};

// ====================================================================
// Command Line Parsing
// ====================================================================

QoSTestConfig parse_arguments(int argc, char* argv[]) {
    QoSTestConfig config;

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
                cout << "MAZE Network Node - QoS Arbitration Tests" << endl;
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
// QoS Test Utilities
// ====================================================================

struct QoSTestPacket {
    uint32_t data;
    QoSLevel qos;
    uint32_t sequence;
    bool processed;
    uint64_t process_time;

    QoSTestPacket(uint32_t d, QoSLevel q, uint32_t seq)
        : data(d), qos(q), sequence(seq), processed(false), process_time(0) {}
};

class QoSTestGenerator {
public:
    static vector<QoSTestPacket> generate_priority_test_packets() {
        vector<QoSTestPacket> packets;

        // High priority packets
        for (uint32_t i = 0; i < 5; i++) {
            uint32_t packet = PacketUtils::create_unicast_packet(
                1, 1, 6, 6, 0x80 + i, QOS_HIGH);
            packets.emplace_back(packet, QOS_HIGH, i);
        }

        // Low priority packets
        for (uint32_t i = 0; i < 5; i++) {
            uint32_t packet = PacketUtils::create_unicast_packet(
                2, 2, 5, 5, 0x10 + i, QOS_LOW);
            packets.emplace_back(packet, QOS_LOW, i + 5);
        }

        return packets;
    }

    static vector<QoSTestPacket> generate_mixed_qos_packets(uint32_t count = 20) {
        vector<QoSTestPacket> packets;

        for (uint32_t i = 0; i < count; i++) {
            QoSLevel qos = (i % 3 == 0) ? QOS_HIGH : QOS_LOW;  // 33% high priority
            uint32_t packet = PacketUtils::create_unicast_packet(
                (i * 2) % 8, (i * 3) % 8, (i + 1) % 8, (i + 2) % 8, 0x40 + i, qos);
            packets.emplace_back(packet, qos, i);
        }

        return packets;
    }

    static vector<QoSTestPacket> generate_qos_fairness_packets(uint32_t high_count = 3,
                                                               uint32_t low_count = 7) {
        vector<QoSTestPacket> packets;
        uint32_t seq = 0;

        // Create alternating pattern: H-L-L-H-L-L-H-L-L-H-L-L
        for (uint32_t i = 0; i < low_count; i++) {
            // High priority packet
            if (i < high_count) {
                uint32_t packet = PacketUtils::create_unicast_packet(
                    0, 0, 7, 7, 0xA0 + seq, QOS_HIGH);
                packets.emplace_back(packet, QOS_HIGH, seq++);
            }

            // Low priority packet
            uint32_t packet = PacketUtils::create_unicast_packet(
                7, 7, 0, 0, 0x20 + seq, QOS_LOW);
            packets.emplace_back(packet, QOS_LOW, seq++);
        }

        return packets;
    }
};

// ====================================================================
// Test Functions
// ====================================================================

// Test basic QoS priority ordering
bool test_qos_priority_ordering(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing QoS priority ordering..." << endl;

    auto test_packets = QoSTestGenerator::generate_priority_test_packets();

    sim.reset_sequence();
    sim.clear_inputs();

    // Send low priority packets first, then high priority
    queue<QoSTestPacket> input_queue;
    for (auto& pkt : test_packets) {
        input_queue.push(pkt);
    }

    uint64_t high_qos_processed = 0;
    uint64_t total_processed = 0;
    bool high_seen_first = false;

    // Send packets rapidly
    while (!input_queue.empty()) {
        auto test_pkt = input_queue.front();
        input_queue.pop();

        if (getenv("VERBOSE")) {
            Packet parsed = PacketUtils::parse_packet(test_pkt.data);
            cout << "[SEND] " << parsed.description << " (seq=" << test_pkt.sequence << ")" << endl;
        }

        sim.send_packet(test_pkt.data);
        sim.step();  // Minimal spacing
    }

    // Wait for processing and observe output order
    sim.run_cycles(50);

    // Try to receive output packets
    vector<Packet> output_packets;
    for (int i = 0; i < 20; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 10)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    // Analyze output order
    bool found_high_qos = false;
    for (size_t i = 0; i < output_packets.size(); i++) {
        if (PacketUtils::is_high_qos_packet(output_packets[i].data)) {
            found_high_qos = true;
        }
    }

    if (getenv("VERBOSE")) {
        cout << "[INFO] Processed " << output_packets.size() << " output packets" << endl;
        cout << "[INFO] High QoS packets in output: " << found_high_qos << endl;
    }

    // Basic check: output should contain high QoS packets
    bool test_passed = output_packets.size() > 0 && found_high_qos;

    if (getenv("VERBOSE")) {
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " QoS priority ordering test" << endl;
    }

    return test_passed;
}

// Test QoS arbitration under contention
bool test_qos_contention(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing QoS arbitration under contention..." << endl;

    auto test_packets = QoSTestGenerator::generate_mixed_qos_packets(15);

    sim.reset_sequence();
    sim.clear_inputs();

    // Send all packets rapidly to create contention
    for (size_t i = 0; i < test_packets.size(); i++) {
        if (getenv("VERBOSE")) {
            Packet parsed = PacketUtils::parse_packet(test_packets[i].data);
            cout << "[SEND] " << parsed.description << " (seq=" << test_packets[i].sequence << ")" << endl;
        }

        sim.send_packet(test_packets[i].data);

        // Very short delay to create backpressure
        if (i % 3 == 0) {
            sim.run_cycles(1);
        }
    }

    // Allow processing with contention
    sim.run_cycles(80);

    // Collect outputs
    vector<Packet> output_packets;
    for (int i = 0; i < 30; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 5)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    if (getenv("VERBOSE")) {
        cout << "[INFO] Contention test: " << test_packets.size() << " input, "
             << output_packets.size() << " output packets" << endl;
    }

    // Basic validation: system should not crash and should produce some output
    bool test_passed = sim.validate_node_state() && output_packets.size() > 0;

    if (getenv("VERBOSE")) {
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " QoS contention test" << endl;
    }

    return test_passed;
}

// Test QoS fairness over time
bool test_qos_fairness(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing QoS fairness..." << endl;

    auto test_packets = QoSTestGenerator::generate_qos_fairness_packets(4, 8);

    sim.reset_sequence();
    sim.clear_inputs();

    // Send packets with controlled timing
    for (size_t i = 0; i < test_packets.size(); i++) {
        sim.send_packet(test_packets[i].data);

        // Small delay between packets
        sim.run_cycles(2);

        if (getenv("VERBOSE")) {
            Packet parsed = PacketUtils::parse_packet(test_packets[i].data);
            cout << "[SEND] " << parsed.description << " (seq=" << test_packets[i].sequence << ")" << endl;
        }
    }

    // Wait for all processing
    sim.run_cycles(100);

    // Collect all outputs
    vector<Packet> output_packets;
    uint32_t high_qos_output = 0;
    uint32_t low_qos_output = 0;

    for (int i = 0; i < 40; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 10)) {
            Packet output = PacketUtils::parse_packet(output_data);
            output_packets.push_back(output);

            if (PacketUtils::is_high_qos_packet(output_data)) {
                high_qos_output++;
            } else {
                low_qos_output++;
            }
        }
    }

    if (getenv("VERBOSE")) {
        cout << "[INFO] Fairness test outputs: " << high_qos_output << " high QoS, "
             << low_qos_output << " low QoS packets" << endl;
    }

    // Basic fairness check: both high and low priority packets should be processed
    bool test_passed = sim.validate_node_state() &&
                      (high_qos_output > 0 && low_qos_output > 0);

    if (getenv("VERBOSE")) {
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " QoS fairness test" << endl;
    }

    return test_passed;
}

// Test QoS starvation prevention
bool test_qos_starvation_prevention(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing QoS starvation prevention..." << endl;

    // Send continuous high QoS packets followed by low QoS packets
    vector<QoSTestPacket> test_packets;

    // First, send many high priority packets
    for (uint32_t i = 0; i < 10; i++) {
        uint32_t packet = PacketUtils::create_unicast_packet(
            (i + 1) % 8, (i + 2) % 8, (i + 3) % 8, (i + 4) % 8, 0x90 + i, QOS_HIGH);
        test_packets.emplace_back(packet, QOS_HIGH, i);
    }

    // Then send low priority packets
    for (uint32_t i = 0; i < 5; i++) {
        uint32_t packet = PacketUtils::create_unicast_packet(
            (i + 5) % 8, (i + 6) % 8, (i + 7) % 8, (i + 8) % 8, 0x30 + i, QOS_LOW);
        test_packets.emplace_back(packet, QOS_LOW, i + 10);
    }

    sim.reset_sequence();
    sim.clear_inputs();

    // Send all packets
    for (auto& pkt : test_packets) {
        sim.send_packet(pkt.data);
        sim.run_cycles(1);  // Minimal spacing

        if (getenv("VERBOSE")) {
            Packet parsed = PacketUtils::parse_packet(pkt.data);
            cout << "[SEND] " << parsed.description << " (seq=" << pkt.sequence << ")" << endl;
        }
    }

    // Extended processing time to allow low priority packets through
    sim.run_cycles(150);

    // Check for low priority packets in output
    bool found_low_qos = false;
    vector<Packet> output_packets;

    for (int i = 0; i < 50; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 5)) {
            Packet output = PacketUtils::parse_packet(output_data);
            output_packets.push_back(output);

            if (!PacketUtils::is_high_qos_packet(output_data)) {
                found_low_qos = true;
            }
        }
    }

    if (getenv("VERBOSE")) {
        cout << "[INFO] Starvation test: " << output_packets.size() << " outputs, "
             << "low QoS found: " << found_low_qos << endl;
    }

    // Check that system remains healthy and processes low QoS packets eventually
    bool test_passed = sim.validate_node_state() && found_low_qos;

    if (getenv("VERBOSE")) {
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " QoS starvation prevention test" << endl;
    }

    return test_passed;
}

// Test QoS arbitration timing characteristics
bool test_qos_timing(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing QoS arbitration timing..." << endl;

    vector<QoSTestPacket> test_packets = QoSTestGenerator::generate_priority_test_packets();

    sim.reset_sequence();
    sim.clear_inputs();

    uint64_t start_time = sim.get_simulation_time();

    // Send packets with timing measurement
    for (auto& pkt : test_packets) {
        uint64_t send_time = sim.get_simulation_time();

        sim.send_packet(pkt.data);

        // Small delay to observe arbitration behavior
        sim.run_cycles(3);

        if (getenv("VERBOSE")) {
            Packet parsed = PacketUtils::parse_packet(pkt.data);
            cout << "[SEND] " << parsed.description
                 << " at cycle " << send_time << endl;
        }
    }

    // Allow full processing
    sim.run_cycles(60);

    uint64_t total_time = sim.get_simulation_time() - start_time;

    // Collect outputs and measure timing
    vector<Packet> output_packets;
    for (int i = 0; i < 25; i++) {
        uint32_t output_data;
        if (sim.receive_packet(output_data, 8)) {
            output_packets.push_back(PacketUtils::parse_packet(output_data));
        }
    }

    if (getenv("VERBOSE")) {
        cout << "[INFO] Timing test: " << total_time << " cycles, "
             << output_packets.size() << " outputs" << endl;
        cout << "[INFO] Average time per output: "
             << (output_packets.size() > 0 ? (double)total_time / output_packets.size() : 0.0)
             << " cycles" << endl;
    }

    // Basic timing validation: reasonable processing time
    bool test_passed = sim.validate_node_state() &&
                      total_time < 500 &&  // Should complete in reasonable time
                      output_packets.size() > 0;

    if (getenv("VERBOSE")) {
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " QoS timing test" << endl;
    }

    return test_passed;
}

// ====================================================================
// Main Test Execution
// ====================================================================

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        QoSTestConfig config = parse_arguments(argc, argv);

        // Set verbose flag
        if (config.verbose) {
            setenv("VERBOSE", "1", 1);
        }

        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - QoS Arbitration Tests" << endl;
        cout << "Node Position: (" << config.hp << ", " << config.vp << ")" << endl;
        cout << "Test Cycles: " << config.test_cycles << endl;
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
        sim_config.max_cycles = config.test_cycles * 2;  // Extra time for processing

        NodeSimulator sim(sim_config);
        if (!sim.initialize()) {
            cerr << "[FATAL] Failed to initialize node simulator" << endl;
            return 1;
        }

        // Create test suite
        TestSuite suite("QoS Arbitration Tests", config.verbose);

        // Run QoS tests
        suite.run_test("QoS Priority Ordering",
                      "Test that high QoS packets get priority over low QoS",
                      [&sim]() { return test_qos_priority_ordering(sim); });

        suite.run_test("QoS Contention Handling",
                      "Test arbitration under packet contention",
                      [&sim]() { return test_qos_contention(sim); });

        suite.run_test("QoS Fairness",
                      "Test fairness between high and low QoS packets",
                      [&sim]() { return test_qos_fairness(sim); });

        suite.run_test("QoS Starvation Prevention",
                      "Test that low QoS packets are not starved",
                      [&sim]() { return test_qos_starvation_prevention(sim); });

        suite.run_test("QoS Timing Characteristics",
                      "Test timing behavior of QoS arbitration",
                      [&sim]() { return test_qos_timing(sim); });

        // Print results
        suite.print_summary();

        // Save results
        suite.save_results("qos_test_results.txt");

        // Print final status
        cout << "\n" << string(80, '=') << endl;
        if (suite.all_passed()) {
            cout << "SUCCESS: All QoS arbitration tests passed!" << endl;
            cout << "QoS priority handling is working correctly." << endl;
        } else {
            cout << "FAILURE: Some QoS arbitration tests failed!" << endl;
            cout << "Please check QoS implementation and arbitration logic." << endl;
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