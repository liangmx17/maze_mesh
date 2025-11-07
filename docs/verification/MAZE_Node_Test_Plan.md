# MAZE Network Node Module - Test Plan

## Document Overview
**Project**: MAZE 64-Node Network-on-Chip (NoC)
**Module**: Node Router (rtl/src/node/node.v)
**Test Plan Version**: v1.0
**Date**: November 7, 2025

---

## 1. Test Strategy Overview

### 1.1 Testing Philosophy
The MAZE node module requires comprehensive testing across multiple verification domains to ensure production readiness. The test strategy employs a multi-tiered approach:

- **Unit Testing**: Individual component validation
- **Integration Testing**: Multi-component interaction validation
- **System Testing**: Full 64-node network validation
- **Performance Testing**: Timing and throughput characterization
- **Stress Testing**: Edge case and failure scenario validation

### 1.2 Test Environment
- **Simulation**: Verilator-based C++ testbenches
- **Waveforms**: VCD format for debug and analysis
- **Build System**: Automated compilation with rtl.filelist
- **Automation**: Python scripts for test execution and reporting

---

## 2. Unit Test Specifications

### 2.1 Stage 0: Input Preprocessing Tests

#### Test Case: UT-Stage0-001 - Basic Packet Validation
**Objective**: Verify basic input packet processing and validation
**Description**: Test unicast packet detection, coordinate extraction, and intermediate node calculation

**Input**:
```systemverilog
// Test Vector 1: Valid unicast packet
.pkt_in_vld(1'b1),
.pkt_in_qos(1'b1),
.pkt_in_type(2'b00),  // Unicast
.pkt_in_src(6'b001010), // Node (2,4)
.pkt_in_tgt(6'b101101), // Node (3,5)
.pkt_in_data(8'hA5),
.rst_n(1'b1),
.pg_en(1'b0)  // No failed nodes
```

**Expected Output**:
```systemverilog
.stage0_out.vld(1'b1),
.stage0_out.qos(1'b1),
.stage0_out.intermediate_node(6'b100011), // [src_y=4, tgt_x=3] = (3,4)
.stage0_out.is_failed(1'b0),
.stage0_out.output_port(4'dXXX) // Calculated port to (3,4)
```

**Validation Points**:
- [ ] Unicast packet correctly identified (type=00)
- [ ] Source and target coordinates correctly extracted
- [ ] Intermediate node correctly calculated as [src_y, tgt_x]
- [ ] Output port correctly determined for intermediate node
- [ ] Failed node detection works (when enabled)

---

#### Test Case: UT-Stage0-002 - Fault Detection
**Objective**: Verify failed node detection and avoidance logic

**Input**:
```systemverilog
// Set node (3,4) as failed
.pg_en(1'b1),
.pg_node(6'b100011), // Failed node (3,4)

// Packet routing through failed node
.pkt_in_src(6'b001010), // Source (2,4)
.pkt_in_tgt(6'b101101), // Target (3,5)
.pkt_in_type(2'b00)      // Unicast
```

**Expected Output**:
```systemverilog
.stage0_out.intermediate_node(6'b011011), // Select intermediate2: [tgt_y=3, src_x=2] = (2,3)
// Avoids failed intermediate1 (3,4)
```

**Validation Points**:
- [ ] Failed intermediate node correctly detected
- [ ] Alternative intermediate node correctly selected
- [ ] Route avoids failed nodes
- [ ] Packet marked as failed when target node failed

---

### 2.2 Stage 1: QoS Arbitration Tests

#### Test Case: UT-Stage1-001 - High QoS Priority
**Objective**: Verify high QoS packets get absolute priority over low QoS

**Input**:
```systemverilog
// Low QoS packet on input 0
.c_input_pkts[0].vld(1'b1),
.c_input_pkts[0].qos(1'b0),
.c_input_pkts[0].tgt(6'b101101),

// High QoS packet on input 1
.c_input_pkts[1].vld(1'b1),
.c_input_pkts[1].qos(1'b1),
.c_input_pkts[1].tgt(6'b110110),

// A-interface input (low QoS)
.a_input_pkt.vld(1'b1),
.a_input_pkt.qos(1'b0),
.a_input_pkt.tgt(6'b111111)
```

