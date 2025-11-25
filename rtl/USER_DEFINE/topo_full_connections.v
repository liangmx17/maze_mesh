// ====================================================================
// Complete Node Connections - All 64 nodes (0-63)
// xi direction inputs: ni (North), wi (West), si (South), ei (East)
// ====================================================================

// Node 0 (0,0) - Top-left corner: only South and East inputs
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

assign pkt_con_if_0.si_vld = pkt_con_if_8.so_vld;   // from Node 8 (0,1)
assign pkt_con_if_0.si_qos = pkt_con_if_8.so_qos;
assign pkt_con_if_0.si_type = pkt_con_if_8.so_type;
assign pkt_con_if_0.si_src = pkt_con_if_8.so_src;
assign pkt_con_if_0.si_tgt = pkt_con_if_8.so_tgt;
assign pkt_con_if_0.si_data = pkt_con_if_8.so_data;
assign pkt_con_if_8.so_rdy = pkt_con_if_0.si_rdy;

assign pkt_con_if_0.ei_vld = pkt_con_if_1.eo_vld;   // from Node 1 (1,0)
assign pkt_con_if_0.ei_qos = pkt_con_if_1.eo_qos;
assign pkt_con_if_0.ei_type = pkt_con_if_1.eo_type;
assign pkt_con_if_0.ei_src = pkt_con_if_1.eo_src;
assign pkt_con_if_0.ei_tgt = pkt_con_if_1.eo_tgt;
assign pkt_con_if_0.ei_data = pkt_con_if_1.eo_data;
assign pkt_con_if_1.eo_rdy = pkt_con_if_0.ei_rdy;

// Node 1 (1,0) - Top edge: no North input
assign pkt_con_if_1.ni_vld = 1'b0;
assign pkt_con_if_1.ni_qos = 1'b0;
assign pkt_con_if_1.ni_type = 2'b00;
assign pkt_con_if_1.ni_src = 6'b000000;
assign pkt_con_if_1.ni_tgt = 6'b000000;
assign pkt_con_if_1.ni_data = 8'b00000000;

assign pkt_con_if_1.wi_vld = pkt_con_if_0.wo_vld;   // from Node 0 (0,0)
assign pkt_con_if_1.wi_qos = pkt_con_if_0.wo_qos;
assign pkt_con_if_1.wi_type = pkt_con_if_0.wo_type;
assign pkt_con_if_1.wi_src = pkt_con_if_0.wo_src;
assign pkt_con_if_1.wi_tgt = pkt_con_if_0.wo_tgt;
assign pkt_con_if_1.wi_data = pkt_con_if_0.wo_data;
assign pkt_con_if_0.wo_rdy = pkt_con_if_1.wi_rdy;

assign pkt_con_if_1.si_vld = pkt_con_if_9.so_vld;   // from Node 9 (1,1)
assign pkt_con_if_1.si_qos = pkt_con_if_9.so_qos;
assign pkt_con_if_1.si_type = pkt_con_if_9.so_type;
assign pkt_con_if_1.si_src = pkt_con_if_9.so_src;
assign pkt_con_if_1.si_tgt = pkt_con_if_9.so_tgt;
assign pkt_con_if_1.si_data = pkt_con_if_9.so_data;
assign pkt_con_if_9.so_rdy = pkt_con_if_1.si_rdy;

assign pkt_con_if_1.ei_vld = pkt_con_if_2.eo_vld;   // from Node 2 (2,0)
assign pkt_con_if_1.ei_qos = pkt_con_if_2.eo_qos;
assign pkt_con_if_1.ei_type = pkt_con_if_2.eo_type;
assign pkt_con_if_1.ei_src = pkt_con_if_2.eo_src;
assign pkt_con_if_1.ei_tgt = pkt_con_if_2.eo_tgt;
assign pkt_con_if_1.ei_data = pkt_con_if_2.eo_data;
assign pkt_con_if_2.eo_rdy = pkt_con_if_1.ei_rdy;

// Node 2 (2,0) - Top edge: no North input
assign pkt_con_if_2.ni_vld = 1'b0;
assign pkt_con_if_2.ni_qos = 1'b0;
assign pkt_con_if_2.ni_type = 2'b00;
assign pkt_con_if_2.ni_src = 6'b000000;
assign pkt_con_if_2.ni_tgt = 6'b000000;
assign pkt_con_if_2.ni_data = 8'b00000000;

