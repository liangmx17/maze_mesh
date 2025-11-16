// =============================================================================
// MAZE网络测试结果检查器
// =============================================================================
// 功能说明：
// 1. 验证路由输出的正确性
// 2. 检查数据包完整性
// 3. 验证QoS仲裁结果
// 4. 支持测试结果统计和报告
// =============================================================================

#ifndef __MAZE_RESULT_CHECKER_H__
#define __MAZE_RESULT_CHECKER_H__

#include "packet_generator.h"
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <iostream>
#include <fstream>

// 输出端口枚举
enum OutputPort {
    PORT_NORTH = 0,
    PORT_WEST = 1,
    PORT_SOUTH = 2,
    PORT_EAST = 3,
    PORT_LOCAL = 4,
    PORT_NONE = 5
};

// 测试结果结构体
struct TestResult {
    bool passed;                     // 测试是否通过
    std::string test_name;          // 测试名称
    std::string description;        // 测试描述
    std::string error_msg;          // 错误信息（如果有）
    int expected_cycles;            // 预期周期数
    int actual_cycles;              // 实际周期数
    MazePacket input_packet;        // 输入数据包
    MazePacket output_packet;       // 输出数据包
    OutputPort expected_port;       // 预期输出端口
    OutputPort actual_port;         // 实际输出端口

    TestResult() : passed(false), test_name(""), error_msg(""),
                  expected_cycles(0), actual_cycles(0),
                  expected_port(PORT_NONE), actual_port(PORT_NONE) {}
};

// 监控的输出数据包信息
struct OutputPacketInfo {
    MazePacket packet;
    OutputPort port;
    uint64_t cycle;
    bool valid;

    OutputPacketInfo() : port(PORT_NONE), cycle(0), valid(false) {}
};

// 测试统计信息
struct TestStatistics {
    int total_tests;                // 总测试数
    int passed_tests;               // 通过测试数
    int failed_tests;               // 失败测试数
    double pass_rate;               // 通过率
    std::chrono::milliseconds total_time;  // 总测试时间

    TestStatistics() : total_tests(0), passed_tests(0), failed_tests(0), pass_rate(0.0),
                       total_time(0) {}

    void update_statistics() {
        pass_rate = (total_tests > 0) ? (double)passed_tests / total_tests * 100.0 : 0.0;
    }

    void print_summary() const {
        printf("\n=== 测试统计摘要 ===\n");
        printf("总测试数: %d\n", total_tests);
        printf("通过测试: %d\n", passed_tests);
        printf("失败测试: %d\n", failed_tests);
        printf("通过率: %.2f%%\n", pass_rate);
        printf("总用时: %ld ms\n", total_time.count());
        printf("===================\n\n");
    }
};

class MazeResultChecker {
private:
    std::vector<TestResult> test_results;
    std::vector<OutputPacketInfo> output_packets;
    TestStatistics stats;
    uint64_t current_cycle;
    bool verbose_logging;

public:
    // 构造函数
    MazeResultChecker(bool verbose = false) : current_cycle(0), verbose_logging(verbose) {}

    // 重置检查器状态
    void reset() {
        test_results.clear();
        output_packets.clear();
        stats = TestStatistics();
        current_cycle = 0;
    }

    // 设置当前仿真周期
    void set_cycle(uint64_t cycle) {
        current_cycle = cycle;
    }

    // 添加输出数据包信息
    void add_output_packet(const MazePacket& packet, OutputPort port, bool valid) {
        OutputPacketInfo info;
        info.packet = packet;
        info.port = port;
        info.cycle = current_cycle;
        info.valid = valid;

        output_packets.push_back(info);

        if (verbose_logging && valid) {
            printf("[Cycle %lu] Output on %s: %s\n",
                   current_cycle,
                   get_port_name(port).c_str(),
                   packet.to_string().c_str());
        }
    }

    // 根据输入和输出计算预期路由方向
    OutputPort calculate_expected_route(const MazePacket& input, uint8_t local_x, uint8_t local_y) {
        // 本地路由检查
        if (input.tgt_x == local_x && input.tgt_y == local_y) {
            return PORT_LOCAL;
        }

        // X方向路由
        if (input.tgt_x > local_x) {
            return PORT_EAST;   // 向东
        } else if (input.tgt_x < local_x) {
            return PORT_WEST;   // 向西
        }

        // Y方向路由（X相同时才考虑Y方向）
        if (input.tgt_y > local_y) {
            return PORT_NORTH;  // 向北
        } else if (input.tgt_y < local_y) {
            return PORT_SOUTH;  // 向南
        }

        return PORT_LOCAL;      // 默认本地
    }

