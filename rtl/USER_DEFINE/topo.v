// ====================================================================
// MAZE Network 8×8 Mesh Topology Module
// ====================================================================
//
// Implements complete 8×8 mesh topology for MAZE network with 64 nodes
// Each node connects to 4 neighbors: North, West, South, East
// Total connections: 64 nodes × 4 connections each = 256 bidirectional connections
//
// Key Features:
// - Mesh topology with boundary termination
// - Direct node-to-node connections (no intermediate routing logic)
// - Direct Node[outputs] → Topology → Node[inputs] signal flow
// - Uses pkt_con_if interface for all node connections
// - Single clock domain, no clock gating in topology
// - Total: 256 direct connections
//
// Packet Format (23-bit): [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
// Mesh Manhattan Distance: Uses minimal path without wraparound
//
// ====================================================================
`timescale 1ns/1ps

module TOPO (
    input   clk,
    input   rst_n,

    // 64 node interfaces - each interface connects to one node
    // Interface contains 4 inputs (ni/wi/si/ei) and 4 outputs (no/wo/so/eo)
    // Each node uses mst modport, topology provides connections between nodes
    pkt_con_if pkt_con_if_0,
    pkt_con_if pkt_con_if_1,
    pkt_con_if pkt_con_if_2,
    pkt_con_if pkt_con_if_3,
    pkt_con_if pkt_con_if_4,
    pkt_con_if pkt_con_if_5,
    pkt_con_if pkt_con_if_6,
    pkt_con_if pkt_con_if_7,
    pkt_con_if pkt_con_if_8,
    pkt_con_if pkt_con_if_9,
    pkt_con_if pkt_con_if_10,
    pkt_con_if pkt_con_if_11,
    pkt_con_if pkt_con_if_12,
    pkt_con_if pkt_con_if_13,
    pkt_con_if pkt_con_if_14,
    pkt_con_if pkt_con_if_15,
    pkt_con_if pkt_con_if_16,
    pkt_con_if pkt_con_if_17,
    pkt_con_if pkt_con_if_18,
    pkt_con_if pkt_con_if_19,
    pkt_con_if pkt_con_if_20,
    pkt_con_if pkt_con_if_21,
    pkt_con_if pkt_con_if_22,
    pkt_con_if pkt_con_if_23,
    pkt_con_if pkt_con_if_24,
    pkt_con_if pkt_con_if_25,
    pkt_con_if pkt_con_if_26,
    pkt_con_if pkt_con_if_27,
    pkt_con_if pkt_con_if_28,
    pkt_con_if pkt_con_if_29,
    pkt_con_if pkt_con_if_30,
    pkt_con_if pkt_con_if_31,
    pkt_con_if pkt_con_if_32,
    pkt_con_if pkt_con_if_33,
    pkt_con_if pkt_con_if_34,
    pkt_con_if pkt_con_if_35,
    pkt_con_if pkt_con_if_36,
    pkt_con_if pkt_con_if_37,
    pkt_con_if pkt_con_if_38,
    pkt_con_if pkt_con_if_39,
    pkt_con_if pkt_con_if_40,
    pkt_con_if pkt_con_if_41,
    pkt_con_if pkt_con_if_42,
    pkt_con_if pkt_con_if_43,
    pkt_con_if pkt_con_if_44,
    pkt_con_if pkt_con_if_45,
    pkt_con_if pkt_con_if_46,
    pkt_con_if pkt_con_if_47,
    pkt_con_if pkt_con_if_48,
    pkt_con_if pkt_con_if_49,
    pkt_con_if pkt_con_if_50,
    pkt_con_if pkt_con_if_51,
    pkt_con_if pkt_con_if_52,
    pkt_con_if pkt_con_if_53,
    pkt_con_if pkt_con_if_54,
    pkt_con_if pkt_con_if_55,
    pkt_con_if pkt_con_if_56,
    pkt_con_if pkt_con_if_57,
    pkt_con_if pkt_con_if_58,
    pkt_con_if pkt_con_if_59,
    pkt_con_if pkt_con_if_60,
    pkt_con_if pkt_con_if_61,
    pkt_con_if pkt_con_if_62,
    pkt_con_if pkt_con_if_63
);

// ====================================================================
// Parameter Definitions and Helper Functions
// ====================================================================

localparam PKT_W = 23;        // 23-bit packet width: 2+1+6+6+8
localparam GRID_SIZE = 8;     // 8×8 mesh grid
localparam NUM_NODES = 64;    // Total number of nodes

// Function to convert 1D node ID to 2D coordinates
function automatic int get_x_coord(input int node_id);
    get_x_coord = node_id % GRID_SIZE;
endfunction

function automatic int get_y_coord(input int node_id);
    get_y_coord = node_id / GRID_SIZE;
endfunction

// Function to convert 2D coordinates to 1D node ID
function automatic int coord_to_node_id(input int x, input int y);
    coord_to_node_id = y * GRID_SIZE + x;
endfunction

// ====================================================================
// Mesh Topology Implementation
// ====================================================================
//
// Connection Pattern for 8×8 Mesh:
// - North: Node[y,x].yo_[0] → Node[y-1,x].yi_[0] (if y > 0)
// - South: Node[y,x].yo_[1] → Node[y+1,x].yi_[1] (if y < 7)
// - West:  Node[y,x].xo_[0] → Node[y,x-1].xi_[0] (if x > 0)
// - East:  Node[y,x].xo_[1] → Node[y,x+1].xi_[1] (if x < 7)
// - Boundary nodes tie-off unused connections to 0
// - Total: 256 direct connections (4 × 64 nodes)
//
// ====================================================================

// ====================================================================
// Direct Mesh Connections
// ====================================================================
// Connect all 64 nodes in 8x8 grid topology
// Each node connects to its North, South, West, East neighbors

// Set all ready signals high (direct connections always ready)
assign pkt_con_if_0.no_rdy = 1'b1;
assign pkt_con_if_0.wo_rdy = 1'b1;
assign pkt_con_if_0.so_rdy = 1'b1;
assign pkt_con_if_0.eo_rdy = 1'b1;

assign pkt_con_if_1.no_rdy = 1'b1;
assign pkt_con_if_1.wo_rdy = 1'b1;
assign pkt_con_if_1.so_rdy = 1'b1;
assign pkt_con_if_1.eo_rdy = 1'b1;

assign pkt_con_if_2.no_rdy = 1'b1;
assign pkt_con_if_2.wo_rdy = 1'b1;
assign pkt_con_if_2.so_rdy = 1'b1;
assign pkt_con_if_2.eo_rdy = 1'b1;

assign pkt_con_if_3.no_rdy = 1'b1;
assign pkt_con_if_3.wo_rdy = 1'b1;
assign pkt_con_if_3.so_rdy = 1'b1;
assign pkt_con_if_3.eo_rdy = 1'b1;

assign pkt_con_if_4.no_rdy = 1'b1;
assign pkt_con_if_4.wo_rdy = 1'b1;
assign pkt_con_if_4.so_rdy = 1'b1;
assign pkt_con_if_4.eo_rdy = 1'b1;

assign pkt_con_if_5.no_rdy = 1'b1;
assign pkt_con_if_5.wo_rdy = 1'b1;
assign pkt_con_if_5.so_rdy = 1'b1;
assign pkt_con_if_5.eo_rdy = 1'b1;

assign pkt_con_if_6.no_rdy = 1'b1;
assign pkt_con_if_6.wo_rdy = 1'b1;
assign pkt_con_if_6.so_rdy = 1'b1;
assign pkt_con_if_6.eo_rdy = 1'b1;

assign pkt_con_if_7.no_rdy = 1'b1;
assign pkt_con_if_7.wo_rdy = 1'b1;
assign pkt_con_if_7.so_rdy = 1'b1;
assign pkt_con_if_7.eo_rdy = 1'b1;

assign pkt_con_if_8.no_rdy = 1'b1;
assign pkt_con_if_8.wo_rdy = 1'b1;
assign pkt_con_if_8.so_rdy = 1'b1;
assign pkt_con_if_8.eo_rdy = 1'b1;

assign pkt_con_if_9.no_rdy = 1'b1;
assign pkt_con_if_9.wo_rdy = 1'b1;
assign pkt_con_if_9.so_rdy = 1'b1;
assign pkt_con_if_9.eo_rdy = 1'b1;

assign pkt_con_if_10.no_rdy = 1'b1;
assign pkt_con_if_10.wo_rdy = 1'b1;
assign pkt_con_if_10.so_rdy = 1'b1;
assign pkt_con_if_10.eo_rdy = 1'b1;

assign pkt_con_if_11.no_rdy = 1'b1;
assign pkt_con_if_11.wo_rdy = 1'b1;
assign pkt_con_if_11.so_rdy = 1'b1;
assign pkt_con_if_11.eo_rdy = 1'b1;

assign pkt_con_if_12.no_rdy = 1'b1;
assign pkt_con_if_12.wo_rdy = 1'b1;
assign pkt_con_if_12.so_rdy = 1'b1;
assign pkt_con_if_12.eo_rdy = 1'b1;

assign pkt_con_if_13.no_rdy = 1'b1;
assign pkt_con_if_13.wo_rdy = 1'b1;
assign pkt_con_if_13.so_rdy = 1'b1;
assign pkt_con_if_13.eo_rdy = 1'b1;

assign pkt_con_if_14.no_rdy = 1'b1;
assign pkt_con_if_14.wo_rdy = 1'b1;
assign pkt_con_if_14.so_rdy = 1'b1;
assign pkt_con_if_14.eo_rdy = 1'b1;

assign pkt_con_if_15.no_rdy = 1'b1;
assign pkt_con_if_15.wo_rdy = 1'b1;
assign pkt_con_if_15.so_rdy = 1'b1;
assign pkt_con_if_15.eo_rdy = 1'b1;

assign pkt_con_if_16.no_rdy = 1'b1;
assign pkt_con_if_16.wo_rdy = 1'b1;
assign pkt_con_if_16.so_rdy = 1'b1;
assign pkt_con_if_16.eo_rdy = 1'b1;

assign pkt_con_if_17.no_rdy = 1'b1;
assign pkt_con_if_17.wo_rdy = 1'b1;
assign pkt_con_if_17.so_rdy = 1'b1;
assign pkt_con_if_17.eo_rdy = 1'b1;

assign pkt_con_if_18.no_rdy = 1'b1;
assign pkt_con_if_18.wo_rdy = 1'b1;
assign pkt_con_if_18.so_rdy = 1'b1;
assign pkt_con_if_18.eo_rdy = 1'b1;

assign pkt_con_if_19.no_rdy = 1'b1;
assign pkt_con_if_19.wo_rdy = 1'b1;
assign pkt_con_if_19.so_rdy = 1'b1;
assign pkt_con_if_19.eo_rdy = 1'b1;

assign pkt_con_if_20.no_rdy = 1'b1;
assign pkt_con_if_20.wo_rdy = 1'b1;
assign pkt_con_if_20.so_rdy = 1'b1;
assign pkt_con_if_20.eo_rdy = 1'b1;

assign pkt_con_if_21.no_rdy = 1'b1;
assign pkt_con_if_21.wo_rdy = 1'b1;
assign pkt_con_if_21.so_rdy = 1'b1;
assign pkt_con_if_21.eo_rdy = 1'b1;

assign pkt_con_if_22.no_rdy = 1'b1;
assign pkt_con_if_22.wo_rdy = 1'b1;
assign pkt_con_if_22.so_rdy = 1'b1;
assign pkt_con_if_22.eo_rdy = 1'b1;

assign pkt_con_if_23.no_rdy = 1'b1;
assign pkt_con_if_23.wo_rdy = 1'b1;
assign pkt_con_if_23.so_rdy = 1'b1;
assign pkt_con_if_23.eo_rdy = 1'b1;

assign pkt_con_if_24.no_rdy = 1'b1;
assign pkt_con_if_24.wo_rdy = 1'b1;
assign pkt_con_if_24.so_rdy = 1'b1;
assign pkt_con_if_24.eo_rdy = 1'b1;

assign pkt_con_if_25.no_rdy = 1'b1;
assign pkt_con_if_25.wo_rdy = 1'b1;
assign pkt_con_if_25.so_rdy = 1'b1;
assign pkt_con_if_25.eo_rdy = 1'b1;

assign pkt_con_if_26.no_rdy = 1'b1;
assign pkt_con_if_26.wo_rdy = 1'b1;
assign pkt_con_if_26.so_rdy = 1'b1;
assign pkt_con_if_26.eo_rdy = 1'b1;

assign pkt_con_if_27.no_rdy = 1'b1;
assign pkt_con_if_27.wo_rdy = 1'b1;
assign pkt_con_if_27.so_rdy = 1'b1;
assign pkt_con_if_27.eo_rdy = 1'b1;

assign pkt_con_if_28.no_rdy = 1'b1;
assign pkt_con_if_28.wo_rdy = 1'b1;
assign pkt_con_if_28.so_rdy = 1'b1;
assign pkt_con_if_28.eo_rdy = 1'b1;

assign pkt_con_if_29.no_rdy = 1'b1;
assign pkt_con_if_29.wo_rdy = 1'b1;
assign pkt_con_if_29.so_rdy = 1'b1;
assign pkt_con_if_29.eo_rdy = 1'b1;

assign pkt_con_if_30.no_rdy = 1'b1;
assign pkt_con_if_30.wo_rdy = 1'b1;
assign pkt_con_if_30.so_rdy = 1'b1;
assign pkt_con_if_30.eo_rdy = 1'b1;

assign pkt_con_if_31.no_rdy = 1'b1;
assign pkt_con_if_31.wo_rdy = 1'b1;
assign pkt_con_if_31.so_rdy = 1'b1;
assign pkt_con_if_31.eo_rdy = 1'b1;

assign pkt_con_if_32.no_rdy = 1'b1;
assign pkt_con_if_32.wo_rdy = 1'b1;
assign pkt_con_if_32.so_rdy = 1'b1;
assign pkt_con_if_32.eo_rdy = 1'b1;

assign pkt_con_if_33.no_rdy = 1'b1;
assign pkt_con_if_33.wo_rdy = 1'b1;
assign pkt_con_if_33.so_rdy = 1'b1;
assign pkt_con_if_33.eo_rdy = 1'b1;

assign pkt_con_if_34.no_rdy = 1'b1;
assign pkt_con_if_34.wo_rdy = 1'b1;
assign pkt_con_if_34.so_rdy = 1'b1;
assign pkt_con_if_34.eo_rdy = 1'b1;

assign pkt_con_if_35.no_rdy = 1'b1;
assign pkt_con_if_35.wo_rdy = 1'b1;
assign pkt_con_if_35.so_rdy = 1'b1;
assign pkt_con_if_35.eo_rdy = 1'b1;

assign pkt_con_if_36.no_rdy = 1'b1;
assign pkt_con_if_36.wo_rdy = 1'b1;
assign pkt_con_if_36.so_rdy = 1'b1;
assign pkt_con_if_36.eo_rdy = 1'b1;

assign pkt_con_if_37.no_rdy = 1'b1;
assign pkt_con_if_37.wo_rdy = 1'b1;
assign pkt_con_if_37.so_rdy = 1'b1;
assign pkt_con_if_37.eo_rdy = 1'b1;

assign pkt_con_if_38.no_rdy = 1'b1;
assign pkt_con_if_38.wo_rdy = 1'b1;
assign pkt_con_if_38.so_rdy = 1'b1;
assign pkt_con_if_38.eo_rdy = 1'b1;

assign pkt_con_if_39.no_rdy = 1'b1;
assign pkt_con_if_39.wo_rdy = 1'b1;
assign pkt_con_if_39.so_rdy = 1'b1;
assign pkt_con_if_39.eo_rdy = 1'b1;

assign pkt_con_if_40.no_rdy = 1'b1;
assign pkt_con_if_40.wo_rdy = 1'b1;
assign pkt_con_if_40.so_rdy = 1'b1;
assign pkt_con_if_40.eo_rdy = 1'b1;

assign pkt_con_if_41.no_rdy = 1'b1;
assign pkt_con_if_41.wo_rdy = 1'b1;
assign pkt_con_if_41.so_rdy = 1'b1;
assign pkt_con_if_41.eo_rdy = 1'b1;

assign pkt_con_if_42.no_rdy = 1'b1;
assign pkt_con_if_42.wo_rdy = 1'b1;
assign pkt_con_if_42.so_rdy = 1'b1;
assign pkt_con_if_42.eo_rdy = 1'b1;

assign pkt_con_if_43.no_rdy = 1'b1;
assign pkt_con_if_43.wo_rdy = 1'b1;
assign pkt_con_if_43.so_rdy = 1'b1;
assign pkt_con_if_43.eo_rdy = 1'b1;

assign pkt_con_if_44.no_rdy = 1'b1;
assign pkt_con_if_44.wo_rdy = 1'b1;
assign pkt_con_if_44.so_rdy = 1'b1;
assign pkt_con_if_44.eo_rdy = 1'b1;

assign pkt_con_if_45.no_rdy = 1'b1;
assign pkt_con_if_45.wo_rdy = 1'b1;
assign pkt_con_if_45.so_rdy = 1'b1;
assign pkt_con_if_45.eo_rdy = 1'b1;

assign pkt_con_if_46.no_rdy = 1'b1;
assign pkt_con_if_46.wo_rdy = 1'b1;
assign pkt_con_if_46.so_rdy = 1'b1;
assign pkt_con_if_46.eo_rdy = 1'b1;

assign pkt_con_if_47.no_rdy = 1'b1;
assign pkt_con_if_47.wo_rdy = 1'b1;
assign pkt_con_if_47.so_rdy = 1'b1;
assign pkt_con_if_47.eo_rdy = 1'b1;

assign pkt_con_if_48.no_rdy = 1'b1;
assign pkt_con_if_48.wo_rdy = 1'b1;
assign pkt_con_if_48.so_rdy = 1'b1;
assign pkt_con_if_48.eo_rdy = 1'b1;

assign pkt_con_if_49.no_rdy = 1'b1;
assign pkt_con_if_49.wo_rdy = 1'b1;
assign pkt_con_if_49.so_rdy = 1'b1;
assign pkt_con_if_49.eo_rdy = 1'b1;

assign pkt_con_if_50.no_rdy = 1'b1;
assign pkt_con_if_50.wo_rdy = 1'b1;
assign pkt_con_if_50.so_rdy = 1'b1;
assign pkt_con_if_50.eo_rdy = 1'b1;

assign pkt_con_if_51.no_rdy = 1'b1;
assign pkt_con_if_51.wo_rdy = 1'b1;
assign pkt_con_if_51.so_rdy = 1'b1;
assign pkt_con_if_51.eo_rdy = 1'b1;

assign pkt_con_if_52.no_rdy = 1'b1;
assign pkt_con_if_52.wo_rdy = 1'b1;
assign pkt_con_if_52.so_rdy = 1'b1;
assign pkt_con_if_52.eo_rdy = 1'b1;

assign pkt_con_if_53.no_rdy = 1'b1;
assign pkt_con_if_53.wo_rdy = 1'b1;
assign pkt_con_if_53.so_rdy = 1'b1;
assign pkt_con_if_53.eo_rdy = 1'b1;

assign pkt_con_if_54.no_rdy = 1'b1;
assign pkt_con_if_54.wo_rdy = 1'b1;
assign pkt_con_if_54.so_rdy = 1'b1;
assign pkt_con_if_54.eo_rdy = 1'b1;

assign pkt_con_if_55.no_rdy = 1'b1;
assign pkt_con_if_55.wo_rdy = 1'b1;
assign pkt_con_if_55.so_rdy = 1'b1;
assign pkt_con_if_55.eo_rdy = 1'b1;

assign pkt_con_if_56.no_rdy = 1'b1;
assign pkt_con_if_56.wo_rdy = 1'b1;
assign pkt_con_if_56.so_rdy = 1'b1;
assign pkt_con_if_56.eo_rdy = 1'b1;

assign pkt_con_if_57.no_rdy = 1'b1;
assign pkt_con_if_57.wo_rdy = 1'b1;
assign pkt_con_if_57.so_rdy = 1'b1;
assign pkt_con_if_57.eo_rdy = 1'b1;

assign pkt_con_if_58.no_rdy = 1'b1;
assign pkt_con_if_58.wo_rdy = 1'b1;
assign pkt_con_if_58.so_rdy = 1'b1;
assign pkt_con_if_58.eo_rdy = 1'b1;

assign pkt_con_if_59.no_rdy = 1'b1;
assign pkt_con_if_59.wo_rdy = 1'b1;
assign pkt_con_if_59.so_rdy = 1'b1;
assign pkt_con_if_59.eo_rdy = 1'b1;

assign pkt_con_if_60.no_rdy = 1'b1;
assign pkt_con_if_60.wo_rdy = 1'b1;
assign pkt_con_if_60.so_rdy = 1'b1;
assign pkt_con_if_60.eo_rdy = 1'b1;

assign pkt_con_if_61.no_rdy = 1'b1;
assign pkt_con_if_61.wo_rdy = 1'b1;
assign pkt_con_if_61.so_rdy = 1'b1;
assign pkt_con_if_61.eo_rdy = 1'b1;

assign pkt_con_if_62.no_rdy = 1'b1;
assign pkt_con_if_62.wo_rdy = 1'b1;
assign pkt_con_if_62.so_rdy = 1'b1;
assign pkt_con_if_62.eo_rdy = 1'b1;

assign pkt_con_if_63.no_rdy = 1'b1;
assign pkt_con_if_63.wo_rdy = 1'b1;
assign pkt_con_if_63.so_rdy = 1'b1;
assign pkt_con_if_63.eo_rdy = 1'b1;

// Node 0 (0,0) - Top-left corner: only South and East connections
assign pkt_con_if_0.ni_vld = 1'b0;
assign pkt_con_if_0.ni_qos = 1'b0;
assign pkt_con_if_0.ni_type = 2'b00;
assign pkt_con_if_0.ni_src = 6'b000000;
assign pkt_con_if_0.ni_tgt = 6'b000000;
assign pkt_con_if_0.ni_data = 8'b00000000;

assign pkt_con_if_0.wi_vld = 1'b0;
assign pkt_con_if_0.wi_qos = 1'b0;
assign pkt_con_if_0.wi_type = 2'b00;
assign pkt_con_if_0.wi_src = 6'b000000;
assign pkt_con_if_0.wi_tgt = 6'b000000;
assign pkt_con_if_0.wi_data = 8'b00000000;

// South connection from Node 8 (0,1)
assign pkt_con_if_0.si_vld = pkt_con_if_8.so_vld;
assign pkt_con_if_0.si_qos = pkt_con_if_8.so_qos;
assign pkt_con_if_0.si_type = pkt_con_if_8.so_type;
assign pkt_con_if_0.si_src = pkt_con_if_8.so_src;
assign pkt_con_if_0.si_tgt = pkt_con_if_8.so_tgt;
assign pkt_con_if_0.si_data = pkt_con_if_8.so_data;
assign pkt_con_if_8.so_rdy = pkt_con_if_0.si_rdy;

// East connection from Node 1 (1,0)
assign pkt_con_if_0.ei_vld = pkt_con_if_1.eo_vld;
assign pkt_con_if_0.ei_qos = pkt_con_if_1.eo_qos;
assign pkt_con_if_0.ei_type = pkt_con_if_1.eo_type;
assign pkt_con_if_0.ei_src = pkt_con_if_1.eo_src;
assign pkt_con_if_0.ei_tgt = pkt_con_if_1.eo_tgt;
assign pkt_con_if_0.ei_data = pkt_con_if_1.eo_data;
assign pkt_con_if_1.eo_rdy = pkt_con_if_0.ei_rdy;

// Node 1 (1,0) - Top edge: no North connection
assign pkt_con_if_1.ni_vld = 1'b0;
assign pkt_con_if_1.ni_qos = 1'b0;
assign pkt_con_if_1.ni_type = 2'b00;
assign pkt_con_if_1.ni_src = 6'b000000;
assign pkt_con_if_1.ni_tgt = 6'b000000;
assign pkt_con_if_1.ni_data = 8'b00000000;

// West connection from Node 0 (0,0)
assign pkt_con_if_1.wi_vld = pkt_con_if_0.wo_vld;
assign pkt_con_if_1.wi_qos = pkt_con_if_0.wo_qos;
assign pkt_con_if_1.wi_type = pkt_con_if_0.wo_type;
assign pkt_con_if_1.wi_src = pkt_con_if_0.wo_src;
assign pkt_con_if_1.wi_tgt = pkt_con_if_0.wo_tgt;
assign pkt_con_if_1.wi_data = pkt_con_if_0.wo_data;
assign pkt_con_if_0.wo_rdy = pkt_con_if_1.wi_rdy;

// East connection from Node 2 (2,0)
assign pkt_con_if_1.ei_vld = pkt_con_if_2.eo_vld;
assign pkt_con_if_1.ei_qos = pkt_con_if_2.eo_qos;
assign pkt_con_if_1.ei_type = pkt_con_if_2.eo_type;
assign pkt_con_if_1.ei_src = pkt_con_if_2.eo_src;
assign pkt_con_if_1.ei_tgt = pkt_con_if_2.eo_tgt;
assign pkt_con_if_1.ei_data = pkt_con_if_2.eo_data;
assign pkt_con_if_2.eo_rdy = pkt_con_if_1.ei_rdy;

// South connection from Node 9 (1,1)
assign pkt_con_if_1.si_vld = pkt_con_if_9.so_vld;
assign pkt_con_if_1.si_qos = pkt_con_if_9.so_qos;
assign pkt_con_if_1.si_type = pkt_con_if_9.so_type;
assign pkt_con_if_1.si_src = pkt_con_if_9.so_src;
assign pkt_con_if_1.si_tgt = pkt_con_if_9.so_tgt;
assign pkt_con_if_1.si_data = pkt_con_if_9.so_data;
assign pkt_con_if_9.so_rdy = pkt_con_if_1.si_rdy;

// Node 2 (2,0) - Top edge: no North connection
assign pkt_con_if_2.ni_vld = 1'b0;
assign pkt_con_if_2.ni_qos = 1'b0;
assign pkt_con_if_2.ni_type = 2'b00;
assign pkt_con_if_2.ni_src = 6'b000000;
assign pkt_con_if_2.ni_tgt = 6'b000000;
assign pkt_con_if_2.ni_data = 8'b00000000;

// West connection from Node 1 (1,0)
assign pkt_con_if_2.wi_vld = pkt_con_if_1.wo_vld;
assign pkt_con_if_2.wi_qos = pkt_con_if_1.wo_qos;
assign pkt_con_if_2.wi_type = pkt_con_if_1.wo_type;
assign pkt_con_if_2.wi_src = pkt_con_if_1.wo_src;
assign pkt_con_if_2.wi_tgt = pkt_con_if_1.wo_tgt;
assign pkt_con_if_2.wi_data = pkt_con_if_1.wo_data;
assign pkt_con_if_1.wo_rdy = pkt_con_if_2.wi_rdy;

// East connection from Node 3 (3,0)
assign pkt_con_if_2.ei_vld = pkt_con_if_3.eo_vld;
assign pkt_con_if_2.ei_qos = pkt_con_if_3.eo_qos;
assign pkt_con_if_2.ei_type = pkt_con_if_3.eo_type;
assign pkt_con_if_2.ei_src = pkt_con_if_3.eo_src;
assign pkt_con_if_2.ei_tgt = pkt_con_if_3.eo_tgt;
assign pkt_con_if_2.ei_data = pkt_con_if_3.eo_data;
assign pkt_con_if_3.eo_rdy = pkt_con_if_2.ei_rdy;

// South connection from Node 10 (2,1)
assign pkt_con_if_2.si_vld = pkt_con_if_10.so_vld;
assign pkt_con_if_2.si_qos = pkt_con_if_10.so_qos;
assign pkt_con_if_2.si_type = pkt_con_if_10.so_type;
assign pkt_con_if_2.si_src = pkt_con_if_10.so_src;
assign pkt_con_if_2.si_tgt = pkt_con_if_10.so_tgt;
assign pkt_con_if_2.si_data = pkt_con_if_10.so_data;
assign pkt_con_if_10.so_rdy = pkt_con_if_2.si_rdy;

// Node 3 (3,0) - Top edge: no North connection
assign pkt_con_if_3.ni_vld = 1'b0;
assign pkt_con_if_3.ni_qos = 1'b0;
assign pkt_con_if_3.ni_type = 2'b00;
assign pkt_con_if_3.ni_src = 6'b000000;
assign pkt_con_if_3.ni_tgt = 6'b000000;
assign pkt_con_if_3.ni_data = 8'b00000000;

// West connection from Node 2 (2,0)
assign pkt_con_if_3.wi_vld = pkt_con_if_2.wo_vld;
assign pkt_con_if_3.wi_qos = pkt_con_if_2.wo_qos;
assign pkt_con_if_3.wi_type = pkt_con_if_2.wo_type;
assign pkt_con_if_3.wi_src = pkt_con_if_2.wo_src;
assign pkt_con_if_3.wi_tgt = pkt_con_if_2.wo_tgt;
assign pkt_con_if_3.wi_data = pkt_con_if_2.wo_data;
assign pkt_con_if_2.wo_rdy = pkt_con_if_3.wi_rdy;

// East connection from Node 4 (4,0)
assign pkt_con_if_3.ei_vld = pkt_con_if_4.eo_vld;
assign pkt_con_if_3.ei_qos = pkt_con_if_4.eo_qos;
assign pkt_con_if_3.ei_type = pkt_con_if_4.eo_type;
assign pkt_con_if_3.ei_src = pkt_con_if_4.eo_src;
assign pkt_con_if_3.ei_tgt = pkt_con_if_4.eo_tgt;
assign pkt_con_if_3.ei_data = pkt_con_if_4.eo_data;
assign pkt_con_if_4.eo_rdy = pkt_con_if_3.ei_rdy;

// South connection from Node 11 (3,1)
assign pkt_con_if_3.si_vld = pkt_con_if_11.so_vld;
assign pkt_con_if_3.si_qos = pkt_con_if_11.so_qos;
assign pkt_con_if_3.si_type = pkt_con_if_11.so_type;
assign pkt_con_if_3.si_src = pkt_con_if_11.so_src;
assign pkt_con_if_3.si_tgt = pkt_con_if_11.so_tgt;
assign pkt_con_if_3.si_data = pkt_con_if_11.so_data;
assign pkt_con_if_11.so_rdy = pkt_con_if_3.si_rdy;

// Node 4 (4,0) - Top edge: no North connection
assign pkt_con_if_4.ni_vld = 1'b0;
assign pkt_con_if_4.ni_qos = 1'b0;
assign pkt_con_if_4.ni_type = 2'b00;
assign pkt_con_if_4.ni_src = 6'b000000;
assign pkt_con_if_4.ni_tgt = 6'b000000;
assign pkt_con_if_4.ni_data = 8'b00000000;

// West connection from Node 3 (3,0)
assign pkt_con_if_4.wi_vld = pkt_con_if_3.wo_vld;
assign pkt_con_if_4.wi_qos = pkt_con_if_3.wo_qos;
assign pkt_con_if_4.wi_type = pkt_con_if_3.wo_type;
assign pkt_con_if_4.wi_src = pkt_con_if_3.wo_src;
assign pkt_con_if_4.wi_tgt = pkt_con_if_3.wo_tgt;
assign pkt_con_if_4.wi_data = pkt_con_if_3.wo_data;
assign pkt_con_if_3.wo_rdy = pkt_con_if_4.wi_rdy;

// East connection from Node 5 (5,0)
assign pkt_con_if_4.ei_vld = pkt_con_if_5.eo_vld;
assign pkt_con_if_4.ei_qos = pkt_con_if_5.eo_qos;
assign pkt_con_if_4.ei_type = pkt_con_if_5.eo_type;
assign pkt_con_if_4.ei_src = pkt_con_if_5.eo_src;
assign pkt_con_if_4.ei_tgt = pkt_con_if_5.eo_tgt;
assign pkt_con_if_4.ei_data = pkt_con_if_5.eo_data;
assign pkt_con_if_5.eo_rdy = pkt_con_if_4.ei_rdy;

// South connection from Node 12 (4,1)
assign pkt_con_if_4.si_vld = pkt_con_if_12.so_vld;
assign pkt_con_if_4.si_qos = pkt_con_if_12.so_qos;
assign pkt_con_if_4.si_type = pkt_con_if_12.so_type;
assign pkt_con_if_4.si_src = pkt_con_if_12.so_src;
assign pkt_con_if_4.si_tgt = pkt_con_if_12.so_tgt;
assign pkt_con_if_4.si_data = pkt_con_if_12.so_data;
assign pkt_con_if_12.so_rdy = pkt_con_if_4.si_rdy;

// Node 5 (5,0) - Top edge: no North connection
assign pkt_con_if_5.ni_vld = 1'b0;
assign pkt_con_if_5.ni_qos = 1'b0;
assign pkt_con_if_5.ni_type = 2'b00;
assign pkt_con_if_5.ni_src = 6'b000000;
assign pkt_con_if_5.ni_tgt = 6'b000000;
assign pkt_con_if_5.ni_data = 8'b00000000;

// West connection from Node 4 (4,0)
assign pkt_con_if_5.wi_vld = pkt_con_if_4.wo_vld;
assign pkt_con_if_5.wi_qos = pkt_con_if_4.wo_qos;
assign pkt_con_if_5.wi_type = pkt_con_if_4.wo_type;
assign pkt_con_if_5.wi_src = pkt_con_if_4.wo_src;
assign pkt_con_if_5.wi_tgt = pkt_con_if_4.wo_tgt;
assign pkt_con_if_5.wi_data = pkt_con_if_4.wo_data;
assign pkt_con_if_4.wo_rdy = pkt_con_if_5.wi_rdy;

// East connection from Node 6 (6,0)
assign pkt_con_if_5.ei_vld = pkt_con_if_6.eo_vld;
assign pkt_con_if_5.ei_qos = pkt_con_if_6.eo_qos;
assign pkt_con_if_5.ei_type = pkt_con_if_6.eo_type;
assign pkt_con_if_5.ei_src = pkt_con_if_6.eo_src;
assign pkt_con_if_5.ei_tgt = pkt_con_if_6.eo_tgt;
assign pkt_con_if_5.ei_data = pkt_con_if_6.eo_data;
assign pkt_con_if_6.eo_rdy = pkt_con_if_5.ei_rdy;

// South connection from Node 13 (5,1)
assign pkt_con_if_5.si_vld = pkt_con_if_13.so_vld;
assign pkt_con_if_5.si_qos = pkt_con_if_13.so_qos;
assign pkt_con_if_5.si_type = pkt_con_if_13.so_type;
assign pkt_con_if_5.si_src = pkt_con_if_13.so_src;
assign pkt_con_if_5.si_tgt = pkt_con_if_13.so_tgt;
assign pkt_con_if_5.si_data = pkt_con_if_13.so_data;
assign pkt_con_if_13.so_rdy = pkt_con_if_5.si_rdy;

// Node 6 (6,0) - Top edge: no North connection
assign pkt_con_if_6.ni_vld = 1'b0;
assign pkt_con_if_6.ni_qos = 1'b0;
assign pkt_con_if_6.ni_type = 2'b00;
assign pkt_con_if_6.ni_src = 6'b000000;
assign pkt_con_if_6.ni_tgt = 6'b000000;
assign pkt_con_if_6.ni_data = 8'b00000000;

// West connection from Node 5 (5,0)
assign pkt_con_if_6.wi_vld = pkt_con_if_5.wo_vld;
assign pkt_con_if_6.wi_qos = pkt_con_if_5.wo_qos;
assign pkt_con_if_6.wi_type = pkt_con_if_5.wo_type;
assign pkt_con_if_6.wi_src = pkt_con_if_5.wo_src;
assign pkt_con_if_6.wi_tgt = pkt_con_if_5.wo_tgt;
assign pkt_con_if_6.wi_data = pkt_con_if_5.wo_data;
assign pkt_con_if_5.wo_rdy = pkt_con_if_6.wi_rdy;

// East connection from Node 7 (7,0)
assign pkt_con_if_6.ei_vld = pkt_con_if_7.eo_vld;
assign pkt_con_if_6.ei_qos = pkt_con_if_7.eo_qos;
assign pkt_con_if_6.ei_type = pkt_con_if_7.eo_type;
assign pkt_con_if_6.ei_src = pkt_con_if_7.eo_src;
assign pkt_con_if_6.ei_tgt = pkt_con_if_7.eo_tgt;
assign pkt_con_if_6.ei_data = pkt_con_if_7.eo_data;
assign pkt_con_if_7.eo_rdy = pkt_con_if_6.ei_rdy;

// South connection from Node 14 (6,1)
assign pkt_con_if_6.si_vld = pkt_con_if_14.so_vld;
assign pkt_con_if_6.si_qos = pkt_con_if_14.so_qos;
assign pkt_con_if_6.si_type = pkt_con_if_14.so_type;
assign pkt_con_if_6.si_src = pkt_con_if_14.so_src;
assign pkt_con_if_6.si_tgt = pkt_con_if_14.so_tgt;
assign pkt_con_if_6.si_data = pkt_con_if_14.so_data;
assign pkt_con_if_14.so_rdy = pkt_con_if_6.si_rdy;

// Node 7 (7,0) - Top-right corner: only South and West connections
assign pkt_con_if_7.ni_vld = 1'b0;
assign pkt_con_if_7.ni_qos = 1'b0;
assign pkt_con_if_7.ni_type = 2'b00;
assign pkt_con_if_7.ni_src = 6'b000000;
assign pkt_con_if_7.ni_tgt = 6'b000000;
assign pkt_con_if_7.ni_data = 8'b00000000;

assign pkt_con_if_7.ei_vld = 1'b0;
assign pkt_con_if_7.ei_qos = 1'b0;
assign pkt_con_if_7.ei_type = 2'b00;
assign pkt_con_if_7.ei_src = 6'b000000;
assign pkt_con_if_7.ei_tgt = 6'b000000;
assign pkt_con_if_7.ei_data = 8'b00000000;

// West connection from Node 6 (6,0)
assign pkt_con_if_7.wi_vld = pkt_con_if_6.wo_vld;
assign pkt_con_if_7.wi_qos = pkt_con_if_6.wo_qos;
assign pkt_con_if_7.wi_type = pkt_con_if_6.wo_type;
assign pkt_con_if_7.wi_src = pkt_con_if_6.wo_src;
assign pkt_con_if_7.wi_tgt = pkt_con_if_6.wo_tgt;
assign pkt_con_if_7.wi_data = pkt_con_if_6.wo_data;
assign pkt_con_if_6.wo_rdy = pkt_con_if_7.wi_rdy;

// South connection from Node 15 (7,1)
assign pkt_con_if_7.si_vld = pkt_con_if_15.so_vld;
assign pkt_con_if_7.si_qos = pkt_con_if_15.so_qos;
assign pkt_con_if_7.si_type = pkt_con_if_15.so_type;
assign pkt_con_if_7.si_src = pkt_con_if_15.so_src;
assign pkt_con_if_7.si_tgt = pkt_con_if_15.so_tgt;
assign pkt_con_if_7.si_data = pkt_con_if_15.so_data;
assign pkt_con_if_15.so_rdy = pkt_con_if_7.si_rdy;

// Continue with Node 8 (0,1) - Left edge: no West connection
assign pkt_con_if_8.wi_vld = 1'b0;
assign pkt_con_if_8.wi_qos = 1'b0;
assign pkt_con_if_8.wi_type = 2'b00;
assign pkt_con_if_8.wi_src = 6'b000000;
assign pkt_con_if_8.wi_tgt = 6'b000000;
assign pkt_con_if_8.wi_data = 8'b00000000;

// North connection from Node 0 (0,0)
assign pkt_con_if_8.ni_vld = pkt_con_if_0.no_vld;
assign pkt_con_if_8.ni_qos = pkt_con_if_0.no_qos;
assign pkt_con_if_8.ni_type = pkt_con_if_0.no_type;
assign pkt_con_if_8.ni_src = pkt_con_if_0.no_src;
assign pkt_con_if_8.ni_tgt = pkt_con_if_0.no_tgt;
assign pkt_con_if_8.ni_data = pkt_con_if_0.no_data;
assign pkt_con_if_0.no_rdy = pkt_con_if_8.ni_rdy;

// South connection from Node 16 (0,2)
assign pkt_con_if_8.si_vld = pkt_con_if_16.so_vld;
assign pkt_con_if_8.si_qos = pkt_con_if_16.so_qos;
assign pkt_con_if_8.si_type = pkt_con_if_16.so_type;
assign pkt_con_if_8.si_src = pkt_con_if_16.so_src;
assign pkt_con_if_8.si_tgt = pkt_con_if_16.so_tgt;
assign pkt_con_if_8.si_data = pkt_con_if_16.so_data;
assign pkt_con_if_16.so_rdy = pkt_con_if_8.si_rdy;

// East connection from Node 9 (1,1)
assign pkt_con_if_8.ei_vld = pkt_con_if_9.eo_vld;
assign pkt_con_if_8.ei_qos = pkt_con_if_9.eo_qos;
assign pkt_con_if_8.ei_type = pkt_con_if_9.eo_type;
assign pkt_con_if_8.ei_src = pkt_con_if_9.eo_src;
assign pkt_con_if_8.ei_tgt = pkt_con_if_9.eo_tgt;
assign pkt_con_if_8.ei_data = pkt_con_if_9.eo_data;
assign pkt_con_if_9.eo_rdy = pkt_con_if_8.ei_rdy;

// Node 9 (1,1) - Interior node: all 4 connections
// North connection from Node 1 (1,0)
assign pkt_con_if_9.ni_vld = pkt_con_if_1.no_vld;
assign pkt_con_if_9.ni_qos = pkt_con_if_1.no_qos;
assign pkt_con_if_9.ni_type = pkt_con_if_1.no_type;
assign pkt_con_if_9.ni_src = pkt_con_if_1.no_src;
assign pkt_con_if_9.ni_tgt = pkt_con_if_1.no_tgt;
assign pkt_con_if_9.ni_data = pkt_con_if_1.no_data;
assign pkt_con_if_1.no_rdy = pkt_con_if_9.ni_rdy;

// West connection from Node 8 (0,1)
assign pkt_con_if_9.wi_vld = pkt_con_if_8.wo_vld;
assign pkt_con_if_9.wi_qos = pkt_con_if_8.wo_qos;
assign pkt_con_if_9.wi_type = pkt_con_if_8.wo_type;
assign pkt_con_if_9.wi_src = pkt_con_if_8.wo_src;
assign pkt_con_if_9.wi_tgt = pkt_con_if_8.wo_tgt;
assign pkt_con_if_9.wi_data = pkt_con_if_8.wo_data;
assign pkt_con_if_8.wo_rdy = pkt_con_if_9.wi_rdy;

// South connection from Node 17 (1,2)
assign pkt_con_if_9.si_vld = pkt_con_if_17.so_vld;
assign pkt_con_if_9.si_qos = pkt_con_if_17.so_qos;
assign pkt_con_if_9.si_type = pkt_con_if_17.so_type;
assign pkt_con_if_9.si_src = pkt_con_if_17.so_src;
assign pkt_con_if_9.si_tgt = pkt_con_if_17.so_tgt;
assign pkt_con_if_9.si_data = pkt_con_if_17.so_data;
assign pkt_con_if_17.so_rdy = pkt_con_if_9.si_rdy;

// East connection from Node 10 (2,1)
assign pkt_con_if_9.ei_vld = pkt_con_if_10.eo_vld;
assign pkt_con_if_9.ei_qos = pkt_con_if_10.eo_qos;
assign pkt_con_if_9.ei_type = pkt_con_if_10.eo_type;
assign pkt_con_if_9.ei_src = pkt_con_if_10.eo_src;
assign pkt_con_if_9.ei_tgt = pkt_con_if_10.eo_tgt;
assign pkt_con_if_9.ei_data = pkt_con_if_10.eo_data;
assign pkt_con_if_10.eo_rdy = pkt_con_if_9.ei_rdy;

// Node 10 (2,1) - Interior node: all 4 connections
// North connection from Node 2 (2,0)
assign pkt_con_if_10.ni_vld = pkt_con_if_2.no_vld;
assign pkt_con_if_10.ni_qos = pkt_con_if_2.no_qos;
assign pkt_con_if_10.ni_type = pkt_con_if_2.no_type;
assign pkt_con_if_10.ni_src = pkt_con_if_2.no_src;
assign pkt_con_if_10.ni_tgt = pkt_con_if_2.no_tgt;
assign pkt_con_if_10.ni_data = pkt_con_if_2.no_data;
assign pkt_con_if_2.no_rdy = pkt_con_if_10.ni_rdy;

// West connection from Node 9 (1,1)
assign pkt_con_if_10.wi_vld = pkt_con_if_9.wo_vld;
assign pkt_con_if_10.wi_qos = pkt_con_if_9.wo_qos;
assign pkt_con_if_10.wi_type = pkt_con_if_9.wo_type;
assign pkt_con_if_10.wi_src = pkt_con_if_9.wo_src;
assign pkt_con_if_10.wi_tgt = pkt_con_if_9.wo_tgt;
assign pkt_con_if_10.wi_data = pkt_con_if_9.wo_data;
assign pkt_con_if_9.wo_rdy = pkt_con_if_10.wi_rdy;

// South connection from Node 18 (2,2)
assign pkt_con_if_10.si_vld = pkt_con_if_18.so_vld;
assign pkt_con_if_10.si_qos = pkt_con_if_18.so_qos;
assign pkt_con_if_10.si_type = pkt_con_if_18.so_type;
assign pkt_con_if_10.si_src = pkt_con_if_18.so_src;
assign pkt_con_if_10.si_tgt = pkt_con_if_18.so_tgt;
assign pkt_con_if_10.si_data = pkt_con_if_18.so_data;
assign pkt_con_if_18.so_rdy = pkt_con_if_10.si_rdy;

// East connection from Node 11 (3,1)
assign pkt_con_if_10.ei_vld = pkt_con_if_11.eo_vld;
assign pkt_con_if_10.ei_qos = pkt_con_if_11.eo_qos;
assign pkt_con_if_10.ei_type = pkt_con_if_11.eo_type;
assign pkt_con_if_10.ei_src = pkt_con_if_11.eo_src;
assign pkt_con_if_10.ei_tgt = pkt_con_if_11.eo_tgt;
assign pkt_con_if_10.ei_data = pkt_con_if_11.eo_data;
assign pkt_con_if_11.eo_rdy = pkt_con_if_10.ei_rdy;

// Node 11 (3,1) - Interior node: all 4 connections
// North connection from Node 3 (3,0)
assign pkt_con_if_11.ni_vld = pkt_con_if_3.no_vld;
assign pkt_con_if_11.ni_qos = pkt_con_if_3.no_qos;
assign pkt_con_if_11.ni_type = pkt_con_if_3.no_type;
assign pkt_con_if_11.ni_src = pkt_con_if_3.no_src;
assign pkt_con_if_11.ni_tgt = pkt_con_if_3.no_tgt;
assign pkt_con_if_11.ni_data = pkt_con_if_3.no_data;
assign pkt_con_if_3.no_rdy = pkt_con_if_11.ni_rdy;

// West connection from Node 10 (2,1)
assign pkt_con_if_11.wi_vld = pkt_con_if_10.wo_vld;
assign pkt_con_if_11.wi_qos = pkt_con_if_10.wo_qos;
assign pkt_con_if_11.wi_type = pkt_con_if_10.wo_type;
assign pkt_con_if_11.wi_src = pkt_con_if_10.wo_src;
assign pkt_con_if_11.wi_tgt = pkt_con_if_10.wo_tgt;
assign pkt_con_if_11.wi_data = pkt_con_if_10.wo_data;
assign pkt_con_if_10.wo_rdy = pkt_con_if_11.wi_rdy;

// South connection from Node 19 (3,2)
assign pkt_con_if_11.si_vld = pkt_con_if_19.so_vld;
assign pkt_con_if_11.si_qos = pkt_con_if_19.so_qos;
assign pkt_con_if_11.si_type = pkt_con_if_19.so_type;
assign pkt_con_if_11.si_src = pkt_con_if_19.so_src;
assign pkt_con_if_11.si_tgt = pkt_con_if_19.so_tgt;
assign pkt_con_if_11.si_data = pkt_con_if_19.so_data;
assign pkt_con_if_19.so_rdy = pkt_con_if_11.si_rdy;

// East connection from Node 12 (4,1)
assign pkt_con_if_11.ei_vld = pkt_con_if_12.eo_vld;
assign pkt_con_if_11.ei_qos = pkt_con_if_12.eo_qos;
assign pkt_con_if_11.ei_type = pkt_con_if_12.eo_type;
assign pkt_con_if_11.ei_src = pkt_con_if_12.eo_src;
assign pkt_con_if_11.ei_tgt = pkt_con_if_12.eo_tgt;
assign pkt_con_if_11.ei_data = pkt_con_if_12.eo_data;
assign pkt_con_if_12.eo_rdy = pkt_con_if_11.ei_rdy;

// Node 12 (4,1) - Interior node: all 4 connections
// North connection from Node 4 (4,0)
assign pkt_con_if_12.ni_vld = pkt_con_if_4.no_vld;
assign pkt_con_if_12.ni_qos = pkt_con_if_4.no_qos;
assign pkt_con_if_12.ni_type = pkt_con_if_4.no_type;
assign pkt_con_if_12.ni_src = pkt_con_if_4.no_src;
assign pkt_con_if_12.ni_tgt = pkt_con_if_4.no_tgt;
assign pkt_con_if_12.ni_data = pkt_con_if_4.no_data;
assign pkt_con_if_4.no_rdy = pkt_con_if_12.ni_rdy;

// West connection from Node 11 (3,1)
assign pkt_con_if_12.wi_vld = pkt_con_if_11.wo_vld;
assign pkt_con_if_12.wi_qos = pkt_con_if_11.wo_qos;
assign pkt_con_if_12.wi_type = pkt_con_if_11.wo_type;
assign pkt_con_if_12.wi_src = pkt_con_if_11.wo_src;
assign pkt_con_if_12.wi_tgt = pkt_con_if_11.wo_tgt;
assign pkt_con_if_12.wi_data = pkt_con_if_11.wo_data;
assign pkt_con_if_11.wo_rdy = pkt_con_if_12.wi_rdy;

// South connection from Node 20 (4,2)
assign pkt_con_if_12.si_vld = pkt_con_if_20.so_vld;
assign pkt_con_if_12.si_qos = pkt_con_if_20.so_qos;
assign pkt_con_if_12.si_type = pkt_con_if_20.so_type;
assign pkt_con_if_12.si_src = pkt_con_if_20.so_src;
assign pkt_con_if_12.si_tgt = pkt_con_if_20.so_tgt;
assign pkt_con_if_12.si_data = pkt_con_if_20.so_data;
assign pkt_con_if_20.so_rdy = pkt_con_if_12.si_rdy;

// East connection from Node 13 (5,1)
assign pkt_con_if_12.ei_vld = pkt_con_if_13.eo_vld;
assign pkt_con_if_12.ei_qos = pkt_con_if_13.eo_qos;
assign pkt_con_if_12.ei_type = pkt_con_if_13.eo_type;
assign pkt_con_if_12.ei_src = pkt_con_if_13.eo_src;
assign pkt_con_if_12.ei_tgt = pkt_con_if_13.eo_tgt;
assign pkt_con_if_12.ei_data = pkt_con_if_13.eo_data;
assign pkt_con_if_13.eo_rdy = pkt_con_if_12.ei_rdy;

// Node 13 (5,1) - Interior node: all 4 connections
// North connection from Node 5 (5,0)
assign pkt_con_if_13.ni_vld = pkt_con_if_5.no_vld;
assign pkt_con_if_13.ni_qos = pkt_con_if_5.no_qos;
assign pkt_con_if_13.ni_type = pkt_con_if_5.no_type;
assign pkt_con_if_13.ni_src = pkt_con_if_5.no_src;
assign pkt_con_if_13.ni_tgt = pkt_con_if_5.no_tgt;
assign pkt_con_if_13.ni_data = pkt_con_if_5.no_data;
assign pkt_con_if_5.no_rdy = pkt_con_if_13.ni_rdy;

// West connection from Node 12 (4,1)
assign pkt_con_if_13.wi_vld = pkt_con_if_12.wo_vld;
assign pkt_con_if_13.wi_qos = pkt_con_if_12.wo_qos;
assign pkt_con_if_13.wi_type = pkt_con_if_12.wo_type;
assign pkt_con_if_13.wi_src = pkt_con_if_12.wo_src;
assign pkt_con_if_13.wi_tgt = pkt_con_if_12.wo_tgt;
assign pkt_con_if_13.wi_data = pkt_con_if_12.wo_data;
assign pkt_con_if_12.wo_rdy = pkt_con_if_13.wi_rdy;

// South connection from Node 21 (5,2)
assign pkt_con_if_13.si_vld = pkt_con_if_21.so_vld;
assign pkt_con_if_13.si_qos = pkt_con_if_21.so_qos;
assign pkt_con_if_13.si_type = pkt_con_if_21.so_type;
assign pkt_con_if_13.si_src = pkt_con_if_21.so_src;
assign pkt_con_if_13.si_tgt = pkt_con_if_21.so_tgt;
assign pkt_con_if_13.si_data = pkt_con_if_21.so_data;
assign pkt_con_if_21.so_rdy = pkt_con_if_13.si_rdy;

// East connection from Node 14 (6,1)
assign pkt_con_if_13.ei_vld = pkt_con_if_14.eo_vld;
assign pkt_con_if_13.ei_qos = pkt_con_if_14.eo_qos;
assign pkt_con_if_13.ei_type = pkt_con_if_14.eo_type;
assign pkt_con_if_13.ei_src = pkt_con_if_14.eo_src;
assign pkt_con_if_13.ei_tgt = pkt_con_if_14.eo_tgt;
assign pkt_con_if_13.ei_data = pkt_con_if_14.eo_data;
assign pkt_con_if_14.eo_rdy = pkt_con_if_13.ei_rdy;

// Node 14 (6,1) - Interior node: all 4 connections
// North connection from Node 6 (6,0)
assign pkt_con_if_14.ni_vld = pkt_con_if_6.no_vld;
assign pkt_con_if_14.ni_qos = pkt_con_if_6.no_qos;
assign pkt_con_if_14.ni_type = pkt_con_if_6.no_type;
assign pkt_con_if_14.ni_src = pkt_con_if_6.no_src;
assign pkt_con_if_14.ni_tgt = pkt_con_if_6.no_tgt;
assign pkt_con_if_14.ni_data = pkt_con_if_6.no_data;
assign pkt_con_if_6.no_rdy = pkt_con_if_14.ni_rdy;

// West connection from Node 13 (5,1)
assign pkt_con_if_14.wi_vld = pkt_con_if_13.wo_vld;
assign pkt_con_if_14.wi_qos = pkt_con_if_13.wo_qos;
assign pkt_con_if_14.wi_type = pkt_con_if_13.wo_type;
assign pkt_con_if_14.wi_src = pkt_con_if_13.wo_src;
assign pkt_con_if_14.wi_tgt = pkt_con_if_13.wo_tgt;
assign pkt_con_if_14.wi_data = pkt_con_if_13.wo_data;
assign pkt_con_if_13.wo_rdy = pkt_con_if_14.wi_rdy;

// South connection from Node 22 (6,2)
assign pkt_con_if_14.si_vld = pkt_con_if_22.so_vld;
assign pkt_con_if_14.si_qos = pkt_con_if_22.so_qos;
assign pkt_con_if_14.si_type = pkt_con_if_22.so_type;
assign pkt_con_if_14.si_src = pkt_con_if_22.so_src;
assign pkt_con_if_14.si_tgt = pkt_con_if_22.so_tgt;
assign pkt_con_if_14.si_data = pkt_con_if_22.so_data;
assign pkt_con_if_22.so_rdy = pkt_con_if_14.si_rdy;

// East connection from Node 15 (7,1)
assign pkt_con_if_14.ei_vld = pkt_con_if_15.eo_vld;
assign pkt_con_if_14.ei_qos = pkt_con_if_15.eo_qos;
assign pkt_con_if_14.ei_type = pkt_con_if_15.eo_type;
assign pkt_con_if_14.ei_src = pkt_con_if_15.eo_src;
assign pkt_con_if_14.ei_tgt = pkt_con_if_15.eo_tgt;
assign pkt_con_if_14.ei_data = pkt_con_if_15.eo_data;
assign pkt_con_if_15.eo_rdy = pkt_con_if_14.ei_rdy;

// Node 15 (7,1) - Right edge: no East connection
// North connection from Node 7 (7,0)
assign pkt_con_if_15.ni_vld = pkt_con_if_7.no_vld;
assign pkt_con_if_15.ni_qos = pkt_con_if_7.no_qos;
assign pkt_con_if_15.ni_type = pkt_con_if_7.no_type;
assign pkt_con_if_15.ni_src = pkt_con_if_7.no_src;
assign pkt_con_if_15.ni_tgt = pkt_con_if_7.no_tgt;
assign pkt_con_if_15.ni_data = pkt_con_if_7.no_data;
assign pkt_con_if_7.no_rdy = pkt_con_if_15.ni_rdy;

// West connection from Node 14 (6,1)
assign pkt_con_if_15.wi_vld = pkt_con_if_14.wo_vld;
assign pkt_con_if_15.wi_qos = pkt_con_if_14.wo_qos;
assign pkt_con_if_15.wi_type = pkt_con_if_14.wo_type;
assign pkt_con_if_15.wi_src = pkt_con_if_14.wo_src;
assign pkt_con_if_15.wi_tgt = pkt_con_if_14.wo_tgt;
assign pkt_con_if_15.wi_data = pkt_con_if_14.wo_data;
assign pkt_con_if_14.wo_rdy = pkt_con_if_15.wi_rdy;

// South connection from Node 23 (7,2)
assign pkt_con_if_15.si_vld = pkt_con_if_23.so_vld;
assign pkt_con_if_15.si_qos = pkt_con_if_23.so_qos;
assign pkt_con_if_15.si_type = pkt_con_if_23.so_type;
assign pkt_con_if_15.si_src = pkt_con_if_23.so_src;
assign pkt_con_if_15.si_tgt = pkt_con_if_23.so_tgt;
assign pkt_con_if_15.si_data = pkt_con_if_23.so_data;
assign pkt_con_if_23.so_rdy = pkt_con_if_15.si_rdy;

assign pkt_con_if_15.ei_vld = 1'b0;
assign pkt_con_if_15.ei_qos = 1'b0;
assign pkt_con_if_15.ei_type = 2'b00;
assign pkt_con_if_15.ei_src = 6'b000000;
assign pkt_con_if_15.ei_tgt = 6'b000000;
assign pkt_con_if_15.ei_data = 8'b00000000;

// Row 2 (nodes 16-23): Complete xi connections for all nodes in row y=2
// Node 16 (0,2) - Left edge: no West connection
assign pkt_con_if_16.wi_vld = 1'b0;
assign pkt_con_if_16.wi_qos = 1'b0;
assign pkt_con_if_16.wi_type = 2'b00;
assign pkt_con_if_16.wi_src = 6'b000000;
assign pkt_con_if_16.wi_tgt = 6'b000000;
assign pkt_con_if_16.wi_data = 8'b00000000;

// North connection from Node 8 (0,1)
assign pkt_con_if_16.ni_vld = pkt_con_if_8.no_vld;
assign pkt_con_if_16.ni_qos = pkt_con_if_8.no_qos;
assign pkt_con_if_16.ni_type = pkt_con_if_8.no_type;
assign pkt_con_if_16.ni_src = pkt_con_if_8.no_src;
assign pkt_con_if_16.ni_tgt = pkt_con_if_8.no_tgt;
assign pkt_con_if_16.ni_data = pkt_con_if_8.no_data;
assign pkt_con_if_8.no_rdy = pkt_con_if_16.ni_rdy;

// South connection from Node 24 (0,3)
assign pkt_con_if_16.si_vld = pkt_con_if_24.so_vld;
assign pkt_con_if_16.si_qos = pkt_con_if_24.so_qos;
assign pkt_con_if_16.si_type = pkt_con_if_24.so_type;
assign pkt_con_if_16.si_src = pkt_con_if_24.so_src;
assign pkt_con_if_16.si_tgt = pkt_con_if_24.so_tgt;
assign pkt_con_if_16.si_data = pkt_con_if_24.so_data;
assign pkt_con_if_24.so_rdy = pkt_con_if_16.si_rdy;

// East connection from Node 17 (1,2)
assign pkt_con_if_16.ei_vld = pkt_con_if_17.eo_vld;
assign pkt_con_if_16.ei_qos = pkt_con_if_17.eo_qos;
assign pkt_con_if_16.ei_type = pkt_con_if_17.eo_type;
assign pkt_con_if_16.ei_src = pkt_con_if_17.eo_src;
assign pkt_con_if_16.ei_tgt = pkt_con_if_17.eo_tgt;
assign pkt_con_if_16.ei_data = pkt_con_if_17.eo_data;
assign pkt_con_if_17.eo_rdy = pkt_con_if_16.ei_rdy;

// Node 17 (1,2) - Interior: all 4 connections
// North from Node 9 (1,1)
assign pkt_con_if_17.ni_vld = pkt_con_if_9.no_vld;
assign pkt_con_if_17.ni_qos = pkt_con_if_9.no_qos;
assign pkt_con_if_17.ni_type = pkt_con_if_9.no_type;
assign pkt_con_if_17.ni_src = pkt_con_if_9.no_src;
assign pkt_con_if_17.ni_tgt = pkt_con_if_9.no_tgt;
assign pkt_con_if_17.ni_data = pkt_con_if_9.no_data;
assign pkt_con_if_9.no_rdy = pkt_con_if_17.ni_rdy;

// West from Node 16 (0,2)
assign pkt_con_if_17.wi_vld = pkt_con_if_16.wo_vld;
assign pkt_con_if_17.wi_qos = pkt_con_if_16.wo_qos;
assign pkt_con_if_17.wi_type = pkt_con_if_16.wo_type;
assign pkt_con_if_17.wi_src = pkt_con_if_16.wo_src;
assign pkt_con_if_17.wi_tgt = pkt_con_if_16.wo_tgt;
assign pkt_con_if_17.wi_data = pkt_con_if_16.wo_data;
assign pkt_con_if_16.wo_rdy = pkt_con_if_17.wi_rdy;

// South from Node 25 (1,3)
assign pkt_con_if_17.si_vld = pkt_con_if_25.so_vld;
assign pkt_con_if_17.si_qos = pkt_con_if_25.so_qos;
assign pkt_con_if_17.si_type = pkt_con_if_25.so_type;
assign pkt_con_if_17.si_src = pkt_con_if_25.so_src;
assign pkt_con_if_17.si_tgt = pkt_con_if_25.so_tgt;
assign pkt_con_if_17.si_data = pkt_con_if_25.so_data;
assign pkt_con_if_25.so_rdy = pkt_con_if_17.si_rdy;

// East from Node 18 (2,2)
assign pkt_con_if_17.ei_vld = pkt_con_if_18.eo_vld;
assign pkt_con_if_17.ei_qos = pkt_con_if_18.eo_qos;
assign pkt_con_if_17.ei_type = pkt_con_if_18.eo_type;
assign pkt_con_if_17.ei_src = pkt_con_if_18.eo_src;
assign pkt_con_if_17.ei_tgt = pkt_con_if_18.eo_tgt;
assign pkt_con_if_17.ei_data = pkt_con_if_18.eo_data;
assign pkt_con_if_18.eo_rdy = pkt_con_if_17.ei_rdy;

// Node 18 (2,2) - Interior: all 4 connections
// North from Node 10 (2,1)
assign pkt_con_if_18.ni_vld = pkt_con_if_10.no_vld;
assign pkt_con_if_18.ni_qos = pkt_con_if_10.no_qos;
assign pkt_con_if_18.ni_type = pkt_con_if_10.no_type;
assign pkt_con_if_18.ni_src = pkt_con_if_10.no_src;
assign pkt_con_if_18.ni_tgt = pkt_con_if_10.no_tgt;
assign pkt_con_if_18.ni_data = pkt_con_if_10.no_data;
assign pkt_con_if_10.no_rdy = pkt_con_if_18.ni_rdy;

// West from Node 17 (1,2)
assign pkt_con_if_18.wi_vld = pkt_con_if_17.wo_vld;
assign pkt_con_if_18.wi_qos = pkt_con_if_17.wo_qos;
assign pkt_con_if_18.wi_type = pkt_con_if_17.wo_type;
assign pkt_con_if_18.wi_src = pkt_con_if_17.wo_src;
assign pkt_con_if_18.wi_tgt = pkt_con_if_17.wo_tgt;
assign pkt_con_if_18.wi_data = pkt_con_if_17.wo_data;
assign pkt_con_if_17.wo_rdy = pkt_con_if_18.wi_rdy;

// South from Node 26 (2,3)
assign pkt_con_if_18.si_vld = pkt_con_if_26.so_vld;
assign pkt_con_if_18.si_qos = pkt_con_if_26.so_qos;
assign pkt_con_if_18.si_type = pkt_con_if_26.so_type;
assign pkt_con_if_18.si_src = pkt_con_if_26.so_src;
assign pkt_con_if_18.si_tgt = pkt_con_if_26.so_tgt;
assign pkt_con_if_18.si_data = pkt_con_if_26.so_data;
assign pkt_con_if_26.so_rdy = pkt_con_if_18.si_rdy;

// East from Node 19 (3,2)
assign pkt_con_if_18.ei_vld = pkt_con_if_19.eo_vld;
assign pkt_con_if_18.ei_qos = pkt_con_if_19.eo_qos;
assign pkt_con_if_18.ei_type = pkt_con_if_19.eo_type;
assign pkt_con_if_18.ei_src = pkt_con_if_19.eo_src;
assign pkt_con_if_18.ei_tgt = pkt_con_if_19.eo_tgt;
assign pkt_con_if_18.ei_data = pkt_con_if_19.eo_data;
assign pkt_con_if_19.eo_rdy = pkt_con_if_18.ei_rdy;

// Node 19 (3,2) - Interior: all 4 connections
// North from Node 11 (3,1)
assign pkt_con_if_19.ni_vld = pkt_con_if_11.no_vld;
assign pkt_con_if_19.ni_qos = pkt_con_if_11.no_qos;
assign pkt_con_if_19.ni_type = pkt_con_if_11.no_type;
assign pkt_con_if_19.ni_src = pkt_con_if_11.no_src;
assign pkt_con_if_19.ni_tgt = pkt_con_if_11.no_tgt;
assign pkt_con_if_19.ni_data = pkt_con_if_11.no_data;
assign pkt_con_if_11.no_rdy = pkt_con_if_19.ni_rdy;

// West from Node 18 (2,2)
assign pkt_con_if_19.wi_vld = pkt_con_if_18.wo_vld;
assign pkt_con_if_19.wi_qos = pkt_con_if_18.wo_qos;
assign pkt_con_if_19.wi_type = pkt_con_if_18.wo_type;
assign pkt_con_if_19.wi_src = pkt_con_if_18.wo_src;
assign pkt_con_if_19.wi_tgt = pkt_con_if_18.wo_tgt;
assign pkt_con_if_19.wi_data = pkt_con_if_18.wo_data;
assign pkt_con_if_18.wo_rdy = pkt_con_if_19.wi_rdy;

// South from Node 27 (3,3)
assign pkt_con_if_19.si_vld = pkt_con_if_27.so_vld;
assign pkt_con_if_19.si_qos = pkt_con_if_27.so_qos;
assign pkt_con_if_19.si_type = pkt_con_if_27.so_type;
assign pkt_con_if_19.si_src = pkt_con_if_27.so_src;
assign pkt_con_if_19.si_tgt = pkt_con_if_27.so_tgt;
assign pkt_con_if_19.si_data = pkt_con_if_27.so_data;
assign pkt_con_if_27.so_rdy = pkt_con_if_19.si_rdy;

// East from Node 20 (4,2)
assign pkt_con_if_19.ei_vld = pkt_con_if_20.eo_vld;
assign pkt_con_if_19.ei_qos = pkt_con_if_20.eo_qos;
assign pkt_con_if_19.ei_type = pkt_con_if_20.eo_type;
assign pkt_con_if_19.ei_src = pkt_con_if_20.eo_src;
assign pkt_con_if_19.ei_tgt = pkt_con_if_20.eo_tgt;
assign pkt_con_if_19.ei_data = pkt_con_if_20.eo_data;
assign pkt_con_if_20.eo_rdy = pkt_con_if_19.ei_rdy;

// Node 20 (4,2) - Interior: all 4 connections
// North from Node 12 (4,1)
assign pkt_con_if_20.ni_vld = pkt_con_if_12.no_vld;
assign pkt_con_if_20.ni_qos = pkt_con_if_12.no_qos;
assign pkt_con_if_20.ni_type = pkt_con_if_12.no_type;
assign pkt_con_if_20.ni_src = pkt_con_if_12.no_src;
assign pkt_con_if_20.ni_tgt = pkt_con_if_12.no_tgt;
assign pkt_con_if_20.ni_data = pkt_con_if_12.no_data;
assign pkt_con_if_12.no_rdy = pkt_con_if_20.ni_rdy;

// West from Node 19 (3,2)
assign pkt_con_if_20.wi_vld = pkt_con_if_19.wo_vld;
assign pkt_con_if_20.wi_qos = pkt_con_if_19.wo_qos;
assign pkt_con_if_20.wi_type = pkt_con_if_19.wo_type;
assign pkt_con_if_20.wi_src = pkt_con_if_19.wo_src;
assign pkt_con_if_20.wi_tgt = pkt_con_if_19.wo_tgt;
assign pkt_con_if_20.wi_data = pkt_con_if_19.wo_data;
assign pkt_con_if_19.wo_rdy = pkt_con_if_20.wi_rdy;

// South from Node 28 (4,3)
assign pkt_con_if_20.si_vld = pkt_con_if_28.so_vld;
assign pkt_con_if_20.si_qos = pkt_con_if_28.so_qos;
assign pkt_con_if_20.si_type = pkt_con_if_28.so_type;
assign pkt_con_if_20.si_src = pkt_con_if_28.so_src;
assign pkt_con_if_20.si_tgt = pkt_con_if_28.so_tgt;
assign pkt_con_if_20.si_data = pkt_con_if_28.so_data;
assign pkt_con_if_28.so_rdy = pkt_con_if_20.si_rdy;

// East from Node 21 (5,2)
assign pkt_con_if_20.ei_vld = pkt_con_if_21.eo_vld;
assign pkt_con_if_20.ei_qos = pkt_con_if_21.eo_qos;
assign pkt_con_if_20.ei_type = pkt_con_if_21.eo_type;
assign pkt_con_if_20.ei_src = pkt_con_if_21.eo_src;
assign pkt_con_if_20.ei_tgt = pkt_con_if_21.eo_tgt;
assign pkt_con_if_20.ei_data = pkt_con_if_21.eo_data;
assign pkt_con_if_21.eo_rdy = pkt_con_if_20.ei_rdy;

// Node 21 (5,2) - Interior: all 4 connections
// North from Node 13 (5,1)
assign pkt_con_if_21.ni_vld = pkt_con_if_13.no_vld;
assign pkt_con_if_21.ni_qos = pkt_con_if_13.no_qos;
assign pkt_con_if_21.ni_type = pkt_con_if_13.no_type;
assign pkt_con_if_21.ni_src = pkt_con_if_13.no_src;
assign pkt_con_if_21.ni_tgt = pkt_con_if_13.no_tgt;
assign pkt_con_if_21.ni_data = pkt_con_if_13.no_data;
assign pkt_con_if_13.no_rdy = pkt_con_if_21.ni_rdy;

// West from Node 20 (4,2)
assign pkt_con_if_21.wi_vld = pkt_con_if_20.wo_vld;
assign pkt_con_if_21.wi_qos = pkt_con_if_20.wo_qos;
assign pkt_con_if_21.wi_type = pkt_con_if_20.wo_type;
assign pkt_con_if_21.wi_src = pkt_con_if_20.wo_src;
assign pkt_con_if_21.wi_tgt = pkt_con_if_20.wo_tgt;
assign pkt_con_if_21.wi_data = pkt_con_if_20.wo_data;
assign pkt_con_if_20.wo_rdy = pkt_con_if_21.wi_rdy;

// South from Node 29 (5,3)
assign pkt_con_if_21.si_vld = pkt_con_if_29.so_vld;
assign pkt_con_if_21.si_qos = pkt_con_if_29.so_qos;
assign pkt_con_if_21.si_type = pkt_con_if_29.so_type;
assign pkt_con_if_21.si_src = pkt_con_if_29.so_src;
assign pkt_con_if_21.si_tgt = pkt_con_if_29.so_tgt;
assign pkt_con_if_21.si_data = pkt_con_if_29.so_data;
assign pkt_con_if_29.so_rdy = pkt_con_if_21.si_rdy;

// East from Node 22 (6,2)
assign pkt_con_if_21.ei_vld = pkt_con_if_22.eo_vld;
assign pkt_con_if_21.ei_qos = pkt_con_if_22.eo_qos;
assign pkt_con_if_21.ei_type = pkt_con_if_22.eo_type;
assign pkt_con_if_21.ei_src = pkt_con_if_22.eo_src;
assign pkt_con_if_21.ei_tgt = pkt_con_if_22.eo_tgt;
assign pkt_con_if_21.ei_data = pkt_con_if_22.eo_data;
assign pkt_con_if_22.eo_rdy = pkt_con_if_21.ei_rdy;

// Node 22 (6,2) - Interior: all 4 connections
// North from Node 14 (6,1)
assign pkt_con_if_22.ni_vld = pkt_con_if_14.no_vld;
assign pkt_con_if_22.ni_qos = pkt_con_if_14.no_qos;
assign pkt_con_if_22.ni_type = pkt_con_if_14.no_type;
assign pkt_con_if_22.ni_src = pkt_con_if_14.no_src;
assign pkt_con_if_22.ni_tgt = pkt_con_if_14.no_tgt;
assign pkt_con_if_22.ni_data = pkt_con_if_14.no_data;
assign pkt_con_if_14.no_rdy = pkt_con_if_22.ni_rdy;

// West from Node 21 (5,2)
assign pkt_con_if_22.wi_vld = pkt_con_if_21.wo_vld;
assign pkt_con_if_22.wi_qos = pkt_con_if_21.wo_qos;
assign pkt_con_if_22.wi_type = pkt_con_if_21.wo_type;
assign pkt_con_if_22.wi_src = pkt_con_if_21.wo_src;
assign pkt_con_if_22.wi_tgt = pkt_con_if_21.wo_tgt;
assign pkt_con_if_22.wi_data = pkt_con_if_21.wo_data;
assign pkt_con_if_21.wo_rdy = pkt_con_if_22.wi_rdy;

// South from Node 30 (6,3)
assign pkt_con_if_22.si_vld = pkt_con_if_30.so_vld;
assign pkt_con_if_22.si_qos = pkt_con_if_30.so_qos;
assign pkt_con_if_22.si_type = pkt_con_if_30.so_type;
assign pkt_con_if_22.si_src = pkt_con_if_30.so_src;
assign pkt_con_if_22.si_tgt = pkt_con_if_30.so_tgt;
assign pkt_con_if_22.si_data = pkt_con_if_30.so_data;
assign pkt_con_if_30.so_rdy = pkt_con_if_22.si_rdy;

// East from Node 23 (7,2)
assign pkt_con_if_22.ei_vld = pkt_con_if_23.eo_vld;
assign pkt_con_if_22.ei_qos = pkt_con_if_23.eo_qos;
assign pkt_con_if_22.ei_type = pkt_con_if_23.eo_type;
assign pkt_con_if_22.ei_src = pkt_con_if_23.eo_src;
assign pkt_con_if_22.ei_tgt = pkt_con_if_23.eo_tgt;
assign pkt_con_if_22.ei_data = pkt_con_if_23.eo_data;
assign pkt_con_if_23.eo_rdy = pkt_con_if_22.ei_rdy;

// Node 23 (7,2) - Right edge: no East connection
// North from Node 15 (7,1)
assign pkt_con_if_23.ni_vld = pkt_con_if_15.no_vld;
assign pkt_con_if_23.ni_qos = pkt_con_if_15.no_qos;
assign pkt_con_if_23.ni_type = pkt_con_if_15.no_type;
assign pkt_con_if_23.ni_src = pkt_con_if_15.no_src;
assign pkt_con_if_23.ni_tgt = pkt_con_if_15.no_tgt;
assign pkt_con_if_23.ni_data = pkt_con_if_15.no_data;
assign pkt_con_if_15.no_rdy = pkt_con_if_23.ni_rdy;

// West from Node 22 (6,2)
assign pkt_con_if_23.wi_vld = pkt_con_if_22.wo_vld;
assign pkt_con_if_23.wi_qos = pkt_con_if_22.wo_qos;
assign pkt_con_if_23.wi_type = pkt_con_if_22.wo_type;
assign pkt_con_if_23.wi_src = pkt_con_if_22.wo_src;
assign pkt_con_if_23.wi_tgt = pkt_con_if_22.wo_tgt;
assign pkt_con_if_23.wi_data = pkt_con_if_22.wo_data;
assign pkt_con_if_22.wo_rdy = pkt_con_if_23.wi_rdy;

// South from Node 31 (7,3)
assign pkt_con_if_23.si_vld = pkt_con_if_31.so_vld;
assign pkt_con_if_23.si_qos = pkt_con_if_31.so_qos;
assign pkt_con_if_23.si_type = pkt_con_if_31.so_type;
assign pkt_con_if_23.si_src = pkt_con_if_31.so_src;
assign pkt_con_if_23.si_tgt = pkt_con_if_31.so_tgt;
assign pkt_con_if_23.si_data = pkt_con_if_31.so_data;
assign pkt_con_if_31.so_rdy = pkt_con_if_23.si_rdy;

assign pkt_con_if_23.ei_vld = 1'b0;
assign pkt_con_if_23.ei_qos = 1'b0;
assign pkt_con_if_23.ei_type = 2'b00;
assign pkt_con_if_23.ei_src = 6'b000000;
assign pkt_con_if_23.ei_tgt = 6'b000000;
assign pkt_con_if_23.ei_data = 8'b00000000;

// Row 3 (nodes 24-31): Complete xi connections for all nodes in row y=3
// Node 24 (0,3) - Left edge: no West connection
assign pkt_con_if_24.wi_vld = 1'b0;
assign pkt_con_if_24.wi_qos = 1'b0;
assign pkt_con_if_24.wi_type = 2'b00;
assign pkt_con_if_24.wi_src = 6'b000000;
assign pkt_con_if_24.wi_tgt = 6'b000000;
assign pkt_con_if_24.wi_data = 8'b00000000;

assign pkt_con_if_24.ni_vld = pkt_con_if_16.no_vld;
assign pkt_con_if_24.ni_qos = pkt_con_if_16.no_qos;
assign pkt_con_if_24.ni_type = pkt_con_if_16.no_type;
assign pkt_con_if_24.ni_src = pkt_con_if_16.no_src;
assign pkt_con_if_24.ni_tgt = pkt_con_if_16.no_tgt;
assign pkt_con_if_24.ni_data = pkt_con_if_16.no_data;
assign pkt_con_if_16.no_rdy = pkt_con_if_24.ni_rdy;

assign pkt_con_if_24.si_vld = pkt_con_if_32.so_vld;
assign pkt_con_if_24.si_qos = pkt_con_if_32.so_qos;
assign pkt_con_if_24.si_type = pkt_con_if_32.so_type;
assign pkt_con_if_24.si_src = pkt_con_if_32.so_src;
assign pkt_con_if_24.si_tgt = pkt_con_if_32.so_tgt;
assign pkt_con_if_24.si_data = pkt_con_if_32.so_data;
assign pkt_con_if_32.so_rdy = pkt_con_if_24.si_rdy;

assign pkt_con_if_24.ei_vld = pkt_con_if_25.eo_vld;
assign pkt_con_if_24.ei_qos = pkt_con_if_25.eo_qos;
assign pkt_con_if_24.ei_type = pkt_con_if_25.eo_type;
assign pkt_con_if_24.ei_src = pkt_con_if_25.eo_src;
assign pkt_con_if_24.ei_tgt = pkt_con_if_25.eo_tgt;
assign pkt_con_if_24.ei_data = pkt_con_if_25.eo_data;
assign pkt_con_if_25.eo_rdy = pkt_con_if_24.ei_rdy;

// Node 25 (1,3) - Interior: all 4 connections
assign pkt_con_if_25.ni_vld = pkt_con_if_17.no_vld;
assign pkt_con_if_25.ni_qos = pkt_con_if_17.no_qos;
assign pkt_con_if_25.ni_type = pkt_con_if_17.no_type;
assign pkt_con_if_25.ni_src = pkt_con_if_17.no_src;
assign pkt_con_if_25.ni_tgt = pkt_con_if_17.no_tgt;
assign pkt_con_if_25.ni_data = pkt_con_if_17.no_data;
assign pkt_con_if_17.no_rdy = pkt_con_if_25.ni_rdy;

assign pkt_con_if_25.wi_vld = pkt_con_if_24.wo_vld;
assign pkt_con_if_25.wi_qos = pkt_con_if_24.wo_qos;
assign pkt_con_if_25.wi_type = pkt_con_if_24.wo_type;
assign pkt_con_if_25.wi_src = pkt_con_if_24.wo_src;
assign pkt_con_if_25.wi_tgt = pkt_con_if_24.wo_tgt;
assign pkt_con_if_25.wi_data = pkt_con_if_24.wo_data;
assign pkt_con_if_24.wo_rdy = pkt_con_if_25.wi_rdy;

assign pkt_con_if_25.si_vld = pkt_con_if_33.so_vld;
assign pkt_con_if_25.si_qos = pkt_con_if_33.so_qos;
assign pkt_con_if_25.si_type = pkt_con_if_33.so_type;
assign pkt_con_if_25.si_src = pkt_con_if_33.so_src;
assign pkt_con_if_25.si_tgt = pkt_con_if_33.so_tgt;
assign pkt_con_if_25.si_data = pkt_con_if_33.so_data;
assign pkt_con_if_33.so_rdy = pkt_con_if_25.si_rdy;

assign pkt_con_if_25.ei_vld = pkt_con_if_26.eo_vld;
assign pkt_con_if_25.ei_qos = pkt_con_if_26.eo_qos;
assign pkt_con_if_25.ei_type = pkt_con_if_26.eo_type;
assign pkt_con_if_25.ei_src = pkt_con_if_26.eo_src;
assign pkt_con_if_25.ei_tgt = pkt_con_if_26.eo_tgt;
assign pkt_con_if_25.ei_data = pkt_con_if_26.eo_data;
assign pkt_con_if_26.eo_rdy = pkt_con_if_25.ei_rdy;

// Node 26 (2,3) - Interior: all 4 connections
assign pkt_con_if_26.ni_vld = pkt_con_if_18.no_vld;
assign pkt_con_if_26.ni_qos = pkt_con_if_18.no_qos;
assign pkt_con_if_26.ni_type = pkt_con_if_18.no_type;
assign pkt_con_if_26.ni_src = pkt_con_if_18.no_src;
assign pkt_con_if_26.ni_tgt = pkt_con_if_18.no_tgt;
assign pkt_con_if_26.ni_data = pkt_con_if_18.no_data;
assign pkt_con_if_18.no_rdy = pkt_con_if_26.ni_rdy;

assign pkt_con_if_26.wi_vld = pkt_con_if_25.wo_vld;
assign pkt_con_if_26.wi_qos = pkt_con_if_25.wo_qos;
assign pkt_con_if_26.wi_type = pkt_con_if_25.wo_type;
assign pkt_con_if_26.wi_src = pkt_con_if_25.wo_src;
assign pkt_con_if_26.wi_tgt = pkt_con_if_25.wo_tgt;
assign pkt_con_if_26.wi_data = pkt_con_if_25.wo_data;
assign pkt_con_if_25.wo_rdy = pkt_con_if_26.wi_rdy;

assign pkt_con_if_26.si_vld = pkt_con_if_34.so_vld;
assign pkt_con_if_26.si_qos = pkt_con_if_34.so_qos;
assign pkt_con_if_26.si_type = pkt_con_if_34.so_type;
assign pkt_con_if_26.si_src = pkt_con_if_34.so_src;
assign pkt_con_if_26.si_tgt = pkt_con_if_34.so_tgt;
assign pkt_con_if_26.si_data = pkt_con_if_34.so_data;
assign pkt_con_if_34.so_rdy = pkt_con_if_26.si_rdy;

assign pkt_con_if_26.ei_vld = pkt_con_if_27.eo_vld;
assign pkt_con_if_26.ei_qos = pkt_con_if_27.eo_qos;
assign pkt_con_if_26.ei_type = pkt_con_if_27.eo_type;
assign pkt_con_if_26.ei_src = pkt_con_if_27.eo_src;
assign pkt_con_if_26.ei_tgt = pkt_con_if_27.eo_tgt;
assign pkt_con_if_26.ei_data = pkt_con_if_27.eo_data;
assign pkt_con_if_27.eo_rdy = pkt_con_if_26.ei_rdy;

// Node 27 (3,3) - Interior: all 4 connections
assign pkt_con_if_27.ni_vld = pkt_con_if_19.no_vld;
assign pkt_con_if_27.ni_qos = pkt_con_if_19.no_qos;
assign pkt_con_if_27.ni_type = pkt_con_if_19.no_type;
assign pkt_con_if_27.ni_src = pkt_con_if_19.no_src;
assign pkt_con_if_27.ni_tgt = pkt_con_if_19.no_tgt;
assign pkt_con_if_27.ni_data = pkt_con_if_19.no_data;
assign pkt_con_if_19.no_rdy = pkt_con_if_27.ni_rdy;

assign pkt_con_if_27.wi_vld = pkt_con_if_26.wo_vld;
assign pkt_con_if_27.wi_qos = pkt_con_if_26.wo_qos;
assign pkt_con_if_27.wi_type = pkt_con_if_26.wo_type;
assign pkt_con_if_27.wi_src = pkt_con_if_26.wo_src;
assign pkt_con_if_27.wi_tgt = pkt_con_if_26.wo_tgt;
assign pkt_con_if_27.wi_data = pkt_con_if_26.wo_data;
assign pkt_con_if_26.wo_rdy = pkt_con_if_27.wi_rdy;

assign pkt_con_if_27.si_vld = pkt_con_if_35.so_vld;
assign pkt_con_if_27.si_qos = pkt_con_if_35.so_qos;
assign pkt_con_if_27.si_type = pkt_con_if_35.so_type;
assign pkt_con_if_27.si_src = pkt_con_if_35.so_src;
assign pkt_con_if_27.si_tgt = pkt_con_if_35.so_tgt;
assign pkt_con_if_27.si_data = pkt_con_if_35.so_data;
assign pkt_con_if_35.so_rdy = pkt_con_if_27.si_rdy;

assign pkt_con_if_27.ei_vld = pkt_con_if_28.eo_vld;
assign pkt_con_if_27.ei_qos = pkt_con_if_28.eo_qos;
assign pkt_con_if_27.ei_type = pkt_con_if_28.eo_type;
assign pkt_con_if_27.ei_src = pkt_con_if_28.eo_src;
assign pkt_con_if_27.ei_tgt = pkt_con_if_28.eo_tgt;
assign pkt_con_if_27.ei_data = pkt_con_if_28.eo_data;
assign pkt_con_if_28.eo_rdy = pkt_con_if_27.ei_rdy;

// Node 28 (4,3) - Interior: all 4 connections
assign pkt_con_if_28.ni_vld = pkt_con_if_20.no_vld;
assign pkt_con_if_28.ni_qos = pkt_con_if_20.no_qos;
assign pkt_con_if_28.ni_type = pkt_con_if_20.no_type;
assign pkt_con_if_28.ni_src = pkt_con_if_20.no_src;
assign pkt_con_if_28.ni_tgt = pkt_con_if_20.no_tgt;
assign pkt_con_if_28.ni_data = pkt_con_if_20.no_data;
assign pkt_con_if_20.no_rdy = pkt_con_if_28.ni_rdy;

assign pkt_con_if_28.wi_vld = pkt_con_if_27.wo_vld;
assign pkt_con_if_28.wi_qos = pkt_con_if_27.wo_qos;
assign pkt_con_if_28.wi_type = pkt_con_if_27.wo_type;
assign pkt_con_if_28.wi_src = pkt_con_if_27.wo_src;
assign pkt_con_if_28.wi_tgt = pkt_con_if_27.wo_tgt;
assign pkt_con_if_28.wi_data = pkt_con_if_27.wo_data;
assign pkt_con_if_27.wo_rdy = pkt_con_if_28.wi_rdy;

assign pkt_con_if_28.si_vld = pkt_con_if_36.so_vld;
assign pkt_con_if_28.si_qos = pkt_con_if_36.so_qos;
assign pkt_con_if_28.si_type = pkt_con_if_36.so_type;
assign pkt_con_if_28.si_src = pkt_con_if_36.so_src;
assign pkt_con_if_28.si_tgt = pkt_con_if_36.so_tgt;
assign pkt_con_if_28.si_data = pkt_con_if_36.so_data;
assign pkt_con_if_36.so_rdy = pkt_con_if_28.si_rdy;

assign pkt_con_if_28.ei_vld = pkt_con_if_29.eo_vld;
assign pkt_con_if_28.ei_qos = pkt_con_if_29.eo_qos;
assign pkt_con_if_28.ei_type = pkt_con_if_29.eo_type;
assign pkt_con_if_28.ei_src = pkt_con_if_29.eo_src;
assign pkt_con_if_28.ei_tgt = pkt_con_if_29.eo_tgt;
assign pkt_con_if_28.ei_data = pkt_con_if_29.eo_data;
assign pkt_con_if_29.eo_rdy = pkt_con_if_28.ei_rdy;

// Node 29 (5,3) - Interior: all 4 connections
assign pkt_con_if_29.ni_vld = pkt_con_if_21.no_vld;
assign pkt_con_if_29.ni_qos = pkt_con_if_21.no_qos;
assign pkt_con_if_29.ni_type = pkt_con_if_21.no_type;
assign pkt_con_if_29.ni_src = pkt_con_if_21.no_src;
assign pkt_con_if_29.ni_tgt = pkt_con_if_21.no_tgt;
assign pkt_con_if_29.ni_data = pkt_con_if_21.no_data;
assign pkt_con_if_21.no_rdy = pkt_con_if_29.ni_rdy;

assign pkt_con_if_29.wi_vld = pkt_con_if_28.wo_vld;
assign pkt_con_if_29.wi_qos = pkt_con_if_28.wo_qos;
assign pkt_con_if_29.wi_type = pkt_con_if_28.wo_type;
assign pkt_con_if_29.wi_src = pkt_con_if_28.wo_src;
assign pkt_con_if_29.wi_tgt = pkt_con_if_28.wo_tgt;
assign pkt_con_if_29.wi_data = pkt_con_if_28.wo_data;
assign pkt_con_if_28.wo_rdy = pkt_con_if_29.wi_rdy;

assign pkt_con_if_29.si_vld = pkt_con_if_37.so_vld;
assign pkt_con_if_29.si_qos = pkt_con_if_37.so_qos;
assign pkt_con_if_29.si_type = pkt_con_if_37.so_type;
assign pkt_con_if_29.si_src = pkt_con_if_37.so_src;
assign pkt_con_if_29.si_tgt = pkt_con_if_37.so_tgt;
assign pkt_con_if_29.si_data = pkt_con_if_37.so_data;
assign pkt_con_if_37.so_rdy = pkt_con_if_29.si_rdy;

assign pkt_con_if_29.ei_vld = pkt_con_if_30.eo_vld;
assign pkt_con_if_29.ei_qos = pkt_con_if_30.eo_qos;
assign pkt_con_if_29.ei_type = pkt_con_if_30.eo_type;
assign pkt_con_if_29.ei_src = pkt_con_if_30.eo_src;
assign pkt_con_if_29.ei_tgt = pkt_con_if_30.eo_tgt;
assign pkt_con_if_29.ei_data = pkt_con_if_30.eo_data;
assign pkt_con_if_30.eo_rdy = pkt_con_if_29.ei_rdy;

// Node 30 (6,3) - Interior: all 4 connections
assign pkt_con_if_30.ni_vld = pkt_con_if_22.no_vld;
assign pkt_con_if_30.ni_qos = pkt_con_if_22.no_qos;
assign pkt_con_if_30.ni_type = pkt_con_if_22.no_type;
assign pkt_con_if_30.ni_src = pkt_con_if_22.no_src;
assign pkt_con_if_30.ni_tgt = pkt_con_if_22.no_tgt;
assign pkt_con_if_30.ni_data = pkt_con_if_22.no_data;
assign pkt_con_if_22.no_rdy = pkt_con_if_30.ni_rdy;

assign pkt_con_if_30.wi_vld = pkt_con_if_29.wo_vld;
assign pkt_con_if_30.wi_qos = pkt_con_if_29.wo_qos;
assign pkt_con_if_30.wi_type = pkt_con_if_29.wo_type;
assign pkt_con_if_30.wi_src = pkt_con_if_29.wo_src;
assign pkt_con_if_30.wi_tgt = pkt_con_if_29.wo_tgt;
assign pkt_con_if_30.wi_data = pkt_con_if_29.wo_data;
assign pkt_con_if_29.wo_rdy = pkt_con_if_30.wi_rdy;

assign pkt_con_if_30.si_vld = pkt_con_if_38.so_vld;
assign pkt_con_if_30.si_qos = pkt_con_if_38.so_qos;
assign pkt_con_if_30.si_type = pkt_con_if_38.so_type;
assign pkt_con_if_30.si_src = pkt_con_if_38.so_src;
assign pkt_con_if_30.si_tgt = pkt_con_if_38.so_tgt;
assign pkt_con_if_30.si_data = pkt_con_if_38.so_data;
assign pkt_con_if_38.so_rdy = pkt_con_if_30.si_rdy;

assign pkt_con_if_30.ei_vld = pkt_con_if_31.eo_vld;
assign pkt_con_if_30.ei_qos = pkt_con_if_31.eo_qos;
assign pkt_con_if_30.ei_type = pkt_con_if_31.eo_type;
assign pkt_con_if_30.ei_src = pkt_con_if_31.eo_src;
assign pkt_con_if_30.ei_tgt = pkt_con_if_31.eo_tgt;
assign pkt_con_if_30.ei_data = pkt_con_if_31.eo_data;
assign pkt_con_if_31.eo_rdy = pkt_con_if_30.ei_rdy;

// Node 31 (7,3) - Right edge: no East connection
assign pkt_con_if_31.ni_vld = pkt_con_if_23.no_vld;
assign pkt_con_if_31.ni_qos = pkt_con_if_23.no_qos;
assign pkt_con_if_31.ni_type = pkt_con_if_23.no_type;
assign pkt_con_if_31.ni_src = pkt_con_if_23.no_src;
assign pkt_con_if_31.ni_tgt = pkt_con_if_23.no_tgt;
assign pkt_con_if_31.ni_data = pkt_con_if_23.no_data;
assign pkt_con_if_23.no_rdy = pkt_con_if_31.ni_rdy;

assign pkt_con_if_31.wi_vld = pkt_con_if_30.wo_vld;
assign pkt_con_if_31.wi_qos = pkt_con_if_30.wo_qos;
assign pkt_con_if_31.wi_type = pkt_con_if_30.wo_type;
assign pkt_con_if_31.wi_src = pkt_con_if_30.wo_src;
assign pkt_con_if_31.wi_tgt = pkt_con_if_30.wo_tgt;
assign pkt_con_if_31.wi_data = pkt_con_if_30.wo_data;
assign pkt_con_if_30.wo_rdy = pkt_con_if_31.wi_rdy;

assign pkt_con_if_31.si_vld = pkt_con_if_39.so_vld;
assign pkt_con_if_31.si_qos = pkt_con_if_39.so_qos;
assign pkt_con_if_31.si_type = pkt_con_if_39.so_type;
assign pkt_con_if_31.si_src = pkt_con_if_39.so_src;
assign pkt_con_if_31.si_tgt = pkt_con_if_39.so_tgt;
assign pkt_con_if_31.si_data = pkt_con_if_39.so_data;
assign pkt_con_if_39.so_rdy = pkt_con_if_31.si_rdy;

assign pkt_con_if_31.ei_vld = 1'b0;
assign pkt_con_if_31.ei_qos = 1'b0;
assign pkt_con_if_31.ei_type = 2'b00;
assign pkt_con_if_31.ei_src = 6'b000000;
assign pkt_con_if_31.ei_tgt = 6'b000000;
assign pkt_con_if_31.ei_data = 8'b00000000;

// Rows 4-7 (nodes 32-63): Continue the same pattern for all remaining nodes
// Following the established pattern: corner nodes (2 connections), edge nodes (3 connections), interior nodes (4 connections)
// Complete explicit connections for all remaining nodes 32-63

// Row 4 (nodes 32-39)
// Node 32 (0,4) - Left edge: no West
assign pkt_con_if_32.wi_vld = 1'b0; assign pkt_con_if_32.wi_qos = 1'b0; assign pkt_con_if_32.wi_type = 2'b00;
assign pkt_con_if_32.wi_src = 6'b000000; assign pkt_con_if_32.wi_tgt = 6'b000000; assign pkt_con_if_32.wi_data = 8'b00000000;
assign pkt_con_if_32.ni_vld = pkt_con_if_24.no_vld; assign pkt_con_if_32.ni_qos = pkt_con_if_24.no_qos;
assign pkt_con_if_32.ni_type = pkt_con_if_24.no_type; assign pkt_con_if_32.ni_src = pkt_con_if_24.no_src;
assign pkt_con_if_32.ni_tgt = pkt_con_if_24.no_tgt; assign pkt_con_if_32.ni_data = pkt_con_if_24.no_data; assign pkt_con_if_24.no_rdy = pkt_con_if_32.ni_rdy;
assign pkt_con_if_32.si_vld = pkt_con_if_40.so_vld; assign pkt_con_if_32.si_qos = pkt_con_if_40.so_qos;
assign pkt_con_if_32.si_type = pkt_con_if_40.so_type; assign pkt_con_if_32.si_src = pkt_con_if_40.so_src;
assign pkt_con_if_32.si_tgt = pkt_con_if_40.so_tgt; assign pkt_con_if_32.si_data = pkt_con_if_40.so_data; assign pkt_con_if_40.so_rdy = pkt_con_if_32.si_rdy;
assign pkt_con_if_32.ei_vld = pkt_con_if_33.eo_vld; assign pkt_con_if_32.ei_qos = pkt_con_if_33.eo_qos;
assign pkt_con_if_32.ei_type = pkt_con_if_33.eo_type; assign pkt_con_if_32.ei_src = pkt_con_if_33.eo_src;
assign pkt_con_if_32.ei_tgt = pkt_con_if_33.eo_tgt; assign pkt_con_if_32.ei_data = pkt_con_if_33.eo_data; assign pkt_con_if_33.eo_rdy = pkt_con_if_32.ei_rdy;

// Node 33 (1,4) - Interior: all 4 connections
assign pkt_con_if_33.ni_vld = pkt_con_if_25.no_vld; assign pkt_con_if_33.ni_qos = pkt_con_if_25.no_qos; assign pkt_con_if_33.ni_type = pkt_con_if_25.no_type;
assign pkt_con_if_33.ni_src = pkt_con_if_25.no_src; assign pkt_con_if_33.ni_tgt = pkt_con_if_25.no_tgt; assign pkt_con_if_33.ni_data = pkt_con_if_25.no_data; assign pkt_con_if_25.no_rdy = pkt_con_if_33.ni_rdy;
assign pkt_con_if_33.wi_vld = pkt_con_if_32.wo_vld; assign pkt_con_if_33.wi_qos = pkt_con_if_32.wo_qos; assign pkt_con_if_33.wi_type = pkt_con_if_32.wo_type;
assign pkt_con_if_33.wi_src = pkt_con_if_32.wo_src; assign pkt_con_if_33.wi_tgt = pkt_con_if_32.wo_tgt; assign pkt_con_if_33.wi_data = pkt_con_if_32.wo_data; assign pkt_con_if_32.wo_rdy = pkt_con_if_33.wi_rdy;
assign pkt_con_if_33.si_vld = pkt_con_if_41.so_vld; assign pkt_con_if_33.si_qos = pkt_con_if_41.so_qos; assign pkt_con_if_33.si_type = pkt_con_if_41.so_type;
assign pkt_con_if_33.si_src = pkt_con_if_41.so_src; assign pkt_con_if_33.si_tgt = pkt_con_if_41.so_tgt; assign pkt_con_if_33.si_data = pkt_con_if_41.so_data; assign pkt_con_if_41.so_rdy = pkt_con_if_33.si_rdy;
assign pkt_con_if_33.ei_vld = pkt_con_if_34.eo_vld; assign pkt_con_if_33.ei_qos = pkt_con_if_34.eo_qos; assign pkt_con_if_33.ei_type = pkt_con_if_34.eo_type;
assign pkt_con_if_33.ei_src = pkt_con_if_34.eo_src; assign pkt_con_if_33.ei_tgt = pkt_con_if_34.eo_tgt; assign pkt_con_if_33.ei_data = pkt_con_if_34.eo_data; assign pkt_con_if_34.eo_rdy = pkt_con_if_33.ei_rdy;

// Node 34 (2,4) - Interior: all 4 connections
assign pkt_con_if_34.ni_vld = pkt_con_if_26.no_vld; assign pkt_con_if_34.ni_qos = pkt_con_if_26.no_qos; assign pkt_con_if_34.ni_type = pkt_con_if_26.no_type;
assign pkt_con_if_34.ni_src = pkt_con_if_26.no_src; assign pkt_con_if_34.ni_tgt = pkt_con_if_26.no_tgt; assign pkt_con_if_34.ni_data = pkt_con_if_26.no_data; assign pkt_con_if_26.no_rdy = pkt_con_if_34.ni_rdy;
assign pkt_con_if_34.wi_vld = pkt_con_if_33.wo_vld; assign pkt_con_if_34.wi_qos = pkt_con_if_33.wo_qos; assign pkt_con_if_34.wi_type = pkt_con_if_33.wo_type;
assign pkt_con_if_34.wi_src = pkt_con_if_33.wo_src; assign pkt_con_if_34.wi_tgt = pkt_con_if_33.wo_tgt; assign pkt_con_if_34.wi_data = pkt_con_if_33.wo_data; assign pkt_con_if_33.wo_rdy = pkt_con_if_34.wi_rdy;
assign pkt_con_if_34.si_vld = pkt_con_if_42.so_vld; assign pkt_con_if_34.si_qos = pkt_con_if_42.so_qos; assign pkt_con_if_34.si_type = pkt_con_if_42.so_type;
assign pkt_con_if_34.si_src = pkt_con_if_42.so_src; assign pkt_con_if_34.si_tgt = pkt_con_if_42.so_tgt; assign pkt_con_if_34.si_data = pkt_con_if_42.so_data; assign pkt_con_if_42.so_rdy = pkt_con_if_34.si_rdy;
assign pkt_con_if_34.ei_vld = pkt_con_if_35.eo_vld; assign pkt_con_if_34.ei_qos = pkt_con_if_35.eo_qos; assign pkt_con_if_34.ei_type = pkt_con_if_35.eo_type;
assign pkt_con_if_34.ei_src = pkt_con_if_35.eo_src; assign pkt_con_if_34.ei_tgt = pkt_con_if_35.eo_tgt; assign pkt_con_if_34.ei_data = pkt_con_if_35.eo_data; assign pkt_con_if_35.eo_rdy = pkt_con_if_34.ei_rdy;

// Node 35 (3,4) - Interior: all 4 connections
assign pkt_con_if_35.ni_vld = pkt_con_if_27.no_vld; assign pkt_con_if_35.ni_qos = pkt_con_if_27.no_qos; assign pkt_con_if_35.ni_type = pkt_con_if_27.no_type;
assign pkt_con_if_35.ni_src = pkt_con_if_27.no_src; assign pkt_con_if_35.ni_tgt = pkt_con_if_27.no_tgt; assign pkt_con_if_35.ni_data = pkt_con_if_27.no_data; assign pkt_con_if_27.no_rdy = pkt_con_if_35.ni_rdy;
assign pkt_con_if_35.wi_vld = pkt_con_if_34.wo_vld; assign pkt_con_if_35.wi_qos = pkt_con_if_34.wo_qos; assign pkt_con_if_35.wi_type = pkt_con_if_34.wo_type;
assign pkt_con_if_35.wi_src = pkt_con_if_34.wo_src; assign pkt_con_if_35.wi_tgt = pkt_con_if_34.wo_tgt; assign pkt_con_if_35.wi_data = pkt_con_if_34.wo_data; assign pkt_con_if_34.wo_rdy = pkt_con_if_35.wi_rdy;
assign pkt_con_if_35.si_vld = pkt_con_if_43.so_vld; assign pkt_con_if_35.si_qos = pkt_con_if_43.so_qos; assign pkt_con_if_35.si_type = pkt_con_if_43.so_type;
assign pkt_con_if_35.si_src = pkt_con_if_43.so_src; assign pkt_con_if_35.si_tgt = pkt_con_if_43.so_tgt; assign pkt_con_if_35.si_data = pkt_con_if_43.so_data; assign pkt_con_if_43.so_rdy = pkt_con_if_35.si_rdy;
assign pkt_con_if_35.ei_vld = pkt_con_if_36.eo_vld; assign pkt_con_if_35.ei_qos = pkt_con_if_36.eo_qos; assign pkt_con_if_35.ei_type = pkt_con_if_36.eo_type;
assign pkt_con_if_35.ei_src = pkt_con_if_36.eo_src; assign pkt_con_if_35.ei_tgt = pkt_con_if_36.eo_tgt; assign pkt_con_if_35.ei_data = pkt_con_if_36.eo_data; assign pkt_con_if_36.eo_rdy = pkt_con_if_35.ei_rdy;

// Node 36 (4,4) - Interior: all 4 connections
assign pkt_con_if_36.ni_vld = pkt_con_if_28.no_vld; assign pkt_con_if_36.ni_qos = pkt_con_if_28.no_qos; assign pkt_con_if_36.ni_type = pkt_con_if_28.no_type;
assign pkt_con_if_36.ni_src = pkt_con_if_28.no_src; assign pkt_con_if_36.ni_tgt = pkt_con_if_28.no_tgt; assign pkt_con_if_36.ni_data = pkt_con_if_28.no_data; assign pkt_con_if_28.no_rdy = pkt_con_if_36.ni_rdy;
assign pkt_con_if_36.wi_vld = pkt_con_if_35.wo_vld; assign pkt_con_if_36.wi_qos = pkt_con_if_35.wo_qos; assign pkt_con_if_36.wi_type = pkt_con_if_35.wo_type;
assign pkt_con_if_36.wi_src = pkt_con_if_35.wo_src; assign pkt_con_if_36.wi_tgt = pkt_con_if_35.wo_tgt; assign pkt_con_if_36.wi_data = pkt_con_if_35.wo_data; assign pkt_con_if_35.wo_rdy = pkt_con_if_36.wi_rdy;
assign pkt_con_if_36.si_vld = pkt_con_if_44.so_vld; assign pkt_con_if_36.si_qos = pkt_con_if_44.so_qos; assign pkt_con_if_36.si_type = pkt_con_if_44.so_type;
assign pkt_con_if_36.si_src = pkt_con_if_44.so_src; assign pkt_con_if_36.si_tgt = pkt_con_if_44.so_tgt; assign pkt_con_if_36.si_data = pkt_con_if_44.so_data; assign pkt_con_if_44.so_rdy = pkt_con_if_36.si_rdy;
assign pkt_con_if_36.ei_vld = pkt_con_if_37.eo_vld; assign pkt_con_if_36.ei_qos = pkt_con_if_37.eo_qos; assign pkt_con_if_36.ei_type = pkt_con_if_37.eo_type;
assign pkt_con_if_36.ei_src = pkt_con_if_37.eo_src; assign pkt_con_if_36.ei_tgt = pkt_con_if_37.eo_tgt; assign pkt_con_if_36.ei_data = pkt_con_if_37.eo_data; assign pkt_con_if_37.eo_rdy = pkt_con_if_36.ei_rdy;

// Node 37 (5,4) - Interior: all 4 connections
assign pkt_con_if_37.ni_vld = pkt_con_if_29.no_vld; assign pkt_con_if_37.ni_qos = pkt_con_if_29.no_qos; assign pkt_con_if_37.ni_type = pkt_con_if_29.no_type;
assign pkt_con_if_37.ni_src = pkt_con_if_29.no_src; assign pkt_con_if_37.ni_tgt = pkt_con_if_29.no_tgt; assign pkt_con_if_37.ni_data = pkt_con_if_29.no_data; assign pkt_con_if_29.no_rdy = pkt_con_if_37.ni_rdy;
assign pkt_con_if_37.wi_vld = pkt_con_if_36.wo_vld; assign pkt_con_if_37.wi_qos = pkt_con_if_36.wo_qos; assign pkt_con_if_37.wi_type = pkt_con_if_36.wo_type;
assign pkt_con_if_37.wi_src = pkt_con_if_36.wo_src; assign pkt_con_if_37.wi_tgt = pkt_con_if_36.wo_tgt; assign pkt_con_if_37.wi_data = pkt_con_if_36.wo_data; assign pkt_con_if_36.wo_rdy = pkt_con_if_37.wi_rdy;
assign pkt_con_if_37.si_vld = pkt_con_if_45.so_vld; assign pkt_con_if_37.si_qos = pkt_con_if_45.so_qos; assign pkt_con_if_37.si_type = pkt_con_if_45.so_type;
assign pkt_con_if_37.si_src = pkt_con_if_45.so_src; assign pkt_con_if_37.si_tgt = pkt_con_if_45.so_tgt; assign pkt_con_if_37.si_data = pkt_con_if_45.so_data; assign pkt_con_if_45.so_rdy = pkt_con_if_37.si_rdy;
assign pkt_con_if_37.ei_vld = pkt_con_if_38.eo_vld; assign pkt_con_if_37.ei_qos = pkt_con_if_38.eo_qos; assign pkt_con_if_37.ei_type = pkt_con_if_38.eo_type;
assign pkt_con_if_37.ei_src = pkt_con_if_38.eo_src; assign pkt_con_if_37.ei_tgt = pkt_con_if_38.eo_tgt; assign pkt_con_if_37.ei_data = pkt_con_if_38.eo_data; assign pkt_con_if_38.eo_rdy = pkt_con_if_37.ei_rdy;

// Node 38 (6,4) - Interior: all 4 connections
assign pkt_con_if_38.ni_vld = pkt_con_if_30.no_vld; assign pkt_con_if_38.ni_qos = pkt_con_if_30.no_qos; assign pkt_con_if_38.ni_type = pkt_con_if_30.no_type;
assign pkt_con_if_38.ni_src = pkt_con_if_30.no_src; assign pkt_con_if_38.ni_tgt = pkt_con_if_30.no_tgt; assign pkt_con_if_38.ni_data = pkt_con_if_30.no_data; assign pkt_con_if_30.no_rdy = pkt_con_if_38.ni_rdy;
assign pkt_con_if_38.wi_vld = pkt_con_if_37.wo_vld; assign pkt_con_if_38.wi_qos = pkt_con_if_37.wo_qos; assign pkt_con_if_38.wi_type = pkt_con_if_37.wo_type;
assign pkt_con_if_38.wi_src = pkt_con_if_37.wo_src; assign pkt_con_if_38.wi_tgt = pkt_con_if_37.wo_tgt; assign pkt_con_if_38.wi_data = pkt_con_if_37.wo_data; assign pkt_con_if_37.wo_rdy = pkt_con_if_38.wi_rdy;
assign pkt_con_if_38.si_vld = pkt_con_if_46.so_vld; assign pkt_con_if_38.si_qos = pkt_con_if_46.so_qos; assign pkt_con_if_38.si_type = pkt_con_if_46.so_type;
assign pkt_con_if_38.si_src = pkt_con_if_46.so_src; assign pkt_con_if_38.si_tgt = pkt_con_if_46.so_tgt; assign pkt_con_if_38.si_data = pkt_con_if_46.so_data; assign pkt_con_if_46.so_rdy = pkt_con_if_38.si_rdy;
assign pkt_con_if_38.ei_vld = pkt_con_if_39.eo_vld; assign pkt_con_if_38.ei_qos = pkt_con_if_39.eo_qos; assign pkt_con_if_38.ei_type = pkt_con_if_39.eo_type;
assign pkt_con_if_38.ei_src = pkt_con_if_39.eo_src; assign pkt_con_if_38.ei_tgt = pkt_con_if_39.eo_tgt; assign pkt_con_if_38.ei_data = pkt_con_if_39.eo_data; assign pkt_con_if_39.eo_rdy = pkt_con_if_38.ei_rdy;

// Node 39 (7,4) - Right edge: no East
assign pkt_con_if_39.ni_vld = pkt_con_if_31.no_vld; assign pkt_con_if_39.ni_qos = pkt_con_if_31.no_qos; assign pkt_con_if_39.ni_type = pkt_con_if_31.no_type;
assign pkt_con_if_39.ni_src = pkt_con_if_31.no_src; assign pkt_con_if_39.ni_tgt = pkt_con_if_31.no_tgt; assign pkt_con_if_39.ni_data = pkt_con_if_31.no_data; assign pkt_con_if_31.no_rdy = pkt_con_if_39.ni_rdy;
assign pkt_con_if_39.wi_vld = pkt_con_if_38.wo_vld; assign pkt_con_if_39.wi_qos = pkt_con_if_38.wo_qos; assign pkt_con_if_39.wi_type = pkt_con_if_38.wo_type;
assign pkt_con_if_39.wi_src = pkt_con_if_38.wo_src; assign pkt_con_if_39.wi_tgt = pkt_con_if_38.wo_tgt; assign pkt_con_if_39.wi_data = pkt_con_if_38.wo_data; assign pkt_con_if_38.wo_rdy = pkt_con_if_39.wi_rdy;
assign pkt_con_if_39.si_vld = pkt_con_if_47.so_vld; assign pkt_con_if_39.si_qos = pkt_con_if_47.so_qos; assign pkt_con_if_39.si_type = pkt_con_if_47.so_type;
assign pkt_con_if_39.si_src = pkt_con_if_47.so_src; assign pkt_con_if_39.si_tgt = pkt_con_if_47.so_tgt; assign pkt_con_if_39.si_data = pkt_con_if_47.so_data; assign pkt_con_if_47.so_rdy = pkt_con_if_39.si_rdy;
assign pkt_con_if_39.ei_vld = 1'b0; assign pkt_con_if_39.ei_qos = 1'b0; assign pkt_con_if_39.ei_type = 2'b00;
assign pkt_con_if_39.ei_src = 6'b000000; assign pkt_con_if_39.ei_tgt = 6'b000000; assign pkt_con_if_39.ei_data = 8'b00000000;

// Row 5 (nodes 40-47): Continue pattern
// Node 40 (0,5) - Left edge: no West
assign pkt_con_if_40.wi_vld = 1'b0; assign pkt_con_if_40.wi_qos = 1'b0; assign pkt_con_if_40.wi_type = 2'b00;
assign pkt_con_if_40.wi_src = 6'b000000; assign pkt_con_if_40.wi_tgt = 6'b000000; assign pkt_con_if_40.wi_data = 8'b00000000;
assign pkt_con_if_40.ni_vld = pkt_con_if_32.no_vld; assign pkt_con_if_40.ni_qos = pkt_con_if_32.no_qos;
assign pkt_con_if_40.ni_type = pkt_con_if_32.no_type; assign pkt_con_if_40.ni_src = pkt_con_if_32.no_src;
assign pkt_con_if_40.ni_tgt = pkt_con_if_32.no_tgt; assign pkt_con_if_40.ni_data = pkt_con_if_32.no_data; assign pkt_con_if_32.no_rdy = pkt_con_if_40.ni_rdy;
assign pkt_con_if_40.si_vld = pkt_con_if_48.so_vld; assign pkt_con_if_40.si_qos = pkt_con_if_48.so_qos;
assign pkt_con_if_40.si_type = pkt_con_if_48.so_type; assign pkt_con_if_40.si_src = pkt_con_if_48.so_src;
assign pkt_con_if_40.si_tgt = pkt_con_if_48.so_tgt; assign pkt_con_if_40.si_data = pkt_con_if_48.so_data; assign pkt_con_if_48.so_rdy = pkt_con_if_40.si_rdy;
assign pkt_con_if_40.ei_vld = pkt_con_if_41.eo_vld; assign pkt_con_if_40.ei_qos = pkt_con_if_41.eo_qos;
assign pkt_con_if_40.ei_type = pkt_con_if_41.eo_type; assign pkt_con_if_40.ei_src = pkt_con_if_41.eo_src;
assign pkt_con_if_40.ei_tgt = pkt_con_if_41.eo_tgt; assign pkt_con_if_40.ei_data = pkt_con_if_41.eo_data; assign pkt_con_if_41.eo_rdy = pkt_con_if_40.ei_rdy;

// Node 41 (1,5) - Interior: all 4 connections
assign pkt_con_if_41.ni_vld = pkt_con_if_33.no_vld; assign pkt_con_if_41.ni_qos = pkt_con_if_33.no_qos; assign pkt_con_if_41.ni_type = pkt_con_if_33.no_type;
assign pkt_con_if_41.ni_src = pkt_con_if_33.no_src; assign pkt_con_if_41.ni_tgt = pkt_con_if_33.no_tgt; assign pkt_con_if_41.ni_data = pkt_con_if_33.no_data; assign pkt_con_if_33.no_rdy = pkt_con_if_41.ni_rdy;
assign pkt_con_if_41.wi_vld = pkt_con_if_40.wo_vld; assign pkt_con_if_41.wi_qos = pkt_con_if_40.wo_qos; assign pkt_con_if_41.wi_type = pkt_con_if_40.wo_type;
assign pkt_con_if_41.wi_src = pkt_con_if_40.wo_src; assign pkt_con_if_41.wi_tgt = pkt_con_if_40.wo_tgt; assign pkt_con_if_41.wi_data = pkt_con_if_40.wo_data; assign pkt_con_if_40.wo_rdy = pkt_con_if_41.wi_rdy;
assign pkt_con_if_41.si_vld = pkt_con_if_49.so_vld; assign pkt_con_if_41.si_qos = pkt_con_if_49.so_qos; assign pkt_con_if_41.si_type = pkt_con_if_49.so_type;
assign pkt_con_if_41.si_src = pkt_con_if_49.so_src; assign pkt_con_if_41.si_tgt = pkt_con_if_49.so_tgt; assign pkt_con_if_41.si_data = pkt_con_if_49.so_data; assign pkt_con_if_49.so_rdy = pkt_con_if_41.si_rdy;
assign pkt_con_if_41.ei_vld = pkt_con_if_42.eo_vld; assign pkt_con_if_41.ei_qos = pkt_con_if_42.eo_qos; assign pkt_con_if_41.ei_type = pkt_con_if_42.eo_type;
assign pkt_con_if_41.ei_src = pkt_con_if_42.eo_src; assign pkt_con_if_41.ei_tgt = pkt_con_if_42.eo_tgt; assign pkt_con_if_41.ei_data = pkt_con_if_42.eo_data; assign pkt_con_if_42.eo_rdy = pkt_con_if_41.ei_rdy;

// Node 42 (2,5) - Interior: all 4 connections
assign pkt_con_if_42.ni_vld = pkt_con_if_34.no_vld; assign pkt_con_if_42.ni_qos = pkt_con_if_34.no_qos; assign pkt_con_if_42.ni_type = pkt_con_if_34.no_type;
assign pkt_con_if_42.ni_src = pkt_con_if_34.no_src; assign pkt_con_if_42.ni_tgt = pkt_con_if_34.no_tgt; assign pkt_con_if_42.ni_data = pkt_con_if_34.no_data; assign pkt_con_if_34.no_rdy = pkt_con_if_42.ni_rdy;
assign pkt_con_if_42.wi_vld = pkt_con_if_41.wo_vld; assign pkt_con_if_42.wi_qos = pkt_con_if_41.wo_qos; assign pkt_con_if_42.wi_type = pkt_con_if_41.wo_type;
assign pkt_con_if_42.wi_src = pkt_con_if_41.wo_src; assign pkt_con_if_42.wi_tgt = pkt_con_if_41.wo_tgt; assign pkt_con_if_42.wi_data = pkt_con_if_41.wo_data; assign pkt_con_if_41.wo_rdy = pkt_con_if_42.wi_rdy;
assign pkt_con_if_42.si_vld = pkt_con_if_50.so_vld; assign pkt_con_if_42.si_qos = pkt_con_if_50.so_qos; assign pkt_con_if_42.si_type = pkt_con_if_50.so_type;
assign pkt_con_if_42.si_src = pkt_con_if_50.so_src; assign pkt_con_if_42.si_tgt = pkt_con_if_50.so_tgt; assign pkt_con_if_42.si_data = pkt_con_if_50.so_data; assign pkt_con_if_50.so_rdy = pkt_con_if_42.si_rdy;
assign pkt_con_if_42.ei_vld = pkt_con_if_43.eo_vld; assign pkt_con_if_42.ei_qos = pkt_con_if_43.eo_qos; assign pkt_con_if_42.ei_type = pkt_con_if_43.eo_type;
assign pkt_con_if_42.ei_src = pkt_con_if_43.eo_src; assign pkt_con_if_42.ei_tgt = pkt_con_if_43.eo_tgt; assign pkt_con_if_42.ei_data = pkt_con_if_43.eo_data; assign pkt_con_if_43.eo_rdy = pkt_con_if_42.ei_rdy;

// Node 43 (3,5) - Interior: all 4 connections
assign pkt_con_if_43.ni_vld = pkt_con_if_35.no_vld; assign pkt_con_if_43.ni_qos = pkt_con_if_35.no_qos; assign pkt_con_if_43.ni_type = pkt_con_if_35.no_type;
assign pkt_con_if_43.ni_src = pkt_con_if_35.no_src; assign pkt_con_if_43.ni_tgt = pkt_con_if_35.no_tgt; assign pkt_con_if_43.ni_data = pkt_con_if_35.no_data; assign pkt_con_if_35.no_rdy = pkt_con_if_43.ni_rdy;
assign pkt_con_if_43.wi_vld = pkt_con_if_42.wo_vld; assign pkt_con_if_43.wi_qos = pkt_con_if_42.wo_qos; assign pkt_con_if_43.wi_type = pkt_con_if_42.wo_type;
assign pkt_con_if_43.wi_src = pkt_con_if_42.wo_src; assign pkt_con_if_43.wi_tgt = pkt_con_if_42.wo_tgt; assign pkt_con_if_43.wi_data = pkt_con_if_42.wo_data; assign pkt_con_if_42.wo_rdy = pkt_con_if_43.wi_rdy;
assign pkt_con_if_43.si_vld = pkt_con_if_51.so_vld; assign pkt_con_if_43.si_qos = pkt_con_if_51.so_qos; assign pkt_con_if_43.si_type = pkt_con_if_51.so_type;
assign pkt_con_if_43.si_src = pkt_con_if_51.so_src; assign pkt_con_if_43.si_tgt = pkt_con_if_51.so_tgt; assign pkt_con_if_43.si_data = pkt_con_if_51.so_data; assign pkt_con_if_51.so_rdy = pkt_con_if_43.si_rdy;
assign pkt_con_if_43.ei_vld = pkt_con_if_44.eo_vld; assign pkt_con_if_43.ei_qos = pkt_con_if_44.eo_qos; assign pkt_con_if_43.ei_type = pkt_con_if_44.eo_type;
assign pkt_con_if_43.ei_src = pkt_con_if_44.eo_src; assign pkt_con_if_43.ei_tgt = pkt_con_if_44.eo_tgt; assign pkt_con_if_43.ei_data = pkt_con_if_44.eo_data; assign pkt_con_if_44.eo_rdy = pkt_con_if_43.ei_rdy;

// Node 44 (4,5) - Interior: all 4 connections
assign pkt_con_if_44.ni_vld = pkt_con_if_36.no_vld; assign pkt_con_if_44.ni_qos = pkt_con_if_36.no_qos; assign pkt_con_if_44.ni_type = pkt_con_if_36.no_type;
assign pkt_con_if_44.ni_src = pkt_con_if_36.no_src; assign pkt_con_if_44.ni_tgt = pkt_con_if_36.no_tgt; assign pkt_con_if_44.ni_data = pkt_con_if_36.no_data; assign pkt_con_if_36.no_rdy = pkt_con_if_44.ni_rdy;
assign pkt_con_if_44.wi_vld = pkt_con_if_43.wo_vld; assign pkt_con_if_44.wi_qos = pkt_con_if_43.wo_qos; assign pkt_con_if_44.wi_type = pkt_con_if_43.wo_type;
assign pkt_con_if_44.wi_src = pkt_con_if_43.wo_src; assign pkt_con_if_44.wi_tgt = pkt_con_if_43.wo_tgt; assign pkt_con_if_44.wi_data = pkt_con_if_43.wo_data; assign pkt_con_if_43.wo_rdy = pkt_con_if_44.wi_rdy;
assign pkt_con_if_44.si_vld = pkt_con_if_52.so_vld; assign pkt_con_if_44.si_qos = pkt_con_if_52.so_qos; assign pkt_con_if_44.si_type = pkt_con_if_52.so_type;
assign pkt_con_if_44.si_src = pkt_con_if_52.so_src; assign pkt_con_if_44.si_tgt = pkt_con_if_52.so_tgt; assign pkt_con_if_44.si_data = pkt_con_if_52.so_data; assign pkt_con_if_52.so_rdy = pkt_con_if_44.si_rdy;
assign pkt_con_if_44.ei_vld = pkt_con_if_45.eo_vld; assign pkt_con_if_44.ei_qos = pkt_con_if_45.eo_qos; assign pkt_con_if_44.ei_type = pkt_con_if_45.eo_type;
assign pkt_con_if_44.ei_src = pkt_con_if_45.eo_src; assign pkt_con_if_44.ei_tgt = pkt_con_if_45.eo_tgt; assign pkt_con_if_44.ei_data = pkt_con_if_45.eo_data; assign pkt_con_if_45.eo_rdy = pkt_con_if_44.ei_rdy;

// Node 45 (5,5) - Interior: all 4 connections
assign pkt_con_if_45.ni_vld = pkt_con_if_37.no_vld; assign pkt_con_if_45.ni_qos = pkt_con_if_37.no_qos; assign pkt_con_if_45.ni_type = pkt_con_if_37.no_type;
assign pkt_con_if_45.ni_src = pkt_con_if_37.no_src; assign pkt_con_if_45.ni_tgt = pkt_con_if_37.no_tgt; assign pkt_con_if_45.ni_data = pkt_con_if_37.no_data; assign pkt_con_if_37.no_rdy = pkt_con_if_45.ni_rdy;
assign pkt_con_if_45.wi_vld = pkt_con_if_44.wo_vld; assign pkt_con_if_45.wi_qos = pkt_con_if_44.wo_qos; assign pkt_con_if_45.wi_type = pkt_con_if_44.wo_type;
assign pkt_con_if_45.wi_src = pkt_con_if_44.wo_src; assign pkt_con_if_45.wi_tgt = pkt_con_if_44.wo_tgt; assign pkt_con_if_45.wi_data = pkt_con_if_44.wo_data; assign pkt_con_if_44.wo_rdy = pkt_con_if_45.wi_rdy;
assign pkt_con_if_45.si_vld = pkt_con_if_53.so_vld; assign pkt_con_if_45.si_qos = pkt_con_if_53.so_qos; assign pkt_con_if_45.si_type = pkt_con_if_53.so_type;
assign pkt_con_if_45.si_src = pkt_con_if_53.so_src; assign pkt_con_if_45.si_tgt = pkt_con_if_53.so_tgt; assign pkt_con_if_45.si_data = pkt_con_if_53.so_data; assign pkt_con_if_53.so_rdy = pkt_con_if_45.si_rdy;
assign pkt_con_if_45.ei_vld = pkt_con_if_46.eo_vld; assign pkt_con_if_45.ei_qos = pkt_con_if_46.eo_qos; assign pkt_con_if_45.ei_type = pkt_con_if_46.eo_type;
assign pkt_con_if_45.ei_src = pkt_con_if_46.eo_src; assign pkt_con_if_45.ei_tgt = pkt_con_if_46.eo_tgt; assign pkt_con_if_45.ei_data = pkt_con_if_46.eo_data; assign pkt_con_if_46.eo_rdy = pkt_con_if_45.ei_rdy;

// Node 46 (6,5) - Interior: all 4 connections
assign pkt_con_if_46.ni_vld = pkt_con_if_38.no_vld; assign pkt_con_if_46.ni_qos = pkt_con_if_38.no_qos; assign pkt_con_if_46.ni_type = pkt_con_if_38.no_type;
assign pkt_con_if_46.ni_src = pkt_con_if_38.no_src; assign pkt_con_if_46.ni_tgt = pkt_con_if_38.no_tgt; assign pkt_con_if_46.ni_data = pkt_con_if_38.no_data; assign pkt_con_if_38.no_rdy = pkt_con_if_46.ni_rdy;
assign pkt_con_if_46.wi_vld = pkt_con_if_45.wo_vld; assign pkt_con_if_46.wi_qos = pkt_con_if_45.wo_qos; assign pkt_con_if_46.wi_type = pkt_con_if_45.wo_type;
assign pkt_con_if_46.wi_src = pkt_con_if_45.wo_src; assign pkt_con_if_46.wi_tgt = pkt_con_if_45.wo_tgt; assign pkt_con_if_46.wi_data = pkt_con_if_45.wo_data; assign pkt_con_if_45.wo_rdy = pkt_con_if_46.wi_rdy;
assign pkt_con_if_46.si_vld = pkt_con_if_54.so_vld; assign pkt_con_if_46.si_qos = pkt_con_if_54.so_qos; assign pkt_con_if_46.si_type = pkt_con_if_54.so_type;
assign pkt_con_if_46.si_src = pkt_con_if_54.so_src; assign pkt_con_if_46.si_tgt = pkt_con_if_54.so_tgt; assign pkt_con_if_46.si_data = pkt_con_if_54.so_data; assign pkt_con_if_54.so_rdy = pkt_con_if_46.si_rdy;
assign pkt_con_if_46.ei_vld = pkt_con_if_47.eo_vld; assign pkt_con_if_46.ei_qos = pkt_con_if_47.eo_qos; assign pkt_con_if_46.ei_type = pkt_con_if_47.eo_type;
assign pkt_con_if_46.ei_src = pkt_con_if_47.eo_src; assign pkt_con_if_46.ei_tgt = pkt_con_if_47.eo_tgt; assign pkt_con_if_46.ei_data = pkt_con_if_47.eo_data; assign pkt_con_if_47.eo_rdy = pkt_con_if_46.ei_rdy;

// Node 47 (7,5) - Right edge: no East
assign pkt_con_if_47.ni_vld = pkt_con_if_39.no_vld; assign pkt_con_if_47.ni_qos = pkt_con_if_39.no_qos; assign pkt_con_if_47.ni_type = pkt_con_if_39.no_type;
assign pkt_con_if_47.ni_src = pkt_con_if_39.no_src; assign pkt_con_if_47.ni_tgt = pkt_con_if_39.no_tgt; assign pkt_con_if_47.ni_data = pkt_con_if_39.no_data; assign pkt_con_if_39.no_rdy = pkt_con_if_47.ni_rdy;
assign pkt_con_if_47.wi_vld = pkt_con_if_46.wo_vld; assign pkt_con_if_47.wi_qos = pkt_con_if_46.wo_qos; assign pkt_con_if_47.wi_type = pkt_con_if_46.wo_type;
assign pkt_con_if_47.wi_src = pkt_con_if_46.wo_src; assign pkt_con_if_47.wi_tgt = pkt_con_if_46.wo_tgt; assign pkt_con_if_47.wi_data = pkt_con_if_46.wo_data; assign pkt_con_if_46.wo_rdy = pkt_con_if_47.wi_rdy;
assign pkt_con_if_47.si_vld = pkt_con_if_55.so_vld; assign pkt_con_if_47.si_qos = pkt_con_if_55.so_qos; assign pkt_con_if_47.si_type = pkt_con_if_55.so_type;
assign pkt_con_if_47.si_src = pkt_con_if_55.so_src; assign pkt_con_if_47.si_tgt = pkt_con_if_55.so_tgt; assign pkt_con_if_47.si_data = pkt_con_if_55.so_data; assign pkt_con_if_55.so_rdy = pkt_con_if_47.si_rdy;
assign pkt_con_if_47.ei_vld = 1'b0; assign pkt_con_if_47.ei_qos = 1'b0; assign pkt_con_if_47.ei_type = 2'b00;
assign pkt_con_if_47.ei_src = 6'b000000; assign pkt_con_if_47.ei_tgt = 6'b000000; assign pkt_con_if_47.ei_data = 8'b00000000;

// Row 6 (nodes 48-55): Continue pattern
// Node 48 (0,6) - Left edge: no West
assign pkt_con_if_48.wi_vld = 1'b0; assign pkt_con_if_48.wi_qos = 1'b0; assign pkt_con_if_48.wi_type = 2'b00;
assign pkt_con_if_48.wi_src = 6'b000000; assign pkt_con_if_48.wi_tgt = 6'b000000; assign pkt_con_if_48.wi_data = 8'b00000000;
assign pkt_con_if_48.ni_vld = pkt_con_if_40.no_vld; assign pkt_con_if_48.ni_qos = pkt_con_if_40.no_qos;
assign pkt_con_if_48.ni_type = pkt_con_if_40.no_type; assign pkt_con_if_48.ni_src = pkt_con_if_40.no_src;
assign pkt_con_if_48.ni_tgt = pkt_con_if_40.no_tgt; assign pkt_con_if_48.ni_data = pkt_con_if_40.no_data; assign pkt_con_if_40.no_rdy = pkt_con_if_48.ni_rdy;
assign pkt_con_if_48.si_vld = pkt_con_if_56.so_vld; assign pkt_con_if_48.si_qos = pkt_con_if_56.so_qos;
assign pkt_con_if_48.si_type = pkt_con_if_56.so_type; assign pkt_con_if_48.si_src = pkt_con_if_56.so_src;
assign pkt_con_if_48.si_tgt = pkt_con_if_56.so_tgt; assign pkt_con_if_48.si_data = pkt_con_if_56.so_data; assign pkt_con_if_56.so_rdy = pkt_con_if_48.si_rdy;
assign pkt_con_if_48.ei_vld = pkt_con_if_49.eo_vld; assign pkt_con_if_48.ei_qos = pkt_con_if_49.eo_qos;
assign pkt_con_if_48.ei_type = pkt_con_if_49.eo_type; assign pkt_con_if_48.ei_src = pkt_con_if_49.eo_src;
assign pkt_con_if_48.ei_tgt = pkt_con_if_49.eo_tgt; assign pkt_con_if_48.ei_data = pkt_con_if_49.eo_data; assign pkt_con_if_49.eo_rdy = pkt_con_if_48.ei_rdy;

// Node 49 (1,6) - Interior: all 4 connections
assign pkt_con_if_49.ni_vld = pkt_con_if_41.no_vld; assign pkt_con_if_49.ni_qos = pkt_con_if_41.no_qos; assign pkt_con_if_49.ni_type = pkt_con_if_41.no_type;
assign pkt_con_if_49.ni_src = pkt_con_if_41.no_src; assign pkt_con_if_49.ni_tgt = pkt_con_if_41.no_tgt; assign pkt_con_if_49.ni_data = pkt_con_if_41.no_data; assign pkt_con_if_41.no_rdy = pkt_con_if_49.ni_rdy;
assign pkt_con_if_49.wi_vld = pkt_con_if_48.wo_vld; assign pkt_con_if_49.wi_qos = pkt_con_if_48.wo_qos; assign pkt_con_if_49.wi_type = pkt_con_if_48.wo_type;
assign pkt_con_if_49.wi_src = pkt_con_if_48.wo_src; assign pkt_con_if_49.wi_tgt = pkt_con_if_48.wo_tgt; assign pkt_con_if_49.wi_data = pkt_con_if_48.wo_data; assign pkt_con_if_48.wo_rdy = pkt_con_if_49.wi_rdy;
assign pkt_con_if_49.si_vld = pkt_con_if_57.so_vld; assign pkt_con_if_49.si_qos = pkt_con_if_57.so_qos; assign pkt_con_if_49.si_type = pkt_con_if_57.so_type;
assign pkt_con_if_49.si_src = pkt_con_if_57.so_src; assign pkt_con_if_49.si_tgt = pkt_con_if_57.so_tgt; assign pkt_con_if_49.si_data = pkt_con_if_57.so_data; assign pkt_con_if_57.so_rdy = pkt_con_if_49.si_rdy;
assign pkt_con_if_49.ei_vld = pkt_con_if_50.eo_vld; assign pkt_con_if_49.ei_qos = pkt_con_if_50.eo_qos; assign pkt_con_if_49.ei_type = pkt_con_if_50.eo_type;
assign pkt_con_if_49.ei_src = pkt_con_if_50.eo_src; assign pkt_con_if_49.ei_tgt = pkt_con_if_50.eo_tgt; assign pkt_con_if_49.ei_data = pkt_con_if_50.eo_data; assign pkt_con_if_50.eo_rdy = pkt_con_if_49.ei_rdy;

// Node 50 (2,6) - Interior: all 4 connections
assign pkt_con_if_50.ni_vld = pkt_con_if_42.no_vld; assign pkt_con_if_50.ni_qos = pkt_con_if_42.no_qos; assign pkt_con_if_50.ni_type = pkt_con_if_42.no_type;
assign pkt_con_if_50.ni_src = pkt_con_if_42.no_src; assign pkt_con_if_50.ni_tgt = pkt_con_if_42.no_tgt; assign pkt_con_if_50.ni_data = pkt_con_if_42.no_data; assign pkt_con_if_42.no_rdy = pkt_con_if_50.ni_rdy;
assign pkt_con_if_50.wi_vld = pkt_con_if_49.wo_vld; assign pkt_con_if_50.wi_qos = pkt_con_if_49.wo_qos; assign pkt_con_if_50.wi_type = pkt_con_if_49.wo_type;
assign pkt_con_if_50.wi_src = pkt_con_if_49.wo_src; assign pkt_con_if_50.wi_tgt = pkt_con_if_49.wo_tgt; assign pkt_con_if_50.wi_data = pkt_con_if_49.wo_data; assign pkt_con_if_49.wo_rdy = pkt_con_if_50.wi_rdy;
assign pkt_con_if_50.si_vld = pkt_con_if_58.so_vld; assign pkt_con_if_50.si_qos = pkt_con_if_58.so_qos; assign pkt_con_if_50.si_type = pkt_con_if_58.so_type;
assign pkt_con_if_50.si_src = pkt_con_if_58.so_src; assign pkt_con_if_50.si_tgt = pkt_con_if_58.so_tgt; assign pkt_con_if_50.si_data = pkt_con_if_58.so_data; assign pkt_con_if_58.so_rdy = pkt_con_if_50.si_rdy;
assign pkt_con_if_50.ei_vld = pkt_con_if_51.eo_vld; assign pkt_con_if_50.ei_qos = pkt_con_if_51.eo_qos; assign pkt_con_if_50.ei_type = pkt_con_if_51.eo_type;
assign pkt_con_if_50.ei_src = pkt_con_if_51.eo_src; assign pkt_con_if_50.ei_tgt = pkt_con_if_51.eo_tgt; assign pkt_con_if_50.ei_data = pkt_con_if_51.eo_data; assign pkt_con_if_51.eo_rdy = pkt_con_if_50.ei_rdy;

// Node 51 (3,6) - Interior: all 4 connections
assign pkt_con_if_51.ni_vld = pkt_con_if_43.no_vld; assign pkt_con_if_51.ni_qos = pkt_con_if_43.no_qos; assign pkt_con_if_51.ni_type = pkt_con_if_43.no_type;
assign pkt_con_if_51.ni_src = pkt_con_if_43.no_src; assign pkt_con_if_51.ni_tgt = pkt_con_if_43.no_tgt; assign pkt_con_if_51.ni_data = pkt_con_if_43.no_data; assign pkt_con_if_43.no_rdy = pkt_con_if_51.ni_rdy;
assign pkt_con_if_51.wi_vld = pkt_con_if_50.wo_vld; assign pkt_con_if_51.wi_qos = pkt_con_if_50.wo_qos; assign pkt_con_if_51.wi_type = pkt_con_if_50.wo_type;
assign pkt_con_if_51.wi_src = pkt_con_if_50.wo_src; assign pkt_con_if_51.wi_tgt = pkt_con_if_50.wo_tgt; assign pkt_con_if_51.wi_data = pkt_con_if_50.wo_data; assign pkt_con_if_50.wo_rdy = pkt_con_if_51.wi_rdy;
assign pkt_con_if_51.si_vld = pkt_con_if_59.so_vld; assign pkt_con_if_51.si_qos = pkt_con_if_59.so_qos; assign pkt_con_if_51.si_type = pkt_con_if_59.so_type;
assign pkt_con_if_51.si_src = pkt_con_if_59.so_src; assign pkt_con_if_51.si_tgt = pkt_con_if_59.so_tgt; assign pkt_con_if_51.si_data = pkt_con_if_59.so_data; assign pkt_con_if_59.so_rdy = pkt_con_if_51.si_rdy;
assign pkt_con_if_51.ei_vld = pkt_con_if_52.eo_vld; assign pkt_con_if_51.ei_qos = pkt_con_if_52.eo_qos; assign pkt_con_if_51.ei_type = pkt_con_if_52.eo_type;
assign pkt_con_if_51.ei_src = pkt_con_if_52.eo_src; assign pkt_con_if_51.ei_tgt = pkt_con_if_52.eo_tgt; assign pkt_con_if_51.ei_data = pkt_con_if_52.eo_data; assign pkt_con_if_52.eo_rdy = pkt_con_if_51.ei_rdy;

// Node 52 (4,6) - Interior: all 4 connections
assign pkt_con_if_52.ni_vld = pkt_con_if_44.no_vld; assign pkt_con_if_52.ni_qos = pkt_con_if_44.no_qos; assign pkt_con_if_52.ni_type = pkt_con_if_44.no_type;
assign pkt_con_if_52.ni_src = pkt_con_if_44.no_src; assign pkt_con_if_52.ni_tgt = pkt_con_if_44.no_tgt; assign pkt_con_if_52.ni_data = pkt_con_if_44.no_data; assign pkt_con_if_44.no_rdy = pkt_con_if_52.ni_rdy;
assign pkt_con_if_52.wi_vld = pkt_con_if_51.wo_vld; assign pkt_con_if_52.wi_qos = pkt_con_if_51.wo_qos; assign pkt_con_if_52.wi_type = pkt_con_if_51.wo_type;
assign pkt_con_if_52.wi_src = pkt_con_if_51.wo_src; assign pkt_con_if_52.wi_tgt = pkt_con_if_51.wo_tgt; assign pkt_con_if_52.wi_data = pkt_con_if_51.wo_data; assign pkt_con_if_51.wo_rdy = pkt_con_if_52.wi_rdy;
assign pkt_con_if_52.si_vld = pkt_con_if_60.so_vld; assign pkt_con_if_52.si_qos = pkt_con_if_60.so_qos; assign pkt_con_if_52.si_type = pkt_con_if_60.so_type;
assign pkt_con_if_52.si_src = pkt_con_if_60.so_src; assign pkt_con_if_52.si_tgt = pkt_con_if_60.so_tgt; assign pkt_con_if_52.si_data = pkt_con_if_60.so_data; assign pkt_con_if_60.so_rdy = pkt_con_if_52.si_rdy;
assign pkt_con_if_52.ei_vld = pkt_con_if_53.eo_vld; assign pkt_con_if_52.ei_qos = pkt_con_if_53.eo_qos; assign pkt_con_if_52.ei_type = pkt_con_if_53.eo_type;
assign pkt_con_if_52.ei_src = pkt_con_if_53.eo_src; assign pkt_con_if_52.ei_tgt = pkt_con_if_53.eo_tgt; assign pkt_con_if_52.ei_data = pkt_con_if_53.eo_data; assign pkt_con_if_53.eo_rdy = pkt_con_if_52.ei_rdy;

// Node 53 (5,6) - Interior: all 4 connections
assign pkt_con_if_53.ni_vld = pkt_con_if_45.no_vld; assign pkt_con_if_53.ni_qos = pkt_con_if_45.no_qos; assign pkt_con_if_53.ni_type = pkt_con_if_45.no_type;
assign pkt_con_if_53.ni_src = pkt_con_if_45.no_src; assign pkt_con_if_53.ni_tgt = pkt_con_if_45.no_tgt; assign pkt_con_if_53.ni_data = pkt_con_if_45.no_data; assign pkt_con_if_45.no_rdy = pkt_con_if_53.ni_rdy;
assign pkt_con_if_53.wi_vld = pkt_con_if_52.wo_vld; assign pkt_con_if_53.wi_qos = pkt_con_if_52.wo_qos; assign pkt_con_if_53.wi_type = pkt_con_if_52.wo_type;
assign pkt_con_if_53.wi_src = pkt_con_if_52.wo_src; assign pkt_con_if_53.wi_tgt = pkt_con_if_52.wo_tgt; assign pkt_con_if_53.wi_data = pkt_con_if_52.wo_data; assign pkt_con_if_52.wo_rdy = pkt_con_if_53.wi_rdy;
assign pkt_con_if_53.si_vld = pkt_con_if_61.so_vld; assign pkt_con_if_53.si_qos = pkt_con_if_61.so_qos; assign pkt_con_if_53.si_type = pkt_con_if_61.so_type;
assign pkt_con_if_53.si_src = pkt_con_if_61.so_src; assign pkt_con_if_53.si_tgt = pkt_con_if_61.so_tgt; assign pkt_con_if_53.si_data = pkt_con_if_61.so_data; assign pkt_con_if_61.so_rdy = pkt_con_if_53.si_rdy;
assign pkt_con_if_53.ei_vld = pkt_con_if_54.eo_vld; assign pkt_con_if_53.ei_qos = pkt_con_if_54.eo_qos; assign pkt_con_if_53.ei_type = pkt_con_if_54.eo_type;
assign pkt_con_if_53.ei_src = pkt_con_if_54.eo_src; assign pkt_con_if_53.ei_tgt = pkt_con_if_54.eo_tgt; assign pkt_con_if_53.ei_data = pkt_con_if_54.eo_data; assign pkt_con_if_54.eo_rdy = pkt_con_if_53.ei_rdy;

// Node 54 (6,6) - Interior: all 4 connections
assign pkt_con_if_54.ni_vld = pkt_con_if_46.no_vld; assign pkt_con_if_54.ni_qos = pkt_con_if_46.no_qos; assign pkt_con_if_54.ni_type = pkt_con_if_46.no_type;
assign pkt_con_if_54.ni_src = pkt_con_if_46.no_src; assign pkt_con_if_54.ni_tgt = pkt_con_if_46.no_tgt; assign pkt_con_if_54.ni_data = pkt_con_if_46.no_data; assign pkt_con_if_46.no_rdy = pkt_con_if_54.ni_rdy;
assign pkt_con_if_54.wi_vld = pkt_con_if_53.wo_vld; assign pkt_con_if_54.wi_qos = pkt_con_if_53.wo_qos; assign pkt_con_if_54.wi_type = pkt_con_if_53.wo_type;
assign pkt_con_if_54.wi_src = pkt_con_if_53.wo_src; assign pkt_con_if_54.wi_tgt = pkt_con_if_53.wo_tgt; assign pkt_con_if_54.wi_data = pkt_con_if_53.wo_data; assign pkt_con_if_53.wo_rdy = pkt_con_if_54.wi_rdy;
assign pkt_con_if_54.si_vld = pkt_con_if_62.so_vld; assign pkt_con_if_54.si_qos = pkt_con_if_62.so_qos; assign pkt_con_if_54.si_type = pkt_con_if_62.so_type;
assign pkt_con_if_54.si_src = pkt_con_if_62.so_src; assign pkt_con_if_54.si_tgt = pkt_con_if_62.so_tgt; assign pkt_con_if_54.si_data = pkt_con_if_62.so_data; assign pkt_con_if_62.so_rdy = pkt_con_if_54.si_rdy;
assign pkt_con_if_54.ei_vld = pkt_con_if_55.eo_vld; assign pkt_con_if_54.ei_qos = pkt_con_if_55.eo_qos; assign pkt_con_if_54.ei_type = pkt_con_if_55.eo_type;
assign pkt_con_if_54.ei_src = pkt_con_if_55.eo_src; assign pkt_con_if_54.ei_tgt = pkt_con_if_55.eo_tgt; assign pkt_con_if_54.ei_data = pkt_con_if_55.eo_data; assign pkt_con_if_55.eo_rdy = pkt_con_if_54.ei_rdy;

// Node 55 (7,6) - Right edge: no East
assign pkt_con_if_55.ni_vld = pkt_con_if_47.no_vld; assign pkt_con_if_55.ni_qos = pkt_con_if_47.no_qos; assign pkt_con_if_55.ni_type = pkt_con_if_47.no_type;
assign pkt_con_if_55.ni_src = pkt_con_if_47.no_src; assign pkt_con_if_55.ni_tgt = pkt_con_if_47.no_tgt; assign pkt_con_if_55.ni_data = pkt_con_if_47.no_data; assign pkt_con_if_47.no_rdy = pkt_con_if_55.ni_rdy;
assign pkt_con_if_55.wi_vld = pkt_con_if_54.wo_vld; assign pkt_con_if_55.wi_qos = pkt_con_if_54.wo_qos; assign pkt_con_if_55.wi_type = pkt_con_if_54.wo_type;
assign pkt_con_if_55.wi_src = pkt_con_if_54.wo_src; assign pkt_con_if_55.wi_tgt = pkt_con_if_54.wo_tgt; assign pkt_con_if_55.wi_data = pkt_con_if_54.wo_data; assign pkt_con_if_54.wo_rdy = pkt_con_if_55.wi_rdy;
assign pkt_con_if_55.si_vld = pkt_con_if_63.so_vld; assign pkt_con_if_55.si_qos = pkt_con_if_63.so_qos; assign pkt_con_if_55.si_type = pkt_con_if_63.so_type;
assign pkt_con_if_55.si_src = pkt_con_if_63.so_src; assign pkt_con_if_55.si_tgt = pkt_con_if_63.so_tgt; assign pkt_con_if_55.si_data = pkt_con_if_63.so_data; assign pkt_con_if_63.so_rdy = pkt_con_if_55.si_rdy;
assign pkt_con_if_55.ei_vld = 1'b0; assign pkt_con_if_55.ei_qos = 1'b0; assign pkt_con_if_55.ei_type = 2'b00;
assign pkt_con_if_55.ei_src = 6'b000000; assign pkt_con_if_55.ei_tgt = 6'b000000; assign pkt_con_if_55.ei_data = 8'b00000000;

// Row 7 (nodes 56-63): Final row - bottom edge: no South connections
// Node 56 (0,7) - Bottom-left corner: only North and East
assign pkt_con_if_56.wi_vld = 1'b0; assign pkt_con_if_56.wi_qos = 1'b0; assign pkt_con_if_56.wi_type = 2'b00;
assign pkt_con_if_56.wi_src = 6'b000000; assign pkt_con_if_56.wi_tgt = 6'b000000; assign pkt_con_if_56.wi_data = 8'b00000000;
assign pkt_con_if_56.si_vld = 1'b0; assign pkt_con_if_56.si_qos = 1'b0; assign pkt_con_if_56.si_type = 2'b00;
assign pkt_con_if_56.si_src = 6'b000000; assign pkt_con_if_56.si_tgt = 6'b000000; assign pkt_con_if_56.si_data = 8'b00000000;
assign pkt_con_if_56.ni_vld = pkt_con_if_48.no_vld; assign pkt_con_if_56.ni_qos = pkt_con_if_48.no_qos;
assign pkt_con_if_56.ni_type = pkt_con_if_48.no_type; assign pkt_con_if_56.ni_src = pkt_con_if_48.no_src;
assign pkt_con_if_56.ni_tgt = pkt_con_if_48.no_tgt; assign pkt_con_if_56.ni_data = pkt_con_if_48.no_data; assign pkt_con_if_48.no_rdy = pkt_con_if_56.ni_rdy;
assign pkt_con_if_56.ei_vld = pkt_con_if_57.eo_vld; assign pkt_con_if_56.ei_qos = pkt_con_if_57.eo_qos;
assign pkt_con_if_56.ei_type = pkt_con_if_57.eo_type; assign pkt_con_if_56.ei_src = pkt_con_if_57.eo_src;
assign pkt_con_if_56.ei_tgt = pkt_con_if_57.eo_tgt; assign pkt_con_if_56.ei_data = pkt_con_if_57.eo_data; assign pkt_con_if_57.eo_rdy = pkt_con_if_56.ei_rdy;

// Node 57 (1,7) - Bottom edge: no South
assign pkt_con_if_57.si_vld = 1'b0; assign pkt_con_if_57.si_qos = 1'b0; assign pkt_con_if_57.si_type = 2'b00;
assign pkt_con_if_57.si_src = 6'b000000; assign pkt_con_if_57.si_tgt = 6'b000000; assign pkt_con_if_57.si_data = 8'b00000000;
assign pkt_con_if_57.ni_vld = pkt_con_if_49.no_vld; assign pkt_con_if_57.ni_qos = pkt_con_if_49.no_qos;
assign pkt_con_if_57.ni_type = pkt_con_if_49.no_type; assign pkt_con_if_57.ni_src = pkt_con_if_49.no_src;
assign pkt_con_if_57.ni_tgt = pkt_con_if_49.no_tgt; assign pkt_con_if_57.ni_data = pkt_con_if_49.no_data; assign pkt_con_if_49.no_rdy = pkt_con_if_57.ni_rdy;
assign pkt_con_if_57.wi_vld = pkt_con_if_56.wo_vld; assign pkt_con_if_57.wi_qos = pkt_con_if_56.wo_qos; assign pkt_con_if_57.wi_type = pkt_con_if_56.wo_type;
assign pkt_con_if_57.wi_src = pkt_con_if_56.wo_src; assign pkt_con_if_57.wi_tgt = pkt_con_if_56.wo_tgt; assign pkt_con_if_57.wi_data = pkt_con_if_56.wo_data; assign pkt_con_if_56.wo_rdy = pkt_con_if_57.wi_rdy;
assign pkt_con_if_57.ei_vld = pkt_con_if_58.eo_vld; assign pkt_con_if_57.ei_qos = pkt_con_if_58.eo_qos;
assign pkt_con_if_57.ei_type = pkt_con_if_58.eo_type; assign pkt_con_if_57.ei_src = pkt_con_if_58.eo_src;
assign pkt_con_if_57.ei_tgt = pkt_con_if_58.eo_tgt; assign pkt_con_if_57.ei_data = pkt_con_if_58.eo_data; assign pkt_con_if_58.eo_rdy = pkt_con_if_57.ei_rdy;

// Node 58 (2,7) - Bottom edge: no South
assign pkt_con_if_58.si_vld = 1'b0; assign pkt_con_if_58.si_qos = 1'b0; assign pkt_con_if_58.si_type = 2'b00;
assign pkt_con_if_58.si_src = 6'b000000; assign pkt_con_if_58.si_tgt = 6'b000000; assign pkt_con_if_58.si_data = 8'b00000000;
assign pkt_con_if_58.ni_vld = pkt_con_if_50.no_vld; assign pkt_con_if_58.ni_qos = pkt_con_if_50.no_qos;
assign pkt_con_if_58.ni_type = pkt_con_if_50.no_type; assign pkt_con_if_58.ni_src = pkt_con_if_50.no_src;
assign pkt_con_if_58.ni_tgt = pkt_con_if_50.no_tgt; assign pkt_con_if_58.ni_data = pkt_con_if_50.no_data; assign pkt_con_if_50.no_rdy = pkt_con_if_58.ni_rdy;
assign pkt_con_if_58.wi_vld = pkt_con_if_57.wo_vld; assign pkt_con_if_58.wi_qos = pkt_con_if_57.wo_qos; assign pkt_con_if_58.wi_type = pkt_con_if_57.wo_type;
assign pkt_con_if_58.wi_src = pkt_con_if_57.wo_src; assign pkt_con_if_58.wi_tgt = pkt_con_if_57.wo_tgt; assign pkt_con_if_58.wi_data = pkt_con_if_57.wo_data; assign pkt_con_if_57.wo_rdy = pkt_con_if_58.wi_rdy;
assign pkt_con_if_58.ei_vld = pkt_con_if_59.eo_vld; assign pkt_con_if_58.ei_qos = pkt_con_if_59.eo_qos;
assign pkt_con_if_58.ei_type = pkt_con_if_59.eo_type; assign pkt_con_if_58.ei_src = pkt_con_if_59.eo_src;
assign pkt_con_if_58.ei_tgt = pkt_con_if_59.eo_tgt; assign pkt_con_if_58.ei_data = pkt_con_if_59.eo_data; assign pkt_con_if_59.eo_rdy = pkt_con_if_58.ei_rdy;

// Node 59 (3,7) - Bottom edge: no South
assign pkt_con_if_59.si_vld = 1'b0; assign pkt_con_if_59.si_qos = 1'b0; assign pkt_con_if_59.si_type = 2'b00;
assign pkt_con_if_59.si_src = 6'b000000; assign pkt_con_if_59.si_tgt = 6'b000000; assign pkt_con_if_59.si_data = 8'b00000000;
assign pkt_con_if_59.ni_vld = pkt_con_if_51.no_vld; assign pkt_con_if_59.ni_qos = pkt_con_if_51.no_qos;
assign pkt_con_if_59.ni_type = pkt_con_if_51.no_type; assign pkt_con_if_59.ni_src = pkt_con_if_51.no_src;
assign pkt_con_if_59.ni_tgt = pkt_con_if_51.no_tgt; assign pkt_con_if_59.ni_data = pkt_con_if_51.no_data; assign pkt_con_if_51.no_rdy = pkt_con_if_59.ni_rdy;
assign pkt_con_if_59.wi_vld = pkt_con_if_58.wo_vld; assign pkt_con_if_59.wi_qos = pkt_con_if_58.wo_qos; assign pkt_con_if_59.wi_type = pkt_con_if_58.wo_type;
assign pkt_con_if_59.wi_src = pkt_con_if_58.wo_src; assign pkt_con_if_59.wi_tgt = pkt_con_if_58.wo_tgt; assign pkt_con_if_59.wi_data = pkt_con_if_58.wo_data; assign pkt_con_if_58.wo_rdy = pkt_con_if_59.wi_rdy;
assign pkt_con_if_59.ei_vld = pkt_con_if_60.eo_vld; assign pkt_con_if_59.ei_qos = pkt_con_if_60.eo_qos;
assign pkt_con_if_59.ei_type = pkt_con_if_60.eo_type; assign pkt_con_if_59.ei_src = pkt_con_if_60.eo_src;
assign pkt_con_if_59.ei_tgt = pkt_con_if_60.eo_tgt; assign pkt_con_if_59.ei_data = pkt_con_if_60.eo_data; assign pkt_con_if_60.eo_rdy = pkt_con_if_59.ei_rdy;

// Node 60 (4,7) - Bottom edge: no South
assign pkt_con_if_60.si_vld = 1'b0; assign pkt_con_if_60.si_qos = 1'b0; assign pkt_con_if_60.si_type = 2'b00;
assign pkt_con_if_60.si_src = 6'b000000; assign pkt_con_if_60.si_tgt = 6'b000000; assign pkt_con_if_60.si_data = 8'b00000000;
assign pkt_con_if_60.ni_vld = pkt_con_if_52.no_vld; assign pkt_con_if_60.ni_qos = pkt_con_if_52.no_qos;
assign pkt_con_if_60.ni_type = pkt_con_if_52.no_type; assign pkt_con_if_60.ni_src = pkt_con_if_52.no_src;
assign pkt_con_if_60.ni_tgt = pkt_con_if_52.no_tgt; assign pkt_con_if_60.ni_data = pkt_con_if_52.no_data; assign pkt_con_if_52.no_rdy = pkt_con_if_60.ni_rdy;
assign pkt_con_if_60.wi_vld = pkt_con_if_59.wo_vld; assign pkt_con_if_60.wi_qos = pkt_con_if_59.wo_qos; assign pkt_con_if_60.wi_type = pkt_con_if_59.wo_type;
assign pkt_con_if_60.wi_src = pkt_con_if_59.wo_src; assign pkt_con_if_60.wi_tgt = pkt_con_if_59.wo_tgt; assign pkt_con_if_60.wi_data = pkt_con_if_59.wo_data; assign pkt_con_if_59.wo_rdy = pkt_con_if_60.wi_rdy;
assign pkt_con_if_60.ei_vld = pkt_con_if_61.eo_vld; assign pkt_con_if_60.ei_qos = pkt_con_if_61.eo_qos;
assign pkt_con_if_60.ei_type = pkt_con_if_61.eo_type; assign pkt_con_if_60.ei_src = pkt_con_if_61.eo_src;
assign pkt_con_if_60.ei_tgt = pkt_con_if_61.eo_tgt; assign pkt_con_if_60.ei_data = pkt_con_if_61.eo_data; assign pkt_con_if_61.eo_rdy = pkt_con_if_60.ei_rdy;

// Node 61 (5,7) - Bottom edge: no South
assign pkt_con_if_61.si_vld = 1'b0; assign pkt_con_if_61.si_qos = 1'b0; assign pkt_con_if_61.si_type = 2'b00;
assign pkt_con_if_61.si_src = 6'b000000; assign pkt_con_if_61.si_tgt = 6'b000000; assign pkt_con_if_61.si_data = 8'b00000000;
assign pkt_con_if_61.ni_vld = pkt_con_if_53.no_vld; assign pkt_con_if_61.ni_qos = pkt_con_if_53.no_qos;
assign pkt_con_if_61.ni_type = pkt_con_if_53.no_type; assign pkt_con_if_61.ni_src = pkt_con_if_53.no_src;
assign pkt_con_if_61.ni_tgt = pkt_con_if_53.no_tgt; assign pkt_con_if_61.ni_data = pkt_con_if_53.no_data; assign pkt_con_if_53.no_rdy = pkt_con_if_61.ni_rdy;
assign pkt_con_if_61.wi_vld = pkt_con_if_60.wo_vld; assign pkt_con_if_61.wi_qos = pkt_con_if_60.wo_qos; assign pkt_con_if_61.wi_type = pkt_con_if_60.wo_type;
assign pkt_con_if_61.wi_src = pkt_con_if_60.wo_src; assign pkt_con_if_61.wi_tgt = pkt_con_if_60.wo_tgt; assign pkt_con_if_61.wi_data = pkt_con_if_60.wo_data; assign pkt_con_if_60.wo_rdy = pkt_con_if_61.wi_rdy;
assign pkt_con_if_61.ei_vld = pkt_con_if_62.eo_vld; assign pkt_con_if_61.ei_qos = pkt_con_if_62.eo_qos;
assign pkt_con_if_61.ei_type = pkt_con_if_62.eo_type; assign pkt_con_if_61.ei_src = pkt_con_if_62.eo_src;
assign pkt_con_if_61.ei_tgt = pkt_con_if_62.eo_tgt; assign pkt_con_if_61.ei_data = pkt_con_if_62.eo_data; assign pkt_con_if_62.eo_rdy = pkt_con_if_61.ei_rdy;

// Node 62 (6,7) - Bottom edge: no South
assign pkt_con_if_62.si_vld = 1'b0; assign pkt_con_if_62.si_qos = 1'b0; assign pkt_con_if_62.si_type = 2'b00;
assign pkt_con_if_62.si_src = 6'b000000; assign pkt_con_if_62.si_tgt = 6'b000000; assign pkt_con_if_62.si_data = 8'b00000000;
assign pkt_con_if_62.ni_vld = pkt_con_if_54.no_vld; assign pkt_con_if_62.ni_qos = pkt_con_if_54.no_qos;
assign pkt_con_if_62.ni_type = pkt_con_if_54.no_type; assign pkt_con_if_62.ni_src = pkt_con_if_54.no_src;
assign pkt_con_if_62.ni_tgt = pkt_con_if_54.no_tgt; assign pkt_con_if_62.ni_data = pkt_con_if_54.no_data; assign pkt_con_if_54.no_rdy = pkt_con_if_62.ni_rdy;
assign pkt_con_if_62.wi_vld = pkt_con_if_61.wo_vld; assign pkt_con_if_62.wi_qos = pkt_con_if_61.wo_qos; assign pkt_con_if_62.wi_type = pkt_con_if_61.wo_type;
assign pkt_con_if_62.wi_src = pkt_con_if_61.wo_src; assign pkt_con_if_62.wi_tgt = pkt_con_if_61.wo_tgt; assign pkt_con_if_62.wi_data = pkt_con_if_61.wo_data; assign pkt_con_if_61.wo_rdy = pkt_con_if_62.wi_rdy;
assign pkt_con_if_62.ei_vld = pkt_con_if_63.eo_vld; assign pkt_con_if_62.ei_qos = pkt_con_if_63.eo_qos;
assign pkt_con_if_62.ei_type = pkt_con_if_63.eo_type; assign pkt_con_if_62.ei_src = pkt_con_if_63.eo_src;
assign pkt_con_if_62.ei_tgt = pkt_con_if_63.eo_tgt; assign pkt_con_if_62.ei_data = pkt_con_if_63.eo_data; assign pkt_con_if_63.eo_rdy = pkt_con_if_62.ei_rdy;

// Node 63 (7,7) - Bottom-right corner: only North and West
assign pkt_con_if_63.wi_vld = 1'b0; assign pkt_con_if_63.wi_qos = 1'b0; assign pkt_con_if_63.wi_type = 2'b00;
assign pkt_con_if_63.wi_src = 6'b000000; assign pkt_con_if_63.wi_tgt = 6'b000000; assign pkt_con_if_63.wi_data = 8'b00000000;
assign pkt_con_if_63.si_vld = 1'b0; assign pkt_con_if_63.si_qos = 1'b0; assign pkt_con_if_63.si_type = 2'b00;
assign pkt_con_if_63.si_src = 6'b000000; assign pkt_con_if_63.si_tgt = 6'b000000; assign pkt_con_if_63.si_data = 8'b00000000;
assign pkt_con_if_63.ei_vld = 1'b0; assign pkt_con_if_63.ei_qos = 1'b0; assign pkt_con_if_63.ei_type = 2'b00;
assign pkt_con_if_63.ei_src = 6'b000000; assign pkt_con_if_63.ei_tgt = 6'b000000; assign pkt_con_if_63.ei_data = 8'b00000000;
assign pkt_con_if_63.ni_vld = pkt_con_if_55.no_vld; assign pkt_con_if_63.ni_qos = pkt_con_if_55.no_qos;
assign pkt_con_if_63.ni_type = pkt_con_if_55.no_type; assign pkt_con_if_63.ni_src = pkt_con_if_55.no_src;
assign pkt_con_if_63.ni_tgt = pkt_con_if_55.no_tgt; assign pkt_con_if_63.ni_data = pkt_con_if_55.no_data; assign pkt_con_if_55.no_rdy = pkt_con_if_63.ni_rdy;
//
// Generated Resources:
// - Direct connections: 64 nodes × 4 directions = 256 bidirectional connections
// - No intermediate buffers or routing logic
// - Zero added latency for direct node-to-node connections
//
// Connection Pattern (8×8 Mesh):
// Each node connects to up to 4 neighbors:
// - North: Node[x,y-1] if y > 0
// - South: Node[x,y+1] if y < 7
// - West:  Node[x-1,y] if x > 0
// - East:  Node[x+1,y] if x < 7
//
// Example Node Connections:
// - Corner nodes (4 nodes): Connect to 2 neighbors
//   * Node[0,0] (ID 0): ← Node[0,1], Node[1,0]
//   * Node[7,0] (ID 7): ← Node[7,1], Node[6,0]
//   * Node[0,7] (ID 56): ← Node[0,6], Node[1,7]
//   * Node[7,7] (ID 63): ← Node[7,6], Node[6,7]
//
// - Edge nodes (24 nodes): Connect to 3 neighbors
//   * Top edge (ID 1-6): ← West, East, South neighbors
//   * Bottom edge (ID 57-62): ← West, East, North neighbors
//   * Left edge (ID 8,16,24,32,40,48): ← North, South, East neighbors
//   * Right edge (ID 15,23,31,39,47,55): ← North, South, West neighbors
//
// - Interior nodes (36 nodes): Connect to 4 neighbors
//   * Example Node[3,4] (ID 28): ← Node[3,3], Node[3,5], Node[2,4], Node[4,4]
//
// Architecture Benefits:
// - True mesh topology with direct connections
// - No routing bottlenecks or intermediate delays
// - Zero additional latency beyond node internal processing
// - Simple boundary handling with tie-offs
// - Complete bidirectional communication with flow control
// - QoS and packet information preserved across all connections
// - Resource-efficient implementation (256 wires vs 896 IRS buffers)
//
// ====================================================================

endmodule : TOPO
