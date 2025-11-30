// C Interface - NetWork Topology Connections (NWSE 4-Direction Mesh)
// 8 separate ports: N input, W input, S input, E input, N output, W output, S output, E output
// Each Node connects to 4 nEighbors in North, West, South, East directions
// Note: This interface expects the folloWing defines to be set before incluSion:
// `define QOS_W 1
// `define ID_W 6
// `define FLIT_W 8

interface pkt_con_if;

    // INPUT ports - data coming FROM other Nodes
    logic Ni_vld;                       // North Input valid Signal
    logic Ni_rdy;                       // North Input ready Signal
    logic Ni_qos;                       // North Input QoS level
    logic [1:0] Ni_type;                // North Input packet type
    logic [`ID_W-1:0] Ni_src;           // North Input Source Node ID
    logic [`ID_W-1:0] Ni_tgt;           // North Input target Node ID
    logic [`FLIT_W-1:0] Ni_data;        // North Input data payload

    logic Wi_vld;                       // West Input valid Signal
    logic Wi_rdy;                       // West Input ready Signal
    logic Wi_qos;                       // West Input QoS level
    logic [1:0] Wi_type;                // West Input packet type
    logic [`ID_W-1:0] Wi_src;           // West Input Source Node ID
    logic [`ID_W-1:0] Wi_tgt;           // West Input target Node ID
    logic [`FLIT_W-1:0] Wi_data;        // West Input data payload

    logic Si_vld;                       // South Input valid Signal
    logic Si_rdy;                       // South Input ready Signal
    logic Si_qos;                       // South Input QoS level
    logic [1:0] Si_type;                // South Input packet type
    logic [`ID_W-1:0] Si_src;           // South Input Source Node ID
    logic [`ID_W-1:0] Si_tgt;           // South Input target Node ID
    logic [`FLIT_W-1:0] Si_data;        // South Input data payload

    logic Ei_vld;                       // East Input valid Signal
    logic Ei_rdy;                       // East Input ready Signal
    logic Ei_qos;                       // East Input QoS level
    logic [1:0] Ei_type;                // East Input packet type
    logic [`ID_W-1:0] Ei_src;           // East Input Source Node ID
    logic [`ID_W-1:0] Ei_tgt;           // East Input target Node ID
    logic [`FLIT_W-1:0] Ei_data;        // East Input data payload

    logic Qi_vld;                       // East Input valid Signal
    logic Qi_rdy;                       // East Input ready Signal
    logic Qi_qos;                       // East Input QoS level
    logic [1:0] Qi_type;                // East Input packet type
    logic [`ID_W-1:0] Qi_src;           // East Input Source Node ID
    logic [`ID_W-1:0] Qi_tgt;           // East Input target Node ID
    logic [`FLIT_W-1:0] Qi_data;        // East Input data payload

    logic Ri_vld;                       // East Input valid Signal
    logic Ri_rdy;                       // East Input ready Signal
    logic Ri_qos;                       // East Input QoS level
    logic [1:0] Ri_type;                // East Input packet type
    logic [`ID_W-1:0] Ri_src;           // East Input Source Node ID
    logic [`ID_W-1:0] Ri_tgt;           // East Input target Node ID
    logic [`FLIT_W-1:0] Ri_data;        // East Input data payload

    // OUTPUT ports - data going TO other Nodes
    logic No_vld;                       // North Output valid Signal
    logic No_rdy;                       // North Output ready Signal
    logic No_qos;                       // North Output QoS level
    logic [1:0] No_type;                // North Output packet type
    logic [`ID_W-1:0] No_src;           // North Output Source Node ID
    logic [`ID_W-1:0] No_tgt;           // North Output target Node ID
    logic [`FLIT_W-1:0] No_data;        // North Output data payload

    logic Wo_vld;                       // West Output valid Signal
    logic Wo_rdy;                       // West Output ready Signal
    logic Wo_qos;                       // West Output QoS level
    logic [1:0] Wo_type;                // West Output packet type
    logic [`ID_W-1:0] Wo_src;           // West Output Source Node ID
    logic [`ID_W-1:0] Wo_tgt;           // West Output target Node ID
    logic [`FLIT_W-1:0] Wo_data;        // West Output data payload

    logic So_vld;                       // South Output valid Signal
    logic So_rdy;                       // South Output ready Signal
    logic So_qos;                       // South Output QoS level
    logic [1:0] So_type;                // South Output packet type
    logic [`ID_W-1:0] So_src;           // South Output Source Node ID
    logic [`ID_W-1:0] So_tgt;           // South Output target Node ID
    logic [`FLIT_W-1:0] So_data;        // South Output data payload

    logic Eo_vld;                       // East Output valid Signal
    logic Eo_rdy;                       // East Output ready Signal
    logic Eo_qos;                       // East Output QoS level
    logic [1:0] Eo_type;                // East Output packet type
    logic [`ID_W-1:0] Eo_src;           // East Output Source Node ID
    logic [`ID_W-1:0] Eo_tgt;           // East Output target Node ID
    logic [`FLIT_W-1:0] Eo_data;        // East Output data payload

    logic Qo_vld;                       // East Output valid Signal
    logic Qo_rdy;                       // East Output ready Signal
    logic Qo_qos;                       // East Output QoS level
    logic [1:0] Qo_type;                // East Output packet type
    logic [`ID_W-1:0] Qo_src;           // East Output Source Node ID
    logic [`ID_W-1:0] Qo_tgt;           // East Output target Node ID
    logic [`FLIT_W-1:0] Qo_data;        // East Output data payload

    logic Ro_vld;                       // East Output valid Signal
    logic Ro_rdy;                       // East Output ready Signal
    logic Ro_qos;                       // East Output QoS level
    logic [1:0] Ro_type;                // East Output packet type
    logic [`ID_W-1:0] Ro_src;           // East Output Source Node ID
    logic [`ID_W-1:0] Ro_tgt;           // East Output target Node ID
    logic [`FLIT_W-1:0] Ro_data;        // East Output data payload

    // Modport for master connections (Nodes)
    // Node drives output ports (No_*, Wo_*, So_*, Eo_*) and recEives from input ports (Ni_*, Wi_*, Si_*, Ei_*)
    modport mst (
        // Input ports (Node recEives data from these)
        input  Ni_vld, output Ni_rdy,
        input  Ni_qos, input  Ni_type, input  Ni_src, input  Ni_tgt, input  Ni_data,
        input  Wi_vld, output Wi_rdy,
        input  Wi_qos, input  Wi_type, input  Wi_src, input  Wi_tgt, input  Wi_data,
        input  Si_vld, output Si_rdy,
        input  Si_qos, input  Si_type, input  Si_src, input  Si_tgt, input  Si_data,
        input  Ei_vld, output Ei_rdy,
        input  Ei_qos, input  Ei_type, input  Ei_src, input  Ei_tgt, input  Ei_data,
        input  Qi_vld, output Qi_rdy,
        input  Qi_qos, input  Qi_type, input  Qi_src, input  Qi_tgt, input  Qi_data,
        input  Ri_vld, output Ri_rdy,
        input  Ri_qos, input  Ri_type, input  Ri_src, input  Ri_tgt, input  Ri_data,

        // Output ports (Node drives data to these)
        output No_vld, input  No_rdy,
        output No_qos, output No_type, output No_src, output No_tgt, output No_data,
        output Wo_vld, input  Wo_rdy,
        output Wo_qos, output Wo_type, output Wo_src, output Wo_tgt, output Wo_data,
        output So_vld, input  So_rdy,
        output So_qos, output So_type, output So_src, output So_tgt, output So_data,
        output Eo_vld, input  Eo_rdy,
        output Eo_qos, output Eo_type, output Eo_src, output Eo_tgt, output Eo_data,
        output Qo_vld, input  Qo_rdy,
        output Qo_qos, output Qo_type, output Qo_src, output Qo_tgt, output Qo_data,
        output Ro_vld, input  Ro_rdy,
        output Ro_qos, output Ro_type, output Ro_src, output Ro_tgt, output Ro_data
    );

    // Modport for slave connections (topology)
    // Used by topo module to connect Nodes together
    modport slv (
        // Connect to Node outputs (topology recEives these)
        input  No_vld, output No_rdy,
        input  No_qos, input  No_type, input  No_src, input  No_tgt, input  No_data,
        input  Wo_vld, output Wo_rdy,
        input  Wo_qos, input  Wo_type, input  Wo_src, input  Wo_tgt, input  Wo_data,
        input  So_vld, output So_rdy,
        input  So_qos, input  So_type, input  So_src, input  So_tgt, input  So_data,
        input  Eo_vld, output Eo_rdy,
        input  Eo_qos, input  Eo_type, input  Eo_src, input  Eo_tgt, input  Eo_data,
        input  Qo_vld, output Qo_rdy,
        input  Qo_qos, input  Qo_type, input  Qo_src, input  Qo_tgt, input  Qo_data,
        input  Ro_vld, output Ro_rdy,
        input  Ro_qos, input  Ro_type, input  Ro_src, input  Ro_tgt, input  Ro_data,

        // Connect to Node inputs (topology drives these)
        output Ni_vld, input  Ni_rdy,
        output Ni_qos, output Ni_type, output Ni_src, output Ni_tgt, output Ni_data,
        output Wi_vld, input  Wi_rdy,
        output Wi_qos, output Wi_type, output Wi_src, output Wi_tgt, output Wi_data,
        output Si_vld, input  Si_rdy,
        output Si_qos, output Si_type, output Si_src, output Si_tgt, output Si_data,
        output Ei_vld, input  Ei_rdy,
        output Ei_qos, output Ei_type, output Ei_src, output Ei_tgt, output Ei_data,
        output Qi_vld, input  Qi_rdy,
        output Qi_qos, output Qi_type, output Qi_src, output Qi_tgt, output Qi_data,
        output Ri_vld, input  Ri_rdy,
        output Ri_qos, output Ri_type, output Ri_src, output Ri_tgt, output Ri_data
    );

endinterface : pkt_con_if