// =============================================================================
// MAZE节点验证环境 - 极简版本C++主函数（支持VCD波形追踪）
// =============================================================================

#include <iostream>
#include <fstream>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vminimal_node_test.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // 启用波形追踪
    Verilated::traceEverOn(true);

    // 创建测试实例
    Vminimal_node_test* dut = new Vminimal_node_test;

    // 创建VCD波形追踪实例
    VerilatedVcdC* tfp = new VerilatedVcdC;

    // 启用VCD波形追踪（深度99）
    dut->trace(tfp, 99);

    // 打开VCD波形文件
    tfp->open("../../../sim/wave/vcd/node_test.vcd");
    if (!tfp->isOpen()) {
        std::cerr << "错误: 无法打开VCD波形文件进行写入" << std::endl;
        exit(1);
    }

    // 运行仿真循环 - C++每步翻转时钟，SystemVerilog使用@posedge等待
    vluint64_t sim_time = 0;
    const vluint64_t max_time = 500000;  // 足够的时间让测试完成

    // 初始化时钟和复位信号
    dut->clk = 0;
    dut->rst_n = 1;  // 复位信号默认高电平（SystemVerilog测试会控制复位时序）

    // 主仿真循环 - C++控制时钟和复位，SystemVerilog等待时钟沿
    while (!Verilated::gotFinish() && sim_time < max_time) {
        // 复位控制逻辑：在时间50-100之间进行复位
        if (sim_time == 10) {
            dut->rst_n = 0;  // 复位拉低
        } else if (sim_time == 20) {
            dut->rst_n = 1;  // 复位拉高
        }

        // 每一步都翻转时钟
        dut->clk = !dut->clk;

        // 执行eval让SystemVerilog感知时钟变化
        dut->eval();

        // 在每个时间步长写入波形数据
        tfp->dump(sim_time);

        // 检查SystemVerilog是否完成
        if (Verilated::gotFinish()) {
            break;
        }

        // 继续时间推进
        sim_time++;
    }

    // 关闭波形文件
    tfp->close();
    delete tfp;

    // 清理测试实例
    delete dut;

    return 0;
}