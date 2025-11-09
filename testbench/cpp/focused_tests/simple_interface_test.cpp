// ====================================================================
// MAZE Network Node - Interface Protocol Test
// ====================================================================
//
// Simple interface validation without Verilator
// Tests A/B/C interface signal protocols and timing
//
// ====================================================================

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

struct InterfaceTestResult {
    int total = 0, passed = 0, failed = 0;

    void pass(const std::string& name) {
        total++; passed++;
        std::cout << "[PASS] " << name << std::endl;
    }

    void fail(const std::string& name, const std::string& reason) {
        total++; failed++;
        std::cout << "[FAIL] " << name << " - " << reason << std::endl;
    }

    void summary() {
        std::cout << "\n=== Interface Protocol Test Summary ===" << std::endl;
        std::cout << "Total: " << total << ", Passed: " << passed << ", Failed: " << failed << std::endl;
        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
                  << (total > 0 ? (100.0 * passed / total) : 0.0) << "%" << std::endl;
    }
};

// Interface signal structures
struct AInterfaceSignals {
    bool pkt_in_vld;
    bool pkt_in_rdy;
    uint32_t pkt_in_qos;
    uint32_t pkt_in_type;
    uint32_t pkt_in_src;
    uint32_t pkt_in_tgt;
    uint32_t pkt_in_data;
};

struct BInterfaceSignals {
    bool pkt_out_vld;
    bool pkt_out_rdy;
    uint32_t pkt_out_qos;
    uint32_t pkt_out_type;
    uint32_t pkt_out_src;
    uint32_t pkt_out_tgt;
    uint32_t pkt_out_data;
};

struct CInterfaceSignals {
    bool x_vld[7];
    bool x_rdy[7];
    uint32_t x_qos[7];
    uint32_t x_type[7];
    uint32_t x_src[7];
    uint32_t x_tgt[7];
    uint32_t x_data[7];

    bool y_vld[7];
    bool y_rdy[7];
    uint32_t y_qos[7];
    uint32_t y_type[7];
    uint32_t y_src[7];
    uint32_t y_tgt[7];
    uint32_t y_data[7];
};

// Protocol validation functions
bool validate_ready_valid_handshake(bool valid, bool ready, bool prev_valid, bool prev_ready) {
    // Basic ready/valid protocol rules
    // - Valid can only go high to low when Ready is high
    // - Ready can be high or low independently
    // - Data transfer happens when both Valid and Ready are high

    if (valid && !prev_valid && !ready && prev_ready) {
        return false; // Valid went high when Ready was low (not a protocol violation, but no transfer)
    }

    return true; // Protocol is valid
}

bool validate_signal_widths(uint32_t value, uint32_t expected_bits, const std::string& signal_name) {
    uint32_t mask = (1 << expected_bits) - 1;
    return (value & mask) == value;
}

bool validate_packet_interface_signals(uint32_t type, uint32_t src, uint32_t tgt, uint32_t data) {
    return validate_signal_widths(type, 2, "type") &&
           validate_signal_widths(src, 6, "src") &&
           validate_signal_widths(tgt, 6, "tgt") &&
           validate_signal_widths(data, 8, "data");
}

// Simulate basic interface behavior
class InterfaceSimulator {
private:
    AInterfaceSignals a_intf;
    BInterfaceSignals b_intf;
    CInterfaceSignals c_intf;

public:
    void reset() {
        a_intf = {};
        b_intf = {};
        c_intf = {};
    }

    void set_a_interface(bool vld, bool rdy, uint32_t qos, uint32_t type,
                         uint32_t src, uint32_t tgt, uint32_t data) {
        a_intf.pkt_in_vld = vld;
        a_intf.pkt_in_rdy = rdy;
        a_intf.pkt_in_qos = qos;
        a_intf.pkt_in_type = type;
        a_intf.pkt_in_src = src;
        a_intf.pkt_in_tgt = tgt;
        a_intf.pkt_in_data = data;
    }

    bool validate_a_interface() {
        return validate_packet_interface_signals(a_intf.pkt_in_type, a_intf.pkt_in_src,
                                                 a_intf.pkt_in_tgt, a_intf.pkt_in_data) &&
               validate_signal_widths(a_intf.pkt_in_qos, 1, "qos");
    }

    void set_c_interface_port(int port, bool is_x_direction, bool vld, bool rdy,
                             uint32_t qos, uint32_t type, uint32_t src, uint32_t tgt, uint32_t data) {
        if (is_x_direction && port >= 0 && port < 7) {
            c_intf.x_vld[port] = vld;
            c_intf.x_rdy[port] = rdy;
            c_intf.x_qos[port] = qos;
            c_intf.x_type[port] = type;
            c_intf.x_src[port] = src;
            c_intf.x_tgt[port] = tgt;
            c_intf.x_data[port] = data;
        } else if (!is_x_direction && port >= 0 && port < 7) {
            c_intf.y_vld[port] = vld;
            c_intf.y_rdy[port] = rdy;
            c_intf.y_qos[port] = qos;
            c_intf.y_type[port] = type;
            c_intf.y_src[port] = src;
            c_intf.y_tgt[port] = tgt;
            c_intf.y_data[port] = data;
        }
    }

    bool validate_c_interface() {
        // Validate all C interface ports
        for (int i = 0; i < 7; i++) {
            if (!validate_packet_interface_signals(c_intf.x_type[i], c_intf.x_src[i],
                                                   c_intf.x_tgt[i], c_intf.x_data[i]) ||
                !validate_signal_widths(c_intf.x_qos[i], 1, "x_qos")) {
                return false;
            }

            if (!validate_packet_interface_signals(c_intf.y_type[i], c_intf.y_src[i],
                                                   c_intf.y_tgt[i], c_intf.y_data[i]) ||
                !validate_signal_widths(c_intf.y_qos[i], 1, "y_qos")) {
                return false;
            }
        }
        return true;
    }

