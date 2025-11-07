# Interface Design Requirements

## Overview

The MAZE network uses three primary interface types for communication: A Interface (external input), B Interface (external output), and C Interface (inter-node connectivity). These interfaces provide standardized protocols for packet-based communication with proper flow control and timing characteristics.

## Interface Types

### 1. A Interface (pkt_in) - External Packet Input
- **Purpose**: External packet injection into the network
- **Direction**: Slave interface (input to network)
- **Protocol**: Ready/valid flow control
- **Usage**: One per network node (64 total)

### 2. B Interface (pkt_out) - External Packet Output
- **Purpose**: External packet extraction from the network
- **Direction**: Master interface (output from network)
- **Protocol**: Ready/valid flow control
- **Usage**: One per network node (64 total)

### 3. C Interface (pkt_con_if) - Inter-Node Connectivity
- **Purpose**: Packet routing between network nodes
- **Direction**: Bidirectional connections
- **Protocol**: Ready/valid flow control per direction
- **Usage**: 14 directional ports per node (896 total connections)

## A Interface Specification (pkt_in)

### Interface Definition
```systemverilog
interface pkt_in;
    // Control signals
    logic       pkt_in_vld;      // Packet valid indicator
    logic       pkt_in_rdy;      // Ready indicator (backpressure)

    // Packet fields
    logic       pkt_in_qos;      // QoS level (0=low, 1=high)
    logic [1:0] pkt_in_type;     // Packet type
    logic [5:0] pkt_in_src;      // Source node ID (6 bits for 64 nodes)
    logic [5:0] pkt_in_tgt;      // Target node ID
    logic [7:0] pkt_in_data;     // Data payload

    // Modports
    modport master (
        output pkt_in_vld,
        output pkt_in_qos,
        output pkt_in_type,
        output pkt_in_src,
        output pkt_in_tgt,
        output pkt_in_data,
        input  pkt_in_rdy
    );

    modport slave (
        input  pkt_in_vld,
        input  pkt_in_qos,
        input  pkt_in_type,
        input  pkt_in_src,
        input  pkt_in_tgt,
        input  pkt_in_data,
        output pkt_in_rdy
    );
endinterface
```

### Protocol Operation
- **Valid Signal**: Indicates valid packet data is present
- **Ready Signal**: Indicates receiver is ready to accept packet
- **Data Transfer**: Occurs when both valid and ready are high
- **Backpressure**: Receiver asserts low ready when not ready

### Packet Format
```
Bit(s)   Field          Description
[0]      pkt_in_qos     QoS level (0=low, 1=high)
[1:0]    pkt_in_type    Packet type (00=unicast, 01=x-mcast, 10=y-mcast, 11=broadcast)
[7:2]    pkt_in_src     Source node ID (6 bits, 0-63)
[13:8]   pkt_in_tgt     Target node ID (6 bits, 0-63)
[21:14]  pkt_in_data    Data payload (8 bits)
Total: 22 bits + ready/valid = 24 signals
```

### Timing Characteristics
- **Setup Time**: pkt_in_* signals must be stable before clock edge
- **Hold Time**: pkt_in_* signals must remain stable after clock edge
- **Latency**: Single cycle data transfer
- **Throughput**: One packet per clock cycle maximum

## B Interface Specification (pkt_out)

### Interface Definition
```systemverilog
interface pkt_out;
    // Control signals
    logic       pkt_out_vld;     // Packet valid indicator
    logic       pkt_out_rdy;     // Ready indicator (backpressure)

    // Packet fields
    logic       pkt_out_qos;     // QoS level (0=low, 1=high)
    logic [1:0] pkt_out_type;    // Packet type
    logic [5:0] pkt_out_src;     // Source node ID
    logic [5:0] pkt_out_tgt;     // Target node ID
    logic [7:0] pkt_out_data;    // Data payload

    // Modports
    modport master (
        output pkt_out_vld,
        output pkt_out_qos,
        output pkt_out_type,
        output pkt_out_src,
        output pkt_out_tgt,
        output pkt_out_data,
        input  pkt_out_rdy
    );

    modport slave (
        input  pkt_out_vld,
        input  pkt_out_qos,
        input  pkt_out_type,
        input  pkt_out_src,
        input  pkt_out_tgt,
        input  pkt_out_data,
        output pkt_out_rdy
    );
endinterface
```

