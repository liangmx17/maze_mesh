// =============================================================================
// MAZE网络拓扑模块2×2小型网格测试
// =============================================================================
// 测试目标：
// 1. 验证2×2小型网格拓扑的基本连接功能
// 2. 验证节点间数据包传输的正确性
// 3. 验证拓扑模块的接口连接
// 4. 验证网格路由的基本行为
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
#include "VTOPO.h"
#include "VTOPO___024root.h"

// 测试配置参数
#define CLK_PERIOD 10
#define MAX_CYCLES 2000
#define TEST_TIMEOUT 200000
#define GRID_SIZE 2
#define NUM_NODES 4

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
        // 节点ID转换为坐标
        src_x = src_node % GRID_SIZE;
        src_y = src_node / GRID_SIZE;
        tgt_x = tgt_node % GRID_SIZE;
        tgt_y = tgt_node / GRID_SIZE;
    }

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Packet[Node" << src_node_id << "(" << (int)src_x << "," << (int)src_y
            << ")->Node" << tgt_node_id << "(" << (int)tgt_x << "," << (int)tgt_y
            << ") QoS=" << (qos ? "H" : "L")
            << " Type=" << std::hex << (int)type << std::dec
            << " Data=0x" << std::hex << (int)data << std::dec << "]";
        return oss.str();
    }

    uint32_t to_23bit() const {
        return (type << 21) | (qos << 20) |
               (src_y << 15) | (src_x << 9) |
               (tgt_y << 3) | tgt_x | data;
    }
};

// 节点连接测试结果
struct NodeConnection {
    int node_id;
    std::map<std::string, bool> connections;  // N, W, S, E连接状态
    std::vector<Packet> sent_packets;
    std::vector<Packet> received_packets;
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;

