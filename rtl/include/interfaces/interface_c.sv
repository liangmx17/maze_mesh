`include "global_defines/top_define.v"

// C Interface - Bidirectional Network Topology Connections
// Single interface that includes both input and output connections
// Each node has 7 X-direction and 7 Y-direction bidirectional connections

interface pkt_con_if;
    // X-direction connections (7 bidirectional ports)
    // Connect nodes with same X coordinate, different Y coordinates
    logic [6:0] x_vld, x_rdy;        // Valid/Ready signals
    logic [6:0] x_qos;               // QoS levels
    logic [1:0] x_type [6:0];        // Packet types
    logic [`ID_W-1:0] x_src [6:0];   // Source node IDs
    logic [`ID_W-1:0] x_tgt [6:0];   // Target node IDs
    logic [`FLIT_W-1:0] x_data [6:0]; // Data payloads

    // Y-direction connections (7 bidirectional ports)
    // Connect nodes with same Y coordinate, different X coordinates
    logic [6:0] y_vld, y_rdy;        // Valid/Ready signals
    logic [6:0] y_qos;               // QoS levels
    logic [1:0] y_type [6:0];        // Packet types
    logic [`ID_W-1:0] y_src [6:0];   // Source node IDs
    logic [`ID_W-1:0] y_tgt [6:0];   // Target node IDs
    logic [`FLIT_W-1:0] y_data [6:0]; // Data payloads

    // Modport for master side (driving outputs)
    modport master (
        output x_vld, input  x_rdy,
        output x_qos, output x_type, output x_src, output x_tgt, output x_data,
        output y_vld, input  y_rdy,
        output y_qos, output y_type, output y_src, output y_tgt, output y_data
    );

    // Modport for slave side (receiving inputs)
    modport slave (
        input  x_vld, output x_rdy,
        input  x_qos, input  x_type, input  x_src, input  x_tgt, input  x_data,
        input  y_vld, output y_rdy,
        input  y_qos, input  y_type, input  y_src, input  y_tgt, input  y_data
    );
endinterface : pkt_con_if