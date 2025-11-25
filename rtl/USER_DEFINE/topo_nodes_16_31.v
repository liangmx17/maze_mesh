// ====================================================================
// Node Connections - Nodes 16-31
// xi direction inputs: ni (North), wi (West), si (South), ei (East)
// ====================================================================

// Node 16 (0,2) - Left edge: no West input
assign pkt_con_if_16.wi_vld = 1'b0;
assign pkt_con_if_16.wi_qos = 1'b0;
assign pkt_con_if_16.wi_type = 2'b00;
assign pkt_con_if_16.wi_src = 6'b000000;
assign pkt_con_if_16.wi_tgt = 6'b000000;
assign pkt_con_if_16.wi_data = 8'b00000000;

assign pkt_con_if_16.ni_vld = pkt_con_if_8.no_vld;   // from Node 8 (0,1)
assign pkt_con_if_16.ni_qos = pkt_con_if_8.no_qos;
assign pkt_con_if_16.ni_type = pkt_con_if_8.no_type;
assign pkt_con_if_16.ni_src = pkt_con_if_8.no_src;
assign pkt_con_if_16.ni_tgt = pkt_con_if_8.no_tgt;
assign pkt_con_if_16.ni_data = pkt_con_if_8.no_data;
assign pkt_con_if_8.no_rdy = pkt_con_if_16.ni_rdy;

assign pkt_con_if_16.si_vld = pkt_con_if_24.so_vld;  // from Node 24 (0,3)
assign pkt_con_if_16.si_qos = pkt_con_if_24.so_qos;
assign pkt_con_if_16.si_type = pkt_con_if_24.so_type;
assign pkt_con_if_16.si_src = pkt_con_if_24.so_src;
assign pkt_con_if_16.si_tgt = pkt_con_if_24.so_tgt;
assign pkt_con_if_16.si_data = pkt_con_if_24.so_data;
assign pkt_con_if_24.so_rdy = pkt_con_if_16.si_rdy;

assign pkt_con_if_16.ei_vld = pkt_con_if_17.eo_vld;  // from Node 17 (1,2)
assign pkt_con_if_16.ei_qos = pkt_con_if_17.eo_qos;
assign pkt_con_if_16.ei_type = pkt_con_if_17.eo_type;
assign pkt_con_if_16.ei_src = pkt_con_if_17.eo_src;
assign pkt_con_if_16.ei_tgt = pkt_con_if_17.eo_tgt;
assign pkt_con_if_16.ei_data = pkt_con_if_17.eo_data;
assign pkt_con_if_17.eo_rdy = pkt_con_if_16.ei_rdy;

// Node 17 (1,2) - Interior node: all 4 connections
assign pkt_con_if_17.ni_vld = pkt_con_if_9.no_vld;   // from Node 9 (1,1)
assign pkt_con_if_17.ni_qos = pkt_con_if_9.no_qos;
assign pkt_con_if_17.ni_type = pkt_con_if_9.no_type;
assign pkt_con_if_17.ni_src = pkt_con_if_9.no_src;
assign pkt_con_if_17.ni_tgt = pkt_con_if_9.no_tgt;
assign pkt_con_if_17.ni_data = pkt_con_if_9.no_data;
assign pkt_con_if_9.no_rdy = pkt_con_if_17.ni_rdy;

assign pkt_con_if_17.wi_vld = pkt_con_if_16.wo_vld;  // from Node 16 (0,2)
assign pkt_con_if_17.wi_qos = pkt_con_if_16.wo_qos;
assign pkt_con_if_17.wi_type = pkt_con_if_16.wo_type;
assign pkt_con_if_17.wi_src = pkt_con_if_16.wo_src;
assign pkt_con_if_17.wi_tgt = pkt_con_if_16.wo_tgt;
assign pkt_con_if_17.wi_data = pkt_con_if_16.wo_data;
assign pkt_con_if_16.wo_rdy = pkt_con_if_17.wi_rdy;

assign pkt_con_if_17.si_vld = pkt_con_if_25.so_vld;  // from Node 25 (1,3)
assign pkt_con_if_17.si_qos = pkt_con_if_25.so_qos;
assign pkt_con_if_17.si_type = pkt_con_if_25.so_type;
assign pkt_con_if_17.si_src = pkt_con_if_25.so_src;
assign pkt_con_if_17.si_tgt = pkt_con_if_25.so_tgt;
assign pkt_con_if_17.si_data = pkt_con_if_25.so_data;
assign pkt_con_if_25.so_rdy = pkt_con_if_17.si_rdy;

assign pkt_con_if_17.ei_vld = pkt_con_if_18.eo_vld;  // from Node 18 (2,2)
assign pkt_con_if_17.ei_qos = pkt_con_if_18.eo_qos;
assign pkt_con_if_17.ei_type = pkt_con_if_18.eo_type;
assign pkt_con_if_17.ei_src = pkt_con_if_18.eo_src;
assign pkt_con_if_17.ei_tgt = pkt_con_if_18.eo_tgt;
assign pkt_con_if_17.ei_data = pkt_con_if_18.eo_data;
assign pkt_con_if_18.eo_rdy = pkt_con_if_17.ei_rdy;

