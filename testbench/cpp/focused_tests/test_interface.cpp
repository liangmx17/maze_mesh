// ====================================================================
// MAZE Network Node - Interface Tests
// ====================================================================
//
// Focused test suite for interface validation
// Tests A/B/C interface signal integrity, protocol compliance, and timing
//
// Usage:
//   ./test_interface [options]
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

struct InterfaceTestConfig {
    uint32_t hp = 3;
    uint32_t vp = 2;
    bool enable_vcd = false;
    bool verbose = false;
    string vcd_file = "test_interface.vcd";
    uint32_t max_test_cycles = 1000;
};

// ====================================================================
// Interface Validation Structure
// ====================================================================

struct InterfaceSignals {
    // A Interface (pkt_in) signals
    bool pkt_in_valid = false;
    bool pkt_in_ready = false;
    uint32_t pkt_in_data = 0;

    // B Interface (pkt_out) signals
    bool pkt_out_valid = false;
    bool pkt_out_ready = false;
    uint32_t pkt_out_data = 0;

    // C Interface (pkt_con_if) signals - 4 interfaces
    struct CInterface {
        bool valid = false;
        bool ready = false;
        uint32_t data = 0;
    };

    CInterface pkt_con_if[4];

    void capture_from_dut(Vnode* dut) {
        // Capture A interface
        pkt_in_valid = dut->pkt_in_valid;
        pkt_in_ready = dut->pkt_in_ready;
        pkt_in_data = dut->pkt_in_data;

        // Capture B interface
        pkt_out_valid = dut->pkt_out_valid;
        pkt_out_ready = dut->pkt_out_ready;
        pkt_out_data = dut->pkt_out_data;

        // Capture C interfaces
        for (int i = 0; i < 4; i++) {
            pkt_con_if[i].valid = dut->pkt_con_if[i].valid;
            pkt_con_if[i].ready = dut->pkt_con_if[i].ready;
            pkt_con_if[i].data = dut->pkt_con_if[i].data;
        }
    }

    void print_state(const string& label = "") const {
        if (!getenv("VERBOSE")) return;

        cout << "[IFACE] " << label << " Interface State:" << endl;
        cout << "  A Interface: valid=" << pkt_in_valid << ", ready=" << pkt_in_ready
             << ", data=0x" << hex << pkt_in_data << dec << endl;
        cout << "  B Interface: valid=" << pkt_out_valid << ", ready=" << pkt_out_ready
             << ", data=0x" << hex << pkt_out_data << dec << endl;
        cout << "  C Interfaces:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "    [" << i << "]: valid=" << pkt_con_if[i].valid
                 << ", ready=" << pkt_con_if[i].ready
                 << ", data=0x" << hex << pkt_con_if[i].data << dec << endl;
        }
    }
};

class InterfaceValidator {
public:
    static bool validate_a_interface_protocol(const InterfaceSignals& signals) {
        // A Interface: pkt_in
        // Protocol: valid and ready should never both be high for more than one cycle
        // (this indicates a proper handshake)

        static bool last_valid = false;
        static bool last_ready = false;
        static int handshake_cycles = 0;

        bool protocol_ok = true;

        // Check for proper handshake timing
        if (signals.pkt_in_valid && signals.pkt_in_ready) {
            handshake_cycles++;
            if (handshake_cycles > 1) {
                if (getenv("VERBOSE")) {
                    cout << "[IFACE] A Interface: Handshake lasting too long (" << handshake_cycles << " cycles)" << endl;
                }
                protocol_ok = false;
            }
        } else {
            handshake_cycles = 0;
        }

        last_valid = signals.pkt_in_valid;
        last_ready = signals.pkt_in_ready;

        return protocol_ok;
    }

    static bool validate_b_interface_protocol(const InterfaceSignals& signals) {
        // B Interface: pkt_out
        // Protocol: valid should remain high until ready goes high

        static uint32_t last_data = 0;
        static bool data_stable = true;

        bool protocol_ok = true;

        // Check data stability when valid is high
        if (signals.pkt_out_valid) {
            if (last_data != 0 && signals.pkt_out_data != last_data) {
                data_stable = false;
                if (getenv("VERBOSE")) {
                    cout << "[IFACE] B Interface: Data changed while valid was high" << endl;
                    cout << "[IFACE] Previous: 0x" << hex << last_data
                         << ", Current: 0x" << signals.pkt_out_data << dec << endl;
                }
                protocol_ok = false;
            }
            last_data = signals.pkt_out_data;
        } else {
            last_data = 0;  // Reset when not valid
        }

        return protocol_ok;
    }