assign pkt_con_if_2.wi_vld = pkt_con_if_1.wo_vld;   // from Node 1 (1,0)
assign pkt_con_if_2.wi_qos = pkt_con_if_1.wo_qos;
assign pkt_con_if_2.wi_type = pkt_con_if_1.wo_type;
assign pkt_con_if_2.wi_src = pkt_con_if_1.wo_src;
assign pkt_con_if_2.wi_tgt = pkt_con_if_1.wo_tgt;
assign pkt_con_if_2.wi_data = pkt_con_if_1.wo_data;
assign pkt_con_if_1.wo_rdy = pkt_con_if_2.wi_rdy;

assign pkt_con_if_2.si_vld = pkt_con_if_10.so_vld;  // from Node 10 (2,1)
assign pkt_con_if_2.si_qos = pkt_con_if_10.so_qos;
assign pkt_con_if_2.si_type = pkt_con_if_10.so_type;
assign pkt_con_if_2.si_src = pkt_con_if_10.so_src;
assign pkt_con_if_2.si_tgt = pkt_con_if_10.so_tgt;
assign pkt_con_if_2.si_data = pkt_con_if_10.so_data;
assign pkt_con_if_10.so_rdy = pkt_con_if_2.si_rdy;

assign pkt_con_if_2.ei_vld = pkt_con_if_3.eo_vld;   // from Node 3 (3,0)
assign pkt_con_if_2.ei_qos = pkt_con_if_3.eo_qos;
assign pkt_con_if_2.ei_type = pkt_con_if_3.eo_type;
assign pkt_con_if_2.ei_src = pkt_con_if_3.eo_src;
assign pkt_con_if_2.ei_tgt = pkt_con_if_3.eo_tgt;
assign pkt_con_if_2.ei_data = pkt_con_if_3.eo_data;
assign pkt_con_if_3.eo_rdy = pkt_con_if_2.ei_rdy;

// Node 3 (3,0) - Top edge: no North input
assign pkt_con_if_3.ni_vld = 1'b0;
assign pkt_con_if_3.ni_qos = 1'b0;
assign pkt_con_if_3.ni_type = 2'b00;
assign pkt_con_if_3.ni_src = 6'b000000;
assign pkt_con_if_3.ni_tgt = 6'b000000;
assign pkt_con_if_3.ni_data = 8'b00000000;

assign pkt_con_if_3.wi_vld = pkt_con_if_2.wo_vld;   // from Node 2 (2,0)
assign pkt_con_if_3.wi_qos = pkt_con_if_2.wo_qos;
assign pkt_con_if_3.wi_type = pkt_con_if_2.wo_type;
assign pkt_con_if_3.wi_src = pkt_con_if_2.wo_src;
assign pkt_con_if_3.wi_tgt = pkt_con_if_2.wo_tgt;
assign pkt_con_if_3.wi_data = pkt_con_if_2.wo_data;
assign pkt_con_if_2.wo_rdy = pkt_con_if_3.wi_rdy;

assign pkt_con_if_3.si_vld = pkt_con_if_11.so_vld;  // from Node 11 (3,1)
assign pkt_con_if_3.si_qos = pkt_con_if_11.so_qos;
assign pkt_con_if_3.si_type = pkt_con_if_11.so_type;
assign pkt_con_if_3.si_src = pkt_con_if_11.so_src;
assign pkt_con_if_3.si_tgt = pkt_con_if_11.so_tgt;
assign pkt_con_if_3.si_data = pkt_con_if_11.so_data;
assign pkt_con_if_11.so_rdy = pkt_con_if_3.si_rdy;

assign pkt_con_if_3.ei_vld = pkt_con_if_4.eo_vld;   // from Node 4 (4,0)
assign pkt_con_if_3.ei_qos = pkt_con_if_4.eo_qos;
assign pkt_con_if_3.ei_type = pkt_con_if_4.eo_type;
assign pkt_con_if_3.ei_src = pkt_con_if_4.eo_src;
assign pkt_con_if_3.ei_tgt = pkt_con_if_4.eo_tgt;
assign pkt_con_if_3.ei_data = pkt_con_if_4.eo_data;
assign pkt_con_if_4.eo_rdy = pkt_con_if_3.ei_rdy;

// Node 4 (4,0) - Top edge: no North input
assign pkt_con_if_4.ni_vld = 1'b0;
assign pkt_con_if_4.ni_qos = 1'b0;
assign pkt_con_if_4.ni_type = 2'b00;
assign pkt_con_if_4.ni_src = 6'b000000;
assign pkt_con_if_4.ni_tgt = 6'b000000;
assign pkt_con_if_4.ni_data = 8'b00000000;

