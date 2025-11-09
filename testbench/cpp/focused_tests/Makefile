# ====================================================================
# MAZE Network Node - Focused Testbenches Makefile
# ====================================================================
#
# Build system for individual focused testbenches
# Supports building and running individual or all tests
#
# Usage:
#   make                    # Build all tests
#   make test_basic        # Build basic functionality test
#   make run_basic         # Run basic functionality test
#   make all               # Build and run all tests
#   make clean             # Clean build artifacts
#   make help              # Show available targets
#
# ====================================================================

# ====================================================================
# Configuration
# ====================================================================

# Project directories
PROJECT_ROOT = ../../..
RTL_DIR = $(PROJECT_ROOT)/rtl
TEST_DIR = .
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj_dir
VCD_DIR = $(PROJECT_ROOT)/sim/wave/vcd
REPORTS_DIR = $(PROJECT_ROOT)/reports/simulation

# Verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = --top-module node --cc --exe -Wall -Wno-fatal
VERILATOR_CFLAGS = -O2
VERILATOR_INCLUDE = -I$(RTL_DIR)/include -I$(TEST_DIR)

# Tools and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -g
LDFLAGS = -lpthread

# RTL sources
RTL_SOURCES = $(RTL_DIR)/src/node/node.v \
              $(RTL_DIR)/include/global_defines/top_define.v \
              $(RTL_DIR)/include/interfaces/interface_a.sv \
              $(RTL_DIR)/include/interfaces/interface_b.sv \
              $(RTL_DIR)/include/interfaces/interface_c.sv \
              $(PROJECT_ROOT)/Provided_Code/irs.v \
              $(PROJECT_ROOT)/Provided_Code/arbiter_with_qos.v

# Test sources
COMMON_SOURCES = packet_utils.h node_simulator.h test_helpers.h
TEST_SOURCES = test_basic.cpp test_qos.cpp test_fault.cpp test_pipeline.cpp test_performance.cpp test_interface.cpp

# Test executables
TEST_EXES = $(BIN_DIR)/test_basic $(BIN_DIR)/test_qos $(BIN_DIR)/test_fault \
            $(BIN_DIR)/test_pipeline $(BIN_DIR)/test_performance $(BIN_DIR)/test_interface

# Default values for optional arguments
DEFAULT_HP = 3
DEFAULT_VP = 2

# ====================================================================
# Main Targets
# ====================================================================

.PHONY: all clean help run_all build_dirs

# Default target - build all tests
all: build_dirs $(TEST_EXES)

# Individual test targets
$(BIN_DIR)/test_basic: $(RTL_SOURCES) $(COMMON_SOURCES) test_basic.cpp | build_dirs
	@echo "[BUILD] Building test_basic..."
	@cd $(PROJECT_ROOT) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) \
		-Irtl/include -IProvided_Code \
		rtl/src/node/node.v rtl/include/global_defines/top_define.v \
		rtl/include/interfaces/interface_a.sv rtl/include/interfaces/interface_b.sv \
		rtl/include/interfaces/interface_c.sv Provided_Code/irs.v \
		Provided_Code/arbiter_with_qos.v \
		testbench/cpp/focused_tests/test_basic.cpp -o testbench/cpp/focused_tests/build/obj_dir/test_basic
	@mv $(PROJECT_ROOT)/testbench/cpp/focused_tests/build/obj_dir/test_basic $@

$(BIN_DIR)/test_qos: $(RTL_SOURCES) $(COMMON_SOURCES) test_qos.cpp | build_dirs
	@echo "[BUILD] Building test_qos..."
	@cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) test_qos.cpp -o test_qos
	@mv $(OBJ_DIR)/test_qos $@

$(BIN_DIR)/test_fault: $(RTL_SOURCES) $(COMMON_SOURCES) test_fault.cpp | build_dirs
	@echo "[BUILD] Building test_fault..."
	@cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) test_fault.cpp -o test_fault
	@mv $(OBJ_DIR)/test_fault $@

$(BIN_DIR)/test_pipeline: $(RTL_SOURCES) $(COMMON_SOURCES) test_pipeline.cpp | build_dirs
	@echo "[BUILD] Building test_pipeline..."
	@cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) test_pipeline.cpp -o test_pipeline
	@mv $(OBJ_DIR)/test_pipeline $@

$(BIN_DIR)/test_performance: $(RTL_SOURCES) $(COMMON_SOURCES) test_performance.cpp | build_dirs
	@echo "[BUILD] Building test_performance..."
	@cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) test_performance.cpp -o test_performance
	@mv $(OBJ_DIR)/test_performance $@

$(BIN_DIR)/test_interface: $(RTL_SOURCES) $(COMMON_SOURCES) test_interface.cpp | build_dirs
	@echo "[BUILD] Building test_interface..."
	@cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) test_interface.cpp -o test_interface
	@mv $(OBJ_DIR)/test_interface $@

# Create build directories
build_dirs:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR) $(OBJ_DIR) $(VCD_DIR) $(REPORTS_DIR)

