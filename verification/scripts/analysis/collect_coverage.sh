#!/bin/bash

# =============================================================================
# MAZE网络芯片测试覆盖率收集脚本
# =============================================================================
# 功能：收集和合并Verilator生成的覆盖率数据
# 使用方法：./collect_coverage.sh [测试模块名]
# =============================================================================

# 设置基本参数
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"
VERIFICATION_DIR="$ROOT_DIR"
SIM_BUILD_DIR="$VERIFICATION_DIR/sim/build"
COVERAGE_DIR="$VERIFICATION_DIR/reports/coverage"
WAVE_DIR="$VERIFICATION_DIR/sim/wave"

# 检查参数
if [ $# -eq 0 ]; then
    echo "用法: $0 <测试模块名>"
    echo "支持的测试模块: node, topo, all"
    echo "示例: $0 node"
    echo "示例: $0 all"
    exit 1
fi

MODULE_NAME="$1"

# 创建覆盖率目录
mkdir -p "$COVERAGE_DIR"

# 函数：收集单个模块的覆盖率
collect_module_coverage() {
    local module=$1
    local module_dir="$SIM_BUILD_DIR"

    echo "=========================================="
    echo "收集 $module 模块覆盖率数据..."
    echo "=========================================="

    if [ ! -d "$module_dir" ]; then
        echo "错误: 构建目录不存在: $module_dir"
        echo "请先运行相应的测试编译"
        return 1
    fi

    # 查找覆盖率数据文件
    cd "$module_dir"

    # Verilator覆盖率文件通常以 .dat 或 .info 结尾
    coverage_files=$(find . -name "*.dat" -o -name "*.info" -o -name "coverage*.txt" 2>/dev/null)

    if [ -z "$coverage_files" ]; then
        echo "警告: 未找到 $module 模块的覆盖率数据文件"
        echo "请确保使用 --coverage 参数编译测试"
        return 1
    fi

    echo "找到覆盖率文件:"
    echo "$coverage_files"

    # 生成覆盖率报告
    local coverage_report="$COVERAGE_DIR/${module}_coverage_report.txt"

    {
        echo "MAZE $module 模块覆盖率报告"
        echo "生成时间: $(date)"
        echo "=========================================="
        echo ""

        # 如果有gcov工具，生成详细的覆盖率报告
        if command -v gcov &> /dev/null; then
            echo "使用gcov生成详细覆盖率报告..."
            gcov *.cpp 2>/dev/null | head -20

            echo ""
            echo "覆盖率统计:"

            # 统计行覆盖率
            line_cov=$(gcov *.cpp 2>/dev/null | grep -o '[0-9.]*%' | head -1)
            if [ ! -z "$line_cov" ]; then
                echo "代码行覆盖率: $line_cov"
            fi

        else
            echo "gcov工具不可用，显示原始覆盖率数据..."
            for file in $coverage_files; do
                echo "=== $file ==="
                head -20 "$file"
                echo ""
            done
        fi

        echo ""
        echo "原始覆盖率文件:"
        for file in $coverage_files; do
            echo "  - $file"
        done

    } > "$coverage_report"

    echo "覆盖率报告已生成: $coverage_report"

    # 复制覆盖率数据文件到覆盖率目录
    for file in $coverage_files; do
        cp "$file" "$COVERAGE_DIR/${module}_$(basename $file)"
    done

    return 0
}

# 函数：生成HTML覆盖率报告
generate_html_report() {
    local module=$1

    echo "生成HTML覆盖率报告..."

    # 检查是否有lcov工具
    if command -v lcov &> /dev/null; then
        local lcov_file="$COVERAGE_DIR/${module}_coverage.info"
        local html_dir="$COVERAGE_DIR/${module}_html"

        # 收集gcov数据并转换为lcov格式
        if [ -f "$lcov_file" ]; then
            mkdir -p "$html_dir"
            genhtml "$lcov_file" -o "$html_dir" 2>/dev/null

            if [ -d "$html_dir" ]; then
                echo "HTML覆盖率报告已生成: $html_dir/index.html"
            fi
        fi
    else
        echo "lcov工具不可用，跳过HTML报告生成"
    fi
}

# 函数：清理覆盖率数据
clean_coverage() {
    local module=$1

    echo "清理 $module 模块的临时覆盖率文件..."

    cd "$SIM_BUILD_DIR"

    # 清理gcov生成的文件
    rm -f *.gcov *.gcda *.gcno

    echo "清理完成"
}

# 主执行逻辑
case "$MODULE_NAME" in
    "node")
        collect_module_coverage "node"
        generate_html_report "node"
        ;;
    "topo")
        collect_module_coverage "topo"
        generate_html_report "topo"
        ;;
    "all")
        echo "收集所有模块的覆盖率数据..."

        # 收集node模块覆盖率
        if collect_module_coverage "node"; then
            generate_html_report "node"
        fi

        # 收集topo模块覆盖率
        if collect_module_coverage "topo"; then
            generate_html_report "topo"
        fi

        echo "所有模块覆盖率收集完成"
        ;;
    *)
        echo "错误: 不支持的模块名 '$MODULE_NAME'"
        echo "支持的模块: node, topo, all"
        exit 1
        ;;
esac

# 生成汇总报告
echo ""
echo "=========================================="
echo "覆盖率收集汇总"
echo "=========================================="
echo "覆盖率目录: $COVERAGE_DIR"
echo "生成的报告文件:"

if [ -d "$COVERAGE_DIR" ]; then
    ls -la "$COVERAGE_DIR" | grep -E "\.(txt|html|info|dat)$" | awk '{print "  " $9 " (" $5 " bytes)"}'
fi

echo ""
echo "使用方法查看报告:"
echo "  文本报告: cat $COVERAGE_DIR/*_coverage_report.txt"
echo "  HTML报告: 浏览器打开 $COVERAGE_DIR/*_html/index.html"

echo ""
echo "覆盖率收集完成！"