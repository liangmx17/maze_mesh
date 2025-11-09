#!/bin/bash
# ====================================================================
# MAZE Network Node - Performance Test Runner
# ====================================================================
#
# Script to run performance tests with configurable options
#
# Usage: ./run_performance.sh [options]
#   Options:
#     --hp <num>     Node horizontal position [0-7] (default: 3)
#     --vp <num>     Node vertical position [0-7] (default: 2)
#     --packets <n>  Number of test packets (default: 1000)
#     --vcd          Enable VCD waveform generation
#     --verbose      Enable verbose output
#     --build        Rebuild before running
#     --clean        Clean build before running
#     --help         Show help message
#
# ====================================================================

# Script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEST_DIR="$(dirname "$SCRIPT_DIR")"

# Default configuration
HP=3
VP=2
PACKETS=1000
BUILD=false
CLEAN=false
VCD=""
VERBOSE=""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# ====================================================================
# Utility Functions
# ====================================================================

print_usage() {
    echo "MAZE Network Node - Performance Test Runner"
    echo "========================================="
    echo ""
    echo "Usage: $0 [options]"
    echo ""
    echo "Options:"
    echo "  --hp <num>     Node horizontal position [0-7] (default: $HP)"
    echo "  --vp <num>     Node vertical position [0-7] (default: $VP)"
    echo "  --packets <n>  Number of test packets (100-10000, default: $PACKETS)"
    echo "  --vcd          Enable VCD waveform generation"
    echo "  --verbose      Enable verbose output"
    echo "  --build        Rebuild before running"
    echo "  --clean        Clean build before running"
    echo "  --help         Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                           # Run with default settings"
    echo "  $0 --hp 5 --vp 2            # Run for node (5,2)"
    echo "  $0 --packets 5000           # Run with 5000 packets"
    echo "  $0 --vcd --verbose          # Run with VCD and verbose output"
    echo "  $0 --build --clean          # Clean build and run"
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

check_dependencies() {
    local missing_deps=()

    if ! command -v make >/dev/null 2>&1; then
        missing_deps+=("make")
    fi

    if ! command -v verilator >/dev/null 2>&1; then
        missing_deps+=("verilator")
    fi

    if [ ${#missing_deps[@]} -ne 0 ]; then
        log_error "Missing dependencies: ${missing_deps[*]}"
        log_error "Please install missing dependencies and try again"
        exit 1
    fi
}

# ====================================================================
# Command Line Parsing
# ====================================================================

parse_arguments() {
    while [[ $# -gt 0 ]]; do
        case $1 in
            --hp)
                HP="$2"
                shift 2
                ;;
            --vp)
                VP="$2"
                shift 2
                ;;
            --packets)
                PACKETS="$2"
                shift 2
                ;;
            --vcd)
                VCD="--vcd"
                shift
                ;;
            --verbose)
                VERBOSE="--verbose"
                shift
                ;;
            --build)
                BUILD=true
                shift
                ;;
            --clean)
                CLEAN=true
                shift
                ;;
            --help)
                print_usage
                exit 0
                ;;
            *)
                log_error "Unknown option: $1"
                print_usage
                exit 1
                ;;
        esac
    done

    # Validate arguments
    if [[ ! "$HP" =~ ^[0-7]$ ]]; then
        log_error "HP must be between 0 and 7, got: $HP"
        exit 1
    fi

    if [[ ! "$VP" =~ ^[0-7]$ ]]; then
        log_error "VP must be between 0 and 7, got: $VP"
        exit 1
    fi

    if [[ ! "$PACKETS" =~ ^[0-9]+$ ]] || [ "$PACKETS" -lt 100 ] || [ "$PACKETS" -gt 10000 ]; then
        log_error "PACKETS must be between 100 and 10000, got: $PACKETS"
        exit 1
    fi
}

# ====================================================================
# Build Functions
# ====================================================================

