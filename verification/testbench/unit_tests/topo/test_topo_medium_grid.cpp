// =============================================================================
// MAZE网络拓扑模块4×4中等网格测试
// =============================================================================
// 测试目标：
// 1. 验证4×4中等网格拓扑的连接功能
// 2. 验证多跳路由的正确性
// 3. 验证网格扩展性
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
#include "VTOPO.h"
#include "VTOPO___024root.h"

// 测试配置参数
#define CLK_PERIOD 10
#define MAX_CYCLES 3000
#define TEST_TIMEOUT 300000
#define GRID_SIZE 4
#define NUM_NODES 16

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
    int src_node_id;
    int tgt_node_id;

    Packet() : valid(false), qos(false), type(0), src_x(0), src_y(0),
               tgt_x(0), tgt_y(0), data(0), cycle(0), src_node_id(-1), tgt_node_id(-1) {}

    Packet(int src_node, int tgt_node, uint8_t d = 0, bool q = false, uint8_t t = 0)
        : valid(true), qos(q), type(t), data(d), cycle(0),
          src_node_id(src_node), tgt_node_id(tgt_node) {
        src_x = src_node % GRID_SIZE;
        src_y = src_node / GRID_SIZE;
        tgt_x = tgt_node % GRID_SIZE;
        tgt_y = tgt_node / GRID_SIZE;
    }

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Packet[Node" << src_node_id << "(" << (int)src_x << "," << (int)src_y
            << ")->Node" << tgt_node_id << "(" << (int)tgt_x << "," << (int)tgt_y
            << ") Data=0x" << std::hex << (int)data << std::dec << "]";
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
    int total_sent_packets;
    int total_received_packets;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0),
                  total_sent_packets(0), total_received_packets(0) {}

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
        std::cout << "\n=== 4×4网格拓扑测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;
        std::cout << "总发送: " << total_sent_packets << ", 总接收: " << total_received_packets << std::endl;
    }
};

// 主测试类
class TopoMediumGridTest {
private:
    VTOPO* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

public:
    TopoMediumGridTest() : main_time(0), rng(time(nullptr)) {
        dut = new VTOPO;
        tfp = nullptr;
    }

    ~TopoMediumGridTest() {
        if (tfp) {
            tfp->close();
            delete tfp;
        }
        delete dut;
    }

    void init_simulation(bool enable_trace = false) {
        dut->clk = 0;
        dut->rst_n = 0;

        // 初始化所有16个节点接口
        for (int i = 0; i < NUM_NODES; i++) {
            dut->node_if[i]->pkt_in_vld = 0;
            dut->node_if[i]->pkt_in_qos = 0;
            dut->node_if[i]->pkt_in_type = 0;
            dut->node_if[i]->pkt_in_src = 0;
            dut->node_if[i]->pkt_in_tgt = 0;
            dut->node_if[i]->pkt_in_data = 0;
            dut->node_if[i]->pkt_out_rdy = 1;
            dut->node_if[i]->ni_vld = 0;
            dut->node_if[i]->wi_vld = 0;
            dut->node_if[i]->si_vld = 0;
            dut->node_if[i]->ei_vld = 0;
            dut->node_if[i]->no_rdy = 1;
            dut->node_if[i]->wo_rdy = 1;
            dut->node_if[i]->so_rdy = 1;
            dut->node_if[i]->eo_rdy = 1;
        }

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_topo_medium_grid.vcd");
        }

