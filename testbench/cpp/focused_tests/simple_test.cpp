// ====================================================================
// MAZE Network Node - Simple Validation Test
// ====================================================================
//
// Basic validation test for MAZE network node concepts
// Tests packet format, routing logic, and basic functionality
// without requiring Verilator compilation
//
// ====================================================================

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <vector>

// ====================================================================
// Packet Format Constants
// ====================================================================
const int PKT_W = 23;
const int TYPE_W = 2;
const int QOS_W = 1;
const int ID_W = 6;
const int DATA_W = 8;

// Packet bit positions
const int TYPE_MSB = 22;
const int TYPE_LSB = 21;
const int QOS_BIT = 20;
const int SRC_MSB = 19;
const int SRC_LSB = 14;
const int TGT_MSB = 13;
const int TGT_LSB = 8;
const int DATA_MSB = 7;
const int DATA_LSB = 0;

// Packet types
const uint32_t PKT_TYPE_UNICAST = 0;
const uint32_t PKT_TYPE_X_MULTICAST = 1;
const uint32_t PKT_TYPE_Y_MULTICAST = 2;
const uint32_t PKT_TYPE_BROADCAST = 3;

// ====================================================================
// Test Structure
// ====================================================================
struct TestResult {
    int total = 0;
    int passed = 0;
    int failed = 0;

    void pass(const std::string& name) {
        total++;
        passed++;
        std::cout << "[PASS] " << name << std::endl;
    }

    void fail(const std::string& name, const std::string& reason) {
        total++;
        failed++;
        std::cout << "[FAIL] " << name << " - " << reason << std::endl;
    }

    void summary() {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Total: " << total << std::endl;
        std::cout << "Passed: " << passed << std::endl;
        std::cout << "Failed: " << failed << std::endl;
        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
                  << (total > 0 ? (100.0 * passed / total) : 0.0) << "%" << std::endl;
    }

    bool all_passed() const {
        return failed == 0;
    }
};

// ====================================================================
// Packet Creation and Validation Functions
// ====================================================================

uint32_t create_packet(uint32_t type, uint32_t qos, uint32_t src_x, uint32_t src_y,
                      uint32_t tgt_x, uint32_t tgt_y, uint32_t data) {
    uint32_t packet = 0;

    // Check bounds
    if (type > 3 || qos > 1 || src_x > 7 || src_y > 7 || tgt_x > 7 || tgt_y > 7 || data > 0xFF) {
        return 0; // Invalid packet
    }

    uint32_t src_id = (src_y << 3) | src_x;
    uint32_t tgt_id = (tgt_y << 3) | tgt_x;

    packet |= (type & 0x3) << TYPE_LSB;
    packet |= (qos & 0x1) << QOS_BIT;
    packet |= (src_id & 0x3F) << SRC_LSB;
    packet |= (tgt_id & 0x3F) << TGT_LSB;
    packet |= (data & 0xFF) << DATA_LSB;

    return packet;
}

bool validate_packet(uint32_t packet) {
    // Check if packet fits in 23 bits
    if (packet > 0x7FFFFF) return false;

    // Extract fields
    uint32_t type = (packet >> TYPE_LSB) & 0x3;
    uint32_t src_id = (packet >> SRC_LSB) & 0x3F;
    uint32_t tgt_id = (packet >> TGT_LSB) & 0x3F;

    // Validate ranges
    if (type > 3) return false;
    if (src_id > 0x3F) return false;
    if (tgt_id > 0x3F) return false;

    return true;
}

uint32_t coord_to_id(uint32_t x, uint32_t y) {
    return (y << 3) | x;
}

// ====================================================================
// Routing Logic Functions (simulating the fixed node logic)
// ====================================================================

