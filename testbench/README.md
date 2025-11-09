# MAZE Network Node - Comprehensive Testbench Suite

## Overview

This directory contains a comprehensive Verilator C++ testbench suite for the MAZE Network-on-Chip (NoC) node module. The testbench validates all aspects of the 4-stage pipeline node implementation, including basic routing, QoS arbitration, fault tolerance, and performance characteristics.

## Architecture

### Node Module Specifications

- **Topology**: 8×8 mesh network with 64 nodes
- **Pipeline**: 4-stage processing pipeline
- **Packet Format**: 23-bit packets (2 type + 1 QoS + 6 src + 6 tgt + 8 data)
- **Routing**: Two-hop unicast with intermediate node calculation
- **QoS**: 2-level priority system (high/low)
- **Fault Tolerance**: Single node failure support with clock gating
- **Interfaces**: A (input), B (output), C (topology connections)

### Testbench Architecture

```
tb_node_main.cpp                    # Main testbench driver
├── PacketGenerator                  # 23-bit packet generation utilities
├── TestUtils                        # Timing, logging, statistics
├── ResultValidator                  # Validation and pass/fail logic
├── BasicFunctionalityTest          # Unicast, multicast, broadcast
├── QoSArbitrationTest              # Priority verification
├── FaultToleranceTest              # Routing around failures
├── PipelineTimingTest              # Pipeline stage validation
└── PerformanceTest                 # Throughput and latency
```

## Quick Start

### Prerequisites

```bash
# Required dependencies
sudo apt-get install verilator g++ make libpthread-stubs0-dev build-essential

# Or use the automated installation
./build_tests.sh --install-deps
```

### Building the Testbench

```bash
# Navigate to testbench directory
cd /home/liangmx/maze/testbench

# Build and run tests
./build_tests.sh --run

# Or use make directly
cd cpp
make all
make run
```

### Basic Usage

```bash
# Quick test (no VCD, minimal output)
make test

# Debug test with VCD waveform
make debug

# Run for specific node position
make run_node HP=3 VP=2

# Run full regression suite
make regression
```

## Test Categories

### 1. Basic Functionality Tests

**Purpose**: Validate fundamental packet routing operations

**Test Cases**:
- Unicast routing to all directions (East, West, North, South)
- Local delivery (source = target)
- X-multicast (same X coordinate)
- Y-multicast (same Y coordinate)
- Broadcast (all nodes)
- Mixed traffic patterns
- Edge cases (boundary coordinates, extreme values)

**Expected Results**:
- Correct packet routing with expected latency (4-6 cycles)
- Proper interface operation (A/B/C interfaces)
- Data integrity preservation
- No packet loss under normal conditions

### 2. QoS Arbitration Tests

**Purpose**: Verify quality-of-service priority enforcement

**Test Cases**:
- High vs low priority packet arbitration
- Mixed priority scenarios
- Arbitration fairness within same priority level
- Starvation prevention for low priority traffic

**Expected Results**:
- High QoS packets receive absolute priority
- Fair arbitration within same QoS level
- No indefinite starvation of any traffic class

### 3. Fault Tolerance Tests

**Purpose**: Validate routing around failed nodes

**Test Cases**:
- Single node failure scenarios
- Route avoidance verification
- Graceful degradation when alternative paths exist
- Multiple fault configuration testing

**Expected Results**:
- Automatic rerouting around faulted nodes
- Correct intermediate node selection
- Graceful handling when both intermediate nodes fail

### 4. Pipeline Timing Tests

**Purpose**: Validate 4-stage pipeline operation

**Test Cases**:
- Pipeline depth verification
- Backpressure handling
- Continuous operation under load
- Ready/valid handshake timing

**Expected Results**:
- Correct pipeline timing (4 cycles base latency)
- Proper backpressure propagation
- No pipeline stalls under normal operation

### 5. Performance Tests

**Purpose**: Characterize throughput and latency

**Test Cases**:
- Maximum throughput measurement
- Sustained load testing
- Latency distribution analysis
- Resource utilization profiling

**Expected Results**:
- Throughput > 0.1 MPPS (million packets per second)
- Latency within specified bounds
- Sustained operation under high load

## File Structure

