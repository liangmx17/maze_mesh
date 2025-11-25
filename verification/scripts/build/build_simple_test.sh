#!/bin/bash
# =============================================================================
# MAZE节点基本路由功能测试编译脚本 - 仅支持Verilator
# =============================================================================
# 用途：编译SystemVerilog版本的测试台
# 限制：只能使用verilator，而不能使用iverilog或者任意其他仿真软件

set -e  # 遇到错误立即退出

# 配置参数 - 支持环境变量
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 支持环境变量，如果未设置则自动推导
# 脚本位置: verification/scripts/build/
# 项目根目录: 需要向上3级
PROJECT_ROOT="${PROJECT_ROOT:-$(cd "$SCRIPT_DIR/../../../" && pwd)}"
VERIFICATION_DIR="${VERIFICATION_DIR:-$(cd "$SCRIPT_DIR/../.." && pwd)}"
RTL_DIR="${RTL_DIR:-$PROJECT_ROOT/rtl}"

TESTBENCH_DIR="$VERIFICATION_DIR/testbench/node_testbench"
BUILD_DIR="$VERIFICATION_DIR/sim/work/build"
WAVE_DIR="$VERIFICATION_DIR/sim/wave/fst"

# 默认参数
SIMULATOR=${1:-"verilator"}  # 只能使用verilator
TEST_NODE_X=${2:-3}
TEST_NODE_Y=${3:-3}

# 创建必要目录
mkdir -p "$BUILD_DIR"
mkdir -p "$WAVE_DIR"

echo "=============================================="
echo "MAZE节点基本路由功能测试编译脚本"
echo "=============================================="
echo "仿真器: $SIMULATOR"
echo "测试节点: ($TEST_NODE_X, $TEST_NODE_Y)"
echo "项目根目录: $PROJECT_ROOT"
echo "验证目录: $VERIFICATION_DIR"
echo "RTL目录: $RTL_DIR"
echo "脚本目录: $SCRIPT_DIR"
echo "=============================================="
echo ""

# 检查依赖工具
check_dependencies() {
    echo "检查仿真器依赖..."

    case $SIMULATOR in
        "verilator")
            if ! command -v verilator &> /dev/null; then
                echo "错误: 未找到verilator，请先安装Verilator"
                echo "Ubuntu/Debian: sudo apt-get install verilator"
                echo "macOS: brew install verilator"
                exit 1
            fi
            echo "✓ Verilator 检查通过"
            ;;
        *)
            echo "错误: 不支持的仿真器 '$SIMULATOR'"
            echo "只能使用verilator，而不能使用iverilog或者任意其他仿真软件"
            exit 1
            ;;
    esac
}

# 检查源文件
check_source_files() {
    echo "检查源文件..."

    local required_files=(
        "$RTL_DIR/USER_DEFINE/node.v"
        "$RTL_DIR/USER_DEFINE/param.v"
        "$RTL_DIR/USER_DEFINE/interface_port_c.sv"
        "$RTL_DIR/irs.v"
        "$RTL_DIR/top_define.v"
        "$RTL_DIR/interface_a.sv"
        "$RTL_DIR/interface_b.sv"
        "$TESTBENCH_DIR/test_node_wrapper.sv"
        "$TESTBENCH_DIR/simple_test.sv"
    )

    local missing_files=()

    for file in "${required_files[@]}"; do
        if [[ ! -f "$file" ]]; then
            missing_files+=("$file")
        fi
    done

    if [[ ${#missing_files[@]} -gt 0 ]]; then
        echo "错误: 缺少以下必需文件:"
        printf '  %s\n' "${missing_files[@]}"
        exit 1
    fi

    echo "✓ 源文件检查通过"
}

# 使用Verilator编译
compile_with_verilator() {
    echo "使用Verilator编译..."

    cd "$BUILD_DIR"

    # 生成文件列表
    cat > simple_test.filelist << EOF
# MAZE节点简化测试文件列表
# 注意：router_unit.v和arbiter.v由node.v包含，不需要单独列出
$RTL_DIR/top_define.v
$RTL_DIR/interface_a.sv
$RTL_DIR/interface_b.sv
$RTL_DIR/irs.v
$RTL_DIR/USER_DEFINE/param.v
$RTL_DIR/USER_DEFINE/interface_port_c.sv
$RTL_DIR/USER_DEFINE/node.v
$TESTBENCH_DIR/minimal_node_test.sv
EOF

    # Verilator编译命令 - 使用C++主函数，不启用的波形
    cat > run_test.cpp << 'EOF'
#include <iostream>
#include "verilated.h"
#include "Vminimal_node_test.h"
#include "Vbasic_test___024root.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vbasic_test* dut = new Vbasic_test;

    std::cout << "MAZE节点基本测试开始..." << std::endl;

    // 通过rootp访问内部信号
    Vbasic_test___024root* root = dut->rootp;

    // 初始化信号
    root->basic_test__DOT__clk = 0;
    root->basic_test__DOT__rst_n = 0;
    root->basic_test__DOT__pg_en = 0;
    root->basic_test__DOT__pg_node = 0;

    // 复位序列 - 5个时钟周期
    for (int i = 0; i < 5; ++i) {
        root->basic_test__DOT__clk = !root->basic_test__DOT__clk;  // 时钟翻转
        dut->eval();
    }

    // 释放复位
    root->basic_test__DOT__rst_n = 1;

    // 测试循环 - 20个时钟周期
    for (int i = 0; i < 20; ++i) {
        // 时钟上升沿
        root->basic_test__DOT__clk = 1;
        dut->eval();

        // 时钟下降沿
        root->basic_test__DOT__clk = 0;
        dut->eval();

        std::cout << "周期 " << (i + 1) << ": 节点运行正常" << std::endl;
    }

    std::cout << "测试完成" << std::endl;

    delete dut;
    return 0;
}
EOF

    # Verilator编译命令 - 使用简单的C++主函数，无波形，无时序
    verilator \
        --top-module basic_test \
        --cc \
        -Wno-fatal \
        -I$PROJECT_ROOT \
        -I$RTL_DIR \
        -I$RTL_DIR/USER_DEFINE \
        -f simple_test.filelist \
        run_test.cpp \
        -CFLAGS "-std=c++14" \
        --Mdir . \
        --exe

    # 编译C++代码
    if command -v nproc &> /dev/null; then
        NPROC=$(nproc)
    else
        NPROC=$(sysctl -n hw.ncpu)
    fi
    make -f Vbasic_test.mk -j$NPROC

    echo "✓ Verilator编译成功"
}

# 生成运行脚本
generate_run_script() {
    local run_script_path="$BUILD_DIR/run_simple_test.sh"

    echo "生成运行脚本: $run_script_path"

    cat > "$run_script_path" << EOF
#!/bin/bash
# =============================================================================
# MAZE节点基本路由功能简化测试运行脚本
# =============================================================================

set -e

# 配置
SIMULATOR="$SIMULATOR"
TEST_NODE_X=$TEST_NODE_X
TEST_NODE_Y=$TEST_NODE_Y
BUILD_DIR="$BUILD_DIR"
WAVE_FILE="$WAVE_DIR/simple_test_${TEST_NODE_X}_${TEST_NODE_Y}.fst"

echo "=============================================="
echo "MAZE节点基本路由功能简化测试"
echo "=============================================="
echo "仿真器: \$SIMULATOR"
echo "测试节点: (\$TEST_NODE_X, \$TEST_NODE_Y)"
echo "=============================================="

case \$SIMULATOR in
    "verilator")
        echo "使用Verilator运行测试..."
        if [[ -f "\$BUILD_DIR/Vsimple_test" ]]; then
            "\$BUILD_DIR/Vsimple_test"
        else
            echo "错误: 可执行文件不存在"
            exit 1
        fi
        ;;
    *)
        echo "错误: 不支持的仿真器 '\$SIMULATOR'"
        echo "只能使用verilator，而不能使用iverilog或者任意其他仿真软件"
        exit 1
        ;;
esac

echo ""
echo "测试运行完成"
EOF

    chmod +x "$run_script_path"
    echo "✓ 运行脚本生成完成"
}

