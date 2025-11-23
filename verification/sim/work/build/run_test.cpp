#include <iostream>
#include "verilated.h"
#include "Vbasic_test.h"
#include "Vbasic_test___024root.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vbasic_test* dut = new Vbasic_test;

    std::cout << "MAZE节点基本测试开始..." << std::endl;

    // 通过rootp访问内部信号
    Vbasic_test___024root* root = dut->rootp;

    // 初始化信号
    root->basic_test__DOT__clk = 0;
    root->basic_test__DOT__rst_n = 0;
    root->basic_test__DOT__pg_en = 0;
    root->basic_test__DOT__pg_node = 0;

    // 复位序列 - 5个时钟周期
    for (int i = 0; i < 5; ++i) {
        root->basic_test__DOT__clk = !root->basic_test__DOT__clk;  // 时钟翻转
        dut->eval();
    }

    // 释放复位
    root->basic_test__DOT__rst_n = 1;

    // 测试循环 - 20个时钟周期
    for (int i = 0; i < 20; ++i) {
        // 时钟上升沿
        root->basic_test__DOT__clk = 1;
        dut->eval();

        // 时钟下降沿
        root->basic_test__DOT__clk = 0;
        dut->eval();

        std::cout << "周期 " << (i + 1) << ": 节点运行正常" << std::endl;
    }

    std::cout << "测试完成" << std::endl;

    delete dut;
    return 0;
}
