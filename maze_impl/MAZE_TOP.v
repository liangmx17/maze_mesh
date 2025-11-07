`include "top_define.v"

module MAZE_TOP (
    input clk,
    input rst_n,
    input pg_en,              // 故障使能信号
    input [`ID_W-1:0] pg_node, // 故障节点坐标

    // 64个节点的A口输入
    pkt_in.mst pkt_in_0,
    pkt_in.mst pkt_in_1,
    pkt_in.mst pkt_in_2,
    pkt_in.mst pkt_in_3,
    pkt_in.mst pkt_in_4,
    pkt_in.mst pkt_in_5,
    pkt_in.mst pkt_in_6,
    pkt_in.mst pkt_in_7,
    pkt_in.mst pkt_in_8,
    pkt_in.mst pkt_in_9,
    pkt_in.mst pkt_in_10,
    pkt_in.mst pkt_in_11,
    pkt_in.mst pkt_in_12,
    pkt_in.mst pkt_in_13,
    pkt_in.mst pkt_in_14,
    pkt_in.mst pkt_in_15,
    pkt_in.mst pkt_in_16,
    pkt_in.mst pkt_in_17,
    pkt_in.mst pkt_in_18,
    pkt_in.mst pkt_in_19,
    pkt_in.mst pkt_in_20,
    pkt_in.mst pkt_in_21,
    pkt_in.mst pkt_in_22,
    pkt_in.mst pkt_in_23,
    pkt_in.mst pkt_in_24,
    pkt_in.mst pkt_in_25,
    pkt_in.mst pkt_in_26,
    pkt_in.mst pkt_in_27,
    pkt_in.mst pkt_in_28,
    pkt_in.mst pkt_in_29,
    pkt_in.mst pkt_in_30,
    pkt_in.mst pkt_in_31,
    pkt_in.mst pkt_in_32,
    pkt_in.mst pkt_in_33,
    pkt_in.mst pkt_in_34,
    pkt_in.mst pkt_in_35,
    pkt_in.mst pkt_in_36,
    pkt_in.mst pkt_in_37,
    pkt_in.mst pkt_in_38,
    pkt_in.mst pkt_in_39,
    pkt_in.mst pkt_in_40,
    pkt_in.mst pkt_in_41,
    pkt_in.mst pkt_in_42,
    pkt_in.mst pkt_in_43,
    pkt_in.mst pkt_in_44,
    pkt_in.mst pkt_in_45,
    pkt_in.mst pkt_in_46,
    pkt_in.mst pkt_in_47,
    pkt_in.mst pkt_in_48,
    pkt_in.mst pkt_in_49,
    pkt_in.mst pkt_in_50,
    pkt_in.mst pkt_in_51,
    pkt_in.mst pkt_in_52,
    pkt_in.mst pkt_in_53,
    pkt_in.mst pkt_in_54,
    pkt_in.mst pkt_in_55,
    pkt_in.mst pkt_in_56,
    pkt_in.mst pkt_in_57,
    pkt_in.mst pkt_in_58,
    pkt_in.mst pkt_in_59,
    pkt_in.mst pkt_in_60,
    pkt_in.mst pkt_in_61,
    pkt_in.mst pkt_in_62,
    pkt_in.mst pkt_in_63,

    // 64个节点的B口输出
    pkt_out.mst pkt_out_0,
    pkt_out.mst pkt_out_1,
    pkt_out.mst pkt_out_2,
    pkt_out.mst pkt_out_3,
    pkt_out.mst pkt_out_4,
    pkt_out.mst pkt_out_5,
    pkt_out.mst pkt_out_6,
    pkt_out.mst pkt_out_7,
    pkt_out.mst pkt_out_8,
    pkt_out.mst pkt_out_9,
    pkt_out.mst pkt_out_10,
    pkt_out.mst pkt_out_11,
    pkt_out.mst pkt_out_12,
    pkt_out.mst pkt_out_13,
    pkt_out.mst pkt_out_14,
    pkt_out.mst pkt_out_15,
    pkt_out.mst pkt_out_16,
    pkt_out.mst pkt_out_17,
    pkt_out.mst pkt_out_18,
    pkt_out.mst pkt_out_19,
    pkt_out.mst pkt_out_20,
    pkt_out.mst pkt_out_21,
    pkt_out.mst pkt_out_22,
    pkt_out.mst pkt_out_23,
    pkt_out.mst pkt_out_24,
    pkt_out.mst pkt_out_25,
    pkt_out.mst pkt_out_26,
    pkt_out.mst pkt_out_27,
    pkt_out.mst pkt_out_28,
    pkt_out.mst pkt_out_29,
    pkt_out.mst pkt_out_30,
    pkt_out.mst pkt_out_31,
    pkt_out.mst pkt_out_32,
    pkt_out.mst pkt_out_33,
    pkt_out.mst pkt_out_34,
    pkt_out.mst pkt_out_35,
    pkt_out.mst pkt_out_36,
    pkt_out.mst pkt_out_37,
    pkt_out.mst pkt_out_38,
    pkt_out.mst pkt_out_39,
    pkt_out.mst pkt_out_40,
    pkt_out.mst pkt_out_41,
    pkt_out.mst pkt_out_42,
    pkt_out.mst pkt_out_43,
    pkt_out.mst pkt_out_44,
    pkt_out.mst pkt_out_45,
    pkt_out.mst pkt_out_46,
    pkt_out.mst pkt_out_47,
    pkt_out.mst pkt_out_48,
    pkt_out.mst pkt_out_49,
    pkt_out.mst pkt_out_50,
    pkt_out.mst pkt_out_51,
    pkt_out.mst pkt_out_52,
    pkt_out.mst pkt_out_53,
    pkt_out.mst pkt_out_54,
    pkt_out.mst pkt_out_55,
    pkt_out.mst pkt_out_56,
    pkt_out.mst pkt_out_57,
    pkt_out.mst pkt_out_58,
    pkt_out.mst pkt_out_59,
    pkt_out.mst pkt_out_60,
    pkt_out.mst pkt_out_61,
    pkt_out.mst pkt_out_62,
    pkt_out.mst pkt_out_63
);

