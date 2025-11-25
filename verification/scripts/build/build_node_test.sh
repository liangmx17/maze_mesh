#!/bin/bash
# =============================================================================
# MAZE节点验证环境构建脚本
# =============================================================================
# 用途：构建完整的node测试验证环境
# 限制：只能使用verilator，而不能使用iverilog或者任意其他仿真软件

set -e  # 遇到错误立即退出

# 配置参数 - 支持环境变量
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 支持环境变量，如果未设置则自动推导
# 脚本位置: verification/scripts/build/
PROJECT_ROOT="${PROJECT_ROOT:-$(cd "$SCRIPT_DIR/../../../" && pwd)}"
VERIFICATION_DIR="${VERIFICATION_DIR:-$(cd "$SCRIPT_DIR/../.." && pwd)}"
RTL_DIR="${RTL_DIR:-$PROJECT_ROOT/rtl}"

NODE_TEST_DIR="$VERIFICATION_DIR/testbench/node_testbench"
BUILD_DIR="$VERIFICATION_DIR/sim/work/node_test"
WAVE_DIR="$VERIFICATION_DIR/sim/wave/node_test"

# 默认参数
SIMULATOR=${1:-"verilator"}  # 只能使用verilator
TEST_MODE=${2:-"all"}         # 测试模式：all, basic, qos, fault, multicast, stress
ENABLE_TRACE=${3:-0}         # 是否启用波形：0=否，1=是
VERBOSE=${4:-0}              # 详细输出：0=否，1=是

# 创建必要目录
mkdir -p "$BUILD_DIR"
mkdir -p "$WAVE_DIR"

echo "=============================================="
echo "MAZE节点验证环境构建脚本"
echo "=============================================="
echo "仿真器: $SIMULATOR"
echo "测试模式: $TEST_MODE"
echo "波形生成: $ENABLE_TRACE"
echo "详细输出: $VERBOSE"
echo "项目根目录: $PROJECT_ROOT"
echo "验证目录: $VERIFICATION_DIR"
echo "RTL目录: $RTL_DIR"
echo "测试环境目录: $NODE_TEST_DIR"
echo "构建目录: $BUILD_DIR"
echo "=============================================="
echo ""