// Node 18 (2,2) - Interior node: all 4 connections
assign pkt_con_if_18.ni_vld = pkt_con_if_10.no_vld;  // from Node 10 (2,1)
assign pkt_con_if_18.ni_qos = pkt_con_if_10.no_qos;
assign pkt_con_if_18.ni_type = pkt_con_if_10.no_type;
assign pkt_con_if_18.ni_src = pkt_con_if_10.no_src;
assign pkt_con_if_18.ni_tgt = pkt_con_if_10.no_tgt;
assign pkt_con_if_18.ni_data = pkt_con_if_10.no_data;
assign pkt_con_if_10.no_rdy = pkt_con_if_18.ni_rdy;

assign pkt_con_if_18.wi_vld = pkt_con_if_17.wo_vld; // from Node 17 (1,2)
assign pkt_con_if_18.wi_qos = pkt_con_if_17.wo_qos;
assign pkt_con_if_18.wi_type = pkt_con_if_17.wo_type;
assign pkt_con_if_18.wi_src = pkt_con_if_17.wo_src;
assign pkt_con_if_18.wi_tgt = pkt_con_if_17.wo_tgt;
assign pkt_con_if_18.wi_data = pkt_con_if_17.wo_data;
assign pkt_con_if_17.wo_rdy = pkt_con_if_18.wi_rdy;

assign pkt_con_if_18.si_vld = pkt_con_if_26.so_vld; // from Node 26 (2,3)
assign pkt_con_if_18.si_qos = pkt_con_if_26.so_qos;
assign pkt_con_if_18.si_type = pkt_con_if_26.so_type;
assign pkt_con_if_18.si_src = pkt_con_if_26.so_src;
assign pkt_con_if_18.si_tgt = pkt_con_if_26.so_tgt;
assign pkt_con_if_18.si_data = pkt_con_if_26.so_data;
assign pkt_con_if_26.so_rdy = pkt_con_if_18.si_rdy;

assign pkt_con_if_18.ei_vld = pkt_con_if_19.eo_vld; // from Node 19 (3,2)
assign pkt_con_if_18.ei_qos = pkt_con_if_19.eo_qos;
assign pkt_con_if_18.ei_type = pkt_con_if_19.eo_type;
assign pkt_con_if_18.ei_src = pkt_con_if_19.eo_src;
assign pkt_con_if_18.ei_tgt = pkt_con_if_19.eo_tgt;
assign pkt_con_if_18.ei_data = pkt_con_if_19.eo_data;
assign pkt_con_if_19.eo_rdy = pkt_con_if_18.ei_rdy;

// Node 19 (3,2) - Interior node: all 4 connections
assign pkt_con_if_19.ni_vld = pkt_con_if_11.no_vld; // from Node 11 (3,1)
assign pkt_con_if_19.ni_qos = pkt_con_if_11.no_qos;
assign pkt_con_if_19.ni_type = pkt_con_if_11.no_type;
assign pkt_con_if_19.ni_src = pkt_con_if_11.no_src;
assign pkt_con_if_19.ni_tgt = pkt_con_if_11.no_tgt;
assign pkt_con_if_19.ni_data = pkt_con_if_11.no_data;
assign pkt_con_if_11.no_rdy = pkt_con_if_19.ni_rdy;

assign pkt_con_if_19.wi_vld = pkt_con_if_18.wo_vld; // from Node 18 (2,2)
assign pkt_con_if_19.wi_qos = pkt_con_if_18.wo_qos;
assign pkt_con_if_19.wi_type = pkt_con_if_18.wo_type;
assign pkt_con_if_19.wi_src = pkt_con_if_18.wo_src;
assign pkt_con_if_19.wi_tgt = pkt_con_if_18.wo_tgt;
assign pkt_con_if_19.wi_data = pkt_con_if_18.wo_data;
assign pkt_con_if_18.wo_rdy = pkt_con_if_19.wi_rdy;

assign pkt_con_if_19.si_vld = pkt_con_if_27.so_vld; // from Node 27 (3,3)
assign pkt_con_if_19.si_qos = pkt_con_if_27.so_qos;
assign pkt_con_if_19.si_type = pkt_con_if_27.so_type;
assign pkt_con_if_19.si_src = pkt_con_if_27.so_src;
assign pkt_con_if_19.si_tgt = pkt_con_if_27.so_tgt;
assign pkt_con_if_19.si_data = pkt_con_if_27.so_data;
assign pkt_con_if_27.so_rdy = pkt_con_if_19.si_rdy;

assign pkt_con_if_19.ei_vld = pkt_con_if_20.eo_vld; // from Node 20 (4,2)
assign pkt_con_if_19.ei_qos = pkt_con_if_20.eo_qos;
assign pkt_con_if_19.ei_type = pkt_con_if_20.eo_type;
assign pkt_con_if_19.ei_src = pkt_con_if_20.eo_src;
assign pkt_con_if_19.ei_tgt = pkt_con_if_20.eo_tgt;
assign pkt_con_if_19.ei_data = pkt_con_if_20.eo_data;
assign pkt_con_if_20.eo_rdy = pkt_con_if_19.ei_rdy;

