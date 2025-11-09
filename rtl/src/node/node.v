// ====================================================================
// MAZE Network Node Module - 4-Stage Pipeline Implementation
// ====================================================================
//
// Implements 4-stage pipeline processing for 8x8 mesh topology
// Based on Node_Technical_Implementation_Guide.md specifications
//
// Architecture Features:
// - Stage 0: Input Preprocessing & Intermediate Node Calculation
// - Stage 1: QoS Arbitration & XY Routing (7 X-arbiters + 7 Y-arbiters + 1 B-port arbiter)
// - Stage 2: Output Selection with winner decoding and data MUX
// - Stage 3: Output Buffering with IRS_LP buffers
// - 16 input buffers (1 A-interface + 7 C-X-input + 7 C-Y-input)
// - 15 output buffers (1 B-interface + 7 C-X-output + 7 C-Y-output)
// - Two-hop unicast routing with intermediate node calculation
// - QoS arbitration with high priority absolute priority
// - Fault tolerance with clock gating
//
// Packet Format (23-bit): [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
//
// ====================================================================

// Include global definitions and interfaces
`include "../../include/global_defines/top_define.v"
`include "../../include/interfaces/interface_a.sv"
`include "../../include/interfaces/interface_b.sv"
`include "../../include/interfaces/interface_c.sv"
`include "../../../Provided_Code/irs.v"
`include "../../../Provided_Code/arbiter_with_qos.v"

module node #(
    parameter HP = 3'b000,    // Horizontal Position (0-7)
    parameter VP = 3'b000     // Vertical Position (0-7)
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

// ====================================================================
// Parameter Definitions and Constants
// ====================================================================

localparam PKT_W = 23;  // Total packet width: 2 type + 1 qos + 6 src + 6 tgt + 8 data
localparam NODE_COORD = {VP, HP};
localparam NUM_X_PORTS = 7;
localparam NUM_Y_PORTS = 7;

// ====================================================================
// Stage 0: Input Preprocessing & Intermediate Node Calculation
// ====================================================================

// Input signals from A interface
wire        a_pkt_vld;
wire        a_pkt_qos;
wire [1:0]  a_pkt_type;
wire [5:0]  a_pkt_src;
wire [5:0]  a_pkt_tgt;
wire [7:0]  a_pkt_data;
wire        a_pkt_rdy;

// A-interface signal connections
assign a_pkt_vld = pkt_i.pkt_in_vld;
assign a_pkt_qos = pkt_i.pkt_in_qos;
assign a_pkt_type = pkt_i.pkt_in_type;
assign a_pkt_src = pkt_i.pkt_in_src;
assign a_pkt_tgt = pkt_i.pkt_in_tgt;
assign a_pkt_data = pkt_i.pkt_in_data;
assign pkt_i.pkt_in_rdy = a_pkt_rdy;

// A-interface input buffer IRS_N - must be defined before fault detection logic
wire [22:0] a_buffered_pkt;
wire        a_buffered_vld;
wire        a_buffered_rdy;

IRS_N #(
    .PYLD_W(23),
    .IRS_DEEP(1),
    .TYPE_NO_READY(0),
    .TYPE_HALF(0),
    .TYPE_RO_EN(1)
) u_a_input_buffer (
    .clk(clk),        // Use direct clk (clock gating in MAZE_TOP)
    .rst_n(rst_n),
    .valid_i(a_pkt_vld),
    .ready_i(a_pkt_rdy),
    .valid_o(a_buffered_vld),
    .ready_o(a_buffered_rdy),
    .payload_i({a_pkt_type, a_pkt_qos, a_pkt_src, a_pkt_tgt, a_pkt_data}),
    .payload_o(a_buffered_pkt)
);

// Fix unconnected a_pkt_rdy signal - connect to input buffer ready
assign a_pkt_rdy = a_buffered_rdy;

// Internal signals for coordinate extraction - only source coordinates (from node position)
wire [5:0]  src_coord = NODE_COORD;
wire [2:0]  src_x = HP;
wire [2:0]  src_y = VP;

// Direction decision signals
wire        route_to_x_first;  // 1: X-first, 0: Y-first
wire [5:0]  selected_intermediate;

// Output buffer selection signals - fix multiple driver conflicts
wire        select_x_buffer;
wire        select_y_buffer;

