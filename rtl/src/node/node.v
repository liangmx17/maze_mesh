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
// - Stage 3: Output Buffering with IRS_N buffers
// - 16 input buffers (1 A-interface + 7 X-input + 7 Y-input)
// - 15 output buffers (1 B-interface + 7 X-output + 7 Y-output)
// - Two-hop unicast routing with intermediate node calculation
// - QoS arbitration with high priority absolute priority
// - Fault tolerance with clock gating
//
// ====================================================================

// Include global definitions and interfaces
`include "../../rtl/include/global_defines/top_define.v"
`include "../../rtl/include/interfaces/interface_a.sv"
`include "../../rtl/include/interfaces/interface_b.sv"
`include "../../rtl/include/interfaces/interface_c.sv"
`include "../../../Provided_Code/irs.v"

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

// ====================================================================
// Clock Gating for Fault Tolerance
// ====================================================================

wire node_active = !(pg_en && (pg_node == NODE_COORD));
wire gated_clk = node_active ? clk : 1'b0;

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

// Internal signals for coordinate extraction
wire [5:0]  src_coord = NODE_COORD;
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
wire [22:0] a_buffered_pkt;
wire        a_buffered_vld;
wire        a_buffered_rdy;

irs_lp #(
    .DEEP(4),
    .WIDTH(23),
    .RO_EN(1)
) u_a_input_buffer (
    .clk(gated_clk),
    .rst_n(rst_n),
    .din({a_pkt_type, a_pkt_qos, a_pkt_src, a_pkt_tgt, a_pkt_data}),
    .din_vld(a_pkt_vld),
    .din_rdy(a_pkt_rdy),
    .dout(a_buffered_pkt),
    .dout_vld(a_buffered_vld),
    .dout_rdy(a_buffered_rdy)
);

// ====================================================================
// Input Buffer Management (16 input buffers)
// ====================================================================

// A-interface buffered signals split for X and Y directions
wire        a_x_vld, a_y_vld;
wire        a_x_qos, a_y_qos;
wire [1:0]  a_x_type, a_y_type;
wire [5:0]  a_x_src, a_y_src;
wire [5:0]  a_x_tgt, a_y_tgt;
wire [7:0]  a_x_data, a_y_data;

// Decode A-interface buffer output for X/Y routing (CONSISTENT 23-bit format)
// [22:21] = pkt_type (2 bits), [20] = pkt_qos (1 bit), [19:14] = pkt_src (6 bits)
// [13:8] = pkt_tgt (6 bits), [7:0] = pkt_data (8 bits)
assign a_x_vld = a_buffered_vld && select_x_buffer;
assign a_x_qos = a_buffered_pkt[20];        // pkt_qos
assign a_x_type = a_buffered_pkt[22:21];    // pkt_type
assign a_x_src = a_buffered_pkt[19:14];     // pkt_src
assign a_x_tgt = a_buffered_pkt[13:8];      // pkt_tgt
assign a_x_data = a_buffered_pkt[7:0];      // pkt_data

assign a_y_vld = a_buffered_vld && select_y_buffer;
assign a_y_qos = a_buffered_pkt[20];        // pkt_qos
assign a_y_type = a_buffered_pkt[22:21];    // pkt_type
assign a_y_src = a_buffered_pkt[19:14];     // pkt_src
assign a_y_tgt = a_buffered_pkt[13:8];      // pkt_tgt
assign a_y_data = a_buffered_pkt[7:0];      // pkt_data

// C-interface input buffers (14 input buffers: 7 X + 7 Y)
// X-direction input buffers
wire [6:0]  c_x_in_vld, c_x_in_rdy;
wire [6:0]  c_x_in_qos;
wire [1:0]  c_x_in_type [6:0];
wire [5:0]  c_x_in_src [6:0];
wire [5:0]  c_x_in_tgt [6:0];
wire [7:0]  c_x_in_data [6:0];
wire [22:0] c_x_buffered_data [6:0];
wire [6:0]  c_x_buffered_vld;
wire [6:0]  c_x_buffered_rdy;

// Y-direction input buffers
wire [6:0]  c_y_in_vld, c_y_in_rdy;
wire [6:0]  c_y_in_qos;
wire [1:0]  c_y_in_type [6:0];
wire [5:0]  c_y_in_src [6:0];
wire [5:0]  c_y_in_tgt [6:0];
wire [7:0]  c_y_in_data [6:0];
wire [22:0] c_y_buffered_data [6:0];
wire [6:0]  c_y_buffered_vld;
wire [6:0]  c_y_buffered_rdy;

// Connect C-interface inputs
genvar i;
generate
    for (i = 0; i < 7; i++) begin : gen_c_inputs
        // X-direction inputs (from other nodes)
        assign c_x_in_vld[i] = pkt_con.x_vld[i];
        assign c_x_in_qos[i] = pkt_con.x_qos[i];
        assign c_x_in_type[i] = pkt_con.x_type[i];
        assign c_x_in_src[i] = pkt_con.x_src[i];
        assign c_x_in_tgt[i] = pkt_con.x_tgt[i];
        assign c_x_in_data[i] = pkt_con.x_data[i];
        assign pkt_con.x_rdy[i] = c_x_in_rdy[i];

        // Y-direction inputs (from other nodes)
        assign c_y_in_vld[i] = pkt_con.y_vld[i];
        assign c_y_in_qos[i] = pkt_con.y_qos[i];
        assign c_y_in_type[i] = pkt_con.y_type[i];
        assign c_y_in_src[i] = pkt_con.y_src[i];
        assign c_y_in_tgt[i] = pkt_con.y_tgt[i];
        assign c_y_in_data[i] = pkt_con.y_data[i];
        assign pkt_con.y_rdy[i] = c_y_in_rdy[i];

        // X-direction input buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23),
            .RO_EN(1)
        ) u_c_x_input_buffer (
            .clk(gated_clk),
            .rst_n(rst_n),
            .din({c_x_in_type[i], c_x_in_qos[i], c_x_in_src[i], c_x_in_tgt[i], c_x_in_data[i]}),
            .din_vld(c_x_in_vld[i]),
            .din_rdy(c_x_in_rdy[i]),
            .dout(c_x_buffered_data[i]),
            .dout_vld(c_x_buffered_vld[i]),
            .dout_rdy(c_x_buffered_rdy[i])
        );

        // Y-direction input buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23),
            .RO_EN(1)
        ) u_c_y_input_buffer (
            .clk(gated_clk),
            .rst_n(rst_n),
            .din({c_y_in_type[i], c_y_in_qos[i], c_y_in_src[i], c_y_in_tgt[i], c_y_in_data[i]}),
            .din_vld(c_y_in_vld[i]),
            .din_rdy(c_y_in_rdy[i]),
            .dout(c_y_buffered_data[i]),
            .dout_vld(c_y_buffered_vld[i]),
            .dout_rdy(c_y_buffered_rdy[i])
        );
    end
endgenerate

// ====================================================================
// Stage 1: QoS Arbitration & XY Routing
// ====================================================================

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

// Generate requests for X-direction arbiters
generate
    for (i = 0; i < 7; i++) begin : gen_x_requests
        assign x_req_from_a_buf[i] = a_x_vld;
        assign x_req_from_y_inputs[i] = c_y_buffered_vld[i];
        assign x_req_total[i] = x_req_from_a_buf[i] | x_req_from_y_inputs[i];
    end
endgenerate

// Generate requests for Y-direction arbiters
generate
    for (i = 0; i < 7; i++) begin : gen_y_requests
        assign y_req_from_a_buf[i] = a_y_vld;
        assign y_req_from_x_inputs[i] = c_x_buffered_vld[i];
        assign y_req_total[i] = y_req_from_a_buf[i] | y_req_from_x_inputs[i];
    end
endgenerate

// Generate requests for B-port arbiter - ALL 16 INPUT SOURCES
assign b_req_total[0] = a_buffered_vld;           // A-interface input

// Y-direction inputs (7 inputs: indices 1-7)
assign b_req_total[1] = c_y_buffered_vld[0];     // Y-input 0
assign b_req_total[2] = c_y_buffered_vld[1];     // Y-input 1
assign b_req_total[3] = c_y_buffered_vld[2];     // Y-input 2
assign b_req_total[4] = c_y_buffered_vld[3];     // Y-input 3
assign b_req_total[5] = c_y_buffered_vld[4];     // Y-input 4
assign b_req_total[6] = c_y_buffered_vld[5];     // Y-input 5
assign b_req_total[7] = c_y_buffered_vld[6];     // Y-input 6

// X-direction inputs (7 inputs: indices 8-14)
assign b_req_total[8] = c_x_buffered_vld[0];     // X-input 0
assign b_req_total[9] = c_x_buffered_vld[1];     // X-input 1
assign b_req_total[10] = c_x_buffered_vld[2];    // X-input 2
assign b_req_total[11] = c_x_buffered_vld[3];    // X-input 3
assign b_req_total[12] = c_x_buffered_vld[4];    // X-input 4
assign b_req_total[13] = c_x_buffered_vld[5];    // X-input 5
assign b_req_total[14] = c_x_buffered_vld[6];    // X-input 6

assign b_req_total[15] = 1'b0;                   // Spare/unused

// X-Direction Arbitration Logic
generate
    for (i = 0; i < 7; i++) begin : gen_x_arbiters
        wire [7:0] arb_qos_inputs;
        wire [7:0] arb_vld_inputs;

        // Connect QoS inputs: 0=A-buffer, 1-7=Y-inputs
        assign arb_qos_inputs[0] = a_x_qos;
        assign arb_vld_inputs[0] = a_x_vld;

        // Connect Y-direction QoS inputs
        assign arb_qos_inputs[7:1] = c_y_in_qos;
        assign arb_vld_inputs[7:1] = c_y_buffered_vld;

        // 8-input arbiter: 0=A-buffer, 1-7=Y-inputs
        // QoS Priority Logic - Synthesizable Priority Encoder
        reg [2:0] winner;
        reg found_winner;

        always_comb begin
            winner = 3'b000;
            found_winner = 1'b0;

            // High QoS priority logic (highest priority first)
            case (1'b1)
                arb_vld_inputs[7] & arb_qos_inputs[7]: begin
                    winner = 3'b111; found_winner = 1'b1;
                end
                arb_vld_inputs[6] & arb_qos_inputs[6]: begin
                    winner = 3'b110; found_winner = 1'b1;
                end
                arb_vld_inputs[5] & arb_qos_inputs[5]: begin
                    winner = 3'b101; found_winner = 1'b1;
                end
                arb_vld_inputs[4] & arb_qos_inputs[4]: begin
                    winner = 3'b100; found_winner = 1'b1;
                end
                arb_vld_inputs[3] & arb_qos_inputs[3]: begin
                    winner = 3'b011; found_winner = 1'b1;
                end
                arb_vld_inputs[2] & arb_qos_inputs[2]: begin
                    winner = 3'b010; found_winner = 1'b1;
                end
                arb_vld_inputs[1] & arb_qos_inputs[1]: begin
                    winner = 3'b001; found_winner = 1'b1;
                end
                arb_vld_inputs[0] & arb_qos_inputs[0]: begin
                    winner = 3'b000; found_winner = 1'b1;
                end
                default: begin
                    // Low QoS search if no high QoS found
                    case (1'b1)
                        arb_vld_inputs[7]: winner = 3'b111;
                        arb_vld_inputs[6]: winner = 3'b110;
                        arb_vld_inputs[5]: winner = 3'b101;
                        arb_vld_inputs[4]: winner = 3'b100;
                        arb_vld_inputs[3]: winner = 3'b011;
                        arb_vld_inputs[2]: winner = 3'b010;
                        arb_vld_inputs[1]: winner = 3'b001;
                        arb_vld_inputs[0]: winner = 3'b000;
                        default: winner = 3'b000;
                    endcase
                end
            endcase
        end

        assign x_winner_addr[i] = winner;
        assign x_winner_vld[i] = arb_vld_inputs[winner] && x_req_total[i];
    end
endgenerate

// Y-Direction Arbitration Logic
generate
    for (i = 0; i < 7; i++) begin : gen_y_arbiters
        wire [7:0] arb_qos_inputs;
        wire [7:0] arb_vld_inputs;

        // Connect QoS inputs: 0=A-buffer, 1-7=X-inputs
        assign arb_qos_inputs[0] = a_y_qos;
        assign arb_vld_inputs[0] = a_y_vld;

        // Connect X-direction QoS inputs
        assign arb_qos_inputs[7:1] = c_x_in_qos;
        assign arb_vld_inputs[7:1] = c_x_buffered_vld;

        // 8-input arbiter: 0=A-buffer, 1-7=X-inputs
        // QoS Priority Logic - Synthesizable Priority Encoder
        reg [2:0] winner;
        reg found_winner;

        always_comb begin
            winner = 3'b000;
            found_winner = 1'b0;

            // High QoS priority logic (highest priority first)
            case (1'b1)
                arb_vld_inputs[7] & arb_qos_inputs[7]: begin
                    winner = 3'b111; found_winner = 1'b1;
                end
                arb_vld_inputs[6] & arb_qos_inputs[6]: begin
                    winner = 3'b110; found_winner = 1'b1;
                end
                arb_vld_inputs[5] & arb_qos_inputs[5]: begin
                    winner = 3'b101; found_winner = 1'b1;
                end
                arb_vld_inputs[4] & arb_qos_inputs[4]: begin
                    winner = 3'b100; found_winner = 1'b1;
                end
                arb_vld_inputs[3] & arb_qos_inputs[3]: begin
                    winner = 3'b011; found_winner = 1'b1;
                end
                arb_vld_inputs[2] & arb_qos_inputs[2]: begin
                    winner = 3'b010; found_winner = 1'b1;
                end
                arb_vld_inputs[1] & arb_qos_inputs[1]: begin
                    winner = 3'b001; found_winner = 1'b1;
                end
                arb_vld_inputs[0] & arb_qos_inputs[0]: begin
                    winner = 3'b000; found_winner = 1'b1;
                end
                default: begin
                    // Low QoS search if no high QoS found
                    case (1'b1)
                        arb_vld_inputs[7]: winner = 3'b111;
                        arb_vld_inputs[6]: winner = 3'b110;
                        arb_vld_inputs[5]: winner = 3'b101;
                        arb_vld_inputs[4]: winner = 3'b100;
                        arb_vld_inputs[3]: winner = 3'b011;
                        arb_vld_inputs[2]: winner = 3'b010;
                        arb_vld_inputs[1]: winner = 3'b001;
                        arb_vld_inputs[0]: winner = 3'b000;
                        default: winner = 3'b000;
                    endcase
                end
            endcase
        end

        assign y_winner_addr[i] = winner;
        assign y_winner_vld[i] = arb_vld_inputs[winner] && y_req_total[i];
    end
endgenerate

// B-Port Arbitration (16-input arbiter)
wire [15:0] b_qos_inputs;

// Connect QoS inputs for B-port arbiter - ALL 16 INPUT SOURCES
assign b_qos_inputs[0] = a_buffered_pkt[20];     // A-interface QoS

// Y-direction QoS inputs (7 inputs: indices 1-7)
assign b_qos_inputs[1] = c_y_buffered_data[0][20]; // Y-input 0 QoS
assign b_qos_inputs[2] = c_y_buffered_data[1][20]; // Y-input 1 QoS
assign b_qos_inputs[3] = c_y_buffered_data[2][20]; // Y-input 2 QoS
assign b_qos_inputs[4] = c_y_buffered_data[3][20]; // Y-input 3 QoS
assign b_qos_inputs[5] = c_y_buffered_data[4][20]; // Y-input 4 QoS
assign b_qos_inputs[6] = c_y_buffered_data[5][20]; // Y-input 5 QoS
assign b_qos_inputs[7] = c_y_buffered_data[6][20]; // Y-input 6 QoS

// X-direction QoS inputs (7 inputs: indices 8-14)
assign b_qos_inputs[8] = c_x_buffered_data[0][20]; // X-input 0 QoS
assign b_qos_inputs[9] = c_x_buffered_data[1][20]; // X-input 1 QoS
assign b_qos_inputs[10] = c_x_buffered_data[2][20]; // X-input 2 QoS
assign b_qos_inputs[11] = c_x_buffered_data[3][20]; // X-input 3 QoS
assign b_qos_inputs[12] = c_x_buffered_data[4][20]; // X-input 4 QoS
assign b_qos_inputs[13] = c_x_buffered_data[5][20]; // X-input 5 QoS
assign b_qos_inputs[14] = c_x_buffered_data[6][20]; // X-input 6 QoS

assign b_qos_inputs[15] = 1'b0;                    // Spare/unused

// B-port arbiter winner selection logic - Synthesizable Priority Encoder
reg [3:0] b_winner;
reg b_found_winner;

always_comb begin
    b_winner = 4'b0000;
    b_found_winner = 1'b0;

    // High QoS priority logic (highest priority first)
    case (1'b1)
        b_req_total[15] & b_qos_inputs[15]: begin
            b_winner = 4'b1111; b_found_winner = 1'b1;
        end
        b_req_total[14] & b_qos_inputs[14]: begin
            b_winner = 4'b1110; b_found_winner = 1'b1;
        end
        b_req_total[13] & b_qos_inputs[13]: begin
            b_winner = 4'b1101; b_found_winner = 1'b1;
        end
        b_req_total[12] & b_qos_inputs[12]: begin
            b_winner = 4'b1100; b_found_winner = 1'b1;
        end
        b_req_total[11] & b_qos_inputs[11]: begin
            b_winner = 4'b1011; b_found_winner = 1'b1;
        end
        b_req_total[10] & b_qos_inputs[10]: begin
            b_winner = 4'b1010; b_found_winner = 1'b1;
        end
        b_req_total[9] & b_qos_inputs[9]: begin
            b_winner = 4'b1001; b_found_winner = 1'b1;
        end
        b_req_total[8] & b_qos_inputs[8]: begin
            b_winner = 4'b1000; b_found_winner = 1'b1;
        end
        b_req_total[7] & b_qos_inputs[7]: begin
            b_winner = 4'b0111; b_found_winner = 1'b1;
        end
        b_req_total[6] & b_qos_inputs[6]: begin
            b_winner = 4'b0110; b_found_winner = 1'b1;
        end
        b_req_total[5] & b_qos_inputs[5]: begin
            b_winner = 4'b0101; b_found_winner = 1'b1;
        end
        b_req_total[4] & b_qos_inputs[4]: begin
            b_winner = 4'b0100; b_found_winner = 1'b1;
        end
        b_req_total[3] & b_qos_inputs[3]: begin
            b_winner = 4'b0011; b_found_winner = 1'b1;
        end
        b_req_total[2] & b_qos_inputs[2]: begin
            b_winner = 4'b0010; b_found_winner = 1'b1;
        end
        b_req_total[1] & b_qos_inputs[1]: begin
            b_winner = 4'b0001; b_found_winner = 1'b1;
        end
        b_req_total[0] & b_qos_inputs[0]: begin
            b_winner = 4'b0000; b_found_winner = 1'b1;
        end
        default: begin
            // Low QoS search if no high QoS found
            case (1'b1)
                b_req_total[15]: b_winner = 4'b1111;
                b_req_total[14]: b_winner = 4'b1110;
                b_req_total[13]: b_winner = 4'b1101;
                b_req_total[12]: b_winner = 4'b1100;
                b_req_total[11]: b_winner = 4'b1011;
                b_req_total[10]: b_winner = 4'b1010;
                b_req_total[9]: b_winner = 4'b1001;
                b_req_total[8]: b_winner = 4'b1000;
                b_req_total[7]: b_winner = 4'b0111;
                b_req_total[6]: b_winner = 4'b0110;
                b_req_total[5]: b_winner = 4'b0101;
                b_req_total[4]: b_winner = 4'b0100;
                b_req_total[3]: b_winner = 4'b0011;
                b_req_total[2]: b_winner = 4'b0010;
                b_req_total[1]: b_winner = 4'b0001;
                b_req_total[0]: b_winner = 4'b0000;
                default: b_winner = 4'b0000;
            endcase
        end
    endcase
end

assign b_winner_addr = b_winner;
assign b_winner_vld = b_req_total[b_winner] && b_found_winner;

// ====================================================================
// Stage 2: Output Selection
// ====================================================================

// Input data from all 16 input buffers
wire [22:0] input_buffer_data [15:0];  // 16 input buffers, 23-bit data
wire [15:0] input_buffer_vld;          // Valid signals from input buffers
wire [15:0] input_buffer_rdy;          // Ready signals to input buffers

// Connect input buffer data
assign input_buffer_data[0] = a_buffered_pkt;       // A-interface buffer
assign input_buffer_vld[0] = a_buffered_vld;
assign input_buffer_rdy[0] = a_buffered_rdy;

assign input_buffer_data[7:1] = c_y_buffered_data;  // Y-direction buffers
assign input_buffer_vld[7:1] = c_y_buffered_vld;
assign input_buffer_rdy[7:1] = c_y_buffered_rdy;

assign input_buffer_data[14:8] = c_x_buffered_data; // X-direction buffers
assign input_buffer_vld[14:8] = c_x_buffered_vld;
assign input_buffer_rdy[14:8] = c_x_buffered_rdy;

assign input_buffer_data[15] = 23'b0;               // Spare
assign input_buffer_vld[15] = 1'b0;
assign input_buffer_rdy[15] = 1'b0;

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
                    3'b011: x_winner_select[i] = 7'b0001000;  // Y-input 2
                    3'b100: x_winner_select[i] = 7'b0010000;  // Y-input 3
                    3'b101: x_winner_select[i] = 7'b0100000;  // Y-input 4
                    3'b110: x_winner_select[i] = 7'b1000000;  // Y-input 5
                    3'b111: x_winner_select[i] = 7'b0000000;  // Y-input 6 (not used)
                    default: x_winner_select[i] = 7'b0000000;
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
                3'b011: x_output_data[i] = input_buffer_data[3];   // Y-input 2
                3'b100: x_output_data[i] = input_buffer_data[4];   // Y-input 3
                3'b101: x_output_data[i] = input_buffer_data[5];   // Y-input 4
                3'b110: x_output_data[i] = input_buffer_data[6];   // Y-input 5
                3'b111: x_output_data[i] = input_buffer_data[7];   // Y-input 6
                default: x_output_data[i] = 23'b0;
            endcase
        end
    end
endgenerate

// Y-Direction Output Selection
generate
    for (i = 0; i < 7; i++) begin : gen_y_output_sel
        // Decode winner address to select input source
        always_comb begin
            y_winner_select[i] = 7'b0;
            if (y_winner_vld[i]) begin
                case (y_winner_addr[i])
                    3'b000: y_winner_select[i] = 7'b0000001;  // A-buffer
                    3'b001: y_winner_select[i] = 7'b0000010;  // X-input 0
                    3'b010: y_winner_select[i] = 7'b0000100;  // X-input 1
                    3'b011: y_winner_select[i] = 7'b0001000;  // X-input 2
                    3'b100: y_winner_select[i] = 7'b0010000;  // X-input 3
                    3'b101: y_winner_select[i] = 7'b0100000;  // X-input 4
                    3'b110: y_winner_select[i] = 7'b1000000;  // X-input 5
                    3'b111: y_winner_select[i] = 7'b0000000;  // X-input 6 (not used)
                    default: y_winner_select[i] = 7'b0000000;
                endcase
            end
        end

        // Data selection MUX
        always_comb begin
            y_output_data[i] = 23'b0;
            case (y_winner_addr[i])
                3'b000: y_output_data[i] = input_buffer_data[8];   // A-buffer Y
                3'b001: y_output_data[i] = input_buffer_data[9];   // X-input 0
                3'b010: y_output_data[i] = input_buffer_data[10];  // X-input 1
                3'b011: y_output_data[i] = input_buffer_data[11];  // X-input 2
                3'b100: y_output_data[i] = input_buffer_data[12];  // X-input 3
                3'b101: y_output_data[i] = input_buffer_data[13];  // X-input 4
                3'b110: y_output_data[i] = input_buffer_data[14];  // X-input 5
                3'b111: y_output_data[i] = input_buffer_data[15];  // X-input 6
                default: y_output_data[i] = 23'b0;
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
        4'h2: b_output_data = input_buffer_data[2];   // C-interface Y1
        4'h3: b_output_data = input_buffer_data[3];   // C-interface Y2
        4'h4: b_output_data = input_buffer_data[4];   // C-interface Y3
        4'h5: b_output_data = input_buffer_data[5];   // C-interface Y4
        4'h6: b_output_data = input_buffer_data[6];   // C-interface Y5
        4'h7: b_output_data = input_buffer_data[7];   // C-interface Y6
        4'h8: b_output_data = input_buffer_data[8];   // C-interface X0
        4'h9: b_output_data = input_buffer_data[9];   // C-interface X1
        4'hA: b_output_data = input_buffer_data[10];  // C-interface X2
        4'hB: b_output_data = input_buffer_data[11];  // C-interface X3
        4'hC: b_output_data = input_buffer_data[12];  // C-interface X4
        4'hD: b_output_data = input_buffer_data[13];  // C-interface X5
        4'hE: b_output_data = input_buffer_data[14];  // C-interface X6
        4'hF: b_output_data = input_buffer_data[15];  // Spare
        default: b_output_data = 23'b0;
    endcase
end

// ====================================================================
// Stage 3: Output Buffering
// ====================================================================

// Registered output signals
wire [22:0] x_buffered_data [6:0];
wire [6:0]  x_buffered_vld;
wire [6:0]  x_buffered_rdy;
wire [1:0]  x_buffered_type [6:0];
wire        x_buffered_qos [6:0];
wire [5:0]  x_buffered_src [6:0];
wire [5:0]  x_buffered_tgt [6:0];
wire [7:0]  x_buffered_payload [6:0];

wire [22:0] y_buffered_data [6:0];
wire [6:0]  y_buffered_vld;
wire [6:0]  y_buffered_rdy;
wire [1:0]  y_buffered_type [6:0];
wire        y_buffered_qos [6:0];
wire [5:0]  y_buffered_src [6:0];
wire [5:0]  y_buffered_tgt [6:0];
wire [7:0]  y_buffered_payload [6:0];

wire [22:0] b_buffered_data;
wire        b_buffered_vld;
wire        b_buffered_rdy;
wire [1:0]  b_buffered_type;
wire        b_buffered_qos;
wire [5:0]  b_buffered_src;
wire [5:0]  b_buffered_tgt;
wire [7:0]  b_buffered_payload;

// Assume all output buffers are ready (simplified)
assign x_output_buffer_rdy = {7{1'b1}};
assign y_output_buffer_rdy = {7{1'b1}};
assign b_output_buffer_rdy = 1'b1;

// X-Direction Output Buffers
generate
    for (i = 0; i < 7; i++) begin : gen_x_output_buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23),
            .RO_EN(1)
        ) u_x_output_buffer (
            .clk(gated_clk),
            .rst_n(rst_n),
            .din(x_output_data[i]),
            .din_vld(x_winner_vld[i] && x_output_buffer_rdy[i]),
            .din_rdy(),
            .dout(x_buffered_data[i]),
            .dout_vld(x_buffered_vld[i]),
            .dout_rdy(x_buffered_rdy[i])
        );

        // Decode buffered data (CONSISTENT 23-bit format)
        assign x_buffered_type[i] = x_buffered_data[i][22:21];    // pkt_type
        assign x_buffered_qos[i] = x_buffered_data[i][20];        // pkt_qos
        assign x_buffered_src[i] = x_buffered_data[i][19:14];     // pkt_src
        assign x_buffered_tgt[i] = x_buffered_data[i][13:8];      // pkt_tgt
        assign x_buffered_payload[i] = x_buffered_data[i][7:0];   // pkt_data
    end
endgenerate

// Y-Direction Output Buffers
generate
    for (i = 0; i < 7; i++) begin : gen_y_output_buffers
        irs_lp #(
            .DEEP(4),
            .WIDTH(23),
            .RO_EN(1)
        ) u_y_output_buffer (
            .clk(gated_clk),
            .rst_n(rst_n),
            .din(y_output_data[i]),
            .din_vld(y_winner_vld[i] && y_output_buffer_rdy[i]),
            .din_rdy(),
            .dout(y_buffered_data[i]),
            .dout_vld(y_buffered_vld[i]),
            .dout_rdy(y_buffered_rdy[i])
        );

        // Decode buffered data (CONSISTENT 23-bit format)
        assign y_buffered_type[i] = y_buffered_data[i][22:21];    // pkt_type
        assign y_buffered_qos[i] = y_buffered_data[i][20];        // pkt_qos
        assign y_buffered_src[i] = y_buffered_data[i][19:14];     // pkt_src
        assign y_buffered_tgt[i] = y_buffered_data[i][13:8];      // pkt_tgt
        assign y_buffered_payload[i] = y_buffered_data[i][7:0];   // pkt_data
    end
endgenerate

// B-Port Output Buffer
irs_lp #(
    .DEEP(4),
    .WIDTH(23),
    .RO_EN(1)
) u_b_output_buffer (
    .clk(gated_clk),
    .rst_n(rst_n),
    .din(b_output_data),
    .din_vld(b_winner_vld && b_output_buffer_rdy),
    .din_rdy(),
    .dout(b_buffered_data),
    .dout_vld(b_buffered_vld),
    .dout_rdy(b_buffered_rdy)
);

// Decode B-port buffered data (CONSISTENT 23-bit format)
assign b_buffered_type = b_buffered_data[22:21];    // pkt_type
assign b_buffered_qos = b_buffered_data[20];        // pkt_qos
assign b_buffered_src = b_buffered_data[19:14];     // pkt_src
assign b_buffered_tgt = b_buffered_data[13:8];      // pkt_tgt
assign b_buffered_payload = b_buffered_data[7:0];   // pkt_data

// ====================================================================
// Interface Output Connections
// ====================================================================

// C Interface output connections (to topology)
// X-direction outputs (7 ports)
generate
    for (i = 0; i < 7; i++) begin : gen_c_x_outputs
        assign pkt_con.x_vld[i] = x_buffered_vld[i];
        assign pkt_con.x_qos[i] = x_buffered_qos[i];
        assign pkt_con.x_type[i] = x_buffered_type[i];
        assign pkt_con.x_src[i] = x_buffered_src[i];
        assign pkt_con.x_tgt[i] = x_buffered_tgt[i];
        assign pkt_con.x_data[i] = x_buffered_payload[i];
        assign x_buffered_rdy[i] = pkt_con.x_rdy[i];
    end
endgenerate

// Y-direction outputs (7 ports)
generate
    for (i = 0; i < 7; i++) begin : gen_c_y_outputs
        assign pkt_con.y_vld[i] = y_buffered_vld[i];
        assign pkt_con.y_qos[i] = y_buffered_qos[i];
        assign pkt_con.y_type[i] = y_buffered_type[i];
        assign pkt_con.y_src[i] = y_buffered_src[i];
        assign pkt_con.y_tgt[i] = y_buffered_tgt[i];
        assign pkt_con.y_data[i] = y_buffered_payload[i];
        assign y_buffered_rdy[i] = pkt_con.y_rdy[i];
    end
endgenerate

// B-Port output connections
assign pkt_o.pkt_out_vld = b_buffered_vld;
assign pkt_o.pkt_out_qos = b_buffered_qos;
assign pkt_o.pkt_out_type = b_buffered_type;
assign pkt_o.pkt_out_src = b_buffered_src;
assign pkt_o.pkt_out_tgt = b_buffered_tgt;
assign pkt_o.pkt_out_data = b_buffered_payload;
assign b_buffered_rdy = pkt_o.pkt_out_rdy;

endmodule