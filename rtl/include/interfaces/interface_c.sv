// C Interface - Network Topology Connections (NWSE 4-Direction Mesh)
// 8 separate ports: N input, W input, S input, E input, N output, W output, S output, E output
// Each node connects to 4 neighbors in North, West, South, East directions
// Note: This interface expects the following defines to be set before inclusion:
// `define QOS_W 1
// `define ID_W 6
// `define FLIT_W 8

interface pkt_con_if;

    // INPUT ports - data coming FROM other nodes
    logic ni_vld;                       // North Input valid signal
    logic ni_rdy;                       // North Input ready signal
    logic ni_qos;                       // North Input QoS level
    logic [1:0] ni_type;                // North Input packet type
    logic [`ID_W-1:0] ni_src;           // North Input source node ID
    logic [`ID_W-1:0] ni_tgt;           // North Input target node ID
    logic [`FLIT_W-1:0] ni_data;        // North Input data payload

    logic wi_vld;                       // West Input valid signal
    logic wi_rdy;                       // West Input ready signal
    logic wi_qos;                       // West Input QoS level
    logic [1:0] wi_type;                // West Input packet type
    logic [`ID_W-1:0] wi_src;           // West Input source node ID
    logic [`ID_W-1:0] wi_tgt;           // West Input target node ID
    logic [`FLIT_W-1:0] wi_data;        // West Input data payload

    logic si_vld;                       // South Input valid signal
    logic si_rdy;                       // South Input ready signal
    logic si_qos;                       // South Input QoS level
    logic [1:0] si_type;                // South Input packet type
    logic [`ID_W-1:0] si_src;           // South Input source node ID
    logic [`ID_W-1:0] si_tgt;           // South Input target node ID
    logic [`FLIT_W-1:0] si_data;        // South Input data payload

    logic ei_vld;                       // East Input valid signal
    logic ei_rdy;                       // East Input ready signal
    logic ei_qos;                       // East Input QoS level
    logic [1:0] ei_type;                // East Input packet type
    logic [`ID_W-1:0] ei_src;           // East Input source node ID
    logic [`ID_W-1:0] ei_tgt;           // East Input target node ID
    logic [`FLIT_W-1:0] ei_data;        // East Input data payload

    // OUTPUT ports - data going TO other nodes
    logic no_vld;                       // North Output valid signal
    logic no_rdy;                       // North Output ready signal
    logic no_qos;                       // North Output QoS level
    logic [1:0] no_type;                // North Output packet type
    logic [`ID_W-1:0] no_src;           // North Output source node ID
    logic [`ID_W-1:0] no_tgt;           // North Output target node ID
    logic [`FLIT_W-1:0] no_data;        // North Output data payload

    logic wo_vld;                       // West Output valid signal
    logic wo_rdy;                       // West Output ready signal
    logic wo_qos;                       // West Output QoS level
    logic [1:0] wo_type;                // West Output packet type
    logic [`ID_W-1:0] wo_src;           // West Output source node ID
    logic [`ID_W-1:0] wo_tgt;           // West Output target node ID
    logic [`FLIT_W-1:0] wo_data;        // West Output data payload

    logic so_vld;                       // South Output valid signal
    logic so_rdy;                       // South Output ready signal
    logic so_qos;                       // South Output QoS level
    logic [1:0] so_type;                // South Output packet type
    logic [`ID_W-1:0] so_src;           // South Output source node ID
    logic [`ID_W-1:0] so_tgt;           // South Output target node ID
    logic [`FLIT_W-1:0] so_data;        // South Output data payload

    logic eo_vld;                       // East Output valid signal
    logic eo_rdy;                       // East Output ready signal
    logic eo_qos;                       // East Output QoS level
    logic [1:0] eo_type;                // East Output packet type
    logic [`ID_W-1:0] eo_src;           // East Output source node ID
    logic [`ID_W-1:0] eo_tgt;           // East Output target node ID
    logic [`FLIT_W-1:0] eo_data;        // East Output data payload

    // Modport for master connections (nodes)
    // Node drives output ports (no_*, wo_*, so_*, eo_*) and receives from input ports (ni_*, wi_*, si_*, ei_*)
    modport mst (
        // Input ports (node receives data from these)
        input  ni_vld, output ni_rdy,
        input  ni_qos, input  ni_type, input  ni_src, input  ni_tgt, input  ni_data,
        input  wi_vld, output wi_rdy,
        input  wi_qos, input  wi_type, input  wi_src, input  wi_tgt, input  wi_data,
        input  si_vld, output si_rdy,
        input  si_qos, input  si_type, input  si_src, input  si_tgt, input  si_data,
        input  ei_vld, output ei_rdy,
        input  ei_qos, input  ei_type, input  ei_src, input  ei_tgt, input  ei_data,

        // Output ports (node drives data to these)
        output no_vld, input  no_rdy,
        output no_qos, output no_type, output no_src, output no_tgt, output no_data,
        output wo_vld, input  wo_rdy,
        output wo_qos, output wo_type, output wo_src, output wo_tgt, output wo_data,
        output so_vld, input  so_rdy,
        output so_qos, output so_type, output so_src, output so_tgt, output so_data,
        output eo_vld, input  eo_rdy,
        output eo_qos, output eo_type, output eo_src, output eo_tgt, output eo_data
    );

    // Modport for slave connections (topology)
    // Used by topo module to connect nodes together
    modport slv (
        // Connect to node outputs (topology receives these)
        input  no_vld, output no_rdy,
        input  no_qos, input  no_type, input  no_src, input  no_tgt, input  no_data,
        input  wo_vld, output wo_rdy,
        input  wo_qos, input  wo_type, input  wo_src, input  wo_tgt, input  wo_data,
        input  so_vld, output so_rdy,
        input  so_qos, input  so_type, input  so_src, input  so_tgt, input  so_data,
        input  eo_vld, output eo_rdy,
        input  eo_qos, input  eo_type, input  eo_src, input  eo_tgt, input  eo_data,

        // Connect to node inputs (topology drives these)
        output ni_vld, output ni_rdy,
        output ni_qos, output ni_type, output ni_src, output ni_tgt, output ni_data,
        output wi_vld, output wi_rdy,
        output wi_qos, output wi_type, output wi_src, output wi_tgt, output wi_data,
        output si_vld, output si_rdy,
        output si_qos, output si_type, output si_src, output si_tgt, output si_data,
        output ei_vld, output ei_rdy,
        output ei_qos, output ei_type, output ei_src, output ei_tgt, output ei_data
    );

endinterface : pkt_con_if