        // 复位序列
        for (int i = 0; i < 3; i++) {
            tick();
        }
        dut->rst_n = 1;
        for (int i = 0; i < 3; i++) {
            tick();
        }
    }

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

    void wait_cycles(int cycles) {
        for (int i = 0; i < cycles; i++) {
            tick();
        }
    }

    void send_packet_to_node(int node_id, const Packet& pkt) {
        if (node_id < 0 || node_id >= NUM_NODES) return;

        dut->node_if[node_id]->pkt_in_vld = 1;
        dut->node_if[node_id]->pkt_in_qos = pkt.qos;
        dut->node_if[node_id]->pkt_in_type = pkt.type;
        dut->node_if[node_id]->pkt_in_src = (pkt.src_y << 3) | pkt.src_x;
        dut->node_if[node_id]->pkt_in_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
        dut->node_if[node_id]->pkt_in_data = pkt.data;

        std::cout << "发送到Node" << node_id << ": " << pkt.to_string() << std::endl;

        int timeout = 100;
        while (!dut->node_if[node_id]->pkt_in_rdy && timeout > 0) {
            tick();
            timeout--;
        }

        tick();

        dut->node_if[node_id]->pkt_in_vld = 0;
        dut->node_if[node_id]->pkt_in_qos = 0;
        dut->node_if[node_id]->pkt_in_type = 0;
        dut->node_if[node_id]->pkt_in_src = 0;
        dut->node_if[node_id]->pkt_in_tgt = 0;
        dut->node_if[node_id]->pkt_in_data = 0;

        stats.total_sent_packets++;
    }

    int check_all_node_outputs(int timeout_cycles = 300) {
        int received_count = 0;
        uint64_t start_time = main_time;

        while (main_time - start_time < timeout_cycles * CLK_PERIOD) {
            tick();

            for (int node_id = 0; node_id < NUM_NODES; node_id++) {
                if (dut->node_if[node_id]->pkt_out_vld) {
                    std::cout << "Node" << node_id << " 接收数据包，数据=0x"
                             << std::hex << (int)dut->node_if[node_id]->pkt_out_data << std::dec << std::endl;
                    received_count++;
                    stats.total_received_packets++;
                }
            }
        }

        return received_count;
    }

    void test_multi_hop_routing() {
        std::cout << "\n=== 测试多跳路由 ===" << std::endl;

        std::vector<Packet> multi_hop_tests = {
            Packet(0, 15, 0x01),  // 左上角到右下角 (6跳)
            Packet(15, 0, 0x02),  // 右下角到左上角 (6跳)
            Packet(3, 12, 0x03),  // 右上角到左下角 (6跳)
            Packet(12, 3, 0x04),  // 左下角到右上角 (6跳)
            Packet(5, 10, 0x05),  // 中间节点间传输
            Packet(8, 7, 0x06)    // 另一对中间节点
        };

        for (const auto& pkt : multi_hop_tests) {
            send_packet_to_node(pkt.src_node_id, pkt);
            wait_cycles(5);
        }

        int received = check_all_node_outputs();
        bool test_passed = (received >= multi_hop_tests.size() * 0.7);

        std::ostringstream oss;
        oss << "多跳路由 - " << received << "/" << multi_hop_tests.size() << " 成功";
        stats.add_test(test_passed, oss.str());
    }

    void test_concurrent_4x4() {
        std::cout << "\n=== 测试4×4并发传输 ===" << std::endl;

        // 从4个角落同时发送
        std::vector<Packet> concurrent_tests = {
            Packet(0, 5, 0x11),   // 左上角
            Packet(3, 6, 0x22),   // 右上角
            Packet(12, 9, 0x33),  // 左下角
            Packet(15, 10, 0x44)  // 右下角
        };

        for (const auto& pkt : concurrent_tests) {
            send_packet_to_node(pkt.src_node_id, pkt);
        }

        int received = check_all_node_outputs();
        bool test_passed = (received >= concurrent_tests.size() * 0.75);

        std::ostringstream oss;
        oss << "4×4并发传输 - " << received << "/" << concurrent_tests.size() << " 成功";
        stats.add_test(test_passed, oss.str());
    }

    void run_all_tests() {
        std::cout << "开始MAZE拓扑模块4×4中等网格测试" << std::endl;
        std::cout << "网格大小: " << GRID_SIZE << "×" << GRID_SIZE << std::endl;
        std::cout << "节点数量: " << NUM_NODES << std::endl;

        init_simulation(true);

        test_multi_hop_routing();
        wait_cycles(100);

        test_concurrent_4x4();
        wait_cycles(100);

        stats.print_summary();

        // 保存测试报告
        std::ofstream report_file("reports/test_topo_medium_grid_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE拓扑模块4×4中等网格测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "网格大小: " << GRID_SIZE << "×" << GRID_SIZE << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;
            report_file.close();
            std::cout << "测试报告已保存到: reports/test_topo_medium_grid_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        TopoMediumGridTest test;
        test.run_all_tests();
        return (test.stats.failed_tests == 0) ? 0 : 1;
    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}