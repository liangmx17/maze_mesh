# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 🚨 关键要求摘要

**⚠️ 强制性验证环境**:
- 只能使用Verilator（禁止使用iverilog或其他仿真软件）
- 必须在verification目录下进行所有验证工作
- 修改RTL后必须执行 `make node-test-basic`

**📋 快速开始**:
```bash
cd verification
make test-quick                    # 基本路由测试
make node-test-basic              # 强制性调试步骤
```

## MAZE网络架构文档

## 概述

本文档提供MAZE 64节点网络系统实现的全面分析。MAZE网络是一个高性能的片上互连系统，支持单播、多播和广播通信，具有QoS优先级和容错能力。

## 系统架构

### 高级架构

MAZE网络实现了**64节点(8×8网格)网格拓扑**，具有以下关键特性：

- **网络拓扑**: 8×8网格，每个节点连接北、西、南、东四个邻居
- **非流水线架构**: 直接路由，每个输入独立处理和输出仲裁
- **数据通路宽度**: 23位数据包(2位类型 + 1位QoS + 6位源地址 + 6位目标地址 + 8位数据)
- **QoS支持**: 2级优先级系统(QoS=0: 低优先级, QoS=1: 高优先级)
- **容错能力**: 单节点故障支持，在MAZE_TOP中实现时钟门控
- **路由算法**: 故障感知XY路由，基于节点与故障节点的相对位置动态选择方向

### 核心组件

#### 1. MAZE_TOP模块
顶层模块，实例化整个64节点网络。当前实现位置: `rtl/MAZE_TOP.v`。

#### 2. 节点模块
具有直接路由架构的单个网络节点。每个节点处理5个输入端口：1个A端口 + 1个C接口(包含4个NWSE方向输入)。每个节点输出5个端口：1个B端口 + 1个C接口(包含4个NWSE方向输出)。**关键说明：每个节点只例化一个C接口，该接口内部包含4个输入端口和4个输出端口**。在输入和输出端口都使用IRS_N缓冲器。

**当前实现状态**: ✅ 已完成
- 非流水线直接路由架构已实现
- 5个独立路由单元已实现 (集成在node.v中)
- 5个QoS仲裁器已实现 (arbiter.v)
- IRS_N缓冲器已集成，提供寄存器功能，无需额外打拍
- 故障感知XY路由算法已实现
- 位置: `rtl/USER_DEFINE/node.v`

#### 3. 拓扑模块
管理节点间的网络连接。通过IRS_N模块连接64个节点形成8×8网格拓扑，处理边缘节点的tie-off和悬空端口。详细设计见 `docs/design/topo_architecture.md`，当前实现位置: `rtl/USER_DEFINE/topo.v`。

#### 4. IRS模块
节点间连接的插入环形缓冲器模块。当前实现位置: `rtl/irs.v`。

### 接口定义

#### A接口(pkt_in)
接口定义见 `rtl/interface_a.sv`。

#### B接口(pkt_out)
接口定义见 `rtl/interface_b.sv`。

#### C接口(pkt_con_if)
**重要说明**: 每个节点只例化**一个C接口**，该C接口内部包含：
- **4个输入端口**: C口_N (北方输入), C口_W (西方输入), C口_S (南方输入), C口_E (东方输入)
- **4个输出端口**: C口_N (北方输出), C口_W (西方输出), C口_S (南方输出), C口_E (东方输出)

接口定义见 `rtl/USER_DEFINE/interface_c.sv`。

#### 全局参数
全局参数定义见 `rtl/top_define.v`。

### 数据包格式和路由

#### 数据包结构
```
[1:0] pkt_type    // 00=单播, 01=X多播, 10=Y多播, 11=广播
[0]   pkt_qos     // 0=低优先级, 1=高优先级
[5:3] src_y       // 源节点Y坐标
[2:0] src_x       // 源节点X坐标
[5:3] tgt_y       // 目标节点Y坐标
[2:0] tgt_x       // 目标节点X坐标
[7:0] pkt_data    // 数据载荷
```

#### 路由算法

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

**多播/广播**:
- X多播: 所有相同X坐标的节点
- Y多播: 所有相同Y坐标的节点
- 广播: 所有64个节点
- 多播/广播时故障节点自动排除

## 构建和编译命令

### 验证环境工作流程

**重要**: 所有验证工作必须在verification目录下进行，严格遵循文件结构规范。

