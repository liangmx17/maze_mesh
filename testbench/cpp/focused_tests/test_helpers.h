// ====================================================================
// MAZE Network Node - Test Helpers
// ====================================================================
//
// Common test utilities and helper functions for node testing
// Provides basic test result tracking and simple assertion macros
//
// ====================================================================

#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// ====================================================================
// Test Result Tracking
// ====================================================================

struct TestResult {
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;
    std::vector<std::string> failures;

    void pass(const std::string& test_name) {
        total_tests++;
        passed_tests++;
        std::cout << "[PASS] " << test_name << std::endl;
    }

    void fail(const std::string& test_name, const std::string& reason = "") {
        total_tests++;
        failed_tests++;
        std::string msg = "[FAIL] " + test_name;
        if (!reason.empty()) {
            msg += " - " + reason;
        }
        std::cout << msg << std::endl;
        failures.push_back(msg);
    }

    void summary() const {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Total: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << failed_tests << std::endl;

        if (failed_tests > 0) {
            std::cout << "\nFailures:" << std::endl;
            for (const auto& failure : failures) {
                std::cout << "  " << failure << std::endl;
            }
        }

        std::cout << "Success Rate: " << std::fixed << std::setprecision(1)
                  << (total_tests > 0 ? (100.0 * passed_tests / total_tests) : 0.0)
                  << "%" << std::endl;
    }

    bool all_passed() const {
        return failed_tests == 0;
    }
};

// ====================================================================
// Simple Assertion Macros
// ====================================================================

#define ASSERT_TRUE(condition, test_name) \
    do { \
        if (condition) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected true"); \
        } \
    } while(0)

#define ASSERT_FALSE(condition, test_name) \
    do { \
        if (!condition) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected false"); \
        } \
    } while(0)

#define ASSERT_EQ(expected, actual, test_name) \
    do { \
        if ((expected) == (actual)) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected " + std::to_string(expected) + \
                              ", got " + std::to_string(actual)); \
        } \
    } while(0)

#define ASSERT_NE(expected, actual, test_name) \
    do { \
        if ((expected) != (actual)) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected not equal to " + std::to_string(expected)); \
        } \
    } while(0)

#define ASSERT_GT(val1, val2, test_name) \
    do { \
        if ((val1) > (val2)) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected " + std::to_string(val1) + \
                              " > " + std::to_string(val2)); \
        } \
    } while(0)

#define ASSERT_LT(val1, val2, test_name) \
    do { \
        if ((val1) < (val2)) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected " + std::to_string(val1) + \
                              " < " + std::to_string(val2)); \
        } \
    } while(0)

// Floating point comparison with tolerance
#define ASSERT_NEAR(expected, actual, tolerance, test_name) \
    do { \
        if (std::abs((expected) - (actual)) <= (tolerance)) { \
            result.pass(test_name); \
        } else { \
            result.fail(test_name, "Expected " + std::to_string(expected) + \
                              " ± " + std::to_string(tolerance) + \
                              ", got " + std::to_string(actual)); \
        } \
    } while(0)

// ====================================================================
// Performance Measurement
// ====================================================================

#include <chrono>

struct Timer {
    std::chrono::high_resolution_clock::time_point start_time;

    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double elapsed_seconds() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            end_time - start_time);
        return duration.count() / 1000000.0;
    }

    double elapsed_ms() {
        return elapsed_seconds() * 1000.0;
    }
};

// ====================================================================
// Utility Functions
// ====================================================================

// Simple packet validation
bool validate_packet_format(uint32_t packet) {
    // Basic 23-bit packet format validation
    if (packet > 0x7FFFFF) return false;  // Exceeds 23 bits

    uint32_t type = (packet >> 21) & 0x3;
    uint32_t qos = (packet >> 20) & 0x1;
    uint32_t src = (packet >> 14) & 0x3F;
    uint32_t tgt = (packet >> 8) & 0x3F;

    // Basic sanity checks
    if (src > 0x3F) return false;  // Source out of range
    if (tgt > 0x3F) return false;  // Target out of range

    return true;
}

// Test coordinate to node ID conversion
uint32_t coord_to_id(uint32_t x, uint32_t y) {
    return (y << 3) | x;
}

// Test node ID to coordinate conversion
void id_to_coord(uint32_t id, uint32_t& x, uint32_t& y) {
    x = id & 0x7;
    y = (id >> 3) & 0x7;
}

#endif // TEST_HELPERS_H