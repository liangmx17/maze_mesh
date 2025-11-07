# Node Module Design Requirements

## Overview

The Node module implements a 4-stage pipeline processing element for the MAZE network. Each node handles packet routing, QoS arbitration, and provides buffering for external and inter-node communications. The node is the fundamental building block of the 64-network mesh topology.

## Functional Requirements

### 0. Reference File
/home/liangmx/maze/Provided_Code/interface_c.sv
/home/liangmx/maze/Provided_Code/node.v

keep same interface and port with reference file

### 1. Interface Management
- **A Interface**: Single input port for external packet injection
- **B Interface**: Single output port for external packet extraction
- **C Interface**: 14x2=28 ports for inter-node connectivity

### 2. 4-Stage Pipeline Architecture

#### Stage 0: Input Preprocessing & Intermediate Node Calculation
- **Purpose**: Process incoming A-interface packets and determine routing
- **Key Functions**:
  - Packet type detection (unicast vs multicast/broadcast)
  - Source coordinate extraction from VP/HP parameters
  - Intermediate node calculation for unicast packets
  - Fault detection and avoidance logic
- **Intermediate Nodes**: Calculate `[src_y, tgt_x]` and `[tgt_y, src_x]`
- **Output**: output the Selected intermediate node to A-port X-buffer or Y-buffer, determinded by initial routing decision

#### Stage 1: QoS Arbitration & XY Routing
- **Purpose**: Arbitrate between multiple inputs and determine output direction
- **Arbiter Structure**:
  - 7 X-Direction arbiters (one per X output port)
  - 7 Y-Direction arbiters (one per Y output port)
  - 1 B-Port arbiter (for external output)
- **Arbitration Logic**:
  - X-Direction: Accepts from A-port (X-buffer) and Y-direction inputs
  - Y-Direction: Accepts from A-port (Y-buffer) and X-direction inputs
  - B-Port: Accepts from all 16 input sources
- **QoS Priority**: High QoS (1) has absolute priority over Low QoS (0)
- **Output**: Winner coordinates (3-bit for X/Y, 4-bit for B-port)

#### Stage 2: Output Selection
- **Purpose**: Map winner coordinates to specific output ports
- **Functions**:
  - Decode winner coordinates to port selection
  - Manage output buffer availability
  - Handle backpressure from downstream nodes
- **Buffer Management**: IRS buffers for all output ports

#### Stage 3: Output Buffering
- **Purpose**: Final output stage with registered interfaces
- **Functions**:
  - Register all output signals for timing
  - Interface to topology module via C interface
  - Manage ready/valid handshaking
- **Connection**: Direct connection to topology network

### 3. Buffer Management
- **Input Buffers**: IRS-based buffering for all input ports
  - 1 A-interface input buffer
  - 14 C-interface input buffers
- **Output Buffers**: IRS-based buffering for all output ports
  - 1 B-interface output buffer
  - 14 C-interface output buffers
- **Buffer Depth**: Configurable based on network requirements

## Interface Specification

### Parameters
```systemverilog
parameter HP = 0;    // Horizontal Position (0-7)
parameter VP = 0;    // Vertical Position (0-7)
```

### Clock and Reset
```systemverilog
input               clk;        // System clock
input               rst_n;      // Active-low reset
```

### External Interfaces
```systemverilog
// A Interface - External Input
pkt_in.mst          pkt_i;  // External packet input

// B Interface - External Output
pkt_out.mst         pkt_o; // External packet output
```

### Network Interfaces
```systemverilog
// C Interface - Topology Connections
pkt_con_if.mst      pkt_con; (including all 7 X input, 7 Y input, 7 X output, 7 Y output port)
```

## Internal Architecture

### 1. Input Processing Pipeline
```systemverilog
// Stage 0: Input Processing
stage0_input_proc u_stage0 (
  .clk(clk),
  .rst_n(rst_n),
  .pkt_i(pkt_i),
  .intermediate_node(intermediate_node),
  .routing_decision(routing_decision)
);
```

### 2. Arbitration Network
```systemverilog
// Stage 1: QoS Arbitration
stage1_qos_arbiter u_stage1 (   //  include 7 C-X port arbiter and 7C-Y port arbiter, and 1 B port arbiter.
  .clk(clk),
  .rst_n(rst_n),
  .x_inputs(x_input_packets), // only transmit pkt_dst_x of 7 y input port and a-port x buffer
  .y_inputs(y_input_packets), // only transmit pkt_dst_y of 7 x input port and a-port y buffer
  .b_inputs(b_input_packets), // transmit all 16 input port, a 16-bit req signal
  .x_winners(x_winners),        //  a 3bit sel signal
  .y_winners(y_winners),        //  a 3bit sel signal
  .b_winner(b_winner)           //  a 4bit sel signal
);
```

### 3. Output Selection Logic
```systemverilog
// Stage 2: Output Selection
stage2_output_sel u_stage2 (
  .clk(clk),
  .rst_n(rst_n),
  .x_winners(x_winners),    // a 3-bit sel signal, select packet data from 7 y input port buffer and a-port x buffer
  .y_winners(y_winners),    // a 3-bit sel signal, select packet data from 7 x input port buffer and a-port y buffer
  .b_winner(b_winner),      //  a 4-bit sel signal
  .input_buffer_data(input_buffer_data),    //  all 16 buffer data
  .output_ports(output_ports)   //  all 15 output buffer data
);
```

### 4. Output Buffering
```systemverilog
// Stage 3: Output Buffering
stage3_output_buf u_stage3 (
  .clk(clk),
  .rst_n(rst_n),
  .output_ports(output_ports),
  .pkt_out_if(pkt_conn)
);
```

