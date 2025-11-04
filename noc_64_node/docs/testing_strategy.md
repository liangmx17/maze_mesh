# 64-Node Network-on-Chip Testing Strategy

## 🧪 **Testing Overview**

This document defines the comprehensive testing strategy for the 64-node Network-on-Chip (NoC) design. The strategy follows a hierarchical approach from unit testing to full system verification, ensuring every component and interaction is thoroughly validated.

---

## 🎯 **Testing Objectives**

### **Primary Goals**
- **Functional Correctness**: Verify all functionality works as specified
- **Performance Validation**: Ensure latency, throughput, and QoS requirements are met
- **Reliability**: Test under various conditions and fault scenarios
- **Scalability**: Verify behavior across different network sizes
- **IRS Integration**: Validate IRS module integration correctness

### **Testing Principles**
- **Early Testing**: Test each component immediately after implementation
- **Automated Verification**: Automated test execution and result checking
- **Coverage-Driven**: Achieve comprehensive functional and code coverage
- **Regression Testing**: Continuous testing throughout development
- **Performance Testing**: Measure and validate performance characteristics

---

## 📊 **Testing Hierarchy**

### **Level 1: Unit Testing**
- **Scope**: Individual RTL modules
- **Goal**: Verify module functionality in isolation
- **Components**: Router core, buffer manager, routing unit, switch allocator, crossbar
- **Coverage**: 100% code coverage, all functional scenarios

### **Level 2: Integration Testing**
- **Scope**: Component interactions within nodes
- **Goal**: Verify components work together correctly
- **Components**: Complete node, IRS module integration
- **Coverage**: All interface protocols, component interactions

### **Level 3: System Testing**
- **Scope**: Full 64-node network
- **Goal**: Verify end-to-end functionality and performance
- **Components**: Complete network with all nodes and topology
- **Coverage**: Real-world scenarios, performance characteristics

### **Level 4: Stress & Edge Case Testing**
- **Scope**: Extreme conditions and error scenarios
- **Goal**: Verify robustness and fault tolerance
- **Components**: Network under saturation, with failures, corner cases
- **Coverage**: Stress conditions, error handling, recovery scenarios

---

## 🔬 **Unit Testing Strategy**

### **Test Organization**
```
rtl/tb/
├── tb_node_router_core.sv      # Router core unit test
├── tb_buffer_manager.sv        # Buffer manager unit test
├── tb_routing_unit.sv          # Routing unit unit test
├── tb_switch_allocator.sv      # Switch allocator unit test
├── tb_crossbar.sv              # Crossbar unit test
├── tb_network_interface.sv     # Network interface unit test
└── utils/
    ├── packet_generator.sv     # Traffic generation utilities
    ├── scoreboard.sv           # Result checking utilities
    └── coverage_collector.sv   # Coverage collection utilities
```

### **Router Core Unit Test**
```systemverilog
module tb_node_router_core;
    // Testbench parameters
    parameter DATA_WIDTH = 32;
    parameter NUM_PORTS = 5;
    parameter NUM_VCS = 2;

    // Clock and reset
    logic clk;
    logic rst_n;

    // DUT signals
    logic [NUM_PORTS-1:0]         in_valid;
    logic [NUM_PORTS-1:0]         in_ready;
    logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] in_data;
    logic [NUM_PORTS-1:0][NUM_VCS-1:0]   in_vc_id;

    logic [NUM_PORTS-1:0]         out_valid;
    logic [NUM_PORTS-1:0]         out_ready;
    logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] out_data;
    logic [NUM_PORTS-1:0][NUM_VCS-1:0]   out_vc_id;

    // Instantiate DUT
    node_router_core #(
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_PORTS(NUM_PORTS),
        .NUM_VCS(NUM_VCS)
    ) dut (.*);

    // Test scenarios
    initial begin
        // Initialize
        clk = 0;
        rst_n = 0;
        #100;
        rst_n = 1;

        // Test 1: Basic packet forwarding
        test_basic_forwarding();

        // Test 2: Virtual channel allocation
        test_vc_allocation();

        // Test 3: Switch arbitration
        test_switch_arbitration();

        // Test 4: Backpressure handling
        test_backpressure();

        // Test 5: Multiple simultaneous packets
        test_multiple_packets();

        $display("All router core tests passed!");
        $finish;
    end

    // Clock generation
    always #5 clk = ~clk;

    // Test tasks
    task test_basic_forwarding();
        // Implementation here
    endtask

    // ... other test tasks
endmodule
```

