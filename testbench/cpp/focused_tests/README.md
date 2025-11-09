# MAZE Network Node - Focused Testbenches

This directory contains a comprehensive suite of focused testbenches for the MAZE network node module. Each testbench is designed to validate specific aspects of the node's functionality, making it easier to debug issues and run targeted tests.

## Overview

The focused testbench system splits the monolithic test suite into six specialized testbenches:

1. **Basic Functionality Tests** (`test_basic.cpp`) - Core routing and packet handling
2. **QoS Arbitration Tests** (`test_qos.cpp`) - Priority-based arbitration
3. **Fault Tolerance Tests** (`test_fault.cpp`) - Single node failure handling
4. **Pipeline Timing Tests** (`test_pipeline.cpp`) - 4-stage pipeline operation
5. **Performance Tests** (`test_performance.cpp`) - Throughput and latency analysis
6. **Interface Tests** (`test_interface.cpp`) - A/B/C interface protocol validation

## Architecture

### File Structure

```
focused_tests/
├── README.md                    # This documentation
├── Makefile                     # Master build system
├── packet_utils.h               # Shared packet utilities
├── node_simulator.h             # Node simulation wrapper
├── test_helpers.h               # Common test utilities
├── test_basic.cpp               # Basic functionality test
├── test_qos.cpp                 # QoS arbitration test
├── test_fault.cpp               # Fault tolerance test
├── test_pipeline.cpp            # Pipeline timing test
├── test_performance.cpp         # Performance test
├── test_interface.cpp           # Interface test
└── scripts/
    ├── run_basic.sh             # Basic test runner
    ├── run_qos.sh               # QoS test runner
    ├── run_fault.sh             # Fault test runner
    ├── run_pipeline.sh          # Pipeline test runner
    ├── run_performance.sh       # Performance test runner
    ├── run_interface.sh         # Interface test runner
    └── run_all.sh               # All tests runner
```

### Common Components

#### packet_utils.h
- **Purpose**: Packet creation, parsing, and validation utilities
- **Features**:
  - 23-bit MAZE packet format support
  - Automatic packet generation for different test scenarios
  - Packet validation and type detection
  - QoS level handling
  - String conversion utilities

#### node_simulator.h
- **Purpose**: Verilator node simulation wrapper
- **Features**:
  - Unified interface for all testbenches
  - VCD waveform generation support
  - Ready/valid protocol handling
  - Node state validation
  - Performance timing measurement

#### test_helpers.h
- **Purpose**: Common test utilities and result handling
- **Features**:
  - Test suite framework
  - Result collection and reporting
  - Performance measurement tools
  - Statistics tracking

## Test Categories

### 1. Basic Functionality Tests (`test_basic.cpp`)

**Purpose**: Validate core node functionality including packet routing, local delivery, and basic I/O operations.

**Test Coverage**:
- Packet format validation and parsing
- Unicast routing through the node
- Local delivery (source = target scenarios)
- I/O interface signal integrity
- Edge node coordinate handling
- Boundary condition testing

**Usage**:
```bash
make run_basic                    # Run with defaults
make run_basic HP=5 VP=2        # Run for node (5,2)
make run_basic VCD_FLAG=--vcd    # Run with VCD generation
```

### 2. QoS Arbitration Tests (`test_qos.cpp`)

**Purpose**: Test Quality of Service priority handling and arbitration fairness.

**Test Coverage**:
- High vs low priority packet ordering
- QoS arbitration under contention
- Priority fairness over time
- Starvation prevention for low QoS packets
- QoS timing characteristics

**Usage**:
```bash
make run_qos                     # Run with defaults
make run_qos HP=3 VP=1          # Run for node (3,1)
make run_qos VCD_FLAG=--vcd     # Run with VCD generation
```

### 3. Fault Tolerance Tests (`test_fault.cpp`)

**Purpose**: Validate node behavior under fault conditions and route avoidance.

**Test Coverage**:
- Single node failure handling
- Route avoidance around faulty nodes
- Fault injection and recovery scenarios
- Multiple fault condition handling
- Edge node fault scenarios

**Usage**:
```bash
make run_fault                   # Run with defaults
make run_fault HP=4 VP=4        # Run for node (4,4)
make run_fault VCD_FLAG=--vcd   # Run with VCD generation
```

### 4. Pipeline Timing Tests (`test_pipeline.cpp`)

**Purpose**: Validate 4-stage pipeline operation and timing characteristics.

**Test Coverage**:
- Basic pipeline latency measurement
- Ready/valid handshaking protocols
- Backpressure handling
- Pipeline throughput measurement
- Bubble insertion handling
- Pipeline efficiency analysis

**Usage**:
```bash
make run_pipeline                # Run with defaults
make run_pipeline HP=2 VP=5     # Run for node (2,5)
make run_pipeline VCD_FLAG=--vcd # Run with VCD generation
```

### 5. Performance Tests (`test_performance.cpp`)

**Purpose**: Measure and analyze node performance characteristics.

**Test Coverage**:
- Maximum throughput measurement
- Average latency analysis
- Performance under stress conditions
- QoS impact on performance
- Pipeline efficiency measurement
- Bandwidth utilization analysis

**Usage**:
```bash
make run_performance             # Run with defaults
make run_performance HP=1 VP=6  # Run for node (1,6)
make run_performance VCD_FLAG=--vcd # Run with VCD generation
```

### 6. Interface Tests (`test_interface.cpp`)

**Purpose**: Validate A/B/C interface protocol compliance and signal integrity.

**Test Coverage**:
- A Interface (pkt_in) protocol validation
- B Interface (pkt_out) protocol validation
- C Interface (pkt_con_if) protocol validation
- Signal timing characteristics
- Signal integrity checking
- Interface compliance verification

