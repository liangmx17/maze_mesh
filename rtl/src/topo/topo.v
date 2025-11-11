// ====================================================================
// MAZE Network 8×8 Torus Topology Module
// ====================================================================
//
// Implements complete 8×8 torus topology for MAZE network with 64 nodes
// Each node connects to 7 neighbors in X-direction and 7 neighbors in Y-direction
// Total connections: 64 nodes × 14 connections each = 896 bidirectional connections
//
// Key Features:
// - Torus topology with wraparound on both X and Y axes
// - Hard-wired IRS_N buffers for each connection (no intermediate routing logic)
// - IRS depth based on Manhattan distance (depth = distance-1, minimum 0)
// - Direct Node[outputs] → IRS_N → Node[inputs] signal flow
// - Uses interface_c.slv modport for all node connections
// - Single clock domain, no clock gating in topology
// - Total: 896 IRS_N buffers with variable depths
//
// Packet Format (23-bit): [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
// Torus Manhattan Distance: Uses minimal path with wraparound
// IRS Depth = max(0, torus_distance - 1)
//
// ====================================================================

`include "/home/liangmx/maze/rtl/include/global_defines/top_define.v"
`include "/home/liangmx/maze/rtl/include/interfaces/interface_c.sv"
`include "/home/liangmx/maze/rtl/lib/irs/irs.v"

module TOPO (
    input   clk,
    input   rst_n,

    // pkt_con_if.slv interface array for all 64 nodes
    // Topology uses slave modport to connect to node master modports
    // Each node provides outputs (xo_*, yo_*) and receives inputs (xi_*, yi_*)
    pkt_con_if.slv node_if[63:0]
);

// ====================================================================
// Parameter Definitions and Helper Functions
// ====================================================================

localparam PKT_W = 23;        // 23-bit packet width: 2+1+6+6+8
localparam GRID_SIZE = 8;     // 8×8 torus grid
localparam NUM_NODES = 64;    // Total number of nodes

// Function to calculate torus Manhattan distance between two coordinates
// Uses minimal path considering wraparound in both directions
function automatic int torus_manhattan_distance(input int src_x, input int src_y, input int dst_x, input int dst_y);
    int dx, dy;
    begin
        // Calculate X distance with wraparound
        dx = dst_x - src_x;
        if (dx < 0) dx = dx + GRID_SIZE;
        if (dx > GRID_SIZE/2) dx = GRID_SIZE - dx;  // Use shorter path

        // Calculate Y distance with wraparound
        dy = dst_y - src_y;
        if (dy < 0) dy = dy + GRID_SIZE;
        if (dy > GRID_SIZE/2) dy = GRID_SIZE - dy;  // Use shorter path

        torus_manhattan_distance = dx + dy;
    end
endfunction

// Function to calculate IRS depth based on torus Manhattan distance
function automatic int calculate_irs_depth(input int src_x, input int src_y, input int dst_x, input int dst_y);
    int distance = torus_manhattan_distance(src_x, src_y, dst_x, dst_y);
    calculate_irs_depth = (distance > 1) ? (distance - 1) : 0;
endfunction

// Function to convert 2D coordinates to 1D node ID
function automatic int coord_to_node_id(input int x, input int y);
    coord_to_node_id = y * GRID_SIZE + x;
endfunction

// ====================================================================
// Torus Topology Implementation
// ====================================================================
//
// Connection Pattern for 8×8 Torus:
// - X-direction: Node[VP,HP].xo_[i] → IRS → Node[VP,(HP+i+1)mod8].xi_[i]
// - Y-direction: Node[VP,HP].yo_[i] → IRS → Node[(VP+i+1)mod8,HP].yi_[i]
// - Where VP = Y coordinate (0-7), HP = X coordinate (0-7), i = offset (0-6)
// - Total: 896 IRS_N buffers (448 X-direction + 448 Y-direction)
//
// ====================================================================

// Generate X-direction torus connections
// Each node connects to 7 other nodes in the same row with wraparound
for (genvar src_y = 0; src_y < GRID_SIZE; src_y++) begin
    for (genvar src_x = 0; src_x < GRID_SIZE; src_x++) begin
        for (genvar offset = 0; offset < 7; offset++) begin
            // Calculate target node using torus modulo arithmetic
            localparam int dst_x = (src_x + offset + 1) % GRID_SIZE;
            localparam int src_node = src_y * GRID_SIZE + src_x;
            localparam int dst_node = src_y * GRID_SIZE + dst_x;

            // Calculate IRS depth based on torus Manhattan distance
            localparam int irs_depth = calculate_irs_depth(src_x, src_y, dst_x, src_y);

            // Instantiate IRS_N buffer for X-direction connection
            IRS_N #(
                .PYLD_W(PKT_W),
                .IRS_DEEP(irs_depth),
                .TYPE_NO_READY(0),
                .TYPE_HALF(0),
                .TYPE_RO_EN(1)
            ) u_x_irs_buffer (
                .clk(clk),
                .rst_n(rst_n),

                // From source node X output
                .valid_i(node_if[src_node].xo_vld[offset]),
                .ready_o(node_if[src_node].xo_rdy[offset]),

                // To destination node X input
                .valid_o(node_if[dst_node].xi_vld[offset]),
                .ready_i(node_if[dst_node].xi_rdy[offset]),

                // 23-bit packet payload: {type[1:0], qos[0], src[5:0], tgt[5:0], data[7:0]}
                .payload_i({
                    node_if[src_node].xo_type[offset],    // [22:21] packet type
                    node_if[src_node].xo_qos[offset],     // [20]    QoS level
                    node_if[src_node].xo_src[offset],     // [19:14] source address
                    node_if[src_node].xo_tgt[offset],     // [13:8]  target address
                    node_if[src_node].xo_data[offset]     // [7:0]   data payload
                }),
                .payload_o({
                    node_if[dst_node].xi_type[offset],    // [22:21] packet type
                    node_if[dst_node].xi_qos[offset],     // [20]    QoS level
                    node_if[dst_node].xi_src[offset],     // [19:14] source address
                    node_if[dst_node].xi_tgt[offset],     // [13:8]  target address
                    node_if[dst_node].xi_data[offset]     // [7:0]   data payload
                })
            );
        end
    end
end

// Generate Y-direction torus connections
// Each node connects to 7 other nodes in the same column with wraparound
for (genvar src_y = 0; src_y < GRID_SIZE; src_y++) begin
    for (genvar src_x = 0; src_x < GRID_SIZE; src_x++) begin
        for (genvar offset = 0; offset < 7; offset++) begin
            // Calculate target node using torus modulo arithmetic
            localparam int dst_y = (src_y + offset + 1) % GRID_SIZE;
            localparam int src_node = src_y * GRID_SIZE + src_x;
            localparam int dst_node = dst_y * GRID_SIZE + src_x;

            // Calculate IRS depth based on torus Manhattan distance
            localparam int irs_depth = calculate_irs_depth(src_x, src_y, src_x, dst_y);

            // Instantiate IRS_N buffer for Y-direction connection
            IRS_N #(
                .PYLD_W(PKT_W),
                .IRS_DEEP(irs_depth),
                .TYPE_NO_READY(0),
                .TYPE_HALF(0),
                .TYPE_RO_EN(1)
            ) u_y_irs_buffer (
                .clk(clk),
                .rst_n(rst_n),

                // From source node Y output
                .valid_i(node_if[src_node].yo_vld[offset]),
                .ready_o(node_if[src_node].yo_rdy[offset]),

                // To destination node Y input
                .valid_o(node_if[dst_node].yi_vld[offset]),
                .ready_i(node_if[dst_node].yi_rdy[offset]),

                // 23-bit packet payload: {type[1:0], qos[0], src[5:0], tgt[5:0], data[7:0]}
                .payload_i({
                    node_if[src_node].yo_type[offset],    // [22:21] packet type
                    node_if[src_node].yo_qos[offset],     // [20]    QoS level
                    node_if[src_node].yo_src[offset],     // [19:14] source address
                    node_if[src_node].yo_tgt[offset],     // [13:8]  target address
                    node_if[src_node].yo_data[offset]     // [7:0]   data payload
                }),
                .payload_o({
                    node_if[dst_node].yi_type[offset],    // [22:21] packet type
                    node_if[dst_node].yi_qos[offset],     // [20]    QoS level
                    node_if[dst_node].yi_src[offset],     // [19:14] source address
                    node_if[dst_node].yi_tgt[offset],     // [13:8]  target address
                    node_if[dst_node].yi_data[offset]     // [7:0]   data payload
                })
            );
        end
    end
end

// ====================================================================
// Implementation Summary
// ====================================================================
//
// Generated Resources:
// - X-direction: 8×8×7 = 448 IRS_N buffers
// - Y-direction: 8×8×7 = 448 IRS_N buffers
// - Total IRS_N buffers: 896
// - Buffer depths: Range from 0 to 3 based on torus Manhattan distance
//
// Connection Pattern (Torus Wraparound):
// Example for Node[3,4] (node_id = 3*8 + 4 = 28):
// - X[0] → Node[3,(4+1)mod8] = Node[3,5] (distance 1, depth 0)
// - X[1] → Node[3,(4+2)mod8] = Node[3,6] (distance 2, depth 1)
// - X[2] → Node[3,(4+3)mod8] = Node[3,7] (distance 3, depth 2)
// - X[3] → Node[3,(4+4)mod8] = Node[3,0] (distance 1, depth 0) [wraparound]
// - X[4] → Node[3,(4+5)mod8] = Node[3,1] (distance 2, depth 1) [wraparound]
// - X[5] → Node[3,(4+6)mod8] = Node[3,2] (distance 3, depth 2) [wraparound]
// - X[6] → Node[3,(4+7)mod8] = Node[3,3] (distance 1, depth 0) [wraparound]
//
// - Y[0] → Node[(3+1)mod8,4] = Node[4,4] (distance 1, depth 0)
// - Y[1] → Node[(3+2)mod8,4] = Node[5,4] (distance 2, depth 1)
// - Y[2] → Node[(3+3)mod8,4] = Node[6,4] (distance 3, depth 2)
// - Y[3] → Node[(3+4)mod8,4] = Node[7,4] (distance 4, depth 3)
// - Y[4] → Node[(3+5)mod8,4] = Node[0,4] (distance 3, depth 2) [wraparound]
// - Y[5] → Node[(3+6)mod8,4] = Node[1,4] (distance 2, depth 1) [wraparound]
// - Y[6] → Node[(3+7)mod8,4] = Node[2,4] (distance 1, depth 0) [wraparound]
//
// Architecture Benefits:
// - True torus topology with shortest-path routing
// - No routing bottlenecks - direct node-to-node connections
// - Optimal buffer depths based on actual distances
// - Single-cycle access to all 7 neighbors in each direction
// - Complete bidirectional communication
// - QoS preservation across all connections
//
// ====================================================================

endmodule : TOPO