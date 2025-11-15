# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## MAZE Network Architecture Documentation

## Overview

This document provides a comprehensive analysis of the MAZE 64-node network system implementation. The MAZE network is a high-performance on-chip interconnect that supports unicast, multicast, and broadcast communications with QoS prioritization and fault tolerance capabilities.

## System Architecture

### High-Level Architecture

The MAZE network implements a **64-node (8×8 grid) mesh topology** with the following key characteristics:

- **Network Topology**: 8×8 grid where each node connects to 4 neighbors in North, West, South, East directions
- **Non-Pipeline Architecture**: Direct routing with per-input processing and output arbitration
- **Data Path Width**: 23-bit packets (2 type + 1 QoS + 6 source + 6 target + 8 data)
- **QoS Support**: 2-level priority system (QoS=0: low, QoS=1: high)
- **Fault Tolerance**: Single node failure support with clock gating in MAZE_TOP
- **Routing Algorithm**: Fault-aware XY routing with dynamic direction selection based on node position relative to failed nodes

### Core Components

#### 1. MAZE_TOP Module
Top-level module that instantiates the entire 64-node network. See `Provided_Code/MAZE_TOP.v` for reference implementation.

#### 2. Node Module
Individual network node with direct routing architecture. Each node processes 5 inputs (4 NWSE directions + 1 A port) through individual routing units, generates 5-bit one-hot request signals for arbiters, and outputs through 5 ports (4 NWSE directions + 1 B port). Uses IRS_N buffers at both input and output ports. See `Provided_Code/node.v` for reference implementation.

#### 3. Topo Module
Manages network connectivity between nodes. See `Provided_Code/topo.v` for reference implementation.

#### 4. IRS Modules
Insertion Ring Buffer modules for node-to-node connections. See `Provided_Code/irs.v` for reference implementation.

### Interface Definitions

#### A Interface (pkt_in)
See `Provided_Code/interface_a.sv` for interface definition.

#### B Interface (pkt_out)
See `Provided_Code/interface_b.sv` for interface definition.

#### C Interface (pkt_con_if)
See `Provided_Code/interface_c.sv` for interface definition.

#### Global Parameters
See `Provided_Code/top_define.v` for global parameter definitions.

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

**故障感知XY路由算法** (详见 路由策略.md):

**基本原理**:
- 基于目标坐标(X_Destination, Y_Destination)和当前节点坐标(X_Local, Y_Local)
- 考虑故障节点位置 REGISTER (静态配置信号)
- 支持多种故障相对位置: NORMAL, N_OF_x, NE_OF_x, E_OF_x, SE_OF_x, S_OF_x, SW_OF_x, W_OF_x, NW_OF_x

**路由决策逻辑**:
1. **X方向优先**:
   - 目标在东方 (X_Destination > X_Local): 优先向东，根据故障位置选择绕行路径
   - 目标在西方 (X_Destination < X_Local): 优先向西，根据故障位置选择绕行路径

2. **Y方向次要**:
   - 目标在北方 (Y_Destination > Y_Local): 优先向北，南方故障时选择东西绕行
   - 目标在南方 (Y_Destination < Y_Local): 优先向南，北方故障时选择东西绕行

3. **本地到达**: 目标坐标与当前坐标相同时选择LOCAL输出

**容错策略**:
- 静态故障信息 REGISTER 预先配置到所有节点
- 路由算法根据与故障节点的相对位置动态调整
- 支持东、西、南、北四个主要方向及八个故障区域的位置感知

**Multicast/Broadcast**:
- X-Multicast: 所有相同X坐标的节点
- Y-Multicast: 所有相同Y坐标的节点
- Broadcast: 所有64个节点
- 多播/广播时故障节点自动排除

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
                                      C接口(NWSE) ← 拓扑网络(IRS_N) ← C接口(NWSE)
                                      ↓
外部输入 → A接口 → IRS_N缓存 → 5个独立路由单元 → 5个仲裁器 → IRS_N缓存 → B接口 → 外部输出
                                      ↓
                                   C接口(NWSE) → 拓扑网络(IRS_N) → C接口(NWSE)