void calculate_intermediate_nodes(uint32_t src_x, uint32_t src_y,
                                uint32_t tgt_x, uint32_t tgt_y,
                                uint32_t& int1_x, uint32_t& int1_y,
                                uint32_t& int2_x, uint32_t& int2_y) {
    // Calculate intermediate nodes based on MAZE routing algorithm
    int1_x = tgt_x;  // [src_y, tgt_x]
    int1_y = src_y;

    int2_x = src_x;  // [tgt_y, src_x]
    int2_y = tgt_y;
}

// Simulate fault avoidance logic
uint32_t select_intermediate_with_fault(uint32_t int1_id, uint32_t int2_id,
                                      uint32_t fault_node_id, bool pg_en) {
    if (pg_en && (fault_node_id == int1_id)) {
        return int2_id;  // Use second intermediate if first is faulted
    } else {
        return int1_id;  // Otherwise use first intermediate
    }
}

// ====================================================================
// Main Test Function
// ====================================================================

int main() {
    std::cout << "=== MAZE Network Node - Simple Validation Test ===" << std::endl;
    std::cout << "Testing packet format, routing logic, and basic functionality\n" << std::endl;

    TestResult result;

    // Test 1: Packet creation and validation
    std::cout << "\n--- Test 1: Packet Creation and Validation ---" << std::endl;

    uint32_t test_packet = create_packet(PKT_TYPE_UNICAST, 1, 3, 2, 6, 7, 0x42);
    if (validate_packet(test_packet)) {
        result.pass("Packet creation and validation");
        std::cout << "  Created packet: 0x" << std::hex << test_packet << std::dec << std::endl;
    } else {
        result.fail("Packet creation and validation", "Invalid packet created");
    }

    // Test 2: Packet field extraction
    std::cout << "\n--- Test 2: Packet Field Extraction ---" << std::endl;

    uint32_t type = (test_packet >> TYPE_LSB) & 0x3;
    uint32_t qos = (test_packet >> QOS_BIT) & 0x1;
    uint32_t src_id = (test_packet >> SRC_LSB) & 0x3F;
    uint32_t tgt_id = (test_packet >> TGT_LSB) & 0x3F;
    uint32_t data = (test_packet >> DATA_LSB) & 0xFF;

    if (type == PKT_TYPE_UNICAST && qos == 1 && src_id == 0x13 && tgt_id == 0x67 && data == 0x42) {
        result.pass("Packet field extraction");
        std::cout << "  Type: " << type << ", QoS: " << qos << ", Src: 0x" << std::hex << src_id
                  << ", Tgt: 0x" << tgt_id << ", Data: 0x" << data << std::dec << std::endl;
    } else {
        result.fail("Packet field extraction", "Incorrect field values extracted");
    }

    // Test 3: Intermediate node calculation
    std::cout << "\n--- Test 3: Intermediate Node Calculation ---" << std::endl;

    uint32_t src_x = 3, src_y = 2, tgt_x = 6, tgt_y = 7;
    uint32_t int1_x, int1_y, int2_x, int2_y;

    calculate_intermediate_nodes(src_x, src_y, tgt_x, tgt_y, int1_x, int1_y, int2_x, int2_y);

    uint32_t expected_int1_x = 6, expected_int1_y = 2;  // [src_y, tgt_x]
    uint32_t expected_int2_x = 3, expected_int2_y = 7;  // [tgt_y, src_x]

    if (int1_x == expected_int1_x && int1_y == expected_int1_y &&
        int2_x == expected_int2_x && int2_y == expected_int2_y) {
        result.pass("Intermediate node calculation");
        std::cout << "  Source: (" << src_x << "," << src_y << ") -> Target: (" << tgt_x << "," << tgt_y << ")" << std::endl;
        std::cout << "  Intermediate 1: (" << int1_x << "," << int1_y << ") [src_y, tgt_x]" << std::endl;
        std::cout << "  Intermediate 2: (" << int2_x << "," << int2_y << ") [tgt_y, src_x]" << std::endl;
    } else {
        result.fail("Intermediate node calculation", "Incorrect intermediate coordinates");
    }

    // Test 4: Fault tolerance logic
    std::cout << "\n--- Test 4: Fault Tolerance Logic ---" << std::endl;

    uint32_t int1_id = (int1_y << 3) | int1_x;
    uint32_t int2_id = (int2_y << 3) | int2_x;
    uint32_t fault_node_id = int1_id;

    uint32_t selected_no_fault = select_intermediate_with_fault(int1_id, int2_id, fault_node_id, false);
    uint32_t selected_with_fault = select_intermediate_with_fault(int1_id, int2_id, fault_node_id, true);

    if (selected_no_fault == int1_id && selected_with_fault == int2_id) {
        result.pass("Fault tolerance logic");
        std::cout << "  No fault: selected intermediate " << selected_no_fault << std::endl;
        std::cout << "  With fault at " << fault_node_id << ": selected intermediate " << selected_with_fault << std::endl;
    } else {
        result.fail("Fault tolerance logic", "Incorrect fault handling");
    }

    // Test 5: Local delivery detection
    std::cout << "\n--- Test 5: Local Delivery Detection ---" << std::endl;

    uint32_t local_src_id = coord_to_id(3, 2);
    uint32_t local_tgt_id = coord_to_id(3, 2);

    bool is_local_delivery = (local_src_id == local_tgt_id);

    if (is_local_delivery) {
        result.pass("Local delivery detection");
        std::cout << "  Source and target at same node: local delivery detected" << std::endl;
    } else {
        result.fail("Local delivery detection", "Failed to detect local delivery");
    }

    // Test 6: QoS priority scenarios
    std::cout << "\n--- Test 6: QoS Priority Scenarios ---" << std::endl;

    uint32_t high_qos_packet = create_packet(PKT_TYPE_UNICAST, 1, 1, 1, 5, 5, 0x11);
    uint32_t low_qos_packet = create_packet(PKT_TYPE_UNICAST, 0, 2, 2, 6, 6, 0x22);

    bool high_qos_valid = validate_packet(high_qos_packet);
    bool low_qos_valid = validate_packet(low_qos_packet);

    if (high_qos_valid && low_qos_valid) {
        uint32_t high_qos_priority = (high_qos_packet >> QOS_BIT) & 0x1;
        uint32_t low_qos_priority = (low_qos_packet >> QOS_BIT) & 0x1;

        if (high_qos_priority > low_qos_priority) {
            result.pass("QoS priority scenarios");
            std::cout << "  High QoS packet priority: " << high_qos_priority << std::endl;
            std::cout << "  Low QoS packet priority: " << low_qos_priority << std::endl;
        } else {
            result.fail("QoS priority scenarios", "Incorrect priority levels");
        }
    } else {
        result.fail("QoS priority scenarios", "Invalid QoS packets created");
    }

    // Test 7: Edge cases and bounds checking
    std::cout << "\n--- Test 7: Edge Cases and Bounds Checking ---" << std::endl;

    // Test boundary values
    uint32_t boundary_packet = create_packet(3, 1, 7, 7, 0, 0, 0xFF);
    bool boundary_valid = validate_packet(boundary_packet);

    // Test invalid packet (too large)
    uint32_t invalid_packet = 0x800000;  // 24 bits, exceeds 23-bit limit
    bool invalid_valid = validate_packet(invalid_packet);

    if (boundary_valid && !invalid_valid) {
        result.pass("Edge cases and bounds checking");
        std::cout << "  Boundary packet valid: " << (boundary_valid ? "yes" : "no") << std::endl;
        std::cout << "  Invalid packet correctly rejected: " << (!invalid_valid ? "yes" : "no") << std::endl;
    } else {
        result.fail("Edge cases and bounds checking", "Boundary validation failed");
    }

    // Final summary
    std::cout << "\n";
    result.summary();

    if (result.all_passed()) {
        std::cout << "\n🎉 All tests PASSED! The MAZE node logic concepts are working correctly." << std::endl;
        return 0;
    } else {
        std::cout << "\n❌ Some tests FAILED. Please review the implementation." << std::endl;
        return 1;
    }
}