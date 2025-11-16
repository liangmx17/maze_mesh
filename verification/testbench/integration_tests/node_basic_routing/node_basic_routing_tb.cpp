// =============================================================================
// MAZE网络节点基本路由功能测试台
// =============================================================================
// 功能说明：
// 1. 实现P0级别基本路由功能测试（N-RF-001到N-RF-005）
// 2. 验证X方向、Y方向和本地路由的正确性
// 3. 测试不同QoS等级的路由功能
// 4. 支持不同坐标位置的节点测试
// =============================================================================

#include <iostream>
#include <cstdlib>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vnode.h"  // Verilator生成的节点模块头文件
#include "packet_generator.h"
#include "result_checker.h"

// 测试配置参数
#define TEST_CYCLES          1000      // 最大测试周期数
#define WARMUP_CYCLES        10        // 预热周期数
#define PACKET_DELAY_CYCLES  2         // 数据包发送间隔周期
#define MAX_OUTPUT_PACKETS   100       // 最大输出数据包记录数

class NodeBasicRoutingTestbench {
private:
    Vnode* dut;                         // Device Under Test (DUT)
    VerilatedVcdC* tfp;                 // 波形文件指针
    MazePacketGenerator packet_gen;     // 数据包生成器
    MazeResultChecker result_checker;   // 结果检查器
    uint64_t sim_time;                  // 仿真时间
    bool verbose;                       // 详细输出标志
    bool trace_enabled;                 // 波形生成标志

    // 节点配置参数
    uint8_t node_x, node_y;             // 节点坐标
    bool fault_enabled;                 // 故障使能标志
    uint8_t fault_node_id;              // 故障节点ID

public:
    // 构造函数
    NodeBasicRoutingTestbench(uint8_t x = 3, uint8_t y = 3, bool verb = false, bool trace = false)
        : dut(nullptr), tfp(nullptr), sim_time(0), verbose(verb), trace_enabled(trace),
          node_x(x), node_y(y), fault_enabled(false), fault_node_id(0xFF) {

        // 初始化DUT
        dut = new Vnode;

        // 设置DUT参数（通过参数重载或构造函数参数）
        // 注意：这需要在编译时设置参数，或者使用可配置的包装器

        // 初始化结果检查器
        result_checker.set_verbose_logging(verbose);

        printf("MAZE节点基本路由测试台初始化完成\n");
        printf("测试节点位置: (%d, %d)\n", node_x, node_y);
        printf("详细输出: %s\n", verbose ? "启用" : "禁用");
        printf("波形生成: %s\n", trace ? "启用" : "禁用");
    }

    // 析构函数
    ~NodeBasicRoutingTestbench() {
        if (tfp) {
            tfp->close();
            delete tfp;
        }
        if (dut) {
            delete dut;
        }
    }