// Node 20 (4,2) - Interior node: all 4 connections
assign pkt_con_if_20.ni_vld = pkt_con_if_12.no_vld; // from Node 12 (4,1)
assign pkt_con_if_20.ni_qos = pkt_con_if_12.no_qos;
assign pkt_con_if_20.ni_type = pkt_con_if_12.no_type;
assign pkt_con_if_20.ni_src = pkt_con_if_12.no_src;
assign pkt_con_if_20.ni_tgt = pkt_con_if_12.no_tgt;
assign pkt_con_if_20.ni_data = pkt_con_if_12.no_data;
assign pkt_con_if_12.no_rdy = pkt_con_if_20.ni_rdy;

assign pkt_con_if_20.wi_vld = pkt_con_if_19.wo_vld; // from Node 19 (3,2)
assign pkt_con_if_20.wi_qos = pkt_con_if_19.wo_qos;
assign pkt_con_if_20.wi_type = pkt_con_if_19.wo_type;
assign pkt_con_if_20.wi_src = pkt_con_if_19.wo_src;
assign pkt_con_if_20.wi_tgt = pkt_con_if_19.wo_tgt;
assign pkt_con_if_20.wi_data = pkt_con_if_19.wo_data;
assign pkt_con_if_19.wo_rdy = pkt_con_if_20.wi_rdy;

assign pkt_con_if_20.si_vld = pkt_con_if_28.so_vld; // from Node 28 (4,3)
assign pkt_con_if_20.si_qos = pkt_con_if_28.so_qos;
assign pkt_con_if_20.si_type = pkt_con_if_28.so_type;
assign pkt_con_if_20.si_src = pkt_con_if_28.so_src;
assign pkt_con_if_20.si_tgt = pkt_con_if_28.so_tgt;
assign pkt_con_if_20.si_data = pkt_con_if_28.so_data;
assign pkt_con_if_28.so_rdy = pkt_con_if_20.si_rdy;

assign pkt_con_if_20.ei_vld = pkt_con_if_21.eo_vld; // from Node 21 (5,2)
assign pkt_con_if_20.ei_qos = pkt_con_if_21.eo_qos;
assign pkt_con_if_20.ei_type = pkt_con_if_21.eo_type;
assign pkt_con_if_20.ei_src = pkt_con_if_21.eo_src;
assign pkt_con_if_20.ei_tgt = pkt_con_if_21.eo_tgt;
assign pkt_con_if_20.ei_data = pkt_con_if_21.eo_data;
assign pkt_con_if_21.eo_rdy = pkt_con_if_20.ei_rdy;

// Node 21 (5,2) - Interior node: all 4 connections
assign pkt_con_if_21.ni_vld = pkt_con_if_13.no_vld; // from Node 13 (5,1)
assign pkt_con_if_21.ni_qos = pkt_con_if_13.no_qos;
assign pkt_con_if_21.ni_type = pkt_con_if_13.no_type;
assign pkt_con_if_21.ni_src = pkt_con_if_13.no_src;
assign pkt_con_if_21.ni_tgt = pkt_con_if_13.no_tgt;
assign pkt_con_if_21.ni_data = pkt_con_if_13.no_data;
assign pkt_con_if_13.no_rdy = pkt_con_if_21.ni_rdy;

assign pkt_con_if_21.wi_vld = pkt_con_if_20.wo_vld; // from Node 20 (4,2)
assign pkt_con_if_21.wi_qos = pkt_con_if_20.wo_qos;
assign pkt_con_if_21.wi_type = pkt_con_if_20.wo_type;
assign pkt_con_if_21.wi_src = pkt_con_if_20.wo_src;
assign pkt_con_if_21.wi_tgt = pkt_con_if_20.wo_tgt;
assign pkt_con_if_21.wi_data = pkt_con_if_20.wo_data;
assign pkt_con_if_20.wo_rdy = pkt_con_if_21.wi_rdy;

assign pkt_con_if_21.si_vld = pkt_con_if_29.so_vld; // from Node 29 (5,3)
assign pkt_con_if_21.si_qos = pkt_con_if_29.so_qos;
assign pkt_con_if_21.si_type = pkt_con_if_29.so_type;
assign pkt_con_if_21.si_src = pkt_con_if_29.so_src;
assign pkt_con_if_21.si_tgt = pkt_con_if_29.so_tgt;
assign pkt_con_if_21.si_data = pkt_con_if_29.so_data;
assign pkt_con_if_29.so_rdy = pkt_con_if_21.si_rdy;