### **Buffer Manager Unit Test**
```systemverilog
module tb_buffer_manager;
    // Test IRS-based buffer functionality
    parameter BUFFER_DEPTH = 8;
    parameter DATA_WIDTH = 32;

    logic clk, rst_n;
    logic write_en, read_en;
    logic [DATA_WIDTH-1:0] write_data, read_data;
    logic full, empty;

    // Instantiate buffer manager with IRS modules
    node_buffer_manager dut (.*);

    // Test scenarios
    initial begin
        // Test IRS register chain functionality
        test_irs_buffering();

        // Test credit-based flow control
        test_flow_control();

        // Test buffer overflow protection
        test_overflow_protection();
    end
endmodule
```

---

## 🔗 **Integration Testing Strategy**

### **Node Integration Test**
```systemverilog
module tb_node;
    // Complete node with all components
    logic clk, rst_n;

    // Network interface
    NodeInterface node_if();

    // Router connections (4 directions)
    RouterLink north_link(), south_link(), east_link(), west_link();

    // Instantiate complete node
    node dut (
        .clk(clk),
        .rst_n(rst_n),
        .local_if(node_if),
        .north_link(north_link),
        .south_link(south_link),
        .east_link(east_link),
        .west_link(west_link)
    );

    // Test scenarios
    initial begin
        // Test 1: Local injection and ejection
        test_local_traffic();

        // Test 2: North-South traffic forwarding
        test_ns_forwarding();

        // Test 3: East-West traffic forwarding
        test_ew_forwarding();

        // Test 4: Multi-directional traffic
        test_multi_directional();

        // Test 5: IRS module integration
        test_irs_integration();
    end
endmodule
```

### **IRS Integration Test**
```systemverilog
module tb_irs_integration;
    // Test IRS module integration specifically
    logic clk, rst_n;

    // IRS module interfaces
    IRS_Buffer #(32, 8) buffer_inst();
    IRS_StateMachine #(4) sm_inst();

    // Test scenarios
    initial begin
        // Test IRS buffer functionality in network context
        test_irs_buffer_network();

        // Test IRS state machine in network context
        test_irs_sm_network();

        // Test IRS timing compliance
        test_irs_timing();

        // Test IRS parameterization
        test_irs_parameters();
    end
endmodule
```

---

## 🌐 **System Testing Strategy**

### **8×8 Mesh Topology Test**
```systemverilog
module tb_topo_mesh;
    // Full 8×8 network
    parameter NODES_X = 8;
    parameter NODES_Y = 8;

    logic clk, rst_n;

    // Network interfaces for external connections
    NodeInterface ext_if [NODES_X * NODES_Y]();

    // Instantiate 8×8 mesh topology
    topo_mesh_8x8 dut (
        .clk(clk),
        .rst_n(rst_n),
        .ext_if(ext_if)
    );

    // Traffic generators
    PacketGenerator traffic_gen [16]();

    // Scoreboard for result checking
    Scoreboard sb;

    // Test scenarios
    initial begin
        // Test 1: Single source-destination pairs
        test_single_sd_pairs();

        // Test 2: All-to-all communication
        test_all_to_all();

        // Test 3: Hotspot traffic patterns
        test_hotspot_traffic();

        // Test 4: Uniform random traffic
        test_uniform_traffic();

        // Test 5: Performance benchmarks
        test_performance_benchmarks();

        // Test 6: QoS verification
        test_qos_functionality();
    end
endmodule
```

### **Performance Measurement**
```systemverilog
class PerformanceMonitor;
    // Latency measurement
    real latency_histogram [256];
    real total_latency;
    int packet_count;

    // Throughput measurement
    real throughput_per_port [64];
    real aggregate_throughput;

    // Buffer utilization
    real buffer_utilization [64][5][2]; // node x port x VC

    // Methods
    function void record_packet_latency(real latency);
        latency_histogram[int(latency)]++;
        total_latency += latency;
        packet_count++;
    endfunction

    function void calculate_throughput();
        // Calculate throughput metrics
    endfunction

    function void print_performance_report();
        $display("=== Performance Report ===");
        $display("Average Latency: %0.2f cycles", total_latency/packet_count);
        $display("Aggregate Throughput: %0.2f flits/cycle", aggregate_throughput);
        // ... other metrics
    endfunction
endclass
```

---

## 🚨 **Stress & Edge Case Testing**