**Usage**:
```bash
make run_interface               # Run with defaults
make run_interface HP=6 VP=1    # Run for node (6,1)
make run_interface VCD_FLAG=--vcd # Run with VCD generation
```

## Build System

### Master Makefile

The Makefile provides comprehensive build and execution targets:

**Build Targets**:
- `make all` - Build all test executables
- `make test_basic` - Build basic functionality test
- `make test_qos` - Build QoS arbitration test
- `make test_fault` - Build fault tolerance test
- `make test_pipeline` - Build pipeline timing test
- `make test_performance` - Build performance test
- `make test_interface` - Build interface test

**Run Targets**:
- `make run_all` - Run all tests sequentially
- `make run_quick` - Run all tests quickly (no VCD)
- `make run_debug` - Run tests with VCD and verbose output

**Utility Targets**:
- `make clean` - Remove build artifacts
- `make help` - Show available targets
- `make status` - Show build status
- `make report` - Generate comprehensive test report

### Command Line Options

All test executables support common command line options:

```bash
./test_* --hp <num>        # Node horizontal position [0-7]
./test_* --vp <num>        # Node vertical position [0-7]
./test_* --vcd             # Enable VCD waveform generation
./test_* --verbose         # Enable verbose output
./test_* --help            # Show help message
```

## Runner Scripts

Convenient shell scripts are provided for each test category:

### Individual Test Runners

```bash
# Run basic functionality test
./scripts/run_basic.sh [options]

# Run QoS arbitration test
./scripts/run_qos.sh [options]

# Run fault tolerance test
./scripts/run_fault.sh [options]

# Run pipeline timing test
./scripts/run_pipeline.sh [options]

# Run performance test
./scripts/run_performance.sh [options]

# Run interface test
./scripts/run_interface.sh [options]
```

### All Tests Runner

```bash
# Run all tests with default settings
./scripts/run_all.sh

# Run all tests for specific node
./scripts/run_all.sh --hp 5 --vp 2

# Run all tests with VCD generation
./scripts/run_all.sh --vcd --verbose

# Run all tests in quick mode
./scripts/run_all.sh --quick

# Run all tests and generate report
./scripts/run_all.sh --report
```

## Test Results

### Output Files

Each test generates the following output files:

- `<test>_test_results.txt` - Detailed test results
- `test_<test>.vcd` - VCD waveform (if --vcd used)
- `test_summary.txt` - Overall test summary (for run_all.sh)

### Report Generation

Use the `--report` option or `make report` to generate a comprehensive test report:

```bash
./scripts/run_all.sh --report
# or
make report
```

This creates `reports/simulation/focused_test_report.md` with:
- Executive summary
- Individual test results
- Performance metrics
- Detailed statistics

## Quick Start Guide

### 1. Build All Tests

```bash
cd /home/liangmx/maze/testbench/cpp/focused_tests
make all
```

### 2. Run Quick Test

```bash
make run_quick
```

### 3. Run Individual Test

```bash
make run_basic HP=3 VP=2
```

### 4. Run with Debugging

```bash
make run_debug VCD_FLAG=--vcd
```

### 5. Generate Report

```bash
make report
```

## Advanced Usage

### Performance Testing

For comprehensive performance analysis:

```bash
# Performance test with many packets
./scripts/run_performance.sh --packets 5000 --verbose

# Generate benchmark
make benchmark
```

### Fault Injection Testing

```bash
# Test fault scenarios with detailed output
./scripts/run_fault.sh --vcd --verbose --hp 4 --vp 4
```

### Pipeline Analysis

```bash
# Detailed pipeline timing analysis
./scripts/run_pipeline.sh --vcd --verbose
```

## Dependencies

- **Verilator** - RTL simulation
- **GNU make** - Build system
- **g++** - C++ compiler (C++11 or later)
- **Bash** - Runner scripts

## Troubleshooting

### Common Issues

1. **Build Fails**:
   - Check Verilator installation: `which verilator`
   - Check RTL files: `ls ../../rtl/src/node/`
   - Clean and rebuild: `make clean && make all`

2. **Tests Fail Immediately**:
   - Check node position: Ensure HP and VP are 0-7
   - Check RTL compilation: Look for Verilator errors
   - Run with verbose: `--verbose` flag

3. **VCD Files Not Generated**:
   - Use `--vcd` flag
   - Check output directory: `ls ../../../sim/wave/vcd/`
   - Ensure Verilator trace support: `verilator --version`

4. **Performance Issues**:
   - Use `--quick` mode for faster execution
   - Reduce packet count for performance tests
   - Disable VCD generation: omit `--vcd` flag

### Debug Tips

- Use `--verbose` for detailed output
- Use `--vcd` for waveform analysis
- Check individual test result files
- Use `make status` to verify build state

## Integration with CI

For continuous integration:

```bash
# CI-friendly test run
make ci

# Quick verification
make run_quick

# Generate machine-readable results
make report
```

## File Locations

- **RTL Source**: `/home/liangmx/maze/rtl/src/node/node.v`
- **Build Artifacts**: `/home/liangmx/maze/testbench/cpp/focused_tests/build/`
- **VCD Waveforms**: `/home/liangmx/maze/sim/wave/vcd/`
- **Test Reports**: `/home/liangmx/maze/reports/simulation/`

## Contributing

When adding new tests:

1. Follow the existing file structure
2. Use the common utilities (`packet_utils.h`, `node_simulator.h`, `test_helpers.h`)
3. Add command line options consistent with existing tests
4. Update the Makefile with new build targets
5. Create corresponding runner script
6. Update this documentation

## License

This testbench system is part of the MAZE network project. See the main project license for details.