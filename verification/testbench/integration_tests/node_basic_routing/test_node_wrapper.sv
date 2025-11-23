// =============================================================================
// MAZE节点测试包装器模块
// =============================================================================
// 功能说明：
// 1. 为node模块提供参数化实例化
// 2. 简化测试接口，便于Verilator调用
// 3. 支持动态配置节点位置和故障设置
// =============================================================================

`timescale 1ns/1ps

// 包含必要的定义文件
`include "rtl/top_define.v"

module test_node_wrapper #(
    parameter HP = 3,                    // 水平坐标 (0-7)
    parameter VP = 3                     // 垂直坐标 (0-7)
) (
    // 时钟和复位
    input  logic clk,
    input  logic rst_n,

    // 故障容错配置
    input  logic pg_en,                  // 故障使能信号
    input  logic [5:0] pg_node,          // 故障节点坐标

    // A接口 - 外部数据包输入（简化接口）
    input  logic pkt_i_pkt_in_vld,
    input  logic [1:0] pkt_i_pkt_in_type,
    input  logic pkt_i_pkt_in_qos,
    input  logic [5:0] pkt_i_pkt_in_src,
    input  logic [5:0] pkt_i_pkt_in_tgt,
    input  logic [7:0] pkt_i_pkt_in_data,
    output logic pkt_i_pkt_in_rdy,

    // B接口 - 外部数据包输出（简化接口）
    output logic pkt_o_pkt_out_vld,
    output logic [1:0] pkt_o_pkt_out_type,
    output logic pkt_o_pkt_out_qos,
    output logic [5:0] pkt_o_pkt_out_src,
    output logic [5:0] pkt_o_pkt_out_tgt,
    output logic [7:0] pkt_o_pkt_out_data,
    input  logic pkt_o_pkt_out_rdy,

    // C接口北方向输入
    input  logic pkt_con_ni_vld,
    input  logic [1:0] pkt_con_ni_type,
    input  logic pkt_con_ni_qos,
    input  logic [5:0] pkt_con_ni_src,
    input  logic [5:0] pkt_con_ni_tgt,
    input  logic [7:0] pkt_con_ni_data,
    output logic pkt_con_ni_rdy,

    // C接口北方向输出
    output logic pkt_con_no_vld,
    output logic [1:0] pkt_con_no_type,
    output logic pkt_con_no_qos,
    output logic [5:0] pkt_con_no_src,
    output logic [5:0] pkt_con_no_tgt,
    output logic [7:0] pkt_con_no_data,
    input  logic pkt_con_no_rdy,

    // C接口西方向输入
    input  logic pkt_con_wi_vld,
    input  logic [1:0] pkt_con_wi_type,
    input  logic pkt_con_wi_qos,
    input  logic [5:0] pkt_con_wi_src,
    input  logic [5:0] pkt_con_wi_tgt,
    input  logic [7:0] pkt_con_wi_data,
    output logic pkt_con_wi_rdy,

    // C接口西方向输出
    output logic pkt_con_wo_vld,
    output logic [1:0] pkt_con_wo_type,
    output logic pkt_con_wo_qos,
    output logic [5:0] pkt_con_wo_src,
    output logic [5:0] pkt_con_wo_tgt,
    output logic [7:0] pkt_con_wo_data,
    input  logic pkt_con_wo_rdy,

    // C接口南方向输入
    input  logic pkt_con_si_vld,
    input  logic [1:0] pkt_con_si_type,
    input  logic pkt_con_si_qos,
    input  logic [5:0] pkt_con_si_src,
    input  logic [5:0] pkt_con_si_tgt,
    input  logic [7:0] pkt_con_si_data,
    output logic pkt_con_si_rdy,

    // C接口南方向输出
    output logic pkt_con_so_vld,
    output logic [1:0] pkt_con_so_type,
    output logic pkt_con_so_qos,
    output logic [5:0] pkt_con_so_src,
    output logic [5:0] pkt_con_so_tgt,
    output logic [7:0] pkt_con_so_data,
    input  logic pkt_con_so_rdy,

    // C接口东方向输入
    input  logic pkt_con_ei_vld,
    input  logic [1:0] pkt_con_ei_type,
    input  logic pkt_con_ei_qos,
    input  logic [5:0] pkt_con_ei_src,
    input  logic [5:0] pkt_con_ei_tgt,
    input  logic [7:0] pkt_con_ei_data,
    output logic pkt_con_ei_rdy,

    // C接口东方向输出
    output logic pkt_con_eo_vld,
    output logic [1:0] pkt_con_eo_type,
    output logic pkt_con_eo_qos,
    output logic [5:0] pkt_con_eo_src,
    output logic [5:0] pkt_con_eo_tgt,
    output logic [7:0] pkt_con_eo_data,
    input  logic pkt_con_eo_rdy
);

    // 实例化接口
    pkt_in pkt_i ();
    pkt_out pkt_o ();
    pkt_con_if pkt_con ();

    // 连接A接口输入
    assign pkt_i.pkt_in_vld = pkt_i_pkt_in_vld;
    assign pkt_i.pkt_in_type = pkt_i_pkt_in_type;
    assign pkt_i.pkt_in_qos = pkt_i_pkt_in_qos;
    assign pkt_i.pkt_in_src = pkt_i_pkt_in_src;
    assign pkt_i.pkt_in_tgt = pkt_i_pkt_in_tgt;
    assign pkt_i.pkt_in_data = pkt_i_pkt_in_data;
    assign pkt_i_pkt_in_rdy = pkt_i.pkt_in_rdy;

    // 连接B接口输出
    assign pkt_o_pkt_out_vld = pkt_o.pkt_out_vld;
    assign pkt_o_pkt_out_type = pkt_o.pkt_out_type;
    assign pkt_o_pkt_out_qos = pkt_o.pkt_out_qos;
    assign pkt_o_pkt_out_src = pkt_o.pkt_out_src;
    assign pkt_o_pkt_out_tgt = pkt_o.pkt_out_tgt;
    assign pkt_o_pkt_out_data = pkt_o.pkt_out_data;
    assign pkt_o.pkt_out_rdy = pkt_o_pkt_out_rdy;

    // 连接C接口
    // 北方向
    assign pkt_con.ni_vld = pkt_con_ni_vld;
    assign pkt_con.ni_type = pkt_con_ni_type;
    assign pkt_con.ni_qos = pkt_con_ni_qos;
    assign pkt_con.ni_src = pkt_con_ni_src;
    assign pkt_con.ni_tgt = pkt_con_ni_tgt;
    assign pkt_con.ni_data = pkt_con_ni_data;
    assign pkt_con_ni_rdy = pkt_con.ni_rdy;

    assign pkt_con_no_vld = pkt_con.no_vld;
    assign pkt_con_no_type = pkt_con.no_type;
    assign pkt_con_no_qos = pkt_con.no_qos;
    assign pkt_con_no_src = pkt_con.no_src;
    assign pkt_con_no_tgt = pkt_con.no_tgt;
    assign pkt_con_no_data = pkt_con.no_data;
    assign pkt_con.no_rdy = pkt_con_no_rdy;

    // 西方向
    assign pkt_con.wi_vld = pkt_con_wi_vld;
    assign pkt_con.wi_type = pkt_con_wi_type;
    assign pkt_con.wi_qos = pkt_con_wi_qos;
    assign pkt_con.wi_src = pkt_con_wi_src;
    assign pkt_con.wi_tgt = pkt_con_wi_tgt;
    assign pkt_con.wi_data = pkt_con_wi_data;
    assign pkt_con_wi_rdy = pkt_con.wi_rdy;

    assign pkt_con_wo_vld = pkt_con.wo_vld;
    assign pkt_con_wo_type = pkt_con.wo_type;
    assign pkt_con_wo_qos = pkt_con.wo_qos;
    assign pkt_con_wo_src = pkt_con.wo_src;
    assign pkt_con_wo_tgt = pkt_con.wo_tgt;
    assign pkt_con_wo_data = pkt_con.wo_data;
    assign pkt_con.wo_rdy = pkt_con_wo_rdy;

    // 南方向
    assign pkt_con.si_vld = pkt_con_si_vld;
    assign pkt_con.si_type = pkt_con_si_type;
    assign pkt_con.si_qos = pkt_con_si_qos;
    assign pkt_con.si_src = pkt_con_si_src;
    assign pkt_con.si_tgt = pkt_con_si_tgt;
    assign pkt_con.si_data = pkt_con_si_data;
    assign pkt_con_si_rdy = pkt_con.si_rdy;

    assign pkt_con_so_vld = pkt_con.so_vld;
    assign pkt_con_so_type = pkt_con.so_type;
    assign pkt_con_so_qos = pkt_con.so_qos;
    assign pkt_con_so_src = pkt_con.so_src;
    assign pkt_con_so_tgt = pkt_con.so_tgt;
    assign pkt_con_so_data = pkt_con.so_data;
    assign pkt_con.so_rdy = pkt_con_so_rdy;

    // 东方向
    assign pkt_con.ei_vld = pkt_con_ei_vld;
    assign pkt_con.ei_type = pkt_con_ei_type;
    assign pkt_con.ei_qos = pkt_con_ei_qos;
    assign pkt_con.ei_src = pkt_con_ei_src;
    assign pkt_con.ei_tgt = pkt_con_ei_tgt;
    assign pkt_con.ei_data = pkt_con_ei_data;
    assign pkt_con_ei_rdy = pkt_con.ei_rdy;

    assign pkt_con_eo_vld = pkt_con.eo_vld;
    assign pkt_con_eo_type = pkt_con.eo_type;
    assign pkt_con_eo_qos = pkt_con.eo_qos;
    assign pkt_con_eo_src = pkt_con.eo_src;
    assign pkt_con_eo_tgt = pkt_con.eo_tgt;
    assign pkt_con_eo_data = pkt_con.eo_data;
    assign pkt_con.eo_rdy = pkt_con_eo_rdy;

    // 实例化MAZE节点模块
    node #(
        .HP(HP),
        .VP(VP)
    ) u_node (
        .clk(clk),
        .rst_n(rst_n),
        .pg_en(pg_en),
        .pg_node(pg_node),
        .pkt_i(pkt_i),
        .pkt_o(pkt_o),
        .pkt_con(pkt_con)
    );

endmodule