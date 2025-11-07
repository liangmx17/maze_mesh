# IRS (Insertion Ring Buffer) Module Design Requirements

## Overview

The IRS (Insertion Ring Buffer) modules provide configurable buffering for node-to-node connections in the MAZE network. These modules implement FIFO-style buffering with configurable depth based on Manhattan distance between connected nodes. Multiple IRS variants support different power and performance requirements.

## Functional Requirements

### 1. Buffer Core Functionality
- **FIFO Behavior**: First-In-First-Out buffer operation
- **Configurable Depth**: Depth based on Manhattan distance (distance - 1)
- **Packet Storage**: Store complete 23-bit packets
- **Flow Control**: Ready/valid handshaking protocol

### 2. Interface Protocol
- **Valid/Ready Protocol**: Standard ready/valid flow control
- **Backpressure Support**: Downstream backpressure propagation
- **Data Integrity**: Maintain data integrity through buffer
- **Timing**: Registered interfaces for timing closure

### 3. Multiple IRS Variants
- **IRS_N**: General-purpose insertion ring buffer
- **IRS_HALF**: Simplified buffering with reduced functionality
- **IRS_LP**: Low-power variant with power-saving features

## Interface Specification

### Generic Parameters
```systemverilog
parameter DATA_W = 23;        // Packet data width
parameter DEPTH = 4;          // Buffer depth (configurable)
parameter ADDR_W = $clog2(DEPTH);  // Address width
```

### Clock and Reset
```systemverilog
input               clk;        // System clock
input               rst_n;      // Active-low reset
```

### Input Interface (Slave)
```systemverilog
input               data_vld;   // Input data valid
input      [DATA_W-1:0] data_in; // Input packet data
input               data_qos;   // Input QoS level
input      [1:0]    data_type;  // Input packet type
input      [5:0]    data_src;   // Input source ID
input      [5:0]    data_tgt;   // Input target ID
input      [7:0]    data_payload; // Input data payload
output              data_rdy;   // Input ready (backpressure)
```

### Output Interface (Master)
```systemverilog
output              data_vld;   // Output data valid
output     [DATA_W-1:0] data_out; // Output packet data
output              data_qos;   // Output QoS level
output     [1:0]    data_type;  // Output packet type
output     [5:0]    data_src;   // Output source ID
output     [5:0]    data_tgt;   // Output target ID
output     [7:0]    data_payload; // Output data payload
input               data_rdy;   // Output ready (backpressure)
```

## Internal Architecture

### 1. Memory Structure
```systemverilog
// Dual-port RAM for buffer storage
(* ram_style = "block" *) logic [DATA_W-1:0] buffer_mem [0:DEPTH-1];

// Read/Write pointers
logic [ADDR_W:0] wr_ptr;    // Write pointer (1 extra bit for full detection)
logic [ADDR_W:0] rd_ptr;    // Read pointer (1 extra bit for full detection)

// Status flags
logic buffer_full;
logic buffer_empty;
logic [ADDR_W:0] buffer_count;
```

### 2. Control Logic
```systemverilog
// Write control
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        wr_ptr <= '0;
    end else if (write_enable) begin
        buffer_mem[wr_ptr[ADDR_W-1:0]] <= write_data;
        wr_ptr <= wr_ptr + 1'b1;
    end
end

// Read control
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        rd_ptr <= '0;
    end else if (read_enable) begin
        rd_ptr <= rd_ptr + 1'b1;
    end
end
```

### 3. Status Generation
```systemverilog
assign buffer_full = (wr_ptr[ADDR_W] != rd_ptr[ADDR_W]) &&
                     (wr_ptr[ADDR_W-1:0] == rd_ptr[ADDR_W-1:0]);
assign buffer_empty = (wr_ptr == rd_ptr);
assign buffer_count = wr_ptr - rd_ptr;

assign write_enable = data_vld && !buffer_full;
assign read_enable = data_rdy && !buffer_empty;
```

## IRS Variants

