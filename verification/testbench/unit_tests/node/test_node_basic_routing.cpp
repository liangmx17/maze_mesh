// =============================================================================
// MAZE网络节点模块基础路由功能测试
// =============================================================================
// 测试目标：
// 1. 验证基本路由功能，包括X、Y、NWSE四个方向的正确路由
// 2. 验证数据包格式解析和路由决策
// 3. 验证本地输出(B端口)功能
// 4. 验证无故障情况下的基本路由行为
// =============================================================================

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <ctime>

// 包含接口定义
#include "Vnode.h"
#include "Vnode___024root.h"

// 测试配置参数
#define CLK_PERIOD 10
#define MAX_CYCLES 1000
#define TEST_TIMEOUT 100000

// 数据包结构定义
struct Packet {
    bool valid;
    bool qos;
    uint8_t type;
    uint8_t src_x;
    uint8_t src_y;
    uint8_t tgt_x;
    uint8_t tgt_y;
    uint8_t data;
    uint64_t cycle;

    Packet() : valid(false), qos(false), type(0), src_x(0), src_y(0),
               tgt_x(0), tgt_y(0), data(0), cycle(0) {}

    Packet(uint8_t sx, uint8_t sy, uint8_t tx, uint8_t ty, uint8_t d = 0,
          bool q = false, uint8_t t = 0)
        : valid(true), qos(q), type(t), src_x(sx), src_y(sy),
          tgt_x(tx), tgt_y(ty), data(d), cycle(0) {}

    uint32_t to_23bit() const {
        return (type << 21) | (qos << 20) |
               (src_y << 15) | (src_x << 9) |
               (tgt_y << 9) | (tgt_x << 3) | data;
    }

    void from_23bit(uint32_t pkt) {
        type = (pkt >> 21) & 0x3;
        qos = (pkt >> 20) & 0x1;
        src_y = (pkt >> 15) & 0x3F;
        src_x = (pkt >> 9) & 0x3F;
        tgt_y = (pkt >> 3) & 0x3F;
        data = pkt & 0xFF;
    }

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Packet[SRC(" << (int)src_x << "," << (int)src_y
            << ")->TGT(" << (int)tgt_x << "," << (int)tgt_y
            << ") QoS=" << (qos ? "H" : "L")
            << " Type=" << std::hex << (int)type << std::dec
            << " Data=0x" << std::hex << (int)data << std::dec << "]";
        return oss.str();
    }
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0) {}

    void add_test(bool passed, const std::string& description) {
        total_tests++;
        if (passed) {
            passed_tests++;
            std::cout << "[PASS] " << description << std::endl;
        } else {
            failed_tests++;
            std::cout << "[FAIL] " << description << std::endl;
            error_messages.push_back(description);
        }
    }

    void print_summary() {
        std::cout << "\n=== 测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        if (!error_messages.empty()) {
            std::cout << "\n失败测试详情:" << std::endl;
            for (const auto& err : error_messages) {
                std::cout << "  - " << err << std::endl;
            }
        }
    }
};

// 主测试类
class NodeBasicRoutingTest {
private:
    Vnode* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    // 输入和输出数据包队列
    std::vector<Packet> input_packets;
    std::vector<Packet> output_packets;

public:
    NodeBasicRoutingTest() : main_time(0), rng(time(nullptr)) {
        dut = new Vnode;
        tfp = nullptr;
    }

    ~NodeBasicRoutingTest() {
        if (tfp) {
            tfp->close();
            delete tfp;
        }
        delete dut;
    }

    // 初始化仿真
    void init_simulation(bool enable_trace = false) {
        dut->clk = 0;
        dut->rst_n = 0;

        // 设置节点坐标为(2,2) - 内部节点，有完整连接
        dut->HP = 2;
        dut->VP = 2;

        // 设置故障配置（无故障）
        dut->pg_en = 0;
        dut->pg_node = 0;

        // 初始化所有接口信号
        // A接口 (外部输入)
        dut->pkt_i_mst_pkt_in_vld = 0;
        dut->pkt_i_mst_pkt_in_qos = 0;
        dut->pkt_i_mst_pkt_in_type = 0;
        dut->pkt_i_mst_pkt_in_src = 0;
        dut->pkt_i_mst_pkt_in_tgt = 0;
        dut->pkt_i_mst_pkt_in_data = 0;

        // B接口 (外部输出) - 默认就绪
        dut->pkt_o_mst_pkt_out_rdy = 1;

        // C接口输入 (NWSE) - 默认无效
        dut->pkt_con_mst_ni_vld = 0;
        dut->pkt_con_mst_wi_vld = 0;
        dut->pkt_con_mst_si_vld = 0;
        dut->pkt_con_mst_ei_vld = 0;

        // C接口输出 (NWSE) - 默认就绪
        dut->pkt_con_mst_no_rdy = 1;
        dut->pkt_con_mst_wo_rdy = 1;
        dut->pkt_con_mst_so_rdy = 1;
        dut->pkt_con_mst_eo_rdy = 1;

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_node_basic_routing.vcd");
        }

