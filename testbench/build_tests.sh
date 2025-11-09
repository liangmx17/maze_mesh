#!/bin/bash

# ====================================================================
# MAZE Network Node - Testbench Build Script
# ====================================================================
#
# Automated build script for MAZE node testbenches
# Handles Verilator compilation, dependency checking, and setup
#
# Usage:
#   ./build_tests.sh [options]
#   ./build_tests.sh --help
#
# ====================================================================

set -e  # Exit on any error

# ====================================================================
# Configuration
# ====================================================================

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Project paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
TESTBENCH_DIR="$PROJECT_ROOT/testbench/cpp"
BUILD_DIR="$PROJECT_ROOT/sim/build"

# Default options
BUILD_TYPE="release"
VERBOSE=0
ENABLE_VCD=0
ENABLE_COVERAGE=0
CLEAN_BUILD=0
RUN_TESTS=0
NODE_HP=3
NODE_VP=2

# ====================================================================
# Helper Functions
# ====================================================================

print_usage() {
    cat << EOF
MAZE Network Node Testbench Build Script

Usage: $0 [options]

Options:
    -h, --help              Show this help message
    -c, --clean             Clean build before compilation
    -v, --verbose           Enable verbose output
    --vcd                   Enable VCD waveform generation
    --coverage              Enable code coverage
    --debug                 Debug build (no optimization)
    --run                   Run tests after building
    --hp <num>              Node horizontal position (0-7) [default: 3]
    --vp <num>              Node vertical position (0-7) [default: 2]
    --build-dir <path>      Custom build directory [default: $BUILD_DIR]
    --install-deps          Install required dependencies (Ubuntu/Debian)
    --check-deps            Check if dependencies are installed

Examples:
    $0                                    # Build release version
    $0 --clean --run                      # Clean build and run tests
    $0 --debug --vcd --run                # Debug build with VCD and test run
    $0 --coverage --run --hp 0 --vp 0     # Build with coverage for node (0,0)
    $0 --install-deps                     # Install dependencies

EOF
}

log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

log_debug() {
    if [ "$VERBOSE" -eq 1 ]; then
        echo -e "${BLUE}[DEBUG]${NC} $1"
    fi
}

# ====================================================================
# Dependency Management
# ====================================================================

