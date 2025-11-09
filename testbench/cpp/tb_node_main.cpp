// ====================================================================
// MAZE Network Node Module - Main Verilator Testbench Driver
// ====================================================================
//
// Comprehensive test suite for the MAZE network node module
// Tests all 4 pipeline stages with configurable scenarios
//
// Architecture:
// - Main testbench driver with configurable test scenarios
// - Individual test classes for each functional area
// - Packet generation utilities for 23-bit packet format
// - Result validation with pass/fail criteria
// - Coverage collection framework
//
// ====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <memory>
#include <iomanip>
#include <fstream>

// Include Verilator generated files
#include "Vnode.h"
#include "verilated.h"

// Include test utilities and classes
#include "common/packet_generator.h"
#include "common/test_utils.h"
#include "common/result_validator.h"
#include "unit_tests/basic_functionality_test.h"
#include "unit_tests/qos_arbitration_test.h"
#include "unit_tests/fault_tolerance_test.h"
#include "unit_tests/pipeline_timing_test.h"
#include "integration_tests/performance_test.h"

using namespace std;

// ====================================================================
// Test Configuration Structure
// ====================================================================
struct TestConfig {
    // Test duration parameters
    uint64_t max_cycles = 10000;
    uint64_t reset_cycles = 5;

    // Test selection flags
    bool run_basic_tests = true;
    bool run_qos_tests = true;
    bool run_fault_tests = true;
    bool run_timing_tests = true;
    bool run_performance_tests = true;

    // Traffic pattern parameters
    double unicast_ratio = 0.6;
    double multicast_ratio = 0.2;
    double broadcast_ratio = 0.1;
    double local_delivery_ratio = 0.1;

    // QoS distribution
    double high_qos_ratio = 0.3;
    double low_qos_ratio = 0.7;

    // Fault injection
    bool enable_fault_injection = true;
    double fault_probability = 0.1;

    // Node position for testing
    uint32_t node_hp = 3;  // Horizontal position [0-7]
    uint32_t node_vp = 2;  // Vertical position [0-7]

    // Random seed for reproducibility
    uint32_t random_seed = 12345;

    // Output verbosity
    int verbosity = 1;  // 0=quiet, 1=normal, 2=verbose, 3=debug

    // Waveform generation
    bool enable_vcd = false;
    string vcd_filename = "tb_node.vcd";
};

// ====================================================================
// Test Result Structure
// ====================================================================
struct TestResult {
    string test_name;
    bool passed;
    uint64_t cycles_run;
    string error_msg;
    double execution_time_ms;
    vector<string> warnings;
    map<string, uint64_t> metrics;

    TestResult(const string& name) : test_name(name), passed(false), cycles_run(0), execution_time_ms(0.0) {}
};

// ====================================================================
// Main Testbench Class
// ====================================================================
class NodeTestbench {
private:
    // Verilator simulation components
    unique_ptr<Vnode> dut_;
    unique_ptr<VerilatedContext> context_;
    VerilatedVcdC* vcd_;

    // Test configuration and results
    TestConfig config_;
    vector<TestResult> results_;

    // Test utilities
    unique_ptr<PacketGenerator> packet_gen_;
    unique_ptr<TestUtils> test_utils_;
    unique_ptr<ResultValidator> validator_;

    // Simulation state
    uint64_t sim_time_;
    bool reset_active_;