// Stage 0 Logic Implementation - Fault-Aware Two-Hop Routing
// Note: This logic operates on A input buffer output signals
always_comb begin
    // Default values
    route_to_x_first = 1'b1;
    selected_intermediate = src_coord;  // Default to source coordinate

    // Extract packet fields from A input buffer output
    wire [1:0]  buffered_pkt_type = a_buffered_pkt[22:21];
    wire [5:0]  buffered_pkt_tgt = a_buffered_pkt[13:8];
    wire [5:0]  buffered_pkt_src = a_buffered_pkt[19:14];  // Fix undefined variable
    wire [2:0]  buffered_tgt_x = buffered_pkt_tgt[2:0];
    wire [2:0]  buffered_tgt_y = buffered_pkt_tgt[5:3];

    // Only process unicast packets (type = 2'b00) from A input buffer
    if (a_buffered_vld && buffered_pkt_type == 2'b00) begin
        // Check for local delivery (source = target) - route to A-Y buffer
        wire is_local_delivery = (buffered_pkt_src == buffered_pkt_tgt);

        if (is_local_delivery) begin
            // Local delivery: route to A-Y buffer (will exit through B port)
            select_x_buffer = 1'b0;
            select_y_buffer = 1'b1;  // Route to Y buffer for local delivery
            selected_intermediate = src_coord;  // No intermediate node needed
            route_to_x_first = 1'b0;  // Not applicable for local delivery
        end else begin
            // Network routing: need intermediate node

            // Recalculate intermediate nodes with correct target from buffered packet
            wire [5:0] buffered_intermediate_1 = {src_y, buffered_tgt_x};  // [src_y, tgt_x]
            wire [5:0] buffered_intermediate_2 = {buffered_tgt_y, src_x};  // [tgt_y, src_x]

            // Simplified fault detection: at most 1 fault node
            // If intermediate node 1 is the fault, use node 2. Otherwise, use node 1.
            if (pg_en && (pg_node == buffered_intermediate_1)) begin
                // Node 1 is faulted, use node 2
                selected_intermediate = buffered_intermediate_2;
            end else begin
                // Node 1 is not faulted, use node 1 (regardless of node 2 status)
                selected_intermediate = buffered_intermediate_1;
            end

            // Route to X first if we need to change X coordinate to reach intermediate
            route_to_x_first = (src_x != selected_intermediate[2:0]);

            // Buffer selection logic based on routing decision
            select_x_buffer = route_to_x_first;
            select_y_buffer = ~route_to_x_first;
        end
    end else begin
        // Non-unicast packets or no valid packet: default routing
        select_x_buffer = 1'b0;
        select_y_buffer = 1'b0;
    end
end

// A-interface input buffer already defined above before fault detection logic

// A-X and A-Y route buffers for Stage 0 output
wire [22:0] a_x_buffered_data;
wire        a_x_buffered_vld;
wire        a_x_buffered_rdy;

IRS_N #(
    .PYLD_W(23),
    .IRS_DEEP(1),
    .TYPE_NO_READY(0),
    .TYPE_HALF(0),
    .TYPE_RO_EN(1)
) u_a_x_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .valid_i(a_buffered_vld && select_x_buffer),  // Only when X-direction selected
    .ready_i(a_x_buffered_rdy),
    .valid_o(a_x_buffered_vld),
    .ready_o(a_x_buffered_rdy),
    .payload_i(a_buffered_pkt),
    .payload_o(a_x_buffered_data)
);

wire [22:0] a_y_buffered_data;
wire        a_y_buffered_vld;
wire        a_y_buffered_rdy;

IRS_N #(
    .PYLD_W(23),
    .IRS_DEEP(1),
    .TYPE_NO_READY(0),
    .TYPE_HALF(0),
    .TYPE_RO_EN(1)
) u_a_y_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .valid_i(a_buffered_vld && select_y_buffer),  // Only when Y-direction selected
    .ready_i(a_y_buffered_rdy),
    .valid_o(a_y_buffered_vld),
    .ready_o(a_y_buffered_rdy),
    .payload_i(a_buffered_pkt),
    .payload_o(a_y_buffered_data)
);

// A-B direct buffer removed - local delivery now uses A-Y buffer

// ====================================================================
// Input Buffer Management (16 total input buffers for B arbitration)
// Architecture: 1 A-interface + 7 C-X-input + 7 C-Y-input + 1 A-X + 1 A-Y
// Local delivery uses A-Y buffer, no direct B path
// ====================================================================

genvar i;