### 1. IRS_N (General Purpose)
- **Full Functionality**: Complete FIFO implementation
- **Configurable Depth**: Any depth from 1 to 16
- **Power Management**: Clock gating when empty
- **Debug Features**: Status and debug outputs

### 2. IRS_HALF (Simplified)
- **Reduced Depth**: Fixed depth of 2 or 4
- **Simplified Logic**: Minimal control logic
- **Lower Power**: Reduced switching activity
- **Area Optimized**: Minimal area implementation

### 3. IRS_LP (Low Power)
- **Power Gating**: Complete clock gating when idle
- **Reduced Functionality**: Basic FIFO operation only
- **Sleep Mode**: Power-down when buffer empty for extended time
- **Wake-up Logic**: Fast wake-up on new data arrival

## Data Path Implementation

### 1. Packet Assembly
```systemverilog
// Combine all packet fields into single data word
always_comb begin
    write_data = {
        data_type,     // [22:21]
        data_qos,      // [20]
        data_src,      // [19:14]
        data_tgt,      // [13:8]
        data_payload   // [7:0]
    };
end
```

### 2. Packet Disassembly
```systemverilog
// Extract individual fields from buffer output
always_comb begin
    data_type_out = buffer_mem[rd_ptr[ADDR_W-1:0]][22:21];
    data_qos_out = buffer_mem[rd_ptr[ADDR_W-1:0]][20];
    data_src_out = buffer_mem[rd_ptr[ADDR_W-1:0]][19:14];
    data_tgt_out = buffer_mem[rd_ptr[ADDR_ptr-1:0]][13:8];
    data_payload_out = buffer_mem[rd_ptr[ADDR_W-1:0]][7:0];
    data_out = buffer_mem[rd_ptr[ADDR_W-1:0]];
end
```

## Performance Requirements

### 1. Timing Characteristics
- **Clock Frequency**: Support 200MHz+ operation
- **Setup Time**: Input setup time < 2ns
- **Hold Time**: Input hold time < 0.5ns
- **Clock-to-Q**: Output delay < 3ns

### 2. Throughput Requirements
- **Sustained Rate**: 1 packet per clock cycle
- **Burst Handling**: Back-to-back packet support
- **Zero Bubble**: Continuous operation when not empty/full
- **Latency**: 1 cycle minimum + buffer depth

### 3. Buffer Performance
- **Read/Write**: Single cycle read/write operations
- **Simultaneous**: Concurrent read and write capability
- **Status**: Real-time status generation
- **Flow Control**: Immediate backpressure response

## Verification Requirements

### 1. Functional Tests
- **Basic FIFO Operation**: Verify correct FIFO behavior
- **Full/Empty Detection**: Test boundary conditions
- **Flow Control**: Verify ready/valid protocol
- **Data Integrity**: Ensure data preservation

### 2. Timing Tests
- **Maximum Frequency**: Verify operation at target frequency
- **Setup/Hold**: Verify timing constraints
- **Clock Skew**: Test clock skew tolerance
- **Critical Path**: Verify critical path timing

### 3. Stress Tests
- **Buffer Overflow**: Test behavior when full
- **Buffer Underflow**: Test behavior when empty
- **Burst Mode**: Test continuous operation
- **Mixed Patterns**: Random access patterns

### 4. Power Tests
- **Dynamic Power**: Measure switching power
- **Leakage Power**: Measure static power
- **Power Gating**: Verify power-down modes
- **Wake-up Time**: Measure wake-up latency

## Implementation Constraints

### 1. Technology Constraints
- **Memory Type**: Block RAM or distributed RAM
- **Clock Domain**: Single clock domain
- **Reset Strategy**: Synchronous reset
- **Library Cells**: Standard library cells only

### 2. Area Constraints
- **Memory Area**: Efficient memory utilization
- **Logic Area**: Minimal control logic
- **Routing Area**: Manageable routing complexity
- **Total Area**: Fit within allocated area budget

### 3. Power Constraints
- **Dynamic Power**: < 10mW per buffer
- **Leakage Power**: < 1mW per buffer
- **Power Gating**: > 90% power reduction in sleep mode
- **Clock Gating**: Clock gating when idle

## Design Variants