节点内部详细架构:
┌─────────────────────────────────────────────────────────────────┐
│                        MAZE节点内部架构                          │
├─────────────────────────────────────────────────────────────────┤
│ 输入端口:                                                       │
│ ├─ A口 (外部输入) → IRS_N                                        │
│ ├─ C口_N (北方输入) → IRS_N                                      │
│ ├─ C口_W (西方输入) → IRS_N                                      │
│ ├─ C口_S (南方输入) → IRS_N                                      │
│ └─ C口_E (东方输入) → IRS_N                                      │
│                                                                │
│ 路由处理:                                                       │
│ ├─ 5个独立路由单元 (每个输入一个)                                │
│ │  └─ 故障感知的XY路由算法 (见路由策略.md)                       │
│ └─ 生成5个5-bit one-hot请求信号                                  │
│                                                                │
│ 输出仲裁:                                                       │
│ ├─ 5个仲裁器 (每个输出端口一个)                                  │
│ │  ├─ 仲裁器_N: 4-bit输入 → 1-bit输出                            │
│ │  ├─ 仲裁器_W: 4-bit输入 → 1-bit输出                            │
│ │  ├─ 仲裁器_S: 4-bit输入 → 1-bit输出                            │
│ │  ├─ 仲裁器_E: 4-bit输入 → 1-bit输出                            │
│ │  └─ 仲裁器_B: 4-bit输入 → 1-bit输出                            │
│                                                                │
│ 输出端口:                                                       │
│ ├─ B口 (外部输出) → IRS_N (RO_EN=1)                             │
│ ├─ C口_N (北方输出) → IRS_N (RO_EN=1)                            │
│ ├─ C口_W (西方输出) → IRS_N (RO_EN=1)                            │
│ ├─ C口_S (南方输出) → IRS_N (RO_EN=1)                            │
│ └─ C口_E (东方输出) → IRS_N (RO_EN=1)                            │
└─────────────────────────────────────────────────────────────────┘

