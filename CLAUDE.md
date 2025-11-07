# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## MAZE Network Architecture Documentation

## Overview

This document provides a comprehensive analysis of the MAZE 64-node network system implementation. The MAZE network is a high-performance on-chip interconnect that supports unicast, multicast, and broadcast communications with QoS prioritization and fault tolerance capabilities.

## System Architecture

### High-Level Architecture

The MAZE network implements a **64-node (8×8 grid) mesh topology** with the following key characteristics:

- **Network Topology**: 8×8 grid where each node connects to 7 neighbors in X-direction and 7 neighbors in Y-direction
- **Pipeline Architecture**: 4-stage pipeline for packet processing
- **Data Path Width**: 23-bit packets (2 type + 1 QoS + 6 source + 6 target + 8 data)
- **QoS Support**: 2-level priority system (QoS=0: low, QoS=1: high)
- **Fault Tolerance**: Single node failure support with clock gating

### Core Components

#### 1. MAZE_TOP Module
- **Purpose**: Top-level module instantiating the entire 64-node network
- **Key Features**:
  - Parameterized 64 node instantiation with coordinate configuration
  - Clock gating for failed nodes (controlled by `pg_en` and `pg_node`)
  - Interface management between external world and internal network
- **Coordinates**: Each node configured with `HP` (horizontal position 0-7) and `VP` (vertical position 0-7)

#### 2. Node Module
- **Purpose**: Individual network node with 4-stage pipeline processing
- **Interfaces**:
  - **A Interface**: Input interface for external packets (pkt_in.mst)
  - **B Interface**: Output interface for external packets (pkt_out.mst)
  - **C Interface**: Connection interface for topology (pkt_con_if)

##### 4-Stage Pipeline Architecture

**Stage 0: Input Preprocessing & Intermediate Node Calculation**
- **Function**: Processes incoming A-interface packets
- **Key Operations**:
  - Detects unicast packets (type = 00)
  - Calculates two possible intermediate nodes: `[src_y, tgt_x]` and `[tgt_y, src_x]`
  - Performs fault detection and avoidance
  - Implements congestion-based intermediate node selection
- **Output**: Determined intermediate node and output port encoding

**Stage 1: QoS Arbitration & XY Routing**
- **Function**: Simplified directional arbitration with QoS prioritization
- **Key Operations**:
  - **X-Direction Arbiter**: Only participates if packet aims to Y-direction targets
    - Accepts inputs from A-port (when target x ≠ source x) and Y-direction C-interface inputs
    - Implements QoS-based arbitration (high QoS absolute priority)
  - **Y-Direction Arbiter**: Only participates if packet aims to X-direction targets
    - Accepts inputs from A-port (when target y ≠ source y) and X-direction C-interface inputs
    - Implements QoS-based arbitration (high QoS absolute priority)
  - Simplifies router structure by reducing cross-direction interference
- **Output**: Winner coordinates and direction identification (X or Y)

**Stage 2: Output Selection**
- **Function**: Output port selection and buffering
- **Key Operations**:
  - Maps winner coordinates to specific output ports
  - Output buffer management with backpressure support
- **Output**: Buffer-ready packets with port encoding

**Stage 3: Output Buffering**
- **Function**: Final output buffering and topology interface
- **Key Operations**:
  - Register outputs (including ready signals)
  - Connection to topology module (C-interface)
- **Output**: Buffered packets to topology network

#### 3. Topo Module
- **Purpose**: Manages network connectivity between nodes
- **Key Features**:
  - Implements 8×8 mesh connectivity rules
  - Each node connects to 7 X-direction and 7 Y-direction neighbors
  - Pure connectivity logic with no routing decisions
- **IRS Integration**: Uses IRS (Insertion Ring Buffer) modules for inter-node connections

#### 4. IRS (Insertion Ring Buffer) Modules
- **Purpose**: Provide buffering for node-to-node connections
- **Key Features**:
  - Configurable depth based on Manhattan distance: `IRS_DEEP = manhattan_distance - 1`
  - Multiple IRS types: IRS_N (general), IRS_HALF (simple buffering), IRS_LP (low power)
  - Payload width: 19 bits (matching packet format)
