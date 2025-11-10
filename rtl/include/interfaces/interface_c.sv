// C Interface - Network Topology Connections
// 28 separate ports: 7x input, 7y input, 7x output, 7y output
// Each node connects to 7 nodes in X-direction and 7 nodes in Y-direction
// Note: This interface expects the following defines to be set before inclusion:
// `define QOS_W 1
// `define ID_W 6
// `define FLIT_W 8

interface pkt_con_if;

    // X-direction INPUT ports (7 connections) - data coming FROM other nodes
    // Connect nodes with same X coordinate, different Y coordinates
    logic [6:0] xi_vld;                // Input valid signals
    logic [6:0] xi_rdy;                // Input ready signals
    logic [6:0] xi_qos;                // Input QoS levels
    logic [1:0] xi_type [6:0];         // Input packet types
    logic [`ID_W-1:0] xi_src [6:0];     // Input source node IDs
    logic [`ID_W-1:0] xi_tgt [6:0];     // Input target node IDs
    logic [`FLIT_W-1:0] xi_data [6:0];  // Input data payloads

    // Y-direction INPUT ports (7 connections) - data coming FROM other nodes
    // Connect nodes with same Y coordinate, different X coordinates
    logic [6:0] yi_vld;                // Input valid signals
    logic [6:0] yi_rdy;                // Input ready signals
    logic [6:0] yi_qos;                // Input QoS levels
    logic [1:0] yi_type [6:0];         // Input packet types
    logic [`ID_W-1:0] yi_src [6:0];     // Input source node IDs
    logic [`ID_W-1:0] yi_tgt [6:0];     // Input target node IDs
    logic [`FLIT_W-1:0] yi_data [6:0];  // Input data payloads

    // X-direction OUTPUT ports (7 connections) - data going TO other nodes
    // Connect nodes with same X coordinate, different Y coordinates
    logic [6:0] xo_vld;                // Output valid signals
    logic [6:0] xo_rdy;                // Output ready signals
    logic [6:0] xo_qos;                // Output QoS levels
    logic [1:0] xo_type [6:0];         // Output packet types
    logic [`ID_W-1:0] xo_src [6:0];     // Output source node IDs
    logic [`ID_W-1:0] xo_tgt [6:0];     // Output target node IDs
    logic [`FLIT_W-1:0] xo_data [6:0];  // Output data payloads

    // Y-direction OUTPUT ports (7 connections) - data going TO other nodes
    // Connect nodes with same Y coordinate, different X coordinates
    logic [6:0] yo_vld;                // Output valid signals
    logic [6:0] yo_rdy;                // Output ready signals
    logic [6:0] yo_qos;                // Output QoS levels
    logic [1:0] yo_type [6:0];         // Output packet types
    logic [`ID_W-1:0] yo_src [6:0];     // Output source node IDs
    logic [`ID_W-1:0] yo_tgt [6:0];     // Output target node IDs
    logic [`FLIT_W-1:0] yo_data [6:0];  // Output data payloads

    // Modport for master connections (nodes)
    // Node drives output ports (xo_*, yo_*) and receives from input ports (xi_*, yi_*)
    modport mst (
        // Input ports (node receives data from these)
        input  xi_vld, output xi_rdy,
        input  xi_qos, input  xi_type, input  xi_src, input  xi_tgt, input  xi_data,
        input  yi_vld, output yi_rdy,
        input  yi_qos, input  yi_type, input  yi_src, input  yi_tgt, input  yi_data,

        // Output ports (node drives data to these)
        output xo_vld, input  xo_rdy,
        output xo_qos, output xo_type, output xo_src, output xo_tgt, output xo_data,
        output yo_vld, input  yo_rdy,
        output yo_qos, output yo_type, output yo_src, output yo_tgt, output yo_data
    );

    // Modport for slave connections (topology)
    // Used by topo module to connect nodes together
    modport slv (
        // Connect to node outputs (topology receives these)
        input  xo_vld, output xo_rdy,
        input  xo_qos, input  xo_type, input  xo_src, input  xo_tgt, input  xo_data,
        input  yo_vld, output yo_rdy,
        input  yo_qos, input  yo_type, input  yo_src, input  yo_tgt, input  yo_data,

        // Connect to node inputs (topology drives these)
        output xi_vld, output xi_rdy,
        output xi_qos, output xi_type, output xi_src, output xi_tgt, output xi_data,
        output yi_vld, output yi_rdy,
        output yi_qos, output yi_type, output yi_src, output yi_tgt, output yi_data
    );

endinterface : pkt_con_if