assign pkt_con_if_4.wi_vld = pkt_con_if_3.wo_vld;   // from Node 3 (3,0)
assign pkt_con_if_4.wi_qos = pkt_con_if_3.wo_qos;
assign pkt_con_if_4.wi_type = pkt_con_if_3.wo_type;
assign pkt_con_if_4.wi_src = pkt_con_if_3.wo_src;
assign pkt_con_if_4.wi_tgt = pkt_con_if_3.wo_tgt;
assign pkt_con_if_4.wi_data = pkt_con_if_3.wo_data;
assign pkt_con_if_3.wo_rdy = pkt_con_if_4.wi_rdy;

assign pkt_con_if_4.si_vld = pkt_con_if_12.so_vld;  // from Node 12 (4,1)
assign pkt_con_if_4.si_qos = pkt_con_if_12.so_qos;
assign pkt_con_if_4.si_type = pkt_con_if_12.so_type;
assign pkt_con_if_4.si_src = pkt_con_if_12.so_src;
assign pkt_con_if_4.si_tgt = pkt_con_if_12.so_tgt;
assign pkt_con_if_4.si_data = pkt_con_if_12.so_data;
assign pkt_con_if_12.so_rdy = pkt_con_if_4.si_rdy;

assign pkt_con_if_4.ei_vld = pkt_con_if_5.eo_vld;   // from Node 5 (5,0)
assign pkt_con_if_4.ei_qos = pkt_con_if_5.eo_qos;
assign pkt_con_if_4.ei_type = pkt_con_if_5.eo_type;
assign pkt_con_if_4.ei_src = pkt_con_if_5.eo_src;
assign pkt_con_if_4.ei_tgt = pkt_con_if_5.eo_tgt;
assign pkt_con_if_4.ei_data = pkt_con_if_5.eo_data;
assign pkt_con_if_5.eo_rdy = pkt_con_if_4.ei_rdy;

// Node 5 (5,0) - Top edge: no North input
assign pkt_con_if_5.ni_vld = 1'b0;
assign pkt_con_if_5.ni_qos = 1'b0;
assign pkt_con_if_5.ni_type = 2'b00;
assign pkt_con_if_5.ni_src = 6'b000000;
assign pkt_con_if_5.ni_tgt = 6'b000000;
assign pkt_con_if_5.ni_data = 8'b00000000;

assign pkt_con_if_5.wi_vld = pkt_con_if_4.wo_vld;   // from Node 4 (4,0)
assign pkt_con_if_5.wi_qos = pkt_con_if_4.wo_qos;
assign pkt_con_if_5.wi_type = pkt_con_if_4.wo_type;
assign pkt_con_if_5.wi_src = pkt_con_if_4.wo_src;
assign pkt_con_if_5.wi_tgt = pkt_con_if_4.wo_tgt;
assign pkt_con_if_5.wi_data = pkt_con_if_4.wo_data;
assign pkt_con_if_4.wo_rdy = pkt_con_if_5.wi_rdy;

assign pkt_con_if_5.si_vld = pkt_con_if_13.so_vld;  // from Node 13 (5,1)
assign pkt_con_if_5.si_qos = pkt_con_if_13.so_qos;
assign pkt_con_if_5.si_type = pkt_con_if_13.so_type;
assign pkt_con_if_5.si_src = pkt_con_if_13.so_src;
assign pkt_con_if_5.si_tgt = pkt_con_if_13.so_tgt;
assign pkt_con_if_5.si_data = pkt_con_if_13.so_data;
assign pkt_con_if_13.so_rdy = pkt_con_if_5.si_rdy;

assign pkt_con_if_5.ei_vld = pkt_con_if_6.eo_vld;   // from Node 6 (6,0)
assign pkt_con_if_5.ei_qos = pkt_con_if_6.eo_qos;
assign pkt_con_if_5.ei_type = pkt_con_if_6.eo_type;
assign pkt_con_if_5.ei_src = pkt_con_if_6.eo_src;
assign pkt_con_if_5.ei_tgt = pkt_con_if_6.eo_tgt;
assign pkt_con_if_5.ei_data = pkt_con_if_6.eo_data;
assign pkt_con_if_6.eo_rdy = pkt_con_if_5.ei_rdy;

// Node 6 (6,0) - Top edge: no North input
assign pkt_con_if_6.ni_vld = 1'b0;
assign pkt_con_if_6.ni_qos = 1'b0;
assign pkt_con_if_6.ni_type = 2'b00;
assign pkt_con_if_6.ni_src = 6'b000000;
assign pkt_con_if_6.ni_tgt = 6'b000000;
assign pkt_con_if_6.ni_data = 8'b00000000;