- **Integration**: Used between connected nodes in topology

### Interface Definitions

#### A Interface (pkt_in)
```systemverilog
interface pkt_in();
    wire pkt_in_vld;      // Valid signal
    wire pkt_in_qos;      // QoS level (0/1)
    wire [1:0] pkt_in_type;  // Packet type
    wire [5:0] pkt_in_src;   // Source node ID
    wire [5:0] pkt_in_tgt;   // Target node ID
    wire [7:0] pkt_in_data;  // Data payload
    wire pkt_in_rdy;      // Ready signal
endinterface
```

#### B Interface (pkt_out)
```systemverilog
interface pkt_out();
    wire pkt_out_vld;     // Valid signal
    wire pkt_out_qos;     // QoS level (0/1)
    wire [1:0] pkt_out_type; // Packet type
    wire [5:0] pkt_out_src;  // Source node ID
    wire [5:0] pkt_out_tgt;  // Target node ID
    wire [7:0] pkt_out_data; // Data payload
    wire pkt_out_rdy;     // Ready signal
endinterface
```

#### C Interface (pkt_con_if)
```systemverilog
interface pkt_con_if();
    // X-direction connections (7 ports)
    wire [6:0] x_vld, x_rdy;
    wire [6:0] x_qos;
    wire [1:0] x_type [6:0];
    wire [5:0] x_src [6:0];
    wire [5:0] x_tgt [6:0];
    wire [7:0] x_data [6:0];
    // Y-direction connections (7 ports)
    wire [6:0] y_vld, y_rdy;
    wire [6:0] y_qos;
    wire [1:0] y_type [6:0];
    wire [5:0] y_src [6:0];
    wire [5:0] y_tgt [6:0];
    wire [7:0] y_data [6:0];
endinterface
```

### Packet Format and Routing

#### Packet Structure
```
[1:0] pkt_type    // 00=Unicast, 01=X-Multicast, 10=Y-Multicast, 11=Broadcast
[0]   pkt_qos     // 0=Low Priority, 1=High Priority
[5:3] src_y       // Source node Y coordinate
[2:0] src_x       // Source node X coordinate
[5:3] tgt_y       // Target node Y coordinate
[2:0] tgt_x       // Target node X coordinate
[7:0] pkt_data    // Data payload
```

#### Routing Algorithm

**Unicast Routing (Two-Hop Strategy)**:
- Source → Intermediate Node → Destination
- Intermediate nodes: `[src_y, tgt_x]` and `[tgt_y, src_x]`
- Selection criteria: fault avoidance, then congestion avoidance

**Multicast/Broadcast**:
- X-Multicast: All nodes with same X coordinate
- Y-Multicast: All nodes with same Y coordinate  
- Broadcast: All 64 nodes

## Build and Compilation Commands

### Verilator Compilation

For Verilator-based verification and simulation:

```bash
# Build the MAZE_TOP module
verilator --top-module MAZE_TOP \
  --cc -f rtl.filelist \
  -Wno-fatal \
  --CFLAGS "-std=c++11" \
  --Mdir obj_dir

# Make the simulation executable
cd obj_dir
make -f VMAZE_TOP.mk
```

### Simulation Commands

```bash
# Run simulation with basic test
./VMAZE_TOP

# Run with specific test cases
./VMAZE_TOP +TEST_CASE=unicast_4node
./VMAZE_TOP +TEST_CASE=qos_priority
./VMAZE_TOP +TEST_CASE=fault_tolerance
```

### Compilation Parameters

- **Global Parameters** (top_define.v):
  - `QOS_W = 1`: QoS width
  - `ID_W = 6`: Node ID width (supports 64 nodes)
  - `TGTID_W = 6`: Target ID width
  - `SRCID_W = 6`: Source ID width
  - `TYPE_W = 2`: Packet type width
  - `FLIT_W = 8`: Data width

## Key Component Relationships