```bash
# 进入验证目录
cd verification

# 检查文件结构合规性（必须执行）
./scripts/verification/check_file_structure.sh
```

### 节点基本路由测试（P0级别）

```bash
# 快速测试中心节点(3,3)
make test-quick

# 测试特定节点
make test-node-basic NODE_X=3 NODE_Y=3

# 完整测试套件（9个典型节点位置）
make test-all

# 边缘节点测试
make test-edge

# 四角节点测试
make test-corner
```

### 完整节点验证环境

```bash
# 基础节点功能测试（强制调试步骤）
make node-test-basic

# 带波形的完整测试
make node-test-all TRACE=1

# QoS仲裁测试
make node-test-qos

# 故障容错测试
make node-test-fault

# 多播广播测试
make node-test-multicast

# 压力测试
make node-test-stress
```

### 直接使用构建脚本

```bash
# 构建基本路由测试
cd verification
./scripts/build/build_simple_test.sh verilator 3 3
cd sim/work/build && ./Vsimple_test
```

### Verilator编译规范（只能使用verilator）

```bash
# 单个模块编译
verilator --top-module node \
  --cc rtl/USER_DEFINE/node.v rtl/interface_*.sv rtl/top_define.v \
  -Wno-fatal --CFLAGS "-std=c++11" -Mdir obj_dir

# 带波形的编译
verilator --top-module node \
  --cc rtl/USER_DEFINE/node.v rtl/interface_*.sv rtl/top_define.v \
  -Wno-fatal --trace --trace-fst --CFLAGS "-std=c++11" -Mdir obj_dir

# 编译和运行
cd obj_dir && make -f Vnode.mk && ./Vnode
```

### 编译参数

- **全局参数** (top_define.v):
  - `QOS_W = 1`: QoS位宽
  - `ID_W = 6`: 节点ID位宽 (支持64个节点)
  - `TGTID_W = 6`: 目标ID位宽
  - `SRCID_W = 6`: 源ID位宽
  - `TYPE_W = 2`: 数据包类型位宽
  - `FLIT_W = 8`: 数据位宽

## 核心组件关系

### 数据流架构

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

### 控制流

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
   - IRS_N配置为寄存器输出模式 (RO_EN=1)
   - 提供到拓扑网络或外部输出的缓冲

6. **拓扑连接阶段**:
   - NWSE输出端口连接到相邻节点的对应输入端口
   - 通过IRS_N实现节点间的可靠数据传输

### 容错机制

- **时钟门控**: 故障节点接收不到时钟信号，实现功耗隔离
- **静态配置**: 故障信息 (`pg_en`, `pg_node`) 预先配置到所有节点
- **REGISTER信号**: 每个节点根据自身坐标与故障坐标计算相对位置，生成静态REGISTER信号
- **路由避障**: 基于故障感知的XY路由算法自动避开故障节点
- **多播处理**: 多播和广播时故障节点自动从目标列表中排除
- **容错区域**: 支持9种故障相对位置，包括正常状态和8个方向的故障区域

## 🔒 强制性验证环境要求

**关键原则**: MAZE项目使用严格的验证环境，**任何时候都必须强制执行**以下规范：

### 核心要求
- **只能使用verilator，而不能使用iverilog或者任意其他仿真软件**
- **必须**在verification目录下进行所有验证工作
- **必须**运行 `./scripts/verification/check_file_structure.sh` 验证合规性
- **严禁**在非标准位置创建测试文件或临时目录

### 强制性调试工作流程
每次修改任何与节点相关的RTL代码后，**必须**执行：
```bash
cd verification
make node-test-basic
```

**检查要点**:
- ✅ 接口端口信号完整性
- ✅ 初始状态检测（buffer ready=1，其他信号=0）
- ✅ 基本路由功能验证
- ✅ 编译无错误无警告
- ✅ 所有测试用例通过

### 违规后果
- 测试将被视为无效
- 代码提交将被拒绝
- 验证环境无法正常工作

## 开发工作流信息

### 模块开发层次

1. **基础层**:
   - 接口定义 (A, B, C接口)
   - 全局参数定义
   - IRS模块库

2. **核心逻辑层**:
   - 节点模块 (非流水线直接路由，已实现)
   - 拓扑模块 (连接逻辑，部分实现)
   - IRS集成 (已完成)

3. **系统集成层**:
   - MAZE_TOP模块 (64节点实例化)
   - 时钟门控和故障处理
   - 接口聚合

