#!/bin/bash
# =============================================================================
# MAZE节点调试测试运行脚本
# =============================================================================

set -e

# 配置
TEST_NODE_X=3
TEST_NODE_Y=3
BUILD_DIR="/home/liangmx/maze_mesh/verification/sim/work/build"
WAVE_FILE="/home/liangmx/maze_mesh/verification/sim/wave/fst/debug_node_3_3.fst"

echo "=============================================="
echo "MAZE节点调试测试"
echo "=============================================="
echo "测试节点: ($TEST_NODE_X, $TEST_NODE_Y)"
echo "波形文件: $WAVE_FILE"
echo "=============================================="

if [[ -f "$BUILD_DIR/Vdebug_simple_test" ]]; then
    echo "使用SystemVerilog调试测试台运行调试..."
    "$BUILD_DIR/Vdebug_simple_test"

    echo ""
    echo "调试完成！"
    echo "波形文件已生成: debug_node_irs_n.vcd"
    echo "使用 gtkwave debug_node_irs_n.vcd 查看内部信号"
else
    echo "错误: 可执行文件不存在"
    exit 1
fi