### Data Flow Architecture

```
                                      C Interface ← Topology (IRS) ← C Interface
                                      ↓                                      
External Input → A Interface → Stage 0 → Stage 1 → Stage 2 → Stage 3 → B Interface → External Output
                                                                     ↓ 
                                                                       C Interface → Topology (IRS) → C Interface

```

### Control Flow

1. **Input Stage (A Interface)**:
   - Packet validation and type detection
   - Intermediate node calculation for unicast
   - Fault node checking and avoidance

2. **Arbitration Stage (Stage 1)**:
   - QoS-based arbitration between multiple inputs
   - XY routing decision logic
   - Winner selection based on priority

3. **Output Stage (Stage 2-3)**:
   - Output port selection and buffering
   - Backpressure management
   - Topology interface connection

### Fault Tolerance Mechanism

- **Clock Gating**: Failed nodes receive no clock signal
- **Static Configuration**: Fault info propagated to all nodes (`pg_en`, `pg_node`)
- **Route Avoidance**: Routing algorithms avoid failed nodes
- **Multicast Handling**: Failed nodes excluded from multicast outputs

## Development Workflow Information

### Module Development Hierarchy

1. **Foundation Layer**:
   - Interface definitions (A, B, C interfaces)
   - Global parameter definitions
   - IRS module library

2. **Core Logic Layer**:
   - Node module (4-stage pipeline)
   - Topo module (connectivity logic)
   - IRS integration

3. **System Integration Layer**:
   - MAZE_TOP module (64-node instantiation)
   - Clock gating and fault handling
   - Interface aggregation

### Verification Strategy

#### Current Testing Status
- ✅ **Interface Definitions**: Complete A/B/C interface implementations
- ✅ **Pipeline Framework**: 4-stage pipeline structure implemented
- ✅ **Unicast Logic**: Stage 0 intermediate node calculation working
- ⚠️ **Arbitration Logic**: Stage 1 QoS arbitration needs completion
- ⚠️ **Topology Integration**: Full C-interface connections pending
- ✅ **Fault Tolerance**: Clock gating implemented

#### Recommended Test Development

1. **Unit Testing**:
   ```bash
   # Individual node testing
   verilator --top-module node --cc node.v interface_*.sv top_define.v -CFLAGS "-std=c++11"
   ```

2. **Integration Testing**:
   ```bash
   # Small network testing (4x4 grid)
   verilator --top-module MAZE_TOP --cc MAZE_TOP.v node.v topo.v irs.v interface_*.sv top_define.v -CFLAGS "-std=c++11"
   ```

3. **System Testing**:
   ```bash
   # Full 64-node network
   verilator --top-module MAZE_TOP --cc maze_impl/* -CFLAGS "-std=c++11"
   ```

### Known Implementation Challenges

1. **Complex Interface Arrays**: Large-scale interface connections between nodes and topology
2. **IRS Depth Configuration**: Dynamic Manhattan distance calculation for IRS depth
3. **Multi-Input Arbitration**: Efficient QoS arbitration for multiple input sources
4. **Timing Synchronization**: Proper clock gating and fault propagation timing
5. **State Space Explosion**: 64-node network verification complexity

### Critical Design Decisions

1. **Two-Hop Routing**: Simplifies individual node complexity but increases latency
2. **QoS Arbitration**: High QoS absolute priority ensures predictable performance
3. **Clock Gating**: Simple but effective fault isolation mechanism
4. **Parameterized Design**: Enables easy scaling and modification

## File Architecture System

The MAZE project uses a structured file architecture to support systematic development and verification. See `README_FILE_STRUCTURE.md` for detailed documentation.

### 🔒 Immutable Files (DO NOT MODIFY)

**Location**: `Provided_Code/`
- All original reference files are preserved here
- Never modify these files directly
- Use as reference when working with modifiable RTL

### ✅ Modifiable RTL Code

