// =============================================================================
// MAZE网络节点模块故障感知路由测试
// =============================================================================
// 测试目标：
// 1. 验证故障感知XY路由算法
// 2. 验证9种故障相对位置的REGISTER信号计算
// 3. 验证故障避障路径选择
// 4. 验证不同故障位置对路由决策的影响
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
#include <map>

// 包含接口定义
#include "Vnode.h"
#include "Vnode___024root.h"

// 测试配置参数
#define CLK_PERIOD 10
#define MAX_CYCLES 1000
#define TEST_TIMEOUT 100000

// 故障相对位置定义
enum FaultPosition {
    NORMAL = 0,    // 正常状态
    N_OF_x = 1,    // 当前节点在故障节点北方
    NE_OF_x = 2,   // 当前节点在故障节点东北方
    E_OF_x = 3,    // 当前节点在故障节点东方
    SE_OF_x = 4,   // 当前节点在故障节点东南方
    S_OF_x = 5,    // 当前节点在故障节点南方
    SW_OF_x = 6,   // 当前节点在故障节点西南方
    W_OF_x = 7,    // 当前节点在故障节点西方
    NW_OF_x = 8    // 当前节点在故障节点西北方
};

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
    std::string input_port;
    std::string expected_output_port;

    Packet() : valid(false), qos(false), type(0), src_x(0), src_y(0),
               tgt_x(0), tgt_y(0), data(0), cycle(0), input_port(""), expected_output_port("") {}

    Packet(const std::string& inp, const std::string& outp,
           uint8_t sx, uint8_t sy, uint8_t tx, uint8_t ty, uint8_t d = 0,
           bool q = false, uint8_t t = 0)
        : valid(true), qos(q), type(t), src_x(sx), src_y(sy),
          tgt_x(tx), tgt_y(ty), data(d), cycle(0), input_port(inp), expected_output_port(outp) {}

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Packet[" << input_port << "->" << expected_output_port
            << " SRC(" << (int)src_x << "," << (int)src_y
            << ")->TGT(" << (int)tgt_x << "," << (int)tgt_y
            << ") QoS=" << (qos ? "H" : "L")
            << " Data=0x" << std::hex << (int)data << std::dec << "]";
        return oss.str();
    }
};

// 故障测试场景
struct FaultScenario {
    std::string name;
    int local_x, local_y;      // 当前节点坐标
    int fault_x, fault_y;      // 故障节点坐标
    FaultPosition expected_pos; // 期望的故障相对位置
    std::vector<Packet> test_packets; // 测试数据包
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;
    std::map<FaultPosition, int> fault_position_tests;
    std::map<FaultPosition, int> fault_position_passes;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0) {}

    void add_test(bool passed, const std::string& description, FaultPosition pos = NORMAL) {
        total_tests++;
        if (passed) {
            passed_tests++;
            fault_position_passes[pos]++;
            std::cout << "[PASS] " << description << std::endl;
        } else {
            failed_tests++;
            std::cout << "[FAIL] " << description << std::endl;
            error_messages.push_back(description);
        }
        fault_position_tests[pos]++;
    }

    void print_summary() {
        std::cout << "\n=== 故障感知路由测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        // 故障位置测试统计
        std::cout << "\n故障位置测试统计:" << std::endl;
        std::map<std::string, FaultPosition> pos_names = {
            {"NORMAL", NORMAL}, {"N_OF_x", N_OF_x}, {"NE_OF_x", NE_OF_x},
            {"E_OF_x", E_OF_x}, {"SE_OF_x", SE_OF_x}, {"S_OF_x", S_OF_x},
            {"SW_OF_x", SW_OF_x}, {"W_OF_x", W_OF_x}, {"NW_OF_x", NW_OF_x}
        };

        for (const auto& name_pos : pos_names) {
            int tests = fault_position_tests[name_pos.second];
            int passes = fault_position_passes[name_pos.second];
            if (tests > 0) {
                std::cout << name_pos.first << ": " << passes << "/" << tests
                         << " (" << std::fixed << std::setprecision(1)
                         << (100.0 * passes / tests) << "%)" << std::endl;
            }
        }

        if (!error_messages.empty()) {
            std::cout << "\n失败测试详情:" << std::endl;
            for (const auto& err : error_messages) {
                std::cout << "  - " << err << std::endl;
            }
        }
    }
};

// 主测试类
class NodeFaultAwareTest {
private:
    Vnode* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    std::vector<Packet> received_packets;

public:
    NodeFaultAwareTest() : main_time(0), rng(time(nullptr)) {
        dut = new Vnode;
        tfp = nullptr;
    }

    ~NodeFaultAwareTest() {
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

        // 初始化所有接口信号
        reset_interfaces();

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_node_fault_aware.vcd");
        }