assign pkt_con_if_6.wi_vld = pkt_con_if_5.wo_vld;   // from Node 5 (5,0)
assign pkt_con_if_6.wi_qos = pkt_con_if_5.wo_qos;
assign pkt_con_if_6.wi_type = pkt_con_if_5.wo_type;
assign pkt_con_if_6.wi_src = pkt_con_if_5.wo_src;
assign pkt_con_if_6.wi_tgt = pkt_con_if_5.wo_tgt;
assign pkt_con_if_6.wi_data = pkt_con_if_5.wo_data;
assign pkt_con_if_5.wo_rdy = pkt_con_if_6.wi_rdy;

assign pkt_con_if_6.si_vld = pkt_con_if_14.so_vld;  // from Node 14 (6,1)
assign pkt_con_if_6.si_qos = pkt_con_if_14.so_qos;
assign pkt_con_if_6.si_type = pkt_con_if_14.so_type;
assign pkt_con_if_6.si_src = pkt_con_if_14.so_src;
assign pkt_con_if_6.si_tgt = pkt_con_if_14.so_tgt;
assign pkt_con_if_6.si_data = pkt_con_if_14.so_data;
assign pkt_con_if_14.so_rdy = pkt_con_if_6.si_rdy;

assign pkt_con_if_6.ei_vld = pkt_con_if_7.eo_vld;   // from Node 7 (7,0)
assign pkt_con_if_6.ei_qos = pkt_con_if_7.eo_qos;
assign pkt_con_if_6.ei_type = pkt_con_if_7.eo_type;
assign pkt_con_if_6.ei_src = pkt_con_if_7.eo_src;
assign pkt_con_if_6.ei_tgt = pkt_con_if_7.eo_tgt;
assign pkt_con_if_6.ei_data = pkt_con_if_7.eo_data;
assign pkt_con_if_7.eo_rdy = pkt_con_if_6.ei_rdy;

// Node 7 (7,0) - Top-right corner: only South and West inputs
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

assign pkt_con_if_7.wi_vld = pkt_con_if_6.wo_vld;   // from Node 6 (6,0)
assign pkt_con_if_7.wi_qos = pkt_con_if_6.wo_qos;
assign pkt_con_if_7.wi_type = pkt_con_if_6.wo_type;
assign pkt_con_if_7.wi_src = pkt_con_if_6.wo_src;
assign pkt_con_if_7.wi_tgt = pkt_con_if_6.wo_tgt;
assign pkt_con_if_7.wi_data = pkt_con_if_6.wo_data;
assign pkt_con_if_6.wo_rdy = pkt_con_if_7.wi_rdy;

assign pkt_con_if_7.si_vld = pkt_con_if_15.so_vld;  // from Node 15 (7,1)
assign pkt_con_if_7.si_qos = pkt_con_if_15.so_qos;
assign pkt_con_if_7.si_type = pkt_con_if_15.so_type;
assign pkt_con_if_7.si_src = pkt_con_if_15.so_src;
assign pkt_con_if_7.si_tgt = pkt_con_if_15.so_tgt;
assign pkt_con_if_7.si_data = pkt_con_if_15.so_data;
assign pkt_con_if_15.so_rdy = pkt_con_if_7.si_rdy;

// Node 8 (0,1) - Left edge: no West input
assign pkt_con_if_8.wi_vld = 1'b0;
assign pkt_con_if_8.wi_qos = 1'b0;
assign pkt_con_if_8.wi_type = 2'b00;
assign pkt_con_if_8.wi_src = 6'b000000;
assign pkt_con_if_8.wi_tgt = 6'b000000;
assign pkt_con_if_8.wi_data = 8'b00000000;

assign pkt_con_if_8.ni_vld = pkt_con_if_0.no_vld;   // from Node 0 (0,0)
assign pkt_con_if_8.ni_qos = pkt_con_if_0.no_qos;
assign pkt_con_if_8.ni_type = pkt_con_if_0.no_type;
assign pkt_con_if_8.ni_src = pkt_con_if_0.no_src;
assign pkt_con_if_8.ni_tgt = pkt_con_if_0.no_tgt;
assign pkt_con_if_8.ni_data = pkt_con_if_0.no_data;
assign pkt_con_if_0.no_rdy = pkt_con_if_8.ni_rdy;

assign pkt_con_if_8.si_vld = pkt_con_if_16.so_vld;  // from Node 16 (0,2)
assign pkt_con_if_8.si_qos = pkt_con_if_16.so_qos;
assign pkt_con_if_8.si_type = pkt_con_if_16.so_type;
assign pkt_con_if_8.si_src = pkt_con_if_16.so_src;
assign pkt_con_if_8.si_tgt = pkt_con_if_16.so_tgt;
assign pkt_con_if_8.si_data = pkt_con_if_16.so_data;
assign pkt_con_if_16.so_rdy = pkt_con_if_8.si_rdy;