check_dependencies() {
    log_info "Checking dependencies..."

    local missing_deps=()

    # Check for Verilator
    if ! command -v verilator &> /dev/null; then
        missing_deps+=("verilator")
    fi

    # Check for C++ compiler
    if ! command -v g++ &> /dev/null && ! command -v clang++ &> /dev/null; then
        missing_deps+=("g++ or clang++")
    fi

    # Check for make
    if ! command -v make &> /dev/null; then
        missing_deps+=("make")
    fi

    if [ ${#missing_deps[@]} -gt 0 ]; then
        log_error "Missing dependencies: ${missing_deps[*]}"
        log_info "Run '$0 --install-deps' to install them (Ubuntu/Debian)"
        return 1
    fi

    log_success "All dependencies found"
    return 0
}

install_dependencies() {
    log_info "Installing dependencies for Ubuntu/Debian..."

    if command -v apt-get &> /dev/null; then
        sudo apt-get update
        sudo apt-get install -y \
            verilator \
            g++ \
            make \
            libpthread-stubs0-dev \
            build-essential \
            git
        log_success "Dependencies installed"
    else
        log_error "Unsupported package manager. Please install manually:"
        echo "  - Verilator (from verilator.org or package manager)"
        echo "  - C++ compiler (g++ or clang++)"
        echo "  - make"
        return 1
    fi
}

# ====================================================================
# Build Functions
# ====================================================================

setup_environment() {
    log_info "Setting up build environment..."

    # Create necessary directories
    mkdir -p "$BUILD_DIR"
    mkdir -p "$PROJECT_ROOT/sim/wave/vcd"
    mkdir -p "$PROJECT_ROOT/reports/simulation"

    # Set working directory
    cd "$TESTBENCH_DIR"

    log_debug "Build directory: $BUILD_DIR"
    log_debug "Working directory: $(pwd)"
}

prepare_rtl_sources() {
    log_info "Preparing RTL sources..."

    # Create RTL filelist if it doesn't exist
    local rtl_filelist="$PROJECT_ROOT/rtl.filelist"

    if [ ! -f "$rtl_filelist" ]; then
        log_info "Creating RTL filelist..."
        {
            # Add include files
            find "$PROJECT_ROOT/rtl/include" -name "*.v" -o -name "*.sv" | sort

            # Add source files
            find "$PROJECT_ROOT/rtl/src" -name "*.v" -o -name "*.sv" | sort

            # Add Provided Code if it exists
            if [ -d "$PROJECT_ROOT/Provided_Code" ]; then
                find "$PROJECT_ROOT/Provided_Code" -name "*.v" -o -name "*.sv" | sort
            fi
        } > "$rtl_filelist"
        log_success "RTL filelist created: $rtl_filelist"
    fi

    # Verify critical files exist
    local critical_files=(
        "$PROJECT_ROOT/rtl/src/node/node.v"
        "$PROJECT_ROOT/rtl/include/global_defines/top_define.v"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_a.sv"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_b.sv"
        "$PROJECT_ROOT/rtl/include/interfaces/interface_c.sv"
    )

    for file in "${critical_files[@]}"; do
        if [ ! -f "$file" ]; then
            log_error "Critical file not found: $file"
            return 1
        fi
    done

    log_success "RTL sources prepared"
}

clean_build() {
    if [ "$CLEAN_BUILD" -eq 1 ]; then
        log_info "Cleaning previous build..."
        rm -rf "$BUILD_DIR"
        rm -rf "$TESTBENCH_DIR/build"
        rm -rf "$TESTBENCH_DIR/obj_dir"
        log_success "Build cleaned"
    fi
}

build_testbench() {
    log_info "Building testbench..."

    # Set build flags based on options
    local make_args=""

    if [ "$VERBOSE" -eq 1 ]; then
        make_args="VERBOSE=1"
    fi

    if [ "$BUILD_TYPE" = "debug" ]; then
        make_args="$make_args debug_build"
    elif [ "$BUILD_TYPE" = "coverage" ]; then
        make_args="$make_args coverage"
    else
        make_args="$make_args release"
    fi

    log_debug "Make arguments: $make_args"

    # Run make
    if make -f Makefile $make_args; then
        log_success "Testbench built successfully"
    else
        log_error "Build failed"
        return 1
    fi
}

# ====================================================================
# Test Execution
# ====================================================================

run_tests() {
    if [ "$RUN_TESTS" -eq 1 ]; then
        log_info "Running tests..."

        local test_exe="$TESTBENCH_DIR/build/bin/tb_node"
        if [ ! -f "$test_exe" ]; then
            log_error "Test executable not found: $test_exe"
            return 1
        fi

        # Prepare test arguments
        local test_args=""
        test_args="$test_args --hp $NODE_HP"
        test_args="$test_args --vp $NODE_VP"
        test_args="$test_args --verbose 1"

        if [ "$ENABLE_VCD" -eq 1 ]; then
            test_args="$test_args --vcd"
            log_info "VCD waveform generation enabled"
        fi

        test_args="$test_args --output $PROJECT_ROOT/reports/simulation/test_results.txt"

        log_debug "Test command: $test_exe $test_args"

        # Run tests
        if $test_exe $test_args; then
            log_success "Tests completed successfully"
        else
            log_warning "Tests completed with some failures"
            return 1
        fi

        # Display results summary if available
        if [ -f "$PROJECT_ROOT/reports/simulation/test_results.txt" ]; then
            log_info "Results saved to: $PROJECT_ROOT/reports/simulation/test_results.txt"
        fi
    fi
}

# ====================================================================
# Utility Functions
# ====================================================================

generate_report() {
    log_info "Generating build report..."

    local report_file="$PROJECT_ROOT/reports/simulation/build_report.txt"
    mkdir -p "$(dirname "$report_file")"

    {
        echo "MAZE Network Node Testbench Build Report"
        echo "========================================"
        echo "Generated: $(date)"
        echo ""
        echo "Build Configuration:"
        echo "  Build Type: $BUILD_TYPE"
        echo "  Node Position: ($NODE_HP, $NODE_VP)"
        echo "  VCD Enabled: $ENABLE_VCD"
        echo "  Coverage Enabled: $ENABLE_COVERAGE"
        echo "  Verbose Mode: $VERBOSE"
        echo ""
        echo "Environment:"
        echo "  Working Directory: $(pwd)"
        echo "  Build Directory: $BUILD_DIR"
        echo ""
        echo "Versions:"
        echo "  $(verilator --version 2>/dev/null || echo 'Verilator not found')"
        echo "  $(g++ --version 2>/dev/null | head -n1 || echo 'G++ not found')"
        echo "  $(make --version 2>/dev/null | head -n1 || echo 'Make not found')"
    } > "$report_file"

    log_success "Build report generated: $report_file"
}

# ====================================================================
# Main Script
# ====================================================================

parse_arguments() {
    while [[ $# -gt 0 ]]; do
        case $1 in
            -h|--help)
                print_usage
                exit 0
                ;;
            -c|--clean)
                CLEAN_BUILD=1
                shift
                ;;
            -v|--verbose)
                VERBOSE=1
                shift
                ;;
            --vcd)
                ENABLE_VCD=1
                shift
                ;;
            --coverage)
                ENABLE_COVERAGE=1
                BUILD_TYPE="coverage"
                shift
                ;;
            --debug)
                BUILD_TYPE="debug"
                shift
                ;;
            --run)
                RUN_TESTS=1
                shift
                ;;
            --hp)
                NODE_HP="$2"
                shift 2
                ;;
            --vp)
                NODE_VP="$2"
                shift 2
                ;;
            --build-dir)
                BUILD_DIR="$2"
                shift 2
                ;;
            --install-deps)
                install_dependencies
                exit $?
                ;;
            --check-deps)
                check_dependencies
                exit $?
                ;;
            *)
                log_error "Unknown option: $1"
                print_usage
                exit 1
                ;;
        esac
    done

    # Validate arguments
    if [[ ! "$NODE_HP" =~ ^[0-7]$ ]]; then
        log_error "Invalid horizontal position: $NODE_HP (must be 0-7)"
        exit 1
    fi

    if [[ ! "$NODE_VP" =~ ^[0-7]$ ]]; then
        log_error "Invalid vertical position: $NODE_VP (must be 0-7)"
        exit 1
    fi
}

main() {
    echo "MAZE Network Node Testbench Build Script"
    echo "======================================="

    parse_arguments "$@"

    # Check dependencies
    if ! check_dependencies; then
        exit 1
    fi

    # Setup environment
    setup_environment

    # Prepare RTL sources
    prepare_rtl_sources

    # Clean if requested
    clean_build

    # Build testbench
    if ! build_testbench; then
        exit 1
    fi

    # Run tests if requested
    if [ "$RUN_TESTS" -eq 1 ]; then
        run_tests
    fi

    # Generate report
    generate_report

    log_success "Build script completed successfully!"

    if [ "$RUN_TESTS" -eq 0 ]; then
        echo ""
        echo "Next steps:"
        echo "  Run tests: $0 --run"
        echo "  Run with VCD: $0 --run --vcd"
        echo "  Debug build: $0 --debug --run"
    fi
}

# Run main function with all arguments
main "$@"