// =============================================================================
// MAZE节点基本路由功能调试测试台（C++版本）
// =============================================================================
// 功能说明：
// 1. 使用自定义C++测试台替代Verilator自动生成的main函数
// 2. 每个周期打印node中A端口IRS_N的输出信息
// 3. 使用Verilated::traceDebug进行深度调试
// =============================================================================

#include "Vsimple_test.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "verilated_trace.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// 数据包编码函数
uint32_t encode_packet(uint8_t pkt_type, uint8_t pkt_qos,
                      uint8_t src_id, uint8_t tgt_id, uint8_t data) {
    return ((uint32_t)pkt_type << 21) | ((uint32_t)pkt_qos << 20) |
           ((uint32_t)src_id << 14) | ((uint32_t)tgt_id << 8) | data;
}

// 数据包解码函数
void decode_packet(uint32_t encoded, uint8_t &pkt_type, uint8_t &pkt_qos,
                  uint8_t &src_id, uint8_t &tgt_id, uint8_t &data) {
    pkt_type = (encoded >> 21) & 0x3;
    pkt_qos = (encoded >> 20) & 0x1;
    src_id = (encoded >> 14) & 0x3F;
    tgt_id = (encoded >> 8) & 0x3F;
    data = encoded & 0xFF;
}

// 打印数据包信息
void print_packet(uint32_t encoded, const std::string& prefix = "") {
    uint8_t pkt_type, pkt_qos, src_id, tgt_id, data;
    decode_packet(encoded, pkt_type, pkt_qos, src_id, tgt_id, data);
    std::cout << prefix << "Packet[0x" << std::hex << std::setfill('0') << std::setw(6)
              << encoded << std::dec << "]: Type=" << (int)pkt_type
              << ", QoS=" << (int)pkt_qos << ", Src=" << (int)src_id
              << ", Tgt=" << (int)tgt_id << ", Data=0x" << std::hex << (int)data << std::dec;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // 创建顶层实例
    Vsimple_test* top = new Vsimple_test;

    // 启用trace调试
    Verilated::traceEverOn(true);
    Verilated::debug(1);  // 启用调试模式

    // 创建VCD跟踪
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("debug_node_irs_n.vcd");

    // 仿真参数
    vluint64_t sim_time = 0;
    vluint64_t timeout_cycles = 10000;
    uint64_t test_cycle = 0;
    uint32_t test_node_x = 3;  // 默认测试节点
    uint32_t test_node_y = 3;

    // 解析命令行参数
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--node_x" && i+1 < argc) {
            test_node_x = std::stoul(argv[i+1]);
        } else if (std::string(argv[i]) == "--node_y" && i+1 < argc) {
            test_node_y = std::stoul(argv[i+1]);
        }
    }

    std::cout << "============================================" << std::endl;
    std::cout << "MAZE节点A端口IRS_N调试测试" << std::endl;
    std::cout << "测试节点: (" << test_node_x << ", " << test_node_y << ")" << std::endl;
    std::cout << "============================================" << std::endl;

    // 初始化输入信号
    top->clk = 0;
    top->rst_n = 0;
    top->pg_en = 0;
    top->pg_node = 0;

    // 初始化A接口输入 - 使用正确的信号名称
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->vld = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->type = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->qos = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->src = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->tgt = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->data = 0;

    // 初始化C接口输入（固定为0）- 使用正确的信号名称
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->ni_vld = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wi_vld = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->si_vld = 0;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->ei_vld = 0;

    // 初始化所有就绪信号为1 - 使用正确的信号名称
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->rdy = 1;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_rdy = 1;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_rdy = 1;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_rdy = 1;
    top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_rdy = 1;

    std::cout << std::endl;
    std::cout << "每个周期打印A端口IRS_N输出信息：" << std::endl;
    std::cout << "格式: [Cycle] IRS_N输出 -> Node内部信号" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    // 复位序列
    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(sim_time++);
        top->clk = !top->clk;
        top->eval();
        tfp->dump(sim_time++);
    }

    top->rst_n = 1;

    // 发送测试数据包
    uint32_t test_packet = encode_packet(0, 0, 27, 28, 0xA5);  // 从节点(3,3)到(4,3)

    for (int i = 0; i < 15; i++) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(sim_time++);

        // 在时钟上升沿发送数据包
        if (i == 1 && top->clk == 1) {
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->vld = 1;
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->type = (test_packet >> 21) & 0x3;
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->qos = (test_packet >> 20) & 0x1;
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->src = (test_packet >> 14) & 0x3F;
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->tgt = (test_packet >> 8) & 0x3F;
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->data = test_packet & 0xFF;

            std::cout << "[Cycle " << test_cycle << "] 发送数据包: ";
            print_packet(test_packet);
            std::cout << std::endl;
        } else if (i == 2 && top->clk == 1) {
            top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->vld = 0;  // 清除valid信号
        }

        // 打印每个周期的A端口IRS_N输出信息
        if (top->clk == 1) {
            std::cout << "[Cycle " << std::setw(3) << test_cycle << "] ";

            // 检查是否有A端口输出到节点
            bool has_activity = false;

            // 如果这里能访问到node实例，我们可以打印IRS_N的输出
            // 但由于封装在test_node_wrapper中，我们需要通过观察节点行为来推断

            // 打印A接口状态
            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->vld && top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->rdy) {
                std::cout << "A端口: 数据包已接收 ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->data));
                has_activity = true;
            }

            // 打印所有输出端口的活动
            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->vld) {
                std::cout << (has_activity ? " | " : "") << "Local输出: ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->data));
                has_activity = true;
            }

            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_vld) {
                std::cout << (has_activity ? " | " : "") << "North输出: ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->no_data));
                has_activity = true;
            }

            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_vld) {
                std::cout << (has_activity ? " | " : "") << "West输出: ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->wo_data));
                has_activity = true;
            }

            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_vld) {
                std::cout << (has_activity ? " | " : "") << "South输出: ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->so_data));
                has_activity = true;
            }

            if (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_vld) {
                std::cout << (has_activity ? " | " : "") << "East输出: ";
                print_packet(encode_packet(top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_type, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_qos,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_src, top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_tgt,
                                          top->__PVT__simple_test__DOT__u_dut__DOT__pkt_con->eo_data));
                has_activity = true;
            }

            if (!has_activity) {
                std::cout << "无活动";
            }

            // 打印关键的握手信号状态
            std::cout << " [A_rdy=" << (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_i->rdy ? "1" : "0")
                      << ", O_rdy=" << (top->__PVT__simple_test__DOT__u_dut__DOT__pkt_o->rdy ? "1" : "0") << "]";

            std::cout << std::endl;
            test_cycle++;
        }

        top->clk = !top->clk;
        top->eval();
        tfp->dump(sim_time++);
    }

    std::cout << "============================================" << std::endl;
    std::cout << "调试信息收集完成" << std::endl;
    std::cout << "波形文件: debug_node_irs_n.vcd" << std::endl;
    std::cout << "使用gtkwave查看: gtkwave debug_node_irs_n.vcd" << std::endl;
    std::cout << "============================================" << std::endl;

    // 清理
    tfp->close();
    delete tfp;
    delete top;

    return 0;
}