### 验证策略

#### 当前实现状态
- ✅ **接口定义**: 完整的A/B/C接口实现
- ✅ **节点架构**: 非流水线直接路由架构已完全实现
- ✅ **IRS_N集成**: 输入输出缓冲器模块已集成，提供寄存器功能
- ✅ **独立路由单元**: 5个独立路由单元已实现 (集成在rtl/USER_DEFINE/node.v中)
- ✅ **QoS仲裁器**: 5个输出仲裁器已实现 (rtl/USER_DEFINE/arbiter.v)
- ✅ **容错能力**: 故障感知路由和REGISTER信号计算已实现
- ⚠️ **拓扑模块**: 4方向网格连接需要完善
- ⚠️ **顶层模块**: 64节点实例化和时钟门控需要完成

#### 推荐测试开发

1. **单元测试**:
   ```bash
   # 单个节点测试
   verilator --top-module node --cc rtl/USER_DEFINE/node.v rtl/interface_*.sv rtl/top_define.v -CFLAGS "-std=c++11"
   ```

2. **集成测试**:
   ```bash
   # 小型网络测试 (4x4网格)
   verilator --top-module MAZE_TOP --cc rtl/MAZE_TOP.v rtl/USER_DEFINE/node.v rtl/USER_DEFINE/topo.v rtl/irs.v rtl/interface_*.sv rtl/top_define.v -CFLAGS "-std=c++11"
   ```

3. **系统测试**:
   ```bash
   # 完整64节点网络
   verilator --top-module MAZE_TOP --cc rtl/MAZE_TOP.v rtl/USER_DEFINE/*.v rtl/*.sv rtl/*.v -CFLAGS "-std=c++11"
   ```

### 已完成实现
1. ✅ **独立路由单元**: 5个并行路由单元已实现，包含故障感知路由算法
2. ✅ **QoS仲裁器**: 5个输出仲裁器已实现，支持高QoS绝对优先权
3. ✅ **故障感知路由**: 完整的故障相对位置计算和路径选择逻辑
4. ✅ **IRS_N集成**: 输入输出缓冲和寄存器功能已实现，无需额外打拍

### 待完成挑战
1. **拓扑连接**: NWSE四个方向的C接口网格连接实现
2. **顶层集成**: 64节点实例化和故障节点的时钟门控
3. **测试验证**: 创建完整的测试基础设施和验证用例
4. **性能优化**: 网络吞吐量和延迟特性的优化

### 关键设计决策

1. **非流水线架构**: 简化节点内部设计，通过并行路由和仲裁提高吞吐量
2. **四方向网格**: NWSE四个方向连接，简化拓扑复杂度，便于故障容错
3. **独立路由单元**: 每输入独立路由计算，避免共享资源的竞争
4. **QoS仲裁**: 高QoS绝对优先权确保可预测的性能表现
5. **故障感知路由**: 基于静态故障信息的智能路由选择
6. **IRS_N缓冲**: 输入输出端口的统一缓冲机制，简化时序设计
7. **参数化设计**: 支持不同规模网络的可扩展性

## 文件架构系统

MAZE项目使用结构化的文件架构来支持系统化的开发和验证。

### 🔒 不可变文件 (请勿修改)

**位置**: `Provided_Code/`
- 所有原始参考文件都保存在这里
- 请勿直接修改这些文件
- 在处理可修改RTL时用作参考

### ✅ 可修改RTL代码

**位置**: `rtl/`
- **接口**: `rtl/` - A/B/C接口定义 (interface_a.sv, interface_b.sv)
- **C接口**: `rtl/USER_DEFINE/` - C接口定义 (interface_c.sv)
- **全局定义**: `rtl/` - 项目全局参数 (top_define.v)
- **源代码**: `rtl/USER_DEFINE/` - 按模块组织的核心RTL实现
- **库文件**: `rtl/` - IRS模块 (irs.v)
- **顶层模块**: `rtl/` - MAZE_TOP.v
- **用户定义模块**: `rtl/USER_DEFINE/` - 包含所有核心组件

### ✅ 测试环境

**位置**: `verification/testbench/`
- **单元测试**: `verification/testbench/unit_tests/` - 单个模块测试
- **集成测试**: `verification/testbench/integration_tests/` - 多模块测试
- **系统测试**: `verification/testbench/system_tests/` - 完整网络验证
- **节点测试台**: `verification/testbench/node_testbench/` - 节点验证环境
- **C++测试**: 基于Verilator的C++测试台（只能使用verilator，而不能使用iverilog或者任意其他仿真软件）

