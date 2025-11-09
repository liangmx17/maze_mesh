#!/bin/bash
# ====================================================================
# MAZE Network Node - All Focused Tests Runner
# ====================================================================
#
# Script to run all focused test suites with configurable options
#
# Usage: ./run_all.sh [options]
#   Options:
#     --hp <num>     Node horizontal position [0-7] (default: 3)
#     --vp <num>     Node vertical position [0-7] (default: 2)
#     --vcd          Enable VCD waveform generation
#     --verbose      Enable verbose output
#     --build        Rebuild before running
#     --clean        Clean build before running
#     --quick        Run in quick mode (no VCD, minimal output)
#     --parallel     Run tests in parallel (experimental)
#     --report       Generate comprehensive test report
#     --help         Show help message
#
# ====================================================================

# Script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEST_DIR="$(dirname "$SCRIPT_DIR")"

# Default configuration
HP=3
VP=2
BUILD=false
CLEAN=false
VCD=""
VERBOSE=""
QUICK=false
PARALLEL=false
REPORT=false

# Test list
TESTS=("basic" "qos" "fault" "pipeline" "performance" "interface")

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
NC='\033[0m' # No Color

# ====================================================================
# Utility Functions
# ====================================================================

print_usage() {
    echo "MAZE Network Node - All Focused Tests Runner"
    echo "==========================================="
    echo ""
    echo "Usage: $0 [options]"
    echo ""
    echo "Options:"
    echo "  --hp <num>     Node horizontal position [0-7] (default: $HP)"
    echo "  --vp <num>     Node vertical position [0-7] (default: $VP)"
    echo "  --vcd          Enable VCD waveform generation"
    echo "  --verbose      Enable verbose output"
    echo "  --build        Rebuild before running"
    echo "  --clean        Clean build before running"
    echo "  --quick        Run in quick mode (no VCD, minimal output)"
    echo "  --parallel     Run tests in parallel (experimental)"
    echo "  --report       Generate comprehensive test report"
    echo "  --help         Show help message"
    echo ""
    echo "Available Tests:"
    echo "  - Basic Functionality (test_basic)"
    echo "  - QoS Arbitration (test_qos)"
    echo "  - Fault Tolerance (test_fault)"
    echo "  - Pipeline Timing (test_pipeline)"
    echo "  - Performance (test_performance)"
    echo "  - Interface Protocol (test_interface)"
    echo ""
    echo "Examples:"
    echo "  $0                           # Run all tests with defaults"
    echo "  $0 --hp 5 --vp 2            # Run all tests for node (5,2)"
    echo "  $0 --vcd --verbose          # Run with VCD and verbose output"
    echo "  $0 --quick                  # Run quickly (no VCD)"
    echo "  $0 --clean --build --report # Clean, build, run, and report"
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

log_test() {
    echo -e "${MAGENTA}[TEST]${NC} $1"
}

log_section() {
    echo -e "${CYAN}=== $1 ===${NC}"
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
            --quick)
                QUICK=true
                VCD=""
                VERBOSE=""
                shift
                ;;
            --parallel)
                PARALLEL=true
                shift
                ;;
            --report)
                REPORT=true
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
}

# ====================================================================
# Build Functions
# ====================================================================

build_all_tests() {
    log_info "Building all focused tests..."
    cd "$TEST_DIR"

    if [ "$CLEAN" = true ]; then
        log_info "Cleaning build artifacts..."
        make clean
    fi

    if ! make all; then
        log_error "Failed to build focused tests"
        exit 1
    fi

    log_success "All focused tests built successfully"
}

# ====================================================================
# Test Execution Functions
# ====================================================================

