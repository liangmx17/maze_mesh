#!/bin/bash

# =============================================================================
# MAZE网络芯片完整测试套件执行脚本
# =============================================================================
# 功能：运行所有node和topo模块的测试
# 使用方法：./run_all_tests.sh [选项]
# =============================================================================

# 设置基本参数
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"
VERIFICATION_DIR="$ROOT_DIR"
TESTBENCH_DIR="$VERIFICATION_DIR/testbench/unit_tests"
REPORTS_DIR="$VERIFICATION_DIR/reports/simulation"
COVERAGE_DIR="$VERIFICATION_DIR/reports/coverage"

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 函数：打印带颜色的消息
print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# 函数：显示帮助信息
show_help() {
    echo "MAZE网络芯片测试套件执行脚本"
    echo "==============================="
    echo ""
    echo "用法: $0 [选项]"
    echo ""
    echo "选项:"
    echo "  -h, --help          显示此帮助信息"
    echo "  -n, --node-only     仅运行node模块测试"
    echo "  -t, --topo-only     仅运行topo模块测试"
    echo "  -q, --quick         快速模式(无波形生成)"
    echo "  -v, --verbose       详细输出"
    echo "  -c, --coverage      收集覆盖率数据"
    echo "  -w, --wave          生成波形文件"
    echo "  -j, --jobs N        并行编译任务数(默认: 4)"
    echo ""
    echo "示例:"
    echo "  $0                  运行所有测试"
    echo "  $0 --node-only      仅运行node模块测试"
    echo "  $0 --quick          快速运行所有测试"
    echo "  $0 --coverage       运行测试并收集覆盖率"
    echo ""
}