// C-Interface Input Buffers - X Direction (7 buffers)
wire [6:0]  c_x_in_vld, c_x_in_rdy;
wire [6:0]  c_x_in_qos;
wire [1:0]  c_x_in_type [6:0];
wire [5:0]  c_x_in_src [6:0];
wire [5:0]  c_x_in_tgt [6:0];
wire [7:0]  c_x_in_data [6:0];
wire [22:0] c_x_buffered_data [6:0];
wire [6:0]  c_x_buffered_vld;
wire [6:0]  c_x_buffered_rdy;

// C-Interface Input Buffers - Y Direction (7 buffers)
wire [6:0]  c_y_in_vld, c_y_in_rdy;
wire [6:0]  c_y_in_qos;
wire [1:0]  c_y_in_type [6:0];
wire [5:0]  c_y_in_src [6:0];
wire [5:0]  c_y_in_tgt [6:0];
wire [7:0]  c_y_in_data [6:0];
wire [22:0] c_y_buffered_data [6:0];
wire [6:0]  c_y_buffered_vld;
wire [6:0]  c_y_buffered_rdy;

// Connect C-interface inputs and instantiate input buffers
generate
    for (i = 0; i < NUM_X_PORTS; i++) begin : gen_c_input_buffers
        // X-direction inputs (from topology)
        assign c_x_in_vld[i] = pkt_con.x_vld[i];
        assign c_x_in_qos[i] = pkt_con.x_qos[i];
        assign c_x_in_type[i] = pkt_con.x_type[i];
        assign c_x_in_src[i] = pkt_con.x_src[i];
        assign c_x_in_tgt[i] = pkt_con.x_tgt[i];
        assign c_x_in_data[i] = pkt_con.x_data[i];
        assign pkt_con.x_rdy[i] = c_x_in_rdy[i];

        // Y-direction inputs (from topology)
        assign c_y_in_vld[i] = pkt_con.y_vld[i];
        assign c_y_in_qos[i] = pkt_con.y_qos[i];
        assign c_y_in_type[i] = pkt_con.y_type[i];
        assign c_y_in_src[i] = pkt_con.y_src[i];
        assign c_y_in_tgt[i] = pkt_con.y_tgt[i];
        assign c_y_in_data[i] = pkt_con.y_data[i];
        assign pkt_con.y_rdy[i] = c_y_in_rdy[i];

        // X-direction input buffer IRS_N
        IRS_N #(
            .PYLD_W(23),
            .IRS_DEEP(1),
            .TYPE_NO_READY(0),
            .TYPE_HALF(0),
            .TYPE_RO_EN(1)
        ) u_c_x_input_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .valid_i(c_x_in_vld[i]),
            .ready_i(c_x_in_rdy[i]),
            .valid_o(c_x_buffered_vld[i]),
            .ready_o(c_x_buffered_rdy[i]),
            .payload_i({c_x_in_type[i], c_x_in_qos[i], c_x_in_src[i], c_x_in_tgt[i], c_x_in_data[i]}),
            .payload_o(c_x_buffered_data[i])
        );

        // Y-direction input buffer IRS_N
        IRS_N #(
            .PYLD_W(23),
            .IRS_DEEP(1),
            .TYPE_NO_READY(0),
            .TYPE_HALF(0),
            .TYPE_RO_EN(1)
        ) u_c_y_input_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .valid_i(c_y_in_vld[i]),
            .ready_i(c_y_in_rdy[i]),
            .valid_o(c_y_buffered_vld[i]),
            .ready_o(c_y_buffered_rdy[i]),
            .payload_i({c_y_in_type[i], c_y_in_qos[i], c_y_in_src[i], c_y_in_tgt[i], c_y_in_data[i]}),
            .payload_o(c_y_buffered_data[i])
        );
    end
endgenerate

// ====================================================================
// Complete Input Buffer Array (16 buffers total for Stage 1)
// Index Mapping:
// [0] = A-X buffer, [1-7] = C-Y buffers, [8] = A-Y buffer, [9-15] = C-X buffers
// ====================================================================

wire [22:0] all_input_data [15:0];
wire [15:0] all_input_vld;
wire [15:0] all_input_rdy;
wire [15:0] all_input_qos;

// Connect all input buffers to unified array for arbitration
assign all_input_data[0] = a_x_buffered_data;        // A-X input
assign all_input_vld[0] = a_x_buffered_vld;
assign all_input_rdy[0] = a_x_buffered_rdy;
assign all_input_qos[0] = a_x_buffered_data[20];     // QoS field