    // Statistics
    uint64_t total_packets_sent_;
    uint64_t total_packets_received_;
    uint64_t total_errors_;

public:
    NodeTestbench(const TestConfig& config)
        : config_(config), sim_time_(0), reset_active_(true),
          total_packets_sent_(0), total_packets_received_(0), total_errors_(0) {

        // Initialize Verilator context
        context_ = make_unique<VerilatedContext>();
        context_->commandArgs(0, nullptr);
        context_->debug(config_.verbosity >= 3);

        // Create DUT instance with node parameters
        dut_ = make_unique<Vnode>(context_.get(), "dut");

        // Set node position parameters
        dut_->HP = config_.node_hp;
        dut_->VP = config_.node_vp;

        // Initialize VCD if enabled
        vcd_ = nullptr;
        if (config_.enable_vcd) {
            Verilated::traceEverOn(true);
            vcd_ = new VerilatedVcdC;
            dut_->trace(vcd_, 99);
            vcd_->open(config_.vcd_filename.c_str());
            cout << "[INFO] VCD trace enabled: " << config_.vcd_filename << endl;
        }

        // Initialize test utilities
        packet_gen_ = make_unique<PacketGenerator>(config_.random_seed);
        test_utils_ = make_unique<TestUtils>(config_.verbosity);
        validator_ = make_unique<ResultValidator>();

        cout << "[INFO] Node testbench initialized" << endl;
        cout << "[INFO] Node position: HP=" << config_.node_hp << ", VP=" << config_.node_vp << endl;
        cout << "[INFO] Random seed: " << config_.random_seed << endl;
    }

    ~NodeTestbench() {
        if (vcd_) {
            vcd_->close();
            delete vcd_;
        }
        dut_.reset();
        context_.reset();
    }

    // ====================================================================
    // Simulation Control Methods
    // ====================================================================

    void reset_sequence() {
        cout << "[INFO] Starting reset sequence..." << endl;

        // Assert reset
        dut_->rst_n = 0;
        reset_active_ = true;

        // Run reset cycles
        for (uint32_t i = 0; i < config_.reset_cycles; i++) {
            step();
        }

        // Deassert reset
        dut_->rst_n = 1;
        reset_active_ = false;

        cout << "[INFO] Reset sequence completed" << endl;
    }

    void step() {
        // Toggle clock
        dut_->clk = 0;
        dut_->eval();
        if (vcd_) vcd_->dump(sim_time_++);

        dut_->clk = 1;
        dut_->eval();
        if (vcd_) vcd_->dump(sim_time_++);
    }

    void run_simulation_cycles(uint64_t cycles) {
        for (uint64_t i = 0; i < cycles; i++) {
            step();

            // Check for Verilator finish
            if (context_->gotFinish()) {
                cout << "[INFO] Verilator requested finish at cycle " << i << endl;
                break;
            }
        }
    }

    // ====================================================================
    // Test Execution Methods
    // ====================================================================

    bool run_all_tests() {
        cout << "\n" << string(80, '=') << endl;
        cout << "MAZE Network Node - Comprehensive Test Suite" << endl;
        cout << string(80, '=') << endl;

        bool all_passed = true;

        // Run reset sequence first
        reset_sequence();

        // Execute selected test suites
        if (config_.run_basic_tests) {
            all_passed &= run_test_suite("Basic Functionality", [this]() { return run_basic_tests(); });
        }

        if (config_.run_qos_tests) {
            all_passed &= run_test_suite("QoS Arbitration", [this]() { return run_qos_tests(); });
        }

        if (config_.run_fault_tests) {
            all_passed &= run_test_suite("Fault Tolerance", [this]() { return run_fault_tests(); });
        }

        if (config_.run_timing_tests) {
            all_passed &= run_test_suite("Pipeline Timing", [this]() { return run_timing_tests(); });
        }

        if (config_.run_performance_tests) {
            all_passed &= run_test_suite("Performance", [this]() { return run_performance_tests(); });
        }

        // Print final summary
        print_test_summary();

        return all_passed;
    }

    bool run_test_suite(const string& suite_name, function<bool()> test_func) {
        cout << "\n" << string(60, '-') << endl;
        cout << "Running " << suite_name << " Tests" << endl;
        cout << string(60, '-') << endl;

        TestResult result(suite_name);
        auto start_time = chrono::high_resolution_clock::now();

        try {
            // Reset DUT before each test suite
            reset_sequence();

            // Run the test suite
            result.passed = test_func();
            result.cycles_run = sim_time_;

        } catch (const exception& e) {
            result.passed = false;
            result.error_msg = string("Exception: ") + e.what();
            cerr << "[ERROR] Exception in " << suite_name << " tests: " << e.what() << endl;
        }

        auto end_time = chrono::high_resolution_clock::now();
        result.execution_time_ms = chrono::duration<double, milli>(end_time - start_time).count();

        results_.push_back(result);

        cout << "[RESULT] " << suite_name << " Tests: "
             << (result.passed ? "PASSED" : "FAILED") << endl;
        if (!result.error_msg.empty()) {
            cout << "[ERROR] " << result.error_msg << endl;
        }
        cout << "[TIME] Execution: " << fixed << setprecision(2)
             << result.execution_time_ms << " ms" << endl;

        return result.passed;
    }

