# Topo Module Design Requirements

## Overview

The Topo module implements the network topology management for the MAZE 8×8 mesh network. It provides pure connectivity logic between all 64 nodes, managing the physical interconnect patterns without participating in routing decisions. The module splits and routes C-interface connections between nodes using IRS buffers.

## Functional Requirements

### 1. Mesh Topology Implementation
- **Network Size**: 8×8 grid (64 nodes total)
- **Connectivity Pattern**: Each node connects to 7 neighbors in X-direction and 7 neighbors in Y-direction
- **Connection Rules**: Implement Manhattan distance-based connectivity
- **Topology Type**: 2D mesh with wraparound (toroidal topology optional)

### 2. C Interface Management
- **Input Splitting**: Split each node's C interface into 28 separate connections
  - 14 X-direction connections (7 input, 7 output)
  - 14 Y-direction connections (7 input, 7 output)
- **Directional Separation**: Clear separation of input and output directions
- **Signal Routing**: Proper routing of all C interface signals

### 3. IRS Buffer Integration
- **Buffer Placement**: IRS buffers between all connected node pairs
- **Depth Configuration**: Buffer depth based on Manhattan distance
- **Buffer Types**: Support for IRS_N, IRS_HALF, and IRS_LP variants
- **Flow Control**: Proper ready/valid handshaking through buffers

### 4. Connectivity Logic
- **Node Identification**: Proper source and destination node identification
- **Path Establishment**: Correct connection paths between nodes
- **Multiplexing**: Manage multiple nodes connecting to same destination
- **Signal Integrity**: Maintain signal integrity across all connections

## Interface Specification

### Clock and Reset
```systemverilog
input               clk;            // System clock
input               rst_n;          // Active-low reset
```

### Node Interfaces
```systemverilog
// 64 Node C Interfaces
pkt_con_if.slv      node_if[63:0];  // Connections from 64 nodes
```

### Internal Structure
- **Total Connections**: 64 nodes × 14 directional ports = 896 individual connections
- **X-Direction**: 448 X-direction connections (224 input, 224 output)
- **Y-Direction**: 448 Y-direction connections (224 input, 224 output)

## Topology Architecture

### 1. Node Coordinate System
- **X-Coordinate**: 0-7 (horizontal position)
- **Y-Coordinate**: 0-7 (vertical position)
- **Node ID**: Y * 8 + X (0-63)
- **Coordinate Mapping**: Used for connectivity determination

### 2. Connection Patterns

#### X-Direction Connections
For each node at position (x, y):
- **Positive X Direction**: Connect to nodes (x+1, y), (x+2, y), ..., (x+7, y)
- **Modulo Arithmetic**: Wrap around for x > 7 (if toroidal topology)
- **Distance Calculation**: Manhattan distance = |Δx|

#### Y-Direction Connections
For each node at position (x, y):
- **Positive Y Direction**: Connect to nodes (x, y+1), (x, y+2), ..., (x, y+7)
- **Modulo Arithmetic**: Wrap around for y > 7 (if toroidal topology)
- **Distance Calculation**: Manhattan distance = |Δy|

### 3. IRS Buffer Configuration
```systemverilog
// IRS depth calculation
function automatic int calculate_irs_depth(int src_x, int src_y, int dst_x, int dst_y);
    int manhattan_dist = abs(dst_x - src_x) + abs(dst_y - src_y);
    return (manhattan_dist > 1) ? (manhattan_dist - 1) : 0;
endfunction
```

## Internal Implementation

### 1. Connection Matrix
```systemverilog
// X-direction connection matrix
for (genvar src_y = 0; src_y < 8; src_y++) begin
    for (genvar src_x = 0; src_x < 8; src_x++) begin
        for (genvar offset = 1; offset <= 7; offset++) begin
            int dst_x = (src_x + offset) % 8;
            int dst_node = dst_y * 8 + dst_x;
            int src_node = src_y * 8 + src_x;

            // X-direction connection from src to dst
            assign node_if[dst_node].x_vld_in[offset-1] = x_irs_buffer[src_node][offset-1].data_vld;
            // ... other signal connections
        end
    end
end
```

### 2. IRS Buffer Instantiation
```systemverilog
// IRS buffers for X-direction connections
for (genvar node = 0; node < 64; node++) begin
    for (genvar port = 0; port < 7; port++) begin
        irs_n #(
            .DEPTH(calculate_irs_depth(node_x, node_y, target_x, target_y)),
            .DATA_W(23)
        ) x_irs_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .data_in(node_input_data),
            .data_out(node_output_data),
            .valid_in(node_input_valid),
            .valid_out(node_output_valid),
            .ready_in(node_input_ready),
            .ready_out(node_output_ready)
        );
    end
end
```

### 3. Signal Routing Logic
```systemverilog
// Route X-direction outputs to appropriate inputs
always_comb begin
    for (int dst_node = 0; dst_node < 64; dst_node++) begin
        for (int input_port = 0; input_port < 7; input_port++) begin
            // Find which source node connects to this input port
            automatic int src_node = find_x_source_node(dst_node, input_port);
            automatic int src_port = find_x_source_port(dst_node, input_port);

            // Connect signals through IRS buffer
            node_if[dst_node].x_vld[input_port] = x_irs[src_node][src_port].valid_out;
            node_if[dst_node].x_qos[input_port] = x_irs[src_node][src_port].qos_out;
            node_if[dst_node].x_type[input_port] = x_irs[src_node][src_port].type_out;
            node_if[dst_node].x_src[input_port] = x_irs[src_node][src_port].src_out;
            node_if[dst_node].x_tgt[input_port] = x_irs[src_node][src_port].tgt_out;
            node_if[dst_node].x_data[input_port] = x_irs[src_node][src_port].data_out;

            x_irs[src_node][src_port].ready_in = node_if[dst_node].x_rdy[input_port];
        end
    end
end
```