```
testbench/
├── README.md                      # This documentation
├── build_tests.sh                 # Automated build script
├── cpp/                          # C++ testbench source
│   ├── Makefile                  # Build system
│   ├── tb_node_main.cpp          # Main testbench driver
│   ├── common/                   # Shared utilities
│   │   ├── packet_generator.h/.cpp    # Packet generation
│   │   ├── test_utils.h/.cpp          # Testing utilities
│   │   └── result_validator.h         # Validation logic
│   ├── unit_tests/               # Individual test classes
│   │   ├── basic_functionality_test.h
│   │   ├── qos_arbitration_test.h
│   │   ├── fault_tolerance_test.h
│   │   └── pipeline_timing_test.h
│   └── integration_tests/        # System-level tests
│       └── performance_test.h
├── system_tests/                 # Multi-node tests (TODO)
├── reports/                      # Test results and reports
│   ├── simulation/               # Simulation reports
│   └── coverage/                 # Coverage reports
└── sim/                          # Simulation artifacts
    ├── build/                    # Build output
    ├── run/                      # Runtime files
    └── wave/                     # Waveform files
        ├── vcd/                  # VCD waveforms
        ├── fsdb/                 # FSDB waveforms
        ├── vpd/                  # VPD waveforms
        └── fst/                  # FST waveforms
```

## Command Line Options

### Main Testbench (tb_node_main)

```bash
./tb_node_main [options]

Options:
  --help, -h              Show help message
  --vcd                   Enable VCD waveform generation
  --seed <num>            Random seed (default: 12345)
  --hp <num>              Node horizontal position [0-7] (default: 3)
  --vp <num>              Node vertical position [0-7] (default: 2)
  --cycles <num>          Max simulation cycles (default: 10000)
  --verbose <0-3>         Verbosity level (default: 1)
  --no-basic              Skip basic functionality tests
  --no-qos                Skip QoS arbitration tests
  --no-fault              Skip fault tolerance tests
  --no-timing             Skip pipeline timing tests
  --no-performance        Skip performance tests
  --output <file>         Save results to file
```

### Build Script (build_tests.sh)

```bash
./build_tests.sh [options]

Options:
  -h, --help              Show help message
  -c, --clean             Clean build before compilation
  -v, --verbose           Enable verbose output
  --vcd                   Enable VCD waveform generation
  --coverage              Enable code coverage
  --debug                 Debug build (no optimization)
  --run                   Run tests after building
  --hp <num>              Node horizontal position (0-7) [default: 3]
  --vp <num>              Node vertical position (0-7) [default: 2]
  --build-dir <path>      Custom build directory
  --install-deps          Install required dependencies
  --check-deps            Check if dependencies are installed
```

### Make Targets

```bash
make [target]

Targets:
  all                     Build all testbenches
  tb_node                 Build main testbench executable
  run                     Run main testbench with VCD
  run_node                Run testbench for specific node
  test                    Run quick test (no VCD)
  debug                   Run debug test with maximum verbosity
  regression              Run full regression suite
  clean                   Remove all build artifacts
  help                    Show available targets
```

## Usage Examples

### Basic Testing

```bash
# Quick test to verify functionality
./build_tests.sh --run

# Test with VCD waveform for debugging
./build_tests.sh --debug --run --vcd

# Test specific node position
./build_tests.sh --run --hp 0 --vp 0
```

### Development and Debugging

```bash
# Debug build with maximum verbosity
make debug
./build/bin/tb_node --verbose 3 --vcd

# Build with code coverage
make coverage
./build/bin/tb_node --run

# Run specific test categories
./build/bin/tb_node --no-performance --no-fault
```

### Regression Testing

```bash
# Full regression suite
make regression

# Custom regression with specific configuration
./tb_node_main --cycles 50000 --verbose 1 --output full_regression.txt
```

## Packet Format

The MAZE network uses a 23-bit packet format:

```
[22:21] = pkt_type    // 00=Unicast, 01=X-Multicast, 10=Y-Multicast, 11=Broadcast
[20]    = pkt_qos     // 0=Low Priority, 1=High Priority
[19:14] = pkt_src     // 6-bit source coordinate [5:3]=Y, [2:0]=X
[13:8]  = pkt_tgt     // 6-bit target coordinate [5:3]=Y, [2:0]=X
[7:0]   = pkt_data    // 8-bit data payload
```

### Coordinate Mapping