assign pkt_con_if_21.ei_vld = pkt_con_if_22.eo_vld; // from Node 22 (6,2)
assign pkt_con_if_21.ei_qos = pkt_con_if_22.eo_qos;
assign pkt_con_if_21.ei_type = pkt_con_if_22.eo_type;
assign pkt_con_if_21.ei_src = pkt_con_if_22.eo_src;
assign pkt_con_if_21.ei_tgt = pkt_con_if_22.eo_tgt;
assign pkt_con_if_21.ei_data = pkt_con_if_22.eo_data;
assign pkt_con_if_22.eo_rdy = pkt_con_if_21.ei_rdy;

// Node 22 (6,2) - Interior node: all 4 connections
assign pkt_con_if_22.ni_vld = pkt_con_if_14.no_vld; // from Node 14 (6,1)
assign pkt_con_if_22.ni_qos = pkt_con_if_14.no_qos;
assign pkt_con_if_22.ni_type = pkt_con_if_14.no_type;
assign pkt_con_if_22.ni_src = pkt_con_if_14.no_src;
assign pkt_con_if_22.ni_tgt = pkt_con_if_14.no_tgt;
assign pkt_con_if_22.ni_data = pkt_con_if_14.no_data;
assign pkt_con_if_14.no_rdy = pkt_con_if_22.ni_rdy;

assign pkt_con_if_22.wi_vld = pkt_con_if_21.wo_vld; // from Node 21 (5,2)
assign pkt_con_if_22.wi_qos = pkt_con_if_21.wo_qos;
assign pkt_con_if_22.wi_type = pkt_con_if_21.wo_type;
assign pkt_con_if_22.wi_src = pkt_con_if_21.wo_src;
assign pkt_con_if_22.wi_tgt = pkt_con_if_21.wo_tgt;
assign pkt_con_if_22.wi_data = pkt_con_if_21.wo_data;
assign pkt_con_if_21.wo_rdy = pkt_con_if_22.wi_rdy;

assign pkt_con_if_22.si_vld = pkt_con_if_30.so_vld; // from Node 30 (6,3)
assign pkt_con_if_22.si_qos = pkt_con_if_30.so_qos;
assign pkt_con_if_22.si_type = pkt_con_if_30.so_type;
assign pkt_con_if_22.si_src = pkt_con_if_30.so_src;
assign pkt_con_if_22.si_tgt = pkt_con_if_30.so_tgt;
assign pkt_con_if_22.si_data = pkt_con_if_30.so_data;
assign pkt_con_if_30.so_rdy = pkt_con_if_22.si_rdy;

assign pkt_con_if_22.ei_vld = pkt_con_if_23.eo_vld; // from Node 23 (7,2)
assign pkt_con_if_22.ei_qos = pkt_con_if_23.eo_qos;
assign pkt_con_if_22.ei_type = pkt_con_if_23.eo_type;
assign pkt_con_if_22.ei_src = pkt_con_if_23.eo_src;
assign pkt_con_if_22.ei_tgt = pkt_con_if_23.eo_tgt;
assign pkt_con_if_22.ei_data = pkt_con_if_23.eo_data;
assign pkt_con_if_23.eo_rdy = pkt_con_if_22.ei_rdy;

// Node 23 (7,2) - Right edge: no East input
assign pkt_con_if_23.ei_vld = 1'b0;
assign pkt_con_if_23.ei_qos = 1'b0;
assign pkt_con_if_23.ei_type = 2'b00;
assign pkt_con_if_23.ei_src = 6'b000000;
assign pkt_con_if_23.ei_tgt = 6'b000000;
assign pkt_con_if_23.ei_data = 8'b00000000;

assign pkt_con_if_23.ni_vld = pkt_con_if_15.no_vld;  // from Node 15 (7,1)
assign pkt_con_if_23.ni_qos = pkt_con_if_15.no_qos;
assign pkt_con_if_23.ni_type = pkt_con_if_15.no_type;
assign pkt_con_if_23.ni_src = pkt_con_if_15.no_src;
assign pkt_con_if_23.ni_tgt = pkt_con_if_15.no_tgt;
assign pkt_con_if_23.ni_data = pkt_con_if_15.no_data;
assign pkt_con_if_15.no_rdy = pkt_con_if_23.ni_rdy;

assign pkt_con_if_23.wi_vld = pkt_con_if_22.wo_vld; // from Node 22 (6,2)
assign pkt_con_if_23.wi_qos = pkt_con_if_22.wo_qos;
assign pkt_con_if_23.wi_type = pkt_con_if_22.wo_type;
assign pkt_con_if_23.wi_src = pkt_con_if_22.wo_src;
assign pkt_con_if_23.wi_tgt = pkt_con_if_22.wo_tgt;
assign pkt_con_if_23.wi_data = pkt_con_if_22.wo_data;
assign pkt_con_if_22.wo_rdy = pkt_con_if_23.wi_rdy;

assign pkt_con_if_23.si_vld = pkt_con_if_31.so_vld; // from Node 31 (7,3)
assign pkt_con_if_23.si_qos = pkt_con_if_31.so_qos;
assign pkt_con_if_23.si_type = pkt_con_if_31.so_type;
assign pkt_con_if_23.si_src = pkt_con_if_31.so_src;
assign pkt_con_if_23.si_tgt = pkt_con_if_31.so_tgt;
assign pkt_con_if_23.si_data = pkt_con_if_31.so_data;
assign pkt_con_if_31.so_rdy = pkt_con_if_23.si_rdy;

