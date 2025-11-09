// ====================================================================
// MAZE Network Node - Basic Functionality Tests
// ====================================================================
//
// Focused test suite for basic node functionality
// Tests unicast routing, local delivery, and packet format validation
//
// Usage:
//   ./test_basic [options]
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
#include "packet_utils.h"
#include "node_simulator.h"
#include "test_helpers.h"

using namespace std;

// ====================================================================
// Test Configuration
// ====================================================================

struct BasicTestConfig {
    uint32_t hp = 3;
    uint32_t vp = 2;
    bool enable_vcd = false;
    bool verbose = false;
    string vcd_file = "test_basic.vcd";
};

// ====================================================================
// Command Line Parsing
// ====================================================================

BasicTestConfig parse_arguments(int argc, char* argv[]) {
    BasicTestConfig config;

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
                cout << "MAZE Network Node - Basic Functionality Tests" << endl;
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

// Test packet format validation and parsing
bool test_packet_format() {
    if (getenv("VERBOSE")) cout << "[TEST] Testing packet format validation..." << endl;

    // Test valid packets
    vector<uint32_t> valid_packets;
    valid_packets.push_back(PacketUtils::create_unicast_packet(0, 0, 1, 1, 0xAA));
    valid_packets.push_back(PacketUtils::create_x_multicast_packet(2, 3, 5, 0x55));
    valid_packets.push_back(PacketUtils::create_y_multicast_packet(4, 1, 6, 0x66));
    valid_packets.push_back(PacketUtils::create_broadcast_packet(7, 7, 0xFF));

    for (auto packet : valid_packets) {
        if (!PacketUtils::is_valid_packet(packet)) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Valid packet rejected: 0x" << hex << packet << dec << endl;
            }
            return false;
        }

        Packet parsed = PacketUtils::parse_packet(packet);
        if (parsed.data != packet) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Packet parsing mismatch" << endl;
            }
            return false;
        }
    }

    // Test packet type detection
    uint32_t unicast = PacketUtils::create_unicast_packet(1, 1, 2, 2, 0x11);
    uint32_t broadcast = PacketUtils::create_broadcast_packet(0, 0, 0x99);

    if (!PacketUtils::is_unicast_packet(unicast) || !PacketUtils::is_broadcast_packet(broadcast)) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Packet type detection failed" << endl;
        }
        return false;
    }

    if (getenv("VERBOSE")) cout << "[PASS] Packet format validation tests" << endl;
    return true;
}

// Test unicast routing through the node
bool test_unicast_routing(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing unicast routing..." << endl;

    // Test different unicast scenarios
    vector<Packet> test_packets = {
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(0, 0, 7, 7, 0xAA)),
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(7, 7, 0, 0, 0x55)),
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(3, 2, 4, 5, 0x33)),
    };

    for (const auto& packet : test_packets) {
        sim.reset_sequence();
        sim.clear_inputs();

        if (getenv("VERBOSE")) {
            cout << "[TEST] Testing packet: " << packet.description << endl;
        }

        // Send packet through node
        if (!sim.send_packet(packet.data)) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Failed to send packet" << endl;
            }
            return false;
        }

        // Allow processing time
        sim.run_cycles(10);

        // Check node state is valid
        if (!sim.validate_node_state()) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Invalid node state after packet processing" << endl;
            }
            return false;
        }
    }

    if (getenv("VERBOSE")) cout << "[PASS] Unicast routing tests" << endl;
    return true;
}

// Test local delivery (source = target)
bool test_local_delivery(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing local delivery..." << endl;

    // Create packet with source = target (local delivery)
    uint32_t local_packet = PacketUtils::create_unicast_packet(3, 2, 3, 2, 0x77);
    Packet parsed = PacketUtils::parse_packet(local_packet);

    sim.reset_sequence();
    sim.clear_inputs();

    if (getenv("VERBOSE")) {
        cout << "[TEST] Testing local delivery: " << parsed.description << endl;
    }

    if (!sim.send_packet(local_packet)) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Failed to send local delivery packet" << endl;
        }
        return false;
    }

    // Local delivery should be faster
    sim.run_cycles(5);

    if (!sim.validate_node_state()) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Invalid node state after local delivery" << endl;
        }
        return false;
    }

    if (getenv("VERBOSE")) cout << "[PASS] Local delivery tests" << endl;
    return true;
}

