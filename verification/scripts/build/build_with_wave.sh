#!/bin/bash
# =============================================================================
# MAZE节点测试编译脚本 - 支持VCD波形追踪
# =============================================================================
# 用途：编译SystemVerilog版本的测试台，支持VCD波形文件生成
# 限制：只能使用verilator，而不能使用iverilog或者任意其他仿真软件

set -e  # 遇到错误立即退出

# 配置参数
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="${PROJECT_ROOT:-$(cd "$SCRIPT_DIR/../../../" && pwd)}"
VERIFICATION_DIR="${VERIFICATION_DIR:-$(cd "$SCRIPT_DIR/../.." && pwd)}"
RTL_DIR="${RTL_DIR:-$PROJECT_ROOT/rtl}"

TESTBENCH_DIR="$VERIFICATION_DIR/testbench/node_testbench"
BUILD_DIR="$VERIFICATION_DIR/sim/work/node_test_with_wave"
WAVE_DIR="$VERIFICATION_DIR/sim/wave/vcd"

# 创建必要目录
mkdir -p "$BUILD_DIR"
mkdir -p "$WAVE_DIR"

echo "=============================================="
echo "MAZE节点测试编译脚本（支持VCD波形）"
echo "=============================================="
echo "项目根目录: $PROJECT_ROOT"
echo "验证目录: $VERIFICATION_DIR"
echo "RTL目录: $RTL_DIR"
echo "构建目录: $BUILD_DIR"
echo "波形目录: $WAVE_DIR"
echo "=============================================="
echo ""

# 检查依赖工具
check_dependencies() {
    echo "检查仿真器依赖..."
    if ! command -v verilator &> /dev/null; then
        echo "错误: 未找到verilator，请先安装Verilator"
        echo "Ubuntu/Debian: sudo apt-get install verilator"
        echo "macOS: brew install verilator"
        echo "Windows: 参考 https://verilator.org/guide/latest/install.html"
        exit 1
    fi
    echo "✓ Verilator: $(verilator -version | head -1 || echo '版本未知')"
}

# Verilator编译命令 - 支持VCD波形追踪
compile_with_verilator() {
    echo "=============================================="
    echo "使用Verilator编译（启用VCD波形追踪）"
    echo "=============================================="

    cd "$BUILD_DIR"

    # 删除旧的构建文件
    rm -f Vminimal_node_test*

    # Verilator编译命令 - 启用VCD波形
    verilator \
        --top-module minimal_node_test \
        --cc \
        --trace \
        -Wno-fatal \
        --timing \
        --autoflush \
        -I$PROJECT_ROOT \
        -I$RTL_DIR \
        -I$RTL_DIR/USER_DEFINE \
        -I$VERIFICATION_DIR/testbench/node_testbench \
        $RTL_DIR/top_define.v \
        $RTL_DIR/interface_a.sv \
        $RTL_DIR/interface_b.sv \
        $RTL_DIR/irs.v \
        $RTL_DIR/USER_DEFINE/param.v \
        $RTL_DIR/USER_DEFINE/interface_port_c.sv \
        $RTL_DIR/USER_DEFINE/node.v \
        $VERIFICATION_DIR/testbench/node_testbench/minimal_node_test.sv \
        $VERIFICATION_DIR/testbench/node_testbench/minimal_main.cpp \
        -CFLAGS "-std=c++14 -O2" \
        --Mdir . \
        --exe

    # 编译C++代码
    if command -v nproc &> /dev/null; then
        NPROC=$(nproc)
    else
        NPROC=$(sysctl -n hw.ncpu)
    fi

    echo "使用 $NPROC 个CPU核心进行编译..."
    make -f Vminimal_node_test.mk -j$NPROC

    echo "✓ Verilator编译完成（支持VCD波形）"
}

# 运行测试
run_test() {
    echo "=============================================="
    echo "运行测试（生成VCD波形文件）"
    echo "=============================================="

    cd "$BUILD_DIR"

    echo "VCD波形文件: $WAVE_DIR/node_test.vcd"
    echo "开始运行测试..."

    # 运行测试
    ./Vminimal_node_test

    if [ $? -eq 0 ]; then
        echo "✓ 测试完成"
        echo "VCD波形文件: $WAVE_DIR/node_test.vcd"
        echo ""
        echo "查看波形文件:"
        echo "  gtkwave $WAVE_DIR/node_test.vcd"
        echo ""
        echo "在线查看:"
        echo "  上传 .vcd 文件到 https://surfer-project.org/"
    else
        echo "✗ 测试失败"
        exit 1
    fi
}

# 主函数
main() {
    echo "MAZE节点测试编译（支持VCD波形）"

    # 检查依赖
    check_dependencies

    # 编译
    compile_with_verilator

    # 运行测试
    run_test
}

# 执行主函数
main "$@"