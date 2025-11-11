# Topo Module Design Requirements

## Overview

The Topo module implements the network topology management for the MAZE 8×8 mesh network. It provides pure connectivity logic between all 64 nodes, managing the physical interconnect patterns without participating in routing decisions. The module splits and routes C-interface connections between nodes using IRS buffers.

## Functional Requirements

### 1. Torus Topology Implementation
- **Network Size**: 8×8 grid (64 nodes total)
- **Connectivity Pattern**: Each node connects to 7 neighbors in X-direction and 7 neighbors in Y-direction
- **Connection Rules**: Implement toroidal topology with modulo 8 arithmetic
- **Topology Type**: 2D torus (wraparound on both X and Y axes)

### 2. C Interface Management
- **Input Splitting**: Split each node's C interface into 28 separate connections
  - 14 X-direction connections (7 input, 7 output)
  - 14 Y-direction connections (7 input, 7 output)
- **Directional Separation**: Clear separation of input and output directions
- **Signal Routing**: Proper routing of all C interface signals

### 3. IRS Buffer Integration
- **Buffer Placement**: IRS_N buffers directly between node pairs (hard-wired connections)
- **Depth Configuration**: Buffer depth based on Manhattan distance (depth = distance-1, minimum 0)
- **Buffer Types**: Only IRS_N with TYPE_RO_EN=1 (no IRS_HALF or IRS_LP)
- **Flow Control**: Ready/valid handshaking through buffers, no intermediate topology routing

### 4. Connectivity Logic
- **Node Identification**: Proper source and destination node identification
- **Path Establishment**: Correct connection paths between nodes
- **Multiplexing**: Manage multiple nodes connecting to same destination
- **Signal Integrity**: Maintain signal integrity across all connections

## Interface Specification

### Clock and Reset
```systemverilog
input               clk;            // System clock (shared across all nodes)
input               rst_n;          // Active-low reset (shared across all nodes)
```

### Node Interfaces
```systemverilog
// 64 Node C Interfaces using slave modports
// Topo uses slave modports to connect to node master modports
pkt_con_if.slv      node_if[63:0];  // Connections to/from 64 nodes

// Interface signal structure (from interface_c.sv):
// X-direction inputs: xi_vld[6:0], xi_rdy[6:0], xi_qos[6:0], xi_type[6:0], xi_src[6:0], xi_tgt[6:0], xi_data[6:0]
// Y-direction inputs: yi_vld[6:0], yi_rdy[6:0], yi_qos[6:0], yi_type[6:0], yi_src[6:0], yi_tgt[6:0], yi_data[6:0]
// X-direction outputs: xo_vld[6:0], xo_rdy[6:0], xo_qos[6:0], xo_type[6:0], xo_src[6:0], xo_tgt[6:0], xo_data[6:0]
// Y-direction outputs: yo_vld[6:0], yo_rdy[6:0], yo_qos[6:0], yo_type[6:0], yo_src[6:0], yo_tgt[6:0], yo_data[6:0]
```

### Torus Connection Architecture
- **Network Topology**: 8×8 torus with wraparound on both axes
- **Total Connections**: 64 nodes × 14 directional ports = 896 individual connections
- **X-Direction**: 448 X-direction connections (224 input, 224 output)
- **Y-Direction**: 448 Y-direction connections (224 input, 224 output)
- **Total IRS Buffers**: 896 IRS_N buffers (448 X + 448 Y) with variable depths
- **Connection Pattern**: Hard-wired connections using torus modulo arithmetic
- **Signal Flow**: Node[outputs] → IRS_N → Node[inputs] (no intermediate routing)

## Topology Architecture

### 1. Node Coordinate System
- **X-Coordinate**: 0-7 (horizontal position)
- **Y-Coordinate**: 0-7 (vertical position)
- **Node ID**: Y * 8 + X (0-63)
- **Coordinate Mapping**: Used for connectivity determination

### 2. Torus Topology Connection Pattern

