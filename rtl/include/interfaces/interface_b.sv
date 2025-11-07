interface pkt_out();
    wire pkt_out_vld;
    wire pkt_out_qos;
    wire [`TYPE_W -1:0] pkt_out_type;
    wire [`ID_W -1:0]   pkt_out_src;
    wire [`ID_W -1:0]   pkt_out_tgt;
    wire [`FLIT_W -1:0] pkt_out_data;
    wire pkt_out_rdy;

    modport mst(
        output pkt_out_vld,
        output pkt_out_qos,
        output pkt_out_type,
        output pkt_out_src,
        output pkt_out_tgt,
        output pkt_out_data,
        input  pkt_out_rdy
    );

    modport slv(
        input   pkt_out_vld,
        input   pkt_out_qos,
        input   pkt_out_type,
        input   pkt_out_src,
        input   pkt_out_tgt,
        input   pkt_out_data,
        output  pkt_out_rdy
    );
endinterface : pkt_out