# ====================================================================
# Test Execution Targets
# ====================================================================

.PHONY: run_basic run_qos run_fault run_pipeline run_performance run_interface run_all

# Run individual tests
run_basic: $(BIN_DIR)/test_basic
	@echo "[RUN] Basic functionality test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_basic --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

run_qos: $(BIN_DIR)/test_qos
	@echo "[RUN] QoS arbitration test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_qos --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

run_fault: $(BIN_DIR)/test_fault
	@echo "[RUN] Fault tolerance test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_fault --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

run_pipeline: $(BIN_DIR)/test_pipeline
	@echo "[RUN] Pipeline timing test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_pipeline --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

run_performance: $(BIN_DIR)/test_performance
	@echo "[RUN] Performance test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_performance --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

run_interface: $(BIN_DIR)/test_interface
	@echo "[RUN] Interface test..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_interface --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG)

# Run all tests
run_all: $(TEST_EXES)
	@echo "[RUN] Running all focused tests..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@echo "=== Starting Basic Functionality Test ===" && \
	$(BIN_DIR)/test_basic --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== Basic Functionality Test Completed ===" && \
	echo "" && \
	echo "=== Starting QoS Arbitration Test ===" && \
	$(BIN_DIR)/test_qos --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== QoS Arbitration Test Completed ===" && \
	echo "" && \
	echo "=== Starting Fault Tolerance Test ===" && \
	$(BIN_DIR)/test_fault --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== Fault Tolerance Test Completed ===" && \
	echo "" && \
	echo "=== Starting Pipeline Timing Test ===" && \
	$(BIN_DIR)/test_pipeline --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== Pipeline Timing Test Completed ===" && \
	echo "" && \
	echo "=== Starting Performance Test ===" && \
	$(BIN_DIR)/test_performance --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== Performance Test Completed ===" && \
	echo "" && \
	echo "=== Starting Interface Test ===" && \
	$(BIN_DIR)/test_interface --hp $(HP) --vp $(VP) $(VCD_FLAG) $(VERBOSE_FLAG) && \
	echo "=== Interface Test Completed ===" && \
	echo "" && \
	echo "=== All Tests Completed ==="

# Quick test run (no VCD, minimal verbosity)
run_quick: $(TEST_EXES)
	@echo "[RUN] Quick test run (no VCD)..."
	@mkdir -p $(REPORTS_DIR)
	@$(BIN_DIR)/test_basic --hp $(HP) --vp $(VP) --verbose 0
	@$(BIN_DIR)/test_qos --hp $(HP) --vp $(VP) --verbose 0
	@$(BIN_DIR)/test_fault --hp $(HP) --vp $(VP) --verbose 0
	@$(BIN_DIR)/test_pipeline --hp $(HP) --vp $(VP) --verbose 0
	@$(BIN_DIR)/test_performance --hp $(HP) --vp $(VP) --verbose 0
	@$(BIN_DIR)/test_interface --hp $(HP) --vp $(VP) --verbose 0

# Debug test run (with VCD and verbose output)
run_debug: $(TEST_EXES)
	@echo "[RUN] Debug test run (with VCD and verbose)..."
	@mkdir -p $(VCD_DIR) $(REPORTS_DIR)
	@$(BIN_DIR)/test_basic --hp $(HP) --vp $(VP) --vcd --verbose
	@$(BIN_DIR)/test_qos --hp $(HP) --vp $(VP) --vcd --verbose

# ====================================================================
# Utility Targets
# ====================================================================

# Show help
help:
	@echo "MAZE Network Node - Focused Testbenches Build System"
	@echo "==================================================="
	@echo ""
	@echo "Build Targets:"
	@echo "  all                Build all test executables"
	@echo "  test_basic         Build basic functionality test"
	@echo "  test_qos           Build QoS arbitration test"
	@echo "  test_fault         Build fault tolerance test"
	@echo "  test_pipeline      Build pipeline timing test"
	@echo "  test_performance   Build performance test"
	@echo "  test_interface     Build interface test"
	@echo ""
	@echo "Run Targets:"
	@echo "  run_basic          Run basic functionality test"
	@echo "  run_qos            Run QoS arbitration test"
	@echo "  run_fault          Run fault tolerance test"
	@echo "  run_pipeline       Run pipeline timing test"
	@echo "  run_performance    Run performance test"
	@echo "  run_interface      Run interface test"
	@echo "  run_all            Run all tests"
	@echo "  run_quick          Run all tests quickly (no VCD, minimal output)"
	@echo "  run_debug          Run tests with VCD and verbose output"
	@echo ""
	@echo "Utility Targets:"
	@echo "  clean              Remove build artifacts"
	@echo "  help               Show this help message"
	@echo "  status             Show build status"
	@echo "  install            Install executables to project bin"
	@echo ""
	@echo "Variables:"
	@echo "  HP                 Node horizontal position (default: $(DEFAULT_HP))"
	@echo "  VP                 Node vertical position (default: $(DEFAULT_VP))"
	@echo "  VCD_FLAG           Pass --vcd to tests (default: empty)"
	@echo "  VERBOSE_FLAG       Pass --verbose to tests (default: empty)"
	@echo ""
	@echo "Examples:"
	@echo "  make run_basic                        # Run basic test with defaults"
	@echo "  make run_basic HP=5 VP=2               # Run test for node (5,2)"
	@echo "  make run_debug VCD_FLAG=--vcd          # Run with VCD generation"
	@echo "  make run_quick VERBOSE_FLAG=--verbose # Run with verbose output"