#### Torus Connection Rules
For each node at position [VP, HP] (where VP=Y coordinate, HP=X coordinate):

**X-Direction Connections:**
- **C-X[i] Output** connects to node `[VP, (HP + i + 1) mod 8]`
- **C-X[i] Input** comes from node `[VP, (HP - i - 1 + 8) mod 8]`
- **Direction**: All X connections follow increasing X coordinate direction
- **Wraparound**: Uses modulo 8 arithmetic for toroidal connections

**Y-Direction Connections:**
- **C-Y[i] Output** connects to node `[(VP + i + 1) mod 8, HP]`
- **C-Y[i] Input** comes from node `[(VP - i - 1 + 8) mod 8, HP]`
- **Direction**: All Y connections follow increasing Y coordinate direction
- **Wraparound**: Uses modulo 8 arithmetic for toroidal connections

#### Connection Implementation Examples
For node at coordinates [3, 4] (VP=3, HP=4):

**X-Direction Outputs:**
- C-X[0] → node [3, (4+1) mod 8] = [3, 5]
- C-X[1] → node [3, (4+2) mod 8] = [3, 6]
- C-X[6] → node [3, (4+7) mod 8] = [3, 3]

**Y-Direction Outputs:**
- C-Y[0] → node [(3+1) mod 8, 4] = [4, 4]
- C-Y[1] → node [(3+2) mod 8, 4] = [5, 4]
- C-Y[6] → node [(3+7) mod 8, 4] = [2, 4]

### 3. Key Connection Features

#### Bidirectional Communication
- **Separate Paths**: Each direction has dedicated input and output channels
- **Full Duplex**: Simultaneous transmission and reception in all directions
- **Independent Flow Control**: Ready/valid handshaking per direction

#### QoS Support in Connections
- **QoS Preservation**: QoS signals travel with packets across all connections
- **Arbitration Integration**: QoS signals participate in destination arbitration
- **Priority Maintenance**: High QoS packets maintain priority through topology

#### Backpressure and Flow Control
- **Ready/Valid Protocol**: Standard ready/valid handshaking between nodes
- **Buffer Management**: IRS modules provide buffering for flow control
- **Deadlock Prevention**: Proper credit-based flow control implementation

#### IRS Buffer Configuration
```systemverilog
// IRS depth calculation based on Manhattan distance in torus topology
function automatic int calculate_irs_depth(int src_x, int src_y, int dst_x, int dst_y);
    int manhattan_dist;
    int dx = (dst_x - src_x + 8) % 8;  // Torus wraparound
    int dy = (dst_y - src_y + 8) % 8;  // Torus wraparound

    // Use minimal path in torus (can go either direction)
    if (dx > 4) dx = 8 - dx;  // Use shorter wraparound path
    if (dy > 4) dy = 8 - dy;  // Use shorter wraparound path

    manhattan_dist = dx + dy;
    return (manhattan_dist > 1) ? (manhattan_dist - 1) : 0;  // Depth = distance-1
endfunction

// IRS buffer instantiation with depth based on Manhattan distance
IRS_N #(
    .PYLD_W(23),      // 23-bit packet width
    .IRS_DEEP(calculate_irs_depth(src_x, src_y, dst_x, dst_y)),  // Dynamic depth
    .TYPE_NO_READY(0),
    .TYPE_HALF(0),
    .TYPE_RO_EN(1)    // Read-only enable mode
) u_connection_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .valid_i(node_if[src_node].xo_vld[port]),     // From source node output
    .ready_o(node_if[src_node].xo_rdy[port]),     // To source node output
    .valid_o(node_if[dst_node].xi_vld[port]),     // To destination node input
    .ready_i(node_if[dst_node].xi_rdy[port]),     // From destination node input
    .payload_i({node_if[src_node].xo_type[port],   // 23-bit packet from source
                node_if[src_node].xo_qos[port],
                node_if[src_node].xo_src[port],
                node_if[src_node].xo_tgt[port],
                node_if[src_node].xo_data[port]}),
    .payload_o({node_if[dst_node].xi_type[port],   // 23-bit packet to destination
                node_if[dst_node].xi_qos[port],
                node_if[dst_node].xi_src[port],
                node_if[dst_node].xi_tgt[port],
                node_if[dst_node].xi_data[port]})
);
```

