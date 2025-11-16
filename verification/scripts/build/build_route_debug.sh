#!/bin/bash
# =============================================================================
# MAZE路由算法调试编译脚本
# =============================================================================
# 用途：专门调试路由算法问题的构建脚本

set -e

# 配置参数
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="${PROJECT_ROOT:-$(cd "$SCRIPT_DIR/../../" && pwd)}"
VERIFICATION_DIR="${VERIFICATION_DIR:-$(cd "$SCRIPT_DIR/../" && pwd)}"
RTL_DIR="${RTL_DIR:-$PROJECT_ROOT/rtl}"

TESTBENCH_DIR="$VERIFICATION_DIR/testbench/integration_tests/node_basic_routing"
BUILD_DIR="$VERIFICATION_DIR/sim/work/build"
WAVE_DIR="$VERIFICATION_DIR/sim/wave/fst"

# 默认参数
SIMULATOR=${1:-"verilator"}
TEST_NODE_X=${2:-3}
TEST_NODE_Y=${3:-3}

# 创建必要目录
mkdir -p "$BUILD_DIR"
mkdir -p "$WAVE_DIR"

echo "=============================================="
echo "MAZE路由算法调试编译脚本"
echo "=============================================="
echo "仿真器: $SIMULATOR"
echo "测试节点: ($TEST_NODE_X, $TEST_NODE_Y)"
echo "=============================================="
echo ""

# 检查依赖
if ! command -v verilator &> /dev/null; then
    echo "错误: 未找到verilator"
    exit 1
fi

# 创建专门的路由调试文件列表
cat > "$BUILD_DIR/route_debug.filelist" << EOF
# MAZE路由调试文件列表
$RTL_DIR/include/global_defines/top_define.v
$RTL_DIR/include/interfaces/interface_a.sv
$RTL_DIR/include/interfaces/interface_b.sv
$RTL_DIR/include/interfaces/interface_c.sv
$RTL_DIR/lib/irs/irs.v
$RTL_DIR/src/node/node.v
$TESTBENCH_DIR/test_node_wrapper.sv
$TESTBENCH_DIR/debug_simple_test.sv
EOF

cd "$BUILD_DIR"

# 编译路由调试版本
echo "编译路由调试版本..."
verilator \
    --top-module debug_simple_test \
    --cc \
    -Wno-fatal \
    -I$PROJECT_ROOT \
    -I$RTL_DIR/include \
    -I$RTL_DIR/src/node_components \
    -I$RTL_DIR/lib \
    -f route_debug.filelist \
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

echo "✓ 路由调试版本编译完成"
echo ""
echo "运行命令:"
echo "  cd $BUILD_DIR"
echo "  ./Vdebug_simple_test"
echo ""
echo "当前问题: 数据包路由方向错误"
echo "- 输入: 节点(3,3) -> 目标(4,3) (应该向东)"
echo "- 实际: 输出到了West端口 (错误方向)"
echo "- 数据包内容被清零"