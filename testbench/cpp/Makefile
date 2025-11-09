# ====================================================================
# MAZE Network Node - Verilator Testbench Makefile
# ====================================================================
#
# Build system for comprehensive MAZE node verification
# Supports individual test compilation and full regression testing
#
# Usage:
#   make                    # Build all testbenches
#   make tb_node           # Build main testbench
#   make clean             # Clean build artifacts
#   make run               # Run main testbench
#   make regression        # Run full regression suite
#   make help              # Show available targets
#
# ====================================================================

# ====================================================================
# Configuration
# ====================================================================

# Project directories
PROJECT_ROOT = ../..
RTL_DIR = $(PROJECT_ROOT)/rtl
TB_DIR = .
SRC_DIR = $(TB_DIR)/src
COMMON_DIR = $(TB_DIR)/common
UNIT_TEST_DIR = $(TB_DIR)/unit_tests
INTEGRATION_TEST_DIR = $(TB_DIR)/integration_tests

# Build directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN_DIR = $(BUILD_DIR)/bin
SIM_DIR = $(BUILD_DIR)/sim

# Verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = --top-module node --cc --exe -Wall -Wno-fatal
VERILATOR_CFLAGS = -std=c++11 -O2 -g
VERILATOR_INCLUDE = -I$(RTL_DIR)/include -I$(COMMON_DIR) -I$(SRC_DIR)

# Tools and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -g
LDFLAGS = -lpthread

# File lists
RTL_FILELIST = $(PROJECT_ROOT)/rtl.filelist
RTL_SOURCES = $(shell cat $(RTL_FILELIST) 2>/dev/null || echo "")
RTL_INCLUDES = $(RTL_DIR)/include/global_defines/top_define.v \
               $(RTL_DIR)/include/interfaces/interface_a.sv \
               $(RTL_DIR)/include/interfaces/interface_b.sv \
               $(RTL_DIR)/include/interfaces/interface_c.sv

# Testbench sources
TB_SOURCES = $(SRC_DIR)/tb_node_main.cpp \
             $(COMMON_DIR)/packet_generator.cpp \
             $(COMMON_DIR)/test_utils.cpp

# Object files
RTL_OBJECTS = $(OBJ_DIR)/Vnode__ALL.a
TB_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TB_SOURCES))

# Target executable
MAIN_TARGET = $(BIN_DIR)/tb_node

# VCD output
VCD_DIR = $(PROJECT_ROOT)/sim/wave/vcd
VCD_FILE = $(VCD_DIR)/tb_node.vcd

# ====================================================================
# Main Targets
# ====================================================================

.PHONY: all clean help run regression build_dirs

# Default target
all: build_dirs $(MAIN_TARGET)

# Main testbench target
$(MAIN_TARGET): $(RTL_OBJECTS) $(TB_OBJECTS) | build_dirs
	@echo "[LINK] Building $@"
	$(CXX) $(CXXFLAGS) -o $@ $(RTL_OBJECTS) $(TB_OBJECTS) $(LDFLAGS)

# Verilator compilation of RTL
$(OBJ_DIR)/Vnode__ALL.a: $(RTL_SOURCES) $(RTL_INCLUDES) | build_dirs
	@echo "[VERILATOR] Compiling RTL sources..."
	cd $(OBJ_DIR) && $(VERILATOR) $(VERILATOR_FLAGS) \
		$(VERILATOR_CFLAGS) $(VERILATOR_INCLUDE) \
		$(RTL_SOURCES) \
		--Mdir $(OBJ_DIR) \
		$(TB_SOURCES)
	@echo "[BUILD] Building RTL objects..."
	$(MAKE) -C $(OBJ_DIR) -f Vnode.mk Vnode__ALL.a