    // ====================================================================
    // Individual Test Suite Implementations
    // ====================================================================

    bool run_basic_tests() {
        auto test = make_unique<BasicFunctionalityTest>(dut_.get(), packet_gen_.get(),
                                                       test_utils_.get(), validator_.get());
        return test->run_all_tests();
    }

    bool run_qos_tests() {
        auto test = make_unique<QoSArbitrationTest>(dut_.get(), packet_gen_.get(),
                                                   test_utils_.get(), validator_.get());
        return test->run_all_tests();
    }

    bool run_fault_tests() {
        auto test = make_unique<FaultToleranceTest>(dut_.get(), packet_gen_.get(),
                                                   test_utils_.get(), validator_.get());
        return test->run_all_tests();
    }

    bool run_timing_tests() {
        auto test = make_unique<PipelineTimingTest>(dut_.get(), packet_gen_.get(),
                                                   test_utils_.get(), validator_.get());
        return test->run_all_tests();
    }

    bool run_performance_tests() {
        auto test = make_unique<PerformanceTest>(dut_.get(), packet_gen_.get(),
                                                test_utils_.get(), validator_.get());
        return test->run_all_tests();
    }

    // ====================================================================
    // Utility Methods
    // ====================================================================

    void print_test_summary() {
        cout << "\n" << string(80, '=') << endl;
        cout << "Test Execution Summary" << endl;
        cout << string(80, '=') << endl;

        int passed_count = 0;
        int total_count = results_.size();
        double total_time = 0.0;
        uint64_t total_cycles = 0;

        cout << setw(25) << left << "Test Suite"
             << setw(10) << "Result"
             << setw(15) << "Execution (ms)"
             << setw(15) << "Cycles"
             << endl;
        cout << string(65, '-') << endl;

        for (const auto& result : results_) {
            cout << setw(25) << left << result.test_name
                 << setw(10) << (result.passed ? "PASS" : "FAIL")
                 << setw(15) << fixed << setprecision(2) << result.execution_time_ms
                 << setw(15) << result.cycles_run
                 << endl;

            if (result.passed) passed_count++;
            total_time += result.execution_time_ms;
            total_cycles += result.cycles_run;

            if (!result.error_msg.empty()) {
                cout << "  Error: " << result.error_msg << endl;
            }
        }

        cout << string(65, '-') << endl;
        cout << setw(25) << left << "TOTAL"
             << setw(10) << (passed_count == total_count ? "ALL PASS" : "SOME FAIL")
             << setw(15) << fixed << setprecision(2) << total_time
             << setw(15) << total_cycles
             << endl;

        cout << "\nOverall Result: " << passed_count << "/" << total_count
             << " test suites passed" << endl;

        // Print additional statistics
        cout << "\nSimulation Statistics:" << endl;
        cout << "  Total simulation time: " << total_cycles << " cycles" << endl;
        cout << "  Total execution time: " << fixed << setprecision(2) << total_time << " ms" << endl;
        cout << "  Average simulation speed: " << fixed << setprecision(0)
             << (total_cycles / (total_time / 1000.0)) << " cycles/sec" << endl;
    }

    bool save_results_to_file(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "[ERROR] Cannot open results file: " << filename << endl;
            return false;
        }

        file << "# MAZE Network Node Test Results" << endl;
        file << "# Generated at: " << test_utils_->get_timestamp() << endl;
        file << "# Configuration: HP=" << config_.node_hp << ", VP=" << config_.node_vp << endl;
        file << "# Random seed: " << config_.random_seed << endl;
        file << endl;

