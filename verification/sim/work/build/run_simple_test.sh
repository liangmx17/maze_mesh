#!/bin/bash
# =============================================================================
# MAZE节点基本路由功能简化测试运行脚本
# =============================================================================

set -e

# 配置
SIMULATOR="verilator"
TEST_NODE_X=3
TEST_NODE_Y=3
BUILD_DIR="/Users/liangmx17/Documents/maze_mesh/verification/sim/work/build"
WAVE_FILE="/Users/liangmx17/Documents/maze_mesh/verification/sim/wave/fst/simple_test_3_3.fst"

echo "=============================================="
echo "MAZE节点基本路由功能简化测试"
echo "=============================================="
echo "仿真器: $SIMULATOR"
echo "测试节点: ($TEST_NODE_X, $TEST_NODE_Y)"
echo "=============================================="

case $SIMULATOR in
    "verilator")
        echo "使用Verilator运行测试..."
        if [[ -f "$BUILD_DIR/Vsimple_test" ]]; then
            "$BUILD_DIR/Vsimple_test"
        else
            echo "错误: 可执行文件不存在"
            exit 1
        fi
        ;;
    *)
        echo "错误: 不支持的仿真器 '$SIMULATOR'"
        echo "只能使用verilator，而不能使用iverilog或者任意其他仿真软件"
        exit 1
        ;;
esac

echo ""
echo "测试运行完成"
