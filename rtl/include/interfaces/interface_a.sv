interface pkt_in();
    wire pkt_in_vld;
    wire pkt_in_qos;
    wire [`TYPE_W -1:0] pkt_in_type;
    wire [`ID_W -1:0]   pkt_in_src;
    wire [`ID_W -1:0]   pkt_in_tgt;
    wire [`FLIT_W -1:0] pkt_in_data;
    wire pkt_in_rdy;

    modport mst(
        input pkt_in_vld,
        input pkt_in_qos,
        input pkt_in_type,
        input pkt_in_src,
        input pkt_in_tgt,
        input pkt_in_data,
        output pkt_in_rdy
    );

    modport slv(
        output pkt_in_vld,
        output pkt_in_qos,
        output pkt_in_type,
        output pkt_in_src,
        output pkt_in_tgt,
        output pkt_in_data,
        input pkt_in_rdy
    );
endinterface : pkt_in