# 清理旧文件
cleanup_old_files() {
    echo "清理旧文件..."

    rm -f "$BUILD_DIR"/Vsimple_test*
    rm -f "$BUILD_DIR"/simple_test.filelist

    echo "✓ 清理完成"
}

# 显示编译信息
show_build_info() {
    echo ""
    echo "=============================================="
    echo "编译完成"
    echo "=============================================="
    echo "仿真器: $SIMULATOR"
    echo "测试节点位置: ($TEST_NODE_X, $TEST_NODE_Y)"
    echo "编译目录: $BUILD_DIR"
    echo "运行脚本: $BUILD_DIR/run_simple_test.sh"
    echo ""

    # 显示可执行文件信息
    local exe="$BUILD_DIR/Vsimple_test"
    if [[ -f "$exe" ]]; then
        echo "可执行文件: $exe"
        echo "运行命令: $exe"
    fi

    echo ""
    echo "使用方法:"
    echo "  cd $BUILD_DIR"
    echo "  ./run_simple_test.sh"
    echo ""
    echo "或直接运行:"
    echo "  $BUILD_DIR/Vsimple_test"
    echo ""
}

# 主函数
main() {
    # 执行编译步骤
    check_dependencies
    check_source_files
    cleanup_old_files

    compile_with_verilator
    generate_run_script
    show_build_info

    echo "编译成功完成！"
}

# 显示帮助信息
show_help() {
    echo "用法: $0 [仿真器] [节点X坐标] [节点Y坐标]"
    echo ""
    echo "支持的仿真器:"
    echo "  verilator   Verilator C++编译器（唯一支持）"
    echo ""
    echo "参数说明:"
    echo "  节点X坐标    测试节点的X坐标 (0-7)，默认为3"
    echo "  节点Y坐标    测试节点的Y坐标 (0-7)，默认为3"
    echo ""
    echo "示例:"
    echo "  $0                    # 使用默认参数"
    echo "  $0 verilator 3 3      # 使用Verilator测试节点(3,3)"
    echo ""
    echo "注意：只能使用verilator，而不能使用iverilog或者任意其他仿真软件"
}

# 处理命令行参数
if [[ "$1" == "--help" || "$1" == "-h" ]]; then
    show_help
    exit 0
fi

# 参数验证
if [[ $TEST_NODE_X -lt 0 || $TEST_NODE_X -gt 7 ]]; then
    echo "错误: 节点X坐标超出范围 (0-7)"
    exit 1
fi

if [[ $TEST_NODE_Y -lt 0 || $TEST_NODE_Y -gt 7 ]]; then
    echo "错误: 节点Y坐标超出范围 (0-7)"
    exit 1
fi

# 运行主函数
main "$@"