### 1. Depth Configurations
```systemverilog
// Common depth configurations
parameter DEPTH_1 = 1;    // Distance = 2 (adjacent nodes)
parameter DEPTH_2 = 2;    // Distance = 3
parameter DEPTH_3 = 3;    // Distance = 4
parameter DEPTH_6 = 6;    // Distance = 7 (maximum in 8×8 grid)
parameter DEPTH_7 = 7;    // Distance = 8 (wraparound)
```

### 2. Width Variants
```systemverilog
// Packet width configurations
parameter PKT_W_23 = 23;  // Standard MAZE packet
parameter PKT_W_32 = 32;  // Extended packet format
parameter PKT_W_64 = 64;  // Wide packet format
```

### 3. Feature Variants
```systemverilog
// Feature enable parameters
parameter ENABLE_DEBUG = 1;    // Debug outputs
parameter ENABLE_PWR_GATING = 1; // Power gating
parameter ENABLE_ECC = 0;      // Error correction
parameter ENABLE_PARITY = 1;   // Parity checking
```

## Testability Features

### 1. Debug Interface
```systemverilog
// Debug outputs
output [ADDR_W:0] debug_wr_ptr;
output [ADDR_W:0] debug_rd_ptr;
output [ADDR_W:0] debug_count;
output            debug_full;
output            debug_empty;
output            debug_overflow;
output            debug_underflow;
```

### 2. Test Mode
```systemverilog
input             test_mode;       // Enable test mode
input      [7:0]  test_pattern;    // Test data pattern
input             test_load;       // Load test pattern
output     [7:0]  test_data_out;   // Test data output
```

### 3. Scan Chain Support
```systemverilog
input             scan_enable;     // Scan enable
input             scan_in;         // Scan data input
output            scan_out;        // Scan data output
```

## Implementation Guidelines

### 1. Memory Implementation
- **Block RAM**: Use block RAM for larger buffers (> 16 entries)
- **Distributed RAM**: Use distributed RAM for small buffers
- **Register Files**: Use registers for very small buffers (< 8 entries)
- **Mixed Approach**: Optimize based on depth and width

### 2. Control Logic Optimization
- **Binary Encoding**: Use binary encoding for pointers
- **One-Hot Detection**: Use one-hot for full/empty detection
- **Pipelining**: Pipeline critical timing paths
- **Logic Sharing**: Share logic where possible

### 3. Clock Domain Considerations
- **Single Domain**: Design for single clock domain
- **Clock Gating**: Implement clock gating for power savings
- **Reset Strategy**: Use synchronous reset
- **Timing Closure**: Ensure timing closure at target frequency

## Documentation Requirements

### 1. Functional Documentation
- **Operation Description**: Detailed operational description
- **Interface Specification**: Complete interface specification
- **Timing Diagrams**: Critical timing relationships
- **State Diagrams**: Control logic state diagrams

### 2. Implementation Documentation
- **Source Code**: Well-commented source code
- **Synthesis Scripts**: Synthesis constraint files
- **Test Benches**: Comprehensive testbench suite
- **Coverage Reports**: Code coverage analysis

### 3. Performance Documentation
- **Timing Analysis**: Static timing analysis results
- **Power Analysis**: Power consumption analysis
- **Area Analysis**: Area utilization breakdown
- **Performance Metrics**: Key performance indicators

## Compliance Requirements

### 1. Standards Compliance
- **SystemVerilog**: IEEE 1800-2017 compliance
- **Synthesis**: Compatible with major synthesis tools
- **Simulation**: Verilator and major simulator compatibility
- **Power Analysis**: Compatible with power analysis tools

### 2. Project Standards
- **File Naming**: Follow project naming conventions
- **Code Style**: Adhere to project coding guidelines
- **Documentation**: Meet project documentation standards
- **Version Control**: Proper version control practices

### 3. Quality Standards
- **Functional Coverage**: 100% functional coverage
- **Code Coverage**: 95%+ line and branch coverage
- **Assertion Coverage**: Complete assertion coverage
- **Performance Standards**: Meet all specified performance targets