**Expected Output**:
```systemverilog
.final_winner.vld(1'b1),
.final_winner.qos(1'b1),  // High QoS winner selected
.final_winner.tgt(6'b110110) // From input 1
```

**Validation Points**:
- [ ] High QoS packet wins arbitration regardless of input index
- [ ] Round-robin arbitration within same QoS level
- [ ] X-direction and Y-direction arbiters work correctly
- [ ] Final winner selection logic works as expected

---

#### Test Case: UT-Stage1-002 - Directional Arbitration
**Objective**: Verify X and Y direction arbiters handle correct traffic

**Input**:
```systemverilog
// Packet aiming to Y-direction (different X coordinate)
.src_coord(6'b001010), // Source (2,4)
.tgt_coord(6'b110110), // Target (6,3) - different X, needs Y direction
.packet_aims_to_y(1'b1),
.packet_aims_to_x(1'b0)
```

**Expected Output**:
```systemverilog
.final_direction(4'd0), // X-direction arbiter selected
.x_arbiter_winner.vld(1'b1)
```

**Validation Points**:
- [ ] Packets with different X coordinates go to X-direction arbiter
- [ ] Packets with different Y coordinates go to Y-direction arbiter
- [ ] A-interface input participates in correct arbiter
- [ ] Direction filtering works correctly

---

### 2.3 Stage 2: Output Selection Tests

#### Test Case: UT-Stage2-001 - Port Mapping Functions
**Objective**: Verify coordinate-to-port mapping functions work correctly

**Input**:
```systemverilog
// Test calc_x_port_index: Same X coordinate, different Y
.current_x(3'd2),
.current_y(3'd4),
.target_y(3'd1) // Node (2,1) - north neighbor
```

**Expected Output**:
```systemverilog
.port_idx(4'd1) // X-port 1 for north connection
```

**Validation Points**:
- [ ] X-port mapping works for same X coordinate neighbors
- [ ] Y-port mapping works for same Y coordinate neighbors
- [ ] Port indices correctly calculated (0-6 for X, 8-14 for Y)
- [ ] B-port (14) selected for local delivery
- [ ] Invalid coordinates return error codes

---

#### Test Case: UT-Stage2-002 - Two-Hop State Machine
**Objective**: Verify two-hop routing state machine transitions

**Input**:
```systemverilog
// Packet requiring two-hop routing
.stage1_out.vld(1'b1),
.stage1_out.src(6'b001010), // (2,4)
.stage1_out.tgt(6'b110110), // (6,3) - different X and Y
.current_route_state(ROUTE_IDLE)
```

**Expected State Transitions**:
```systemverilog
// Cycle 1: IDLE → FIRST_HOP
.next_route_state(ROUTE_FIRST_HOP),
.next_target(6'b011011), // [src_y=4, tgt_x=6] = (6,4)

// Cycle 2: FIRST_HOP → SECOND_HOP
.next_route_state(ROUTE_SECOND_HOP),
.next_target(6'b110110), // Final target (6,3)

// Cycle 3: SECOND_HOP → LOCAL
.next_route_state(ROUTE_LOCAL),
.next_target(6'b110110)
```

**Validation Points**:
- [ ] State transitions occur in correct sequence
- [ ] Intermediate nodes correctly calculated
- [ ] Final target routing works correctly
- [ ] Direct routing bypasses state machine

---

### 2.4 Stage 3: Output Buffering Tests

#### Test Case: UT-Stage3-001 - C-Interface Connections
**Objective**: Verify C-interface port assignments work correctly

**Input**:
```systemverilog
.stage3_out.vld(1'b1),
.stage3_out.output_port(4'd3), // X-port 3
.stage3_out.qos(1'b1),
.stage3_out.pkt_type(2'b00),
.stage3_out.src(6'b001010),
.stage3_out.tgt(6'b110110),
.stage3_out.data(8'hA5)
```

**Expected Output**:
```systemverilog
.pkt_con_out.x_vld[3](1'b1),
.pkt_con_out.x_qos[3](1'b1),
.pkt_con_out.x_type[3](2'b00),
.pkt_con_out.x_src[3](6'b001010),
.pkt_con_out.x_tgt[3](6'b110110),
.pkt_con_out.x_data[3](8'hA5)
```