// Node 24 (0,3) - Left edge: no West input
assign pkt_con_if_24.wi_vld = 1'b0;
assign pkt_con_if_24.wi_qos = 1'b0;
assign pkt_con_if_24.wi_type = 2'b00;
assign pkt_con_if_24.wi_src = 6'b000000;
assign pkt_con_if_24.wi_tgt = 6'b000000;
assign pkt_con_if_24.wi_data = 8'b00000000;

assign pkt_con_if_24.ni_vld = pkt_con_if_16.no_vld; // from Node 16 (0,2)
assign pkt_con_if_24.ni_qos = pkt_con_if_16.no_qos;
assign pkt_con_if_24.ni_type = pkt_con_if_16.no_type;
assign pkt_con_if_24.ni_src = pkt_con_if_16.no_src;
assign pkt_con_if_24.ni_tgt = pkt_con_if_16.no_tgt;
assign pkt_con_if_24.ni_data = pkt_con_if_16.no_data;
assign pkt_con_if_16.no_rdy = pkt_con_if_24.ni_rdy;

assign pkt_con_if_24.si_vld = pkt_con_if_32.so_vld; // from Node 32 (0,4)
assign pkt_con_if_24.si_qos = pkt_con_if_32.so_qos;
assign pkt_con_if_24.si_type = pkt_con_if_32.so_type;
assign pkt_con_if_24.si_src = pkt_con_if_32.so_src;
assign pkt_con_if_24.si_tgt = pkt_con_if_32.so_tgt;
assign pkt_con_if_24.si_data = pkt_con_if_32.so_data;
assign pkt_con_if_32.so_rdy = pkt_con_if_24.si_rdy;

assign pkt_con_if_24.ei_vld = pkt_con_if_25.eo_vld; // from Node 25 (1,3)
assign pkt_con_if_24.ei_qos = pkt_con_if_25.eo_qos;
assign pkt_con_if_24.ei_type = pkt_con_if_25.eo_type;
assign pkt_con_if_24.ei_src = pkt_con_if_25.eo_src;
assign pkt_con_if_24.ei_tgt = pkt_con_if_25.eo_tgt;
assign pkt_con_if_24.ei_data = pkt_con_if_25.eo_data;
assign pkt_con_if_25.eo_rdy = pkt_con_if_24.ei_rdy;

// Node 25 (1,3) - Interior node: all 4 connections
assign pkt_con_if_25.ni_vld = pkt_con_if_17.no_vld; // from Node 17 (1,2)
assign pkt_con_if_25.ni_qos = pkt_con_if_17.no_qos;
assign pkt_con_if_25.ni_type = pkt_con_if_17.no_type;
assign pkt_con_if_25.ni_src = pkt_con_if_17.no_src;
assign pkt_con_if_25.ni_tgt = pkt_con_if_17.no_tgt;
assign pkt_con_if_25.ni_data = pkt_con_if_17.no_data;
assign pkt_con_if_17.no_rdy = pkt_con_if_25.ni_rdy;

assign pkt_con_if_25.wi_vld = pkt_con_if_24.wo_vld; // from Node 24 (0,3)
assign pkt_con_if_25.wi_qos = pkt_con_if_24.wo_qos;
assign pkt_con_if_25.wi_type = pkt_con_if_24.wo_type;
assign pkt_con_if_25.wi_src = pkt_con_if_24.wo_src;
assign pkt_con_if_25.wi_tgt = pkt_con_if_24.wo_tgt;
assign pkt_con_if_25.wi_data = pkt_con_if_24.wo_data;
assign pkt_con_if_24.wo_rdy = pkt_con_if_25.wi_rdy;

assign pkt_con_if_25.si_vld = pkt_con_if_33.so_vld; // from Node 33 (1,4)
assign pkt_con_if_25.si_qos = pkt_con_if_33.so_qos;
assign pkt_con_if_25.si_type = pkt_con_if_33.so_type;
assign pkt_con_if_25.si_src = pkt_con_if_33.so_src;
assign pkt_con_if_25.si_tgt = pkt_con_if_33.so_tgt;
assign pkt_con_if_25.si_data = pkt_con_if_33.so_data;
assign pkt_con_if_33.so_rdy = pkt_con_if_25.si_rdy;

assign pkt_con_if_25.ei_vld = pkt_con_if_26.eo_vld; // from Node 26 (2,3)
assign pkt_con_if_25.ei_qos = pkt_con_if_26.eo_qos;
assign pkt_con_if_25.ei_type = pkt_con_if_26.eo_type;
assign pkt_con_if_25.ei_src = pkt_con_if_26.eo_src;
assign pkt_con_if_25.ei_tgt = pkt_con_if_26.eo_tgt;
assign pkt_con_if_25.ei_data = pkt_con_if_26.eo_data;
assign pkt_con_if_26.eo_rdy = pkt_con_if_25.ei_rdy;