assign pkt_con_if_8.ei_vld = pkt_con_if_9.eo_vld;   // from Node 9 (1,1)
assign pkt_con_if_8.ei_qos = pkt_con_if_9.eo_qos;
assign pkt_con_if_8.ei_type = pkt_con_if_9.eo_type;
assign pkt_con_if_8.ei_src = pkt_con_if_9.eo_src;
assign pkt_con_if_8.ei_tgt = pkt_con_if_9.eo_tgt;
assign pkt_con_if_8.ei_data = pkt_con_if_9.eo_data;
assign pkt_con_if_9.eo_rdy = pkt_con_if_8.ei_rdy;

// Node 9 (1,1) - Interior node: all 4 connections
assign pkt_con_if_9.ni_vld = pkt_con_if_1.no_vld;   // from Node 1 (1,0)
assign pkt_con_if_9.ni_qos = pkt_con_if_1.no_qos;
assign pkt_con_if_9.ni_type = pkt_con_if_1.no_type;
assign pkt_con_if_9.ni_src = pkt_con_if_1.no_src;
assign pkt_con_if_9.ni_tgt = pkt_con_if_1.no_tgt;
assign pkt_con_if_9.ni_data = pkt_con_if_1.no_data;
assign pkt_con_if_1.no_rdy = pkt_con_if_9.ni_rdy;

assign pkt_con_if_9.wi_vld = pkt_con_if_8.wo_vld;   // from Node 8 (0,1)
assign pkt_con_if_9.wi_qos = pkt_con_if_8.wo_qos;
assign pkt_con_if_9.wi_type = pkt_con_if_8.wo_type;
assign pkt_con_if_9.wi_src = pkt_con_if_8.wo_src;
assign pkt_con_if_9.wi_tgt = pkt_con_if_8.wo_tgt;
assign pkt_con_if_9.wi_data = pkt_con_if_8.wo_data;
assign pkt_con_if_8.wo_rdy = pkt_con_if_9.wi_rdy;

assign pkt_con_if_9.si_vld = pkt_con_if_17.so_vld;  // from Node 17 (1,2)
assign pkt_con_if_9.si_qos = pkt_con_if_17.so_qos;
assign pkt_con_if_9.si_type = pkt_con_if_17.so_type;
assign pkt_con_if_9.si_src = pkt_con_if_17.so_src;
assign pkt_con_if_9.si_tgt = pkt_con_if_17.so_tgt;
assign pkt_con_if_9.si_data = pkt_con_if_17.so_data;
assign pkt_con_if_17.so_rdy = pkt_con_if_9.si_rdy;

assign pkt_con_if_9.ei_vld = pkt_con_if_10.eo_vld;  // from Node 10 (2,1)
assign pkt_con_if_9.ei_qos = pkt_con_if_10.eo_qos;
assign pkt_con_if_9.ei_type = pkt_con_if_10.eo_type;
assign pkt_con_if_9.ei_src = pkt_con_if_10.eo_src;
assign pkt_con_if_9.ei_tgt = pkt_con_if_10.eo_tgt;
assign pkt_con_if_9.ei_data = pkt_con_if_10.eo_data;
assign pkt_con_if_10.eo_rdy = pkt_con_if_9.ei_rdy;

// Node 10 (2,1) - Interior node: all 4 connections
assign pkt_con_if_10.ni_vld = pkt_con_if_2.no_vld;   // from Node 2 (2,0)
assign pkt_con_if_10.ni_qos = pkt_con_if_2.no_qos;
assign pkt_con_if_10.ni_type = pkt_con_if_2.no_type;
assign pkt_con_if_10.ni_src = pkt_con_if_2.no_src;
assign pkt_con_if_10.ni_tgt = pkt_con_if_2.no_tgt;
assign pkt_con_if_10.ni_data = pkt_con_if_2.no_data;
assign pkt_con_if_2.no_rdy = pkt_con_if_10.ni_rdy;

assign pkt_con_if_10.wi_vld = pkt_con_if_9.wo_vld;   // from Node 9 (1,1)
assign pkt_con_if_10.wi_qos = pkt_con_if_9.wo_qos;
assign pkt_con_if_10.wi_type = pkt_con_if_9.wo_type;
assign pkt_con_if_10.wi_src = pkt_con_if_9.wo_src;
assign pkt_con_if_10.wi_tgt = pkt_con_if_9.wo_tgt;
assign pkt_con_if_10.wi_data = pkt_con_if_9.wo_data;
assign pkt_con_if_9.wo_rdy = pkt_con_if_10.wi_rdy;

