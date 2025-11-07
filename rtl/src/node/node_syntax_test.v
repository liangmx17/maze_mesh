// Simple test to verify node module syntax without interface dependencies
// This tests the core routing logic functionality

// Mock interface definitions
`define QOS_W 1
`define ID_W 6
`define TYPE_W 2
`define FLIT_W 8

interface pkt_in;
    logic pkt_in_vld;
    logic pkt_in_qos;
    logic [1:0] pkt_in_type;
    logic [5:0] pkt_in_src;
    logic [5:0] pkt_in_tgt;
    logic [7:0] pkt_in_data;
    logic pkt_in_rdy;
    modport mst (input pkt_in_rdy, output pkt_in_vld, pkt_in_qos, pkt_in_type, pkt_in_src, pkt_in_tgt, pkt_in_data);
endinterface

interface pkt_out;
    logic pkt_out_vld;
    logic pkt_out_qos;
    logic [1:0] pkt_out_type;
    logic [5:0] pkt_out_src;
    logic [5:0] pkt_out_tgt;
    logic [7:0] pkt_out_data;
    logic pkt_out_rdy;
    modport mst (input pkt_out_rdy, output pkt_out_vld, pkt_out_qos, pkt_out_type, pkt_out_src, pkt_out_tgt, pkt_out_data);
endinterface

interface pkt_con_if;
    logic [6:0] x_vld, x_rdy;
    logic [6:0] x_qos;
    logic [1:0] x_type [6:0];
    logic [5:0] x_src [6:0];
    logic [5:0] x_tgt [6:0];
    logic [7:0] x_data [6:0];
    logic [6:0] y_vld, y_rdy;
    logic [6:0] y_qos;
    logic [1:0] y_type [6:0];
    logic [5:0] y_src [6:0];
    logic [5:0] y_tgt [6:0];
    logic [7:0] y_data [6:0];
    modport slv (input x_vld, x_qos, x_type, x_src, x_tgt, x_data, y_vld, y_qos, y_type, y_src, y_tgt, y_data, output x_rdy, y_rdy);
    modport mst (input x_rdy, y_rdy, output x_vld, x_qos, x_type, x_src, x_tgt, x_data, y_vld, y_qos, y_type, y_src, y_tgt, y_data);
endinterface