build_test() {
    log_info "Building performance test..."
    cd "$TEST_DIR"

    if [ "$CLEAN" = true ]; then
        log_info "Cleaning build artifacts..."
        make clean
    fi

    if ! make test_performance; then
        log_error "Failed to build performance test"
        exit 1
    fi

    log_success "Performance test built successfully"
}

# ====================================================================
# Test Execution
# ====================================================================

run_test() {
    log_info "Running performance test..."
    log_info "Node position: ($HP, $VP)"
    log_info "Test packets: $PACKETS"

    if [ -n "$VCD" ]; then
        log_info "VCD generation enabled"
    fi

    if [ -n "$VERBOSE" ]; then
        log_info "Verbose output enabled"
    fi

    cd "$TEST_DIR"

    # Create output directories
    mkdir -p ../reports/simulation
    mkdir -p ../../../sim/wave/vcd

    # Run the test with proper error handling
    local test_start=$(date +%s)
    local test_output

    if test_output=$(make run_performance HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1); then
        local test_end=$(date +%s)
        local test_duration=$((test_end - test_start))

        log_success "Performance test completed successfully in ${test_duration}s"
        log_info "Test results saved to: performance_test_results.txt"

        if [ -n "$VCD" ]; then
            log_info "VCD waveform saved to: test_performance.vcd"
        fi

        # Display performance metrics
        if [ -f "performance_test_results.txt" ]; then
            echo ""
            log_info "Performance Metrics:"
            echo "====================="

            # Extract key performance numbers
            if grep -q "throughput_pps" performance_test_results.txt; then
                echo "Throughput: $(grep -o 'throughput_pps=[0-9.]*' performance_test_results.txt | cut -d'=' -f2) packets/sec"
            fi

            if grep -q "avg_latency_cycles" performance_test_results.txt; then
                echo "Avg Latency: $(grep -o 'avg_latency_cycles=[0-9.]*' performance_test_results.txt | cut -d'=' -f2) cycles"
            fi

            if grep -q "pipeline_efficiency" performance_test_results.txt; then
                echo "Pipeline Efficiency: $(grep -o 'pipeline_efficiency=[0-9.]*' performance_test_results.txt | cut -d'=' -f2 | cut -d'.' -f1)%"
            fi
        fi

        return 0
    else
        local test_end=$(date +%s)
        local test_duration=$((test_end - test_start))

        log_error "Performance test failed after ${test_duration}s"

        if [ -n "$test_output" ]; then
            echo ""
            log_error "Test Output:"
            echo "============="
            echo "$test_output" | tail -n 20
        fi

        return 1
    fi
}

# ====================================================================
# Main Execution
# ====================================================================

main() {
    echo "MAZE Network Node - Performance Test Runner"
    echo "========================================="
    echo ""

    # Check dependencies
    check_dependencies

    # Parse command line arguments
    parse_arguments "$@"

    # Validate node position
    if [ "$HP" -lt 0 ] || [ "$HP" -gt 7 ]; then
        log_error "Invalid HP value: $HP (must be 0-7)"
        exit 1
    fi

    if [ "$VP" -lt 0 ] || [ "$VP" -gt 7 ]; then
        log_error "Invalid VP value: $VP (must be 0-7)"
        exit 1
    fi

    log_info "Configuration:"
    log_info "  Node Position: ($HP, $VP)"
    log_info "  Test Packets: $PACKETS"
    log_info "  Build: $BUILD"
    log_info "  Clean: $CLEAN"
    log_info "  VCD: ${VCD:-disabled}"
    log_info "  Verbose: ${VERBOSE:-disabled}"
    echo ""

    # Build test if requested
    if [ "$BUILD" = true ]; then
        build_test
        echo ""
    fi

    # Check if test executable exists
    if [ ! -f "$TEST_DIR/build/bin/test_performance" ]; then
        log_warning "Test executable not found, building..."
        build_test
        echo ""
    fi

    # Run the test
    if run_test; then
        log_success "Performance test completed successfully!"
        exit 0
    else
        log_error "Performance test failed!"
        exit 1
    fi
}

# Run main function with all arguments
main "$@"