assign all_input_data[1:7] = c_y_buffered_data;      // C-Y inputs (7 buffers)
assign all_input_vld[1:7] = c_y_buffered_vld;
assign all_input_rdy[1:7] = c_y_buffered_rdy;
assign all_input_qos[1:7] = c_y_in_qos;

assign all_input_data[8] = a_y_buffered_data;        // A-Y input
assign all_input_vld[8] = a_y_buffered_vld;
assign all_input_rdy[8] = a_y_buffered_rdy;
assign all_input_qos[8] = a_y_buffered_data[20];     // QoS field

assign all_input_data[9:15] = c_x_buffered_data;     // C-X inputs (7 buffers)
assign all_input_vld[9:15] = c_x_buffered_vld;
assign all_input_rdy[9:15] = c_x_buffered_rdy;
assign all_input_qos[9:15] = c_x_in_qos;

// ====================================================================
// Stage 1&2: Combined Arbitration and Output Selection
// Architecture: 7 X-direction arbiters + 7 Y-direction arbiters + 1 B-port arbiter
// Each arbiter outputs grant vector used for direct data selection
// ====================================================================

// Output data for each direction
wire [22:0] x_output_data [6:0];       // X-direction output data
wire [22:0] y_output_data [6:0];       // Y-direction output data
wire [22:0] b_output_data;             // B-port output data

// Backpressure signals from actual output buffers
wire [6:0]  x_output_buffer_rdy;       // From X output buffers
wire [6:0]  y_output_buffer_rdy;       // From Y output buffers
wire        b_output_buffer_rdy;       // From B output buffer