### 🗂️ 临时文件

**位置**: `verification/sim/`
- **构建产物**: `verification/sim/work/build/` - Verilator生成的文件和可执行文件
- **运行时文件**: `verification/sim/work/run/` - 临时仿真数据
- **波形文件**: `verification/sim/wave/` - 按格式组织 (vcd, fst, fsdb, vpd)
- **工作目录**: `verification/sim/work/` - 所有临时文件（git忽略）

### 📄 报告和文档

**位置**: `reports/` 和 `docs/`
- **Verilator仿真报告**: `reports/simulation/` - 测试结果和分析
- **覆盖率报告**: `reports/coverage/` - 代码覆盖率分析
- **设计文档**: `docs/design/` - 设计规范，包括topo架构文档
- **验证文档**: `docs/verification/` - 验证计划和结果

### 当前工作目录结构

```
maze/
├── rtl/                        # ✅ 主要RTL开发
│   ├── MAZE_TOP.v              # 顶层64节点模块
│   ├── interface_a.sv          # A接口定义
│   ├── interface_b.sv          # B接口定义
│   ├── irs.v                   # IRS模块
│   ├── top_define.v            # 全局参数
│   └── USER_DEFINE/            # 用户定义模块目录
│       ├── node.v              # 节点模块
│       ├── topo.v              # 拓扑模块
│       ├── interface_c.sv      # C接口定义
│       ├── arbiter.v           # 仲裁器
│       ├── buffer_in.v          # 输入缓冲器
│       ├── buffer_in_A_ctrl.v   # 输入缓冲器A控制
│       ├── buffer_in_A_data.v   # 输入缓冲器A数据
│       ├── pre_router.v        # 预路由器
│       ├── multi_packet_gen.v  # 多数据包生成器
│       └── fault_relative_pos_detect.v  # 故障相对位置检测
├── verification/              # ✅ 完整验证环境
│   ├── sim/                   # 🗂️ Verilator仿真文件和波形
│   ├── testbench/             # ✅ 测试台代码
│   ├── scripts/               # 🔧 自动化脚本
│   ├── reports/               # 📄 验证报告
│   └── logs/                  # 📋 日志文件
├── reports/                   # 📄 分析和覆盖率报告
├── docs/                      # 📚 项目文档
├── scripts/                   # 🔧 构建和工具脚本
├── workspace/                 # 🗂️ 开发工作区
├── Provided_Code/             # 🔒 原始参考文件
├── MAZE_题目.md              # 原始需求
└── CLAUDE.md                  # 本文档
```

### 开发工作流命令

```bash
# RTL开发 (在rtl/中工作)
cd rtl/
# 编辑MAZE_TOP.v、USER_DEFINE/目录下的模块或其他RTL文件

# 验证 (必须使用标准化的verification环境)
cd verification/
# 检查文件结构合规性
./scripts/verification/check_file_structure.sh

# 构建和运行节点基本路由测试
make test-quick
# 或
./scripts/build/build_simple_test.sh verilator 3 3
cd sim/work/build && ./Vsimple_test

# 波形分析
ls sim/wave/fst/  # 检查生成的波形文件

# 强制性节点调试（每次修改RTL后必须执行）
make node-test-basic
```

### 🔒 **强制验证环境规范**

**重要**: 验证环境有严格的文件结构规范，**任何时候都必须强制执行**！

#### 核心原则
- **只能使用verilator，而不能使用iverilog或者任意其他仿真软件**
- **必须**遵守 `verification/docs/FILE_STRUCTURE_STANDARD.md` 中的所有规范
- **必须**在verification根目录运行 `./scripts/verification/check_file_structure.sh` 验证合规性
- **严禁**在非标准位置创建测试文件或临时目录

#### 标准目录结构（强制）
```
verification/                    # 验证环境根目录
├── docs/FILE_STRUCTURE_STANDARD.md  # 📋 文件结构规范（必读）
├── CLAUDE_VERIFICATION.md      # Claude验证环境专用指南
├── testbench/                  # 🧪 测试台代码
│   ├── integration_tests/node_basic_routing/  # 节点基本路由测试
│   ├── unit_tests/            # 单元测试
│   └── system_tests/          # 系统测试
├── scripts/                    # 🔧 自动化脚本
│   ├── build/                 # 构建脚本
│   ├── run/                   # 运行脚本
│   └── verification/          # 规范检查脚本
├── sim/                        # 🗂️ 仿真运行环境
│   ├── work/                  # 临时工作目录（git忽略）
│   └── waves/                 # 波形文件存储
└── reports/                    # 📊 验证报告
```