### Protocol Operation
- **Valid Signal**: Indicates valid packet data is available
- **Ready Signal**: Indicates external receiver is ready
- **Data Transfer**: Occurs when both valid and ready are high
- **Backpressure**: External receiver can throttle output

### Packet Format
```
Bit(s)   Field           Description
[0]      pkt_out_qos     QoS level (0=low, 1=high)
[1:0]    pkt_out_type    Packet type (00=unicast, 01=x-mcast, 10=y-mcast, 11=broadcast)
[7:2]    pkt_out_src     Source node ID (6 bits, 0-63)
[13:8]   pkt_out_tgt     Target node ID (6 bits, 0-63)
[21:14]  pkt_out_data    Data payload (8 bits)
Total: 22 bits + ready/valid = 24 signals
```

### Timing Characteristics
- **Clock-to-Q**: Output signals available within specified time
- **Setup Time**: pkt_out_rdy must meet setup requirements
- **Hold Time**: pkt_out_rdy must meet hold requirements
- **Latency**: Single cycle data transfer

## C Interface Specification (pkt_con_if)

### Interface Definition
```systemverilog
interface pkt_con_if;
    // X-direction connections (7 ports each)
    logic [6:0] x_vld, x_rdy;        // Valid/ready signals
    logic [6:0] x_qos;               // QoS levels
    logic [1:0] x_type [6:0];        // Packet types
    logic [5:0] x_src [6:0];         // Source IDs
    logic [5:0] x_tgt [6:0];         // Target IDs
    logic [7:0] x_data [6:0];        // Data payloads

    // Y-direction connections (7 ports each)
    logic [6:0] y_vld, y_rdy;        // Valid/ready signals
    logic [6:0] y_qos;               // QoS levels
    logic [1:0] y_type [6:0];        // Packet types
    logic [5:0] y_src [6:0];         // Source IDs
    logic [5:0] y_tgt [6:0];         // Target IDs
    logic [7:0] y_data [6:0];        // Data payloads

    // Modports
    modport master (
        output x_vld, output x_rdy,
        output x_qos, output x_type, output x_src, output x_tgt, output x_data,
        output y_vld, output y_rdy,
        output y_qos, output y_type, output y_src, output y_tgt, output y_data
    );

    modport slave (
        input  x_vld, input  x_rdy,
        input  x_qos, input  x_type, input  x_src, input  x_tgt, input  x_data,
        input  y_vld, input  y_rdy,
        input  y_qos, input  y_type, input  y_src, input  y_tgt, input  y_data
    );
endinterface
```

### Port Organization
- **X-Direction**: 7 independent X-directional connections
- **Y-Direction**: 7 independent Y-directional connections
- **Bidirectional**: Each connection has separate input/output
- **Independent**: Each port operates independently

### Packet Format per Port
```
Bit(s)   Field    Description
[0]      qos      QoS level (0=low, 1=high)
[1:0]    type     Packet type
[7:2]    src      Source node ID
[13:8]   tgt      Target node ID
[21:14]  data     Data payload
Total: 22 bits per direction
```

### Connection Mapping
- **Port 0**: Nearest neighbor (distance 1)
- **Port 1**: Second nearest neighbor (distance 2)
- **Port 6**: Farthest neighbor (distance 7)
- **Direction**: X or Y based on port type

## Common Interface Characteristics

### 1. Flow Control Protocol
```systemverilog
// Ready/Valid protocol timing
always @(posedge clk) begin
    if (valid && ready) begin
        // Data transfer occurs
        data_accepted <= 1'b1;
    end else begin
        data_accepted <= 1'b0;
    end
end
```

### 2. Backpressure Handling
- **Valid without Ready**: Sender must hold data valid
- **Ready without Valid**: Receiver ready but no data
- **Both High**: Data transfer completed
- **Both Low**: No activity

### 3. Clock Domain
- **Single Clock**: All interfaces synchronous to same clock
- **Clock Skew**: Minimal skew tolerance required
- **Reset**: Synchronous reset to known state

## Timing Requirements

### 1. Setup and Hold Times
- **Input Setup**: Data signals stable T_setup before clock edge
- **Input Hold**: Data signals stable T_hold after clock edge
- **Output Valid**: Output valid within T_clock_to_Q
- **Output Hold**: Output held for minimum T_output_hold

### 2. Maximum Frequency
- **Target Frequency**: 100MHz minimum
- **Target Frequency**: 200MHz desirable
- **Timing Margin**: 20% timing margin required
- **Clock Skew**: < 10% clock period