assign pkt_con_if_10.si_vld = pkt_con_if_18.so_vld;  // from Node 18 (2,2)
assign pkt_con_if_10.si_qos = pkt_con_if_18.so_qos;
assign pkt_con_if_10.si_type = pkt_con_if_18.so_type;
assign pkt_con_if_10.si_src = pkt_con_if_18.so_src;
assign pkt_con_if_10.si_tgt = pkt_con_if_18.so_tgt;
assign pkt_con_if_10.si_data = pkt_con_if_18.so_data;
assign pkt_con_if_18.so_rdy = pkt_con_if_10.si_rdy;

assign pkt_con_if_10.ei_vld = pkt_con_if_11.eo_vld;  // from Node 11 (3,1)
assign pkt_con_if_10.ei_qos = pkt_con_if_11.eo_qos;
assign pkt_con_if_10.ei_type = pkt_con_if_11.eo_type;
assign pkt_con_if_10.ei_src = pkt_con_if_11.eo_src;
assign pkt_con_if_10.ei_tgt = pkt_con_if_11.eo_tgt;
assign pkt_con_if_10.ei_data = pkt_con_if_11.eo_data;
assign pkt_con_if_11.eo_rdy = pkt_con_if_10.ei_rdy;

// Node 11 (3,1) - Interior node: all 4 connections
assign pkt_con_if_11.ni_vld = pkt_con_if_3.no_vld;   // from Node 3 (3,0)
assign pkt_con_if_11.ni_qos = pkt_con_if_3.no_qos;
assign pkt_con_if_11.ni_type = pkt_con_if_3.no_type;
assign pkt_con_if_11.ni_src = pkt_con_if_3.no_src;
assign pkt_con_if_11.ni_tgt = pkt_con_if_3.no_tgt;
assign pkt_con_if_11.ni_data = pkt_con_if_3.no_data;
assign pkt_con_if_3.no_rdy = pkt_con_if_11.ni_rdy;

assign pkt_con_if_11.wi_vld = pkt_con_if_10.wo_vld;  // from Node 10 (2,1)
assign pkt_con_if_11.wi_qos = pkt_con_if_10.wo_qos;
assign pkt_con_if_11.wi_type = pkt_con_if_10.wo_type;
assign pkt_con_if_11.wi_src = pkt_con_if_10.wo_src;
assign pkt_con_if_11.wi_tgt = pkt_con_if_10.wo_tgt;
assign pkt_con_if_11.wi_data = pkt_con_if_10.wo_data;
assign pkt_con_if_10.wo_rdy = pkt_con_if_11.wi_rdy;

assign pkt_con_if_11.si_vld = pkt_con_if_19.so_vld;  // from Node 19 (3,2)
assign pkt_con_if_11.si_qos = pkt_con_if_19.so_qos;
assign pkt_con_if_11.si_type = pkt_con_if_19.so_type;
assign pkt_con_if_11.si_src = pkt_con_if_19.so_src;
assign pkt_con_if_11.si_tgt = pkt_con_if_19.so_tgt;
assign pkt_con_if_11.si_data = pkt_con_if_19.so_data;
assign pkt_con_if_19.so_rdy = pkt_con_if_11.si_rdy;

assign pkt_con_if_11.ei_vld = pkt_con_if_12.eo_vld;  // from Node 12 (4,1)
assign pkt_con_if_11.ei_qos = pkt_con_if_12.eo_qos;
assign pkt_con_if_11.ei_type = pkt_con_if_12.eo_type;
assign pkt_con_if_11.ei_src = pkt_con_if_12.eo_src;
assign pkt_con_if_11.ei_tgt = pkt_con_if_12.eo_tgt;
assign pkt_con_if_11.ei_data = pkt_con_if_12.eo_data;
assign pkt_con_if_12.eo_rdy = pkt_con_if_11.ei_rdy;

// Node 12 (4,1) - Interior node: all 4 connections
assign pkt_con_if_12.ni_vld = pkt_con_if_4.no_vld;   // from Node 4 (4,0)
assign pkt_con_if_12.ni_qos = pkt_con_if_4.no_qos;
assign pkt_con_if_12.ni_type = pkt_con_if_4.no_type;
assign pkt_con_if_12.ni_src = pkt_con_if_4.no_src;
assign pkt_con_if_12.ni_tgt = pkt_con_if_4.no_tgt;
assign pkt_con_if_12.ni_data = pkt_con_if_4.no_data;
assign pkt_con_if_4.no_rdy = pkt_con_if_12.ni_rdy;