# Show build status
status:
	@echo "Build Status:"
	@echo "============"
	@echo "Project Root: $(PROJECT_ROOT)"
	@echo "Build Directory: $(BUILD_DIR)"
	@echo "Binary Directory: $(BIN_DIR)"
	@echo "VCD Directory: $(VCD_DIR)"
	@echo ""
	@echo "Test Executables:"
	@for exe in $(TEST_EXES); do \
		if [ -f $$exe ]; then \
			echo "  ✓ $$exe"; \
		else \
			echo "  ✗ $$exe (missing)"; \
		fi; \
	done
	@echo ""
	@echo "Dependencies:"
	@echo "  Verilator: $$(which $(VERILATOR) || echo 'NOT FOUND')"
	@echo "  C++ Compiler: $$(which $(CXX) || echo 'NOT FOUND')"

# Install executables
install: $(TEST_EXES)
	@echo "[INSTALL] Installing test executables..."
	@mkdir -p $(PROJECT_ROOT)/bin
	@cp $(TEST_EXES) $(PROJECT_ROOT)/bin/
	@echo "[INSTALL] Installation completed"

# Clean build artifacts
clean:
	@echo "[CLEAN] Removing build artifacts..."
	@rm -rf $(BUILD_DIR)
	@rm -f *.o *.a
	@rm -f *.vcd
	@rm -f *_test_results.txt
	@echo "[CLEAN] Clean completed"

# Clean including VCD files
clean_all: clean
	@echo "[CLEAN] Removing VCD files..."
	@rm -rf $(VCD_DIR)/*.vcd
	@echo "[CLEAN] All clean completed"

# ====================================================================
# Development Targets
# ====================================================================

# Build with debug flags
debug: CXXFLAGS += -O0 -g3 -DDEBUG -fsanitize=address
debug: VERILATOR_CFLAGS += -O0 -g3 -DDEBUG
debug: clean all

# Build with coverage support
coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean all
	@echo "[COVERAGE] Built with coverage support"

# Static analysis
analyze:
	@echo "[ANALYZE] Running static analysis..."
	@which cppcheck > /dev/null && \
		cppcheck --enable=all --std=c++11 $(TEST_SOURCES) || \
		echo "cppcheck not available"

# Code formatting
format:
	@echo "[FORMAT] Formatting code..."
	@which clang-format > /dev/null && \
		clang-format -i $(TEST_SOURCES) $(COMMON_SOURCES) || \
		echo "clang-format not available"

# ====================================================================
# Advanced Targets
# ====================================================================

# Generate test report
report: run_all
	@echo "[REPORT] Generating test report..."
	@mkdir -p $(REPORTS_DIR)
	@echo "# MAZE Network Node Focused Tests Report" > $(REPORTS_DIR)/focused_test_report.md
	@echo "Generated: $$(date)" >> $(REPORTS_DIR)/focused_test_report.md
	@echo "" >> $(REPORTS_DIR)/focused_test_report.md
	@echo "## Test Results Summary" >> $(REPORTS_DIR)/focused_test_report.md
	@for result in *_test_results.txt; do \
		if [ -f $$result ]; then \
			echo "### $$result" >> $(REPORTS_DIR)/focused_test_report.md; \
			echo '```' >> $(REPORTS_DIR)/focused_test_report.md; \
			cat $$result >> $(REPORTS_DIR)/focused_test_report.md; \
			echo '```' >> $(REPORTS_DIR)/focused_test_report.md; \
			echo "" >> $(REPORTS_DIR)/focused_test_report.md; \
		fi; \
	done
	@echo "[REPORT] Test report generated: $(REPORTS_DIR)/focused_test_report.md"

# Continuous integration target
ci: clean all run_quick
	@echo "[CI] Continuous integration build and test completed"

# Performance benchmark
benchmark: $(BIN_DIR)/test_performance
	@echo "[BENCHMARK] Running performance benchmark..."
	@mkdir -p $(REPORTS_DIR)
	@$(BIN_DIR)/test_performance --hp $(HP) --vp $(VP) --packets 5000 --verbose

# ====================================================================
# Variable Defaults
# ====================================================================

HP ?= $(DEFAULT_HP)
VP ?= $(DEFAULT_VP)
VCD_FLAG ?=
VERBOSE_FLAG ?=

# ====================================================================
# Phony Targets
# ====================================================================

.PHONY: all clean help run_all build_dirs status install clean_all debug coverage analyze format report ci benchmark
.PHONY: run_basic run_qos run_fault run_pipeline run_performance run_interface run_quick run_debug