**Location**: `rtl/`
- **Interfaces**: `rtl/include/interfaces/` - A/B/C interface definitions
- **Global Defines**: `rtl/include/global_defines/` - Project-wide parameters
- **Source Code**: `rtl/src/` - Core RTL implementations organized by module
- **Libraries**: `rtl/lib/irs/` - IRS and other third-party IP

### ✅ Test Environment

**Location**: `testbench/`
- **Unit Tests**: `testbench/src/unit_tests/` - Individual module testing
- **Integration Tests**: `testbench/src/integration_tests/` - Multi-module testing
- **System Tests**: `testbench/src/system_tests/` - Full network verification
- **C++ Tests**: `testbench/cpp/` - Verilator-based C++ testbenches

### 🗂️ Temporary Files

**Location**: `sim/`
- **Build Artifacts**: `sim/build/obj_dir/` - Verilator generated files
- **Runtime Files**: `sim/run/temp/` - Temporary simulation data
- **Waveform Files**: `sim/wave/` - Organized by format (vcd, fsdb, vpd, fst)

### 📄 Reports and Documentation

**Location**: `reports/` and `docs/`
- **Simulation Reports**: `reports/simulation/` - Test results and analysis
- **Coverage Reports**: `reports/coverage/` - Code coverage analysis
- **Design Docs**: `docs/design/` - Design specifications
- **Verification Docs**: `docs/verification/` - Verification plans and results

### Current Working Directory Structure

```
maze/
├── rtl/                        # ✅ Main RTL development
│   ├── include/
│   │   ├── interfaces/         # A/B/C interface definitions
│   │   └── global_defines/     # Global parameters
│   ├── src/
│   │   ├── node/node.v         # Node module (4-stage pipeline)
│   │   ├── topo/topo.v         # Topology module
│   │   └── system/MAZE_TOP.v   # Top-level 64-node module
│   └── lib/irs/irs.v          # IRS library
├── testbench/                  # ✅ Test environment
├── sim/                       # 🗂️ Simulation files and waveforms
├── reports/                   # 📄 Analysis and coverage reports
├── docs/                      # 📚 Project documentation
├── scripts/                   # 🔧 Build and utility scripts
├── workspace/                 # 🗂️ Development workspace
├── Provided_Code/             # 🔒 Original reference files
├── maze_impl/                 # Legacy implementation (preserved)
├── MAZE_题目.md              # Original requirements
├── README_FILE_STRUCTURE.md   # File architecture guide
└── CLAUDE.md                  # This documentation
```

### Development Workflow Commands

```bash
# RTL Development (work in rtl/src/)
cd rtl/src/system/
# Edit MAZE_TOP.v or other RTL files

# Verification (create tests in testbench/)
cd testbench/src/unit_tests/
# Create testbenches here

# Build and Simulation
cd sim/build/
verilator --top-module MAZE_TOP -cc -f ../../rtl.filelist \
  -I../../rtl/include

# Waveform Analysis
ls ../sim/wave/vcd/  # Check generated waveforms
```

## Performance Characteristics

- **Network Latency**: 4 clock cycles (pipeline stages) + 2 hops for unicast
- **Throughput**: Depends on QoS arbitration and congestion levels
- **Scalability**: Designed for 64-node network, parameterizable for larger networks
- **Fault Resilience**: Single node fault tolerance with automatic routing adaptation

This architecture provides a solid foundation for a high-performance on-chip interconnect with advanced features like QoS prioritization, fault tolerance, and efficient multicast/broadcast capabilities.

## Available Agent Types for MAZE Project

This project supports several specialized agents that can assist with different aspects of development and verification:

### 🎯 High Priority Agents (Immediate Impact)

#### 1. RTL Verification Agent
**Purpose**: Comprehensive testing and verification of the 64-node network
**Capabilities**:
- Generate automated testbench environments for Verilator simulation
- Create behavioral-level tests for the 4-stage pipeline
- Implement assertion-based verification for packet routing
- Perform fault injection and tolerance testing
- Generate coverage analysis for router scenarios

**When to Use**:
- Validate incomplete Stage 1-3 pipeline implementation
- Test QoS arbitration and fault tolerance mechanisms
- Create regression tests for continuous validation

