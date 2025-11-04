#!/bin/bash

# NoC 64-Node Network Test Runner
# This script runs all tests in the correct order and generates a comprehensive report

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Project configuration
NOC_ROOT=$(pwd)
RTL_DIR="$NOC_ROOT/rtl"
TB_DIR="$RTL_DIR/tb"
OBJ_DIR="$RTL_DIR/obj_dir"
RESULTS_DIR="$NOC_ROOT/test_results"
COVERAGE_DIR="$RESULTS_DIR/coverage"

# Create directories
mkdir -p "$RESULTS_DIR"
mkdir -p "$COVERAGE_DIR"
mkdir -p "$OBJ_DIR"

# Test results
TESTS_PASSED=0
TESTS_FAILED=0
TOTAL_TESTS=0

# Print header
echo -e "${BLUE}=====================================${NC}"
echo -e "${BLUE}    NoC 64-Node Test Runner       ${NC}"
echo -e "${BLUE}=====================================${NC}"
echo ""

# Function to print status
print_status() {
    echo -e "${BLUE}[$(date '+%Y-%m-%d %H:%M:%S')]${NC} $1"
}

print_success() {
    echo -e "${GREEN}✓${NC} $1"
}

print_error() {
    echo -e "${RED}✗${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}⚠${NC} $1"
}

# Function to run a single test
run_test() {
    local test_file=$1
    local test_name=$(basename "$test_file" .sv)
    local test_log="$RESULTS_DIR/${test_name}.log"

    print_status "Running test: $test_name"

    # Compile with Verilator
    cd "$RTL_DIR"
    if ! verilator -Wall --cc --exe --top "$test_name" "$test_file" > "$test_log" 2>&1; then
        print_error "$test_name: Compilation failed"
        echo "Check log: $test_log"
        ((TESTS_FAILED++))
        ((TOTAL_TESTS++))
        return 1
    fi

    # Build and run
    cd obj_dir
    if ! make -f "V${test_name}.mk" >> "$test_log" 2>&1; then
        print_error "$test_name: Build failed"
        echo "Check log: $test_log"
        ((TESTS_FAILED++))
        ((TOTAL_TESTS++))
        return 1
    fi

    # Run the test with timeout
    timeout 60s "./V${test_name}" >> "$test_log" 2>&1
    local exit_code=$?

    if [ $exit_code -eq 124 ]; then
        print_error "$test_name: Test timed out (60s)"
        echo "Check log: $test_log"
        ((TESTS_FAILED++))
        ((TOTAL_TESTS++))
        return 1
    elif [ $exit_code -eq 0 ]; then
        if grep -q "PASSED\|All tests passed" "$test_log"; then
            print_success "$test_name: PASSED"
            ((TESTS_PASSED++))
            ((TOTAL_TESTS++))
            return 0
        else
            print_error "$test_name: Test failed (see log)"
            echo "Check log: $test_log"
            ((TESTS_FAILED++))
            ((TOTAL_TESTS++))
            return 1
        fi
    else
        print_error "$test_name: Runtime error (exit code: $exit_code)"
        echo "Check log: $test_log"
        ((TESTS_FAILED++))
        ((TOTAL_TESTS++))
        return 1
    fi
}

# Function to check if Verilator is available
check_dependencies() {
    print_status "Checking dependencies..."

    if ! command -v verilator &> /dev/null; then
        print_error "Verilator not found. Please install Verilator first."
        exit 1
    fi

    if ! command -v make &> /dev/null; then
        print_error "Make not found. Please install build tools."
        exit 1
    fi

    local verilator_version=$(verilator -version | head -n1)
    print_success "Verilator: $verilator_version"
    print_success "Dependencies check complete"
}

# Function to run syntax check
run_syntax_check() {
    print_status "Running syntax check on all RTL files..."

    local syntax_errors=0

    # Check all SystemVerilog files
    find "$RTL_DIR" -name "*.sv" -not -path "*/tb/*" | while read -r file; do
        if ! verilator -Wall --lint-only "$file" 2>/dev/null; then
            print_error "Syntax error in: $file"
            ((syntax_errors++))
        fi
    done

    if [ $syntax_errors -eq 0 ]; then
        print_success "All syntax checks passed"
    else
        print_error "Found $syntax_errors syntax errors"
        return 1
    fi
}

