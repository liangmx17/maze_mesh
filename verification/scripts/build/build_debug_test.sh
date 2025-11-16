#!/bin/bash
# =============================================================================
# MAZE节点调试测试编译脚本 - 使用自定义C++测试台
# =============================================================================
# 用途：编译支持内部信号调试的测试台
# 特点：使用自定义C++代码访问和打印内部信号

set -e  # 遇到错误立即退出

# 配置参数 - 支持环境变量
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 支持环境变量，如果未设置则自动推导
PROJECT_ROOT="${PROJECT_ROOT:-$(cd "$SCRIPT_DIR/../../" && pwd)}"
VERIFICATION_DIR="${VERIFICATION_DIR:-$(cd "$SCRIPT_DIR/../../" && pwd)}"
RTL_DIR="${RTL_DIR:-$PROJECT_ROOT/rtl}"

TESTBENCH_DIR="$VERIFICATION_DIR/testbench/integration_tests/node_basic_routing"
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
echo "MAZE节点调试测试编译脚本"
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
        "$RTL_DIR/src/node/node.v"
        "$RTL_DIR/src/node_components/router_unit.v"
        "$RTL_DIR/src/node_components/arbiter.v"
        "$RTL_DIR/lib/irs/irs.v"
        "$RTL_DIR/include/global_defines/top_define.v"
        "$RTL_DIR/include/interfaces/interface_a.sv"
        "$RTL_DIR/include/interfaces/interface_b.sv"
        "$RTL_DIR/include/interfaces/interface_c.sv"
        "$TESTBENCH_DIR/test_node_wrapper.sv"
        "$TESTBENCH_DIR/simple_test.sv"
        "$TESTBENCH_DIR/debug_simple_test.cpp"
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

# 使用Verilator编译调试版本
compile_with_verilator() {
    echo "使用Verilator编译调试版本..."

    cd "$BUILD_DIR"

    # 生成文件列表
    cat > debug_test.filelist << EOF
# MAZE节点调试测试文件列表
$RTL_DIR/include/global_defines/top_define.v
$RTL_DIR/include/interfaces/interface_a.sv
$RTL_DIR/include/interfaces/interface_b.sv
$RTL_DIR/include/interfaces/interface_c.sv
$RTL_DIR/lib/irs/irs.v
$RTL_DIR/src/node/node.v
$TESTBENCH_DIR/test_node_wrapper.sv
$TESTBENCH_DIR/debug_simple_test.sv
EOF

    # Verilator编译命令 - 使用调试测试台
    verilator \
        --top-module debug_simple_test \
        --cc \
        -Wno-fatal \
        -I$PROJECT_ROOT \
        -I$RTL_DIR/include \
        -I$RTL_DIR/src/node_components \
        -I$RTL_DIR/lib \
        -f debug_test.filelist \
        -CFLAGS "-std=c++14 -DVL_DEBUG=1 -g -O0" \
        --Mdir . \
        --exe \
        --trace \
        --trace-structs \
        --trace-params \
        --public-flat-rw \
        --timing \
        -GTEST_NODE_X=$TEST_NODE_X \
        -GTEST_NODE_Y=$TEST_NODE_Y \
        --main

    # 编译C++代码
    make -f Vdebug_simple_test.mk -j$(nproc)

    echo "✓ Verilator调试版本编译成功"
}

# 生成运行脚本
generate_run_script() {
    local run_script_path="$BUILD_DIR/run_debug_test.sh"

    echo "生成调试运行脚本: $run_script_path"

    cat > "$run_script_path" << EOF
#!/bin/bash
# =============================================================================
# MAZE节点调试测试运行脚本
# =============================================================================

set -e

# 配置
TEST_NODE_X=$TEST_NODE_X
TEST_NODE_Y=$TEST_NODE_Y
BUILD_DIR="$BUILD_DIR"
WAVE_FILE="$WAVE_DIR/debug_node_${TEST_NODE_X}_${TEST_NODE_Y}.fst"

echo "=============================================="
echo "MAZE节点调试测试"
echo "=============================================="
echo "测试节点: (\$TEST_NODE_X, \$TEST_NODE_Y)"
echo "波形文件: \$WAVE_FILE"
echo "=============================================="

if [[ -f "\$BUILD_DIR/Vdebug_simple_test" ]]; then
    echo "使用SystemVerilog调试测试台运行调试..."
    "\$BUILD_DIR/Vdebug_simple_test"

    echo ""
    echo "调试完成！"
    echo "波形文件已生成: debug_node_irs_n.vcd"
    echo "使用 gtkwave debug_node_irs_n.vcd 查看内部信号"
else
    echo "错误: 可执行文件不存在"
    exit 1
fi
EOF

    chmod +x "$run_script_path"
    echo "✓ 调试运行脚本生成完成"
}

# 清理旧文件
cleanup_old_files() {
    echo "清理旧文件..."

    rm -f "$BUILD_DIR"/Vsimple_test*
    rm -f "$BUILD_DIR"/*.filelist
    rm -f "$BUILD_DIR"/debug_node_irs_n.vcd

    echo "✓ 清理完成"
}

# 显示编译信息
show_build_info() {
    echo ""
    echo "=============================================="
    echo "调试版本编译完成"
    echo "=============================================="
    echo "仿真器: $SIMULATOR"
    echo "测试节点位置: ($TEST_NODE_X, $TEST_NODE_Y)"
    echo "编译目录: $BUILD_DIR"
    echo "调试运行脚本: $BUILD_DIR/run_debug_test.sh"
    echo "SystemVerilog调试测试台: $TESTBENCH_DIR/debug_simple_test.sv"
    echo ""

    # 显示可执行文件信息
    local exe="$BUILD_DIR/Vdebug_simple_test"
    if [[ -f "$exe" ]]; then
        echo "调试可执行文件: $exe"
        echo "运行命令: $exe"
    fi

    echo ""
    echo "使用方法:"
    echo "  cd $BUILD_DIR"
    echo "  ./run_debug_test.sh"
    echo ""
    echo "或直接运行:"
    echo "  $BUILD_DIR/Vdebug_simple_test"
    echo ""
    echo "调试特性:"
    echo "  ✓ 每个周期打印A端口IRS_N状态"
    echo "  ✓ 生成详细的VCD波形文件"
    echo "  ✓ 启用Verilator调试模式"
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

    echo "调试版本编译成功完成！"
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