#### Signal Structure Preservation
- **Packet Format**: 23-bit packet format maintained across all connections
  - Bits [22:21]: Packet type (00=unicast, 01=X-multicast, 10=Y-multicast, 11=broadcast)
  - Bits [20]: QoS level (0=low, 1=high)
  - Bits [19:14]: Source address (6 bits)
  - Bits [13:8]: Target address (6 bits)
  - Bits [7:0]: Data payload (8 bits)
- **Signal Integrity**: All signals maintain integrity through topology
- **Timing**: Registered interfaces provide timing isolation

## Internal Implementation

### 1. Hard-Wired Torus Connection Matrix Implementation
```systemverilog
// Hard-wired torus topology connections for X-direction
// No intermediate routing logic - direct IRS connections between nodes
for (genvar src_y = 0; src_y < 8; src_y++) begin
    for (genvar src_x = 0; src_x < 8; src_x++) begin
        for (genvar offset = 0; offset < 7; offset++) begin
            // Calculate target node using torus modulo arithmetic
            int dst_x = (src_x + offset + 1) % 8;
            int dst_node = src_y * 8 + dst_x;  // Same row, different column
            int src_node = src_y * 8 + src_x;  // Source node

            // Instantiate IRS_N buffer for this specific connection
            IRS_N #(
                .PYLD_W(23),
                .IRS_DEEP(calculate_irs_depth(src_x, src_y, dst_x, src_y)),  // Manhattan-based depth
                .TYPE_NO_READY(0),
                .TYPE_HALF(0),
                .TYPE_RO_EN(1)
            ) x_irs_buffer (
                .clk(clk),
                .rst_n(rst_n),
                .valid_i(node_if[src_node].xo_vld[offset]),      // From source node X output
                .ready_o(node_if[src_node].xo_rdy[offset]),      // To source node X output
                .valid_o(node_if[dst_node].xi_vld[offset]),      // Direct to destination node X input
                .ready_i(node_if[dst_node].xi_rdy[offset]),      // From destination node X input
                .payload_i({node_if[src_node].xo_type[offset],    // 23-bit packet from source
                            node_if[src_node].xo_qos[offset],
                            node_if[src_node].xo_src[offset],
                            node_if[src_node].xo_tgt[offset],
                            node_if[src_node].xo_data[offset]}),
                .payload_o({node_if[dst_node].xi_type[offset],    // 23-bit packet to destination
                            node_if[dst_node].xi_qos[offset],
                            node_if[dst_node].xi_src[offset],
                            node_if[dst_node].xi_tgt[offset],
                            node_if[dst_node].xi_data[offset]})
            );
        end
    end
end

// Hard-wired torus topology connections for Y-direction
// No intermediate routing logic - direct IRS connections between nodes
for (genvar src_y = 0; src_y < 8; src_y++) begin
    for (genvar src_x = 0; src_x < 8; src_x++) begin
        for (genvar offset = 0; offset < 7; offset++) begin
            // Calculate target node using torus modulo arithmetic
            int dst_y = (src_y + offset + 1) % 8;
            int dst_node = dst_y * 8 + src_x;  // Same column, different row
            int src_node = src_y * 8 + src_x;  // Source node

            // Instantiate IRS_N buffer for this specific connection
            IRS_N #(
                .PYLD_W(23),
                .IRS_DEEP(calculate_irs_depth(src_x, src_y, src_x, dst_y)),  // Manhattan-based depth
                .TYPE_NO_READY(0),
                .TYPE_HALF(0),
                .TYPE_RO_EN(1)
            ) y_irs_buffer (
                .clk(clk),
                .rst_n(rst_n),
                .valid_i(node_if[src_node].yo_vld[offset]),      // From source node Y output
                .ready_o(node_if[src_node].yo_rdy[offset]),      // To source node Y output
                .valid_o(node_if[dst_node].yi_vld[offset]),      // Direct to destination node Y input
                .ready_i(node_if[dst_node].yi_rdy[offset]),      // From destination node Y input
                .payload_i({node_if[src_node].yo_type[offset],    // 23-bit packet from source
                            node_if[src_node].yo_qos[offset],
                            node_if[src_node].yo_src[offset],
                            node_if[src_node].yo_tgt[offset],
                            node_if[src_node].yo_data[offset]}),
                .payload_o({node_if[dst_node].yi_type[offset],    // 23-bit packet to destination
                            node_if[dst_node].yi_qos[offset],
                            node_if[dst_node].yi_src[offset],
                            node_if[dst_node].yi_tgt[offset],
                            node_if[dst_node].yi_data[offset]})
            );
        end
    end
end

// Total: 896 IRS_N buffers (448 X-direction + 448 Y-direction)
// Each buffer depth varies based on Manhattan distance between connected nodes
// No additional routing logic required - connections are hard-wired
```