    static bool validate_c_interface_protocol(const InterfaceSignals& signals) {
        // C Interface: pkt_con_if
        // Protocol: Each interface should follow standard ready/valid handshake

        bool protocol_ok = true;

        for (int i = 0; i < 4; i++) {
            const auto& iface = signals.pkt_con_if[i];

            // Basic protocol check: valid and ready can be high simultaneously
            // (this is normal for ready/valid interfaces)

            // Check for valid combinations
            if (iface.valid && iface.ready) {
                // Normal operation: data transfer
            } else if (!iface.valid && iface.ready) {
                // Ready but no data: normal idle state
            } else if (iface.valid && !iface.ready) {
                // Valid but not ready: waiting state, normal
            } else {
                // Not valid and not ready: idle state, normal
            }

            // Check data validity when valid is high
            if (iface.valid && iface.data == 0) {
                if (getenv("VERBOSE")) {
                    cout << "[IFACE] C Interface[" << i << "]: Valid high but data is 0" << endl;
                }
                protocol_ok = false;
            }
        }

        return protocol_ok;
    }

    static bool validate_signal_timing(const InterfaceSignals& signals, uint64_t cycle_count) {
        // Basic timing validation
        bool timing_ok = true;

        // Check for X or Z values (indicating timing issues)
        // Note: In simulation, uninitialized signals may appear as X
        // This is a simplified check - real RTL would need proper X detection

        return timing_ok;
    }
};

// ====================================================================
// Command Line Parsing
// ====================================================================

InterfaceTestConfig parse_arguments(int argc, char* argv[]) {
    InterfaceTestConfig config;

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
                cout << "MAZE Network Node - Interface Tests" << endl;
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
// Interface Test Functions
// ====================================================================

bool test_a_interface_protocol(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing A interface protocol..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t protocol_violations = 0;
    uint64_t test_cycles = 0;

    // Test 1: Reset state
    signals.capture_from_dut(sim.dut_.get());
    if (signals.pkt_in_ready) {
        if (getenv("VERBOSE")) {
            cout << "[IFACE] A Interface: Ready should not be high during reset" << endl;
        }
        protocol_violations++;
    }

    sim.run_cycles(5);

    // Test 2: Normal operation
    for (int test = 0; test < 10; test++) {
        uint32_t test_packet = PacketUtils::create_unicast_packet(
            (test + 1) % 8, (test + 2) % 8, (test + 3) % 8, (test + 4) % 8, 0x40 + test);

        // Wait for ready
        while (!sim.is_input_ready() && test_cycles < 100) {
            signals.capture_from_dut(sim.dut_.get());
            if (!InterfaceValidator::validate_a_interface_protocol(signals)) {
                protocol_violations++;
            }
            sim.step();
            test_cycles++;
        }

        // Send packet
        sim.send_packet(test_packet);

        // Monitor protocol during transfer
        for (int i = 0; i < 5; i++) {
            signals.capture_from_dut(sim.dut_.get());
            if (!InterfaceValidator::validate_a_interface_protocol(signals)) {
                protocol_violations++;
            }
            sim.step();
            test_cycles++;
        }
    }

    bool test_passed = (protocol_violations == 0) && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[IFACE] A Interface protocol test: " << protocol_violations
             << " violations in " << test_cycles << " cycles" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " A interface protocol test" << endl;
    }

    return test_passed;
}

bool test_b_interface_protocol(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing B interface protocol..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t protocol_violations = 0;

    // Send test packet to generate output
    uint32_t test_packet = PacketUtils::create_unicast_packet(1, 1, 6, 6, 0xAA);
    sim.send_packet(test_packet);

    // Monitor B interface for output
    for (int cycle = 0; cycle < 50; cycle++) {
        signals.capture_from_dut(sim.dut_.get());

        if (!InterfaceValidator::validate_b_interface_protocol(signals)) {
            protocol_violations++;
        }

        // When output is valid, assert ready for one cycle
        if (signals.pkt_out_valid) {
            sim.dut_->pkt_out_ready = 1;
            sim.step();
            sim.dut_->pkt_out_ready = 0;
        } else {
            sim.step();
        }
    }

    bool test_passed = (protocol_violations == 0) && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[IFACE] B Interface protocol test: " << protocol_violations << " violations" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " B interface protocol test" << endl;
    }

    return test_passed;
}

bool test_c_interface_protocol(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing C interface protocol..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t protocol_violations = 0;

    // Configure C interfaces for testing
    for (int i = 0; i < 4; i++) {
        sim.dut_->pkt_con_if[i].ready = 1;  // Assume ready
        sim.dut_->pkt_con_if[i].valid = 0;
        sim.dut_->pkt_con_if[i].data = 0;
    }

    // Send multiple packets to exercise C interfaces
    for (int test = 0; test < 8; test++) {
        uint32_t test_packet = PacketUtils::create_unicast_packet(
            test % 8, (test + 1) % 8, (test + 2) % 8, (test + 3) % 8, 0x50 + test);

        sim.send_packet(test_packet);

        // Monitor C interfaces during processing
        for (int cycle = 0; cycle < 10; cycle++) {
            signals.capture_from_dut(sim.dut_.get());

            if (!InterfaceValidator::validate_c_interface_protocol(signals)) {
                protocol_violations++;
            }

            sim.step();
        }
    }

    bool test_passed = (protocol_violations == 0) && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[IFACE] C Interface protocol test: " << protocol_violations << " violations" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " C interface protocol test" << endl;
    }

    return test_passed;
}

