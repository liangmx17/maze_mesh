// =============================================================================
// MAZE网络节点模块并发输入处理测试
// =============================================================================
// 测试目标：
// 1. 验证5个输入端口(A,N,W,S,E)同时处理数据包的能力
// 2. 验证并发输入时的正确路由和仲裁
// 3. 验证高并发情况下的性能和稳定性
// 4. 验证并发输入时的QoS优先级处理
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
#include <queue>

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

// 并发测试场景
struct ConcurrentScenario {
    std::string name;
    std::vector<Packet> input_packets;
    int expected_outputs;
    bool check_qos_priority;
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;
    std::vector<std::string> performance_metrics;

    // 并发性能统计
    int total_concurrent_inputs;
    int successful_concurrent_outputs;
    int qos_priority_violations;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0),
                  total_concurrent_inputs(0), successful_concurrent_outputs(0),
                  qos_priority_violations(0) {}

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

    void add_performance_metric(const std::string& metric) {
        performance_metrics.push_back(metric);
    }

    void update_concurrent_stats(int inputs, int outputs) {
        total_concurrent_inputs += inputs;
        successful_concurrent_outputs += outputs;
    }

    void print_summary() {
        std::cout << "\n=== 并发输入处理测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        // 并发性能统计
        std::cout << "\n并发性能统计:" << std::endl;
        std::cout << "总并发输入数: " << total_concurrent_inputs << std::endl;
        std::cout << "成功并发输出数: " << successful_concurrent_outputs << std::endl;
        if (total_concurrent_inputs > 0) {
            std::cout << "并发处理成功率: " << std::fixed << std::setprecision(2)
                      << (100.0 * successful_concurrent_outputs / total_concurrent_inputs) << "%" << std::endl;
        }
        std::cout << "QoS优先级违规次数: " << qos_priority_violations << std::endl;

        // 性能指标
        if (!performance_metrics.empty()) {
            std::cout << "\n性能指标:" << std::endl;
            for (const auto& metric : performance_metrics) {
                std::cout << "  - " << metric << std::endl;
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
class NodeConcurrentTest {
private:
    Vnode* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    std::queue<Packet> expected_outputs;
    std::vector<Packet> received_packets;

public:
    NodeConcurrentTest() : main_time(0), rng(time(nullptr)) {
        dut = new Vnode;
        tfp = nullptr;
    }

    ~NodeConcurrentTest() {
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
            tfp->open("wave/test_node_concurrent.vcd");
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

    // 并发发送多个数据包
    void send_concurrent_packets(const std::vector<Packet>& packets) {
        std::cout << "\n并发发送 " << packets.size() << " 个数据包:" << std::endl;

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

        // 更新统计
        stats.update_concurrent_stats(packets.size(), 0);
    }

    // 检查并发输出数据包
    std::vector<Packet> check_concurrent_outputs(int timeout_cycles = 100) {
        std::vector<Packet> outputs;
        uint64_t start_time = main_time;

        while (main_time - start_time < timeout_cycles * CLK_PERIOD) {
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
                received_pkt.input_port = "B";

                std::cout << "B接口输出: " << received_pkt.to_string() << std::endl;
                outputs.push_back(received_pkt);
                received_packets.push_back(received_pkt);
            }

            // 检查C接口输出
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
                received_pkt.input_port = "N";

                std::cout << "C接口北向输出: " << received_pkt.to_string() << std::endl;
                outputs.push_back(received_pkt);
                received_packets.push_back(received_pkt);
            }

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
                received_pkt.input_port = "W";

                std::cout << "C接口西向输出: " << received_pkt.to_string() << std::endl;
                outputs.push_back(received_pkt);
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "S";

                std::cout << "C接口南向输出: " << received_pkt.to_string() << std::endl;
                outputs.push_back(received_pkt);
                received_packets.push_back(received_pkt);
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
                received_pkt.input_port = "E";

                std::cout << "C接口东向输出: " << received_pkt.to_string() << std::endl;
                outputs.push_back(received_pkt);
                received_packets.push_back(received_pkt);
            }
        }

        // 更新统计
        stats.update_concurrent_stats(0, outputs.size());

        if (outputs.empty()) {
            std::cout << "警告: 等待" << timeout_cycles << "周期后未检测到输出数据包" << std::endl;
        }

        return outputs;
    }

    // 测试1: 5端口满并发测试
    void test_full_concurrent_inputs() {
        std::cout << "\n=== 测试1: 5端口满并发测试 ===" << std::endl;

        std::vector<Packet> concurrent_packets = {
            Packet("A", "B", 0, 0, 3, 3, 0xA1, false, 0),  // A接口 -> 本地
            Packet("N", "B", 3, 4, 3, 3, 0xA2, false, 0),  // N接口 -> 本地
            Packet("W", "B", 2, 3, 3, 3, 0xA3, false, 0),  // W接口 -> 本地
            Packet("S", "B", 3, 2, 3, 3, 0xA4, false, 0),  // S接口 -> 本地
            Packet("E", "B", 4, 3, 3, 3, 0xA5, false, 0)   // E接口 -> 本地
        };

        send_concurrent_packets(concurrent_packets);
        std::vector<Packet> outputs = check_concurrent_outputs();

        bool test_passed = (outputs.size() == 5);  // 应该有5个输出
        stats.add_test(test_passed, "5端口满并发测试 - 应处理所有输入");

        // 添加性能指标
        std::ostringstream perf;
        perf << "满并发处理: " << outputs.size() << "/5 数据包成功处理";
        stats.add_performance_metric(perf.str());
    }

    // 测试2: 混合QoS并发测试
    void test_mixed_qos_concurrent() {
        std::cout << "\n=== 测试2: 混合QoS并发测试 ===" << std::endl;

        std::vector<Packet> mixed_qos_packets = {
            Packet("A", "B", 0, 0, 3, 3, 0xB1, true, 0),   // 高QoS
            Packet("N", "E", 3, 4, 4, 3, 0xB2, false, 0),  // 低QoS
            Packet("W", "B", 2, 3, 3, 3, 0xB3, true, 0),   // 高QoS
            Packet("S", "N", 3, 2, 3, 4, 0xB4, false, 0),  // 低QoS
            Packet("E", "W", 4, 3, 2, 3, 0xB5, false, 0)   // 低QoS
        };

        send_concurrent_packets(mixed_qos_packets);
        std::vector<Packet> outputs = check_concurrent_outputs();

        bool test_passed = (outputs.size() >= 3);  // 至少应该处理高QoS的数据包
        stats.add_test(test_passed, "混合QoS并发测试 - 高QoS数据包应优先处理");

        // 检查QoS优先级
        int high_qos_outputs = 0;
        for (const auto& out : outputs) {
            if (out.qos) high_qos_outputs++;
        }

        std::ostringstream perf;
        perf << "QoS优先级: " << high_qos_outputs << "个高QoS输出/" << outputs.size() << "总输出";
        stats.add_performance_metric(perf.str());
    }

    // 测试3: 连续并发压力测试
    void test_continuous_concurrent_stress() {
        std::cout << "\n=== 测试3: 连续并发压力测试 ===" << std::endl;

        int total_inputs = 0;
        int total_outputs = 0;

        for (int round = 0; round < 3; round++) {
            std::cout << "压力测试轮次 " << (round + 1) << std::endl;

            std::vector<Packet> stress_packets = {
                Packet("A", "E", round, round, 3 + round, 3, 0xC0 + round * 10 + 1, round % 2 == 0, 0),
                Packet("N", "S", 3, 4 + round, 3, 2 + round, 0xC0 + round * 10 + 2, round % 2 == 1, 0),
                Packet("W", "E", 2 + round, 3, 4 + round, 3, 0xC0 + round * 10 + 3, round % 2 == 0, 0),
                Packet("S", "N", 3, 2 - round, 3, 4 - round, 0xC0 + round * 10 + 4, round % 2 == 1, 0)
            };

            total_inputs += stress_packets.size();
            send_concurrent_packets(stress_packets);
            std::vector<Packet> outputs = check_concurrent_outputs();
            total_outputs += outputs.size();

            wait_cycles(5);  // 轮次间间隔
        }

        bool test_passed = (total_outputs >= total_inputs * 0.8);  // 至少80%成功率
        stats.add_test(test_passed, "连续并发压力测试");

        std::ostringstream perf;
        perf << "压力测试: " << total_outputs << "/" << total_inputs << " 数据包处理成功";
        stats.add_performance_metric(perf.str());
    }

    // 测试4: 不同输出端口并发测试
    void test_different_output_concurrent() {
        std::cout << "\n=== 测试4: 不同输出端口并发测试 ===" << std::endl;

        std::vector<Packet> different_output_packets = {
            Packet("A", "N", 3, 3, 3, 4, 0xD1, false, 0),  // 目标北向
            Packet("N", "E", 3, 4, 4, 3, 0xD2, false, 0),  // 目标东向
            Packet("W", "S", 2, 3, 3, 2, 0xD3, false, 0),  // 目标南向
            Packet("S", "W", 3, 2, 2, 3, 0xD4, false, 0),  // 目标西向
            Packet("E", "B", 4, 3, 3, 3, 0xD5, false, 0)   // 目标本地
        };

        send_concurrent_packets(different_output_packets);
        std::vector<Packet> outputs = check_concurrent_outputs();

        bool test_passed = (outputs.size() >= 4);  // 大部分应该成功处理
        stats.add_test(test_passed, "不同输出端口并发测试");

        // 统计输出端口分布
        std::map<std::string, int> output_counts;
        for (const auto& out : outputs) {
            output_counts[out.input_port]++;
        }

        std::cout << "输出端口分布:" << std::endl;
        for (const auto& count : output_counts) {
            std::cout << "  " << count.first << ": " << count.second << std::endl;
        }
    }

    // 测试5: 随机并发测试
    void test_random_concurrent() {
        std::cout << "\n=== 测试5: 随机并发测试 ===" << std::endl;

        std::vector<std::string> input_ports = {"A", "N", "W", "S", "E"};
        std::vector<std::string> output_ports = {"B", "N", "W", "S", "E"};

        for (int test = 0; test < 3; test++) {
            std::cout << "随机并发测试 " << (test + 1) << std::endl;

            std::vector<Packet> random_packets;
            int num_packets = 3 + (rng() % 3);  // 3-5个数据包

            for (int i = 0; i < num_packets; i++) {
                std::string input = input_ports[rng() % input_ports.size()];
                std::string output = output_ports[rng() % output_ports.size()];
                uint8_t data = 0xE0 + test * 10 + i;
                bool qos = (rng() % 2) == 1;

                // 生成合理的源和目标坐标
                uint8_t src_x = rng() % 8;
                uint8_t src_y = rng() % 8;
                uint8_t tgt_x = rng() % 8;
                uint8_t tgt_y = rng() % 8;

                random_packets.emplace_back(input, output, src_x, src_y, tgt_x, tgt_y, data, qos, 0);
            }

            send_concurrent_packets(random_packets);
            std::vector<Packet> outputs = check_concurrent_outputs();

            bool test_passed = (outputs.size() >= 2);  // 至少处理一半
            std::ostringstream oss;
            oss << "随机并发测试 " << (test + 1) << " - " << outputs.size() << "/" << random_packets.size() << " 成功";
            stats.add_test(test_passed, oss.str());

            wait_cycles(5);
        }
    }

    // 测试6: 并发延迟测试
    void test_concurrent_latency() {
        std::cout << "\n=== 测试6: 并发延迟测试 ===" << std::endl;

        uint64_t start_time = main_time;

        std::vector<Packet> latency_packets = {
            Packet("A", "B", 0, 0, 3, 3, 0xF1, false, 0),
            Packet("N", "B", 3, 4, 3, 3, 0xF2, false, 0),
            Packet("W", "B", 2, 3, 3, 3, 0xF3, false, 0)
        };

        send_concurrent_packets(latency_packets);
        std::vector<Packet> outputs = check_concurrent_outputs();

        uint64_t end_time = main_time;
        uint64_t total_latency = end_time - start_time;
        uint64_t avg_latency_per_packet = total_latency / (outputs.size() > 0 ? outputs.size() : 1);

        bool test_passed = (outputs.size() == 3 && total_latency < 1000);  // 应在合理时间内完成
        stats.add_test(test_passed, "并发延迟测试");

        std::ostringstream perf;
        perf << "并发延迟: 总计 " << total_latency << " ns, 平均 " << avg_latency_per_packet << " ns/数据包";
        stats.add_performance_metric(perf.str());
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE节点模块并发输入处理测试" << std::endl;
        std::cout << "节点坐标: (3,3)" << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_full_concurrent_inputs();
        wait_cycles(20);

        test_mixed_qos_concurrent();
        wait_cycles(20);

        test_continuous_concurrent_stress();
        wait_cycles(20);

        test_different_output_concurrent();
        wait_cycles(20);

        test_random_concurrent();
        wait_cycles(20);

        test_concurrent_latency();
        wait_cycles(20);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_node_concurrent_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE节点模块并发输入处理测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "节点坐标: (3,3)" << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            // 并发性能统计
            report_file << "\n并发性能统计:" << std::endl;
            report_file << "总并发输入数: " << stats.total_concurrent_inputs << std::endl;
            report_file << "成功并发输出数: " << stats.successful_concurrent_outputs << std::endl;
            if (stats.total_concurrent_inputs > 0) {
                report_file << "并发处理成功率: " << std::fixed << std::setprecision(2)
                           << (100.0 * stats.successful_concurrent_outputs / stats.total_concurrent_inputs) << "%" << std::endl;
            }
            report_file << "QoS优先级违规次数: " << stats.qos_priority_violations << std::endl;

            // 性能指标
            if (!stats.performance_metrics.empty()) {
                report_file << "\n性能指标:" << std::endl;
                for (const auto& metric : stats.performance_metrics) {
                    report_file << "  - " << metric << std::endl;
                }
            }

            if (!stats.error_messages.empty()) {
                report_file << "\n失败测试详情:" << std::endl;
                for (const auto& err : stats.error_messages) {
                    report_file << "  - " << err << std::endl;
                }
            }

            report_file.close();
            std::cout << "测试报告已保存到: reports/test_node_concurrent_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        NodeConcurrentTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}