// Test I/O interface signals
bool test_io_interface(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing I/O interface signals..." << endl;

    sim.reset_sequence();
    sim.clear_inputs();

    // Wait for node to be ready
    sim.run_cycles(3);

    // Check input ready signal
    if (!sim.is_input_ready()) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Input not ready after reset" << endl;
        }
        return false;
    }

    // Test packet injection
    uint32_t test_packet = PacketUtils::create_unicast_packet(1, 1, 2, 2, 0x44);
    if (!sim.send_packet(test_packet)) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Packet injection failed" << endl;
        }
        return false;
    }

    // Verify interface protocols
    sim.run_cycles(2);
    if (!sim.validate_node_state()) {
        if (getenv("VERBOSE")) {
            cout << "[FAIL] Interface protocol violation" << endl;
        }
        return false;
    }

    if (getenv("VERBOSE")) cout << "[PASS] I/O interface tests" << endl;
    return true;
}

// Test packet boundary conditions
bool test_boundary_conditions(NodeSimulator& sim) {
    if (getenv("VERBOSE")) cout << "[TEST] Testing boundary conditions..." << endl;

    // Test edge node coordinates
    vector<Packet> edge_packets = {
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(0, 0, 7, 7, 0xAA)),
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(7, 0, 0, 7, 0x55)),
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(0, 7, 7, 0, 0x33)),
        PacketUtils::parse_packet(PacketUtils::create_unicast_packet(7, 7, 0, 0, 0x77)),
    };

    for (const auto& packet : edge_packets) {
        sim.reset_sequence();
        sim.clear_inputs();

        if (getenv("VERBOSE")) {
            cout << "[TEST] Testing edge packet: " << packet.description << endl;
        }

        if (!sim.send_packet(packet.data)) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Failed to process edge packet" << endl;
            }
            return false;
        }

        sim.run_cycles(10);

        if (!sim.validate_node_state()) {
            if (getenv("VERBOSE")) {
                cout << "[FAIL] Invalid state after edge packet" << endl;
            }
            return false;
        }
    }

    if (getenv("VERBOSE")) cout << "[PASS] Boundary condition tests" << endl;
    return true;
}

// ====================================================================
// Main Test Execution
// ====================================================================

int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        BasicTestConfig config = parse_arguments(argc, argv);

        // Set verbose flag
        if (config.verbose) {
            setenv("VERBOSE", "1", 1);
        }

        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - Basic Functionality Tests" << endl;
        cout << "Node Position: (" << config.hp << ", " << config.vp << ")" << endl;
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
        sim_config.max_cycles = 5000;

        NodeSimulator sim(sim_config);
        if (!sim.initialize()) {
            cerr << "[FATAL] Failed to initialize node simulator" << endl;
            return 1;
        }

        // Create test suite
        TestSuite suite("Basic Functionality Tests", config.verbose);

        // Run tests
        suite.run_test("Packet Format Validation", "Test packet format and parsing",
                      []() { return test_packet_format(); });

        suite.run_test("Unicast Routing", "Test basic unicast packet routing",
                      [&sim]() { return test_unicast_routing(sim); });

        suite.run_test("Local Delivery", "Test local delivery (source = target)",
                      [&sim]() { return test_local_delivery(sim); });

        suite.run_test("I/O Interface", "Test input/output interface signals",
                      [&sim]() { return test_io_interface(sim); });

        suite.run_test("Boundary Conditions", "Test edge node packet routing",
                      [&sim]() { return test_boundary_conditions(sim); });

        // Print results
        suite.print_summary();

        // Save results
        suite.save_results("basic_test_results.txt");

        // Print final status
        cout << "\n" << string(80, '=') << endl;
        if (suite.all_passed()) {
            cout << "SUCCESS: All basic functionality tests passed!" << endl;
            cout << "Simulation completed successfully." << endl;
        } else {
            cout << "FAILURE: Some basic functionality tests failed!" << endl;
            cout << "Please check the detailed output above." << endl;
        }
        cout << string(80, '=') << endl;

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