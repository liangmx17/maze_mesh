// ====================================================================
// MAZE Network Node - QoS Arbitration Test
// ====================================================================
//
// Simple QoS arbitration validation without Verilator
// Tests QoS priority scenarios and arbitration logic concepts
//
// ====================================================================

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <algorithm>

struct QoSTestResult {
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
        std::cout << "\n=== QoS Test Summary ===" << std::endl;
        std::cout << "Total: " << total << ", Passed: " << passed << ", Failed: " << failed << std::endl;
        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
                  << (total > 0 ? (100.0 * passed / total) : 0.0) << "%" << std::endl;
    }
};

// Simulate QoS arbiter logic
struct QoSRequest {
    int id;
    int priority;  // 1 = high, 0 = low
    uint32_t timestamp;
};

// Simple QoS arbitration simulation
int simulate_qos_arbitration(const std::vector<QoSRequest>& requests) {
    if (requests.empty()) return -1;

    // High priority requests always win over low priority
    for (const auto& req : requests) {
        if (req.priority == 1) {
            return req.id;  // First high priority request wins
        }
    }

    // If no high priority, first low priority wins (FIFO)
    return requests[0].id;
}

int main() {
    std::cout << "=== MAZE Network Node - QoS Arbitration Test ===" << std::endl;
    std::cout << "Testing QoS priority arbitration logic\n" << std::endl;

    QoSTestResult result;

    // Test 1: High priority wins over low priority
    std::cout << "--- Test 1: High Priority Wins Over Low Priority ---" << std::endl;
    std::vector<QoSRequest> mixed_requests = {
        {1, 0, 100},  // Low priority
        {2, 1, 101},  // High priority
        {3, 0, 102},  // Low priority
        {4, 1, 103}   // High priority
    };

    int winner = simulate_qos_arbitration(mixed_requests);
    if (winner == 2) {  // First high priority request should win
        result.pass("High priority wins over low priority");
    } else {
        result.fail("High priority wins over low priority", "Wrong winner: " + std::to_string(winner));
    }

    // Test 2: All low priority - FIFO behavior
    std::cout << "\n--- Test 2: All Low Priority - FIFO Behavior ---" << std::endl;
    std::vector<QoSRequest> low_requests = {
        {5, 0, 200},
        {6, 0, 201},
        {7, 0, 202}
    };

    winner = simulate_qos_arbitration(low_requests);
    if (winner == 5) {  // First request should win
        result.pass("All low priority - FIFO behavior");
    } else {
        result.fail("All low priority - FIFO behavior", "Wrong winner: " + std::to_string(winner));
    }

    // Test 3: All high priority - first wins
    std::cout << "\n--- Test 3: All High Priority - First Wins ---" << std::endl;
    std::vector<QoSRequest> high_requests = {
        {8, 1, 300},
        {9, 1, 301},
        {10, 1, 302}
    };

    winner = simulate_qos_arbitration(high_requests);
    if (winner == 8) {  // First request should win
        result.pass("All high priority - first wins");
    } else {
        result.fail("All high priority - first wins", "Wrong winner: " + std::to_string(winner));
    }

    // Test 4: QoS field extraction from packet
    std::cout << "\n--- Test 4: QoS Field Extraction from Packet ---" << std::endl;

    uint32_t test_packets[] = {
        0x100000,  // Low QoS packet
        0x110000   // High QoS packet
    };

    int qos_values[2];
    for (int i = 0; i < 2; i++) {
        qos_values[i] = (test_packets[i] >> 20) & 0x1;
    }

    if (qos_values[0] == 0 && qos_values[1] == 1) {
        result.pass("QoS field extraction from packet");
        std::cout << "  Low QoS packet: " << qos_values[0] << ", High QoS packet: " << qos_values[1] << std::endl;
    } else {
        result.fail("QoS field extraction from packet", "Incorrect QoS values");
    }

    // Test 5: Priority starvation prevention check
    std::cout << "\n--- Test 5: Priority Starvation Prevention Check ---" << std::endl;

    // Simulate multiple arbitration cycles
    int low_priority_wins = 0;
    int total_cycles = 100;

    for (int cycle = 0; cycle < total_cycles; cycle++) {
        std::vector<QoSRequest> cycle_requests;

        // Add mostly high priority requests
        cycle_requests.push_back({cycle + 100, 1, cycle});

        // Occasionally add low priority request
        if (cycle % 10 == 0) {
            cycle_requests.push_back({cycle + 200, 0, cycle});
        }

        // If only low priority present, it should win
        if (cycle_requests.size() == 1 && cycle_requests[0].priority == 0) {
            low_priority_wins++;
        }
    }

    if (low_priority_wins > 0) {
        result.pass("Priority starvation prevention check");
        std::cout << "  Low priority won in " << low_priority_wins << " cycles" << std::endl;
    } else {
        result.fail("Priority starvation prevention check", "No low priority wins detected");
    }

    result.summary();

    if (result.failed == 0) {
        std::cout << "\n🎉 All QoS tests PASSED!" << std::endl;
        return 0;
    } else {
        std::cout << "\n❌ Some QoS tests FAILED!" << std::endl;
        return 1;
    }
}