**Validation Points**:
- [ ] X-ports correctly activated for indices 0-6
- [ ] Y-ports correctly activated for indices 8-14
- [ ] B-port correctly activated for index 14
- [ ] All other ports remain inactive
- [ ] Ready signals properly connected

---

#### Test Case: UT-Stage3-002 - Backpressure Propagation
**Objective**: Verify backpressure signals propagate upstream correctly

**Input**:
```systemverilog
// Downstream not ready
.pkt_con_out.x_rdy[3](1'b0), // X-port 3 not ready
.b_port_rdy(1'b0),           // B-port not ready
.stage3_out.vld(1'b1),
.stage3_out.output_port(4'd3) // Outputting to X-port 3
```

**Expected Output**:
```systemverilog
.stage3_stall(1'b1),        // Stage 3 stalled
.stage2_stall(1'b1),        // Stage 2 stalled
.stage1_stall(1'b1),        // Stage 1 stalled
.a_port_stall(1'b1),        // A-port stalled
.a_port_rdy(1'b0),          // Not ready for new packets
.pkt_con_in.x_rdy[0](1'b0)  // Tell upstream not ready
```

**Validation Points**:
- [ ] Backpressure propagates through all pipeline stages
- [ ] Ready signals correctly indicate upstream readiness
- [ ] Stall conditions properly detected and propagated
- [ ] Deadlock prevention mechanisms work

---

## 3. Integration Test Specifications

### 3.1 Multi-Node Network Tests

#### Test Case: IT-Multi-001 - 2×2 Network (4 Nodes)
**Objective**: Verify basic multi-node operation

**Network Topology**:
```
Nodes: (0,0) (0,1) (1,0) (1,1)
Connections: Full 2×2 mesh topology
```

**Test Scenario**: Packet from (0,0) to (1,1)
**Expected Path**: (0,0) → [0,1] → (1,1)

**Validation Points**:
- [ ] Packet successfully traverses intermediate node
- [ ] C-interface connections work between nodes
- [ ] End-to-end delivery successful
- [ ] No packet loss or corruption

---

#### Test Case: IT-Multi-002 - 8×8 Network (64 Nodes)
**Objective**: Verify full network operation

**Network Topology**:
```
Nodes: Complete 8×8 mesh (coordinates 0,0 to 7,7)
Connections: 14 bidirectional links per node
```

**Test Scenarios**:
1. **Shortest Path**: (0,0) → (0,1) - Direct routing
2. **Two-Hop**: (0,0) → (7,7) - Maximum distance routing
3. **Congestion**: Multiple simultaneous packets
4. **Fault Tolerance**: Single node failure scenarios

**Validation Points**:
- [ ] All nodes functional in full network
- [ ] Routing works across entire address space
- [ ] Performance scales with network size
- [ ] No routing deadlocks or livelocks

---

### 3.2 QoS System Integration Tests

#### Test Case: IT-QoS-001 - Priority Inversion Prevention
**Objective**: Verify high QoS packets aren't starved by low QoS traffic

**Test Scenario**:
- Continuous low QoS traffic at 90% utilization
- Intermittent high QoS packets
- Measure high QoS packet latency

**Validation Points**:
- [ ] High QoS packets experience minimal queuing delay
- [ ] Low QoS packets continue to make progress
- [ ] No priority inversion scenarios
- [ ] QoS arbitration scales with traffic load

---

### 3.3 Fault Tolerance Integration Tests

#### Test Case: IT-Fault-001 - Single Node Failure
**Objective**: Verify network continues operating with failed node

**Test Scenario**:
- Normal operation established
- Inject node failure at coordinate (3,4)
- Continue packet transmission

**Validation Points**:
- [ ] Failed node clock correctly gated
- [ ] Routes automatically avoid failed node
- [ ] Network connectivity maintained
- [ ] No packet loss due to node failure

---

## 4. Performance Test Specifications

### 4.1 Throughput Testing

#### Test Case: PT-Throughput-001 - Maximum Packet Rate
**Objective**: Measure maximum sustainable throughput

