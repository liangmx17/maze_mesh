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

endmodule : TOPO