## Performance Requirements

### 1. Timing Characteristics
- **Propagation Delay**: Minimal delay through connectivity logic
- **Clock Frequency**: Support 100MHz+ operation
- **Setup/Hold**: Meet timing for all signal paths
- **Skew Management**: Minimal clock skew across topology

### 2. Throughput Support
- **Aggregate Bandwidth**: Support maximum network throughput
- **Concurrent Connections**: All connections can be active simultaneously
- **Buffer Sizing**: Adequate buffering for network congestion
- **Backpressure**: Proper flow control implementation

### 3. Resource Utilization
- **Logic Resources**: Minimal logic for pure connectivity
- **Memory Resources**: IRS buffer memory utilization
- **Routing Resources**: Efficient wire routing implementation
- **Power Consumption**: Low static power, dynamic proportional to activity

## Verification Requirements

### 1. Connectivity Verification
- **Connection Matrix**: Verify all required connections exist
- **Signal Integrity**: Ensure signals reach correct destinations
- **No Connection Conflicts**: Verify no multiple drivers for same signal
- **Completeness**: All 896 connections properly implemented

### 2. Timing Verification
- **Setup/Hold Analysis**: Verify timing constraints met
- **Clock Domain**: Single clock domain operation verified
- **Critical Paths**: Identify and verify critical timing paths
- **Worst-case Scenarios**: Verify timing under maximum load

### 3. Functional Verification
- **Packet Flow**: End-to-end packet transmission
- **Bidirectional Communication**: Verify both directions work
- **Multiple Simultaneous Connections**: Concurrent operation testing
- **IRS Buffer Behavior**: Buffer overflow/underflow testing

### 4. Topology-specific Tests
- **Mesh Connectivity**: Verify 8×8 mesh structure
- **Neighbor Connections**: Each node connects to correct neighbors
- **Distance Calculation**: Verify Manhattan distance calculations
- **Wraparound Logic**: Test toroidal topology if implemented

## Design Constraints

### 1. Physical Constraints
- **Placement**: Optimized placement for 8×8 grid
- **Routing**: Manageable wire routing complexity
- **Area**: Efficient area utilization
- **Timing**: Critical path optimization

### 2. Logical Constraints
- **Connection Rules**: Strict adherence to mesh topology rules
- **Signal Naming**: Consistent signal naming conventions
- **Parameterization**: Support for different network sizes
- **Scalability**: Design should scale to larger networks

### 3. Implementation Constraints
- **Technology Independence**: Portable across different technologies
- **Tool Compatibility**: Compatible with major synthesis/simulation tools
- **Synthesis**: Efficient synthesis results
- **Verification**: Complete verification coverage

## Implementation Guidelines

### 1. Coding Style
- **SystemVerilog**: IEEE 1800-2017 compliance
- **Synthesis**: RTL synthesis compatibility
- **Readability**: Clear and maintainable code structure
- **Documentation**: Comprehensive inline documentation

### 2. Modular Design
- **Hierarchical Structure**: Clean hierarchical decomposition
- **Interface Consistency**: Consistent interface definitions
- **Reusable Components**: Design for component reuse
- **Separation of Concerns**: Clear functional separation

### 3. Optimization Techniques
- **Resource Sharing**: Share common resources where possible
- **Logic Optimization**: Minimize logic complexity
- **Timing Optimization**: Optimize critical timing paths
- **Power Optimization**: Minimize power consumption

## Testability Features

### 1. Debug Interfaces
- **Connection Status**: Monitor connection status
- **Signal Observation**: Access to internal signals
- **Performance Monitoring**: Throughput and latency metrics
- **Error Detection**: Comprehensive error checking

### 2. Configuration Control
- **Topology Configuration**: Runtime topology configuration
- **Buffer Configuration**: IRS buffer depth configuration
- **Debug Modes**: Special debug operation modes
- **Parameter Access**: Runtime parameter modification

### 3. Diagnostic Features
- **Loopback Tests**: Built-in loopback testing capability
- **Pattern Generation**: Test pattern generation
- **Status Reporting**: Comprehensive status reporting
- **Fault Injection**: Controlled fault injection capability

## Documentation Requirements

### 1. Architecture Documentation
- **Block Diagrams**: Complete topology architecture
- **Connection Matrices**: Detailed connection specifications
- **Signal Flow**: Signal flow documentation
- **Timing Diagrams**: Critical path timing diagrams

### 2. Interface Documentation
- **Signal Descriptions**: Complete signal specification
- **Timing Specifications**: Detailed timing requirements
- **Protocol Description**: Interface protocol documentation
- **Connection Rules**: Topology connection rules

### 3. Verification Documentation
- **Test Plan**: Comprehensive test strategy
- **Test Benches**: Complete testbench descriptions
- **Coverage Analysis**: Coverage reports and analysis
- **Regression Results**: Ongoing verification status

## Compliance Requirements

### 1. Standards Compliance
- **SystemVerilog Standard**: IEEE 1800-2017
- **Synthesis Standards**: Compatible with major synthesis tools
- **Simulation Standards**: Verilator and major simulator compatibility
- **Documentation Standards**: Industry-standard documentation

### 2. Project Compliance
- **File Organization**: Follow project file structure
- **Naming Conventions**: Adhere to naming standards
- **Code Review**: Pass all code review requirements
- **Version Control**: Proper version control practices

### 3. Quality Compliance
- **Functional Coverage**: 100% connectivity coverage
- **Code Coverage**: 95%+ line and branch coverage
- **Performance Standards**: Meet all performance targets
- **Reliability Standards**: High reliability requirements