# MAZE_TOP Module Design Requirements

## Overview

The MAZE_TOP module is the top-level system module that instantiates and manages the entire 64-node MAZE network. It provides the interface between the external world and the internal network topology while managing fault tolerance and network configuration.

## Functional Requirements

### 1. Network Instantiation
- **Requirement**: Instantiate exactly 64 network nodes in an 8×8 grid configuration
- **Implementation**: Each node must be configured with unique coordinates:
  - `HP` (Horizontal Position): 0-7 for X-coordinate
  - `VP` (Vertical Position): 0-7 for Y-coordinate
- **Mapping**: Node ID = VP * 8 + HP (0-63)

### 2. External Interface Management
- **Requirement**: Provide 64 A interfaces for external packet input
- **Requirement**: Provide 64 B interfaces for external packet output
- **Implementation**:
  - Array of 64 `pkt_in` interfaces: `pkt_in_if[63:0]`
  - Array of 64 `pkt_out` interfaces: `pkt_out_if[63:0]`
  - Each interface connects to corresponding node's A/B ports

### 3. Topology Integration
- **Requirement**: Connect all nodes through the topology module
- **Implementation**:
  - Instantiate single `topo` module
  - Connect all node C interfaces to topology
  - Manage bidirectional packet flow between nodes

### 4. Fault Tolerance Management
- **Requirement**: Implement clock gating for failed nodes
- **Control Signals**:
  - `pg_en` (Power Gate Enable): Global fault tolerance enable
  - `pg_node[63:0]`: Per-node fault indicator (1 = failed, 0 = functional)
- **Implementation**:
  - Clock gating logic for each node based on fault status
  - Propagate fault information to all nodes for routing avoidance

### 5. Clock and Reset Management
- **Requirement**: Provide global clock and reset to all network components
- **Signals**:
  - `clk`: Global system clock
  - `rst_n`: Active-low global reset
- **Distribution**: Clock and reset must reach all nodes and topology

## Interface Specification

### Inputs
```systemverilog
input               clk;                    // Global clock
input               rst_n;                  // Active-low reset
input               pg_en;                  // Power gate enable
input      [63:0]   pg_node;                // Per-node fault indicators
```

### Interface Arrays
```systemverilog
// External input interfaces (64 ports)
pkt_in.mst          pkt_in_if[63:0];        // External packet input

// External output interfaces (64 ports)
pkt_out.slv         pkt_out_if[63:0];       // External packet output
```

## Internal Architecture

### 1. Node Array
- **Structure**: 8×8 grid of node instances
- **Coordinate Assignment**:
  ```systemverilog
  for (genvar y = 0; y < 8; y++) begin
    for (genvar x = 0; x < 8; x++) begin
      node #(.HP(x), .VP(y)) node_inst (
        .clk(clk_gated[y*8+x]),  // Gated clock
        .rst_n(rst_n),
        // A/B interface connections
        // C interface connections to topology
      );
    end
  end
  ```

### 2. Clock Gating Logic
- **Implementation**: Per-node clock gating based on fault status
- **Logic**:
  ```systemverilog
  assign clk_gated[i] = pg_en ? (pg_node[i] ? 1'b0 : clk) : clk;
  ```

### 3. Topology Integration
- **C Interface Management**:
  - 64 node C interfaces → topology module
  - Split each C interface into input/output directions
  - Manage 14 X-direction and 14 Y-direction connections per node

## Performance Requirements

### 1. Timing
- **Clock Frequency**: Target 100MHz+ (adjustable based on technology)
- **Clock Skew**: Minimal skew between gated and ungated clocks
- **Setup/Hold Times**: Meet timing constraints for all interface signals

### 2. Area
- **Gate Count**: Optimized for 64-node network implementation
- **Wire Routing**: Efficient interconnect between nodes and topology

### 3. Power
- **Dynamic Power**: Proportional to network activity
- **Static Power**: Minimized through clock gating of failed nodes

## Verification Requirements

### 1. Functional Tests
- **Network Initialization**: Verify all nodes initialize correctly
- **Interface Connectivity**: Test all 64 A/B interfaces
- **Topology Integration**: Verify node-to-node connections

### 2. Fault Tolerance Tests
- **Single Node Failure**: Test network operation with one failed node
- **Multiple Node Failure**: Test with various fault patterns
- **Clock Gating**: Verify failed nodes receive no clock

### 3. Performance Tests
- **Throughput**: Maximum sustainable packet rate
- **Latency**: End-to-end packet delivery time
- **Congestion**: Behavior under high network load

## Design Constraints

### 1. Scalability
- **Maximum Nodes**: Currently fixed at 64 (8×8)
- **Parameterization**: Future expansion to larger networks
- **Resource Limits**: Memory and logic resource bounds

### 2. Technology Constraints
- **Clock Domain**: Single clock domain design
- **Reset Strategy**: Synchronous reset assertion
- **Interface Standards**: Compatible with standard on-chip interconnect

### 3. Physical Constraints
- **Floor Planning**: 8×8 grid layout consideration
- **Wire Length**: Minimize long interconnect routes
- **Clock Distribution**: Balanced clock tree implementation

## Integration Points

### 1. External System Interface
- **Connection**: Connects to external processors/memory
- **Protocol**: Standard packet-based interface
- **Bandwidth**: Sufficient for external traffic requirements

### 2. Configuration Interface
- **Fault Configuration**: Runtime fault injection capability
- **Network Parameters**: Configurable network settings
- **Debug Interface**: Access to internal network state

### 3. Test and Debug
- **Scan Chains**: Built-in test access for manufacturing
- **Observability**: Internal signal visibility for debug
- **Control Points**: Debug control of network behavior

## Implementation Notes

### 1. Coding Style
- **Language**: SystemVerilog
- **Synthesis**: Synthesizable RTL code
- **Lint**: Pass all linting rules

### 2. Synthesis Guidelines
- **State Machines**: Binary encoding for area efficiency
- **Pipelining**: Register all outputs for timing
- **Resource Sharing**: Minimize duplicate logic where possible

### 3. Design for Testability
- **Controllability**: All internal signals controllable for test
- **Observability**: Critical internal signals observable
- **Isolation**: Ability to isolate sub-modules for testing

## Documentation Requirements

### 1. Interface Documentation
- **Signal Descriptions**: Complete signal specification
- **Timing Diagrams**: Interface timing relationships
- **Protocol Description**: Packet format and routing

### 2. Architecture Documentation
- **Block Diagram**: Complete system architecture
- **Data Flow**: Packet flow through the network
- **Control Flow**: Control signal propagation

### 3. Verification Documentation
- **Test Plan**: Comprehensive test strategy
- **Coverage Goals**: Code and functional coverage targets
- **Regression Results**: Ongoing verification status

## Compliance Requirements

### 1. Standards Compliance
- **SystemVerilog**: IEEE 1800-2017 compliance
- **Synthesis**: Compatible with major synthesis tools
- **Simulation**: Verilator and major simulator compatibility

### 2. Project Standards
- **File Naming**: Follow project file naming conventions
- **Code Style**: Adhere to project coding guidelines
- **Version Control**: Proper version control practices

### 3. Quality Requirements
- **Code Coverage**: Minimum 95% line coverage
- **Functional Coverage**: Complete scenario coverage
- **Performance**: Meet specified performance targets