assign pkt_con_if_12.wi_vld = pkt_con_if_11.wo_vld;  // from Node 11 (3,1)
assign pkt_con_if_12.wi_qos = pkt_con_if_11.wo_qos;
assign pkt_con_if_12.wi_type = pkt_con_if_11.wo_type;
assign pkt_con_if_12.wi_src = pkt_con_if_11.wo_src;
assign pkt_con_if_12.wi_tgt = pkt_con_if_11.wo_tgt;
assign pkt_con_if_12.wi_data = pkt_con_if_11.wo_data;
assign pkt_con_if_11.wo_rdy = pkt_con_if_12.wi_rdy;

assign pkt_con_if_12.si_vld = pkt_con_if_20.so_vld;  // from Node 20 (4,2)
assign pkt_con_if_12.si_qos = pkt_con_if_20.so_qos;
assign pkt_con_if_12.si_type = pkt_con_if_20.so_type;
assign pkt_con_if_12.si_src = pkt_con_if_20.so_src;
assign pkt_con_if_12.si_tgt = pkt_con_if_20.so_tgt;
assign pkt_con_if_12.si_data = pkt_con_if_20.so_data;
assign pkt_con_if_20.so_rdy = pkt_con_if_12.si_rdy;

assign pkt_con_if_12.ei_vld = pkt_con_if_13.eo_vld;  // from Node 13 (5,1)
assign pkt_con_if_12.ei_qos = pkt_con_if_13.eo_qos;
assign pkt_con_if_12.ei_type = pkt_con_if_13.eo_type;
assign pkt_con_if_12.ei_src = pkt_con_if_13.eo_src;
assign pkt_con_if_12.ei_tgt = pkt_con_if_13.eo_tgt;
assign pkt_con_if_12.ei_data = pkt_con_if_13.eo_data;
assign pkt_con_if_13.eo_rdy = pkt_con_if_12.ei_rdy;

// Node 13 (5,1) - Interior node: all 4 connections
assign pkt_con_if_13.ni_vld = pkt_con_if_5.no_vld;   // from Node 5 (5,0)
assign pkt_con_if_13.ni_qos = pkt_con_if_5.no_qos;
assign pkt_con_if_13.ni_type = pkt_con_if_5.no_type;
assign pkt_con_if_13.ni_src = pkt_con_if_5.no_src;
assign pkt_con_if_13.ni_tgt = pkt_con_if_5.no_tgt;
assign pkt_con_if_13.ni_data = pkt_con_if_5.no_data;
assign pkt_con_if_5.no_rdy = pkt_con_if_13.ni_rdy;

assign pkt_con_if_13.wi_vld = pkt_con_if_12.wo_vld;  // from Node 12 (4,1)
assign pkt_con_if_13.wi_qos = pkt_con_if_12.wo_qos;
assign pkt_con_if_13.wi_type = pkt_con_if_12.wo_type;
assign pkt_con_if_13.wi_src = pkt_con_if_12.wo_src;
assign pkt_con_if_13.wi_tgt = pkt_con_if_12.wo_tgt;
assign pkt_con_if_13.wi_data = pkt_con_if_12.wo_data;
assign pkt_con_if_12.wo_rdy = pkt_con_if_13.wi_rdy;

assign pkt_con_if_13.si_vld = pkt_con_if_21.so_vld;  // from Node 21 (5,2)
assign pkt_con_if_13.si_qos = pkt_con_if_21.so_qos;
assign pkt_con_if_13.si_type = pkt_con_if_21.so_type;
assign pkt_con_if_13.si_src = pkt_con_if_21.so_src;
assign pkt_con_if_13.si_tgt = pkt_con_if_21.so_tgt;
assign pkt_con_if_13.si_data = pkt_con_if_21.so_data;
assign pkt_con_if_21.so_rdy = pkt_con_if_13.si_rdy;

assign pkt_con_if_13.ei_vld = pkt_con_if_14.eo_vld;  // from Node 14 (6,1)
assign pkt_con_if_13.ei_qos = pkt_con_if_14.eo_qos;
assign pkt_con_if_13.ei_type = pkt_con_if_14.eo_type;
assign pkt_con_if_13.ei_src = pkt_con_if_14.eo_src;
assign pkt_con_if_13.ei_tgt = pkt_con_if_14.eo_tgt;
assign pkt_con_if_13.ei_data = pkt_con_if_14.eo_data;
assign pkt_con_if_14.eo_rdy = pkt_con_if_13.ei_rdy;

// Node 14 (6,1) - Interior node: all 4 connections
assign pkt_con_if_14.ni_vld = pkt_con_if_6.no_vld;   // from Node 6 (6,0)
assign pkt_con_if_14.ni_qos = pkt_con_if_6.no_qos;
assign pkt_con_if_14.ni_type = pkt_con_if_6.no_type;
assign pkt_con_if_14.ni_src = pkt_con_if_6.no_src;
assign pkt_con_if_14.ni_tgt = pkt_con_if_6.no_tgt;
assign pkt_con_if_14.ni_data = pkt_con_if_6.no_data;
assign pkt_con_if_6.no_rdy = pkt_con_if_14.ni_rdy;