# 检查仿真器依赖
check_simulator() {
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
        "$NODE_TEST_DIR/node_test_environment.sv"
        "$NODE_TEST_DIR/packet_injector.sv"
        "$NODE_TEST_DIR/packet_monitor.sv"
        "$NODE_TEST_DIR/config_manager.sv"
        "$NODE_TEST_DIR/test_sequences.sv"
        "$NODE_TEST_DIR/test_runner.cpp"
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

# 构建测试环境
build_test_environment() {
    echo "构建node测试环境..."

    cd "$BUILD_DIR"

    # 准备Verilator参数
    local verilator_args=(
        --top-module node_test_environment
        --cc
        -Wno-fatal
        -I"$PROJECT_ROOT"
        -I"$RTL_DIR"
        -I"$RTL_DIR/USER_DEFINE"
        -I"$NODE_TEST_DIR"
    )

    # 添加源文件
    verilator_args+=(
        "$RTL_DIR/top_define.v"
        "$RTL_DIR/interface_a.sv"
        "$RTL_DIR/interface_b.sv"
        "$RTL_DIR/irs.v"
        "$RTL_DIR/USER_DEFINE/param.v"
        "$RTL_DIR/USER_DEFINE/interface_port_c.sv"
        "$RTL_DIR/USER_DEFINE/node.v"
        "$NODE_TEST_DIR/packet_injector.sv"
        "$NODE_TEST_DIR/packet_monitor.sv"
        "$NODE_TEST_DIR/config_manager.sv"
        "$NODE_TEST_DIR/test_sequences.sv"
        "$NODE_TEST_DIR/node_test_environment.sv"
        "$NODE_TEST_DIR/test_runner.cpp"
    )

    # 波形追踪选项
    if [[ $ENABLE_TRACE -eq 1 ]]; then
        echo "启用波形追踪..."
        verilator_args+=(--trace --trace-fst)
    fi

    # C++编译选项
    verilator_args+=(
        -CFLAGS "-std=c++14 -O2"
        --Mdir .
        --exe
    )

    echo "执行Verilator编译..."
    if [[ $VERBOSE -eq 1 ]]; then
        echo "Verilator命令: verilator ${verilator_args[*]}"
    fi

    verilator "${verilator_args[@]}"

    # 编译C++代码
    echo "编译C++代码..."
    if command -v nproc &> /dev/null; then
        NPROC=$(nproc)
    else
        NPROC=$(sysctl -n hw.ncpu)
    fi

    make -f Vnode_test_environment.mk -j$NPROC

    echo "✓ node测试环境构建成功"
}

# 生成运行脚本
generate_run_script() {
    local run_script_path="$BUILD_DIR/run_node_test.sh"

    echo "生成运行脚本: $run_script_path"

    cat > "$run_script_path" << EOF
#!/bin/bash
# =============================================================================
# MAZE节点验证环境运行脚本
# =============================================================================

set -e

# 配置
SIMULATOR="$SIMULATOR"
TEST_MODE="$TEST_MODE"
ENABLE_TRACE=$ENABLE_TRACE
VERBOSE=$VERBOSE
BUILD_DIR="$BUILD_DIR"
WAVE_DIR="$WAVE_DIR"

echo "=============================================="
echo "MAZE节点验证环境"
echo "=============================================="
echo "仿真器: \$SIMULATOR"
echo "测试模式: \$TEST_MODE"
echo "波形生成: \$ENABLE_TRACE"
echo "详细输出: \$VERBOSE"
echo "=============================================="

# 准备测试参数
TEST_ARGS="--test \$TEST_MODE"
if [[ \$ENABLE_TRACE -eq 1 ]]; then
    WAVE_FILE="\$WAVE_DIR/node_test_\$TEST_MODE.fst"
    TEST_ARGS="\$TEST_ARGS --trace --wave \$WAVE_FILE"
    echo "波形文件: \$WAVE_FILE"
fi

if [[ \$VERBOSE -eq 1 ]]; then
    TEST_ARGS="\$TEST_ARGS --verbose"
fi

echo "测试参数: \$TEST_ARGS"
echo ""

case \$SIMULATOR in
    "verilator")
        echo "使用Verilator运行测试..."
        if [[ -f "\$BUILD_DIR/Vnode_test_environment" ]]; then
            "\$BUILD_DIR/Vnode_test_environment" \$TEST_ARGS
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

# 生成快速测试脚本
generate_quick_scripts() {
    local quick_script_dir="$VERIFICATION_DIR/scripts/quick_test"
    mkdir -p "$quick_script_dir"

    # 生成快速测试脚本
    cat > "$quick_script_dir/run_basic_test.sh" << EOF
#!/bin/bash
# 快速基本功能测试
cd "\$(dirname "\$0")/../.."
./scripts/build/build_node_test.sh verilator basic 0 0
EOF

    cat > "$quick_script_dir/run_full_test.sh" << EOF
#!/bin/bash
# 完整测试套件（包含波形）
cd "\$(dirname "\$0")/../.."
./scripts/build/build_node_test.sh verilator all 1 0
EOF

    cat > "$quick_script_dir/run_qos_test.sh" << EOF
#!/bin/bash
# QoS测试
cd "\$(dirname "\$0")/../.."
./scripts/build/build_node_test.sh verilator qos 0 0
EOF

    chmod +x "$quick_script_dir"/*.sh
    echo "✓ 快速测试脚本生成完成: $quick_script_dir"
}

# 显示构建信息
show_build_info() {
    echo ""
    echo "=============================================="
    echo "构建完成"
    echo "=============================================="
    echo "仿真器: $SIMULATOR"
    echo "测试模式: $TEST_MODE"
    echo "波形生成: $ENABLE_TRACE"
    echo "构建目录: $BUILD_DIR"
    echo "运行脚本: $BUILD_DIR/run_node_test.sh"
    echo ""

    # 显示可执行文件信息
    local exe="$BUILD_DIR/Vnode_test_environment"
    if [[ -f "$exe" ]]; then
        echo "可执行文件: $exe"
        echo "文件大小: $(du -h "$exe" | cut -f1)"
    fi

    echo ""
    echo "使用方法:"
    echo "  # 运行测试"
    echo "  cd $BUILD_DIR"
    echo "  ./run_node_test.sh"
    echo ""
    echo "  # 或直接运行"
    echo "  $exe --test $TEST_MODE"
    echo ""

    if [[ $ENABLE_TRACE -eq 1 ]]; then
        echo "  # 查看波形文件"
        echo "  gtkwave $WAVE_DIR/node_test_$TEST_MODE.fst"
        echo ""
    fi

    echo "  # 使用make命令"
    echo "  cd $VERIFICATION_DIR"
    echo "  make node-test TEST=$TEST_MODE TRACE=$ENABLE_TRACE"
    echo ""
}

# 主函数
main() {
    # 执行构建步骤
    check_simulator
    check_source_files

    # 清理旧文件
    echo "清理旧构建文件..."
    rm -f "$BUILD_DIR"/Vnode_test_environment*
    rm -f "$BUILD_DIR"/*.mk
    echo "✓ 清理完成"

    build_test_environment
    generate_run_script
    generate_quick_scripts
    show_build_info

    echo "构建成功完成！"
}

# 显示帮助信息
show_help() {
    echo "用法: $0 [仿真器] [测试模式] [波形生成] [详细输出]"
    echo ""
    echo "支持的仿真器:"
    echo "  verilator   Verilator C++编译器（唯一支持）"
    echo ""
    echo "测试模式:"
    echo "  all         完整测试套件（默认）"
    echo "  basic       基本路由功能测试"
    echo "  qos         QoS仲裁测试"
    echo "  fault       故障容错测试"
    echo "  multicast   多播广播测试"
    echo "  stress      压力测试"
    echo ""
    echo "波形生成:"
    echo "  0           不生成波形（默认）"
    echo "  1           生成FST格式波形文件"
    echo ""
    echo "详细输出:"
    echo "  0           简洁输出（默认）"
    echo "  1           详细输出"
    echo ""
    echo "示例:"
    echo "  $0                                    # 使用默认参数"
    echo "  $0 verilator basic 1 0                # 基本测试并生成波形"
    echo "  $0 verilator all 1 1                  # 完整测试，波形，详细输出"
    echo ""
    echo "注意：只能使用verilator，而不能使用iverilog或者任意其他仿真软件"
}

# 处理命令行参数
if [[ "$1" == "--help" || "$1" == "-h" ]]; then
    show_help
    exit 0
fi

# 参数验证
if [[ $ENABLE_TRACE -ne 0 && $ENABLE_TRACE -ne 1 ]]; then
    echo "错误: 波形生成参数必须是0或1"
    exit 1
fi

if [[ $VERBOSE -ne 0 && $VERBOSE -ne 1 ]]; then
    echo "错误: 详细输出参数必须是0或1"
    exit 1
fi

# 运行主函数
main "$@"