### 3. Propagation Delay
- **Combinatorial Delay**: < 2ns for critical paths
- **Clock-to-Q Delay**: < 1ns for registered outputs
- **Wire Delay**: Account for interconnect delay
- **Load Dependence**: Consider load-dependent delays

## Signal Integrity Requirements

### 1. Signal Quality
- **Rise Time**: < 10% of clock period
- **Fall Time**: < 10% of clock period
- **Overshoot**: < 10% of signal swing
- **Undershoot**: < 10% of signal swing

### 2. Noise Immunity
- **Noise Margin**: Minimum 20% of signal swing
- **Crosstalk**: < 5% signal coupling
- **Ground Bounce**: < 5% supply noise
- **EMI**: Meet EMI specifications

### 3. Termination
- **Source Termination**: Match source impedance
- **Load Termination**: Match load impedance
- **Reflection**: Minimize signal reflections
- **Impedance Matching**: 50Ω typical

## Electrical Characteristics

### 1. Voltage Levels
- **Supply Voltage**: 1.2V core, 3.3V I/O
- **Input High**: > 0.7 * VDD
- **Input Low**: < 0.3 * VDD
- **Output High**: > 0.9 * VDD
- **Output Low**: < 0.1 * VDD

### 2. Current Requirements
- **Input Current**: < 1μA static, < 10mA dynamic
- **Output Current**: 20mA drive capability
- **Short Circuit**: Protected against short circuits
- **ESD Protection**: 2kV HBM, 200V CDM

### 3. Power Consumption
- **Static Power**: < 1mW per interface
- **Dynamic Power**: < 10mW per interface at 100MHz
- **Power Scaling**: Quadratic scaling with frequency
- **Power Gating**: Support for power gating

## Verification Requirements

### 1. Protocol Compliance
- **Ready/Valid Protocol**: Verify correct protocol behavior
- **Backpressure**: Test backpressure scenarios
- **Timing**: Verify all timing constraints
- **Corner Cases**: Test all protocol corner cases

### 2. Electrical Tests
- **Voltage Levels**: Verify voltage specifications
- **Timing**: Verify setup/hold times
- **Signal Integrity**: Verify signal quality
- **Power**: Verify power consumption

### 3. Functional Tests
- **Data Transfer**: Verify correct data transfer
- **Error Conditions**: Test error handling
- **Performance**: Verify performance requirements
- **Compatibility**: Verify interoperability

## Testability Features

### 1. Debug Interface
```systemverilog
// Debug signals for each interface
logic        debug_valid;
logic        debug_ready;
logic [21:0] debug_data;
logic        debug_error;
```

### 2. Test Mode
```systemverilog
// Test mode control
input        test_mode;
input        test_enable;
input [21:0] test_data;
output       test_result;
```

### 3. Status Monitoring
```systemverilog
// Status and performance monitoring
output [31:0] transfer_count;
output [31:0] error_count;
output [15:0] utilization;
output        buffer_status;
```

## Implementation Guidelines

### 1. Coding Style
- **SystemVerilog**: Use SystemVerilog interface constructs
- **Modports**: Define appropriate modports
- **Parameters**: Use parameters for configurability
- **Assertions**: Include protocol assertions

### 2. Synthesis Guidelines
- **Interface Synthesis**: Ensure tools support interfaces
- **Modport Handling**: Verify correct modport synthesis
- **Signal Naming**: Follow consistent naming conventions
- **Hierarchy**: Maintain clean interface hierarchy

### 3. Physical Design
- **Pin Planning**: Plan interface pin assignments
- **Floor Planning**: Consider interface placement
- **Routing**: Plan routing for interface signals
- **Timing Closure**: Ensure interface timing closure

## Compliance Requirements

### 1. Standards Compliance
- **SystemVerilog IEEE 1800-2017**: Interface syntax compliance
- **AMBA AXI4**: Consider AXI4 compatibility
- **OCP**: Consider Open Core Protocol compatibility
- **Custom Protocol**: Custom protocol compliance

### 2. Tool Compatibility
- **Synthesis Tools**: Compatible with Synopsys DC, Cadence Genus
- **Simulation Tools**: Verilator, VCS, Questa compatibility
- **Verification Tools**: Compatible with verification tools
- **Formal Tools**: Formal verification tool support

### 3. Quality Standards
- **Functional Coverage**: 100% protocol coverage
- **Code Coverage**: 95%+ code coverage
- **Assertion Coverage**: 100% assertion coverage
- **Performance Standards**: Meet all performance targets