    // 验证基本路由功能（N-RF-001到N-RF-005）
    TestResult verify_basic_routing(const MazePacket& input, uint8_t local_x, uint8_t local_y,
                                   const std::string& test_name, const std::string& description) {
        TestResult result;
        result.test_name = test_name;
        result.description = description;
        result.input_packet = input;
        result.expected_port = calculate_expected_route(input, local_x, local_y);

        // 查找匹配的输出数据包
        bool found_output = false;
        uint64_t min_cycle = UINT64_MAX;

        for (const auto& output : output_packets) {
            if (output.valid &&
                output.packet.get_encoded_packet() == input.get_encoded_packet() &&
                output.port == result.expected_port) {
                found_output = true;
                result.output_packet = output.packet;
                result.actual_port = output.port;
                result.actual_cycles = output.cycle - current_cycle;  // 简化的周期计算

                if (output.cycle < min_cycle) {
                    min_cycle = output.cycle;
                }
            }
        }

        result.passed = found_output;
        result.expected_cycles = 2;  // MAZE节点预期2个周期延迟

        if (!found_output) {
            std::ostringstream oss;
            oss << "未找到预期输出。预期端口: " << get_port_name(result.expected_port);
            result.error_msg = oss.str();
        }

        test_results.push_back(result);
        return result;
    }

    // 验证数据包完整性
    bool verify_packet_integrity(const MazePacket& input, const MazePacket& output) {
        return (input.pkt_type == output.pkt_type &&
                input.pkt_qos == output.pkt_qos &&
                input.get_src_id() == output.get_src_id() &&
                input.get_tgt_id() == output.get_tgt_id() &&
                input.pkt_data == output.pkt_data);
    }

    // 验证QoS优先级（高QoS应该优先输出）
    bool verify_qos_priority(const std::vector<MazePacket>& high_qos_inputs,
                           const std::vector<MazePacket>& low_qos_inputs,
                           uint8_t local_x, uint8_t local_y) {
        // 在输出数据包中查找高QoS和低QoS数据包的输出顺序
        uint64_t first_high_qos_cycle = UINT64_MAX;
        uint64_t first_low_qos_cycle = UINT64_MAX;

        for (const auto& output : output_packets) {
            if (output.valid) {
                for (const auto& high_pkt : high_qos_inputs) {
                    if (output.packet.get_encoded_packet() == high_pkt.get_encoded_packet()) {
                        if (output.cycle < first_high_qos_cycle) {
                            first_high_qos_cycle = output.cycle;
                        }
                    }
                }

                for (const auto& low_pkt : low_qos_inputs) {
                    if (output.packet.get_encoded_packet() == low_pkt.get_encoded_packet()) {
                        if (output.cycle < first_low_qos_cycle) {
                            first_low_qos_cycle = output.cycle;
                        }
                    }
                }
            }
        }

        // 高QoS应该比低QoS更早输出
        return (first_high_qos_cycle < first_low_qos_cycle);
    }

