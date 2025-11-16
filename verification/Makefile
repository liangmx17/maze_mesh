# =============================================================================
# MAZE网络验证环境Makefile
# =============================================================================

.PHONY: help test clean regress coverage waves all test-node-basic test-quick test-edge test-corner

# 默认目标
all: test

# 项目配置 - 支持环境变量
PROJECT_ROOT ?= $(shell cd .. && pwd)
VERIFICATION_DIR := $(shell pwd)
RTL_DIR := $(PROJECT_ROOT)/rtl
SCRIPTS_DIR := $(VERIFICATION_DIR)/scripts
BUILD_DIR := $(VERIFICATION_DIR)/sim/work/build
WAVE_DIR := $(VERIFICATION_DIR)/sim/wave/fst

# 导出环境变量供子进程使用
export PROJECT_ROOT
export VERIFICATION_DIR
export RTL_DIR

# 默认参数
DEFAULT_SIMULATOR := verilator
DEFAULT_NODE_X := 3
DEFAULT_NODE_Y := 3

# 颜色输出
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m # No Color

# 帮助信息
help:
	@echo "=============================================="
	@echo "MAZE网络验证系统"
	@echo "=============================================="
	@echo ""
	@echo "$(BLUE)基本路由功能测试:$(NC)"
	@echo "  make test-node-basic [SIMULATOR=verilator] [NODE_X=3] [NODE_Y=3]"
	@echo "      # 运行基本路由功能测试 (N-RF-001到N-RF-005)"
	@echo ""
	@echo "$(BLUE)预设测试场景:$(NC)"
	@echo "  make test-quick [SIMULATOR=verilator]"
	@echo "      # 快速测试中心节点(3,3)"
	@echo "  make test-edge [SIMULATOR=verilator]"
	@echo "      # 测试所有边缘节点"
	@echo "  make test-corner [SIMULATOR=verilator]"
	@echo "      # 测试四角节点"
	@echo "  make test-all [SIMULATOR=verilator]"
	@echo "      # 测试所有典型节点位置"
	@echo ""
	@echo "$(BLUE)传统验证命令:$(NC)"
	@echo "  make test          - 运行基本测试"
	@echo "  make regress       - 运行回归测试"
	@echo "  make coverage      - 运行带覆盖率的测试"
	@echo "  make waves         - 生成波形文件"
	@echo "  make clean         - 清理临时文件"
	@echo "  make unit          - 运行单元测试"
	@echo "  make integration   - 运行集成测试"
	@echo "  make system        - 运行系统测试"

# 基本测试
test:
	@echo "运行基本测试..."
	cd testbench/unit_tests/router_unit && make test
	cd testbench/unit_tests/arbiter && make test
	@echo "基本测试完成"

# 单元测试
unit:
	@echo "运行所有单元测试..."
	cd testbench/unit_tests && make all
	@echo "单元测试完成"

# 集成测试
integration:
	@echo "运行集成测试..."
	cd testbench/integration_tests && make all
	@echo "集成测试完成"

# 系统测试
system:
	@echo "运行系统测试..."
	cd testbench/system_tests && make all
	@echo "系统测试完成"

# 回归测试
regress:
	@echo "开始回归测试..."
	cd scripts/run_regression && ./run_all_tests.sh
	@echo "回归测试完成，报告位于 reports/regression/"

# 覆盖率测试
coverage:
	@echo "运行带覆盖率的测试..."
	cd scripts/run_simulation && ./run_with_coverage.sh -all
	@echo "覆盖率报告位于 reports/coverage/"

# 波形生成
waves:
	@echo "生成波形文件..."
	cd scripts/generate_waveforms && ./convert_vcd_to_fst.sh
	@echo "波形文件位于 sim/wave/"

