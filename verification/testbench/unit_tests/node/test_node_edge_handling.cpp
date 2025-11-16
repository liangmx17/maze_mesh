// =============================================================================
// MAZE网络节点模块边缘节点处理测试
// =============================================================================
// 测试目标：
// 1. 验证边缘节点(0,0)的边界处理
// 2. 验证边缘节点(7,7)的边界处理
// 3. 验证边缘节点的特殊路由逻辑
// 4. 验证边缘节点故障避障行为
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

// 边缘节点测试场景
struct EdgeNodeScenario {
    std::string name;
    int node_x, node_y;
    bool is_corner;
    bool is_edge_n, is_edge_s, is_edge_w, is_edge_e;
    std::vector<Packet> test_packets;
};

// 测试结果统计
class TestStats {
public:
    int total_tests;
    int passed_tests;
    int failed_tests;
    std::vector<std::string> error_messages;
    std::map<std::string, int> edge_node_tests;
    std::map<std::string, int> edge_node_passes;

    TestStats() : total_tests(0), passed_tests(0), failed_tests(0) {}

    void add_test(bool passed, const std::string& description, const std::string& node_type = "") {
        total_tests++;
        if (passed) {
            passed_tests++;
            edge_node_passes[node_type]++;
            std::cout << "[PASS] " << description << std::endl;
        } else {
            failed_tests++;
            std::cout << "[FAIL] " << description << std::endl;
            error_messages.push_back(description);
        }
        edge_node_tests[node_type]++;
    }

