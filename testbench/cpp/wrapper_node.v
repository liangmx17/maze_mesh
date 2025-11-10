// ====================================================================
// MAZE Network Node - Test Wrapper
// ====================================================================
//
// Wrapper module for testing node.v with Verilator
// Converts interface ports to simple signals for Verilator compatibility
//
// ====================================================================

`include "/home/liangmx/maze/rtl/include/global_defines/top_define.v"
`include "/home/liangmx/maze/rtl/include/interfaces/interface_a.sv"
`include "/home/liangmx/maze/rtl/include/interfaces/interface_b.sv"
`include "/home/liangmx/maze/rtl/include/interfaces/interface_c.sv"
`include "/home/liangmx/maze/rtl/lib/irs/irs.v"
`include "/home/liangmx/maze/Provided_Code/arbiter_with_qos.v"

module wrapper_node #(
    parameter HP = 3'b000,    // Horizontal Position (0-7)
    parameter VP = 3'b000     // Vertical Position (0-7)
) (
    input               clk,
    input               rst_n,

    // A Interface - External Input (converted from interface to simple signals)
    input               a_pkt_in_vld,
    input               a_pkt_in_qos,
    input        [1:0]  a_pkt_in_type,
    input        [5:0]  a_pkt_in_src,
    input        [5:0]  a_pkt_in_tgt,
    input        [7:0]  a_pkt_in_data,
    output              a_pkt_in_rdy,

    // B Interface - External Output
    output              b_pkt_out_vld,
    output              b_pkt_out_qos,
    output       [1:0]  b_pkt_out_type,
    output       [5:0]  b_pkt_out_src,
    output       [5:0]  b_pkt_out_tgt,
    output       [7:0]  b_pkt_out_data,
    input               b_pkt_out_rdy,

    // C Interface - Topology Connections (simplified for testing)
    output [6:0]        c_x_vld,
    output [6:0]        c_x_qos,
    output [1:0]  c_x_type [6:0],
    output [5:0]  c_x_src [6:0],
    output [5:0]  c_x_tgt [6:0],
    output [7:0]  c_x_data [6:0],
    input  [6:0]        c_x_rdy,

    output [6:0]        c_y_vld,
    output [6:0]        c_y_qos,
    output [1:0]  c_y_type [6:0],
    output [5:0]  c_y_src [6:0],
    output [5:0]  c_y_tgt [6:0],
    output [7:0]  c_y_data [6:0],
    input  [6:0]        c_y_rdy,

    // Power Gating Control
    input               pg_en,
    input [5:0]         pg_node
);

// ====================================================================
// Interface Instantiations
// ====================================================================

// A Interface
pkt_in pkt_i_inst (
    .clk(clk),
    .rst_n(rst_n),
    .pkt_in_vld(a_pkt_in_vld),
    .pkt_in_rdy(a_pkt_in_rdy),
    .pkt_in_qos(a_pkt_in_qos),
    .pkt_in_type(a_pkt_in_type),
    .pkt_in_src(a_pkt_in_src),
    .pkt_in_tgt(a_pkt_in_tgt),
    .pkt_in_data(a_pkt_in_data)
);

// B Interface
pkt_out pkt_o_inst (
    .clk(clk),
    .rst_n(rst_n),
    .pkt_out_vld(b_pkt_out_vld),
    .pkt_out_rdy(b_pkt_out_rdy),
    .pkt_out_qos(b_pkt_out_qos),
    .pkt_out_type(b_pkt_out_type),
    .pkt_out_src(b_pkt_out_src),
    .pkt_out_tgt(b_pkt_out_tgt),
    .pkt_out_data(b_pkt_out_data)
);

// C Interface
pkt_con_if pkt_con_inst (
    .clk(clk),
    .rst_n(rst_n),
    .x_vld(c_x_vld),
    .x_rdy(c_x_rdy),
    .x_qos(c_x_qos),
    .x_type(c_x_type),
    .x_src(c_x_src),
    .x_tgt(c_x_tgt),
    .x_data(c_x_data),
    .y_vld(c_y_vld),
    .y_rdy(c_y_rdy),
    .y_qos(c_y_qos),
    .y_type(c_y_type),
    .y_src(c_y_src),
    .y_tgt(c_y_tgt),
    .y_data(c_y_data)
);

// ====================================================================
// Node Module Instantiation
// ====================================================================

node #(
    .HP(HP),
    .VP(VP)
) u_node (
    .clk(clk),
    .rst_n(rst_n),
    .pkt_i(pkt_i_inst),
    .pkt_o(pkt_o_inst),
    .pkt_con(pkt_con_inst.mst),
    .pg_en(pg_en),
    .pg_node(pg_node)
);

endmodule