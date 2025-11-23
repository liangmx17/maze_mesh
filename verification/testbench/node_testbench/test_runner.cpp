// =============================================================================
// MAZE节点验证环境 - C++测试运行器
// =============================================================================
// 功能：提供C++主程序，控制仿真流程和测试执行

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <signal.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vnode_test_environment.h"

// 测试模式枚举
enum TestMode {
    MODE_IDLE = 0x0,
    MODE_BASIC_ROUTING = 0x1,
    MODE_QOS = 0x2,
    MODE_FAULT_TOLERANCE = 0x3,
    MODE_MULTICAST = 0x4,
    MODE_STRESS = 0x5,
    MODE_ALL = 0xF
};

// 全局变量
static volatile bool keep_running = true;
Vnode_test_environment* dut = nullptr;
VerilatedVcdC* tfp = nullptr;

// 信号处理函数
void signal_handler(int sig) {
    std::cout << "\n[INTERRUPT] 收到信号 " << sig << "，正在优雅退出..." << std::endl;
    keep_running = false;
    if (tfp) {
        tfp->close();
    }
    if (dut) {
        dut->final();
    }
    exit(0);
}

// 解析命令行参数
struct TestConfig {
    bool verbose = false;
    bool trace = false;
    TestMode mode = MODE_ALL;
    int timeout_cycles = 100000;
    std::string wave_file = "node_test.fst";

    TestConfig(int argc, char** argv) {
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];

            if (arg == "--help" || arg == "-h") {
                print_help();
                exit(0);
            }
            else if (arg == "--verbose" || arg == "-v") {
                verbose = true;
            }
            else if (arg == "--trace" || arg == "-t") {
                trace = true;
            }
            else if (arg == "--test") {
                if (i + 1 < argc) {
                    std::string test_name = argv[++i];
                    if (test_name == "basic") {
                        mode = MODE_BASIC_ROUTING;
                    }
                    else if (test_name == "qos") {
                        mode = MODE_QOS;
                    }
                    else if (test_name == "fault") {
                        mode = MODE_FAULT_TOLERANCE;
                    }
                    else if (test_name == "multicast") {
                        mode = MODE_MULTICAST;
                    }
                    else if (test_name == "stress") {
                        mode = MODE_STRESS;
                    }
                    else if (test_name == "all") {
                        mode = MODE_ALL;
                    }
                    else {
                        std::cerr << "错误: 未知的测试名称 '" << test_name << "'" << std::endl;
                        exit(1);
                    }
                }
            }
            else if (arg == "--timeout") {
                if (i + 1 < argc) {
                    timeout_cycles = std::atoi(argv[++i]);
                }
            }
            else if (arg == "--wave") {
                if (i + 1 < argc) {
                    wave_file = argv[++i];
                }
            }
            else {
                std::cerr << "错误: 未知参数 '" << arg << "'" << std::endl;
                print_help();
                exit(1);
            }
        }
    }

    void print_help() {
        std::cout << "MAZE节点验证环境测试运行器\n\n";
        std::cout << "用法: test_runner [选项]\n\n";
        std::cout << "选项:\n";
        std::cout << "  -h, --help              显示此帮助信息\n";
        std::cout << "  -v, --verbose           详细输出模式\n";
        std::cout << "  -t, --trace             生成波形文件\n";
        std::cout << "  --test <name>           指定测试模式:\n";
        std::cout << "                         basic       - 基本路由功能测试\n";
        std::cout << "                         qos         - QoS仲裁测试\n";
        std::cout << "                         fault       - 故障容错测试\n";
        std::cout << "                         multicast   - 多播广播测试\n";
        std::cout << "                         stress      - 压力测试\n";
        std::cout << "                         all         - 完整测试套件 (默认)\n";
        std::cout << "  --timeout <cycles>      仿真超时周期 (默认: 100000)\n";
        std::cout << "  --wave <filename>       指定波形文件名 (默认: node_test.fst)\n";
        std::cout << "\n";
        std::cout << "示例:\n";
        std::cout << "  test_runner                           # 运行完整测试套件\n";
        std::cout << "  test_runner --test basic --trace      # 运行基本测试并生成波形\n";
        std::cout << "  test_runner --test qos --verbose      # 运行QoS测试并显示详细输出\n";
    }
};

// 测试结果结构
struct TestResult {
    bool success = false;
    int cycles_ran = 0;
    std::chrono::milliseconds elapsed_time{0};
    std::string error_message;
};