    // 运行基本路由功能测试套件
    std::vector<TestResult> run_basic_routing_test_suite(uint8_t node_x, uint8_t node_y,
                                                       MazePacketGenerator& gen) {
        std::vector<TestResult> results;
        std::vector<MazePacket> test_packets = gen.generate_basic_routing_test_sequence(node_x, node_y);

        printf("运行基本路由功能测试套件，节点位置: (%d, %d)\n", node_x, node_y);

        // 清空之前的输出记录
        output_packets.clear();

        // 发送测试数据包（在实际仿真中会通过DUT）
        for (size_t i = 0; i < test_packets.size(); ++i) {
            if (verbose_logging) {
                printf("发送测试包 %zu: %s\n", i + 1, test_packets[i].to_string().c_str());
            }

            // 在实际仿真中，这里会设置DUT的输入信号
            // 然后等待几个周期让数据包通过DUT
            current_cycle += 5;  // 假设每个测试包需要5个周期
        }

        // 等待所有数据包输出完成
        current_cycle += 20;

        // 验证每个测试数据包
        std::string test_names[] = {"N-RF-001", "N-RF-002", "N-RF-003", "N-RF-004", "N-RF-005"};
        std::string test_desc[] = {
            "X方向正向路由测试（向东）",
            "X方向反向路由测试（向西）",
            "Y方向正向路由测试（向北）",
            "Y方向反向路由测试（向南）",
            "本地路由测试"
        };

        for (size_t i = 0; i < test_packets.size() && i < 5; ++i) {
            TestResult result = verify_basic_routing(test_packets[i], node_x, node_y,
                                                   test_names[i], test_desc[i]);
            results.push_back(result);

            printf("%s: %s - %s\n",
                   result.test_name.c_str(),
                   result.passed ? "PASS" : "FAIL",
                   result.description.c_str());

            if (!result.passed && verbose_logging) {
                printf("  错误: %s\n", result.error_msg.c_str());
            }
        }

        return results;
    }

    // 生成测试报告
    void generate_test_report(const std::string& filename) {
        std::ofstream report(filename);
        if (!report.is_open()) {
            printf("错误: 无法创建测试报告文件: %s\n", filename.c_str());
            return;
        }

        // 更新统计信息
        stats.total_tests = test_results.size();
        stats.passed_tests = std::count_if(test_results.begin(), test_results.end(),
                                          [](const TestResult& r) { return r.passed; });
        stats.failed_tests = stats.total_tests - stats.passed_tests;
        stats.update_statistics();

        // 写入报告头
        report << "MAZE网络节点基本路由功能测试报告\n";
        report << "=================================\n\n";
        report << "生成时间: " << std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) << "\n";
        report << "测试工具: Verilator + 自定义测试台\n\n";

        // 写入统计摘要
        report << "测试统计摘要:\n";
        report << "------------\n";
        report << "总测试数: " << stats.total_tests << "\n";
        report << "通过测试: " << stats.passed_tests << "\n";
        report << "失败测试: " << stats.failed_tests << "\n";
        report << "通过率: " << std::fixed << std::setprecision(2) << stats.pass_rate << "%\n";
        report << "总用时: " << stats.total_time.count() << " ms\n\n";

        // 写入详细测试结果
        report << "详细测试结果:\n";
        report << "------------\n";
        for (const auto& result : test_results) {
            report << result.test_name << ": " << (result.passed ? "PASS" : "FAIL") << "\n";
            report << "  描述: " << result.description << "\n";
            report << "  输入包: " << result.input_packet.to_string() << "\n";

            if (result.passed) {
                report << "  输出包: " << result.output_packet.to_string() << "\n";
                report << "  预期端口: " << get_port_name(result.expected_port) << "\n";
                report << "  实际端口: " << get_port_name(result.actual_port) << "\n";
                report << "  周期数: " << result.actual_cycles << "\n";
            } else {
                report << "  错误: " << result.error_msg << "\n";
            }
            report << "\n";
        }

        report.close();
        printf("测试报告已生成: %s\n", filename.c_str());
    }

    // 获取端口名称
    static std::string get_port_name(OutputPort port) {
        switch (port) {
            case PORT_NORTH: return "NORTH";
            case PORT_WEST:  return "WEST";
            case PORT_SOUTH: return "SOUTH";
            case PORT_EAST:  return "EAST";
            case PORT_LOCAL: return "LOCAL";
            case PORT_NONE:  return "NONE";
            default:         return "UNKNOWN";
        }
    }

    // 获取测试统计信息
    const TestStatistics& get_statistics() const {
        return stats;
    }

    // 设置详细日志
    void set_verbose_logging(bool verbose) {
        verbose_logging = verbose;
    }

    // 打印所有输出数据包信息（调试用）
    void print_all_output_packets() const {
        printf("\n=== 所有输出数据包 ===\n");
        for (const auto& output : output_packets) {
            if (output.valid) {
                printf("[Cycle %lu] %s: %s\n",
                       output.cycle,
                       get_port_name(output.port).c_str(),
                       output.packet.to_string().c_str());
            }
        }
        printf("======================\n\n");
    }
};

#endif // __MAZE_RESULT_CHECKER_H__