    // 初始化波形跟踪
    void init_trace(const std::string& trace_file) {
        if (trace_enabled) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open(trace_file.c_str());
            printf("波形跟踪已启用: %s\n", trace_file.c_str());
        }
    }

    // 复位DUT
    void reset_dut() {
        printf("复位DUT...\n");

        // 设置复位信号
        dut->clk = 0;
        dut->rst_n = 0;

        // 设置故障配置（默认无故障）
        dut->pg_en = 0;
        dut->pg_node = 0;

        // 设置所有接口为非活动状态
        dut->pkt_i_pkt_in_vld = 0;
        dut->pkt_con_ni_vld = 0;
        dut->pkt_con_wi_vld = 0;
        dut->pkt_con_si_vld = 0;
        dut->pkt_con_ei_vld = 0;

        // 设置输出就绪信号（允许输出）
        dut->pkt_o_pkt_out_rdy = 1;
        dut->pkt_con_no_rdy = 1;
        dut->pkt_con_wo_rdy = 1;
        dut->pkt_con_so_rdy = 1;
        dut->pkt_con_eo_rdy = 1;

        // 复位周期
        for (int i = 0; i < 5; ++i) {
            dut->clk = !dut->clk;
            dut->eval();
            if (tfp) tfp->dump(sim_time++);
        }

        // 释放复位
        dut->rst_n = 1;

        // 预热周期
        for (int i = 0; i < WARMUP_CYCLES; ++i) {
            tick();
        }

        printf("DUT复位完成\n");
    }

    // 单个时钟周期
    void tick() {
        // 时钟上升沿
        dut->clk = 1;
        dut->eval();
        if (tfp) tfp->dump(sim_time++);

        // 时钟下降沿
        dut->clk = 0;
        dut->eval();
        if (tfp) tfp->dump(sim_time++);

        result_checker.set_cycle(sim_time / 2);  // 设置当前周期
    }

    // 发送数据包到A接口
    bool send_packet_to_A(const MazePacket& packet) {
        if (!dut->pkt_i_pkt_in_rdy) {
            if (verbose) {
                printf("[Cycle %lu] A接口未就绪，无法发送数据包\n", sim_time / 2);
            }
            return false;
        }

        // 设置A接口信号
        dut->pkt_i_pkt_in_vld = 1;
        dut->pkt_i_pkt_in_type = packet.pkt_type;
        dut->pkt_i_pkt_in_qos = packet.pkt_qos;
        dut->pkt_i_pkt_in_src = packet.get_src_id();
        dut->pkt_i_pkt_in_tgt = packet.get_tgt_id();
        dut->pkt_i_pkt_in_data = packet.pkt_data;

        if (verbose) {
            printf("[Cycle %lu] 发送数据包到A接口: %s\n", sim_time / 2, packet.to_string().c_str());
        }

        return true;
    }

    // 发送数据包到C接口
    bool send_packet_to_C(const MazePacket& packet, const std::string& direction) {
        bool ready = false;

        if (direction == "NORTH") {
            ready = dut->pkt_con_ni_rdy;
            if (ready) {
                dut->pkt_con_ni_vld = 1;
                dut->pkt_con_ni_type = packet.pkt_type;
                dut->pkt_con_ni_qos = packet.pkt_qos;
                dut->pkt_con_ni_src = packet.get_src_id();
                dut->pkt_con_ni_tgt = packet.get_tgt_id();
                dut->pkt_con_ni_data = packet.pkt_data;
            }
        } else if (direction == "WEST") {
            ready = dut->pkt_con_wi_rdy;
            if (ready) {
                dut->pkt_con_wi_vld = 1;
                dut->pkt_con_wi_type = packet.pkt_type;
                dut->pkt_con_wi_qos = packet.pkt_qos;
                dut->pkt_con_wi_src = packet.get_src_id();
                dut->pkt_con_wi_tgt = packet.get_tgt_id();
                dut->pkt_con_wi_data = packet.pkt_data;
            }
        } else if (direction == "SOUTH") {
            ready = dut->pkt_con_si_rdy;
            if (ready) {
                dut->pkt_con_si_vld = 1;
                dut->pkt_con_si_type = packet.pkt_type;
                dut->pkt_con_si_qos = packet.pkt_qos;
                dut->pkt_con_si_src = packet.get_src_id();
                dut->pkt_con_si_tgt = packet.get_tgt_id();
                dut->pkt_con_si_data = packet.pkt_data;
            }
        } else if (direction == "EAST") {
            ready = dut->pkt_con_ei_rdy;
            if (ready) {
                dut->pkt_con_ei_vld = 1;
                dut->pkt_con_ei_type = packet.pkt_type;
                dut->pkt_con_ei_qos = packet.pkt_qos;
                dut->pkt_con_ei_src = packet.get_src_id();
                dut->pkt_con_ei_tgt = packet.get_tgt_id();
                dut->pkt_con_ei_data = packet.pkt_data;
            }
        }

        if (verbose) {
            if (ready) {
                printf("[Cycle %lu] 发送数据包到C接口(%s): %s\n",
                       sim_time / 2, direction.c_str(), packet.to_string().c_str());
            } else {
                printf("[Cycle %lu] C接口(%s)未就绪，无法发送数据包\n",
                       sim_time / 2, direction.c_str());
            }
        }

        return ready;
    }

    // 清除所有输入有效信号
    void clear_input_signals() {
        dut->pkt_i_pkt_in_vld = 0;
        dut->pkt_con_ni_vld = 0;
        dut->pkt_con_wi_vld = 0;
        dut->pkt_con_si_vld = 0;
        dut->pkt_con_ei_vld = 0;
    }

    // 检查并记录输出数据包
    void check_and_record_outputs() {
        // 检查B接口输出（本地输出）
        if (dut->pkt_o_pkt_out_vld && dut->pkt_o_pkt_out_rdy) {
            MazePacket output_pkt;
            output_pkt.pkt_type = dut->pkt_o_pkt_out_type;
            output_pkt.pkt_qos = dut->pkt_o_pkt_out_qos;
            output_pkt.decode_packet(
                (output_pkt.pkt_type << 21) |
                (output_pkt.pkt_qos << 20) |
                (dut->pkt_o_pkt_out_src << 14) |
                (dut->pkt_o_pkt_out_tgt << 8) |
                dut->pkt_o_pkt_out_data
            );

            result_checker.add_output_packet(output_pkt, PORT_LOCAL, true);

            if (verbose) {
                printf("[Cycle %lu] B接口输出: %s\n", sim_time / 2, output_pkt.to_string().c_str());
            }
        }

        // 检查C接口北输出
        if (dut->pkt_con_no_vld && dut->pkt_con_no_rdy) {
            MazePacket output_pkt;
            output_pkt.pkt_type = dut->pkt_con_no_type;
            output_pkt.pkt_qos = dut->pkt_con_no_qos;
            output_pkt.decode_packet(
                (output_pkt.pkt_type << 21) |
                (output_pkt.pkt_qos << 20) |
                (dut->pkt_con_no_src << 14) |
                (dut->pkt_con_no_tgt << 8) |
                dut->pkt_con_no_data
            );

            result_checker.add_output_packet(output_pkt, PORT_NORTH, true);

            if (verbose) {
                printf("[Cycle %lu] C接口北输出: %s\n", sim_time / 2, output_pkt.to_string().c_str());
            }
        }

        // 检查C接口西输出
        if (dut->pkt_con_wo_vld && dut->pkt_con_wo_rdy) {
            MazePacket output_pkt;
            output_pkt.pkt_type = dut->pkt_con_wo_type;
            output_pkt.pkt_qos = dut->pkt_con_wo_qos;
            output_pkt.decode_packet(
                (output_pkt.pkt_type << 21) |
                (output_pkt.pkt_qos << 20) |
                (dut->pkt_con_wo_src << 14) |
                (dut->pkt_con_wo_tgt << 8) |
                dut->pkt_con_wo_data
            );

            result_checker.add_output_packet(output_pkt, PORT_WEST, true);

            if (verbose) {
                printf("[Cycle %lu] C接口西输出: %s\n", sim_time / 2, output_pkt.to_string().c_str());
            }
        }

        // 检查C接口南输出
        if (dut->pkt_con_so_vld && dut->pkt_con_so_rdy) {
            MazePacket output_pkt;
            output_pkt.pkt_type = dut->pkt_con_so_type;
            output_pkt.pkt_qos = dut->pkt_con_so_qos;
            output_pkt.decode_packet(
                (output_pkt.pkt_type << 21) |
                (output_pkt.pkt_qos << 20) |
                (dut->pkt_con_so_src << 14) |
                (dut->pkt_con_so_tgt << 8) |
                dut->pkt_con_so_data
            );

            result_checker.add_output_packet(output_pkt, PORT_SOUTH, true);

            if (verbose) {
                printf("[Cycle %lu] C接口南输出: %s\n", sim_time / 2, output_pkt.to_string().c_str());
            }
        }

        // 检查C接口东输出
        if (dut->pkt_con_eo_vld && dut->pkt_con_eo_rdy) {
            MazePacket output_pkt;
            output_pkt.pkt_type = dut->pkt_con_eo_type;
            output_pkt.pkt_qos = dut->pkt_con_eo_qos;
            output_pkt.decode_packet(
                (output_pkt.pkt_type << 21) |
                (output_pkt.pkt_qos << 20) |
                (dut->pkt_con_eo_src << 14) |
                (dut->pkt_con_eo_tgt << 8) |
                dut->pkt_con_eo_data
            );

            result_checker.add_output_packet(output_pkt, PORT_EAST, true);

            if (verbose) {
                printf("[Cycle %lu] C接口东输出: %s\n", sim_time / 2, output_pkt.to_string().c_str());
            }
        }
    }

    // 运行基本路由功能测试
    bool run_basic_routing_tests() {
        printf("\n=== 开始基本路由功能测试 ===\n");
        bool all_passed = true;

        // 生成测试数据包序列
        std::vector<MazePacket> test_packets =
            packet_gen.generate_basic_routing_test_sequence(node_x, node_y);

        printf("生成了 %zu 个测试数据包\n", test_packets.size());

        // 重置结果检查器
        result_checker.reset();

        // 逐个发送测试数据包
        for (size_t i = 0; i < test_packets.size(); ++i) {
            const auto& packet = test_packets[i];

            printf("\n--- 测试 %zu/%zu ---\n", i + 1, test_packets.size());
            MazePacketGenerator::print_packet(packet);

            // 等待几个周期确保接口就绪
            for (int wait = 0; wait < PACKET_DELAY_CYCLES; ++wait) {
                tick();
            }

            // 发送数据包到A接口
            if (send_packet_to_A(packet)) {
                // 运行几个时钟周期让数据包通过DUT
                tick();  // 数据包被采样
                clear_input_signals();  // 清除valid信号

                // 等待数据包通过路由和仲裁
                for (int cycle = 0; cycle < 10; ++cycle) {
                    tick();
                    check_and_record_outputs();

                    // 检查是否有数据包输出
                    if (cycle > 3 && check_output_complete(packet)) {
                        break;
                    }
                }
            } else {
                printf("数据包发送失败\n");
                all_passed = false;
            }
        }

        // 运行额外的周期确保所有数据包输出完成
        for (int cycle = 0; cycle < 20; ++cycle) {
            tick();
            check_and_record_outputs();
        }

        // 验证测试结果
        printf("\n=== 验证测试结果 ===\n");
        auto results = result_checker.run_basic_routing_test_suite(node_x, node_y, packet_gen);

        // 统计通过率
        int passed_count = std::count_if(results.begin(), results.end(),
                                        [](const TestResult& r) { return r.passed; });

        printf("\n基本路由测试完成: %d/%zu 通过\n", passed_count, results.size());

        if (passed_count == results.size()) {
            printf("✓ 所有基本路由功能测试通过！\n");
        } else {
            printf("✗ 部分基本路由功能测试失败\n");
            all_passed = false;
        }

        // 打印详细结果
        if (verbose) {
            result_checker.print_all_output_packets();
        }

        return all_passed;
    }

    // 检查特定数据包是否已输出完成
    bool check_output_complete(const MazePacket& packet) {
        // 在实际实现中，这里会检查结果检查器中是否已经记录了对应的数据包
        // 简化实现，假设4个周期后数据包应该已经输出
        return false;
    }

    // 运行完整的测试套件
    bool run_complete_test_suite() {
        printf("\n=================================\n");
        printf("MAZE节点基本路由功能测试套件\n");
        printf("=================================\n");

        bool result = true;

        // 1. 基本路由功能测试
        result &= run_basic_routing_tests();

        // 2. 生成测试报告
        std::string report_file = "/Users/liangmx17/Documents/maze_mesh/verification/sim/run/temp/test_report.txt";
        result_checker.generate_test_report(report_file);

        // 3. 打印统计信息
        const auto& stats = result_checker.get_statistics();
        stats.print_summary();

        return result;
    }

    // 获取当前仿真周期
    uint64_t get_current_cycle() const {
        return sim_time / 2;
    }
};