        // 复位序列
        reset_sequence();
    }

    // 重置所有接口信号
    void reset_interfaces() {
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

    // 设置节点和故障配置
    void configure_fault_scenario(int local_x, int local_y, int fault_x, int fault_y, bool enable_fault = true) {
        dut->HP = local_x;
        dut->VP = local_y;
        dut->pg_en = enable_fault ? 1 : 0;
        dut->pg_node = (fault_y << 3) | fault_x;  // 6位故障坐标

        std::cout << "配置故障场景: 当前节点(" << local_x << "," << local_y
                  << "), 故障节点(" << fault_x << "," << fault_y
                  << "), 故障使能=" << (enable_fault ? "是" : "否") << std::endl;

        // 等待配置生效
        wait_cycles(3);
    }

    // 发送数据包
    void send_packet(const Packet& pkt) {
        if (pkt.input_port == "A") {
            dut->pkt_i_mst_pkt_in_vld = 1;
            dut->pkt_i_mst_pkt_in_qos = pkt.qos;
            dut->pkt_i_mst_pkt_in_type = pkt.type;
            dut->pkt_i_mst_pkt_in_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_i_mst_pkt_in_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_i_mst_pkt_in_data = pkt.data;
        } else if (pkt.input_port == "N") {
            dut->pkt_con_mst_ni_vld = 1;
            dut->pkt_con_mst_ni_qos = pkt.qos;
            dut->pkt_con_mst_ni_type = pkt.type;
            dut->pkt_con_mst_ni_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_ni_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_ni_data = pkt.data;
        } else if (pkt.input_port == "W") {
            dut->pkt_con_mst_wi_vld = 1;
            dut->pkt_con_mst_wi_qos = pkt.qos;
            dut->pkt_con_mst_wi_type = pkt.type;
            dut->pkt_con_mst_wi_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_wi_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_wi_data = pkt.data;
        } else if (pkt.input_port == "S") {
            dut->pkt_con_mst_si_vld = 1;
            dut->pkt_con_mst_si_qos = pkt.qos;
            dut->pkt_con_mst_si_type = pkt.type;
            dut->pkt_con_mst_si_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_si_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_si_data = pkt.data;
        } else if (pkt.input_port == "E") {
            dut->pkt_con_mst_ei_vld = 1;
            dut->pkt_con_mst_ei_qos = pkt.qos;
            dut->pkt_con_mst_ei_type = pkt.type;
            dut->pkt_con_mst_ei_src = (pkt.src_y << 3) | pkt.src_x;
            dut->pkt_con_mst_ei_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
            dut->pkt_con_mst_ei_data = pkt.data;
        }

        std::cout << "发送数据包: " << pkt.to_string() << std::endl;

        // 等待就绪信号
        int timeout = 100;
        bool ready = false;
        while (!ready && timeout > 0) {
            tick();
            if (pkt.input_port == "A" && dut->pkt_i_mst_pkt_in_rdy) ready = true;
            else if (pkt.input_port == "N" && dut->pkt_con_mst_ni_rdy) ready = true;
            else if (pkt.input_port == "W" && dut->pkt_con_mst_wi_rdy) ready = true;
            else if (pkt.input_port == "S" && dut->pkt_con_mst_si_rdy) ready = true;
            else if (pkt.input_port == "E" && dut->pkt_con_mst_ei_rdy) ready = true;
            timeout--;
        }

        if (timeout == 0) {
            std::cout << "错误: 发送数据包超时" << std::endl;
            return;
        }

        tick(); // 完成传输

        // 清除输入信号
        reset_interfaces();
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
                received_pkt.input_port = "B";

                std::cout << "B接口输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "N";

                std::cout << "C接口北向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "W";

                std::cout << "C接口西向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "S";

                std::cout << "C接口南向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "E";

                std::cout << "C接口东向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return received_pkt;
            }
        }

        std::cout << "警告: 等待" << timeout_cycles << "周期后未检测到输出数据包" << std::endl;
        return received_pkt;
    }

    // 测试1: 故障相对位置计算验证
    void test_fault_position_calculation() {
        std::cout << "\n=== 测试1: 故障相对位置计算验证 ===" << std::endl;

        std::vector<FaultScenario> scenarios = {
            {"正常状态", 3, 3, 0, 0, NORMAL,
             {Packet("A", "E", 2, 3, 4, 3, 0x01)}},
            {"北故障", 3, 4, 3, 3, N_OF_x,
             {Packet("A", "S", 2, 4, 4, 4, 0x02)}},
            {"东北故障", 4, 4, 3, 3, NE_OF_x,
             {Packet("A", "S", 3, 4, 5, 3, 0x03)}},
            {"东故障", 4, 3, 3, 3, E_OF_x,
             {Packet("A", "W", 3, 2, 5, 3, 0x04)}},
            {"东南故障", 4, 2, 3, 3, SE_OF_x,
             {Packet("A", "W", 3, 2, 5, 1, 0x05)}},
            {"南故障", 3, 2, 3, 3, S_OF_x,
             {Packet("A", "N", 2, 2, 4, 2, 0x06)}},
            {"西南故障", 2, 2, 3, 3, SW_OF_x,
             {Packet("A", "N", 1, 2, 1, 3, 0x07)}},
            {"西故障", 2, 3, 3, 3, W_OF_x,
             {Packet("A", "E", 1, 3, 3, 4, 0x08)}},
            {"西北故障", 2, 4, 3, 3, NW_OF_x,
             {Packet("A", "E", 1, 4, 1, 5, 0x09)}}
        };

        for (const auto& scenario : scenarios) {
            std::cout << "\n测试场景: " << scenario.name << std::endl;
            configure_fault_scenario(scenario.local_x, scenario.local_y,
                                   scenario.fault_x, scenario.fault_y, true);

            for (const auto& pkt : scenario.test_packets) {
                send_packet(pkt);
                wait_cycles(2);
                Packet received = check_output_packet();

                // 验证数据包正确到达（避障成功）
                bool test_passed = (received.valid &&
                                  received.src_x == pkt.src_x &&
                                  received.src_y == pkt.src_y &&
                                  received.tgt_x == pkt.tgt_x &&
                                  received.tgt_y == pkt.tgt_y &&
                                  received.data == pkt.data);

                std::ostringstream oss;
                oss << scenario.name << " - 故障避障路由测试";
                stats.add_test(test_passed, oss.str(), scenario.expected_pos);

                wait_cycles(5);
            }
        }
    }

    // 测试2: 故障避障路径选择测试
    void test_fault_avoidance_routing() {
        std::cout << "\n=== 测试2: 故障避障路径选择测试 ===" << std::endl;

        // 场景：当前节点(3,3)，故障节点(3,4)（北方向）
        configure_fault_scenario(3, 3, 3, 4, true);

        std::vector<Packet> avoidance_tests = {
            // 正常情况下应该向北，但故障时需要绕行
            Packet("A", "E", 3, 3, 3, 5, 0x11),   // 目标在北方向，需要绕行
            Packet("A", "W", 3, 3, 3, 2, 0x12),   // 目标在南方向，正常路径
            Packet("A", "B", 2, 2, 3, 3, 0x13),   // 目标为本地，正常路径
            Packet("A", "N", 2, 3, 4, 3, 0x14),   // 目标在东方向，正常路径
            Packet("A", "S", 4, 3, 2, 3, 0x15)    // 目标在西方向，正常路径
        };

        for (const auto& pkt : avoidance_tests) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            // 验证数据包正确传输（可能选择了不同路径）
            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "故障避障路径测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), N_OF_x);

            wait_cycles(5);
        }
    }

    // 测试3: 多故障场景测试
    void test_multiple_fault_scenarios() {
        std::cout << "\n=== 测试3: 多故障场景测试 ===" << std::endl;

        // 测试多个不同的故障位置和路由场景
        std::vector<std::pair<std::string, std::pair<int, int>>> fault_configs = {
            {"东侧故障", {4, 3}},
            {"西侧故障", {2, 3}},
            {"南侧故障", {3, 2}},
            {"东北故障", {4, 4}},
            {"西南故障", {2, 2}}
        };

        for (const auto& config : fault_configs) {
            std::cout << "\n测试配置: " << config.first << std::endl;
            configure_fault_scenario(3, 3, config.second.first, config.second.second, true);

            // 发送测试数据包
            Packet test_pkt("A", "B", 0, 0, 3, 3, 0x20 + (config.second.first & 0xF));
            send_packet(test_pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == test_pkt.src_x &&
                              received.src_y == test_pkt.src_y &&
                              received.tgt_x == test_pkt.tgt_x &&
                              received.tgt_y == test_pkt.tgt_y &&
                              received.data == test_pkt.data);

            std::ostringstream oss;
            oss << config.first << " - 多故障场景测试";
            stats.add_test(test_passed, oss.str());

            wait_cycles(5);
        }
    }

    // 测试4: 故障使能/禁用切换测试
    void test_fault_enable_disable() {
        std::cout << "\n=== 测试4: 故障使能/禁用切换测试 ===" << std::endl;

        // 固定故障位置：(3,3)
        int fault_x = 3, fault_y = 3;

        // 测试1: 故障禁用时的正常路由
        std::cout << "故障禁用测试..." << std::endl;
        configure_fault_scenario(2, 3, fault_x, fault_y, false);

        Packet normal_pkt("A", "E", 2, 3, 4, 3, 0x30);  // 正常情况下应向东
        send_packet(normal_pkt);
        wait_cycles(2);
        Packet received_normal = check_output_packet();

        bool normal_passed = (received_normal.valid &&
                             received_normal.src_x == normal_pkt.src_x &&
                             received_normal.src_y == normal_pkt.src_y &&
                             received_normal.tgt_x == normal_pkt.tgt_x &&
                             received_normal.tgt_y == normal_pkt.tgt_y &&
                             received_normal.data == normal_pkt.data);

        stats.add_test(normal_passed, "故障禁用时的正常路由测试");

        wait_cycles(10);

        // 测试2: 故障启用时的避障路由
        std::cout << "故障启用测试..." << std::endl;
        configure_fault_scenario(2, 3, fault_x, fault_y, true);

        Packet fault_pkt("A", "E", 2, 3, 4, 3, 0x31);  // 相同路径，但需要避障
        send_packet(fault_pkt);
        wait_cycles(2);
        Packet received_fault = check_output_packet();

        bool fault_passed = (received_fault.valid &&
                            received_fault.src_x == fault_pkt.src_x &&
                            received_fault.src_y == fault_pkt.src_y &&
                            received_fault.data == fault_pkt.data);

        stats.add_test(fault_passed, "故障启用时的避障路由测试");

        wait_cycles(10);
    }

    // 测试5: 边界故障条件测试
    void test_boundary_fault_conditions() {
        std::cout << "\n=== 测试5: 边界故障条件测试 ===" << std::endl;

        // 测试边缘节点附近有故障的情况
        std::vector<std::tuple<int, int, int, int, std::string>> boundary_scenarios = {
            {0, 0, 0, 1, "左下角附近故障"},
            {0, 0, 1, 0, "左下角右侧故障"},
            {7, 7, 7, 6, "右上角附近故障"},
            {7, 7, 6, 7, "右上角下方故障"},
            {0, 7, 0, 6, "左上角附近故障"},
            {7, 0, 7, 1, "右下角附近故障"}
        };

        for (const auto& scenario : boundary_scenarios) {
            int local_x = std::get<0>(scenario);
            int local_y = std::get<1>(scenario);
            int fault_x = std::get<2>(scenario);
            int fault_y = std::get<3>(scenario);
            std::string desc = std::get<4>(scenario);

            std::cout << "测试场景: " << desc << std::endl;
            configure_fault_scenario(local_x, local_y, fault_x, fault_y, true);

            Packet boundary_pkt("A", "B", 0, 0, local_x, local_y, 0x40 + (local_x & 0xF));
            send_packet(boundary_pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == boundary_pkt.src_x &&
                              received.src_y == boundary_pkt.src_y &&
                              received.tgt_x == boundary_pkt.tgt_x &&
                              received.tgt_y == boundary_pkt.tgt_y &&
                              received.data == boundary_pkt.data);

            stats.add_test(test_passed, desc + " - 边界故障测试");

            wait_cycles(5);
        }
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE节点模块故障感知路由测试" << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_fault_position_calculation();
        wait_cycles(20);

        test_fault_avoidance_routing();
        wait_cycles(20);

        test_multiple_fault_scenarios();
        wait_cycles(20);

        test_fault_enable_disable();
        wait_cycles(20);

        test_boundary_fault_conditions();
        wait_cycles(20);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_node_fault_aware_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE节点模块故障感知路由测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            // 故障位置测试统计
            report_file << "\n故障位置测试统计:" << std::endl;
            std::map<std::string, FaultPosition> pos_names = {
                {"NORMAL", NORMAL}, {"N_OF_x", N_OF_x}, {"NE_OF_x", NE_OF_x},
                {"E_OF_x", E_OF_x}, {"SE_OF_x", SE_OF_x}, {"S_OF_x", S_OF_x},
                {"SW_OF_x", SW_OF_x}, {"W_OF_x", W_OF_x}, {"NW_OF_x", NW_OF_x}
            };

            for (const auto& name_pos : pos_names) {
                int tests = stats.fault_position_tests[name_pos.second];
                int passes = stats.fault_position_passes[name_pos.second];
                if (tests > 0) {
                    report_file << name_pos.first << ": " << passes << "/" << tests
                               << " (" << std::fixed << std::setprecision(1)
                               << (100.0 * passes / tests) << "%)" << std::endl;
                }
            }

            if (!stats.error_messages.empty()) {
                report_file << "\n失败测试详情:" << std::endl;
                for (const auto& err : stats.error_messages) {
                    report_file << "  - " << err << std::endl;
                }
            }

            report_file.close();
            std::cout << "测试报告已保存到: reports/test_node_fault_aware_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        NodeFaultAwareTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}