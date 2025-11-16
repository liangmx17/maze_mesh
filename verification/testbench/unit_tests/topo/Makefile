# =============================================================================
# MAZE网络拓扑模块测试Makefile
# =============================================================================
# 支持所有topo模块测试的编译和运行
# =============================================================================

# 基本设置
VERILATOR = verilator
VERILATOR_FLAGS = --cc --trace --trace-fst --trace-structs -Wno-fatal
VERILATOR_CFLAGS = -std=c++11 -O2 -Wall -Wextra

# 目录设置
ROOT_DIR = ../../../../..
RTL_DIR = $(ROOT_DIR)/rtl
SRC_DIR = $(ROOT_DIR)/verification/sim/build
WAVE_DIR = $(ROOT_DIR)/verification/sim/wave
REPORT_DIR = $(ROOT_DIR)/verification/reports/simulation

# 源文件定义
RTL_SOURCES = \
	$(RTL_DIR)/include/global_defines/top_define.v \
	$(RTL_DIR)/include/interfaces/interface_a.sv \
	$(RTL_DIR)/include/interfaces/interface_b.sv \
	$(RTL_DIR)/include/interfaces/interface_c.sv \
	$(RTL_DIR)/lib/irs/irs.v \
	$(RTL_DIR)/src/node_components/router_unit.v \
	$(RTL_DIR)/src/node_components/arbiter.v \
	$(RTL_DIR)/src/node/node.v \
	$(RTL_DIR)/src/topo/topo.v

# 测试目标
TESTS = \
	test_topo_small_grid \
	test_topo_medium_grid \
	test_topo_end_to_end \
	test_topo_integrity

# 默认目标
.PHONY: all clean test help
all: $(TESTS)

# 帮助信息
help:
	@echo "MAZE拓扑模块测试Makefile"
	@echo "====================="
	@echo ""
	@echo "可用目标:"
	@echo "  all              - 编译所有测试"
	@echo "  clean            - 清理编译文件"
	@echo "  test             - 运行所有测试"
	@echo "  test_<name>      - 运行指定测试"
	@echo "  compile_<name>   - 编译指定测试"
	@echo "  wave_<name>      - 运行指定测试并生成波形"
	@echo "  report_<name>    - 生成指定测试的报告"
	@echo "  reports          - 生成所有测试报告"
	@echo ""
	@echo "可用测试:"
	@echo "  test_topo_small_grid   - 2×2小型网格测试"
	@echo "  test_topo_medium_grid  - 4×4中等网格测试"
	@echo "  test_topo_end_to_end   - 端到端传输测试"
	@echo "  test_topo_integrity    - 拓扑连接完整性测试"
	@echo ""
	@echo "示例:"
	@echo "  make compile_test_topo_small_grid"
	@echo "  make test_topo_small_grid"
	@echo "  make wave_test_topo_small_grid"

# 目录创建
$(SRC_DIR):
	mkdir -p $(SRC_DIR)

$(WAVE_DIR):
	mkdir -p $(WAVE_DIR)/vcd
	mkdir -p $(WAVE_DIR)/fst

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

# 编译规则 - 2×2小型网格测试
compile_test_topo_small_grid: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译2×2小型网格测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module TOPO \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/topo/test_topo_small_grid.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f VTOPO.mk
	@echo "2×2小型网格测试编译完成"

# 编译规则 - 4×4中等网格测试
compile_test_topo_medium_grid: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译4×4中等网格测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module TOPO \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/topo/test_topo_medium_grid.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f VTOPO.mk
	@echo "4×4中等网格测试编译完成"

# 编译规则 - 端到端传输测试
compile_test_topo_end_to_end: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译端到端传输测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module TOPO \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/topo/test_topo_end_to_end.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f VTOPO.mk
	@echo "端到端传输测试编译完成"

# 编译规则 - 拓扑连接完整性测试
compile_test_topo_integrity: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译拓扑连接完整性测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module TOPO \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/topo/test_topo_integrity.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f VTOPO.mk
	@echo "拓扑连接完整性测试编译完成"

# 构建别名
test_topo_small_grid: compile_test_topo_small_grid

test_topo_medium_grid: compile_test_topo_medium_grid

test_topo_end_to_end: compile_test_topo_end_to_end

test_topo_integrity: compile_test_topo_integrity

# 运行测试规则
run_test_topo_small_grid: $(REPORT_DIR)
	@echo "运行2×2小型网格测试..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@if [ -f "$(WAVE_DIR)/fst/test_topo_small_grid.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_topo_small_grid.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "2×2小型网格测试完成"