#### 验证工作流程（必须遵循）
1. **环境检查**: `./scripts/verification/check_file_structure.sh`
2. **测试执行**: `make test-quick` 或使用标准化脚本
3. **结果分析**: 查看reports/和logs/中的报告
4. **代码清理**: 保持sim/work/目录干净（自动git忽略）

#### 🔧 **强制性节点调试工作流程**
**重要**: 在修改任何与节点相关的RTL代码后，**必须**使用以下命令进行基础调试验证：

```bash
# 在verification目录下执行基础节点功能测试
cd verification
make node-test-basic
```

**调试检查要点**:
- ✅ **接口端口信息**: 验证所有interface端口信号完整性和正确性
- ✅ **初始状态检测**: 确认输入buffer ready信号=1，其他信号=0
- ✅ **数据包传输**: 验证基本路由功能正常工作
- ✅ **编译通过**: 确保没有语法错误或警告
- ✅ **测试完成**: 所有测试用例必须成功通过

**⚠️ 强制要求**:
- 每次修改node.v、interface相关文件或测试代码后，**必须**执行`make node-test-basic`
- 如果测试失败，**不得**提交代码或进行后续开发
- 所有接口信号状态异常都需要在提交前修复
- 此调试步骤是代码质量检查的强制性环节

#### 当前验证重点
- **P0级别测试**: 节点基本路由功能（N-RF-001到N-RF-005）
- **测试台位置**: `verification/testbench/node_testbench/`
- **执行位置**: `verification/sim/work/build/Vminimal_node_test`
- **文档参考**: `verification/docs/test_plans/test_point_decomposition.md`

**⚠️ 违反验证环境规范将导致验证失败！**

## 性能特征

- **网络延迟**: 1-2时钟周期 (直接路由) + 路径跳数，无流水线延迟
- **吞吐量**: 每个时钟周期每个节点可处理最多5个输入数据包 (并行路由)
- **仲裁延迟**: 1个时钟周期的QoS仲裁延迟
- **可扩展性**: 设计为64节点网络，可参数化扩展到更大规模
- **容错性能**: 单节点故障容错，自动路由重构
- **缓冲能力**: IRS_N提供输入输出缓冲，支持流量控制
- **资源效率**: 相比流水线架构，减少硬件开销和功耗

该架构为高性能片上互连提供了坚实的基础，具备QoS优先级、容错和高效直接路由等先进特性。

## MAZE项目可用的代理类型

本项目支持多种专业化代理，可在开发和验证的不同方面提供帮助：

### 🎯 高优先级代理 (立即影响)

#### 1. verilator-test-engineer (MAZE专用验证代理)
**用途**: 专门为MAZE网络芯片创建Verilator测试环境和验证用例
**能力**:
- 为MAZE节点模块创建SystemVerilog测试台
- 实现基于C++的Verilator测试框架
- 执行故障注入和容错测试
- 生成数据包路由的断言式验证
- 构建节点基本路由功能的完整测试套件

**何时使用**:
- 验证节点模块的基本路由功能(N-RF-001到N-RF-005)
- 测试QoS仲裁和容错机制
- 在verification环境下创建符合规范的测试用例

**集成**: 与verification/目录下的标准化测试环境完全集成，严格遵循文件结构规范

#### 2. RTL验证代理
**用途**: 对64节点网络进行全面测试和验证
**能力**:
- 为Verilator仿真生成自动化测试台环境
- 为4级流水线创建行为级测试
- 实现数据包路由的断言式验证
- 执行故障注入和容错测试
- 生成路由器场景的覆盖率分析

**何时使用**:
- 验证不完整的1-3级流水线实现
- 测试QoS仲裁和容错机制
- 创建持续验证的回归测试

**集成**: 与现有构建脚本(`scripts/build/build_maze.sh`)和Verilator基础设施配合工作（只能使用verilator，而不能使用iverilog或者任意其他仿真软件）

#### 3. 测试开发和自动化代理
**用途**: 创建全面的测试基础设施
**能力**:
- 为64节点网络开发可扩展的测试台
- 创建自动化回归测试脚本
- 实现性能测量和分析工具
- 生成约束随机测试用例
- 构建仿真结果可视化工具

