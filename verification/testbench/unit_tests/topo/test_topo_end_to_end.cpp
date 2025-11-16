// =============================================================================
// MAZE网络拓扑模块端到端传输测试
// =============================================================================
// 测试目标：
// 1. 验证端到端数据包传输的完整性
// 2. 验证数据包在网络中的正确路由
// 3. 验证传输延迟和可靠性
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
#define MAX_CYCLES 2000
#define GRID_SIZE 2
#define NUM_NODES 4

// 数据包结构
struct Packet {
    int src_node;
    int tgt_node;
    uint8_t data;
    bool qos;
    uint64_t send_time;
    uint64_t recv_time;

    Packet(int s, int t, uint8_t d, bool q = false)
        : src_node(s), tgt_node(t), data(d), qos(q), send_time(0), recv_time(0) {}

    uint32_t latency() const {
        return recv_time > send_time ? (recv_time - send_time) / CLK_PERIOD : 0;
    }
};

// 测试统计
class TestStats {
public:
    int total_packets;
    int received_packets;
    std::vector<uint32_t> latencies;
    std::vector<std::string> errors;

    TestStats() : total_packets(0), received_packets(0) {}

    void add_packet_sent() { total_packets++; }
    void add_packet_received(uint32_t latency) {
        received_packets++;
        latencies.push_back(latency);
    }

    void add_error(const std::string& err) {
        errors.push_back(err);
    }

    void print_summary() {
        std::cout << "\n=== 端到端传输测试结果 ===" << std::endl;
        std::cout << "发送数据包: " << total_packets << std::endl;
        std::cout << "接收数据包: " << received_packets << std::endl;
        std::cout << "成功率: " << std::fixed << std::setprecision(1)
                  << (total_packets > 0 ? 100.0 * received_packets / total_packets : 0) << "%" << std::endl;

        if (!latencies.empty()) {
            uint32_t min_lat = *std::min_element(latencies.begin(), latencies.end());
            uint32_t max_lat = *std::max_element(latencies.begin(), latencies.end());
            uint32_t avg_lat = std::accumulate(latencies.begin(), latencies.end(), 0) / latencies.size();

            std::cout << "延迟统计:" << std::endl;
            std::cout << "  最小: " << min_lat << " 周期" << std::endl;
            std::cout << "  最大: " << max_lat << " 周期" << std::endl;
            std::cout << "  平均: " << avg_lat << " 周期" << std::endl;
        }
    }
};

// 主测试类
class TopoEndToEndTest {
private:
    VTOPO* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;
    std::vector<Packet> pending_packets;

public:
    TopoEndToEndTest() : main_time(0), rng(time(nullptr)) {
        dut = new VTOPO;
        tfp = nullptr;
    }

    ~TopoEndToEndTest() {
        if (tfp) {
            tfp->close();
            delete tfp;
        }
        delete dut;
    }