**Test Method**:
- Send packets at maximum rate (1 per clock cycle)
- Measure successful delivery rate
- Test across different traffic patterns

**Expected Results**:
- **Target Throughput**: 200M packets/second per node
- **Sustained Rate**: >95% of theoretical maximum
- **QoS Impact**: <5% performance penalty for mixed QoS traffic

**Validation Points**:
- [ ] No dropped packets under backpressure
- [ ] Pipeline maintains full utilization
- [ ] QoS system doesn't significantly reduce throughput
- [ ] Performance consistent across network

---

### 4.2 Latency Testing

#### Test Case: PT-Latency-001 - Routing Latency
**Objective**: Measure packet routing latency

**Test Scenarios**:
1. **Local Delivery**: Same node (0 hops)
2. **Single Hop**: Adjacent node (1 hop)
3. **Two Hop**: Maximum distance (2 hops)

**Expected Results**:
- **Local Delivery**: 4 clock cycles
- **Single Hop**: 5-6 clock cycles
- **Two Hop**: 6-8 clock cycles

**Validation Points**:
- [ ] Latency matches pipeline expectations
- [ ] No unexpected delays in routing
- [ ] QoS doesn't add significant latency
- [ ] Latency consistent across path variations

---

### 4.3 Timing Closure Testing

#### Test Case: PT-Timing-001 - 200MHz Target
**Objective**: Verify timing closure at 200MHz

**Test Method**:
- Synthesize with 5.0ns clock period constraint
- Perform static timing analysis
- Measure critical path timing

**Expected Results**:
- **Target Frequency**: 200MHz (5.0ns period)
- **Critical Path**: <4.5ns (10% margin)
- **Setup/Hold**: All paths meet timing
- **Clock Skew**: <0.5ns across design

**Validation Points**:
- [ ] All timing constraints met
- [ ] No timing violations in critical paths
- [ ] Adequate timing margin for process variation
- [ ] Clock distribution meets skew requirements

---

## 5. Stress Test Specifications

### 5.1 High Traffic Volume Tests

#### Test Case: ST-Volume-001 - Network Saturation
**Objective**: Test behavior under maximum network load

**Test Method**:
- Generate traffic from all nodes simultaneously
- Random destination distribution
- Measure network stability

**Validation Points**:
- [ ] Network remains stable under saturation
- [ ] Backpressure prevents buffer overflow
- [ ] No deadlock conditions arise
- [ ] graceful degradation under overload

---

### 5.2 Edge Case Tests

#### Test Case: ST-Edge-001 - Invalid Packet Handling
**Objective**: Verify robustness against invalid inputs

**Test Scenarios**:
- Invalid packet types
- Out-of-range coordinates
- Corrupted packet headers
- Malformed data payloads

**Validation Points**:
- [ ] Invalid packets safely rejected
- [ ] No corruption of valid traffic
- [ ] Error conditions properly handled
- [ ] System remains stable

---

## 6. Test Automation

### 6.1 Test Execution Framework

**Test Script**: `run_node_tests.py`
```python
#!/usr/bin/env python3
"""MAZE Node Module Test Execution Framework"""

import subprocess
import os
import sys
from datetime import datetime

class NodeTestRunner:
    def __init__(self):
        self.test_results = []
        self.pass_count = 0
        self.fail_count = 0

    def run_test(self, test_name, test_file):
        """Execute individual test case"""
        print(f"Running test: {test_name}")

        # Compile test
        compile_cmd = [
            "verilator", "--top-module", test_name,
            "--cc", test_file, "-f", "../../rtl.filelist",
            "--CFLAGS", "-std=c++11", "--Mdir", f"obj_dir/{test_name}"
        ]

        compile_result = subprocess.run(compile_cmd, capture_output=True, text=True)
        if compile_result.returncode != 0:
            self.log_failure(test_name, "Compilation failed", compile_result.stderr)
            return False

        # Build and run test
        build_cmd = f"cd obj_dir/{test_name} && make -f V{test_name}.mk"
        run_cmd = f"cd obj_dir/{test_name} && ./V{test_name}"

        # ... test execution logic

    def log_success(self, test_name, details):
        """Record successful test"""
        self.pass_count += 1
        self.test_results.append({
            'name': test_name,
            'status': 'PASS',
            'details': details
        })

    def log_failure(self, test_name, error, output):
        """Record test failure"""
        self.fail_count += 1
        self.test_results.append({
            'name': test_name,
            'status': 'FAIL',
            'error': error,
            'output': output
        })

if __name__ == "__main__":
    runner = NodeTestRunner()

    # Run unit tests
    unit_tests = [
        ("Stage0_Basic", "ut_stage0_basic.cpp"),
        ("Stage0_Fault", "ut_stage0_fault.cpp"),
        ("Stage1_QoS", "ut_stage1_qos.cpp"),
        ("Stage2_PortMap", "ut_stage2_portmap.cpp"),
        ("Stage3_Backpressure", "ut_stage3_backpressure.cpp")
    ]

    for test_name, test_file in unit_tests:
        runner.run_test(test_name, test_file)

    # Generate report
    runner.generate_report()
```