**Integration**: Works with existing build scripts (`scripts/build/build_maze.sh`) and Verilator infrastructure

#### 2. Test Development and Automation Agent
**Purpose**: Create comprehensive test infrastructure
**Capabilities**:
- Develop scalable testbenches for 64-node networks
- Create automated regression testing scripts
- Implement performance measurement and analysis tools
- Generate constraint-random test cases
- Build simulation result visualization tools

**When to Use**:
- Expand beyond current 4-node simplified testing
- Create systematic validation methodology
- Generate performance benchmarks

### 🏗️ Medium Priority Agents (Architecture Improvement)

#### 3. Network-on-Chip Architecture Specialist
**Purpose**: Analyze and optimize mesh topology and routing
**Capabilities**:
- Evaluate 8×8 mesh topology optimization
- Analyze buffer depth and arbitration strategies
- Validate inter-router communication protocols
- Optimize XY routing algorithm performance
- Identify congestion control bottlenecks

**When to Use**:
- Analyze performance bottlenecks in current implementation
- Optimize IRS module configuration for different Manhattan distances
- Suggest improvements to the simplified directional arbitration

#### 4. SystemVerilog Design Review Agent
**Purpose**: Code quality, synthesis, and timing analysis
**Capabilities**:
- Comprehensive code review for synthesis readiness
- Interface definition validation and improvement
- Pipeline stage timing analysis
- Parameterized design scalability verification
- Static timing analysis preparation

**When to Use**:
- Validate code quality before synthesis
- Identify timing violations in pipeline design
- Improve interface definitions for better standardization

### 📊 Lower Priority Agents (Long-term Enhancement)

#### 5. Performance Analysis and Optimization Agent
**Purpose**: Quantitative performance analysis
**Capabilities**:
- Analyze throughput and latency characteristics
- Identify implementation bottlenecks
- Suggest pipeline optimizations
- Evaluate buffer sizing requirements
- Provide power consumption estimates

**When to Use**:
- After basic functionality is complete
- Need performance optimization for specific workloads
- Generate detailed performance reports

#### 6. Documentation and Specification Agent
**Purpose**: Maintain comprehensive project documentation
**Capabilities**:
- Generate API documentation for interfaces
- Create architecture design documents
- Maintain implementation specifications
- Generate user guides for simulation
- Create performance benchmark documentation

**When to Use**:
- Update documentation after major changes
- Create detailed API references
- Generate user guides for team members

### 🚀 How to Use Agents

**Syntax**: Use specific agent commands when appropriate:
- For RTL verification: "Create comprehensive tests for the node module's Stage 1 QoS arbitration"
- For architecture analysis: "Analyze the current mesh topology and suggest optimizations"
- For code review: "Review the current node.v implementation for synthesis issues"
- For test development: "Create testbenches for 64-node network validation"

**Current Project Status & Agent Priority**:
1. **Critical Gap**: Stage 1-3 pipeline implementation is incomplete
2. **Testing Gap**: Limited to 4-node simplified testing
3. **Architecture Gap**: C-interface connections between nodes need completion

**Recommended Agent Usage Sequence**:
1. Start with **RTL Verification Agent** to complete and test pipeline stages
2. Use **Test Development Agent** to create comprehensive 64-node test infrastructure
3. Apply **NoC Architecture Specialist** to optimize topology and routing
4. Engage **SystemVerilog Review Agent** for code quality and timing validation

### 💡 Agent Selection Guidelines

- **Use RTL Verification Agent** when: Working on pipeline stages, QoS logic, or fault tolerance
- **Use Test Development Agent** when: Need testbenches, regression tests, or performance measurement
- **Use NoC Architecture Specialist** when: Optimizing topology, routing, or buffer management
- **Use SystemVerilog Review Agent** when: Preparing for synthesis or timing analysis

These agents integrate seamlessly with the existing file architecture (`rtl/`, `testbench/`, `sim/`) and build infrastructure to provide comprehensive support for the MAZE network development lifecycle.