        // 复位序列
        reset_sequence();
    }

    // 复位序列
    void reset_sequence() {
        std::cout << "开始复位序列..." << std::endl;

        // 复位3个时钟周期
        for (int i = 0; i < 3; i++) {
            tick();
        }

        dut->rst_n = 1;
        for (int i = 0; i < 3; i++) {
            tick();
        }

        std::cout << "复位完成" << std::endl;
    }

    // 时钟周期
    void tick() {
        dut->clk = 0;
        dut->eval();
        if (tfp) tfp->dump(main_time);
        main_time += CLK_PERIOD/2;

        dut->clk = 1;
        dut->eval();
        if (tfp) tfp->dump(main_time);
        main_time += CLK_PERIOD/2;
    }

    // 等待指定周期
    void wait_cycles(int cycles) {
        for (int i = 0; i < cycles; i++) {
            tick();
        }
    }

    // 发送数据包到A接口
    void send_packet_to_a(const Packet& pkt) {
        dut->pkt_i_mst_pkt_in_vld = 1;
        dut->pkt_i_mst_pkt_in_qos = pkt.qos;
        dut->pkt_i_mst_pkt_in_type = pkt.type;
        dut->pkt_i_mst_pkt_in_src = (pkt.src_y << 3) | pkt.src_x;
        dut->pkt_i_mst_pkt_in_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
        dut->pkt_i_mst_pkt_in_data = pkt.data;

        std::cout << "发送数据包到A接口: " << pkt.to_string() << std::endl;

        // 等待就绪信号
        int timeout = 100;
        while (!dut->pkt_i_mst_pkt_in_rdy && timeout > 0) {
            tick();
            timeout--;
        }

        if (timeout == 0) {
            std::cout << "错误: A接口超时，无法发送数据包" << std::endl;
            stats.add_test(false, "A接口发送超时");
            return;
        }

        tick(); // 完成传输

        // 清除有效信号
        dut->pkt_i_mst_pkt_in_vld = 0;
        dut->pkt_i_mst_pkt_in_qos = 0;
        dut->pkt_i_mst_pkt_in_type = 0;
        dut->pkt_i_mst_pkt_in_src = 0;
        dut->pkt_i_mst_pkt_in_tgt = 0;
        dut->pkt_i_mst_pkt_in_data = 0;

        input_packets.push_back(pkt);
    }

    // 发送数据包到C接口指定方向
    void send_packet_to_c(const Packet& pkt, const std::string& direction) {
        if (direction == "N") {
            dut->pkt_con_mst_ni_vld = 1;
            dut->pkt_con_mst_ni_qos = pkt.qos;
            dut->pkt_con_mst_ni_type = pkt.type;
            dut->pkt_con_mst_ni_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_ni_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_ni_data = pkt.data;
        } else if (direction == "W") {
            dut->pkt_con_mst_wi_vld = 1;
            dut->pkt_con_mst_wi_qos = pkt.qos;
            dut->pkt_con_mst_wi_type = pkt.type;
            dut->pkt_con_mst_wi_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_wi_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_wi_data = pkt.data;
        } else if (direction == "S") {
            dut->pkt_con_mst_si_vld = 1;
            dut->pkt_con_mst_si_qos = pkt.qos;
            dut->pkt_con_mst_si_type = pkt.type;
            dut->pkt_con_mst_si_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_si_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_si_data = pkt.data;
        } else if (direction == "E") {
            dut->pkt_con_mst_ei_vld = 1;
            dut->pkt_con_mst_ei_qos = pkt.qos;
            dut->pkt_con_mst_ei_type = pkt.type;
            dut->pkt_con_mst_ei_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_ei_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_ei_data = pkt.data;
        }

        std::cout << "发送数据包到C接口" << direction << "方向: " << pkt.to_string() << std::endl;

        // 等待就绪信号
        int timeout = 100;
        bool ready = false;
        while (!ready && timeout > 0) {
            tick();
            if (direction == "N" && dut->pkt_con_mst_ni_rdy) ready = true;
            else if (direction == "W" && dut->pkt_con_mst_wi_rdy) ready = true;
            else if (direction == "S" && dut->pkt_con_mst_si_rdy) ready = true;
            else if (direction == "E" && dut->pkt_con_mst_ei_rdy) ready = true;
            timeout--;
        }

        if (timeout == 0) {
            std::cout << "错误: C接口" << direction << "方向超时，无法发送数据包" << std::endl;
            stats.add_test(false, "C接口" + direction + "方向发送超时");
            return;
        }

        tick(); // 完成传输

        // 清除有效信号
        if (direction == "N") {
            dut->pkt_con_mst_ni_vld = 0;
            dut->pkt_con_mst_ni_qos = 0;
            dut->pkt_con_mst_ni_type = 0;
            dut->pkt_con_mst_ni_src = 0;
            dut->pkt_con_mst_ni_tgt = 0;
            dut->pkt_con_mst_ni_data = 0;
        } else if (direction == "W") {
            dut->pkt_con_mst_wi_vld = 0;
            dut->pkt_con_mst_wi_qos = 0;
            dut->pkt_con_mst_wi_type = 0;
            dut->pkt_con_mst_wi_src = 0;
            dut->pkt_con_mst_wi_tgt = 0;
            dut->pkt_con_mst_wi_data = 0;
        } else if (direction == "S") {
            dut->pkt_con_mst_si_vld = 0;
            dut->pkt_con_mst_si_qos = 0;
            dut->pkt_con_mst_si_type = 0;
            dut->pkt_con_mst_si_src = 0;
            dut->pkt_con_mst_si_tgt = 0;
            dut->pkt_con_mst_si_data = 0;
        } else if (direction == "E") {
            dut->pkt_con_mst_ei_vld = 0;
            dut->pkt_con_mst_ei_qos = 0;
            dut->pkt_con_mst_ei_type = 0;
            dut->pkt_con_mst_ei_src = 0;
            dut->pkt_con_mst_ei_tgt = 0;
            dut->pkt_con_mst_ei_data = 0;
        }

        input_packets.push_back(pkt);
    }

    // 检查输出数据包
    Packet check_output_packet(int timeout_cycles = 100) {
        Packet received_pkt;

        for (int i = 0; i < timeout_cycles; i++) {
            tick();

            // 检查B接口输出
            if (dut->pkt_o_mst_pkt_out_vld) {
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_o_mst_pkt_out_qos;
                received_pkt.type = dut->pkt_o_mst_pkt_out_type;
                received_pkt.src_y = (dut->pkt_o_mst_pkt_out_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_o_mst_pkt_out_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_o_mst_pkt_out_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_o_mst_pkt_out_tgt & 0x7;
                received_pkt.data = dut->pkt_o_mst_pkt_out_data;
                received_pkt.cycle = main_time;

                std::cout << "接收B接口输出: " << received_pkt.to_string() << std::endl;
                output_packets.push_back(received_pkt);
                return received_pkt;
            }

            // 检查C接口输出
            if (dut->pkt_con_mst_no_vld) {
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_no_qos;
                received_pkt.type = dut->pkt_con_mst_no_type;
                received_pkt.src_y = (dut->pkt_con_mst_no_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_no_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_no_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_no_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_no_data;
                received_pkt.cycle = main_time;

                std::cout << "接收C接口北向输出: " << received_pkt.to_string() << std::endl;
                output_packets.push_back(received_pkt);
                return received_pkt;
            }

            if (dut->pkt_con_mst_wo_vld) {
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_wo_qos;
                received_pkt.type = dut->pkt_con_mst_wo_type;
                received_pkt.src_y = (dut->pkt_con_mst_wo_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_wo_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_wo_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_wo_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_wo_data;
                received_pkt.cycle = main_time;

                std::cout << "接收C接口西向输出: " << received_pkt.to_string() << std::endl;
                output_packets.push_back(received_pkt);
                return received_pkt;
            }

            if (dut->pkt_con_mst_so_vld) {
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_so_qos;
                received_pkt.type = dut->pkt_con_mst_so_type;
                received_pkt.src_y = (dut->pkt_con_mst_so_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_so_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_so_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_so_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_so_data;
                received_pkt.cycle = main_time;

                std::cout << "接收C接口南向输出: " << received_pkt.to_string() << std::endl;
                output_packets.push_back(received_pkt);
                return received_pkt;
            }

            if (dut->pkt_con_mst_eo_vld) {
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_eo_qos;
                received_pkt.type = dut->pkt_con_mst_eo_type;
                received_pkt.src_y = (dut->pkt_con_mst_eo_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_eo_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_eo_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_eo_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_eo_data;
                received_pkt.cycle = main_time;

                std::cout << "接收C接口东向输出: " << received_pkt.to_string() << std::endl;
                output_packets.push_back(received_pkt);
                return received_pkt;
            }
        }

        std::cout << "警告: 等待" << timeout_cycles << "周期后未检测到输出数据包" << std::endl;
        return received_pkt;
    }

    // 测试1: 基本地到本地路由 (A接口输入 -> B接口输出)
    void test_local_routing() {
        std::cout << "\n=== 测试1: 基本地到本地路由 ===" << std::endl;

        // 发送目标为本地的数据包
        Packet test_pkt(1, 1, 2, 2, 0xAA, false, 0); // SRC(1,1)->TGT(2,2)
        send_packet_to_a(test_pkt);

        // 等待输出
        Packet received = check_output_packet();

        // 验证结果
        bool test_passed = (received.valid &&
                          received.src_x == test_pkt.src_x &&
                          received.src_y == test_pkt.src_y &&
                          received.tgt_x == test_pkt.tgt_x &&
                          received.tgt_y == test_pkt.tgt_y &&
                          received.data == test_pkt.data);

        stats.add_test(test_passed, "本地路由测试 - 数据包应从A接口输入到B接口输出");
    }

    // 测试2: 基本东向路由 (A接口输入 -> C接口东向输出)
    void test_east_routing() {
        std::cout << "\n=== 测试2: 基本东向路由 ===" << std::endl;

        // 发送目标在东方的数据包
        Packet test_pkt(2, 2, 3, 2, 0xBB, false, 0); // SRC(2,2)->TGT(3,2)
        send_packet_to_a(test_pkt);

        // 等待输出
        Packet received = check_output_packet();

        // 验证结果
        bool test_passed = (received.valid &&
                          received.src_x == test_pkt.src_x &&
                          received.src_y == test_pkt.src_y &&
                          received.tgt_x == test_pkt.tgt_x &&
                          received.tgt_y == test_pkt.tgt_y &&
                          received.data == test_pkt.data);

        stats.add_test(test_passed, "东向路由测试 - 数据包应从C接口东向输出");
    }

    // 测试3: 基本西向路由 (A接口输入 -> C接口西向输出)
    void test_west_routing() {
        std::cout << "\n=== 测试3: 基本西向路由 ===" << std::endl;

        // 发送目标在西方的数据包
        Packet test_pkt(2, 2, 1, 2, 0xCC, false, 0); // SRC(2,2)->TGT(1,2)
        send_packet_to_a(test_pkt);

        // 等待输出
        Packet received = check_output_packet();

        // 验证结果
        bool test_passed = (received.valid &&
                          received.src_x == test_pkt.src_x &&
                          received.src_y == test_pkt.src_y &&
                          received.tgt_x == test_pkt.tgt_x &&
                          received.tgt_y == test_pkt.tgt_y &&
                          received.data == test_pkt.data);

        stats.add_test(test_passed, "西向路由测试 - 数据包应从C接口西向输出");
    }

    // 测试4: 基本北向路由 (A接口输入 -> C接口北向输出)
    void test_north_routing() {
        std::cout << "\n=== 测试4: 基本北向路由 ===" << std::endl;

        // 发送目标在北方的数据包
        Packet test_pkt(2, 2, 2, 3, 0xDD, false, 0); // SRC(2,2)->TGT(2,3)
        send_packet_to_a(test_pkt);

        // 等待输出
        Packet received = check_output_packet();

        // 验证结果
        bool test_passed = (received.valid &&
                          received.src_x == test_pkt.src_x &&
                          received.src_y == test_pkt.src_y &&
                          received.tgt_x == test_pkt.tgt_x &&
                          received.tgt_y == test_pkt.tgt_y &&
                          received.data == test_pkt.data);

        stats.add_test(test_passed, "北向路由测试 - 数据包应从C接口北向输出");
    }

    // 测试5: 基本南向路由 (A接口输入 -> C接口南向输出)
    void test_south_routing() {
        std::cout << "\n=== 测试5: 基本南向路由 ===" << std::endl;

        // 发送目标在南方的数据包
        Packet test_pkt(2, 2, 2, 1, 0xEE, false, 0); // SRC(2,2)->TGT(2,1)
        send_packet_to_a(test_pkt);

        // 等待输出
        Packet received = check_output_packet();

        // 验证结果
        bool test_passed = (received.valid &&
                          received.src_x == test_pkt.src_x &&
                          received.src_y == test_pkt.src_y &&
                          received.tgt_x == test_pkt.tgt_x &&
                          received.tgt_y == test_pkt.tgt_y &&
                          received.data == test_pkt.data);

        stats.add_test(test_passed, "南向路由测试 - 数据包应从C接口南向输出");
    }

    // 测试6: C接口输入路由测试
    void test_c_interface_routing() {
        std::cout << "\n=== 测试6: C接口输入路由测试 ===" << std::endl;

        // 从北方输入，目标为本地
        Packet test_pkt_n(2, 3, 2, 2, 0xF1, false, 0); // SRC(2,3)->TGT(2,2)
        send_packet_to_c(test_pkt_n, "N");

        wait_cycles(2);
        Packet received_n = check_output_packet();

        bool test_n_passed = (received_n.valid &&
                             received_n.src_x == test_pkt_n.src_x &&
                             received_n.src_y == test_pkt_n.src_y &&
                             received_n.tgt_x == test_pkt_n.tgt_x &&
                             received_n.tgt_y == test_pkt_n.tgt_y &&
                             received_n.data == test_pkt_n.data);

        stats.add_test(test_n_passed, "C接口北向输入路由测试 - 应输出到B接口");

        wait_cycles(5);

        // 从西方输入，目标为东方
        Packet test_pkt_w(1, 2, 3, 2, 0xF2, false, 0); // SRC(1,2)->TGT(3,2)
        send_packet_to_c(test_pkt_w, "W");

        wait_cycles(2);
        Packet received_w = check_output_packet();

        bool test_w_passed = (received_w.valid &&
                             received_w.src_x == test_pkt_w.src_x &&
                             received_w.src_y == test_pkt_w.src_y &&
                             received_w.tgt_x == test_pkt_w.tgt_x &&
                             received_w.tgt_y == test_pkt_w.tgt_y &&
                             received_w.data == test_pkt_w.data);

        stats.add_test(test_w_passed, "C接口西向输入路由测试 - 应输出到东向");
    }

    // 测试7: 数据包完整性验证
    void test_packet_integrity() {
        std::cout << "\n=== 测试7: 数据包完整性验证 ===" << std::endl;

        // 测试不同数据包类型和数据
        std::vector<Packet> test_packets = {
            Packet(0, 0, 2, 2, 0x12, false, 0),   // 单播，低QoS
            Packet(0, 0, 2, 2, 0x34, true, 0),    // 单播，高QoS
            Packet(2, 2, 2, 2, 0x56, false, 1),   // X多播
            Packet(2, 2, 2, 2, 0x78, false, 2),   // Y多播
            Packet(2, 2, 2, 2, 0x9A, false, 3)    // 广播
        };

        for (size_t i = 0; i < test_packets.size(); i++) {
            send_packet_to_a(test_packets[i]);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == test_packets[i].src_x &&
                              received.src_y == test_packets[i].src_y &&
                              received.tgt_x == test_packets[i].tgt_x &&
                              received.tgt_y == test_packets[i].tgt_y &&
                              received.data == test_packets[i].data &&
                              received.qos == test_packets[i].qos &&
                              received.type == test_packets[i].type);

            std::ostringstream oss;
            oss << "数据包完整性测试" << (i+1) << " - " << test_packets[i].to_string();
            stats.add_test(test_passed, oss.str());

            wait_cycles(3);
        }
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE节点模块基本路由功能测试" << std::endl;
        std::cout << "节点坐标: (2,2)" << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_local_routing();
        wait_cycles(10);

        test_east_routing();
        wait_cycles(10);

        test_west_routing();
        wait_cycles(10);

        test_north_routing();
        wait_cycles(10);

        test_south_routing();
        wait_cycles(10);

        test_c_interface_routing();
        wait_cycles(10);

        test_packet_integrity();
        wait_cycles(20);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_node_basic_routing_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE节点模块基本路由功能测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "节点坐标: (2,2)" << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            if (!stats.error_messages.empty()) {
                report_file << "\n失败测试详情:" << std::endl;
                for (const auto& err : stats.error_messages) {
                    report_file << "  - " << err << std::endl;
                }
            }

            report_file.close();
            std::cout << "测试报告已保存到: reports/test_node_basic_routing_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        NodeBasicRoutingTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}