    void print_summary() {
        std::cout << "\n=== 边缘节点处理测试结果汇总 ===" << std::endl;
        std::cout << "总测试数: " << total_tests << std::endl;
        std::cout << "通过: " << passed_tests << std::endl;
        std::cout << "失败: " << failed_tests << std::endl;
        std::cout << "通过率: " << std::fixed << std::setprecision(2)
                  << (total_tests > 0 ? 100.0 * passed_tests / total_tests : 0) << "%" << std::endl;

        // 边缘节点测试统计
        std::cout << "\n边缘节点类型测试统计:" << std::endl;
        for (const auto& type_tests : edge_node_tests) {
            std::string node_type = type_tests.first;
            int tests = type_tests.second;
            int passes = edge_node_passes[node_type];
            if (tests > 0) {
                std::cout << node_type << ": " << passes << "/" << tests
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
class NodeEdgeHandlingTest {
private:
    Vnode* dut;
    VerilatedVcdC* tfp;
    vluint64_t main_time;
    TestStats stats;
    std::mt19937 rng;

    std::vector<Packet> received_packets;

public:
    NodeEdgeHandlingTest() : main_time(0), rng(time(nullptr)) {
        dut = new Vnode;
        tfp = nullptr;
    }

    ~NodeEdgeHandlingTest() {
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
            tfp->open("wave/test_node_edge_handling.vcd");
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

    // 配置边缘节点
    void configure_edge_node(int x, int y, bool fault_enable = false, int fault_x = -1, int fault_y = -1) {
        dut->HP = x;
        dut->VP = y;
        dut->pg_en = fault_enable ? 1 : 0;
        dut->pg_node = fault_enable ? ((fault_y << 3) | fault_x) : 0;

        // 确定边缘状态
        bool is_corner = ((x == 0 || x == 7) && (y == 0 || y == 7));
        bool is_edge_n = (y == 7);
        bool is_edge_s = (y == 0);
        bool is_edge_w = (x == 0);
        bool is_edge_e = (x == 7);

        std::cout << "配置边缘节点: (" << x << "," << y << ")";
        if (is_corner) std::cout << " [角落]";
        if (is_edge_n) std::cout << " [北边缘]";
        if (is_edge_s) std::cout << " [南边缘]";
        if (is_edge_w) std::cout << " [西边缘]";
        if (is_edge_e) std::cout << " [东边缘]";
        std::cout << std::endl;

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

    // 测试1: 左下角节点(0,0)测试
    void test_bottom_left_corner() {
        std::cout << "\n=== 测试1: 左下角节点(0,0)测试 ===" << std::endl;

        configure_edge_node(0, 0);

        std::vector<Packet> corner_tests = {
            Packet("A", "B", 1, 1, 0, 0, 0x01),   // 目标为本地
            Packet("A", "E", 0, 0, 1, 0, 0x02),   // 目标在东边
            Packet("A", "N", 0, 0, 0, 1, 0x03),   // 目标在北边
            Packet("A", "N", 0, 0, 1, 1, 0x04),   // 目标在东北方向
            Packet("N", "B", 0, 1, 0, 0, 0x05),   // 从北方输入到本地
            Packet("E", "B", 1, 0, 0, 0, 0x06)    // 从东方输入到本地
        };

        for (const auto& pkt : corner_tests) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "左下角节点测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), "左下角节点");

            wait_cycles(5);
        }
    }

    // 测试2: 右上角节点(7,7)测试
    void test_top_right_corner() {
        std::cout << "\n=== 测试2: 右上角节点(7,7)测试 ===" << std::endl;

        configure_edge_node(7, 7);

        std::vector<Packet> corner_tests = {
            Packet("A", "B", 6, 6, 7, 7, 0x11),   // 目标为本地
            Packet("A", "W", 7, 7, 6, 7, 0x12),   // 目标在西边
            Packet("A", "S", 7, 7, 7, 6, 0x13),   // 目标在南边
            Packet("A", "S", 7, 7, 6, 6, 0x14),   // 目标在西南方向
            Packet("S", "B", 7, 6, 7, 7, 0x15),   // 从南方输入到本地
            Packet("W", "B", 6, 7, 7, 7, 0x16)    // 从西方输入到本地
        };

        for (const auto& pkt : corner_tests) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "右上角节点测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), "右上角节点");

            wait_cycles(5);
        }
    }

    // 测试3: 边缘节点测试
    void test_edge_nodes() {
        std::cout << "\n=== 测试3: 边缘节点测试 ===" << std::endl;

        std::vector<std::tuple<int, int, std::string>> edge_positions = {
            {3, 0, "南边缘节点"},    // y=0, 南边缘
            {3, 7, "北边缘节点"},    // y=7, 北边缘
            {0, 3, "西边缘节点"},    // x=0, 西边缘
            {7, 3, "东边缘节点"}     // x=7, 东边缘
        };

        for (const auto& pos : edge_positions) {
            int x = std::get<0>(pos);
            int y = std::get<1>(pos);
            std::string name = std::get<2>(pos);

            std::cout << "\n测试: " << name << " (" << x << "," << y << ")" << std::endl;
            configure_edge_node(x, y);

            std::vector<Packet> edge_tests = {
                Packet("A", "B", 2, 2, x, y, 0x20 + (x & 0xF)),  // 目标为本地
                Packet("A", "B", x, y, x, y, 0x30 + (y & 0xF))   // 从本地输入到本地
            };

            for (const auto& pkt : edge_tests) {
                send_packet(pkt);
                wait_cycles(2);
                Packet received = check_output_packet();

                bool test_passed = (received.valid &&
                                  received.src_x == pkt.src_x &&
                                  received.src_y == pkt.src_y &&
                                  received.tgt_x == pkt.tgt_x &&
                                  received.tgt_y == pkt.tgt_y &&
                                  received.data == pkt.data);

                std::ostringstream oss;
                oss << name << " - " << pkt.to_string();
                stats.add_test(test_passed, oss.str(), name);

                wait_cycles(5);
            }
        }
    }

    // 测试4: 边缘节点边界路由测试
    void test_edge_boundary_routing() {
        std::cout << "\n=== 测试4: 边缘节点边界路由测试 ===" << std::endl;

        // 测试西边缘节点(0,3)
        configure_edge_node(0, 3);

        std::vector<Packet> boundary_tests = {
            Packet("A", "E", 0, 3, 1, 3, 0x41),   // 向东路由
            Packet("A", "E", 0, 3, 2, 3, 0x42),   // 向东路由(更远)
            Packet("A", "N", 0, 3, 0, 4, 0x43),   // 向北路由
            Packet("A", "S", 0, 3, 0, 2, 0x44),   // 向南路由
            Packet("A", "N", 0, 3, 1, 4, 0x45),   // 东北方向路由
            Packet("A", "S", 0, 3, 1, 2, 0x46)    // 东南方向路由
        };

        for (const auto& pkt : boundary_tests) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "边界路由测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), "边界路由");

            wait_cycles(5);
        }
    }

    // 测试5: 边缘节点故障避障测试
    void test_edge_fault_avoidance() {
        std::cout << "\n=== 测试5: 边缘节点故障避障测试 ===" << std::endl;

        // 西边缘节点(0,2)，故障节点(1,2)
        configure_edge_node(0, 2, true, 1, 2);

        std::vector<Packet> fault_tests = {
            Packet("A", "N", 0, 2, 2, 2, 0x51),   // 目标在东方，需要绕行
            Packet("A", "B", 1, 1, 0, 2, 0x52),   // 目标为本地
            Packet("A", "N", 0, 2, 0, 3, 0x53),   // 目标在北方，正常路径
            Packet("A", "S", 0, 2, 0, 1, 0x54)    // 目标在南方，正常路径
        };

        for (const auto& pkt : fault_tests) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "边缘故障避障测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), "边缘故障");

            wait_cycles(5);
        }
    }

    // 测试6: 边缘节点多输入测试
    void test_edge_multiple_inputs() {
        std::cout << "\n=== 测试6: 边缘节点多输入测试 ===" << std::endl;

        // 左下角节点(0,0)
        configure_edge_node(0, 0);

        std::vector<Packet> multiple_inputs = {
            Packet("A", "B", 1, 1, 0, 0, 0x61),   // A接口输入
            Packet("N", "B", 0, 1, 0, 0, 0x62),   // 北接口输入
            Packet("E", "B", 1, 0, 0, 0, 0x63)    // 东接口输入
        };

        for (const auto& pkt : multiple_inputs) {
            send_packet(pkt);
            wait_cycles(2);
            Packet received = check_output_packet();

            bool test_passed = (received.valid &&
                              received.src_x == pkt.src_x &&
                              received.src_y == pkt.src_y &&
                              received.tgt_x == pkt.tgt_x &&
                              received.tgt_y == pkt.tgt_y &&
                              received.data == pkt.data);

            std::ostringstream oss;
            oss << "边缘多输入测试 - " << pkt.to_string();
            stats.add_test(test_passed, oss.str(), "边缘多输入");

            wait_cycles(5);
        }
    }

    // 运行所有测试
    void run_all_tests() {
        std::cout << "开始MAZE节点模块边缘节点处理测试" << std::endl;
        std::cout << "======================================" << std::endl;

        init_simulation(true);  // 启用波形跟踪

        test_bottom_left_corner();
        wait_cycles(20);

        test_top_right_corner();
        wait_cycles(20);

        test_edge_nodes();
        wait_cycles(20);

        test_edge_boundary_routing();
        wait_cycles(20);

        test_edge_fault_avoidance();
        wait_cycles(20);

        test_edge_multiple_inputs();
        wait_cycles(20);

        stats.print_summary();

        // 保存测试报告
        save_test_report();
    }

    // 保存测试报告
    void save_test_report() {
        std::ofstream report_file("reports/test_node_edge_handling_report.txt");
        if (report_file.is_open()) {
            report_file << "MAZE节点模块边缘节点处理测试报告" << std::endl;
            report_file << "测试时间: " << std::time(nullptr) << std::endl;
            report_file << "======================================" << std::endl;
            report_file << "总测试数: " << stats.total_tests << std::endl;
            report_file << "通过: " << stats.passed_tests << std::endl;
            report_file << "失败: " << stats.failed_tests << std::endl;
            report_file << "通过率: " << std::fixed << std::setprecision(2)
                       << (stats.total_tests > 0 ? 100.0 * stats.passed_tests / stats.total_tests : 0)
                       << "%" << std::endl;

            // 边缘节点类型测试统计
            report_file << "\n边缘节点类型测试统计:" << std::endl;
            for (const auto& type_tests : stats.edge_node_tests) {
                std::string node_type = type_tests.first;
                int tests = type_tests.second;
                int passes = stats.edge_node_passes[node_type];
                if (tests > 0) {
                    report_file << node_type << ": " << passes << "/" << tests
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
            std::cout << "测试报告已保存到: reports/test_node_edge_handling_report.txt" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        NodeEdgeHandlingTest test;
        test.run_all_tests();

        return (test.stats.failed_tests == 0) ? 0 : 1;

    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}