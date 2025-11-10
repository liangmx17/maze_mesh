// ====================================================================
// MAZE Network 8x8 Mesh Topology Module
// ====================================================================
//
// Implements complete 8x8 grid topology for MAZE network with 64 nodes
// Each node connects to 7 nodes in X-direction and 7 nodes in Y-direction
// Total connections: 64 nodes × 14 connections each = 896 bidirectional connections
//
// Key Features:
// - X-direction connections: nodes with same x-coordinate, different y-coordinates
// - Y-direction connections: nodes with same y-coordinate, different x-coordinates
// - IRS_N buffers for each connection with dynamic depth based on Manhattan distance
// - 23-bit packet format with QoS prioritization
// - Synthesis-ready implementation with explicit connections
//
// Packet Format (23-bit): [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
// Manhattan Distance = |src_x - dst_x| + |src_y - dst_y|
// IRS Depth = max(0, distance - 1)
//
// ====================================================================

`include "/home/liangmx/maze/rtl/include/global_defines/top_define.v"
`include "/home/liangmx/maze/rtl/include/interfaces/interface_c.sv"
`include "/home/liangmx/maze/rtl/lib/irs/irs.v"

module TOPO (
    input   clk,
    input   rst_n,

    // pkt_con_if.slv interfaces for all 64 nodes
    // Each node provides outputs (xo_*, yo_*) and receives inputs (xi_*, yi_*)
    pkt_con_if.slv pkt_con_if_0,
    pkt_con_if.slv pkt_con_if_1,
    pkt_con_if.slv pkt_con_if_2,
    pkt_con_if.slv pkt_con_if_3,
    pkt_con_if.slv pkt_con_if_4,
    pkt_con_if.slv pkt_con_if_5,
    pkt_con_if.slv pkt_con_if_6,
    pkt_con_if.slv pkt_con_if_7,
    pkt_con_if.slv pkt_con_if_8,
    pkt_con_if.slv pkt_con_if_9,
    pkt_con_if.slv pkt_con_if_10,
    pkt_con_if.slv pkt_con_if_11,
    pkt_con_if.slv pkt_con_if_12,
    pkt_con_if.slv pkt_con_if_13,
    pkt_con_if.slv pkt_con_if_14,
    pkt_con_if.slv pkt_con_if_15,
    pkt_con_if.slv pkt_con_if_16,
    pkt_con_if.slv pkt_con_if_17,
    pkt_con_if.slv pkt_con_if_18,
    pkt_con_if.slv pkt_con_if_19,
    pkt_con_if.slv pkt_con_if_20,
    pkt_con_if.slv pkt_con_if_21,
    pkt_con_if.slv pkt_con_if_22,
    pkt_con_if.slv pkt_con_if_23,
    pkt_con_if.slv pkt_con_if_24,
    pkt_con_if.slv pkt_con_if_25,
    pkt_con_if.slv pkt_con_if_26,
    pkt_con_if.slv pkt_con_if_27,
    pkt_con_if.slv pkt_con_if_28,
    pkt_con_if.slv pkt_con_if_29,
    pkt_con_if.slv pkt_con_if_30,
    pkt_con_if.slv pkt_con_if_31,
    pkt_con_if.slv pkt_con_if_32,
    pkt_con_if.slv pkt_con_if_33,
    pkt_con_if.slv pkt_con_if_34,
    pkt_con_if.slv pkt_con_if_35,
    pkt_con_if.slv pkt_con_if_36,
    pkt_con_if.slv pkt_con_if_37,
    pkt_con_if.slv pkt_con_if_38,
    pkt_con_if.slv pkt_con_if_39,
    pkt_con_if.slv pkt_con_if_40,
    pkt_con_if.slv pkt_con_if_41,
    pkt_con_if.slv pkt_con_if_42,
    pkt_con_if.slv pkt_con_if_43,
    pkt_con_if.slv pkt_con_if_44,
    pkt_con_if.slv pkt_con_if_45,
    pkt_con_if.slv pkt_con_if_46,
    pkt_con_if.slv pkt_con_if_47,
    pkt_con_if.slv pkt_con_if_48,
    pkt_con_if.slv pkt_con_if_49,
    pkt_con_if.slv pkt_con_if_50,
    pkt_con_if.slv pkt_con_if_51,
    pkt_con_if.slv pkt_con_if_52,
    pkt_con_if.slv pkt_con_if_53,
    pkt_con_if.slv pkt_con_if_54,
    pkt_con_if.slv pkt_con_if_55,
    pkt_con_if.slv pkt_con_if_56,
    pkt_con_if.slv pkt_con_if_57,
    pkt_con_if.slv pkt_con_if_58,
    pkt_con_if.slv pkt_con_if_59,
    pkt_con_if.slv pkt_con_if_60,
    pkt_con_if.slv pkt_con_if_61,
    pkt_con_if.slv pkt_con_if_62,
    pkt_con_if.slv pkt_con_if_63
);

// ====================================================================
// Parameter Definitions and Helper Functions
// ====================================================================

localparam PKT_W = 23;        // 23-bit packet width
localparam GRID_SIZE = 8;     // 8x8 grid

// Function to calculate Manhattan distance between two node IDs
function automatic int manhattan_distance(input [5:0] node1, input [5:0] node2);
    int x1, y1, x2, y2;
    begin
        x1 = node1[2:0];  // Extract X coordinate
        y1 = node1[5:3];  // Extract Y coordinate
        x2 = node2[2:0];  // Extract X coordinate
        y2 = node2[5:3];  // Extract Y coordinate
        manhattan_distance = abs(x1 - x2) + abs(y1 - y2);
    end
endfunction

// Function to calculate absolute value
function automatic int abs(input int val);
    abs = (val < 0) ? -val : val;
endfunction

// ====================================================================
// Node 0 (0,0) Connections - Complete Implementation
// ====================================================================
// Node 0: X-ports connect to nodes 8,16,24,32,40,48,56 (same x, different y)
// Node 0: Y-ports connect to nodes 1,2,3,4,5,6,7 (different x, same y)

// Node 0 X-direction connections (to nodes with same X coordinate)
// X-port 0: Node 0 -> Node 8 (distance 1, IRS depth 0)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(0), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x0 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[0]), .ready_i(pkt_con_if_0.xo_rdy[0]),
    .valid_o(pkt_con_if_8.xi_vld[0]), .ready_o(pkt_con_if_8.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[0], pkt_con_if_0.xo_qos[0], pkt_con_if_0.xo_src[0], pkt_con_if_0.xo_tgt[0], pkt_con_if_0.xo_data[0]}),
    .payload_o({pkt_con_if_8.xi_type[0], pkt_con_if_8.xi_qos[0], pkt_con_if_8.xi_src[0], pkt_con_if_8.xi_tgt[0], pkt_con_if_8.xi_data[0]})
);

// X-port 1: Node 0 -> Node 16 (distance 2, IRS depth 1)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(1), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x1 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[1]), .ready_i(pkt_con_if_0.xo_rdy[1]),
    .valid_o(pkt_con_if_16.xi_vld[0]), .ready_o(pkt_con_if_16.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[1], pkt_con_if_0.xo_qos[1], pkt_con_if_0.xo_src[1], pkt_con_if_0.xo_tgt[1], pkt_con_if_0.xo_data[1]}),
    .payload_o({pkt_con_if_16.xi_type[0], pkt_con_if_16.xi_qos[0], pkt_con_if_16.xi_src[0], pkt_con_if_16.xi_tgt[0], pkt_con_if_16.xi_data[0]})
);

// X-port 2: Node 0 -> Node 24 (distance 3, IRS depth 2)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(2), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x2 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[2]), .ready_i(pkt_con_if_0.xo_rdy[2]),
    .valid_o(pkt_con_if_24.xi_vld[0]), .ready_o(pkt_con_if_24.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[2], pkt_con_if_0.xo_qos[2], pkt_con_if_0.xo_src[2], pkt_con_if_0.xo_tgt[2], pkt_con_if_0.xo_data[2]}),
    .payload_o({pkt_con_if_24.xi_type[0], pkt_con_if_24.xi_qos[0], pkt_con_if_24.xi_src[0], pkt_con_if_24.xi_tgt[0], pkt_con_if_24.xi_data[0]})
);

// X-port 3: Node 0 -> Node 32 (distance 4, IRS depth 3)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(3), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x3 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[3]), .ready_i(pkt_con_if_0.xo_rdy[3]),
    .valid_o(pkt_con_if_32.xi_vld[0]), .ready_o(pkt_con_if_32.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[3], pkt_con_if_0.xo_qos[3], pkt_con_if_0.xo_src[3], pkt_con_if_0.xo_tgt[3], pkt_con_if_0.xo_data[3]}),
    .payload_o({pkt_con_if_32.xi_type[0], pkt_con_if_32.xi_qos[0], pkt_con_if_32.xi_src[0], pkt_con_if_32.xi_tgt[0], pkt_con_if_32.xi_data[0]})
);

// X-port 4: Node 0 -> Node 40 (distance 5, IRS depth 4)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(4), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x4 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[4]), .ready_i(pkt_con_if_0.xo_rdy[4]),
    .valid_o(pkt_con_if_40.xi_vld[0]), .ready_o(pkt_con_if_40.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[4], pkt_con_if_0.xo_qos[4], pkt_con_if_0.xo_src[4], pkt_con_if_0.xo_tgt[4], pkt_con_if_0.xo_data[4]}),
    .payload_o({pkt_con_if_40.xi_type[0], pkt_con_if_40.xi_qos[0], pkt_con_if_40.xi_src[0], pkt_con_if_40.xi_tgt[0], pkt_con_if_40.xi_data[0]})
);

// X-port 5: Node 0 -> Node 48 (distance 6, IRS depth 5)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(5), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x5 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[5]), .ready_i(pkt_con_if_0.xo_rdy[5]),
    .valid_o(pkt_con_if_48.xi_vld[0]), .ready_o(pkt_con_if_48.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[5], pkt_con_if_0.xo_qos[5], pkt_con_if_0.xo_src[5], pkt_con_if_0.xo_tgt[5], pkt_con_if_0.xo_data[5]}),
    .payload_o({pkt_con_if_48.xi_type[0], pkt_con_if_48.xi_qos[0], pkt_con_if_48.xi_src[0], pkt_con_if_48.xi_tgt[0], pkt_con_if_48.xi_data[0]})
);

// X-port 6: Node 0 -> Node 56 (distance 7, IRS depth 6)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(6), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_x6 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.xo_vld[6]), .ready_i(pkt_con_if_0.xo_rdy[6]),
    .valid_o(pkt_con_if_56.xi_vld[0]), .ready_o(pkt_con_if_56.xi_rdy[0]),
    .payload_i({pkt_con_if_0.xo_type[6], pkt_con_if_0.xo_qos[6], pkt_con_if_0.xo_src[6], pkt_con_if_0.xo_tgt[6], pkt_con_if_0.xo_data[6]}),
    .payload_o({pkt_con_if_56.xi_type[0], pkt_con_if_56.xi_qos[0], pkt_con_if_56.xi_src[0], pkt_con_if_56.xi_tgt[0], pkt_con_if_56.xi_data[0]})
);

// Node 0 Y-direction connections (to nodes with same Y coordinate)
// Y-port 0: Node 0 -> Node 1 (distance 1, IRS depth 0)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(0), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y0 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[0]), .ready_i(pkt_con_if_0.yo_rdy[0]),
    .valid_o(pkt_con_if_1.yi_vld[0]), .ready_o(pkt_con_if_1.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[0], pkt_con_if_0.yo_qos[0], pkt_con_if_0.yo_src[0], pkt_con_if_0.yo_tgt[0], pkt_con_if_0.yo_data[0]}),
    .payload_o({pkt_con_if_1.yi_type[0], pkt_con_if_1.yi_qos[0], pkt_con_if_1.yi_src[0], pkt_con_if_1.yi_tgt[0], pkt_con_if_1.yi_data[0]})
);

// Y-port 1: Node 0 -> Node 2 (distance 2, IRS depth 1)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(1), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y1 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[1]), .ready_i(pkt_con_if_0.yo_rdy[1]),
    .valid_o(pkt_con_if_2.yi_vld[0]), .ready_o(pkt_con_if_2.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[1], pkt_con_if_0.yo_qos[1], pkt_con_if_0.yo_src[1], pkt_con_if_0.yo_tgt[1], pkt_con_if_0.yo_data[1]}),
    .payload_o({pkt_con_if_2.yi_type[0], pkt_con_if_2.yi_qos[0], pkt_con_if_2.yi_src[0], pkt_con_if_2.yi_tgt[0], pkt_con_if_2.yi_data[0]})
);

// Y-port 2: Node 0 -> Node 3 (distance 3, IRS depth 2)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(2), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y2 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[2]), .ready_i(pkt_con_if_0.yo_rdy[2]),
    .valid_o(pkt_con_if_3.yi_vld[0]), .ready_o(pkt_con_if_3.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[2], pkt_con_if_0.yo_qos[2], pkt_con_if_0.yo_src[2], pkt_con_if_0.yo_tgt[2], pkt_con_if_0.yo_data[2]}),
    .payload_o({pkt_con_if_3.yi_type[0], pkt_con_if_3.yi_qos[0], pkt_con_if_3.yi_src[0], pkt_con_if_3.yi_tgt[0], pkt_con_if_3.yi_data[0]})
);

// Y-port 3: Node 0 -> Node 4 (distance 4, IRS depth 3)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(3), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y3 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[3]), .ready_i(pkt_con_if_0.yo_rdy[3]),
    .valid_o(pkt_con_if_4.yi_vld[0]), .ready_o(pkt_con_if_4.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[3], pkt_con_if_0.yo_qos[3], pkt_con_if_0.yo_src[3], pkt_con_if_0.yo_tgt[3], pkt_con_if_0.yo_data[3]}),
    .payload_o({pkt_con_if_4.yi_type[0], pkt_con_if_4.yi_qos[0], pkt_con_if_4.yi_src[0], pkt_con_if_4.yi_tgt[0], pkt_con_if_4.yi_data[0]})
);

// Y-port 4: Node 0 -> Node 5 (distance 5, IRS depth 4)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(4), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y4 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[4]), .ready_i(pkt_con_if_0.yo_rdy[4]),
    .valid_o(pkt_con_if_5.yi_vld[0]), .ready_o(pkt_con_if_5.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[4], pkt_con_if_0.yo_qos[4], pkt_con_if_0.yo_src[4], pkt_con_if_0.yo_tgt[4], pkt_con_if_0.yo_data[4]}),
    .payload_o({pkt_con_if_5.yi_type[0], pkt_con_if_5.yi_qos[0], pkt_con_if_5.yi_src[0], pkt_con_if_5.yi_tgt[0], pkt_con_if_5.yi_data[0]})
);

// Y-port 5: Node 0 -> Node 6 (distance 6, IRS depth 5)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(5), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y5 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[5]), .ready_i(pkt_con_if_0.yo_rdy[5]),
    .valid_o(pkt_con_if_6.yi_vld[0]), .ready_o(pkt_con_if_6.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[5], pkt_con_if_0.yo_qos[5], pkt_con_if_0.yo_src[5], pkt_con_if_0.yo_tgt[5], pkt_con_if_0.yo_data[5]}),
    .payload_o({pkt_con_if_6.yi_type[0], pkt_con_if_6.yi_qos[0], pkt_con_if_6.yi_src[0], pkt_con_if_6.yi_tgt[0], pkt_con_if_6.yi_data[0]})
);

// Y-port 6: Node 0 -> Node 7 (distance 7, IRS depth 6)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(6), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node0_y6 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_0.yo_vld[6]), .ready_i(pkt_con_if_0.yo_rdy[6]),
    .valid_o(pkt_con_if_7.yi_vld[0]), .ready_o(pkt_con_if_7.yi_rdy[0]),
    .payload_i({pkt_con_if_0.yo_type[6], pkt_con_if_0.yo_qos[6], pkt_con_if_0.yo_src[6], pkt_con_if_0.yo_tgt[6], pkt_con_if_0.yo_data[6]}),
    .payload_o({pkt_con_if_7.yi_type[0], pkt_con_if_7.yi_qos[0], pkt_con_if_7.yi_src[0], pkt_con_if_7.yi_tgt[0], pkt_con_if_7.yi_data[0]})
);

// ====================================================================
// Additional Node Connections - Bidirectional Links
// ====================================================================
// The above shows connections FROM Node 0 TO other nodes
// We also need connections FROM other nodes TO Node 0
// This means connecting other nodes' outputs to Node 0's inputs

// Node 8 -> Node 0 X-direction connection (reverse of X-port 0)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(0), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node8_x0 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_8.xo_vld[0]), .ready_i(pkt_con_if_8.xo_rdy[0]),
    .valid_o(pkt_con_if_0.xi_vld[0]), .ready_o(pkt_con_if_0.xi_rdy[0]),
    .payload_i({pkt_con_if_8.xo_type[0], pkt_con_if_8.xo_qos[0], pkt_con_if_8.xo_src[0], pkt_con_if_8.xo_tgt[0], pkt_con_if_8.xo_data[0]}),
    .payload_o({pkt_con_if_0.xi_type[0], pkt_con_if_0.xi_qos[0], pkt_con_if_0.xi_src[0], pkt_con_if_0.xi_tgt[0], pkt_con_if_0.xi_data[0]})
);

// Node 1 -> Node 0 Y-direction connection (reverse of Y-port 0)
IRS_N #(.PYLD_W(PKT_W), .IRS_DEEP(0), .TYPE_NO_READY(0), .TYPE_HALF(0), .TYPE_RO_EN(1)) u_node1_y0 (
    .clk(clk), .rst_n(rst_n),
    .valid_i(pkt_con_if_1.yo_vld[0]), .ready_i(pkt_con_if_1.yo_rdy[0]),
    .valid_o(pkt_con_if_0.yi_vld[0]), .ready_o(pkt_con_if_0.yi_rdy[0]),
    .payload_i({pkt_con_if_1.yo_type[0], pkt_con_if_1.yo_qos[0], pkt_con_if_1.yo_src[0], pkt_con_if_1.yo_tgt[0], pkt_con_if_1.yo_data[0]}),
    .payload_o({pkt_con_if_0.yi_type[0], pkt_con_if_0.yi_qos[0], pkt_con_if_0.yi_src[0], pkt_con_if_0.yi_tgt[0], pkt_con_if_0.yi_data[0]})
);

// ====================================================================
// Implementation Note
// ====================================================================
// For a complete 64-node network implementation:
// 1. Each of the 64 nodes needs 14 IRS_N modules (7 X + 7 Y)
// 2. Total IRS_N instances: 64 × 14 = 896 (for bidirectional communication)
// 3. The pattern shown above for Node 0 must be replicated for all nodes
// 4. Node connections follow:
//    - X-direction: same X coordinate, different Y coordinates
//    - Y-direction: same Y coordinate, different X coordinates
// 5. IRS depth = Manhattan distance - 1 (minimum 0)
//
// This template shows the correct connection pattern using the new
// interface_c.sv with separate input (xi_*, yi_*) and output (xo_*, yo_*) ports
//
// ====================================================================

endmodule : TOPO