// =============================================================================
// MAZE网络拓扑模块连接完整性测试
// =============================================================================
// 测试目标：
// 1. 验证拓扑模块所有连接的完整性
// 2. 验证网格连接的正确性
// 3. 验证无断连和错连
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
#define GRID_SIZE 2
#define NUM_NODES 4

// 连接测试结果
struct ConnectionTest {
    int src_node;
    int tgt_node;
    bool connected;
    uint8_t test_data;
};

// 测试统计
class TestStats {
public:
    int total_connections;
    int successful_connections;
    std::vector<ConnectionTest> connection_results;
    std::vector<std::string> errors;

    TestStats() : total_connections(0), successful_connections(0) {}

    void add_connection_test(const ConnectionTest& test) {
        total_connections++;
        connection_results.push_back(test);
        if (test.connected) {
            successful_connections++;
        }
    }

    void print_summary() {
        std::cout << "\n=== 拓扑连接完整性测试结果 ===" << std::endl;
        std::cout << "总连接测试: " << total_connections << std::endl;
        std::cout << "成功连接: " << successful_connections << std::endl;
        std::cout << "连接成功率: " << std::fixed << std::setprecision(1)
                  << (total_connections > 0 ? 100.0 * successful_connections / total_connections : 0)
                  << "%" << std::endl;

        std::cout << "\n详细连接测试结果:" << std::endl;
        for (const auto& conn : connection_results) {
            std::cout << "Node" << conn.src_node << "->Node" << conn.tgt_node
                     << ": " << (conn.connected ? "成功" : "失败")
                     << " (Data=0x" << std::hex << (int)conn.test_data << std::dec << ")" << std::endl;
        }
    }
};

// 主测试类
class TopoIntegrityTest {
private:
    VTOPO* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

public:
    TopoIntegrityTest() : main_time(0), rng(time(nullptr)) {
        dut = new VTOPO;
        tfp = nullptr;
    }

    ~TopoIntegrityTest() {
        if (tfp) {
            tfp->close();
            delete tfp;
        }
        delete dut;
    }

    void init_simulation(bool enable_trace = false) {
        dut->clk = 0;
        dut->rst_n = 0;

        // 初始化所有节点接口
        for (int i = 0; i < NUM_NODES; i++) {
            dut->node_if[i]->pkt_in_vld = 0;
            dut->node_if[i]->pkt_in_qos = 0;
            dut->node_if[i]->pkt_in_type = 0;
            dut->node_if[i]->pkt_in_src = 0;
            dut->node_if[i]->pkt_in_tgt = 0;
            dut->node_if[i]->pkt_in_data = 0;
            dut->node_if[i]->pkt_out_rdy = 1;
            dut->node_if[i]->ni_vld = dut->node_if[i]->wi_vld = 0;
            dut->node_if[i]->si_vld = dut->node_if[i]->ei_vld = 0;
            dut->node_if[i]->no_rdy = dut->node_if[i]->wo_rdy = 1;
            dut->node_if[i]->so_rdy = dut->node_if[i]->eo_rdy = 1;
        }

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_topo_integrity.vcd");
        }

        // 复位
        for (int i = 0; i < 3; i++) tick();
        dut->rst_n = 1;
        for (int i = 0; i < 3; i++) tick();
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

    bool test_single_connection(int src_node, int tgt_node, uint8_t test_data) {
        // 发送测试数据包
        int src_x = src_node % GRID_SIZE;
        int src_y = src_node / GRID_SIZE;
        int tgt_x = tgt_node % GRID_SIZE;
        int tgt_y = tgt_node / GRID_SIZE;

        dut->node_if[src_node]->pkt_in_vld = 1;
        dut->node_if[src_node]->pkt_in_qos = 0;
        dut->node_if[src_node]->pkt_in_type = 0;
        dut->node_if[src_node]->pkt_in_src = (src_y << 3) | src_x;
        dut->node_if[src_node]->pkt_in_tgt = (tgt_y << 3) | tgt_x;
        dut->node_if[src_node]->pkt_in_data = test_data;

        // 等待发送完成
        int timeout = 100;
        while (!dut->node_if[src_node]->pkt_in_rdy && timeout > 0) {
            tick();
            timeout--;
        }

        tick();

        // 清除发送信号
        dut->node_if[src_node]->pkt_in_vld = 0;
        dut->node_if[src_node]->pkt_in_qos = 0;
        dut->node_if[src_node]->pkt_in_type = 0;
        dut->node_if[src_node]->pkt_in_src = 0;
        dut->node_if[src_node]->pkt_in_tgt = 0;
        dut->node_if[src_node]->pkt_in_data = 0;

        // 检查接收
        timeout = 200;
        while (timeout > 0) {
            tick();

            // 检查所有节点的输出
            for (int node_id = 0; node_id < NUM_NODES; node_id++) {
                if (dut->node_if[node_id]->pkt_out_vld) {
                    uint8_t recv_data = dut->node_if[node_id]->pkt_out_data;
                    uint8_t recv_tgt = (dut->node_if[node_id]->pkt_out_tgt & 0x3F);
                    int recv_tgt_node = (recv_tgt & 0x07) + ((recv_tgt >> 3) & 0x07) * GRID_SIZE;

                    if (recv_data == test_data && recv_tgt_node == tgt_node) {
                        return true;  // 连接成功
                    }
                }
            }
            timeout--;
        }

        return false;  // 连接失败
    }

    void test_all_node_connections() {
        std::cout << "\n=== 所有可能节点连接测试 ===" << std::endl;

        for (int src = 0; src < NUM_NODES; src++) {
            for (int tgt = 0; tgt < NUM_NODES; tgt++) {
                if (src != tgt) {
                    uint8_t test_data = 0x80 + src * 16 + tgt;
                    bool connected = test_single_connection(src, tgt, test_data);

                    ConnectionTest conn_test;
                    conn_test.src_node = src;
                    conn_test.tgt_node = tgt;
                    conn_test.connected = connected;
                    conn_test.test_data = test_data;

                    stats.add_connection_test(conn_test);

                    std::cout << "测试 Node" << src << "->Node" << tgt
                             << ": " << (connected ? "成功" : "失败") << std::endl;

                    tick(10);  // 测试间隔
                }
            }
        }
    }

    void run_all_tests() {
        std::cout << "开始MAZE拓扑模块连接完整性测试" << std::endl;
        std::cout << "网格大小: " << GRID_SIZE << "×" << GRID_SIZE << std::endl;

        init_simulation(true);

        test_all_node_connections();

        stats.print_summary();

        // 保存测试报告
        std::ofstream report_file("reports/test_topo_integrity_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE拓扑模块连接完整性测试报告" << std::endl;
            report_file << "总连接测试: " << stats.total_connections << std::endl;
            report_file << "成功连接: " << stats.successful_connections << std::endl;
            report_file << "连接成功率: " << std::fixed << std::setprecision(1)
                       << (stats.total_connections > 0 ? 100.0 * stats.successful_connections / stats.total_connections : 0)
                       << "%" << std::endl;
            report_file.close();
            std::cout << "测试报告已保存到: reports/test_topo_integrity_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        TopoIntegrityTest test;
        test.run_all_tests();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}