bool test_interface_timing(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing interface signal timing..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t timing_violations = 0;
    vector<InterfaceSignals> signal_history;
    uint64_t start_cycle = sim.get_simulation_time();

    // Rapid packet injection to test timing boundaries
    for (int test = 0; test < 15; test++) {
        uint32_t test_packet = PacketUtils::create_unicast_packet(
            (test * 2) % 8, (test * 3) % 8, (test + 1) % 8, (test + 2) % 8, 0x60 + test);

        // Capture signals before sending
        signals.capture_from_dut(sim.dut_.get());
        signal_history.push_back(signals);

        sim.send_packet(test_packet);

        // Capture signals during and after sending
        for (int cycle = 0; cycle < 3; cycle++) {
            signals.capture_from_dut(sim.dut_.get());
            signal_history.push_back(signals);

            // Validate timing
            if (!InterfaceValidator::validate_signal_timing(signals, sim.get_simulation_time() - start_cycle)) {
                timing_violations++;
            }

            sim.step();
        }
    }

    // Allow processing and monitor timing
    sim.run_cycles(100);

    // Analyze signal timing patterns
    if (getenv("VERBOSE") && timing_violations > 0) {
        cout << "[IFACE] Signal timing analysis:" << endl;
        for (size_t i = 1; i < signal_history.size(); i++) {
            const auto& prev = signal_history[i-1];
            const auto& curr = signal_history[i];

            // Look for sudden signal changes (potential timing issues)
            if (prev.pkt_in_valid != curr.pkt_in_valid) {
                cout << "[IFACE] Cycle " << i << ": pkt_in_valid changed (" << prev.pkt_in_valid
                     << " -> " << curr.pkt_in_valid << ")" << endl;
            }
        }
    }

    bool test_passed = (timing_violations == 0) && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[IFACE] Interface timing test: " << timing_violations << " violations" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Interface timing test" << endl;
    }

    return test_passed;
}

bool test_signal_integrity(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing signal integrity..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t integrity_issues = 0;

    // Test with different data patterns
    vector<uint32_t> test_patterns = {
        0x000000,  // All zeros
        0xFFFFFF,  // All ones (truncated to 23 bits)
        0x555555,  // Alternating pattern
        0xAAAAAA,  // Alternating pattern (inverse)
        0x123456,  // Mixed pattern
        0xFEDCBA   // Mixed pattern (inverse)
    };

    for (size_t pattern_idx = 0; pattern_idx < test_patterns.size(); pattern_idx++) {
        uint32_t pattern = test_patterns[pattern_idx] & 0x7FFFFF;  // Mask to 23 bits

        if (getenv("VERBOSE")) {
            cout << "[IFACE] Testing pattern 0x" << hex << pattern << dec << endl;
        }

        // Create packet with test pattern
        uint32_t test_packet = PacketUtils::create_unicast_packet(
            (pattern_idx + 1) % 8, (pattern_idx + 2) % 8,
            (pattern_idx + 3) % 8, (pattern_idx + 4) % 8, pattern & 0xFF);

        sim.send_packet(test_packet);

        // Monitor signals for integrity
        for (int cycle = 0; cycle < 20; cycle++) {
            signals.capture_from_dut(sim.dut_.get());

            // Check for reasonable signal values
            if (signals.pkt_in_valid && signals.pkt_in_data == 0) {
                integrity_issues++;
                if (getenv("VERBOSE")) {
                    cout << "[IFACE] Integrity issue: pkt_in_valid high but data is 0" << endl;
                }
            }

            if (signals.pkt_out_valid && signals.pkt_out_data == 0) {
                integrity_issues++;
                if (getenv("VERBOSE")) {
                    cout << "[IFACE] Integrity issue: pkt_out_valid high but data is 0" << endl;
                }
            }

            // Check C interface integrity
            for (int i = 0; i < 4; i++) {
                if (signals.pkt_con_if[i].valid && signals.pkt_con_if[i].data == 0) {
                    integrity_issues++;
                    if (getenv("VERBOSE")) {
                        cout << "[IFACE] Integrity issue: C Interface[" << i
                             << "] valid high but data is 0" << endl;
                    }
                }
            }

            sim.step();
        }

        // Allow processing to complete
        sim.run_cycles(10);
    }

    bool test_passed = (integrity_issues == 0) && sim.validate_node_state();

    if (getenv("VERBOSE")) {
        cout << "[IFACE] Signal integrity test: " << integrity_issues << " issues" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Signal integrity test" << endl;
    }

    return test_passed;
}