# Compile testbench objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | build_dirs
	@echo "[CXX] Compiling $<"
	$(CXX) $(CXXFLAGS) $(VERILATOR_INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(COMMON_DIR)/%.cpp | build_dirs
	@echo "[CXX] Compiling $<"
	$(CXX) $(CXXFLAGS) $(VERILATOR_INCLUDE) -c $< -o $@

# Create build directories
build_dirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(SIM_DIR) $(VCD_DIR)

# ====================================================================
# Test Execution Targets
# ====================================================================

# Run main testbench
run: $(MAIN_TARGET)
	@echo "[RUN] Executing main testbench..."
	@mkdir -p $(VCD_DIR)
	$(MAIN_TARGET) --vcd --output results.txt --verbose 2

# Run with specific node position
run_node: $(MAIN_TARGET)
	@echo "[RUN] Executing testbench for node $(HP),$(VP)"
	$(MAIN_TARGET) --hp $(HP) --vp $(VP) --vcd --verbose 2

# Run regression tests
regression: $(MAIN_TARGET)
	@echo "[REGRESSION] Running comprehensive test suite..."
	@mkdir -p $(PROJECT_ROOT)/reports/simulation
	$(MAIN_TARGET) --verbose 1 --output regression_results.txt

# Run quick test (no VCD, minimal output)
test: $(MAIN_TARGET)
	@echo "[TEST] Running quick test..."
	$(MAIN_TARGET) --verbose 0

# Run debug test (max verbosity)
debug: $(MAIN_TARGET)
	@echo "[DEBUG] Running debug test with VCD..."
	@mkdir -p $(VCD_DIR)
	$(MAIN_TARGET) --vcd --verbose 3

# ====================================================================
# Utility Targets
# ====================================================================

# Show help
help:
	@echo "MAZE Network Node Testbench Build System"
	@echo "======================================"
	@echo ""
	@echo "Available targets:"
	@echo "  all          Build all testbenches"
	@echo "  tb_node      Build main testbench executable"
	@echo "  run          Run main testbench with VCD"
	@echo "  run_node    Run testbench for specific node"
	@echo "  test         Run quick test (no VCD)"
	@echo "  debug        Run debug test with maximum verbosity"
	@echo "  regression   Run full regression suite"
	@echo "  clean        Remove all build artifacts"
	@echo "  help         Show this help message"
	@echo ""
	@echo "Variables:"
	@echo "  HP           Horizontal position for node (0-7)"
	@echo "  VP           Vertical position for node (0-7)"
	@echo ""
	@echo "Examples:"
	@echo "  make run_node HP=3 VP=2"
	@echo "  make debug"
	@echo "  make test"

# Clean build artifacts
clean:
	@echo "[CLEAN] Removing build artifacts..."
	rm -rf $(BUILD_DIR)
	rm -f $(VCD_FILE)
	rm -f results.txt
	rm -f regression_results.txt
	@echo "[CLEAN] Clean completed"

# Clean including VCD files
clean_all: clean
	@echo "[CLEAN] Removing all VCD files..."
	rm -rf $(VCD_DIR)/*.vcd

# ====================================================================
# File Generation Targets
# ====================================================================

# Generate RTL filelist if it doesn't exist
$(RTL_FILELIST):
	@echo "[GEN] Generating RTL filelist..."
	@mkdir -p $(dir $(RTL_FILELIST))
	@find $(RTL_DIR)/src -name "*.v" -o -name "*.sv" > $(RTL_FILELIST)
	@echo "$(RTL_DIR)/src/node/node.v" >> $(RTL_FILELIST)
	@echo "[GEN] RTL filelist generated"

# Check dependencies
check_deps:
	@echo "[CHECK] Verifying dependencies..."
	@which $(VERILATOR) > /dev/null || (echo "ERROR: verilator not found in PATH" && exit 1)
	@which $(CXX) > /dev/null || (echo "ERROR: C++ compiler not found in PATH" && exit 1)
	@echo "[CHECK] All dependencies found"

# ====================================================================
# Installation and Packaging
# ====================================================================

# Install testbench
install: $(MAIN_TARGET)
	@echo "[INSTALL] Installing testbench..."
	@mkdir -p $(PROJECT_ROOT)/bin
	cp $(MAIN_TARGET) $(PROJECT_ROOT)/bin/
	@echo "[INSTALL] Installation completed"

# Create distribution package
package: clean all
	@echo "[PACKAGE] Creating distribution package..."
	@cd $(PROJECT_ROOT) && tar -czf maze_testbench_$(shell date +%Y%m%d_%H%M%S).tar.gz \
		--exclude=sim --exclude=obj_dir --exclude=*.o --exclude=*.a \
		testbench/ rtl/ docs/ *.md
	@echo "[PACKAGE] Package created"

# ====================================================================
# Development Targets
# ====================================================================

# Generate Doxygen documentation (if available)
docs:
	@echo "[DOCS] Generating documentation..."
	@which doxygen > /dev/null && doxygen Doxyfile || echo "Doxygen not available"

# Check code style (if available)
format:
	@echo "[FORMAT] Formatting code..."
	@which clang-format > /dev/null && \
		clang-format -i $(TB_SOURCES) $(COMMON_DIR)/*.cpp $(COMMON_DIR)/*.h || \
		echo "clang-format not available"

# Static analysis
analyze:
	@echo "[ANALYZE] Running static analysis..."
	@which cppcheck > /dev/null && \
		cppcheck --enable=all --std=c++11 $(TB_SOURCES) $(COMMON_DIR)/*.cpp || \
		echo "cppcheck not available"

# ====================================================================
# Advanced Targets
# ====================================================================

# Build with coverage support
coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean all
	@echo "[COVERAGE] Built with coverage support"

# Build for debugging
debug_build: CXXFLAGS += -O0 -g3 -DDEBUG
debug_build: VERILATOR_CFLAGS += -O0 -g3 -DDEBUG
debug_build: clean all
	@echo "[DEBUG] Built with debug flags"

# Build for release
release: CXXFLAGS += -O3 -DNDEBUG
release: VERILATOR_CFLAGS += -O3 -DNDEBUG
release: clean all
	@echo "[RELEASE] Built with release optimization"

# ====================================================================
# Phony Targets (for completeness)
# ====================================================================

.PHONY: all clean help run regression test debug check_deps install package docs format analyze coverage debug_build release build_dirs clean_all run_node

# ====================================================================
# Dependencies
# ====================================================================

# Ensure RTL filelist exists
-include $(RTL_FILELIST)

# Include Verilator generated dependencies if available
-include $(OBJ_DIR)/Vnode.mk

# End of Makefile
# ====================================================================