# Function to generate test report
generate_report() {
    local report_file="$RESULTS_DIR/test_report.txt"

    print_status "Generating test report..."

    cat > "$report_file" << EOF
===================================
NoC 64-Node Test Report
===================================

Test Date: $(date)
Test Runner: $(whoami)@$(hostname)

Test Summary:
------------
Total Tests: $TOTAL_TESTS
Passed: $TESTS_PASSED
Failed: $TESTS_FAILED
Success Rate: $(( TOTAL_TESTS > 0 ? TESTS_PASSED * 100 / TOTAL_TESTS : 0 ))%

Individual Test Results:
------------------------
EOF

    # Add individual test results
    for log_file in "$RESULTS_DIR"/*.log; do
        if [ -f "$log_file" ]; then
            local test_name=$(basename "$log_file" .log)
            local status="UNKNOWN"

            if grep -q "PASSED\|All tests passed" "$log_file"; then
                status="PASSED"
            elif grep -q "FAILED\|failed\|Error" "$log_file"; then
                status="FAILED"
            fi

            echo "$test_name: $status" >> "$report_file"
        fi
    done

    cat >> "$report_file" << EOF

Coverage Information:
-------------------
EOF

    # Add coverage information if available
    if [ -f "$COVERAGE_DIR/coverage_report.txt" ]; then
        cat "$COVERAGE_DIR/coverage_report.txt" >> "$report_file"
    else
        echo "Coverage report not available" >> "$report_file"
    fi

    print_success "Test report generated: $report_file"
}

# Function to clean up
cleanup() {
    print_status "Cleaning up temporary files..."
    if [ -d "$OBJ_DIR" ]; then
        rm -rf "$OBJ_DIR"
    fi
    print_success "Cleanup complete"
}

# Main execution
main() {
    # Parse command line arguments
    local CLEAN_ONLY=false
    local SYNTAX_ONLY=false
    local SKIP_SYNTAX=false

    while [[ $# -gt 0 ]]; do
        case $1 in
            --clean)
                CLEAN_ONLY=true
                shift
                ;;
            --syntax-only)
                SYNTAX_ONLY=true
                shift
                ;;
            --skip-syntax)
                SKIP_SYNTAX=true
                shift
                ;;
            --help|-h)
                echo "Usage: $0 [OPTIONS]"
                echo "Options:"
                echo "  --clean        Clean build files and exit"
                echo "  --syntax-only  Run syntax checks only"
                echo "  --skip-syntax  Skip syntax checks"
                echo "  --help, -h     Show this help message"
                exit 0
                ;;
            *)
                print_error "Unknown option: $1"
                exit 1
                ;;
        esac
    done

    # Handle clean option
    if [ "$CLEAN_ONLY" = true ]; then
        cleanup
        exit 0
    fi

    # Start testing
    local start_time=$(date +%s)

    print_status "Starting NoC 64-Node test suite..."

    # Check dependencies
    check_dependencies

    # Run syntax check
    if [ "$SKIP_SYNTAX" = false ]; then
        if ! run_syntax_check; then
            if [ "$SYNTAX_ONLY" = true ]; then
                exit 1
            fi
        fi

        if [ "$SYNTAX_ONLY" = true ]; then
            print_success "Syntax checks complete"
            exit 0
        fi
    fi

    # Find and run tests
    print_status "Discovering tests..."

    # Look for test files in different categories
    local test_files=()

    # Unit tests
    for test_file in "$TB_DIR"/tb_*.sv; do
        if [ -f "$test_file" ]; then
            test_files+=("$test_file")
        fi
    done

    if [ ${#test_files[@]} -eq 0 ]; then
        print_warning "No test files found in $TB_DIR"
        print_status "You need to create test files first. See documentation for guidance."
        exit 0
    fi

    print_status "Found ${#test_files[@]} test files"
    echo ""

    # Run all tests
    for test_file in "${test_files[@]}"; do
        if run_test "$test_file"; then
            # Test passed, continue
            echo ""
        else
            # Test failed, but continue with other tests
            echo ""
        fi
    done

    # Generate report
    generate_report

    # Calculate duration
    local end_time=$(date +%s)
    local duration=$((end_time - start_time))

    # Print final summary
    echo ""
    echo -e "${BLUE}=====================================${NC}"
    echo -e "${BLUE}        Final Test Summary         ${NC}"
    echo -e "${BLUE}=====================================${NC}"
    echo -e "Total Tests: ${#test_files[@]}"
    echo -e "Passed: ${GREEN}$TESTS_PASSED${NC}"
    echo -e "Failed: ${RED}$TESTS_FAILED${NC}"
    echo -e "Duration: ${duration} seconds"
    echo ""

    if [ $TESTS_FAILED -eq 0 ]; then
        print_success "🎉 All tests passed!"
        echo -e "Check detailed report: ${RESULTS_DIR}/test_report.txt"
        exit 0
    else
        print_error "❌ $TESTS_FAILED test(s) failed"
        echo -e "Check detailed report: ${RESULTS_DIR}/test_report.txt"
        echo -e "Failed test logs are in: ${RESULTS_DIR}/"
        exit 1
    fi
}

# Handle interrupt gracefully
trap cleanup EXIT

# Run main function
main "$@"