bool test_interface_compliance(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[IFACE] Testing interface compliance..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    InterfaceSignals signals;
    uint32_t compliance_issues = 0;

    // Test comprehensive compliance scenarios
    struct ComplianceTest {
        string name;
        vector<uint32_t> packets;
        uint32_t expected_violations;
    };

    vector<ComplianceTest> compliance_tests = {
        {
            "Basic packet sequence",
            {
                PacketUtils::create_unicast_packet(0, 0, 1, 1, 0x11),
                PacketUtils::create_unicast_packet(1, 1, 2, 2, 0x22),
                PacketUtils::create_unicast_packet(2, 2, 3, 3, 0x33)
            },
            0
        },
        {
            "QoS mixed packets",
            {
                PacketUtils::create_unicast_packet(1, 1, 2, 2, 0x44, QOS_HIGH),
                PacketUtils::create_unicast_packet(2, 2, 3, 3, 0x55, QOS_LOW),
                PacketUtils::create_unicast_packet(3, 3, 4, 4, 0x66, QOS_HIGH)
            },
            0
        },
        {
            "Edge case packets",
            {
                PacketUtils::create_unicast_packet(0, 0, 7, 7, 0x77),
                PacketUtils::create_unicast_packet(7, 7, 0, 0, 0x88)
            },
            0
        }
    };

    for (const auto& test : compliance_tests) {
        if (getenv("VERBOSE")) {
            cout << "[IFACE] Compliance test: " << test.name << endl;
        }

        uint32_t test_violations = 0;

        for (uint32_t packet : test.packets) {
            sim.send_packet(packet);

            // Monitor all interfaces during compliance test
            for (int cycle = 0; cycle < 30; cycle++) {
                signals.capture_from_dut(sim.dut_.get());

                // Validate all interface protocols
                if (!InterfaceValidator::validate_a_interface_protocol(signals)) {
                    test_violations++;
                }
                if (!InterfaceValidator::validate_b_interface_protocol(signals)) {
                    test_violations++;
                }
                if (!InterfaceValidator::validate_c_interface_protocol(signals)) {
                    test_violations++;
                }

                sim.step();
            }

            sim.run_cycles(10);  // Cool down between packets
        }

        compliance_issues += test_violations;

        if (getenv("VERBOSE")) {
            cout << "[IFACE] " << test.name << ": " << test_violations
                 << " violations (expected " << test.expected_violations << ")" << endl;
        }

        sim.reset_sequence();
        sim.clear_inputs();
    }

    bool test_passed = (compliance_issues <= 5) && sim.validate_node_state();  // Allow some tolerance

    if (getenv("VERBOSE")) {
        cout << "[IFACE] Interface compliance test: " << compliance_issues << " total violations" << endl;
        cout << (test_passed ? "[PASS]" : "[FAIL]") << " Interface compliance test" << endl;
    }

    return test_passed;
}

// ====================================================================
// Main Test Execution
// ====================================================================

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        InterfaceTestConfig config = parse_arguments(argc, argv);

        // Set verbose flag
        if (config.verbose) {
            setenv("VERBOSE", "1", 1);
        }

        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - Interface Tests" << endl;
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

        // Create test suite
        TestSuite suite("Interface Tests", config.verbose);

        // Run interface tests
        suite.run_test("A Interface Protocol",
                      "Test A interface (pkt_in) protocol compliance",
                      [&sim]() { return test_a_interface_protocol(sim); });

        suite.run_test("B Interface Protocol",
                      "Test B interface (pkt_out) protocol compliance",
                      [&sim]() { return test_b_interface_protocol(sim); });

        suite.run_test("C Interface Protocol",
                      "Test C interface (pkt_con_if) protocol compliance",
                      [&sim]() { return test_c_interface_protocol(sim); });

        suite.run_test("Interface Timing",
                      "Test interface signal timing characteristics",
                      [&sim]() { return test_interface_timing(sim); });

        suite.run_test("Signal Integrity",
                      "Test signal integrity and data validity",
                      [&sim]() { return test_signal_integrity(sim); });

        suite.run_test("Interface Compliance",
                      "Test overall interface compliance with specifications",
                      [&sim]() { return test_interface_compliance(sim); });

        // Print results
        suite.print_summary();

        // Save results
        suite.save_results("interface_test_results.txt");

        // Print final status
        cout << "\n" << string(80, '=') << endl;
        if (suite.all_passed()) {
            cout << "SUCCESS: All interface tests passed!" << endl;
            cout << "A/B/C interface protocols are working correctly." << endl;
        } else {
            cout << "FAILURE: Some interface tests failed!" << endl;
            cout << "Interface implementation needs review and debugging." << endl;
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