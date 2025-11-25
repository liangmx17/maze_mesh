#!/bin/bash
# =============================================================================
# MAZE节点基本路由功能测试编译脚本
# =============================================================================
# 用途：编译Verilator测试台和MAZE节点模块
# 使用方法：./build_test.sh [节点X坐标] [节点Y坐标] [编译选项]

set -e  # 遇到错误立即退出

# 配置参数
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
VERIFICATION_DIR="$PROJECT_ROOT/verification"
TESTBENCH_DIR="$VERIFICATION_DIR/testbench/node_basic_routing"
BUILD_DIR="$VERIFICATION_DIR/sim/build"
RUN_DIR="$VERIFICATION_DIR/sim/run/temp"
WAVE_DIR="$VERIFICATION_DIR/sim/wave/fst"

# 默认参数
NODE_X=${1:-3}
NODE_Y=${2:-3}
ENABLE_TRACE=${3:-0}
VERBOSE_OUTPUT=${4:-0}

# 创建必要目录
mkdir -p "$BUILD_DIR"
mkdir -p "$RUN_DIR"
mkdir -p "$WAVE_DIR"

# 检查依赖工具
check_dependencies() {
    echo "检查编译依赖..."

    if ! command -v verilator &> /dev/null; then
        echo "错误: 未找到verilator，请先安装Verilator"
        exit 1
    fi

    if ! command -v make &> /dev/null; then
        echo "错误: 未找到make，请先安装Make"
        exit 1
    fi

    echo "✓ 依赖检查通过"
}