// Node 26 (2,3) - Interior node: all 4 connections
assign pkt_con_if_26.ni_vld = pkt_con_if_18.no_vld; // from Node 18 (2,2)
assign pkt_con_if_26.ni_qos = pkt_con_if_18.no_qos;
assign pkt_con_if_26.ni_type = pkt_con_if_18.no_type;
assign pkt_con_if_26.ni_src = pkt_con_if_18.no_src;
assign pkt_con_if_26.ni_tgt = pkt_con_if_18.no_tgt;
assign pkt_con_if_26.ni_data = pkt_con_if_18.no_data;
assign pkt_con_if_18.no_rdy = pkt_con_if_26.ni_rdy;

assign pkt_con_if_26.wi_vld = pkt_con_if_25.wo_vld; // from Node 25 (1,3)
assign pkt_con_if_26.wi_qos = pkt_con_if_25.wo_qos;
assign pkt_con_if_26.wi_type = pkt_con_if_25.wo_type;
assign pkt_con_if_26.wi_src = pkt_con_if_25.wo_src;
assign pkt_con_if_26.wi_tgt = pkt_con_if_25.wo_tgt;
assign pkt_con_if_26.wi_data = pkt_con_if_25.wo_data;
assign pkt_con_if_25.wo_rdy = pkt_con_if_26.wi_rdy;

assign pkt_con_if_26.si_vld = pkt_con_if_34.so_vld; // from Node 34 (2,4)
assign pkt_con_if_26.si_qos = pkt_con_if_34.so_qos;
assign pkt_con_if_26.si_type = pkt_con_if_34.so_type;
assign pkt_con_if_26.si_src = pkt_con_if_34.so_src;
assign pkt_con_if_26.si_tgt = pkt_con_if_34.so_tgt;
assign pkt_con_if_26.si_data = pkt_con_if_34.so_data;
assign pkt_con_if_34.so_rdy = pkt_con_if_26.si_rdy;

assign pkt_con_if_26.ei_vld = pkt_con_if_27.eo_vld; // from Node 27 (3,3)
assign pkt_con_if_26.ei_qos = pkt_con_if_27.eo_qos;
assign pkt_con_if_26.ei_type = pkt_con_if_27.eo_type;
assign pkt_con_if_26.ei_src = pkt_con_if_27.eo_src;
assign pkt_con_if_26.ei_tgt = pkt_con_if_27.eo_tgt;
assign pkt_con_if_26.ei_data = pkt_con_if_27.eo_data;
assign pkt_con_if_27.eo_rdy = pkt_con_if_26.ei_rdy;

// Node 27 (3,3) - Interior node: all 4 connections
assign pkt_con_if_27.ni_vld = pkt_con_if_19.no_vld; // from Node 19 (3,2)
assign pkt_con_if_27.ni_qos = pkt_con_if_19.no_qos;
assign pkt_con_if_27.ni_type = pkt_con_if_19.no_type;
assign pkt_con_if_27.ni_src = pkt_con_if_19.no_src;
assign pkt_con_if_27.ni_tgt = pkt_con_if_19.no_tgt;
assign pkt_con_if_27.ni_data = pkt_con_if_19.no_data;
assign pkt_con_if_19.no_rdy = pkt_con_if_27.ni_rdy;

assign pkt_con_if_27.wi_vld = pkt_con_if_26.wo_vld; // from Node 26 (2,3)
assign pkt_con_if_27.wi_qos = pkt_con_if_26.wo_qos;
assign pkt_con_if_27.wi_type = pkt_con_if_26.wo_type;
assign pkt_con_if_27.wi_src = pkt_con_if_26.wo_src;
assign pkt_con_if_27.wi_tgt = pkt_con_if_26.wo_tgt;
assign pkt_con_if_27.wi_data = pkt_con_if_26.wo_data;
assign pkt_con_if_26.wo_rdy = pkt_con_if_27.wi_rdy;

assign pkt_con_if_27.si_vld = pkt_con_if_35.so_vld; // from Node 35 (3,4)
assign pkt_con_if_27.si_qos = pkt_con_if_35.so_qos;
assign pkt_con_if_27.si_type = pkt_con_if_35.so_type;
assign pkt_con_if_27.si_src = pkt_con_if_35.so_src;
assign pkt_con_if_27.si_tgt = pkt_con_if_35.so_tgt;
assign pkt_con_if_27.si_data = pkt_con_if_35.so_data;
assign pkt_con_if_35.so_rdy = pkt_con_if_27.si_rdy;

assign pkt_con_if_27.ei_vld = pkt_con_if_28.eo_vld; // from Node 28 (4,3)
assign pkt_con_if_27.ei_qos = pkt_con_if_28.eo_qos;
assign pkt_con_if_27.ei_type = pkt_con_if_28.eo_type;
assign pkt_con_if_27.ei_src = pkt_con_if_28.eo_src;
assign pkt_con_if_27.ei_tgt = pkt_con_if_28.eo_tgt;
assign pkt_con_if_27.ei_data = pkt_con_if_28.eo_data;
assign pkt_con_if_28.eo_rdy = pkt_con_if_27.ei_rdy;

