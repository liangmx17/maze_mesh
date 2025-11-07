# Node Technical Implementation Guide

## Overview

This document provides detailed technical implementation specifications for the MAZE network Node module with 4-stage pipeline architecture. It includes pseudo-code, signal specifications, and architectural details for implementation.

## Module Interface Specification

### Parameter Definition
```systemverilog
parameter HP = 3'b000;    // Horizontal Position (0-7)
parameter VP = 3'b000;    // Vertical Position (0-7)
```

### Port Specification
```systemverilog
module node #(
    parameter HP = 3'b000,
    parameter VP = 3'b000
) (
    input               clk,
    input               rst_n,

    // A Interface - External Input
    pkt_in.mst          pkt_i,

    // B Interface - External Output
    pkt_out.mst         pkt_o,

    // C Interface - Topology Connections
    pkt_con_if.mst      pkt_con,

    // Power Gating Control
    input               pg_en,
    input [5:0]         pg_node
);
```

## 4-Stage Pipeline Architecture

### Stage 0: Input Preprocessing & Intermediate Node Calculation

#### Purpose
Process incoming A-interface packets and determine optimal intermediate node for unicast routing.

#### Key Operations
1. **Packet Type Detection**: Identify unicast packets (type = 2'b00)
2. **Coordinate Extraction**: Extract source coordinates from VP/HP parameters
3. **Intermediate Node Calculation**: Compute two potential intermediate nodes
4. **Fault Detection**: Check for failed nodes and select alternative routes
5. **Direction Decision**: Determine initial X or Y routing direction

#### Signal Specifications
```systemverilog
// Input signals from A interface
wire        a_pkt_vld;
wire        a_pkt_qos;
wire [1:0]  a_pkt_type;
wire [5:0]  a_pkt_src;
wire [5:0]  a_pkt_tgt;
wire [7:0]  a_pkt_data;
wire        a_pkt_rdy;

// Internal signals
wire [5:0]  src_coord = {VP, HP};
wire [5:0]  tgt_coord = a_pkt_tgt;
wire [2:0]  src_x = HP;
wire [2:0]  src_y = VP;
wire [2:0]  tgt_x = a_pkt_tgt[2:0];
wire [2:0]  tgt_y = a_pkt_tgt[5:3];

// Intermediate node calculations
wire [5:0]  intermediate_node_1 = {src_y, tgt_x};  // [src_y, tgt_x]
wire [5:0]  intermediate_node_2 = {tgt_y, src_x};  // [tgt_y, src_x]

// Fault detection signals
wire        node1_failed = (pg_en && (pg_node == intermediate_node_1));
wire        node2_failed = (pg_en && (pg_node == intermediate_node_2));

// Direction decision
wire        route_to_x_first;  // 1: X-first, 0: Y-first
wire [5:0]  selected_intermediate;

// Output buffer selection
wire        select_x_buffer;
wire        select_y_buffer;
```

#### Pseudo-Code Implementation
```systemverilog
// Stage 0 Logic Implementation
always_comb begin
    // Default values
    route_to_x_first = 1'b1;
    selected_intermediate = intermediate_node_1;

    // Only process unicast packets
    if (a_pkt_vld && a_pkt_type == 2'b00) begin
        // Fault-aware intermediate node selection
        if (!node1_failed) begin
            selected_intermediate = intermediate_node_1;
            // Determine initial direction based on source vs intermediate
            route_to_x_first = (src_x != selected_intermediate[2:0]);
        end else if (!node2_failed) begin
            selected_intermediate = intermediate_node_2;
            route_to_x_first = (src_x != selected_intermediate[2:0]);
        end else begin
            // Both intermediate nodes failed, use direct routing
            selected_intermediate = tgt_coord;
            route_to_x_first = (src_x != tgt_x);
        end
    end

    // Buffer selection logic
    select_x_buffer = route_to_x_first;
    select_y_buffer = ~route_to_x_first;
end

// A-interface input buffer IRS
irs_lp #(
    .DEEP(4),
    .WIDTH(23)
) u_a_input_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .din({a_pkt_type, a_pkt_qos, a_pkt_src, a_pkt_tgt, a_pkt_data}),
    .din_vld(a_pkt_vld),
    .din_rdy(a_pkt_rdy),
    .dout(a_buffered_pkt),
    .dout_vld(a_buffered_vld),
    .dout_rdy(a_buffered_rdy)
);
```

### Stage 1: QoS Arbitration & XY Routing

#### Purpose
Implement simplified directional arbitration with QoS prioritization for multiple input sources.

#### Arbitration Architecture
- **7 X-Direction Arbiters**: One for each X output port
- **7 Y-Direction Arbiters**: One for each Y output port
- **1 B-Port Arbiter**: For external output selection

#### Signal Specifications
```systemverilog
// X-Direction Arbiters (7 arbiters, one per X output port)
wire [6:0]  x_req_from_a_buf;      // Requests from A-port X buffer
wire [6:0]  x_req_from_y_inputs;   // Requests from 7 Y-direction inputs
wire [6:0]  x_req_total;           // Combined requests for each X output
wire [2:0]  x_winner_addr [6:0];   // Winner address for each X arbiter (3-bit)
wire        x_winner_vld [6:0];    // Winner valid signal

// Y-Direction Arbiters (7 arbiters, one per Y output port)
wire [6:0]  y_req_from_a_buf;      // Requests from A-port Y buffer
wire [6:0]  y_req_from_x_inputs;   // Requests from 7 X-direction inputs
wire [6:0]  y_req_total;           // Combined requests for each Y output
wire [2:0]  y_winner_addr [6:0];   // Winner address for each Y arbiter (3-bit)
wire        y_winner_vld [6:0];    // Winner valid signal

// B-Port Arbiter (1 arbiter for external output)
wire [15:0] b_req_total;           // Requests from all 16 input sources
wire [3:0]  b_winner_addr;         // Winner address (4-bit)
wire        b_winner_vld;          // Winner valid signal

// QoS signals for arbitration
wire [15:0] input_qos_levels;      // QoS levels from all input sources
```

#### Pseudo-Code Implementation
```systemverilog
// X-Direction Arbitration Logic
genvar i;
generate
    for (i = 0; i < 7; i++) begin : gen_x_arbiters
        // Combine requests from A-buffer and Y-inputs
        assign x_req_total[i] = x_req_from_a_buf[i] | x_req_from_y_inputs[i];

        // 8-input arbiter: 0=A-buffer, 1-7=Y-inputs
        arbiter_8_input #(
            .ARBITER_TYPE("PRIORITY"),  // QoS-based priority
            .HIGH_QOS_PRIORITY(1)       // High QoS has absolute priority
        ) u_x_arbiter (
            .clk(clk),
            .rst_n(rst_n),
            .req_i(x_req_total[i]),
            .qos_i({y_qos_inputs[6:0], a_buffer_qos}),
            .grant_addr_o(x_winner_addr[i]),
            .grant_valid_o(x_winner_vld[i])
        );
    end
endgenerate

// Y-Direction Arbitration Logic
generate
    for (i = 0; i < 7; i++) begin : gen_y_arbiters
        // Combine requests from A-buffer and X-inputs
        assign y_req_total[i] = y_req_from_a_buf[i] | y_req_from_x_inputs[i];

        // 8-input arbiter: 0=A-buffer, 1-7=X-inputs
        arbiter_8_input #(
            .ARBITER_TYPE("PRIORITY"),
            .HIGH_QOS_PRIORITY(1)
        ) u_y_arbiter (
            .clk(clk),
            .rst_n(rst_n),
            .req_i(y_req_total[i]),
            .qos_i({x_qos_inputs[6:0], a_buffer_qos}),
            .grant_addr_o(y_winner_addr[i]),
            .grant_valid_o(y_winner_vld[i])
        );
    end
endgenerate

// B-Port Arbitration (16-input arbiter)
arbiter_16_input #(
    .ARBITER_TYPE("PRIORITY"),
    .HIGH_QOS_PRIORITY(1)
) u_b_arbiter (
    .clk(clk),
    .rst_n(rst_n),
    .req_i(b_req_total),
    .qos_i(input_qos_levels),
    .grant_addr_o(b_winner_addr),
    .grant_valid_o(b_winner_vld)
);

// QoS Priority Logic
function automatic qos_priority;
    input [15:0] req;
    input [15:0] qos;
    input integer high_qos_count;

    // High QoS requests have absolute priority
    if (| (req & qos)) begin
        // Grant only high QoS requests
        qos_priority = req & qos;
    end else begin
        // Round-robin among low QoS requests
        qos_priority = req & ~qos;
    end
endfunction
```

### Stage 2: Output Selection

#### Purpose
Map arbitration winner addresses to specific output ports and manage output buffer availability.

#### Signal Specifications
```systemverilog
// Input data from all 16 input buffers
wire [22:0] input_buffer_data [15:0];  // 16 input buffers, 23-bit data
wire [15:0] input_buffer_vld;          // Valid signals from input buffers
wire [15:0] input_buffer_rdy;          // Ready signals to input buffers

// Winner decoding signals
wire [6:0]  x_winner_select [6:0];     // Decoded X winner selection (7 outputs)
wire [6:0]  y_winner_select [6:0];     // Decoded Y winner selection (7 outputs)
wire [15:0] b_winner_select;           // Decoded B winner selection

// Output port data
wire [22:0] x_output_data [6:0];       // X-direction output data
wire [22:0] y_output_data [6:0];       // Y-direction output data
wire [22:0] b_output_data;             // B-port output data

// Buffer availability signals
wire [6:0]  x_output_buffer_rdy;       // X output buffer ready
wire [6:0]  y_output_buffer_rdy;       // Y output buffer ready
wire        b_output_buffer_rdy;       // B output buffer ready
```

#### Pseudo-Code Implementation
```systemverilog
// X-Direction Output Selection
generate
    for (i = 0; i < 7; i++) begin : gen_x_output_sel
        // Decode winner address to select input source
        always_comb begin
            x_winner_select[i] = 7'b0;
            if (x_winner_vld[i]) begin
                case (x_winner_addr[i])
                    3'b000: x_winner_select[i] = 7'b0000001;  // A-buffer
                    3'b001: x_winner_select[i] = 7'b0000010;  // Y-input 0
                    3'b010: x_winner_select[i] = 7'b0000100;  // Y-input 1
                    // ... other Y-inputs
                    3'b111: x_winner_select[i] = 7'b1000000;  // Y-input 6
                endcase
            end
        end

        // MUX to select data from winning input
        always_comb begin
            x_output_data[i] = 23'b0;
            case (x_winner_addr[i])
                3'b000: x_output_data[i] = input_buffer_data[0];   // A-buffer X
                3'b001: x_output_data[i] = input_buffer_data[1];   // Y-input 0
                3'b010: x_output_data[i] = input_buffer_data[2];   // Y-input 1
                // ... other cases
                3'b111: x_output_data[i] = input_buffer_data[7];   // Y-input 6
            endcase
        end
    end
endgenerate

// Y-Direction Output Selection
generate
    for (i = 0; i < 7; i++) begin : gen_y_output_sel
        // Similar logic for Y-direction
        always_comb begin
            y_winner_select[i] = 7'b0;
            if (y_winner_vld[i]) begin
                case (y_winner_addr[i])
                    3'b000: y_winner_select[i] = 7'b0000001;  // A-buffer
                    3'b001: y_winner_select[i] = 7'b0000010;  // X-input 0
                    // ... other X-inputs
                endcase
            end
        end

        // Data selection MUX
        always_comb begin
            y_output_data[i] = 23'b0;
            case (y_winner_addr[i])
                3'b000: y_output_data[i] = input_buffer_data[8];   // A-buffer Y
                3'b001: y_output_data[i] = input_buffer_data[9];   // X-input 0
                // ... other cases
            endcase
        end
    end
endgenerate

// B-Port Output Selection
always_comb begin
    b_winner_select = 16'b0;
    if (b_winner_vld) begin
        b_winner_select = 16'b0001 << b_winner_addr;
    end

    // Select data from winning input (all 16 sources compete)
    case (b_winner_addr)
        4'h0: b_output_data = input_buffer_data[0];   // A-interface
        4'h1: b_output_data = input_buffer_data[1];   // C-interface Y0
        // ... other cases
        4'hF: b_output_data = input_buffer_data[15];  // Last C-interface
    endcase
end
```

### Stage 3: Output Buffering

#### Purpose
Final output buffering with registered interfaces and handshaking with topology network.

#### Signal Specifications
```systemverilog
// Registered output signals
wire [22:0] x_buffered_data [6:0];
wire [6:0]  x_buffered_vld;
wire [6:0]  x_buffered_rdy;
wire        x_buffered_qos [6:0];
wire [1:0]  x_buffered_type [6:0];
wire [5:0]  x_buffered_src [6:0];
wire [5:0]  x_buffered_tgt [6:0];
wire [7:0]  x_buffered_payload [6:0];

// Similar signals for Y and B directions
wire [22:0] y_buffered_data [6:0];
wire [6:0]  y_buffered_vld;
wire [6:0]  y_buffered_rdy;

wire [22:0] b_buffered_data;
wire        b_buffered_vld;
wire        b_buffered_rdy;

// Topology interface signals
wire [6:0]  pkt_con_x_vld;
wire [6:0]  pkt_con_x_rdy;
wire [6:0]  pkt_con_y_vld;
wire [6:0]  pkt_con_y_rdy;
```

#### Pseudo-Code Implementation
```systemverilog
// X-Direction Output Buffers
generate
    for (i = 0; i < 7; i++) begin : gen_x_output_buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23)
        ) u_x_output_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .din(x_output_data[i]),
            .din_vld(x_winner_vld[i] && x_output_buffer_rdy[i]),
            .din_rdy(),
            .dout(x_buffered_data[i]),
            .dout_vld(x_buffered_vld[i]),
            .dout_rdy(x_buffered_rdy[i])
        );

        // Output register stage
        always_ff @(posedge clk or negedge rst_n) begin
            if (!rst_n) begin
                pkt_con_x_vld[i] <= 1'b0;
                pkt_con_x_data[i] <= 23'b0;
            end else begin
                pkt_con_x_vld[i] <= x_buffered_vld[i];
                pkt_con_x_data[i] <= x_buffered_data[i];
            end
        end

        // Ready signal combination
        assign x_buffered_rdy[i] = pkt_con_x_rdy[i];
    end
endgenerate

// Y-Direction Output Buffers (similar structure)
generate
    for (i = 0; i < 7; i++) begin : gen_y_output_buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23)
        ) u_y_output_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .din(y_output_data[i]),
            .din_vld(y_winner_vld[i] && y_output_buffer_rdy[i]),
            .din_rdy(),
            .dout(y_buffered_data[i]),
            .dout_vld(y_buffered_vld[i]),
            .dout_rdy(y_buffered_rdy[i])
        );
    end
endgenerate

// B-Port Output Buffer
irs_lp #(
    .DEEP(4),
    .WIDTH(23)
) u_b_output_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .din(b_output_data),
    .din_vld(b_winner_vld && b_output_buffer_rdy),
    .din_rdy(),
    .dout(b_buffered_data),
    .dout_vld(b_buffered_vld),
    .dout_rdy(b_buffered_rdy)
);

// B-Port output register
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pkt_o.vld <= 1'b0;
        pkt_o.data <= 23'b0;
    end else begin
        pkt_o.vld <= b_buffered_vld;
        pkt_o.data <= b_buffered_data;
    end
end

assign b_buffered_rdy = pkt_o.rdy;
```

## Buffer Management Architecture

### Input Buffer Configuration
```systemverilog
// Total of 16 input buffers (IRS_LP with RO_EN)
// 1 A-interface input buffer
// 7 C-interface X-direction input buffers
// 7 C-interface Y-direction input buffers

// Input buffer instantiation template
irs_lp #(
    .DEEP(4),      // 4-deep FIFO buffer
    .WIDTH(23),    // 23-bit packet width
    .RO_EN(1)      // Read-Only enable mode
) u_input_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .din(input_data),
    .din_vld(input_vld),
    .din_rdy(input_rdy),
    .dout(buffered_data),
    .dout_vld(buffered_vld),
    .dout_rdy(buffered_rdy)
);
```

### Output Buffer Configuration
```systemverilog
// Total of 15 output buffers (IRS_LP with RO_EN)
// 1 B-interface output buffer
// 7 C-interface X-direction output buffers
// 7 C-interface Y-direction output buffers

// Output buffer instantiation template
irs_lp #(
    .DEEP(4),      // 4-deep FIFO buffer
    .WIDTH(23),    // 23-bit packet width
    .RO_EN(1)      // Read-Only enable mode
) u_output_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .din(output_data),
    .din_vld(output_vld),
    .din_rdy(output_rdy),
    .dout(final_data),
    .dout_vld(final_vld),
    .dout_rdy(final_rdy)
);
```

## Clock Gating and Power Management

### Power Gating Implementation
```systemverilog
// Clock gating for failed nodes
wire node_active = !(pg_en && (pg_node == {VP, HP}));

// Clock gating cell
assign gated_clk = node_active ? clk : 1'b0;

// Apply gated clock to all sequential logic
// All flip-flops use gated_clk instead of clk
```

### Reset Management
```systemverilog
// Synchronous reset with power gating consideration
always_ff @(posedge gated_clk or negedge rst_n) begin
    if (!rst_n || !node_active) begin
        // Reset all state to default
        pipeline_state <= IDLE;
        buffer_data <= 23'b0;
    end else begin
        // Normal operation
        // Pipeline logic here
    end
end
```

## Interface Connection Specifications

### C Interface Signal Mapping
```systemverilog
// C Interface input connections (from topology)
// X-direction inputs (7 ports)
assign c_x_in_vld[i] = pkt_con.x_vld_in[i];
assign c_x_in_data[i] = {pkt_con.x_type[i], pkt_con.x_qos[i],
                        pkt_con.x_src[i], pkt_con.x_tgt[i], pkt_con.x_data[i]};
assign c_x_in_rdy[i] = pkt_con.x_rdy_in[i];

// Y-direction inputs (7 ports)
assign c_y_in_vld[i] = pkt_con.y_vld_in[i];
assign c_y_in_data[i] = {pkt_con.y_type[i], pkt_con.y_qos[i],
                        pkt_con.y_src[i], pkt_con.y_tgt[i], pkt_con.y_data[i]};
assign c_y_in_rdy[i] = pkt_con.y_rdy_in[i];

// C Interface output connections (to topology)
// X-direction outputs (7 ports)
assign pkt_con.x_vld_out[i] = x_buffered_vld[i];
assign {pkt_con.x_type_out[i], pkt_con.x_qos_out[i],
       pkt_con.x_src_out[i], pkt_con.x_tgt_out[i], pkt_con.x_data_out[i]} = x_buffered_data[i];
assign x_buffered_rdy[i] = pkt_con.x_rdy_out[i];

// Y-direction outputs (7 ports)
assign pkt_con.y_vld_out[i] = y_buffered_vld[i];
assign {pkt_con.y_type_out[i], pkt_con.y_qos_out[i],
       pkt_con.y_src_out[i], pkt_con.y_tgt_out[i], pkt_con.y_data_out[i]} = y_buffered_data[i];
assign y_buffered_rdy[i] = pkt_con.y_rdy_out[i];
```

## Timing and Performance Considerations

### Pipeline Timing
```systemverilog
// Timing budget estimates (100MHz target)
// Stage 0: Input Processing - 3ns
//   - Packet decoding: 1ns
//   - Coordinate calculation: 0.5ns
//   - Fault checking: 0.5ns
//   - Direction decision: 0.5ns
//   - Setup margin: 0.5ns

// Stage 1: QoS Arbitration - 4ns
//   - Request combination: 0.5ns
//   - QoS priority logic: 1ns
//   - Arbiter decision: 2ns
//   - Setup margin: 0.5ns

// Stage 2: Output Selection - 2ns
//   - Winner decoding: 0.5ns
//   - Data MUX selection: 0.5ns
//   - Buffer availability: 0.5ns
//   - Setup margin: 0.5ns

// Stage 3: Output Buffering - 2ns
//   - Buffer write: 1ns
//   - Output register: 0.5ns
//   - Setup margin: 0.5ns

// Total pipeline latency: 4 clock cycles minimum
```

### Critical Paths
1. **Stage 1 Arbitration**: Most complex logic with multiple inputs
2. **Winner Decoding**: Large multiplexers for data selection
3. **Interface Handshaking**: Ready/valid propagation through buffers

## Verification and Test Points

### Key Test Points
```systemverilog
// Internal signals for verification
// Stage 0
logic [5:0] stage0_intermediate_node;
logic stage0_route_to_x_first;
logic stage0_fault_detected;

// Stage 1
logic [2:0] stage1_x_winner_addr [6:0];
logic [2:0] stage1_y_winner_addr [6:0];
logic [3:0] stage1_b_winner_addr;
logic [6:0] stage1_x_arbiter_vld;
logic [6:0] stage1_y_arbiter_vld;
logic stage1_b_arbiter_vld;

// Stage 2
logic [22:0] stage2_x_selected_data [6:0];
logic [22:0] stage2_y_selected_data [6:0];
logic [22:0] stage2_b_selected_data;

// Stage 3
logic [6:0] stage3_x_buffer_occupancy;
logic [6:0] stage3_y_buffer_occupancy;
logic stage3_b_buffer_occupancy;
```

### Test Scenarios
1. **Basic Unicast**: Single packet A→B through intermediate node
2. **QoS Priority**: High vs low priority arbitration
3. **Multiple Inputs**: Concurrent requests from different directions
4. **Fault Avoidance**: Routing around failed nodes
5. **Buffer Overflow**: Backpressure handling
6. **Pipeline Stall**: Bubble insertion and recovery

## Implementation Guidelines

### Coding Standards
- Use SystemVerilog IEEE 1800-2017 standard
- All signals declared with explicit widths
- Synchronous design with proper reset handling
- Parameterized for scalability

### Synthesis Considerations
- Target 100MHz operation (10ns period)
- Optimize arbiter implementation for area efficiency
- Use appropriate buffer sizing for performance
- Implement proper clock gating for power management

### Verification Strategy
- Unit tests for each pipeline stage
- Integration tests for end-to-end functionality
- Performance tests for throughput and latency
- Fault injection tests for robustness

## Resource Estimation

### Logic Resources (per node)
- **Combinational Logic**: ~15,000 gates
- **Sequential Logic**: ~2,000 flip-flops
- **Buffer Memory**: 31 × 23 × 4 = 2,856 bits
- **Arbiters**: 15 arbiters (7X + 7Y + 1B)
- **Multiplexers**: Large data path MUXes

### Power Consumption (per node)
- **Dynamic Power**: Proportional to switching activity
- **Leakage Power**: Minimal with proper gating
- **Clock Power**: Reduced with gated clocks
- **I/O Power**: Depends on traffic patterns

This technical implementation guide provides the detailed specifications needed to implement the MAZE network node module with 4-stage pipeline architecture, QoS arbitration, and fault tolerance capabilities.