### 2. Implementation Notes

#### IRS Buffer Depth Calculation Examples
For an 8×8 torus topology, Manhattan distances determine IRS buffer depths:

**X-Direction Examples (same row):**
- Node[3,4] → Node[3,5]: Distance = 1 → IRS depth = 0
- Node[3,4] → Node[3,6]: Distance = 2 → IRS depth = 1
- Node[3,4] → Node[3,3]: Distance = 1 (wraparound) → IRS depth = 0

**Y-Direction Examples (same column):**
- Node[3,4] → Node[4,4]: Distance = 1 → IRS depth = 0
- Node[3,4] → Node[5,4]: Distance = 2 → IRS depth = 1
- Node[3,4] → Node[2,4]: Distance = 1 (wraparound) → IRS depth = 0

**Total IRS Buffer Depth**: Variable across all connections
- Depth 0 buffers: Direct neighbor connections
- Depth 1-3 buffers: Multi-hop connections
- Total depth varies based on torus geometry

#### Key Implementation Characteristics
- **No Topology Routing Logic**: All connections are hard-wired IRS buffers
- **Direct Signal Paths**: Node output → IRS Buffer → Node input (no intermediate stages)
- **Clock Distribution**: Single clock domain, no clock gating in Topo
- **Power Management**: No power management in Topo (handled in MAZE_TOP)
- **Signal Naming**: Uses interface_c.slv modport signals (xi_*, yi_*, xo_*, yo_*)
- **Resource Usage**: 896 individual IRS_N buffers (no optimization)

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
- **Torus Connectivity**: Verify 8×8 torus structure with correct wraparound
- **Neighbor Connections**: Each node connects to correct 7 X and 7 Y neighbors
- **Modulo Arithmetic**: Verify modulo 8 calculations for wraparound connections
- **Bidirectional Communication**: Test both directions of all connections
- **QoS Preservation**: Verify QoS signals maintain priority through topology
- **Backpressure Handling**: Test ready/valid handshaking across all connections
- **IRS Buffer Behavior**: Verify 896 IRS buffers operate correctly
- **Complete Connection Matrix**: Verify all 896 connections properly implemented

## Design Constraints

### 1. Physical Constraints
- **Placement**: Optimized placement for 8×8 grid
- **Routing**: Manageable wire routing complexity
- **Area**: Efficient area utilization
- **Timing**: Critical path optimization

### 2. Logical Constraints
- **Torus Connection Rules**: Strict adherence to torus topology with modulo 8 arithmetic
- **Signal Naming**: Consistent signal naming conventions (xi_/yi_/xo_/yo_)
- **Parameterization**: Support for different network sizes (currently fixed at 8×8)
- **Scalability**: Design should scale to larger N×N torus networks
- **Bidirectional Separation**: Clear separation of input/output directions
- **QoS Signal Integrity**: QoS signals must be preserved across all connections

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