// Node 28 (4,3) - Interior node: all 4 connections
assign pkt_con_if_28.ni_vld = pkt_con_if_20.no_vld; // from Node 20 (4,2)
assign pkt_con_if_28.ni_qos = pkt_con_if_20.no_qos;
assign pkt_con_if_28.ni_type = pkt_con_if_20.no_type;
assign pkt_con_if_28.ni_src = pkt_con_if_20.no_src;
assign pkt_con_if_28.ni_tgt = pkt_con_if_20.no_tgt;
assign pkt_con_if_28.ni_data = pkt_con_if_20.no_data;
assign pkt_con_if_20.no_rdy = pkt_con_if_28.ni_rdy;

assign pkt_con_if_28.wi_vld = pkt_con_if_27.wo_vld; // from Node 27 (3,3)
assign pkt_con_if_28.wi_qos = pkt_con_if_27.wo_qos;
assign pkt_con_if_28.wi_type = pkt_con_if_27.wo_type;
assign pkt_con_if_28.wi_src = pkt_con_if_27.wo_src;
assign pkt_con_if_28.wi_tgt = pkt_con_if_27.wo_tgt;
assign pkt_con_if_28.wi_data = pkt_con_if_27.wo_data;
assign pkt_con_if_27.wo_rdy = pkt_con_if_28.wi_rdy;

assign pkt_con_if_28.si_vld = pkt_con_if_36.so_vld; // from Node 36 (4,4)
assign pkt_con_if_28.si_qos = pkt_con_if_36.so_qos;
assign pkt_con_if_28.si_type = pkt_con_if_36.so_type;
assign pkt_con_if_28.si_src = pkt_con_if_36.so_src;
assign pkt_con_if_28.si_tgt = pkt_con_if_36.so_tgt;
assign pkt_con_if_28.si_data = pkt_con_if_36.so_data;
assign pkt_con_if_36.so_rdy = pkt_con_if_28.si_rdy;

assign pkt_con_if_28.ei_vld = pkt_con_if_29.eo_vld; // from Node 29 (5,3)
assign pkt_con_if_28.ei_qos = pkt_con_if_29.eo_qos;
assign pkt_con_if_28.ei_type = pkt_con_if_29.eo_type;
assign pkt_con_if_28.ei_src = pkt_con_if_29.eo_src;
assign pkt_con_if_28.ei_tgt = pkt_con_if_29.eo_tgt;
assign pkt_con_if_28.ei_data = pkt_con_if_29.eo_data;
assign pkt_con_if_29.eo_rdy = pkt_con_if_28.ei_rdy;

// Node 29 (5,3) - Interior node: all 4 connections
assign pkt_con_if_29.ni_vld = pkt_con_if_21.no_vld; // from Node 21 (5,2)
assign pkt_con_if_29.ni_qos = pkt_con_if_21.no_qos;
assign pkt_con_if_29.ni_type = pkt_con_if_21.no_type;
assign pkt_con_if_29.ni_src = pkt_con_if_21.no_src;
assign pkt_con_if_29.ni_tgt = pkt_con_if_21.no_tgt;
assign pkt_con_if_29.ni_data = pkt_con_if_21.no_data;
assign pkt_con_if_21.no_rdy = pkt_con_if_29.ni_rdy;

assign pkt_con_if_29.wi_vld = pkt_con_if_28.wo_vld; // from Node 28 (4,3)
assign pkt_con_if_29.wi_qos = pkt_con_if_28.wo_qos;
assign pkt_con_if_29.wi_type = pkt_con_if_28.wo_type;
assign pkt_con_if_29.wi_src = pkt_con_if_28.wo_src;
assign pkt_con_if_29.wi_tgt = pkt_con_if_28.wo_tgt;
assign pkt_con_if_29.wi_data = pkt_con_if_28.wo_data;
assign pkt_con_if_28.wo_rdy = pkt_con_if_29.wi_rdy;

assign pkt_con_if_29.si_vld = pkt_con_if_37.so_vld; // from Node 37 (5,4)
assign pkt_con_if_29.si_qos = pkt_con_if_37.so_qos;
assign pkt_con_if_29.si_type = pkt_con_if_37.so_type;
assign pkt_con_if_29.si_src = pkt_con_if_37.so_src;
assign pkt_con_if_29.si_tgt = pkt_con_if_37.so_tgt;
assign pkt_con_if_29.si_data = pkt_con_if_37.so_data;
assign pkt_con_if_37.so_rdy = pkt_con_if_29.si_rdy;

assign pkt_con_if_29.ei_vld = pkt_con_if_30.eo_vld; // from Node 30 (6,3)
assign pkt_con_if_29.ei_qos = pkt_con_if_30.eo_qos;
assign pkt_con_if_29.ei_type = pkt_con_if_30.eo_type;
assign pkt_con_if_29.ei_src = pkt_con_if_30.eo_src;
assign pkt_con_if_29.ei_tgt = pkt_con_if_30.eo_tgt;
assign pkt_con_if_29.ei_data = pkt_con_if_30.eo_data;
assign pkt_con_if_30.eo_rdy = pkt_con_if_29.ei_rdy;