// X-Direction Output Selection (7 outputs)
generate
    for (i = 0; i < NUM_X_PORTS; i++) begin : gen_x_output_sel
        wire [7:0] x_grant;
        reg [7:0] x_grant_reg;             // Registered grant signal
        reg x_grant_valid;                  // Registered grant valid

        // C-X Output Port i: Accepts C-Y[y] requests where dst_x[y] == (HP + i + 1) mod 8, plus A-Y request
        // Request logic: req[y][x] = dst_x[y] == (HP + x + 1) mod 8
        wire [7:0] x_req_inputs;
        wire [7:0] x_qos_inputs;

        // Calculate target X coordinate for this output port
        wire [2:0] target_x_coord = (HP + i + 1) % 8;

        // A-Y input (index 0)
        assign x_req_inputs[0] = all_input_vld[8];  // A-Y always participates
        assign x_qos_inputs[0] = all_input_qos[8];

        // C-Y inputs (index 1:7 correspond to C-Y[0:6])
        genvar j;
        generate
            for (j = 0; j < NUM_Y_PORTS; j++) begin : gen_x_req_logic
                // Extract destination X coordinate from C-Y[j] packet
                wire [2:0] cy_dst_x = c_y_buffered_data[j][13:8] & 3'b111;  // tgt[2:0] from C-Y[j]

                // Request only if destination X matches target coordinate
                assign x_req_inputs[j+1] = all_input_vld[j+1] && (cy_dst_x == target_x_coord);
                assign x_qos_inputs[j+1] = all_input_qos[j+1];
            end
        endgenerate

        // Use provided QoS arbiter for this output port
        arbiter_with_qos #(
            .WIDTH(8)
        ) u_x_arbiter_port (
            .req(x_req_inputs),
            .qos(x_qos_inputs),
            .gnt(x_grant)
        );

        // Register grant signal
        always_ff @(posedge clk or negedge rst_n) begin
            if (!rst_n) begin
                x_grant_reg <= 8'b0;
                x_grant_valid <= 1'b0;
            end else begin
                x_grant_reg <= x_grant;
                x_grant_valid <= |x_grant;
            end
        end

        // Select data using registered grant vector (priority encoder)
        always_comb begin
            if (x_grant_valid && x_output_buffer_rdy[i]) begin
                case (1'b1)
                    x_grant_reg[7]: x_output_data[i] = c_y_buffered_data[6];  // C-Y[6]
                    x_grant_reg[6]: x_output_data[i] = c_y_buffered_data[5];  // C-Y[5]
                    x_grant_reg[5]: x_output_data[i] = c_y_buffered_data[4];  // C-Y[4]
                    x_grant_reg[4]: x_output_data[i] = c_y_buffered_data[3];  // C-Y[3]
                    x_grant_reg[3]: x_output_data[i] = c_y_buffered_data[2];  // C-Y[2]
                    x_grant_reg[2]: x_output_data[i] = c_y_buffered_data[1];  // C-Y[1]
                    x_grant_reg[1]: x_output_data[i] = c_y_buffered_data[0];  // C-Y[0]
                    x_grant_reg[0]: x_output_data[i] = a_x_buffered_data;      // A-X
                    default: x_output_data[i] = 23'b0;
                endcase
            end else begin
                x_output_data[i] = 23'b0;
            end
        end

        // Note: Ready signals will be handled globally to avoid multiple driver conflicts
    end
endgenerate

// Y-Direction Output Selection (7 outputs)
generate
    for (i = 0; i < NUM_Y_PORTS; i++) begin : gen_y_output_sel
        wire [7:0] y_grant;
        reg [7:0] y_grant_reg;             // Registered grant signal
        reg y_grant_valid;                  // Registered grant valid

        // C-Y Output Port i: Accepts C-X[x] requests where dst_y[x] == (VP + i + 1) mod 8, plus A-X request
        // Request logic: req[x][y] = dst_y[x] == (VP + y + 1) mod 8
        wire [7:0] y_req_inputs;
        wire [7:0] y_qos_inputs;

        // Calculate target Y coordinate for this output port
        wire [2:0] target_y_coord = (VP + i + 1) % 8;

        // A-X input (index 0)
        assign y_req_inputs[0] = all_input_vld[0];  // A-X always participates
        assign y_qos_inputs[0] = all_input_qos[0];

        // C-X inputs (index 1:7 correspond to C-X[0:6])
        genvar k;
        generate
            for (k = 0; k < NUM_X_PORTS; k++) begin : gen_y_req_logic
                // Extract destination Y coordinate from C-X[k] packet
                wire [2:0] cx_dst_y = (c_x_buffered_data[k][13:8] >> 3) & 3'b111;  // tgt[5:3] from C-X[k]

                // Request only if destination Y matches target coordinate
                assign y_req_inputs[k+1] = all_input_vld[k+9] && (cx_dst_y == target_y_coord);
                assign y_qos_inputs[k+1] = all_input_qos[k+9];
            end
        endgenerate

        // Use provided QoS arbiter for this output port
        arbiter_with_qos #(
            .WIDTH(8)
        ) u_y_arbiter_port (
            .req(y_req_inputs),
            .qos(y_qos_inputs),
            .gnt(y_grant)
        );

        // Register grant signal
        always_ff @(posedge clk or negedge rst_n) begin
            if (!rst_n) begin
                y_grant_reg <= 8'b0;
                y_grant_valid <= 1'b0;
            end else begin
                y_grant_reg <= y_grant;
                y_grant_valid <= |y_grant;
            end
        end

        // Select data using registered grant vector (priority encoder)
        always_comb begin
            if (y_grant_valid && y_output_buffer_rdy[i]) begin
                case (1'b1)
                    y_grant_reg[7]: y_output_data[i] = c_x_buffered_data[6];  // C-X[6]
                    y_grant_reg[6]: y_output_data[i] = c_x_buffered_data[5];  // C-X[5]
                    y_grant_reg[5]: y_output_data[i] = c_x_buffered_data[4];  // C-X[4]
                    y_grant_reg[4]: y_output_data[i] = c_x_buffered_data[3];  // C-X[3]
                    y_grant_reg[3]: y_output_data[i] = c_x_buffered_data[2];  // C-X[2]
                    y_grant_reg[2]: y_output_data[i] = c_x_buffered_data[1];  // C-X[1]
                    y_grant_reg[1]: y_output_data[i] = c_x_buffered_data[0];  // C-X[0]
                    y_grant_reg[0]: y_output_data[i] = a_y_buffered_data;      // A-Y
                    default: y_output_data[i] = 23'b0;
                endcase
            end else begin
                y_output_data[i] = 23'b0;
            end
        end

        // Note: Ready signals will be handled globally to avoid multiple driver conflicts
    end
endgenerate

// B-Port Output Selection (1 output)
wire [15:0] b_grant;
reg [15:0] b_grant_reg;            // Registered grant signal
reg b_grant_valid;                 // Registered grant valid

// B-Port Arbiter - all 16 input sources compete for B output
arbiter_with_qos #(
    .WIDTH(16)
) u_b_arbiter (
    .req(all_input_vld),
    .qos(all_input_qos),
    .gnt(b_grant)
);