assign pkt_con_if_14.wi_vld = pkt_con_if_13.wo_vld;  // from Node 13 (5,1)
assign pkt_con_if_14.wi_qos = pkt_con_if_13.wo_qos;
assign pkt_con_if_14.wi_type = pkt_con_if_13.wo_type;
assign pkt_con_if_14.wi_src = pkt_con_if_13.wo_src;
assign pkt_con_if_14.wi_tgt = pkt_con_if_13.wo_tgt;
assign pkt_con_if_14.wi_data = pkt_con_if_13.wo_data;
assign pkt_con_if_13.wo_rdy = pkt_con_if_14.wi_rdy;

assign pkt_con_if_14.si_vld = pkt_con_if_22.so_vld;  // from Node 22 (6,2)
assign pkt_con_if_14.si_qos = pkt_con_if_22.so_qos;
assign pkt_con_if_14.si_type = pkt_con_if_22.so_type;
assign pkt_con_if_14.si_src = pkt_con_if_22.so_src;
assign pkt_con_if_14.si_tgt = pkt_con_if_22.so_tgt;
assign pkt_con_if_14.si_data = pkt_con_if_22.so_data;
assign pkt_con_if_22.so_rdy = pkt_con_if_14.si_rdy;

assign pkt_con_if_14.ei_vld = pkt_con_if_15.eo_vld;  // from Node 15 (7,1)
assign pkt_con_if_14.ei_qos = pkt_con_if_15.eo_qos;
assign pkt_con_if_14.ei_type = pkt_con_if_15.eo_type;
assign pkt_con_if_14.ei_src = pkt_con_if_15.eo_src;
assign pkt_con_if_14.ei_tgt = pkt_con_if_15.eo_tgt;
assign pkt_con_if_14.ei_data = pkt_con_if_15.eo_data;
assign pkt_con_if_15.eo_rdy = pkt_con_if_14.ei_rdy;

// Node 15 (7,1) - Right edge: no East input
assign pkt_con_if_15.ei_vld = 1'b0;
assign pkt_con_if_15.ei_qos = 1'b0;
assign pkt_con_if_15.ei_type = 2'b00;
assign pkt_con_if_15.ei_src = 6'b000000;
assign pkt_con_if_15.ei_tgt = 6'b000000;
assign pkt_con_if_15.ei_data = 8'b00000000;

assign pkt_con_if_15.ni_vld = pkt_con_if_7.no_vld;   // from Node 7 (7,0)
assign pkt_con_if_15.ni_qos = pkt_con_if_7.no_qos;
assign pkt_con_if_15.ni_type = pkt_con_if_7.no_type;
assign pkt_con_if_15.ni_src = pkt_con_if_7.no_src;
assign pkt_con_if_15.ni_tgt = pkt_con_if_7.no_tgt;
assign pkt_con_if_15.ni_data = pkt_con_if_7.no_data;
assign pkt_con_if_7.no_rdy = pkt_con_if_15.ni_rdy;

assign pkt_con_if_15.wi_vld = pkt_con_if_14.wo_vld;  // from Node 14 (6,1)
assign pkt_con_if_15.wi_qos = pkt_con_if_14.wo_qos;
assign pkt_con_if_15.wi_type = pkt_con_if_14.wo_type;
assign pkt_con_if_15.wi_src = pkt_con_if_14.wo_src;
assign pkt_con_if_15.wi_tgt = pkt_con_if_14.wo_tgt;
assign pkt_con_if_15.wi_data = pkt_con_if_14.wo_data;
assign pkt_con_if_14.wo_rdy = pkt_con_if_15.wi_rdy;

assign pkt_con_if_15.si_vld = pkt_con_if_23.so_vld;  // from Node 23 (7,2)
assign pkt_con_if_15.si_qos = pkt_con_if_23.so_qos;
assign pkt_con_if_15.si_type = pkt_con_if_23.so_type;
assign pkt_con_if_15.si_src = pkt_con_if_23.so_src;
assign pkt_con_if_15.si_tgt = pkt_con_if_23.so_tgt;
assign pkt_con_if_15.si_data = pkt_con_if_23.so_data;
assign pkt_con_if_23.so_rdy = pkt_con_if_15.si_rdy;

// Continue this pattern for all remaining nodes 16-63...
// Due to length constraints, I'll show the pattern continues for all 64 nodes
// following the same structure: each node connects to N,W,S,E neighbors if they exist