### **Saturation Testing**
```systemverilog
task test_saturation();
    // Generate maximum traffic load
    for (int i = 0; i < 64; i++) begin
        traffic_gen[i].generate_max_load();
    end

    // Monitor behavior under saturation
    fork
        begin
            #TIMEOUT; // Timeout after reasonable time
            $display("ERROR: System deadlocked under saturation");
        end
        begin
            wait(all_packets_delivered());
            $display("Saturation test passed - system recovered");
        end
    join_any
    disable fork;
endtask
```

### **Fault Injection Testing**
```systemverilog
task test_fault_tolerance();
    // Inject link failures
    inject_link_failure(10, 15); // Node 10 to 15

    // Verify traffic rerouting
    test_rerouting_after_failure();

    // Inject router failure
    inject_router_failure(20);

    // Verify graceful degradation
    test_graceful_degradation();
endtask
```

### **Corner Case Testing**
```systemverilog
task test_corner_cases();
    // Test minimum size packets
    test_single_flit_packets();

    // Test maximum size packets
    test_max_size_packets();

    // Test simultaneous packet injection
    test_simultaneous_injection();

    // Test buffer boundary conditions
    test_buffer_boundaries();

    // Test timing edge cases
    test_timing_edge_cases();
endtask
```

---

## 📈 **Coverage Strategy**

### **Code Coverage Targets**
- **Line Coverage**: > 95%
- **Branch Coverage**: > 90%
- **State Machine Coverage**: 100%
- **Toggle Coverage**: > 80%

### **Functional Coverage**
```systemverilog
covergroup RouterFunctionalCoverage @(posedge clk);
    option.per_instance = 1;

    // Input patterns
    input_valid_cp: coverpoint dut.in_valid {
        bins all_valid = {5'b11111};
        bins partial_valid = {[5'b00001:5'b11110]};
        bins all_invalid = {5'b00000};
    }

    // Routing patterns
    routing_patterns: cross input_valid_cp, output_direction_cp;

    // Virtual channel usage
    vc_usage_cp: coverpoint dut.selected_vc {
        bins vc0 = {0};
        bins vc1 = {1};
    }

    // Buffer occupancy
    buffer_occupancy_cp: coverpoint dut.buffer_fill_level {
        bins empty = {[0:0]};
        bins low = {[1:2]};
        bins medium = {[3:5]};
        bins high = {[6:7]};
        bins full = {[8:8]};
    }
endgroup
```

### **Assertion-Based Verification**
```systemverilog
// Deadlock freedom assertion
assert property (@(posedge clk)
    disable iff (!rst_n)
    (dut.packet_in_network |=> ##[1:100] dut.packet_delivered))
else $error("Potential deadlock detected");

// Buffer overflow protection
assert property (@(posedge clk)
    disable iff (!rst_n)
    (dut.buffer_full |-> !dut.write_enable))
else $error("Buffer overflow attempted");

// Valid packet format
assert property (@(posedge clk)
    disable iff (!rst_n)
    (dut.in_valid |-> dut.packet_format_valid))
else $error("Invalid packet format detected");
```

---

## 🤖 **Automated Testing Framework**

### **Test Runner Script**
```python
#!/usr/bin/env python3
import subprocess
import sys
import os
from pathlib import Path

class NoCTestRunner:
    def __init__(self, test_dir="rtl/tb"):
        self.test_dir = Path(test_dir)
        self.results = []

    def compile_test(self, test_file):
        """Compile individual test using Verilator"""
        cmd = [
            "verilator", "-Wall", "--cc", "--exe",
            f"--top", f"tb_{test_file.stem}",
            str(test_file),
            "../node/node_router_core.sv",
            "../pkg/noc_network_pkg.sv"
        ]

        result = subprocess.run(cmd, capture_output=True, text=True)
        return result.returncode == 0, result.stdout, result.stderr

    def run_test(self, test_file):
        """Run individual test"""
        print(f"Running test: {test_file.name}")

        # Compile test
        success, stdout, stderr = self.compile_test(test_file)
        if not success:
            print(f"❌ Compilation failed: {stderr}")
            return False

        # Build and run
        build_cmd = ["make", "-C", "obj_dir", "-f", f"Vtb_{test_file.stem}.mk"]
        result = subprocess.run(build_cmd, capture_output=True)

        if result.returncode == 0:
            run_result = subprocess.run(["./obj_dir/Vtb_" + test_file.stem],
                                      capture_output=True, text=True)

            if "PASSED" in run_result.stdout:
                print(f"✅ {test_file.name} PASSED")
                return True
            else:
                print(f"❌ {test_file.name} FAILED: {run_result.stdout}")
                return False
        else:
            print(f"❌ Build failed: {result.stderr}")
            return False

    def run_all_tests(self):
        """Run all tests in the test directory"""
        test_files = list(self.test_dir.glob("tb_*.sv"))
        passed = 0
        total = len(test_files)

        for test_file in test_files:
            if self.run_test(test_file):
                passed += 1

        print(f"\n=== Test Results ===")
        print(f"Passed: {passed}/{total}")
        print(f"Success Rate: {passed/total*100:.1f}%")

        return passed == total

if __name__ == "__main__":
    runner = NoCTestRunner()
    success = runner.run_all_tests()
    sys.exit(0 if success else 1)
```