run_single_test() {
    local test_name="$1"
    log_test "Running $test_name test..."

    cd "$TEST_DIR"

    # Create output directories
    mkdir -p ../reports/simulation
    mkdir -p ../../../sim/wave/vcd

    local test_start=$(date +%s)
    local test_output

    # Run specific test
    case $test_name in
        "basic")
            test_output=$(make run_basic HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        "qos")
            test_output=$(make run_qos HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        "fault")
            test_output=$(make run_fault HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        "pipeline")
            test_output=$(make run_pipeline HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        "performance")
            test_output=$(make run_performance HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        "interface")
            test_output=$(make run_interface HP="$HP" VP="$VP" VCD_FLAG="$VCD" VERBOSE_FLAG="$VERBOSE" 2>&1)
            ;;
        *)
            log_error "Unknown test: $test_name"
            return 1
            ;;
    esac

    local test_end=$(date +%s)
    local test_duration=$((test_end - test_start))

    if [ $? -eq 0 ]; then
        log_success "$test_name test completed in ${test_duration}s"
        echo "$test_name: PASS (${test_duration}s)" >> "$TEST_DIR/test_summary.txt"
        return 0
    else
        log_error "$test_name test failed after ${test_duration}s"
        echo "$test_name: FAIL (${test_duration}s)" >> "$TEST_DIR/test_summary.txt"

        if [ -n "$test_output" ]; then
            echo "Error output for $test_name:" >> "$TEST_DIR/test_summary.txt"
            echo "$test_output" | tail -n 10 >> "$TEST_DIR/test_summary.txt"
        fi

        return 1
    fi
}

run_all_tests_sequential() {
    local total_start=$(date +%s)
    local passed=0
    local failed=0

    # Initialize summary file
    echo "MAZE Network Node - Focused Tests Summary" > "$TEST_DIR/test_summary.txt"
    echo "Generated: $(date)" >> "$TEST_DIR/test_summary.txt"
    echo "Node Position: ($HP, $VP)" >> "$TEST_DIR/test_summary.txt"
    echo "=============================================" >> "$TEST_DIR/test_summary.txt"
    echo "" >> "$TEST_DIR/test_summary.txt"

    log_section "Running All Focused Tests"
    log_info "Node position: ($HP, $VP)"
    log_info "Tests to run: ${#TESTS[@]}"

    for test in "${TESTS[@]}"; do
        echo ""
        if run_single_test "$test"; then
            ((passed++))
        else
            ((failed++))
        fi
    done

    local total_end=$(date +%s)
    local total_duration=$((total_end - total_start))

    echo "" >> "$TEST_DIR/test_summary.txt"
    echo "=============================================" >> "$TEST_DIR/test_summary.txt"
    echo "Summary:" >> "$TEST_DIR/test_summary.txt"
    echo "Total Tests: ${#TESTS[@]}" >> "$TEST_DIR/test_summary.txt"
    echo "Passed: $passed" >> "$TEST_DIR/test_summary.txt"
    echo "Failed: $failed" >> "$TEST_DIR/test_summary.txt"
    echo "Total Duration: ${total_duration}s" >> "$TEST_DIR/test_summary.txt"

    if [ $failed -eq 0 ]; then
        echo "Result: ALL TESTS PASSED" >> "$TEST_DIR/test_summary.txt"
    else
        echo "Result: SOME TESTS FAILED" >> "$TEST_DIR/test_summary.txt"
    fi

    return $failed
}

run_all_tests_parallel() {
    log_warning "Parallel execution is experimental - may have resource contention"

    local total_start=$(date +%s)
    local pids=()

    # Initialize summary file
    echo "MAZE Network Node - Focused Tests Summary (Parallel)" > "$TEST_DIR/test_summary.txt"
    echo "Generated: $(date)" >> "$TEST_DIR/test_summary.txt"
    echo "Node Position: ($HP, $VP)" >> "$TEST_DIR/test_summary.txt"
    echo "=============================================" >> "$TEST_DIR/test_summary.txt"
    echo "" >> "$TEST_DIR/test_summary.txt"

    log_section "Running All Tests in Parallel"

    # Start all tests in background
    for test in "${TESTS[@]}"; do
        run_single_test "$test" &
        pids+=($!)
    done

    # Wait for all tests to complete
    local failed=0
    for pid in "${pids[@]}"; do
        if ! wait "$pid"; then
            ((failed++))
        fi
    done

    local total_end=$(date +%s)
    local total_duration=$((total_end - total_start))

    log_info "Parallel execution completed in ${total_duration}s"

    # Generate summary (simplified for parallel)
    echo "Parallel execution completed in ${total_duration}s" >> "$TEST_DIR/test_summary.txt"

    return $failed
}