# 清理
clean:
	@echo "清理临时文件..."
	rm -rf sim/build/*
	rm -rf sim/run/temp/*
	rm -f logs/detailed/*
	rm -f logs/simulation/*
	@echo "清理完成"

# 深度清理（包括编译产物）
distclean: clean
	@echo "深度清理..."
	rm -rf sim/build/obj_dir/*
	rm -f reports/coverage/*
	rm -f reports/performance/*
	@echo "深度清理完成"

# 检查环境
check-env:
	@echo "检查验证环境..."
	@which verilator > /dev/null || (echo "错误：未找到verilator" && exit 1)
	@echo "环境检查通过"

# 生成文档（如果有Doxygen）
docs:
	@echo "生成验证文档..."
	@if [ -d docs ]; then cd docs && make; else echo "文档目录不存在"; fi

# 基本路由功能测试
test-node-basic:
	@echo "$(BLUE)[INFO]$(NC) 开始基本路由功能测试..."
	@echo "  仿真器: $(SIMULATOR)"
	@echo "  节点位置: ($(NODE_X), $(NODE_Y))"
	@echo ""
	@mkdir -p $(BUILD_DIR) $(WAVE_DIR)
	@if [ "$(SIMULATOR)" = "verilator" ]; then \
		echo "$(YELLOW)[INFO]$(NC) 使用Verilator编译和运行测试..."; \
		$(SCRIPTS_DIR)/build/build_simple_test.sh verilator $(NODE_X) $(NODE_Y) && \
		cd $(BUILD_DIR) && ./Vsimple_test; \
	elif [ "$(SIMULATOR)" = "modelsim" ] || [ "$(SIMULATOR)" = "questasim" ]; then \
		echo "$(YELLOW)[INFO]$(NC) 使用ModelSim编译和运行测试..."; \
		$(SCRIPTS_DIR)/build/build_simple_test.sh modelsim $(NODE_X) $(NODE_Y) && \
		cd $(BUILD_DIR) && ./Vsimple_test; \
	elif [ "$(SIMULATOR)" = "vcs" ]; then \
		echo "$(YELLOW)[INFO]$(NC) 使用VCS编译和运行测试..."; \
		$(SCRIPTS_DIR)/build/build_simple_test.sh vcs $(NODE_X) $(NODE_Y) && \
		cd $(BUILD_DIR) && ./Vsimple_test; \
	else \
		echo "$(YELLOW)[INFO]$(NC) 使用Verilator编译和运行测试..."; \
		$(SCRIPTS_DIR)/build/build_simple_test.sh verilator $(NODE_X) $(NODE_Y) && \
		cd $(BUILD_DIR) && ./Vsimple_test; \
	fi
	@echo ""
	@echo "$(GREEN)[PASS]$(NC) 基本路由功能测试完成"

# 快速测试（中心节点）
test-quick:
	@echo "$(BLUE)[INFO]$(NC) 运行快速测试..."
	$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=3 NODE_Y=3

# 边缘节点测试
test-edge:
	@echo "$(BLUE)[INFO]$(NC) 运行边缘节点测试..."
	@echo "  测试4个边缘节点: (3,0), (3,7), (0,3), (7,3)"
	@echo ""
	@mkdir -p $(BUILD_DIR) $(WAVE_DIR)
	@echo "$(YELLOW)[INFO]$(NC) 测试南边缘节点(3,0)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=3 NODE_Y=0
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试北边缘节点(3,7)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=3 NODE_Y=7
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试西边缘节点(0,3)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=0 NODE_Y=3
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试东边缘节点(7,3)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=7 NODE_Y=3
	@echo ""
	@echo "$(GREEN)[PASS]$(NC) 边缘节点测试完成"

# 四角节点测试
test-corner:
	@echo "$(BLUE)[INFO]$(NC) 运行四角节点测试..."
	@echo "  测试4个角落节点: (0,0), (0,7), (7,0), (7,7)"
	@echo ""
	@mkdir -p $(BUILD_DIR) $(WAVE_DIR)
	@echo "$(YELLOW)[INFO]$(NC) 测试左下角节点(0,0)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=0 NODE_Y=0
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试左上角节点(0,7)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=0 NODE_Y=7
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试右下角节点(7,0)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=7 NODE_Y=0
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 测试右上角节点(7,7)..."
	@$(MAKE) test-node-basic SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR)) NODE_X=7 NODE_Y=7
	@echo ""
	@echo "$(GREEN)[PASS]$(NC) 四角节点测试完成"

# 完整测试套件
test-all:
	@echo "$(BLUE)[INFO]$(NC) 运行完整测试套件..."
	@echo "  测试9个典型节点位置"
	@echo ""
	@mkdir -p $(BUILD_DIR) $(WAVE_DIR)
	@echo "$(YELLOW)[INFO]$(NC) 1. 中心节点测试"
	@$(MAKE) test-quick SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR))
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 2. 边缘节点测试"
	@$(MAKE) test-edge SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR))
	@echo ""
	@echo "$(YELLOW)[INFO]$(NC) 3. 四角节点测试"
	@$(MAKE) test-corner SIMULATOR=$(or $(SIMULATOR),$(DEFAULT_SIMULATOR))
	@echo ""
	@echo "$(GREEN)[PASS]$(NC) 完整测试套件执行完成"
	@echo ""
	@echo "$(BLUE)[INFO]$(NC) 测试统计:"
	@echo "  总测试节点数: 9个"
	@echo "  每节点测试数: 5个基本路由测试"
	@echo "  总测试用例数: 45个"
	@echo ""
	@echo "$(BLUE)[INFO]$(NC) 查看详细结果:"
	@echo "  测试日志: $(BUILD_DIR)/"
	@echo "  波形文件: $(WAVE_DIR)/"
	@echo "  运行指南: $(VERIFICATION_DIR)/docs/node_basic_routing_guide.md"

# 显示目录结构
show-tree:
	@echo "验证环境目录结构："
	tree . -L 3

# 检查依赖
check-deps:
	@echo "$(BLUE)[INFO]$(NC) 检查依赖工具..."
		@if command -v verilator >/dev/null 2>&1; then \
		echo "  ✓ Verilator: $(shell verilator --version)"; \
	else \
		echo "  ✗ Verilator: 未安装"; \
	fi
		@if command -v gtkwave >/dev/null 2>&1; then \
		echo "  ✓ GTKWave: $(shell gtkwave --version 2>/dev/null | head -1 || echo '版本未知')"; \
	else \
		echo "  ✗ GTKWave: 未安装 (可选，用于波形查看)"; \
	fi

# 项目信息
info:
	@echo "=============================================="
	@echo "MAZE网络验证系统信息"
	@echo "=============================================="
	@echo "项目根目录: $(PROJECT_ROOT)"
	@echo "验证目录: $(VERIFICATION_DIR)"
	@echo "构建目录: $(BUILD_DIR)"
	@echo "波形目录: $(WAVE_DIR)"
	@echo "脚本目录: $(SCRIPTS_DIR)"
	@echo ""
	@echo "默认配置:"
	@echo "  默认仿真器: $(DEFAULT_SIMULATOR)"
	@echo "  默认测试节点: ($(DEFAULT_NODE_X), $(DEFAULT_NODE_Y))"
	@echo ""
	@echo "关键文件:"
	@echo "  测试指南: $(VERIFICATION_DIR)/docs/node_basic_routing_guide.md"
	@echo "  测试点文档: $(VERIFICATION_DIR)/docs/test_point_decomposition.md"
	@echo "  项目说明: $(PROJECT_ROOT)/CLAUDE.md"
	@echo ""

# 安装依赖 (Ubuntu/Debian)
install-deps-ubuntu:
	@echo "$(BLUE)[INFO]$(NC) 安装Ubuntu/Debian依赖..."
	sudo apt-get update
	sudo apt-get install -y verilator gtkwave
	@echo "$(GREEN)[PASS]$(NC) 依赖安装完成"

# 安装依赖 (macOS)
install-deps-macos:
	@echo "$(BLUE)[INFO]$(NC) 安装macOS依赖..."
	brew install verilator gtkwave
	@echo "$(GREEN)[PASS]$(NC) 依赖安装完成"