    void init_simulation(bool enable_trace = false) {
        dut->clk = 0;
        dut->rst_n = 0;

        // 初始化接口
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
            tfp->open("wave/test_topo_end_to_end.vcd");
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

    void send_packet(const Packet& pkt) {
        int src_x = pkt.src_node % GRID_SIZE;
        int src_y = pkt.src_node / GRID_SIZE;
        int tgt_x = pkt.tgt_node % GRID_SIZE;
        int tgt_y = pkt.tgt_node / GRID_SIZE;

        dut->node_if[pkt.src_node]->pkt_in_vld = 1;
        dut->node_if[pkt.src_node]->pkt_in_qos = pkt.qos;
        dut->node_if[pkt.src_node]->pkt_in_type = 0;
        dut->node_if[pkt.src_node]->pkt_in_src = (src_y << 3) | src_x;
        dut->node_if[pkt.src_node]->pkt_in_tgt = (tgt_y << 3) | tgt_x;
        dut->node_if[pkt.src_node]->pkt_in_data = pkt.data;

        // 记录发送时间
        const_cast<Packet&>(pkt).send_time = main_time;

        int timeout = 100;
        while (!dut->node_if[pkt.src_node]->pkt_in_rdy && timeout > 0) {
            tick();
            timeout--;
        }

        tick();

        dut->node_if[pkt.src_node]->pkt_in_vld = 0;
        dut->node_if[pkt.src_node]->pkt_in_qos = 0;
        dut->node_if[pkt.src_node]->pkt_in_type = 0;
        dut->node_if[pkt.src_node]->pkt_in_src = 0;
        dut->node_if[pkt.src_node]->pkt_in_tgt = 0;
        dut->node_if[pkt.src_node]->pkt_in_data = 0;

        pending_packets.push_back(pkt);
        stats.add_packet_sent();

        std::cout << "发送: Node" << pkt.src_node << "->Node" << pkt.tgt_node
                  << " Data=0x" << std::hex << (int)pkt.data << std::dec << std::endl;
    }

    void check_outputs(int timeout_cycles = 200) {
        uint64_t start_time = main_time;

        while (main_time - start_time < timeout_cycles * CLK_PERIOD) {
            tick();

            for (int node_id = 0; node_id < NUM_NODES; node_id++) {
                if (dut->node_if[node_id]->pkt_out_vld) {
                    uint8_t data = dut->node_if[node_id]->pkt_out_data;
                    uint8_t tgt_node = (dut->node_if[node_id]->pkt_out_tgt & 0x3F);

                    // 查找匹配的待处理数据包
                    for (auto it = pending_packets.begin(); it != pending_packets.end(); ++it) {
                        if (it->data == data && it->tgt_node == tgt_node) {
                            const_cast<Packet&>(*it).recv_time = main_time;
                            stats.add_packet_received(it->latency());

                            std::cout << "接收: Node" << node_id
                                     << " Data=0x" << std::hex << (int)data << std::dec
                                     << " 延迟=" << it->latency() << " 周期" << std::endl;

                            pending_packets.erase(it);
                            break;
                        }
                    }
                }
            }
        }
    }

    void test_basic_e2e() {
        std::cout << "\n=== 基本端到端测试 ===" << std::endl;

        std::vector<Packet> test_packets = {
            Packet(0, 1, 0x11),
            Packet(1, 2, 0x22),
            Packet(2, 3, 0x33),
            Packet(3, 0, 0x44)
        };

        for (const auto& pkt : test_packets) {
            send_packet(pkt);
            tick();
        }

        check_outputs();

        std::cout << "剩余未处理数据包: " << pending_packets.size() << std::endl;
    }

    void test_all_pairs() {
        std::cout << "\n=== 所有可能节点对测试 ===" << std::endl;

        for (int src = 0; src < NUM_NODES; src++) {
            for (int tgt = 0; tgt < NUM_NODES; tgt++) {
                if (src != tgt) {
                    Packet pkt(src, tgt, 0x80 + src * 10 + tgt);
                    send_packet(pkt);
                    tick();
                }
            }
        }

        check_outputs(300);
    }

    void run_all_tests() {
        std::cout << "开始MAZE拓扑模块端到端传输测试" << std::endl;

        init_simulation(true);

        test_basic_e2e();
        tick(50);

        test_all_pairs();
        tick(100);

        stats.print_summary();

        // 保存报告
        std::ofstream report_file("reports/test_topo_end_to_end_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE拓扑模块端到端传输测试报告" << std::endl;
            report_file << "发送数据包: " << stats.total_packets << std::endl;
            report_file << "接收数据包: " << stats.received_packets << std::endl;
            report_file << "成功率: " << std::fixed << std::setprecision(1)
                       << (stats.total_packets > 0 ? 100.0 * stats.received_packets / stats.total_packets : 0)
                       << "%" << std::endl;
            report_file.close();
            std::cout << "测试报告已保存到: reports/test_topo_end_to_end_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        TopoEndToEndTest test;
        test.run_all_tests();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}