**何时使用**:
- 扩展当前4节点的简化测试
- 创建系统化验证方法学
- 生成性能基准测试

### 🏗️ 中等优先级代理 (架构改进)

#### 4. 片上网络架构专家
**用途**: 分析和优化网格拓扑和路由
**能力**:
- 评估8×8网格拓扑优化
- 分析缓冲器深度和仲裁策略
- 验证路由器间通信协议
- 优化XY路由算法性能
- 识别拥塞控制瓶颈

**何时使用**:
- 分析当前实现中的性能瓶颈
- 针对不同曼哈顿距离优化IRS模块配置
- 建议简化方向仲裁的改进方案

#### 5. SystemVerilog设计审查代理
**用途**: 代码质量、综合和时序分析
**能力**:
- 面向综合准备的全面代码审查
- 接口定义验证和改进
- 流水线阶段时序分析
- 参数化设计可扩展性验证
- 静态时序分析准备

**何时使用**:
- 综合前验证代码质量
- 识别流水线设计中的时序违规
- 改进接口定义以获得更好的标准化

### 📊 低优先级代理 (长期增强)

#### 6. 性能分析和优化代理
**用途**: 定量性能分析
**能力**:
- 分析吞吐量和延迟特征
- 识别实现瓶颈
- 建议流水线优化
- 评估缓冲器大小需求
- 提供功耗估算

**何时使用**:
- 基本功能完成后
- 需要特定工作负载的性能优化
- 生成详细性能报告

#### 7. 文档和规范代理
**用途**: 维护全面的项目文档
**能力**:
- 为接口生成API文档
- 创建架构设计文档
- 维护实现规范
- 生成仿真用户指南
- 创建性能基准文档

**何时使用**:
- 重大更改后更新文档
- 创建详细API参考
- 为团队成员生成用户指南

### 🚀 如何使用代理

**语法**: 在适当时机使用特定代理命令:
- 对于RTL验证: "为节点模块的独立路由单元创建综合测试"
- 对于架构分析: "分析当前四方向网格拓扑并优化故障感知路由"
- 对于代码审查: "审查当前node.v实现的综合问题"
- 对于测试开发: "为64节点四方向网络创建验证测试台"

**当前项目状态和代理优先级**:
1. ✅ **已完成**: 独立路由单元和仲裁器已完全实现
2. ✅ **已完成**: 故障感知XY路由算法已集成
3. ⚠️ **待完成**: 拓扑模块的NWSE方向C接口连接
4. ⚠️ **待完成**: MAZE_TOP的64节点实例化和集成
5. ⚠️ **测试缺口**: 缺少系统级测试基础设施

**推荐代理使用序列**:
1. 使用**NoC架构专家代理**完成拓扑模块的NWSE网格连接
2. 使用**测试开发代理**创建64节点网络的验证测试台
3. 应用**RTL验证代理**进行系统级功能和性能验证
4. 启用**SystemVerilog审查代理**进行综合前代码质量检查

### 💡 代理选择指南

- **使用verilator-test-engineer代理** 当: 为MAZE节点创建Verilator测试环境、验证基本路由功能时
- **使用NoC架构专家代理** 当: 处理拓扑模块、NWSE网格连接或节点间通信时
- **使用测试开发代理** 当: 需要测试台、回归测试或系统级验证时
- **使用RTL验证代理** 当: 进行功能验证、性能测试或故障注入测试时
- **使用SystemVerilog审查代理** 当: 准备综合、时序分析或代码质量检查时

## 关键架构特性

### 已实现的核心特性
- **非流水线架构**: 2时钟周期总延迟，无流水线开销
- **并行处理**: 5个独立路由单元和5个仲裁器
- **QoS支持**: 高QoS数据包绝对优先权
- **故障容错**: 9种故障相对位置的智能路由
- **IRS_N集成**: 内置寄存器功能，无需额外打拍

### 开发重点
1. **拓扑模块完成**: 实现8×8网格的C接口连接
2. **系统集成**: 完成MAZE_TOP的64节点实例化
3. **测试基础设施**: 创建系统级验证环境
4. **性能验证**: 吞吐量和延迟特性测试

这些代理与现有文件架构(`rtl/`)和构建基础设施(`scripts/build/`)无缝集成，为MAZE网络开发生命周期提供全面支持。