```

### Control Flow

1. **输入缓存阶段 (IRS_N)**:
   - A接口和4个C接口(NWSE)的数据包进入各自的IRS_N缓存
   - IRS_N提供基本的流量控制和反压管理

2. **路由计算阶段 (独立路由单元)**:
   - 每个输入端口对应一个独立的路由单元
   - 基于故障感知的XY路由算法计算输出方向
   - 根据目标坐标和当前节点位置生成路由决策
   - 考虑故障节点位置，选择最优路径 (详见 路由策略.md)

3. **请求生成阶段**:
   - 5个路由单元分别生成5-bit one-hot请求信号
   - 每个信号位对应一个输出端口(N, W, S, E, B)
   - 请求信号基于路由计算结果生成

4. **仲裁阶段 (5个仲裁器)**:
   - 每个输出端口有独立的仲裁器
   - 仲裁器接收4个输入请求 (排除本地输入)
   - 基于QoS优先级进行仲裁决策
   - 高QoS数据包获得绝对优先权

5. **输出缓存阶段 (IRS_N, RO_EN=1)**:
   - 仲裁胜出的数据包进入对应输出端口的IRS_N
   - IRS_N配置为只读模式 (RO_EN=1)
   - 提供到拓扑网络或外部输出的缓冲

6. **拓扑连接阶段**:
   - NWSE输出端口连接到相邻节点的对应输入端口
   - 通过IRS_N实现节点间的可靠数据传输

### Fault Tolerance Mechanism

- **时钟门控**: 故障节点接收不到时钟信号，实现功耗隔离
- **静态配置**: 故障信息 (`pg_en`, `pg_node`) 预先配置到所有节点
- **REGISTER信号**: 每个节点根据自身坐标与故障坐标计算相对位置，生成静态REGISTER信号
- **路由避障**: 基于故障感知的XY路由算法自动避开故障节点
- **多播处理**: 多播和广播时故障节点自动从目标列表中排除
- **容错区域**: 支持9种故障相对位置，包括正常状态和8个方向的故障区域

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
- ✅ **Node Architecture**: Non-pipeline direct routing framework implemented
- ✅ **IRS_N Integration**: Input/output buffer modules integrated
- ✅ **Fault Tolerance**: Clock gating and REGISTER signal calculation implemented
- ⚠️ **Independent Routing Units**: 5 separate routing units need implementation
- ⚠️ **Arbiter Implementation**: 5 output arbiters need QoS logic completion
- ⚠️ **NWSE Topology**: 4-direction mesh connections need completion

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

1. **四方向网格连接**: NWSE四个方向的接口数组连接复杂性
2. **独立路由单元实现**: 5个并行路由单元的资源开销和时序优化
3. **多仲裁器协同**: 5个输出仲裁器的QoS优先级一致性和死锁避免
4. **故障感知路由**: 复杂的故障相对位置计算和路径选择逻辑
5. **时序同步**: 时钟门控、故障信息传播和数据包路由的时序协调
6. **验证复杂度**: 64节点四方向网格的状态空间爆炸问题

### Critical Design Decisions

1. **非流水线架构**: 简化节点内部设计，通过并行路由和仲裁提高吞吐量
2. **四方向网格**: NWSE四个方向连接，简化拓扑复杂度，便于故障容错
3. **独立路由单元**: 每输入独立路由计算，避免共享资源的竞争
4. **QoS仲裁**: 高QoS绝对优先权确保可预测的性能表现
5. **故障感知路由**: 基于静态故障信息的智能路由选择
6. **IRS_N缓冲**: 输入输出端口的统一缓冲机制，简化时序设计
7. **参数化设计**: 支持不同规模网络的可扩展性

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

- **网络延迟**: 1-2时钟周期 (直接路由) + 路径跳数，无流水线延迟
- **吞吐量**: 每个时钟周期每个节点可处理最多5个输入数据包 (并行路由)
- **仲裁延迟**: 1个时钟周期的QoS仲裁延迟
- **可扩展性**: 设计为64节点网络，可参数化扩展到更大规模
- **容错性能**: 单节点故障容错，自动路由重构
- **缓冲能力**: IRS_N提供输入输出缓冲，支持流量控制
- **资源效率**: 相比流水线架构，减少硬件开销和功耗

This architecture provides a solid foundation for a high-performance on-chip interconnect with advanced features like QoS prioritization, fault tolerance, and efficient direct routing capabilities.

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

**语法**: 在适当时机使用特定代理命令:
- 对于RTL验证: "为节点模块的独立路由单元创建综合测试"
- 对于架构分析: "分析当前四方向网格拓扑并优化故障感知路由"
- 对于代码审查: "审查当前node.v实现的综合问题"
- 对于测试开发: "为64节点四方向网络创建验证测试台"

**Current Project Status & Agent Priority**:
1. **关键缺口**: 独立路由单元和仲裁器实现不完整
2. **测试缺口**: 缺少四方向网格和故障感知路由的测试
3. **架构缺口**: NWSE方向的C接口连接需要完成
4. **算法缺口**: 故障感知的XY路由算法需要集成验证

**推荐代理使用序列**:
1. 首先使用**RTL验证代理**完成并测试独立路由单元和仲裁器
2. 使用**测试开发代理**创建四方向网格的综合测试基础设施
3. 应用**NoC架构专家代理**优化故障感知路由和拓扑连接
4. 启用**SystemVerilog审查代理**进行代码质量和时序验证

### 💡 Agent Selection Guidelines

- **使用RTL验证代理** 当: 处理独立路由单元、QoS仲裁器或故障容错时
- **使用测试开发代理** 当: 需要测试台、回归测试或性能测量时
- **使用NoC架构专家代理** 当: 优化四方向拓扑、故障感知路由或缓冲管理时
- **使用SystemVerilog审查代理** 当: 准备综合或时序分析时

These agents integrate seamlessly with the existing file architecture (`rtl/`, `testbench/`, `sim/`) and build infrastructure to provide comprehensive support for the MAZE network development lifecycle.
