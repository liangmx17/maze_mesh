# =============================================================================
# MAZE网络节点模块测试Makefile
# =============================================================================
# 支持所有node模块测试的编译和运行
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
	$(RTL_DIR)/include/interfaces/interface_port_c.sv \
	$(RTL_DIR)/lib/irs/irs.v \
	$(RTL_DIR)/src/node_components/router_unit.v \
	$(RTL_DIR)/src/node_components/arbiter.v \
	$(RTL_DIR)/src/node/node.v

# 测试目标
TESTS = \
	test_node_basic_routing \
	test_node_qos_arbiter \
	test_node_fault_aware \
	test_node_edge_handling \
	test_node_concurrent

# 默认目标
.PHONY: all clean test help
all: $(TESTS)

# 帮助信息
help:
	@echo "MAZE节点模块测试Makefile"
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
	@echo "  test_node_basic_routing   - 基本路由功能测试"
	@echo "  test_node_qos_arbiter     - QoS仲裁功能测试"
	@echo "  test_node_fault_aware     - 故障感知路由测试"
	@echo "  test_node_edge_handling   - 边缘节点处理测试"
	@echo "  test_node_concurrent      - 并发输入处理测试"
	@echo ""
	@echo "示例:"
	@echo "  make compile_test_node_basic_routing"
	@echo "  make test_node_basic_routing"
	@echo "  make wave_test_node_basic_routing"

# 目录创建
$(SRC_DIR):
	mkdir -p $(SRC_DIR)

$(WAVE_DIR):
	mkdir -p $(WAVE_DIR)/vcd
	mkdir -p $(WAVE_DIR)/fst

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

# 编译规则 - 基本路由功能测试
compile_test_node_basic_routing: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译基本路由功能测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_basic_routing.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "基本路由功能测试编译完成"

# 编译规则 - QoS仲裁功能测试
compile_test_node_qos_arbiter: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译QoS仲裁功能测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_qos_arbiter.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "QoS仲裁功能测试编译完成"

# 编译规则 - 故障感知路由测试
compile_test_node_fault_aware: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译故障感知路由测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_fault_aware.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "故障感知路由测试编译完成"

# 编译规则 - 边缘节点处理测试
compile_test_node_edge_handling: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译边缘节点处理测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_edge_handling.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "边缘节点处理测试编译完成"

# 编译规则 - 并发输入处理测试
compile_test_node_concurrent: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译并发输入处理测试..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_concurrent.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS)" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "并发输入处理测试编译完成"

# 构建别名
test_node_basic_routing: compile_test_node_basic_routing

test_node_qos_arbiter: compile_test_node_qos_arbiter

test_node_fault_aware: compile_test_node_fault_aware

test_node_edge_handling: compile_test_node_edge_handling

test_node_concurrent: compile_test_node_concurrent