// Register grant signal
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        b_grant_reg <= 16'b0;
        b_grant_valid <= 1'b0;
    end else begin
        b_grant_reg <= b_grant;
        b_grant_valid <= |b_grant;
    end
end

always_comb begin
    // B-port arbiter selects data from all input sources
    if (b_grant_valid && b_output_buffer_rdy) begin
        // Network routing: from B-port arbiter using registered grant vector
        case (1'b1)
            b_grant_reg[15]: b_output_data = c_x_buffered_data[6];  // C-X[6]
            b_grant_reg[14]: b_output_data = c_x_buffered_data[5];  // C-X[5]
            b_grant_reg[13]: b_output_data = c_x_buffered_data[4];  // C-X[4]
            b_grant_reg[12]: b_output_data = c_x_buffered_data[3];  // C-X[3]
            b_grant_reg[11]: b_output_data = c_x_buffered_data[2];  // C-X[2]
            b_grant_reg[10]: b_output_data = c_x_buffered_data[1];  // C-X[1]
            b_grant_reg[9]:  b_output_data = c_x_buffered_data[0];  // C-X[0]
            b_grant_reg[8]:  b_output_data = a_y_buffered_data;      // A-Y
            b_grant_reg[7]:  b_output_data = c_y_buffered_data[6];  // C-Y[6]
            b_grant_reg[6]:  b_output_data = c_y_buffered_data[5];  // C-Y[5]
            b_grant_reg[5]:  b_output_data = c_y_buffered_data[4];  // C-Y[4]
            b_grant_reg[4]:  b_output_data = c_y_buffered_data[3];  // C-Y[3]
            b_grant_reg[3]:  b_output_data = c_y_buffered_data[2];  // C-Y[2]
            b_grant_reg[2]:  b_output_data = c_y_buffered_data[1];  // C-Y[1]
            b_grant_reg[1]:  b_output_data = c_y_buffered_data[0];  // C-Y[0]
            b_grant_reg[0]:  b_output_data = a_x_buffered_data;      // A-X
            default:      b_output_data = 23'b0;
        endcase
    end else begin
        b_output_data = 23'b0;
    end
end

// ====================================================================
// Global Backpressure Handling
// Assign ready signals from all input buffers to avoid multiple driver conflicts
// ====================================================================

// Connect input buffer ready signals based on arbitration results
assign a_x_buffered_rdy = (|x_grant_reg) && x_output_buffer_rdy[0];  // A-X goes to X arbitration
assign a_y_buffered_rdy = (|y_grant_reg) && y_output_buffer_rdy[0];  // A-Y goes to Y arbitration

// C-X input buffers ready signals - connect to Y arbitration results
generate
    for (i = 0; i < NUM_X_PORTS; i++) begin : gen_cx_rdy_assignment
        assign c_x_in_rdy[i] = (|y_grant_reg) && y_output_buffer_rdy[i];
    end
endgenerate

// C-Y input buffers ready signals - connect to X arbitration results
generate
    for (i = 0; i < NUM_Y_PORTS; i++) begin : gen_cy_rdy_assignment
        assign c_y_in_rdy[i] = (|x_grant_reg) && x_output_buffer_rdy[i];
    end
endgenerate

// ====================================================================
// Stage 3: Output Buffering
// Architecture: 15 output buffers with IRS_LP Deep=1, RO_EN=1
// ====================================================================

// Output buffer signals
wire [22:0] x_buffered_data [6:0];   // C-X output buffers
wire [6:0]  x_buffered_vld;
wire [6:0]  x_buffered_rdy;

wire [22:0] y_buffered_data [6:0];   // C-Y output buffers
wire [6:0]  y_buffered_vld;
wire [6:0]  y_buffered_rdy;

wire [22:0] b_buffered_data;         // B output buffer
wire        b_buffered_vld;
wire        b_buffered_rdy;

// X-Direction Output Buffers (7 C-X outputs)
generate
    for (i = 0; i < NUM_X_PORTS; i++) begin : gen_x_output_buffers
        IRS_N #(
            .PYLD_W(23),
            .IRS_DEEP(1),
            .TYPE_NO_READY(0),
            .TYPE_HALF(0),
            .TYPE_RO_EN(1)
        ) u_x_output_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .valid_i(x_grant_valid),                           // Use registered grant valid
            .ready_i(1'b1),                                     // Always ready - break combinatorial loop
            .valid_o(x_buffered_vld[i]),
            .ready_o(x_buffered_rdy[i]),
            .payload_i(x_output_data[i]),
            .payload_o(x_buffered_data[i])
        );
    end