// 主函数
int main(int argc, char** argv) {
    // 解析命令行参数
    bool verbose = false;
    bool trace = false;
    uint8_t test_node_x = 3;
    uint8_t test_node_y = 3;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--verbose" || std::string(argv[i]) == "-v") {
            verbose = true;
        } else if (std::string(argv[i]) == "--trace" || std::string(argv[i]) == "-t") {
            trace = true;
        } else if (std::string(argv[i]) == "--node-x") {
            if (i + 1 < argc) {
                test_node_x = std::stoi(argv[++i]) & 0x7;
            }
        } else if (std::string(argv[i]) == "--node-y") {
            if (i + 1 < argc) {
                test_node_y = std::stoi(argv[++i]) & 0x7;
            }
        } else if (std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h") {
            printf("用法: %s [选项]\n", argv[0]);
            printf("选项:\n");
            printf("  -v, --verbose     启用详细输出\n");
            printf("  -t, --trace       生成波形文件\n");
            printf("  --node-x <x>      设置测试节点X坐标 (0-7)\n");
            printf("  --node-y <y>      设置测试节点Y坐标 (0-7)\n");
            printf("  -h, --help        显示帮助信息\n");
            return 0;
        }
    }

    printf("MAZE节点基本路由功能测试\n");
    printf("测试节点位置: (%d, %d)\n", test_node_x, test_node_y);

    // 初始化Verilator
    Verilated::commandArgs(argc, argv);

    // 创建测试台
    NodeBasicRoutingTestbench tb(test_node_x, test_node_y, verbose, trace);

    // 初始化波形跟踪
    if (trace) {
        std::string trace_file = "/Users/liangmx17/Documents/maze_mesh/verification/sim/wave/fst/node_basic_routing.fst";
        tb.init_trace(trace_file);
    }

    // 复位DUT
    tb.reset_dut();

    // 运行测试套件
    bool test_passed = tb.run_complete_test_suite();

    printf("\n测试完成，最终结果: %s\n", test_passed ? "PASS" : "FAIL");

    // 清理
    Verilated::callFinish();

    return test_passed ? 0 : 1;
}