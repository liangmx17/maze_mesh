# MAZE单节点验证环境文档

## 📋 目录
- [1. 概述](#1-概述)
- [2. 架构设计](#2-架构设计)
- [3. 核心组件](#3-核心组件)
- [4. 使用指南](#4-使用指南)
- [5. 测试场景](#5-测试场景)
- [6. 最佳实践](#6-最佳实践)
- [7. 故障排除](#7-故障排除)
- [8. 扩展开发](#8-扩展开发)

---

## 1. 概述

### 1.1 验证环境目标
MAZE单节点验证环境是一个专门用于测试MAZE网络节点模块的SystemVerilog验证平台。该环境专注于单个节点的功能验证，提供完整的包注入、路由、仲裁和输出验证功能。

### 1.2 核心特性
- ✅ **5端口完整覆盖**: A（外部）+ NWSE（网格）输入输出端口
- ✅ **事件驱动验证**: 自动化的包注入→检测流程
- ✅ **模块化设计**: 可重用的测试组件和测试序列
- ✅ **Verilator集成**: 支持高性能的C++仿真
- ✅ **灵活配置**: 动态节点位置和故障设置
- ✅ **完整调试**: FST波形生成和详细日志输出

### 1.3 适用场景
- 🎯 **单元测试**: 单个节点的基本路由功能验证
- 🎯 **QoS测试**: 优先级仲裁机制验证
- 🎯 **容错测试**: 故障感知路由算法验证
- 🎯 **性能测试**: 吞吐量和延迟特性分析
- 🎯 **回归测试**: 自动化测试序列执行

---

## 2. 架构设计

### 2.1 系统架构图
```
┌─────────────────────────────────────────────────────────────────┐
│                    MAZE单节点验证环境                          │
├─────────────────────────────────────────────────────────────────┤
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    │
│  │  包注入器   │────│   被测节点   │────│  包监控器   │    │
│  │ PacketInjector│    │  Node DUT   │    │PacketMonitor │    │
│  └─────────────┘    └─────────────┘    └─────────────┘    │
│         │                    │                    │         │
│         ▼                    ▼                    ▼         │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    │
│  │  事件系统   │    │  配置管理器 │    │  测试序列   │    │
│  │Event System │    │ConfigManager │    │TestSequences│    │
│  └─────────────┘    └─────────────┘    └─────────────┘    │
│                                                                │
│  ┌─────────────────────────────────────────────────────────┐  │
│  │               C++测试运行器                         │  │
│  │           test_runner.cpp                            │  │
│  └─────────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────────┘
```

### 2.2 数据流
```
包注入器 → DUT输入端口 → 节点内部路由 → 仲裁器 → DUT输出端口 → 包监控器
    ↓               ↓             ↓           ↓              ↓
触发注入事件     路由计算      QoS仲裁     输出数据      验证比对
```

### 2.3 文件结构
```
verification/
├── testbench/
│   └── node_testbench/              # 单节点测试环境
│       ├── node_test_environment.sv    # 主测试环境 ⭐
│       ├── packet_injector.sv        # 包注入器 ⭐
│       ├── packet_monitor.sv          # 包监控器 ⭐
│       ├── test_sequences.sv          # 测试序列库 ⭐
│       └── config_manager.sv          # 配置管理器 ⭐
├── cpp/
│   └── test_runner.cpp             # C++测试运行器 ⭐
├── integration_tests/
│   └── node_basic_routing/
│       ├── test_node_wrapper.sv    # 节点包装器 ⭐
│       └── simple_test.sv          # 简化测试示例
└── scripts/
    └── build_node_test.sh          # 构建脚本 ⭐
```

---

## 3. 核心组件

### 3.1 包注入器 (packet_injector.sv) ⭐

**功能**: 提供5个方向的包注入接口，支持各种包类型和QoS级别。

**主要接口**:
```systemverilog
// A端口（外部）包注入
task automatic inject_packet_A(
    input [1:0] pkt_type,     // 包类型：00单播，01列多播，10行多播，11广播
    input pkt_qos,           // QoS优先级：0低，1高
    input [5:0] src_id,      // 源节点ID
    input [5:0] tgt_id,      // 目标节点ID
    input [7:0] data,        // 数据载荷
    input integer timeout    // 超时周期（默认100）
);

// 四个网格方向包注入
task automatic inject_packet_N(...);  // 北方向
task automatic inject_packet_W(...);  // 西方向
task automatic inject_packet_S(...);  // 南方向
task automatic inject_packet_E(...);  // 东方向
```

**使用示例**:
```systemverilog
// 注入一个从节点(3,3)到节点(4,3)的单播包
inject_packet_A(2'b00, 1'b0, 6'h33, 6'h43, 8'hAA, 100);

// 注入一个高优先级多播包
inject_packet_N(2'b01, 1'b1, 6'h12, 6'h02, 8'h55, 150);
```

**特性**:
- 🔄 **自动握手**: 自动处理valid/ready握手协议
- ⏱️ **超时保护**: 可配置的注入超时机制
- 📊 **状态反馈**: 详细的注入状态和错误信息
- 🎯 **灵活配置**: 支持所有包类型和QoS级别

### 3.2 包监控器 (packet_monitor.sv) ⭐

**功能**: 监控5个输出端口，提供包检测和验证功能。

**主要接口**:
```systemverilog
// 输出包结构
typedef struct packed {
    logic valid;
    logic [1:0] pkt_type;
    logic pkt_qos;
    logic [5:0] src_id;
    logic [5:0] tgt_id;
    logic [7:0] data;
    logic [2:0] port_id;     // 0=N, 1=W, 2=S, 3=E, 4=B
    integer timestamp;
} packet_output_t;

// 等待任意输出端口的数据包
task automatic wait_for_output_packet(
    output packet_output_t detected_packet,
    input integer timeout
);

// 验证特定数据包的输出
task automatic verify_packet_output(
    input [22:0] expected_packet,     // 期望的编码数据包
    input [2:0] expected_port,        // 期望的输出端口
    output logic verification_result,
    input integer timeout
);
```

**使用示例**:
```systemverilog
packet_output_t detected_pkt;
logic verify_result;

// 等待任意输出
wait_for_output_packet(detected_pkt, 200);

// 验证特定包的输出
verify_packet_output(encode_packet(2'b00, 1'b0, 6'h33, 6'h43, 8'hAA), 3'd3, verify_result, 100);
```

**特性**:
- 👁️ **实时监控**: 持续监控所有输出端口
- 🔍 **精确匹配**: 支持精确的包内容验证
- ⏰ **时间戳记录**: 记录包输出的时间信息
- 📈 **统计分析**: 提供吞吐量和延迟统计

### 3.3 配置管理器 (config_manager.sv) ⭐

**功能**: 管理节点配置、故障设置和测试参数。

**主要接口**:
```systemverilog
class NodeConfig;
    logic [2:0] node_x, node_y;     // 节点坐标
    logic pg_en;                    // 故障使能
    logic [5:0] pg_node;            // 故障节点坐标

    function void set_position(integer x, integer y);
    function void set_fault(logic enable, integer fault_x, integer fault_y);
    function void reset_config();
endclass
```

**使用示例**:
```systemverilog
NodeConfig cfg = new();

// 设置节点位置为(3,3)
cfg.set_position(3, 3);

// 设置故障节点为(2,4)
cfg.set_fault(1'b1, 2, 4);
```

### 3.4 测试序列库 (test_sequences.sv) ⭐

**功能**: 提供预定义的测试序列，涵盖各种测试场景。

**主要测试序列**:
```systemverilog
// 基本路由测试
task automatic test_basic_routing();

// QoS仲裁测试
task automatic test_qos_arbitration();

// 故障容错测试
task automatic test_fault_tolerance();

// 多播广播测试
task automatic test_multicast_broadcast();

// 压力测试
task automatic test_stress_conditions();
```

**使用示例**:
```systemverilog
// 运行所有基本路由测试
test_basic_routing();

// 运行QoS测试
test_qos_arbitration();
```

### 3.5 主测试环境 (node_test_environment.sv) ⭐

**功能**: 集成所有组件，提供完整的测试环境。

**主要功能**:
- 🔧 **组件初始化**: 初始化所有测试组件
- 🎮 **测试控制**: 控制测试流程和执行顺序
- 📊 **结果报告**: 生成测试结果和统计信息
- 🛠️ **调试支持**: 提供详细的调试信息

---

## 4. 使用指南

### 4.1 快速开始

#### 步骤1: 环境准备
```bash
cd verification/testbench/node_testbench/

# 确保RTL文件存在
ls ../../rtl/USER_DEFINE/node.v
ls ../../rtl/interface_*.sv
```

#### 步骤2: 构建测试环境
```bash
# 使用构建脚本
./scripts/build_node_test.sh

# 或手动构建
verilator --top-module node_test_environment \
    --cc node_test_environment.sv \
    ../../rtl/USER_DEFINE/node.v \
    ../../rtl/USER_DEFINE/param.v \
    ../../rtl/interface_*.sv \
    --trace --trace-fst \
    --exe test_runner.cpp

cd obj_dir && make -f Vnode_test_environment.mk
```

#### 步骤3: 运行测试
```bash
# 运行所有测试
./obj_dir/Vnode_test_environment

# 运行特定测试
./obj_dir/Vnode_test_environment --test=basic_routing
./obj_dir/Vnode_test_environment --test=qos
./obj_dir/Vnode_test_environment --test=fault_tolerance

# 生成波形
./obj_dir/Vnode_test_environment --trace
```

### 4.2 编写自定义测试

#### 创建基本测试用例
```systemverilog
// 自定义测试示例
task automatic test_custom_scenario();
    packet_output_t detected_pkt;
    logic verify_result;

    $display("开始自定义测试场景...");

    // 测试场景：东西向路由竞争
    fork
        // 从A端口注入向东的包
        injector.inject_packet_A(2'b00, 1'b0, 6'h33, 6'h53, 8'hA1, 100);

        // 从W端口注入向东的包
        injector.inject_packet_W(2'b00, 1'b1, 6'h13, 6'h53, 8'hB2, 100);
    join

    // 验证高优先级包先输出
    monitor.verify_packet_output(
        encode_packet(2'b00, 1'b1, 6'h13, 6'h53, 8'hB2),
        3'd3, verify_result, 150
    );

    if (verify_result) begin
        $display("✓ 自定义测试通过");
    end else begin
        $display("✗ 自定义测试失败");
    end
endtask
```

#### 配置节点参数
```systemverilog
// 在测试开始前配置节点
initial begin
    // 设置节点位置
    cfg_mgr.set_position(2, 5);

    // 设置故障节点
    cfg_mgr.set_fault(1'b1, 1, 5);

    // 应用配置
    cfg_mgr.apply_config();

    // 运行测试
    test_custom_scenario();
end
```

### 4.3 事件驱动验证

#### 基本事件使用
```systemverilog
// 监控特定输入的输出
initial begin
    forever begin
        @injector.packet_injected[4];  // 等待A端口注入事件
        $display("检测到A端口包注入，开始监控输出...");

        // 等待对应的输出
        monitor.wait_for_output_packet(detected_pkt, 200);

        // 验证输出正确性
        if (detected_pkt.valid) begin
            $display("输出端口: %0d, 包内容: %h", detected_pkt.port_id, detected_pkt.data);
        end
    end
end
```

### 4.4 C++测试运行器

#### 基本使用
```cpp
#include "Vnode_test_environment.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    // 创建测试环境
    Vnode_test_environment* dut = new Vnode_test_environment;

    // 运行测试
    dut->test_mode = 1;  // 设置测试模式
    dut->reset = 0;

    // 主仿真循环
    while (!Verilated::gotFinish()) {
        dut->clk = !dut->clk;
        dut->eval();
    }

    delete dut;
    return 0;
}
```

---

## 5. 测试场景

### 5.1 基本路由测试 (N-RF-001 到 N-RF-005)

**目标**: 验证节点的基本路由功能

**测试用例**:
```systemverilog
// N-RF-001: X方向正向路由（向东）
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(4,3), 8'hA5, 100);
verify_packet_output(encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(4,3), 8'hA5), 3'd3);

// N-RF-002: X方向反向路由（向西）
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(2,3), 8'h5A, 100);
verify_packet_output(encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(2,3), 8'h5A), 3'd1);

// N-RF-003: Y方向正向路由（向北）
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,4), 8'h33, 100);
verify_packet_output(encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,4), 8'h33), 3'd0);

// N-RF-004: Y方向反向路由（向南）
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,2), 8'hCC, 100);
verify_packet_output(encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,2), 8'hCC), 3'd2);

// N-RF-005: 本地路由
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,3), 8'hFF, 100);
verify_packet_output(encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(3,3), 8'hFF), 3'd4);
```

### 5.2 QoS仲裁测试

**目标**: 验证QoS优先级仲裁机制

**测试场景**:
```systemverilog
// 高优先级包抢占低优先级包
fork
    injector.inject_packet_A(2'b00, 1'b0, 6'h10, 6'h12, 8'hA1, 50);  // 低优先级
    injector.inject_packet_W(2'b00, 1'b1, 6'h08, 6'h12, 8'hB2, 50);  // 高优先级
join

// 验证高优先级包先输出
monitor.verify_packet_output(encode_packet(2'b00, 1'b1, 6'h08, 6'h12, 8'hB2), 3'd3, result1, 100);
monitor.verify_packet_output(encode_packet(2'b00, 1'b0, 6'h10, 6'h12, 8'hA1), 3'd3, result2, 100);
```

### 5.3 故障容错测试

**目标**: 验证故障感知路由算法

**测试步骤**:
```systemverilog
// 1. 设置故障节点
cfg_mgr.set_fault(1'b1, 4, 3);  // 故障节点在(4,3)

// 2. 测试绕行路由
inject_packet_A(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(5,3), 8'hAA, 100);

// 3. 验证包选择绕行路径（向北或向南）
// 这里需要根据具体的故障感知路由算法来期望输出
```

### 5.4 多播广播测试

**目标**: 验证多播和广播功能

**测试用例**:
```systemverilog
// 行多播（相同Y坐标）
inject_packet_A(2'b10, 1'b0, calc_node_id(3,3), calc_node_id(0,3), 8'h01, 100);

// 列多播（相同X坐标）
inject_packet_A(2'b01, 1'b0, calc_node_id(3,3), calc_node_id(3,0), 8'h02, 100);

// 广播
inject_packet_A(2'b11, 1'b1, calc_node_id(3,3), calc_node_id(0,0), 8'hFF, 100);
```

---

## 6. 最佳实践

### 6.1 测试设计原则

#### 1. 模块化测试
```systemverilog
// ✅ 好的做法：创建独立的测试任务
task automatic test_single_direction(input [2:0] direction);
    // 测试单个方向的逻辑
endtask

// ❌ 避免：混合多种测试逻辑
task automatic test_everything();
    // 混乱的测试逻辑
endtask
```

#### 2. 参数化配置
```systemverilog
// ✅ 好的做法：使用参数配置
parameter TEST_X = 3;
parameter TEST_Y = 3;
parameter TIMEOUT_CYCLES = 100;

// ❌ 避免：硬编码数值
inject_packet_A(2'b00, 1'b0, 6'h33, 6'h43, 8'hAA, 100);  // 魔数
```

#### 3. 完整的错误处理
```systemverilog
// ✅ 好的做法：检查返回值
logic injection_success;
injector.inject_packet_A(..., injection_success);

if (!injection_success) begin
    $display("包注入失败，跳过验证步骤");
    return;
end

// ❌ 避免：假设总是成功
injector.inject_packet_A(...);
monitor.verify_packet_output(...);  // 可能失败但没有检查
```

### 6.2 性能优化

#### 1. 合理的超时设置
```systemverilog
// 根据测试场景调整超时
integer basic_timeout = 50;      // 基本路由测试
integer complex_timeout = 200;   // 复杂路由测试
integer stress_timeout = 1000;   // 压力测试
```

#### 2. 波形生成控制
```systemverilog
// 调试时生成波形，回归测试时关闭
initial begin
    if ($test$plusargs("GENERATE_WAVE")) begin
        $dumpfile("waveform.fst");
        $dumpvars(0, dut);
    end
end
```

### 6.3 调试技巧

#### 1. 分层调试
```systemverilog
// 使用调试级别控制输出
`define DEBUG_LEVEL 1

`ifdef DEBUG
    `if (DEBUG_LEVEL >= 1)
        $display("[DEBUG] 详细信息...");
    `endif
`endif
```

#### 2. 信号跟踪
```systemverilog
// 关键信号跟踪
always @(posedge clk) begin
    if (dut.pkt_i.pkt_in_vld && dut.pkt_i.pkt_in_rdy) begin
        $display("[TRACE] Cycle %0d: Packet injected - Type=%d, QoS=%d",
                 $time, dut.pkt_i.pkt_in_type, dut.pkt_i.pkt_in_qos);
    end
end
```

---

## 7. 故障排除

### 7.1 常见问题

#### 问题1: 编译错误
**症状**: Verilator编译失败
```
verilator: Error: Cannot find file: ../../rtl/USER_DEFINE/node.v
```

**解决方案**:
```bash
# 1. 检查文件路径
ls -la ../../rtl/USER_DEFINE/node.v

# 2. 检查工作目录
pwd

# 3. 修正相对路径或使用绝对路径
verilator --top-module node_test_environment \
    -cc /full/path/to/rtl/USER_DEFINE/node.v \
    ...
```

#### 问题2: 仿真超时
**症状**: 测试运行超时，没有输出
```
ERROR: 测试超时！
```

**解决方案**:
```systemverilog
// 1. 增加超时时间
injector.inject_packet_A(..., 500);  // 增加到500周期

// 2. 检查ready信号
if (!dut.pkt_i.pkt_in_rdy) begin
    $display("WARNING: 输入端口未就绪");
end

// 3. 检查复位状态
if (!dut.rst_n) begin
    $display("ERROR: 节点仍处于复位状态");
end
```

#### 问题3: 包验证失败
**症状**: 期望的包没有在输出端口检测到

**解决方案**:
```systemverilog
// 1. 打印实际输出
monitor.print_last_outputs();

// 2. 检查路由计算
$display("期望路由: 从(%0d,%0d)到(%0d,%0d)", src_x, src_y, tgt_x, tgt_y);
$display("期望端口: %0d", expected_port);

// 3. 验证包编码
automatic [22:0] encoded = encode_packet(type, qos, src, tgt, data);
$display("编码结果: %h", encoded);
```

#### 问题4: 事件系统不工作
**症状**: 事件驱动验证没有响应

**解决方案**:
```systemverilog
// 1. 检查事件触发
-> packet_injected[4];  // 确保事件被触发

// 2. 检查事件等待
@(packet_injected[4]);  // 确保在正确的进程中等待

// 3. 使用超时机制
fork
    begin
        @(packet_injected[4]);
        $display("事件触发成功");
    end
    begin
        #1000;
        $display("ERROR: 事件等待超时");
    end
join_any
disable fork;
```

### 7.2 调试命令

#### Verilator调试
```bash
# 启用详细输出
verilator --trace -Wno-lint -Wno-style ...

# 生成调试信息
verilator --debug

# 查看生成的C++代码
obj_dir/Vnode_test_environment.cpp
```

#### 运行时调试
```bash
# 启用波形
./obj_dir/Vnode_test_environment +trace

# 详细输出
./obj_dir/Vnode_test_environment +verbose

# 特定测试
./obj_dir/Vnode_test_environment +test_name=basic_routing
```

---

## 8. 扩展开发

### 8.1 添加新的测试组件

#### 1. 创建新组件
```systemverilog
// 新组件示例: latency_analyzer.sv
class LatencyAnalyzer;
    integer start_times[256];
    integer end_times[256];

    function void record_start(integer packet_id);
        start_times[packet_id] = $time;
    endfunction

    function void record_end(integer packet_id);
        end_times[packet_id] = $time;
    endfunction

    function integer get_latency(integer packet_id);
        return end_times[packet_id] - start_times[packet_id];
    endfunction
endclass
```

#### 2. 集成到主环境
```systemverilog
// 在node_test_environment.sv中添加
LatencyAnalyzer latency_analyzer;

initial begin
    latency_analyzer = new();
    // 初始化其他组件
end
```

### 8.2 扩展测试序列

#### 1. 创建新测试序列
```systemverilog
// test_performance.sv
task automatic test_throughput();
    integer i;
    packet_output_t pkt;
    logic result;

    $display("开始吞吐量测试...");

    // 连续注入100个包
    for (i = 0; i < 100; i++) begin
        injector.inject_packet_A(
            2'b00, 1'b0,
            calc_node_id(3,3), calc_node_id(4,3),
            8'h00 + i,
            50
        );

        // 验证每个包
        monitor.verify_packet_output(
            encode_packet(2'b00, 1'b0, calc_node_id(3,3), calc_node_id(4,3), 8'h00 + i),
            3'd3, result, 100
        );
    end
endtask
```

### 8.3 自定义断言

#### 1. 添加SVA断言
```systemverilog
// 在test_node_wrapper.sv中添加
property route_correctness;
    @(posedge clk)
    pkt_i.pkt_in_vld && pkt_i.pkt_in_rdy |=>
    ##[1:10] (pkt_o.pkt_out_vld && pkt_o.pkt_out_rdy);
endproperty

assert property (route_correctness) else
    $error("路由正确性断言失败");
```

#### 2. 功能覆盖
```systemverilog
// 覆盖率定义
covergroup port_coverage @(posedge clk);
    coverpoint pkt_i.pkt_in_type {
        bins unicast = {2'b00};
        bins col_multicast = {2'b01};
        bins row_multicast = {2'b10};
        bins broadcast = {2'b11};
    }

    coverpoint pkt_i.pkt_in_qos {
        bins low = {0};
        bins high = {1};
    }
endgroup
```

---

## 📝 总结

MAZE单节点验证环境提供了一个完整、灵活、易用的测试平台，用于验证MAZE网络节点的各项功能。通过模块化设计和事件驱动机制，用户可以快速编写和执行各种测试场景。

### 🎯 关键优势
- **易用性**: 简单的函数接口，快速上手
- **完整性**: 覆盖所有端口和功能
- **自动化**: 事件驱动的验证流程
- **可扩展性**: 模块化设计便于定制
- **调试友好**: 详细的日志和波形支持

### 🚀 快速上手
1. 克隆验证环境代码
2. 运行构建脚本生成可执行文件
3. 使用预定义测试序列验证基本功能
4. 根据需要编写自定义测试用例

### 📚 更多资源
- [MAZE网络架构文档](../../CLAUDE.md)
- [SystemVerilog验证方法学指南](../docs/verification_methodology.md)
- [故障排除指南](../docs/troubleshooting.md)

---

*最后更新: 2024年*
*文档版本: v1.0*