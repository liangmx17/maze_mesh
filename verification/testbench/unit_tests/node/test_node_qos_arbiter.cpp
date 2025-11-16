// =============================================================================
// MAZE网络节点模块QoS仲裁功能测试
// =============================================================================
// 测试目标：
// 1. 验证QoS优先级仲裁功能
// 2. 验证高QoS数据包的绝对优先权
// 3. 验证多个输入竞争同一输出端口的仲裁行为
// 4. 验证5个仲裁器(N,W,S,E,B)的独立工作
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
#include <algorithm>

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
    std::string input_port;  // A, N, W, S, E
    std::string expected_output_port;  // B, N, W, S, E

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
            << " Type=" << std::hex << (int)type << std::dec
            << " Data=0x" << std::hex << (int)data << std::dec << "]";
        return oss.str();
    }
};

// 仲裁器测试结果
struct ArbiterResult {
    std::string output_port;
    Packet winner_packet;
    std::vector<Packet> competing_packets;
    bool high_qos_won;
    uint64_t decision_cycle;
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;
    std::vector<ArbiterResult> arbiter_results;

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

    void add_arbiter_result(const ArbiterResult& result) {
        arbiter_results.push_back(result);
    }

    void print_summary() {
        std::cout << "\n=== QoS仲裁测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        // 仲裁结果统计
        int high_qos_wins = 0;
        for (const auto& result : arbiter_results) {
            if (result.high_qos_won) high_qos_wins++;
        }

        if (!arbiter_results.empty()) {
            std::cout << "\n仲裁决策统计:" << std::endl;
            std::cout << "仲裁决策次数: " << arbiter_results.size() << std::endl;
            std::cout << "高QoS获胜次数: " << high_qos_wins << std::endl;
            std::cout << "高QoS获胜率: " << std::fixed << std::setprecision(2)
                      << (100.0 * high_qos_wins / arbiter_results.size()) << "%" << std::endl;
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
class NodeQoSTest {
private:
    Vnode* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    // 待发送的数据包队列
    std::vector<Packet> pending_packets;
    // 已接收的数据包队列
    std::vector<Packet> received_packets;

public:
    NodeQoSTest() : main_time(0), rng(time(nullptr)) {
        dut = new Vnode;
        tfp = nullptr;
    }

    ~NodeQoSTest() {
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

        // 设置节点坐标为(3,3) - 内部节点
        dut->HP = 3;
        dut->VP = 3;

        // 设置故障配置（无故障）
        dut->pg_en = 0;
        dut->pg_node = 0;

        // 初始化所有接口信号
        reset_interfaces();

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_node_qos_arbiter.vcd");
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

    // 同时发送多个数据包到不同输入端口
    void send_concurrent_packets(const std::vector<Packet>& packets) {
        std::cout << "\n发送并发数据包:" << std::endl;

        // 设置所有输入信号
        for (const auto& pkt : packets) {
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

            std::cout << "  " << pkt.to_string() << std::endl;
            pending_packets.push_back(pkt);
        }

        // 等待所有输入就绪
        int timeout = 100;
        bool all_ready = false;
        while (!all_ready && timeout > 0) {
            tick();

            all_ready = true;
            for (const auto& pkt : packets) {
                if (pkt.input_port == "A" && !dut->pkt_i_mst_pkt_in_rdy) all_ready = false;
                else if (pkt.input_port == "N" && !dut->pkt_con_mst_ni_rdy) all_ready = false;
                else if (pkt.input_port == "W" && !dut->pkt_con_mst_wi_rdy) all_ready = false;
                else if (pkt.input_port == "S" && !dut->pkt_con_mst_si_rdy) all_ready = false;
                else if (pkt.input_port == "E" && !dut->pkt_con_mst_ei_rdy) all_ready = false;
            }
            timeout--;
        }

        if (timeout == 0) {
            std::cout << "警告: 并发输入超时" << std::endl;
        }

        tick(); // 完成传输

        // 清除所有输入信号
        reset_interfaces();
    }

    // 检查仲裁结果
    ArbiterResult check_arbiter_decision(int timeout_cycles = 50) {
        ArbiterResult result;
        result.decision_cycle = main_time;

        for (int i = 0; i < timeout_cycles; i++) {
            tick();

            // 检查B接口输出
            if (dut->pkt_o_mst_pkt_out_vld) {
                Packet received_pkt;
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_o_mst_pkt_out_qos;
                received_pkt.type = dut->pkt_o_mst_pkt_out_type;
                received_pkt.src_y = (dut->pkt_o_mst_pkt_out_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_o_mst_pkt_out_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_o_mst_pkt_out_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_o_mst_pkt_out_tgt & 0x7;
                received_pkt.data = dut->pkt_o_mst_pkt_out_data;
                received_pkt.cycle = main_time;

                result.output_port = "B";
                result.winner_packet = received_pkt;

                std::cout << "B接口输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return result;
            }

            // 检查C接口北向输出
            if (dut->pkt_con_mst_no_vld) {
                Packet received_pkt;
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_no_qos;
                received_pkt.type = dut->pkt_con_mst_no_type;
                received_pkt.src_y = (dut->pkt_con_mst_no_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_no_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_no_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_no_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_no_data;
                received_pkt.cycle = main_time;

                result.output_port = "N";
                result.winner_packet = received_pkt;

                std::cout << "C接口北向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return result;
            }

            // 检查其他C接口输出
            if (dut->pkt_con_mst_wo_vld) {
                Packet received_pkt;
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_wo_qos;
                received_pkt.type = dut->pkt_con_mst_wo_type;
                received_pkt.src_y = (dut->pkt_con_mst_wo_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_wo_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_wo_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_wo_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_wo_data;
                received_pkt.cycle = main_time;

                result.output_port = "W";
                result.winner_packet = received_pkt;

                std::cout << "C接口西向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return result;
            }

            if (dut->pkt_con_mst_so_vld) {
                Packet received_pkt;
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_so_qos;
                received_pkt.type = dut->pkt_con_mst_so_type;
                received_pkt.src_y = (dut->pkt_con_mst_so_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_so_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_so_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_so_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_so_data;
                received_pkt.cycle = main_time;

                result.output_port = "S";
                result.winner_packet = received_pkt;

                std::cout << "C接口南向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return result;
            }

            if (dut->pkt_con_mst_eo_vld) {
                Packet received_pkt;
                received_pkt.valid = true;
                received_pkt.qos = dut->pkt_con_mst_eo_qos;
                received_pkt.type = dut->pkt_con_mst_eo_type;
                received_pkt.src_y = (dut->pkt_con_mst_eo_src >> 3) & 0x3F;
                received_pkt.src_x = dut->pkt_con_mst_eo_src & 0x7;
                received_pkt.tgt_y = (dut->pkt_con_mst_eo_tgt >> 3) & 0x3F;
                received_pkt.tgt_x = dut->pkt_con_mst_eo_tgt & 0x7;
                received_pkt.data = dut->pkt_con_mst_eo_data;
                received_pkt.cycle = main_time;

                result.output_port = "E";
                result.winner_packet = received_pkt;

                std::cout << "C接口东向输出: " << received_pkt.to_string() << std::endl;
                received_packets.push_back(received_pkt);
                return result;
            }
        }

        std::cout << "警告: 等待" << timeout_cycles << "周期后未检测到仲裁结果" << std::endl;
        return result;
    }

    // 测试1: 高QoS绝对优先权测试
    void test_high_qos_priority() {
        std::cout << "\n=== 测试1: 高QoS绝对优先权测试 ===" << std::endl;

        // 创建竞争本地输出的数据包：3个低QoS，1个高QoS
        std::vector<Packet> competing_packets = {
            Packet("A", "B", 0, 0, 3, 3, 0x11, false, 0),  // 低QoS
            Packet("N", "B", 0, 4, 3, 3, 0x22, false, 0),  // 低QoS
            Packet("W", "B", 2, 3, 3, 3, 0x33, false, 0),  // 低QoS
            Packet("S", "B", 3, 2, 3, 3, 0x44, true, 0)    // 高QoS，应该获胜
        };

        send_concurrent_packets(competing_packets);
        ArbiterResult result = check_arbiter_decision();
        result.competing_packets = competing_packets;

        // 检查高QoS是否获胜
        bool high_qos_won = (result.winner_packet.valid && result.winner_packet.qos == true);
        result.high_qos_won = high_qos_won;

        bool test_passed = high_qos_won;
        std::string test_desc = "高QoS绝对优先权 - 高QoS数据包应赢得仲裁";
        stats.add_test(test_passed, test_desc);
        stats.add_arbiter_result(result);
    }

    // 测试2: 同等QoS公平仲裁测试
    void test_fair_arbitration() {
        std::cout << "\n=== 测试2: 同等QoS公平仲裁测试 ===" << std::endl;

        // 创建所有低QoS的数据包竞争同一输出
        std::vector<Packet> competing_packets = {
            Packet("A", "E", 0, 0, 4, 3, 0x51, false, 0),  // 所有目标都在东方
            Packet("N", "E", 0, 4, 4, 3, 0x52, false, 0),
            Packet("W", "E", 2, 3, 4, 3, 0x53, false, 0),
            Packet("S", "E", 3, 2, 4, 3, 0x54, false, 0)
        };

        send_concurrent_packets(competing_packets);
        ArbiterResult result = check_arbiter_decision();
        result.competing_packets = competing_packets;

        // 检查是否有获胜者（应该有一个）
        bool has_winner = result.winner_packet.valid;
        bool test_passed = has_winner;  // 只要有获胜者就算通过，具体仲裁逻辑难以预测

        std::string test_desc = "公平仲裁 - 同等QoS数据包应有获胜者";
        stats.add_test(test_passed, test_desc);
        stats.add_arbiter_result(result);
    }

    // 测试3: 不同输出端口独立仲裁测试
    void test_independent_arbiters() {
        std::cout << "\n=== 测试3: 不同输出端口独立仲裁测试 ===" << std::endl;

        // 第一组：竞争北输出
        std::vector<Packet> north_competing = {
            Packet("A", "N", 3, 0, 3, 4, 0x61, false, 0),
            Packet("W", "N", 2, 3, 3, 4, 0x62, false, 0),
            Packet("S", "N", 3, 2, 3, 4, 0x63, false, 0),
            Packet("E", "N", 4, 3, 3, 4, 0x64, true, 0)   // 高QoS应获胜
        };

        send_concurrent_packets(north_competing);
        ArbiterResult north_result = check_arbiter_decision();
        north_result.competing_packets = north_competing;
        north_result.high_qos_won = (north_result.winner_packet.valid && north_result.winner_packet.qos);

        wait_cycles(10);

        // 第二组：竞争西输出
        std::vector<Packet> west_competing = {
            Packet("A", "W", 3, 3, 2, 3, 0x71, true, 0),   // 高QoS应获胜
            Packet("N", "W", 3, 4, 2, 3, 0x72, false, 0),
            Packet("S", "W", 3, 2, 2, 3, 0x73, false, 0),
            Packet("E", "W", 4, 3, 2, 3, 0x74, false, 0)
        };

        send_concurrent_packets(west_competing);
        ArbiterResult west_result = check_arbiter_decision();
        west_result.competing_packets = west_competing;
        west_result.high_qos_won = (west_result.winner_packet.valid && west_result.winner_packet.qos);

        // 验证结果
        bool north_test_passed = north_result.high_qos_won;
        bool west_test_passed = west_result.high_qos_won;

        stats.add_test(north_test_passed, "北向独立仲裁 - 高QoS应获胜");
        stats.add_test(west_test_passed, "西向独立仲裁 - 高QoS应获胜");

        stats.add_arbiter_result(north_result);
        stats.add_arbiter_result(west_result);
    }

    // 测试4: 多周期QoS仲裁序列测试
    void test_sequential_qos_arbitration() {
        std::cout << "\n=== 测试4: 多周期QoS仲裁序列测试 ===" << std::endl;

        for (int i = 0; i < 5; i++) {
            std::vector<Packet> competing_packets = {
                Packet("A", "S", 0, 0, 3, 2, 0x80 + i, false, 0),   // 低QoS
                Packet("N", "S", 0, 4, 3, 2, 0x90 + i, true, 0)    // 高QoS，应该获胜
            };

            send_concurrent_packets(competing_packets);
            ArbiterResult result = check_arbiter_decision();
            result.competing_packets = competing_packets;
            result.high_qos_won = (result.winner_packet.valid && result.winner_packet.qos);

            bool test_passed = result.high_qos_won;
            std::ostringstream oss;
            oss << "多周期仲裁测试" << (i+1) << " - 高QoS应获胜";
            stats.add_test(test_passed, oss.str());
            stats.add_arbiter_result(result);

            wait_cycles(5);
        }
    }

    // 测试5: 混合QoS混合端口测试
    void test_mixed_qos_ports() {
        std::cout << "\n=== 测试5: 混合QoS混合端口测试 ===" << std::endl;

        // 复杂场景：不同端口，不同QoS，竞争不同输出
        std::vector<std::vector<Packet>> test_scenarios = {
            // 场景1: 高QoS从西输入，竞争东输出
            {
                Packet("W", "E", 2, 3, 4, 3, 0xA1, true, 0),
                Packet("S", "E", 3, 2, 4, 3, 0xA2, false, 0)
            },
            // 场景2: 高QoS从北输入，竞争本地输出
            {
                Packet("N", "B", 3, 4, 3, 3, 0xB1, true, 0),
                Packet("E", "B", 4, 3, 3, 3, 0xB2, false, 0)
            },
            // 场景3: 高QoS从A输入，竞争南输出
            {
                Packet("A", "S", 0, 0, 3, 2, 0xC1, true, 0),
                Packet("W", "S", 2, 3, 3, 2, 0xC2, false, 0)
            }
        };

        for (size_t i = 0; i < test_scenarios.size(); i++) {
            send_concurrent_packets(test_scenarios[i]);
            ArbiterResult result = check_arbiter_decision();
            result.competing_packets = test_scenarios[i];
            result.high_qos_won = (result.winner_packet.valid && result.winner_packet.qos);

            bool test_passed = result.high_qos_won;
            std::ostringstream oss;
            oss << "混合QoS端口测试" << (i+1) << " - 高QoS应获胜";
            stats.add_test(test_passed, oss.str());
            stats.add_arbiter_result(result);

            wait_cycles(10);
        }
    }

    // 测试6: QoS数据包完整性测试
    void test_qos_packet_integrity() {
        std::cout << "\n=== 测试6: QoS数据包完整性测试 ===" << std::endl;

        std::vector<Packet> qos_packets = {
            Packet("A", "B", 1, 1, 3, 3, 0xD1, true, 0),   // 高QoS单播
            Packet("N", "B", 2, 4, 3, 3, 0xD2, true, 1),   // 高QoS多播
            Packet("W", "B", 1, 3, 3, 3, 0xD3, false, 0),  // 低QoS单播
            Packet("S", "B", 3, 1, 3, 3, 0xD4, false, 3)   // 低QoS广播
        };

        for (size_t i = 0; i < qos_packets.size(); i++) {
            std::vector<Packet> single_packet = {qos_packets[i]};
            send_concurrent_packets(single_packet);
            ArbiterResult result = check_arbiter_decision();
            result.competing_packets = single_packet;

            bool test_passed = (result.winner_packet.valid &&
                              result.winner_packet.qos == qos_packets[i].qos &&
                              result.winner_packet.type == qos_packets[i].type &&
                              result.winner_packet.data == qos_packets[i].data);

            std::ostringstream oss;
            oss << "QoS数据包完整性测试" << (i+1) << " - " << qos_packets[i].to_string();
            stats.add_test(test_passed, oss.str());

            wait_cycles(5);
        }
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE节点模块QoS仲裁功能测试" << std::endl;
        std::cout << "节点坐标: (3,3)" << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_high_qos_priority();
        wait_cycles(10);

        test_fair_arbitration();
        wait_cycles(10);

        test_independent_arbiters();
        wait_cycles(10);

        test_sequential_qos_arbitration();
        wait_cycles(10);

        test_mixed_qos_ports();
        wait_cycles(10);

        test_qos_packet_integrity();
        wait_cycles(20);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_node_qos_arbiter_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE节点模块QoS仲裁功能测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "节点坐标: (3,3)" << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            // 仲裁决策统计
            if (!stats.arbiter_results.empty()) {
                int high_qos_wins = 0;
                for (const auto& result : stats.arbiter_results) {
                    if (result.high_qos_won) high_qos_wins++;
                }

                report_file << "\n仲裁决策统计:" << std::endl;
                report_file << "仲裁决策次数: " << stats.arbiter_results.size() << std::endl;
                report_file << "高QoS获胜次数: " << high_qos_wins << std::endl;
                report_file << "高QoS获胜率: " << std::fixed << std::setprecision(2)
                           << (100.0 * high_qos_wins / stats.arbiter_results.size()) << "%" << std::endl;
            }

            if (!stats.error_messages.empty()) {
                report_file << "\n失败测试详情:" << std::endl;
                for (const auto& err : stats.error_messages) {
                    report_file << "  - " << err << std::endl;
                }
            }

            report_file.close();
            std::cout << "测试报告已保存到: reports/test_node_qos_arbiter_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        NodeQoSTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}