# 运行测试规则
run_test_node_basic_routing: $(REPORT_DIR)
	@echo "运行基本路由功能测试..."
	cd $(SRC_DIR) && ./Vnode +trace
	@if [ -f "$(WAVE_DIR)/fst/test_node_basic_routing.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_node_basic_routing.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "基本路由功能测试完成"

run_test_node_qos_arbiter: $(REPORT_DIR)
	@echo "运行QoS仲裁功能测试..."
	cd $(SRC_DIR) && ./Vnode +trace
	@if [ -f "$(WAVE_DIR)/fst/test_node_qos_arbiter.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_node_qos_arbiter.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "QoS仲裁功能测试完成"

run_test_node_fault_aware: $(REPORT_DIR)
	@echo "运行故障感知路由测试..."
	cd $(SRC_DIR) && ./Vnode +trace
	@if [ -f "$(WAVE_DIR)/fst/test_node_fault_aware.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_node_fault_aware.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "故障感知路由测试完成"

run_test_node_edge_handling: $(REPORT_DIR)
	@echo "运行边缘节点处理测试..."
	cd $(SRC_DIR) && ./Vnode +trace
	@if [ -f "$(WAVE_DIR)/fst/test_node_edge_handling.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_node_edge_handling.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "边缘节点处理测试完成"

run_test_node_concurrent: $(REPORT_DIR)
	@echo "运行并发输入处理测试..."
	cd $(SRC_DIR) && ./Vnode +trace
	@if [ -f "$(WAVE_DIR)/fst/test_node_concurrent.fst" ]; then \
		mv $(WAVE_DIR)/fst/test_node_concurrent.fst $(WAVE_DIR)/fst/; \
	fi
	@echo "并发输入处理测试完成"

# 带波形生成的测试运行
wave_test_node_basic_routing: compile_test_node_basic_routing
	@echo "运行基本路由功能测试(生成波形)..."
	cd $(SRC_DIR) && ./Vnode +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_node_basic_routing.fst"

wave_test_node_qos_arbiter: compile_test_node_qos_arbiter
	@echo "运行QoS仲裁功能测试(生成波形)..."
	cd $(SRC_DIR) && ./Vnode +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_node_qos_arbiter.fst"

wave_test_node_fault_aware: compile_test_node_fault_aware
	@echo "运行故障感知路由测试(生成波形)..."
	cd $(SRC_DIR) && ./Vnode +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_node_fault_aware.fst"

wave_test_node_edge_handling: compile_test_node_edge_handling
	@echo "运行边缘节点处理测试(生成波形)..."
	cd $(SRC_DIR) && ./Vnode +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_node_edge_handling.fst"

wave_test_node_concurrent: compile_test_node_concurrent
	@echo "运行并发输入处理测试(生成波形)..."
	cd $(SRC_DIR) && ./Vnode +trace
	@echo "波形文件: $(WAVE_DIR)/fst/test_node_concurrent.fst"

# 快速测试(无波形)
quick_test_node_basic_routing: compile_test_node_basic_routing
	@echo "运行基本路由功能测试(快速模式)..."
	cd $(SRC_DIR) && ./Vnode

quick_test_node_qos_arbiter: compile_test_node_qos_arbiter
	@echo "运行QoS仲裁功能测试(快速模式)..."
	cd $(SRC_DIR) && ./Vnode

quick_test_node_fault_aware: compile_test_node_fault_aware
	@echo "运行故障感知路由测试(快速模式)..."
	cd $(SRC_DIR) && ./Vnode

quick_test_node_edge_handling: compile_test_node_edge_handling
	@echo "运行边缘节点处理测试(快速模式)..."
	cd $(SRC_DIR) && ./Vnode

quick_test_node_concurrent: compile_test_node_concurrent
	@echo "运行并发输入处理测试(快速模式)..."
	cd $(SRC_DIR) && ./Vnode

# 运行所有测试
test: $(REPORT_DIR)
	@echo "运行所有节点模块测试..."
	@echo "======================================"
	@make run_test_node_basic_routing
	@echo "======================================"
	@make run_test_node_qos_arbiter
	@echo "======================================"
	@make run_test_node_fault_aware
	@echo "======================================"
	@make run_test_node_edge_handling
	@echo "======================================"
	@make run_test_node_concurrent
	@echo "======================================"
	@echo "所有节点模块测试完成"

# 快速测试所有(无波形)
quick_test: $(REPORT_DIR)
	@echo "快速运行所有节点模块测试..."
	@echo "======================================"
	@make quick_test_node_basic_routing
	@echo "======================================"
	@make quick_test_node_qos_arbiter
	@echo "======================================"
	@make quick_test_node_fault_aware
	@echo "======================================"
	@make quick_test_node_edge_handling
	@echo "======================================"
	@make quick_test_node_concurrent
	@echo "======================================"
	@echo "所有节点模块快速测试完成"

# 调试版本编译
debug_test_node_basic_routing: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译基本路由功能测试(调试版本)..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) --trace-debug \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_basic_routing.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS) -g -DDEBUG" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "基本路由功能测试调试版本编译完成"

# 覆盖率编译
coverage_test_node_basic_routing: $(SRC_DIR) $(WAVE_DIR)
	@echo "编译基本路由功能测试(覆盖率版本)..."
	cd $(SRC_DIR) && \
	$(VERILATOR) $(VERILATOR_FLAGS) --coverage \
		--top-module node \
		--exe \
		$(ROOT_DIR)/verification/testbench/unit_tests/node/test_node_basic_routing.cpp \
		-CFLAGS "$(VERILATOR_CFLAGS) --coverage" \
		$(RTL_SOURCES)
	$(MAKE) -C $(SRC_DIR) -j -f Vnode.mk
	@echo "基本路由功能测试覆盖率版本编译完成"

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
	@echo "MAZE节点模块测试状态"
	@echo "===================="
	@echo "RTL源文件数: $(words $(RTL_SOURCES))"
	@echo "测试目标数: $(words $(TESTS))"
	@echo "构建目录: $(SRC_DIR)"
	@echo "波形目录: $(WAVE_DIR)"
	@echo "报告目录: $(REPORT_DIR)"
	@if [ -d "$(SRC_DIR)" ]; then \
		echo "构建目录: 存在"; \
		if [ -f "$(SRC_DIR)/Vnode" ]; then \
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
	debug_$(TESTS) \
	coverage_$(TESTS) \
	syntax_check clean distclean status all test quick_test

# 默认构建目标
.DEFAULT_GOAL := all