## Packet Processing Requirements

### 1. Packet Format
```
Bits    Field           Description
[1:0]   pkt_type        00=Unicast, 01=X-Mcast, 10=Y-Mcast, 11=Broadcast
[0]     pkt_qos         0=Low Priority, 1=High Priority
[5:3]   src_y           Source Y coordinate (from VP)
[2:0]   src_x           Source X coordinate (from HP)
[5:3]   tgt_y           Target Y coordinate
[2:0]   tgt_x           Target X coordinate
[7:0]   pkt_data        Data payload
```

### 2. Routing Logic

#### Unicast Routing
- **Two-Hop Strategy**: Source → Intermediate → Destination
- **Intermediate Calculation**:
  - Option 1: `[src_y, tgt_x]`
  - Option 2: `[tgt_y, src_x]`
- **Selection Criteria**:
  1. Avoid failed nodes (check pg_node)
  2. Select based on congestion/availability
  3. Default to Option 1 if both available

#### Multicast Routing
- **X-Multicast**: Target all nodes with same X coordinate
- **Y-Multicast**: Target all nodes with same Y coordinate
- **Broadcast**: Target all 64 nodes
- **Implementation**: No need to implement in current version 

### 3. QoS Arbitration Rules
- **High Priority**: QoS=1 packets have absolute priority
- **Fairness**: Round-robin among same-priority packets

## Performance Requirements

### 1. Throughput
- **Pipeline Rate**: 1 packet per clock cycle per pipeline stage
- **Sustained Throughput**: Dependent on arbitration and congestion
- **Peak Throughput**: 15 packets per cycle (theoretical maximum)

### 2. Latency
- **Pipeline Latency**: 4 clock cycles minimum
- **Network Latency**: 2 hops for typical unicast
- **Queuing Latency**: Variable based on congestion

### 3. Buffer Requirements
- **Input Buffer Depth**: USE IRS_LP (RO_EN) 
- **Output Buffer Depth**: USE IRS_LP (RO_EN)

## Verification Requirements

### 1. Unit Tests
- **Stage 0 Testing**: Intermediate node calculation accuracy
- **Stage 1 Testing**: QoS arbitration correctness
- **Stage 2 Testing**: Output selection logic
- **Stage 3 Testing**: Output buffering and timing

### 2. Integration Tests
- **Pipeline Integration**: End-to-end packet flow
- **Interface Testing**: A/B/C interface protocol compliance
- **Arbitration Testing**: Multi-input contention scenarios

### 3. Scenario Tests
- **Unicast Routing**: Various source/destination combinations
- **Multicast Handling**: X and Y multicast scenarios
- **QoS Priority**: High vs low priority arbitration
- **Fault Tolerance**: Failed node avoidance
- **Congestion Handling**: Backpressure and buffer management

## Design Constraints

### 1. Timing Constraints
- **Clock Frequency**: 100MHz target (technology dependent)
- **Setup Time**: All inputs must meet setup requirements
- **Hold Time**: All outputs must meet hold requirements
- **Clock Skew**: Minimal skew within the node

### 2. Resource Constraints
- **Logic Utilization**: Optimized for 64-node implementation
- **Memory Usage**: Efficient buffer implementation
- **Wire Routing**: Manageable interconnect complexity

### 3. Power Constraints
- **Dynamic Power**: Proportional to switching activity
- **Leakage Power**: Minimized through proper design
- **Clock Gating**: Possible for unused pipeline stages

## Implementation Guidelines

### 1. Coding Style
- **Language**: SystemVerilog
- **Synthesis**: RTL synthesis compatible
- **Simulation**: Verilator and major simulator compatible
- **Lint**: Pass all linting checks

### 2. State Machine Design
- **Encoding**: Binary encoding for area efficiency
- **Reset**: Synchronous reset to known state
- **Timeout**: Proper handling of stall conditions

### 3. Pipeline Design
- **Register Stages**: All pipeline stages registered
- **Control Signals**: Proper pipeline control and stall
- **Data Path**: Efficient data path implementation

## Testability Requirements

### 1. Controllability
- **Pipeline Control**: Ability to stall and advance pipeline
- **Interface Control**: Direct control of all interfaces
- **Parameter Access**: Runtime parameter modification

### 2. Observability
- **Pipeline State**: Visibility into all pipeline stages
- **Internal Signals**: Access to critical internal nodes
- **Performance Counters**: Throughput and latency monitoring

### 3. Debug Features
- **Trace Capability**: Packet tracing through pipeline
- **Error Detection**: Comprehensive error checking
- **Status Reporting**: Node status and health monitoring

## Documentation Requirements

### 1. Interface Documentation
- **Timing Diagrams**: Complete interface timing
- **Protocol Description**: Detailed interface protocols
- **Signal Descriptions**: All signals documented

### 2. Architecture Documentation
- **Pipeline Diagram**: Complete pipeline architecture
- **Data Flow**: Packet flow documentation
- **Control Flow**: Control signal documentation

### 3. Verification Documentation
- **Test Plan**: Comprehensive test strategy
- **Test Benches**: Complete testbench descriptions
- **Coverage Report**: Coverage analysis and goals

## Compliance Requirements

### 1. Standards Compliance
- **SystemVerilog**: IEEE 1800-2017
- **Synthesis**: Compatible with Synopsys DC
- **Simulation**: Verilator

### 2. Project Compliance
- **File Structure**: Follow project file organization
- **Naming Conventions**: Follow project naming standards
- **Code Review**: Pass all code review requirements

### 3. Quality Compliance
- **Functional Coverage**: 100% functional coverage
- **Code Coverage**: 95%+ line and branch coverage
- **Performance**: Meet all specified performance targets