run_test_topo_medium_grid: $(REPORT_DIR)
	@echo "运行4×4中等网格测试..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@if [ -f "$(WAVE_DIR)/fst/test_topo_medium_grid.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_topo_medium_grid.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "4×4中等网格测试完成"

run_test_topo_end_to_end: $(REPORT_DIR)
	@echo "运行端到端传输测试..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@if [ -f "$(WAVE_DIR)/fst/test_topo_end_to_end.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_topo_end_to_end.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "端到端传输测试完成"

run_test_topo_integrity: $(REPORT_DIR)
	@echo "运行拓扑连接完整性测试..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@if [ -f "$(WAVE_DIR)/fst/test_topo_integrity.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_topo_integrity.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "拓扑连接完整性测试完成"

# 带波形生成的测试运行
wave_test_topo_small_grid: compile_test_topo_small_grid
	@echo "运行2×2小型网格测试(生成波形)..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_topo_small_grid.fst"

wave_test_topo_medium_grid: compile_test_topo_medium_grid
	@echo "运行4×4中等网格测试(生成波形)..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_topo_medium_grid.fst"

wave_test_topo_end_to_end: compile_test_topo_end_to_end
	@echo "运行端到端传输测试(生成波形)..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_topo_end_to_end.fst"

wave_test_topo_integrity: compile_test_topo_integrity
	@echo "运行拓扑连接完整性测试(生成波形)..."
	cd $(SRC_DIR) && ./VTOPO +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_topo_integrity.fst"

# 快速测试(无波形)
quick_test_topo_small_grid: compile_test_topo_small_grid
	@echo "运行2×2小型网格测试(快速模式)..."
	cd $(SRC_DIR) && ./VTOPO

quick_test_topo_medium_grid: compile_test_topo_medium_grid
	@echo "运行4×4中等网格测试(快速模式)..."
	cd $(SRC_DIR) && ./VTOPO

quick_test_topo_end_to_end: compile_test_topo_end_to_end
	@echo "运行端到端传输测试(快速模式)..."
	cd $(SRC_DIR) && ./VTOPO

quick_test_topo_integrity: compile_test_topo_integrity
	@echo "运行拓扑连接完整性测试(快速模式)..."
	cd $(SRC_DIR) && ./VTOPO

# 运行所有测试
test: $(REPORT_DIR)
	@echo "运行所有拓扑模块测试..."
	@echo "======================================"
	@make run_test_topo_small_grid
	@echo "======================================"
	@make run_test_topo_end_to_end
	@echo "======================================"
	@make run_test_topo_integrity
	@echo "======================================"
	@echo "所有拓扑模块测试完成"

# 快速测试所有(无波形)
quick_test: $(REPORT_DIR)
	@echo "快速运行所有拓扑模块测试..."
	@echo "======================================"
	@make quick_test_topo_small_grid
	@echo "======================================"
	@make quick_test_topo_end_to_end
	@echo "======================================"
	@make quick_test_topo_integrity
	@echo "======================================"
	@echo "所有拓扑模块快速测试完成"

# 检查语法
syntax_check:
	@echo "检查RTL语法..."
	$(VERILATOR) --lint-only -Wall $(RTL_SOURCES)
	@echo "语法检查完成"

# 清理规则
clean:
	@echo "清理编译文件..."
	rm -rf $(SRC_DIR)
	rm -f *.d *.o *.log
	@echo "清理完成"

# 深度清理
distclean: clean
	@echo "深度清理..."
	rm -rf $(WAVE_DIR)
	rm -rf $(REPORT_DIR)
	rm -f reports/*.txt
	@echo "深度清理完成"

# 显示状态
status:
	@echo "MAZE拓扑模块测试状态"
	@echo "===================="
	@echo "RTL源文件数: $(words $(RTL_SOURCES))"
	@echo "测试目标数: $(words $(TESTS))"
	@echo "构建目录: $(SRC_DIR)"
	@echo "波形目录: $(WAVE_DIR)"
	@echo "报告目录: $(REPORT_DIR)"
	@if [ -d "$(SRC_DIR)" ]; then \
		echo "构建目录: 存在"; \
		if [ -f "$(SRC_DIR)/VTOPO" ]; then \
			echo "可执行文件: 存在"; \
		else \
			echo "可执行文件: 不存在"; \
		fi \
	else \
		echo "构建目录: 不存在"; \
	fi

# 依赖关系
$(TESTS): % : compile_%

# 伪目标声明
.PHONY: $(TESTS) \
	compile_$(TESTS) \
	run_$(TESTS) \
	wave_$(TESTS) \
	quick_$(TESTS) \
	syntax_check clean distclean status all test quick_test

# 默认构建目标
.DEFAULT_GOAL := all