// 64个C接口信号
pkt_con_if node_to_topo [0:63] ();
pkt_con_if topo_to_node [0:63] ();

// 生成64个节点
genvar node_idx;
generate
    for (node_idx = 0; node_idx < 64; node_idx = node_idx + 1) begin : node_gen
        // 计算节点坐标
        localparam node_hp = node_idx % 8;    // 水平坐标 (0-7)
        localparam node_vp = node_idx / 8;    // 垂直坐标 (0-7)
        localparam node_coord = {node_vp[2:0], node_hp[2:0]};

        // 时钟门控 (故障节点没有时钟)
        wire node_clk;
        assign node_clk = (pg_en && (pg_node == node_coord)) ? 1'b0 : clk;

        // 节点实例化
        node #(
            .HP(node_hp),
            .VP(node_vp)
        ) u_node (
            .clk(node_clk),
            .rst_n(rst_n),
            .pg_en(pg_en),
            .pg_node(pg_node),
            .pkt_i(get_pkt_in(node_idx)),
            .pkt_o(get_pkt_out(node_idx)),
            .pkt_con_in(topo_to_node[node_idx]),
            .pkt_con_out(node_to_topo[node_idx])
        );

        // 输入接口选择函数
        function automatic pkt_in get_pkt_in(input integer idx);
            case (idx)
                0:  get_pkt_in = pkt_in_0;
                1:  get_pkt_in = pkt_in_1;
                2:  get_pkt_in = pkt_in_2;
                3:  get_pkt_in = pkt_in_3;
                4:  get_pkt_in = pkt_in_4;
                5:  get_pkt_in = pkt_in_5;
                6:  get_pkt_in = pkt_in_6;
                7:  get_pkt_in = pkt_in_7;
                8:  get_pkt_in = pkt_in_8;
                9:  get_pkt_in = pkt_in_9;
                10: get_pkt_in = pkt_in_10;
                11: get_pkt_in = pkt_in_11;
                12: get_pkt_in = pkt_in_12;
                13: get_pkt_in = pkt_in_13;
                14: get_pkt_in = pkt_in_14;
                15: get_pkt_in = pkt_in_15;
                16: get_pkt_in = pkt_in_16;
                17: get_pkt_in = pkt_in_17;
                18: get_pkt_in = pkt_in_18;
                19: get_pkt_in = pkt_in_19;
                20: get_pkt_in = pkt_in_20;
                21: get_pkt_in = pkt_in_21;
                22: get_pkt_in = pkt_in_22;
                23: get_pkt_in = pkt_in_23;
                24: get_pkt_in = pkt_in_24;
                25: get_pkt_in = pkt_in_25;
                26: get_pkt_in = pkt_in_26;
                27: get_pkt_in = pkt_in_27;
                28: get_pkt_in = pkt_in_28;
                29: get_pkt_in = pkt_in_29;
                30: get_pkt_in = pkt_in_30;
                31: get_pkt_in = pkt_in_31;
                32: get_pkt_in = pkt_in_32;
                33: get_pkt_in = pkt_in_33;
                34: get_pkt_in = pkt_in_34;
                35: get_pkt_in = pkt_in_35;
                36: get_pkt_in = pkt_in_36;
                37: get_pkt_in = pkt_in_37;
                38: get_pkt_in = pkt_in_38;
                39: get_pkt_in = pkt_in_39;
                40: get_pkt_in = pkt_in_40;
                41: get_pkt_in = pkt_in_41;
                42: get_pkt_in = pkt_in_42;
                43: get_pkt_in = pkt_in_43;
                44: get_pkt_in = pkt_in_44;
                45: get_pkt_in = pkt_in_45;
                46: get_pkt_in = pkt_in_46;
                47: get_pkt_in = pkt_in_47;
                48: get_pkt_in = pkt_in_48;
                49: get_pkt_in = pkt_in_49;
                50: get_pkt_in = pkt_in_50;
                51: get_pkt_in = pkt_in_51;
                52: get_pkt_in = pkt_in_52;
                53: get_pkt_in = pkt_in_53;
                54: get_pkt_in = pkt_in_54;
                55: get_pkt_in = pkt_in_55;
                56: get_pkt_in = pkt_in_56;
                57: get_pkt_in = pkt_in_57;
                58: get_pkt_in = pkt_in_58;
                59: get_pkt_in = pkt_in_59;
                60: get_pkt_in = pkt_in_60;
                61: get_pkt_in = pkt_in_61;
                62: get_pkt_in = pkt_in_62;
                63: get_pkt_in = pkt_in_63;
                default: get_pkt_in = pkt_in_0;
            endcase
        endfunction

        // 输出接口选择函数
        function automatic pkt_out get_pkt_out(input integer idx);
            case (idx)
                0:  get_pkt_out = pkt_out_0;
                1:  get_pkt_out = pkt_out_1;
                2:  get_pkt_out = pkt_out_2;
                3:  get_pkt_out = pkt_out_3;
                4:  get_pkt_out = pkt_out_4;
                5:  get_pkt_out = pkt_out_5;
                6:  get_pkt_out = pkt_out_6;
                7:  get_pkt_out = pkt_out_7;
                8:  get_pkt_out = pkt_out_8;
                9:  get_pkt_out = pkt_out_9;
                10: get_pkt_out = pkt_out_10;
                11: get_pkt_out = pkt_out_11;
                12: get_pkt_out = pkt_out_12;
                13: get_pkt_out = pkt_out_13;
                14: get_pkt_out = pkt_out_14;
                15: get_pkt_out = pkt_out_15;
                16: get_pkt_out = pkt_out_16;
                17: get_pkt_out = pkt_out_17;
                18: get_pkt_out = pkt_out_18;
                19: get_pkt_out = pkt_out_19;
                20: get_pkt_out = pkt_out_20;
                21: get_pkt_out = pkt_out_21;
                22: get_pkt_out = pkt_out_22;
                23: get_pkt_out = pkt_out_23;
                24: get_pkt_out = pkt_out_24;
                25: get_pkt_out = pkt_out_25;
                26: get_pkt_out = pkt_out_26;
                27: get_pkt_out = pkt_out_27;
                28: get_pkt_out = pkt_out_28;
                29: get_pkt_out = pkt_out_29;
                30: get_pkt_out = pkt_out_30;
                31: get_pkt_out = pkt_out_31;
                32: get_pkt_out = pkt_out_32;
                33: get_pkt_out = pkt_out_33;
                34: get_pkt_out = pkt_out_34;
                35: get_pkt_out = pkt_out_35;
                36: get_pkt_out = pkt_out_36;
                37: get_pkt_out = pkt_out_37;
                38: get_pkt_out = pkt_out_38;
                39: get_pkt_out = pkt_out_39;
                40: get_pkt_out = pkt_out_40;
                41: get_pkt_out = pkt_out_41;
                42: get_pkt_out = pkt_out_42;
                43: get_pkt_out = pkt_out_43;
                44: get_pkt_out = pkt_out_44;
                45: get_pkt_out = pkt_out_45;
                46: get_pkt_out = pkt_out_46;
                47: get_pkt_out = pkt_out_47;
                48: get_pkt_out = pkt_out_48;
                49: get_pkt_out = pkt_out_49;
                50: get_pkt_out = pkt_out_50;
                51: get_pkt_out = pkt_out_51;
                52: get_pkt_out = pkt_out_52;
                53: get_pkt_out = pkt_out_53;
                54: get_pkt_out = pkt_out_54;
                55: get_pkt_out = pkt_out_55;
                56: get_pkt_out = pkt_out_56;
                57: get_pkt_out = pkt_out_57;
                58: get_pkt_out = pkt_out_58;
                59: get_pkt_out = pkt_out_59;
                60: get_pkt_out = pkt_out_60;
                61: get_pkt_out = pkt_out_61;
                62: get_pkt_out = pkt_out_62;
                63: get_pkt_out = pkt_out_63;
                default: get_pkt_out = pkt_out_0;
            endcase
        endfunction
    end
endgenerate

// 简化的拓扑连接 (直接连接，暂不使用IRS)
// 对于完整的实现，需要根据曼哈顿距离使用适当的IRS深度
generate
    for (node_idx = 0; node_idx < 64; node_idx = node_idx + 1) begin : topo_connections
        localparam node_hp = node_idx % 8;
        localparam node_vp = node_idx / 8;

        // 暂时将C接口接地 (无连接)
        assign topo_to_node[node_idx].x_vld = '0;
        assign topo_to_node[node_idx].x_qos = '0;
        assign topo_to_node[node_idx].x_type = '0;
        assign topo_to_node[node_idx].x_src = '0;
        assign topo_to_node[node_idx].x_tgt = '0;
        assign topo_to_node[node_idx].x_data = '0;
        assign topo_to_node[node_idx].y_vld = '0;
        assign topo_to_node[node_idx].y_qos = '0;
        assign topo_to_node[node_idx].y_type = '0;
        assign topo_to_node[node_idx].y_src = '0;
        assign topo_to_node[node_idx].y_tgt = '0;
        assign topo_to_node[node_idx].y_data = '0;
    end
endgenerate

endmodule
