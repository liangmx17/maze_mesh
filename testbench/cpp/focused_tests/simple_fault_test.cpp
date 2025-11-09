// ====================================================================
// MAZE Network Node - Fault Tolerance Test
// ====================================================================
//
// Simple fault tolerance validation without Verilator
// Tests fault injection, route avoidance, and resilience
//
// ====================================================================

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

struct FaultTestResult {
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
        std::cout << "\n=== Fault Tolerance Test Summary ===" << std::endl;
        std::cout << "Total: " << total << ", Passed: " << passed << ", Failed: " << failed << std::endl;
        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
                  << (total > 0 ? (100.0 * passed / total) : 0.0) << "%" << std::endl;
    }
};

// Routing calculation functions (matching the fixed node logic)
void calculate_intermediate_nodes(uint32_t src_x, uint32_t src_y,
                                uint32_t tgt_x, uint32_t tgt_y,
                                uint32_t& int1_x, uint32_t& int1_y,
                                uint32_t& int2_x, uint32_t& int2_y) {
    int1_x = tgt_x;  // [src_y, tgt_x]
    int1_y = src_y;

    int2_x = src_x;  // [tgt_y, src_x]
    int2_y = tgt_y;
}

uint32_t coord_to_id(uint32_t x, uint32_t y) {
    return (y << 3) | x;
}

// Fault-aware route selection (matching the fixed node logic)
uint32_t select_route_with_fault(uint32_t src_x, uint32_t src_y,
                                uint32_t tgt_x, uint32_t tgt_y,
                                uint32_t fault_node_id, bool fault_enabled) {
    uint32_t int1_x, int1_y, int2_x, int2_y;
    calculate_intermediate_nodes(src_x, src_y, tgt_x, tgt_y,
                                int1_x, int1_y, int2_x, int2_y);

    uint32_t int1_id = coord_to_id(int1_x, int1_y);
    uint32_t int2_id = coord_to_id(int2_x, int2_y);

    // Simplified fault detection: at most 1 fault node
    if (fault_enabled && (fault_node_id == int1_id)) {
        return int2_id;  // Use node 2 if node 1 is faulted
    } else {
        return int1_id;  // Otherwise use node 1
    }
}

bool is_route_valid(uint32_t src_x, uint32_t src_y, uint32_t tgt_x, uint32_t tgt_y,
                   uint32_t fault_node_id, bool fault_enabled) {
    uint32_t selected_intermediate = select_route_with_fault(src_x, src_y, tgt_x, tgt_y,
                                                           fault_node_id, fault_enabled);

    // Check if selected route avoids the fault node
    if (fault_enabled) {
        return selected_intermediate != fault_node_id;
    } else {
        return true;  // Any route is valid when no fault
    }
}