# ====================================================================
# Report Generation
# ====================================================================

generate_report() {
    if [ ! -f "$TEST_DIR/test_summary.txt" ]; then
        log_error "No test summary found, cannot generate report"
        return 1
    fi

    log_info "Generating comprehensive test report..."

    local report_file="$TEST_DIR/../reports/simulation/focused_tests_report.md"
    mkdir -p "$(dirname "$report_file")"

    cat > "$report_file" << EOF
# MAZE Network Node - Focused Tests Report

Generated: $(date)
Node Position: ($HP, $VP)

## Executive Summary

EOF

    # Add summary statistics
    tail -n 10 "$TEST_DIR/test_summary.txt" >> "$report_file"

    echo "" >> "$report_file"
    echo "## Detailed Test Results" >> "$report_file"
    echo "" >> "$report_file"

    # Add individual test results
    for test in "${TESTS[@]}"; do
        local result_file="${test}_test_results.txt"
        if [ -f "$TEST_DIR/$result_file" ]; then
            echo "### $test Test" >> "$report_file"
            echo "" >> "$report_file"
            echo "\`\`\`" >> "$report_file"
            cat "$TEST_DIR/$result_file" >> "$report_file"
            echo "\`\`\`" >> "$report_file"
            echo "" >> "$report_file"
        fi
    done

    # Add performance metrics if available
    if [ -f "$TEST_DIR/performance_test_results.txt" ]; then
        echo "## Performance Metrics" >> "$report_file"
        echo "" >> "$report_file"
        echo "\`\`\`" >> "$report_file"
        grep -E "(Throughput|Latency|Efficiency)" "$TEST_DIR/performance_test_results.txt" >> "$report_file" || echo "No performance metrics available"
        echo "\`\`\`" >> "$report_file"
        echo "" >> "$report_file"
    fi

    log_success "Test report generated: $report_file"
}

# ====================================================================
# Main Execution
# ====================================================================

main() {
    echo "MAZE Network Node - All Focused Tests Runner"
    echo "==========================================="
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
    log_info "  Build: $BUILD"
    log_info "  Clean: $CLEAN"
    log_info "  VCD: ${VCD:-disabled}"
    log_info "  Verbose: ${VERBOSE:-disabled}"
    log_info "  Quick Mode: $QUICK"
    log_info "  Parallel: $PARALLEL"
    log_info "  Report: $REPORT"
    echo ""

    # Build tests if requested
    if [ "$BUILD" = true ]; then
        build_all_tests
        echo ""
    fi

    # Check if test executables exist
    local missing_tests=()
    for test in "${TESTS[@]}"; do
        if [ ! -f "$TEST_DIR/build/bin/test_$test" ]; then
            missing_tests+=("test_$test")
        fi
    done

    if [ ${#missing_tests[@]} -ne 0 ]; then
        log_warning "Missing test executables: ${missing_tests[*]}"
        log_info "Building missing tests..."
        build_all_tests
        echo ""
    fi

    # Run the tests
    local overall_start=$(date +%s)
    local test_failed=0

    if [ "$PARALLEL" = true ]; then
        if run_all_tests_parallel; then
            test_failed=0
        else
            test_failed=$?
        fi
    else
        if run_all_tests_sequential; then
            test_failed=0
        else
            test_failed=$?
        fi
    fi

    local overall_end=$(date +%s)
    local overall_duration=$((overall_end - overall_start))

    echo ""
    log_section "Overall Results"
    echo ""

    # Display summary
    if [ -f "$TEST_DIR/test_summary.txt" ]; then
        tail -n 15 "$TEST_DIR/test_summary.txt"
    fi

    echo ""
    log_info "Total execution time: ${overall_duration}s"

    # Generate report if requested
    if [ "$REPORT" = true ]; then
        generate_report
        echo ""
    fi

    # Final status
    if [ $test_failed -eq 0 ]; then
        log_success "All focused tests completed successfully!"
        exit 0
    else
        log_error "$test_failed test(s) failed!"
        exit 1
    fi
}

# Run main function with all arguments
main "$@"