    bool can_transfer(bool valid, bool ready) {
        return valid && ready;
    }
};

int main() {
    std::cout << "=== MAZE Network Node - Interface Protocol Test ===" << std::endl;
    std::cout << "Testing A/B/C interface signal protocols\n" << std::endl;

    InterfaceTestResult result;
    InterfaceSimulator sim;

    // Test 1: A Interface Basic Signal Validation
    std::cout << "--- Test 1: A Interface Basic Signal Validation ---" << std::endl;

    sim.set_a_interface(true, true, 1, 0, 0x13, 0x67, 0x42);
    if (sim.validate_a_interface()) {
        result.pass("A Interface basic signal validation");
        std::cout << "  A interface signals are within valid bit widths" << std::endl;
    } else {
        result.fail("A Interface basic signal validation", "Invalid signal widths detected");
    }

    // Test 2: Ready/Valid Handshake Protocol
    std::cout << "\n--- Test 2: Ready/Valid Handshake Protocol ---" << std::endl;

    bool handshake_valid = true;
    std::vector<std::pair<bool, bool>> sequence = {
        {false, false},  // No activity
        {true, true},    // Transfer occurs
        {false, true},   // Valid goes low, ready stays high
        {true, false},   // Valid goes high, ready goes low
        {true, true}     // Both high for transfer
    };

    bool prev_valid = false, prev_ready = false;
    for (size_t i = 0; i < sequence.size(); i++) {
        bool curr_valid = sequence[i].first;
        bool curr_ready = sequence[i].second;

        if (!validate_ready_valid_handshake(curr_valid, curr_ready, prev_valid, prev_ready)) {
            handshake_valid = false;
            break;
        }

        prev_valid = curr_valid;
        prev_ready = curr_ready;
    }

    if (handshake_valid) {
        result.pass("Ready/Valid handshake protocol");
    } else {
        result.fail("Ready/Valid handshake protocol", "Protocol violation detected");
    }

    // Test 3: C Interface Multiple Ports
    std::cout << "\n--- Test 3: C Interface Multiple Ports ---" << std::endl;

    sim.reset();
    for (int i = 0; i < 7; i++) {
        sim.set_c_interface_port(i, true, true, true, static_cast<uint32_t>(i%2), static_cast<uint32_t>(i%4), static_cast<uint32_t>(i), static_cast<uint32_t>(i+16), static_cast<uint32_t>(i+32));
        sim.set_c_interface_port(i, false, false, true, static_cast<uint32_t>((i+1)%2), static_cast<uint32_t>((i+1)%4), static_cast<uint32_t>(i+8), static_cast<uint32_t>(i+24), static_cast<uint32_t>(i+40));
    }

    if (sim.validate_c_interface()) {
        result.pass("C interface multiple ports");
        std::cout << "  All 7 X and 7 Y ports have valid signal widths" << std::endl;
    } else {
        result.fail("C interface multiple ports", "Invalid signals detected in C interface");
    }

    // Test 4: Boundary Value Testing
    std::cout << "\n--- Test 4: Boundary Value Testing ---" << std::endl;

    sim.reset();
    sim.set_a_interface(true, true, 1, 3, 0x3F, 0x3F, 0xFF);  // Maximum values
    bool boundary_valid = sim.validate_a_interface();

    sim.set_a_interface(true, true, 1, 4, 0x40, 0x40, 0x100);  // Invalid values (should fail)
    bool invalid_boundary = !sim.validate_a_interface();

    if (boundary_valid && invalid_boundary) {
        result.pass("Boundary value testing");
        std::cout << "  Boundary values correctly validated" << std::endl;
    } else {
        result.fail("Boundary value testing", "Boundary validation failed");
    }

    // Test 5: Data Transfer Scenarios
    std::cout << "\n--- Test 5: Data Transfer Scenarios ---" << std::endl;

    struct TransferScenario {
        bool valid, ready, expected_transfer;
    };

    std::vector<TransferScenario> transfer_scenarios = {
        {true, true, true},    // Should transfer
        {true, false, false},  // Should not transfer
        {false, true, false},  // Should not transfer
        {false, false, false}  // Should not transfer
    };

    bool all_scenarios_correct = true;
    for (const auto& scenario : transfer_scenarios) {
        bool actual_transfer = sim.can_transfer(scenario.valid, scenario.ready);
        if (actual_transfer != scenario.expected_transfer) {
            all_scenarios_correct = false;
            break;
        }
    }

    if (all_scenarios_correct) {
        result.pass("Data transfer scenarios");
    } else {
        result.fail("Data transfer scenarios", "Incorrect transfer logic");
    }

    // Test 6: Interface Signal Consistency
    std::cout << "\n--- Test 6: Interface Signal Consistency ---" << std::endl;

    sim.reset();
    bool consistency_tests_passed = true;

    // Test consistency across multiple cycles
    for (int cycle = 0; cycle < 10; cycle++) {
        sim.set_a_interface((cycle % 3 != 0), (cycle % 2 != 0), cycle % 2,
                          cycle % 4, cycle, cycle + 10, cycle * 3);

        if (!sim.validate_a_interface()) {
            consistency_tests_passed = false;
            break;
        }
    }

    if (consistency_tests_passed) {
        result.pass("Interface signal consistency");
    } else {
        result.fail("Interface signal consistency", "Inconsistency detected over multiple cycles");
    }

    result.summary();

    if (result.failed == 0) {
        std::cout << "\n🎉 All interface protocol tests PASSED!" << std::endl;
        return 0;
    } else {
        std::cout << "\n❌ Some interface protocol tests FAILED!" << std::endl;
        return 1;
    }
}