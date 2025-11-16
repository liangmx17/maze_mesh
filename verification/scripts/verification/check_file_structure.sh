#!/bin/bash

# =============================================================================
# MAZE验证环境文件结构检查脚本
# =============================================================================
#
# 用途: 检查verification目录是否符合文件结构规范
# 使用: ./scripts/verification/check_file_structure.sh
# 依赖: 必须在verification根目录执行
#
# =============================================================================

set -e  # 遇到错误立即退出

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 计数器
ERRORS=0
WARNINGS=0
CHECKS=0

# 打印函数
print_header() {
    echo -e "${BLUE}============================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}============================================${NC}"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
    ((ERRORS++))
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
    ((WARNINGS++))
}

print_success() {
    echo -e "${GREEN}[PASS]${NC} $1"
}

print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

check_file() {
    ((CHECKS++))
    if [ -f "$1" ]; then
        print_success "必需文件存在: $1"
        return 0
    else
        print_error "必需文件缺失: $1"
        return 1
    fi
}

check_dir() {
    ((CHECKS++))
    if [ -d "$1" ]; then
        print_success "必需目录存在: $1"
        return 0
    else
        print_error "必需目录缺失: $1"
        return 1
    fi
}

check_not_exist() {
    ((CHECKS++))
    if [ ! -e "$1" ]; then
        print_success "禁用文件/目录不存在: $1"
        return 0
    else
        print_error "禁用文件/目录存在: $1"
        return 1
    fi
}

check_naming() {
    local dir="$1"
    local pattern="$2"
    local desc="$3"

    print_info "检查 $desc 命名规范..."

    for item in "$dir"/*; do
        if [ -e "$item" ]; then
            basename_item=$(basename "$item")
            if [[ ! "$basename_item" =~ $pattern ]]; then
                print_warning "命名不符合规范: $basename_item (应该匹配: $pattern)"
            fi
        fi
    done
}

# =============================================================================
# 主要检查函数
# =============================================================================

main() {
    print_header "MAZE验证环境文件结构检查"

    # 检查当前目录
    if [ ! -f "Makefile" ] || [ ! -d "testbench" ]; then
        print_error "请在verification根目录执行此脚本"
        exit 1
    fi

    print_info "当前目录: $(pwd)"
    print_info "检查时间: $(date)"
    echo

    # 1. 检查根目录必需文件
    print_header "1. 根目录文件检查"
    check_file "Makefile"
    check_file "README.md"
    check_file "docs/FILE_STRUCTURE_STANDARD.md"

    # 2. 检查目录结构
    print_header "2. 目录结构检查"

    # 必需目录
    check_dir "docs"
    check_dir "testbench"
    check_dir "scripts"
    check_dir "sim"
    check_dir "reports"
    check_dir "logs"

    # 子目录
    check_dir "docs/architecture"
    check_dir "docs/test_plans"
    check_dir "docs/user_guides"
    check_dir "testbench/unit_tests"
    check_dir "testbench/integration_tests"
    check_dir "testbench/system_tests"
    check_dir "testbench/utils"
    check_dir "scripts/build"
    check_dir "scripts/run"
    check_dir "scripts/analysis"
    check_dir "scripts/verification"
    check_dir "sim/work"
    check_dir "sim/wave"

    # 3. 检查禁用目录/文件（不应该存在）
    print_header "3. 禁用文件/目录检查"
    check_not_exist "verification"  # 重复的verification目录
    check_not_exist "sim/build"     # 旧的build目录
    check_not_exist "work"          # 根目录下的work目录

    # 4. 检查文件命名规范
    print_header "4. 文件命名规范检查"

    # 检查测试文件命名
    if [ -d "testbench/unit_tests" ]; then
        check_naming "testbench/unit_tests" "^[a-z][a-z0-9_]*$" "单元测试目录"
    fi

    # 检查脚本文件命名
    if [ -d "scripts/build" ]; then
        for script in scripts/build/*.sh; do
            if [ -f "$script" ]; then
                basename_script=$(basename "$script")
                if [[ ! "$basename_script" =~ ^[a-z][a-z0-9_]*\.sh$ ]]; then
                    print_warning "脚本命名不符合规范: $basename_script (应该: 动词_名词.sh)"
                fi
            fi
        done
    fi

    # 5. 检查gitignore
    print_header "5. Git配置检查"
    if [ -f "../.gitignore" ]; then
        if grep -q "verification/sim/work/" "../.gitignore"; then
            print_success "work目录已在gitignore中"
        else
            print_warning "work目录未在gitignore中，建议添加"
        fi
    fi

    # 6. 检查权限
    print_header "6. 文件权限检查"
    if [ -d "scripts" ]; then
        find scripts -name "*.sh" -not -perm +111 | while read script; do
            print_warning "脚本文件没有执行权限: $script"
        done
    fi

    # 7. 检查测试台文件
    print_header "7. 测试台文件检查"
    if [ -d "testbench/integration_tests/node_basic_routing" ]; then
        check_file "testbench/integration_tests/node_basic_routing/simple_test.sv"
        check_file "testbench/integration_tests/node_basic_routing/test_node_wrapper.sv"
        check_file "testbench/integration_tests/node_basic_routing/node_basic_routing_tb.cpp"
        check_file "testbench/integration_tests/node_basic_routing/packet_generator.h"
        check_file "testbench/integration_tests/node_basic_routing/result_checker.h"
    fi

    # 8. 检查脚本文件
    print_header "8. 脚本文件检查"
    if [ -d "scripts/build" ]; then
        check_file "scripts/build/build_simple_test.sh"
    fi
    if [ -d "scripts/analysis" ]; then
        check_file "scripts/analysis/collect_coverage.sh"
    fi
    if [ -d "scripts/run" ]; then
        check_file "scripts/run/run_all_tests.sh"
    fi

    # =============================================================================
    # 结果汇总
    # =============================================================================
    print_header "检查结果汇总"
    echo -e "总检查项目: ${CHECKS}"
    echo -e "${RED}错误数量: ${ERRORS}${NC}"
    echo -e "${YELLOW}警告数量: ${WARNINGS}${NC}"
    echo -e "${GREEN}通过数量: $((CHECKS - ERRORS - WARNINGS))${NC}"
    echo

    if [ $ERRORS -eq 0 ]; then
        if [ $WARNINGS -eq 0 ]; then
            print_success "🎉 文件结构检查完全通过！"
            echo -e "${GREEN}验证环境结构完全符合规范。${NC}"
            exit 0
        else
            print_warning "⚠️  文件结构基本符合规范，但有${WARNINGS}个警告需要注意。"
            exit 0
        fi
    else
        print_error "❌ 文件结构检查失败，发现${ERRORS}个错误需要修复。"
        echo -e "${RED}请参考 docs/FILE_STRUCTURE_STANDARD.md 修复相关问题。${NC}"
        exit 1
    fi
}

# 显示帮助信息
show_help() {
    echo "MAZE验证环境文件结构检查脚本"
    echo
    echo "用法:"
    echo "  $0                    # 运行完整检查"
    echo "  $0 --help             # 显示此帮助信息"
    echo
    echo "说明:"
    echo "  此脚本检查verification目录是否符合文件结构规范"
    echo "  必须在verification根目录执行"
    echo
    echo "退出代码:"
    echo "  0  检查通过"
    echo "  1  检查失败或执行错误"
}

# 解析命令行参数
case "${1:-}" in
    --help|-h)
        show_help
        exit 0
        ;;
    "")
        main
        ;;
    *)
        echo "未知参数: $1"
        echo "使用 --help 查看帮助信息"
        exit 1
        ;;
esac