// Node 30 (6,3) - Interior node: all 4 connections
assign pkt_con_if_30.ni_vld = pkt_con_if_22.no_vld; // from Node 22 (6,2)
assign pkt_con_if_30.ni_qos = pkt_con_if_22.no_qos;
assign pkt_con_if_30.ni_type = pkt_con_if_22.no_type;
assign pkt_con_if_30.ni_src = pkt_con_if_22.no_src;
assign pkt_con_if_30.ni_tgt = pkt_con_if_22.no_tgt;
assign pkt_con_if_30.ni_data = pkt_con_if_22.no_data;
assign pkt_con_if_22.no_rdy = pkt_con_if_30.ni_rdy;

assign pkt_con_if_30.wi_vld = pkt_con_if_29.wo_vld; // from Node 29 (5,3)
assign pkt_con_if_30.wi_qos = pkt_con_if_29.wo_qos;
assign pkt_con_if_30.wi_type = pkt_con_if_29.wo_type;
assign pkt_con_if_30.wi_src = pkt_con_if_29.wo_src;
assign pkt_con_if_30.wi_tgt = pkt_con_if_29.wo_tgt;
assign pkt_con_if_30.wi_data = pkt_con_if_29.wo_data;
assign pkt_con_if_29.wo_rdy = pkt_con_if_30.wi_rdy;

assign pkt_con_if_30.si_vld = pkt_con_if_38.so_vld; // from Node 38 (6,4)
assign pkt_con_if_30.si_qos = pkt_con_if_38.so_qos;
assign pkt_con_if_30.si_type = pkt_con_if_38.so_type;
assign pkt_con_if_30.si_src = pkt_con_if_38.so_src;
assign pkt_con_if_30.si_tgt = pkt_con_if_38.so_tgt;
assign pkt_con_if_30.si_data = pkt_con_if_38.so_data;
assign pkt_con_if_38.so_rdy = pkt_con_if_30.si_rdy;

assign pkt_con_if_30.ei_vld = pkt_con_if_31.eo_vld; // from Node 31 (7,3)
assign pkt_con_if_30.ei_qos = pkt_con_if_31.eo_qos;
assign pkt_con_if_30.ei_type = pkt_con_if_31.eo_type;
assign pkt_con_if_30.ei_src = pkt_con_if_31.eo_src;
assign pkt_con_if_30.ei_tgt = pkt_con_if_31.eo_tgt;
assign pkt_con_if_30.ei_data = pkt_con_if_31.eo_data;
assign pkt_con_if_31.eo_rdy = pkt_con_if_30.ei_rdy;

// Node 31 (7,3) - Right edge: no East input
assign pkt_con_if_31.ei_vld = 1'b0;
assign pkt_con_if_31.ei_qos = 1'b0;
assign pkt_con_if_31.ei_type = 2'b00;
assign pkt_con_if_31.ei_src = 6'b000000;
assign pkt_con_if_31.ei_tgt = 6'b000000;
assign pkt_con_if_31.ei_data = 8'b00000000;

assign pkt_con_if_31.ni_vld = pkt_con_if_23.no_vld; // from Node 23 (7,2)
assign pkt_con_if_31.ni_qos = pkt_con_if_23.no_qos;
assign pkt_con_if_31.ni_type = pkt_con_if_23.no_type;
assign pkt_con_if_31.ni_src = pkt_con_if_23.no_src;
assign pkt_con_if_31.ni_tgt = pkt_con_if_23.no_tgt;
assign pkt_con_if_31.ni_data = pkt_con_if_23.no_data;
assign pkt_con_if_23.no_rdy = pkt_con_if_31.ni_rdy;

assign pkt_con_if_31.wi_vld = pkt_con_if_30.wo_vld; // from Node 30 (6,3)
assign pkt_con_if_31.wi_qos = pkt_con_if_30.wo_qos;
assign pkt_con_if_31.wi_type = pkt_con_if_30.wo_type;
assign pkt_con_if_31.wi_src = pkt_con_if_30.wo_src;
assign pkt_con_if_31.wi_tgt = pkt_con_if_30.wo_tgt;
assign pkt_con_if_31.wi_data = pkt_con_if_30.wo_data;
assign pkt_con_if_30.wo_rdy = pkt_con_if_31.wi_rdy;

assign pkt_con_if_31.si_vld = pkt_con_if_39.so_vld; // from Node 39 (7,4)
assign pkt_con_if_31.si_qos = pkt_con_if_39.so_qos;
assign pkt_con_if_31.si_type = pkt_con_if_39.so_type;
assign pkt_con_if_31.si_src = pkt_con_if_39.so_src;
assign pkt_con_if_31.si_tgt = pkt_con_if_39.so_tgt;
assign pkt_con_if_31.si_data = pkt_con_if_39.so_data;
assign pkt_con_if_39.so_rdy = pkt_con_if_31.si_rdy;