### 6.2 Continuous Integration

**CI Script**: `ci_node_validation.sh`
```bash
#!/bin/bash
# Continuous Integration for MAZE Node Module

set -e  # Exit on any error

echo "=== MAZE Node Module CI Validation ==="
echo "Date: $(date)"
echo "Commit: $(git rev-parse HEAD)"

# 1. Syntax and Lint Check
echo "1. Running syntax and lint checks..."
verilator --lint-only -f rtl.filelist rtl/src/node/node.v

# 2. Build Test Environment
echo "2. Building test environment..."
cd testbench/cpp
make clean && make all

# 3. Run Unit Tests
echo "3. Running unit tests..."
python3 run_node_tests.py --category unit

# 4. Run Integration Tests
echo "4. Running integration tests..."
python3 run_node_tests.py --category integration

# 5. Performance Validation
echo "5. Running performance tests..."
python3 run_node_tests.py --category performance

# 6. Generate Coverage Report
echo "6. Generating coverage report..."
python3 run_node_tests.py --coverage

echo "=== CI Validation Complete ==="
```

---

## 7. Test Coverage Requirements

### 7.1 Code Coverage Targets

**Coverage Requirements**:
- **Line Coverage**: >95%
- **Branch Coverage**: >90%
- **State Coverage**: 100% (all routing states)
- **Toggle Coverage**: >85%

### 7.2 Functional Coverage Requirements

**Functional Coverage Areas**:
- All packet types (unicast, multicast, broadcast)
- All QoS levels (high, low priority)
- All routing scenarios (direct, two-hop)
- All fault conditions (node failures, congestion)
- All interface transactions (A, B, C interfaces)

---

## 8. Success Criteria

### 8.1 Functional Success
- ✅ All unit tests pass (100%)
- ✅ All integration tests pass (100%)
- ✅ No critical bugs or design flaws
- ✅ Correct operation across all specified conditions

### 8.2 Performance Success
- ✅ 200MHz timing closure achieved
- ✅ Target throughput rates met
- ✅ Latency specifications met
- ✅ QoS guarantees delivered

### 8.3 Quality Success
- ✅ >95% code coverage achieved
- ✅ All corner cases tested
- ✅ Stress testing completed
- ✅ Production readiness validated

---

## 9. Deliverables

### 9.1 Test Deliverables
- [ ] Complete test suite (unit, integration, performance)
- [ ] Automated test execution framework
- [ ] Comprehensive test reports and coverage analysis
- [ ] Performance characterization data

### 9.2 Documentation Deliverables
- [ ] Test execution procedures
- [ ] Debug and troubleshooting guides
- [ ] Performance benchmarking data
- [ ] Production validation report

---

## 10. Revision History

| **Version** | **Date** | **Changes** | **Author** |
|-------------|----------|-------------|------------|
| 1.0 | 2025-11-07 | Initial test plan for production-ready implementation | Claude Code |

---

**Document Status**: ✅ **APPROVED FOR EXECUTION**
**Implementation Priority**: HIGH - Begin with Unit Test Development
**Test Environment Setup**: IMMEDIATE - Week 1

*This test plan provides the comprehensive testing strategy required to validate the MAZE network node module for production deployment.*