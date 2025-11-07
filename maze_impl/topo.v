`include "top_define.v"

module TOPO (
    input clk,
    input rst_n,
    // 节点到拓扑的输出接口 (mst端)
    pkt_con_if.mst pkt_con_if_0,
    pkt_con_if.mst pkt_con_if_1,
    pkt_con_if.mst pkt_con_if_2,
    pkt_con_if.mst pkt_con_if_3,
    pkt_con_if.mst pkt_con_if_4,
    pkt_con_if.mst pkt_con_if_5,
    pkt_con_if.mst pkt_con_if_6,
    pkt_con_if.mst pkt_con_if_7,
    pkt_con_if.mst pkt_con_if_8,
    pkt_con_if.mst pkt_con_if_9,
    pkt_con_if.mst pkt_con_if_10,
    pkt_con_if.mst pkt_con_if_11,
    pkt_con_if.mst pkt_con_if_12,
    pkt_con_if.mst pkt_con_if_13,
    pkt_con_if.mst pkt_con_if_14,
    pkt_con_if.mst pkt_con_if_15,
    pkt_con_if.mst pkt_con_if_16,
    pkt_con_if.mst pkt_con_if_17,
    pkt_con_if.mst pkt_con_if_18,
    pkt_con_if.mst pkt_con_if_19,
    pkt_con_if.mst pkt_con_if_20,
    pkt_con_if.mst pkt_con_if_21,
    pkt_con_if.mst pkt_con_if_22,
    pkt_con_if.mst pkt_con_if_23,
    pkt_con_if.mst pkt_con_if_24,
    pkt_con_if.mst pkt_con_if_25,
    pkt_con_if.mst pkt_con_if_26,
    pkt_con_if.mst pkt_con_if_27,
    pkt_con_if.mst pkt_con_if_28,
    pkt_con_if.mst pkt_con_if_29,
    pkt_con_if.mst pkt_con_if_30,
    pkt_con_if.mst pkt_con_if_31,
    pkt_con_if.mst pkt_con_if_32,
    pkt_con_if.mst pkt_con_if_33,
    pkt_con_if.mst pkt_con_if_34,
    pkt_con_if.mst pkt_con_if_35,
    pkt_con_if.mst pkt_con_if_36,
    pkt_con_if.mst pkt_con_if_37,
    pkt_con_if.mst pkt_con_if_38,
    pkt_con_if.mst pkt_con_if_39,
    pkt_con_if.mst pkt_con_if_40,
    pkt_con_if.mst pkt_con_if_41,
    pkt_con_if.mst pkt_con_if_42,
    pkt_con_if.mst pkt_con_if_43,
    pkt_con_if.mst pkt_con_if_44,
    pkt_con_if.mst pkt_con_if_45,
    pkt_con_if.mst pkt_con_if_46,
    pkt_con_if.mst pkt_con_if_47,
    pkt_con_if.mst pkt_con_if_48,
    pkt_con_if.mst pkt_con_if_49,
    pkt_con_if.mst pkt_con_if_50,
    pkt_con_if.mst pkt_con_if_51,
    pkt_con_if.mst pkt_con_if_52,
    pkt_con_if.mst pkt_con_if_53,
    pkt_con_if.mst pkt_con_if_54,
    pkt_con_if.mst pkt_con_if_55,
    pkt_con_if.mst pkt_con_if_56,
    pkt_con_if.mst pkt_con_if_57,
    pkt_con_if.mst pkt_con_if_58,
    pkt_con_if.mst pkt_con_if_59,
    pkt_con_if.mst pkt_con_if_60,
    pkt_con_if.mst pkt_con_if_61,
    pkt_con_if.mst pkt_con_if_62,
    pkt_con_if.mst pkt_con_if_63
);

// 将所有节点接口组织成数组
pkt_con_if.mst node_outputs [0:63] (
    .x_vld(pkt_con_if_0.x_vld, pkt_con_if_1.x_vld, pkt_con_if_2.x_vld, pkt_con_if_3.x_vld,
           pkt_con_if_4.x_vld, pkt_con_if_5.x_vld, pkt_con_if_6.x_vld, pkt_con_if_7.x_vld,
           pkt_con_if_8.x_vld, pkt_con_if_9.x_vld, pkt_con_if_10.x_vld, pkt_con_if_11.x_vld,
           pkt_con_if_12.x_vld, pkt_con_if_13.x_vld, pkt_con_if_14.x_vld, pkt_con_if_15.x_vld,
           pkt_con_if_16.x_vld, pkt_con_if_17.x_vld, pkt_con_if_18.x_vld, pkt_con_if_19.x_vld,
           pkt_con_if_20.x_vld, pkt_con_if_21.x_vld, pkt_con_if_22.x_vld, pkt_con_if_23.x_vld,
           pkt_con_if_24.x_vld, pkt_con_if_25.x_vld, pkt_con_if_26.x_vld, pkt_con_if_27.x_vld,
           pkt_con_if_28.x_vld, pkt_con_if_29.x_vld, pkt_con_if_30.x_vld, pkt_con_if_31.x_vld,
           pkt_con_if_32.x_vld, pkt_con_if_33.x_vld, pkt_con_if_34.x_vld, pkt_con_if_35.x_vld,
           pkt_con_if_36.x_vld, pkt_con_if_37.x_vld, pkt_con_if_38.x_vld, pkt_con_if_39.x_vld,
           pkt_con_if_40.x_vld, pkt_con_if_41.x_vld, pkt_con_if_42.x_vld, pkt_con_if_43.x_vld,
           pkt_con_if_44.x_vld, pkt_con_if_45.x_vld, pkt_con_if_46.x_vld, pkt_con_if_47.x_vld,
           pkt_con_if_48.x_vld, pkt_con_if_49.x_vld, pkt_con_if_50.x_vld, pkt_con_if_51.x_vld,
           pkt_con_if_52.x_vld, pkt_con_if_53.x_vld, pkt_con_if_54.x_vld, pkt_con_if_55.x_vld,
           pkt_con_if_56.x_vld, pkt_con_if_57.x_vld, pkt_con_if_58.x_vld, pkt_con_if_59.x_vld,
           pkt_con_if_60.x_vld, pkt_con_if_61.x_vld, pkt_con_if_62.x_vld, pkt_con_if_63.x_vld),
    // 注意：这里只是示意，实际的SystemVerilog接口数组语法可能需要调整
);

// 拓扑连接实现
// 根据8x8网格的连接规则，每个节点需要连接到：
// 1. 相同x坐标的其他7个节点 (Y方向连接)
// 2. 相同y坐标的其他7个节点 (X方向连接)

// 数据包宽度定义
localparam PACKET_WIDTH = 1 + 1 + `TYPE_W + `ID_W + `ID_W + `FLIT_W; // vld + qos + type + src + tgt + data

// 生成节点间的连接
genvar src_node, dst_node;
generate
    for (src_node = 0; src_node < 64; src_node = src_node + 1) begin : src_connections
        // 获取源节点坐标
        localparam src_x = src_node % 8;
        localparam src_y = src_node / 8;

        // X方向连接 (相同x坐标，不同y坐标)
        for (dst_node = 0; dst_node < 64; dst_node = dst_node + 1) begin : x_direction_connections
            localparam dst_x = dst_node % 8;
            localparam dst_y = dst_node / 8;

            // 只有x坐标相同且不是同一节点时才连接
            if (src_x == dst_x && src_node != dst_node) begin : x_connect
                localparam manhattan_distance = abs(src_y - dst_y);
                localparam irs_depth = (manhattan_distance > 0) ? (manhattan_distance - 1) : 0;

                // 连接源节点的Y方向输出到目标节点的X方向输入
                wire [PACKET_WIDTH-1:0] x_packet_from_src;
                wire [PACKET_WIDTH-1:0] x_packet_to_dst;
                wire x_valid_from_src, x_ready_to_src, x_valid_to_dst, x_ready_from_dst;

                // 组装数据包
                assign x_packet_from_src = {
                    node_outputs[src_node].y_vld[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)],
                    node_outputs[src_node].y_qos[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)],
                    node_outputs[src_node].y_type[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)],
                    node_outputs[src_node].y_src[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)],
                    node_outputs[src_node].y_tgt[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)],
                    node_outputs[src_node].y_data[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)]
                };

                assign x_valid_from_src = node_outputs[src_node].y_vld[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)];
                assign node_outputs[src_node].y_rdy[dst_y > src_y ? (dst_y - src_y - 1) : (src_y - dst_y - 1)] = x_ready_to_src;

                // IRS模块实例化
                IRS_N #(
                    .PYLD_W(PACKET_WIDTH),
                    .IRS_DEEP(irs_depth),
                    .TYPE_NO_READY(0),
                    .TYPE_HALF(0),
                    .TYPE_RO_EN(1)
                ) x_irs_inst (
                    .clk(clk),
                    .rst_n(rst_n),
                    .valid_i(x_valid_from_src),
                    .ready_i(x_ready_from_dst),
                    .valid_o(x_valid_to_dst),
                    .ready_o(x_ready_to_src),
                    .payload_i(x_packet_from_src),
                    .payload_o(x_packet_to_dst)
                );

                // 将数据包连接到目标节点 (这里需要实际的节点输入接口)
                // 暂时省略具体连接，需要在完整实现中处理

            end
        end

        // Y方向连接 (相同y坐标，不同x坐标)
        for (dst_node = 0; dst_node < 64; dst_node = dst_node + 1) begin : y_direction_connections
            localparam dst_x = dst_node % 8;
            localparam dst_y = dst_node / 8;

            // 只有y坐标相同且不是同一节点时才连接
            if (src_y == dst_y && src_node != dst_node) begin : y_connect
                localparam manhattan_distance = abs(src_x - dst_x);
                localparam irs_depth = (manhattan_distance > 0) ? (manhattan_distance - 1) : 0;

                // 连接源节点的X方向输出到目标节点的Y方向输入
                wire [PACKET_WIDTH-1:0] y_packet_from_src;
                wire [PACKET_WIDTH-1:0] y_packet_to_dst;
                wire y_valid_from_src, y_ready_to_src, y_valid_to_dst, y_ready_from_dst;

                // 组装数据包
                assign y_packet_from_src = {
                    node_outputs[src_node].x_vld[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)],
                    node_outputs[src_node].x_qos[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)],
                    node_outputs[src_node].x_type[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)],
                    node_outputs[src_node].x_src[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)],
                    node_outputs[src_node].x_tgt[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)],
                    node_outputs[src_node].x_data[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)]
                };

                assign y_valid_from_src = node_outputs[src_node].x_vld[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)];
                assign node_outputs[src_node].x_rdy[dst_x > src_x ? (dst_x - src_x - 1) : (src_x - dst_x - 1)] = y_ready_to_src;

                // IRS模块实例化
                IRS_N #(
                    .PYLD_W(PACKET_WIDTH),
                    .IRS_DEEP(irs_depth),
                    .TYPE_NO_READY(0),
                    .TYPE_HALF(0),
                    .TYPE_RO_EN(1)
                ) y_irs_inst (
                    .clk(clk),
                    .rst_n(rst_n),
                    .valid_i(y_valid_from_src),
                    .ready_i(y_ready_from_dst),
                    .valid_o(y_valid_to_dst),
                    .ready_o(y_ready_to_src),
                    .payload_i(y_packet_from_src),
                    .payload_o(y_packet_to_dst)
                );

                // 将数据包连接到目标节点 (这里需要实际的节点输入接口)
                // 暂时省略具体连接，需要在完整实现中处理

            end
        end
    end
endgenerate

// 绝对值函数 (使用组合逻辑)
function automatic integer abs(input integer val);
    abs = (val < 0) ? -val : val;
endfunction

endmodule