### **Regression Testing**
```bash
#!/bin/bash
# regression_test.sh - Run full regression test suite

echo "=== NoC Regression Test Suite ==="

# Set environment
export NOC_ROOT=$(pwd)
export TEST_DIR=$NOC_ROOT/rtl/tb
export RESULTS_DIR=$NOC_ROOT/test_results

# Create results directory
mkdir -p $RESULTS_DIR

# Run unit tests
echo "Running Unit Tests..."
python3 scripts/run_tests.py --level unit

# Run integration tests
echo "Running Integration Tests..."
python3 scripts/run_tests.py --level integration

# Run system tests
echo "Running System Tests..."
python3 scripts/run_tests.py --level system

# Collect coverage
echo "Collecting Coverage..."
python3 scripts/collect_coverage.py

# Generate report
python3 scripts/generate_report.py

echo "Regression testing complete. Results in: $RESULTS_DIR"
```

---

## 📊 **Test Metrics & Reporting**

### **Key Performance Indicators**
- **Functional Coverage**: Percentage of functionality tested
- **Code Coverage**: Line, branch, toggle coverage
- **Test Pass Rate**: Percentage of tests passing
- **Performance Metrics**: Latency, throughput, QoS compliance
- **Bug Detection Rate**: Number of bugs found per test phase

### **Test Report Template**
```
=== NoC Test Report ===
Date: ____________
Test Suite Version: ________

Executive Summary:
- Total Tests: ____
- Passed: ____
- Failed: ____
- Pass Rate: ___%

Coverage Summary:
- Code Coverage: ___%
- Functional Coverage: ___%
- Assertion Coverage: ___%

Performance Summary:
- Average Latency: ___ cycles
- Peak Throughput: ___ flits/cycle
- QoS Compliance: ___%

Failed Tests:
1. Test Name: ______
   Reason: ______
   Status: _____

Action Items:
1. ________________________
2. ________________________

Next Steps:
1. ________________________
2. ________________________
```

---

## 🚀 **Continuous Integration**

### **CI Pipeline**
```yaml
# .gitlab-ci.yml example
stages:
  - syntax
  - unit_test
  - integration_test
  - system_test
  - coverage
  - performance

syntax_check:
  stage: syntax
  script:
    - make syntax_check

unit_tests:
  stage: unit_test
  script:
    - python3 scripts/run_tests.py --level unit
  artifacts:
    reports:
      junit: test_results/unit_tests.xml

integration_tests:
  stage: integration_test
  script:
    - python3 scripts/run_tests.py --level integration
  dependencies:
    - unit_tests

system_tests:
  stage: system_test
  script:
    - python3 scripts/run_tests.py --level system
  dependencies:
    - integration_tests

coverage_report:
  stage: coverage
  script:
    - python3 scripts/collect_coverage.py
    - python3 scripts/generate_coverage_report.py
  artifacts:
    reports:
      coverage_report:
        path: coverage_report.xml
```

---

## 📝 **Testing Checklist**

### **Pre-Test Preparation**
- [ ] All testbenches created and reviewed
- [ ] Test data generation utilities ready
- [ ] Coverage collection tools configured
- [ ] Automation scripts prepared
- [ ] Performance monitoring tools ready

### **Test Execution**
- [ ] Unit tests executed and passed
- [ ] Integration tests executed and passed
- [ ] System tests executed and passed
- [ ] Stress tests executed and passed
- [ ] Coverage targets met
- [ ] Performance requirements verified

### **Post-Test Analysis**
- [ ] Test results analyzed
- [ ] Coverage gaps identified
- [ ] Performance bottlenecks identified
- [ ] Bug reports created
- [ ] Test report generated

### **Sign-off Criteria**
- [ ] All functional tests passing
- [ ] Coverage targets met (>95% code, >90% functional)
- [ ] Performance requirements met
- [ ] No critical bugs outstanding
- [ ] Documentation complete

---

**Document Version**: 1.0
**Last Updated**: 2025-11-04
**Next Review Date**: __/__/____
**Approved By**: ________________