# 函数：检查依赖
check_dependencies() {
    print_info "检查测试依赖..."

    local missing_deps=()

    # 检查Verilator
    if ! command -v verilator &> /dev/null; then
        missing_deps+=("verilator")
    fi

    # 检查make
    if ! command -v make &> /dev/null; then
        missing_deps+=("make")
    fi

    # 检查g++
    if ! command -v g++ &> /dev/null; then
        missing_deps+=("g++")
    fi

    if [ ${#missing_deps[@]} -ne 0 ]; then
        print_error "缺少以下依赖:"
        for dep in "${missing_deps[@]}"; do
            echo "  - $dep"
        done
        echo "请安装缺少的依赖后重新运行"
        exit 1
    fi

    print_success "所有依赖检查通过"
}

# 函数：准备测试环境
prepare_environment() {
    print_info "准备测试环境..."

    # 创建必要的目录
    mkdir -p "$VERIFICATION_DIR/sim/build"
    mkdir -p "$VERIFICATION_DIR/sim/wave/vcd"
    mkdir -p "$VERIFICATION_DIR/sim/wave/fst"
    mkdir -p "$REPORTS_DIR"
    mkdir -p "$COVERAGE_DIR"

    print_success "测试环境准备完成"
}

# 函数：运行node模块测试
run_node_tests() {
    print_info "开始运行node模块测试..."
    echo "=================================="

    local node_dir="$TESTBENCH_DIR/node"
    local make_cmd="make"

    if [ "$QUICK_MODE" = true ]; then
        make_cmd="$make_cmd quick_test"
    elif [ "$WAVE_MODE" = true ]; then
        make_cmd="$make_cmd test"
    else
        make_cmd="$make_cmd test"
    fi

    cd "$node_dir"

    if [ "$VERBOSE" = true ]; then
        $make_cmd
    else
        $make_cmd > /dev/null 2>&1
    fi

    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        print_success "Node模块测试完成"
    else
        print_error "Node模块测试失败 (退出码: $exit_code)"
        return 1
    fi

    return 0
}

# 函数：运行topo模块测试
run_topo_tests() {
    print_info "开始运行topo模块测试..."
    echo "=================================="

    local topo_dir="$TESTBENCH_DIR/topo"
    local make_cmd="make"

    if [ "$QUICK_MODE" = true ]; then
        make_cmd="$make_cmd quick_test"
    elif [ "$WAVE_MODE" = true ]; then
        make_cmd="$make_cmd test"
    else
        make_cmd="$make_cmd test"
    fi

    cd "$topo_dir"

    if [ "$VERBOSE" = true ]; then
        $make_cmd
    else
        $make_cmd > /dev/null 2>&1
    fi

    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        print_success "Topo模块测试完成"
    else
        print_error "Topo模块测试失败 (退出码: $exit_code)"
        return 1
    fi

    return 0
}

# 函数：收集覆盖率数据
collect_coverage_data() {
    if [ "$COLLECT_COVERAGE" = true ]; then
        print_info "收集覆盖率数据..."

        local coverage_script="$SCRIPT_DIR/collect_coverage.sh"

        if [ -f "$coverage_script" ]; then
            if [ "$NODE_ONLY" = false ] && [ "$TOPO_ONLY" = false ]; then
                $coverage_script all
            elif [ "$NODE_ONLY" = true ]; then
                $coverage_script node
            elif [ "$TOPO_ONLY" = true ]; then
                $coverage_script topo
            fi
        else
            print_warning "覆盖率收集脚本不存在，跳过覆盖率收集"
        fi
    fi
}

# 函数：生成测试报告摘要
generate_test_summary() {
    print_info "生成测试报告摘要..."

    local summary_file="$REPORTS_DIR/test_summary_$(date +%Y%m%d_%H%M%S).txt"

    {
        echo "MAZE网络芯片测试执行摘要"
        echo "======================="
        echo "执行时间: $(date)"
        echo "执行选项:"
        if [ "$NODE_ONLY" = true ]; then echo "  - 仅Node模块测试"; fi
        if [ "$TOPO_ONLY" = true ]; then echo "  - 仅Topo模块测试"; fi
        if [ "$QUICK_MODE" = true ]; then echo "  - 快速模式"; fi
        if [ "$WAVE_MODE" = true ]; then echo "  - 波形生成"; fi
        if [ "$COLLECT_COVERAGE" = true ]; then echo "  - 覆盖率收集"; fi
        echo ""

        echo "生成的报告文件:"
        if [ -d "$REPORTS_DIR" ]; then
            ls -la "$REPORTS_DIR"/*.txt 2>/dev/null | awk '{print "  " $9}' || echo "  (无报告文件)"
        fi

        if [ "$COLLECT_COVERAGE" = true ] && [ -d "$COVERAGE_DIR" ]; then
            echo ""
            echo "覆盖率报告:"
            ls -la "$COVERAGE_DIR"/*.txt 2>/dev/null | awk '{print "  " $9}' || echo "  (无覆盖率文件)"
        fi

        if [ "$WAVE_MODE" = true ] && [ -d "$VERIFICATION_DIR/sim/wave" ]; then
            echo ""
            echo "波形文件:"
            find "$VERIFICATION_DIR/sim/wave" -name "*.fst" -o -name "*.vcd" | head -10 | awk '{print "  " $1}' || echo "  (无波形文件)"
        fi

    } > "$summary_file"

    print_success "测试报告摘要已生成: $summary_file"
}

# 函数：清理临时文件
cleanup_temp_files() {
    if [ "$KEEP_TEMP_FILES" = false ]; then
        print_info "清理临时文件..."

        # 清理编译临时文件
        if [ -d "$VERIFICATION_DIR/sim/build" ]; then
            find "$VERIFICATION_DIR/sim/build" -name "*.o" -delete 2>/dev/null
            find "$VERIFICATION_DIR/sim/build" -name "*.d" -delete 2>/dev/null
        fi

        print_success "临时文件清理完成"
    fi
}

# 默认参数
NODE_ONLY=false
TOPO_ONLY=false
QUICK_MODE=false
VERBOSE=false
COLLECT_COVERAGE=false
WAVE_MODE=true
KEEP_TEMP_FILES=false
JOBS=4

# 解析命令行参数
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_help
            exit 0
            ;;
        -n|--node-only)
            NODE_ONLY=true
            shift
            ;;
        -t|--topo-only)
            TOPO_ONLY=true
            shift
            ;;
        -q|--quick)
            QUICK_MODE=true
            WAVE_MODE=false
            shift
            ;;
        -v|--verbose)
            VERBOSE=true
            shift
            ;;
        -c|--coverage)
            COLLECT_COVERAGE=true
            shift
            ;;
        -w|--wave)
            WAVE_MODE=true
            shift
            ;;
        -j|--jobs)
            JOBS="$2"
            shift 2
            ;;
        *)
            print_error "未知选项: $1"
            show_help
            exit 1
            ;;
    esac
done

# 主执行流程
main() {
    echo "MAZE网络芯片测试套件"
    echo "==================="
    echo "开始时间: $(date)"
    echo ""

    # 检查互斥选项
    if [ "$NODE_ONLY" = true ] && [ "$TOPO_ONLY" = true ]; then
        print_error "不能同时指定 --node-only 和 --topo-only"
        exit 1
    fi

    # 执行测试步骤
    check_dependencies
    prepare_environment

    local overall_success=true

    # 运行测试
    if [ "$TOPO_ONLY" = false ]; then
        if ! run_node_tests; then
            overall_success=false
        fi
        echo ""
    fi

    if [ "$NODE_ONLY" = false ]; then
        if ! run_topo_tests; then
            overall_success=false
        fi
        echo ""
    fi

    # 收集覆盖率
    collect_coverage_data

    # 生成报告
    generate_test_summary

    # 清理
    cleanup_temp_files

    # 最终结果
    echo ""
    echo "=================================="
    if [ "$overall_success" = true ]; then
        print_success "所有测试执行完成！"
    else
        print_error "部分测试执行失败！"
    fi
    echo "结束时间: $(date)"
    echo "=================================="

    if [ "$overall_success" = true ]; then
        exit 0
    else
        exit 1
    fi
}

# 执行主函数
main