endgenerate

// Y-Direction Output Buffers (7 C-Y outputs)
generate
    for (i = 0; i < NUM_Y_PORTS; i++) begin : gen_y_output_buffers
        IRS_N #(
            .PYLD_W(23),
            .IRS_DEEP(1),
            .TYPE_NO_READY(0),
            .TYPE_HALF(0),
            .TYPE_RO_EN(1)
        ) u_y_output_buffer (
            .clk(clk),
            .rst_n(rst_n),
            .valid_i(y_grant_valid),                            // Use registered grant valid
            .ready_i(1'b1),                                     // Always ready - break combinatorial loop
            .valid_o(y_buffered_vld[i]),
            .ready_o(y_buffered_rdy[i]),
            .payload_i(y_output_data[i]),
            .payload_o(y_buffered_data[i])
        );
    end
endgenerate

// B-Port Output Buffer (1 B output)
IRS_N #(
    .PYLD_W(23),
    .IRS_DEEP(1),
    .TYPE_NO_READY(0),
    .TYPE_HALF(0),
    .TYPE_RO_EN(1)
) u_b_output_buffer (
    .clk(clk),
    .rst_n(rst_n),
    .valid_i(b_grant_valid),                                   // Use grant valid only
    .ready_i(1'b1),                                           // Always ready - break combinatorial loop
    .valid_o(b_buffered_vld),
    .ready_o(b_buffered_rdy),
    .payload_i(b_output_data),
    .payload_o(b_buffered_data)
);

// Connect backpressure signals from output buffers to arbitration logic
assign x_output_buffer_rdy = x_buffered_rdy;      // X direction backpressure
assign y_output_buffer_rdy = y_buffered_rdy;      // Y direction backpressure
assign b_output_buffer_rdy = b_buffered_rdy;      // B port backpressure

// ====================================================================
// Interface Output Connections
// Connect buffered outputs to external interfaces with proper signal mapping
// ====================================================================

// C Interface output connections (to topology)
// X-direction outputs (7 ports) - Connect buffered data to interface signals
generate
    for (i = 0; i < NUM_X_PORTS; i++) begin : gen_c_x_outputs
        // Decode 23-bit packet format: [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
        assign pkt_con.x_vld[i] = x_buffered_vld[i];
        assign pkt_con.x_qos[i] = x_buffered_data[i][20];
        assign pkt_con.x_type[i] = x_buffered_data[i][22:21];
        assign pkt_con.x_src[i] = x_buffered_data[i][19:14];
        assign pkt_con.x_tgt[i] = x_buffered_data[i][13:8];
        assign pkt_con.x_data[i] = x_buffered_data[i][7:0];
        assign x_buffered_rdy[i] = pkt_con.x_rdy[i];
    end
endgenerate

// Y-direction outputs (7 ports)
generate
    for (i = 0; i < NUM_Y_PORTS; i++) begin : gen_c_y_outputs
        // Decode 23-bit packet format: [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
        assign pkt_con.y_vld[i] = y_buffered_vld[i];
        assign pkt_con.y_qos[i] = y_buffered_data[i][20];
        assign pkt_con.y_type[i] = y_buffered_data[i][22:21];
        assign pkt_con.y_src[i] = y_buffered_data[i][19:14];
        assign pkt_con.y_tgt[i] = y_buffered_data[i][13:8];
        assign pkt_con.y_data[i] = y_buffered_data[i][7:0];
        assign y_buffered_rdy[i] = pkt_con.y_rdy[i];
    end
endgenerate

// B-Port output connections (external output)
// Decode 23-bit packet format: [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
assign pkt_o.pkt_out_vld = b_buffered_vld;
assign pkt_o.pkt_out_qos = b_buffered_data[20];
assign pkt_o.pkt_out_type = b_buffered_data[22:21];
assign pkt_o.pkt_out_src = b_buffered_data[19:14];
assign pkt_o.pkt_out_tgt = b_buffered_data[13:8];
assign pkt_o.pkt_out_data = b_buffered_data[7:0];
assign b_buffered_rdy = pkt_o.pkt_out_rdy;

endmodule