// 主测试函数
TestResult run_test(const TestConfig& config) {
    TestResult result;

    std::cout << "========================================\n";
    std::cout << "🚀 开始MAZE节点验证测试\n";
    std::cout << "========================================\n";

    if (config.verbose) {
        std::cout << "测试模式: 0x" << std::hex << static_cast<int>(config.mode) << std::dec << "\n";
        std::cout << "超时周期: " << config.timeout_cycles << "\n";
        if (config.trace) {
            std::cout << "波形文件: " << config.wave_file << "\n";
        }
        std::cout << "========================================\n";
    }

    // 记录开始时间
    auto start_time = std::chrono::steady_clock::now();

    try {
        // 创建DUT实例
        dut = new Vnode_test_environment;

        // 设置波形生成
        if (config.trace) {
            Verilated::traceEverOn(true);
            tfp = new VerilatedVcdC;
            dut->trace(tfp, 99);
            tfp->open(config.wave_file.c_str());
            std::cout << "📊 波形文件已启动: " << config.wave_file << "\n";
        }

        // 初始化输入信号
        dut->clk = 0;
        dut->rst_n = 0;
        dut->pg_en = 0;
        dut->pg_node = 0;
        dut->test_start = 0;
        dut->test_mode = config.mode;
        dut->test_complete = 0;
        dut->test_result = 0;

        // 复位序列
        std::cout << "\n🔄 执行复位序列...\n";
        for (int i = 0; i < 10 && keep_running; i++) {
            dut->clk = !dut->clk;
            dut->eval();
            if (tfp) tfp->dump(i);
        }

        // 释放复位
        dut->rst_n = 1;

        // 等待几个周期让稳定
        for (int i = 10; i < 20 && keep_running; i++) {
            dut->clk = !dut->clk;
            dut->eval();
            if (tfp) tfp->dump(i);
        }

        std::cout << "✅ 复位完成\n";

        // 启动测试
        std::cout << "\n🧪 启动测试模式...\n";
        dut->test_start = 1;
        dut->test_mode = config.mode;

        // 主仿真循环
        std::cout << "⏳ 运行仿真循环...\n";
        int cycle_count = 20;

        while (keep_running && cycle_count < config.timeout_cycles) {
            // 时钟上升沿
            dut->clk = 1;
            dut->eval();
            if (tfp) tfp->dump(cycle_count * 2 + 1);

            // 检查测试完成
            if (dut->test_complete) {
                std::cout << "🎯 检测到测试完成信号\n";
                break;
            }

            // 时钟下降沿
            dut->clk = 0;
            dut->eval();
            if (tfp) tfp->dump(cycle_count * 2 + 2);

            // 周期计数
            cycle_count++;

            // 详细模式下的进度输出
            if (config.verbose && cycle_count % 1000 == 0) {
                std::cout << "  已运行 " << cycle_count << " 个周期\n";
            }
        }

        result.cycles_ran = cycle_count;

        // 检查测试结果
        if (dut->test_complete && dut->test_result) {
            result.success = true;
            std::cout << "✅ 测试通过！\n";
        } else if (dut->test_complete && !dut->test_result) {
            result.success = false;
            result.error_message = "测试完成但结果为失败";
            std::cout << "❌ 测试失败！\n";
        } else if (cycle_count >= config.timeout_cycles) {
            result.success = false;
            result.error_message = "测试超时";
            std::cout << "⏰ 测试超时！\n";
        } else {
            result.success = false;
            result.error_message = "测试被中断";
            std::cout << "🛑 测试被中断！\n";
        }

    } catch (const std::exception& e) {
        result.success = false;
        result.error_message = std::string("C++异常: ") + e.what();
        std::cerr << "💥 C++异常: " << e.what() << std::endl;
    } catch (...) {
        result.success = false;
        result.error_message = "未知异常";
        std::cerr << "💥 未知异常发生" << std::endl;
    }

    // 计算执行时间
    auto end_time = std::chrono::steady_clock::now();
    result.elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // 清理资源
    if (tfp) {
        tfp->close();
        delete tfp;
        tfp = nullptr;
    }

    if (dut) {
        dut->final();
        delete dut;
        dut = nullptr;
    }

    return result;
}

// 打印测试结果
void print_test_result(const TestResult& result, const TestConfig& config) {
    std::cout << "\n========================================\n";
    std::cout << "📊 测试结果报告\n";
    std::cout << "========================================\n";

    std::cout << "测试状态: " << (result.success ? "✅ 通过" : "❌ 失败") << "\n";
    std::cout << "运行周期: " << result.cycles_ran << "\n";
    std::cout << "执行时间: " << result.elapsed_time.count() << " ms\n";

    if (!result.success && !result.error_message.empty()) {
        std::cout << "错误信息: " << result.error_message << "\n";
    }

    if (config.trace) {
        std::cout << "波形文件: " << config.wave_file << "\n";
        std::cout << "💡 使用以下命令查看波形:\n";
        std::cout << "   gtkwave " << config.wave_file << "\n";
    }

    std::cout << "========================================\n";
}

int main(int argc, char** argv) {
    // 设置信号处理
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    // 解析命令行参数
    TestConfig config(argc, argv);

    // 初始化Verilator
    Verilated::commandArgs(argc, argv);
    Verilated::randReset(2);  // 随机初始化

    // 运行测试
    TestResult result = run_test(config);

    // 打印结果
    print_test_result(result, config);

    // 返回适当的退出码
    return result.success ? 0 : 1;
}