        for (const auto& result : results_) {
            file << result.test_name << ": " << (result.passed ? "PASS" : "FAIL") << endl;
            file << "  Execution time: " << result.execution_time_ms << " ms" << endl;
            file << "  Cycles run: " << result.cycles_run << endl;
            if (!result.error_msg.empty()) {
                file << "  Error: " << result.error_msg << endl;
            }
            file << endl;
        }

        file.close();
        cout << "[INFO] Results saved to: " << filename << endl;
        return true;
    }
};

// ====================================================================
// Command Line Argument Parsing
// ====================================================================
TestConfig parse_command_line(int argc, char* argv[]) {
    TestConfig config;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            cout << "MAZE Network Node Testbench" << endl;
            cout << "Usage: " << argv[0] << " [options]" << endl;
            cout << "Options:" << endl;
            cout << "  --help, -h              Show this help message" << endl;
            cout << "  --vcd                   Enable VCD waveform generation" << endl;
            cout << "  --seed <num>            Random seed (default: 12345)" << endl;
            cout << "  --hp <num>              Node horizontal position [0-7] (default: 3)" << endl;
            cout << "  --vp <num>              Node vertical position [0-7] (default: 2)" << endl;
            cout << "  --cycles <num>          Max simulation cycles (default: 10000)" << endl;
            cout << "  --verbose <0-3>         Verbosity level (default: 1)" << endl;
            cout << "  --no-basic              Skip basic functionality tests" << endl;
            cout << "  --no-qos                Skip QoS arbitration tests" << endl;
            cout << "  --no-fault              Skip fault tolerance tests" << endl;
            cout << "  --no-timing             Skip pipeline timing tests" << endl;
            cout << "  --no-performance        Skip performance tests" << endl;
            cout << "  --output <file>         Save results to file" << endl;
            exit(0);
        }
        else if (arg == "--vcd") {
            config.enable_vcd = true;
        }
        else if (arg == "--seed" && i + 1 < argc) {
            config.random_seed = stoul(argv[++i]);
        }
        else if (arg == "--hp" && i + 1 < argc) {
            config.node_hp = stoul(argv[++i]) % 8;
        }
        else if (arg == "--vp" && i + 1 < argc) {
            config.node_vp = stoul(argv[++i]) % 8;
        }
        else if (arg == "--cycles" && i + 1 < argc) {
            config.max_cycles = stoull(argv[++i]);
        }
        else if (arg == "--verbose" && i + 1 < argc) {
            config.verbosity = stoi(argv[++i]);
        }
        else if (arg == "--no-basic") {
            config.run_basic_tests = false;
        }
        else if (arg == "--no-qos") {
            config.run_qos_tests = false;
        }
        else if (arg == "--no-fault") {
            config.run_fault_tests = false;
        }
        else if (arg == "--no-timing") {
            config.run_timing_tests = false;
        }
        else if (arg == "--no-performance") {
            config.run_performance_tests = false;
        }
        else if (arg == "--output" && i + 1 < argc) {
            // Handle output file later after test execution
            i++;
        }
        else {
            cerr << "[WARNING] Unknown argument: " << arg << endl;
        }
    }

    return config;
}

// ====================================================================
// Main Function
// ====================================================================
int main(int argc, char* argv[]) {
    try {
        // Parse command line arguments
        TestConfig config = parse_command_line(argc, argv);

        // Create and run testbench
        NodeTestbench tb(config);
        bool success = tb.run_all_tests();

        // Save results if output file specified
        for (int i = 1; i < argc - 1; i++) {
            if (string(argv[i]) == "--output") {
                tb.save_results_to_file(argv[i + 1]);
                break;
            }
        }

        // Return appropriate exit code
        return success ? 0 : 1;

    } catch (const exception& e) {
        cerr << "[FATAL] Exception in main: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "[FATAL] Unknown exception in main" << endl;
        return 1;
    }
}