- **Node ID**: `{Y[2:0], X[2:0]}` (6 bits, supports 64 nodes)
- **X Coordinate**: Horizontal position [0-7]
- **Y Coordinate**: Vertical position [0-7]
- **Node Position**: (HP, VP) parameter in node module

### Routing Types

1. **Unicast (00)**: Point-to-point routing with two-hop strategy
2. **X-Multicast (01)**: All nodes with same X coordinate
3. **Y-Multicast (10)**: All nodes with same Y coordinate
4. **Broadcast (11)**: All 64 nodes in network

## Expected Performance Characteristics

### Latency

- **Local Delivery**: 4 cycles (pipeline only)
- **Unicast**: 6 cycles (4 pipeline + 2 hops)
- **Multicast/Broadcast**: 5 cycles (4 pipeline + 1 hop)

### Throughput

- **Target**: >0.8 packets/cycle per node under normal load
- **Minimum**: 0.1 MPPS for acceptable performance
- **Peak**: Limited by arbitration and buffer availability

### Success Rate

- **Target**: >95% packet success rate under normal conditions
- **Minimum**: 80% for test to pass
- **Optimal**: 100% under no backpressure conditions

## Waveform Analysis

### VCD File Location

```
sim/wave/vcd/tb_node.vcd    # Main testbench VCD
```

### Key Signals to Monitor

1. **Pipeline Stages**:
   - Input buffer signals
   - Arbitration grant signals
   - Output selection signals
   - Output buffer signals

2. **Interfaces**:
   - A-interface: `pkt_i.*` (input)
   - B-interface: `pkt_o.*` (output)
   - C-interface: `pkt_con.*` (topology)

3. **Control Signals**:
   - Clock: `clk`
   - Reset: `rst_n`
   - Power gating: `pg_en`, `pg_node`

### GTKWave Command

```bash
# Install GTKWave for waveform viewing
sudo apt-get install gtkwave

# View waveform
gtkwave sim/wave/vcd/tb_node.vcd
```

## Troubleshooting

### Common Build Issues

1. **Verilator not found**:
   ```bash
   sudo apt-get install verilator
   # or download from verilator.org
   ```

2. **Missing RTL files**:
   ```bash
   # Ensure node.v exists
   ls -la rtl/src/node/node.v
   # Ensure interface files exist
   ls -la rtl/include/interfaces/
   ```

3. **Compilation errors**:
   ```bash
   # Clean and rebuild
   make clean
   make all
   ```

### Common Runtime Issues

1. **Simulation hangs**:
   - Check for deadlock in arbitration logic
   - Verify ready/valid handshake implementation
   - Enable debug verbosity for detailed tracing

2. **High error rate**:
   - Verify packet format compliance
   - Check interface signal connections
   - Review validation criteria

3. **Performance issues**:
   - Check arbitration fairness
   - Verify buffer configuration
   - Analyze timing constraints

### Debug Tips

1. **Enable maximum verbosity**:
   ```bash
   ./tb_node_main --verbose 3 --vcd
   ```

2. **Use specific test seeds**:
   ```bash
   ./tb_node_main --seed 12345 --verbose 2
   ```

3. **Focus on specific test categories**:
   ```bash
   ./tb_node_main --no-performance --no-fault
   ```

## Contributing

### Adding New Tests

1. Create test class in `unit_tests/` or `integration_tests/`
2. Inherit from base test pattern
3. Implement `run_all_tests()` method
4. Add to main testbench driver
5. Update Makefile if needed

### Code Style

- Use C++11 standard
- Follow existing naming conventions
- Add comprehensive comments
- Include error handling
- Use RAII for resource management

### Testing Guidelines

- Each test should be independent
- Use deterministic seeds for reproducibility
- Include both positive and negative test cases
- Verify edge cases and boundary conditions
- Document expected behavior clearly

## References

- [MAZE Node Technical Implementation Guide](../../docs/design/Node_Technical_Implementation_Guide.md)
- [Node Design Requirements](../../docs/design/Node_design_requirements.md)
- [Test Requirements Document](../../docs/verification/Node_Module_Test_Requirements.md)
- [File Architecture Guide](../../README_FILE_STRUCTURE.md)

## Support

For questions or issues:
1. Check this README first
2. Review the test requirements document
3. Examine generated log files
4. Review VCD waveforms
5. Enable debug output for detailed analysis

---

**Last Updated**: 2025-11-09
**Version**: 1.0
**Target**: MAZE Network Node v1.0