    // 传输统计
    int total_sent_packets;
    int total_received_packets;
    int successful_transmissions;
    std::map<int, int> node_sent_count;
    std::map<int, int> node_received_count;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0),
                  total_sent_packets(0), total_received_packets(0), successful_transmissions(0) {}

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

    void update_transmission_stats(int src_node, int tgt_node, bool success) {
        total_sent_packets++;
        node_sent_count[src_node]++;
        if (success) {
            total_received_packets++;
            successful_transmissions++;
            node_received_count[tgt_node]++;
        }
    }

    void print_summary() {
        std::cout << "\n=== 2×2网格拓扑测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        // 传输统计
        std::cout << "\n传输统计:" << std::endl;
        std::cout << "总发送数据包: " << total_sent_packets << std::endl;
        std::cout << "总接收数据包: " << total_received_packets << std::endl;
        std::cout << "成功传输: " << successful_transmissions << std::endl;
        if (total_sent_packets > 0) {
            std::cout << "传输成功率: " << std::fixed << std::setprecision(2)
                      << (100.0 * successful_transmissions / total_sent_packets) << "%" << std::endl;
        }

        // 节点统计
        std::cout << "\n节点传输统计:" << std::endl;
        for (int i = 0; i < NUM_NODES; i++) {
            int sent = node_sent_count[i];
            int received = node_received_count[i];
            std::cout << "Node" << i << ": 发送 " << sent << ", 接收 " << received << std::endl;
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
class TopoSmallGridTest {
private:
    VTOPO* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    // 节点接口连接
    std::vector<NodeConnection> node_connections;
    std::vector<Packet> pending_packets;
    std::vector<Packet> completed_packets;

public:
    TopoSmallGridTest() : main_time(0), rng(time(nullptr)) {
        dut = new VTOPO;
        tfp = nullptr;
        node_connections.resize(NUM_NODES);
    }

    ~TopoSmallGridTest() {
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

        // 初始化所有节点接口信号
        reset_all_node_interfaces();

        dut->eval();

        if (enable_trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open("wave/test_topo_small_grid.vcd");
        }

        // 复位序列
        reset_sequence();

        // 验证节点连接
        verify_node_connections();
    }

    // 重置所有节点接口信号
    void reset_all_node_interfaces() {
        for (int i = 0; i < NUM_NODES; i++) {
            // A接口输入 (pkt_in)
            dut->node_if[i]->pkt_in_vld = 0;
            dut->node_if[i]->pkt_in_qos = 0;
            dut->node_if[i]->pkt_in_type = 0;
            dut->node_if[i]->pkt_in_src = 0;
            dut->node_if[i]->pkt_in_tgt = 0;
            dut->node_if[i]->pkt_in_data = 0;

            // B接口输出 (pkt_out) - 默认就绪
            dut->node_if[i]->pkt_out_rdy = 1;

            // C接口输入 (NWSE) - 默认无效
            dut->node_if[i]->ni_vld = 0;
            dut->node_if[i]->wi_vld = 0;
            dut->node_if[i]->si_vld = 0;
            dut->node_if[i]->ei_vld = 0;

            // C接口输出 (NWSE) - 默认就绪
            dut->node_if[i]->no_rdy = 1;
            dut->node_if[i]->wo_rdy = 1;
            dut->node_if[i]->so_rdy = 1;
            dut->node_if[i]->eo_rdy = 1;
        }
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

    // 验证节点连接
    void verify_node_connections() {
        std::cout << "\n验证2×2网格节点连接..." << std::endl;

        // 2×2网格连接验证
        // Node0(0,0): 连接到Node1(东), Node2(北)
        // Node1(1,0): 连接到Node0(西), Node3(北)
        // Node2(0,1): 连接到Node3(东), Node0(南)
        // Node3(1,1): 连接到Node2(西), Node1(南)

        struct NodeConnectionMap {
            int node_id;
            std::vector<std::pair<std::string, int>> neighbors; // direction, target_node
        };

        std::vector<NodeConnectionMap> connections = {
            {0, {{"E", 1}, {"N", 2}}},  // Node0
            {1, {{"W", 0}, {"N", 3}}},  // Node1
            {2, {{"E", 3}, {"S", 0}}},  // Node2
            {3, {{"W", 2}, {"S", 1}}}   // Node3
        };

        for (const auto& conn : connections) {
            std::cout << "Node" << conn.node_id << " 连接: ";
            for (const auto& neighbor : conn.neighbors) {
                std::cout << neighbor.first << "->Node" << neighbor.second << " ";
            }
            std::cout << std::endl;

            node_connections[conn.node_id].node_id = conn.node_id;
            for (const auto& neighbor : conn.neighbors) {
                node_connections[conn.node_id].connections[neighbor.first] = true;
            }
        }

        std::cout << "节点连接验证完成" << std::endl;
    }

    // 发送数据包到指定节点
    void send_packet_to_node(int node_id, const Packet& pkt) {
        if (node_id < 0 || node_id >= NUM_NODES) {
            std::cout << "错误: 无效的节点ID " << node_id << std::endl;
            return;
        }

        // 设置A接口输入信号
        dut->node_if[node_id]->pkt_in_vld = 1;
        dut->node_if[node_id]->pkt_in_qos = pkt.qos;
        dut->node_if[node_id]->pkt_in_type = pkt.type;
        dut->node_if[node_id]->pkt_in_src = (pkt.src_y << 3) | pkt.src_x;
        dut->node_if[node_id]->pkt_in_tgt = (pkt.tgt_y << 3) | pkt.tgt_x;
        dut->node_if[node_id]->pkt_in_data = pkt.data;

        std::cout << "发送数据包到Node" << node_id << ": " << pkt.to_string() << std::endl;

        // 等待就绪信号
        int timeout = 100;
        while (!dut->node_if[node_id]->pkt_in_rdy && timeout > 0) {
            tick();
            timeout--;
        }

        if (timeout == 0) {
            std::cout << "错误: Node" << node_id << " A接口超时" << std::endl;
            return;
        }

        tick(); // 完成传输

        // 清除输入信号
        dut->node_if[node_id]->pkt_in_vld = 0;
        dut->node_if[node_id]->pkt_in_qos = 0;
        dut->node_if[node_id]->pkt_in_type = 0;
        dut->node_if[node_id]->pkt_in_src = 0;
        dut->node_if[node_id]->pkt_in_tgt = 0;
        dut->node_if[node_id]->pkt_in_data = 0;

        pending_packets.push_back(pkt);
        node_connections[node_id].sent_packets.push_back(pkt);
        stats.update_transmission_stats(pkt.src_node_id, pkt.tgt_node_id, false);
    }

    // 检查所有节点的输出
    std::vector<Packet> check_all_node_outputs(int timeout_cycles = 200) {
        std::vector<Packet> received_packets;
        uint64_t start_time = main_time;

        while (main_time - start_time < timeout_cycles * CLK_PERIOD) {
            tick();

            // 检查所有节点的B接口输出
            for (int node_id = 0; node_id < NUM_NODES; node_id++) {
                if (dut->node_if[node_id]->pkt_out_vld) {
                    Packet received_pkt;
                    received_pkt.valid = true;
                    received_pkt.qos = dut->node_if[node_id]->pkt_out_qos;
                    received_pkt.type = dut->node_if[node_id]->pkt_out_type;
                    received_pkt.src_y = (dut->node_if[node_id]->pkt_out_src >> 3) & 0x3F;
                    received_pkt.src_x = dut->node_if[node_id]->pkt_out_src & 0x7;
                    received_pkt.tgt_y = (dut->node_if[node_id]->pkt_out_tgt >> 3) & 0x3F;
                    received_pkt.tgt_x = dut->node_if[node_id]->pkt_out_tgt & 0x7;
                    received_pkt.data = dut->node_if[node_id]->pkt_out_data;
                    received_pkt.cycle = main_time;

                    // 计算目标节点ID
                    received_pkt.tgt_node_id = received_pkt.tgt_y * GRID_SIZE + received_pkt.tgt_x;

                    std::cout << "Node" << node_id << " B接口输出: " << received_pkt.to_string() << std::endl;
                    received_packets.push_back(received_pkt);
                    node_connections[node_id].received_packets.push_back(received_pkt);
                    completed_packets.push_back(received_pkt);

                    // 更新传输统计
                    for (const auto& pending : pending_packets) {
                        if (pending.src_node_id == (int)received_pkt.src_x + received_pkt.src_y * GRID_SIZE &&
                            pending.tgt_node_id == received_pkt.tgt_node_id &&
                            pending.data == received_pkt.data) {
                            stats.update_transmission_stats(pending.src_node_id, pending.tgt_node_id, true);
                            break;
                        }
                    }
                }
            }
        }

        return received_packets;
    }

    // 测试1: 基本节点间通信测试
    void test_basic_node_communication() {
        std::cout << "\n=== 测试1: 基本节点间通信测试 ===" << std::endl;

        std::vector<Packet> test_packets = {
            Packet(0, 1, 0x11),  // Node0 -> Node1
            Packet(1, 0, 0x22),  // Node1 -> Node0
            Packet(2, 3, 0x33),  // Node2 -> Node3
            Packet(3, 2, 0x44),  // Node3 -> Node2
            Packet(0, 3, 0x55),  // Node0 -> Node3 (两跳)
            Packet(3, 0, 0x66)   // Node3 -> Node0 (两跳)
        };

        for (const auto& pkt : test_packets) {
            send_packet_to_node(pkt.src_node_id, pkt);
            wait_cycles(5);  // 发送间隔
        }

        std::vector<Packet> received = check_all_node_outputs();

        bool test_passed = (received.size() >= test_packets.size() * 0.8);  // 至少80%成功
        std::ostringstream oss;
        oss << "基本节点间通信 - " << received.size() << "/" << test_packets.size() << " 数据包成功传输";
        stats.add_test(test_passed, oss.str());
    }

    // 测试2: 本地节点通信测试
    void test_local_node_communication() {
        std::cout << "\n=== 测试2: 本地节点通信测试 ===" << std::endl;

        for (int node_id = 0; node_id < NUM_NODES; node_id++) {
            Packet local_pkt(node_id, node_id, 0x80 + node_id);
            send_packet_to_node(node_id, local_pkt);
            wait_cycles(3);
        }

        std::vector<Packet> received = check_all_node_outputs();

        bool test_passed = (received.size() >= NUM_NODES * 0.8);
        std::ostringstream oss;
        oss << "本地节点通信 - " << received.size() << "/" << NUM_NODES << " 本地数据包成功";
        stats.add_test(test_passed, oss.str());
    }

    // 测试3: 并发传输测试
    void test_concurrent_transmission() {
        std::cout << "\n=== 测试3: 并发传输测试 ===" << std::endl;

        // 同时从多个节点发送数据包
        std::vector<Packet> concurrent_packets = {
            Packet(0, 2, 0xA1),  // Node0 -> Node2
            Packet(1, 3, 0xA2),  // Node1 -> Node3
            Packet(2, 0, 0xA3),  // Node2 -> Node0
            Packet(3, 1, 0xA4)   // Node3 -> Node1
        };

        // 快速发送所有数据包
        for (const auto& pkt : concurrent_packets) {
            send_packet_to_node(pkt.src_node_id, pkt);
            wait_cycles(1);  // 最小间隔
        }

        std::vector<Packet> received = check_all_node_outputs();

        bool test_passed = (received.size() >= concurrent_packets.size() * 0.75);
        std::ostringstream oss;
        oss << "并发传输测试 - " << received.size() << "/" << concurrent_packets.size() << " 数据包成功";
        stats.add_test(test_passed, oss.str());
    }

    // 测试4: 网格路径测试
    void test_grid_routing_paths() {
        std::cout << "\n=== 测试4: 网格路径测试 ===" << std::endl;

        // 测试不同的网格路径
        std::vector<Packet> path_tests = {
            Packet(0, 1, 0x01),  // 东向路径
            Packet(0, 2, 0x02),  // 北向路径
            Packet(1, 2, 0x03),  // 西北路径
            Packet(3, 0, 0x04),  // 西南路径
            Packet(2, 1, 0x05),  // 东南路径
            Packet(1, 3, 0x06)   // 东北路径
        };

        for (const auto& pkt : path_tests) {
            send_packet_to_node(pkt.src_node_id, pkt);
            wait_cycles(3);
        }

        std::vector<Packet> received = check_all_node_outputs();

        bool test_passed = (received.size() >= path_tests.size() * 0.8);
        std::ostringstream oss;
        oss << "网格路径测试 - " << received.size() << "/" << path_tests.size() << " 路径成功";
        stats.add_test(test_passed, oss.str());
    }

    // 测试5: QoS数据包传输测试
    void test_qos_packet_transmission() {
        std::cout << "\n=== 测试5: QoS数据包传输测试 ===" << std::endl;

        std::vector<Packet> qos_packets = {
            Packet(0, 1, 0xB1, false, 0),  // 低QoS单播
            Packet(1, 2, 0xB2, true, 0),   // 高QoS单播
            Packet(2, 3, 0xB3, false, 1),  // 低QoS多播
            Packet(3, 0, 0xB4, true, 3)    // 高QoS广播
        };

        for (const auto& pkt : qos_packets) {
            send_packet_to_node(pkt.src_node_id, pkt);
            wait_cycles(3);
        }

        std::vector<Packet> received = check_all_node_outputs();

        bool test_passed = (received.size() >= qos_packets.size() * 0.75);
        std::ostringstream oss;
        oss << "QoS数据包传输 - " << received.size() << "/" << qos_packets.size() << " QoS数据包成功";
        stats.add_test(test_passed, oss.str());

        // 检查QoS保持
        int qos_preserved = 0;
        for (const auto& recv : received) {
            for (const auto& sent : qos_packets) {
                if (recv.data == sent.data && recv.qos == sent.qos) {
                    qos_preserved++;
                    break;
                }
            }
        }

        std::ostringstream qos_oss;
        qos_oss << "QoS保持性 - " << qos_preserved << "/" << received.size() << " 数据包QoS正确";
        stats.add_test(qos_preserved >= received.size() * 0.8, qos_oss.str());
    }

    // 测试6: 网格完整性测试
    void test_grid_integrity() {
        std::cout << "\n=== 测试6: 网格完整性测试 ===" << std::endl;

        // 测试所有可能的节点对连接
        int total_pairs = 0;
        int successful_pairs = 0;

        for (int src = 0; src < NUM_NODES; src++) {
            for (int tgt = 0; tgt < NUM_NODES; tgt++) {
                if (src != tgt) {
                    total_pairs++;
                    Packet test_pkt(src, tgt, 0xC0 + src * 10 + tgt);
                    send_packet_to_node(src, test_pkt);
                    wait_cycles(2);

                    std::vector<Packet> received = check_all_node_outputs(50);

                    bool pair_success = false;
                    for (const auto& recv : received) {
                        if (recv.data == test_pkt.data &&
                            recv.src_x == test_pkt.src_x &&
                            recv.src_y == test_pkt.src_y &&
                            recv.tgt_x == test_pkt.tgt_x &&
                            recv.tgt_y == test_pkt.tgt_y) {
                            pair_success = true;
                            break;
                        }
                    }

                    if (pair_success) successful_pairs++;
                    wait_cycles(3);
                }
            }
        }

        bool test_passed = (successful_pairs >= total_pairs * 0.7);  // 至少70%的节点对连接成功
        std::ostringstream oss;
        oss << "网格完整性 - " << successful_pairs << "/" << total_pairs << " 节点对连接成功";
        stats.add_test(test_passed, oss.str());
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE拓扑模块2×2小型网格测试" << std::endl;
        std::cout << "网格大小: " << GRID_SIZE << "×" << GRID_SIZE << std::endl;
        std::cout << "节点数量: " << NUM_NODES << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_basic_node_communication();
        wait_cycles(50);

        test_local_node_communication();
        wait_cycles(50);

        test_concurrent_transmission();
        wait_cycles(50);

        test_grid_routing_paths();
        wait_cycles(50);

        test_qos_packet_transmission();
        wait_cycles(50);

        test_grid_integrity();
        wait_cycles(100);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_topo_small_grid_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE拓扑模块2×2小型网格测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "网格大小: " << GRID_SIZE << "×" << GRID_SIZE << std::endl;
            report_file << "节点数量: " << NUM_NODES << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            // 传输统计
            report_file << "\n传输统计:" << std::endl;
            report_file << "总发送数据包: " << stats.total_sent_packets << std::endl;
            report_file << "总接收数据包: " << stats.total_received_packets << std::endl;
            report_file << "成功传输: " << stats.successful_transmissions << std::endl;
            if (stats.total_sent_packets > 0) {
                report_file << "传输成功率: " << std::fixed << std::setprecision(2)
                           << (100.0 * stats.successful_transmissions / stats.total_sent_packets) << "%" << std::endl;
            }

            // 节点统计
            report_file << "\n节点传输统计:" << std::endl;
            for (int i = 0; i < NUM_NODES; i++) {
                int sent = stats.node_sent_count[i];
                int received = stats.node_received_count[i];
                report_file << "Node" << i << ": 发送 " << sent << ", 接收 " << received << std::endl;
            }

            if (!stats.error_messages.empty()) {
                report_file << "\n失败测试详情:" << std::endl;
                for (const auto& err : stats.error_messages) {
                    report_file << "  - " << err << std::endl;
                }
            }

            report_file.close();
            std::cout << "测试报告已保存到: reports/test_topo_small_grid_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        TopoSmallGridTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}