# 检查源文件
check_source_files() {
    echo "检查源文件..."

    local required_files=(
        "$PROJECT_ROOT/rtl/src/node/node.v"
        "$PROJECT_ROOT/rtl/src/node_components/router_unit.v"
        "$PROJECT_ROOT/rtl/src/node_components/arbiter.v"
        "$PROJECT_ROOT/rtl/lib/irs/irs.v"
        "$PROJECT_ROOT/rtl/include/global_defines/top_define.v"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_a.sv"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_b.sv"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_port_c.sv"
        "$TESTBENCH_DIR/test_node_wrapper.sv"
        "$TESTBENCH_DIR/node_basic_routing_tb.cpp"
        "$TESTBENCH_DIR/packet_generator.h"
        "$TESTBENCH_DIR/result_checker.h"
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

# 生成Verilator文件列表
generate_filelist() {
    local filelist_path="$BUILD_DIR/node_test.filelist"

    echo "生成文件列表: $filelist_path"

    cat > "$filelist_path" << EOF
# MAZE节点基本路由功能测试文件列表
# 生成时间: $(date)

# 全局定义文件
$PROJECT_ROOT/rtl/include/global_defines/top_define.v

# 接口定义文件
$PROJECT_ROOT/rtl/include/interfaces/interface_a.sv
$PROJECT_ROOT/rtl/include/interfaces/interface_b.sv
$PROJECT_ROOT/rtl/include/interfaces/interface_port_c.sv

# IRS模块
$PROJECT_ROOT/rtl/lib/irs/irs.v

# 节点组件
$PROJECT_ROOT/rtl/src/node_components/router_unit.v
$PROJECT_ROOT/rtl/src/node_components/arbiter.v

# 节点主模块
$PROJECT_ROOT/rtl/src/node/node.v

# 测试包装器
$TESTBENCH_DIR/test_node_wrapper.sv

EOF

    echo "✓ 文件列表生成完成"
}

# 编译Verilator
compile_verilator() {
    echo "开始Verilator编译..."
    echo "测试节点位置: ($NODE_X, $NODE_Y)"

    cd "$BUILD_DIR"

    local trace_option=""
    if [[ $ENABLE_TRACE -eq 1 ]]; then
        trace_option="--trace --trace-fst --trace-structs"
        echo "启用波形生成"
    fi

    local verbose_option=""
    if [[ $VERBOSE_OUTPUT -eq 1 ]]; then
        verbose_option="--Wno-lint --Wno-style"
        echo "启用详细输出"
    fi

    # Verilator编译命令
    verilator \
        --top-module test_node_wrapper \
        --cc \
        -f node_test.filelist \
        -CFLAGS "-std=c++11 -I$TESTBENCH_DIR" \
        -LDFLAGS "-pthread" \
        --Mdir . \
        --exe \
        $trace_option \
        $verbose_option \
        -GHP=$NODE_X \
        -GVP=$NODE_Y \
        "$TESTBENCH_DIR/node_basic_routing_tb.cpp"

    echo "✓ Verilator编译完成"
}

# 编译C++代码
compile_cpp() {
    echo "编译C++测试台..."

    cd "$BUILD_DIR"

    # 使用make编译
    make -f Vtest_node_wrapper.mk -j$(nproc)

    echo "✓ C++编译完成"

    # 检查可执行文件
    local executable="$BUILD_DIR/Vtest_node_wrapper"
    if [[ -f "$executable" ]]; then
        echo "✓ 可执行文件生成: $executable"

        # 显示文件大小
        local file_size=$(stat -f%z "$executable" 2>/dev/null || stat -c%s "$executable" 2>/dev/null || echo "unknown")
        echo "  文件大小: $file_size 字节"
    else
        echo "错误: 可执行文件未生成"
        exit 1
    fi
}

# 生成运行脚本
generate_run_script() {
    local run_script_path="$RUN_DIR/run_node_test.sh"

    echo "生成运行脚本: $run_script_path"

    cat > "$run_script_path" << EOF
#!/bin/bash
# =============================================================================
# MAZE节点基本路由功能测试运行脚本
# =============================================================================
# 自动生成，请勿手动修改

set -e

# 配置
EXECUTABLE="$BUILD_DIR/Vtest_node_wrapper"
WAVE_FILE="$WAVE_DIR/node_basic_routing_${NODE_X}_${NODE_Y}.fst"
REPORT_FILE="$RUN_DIR/test_report_${NODE_X}_${NODE_Y}.txt"
LOG_FILE="$RUN_DIR/test_log_${NODE_X}_${NODE_Y}.txt"

# 运行参数
NODE_X=$NODE_X
NODE_Y=$NODE_Y
ENABLE_TRACE=$ENABLE_TRACE

# 检查可执行文件
if [[ ! -f "\$EXECUTABLE" ]]; then
    echo "错误: 可执行文件不存在: \$EXECUTABLE"
    echo "请先运行编译脚本"
    exit 1
fi

echo "=============================================="
echo "MAZE节点基本路由功能测试"
echo "=============================================="
echo "测试节点: (\$NODE_X, \$NODE_Y)"
echo "可执行文件: \$EXECUTABLE"
echo "波形文件: \$WAVE_FILE"
echo "报告文件: \$REPORT_FILE"
echo "=============================================="

# 构建命令行参数
ARGS=""
ARGS="\$ARGS --node-x \$NODE_X"
ARGS="\$ARGS --node-y \$NODE_Y"

if [[ \$ENABLE_TRACE -eq 1 ]]; then
    ARGS="\$ARGS --trace"
    echo "波形生成已启用"
fi

# 添加详细输出
ARGS="\$ARGS --verbose"

echo "运行命令: \$EXECUTABLE \$ARGS"
echo ""

# 运行测试
echo "开始测试..."
if \$EXECUTABLE \$ARGS 2>&1 | tee "\$LOG_FILE"; then
    echo ""
    echo "=============================================="
    echo "测试结果: PASS"
    echo "=============================================="
    echo "详细日志: \$LOG_FILE"

    if [[ -f "\$REPORT_FILE" ]]; then
        echo "测试报告: \$REPORT_FILE"
    fi

    if [[ \$ENABLE_TRACE -eq 1 && -f "\$WAVE_FILE" ]]; then
        echo "波形文件: \$WAVE_FILE"
        echo "使用以下命令查看波形:"
        echo "  gtkwave \$WAVE_FILE"
    fi

    exit 0
else
    echo ""
    echo "=============================================="
    echo "测试结果: FAIL"
    echo "=============================================="
    echo "详细日志: \$LOG_FILE"

    if [[ \$ENABLE_TRACE -eq 1 && -f "\$WAVE_FILE" ]]; then
        echo "波形文件: \$WAVE_FILE"
        echo "使用波形文件进行调试"
    fi

    exit 1
fi
EOF

    chmod +x "$run_script_path"
    echo "✓ 运行脚本生成完成"
}

# 清理旧文件
cleanup_old_files() {
    echo "清理旧文件..."

    # 清理旧的编译产物
    rm -f "$BUILD_DIR"/*.o
    rm -f "$BUILD_DIR"/*.d
    rm -f "$BUILD_DIR"/Vtest_node_wrapper*
    rm -f "$BUILD_DIR"/*.mk

    # 清理旧的临时文件
    rm -f "$RUN_DIR"/test_log_*
    rm -f "$RUN_DIR"/test_report_*

    echo "✓ 清理完成"
}

# 显示编译信息
show_build_info() {
    echo ""
    echo "=============================================="
    echo "编译完成"
    echo "=============================================="
    echo "测试节点位置: ($NODE_X, $NODE_Y)"
    echo "编译目录: $BUILD_DIR"
    echo "可执行文件: $BUILD_DIR/Vtest_node_wrapper"
    echo "运行脚本: $RUN_DIR/run_node_test.sh"
    echo ""
    echo "使用方法:"
    echo "  cd $RUN_DIR"
    echo "  ./run_node_test.sh"
    echo ""

    if [[ $ENABLE_TRACE -eq 1 ]]; then
        echo "波形文件将生成到: $WAVE_DIR/"
        echo "查看波形: gtkwave $WAVE_DIR/node_basic_routing_${NODE_X}_${NODE_Y}.fst"
        echo ""
    fi

    echo "其他用法:"
    echo "  直接运行: $BUILD_DIR/Vtest_node_wrapper --node-x $NODE_X --node-y $NODE_Y --verbose"
    echo ""
}

# 主函数
main() {
    echo "=============================================="
    echo "MAZE节点基本路由功能测试编译脚本"
    echo "=============================================="
    echo "编译时间: $(date)"
    echo "项目根目录: $PROJECT_ROOT"
    echo "测试节点位置: ($NODE_X, $NODE_Y)"
    echo "波形生成: $([ $ENABLE_TRACE -eq 1 ] && echo "启用" || echo "禁用")"
    echo "详细输出: $([ $VERBOSE_OUTPUT -eq 1 ] && echo "启用" || echo "禁用")"
    echo "=============================================="
    echo ""

    # 执行编译步骤
    check_dependencies
    check_source_files
    cleanup_old_files
    generate_filelist
    compile_verilator
    compile_cpp
    generate_run_script
    show_build_info

    echo "编译成功完成！"
}

# 显示帮助信息
show_help() {
    echo "用法: $0 [节点X坐标] [节点Y坐标] [启用波形] [详细输出]"
    echo ""
    echo "参数说明:"
    echo "  节点X坐标     测试节点的X坐标 (0-7)，默认为3"
    echo "  节点Y坐标     测试节点的Y坐标 (0-7)，默认为3"
    echo "  启用波形      1=启用波形生成，0=禁用，默认为0"
    echo "  详细输出      1=启用详细编译输出，0=禁用，默认为0"
    echo ""
    echo "示例:"
    echo "  $0 3 3 0 0    # 编译节点(3,3)，无波形，简洁输出"
    echo "  $0 0 0 1 1    # 编译节点(0,0)，启用波形，详细输出"
    echo "  $0            # 使用默认参数编译"
    echo ""
}

# 处理命令行参数
if [[ "$1" == "--help" || "$1" == "-h" ]]; then
    show_help
    exit 0
fi

# 参数验证
if [[ $NODE_X -lt 0 || $NODE_X -gt 7 ]]; then
    echo "错误: 节点X坐标超出范围 (0-7)"
    exit 1
fi

if [[ $NODE_Y -lt 0 || $NODE_Y -gt 7 ]]; then
    echo "错误: 节点Y坐标超出范围 (0-7)"
    exit 1
fi

# 运行主函数
main "$@"