int main() {
    std::cout << "=== MAZE Network Node - Fault Tolerance Test ===" << std::endl;
    std::cout << "Testing fault injection and route avoidance logic\n" << std::endl;

    FaultTestResult result;

    // Test 1: Basic intermediate node calculation
    std::cout << "--- Test 1: Basic Intermediate Node Calculation ---" << std::endl;

    uint32_t src_x = 2, src_y = 3, tgt_x = 6, tgt_y = 7;
    uint32_t int1_x, int1_y, int2_x, int2_y;

    calculate_intermediate_nodes(src_x, src_y, tgt_x, tgt_y,
                                int1_x, int1_y, int2_x, int2_y);

    if (int1_x == 6 && int1_y == 3 && int2_x == 2 && int2_y == 7) {
        result.pass("Basic intermediate node calculation");
        std::cout << "  Source: (" << src_x << "," << src_y << ") -> Target: (" << tgt_x << "," << tgt_y << ")" << std::endl;
        std::cout << "  Intermediate 1: (" << int1_x << "," << int1_y << ")" << std::endl;
        std::cout << "  Intermediate 2: (" << int2_x << "," << int2_y << ")" << std::endl;
    } else {
        result.fail("Basic intermediate node calculation", "Incorrect intermediate coordinates");
    }

    // Test 2: Single node fault avoidance
    std::cout << "\n--- Test 2: Single Node Fault Avoidance ---" << std::endl;

    uint32_t fault_node = coord_to_id(int1_x, int1_y);  // Fault is at intermediate 1
    uint32_t selected_route = select_route_with_fault(src_x, src_y, tgt_x, tgt_y,
                                                     fault_node, true);

    uint32_t expected_route = coord_to_id(int2_x, int2_y);  // Should select intermediate 2

    if (selected_route == expected_route) {
        result.pass("Single node fault avoidance");
        std::cout << "  Fault at node " << fault_node << ", selected route: " << selected_route << std::endl;
    } else {
        result.fail("Single node fault avoidance", "Selected wrong route");
    }

    // Test 3: No fault scenario
    std::cout << "\n--- Test 3: No Fault Scenario ---" << std::endl;

    uint32_t no_fault_route = select_route_with_fault(src_x, src_y, tgt_x, tgt_y,
                                                     0, false);  // No fault enabled

    uint32_t expected_no_fault = coord_to_id(int1_x, int1_y);  // Should select intermediate 1

    if (no_fault_route == expected_no_fault) {
        result.pass("No fault scenario");
        std::cout << "  No fault, selected route: " << no_fault_route << std::endl;
    } else {
        result.fail("No fault scenario", "Selected wrong route without fault");
    }

    // Test 4: Fault不在路由路径上
    std::cout << "\n--- Test 4: Fault Not on Route Path ---" << std::endl;

    uint32_t unrelated_fault = coord_to_id(0, 0);  // Fault at unrelated node
    uint32_t route_with_unrelated_fault = select_route_with_fault(src_x, src_y, tgt_x, tgt_y,
                                                                unrelated_fault, true);

    // Should still select intermediate 1 since fault is not on path
    if (route_with_unrelated_fault == expected_no_fault) {
        result.pass("Fault not on route path");
        std::cout << "  Unrelated fault at " << unrelated_fault << ", route unchanged: " << route_with_unrelated_fault << std::endl;
    } else {
        result.fail("Fault not on route path", "Route incorrectly changed");
    }

    // Test 5: Multiple routing scenarios
    std::cout << "\n--- Test 5: Multiple Routing Scenarios ---" << std::endl;

    struct RouteScenario {
        uint32_t src_x, src_y, tgt_x, tgt_y;
        uint32_t fault_id;
        bool fault_enabled;
        std::string description;
    };

    std::vector<RouteScenario> scenarios = {
        {1, 1, 5, 5, coord_to_id(1, 5), true, "Fault at intermediate 1"},
        {3, 2, 7, 4, coord_to_id(3, 4), true, "Fault at intermediate 1"},
        {0, 0, 7, 7, coord_to_id(0, 7), true, "Fault at intermediate 1"},
        {4, 4, 1, 1, coord_to_id(4, 1), true, "Fault at intermediate 1"},
        {6, 3, 2, 5, coord_to_id(6, 5), true, "Fault at intermediate 1"}
    };

    int valid_routes = 0;
    for (const auto& scenario : scenarios) {
        if (is_route_valid(scenario.src_x, scenario.src_y,
                          scenario.tgt_x, scenario.tgt_y,
                          scenario.fault_id, scenario.fault_enabled)) {
            valid_routes++;
        }
    }

    if (valid_routes == scenarios.size()) {
        result.pass("Multiple routing scenarios");
        std::cout << "  All " << valid_routes << " routing scenarios avoided faults successfully" << std::endl;
    } else {
        result.fail("Multiple routing scenarios",
                   "Only " + std::to_string(valid_routes) + " out of " +
                   std::to_string(scenarios.size()) + " scenarios valid");
    }

    // Test 6: Local delivery fault handling
    std::cout << "\n--- Test 6: Local Delivery Fault Handling ---" << std::endl;

    uint32_t local_x = 3, local_y = 4;
    uint32_t local_fault = coord_to_id(local_x, local_y);

    // For local delivery, no intermediate nodes needed
    bool local_delivery_valid = is_route_valid(local_x, local_y, local_x, local_y,
                                             local_fault, true);

    if (local_delivery_valid) {
        result.pass("Local delivery fault handling");
        std::cout << "  Local delivery handled correctly with fault at same node" << std::endl;
    } else {
        result.fail("Local delivery fault handling", "Local delivery incorrectly affected by fault");
    }

    result.summary();

    if (result.failed == 0) {
        std::cout << "\n🎉 All fault tolerance tests PASSED!" << std::endl;
        return 0;
    } else {
        std::cout << "\n❌ Some fault tolerance tests FAILED!" << std::endl;
        return 1;
    }
}