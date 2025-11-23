// =============================================================================
// MAZE节点简单测试主函数
// =============================================================================
// 简单的主函数，用于验证Verilator编译和基本功能

#include <iostream>
#include <cstdlib>
#include <verilated.h>
#include "Vsimple_test.h"  // Verilator生成的测试模块头文件

// 测试配置参数
#define MAX_SIM_CYCLES     50        // 最大仿真周期数

int main(int argc, char** argv) {
    printf("=== MAZE节点简单测试 ===\n");

    // 初始化Verilator
    Verilated::commandArgs(argc, argv);

    // 创建DUT实例
    Vsimple_test* dut = new Vsimple_test;

    // 复位序列
    printf("开始复位序列...\n");
    dut->clk = 0;
    dut->rst_n = 0;

    // 设置故障配置（默认无故障）
    dut->pg_en = 0;
    dut->pg_node = 0;

    // 复位周期
    for (int i = 0; i < 5; ++i) {
        dut->clk = !dut->clk;
        dut->eval();
    }

    // 释放复位
    dut->rst_n = 1;
    printf("复位完成\n");

    // 基本测试循环
    printf("开始基本功能测试...\n");

    for (int cycle = 0; cycle < MAX_SIM_CYCLES; ++cycle) {
        // 时钟上升沿
        dut->clk = 1;
        dut->eval();

        // 时钟下降沿
        dut->clk = 0;
        dut->eval();

        // 简单测试：在第10个周期发送一个测试数据包
        if (cycle == 10) {
            printf("发送测试数据包...\n");
            dut->pkt_in_pkt_in_vld = 1;
            dut->pkt_in_pkt_in_type = 0;  // 单播
            dut->pkt_in_pkt_in_qos = 1;   // 高优先级
            dut->pkt_in_pkt_in_src = 0x12; // 源地址
            dut->pkt_in_pkt_in_tgt = 0x21; // 目标地址
            dut->pkt_in_pkt_in_data = 0xAA; // 测试数据
        } else if (cycle == 11) {
            // 清除输入有效信号
            dut->pkt_in_pkt_in_vld = 0;
        }

        // 检查输出（简化检查）
        if (dut->pkt_o_pkt_out_vld) {
            printf("检测到输出数据包！周期: %d\n", cycle);
            printf("  类型: %d, QoS: %d\n",
                   dut->pkt_o_pkt_out_type, dut->pkt_o_pkt_out_qos);
            printf("  源地址: 0x%02X, 目标地址: 0x%02X\n",
                   dut->pkt_o_pkt_out_src, dut->pkt_o_pkt_out_tgt);
            printf("  数据: 0x%02X\n", dut->pkt_o_pkt_out_data);
        }

        // 设置输出就绪信号
        dut->pkt_o_pkt_out_rdy = 1;
        dut->pkt_con_no_rdy = 1;
        dut->pkt_con_wo_rdy = 1;
        dut->pkt_con_so_rdy = 1;
        dut->pkt_con_eo_rdy = 1;
    }

    printf("测试完成\n");

    // 清理
    delete dut;
    Verilated::callFinish();

    return 0;
}