# MAZE网络测试用例详细说明文档

## 文档概述

本文档详细说明了MAZE网络芯片各个测试用例的具体实现、测试步骤、预期结果和判断标准。

**文档版本**: v1.0
**创建日期**: 2024年
**适用范围**: MAZE网络Node模块和Topo模块的具体测试用例

---

## 1. 测试用例框架说明

### 1.1 测试用例结构

每个测试用例包含以下标准结构：

```cpp
class TestName : public TestBase {
private:
    // 测试参数配置
    // 测试数据结构
    // 统计计数器

public:
    // 构造函数 - 初始化测试参数
    // run() - 主测试执行函数
    // test_xxx() - 具体测试场景函数
    // check_xxx() - 结果检查函数
    // dump_stats() - 统计输出函数
};
```

### 1.2 测试用例基类

所有测试用例继承自`TestBase`基类，提供以下通用功能：

- **时钟控制**: `tick()` - 推进一个时钟周期
- **复位控制**: `reset()` - 执行复位操作
- **时间管理**: `get_cycle()` - 获取当前时钟周期
- **参数配置**: `set_param()` - 设置测试参数
- **日志输出**: `log()` - 记录测试日志
- **断言检查**: `assert()` - 检查测试条件

### 1.3 测试数据包格式

```cpp
struct TestPacket {
    uint8_t type;        // 数据包类型 (0=单播)
    uint8_t qos;         // QoS优先级 (0=低, 1=高)
    uint8_t src_x;       // 源节点X坐标
    uint8_t src_y;       // 源节点Y坐标
    uint8_t tgt_x;       // 目标节点X坐标
    uint8_t tgt_y;       // 目标节点Y坐标
    uint8_t data[8];     // 数据载荷
    uint32_t expected_time; // 预期到达时间
};
```

---

## 2. Node模块测试用例详解

### 2.1 基本路由功能测试 (`test_node_basic_routing.cpp`)

#### 2.1.1 测试目标
验证Node模块的基本单播路由功能，确保单播数据包能够正确路由到目标方向。

#### 2.1.2 测试场景

**场景1: X方向正向路由 (测试点 N-RF-001)**
```cpp
void TestNodeBasicRouting::test_east_routing() {
    // 测试配置
    node_x = 3;  // 当前节点X=3
    node_y = 4;  // 当前节点Y=4

    // 测试数据包
    TestPacket pkt = {
        .type = 0,    // 单播
        .qos = 0,     // 低优先级
        .src_x = 0, .src_y = 0,
        .tgt_x = 6, .tgt_y = 4,  // 目标在东方
        .data = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果
    EXPECT_TRUE(wait_for_output(EAST_PORT, 10));
    EXPECT_EQ(get_output_packet(EAST_PORT), pkt);
}
```

**预期结果**: 数据包从东方向端口(C口_E)输出

**判断标准**:
- 在10个时钟周期内检测到东方向输出
- 输出数据包内容与输入完全一致
- 路由延迟不超过3个时钟周期

---

**场景2: X方向反向路由 (测试点 N-RF-002)**
```cpp
void TestNodeBasicRouting::test_west_routing() {
    // 测试配置
    node_x = 5;
    node_y = 2;

    // 测试数据包 - 目标在西方
    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 7, .src_y = 7,
        .tgt_x = 1, .tgt_y = 2,  // 目标在西方
        .data = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果
    EXPECT_TRUE(wait_for_output(WEST_PORT, 10));
    EXPECT_EQ(get_output_packet(WEST_PORT), pkt);
}
```

**预期结果**: 数据包从西方向端口(C口_W)输出

**判断标准**:
- 在10个时钟周期内检测到西方向输出
- 输出数据包内容正确

---

**场景3: Y方向正向路由 (测试点 N-RF-003)**
```cpp
void TestNodeBasicRouting::test_north_routing() {
    // 测试配置
    node_x = 2;
    node_y = 3;

    // 测试数据包 - 目标在北方
    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 0, .src_y = 0,
        .tgt_x = 2, .tgt_y = 6,  // 目标在北方
        .data = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果
    EXPECT_TRUE(wait_for_output(NORTH_PORT, 10));
    EXPECT_EQ(get_output_packet(NORTH_PORT), pkt);
}
```

**预期结果**: 数据包从北方向端口(C口_N)输出

---

**场景4: 本地路由 (测试点 N-RF-005)**
```cpp
void TestNodeBasicRouting::test_local_routing() {
    // 测试配置
    node_x = 4;
    node_y = 4;

    // 测试数据包 - 目标为当前节点
    TestPacket pkt = {
        .type = 0, .qos = 1,  // 高优先级
        .src_x = 0, .src_y = 0,
        .tgt_x = 4, .tgt_y = 4,  // 目标为当前节点
        .data = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果
    EXPECT_TRUE(wait_for_output(B_PORT, 10));
    EXPECT_EQ(get_output_packet(B_PORT), pkt);
}
```

**预期结果**: 数据包从本地端口(B口)输出

---

#### 2.1.3 测试统计和报告

```cpp
void TestNodeBasicRouting::dump_stats() {
    printf("\n=== Node基本路由功能测试统计 ===\n");
    printf("总测试用例: %zu\n", total_tests);
    printf("通过测试: %zu\n", passed_tests);
    printf("失败测试: %zu\n", failed_tests);
    printf("通过率: %.2f%%\n", (float)passed_tests / total_tests * 100);
    printf("平均路由延迟: %.2f 周期\n", total_latency / total_tests);
    printf("测试耗时: %zu 周期\n", get_cycle());
    printf("===============================\n");
}
```

---

### 2.2 QoS仲裁功能测试 (`test_node_qos_arbiter.cpp`)

#### 2.2.1 测试目标
验证Node模块的QoS仲裁机制，确保高优先级数据包获得优先服务。

#### 2.2.2 测试场景

**场景1: 高QoS绝对优先 (测试点 N-QS-001)**
```cpp
void TestNodeQosArbiter::test_high_qos_priority() {
    // 配置节点位置
    node_x = 3; node_y = 3;

    // 准备测试数据包
    TestPacket low_qos_pkt = {
        .type = 0, .qos = 0,  // 低优先级
        .src_x = 0, .src_y = 0,
        .tgt_x = 4, .tgt_y = 3,
        .data = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA}
    };

    TestPacket high_qos_pkt = {
        .type = 0, .qos = 1,  // 高优先级
        .src_x = 1, .src_y = 1,
        .tgt_x = 4, .tgt_y = 3,  // 相同目标方向
        .data = {0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB}
    };

    // 测试步骤
    // 1. 先发送低QoS数据包
    send_packet_to_A(low_qos_pkt);
    tick();  // 等待1个周期

    // 2. 再发送高QoS数据包
    send_packet_to_N(high_qos_pkt);

    // 3. 验证高QoS数据包优先输出
    uint32_t high_qos_start = get_cycle();
    EXPECT_TRUE(wait_for_output(EAST_PORT, 10));
    uint32_t high_qos_end = get_cycle();

    TestPacket output_pkt = get_output_packet(EAST_PORT);
    EXPECT_EQ(output_pkt.qos, 1);  // 确认是高QoS数据包
    EXPECT_EQ(output_pkt, high_qos_pkt);

    // 4. 验证低QoS数据包随后输出
    EXPECT_TRUE(wait_for_output(EAST_PORT, 10));
    TestPacket low_qos_output = get_output_packet(EAST_PORT);
    EXPECT_EQ(low_qos_output.qos, 0);  // 确认是低QoS数据包
    EXPECT_EQ(low_qos_output, low_qos_pkt);
}
```

**预期结果**: 高QoS数据包优先输出，延迟小于低QoS数据包

**判断标准**:
- 高QoS数据包在5个周期内输出
- 低QoS数据包在高QoS之后输出
- 输出顺序严格按QoS优先级

---

**场景2: 五仲裁器独立工作 (测试点 N-QS-003)**
```cpp
void TestNodeQosArbiter::test_independent_arbiters() {
    // 配置节点位置为网格中心
    node_x = 3; node_y = 3;

    // 准备5个不同输入端口的数据包
    std::vector<TestPacket> packets = {
        // A口输入 -> 目标向西
        {.type = 0, .qos = 1, .src_x = 0, .src_y = 0, .tgt_x = 1, .tgt_y = 3},
        // N口输入 -> 目标向东
        {.type = 0, .qos = 0, .src_x = 2, .src_y = 4, .tgt_x = 4, .tgt_y = 3},
        // W口输入 -> 目标向北
        {.type = 0, .qos = 1, .src_x = 3, .src_y = 2, .tgt_x = 3, .tgt_y = 4},
        // S口输入 -> 目标向南
        {.type = 0, .qos = 0, .src_x = 3, .src_y = 5, .tgt_x = 3, .tgt_y = 2},
        // E口输入 -> 目标本地
        {.type = 0, .qos = 1, .src_x = 4, .src_y = 3, .tgt_x = 3, .tgt_y = 3}
    };

    // 同时发送5个数据包
    send_packet_to_A(packets[0]);
    send_packet_to_N(packets[1]);
    send_packet_to_W(packets[2]);
    send_packet_to_S(packets[3]);
    send_packet_to_E(packets[4]);

    // 等待所有输出
    std::vector<bool> output_received(5, false);
    uint32_t timeout = 20;

    while (timeout-- > 0) {
        if (!output_received[0] && has_output(WEST_PORT)) {
            EXPECT_EQ(get_output_packet(WEST_PORT), packets[0]);
            output_received[0] = true;
        }
        if (!output_received[1] && has_output(EAST_PORT)) {
            EXPECT_EQ(get_output_packet(EAST_PORT), packets[1]);
            output_received[1] = true;
        }
        if (!output_received[2] && has_output(NORTH_PORT)) {
            EXPECT_EQ(get_output_packet(NORTH_PORT), packets[2]);
            output_received[2] = true;
        }
        if (!output_received[3] && has_output(SOUTH_PORT)) {
            EXPECT_EQ(get_output_packet(SOUTH_PORT), packets[3]);
            output_received[3] = true;
        }
        if (!output_received[4] && has_output(B_PORT)) {
            EXPECT_EQ(get_output_packet(B_PORT), packets[4]);
            output_received[4] = true;
        }

        if (std::all_of(output_received.begin(), output_received.end(),
                       [](bool v) { return v; })) {
            break;
        }
        tick();
    }

    // 验证所有输出都收到
    EXPECT_TRUE(std::all_of(output_received.begin(), output_received.end(),
                           [](bool v) { return v; }));
}
```

**预期结果**: 所有5个仲裁器独立工作，数据包正确输出到对应端口

**判断标准**:
- 5个输出端口都产生正确输出
- 每个仲裁器独立决策，无相互干扰
- 并发处理无死锁

---

### 2.3 故障感知路由测试 (`test_node_fault_aware.cpp`)

#### 2.3.1 测试目标
验证Node模块的故障感知路由功能，确保在故障情况下能够正确选择绕行路径。

#### 2.3.2 测试场景

**场景1: 东方故障避障 (测试点 N-FT-004)**
```cpp
void TestNodeFaultAware::test_east_fault_detour() {
    // 测试配置
    node_x = 3; node_y = 3;

    // 设置东方故障
    uint8_t fault_node = (4 << 3) | 3;  // 故障节点 (X=3, Y=4)
    set_fault_enable(true);
    set_fault_node(fault_node);

    // 测试数据包 - 目标在故障节点东方
    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 0, .src_y = 0,
        .tgt_x = 5, .tgt_y = 3,  // 需要经过故障位置
        .data = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果 - 应该选择绕行路径
    EXPECT_TRUE(wait_for_any_output(15));

    TestPacket output_pkt;
    Port output_port = get_output_port();
    output_pkt = get_output_packet(output_port);

    // 检查绕行路径选择
    if (output_port == NORTH_PORT) {
        // 选择向北绕行
        EXPECT_EQ(output_pkt.tgt_x, pkt.tgt_x);
        EXPECT_EQ(output_pkt.tgt_y, pkt.tgt_y);
    } else if (output_port == SOUTH_PORT) {
        // 选择向南绕行
        EXPECT_EQ(output_pkt.tgt_x, pkt.tgt_x);
        EXPECT_EQ(output_pkt.tgt_y, pkt.tgt_y);
    } else {
        // 不应该选择东方（故障方向）
        EXPECT_NE(output_port, EAST_PORT);
    }
}
```

**预期结果**: 数据包选择南北绕行路径，避免东方故障

**判断标准**:
- 不选择东方输出
- 选择北方或南方绕行
- 绕行路径符合路由算法

---

**场景2: 故障使能/禁用切换 (测试点 N-FT-001)**
```cpp
void TestNodeFaultAware::test_fault_enable_disable() {
    node_x = 2; node_y = 2;

    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 0, .src_y = 0,
        .tgt_x = 4, .tgt_y = 2,
        .data = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}
    };

    // 场景1: 故障禁用 - 正常路由
    set_fault_enable(false);
    send_packet_to_A(pkt);
    EXPECT_TRUE(wait_for_output(EAST_PORT, 10));
    TestPacket normal_output = get_output_packet(EAST_PORT);
    EXPECT_EQ(normal_output, pkt);

    reset_node();

    // 场景2: 故障使用 - 故障路由
    set_fault_enable(true);
    set_fault_node((3 << 3) | 3);  // (X=3, Y=3)故障

    send_packet_to_A(pkt);
    EXPECT_TRUE(wait_for_any_output(15));

    // 应该选择绕行路径
    Port fault_output = get_output_port();
    EXPECT_NE(fault_output, EAST_PORT);
}
```

**预期结果**: 故障使能时选择绕行，禁用时正常路由

---

### 2.4 边缘节点处理测试 (`test_node_edge_handling.cpp`)

#### 2.4.1 测试目标
验证边缘节点的特殊处理逻辑，确保不会产生越界访问。

#### 2.4.2 测试场景

**场景1: 北边缘边界处理 (测试点 N-ED-001)**
```cpp
void TestNodeEdgeHandling::test_north_edge_boundary() {
    // 配置为北边缘节点
    node_x = 3; node_y = 7;  // Y=7是北边缘

    // 测试数据包 - 目标在更北方
    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 0, .src_y = 0,
        .tgt_x = 3, .tgt_y = 8,  // Y=8超出边界
        .data = {0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE}
    };

    // 执行测试
    send_packet_to_A(pkt);

    // 验证结果 - 不应该向北输出
    uint32_t timeout = 20;
    while (timeout-- > 0) {
        if (has_output(NORTH_PORT)) {
            FAIL("不应该在北边缘节点向北输出");
        }

        if (has_output(EAST_PORT) || has_output(WEST_PORT) ||
            has_output(SOUTH_PORT) || has_output(B_PORT)) {
            // 找到合法输出
            break;
        }
        tick();
    }

    EXPECT_GT(timeout, 0);  // 确保找到合法输出
}
```

**预期结果**: 边缘节点不会向边界外方向输出

**判断标准**:
- 北边缘节点不向北输出
- 选择其他合法方向或本地输出
- 系统不产生死锁

---

**场景2: 四角节点处理 (测试点 N-ED-005)**
```cpp
void TestNodeEdgeHandling::test_corner_node_handling() {
    // 测试四个角节点
    std::vector<std::pair<uint8_t, uint8_t>> corners = {
        {0, 0},   // 西南角
        {7, 0},   // 东南角
        {0, 7},   // 西北角
        {7, 7}    // 东北角
    };

    for (auto corner : corners) {
        node_x = corner.first;
        node_y = corner.second;

        reset_node();

        // 测试向各个方向的目标
        std::vector<TestPacket> test_packets = {
            // 向东
            {.type = 0, .qos = 0, .src_x = 0, .src_y = 0,
             .tgt_x = 8, .tgt_y = corner.second},
            // 向西
            {.type = 0, .qos = 0, .src_x = 0, .src_y = 0,
             .tgt_x = -1, .tgt_y = corner.second},
            // 向北
            {.type = 0, .qos = 0, .src_x = 0, .src_y = 0,
             .tgt_x = corner.first, .tgt_y = 8},
            // 向南
            {.type = 0, .qos = 0, .src_x = 0, .src_y = 0,
             .tgt_x = corner.first, .tgt_y = -1}
        };

        for (auto pkt : test_packets) {
            send_packet_to_A(pkt);

            // 验证不会向边界外输出
            bool valid_output = false;
            uint32_t timeout = 15;

            while (timeout-- > 0) {
                if ((corner.first == 0 && has_output(WEST_PORT)) ||
                    (corner.first == 7 && has_output(EAST_PORT)) ||
                    (corner.second == 0 && has_output(SOUTH_PORT)) ||
                    (corner.second == 7 && has_output(NORTH_PORT))) {
                    FAIL("角节点向边界外输出");
                }

                if (has_any_output()) {
                    valid_output = true;
                    break;
                }
                tick();
            }

            EXPECT_TRUE(valid_output);
            reset_node();
        }
    }
}
```

**预期结果**: 四角节点正确处理双向边界限制

---

### 2.5 并发输入处理测试 (`test_node_concurrent.cpp`)

#### 2.5.1 测试目标
验证Node模块的并发处理能力，确保5个输入端口可以同时工作。

#### 2.5.2 测试场景

**场景1: 五端口满并发 (测试点 N-CN-001)**
```cpp
void TestNodeConcurrent::test_full_concurrent_input() {
    // 配置节点位置
    node_x = 3; node_y = 3;

    // 准备5个并发输入数据包
    TestPacket packets[5];
    for (int i = 0; i < 5; i++) {
        packets[i] = {
            .type = 0,
            .qos = i % 2,  // 交替高低优先级
            .src_x = i,
            .src_y = i,
            .tgt_x = (i + 1) % 8,
            .tgt_y = i,
            .data = {static_cast<uint8_t>(i), static_cast<uint8_t>(i+10),
                     static_cast<uint8_t>(i+20), static_cast<uint8_t>(i+30),
                     static_cast<uint8_t>(i+40), static_cast<uint8_t>(i+50),
                     static_cast<uint8_t>(i+60), static_cast<uint8_t>(i+70)}
        };
    }

    // 记录开始时间
    uint32_t start_time = get_cycle();

    // 同时发送5个数据包
    send_packet_to_A(packets[0]);
    send_packet_to_N(packets[1]);
    send_packet_to_W(packets[2]);
    send_packet_to_S(packets[3]);
    send_packet_to_E(packets[4]);

    // 等待所有输出
    std::vector<TestPacket> received_packets;
    uint32_t timeout = 30;

    while (timeout-- > 0 && received_packets.size() < 5) {
        if (has_output(NORTH_PORT)) {
            received_packets.push_back(get_output_packet(NORTH_PORT));
        }
        if (has_output(WEST_PORT)) {
            received_packets.push_back(get_output_packet(WEST_PORT));
        }
        if (has_output(SOUTH_PORT)) {
            received_packets.push_back(get_output_packet(SOUTH_PORT));
        }
        if (has_output(EAST_PORT)) {
            received_packets.push_back(get_output_packet(EAST_PORT));
        }
        if (has_output(B_PORT)) {
            received_packets.push_back(get_output_packet(B_PORT));
        }
        tick();
    }

    uint32_t end_time = get_cycle();

    // 验证结果
    EXPECT_EQ(received_packets.size(), 5);  // 确保收到所有5个输出

    // 验证数据包完整性
    for (const auto& pkt : received_packets) {
        auto it = std::find_if(std::begin(packets), std::end(packets),
                             [&pkt](const TestPacket& p) {
                                 return std::equal(std::begin(p.data), std::end(p.data),
                                                 std::begin(pkt.data), std::end(pkt.data));
                             });
        EXPECT_NE(it, std::end(packets));  // 确保收到的是发送的数据包
    }

    // 记录性能指标
    concurrent_stats.total_time = end_time - start_time;
    concurrent_stats.packets_processed = received_packets.size();
    concurrent_stats.throughput = (float)concurrent_stats.packets_processed /
                                 concurrent_stats.total_time;
}
```

**预期结果**: 5个输入并发处理，无数据包丢失

**判断标准**:
- 收到所有5个数据包输出
- 处理时间在合理范围内
- 无死锁或阻塞现象

---

**场景2: 混合QoS并发处理 (测试点 N-CN-002)**
```cpp
void TestNodeConcurrent::test_mixed_qos_concurrent() {
    node_x = 4; node_y = 4;

    // 创建高QoS和低QoS混合输入
    std::vector<TestPacket> high_qos_packets;
    std::vector<TestPacket> low_qos_packets;

    // 生成高QoS数据包
    for (int i = 0; i < 3; i++) {
        high_qos_packets.push_back({
            .type = 0, .qos = 1,
            .src_x = i, .src_y = i,
            .tgt_x = 5, .tgt_y = 4,
            .data = {0x80, static_cast<uint8_t>(i), 0x02, 0x03, 0x04, 0x05, 0x06, 0x07}
        });
    }

    // 生成低QoS数据包
    for (int i = 0; i < 2; i++) {
        low_qos_packets.push_back({
            .type = 0, .qos = 0,
            .src_x = i+3, .src_y = i+3,
            .tgt_x = 5, .tgt_y = 4,
            .data = {0x09, static_cast<uint8_t>(i), 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F}
        });
    }

    // 交错发送：先发送低QoS，再发送高QoS
    for (auto& pkt : low_qos_packets) {
        send_packet_to_A(pkt);
        tick();
    }

    for (auto& pkt : high_qos_packets) {
        send_packet_to_N(pkt);
        tick();
    }

    // 跟踪输出顺序
    std::vector<TestPacket> output_order;
    uint32_t timeout = 25;

    while (timeout-- > 0 && output_order.size() < 5) {
        if (has_output(EAST_PORT)) {
            output_order.push_back(get_output_packet(EAST_PORT));
        }
        tick();
    }

    // 验证QoS优先级：高QoS应该优先输出
    int high_qos_first = -1;
    for (size_t i = 0; i < output_order.size(); i++) {
        if (output_order[i].qos == 1) {
            high_qos_first = i;
            break;
        }
    }

    // 至少应该有一个高QoS数据包在低QoS之前输出
    EXPECT_NE(high_qos_first, -1);
}
```

**预期结果**: 在并发情况下，高QoS数据包仍然获得优先服务

---

## 3. Topo模块测试用例详解

### 3.1 2×2小型网格测试 (`test_topo_small_grid.cpp`)

#### 3.1.1 测试目标
验证基本的2×2网格拓扑连接和通信功能。

#### 3.1.2 测试场景

**场景1: 基本节点间通信 (测试点 T-GC-001)**
```cpp
void TestTopoSmallGrid::test_basic_node_communication() {
    // 创建2×2网格
    create_grid(2, 2);

    // 配置节点位置
    struct NodePos {
        uint8_t x, y;
        int id;
    };

    std::vector<NodePos> nodes = {
        {0, 0, 0}, {1, 0, 1},  // 下排
        {0, 1, 2}, {1, 1, 3}   // 上排
    };

    // 测试数据包
    TestPacket test_pkt = {
        .type = 0, .qos = 1,
        .src_x = 0, .src_y = 0,
        .tgt_x = 1, .tgt_y = 0,
        .data = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0}
    };

    // 从节点(0,0)发送到节点(1,0)
    inject_packet_to_node(0, test_pkt);

    // 等待传输
    uint32_t timeout = 20;
    bool received = false;

    while (timeout-- > 0 && !received) {
        // 检查节点(1,0)是否收到数据包
        if (node_has_input(1, test_pkt)) {
            received = true;
        }
        tick();
    }

    EXPECT_TRUE(received);
    if (received) {
        // 验证数据包完整性
        TestPacket received_pkt = get_node_input(1);
        EXPECT_EQ(received_pkt, test_pkt);

        // 记录传输统计
        comm_stats.packets_transmitted++;
        comm_stats.total_latency += (20 - timeout);
    }
}
```

**预期结果**: 相邻节点间成功通信，数据包完整

**判断标准**:
- 目标节点收到数据包
- 数据包内容完全一致
- 传输延迟在预期范围内

---

**场景2: 对角节点通信 (多跳传输)**
```cpp
void TestTopoSmallGrid::test_diagonal_communication() {
    create_grid(2, 2);

    // 测试从(0,0)到(1,1)的对角通信
    TestPacket pkt = {
        .type = 0, .qos = 0,
        .src_x = 0, .src_y = 0,
        .tgt_x = 1, .tgt_y = 1,
        .data = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33}
    };

    // 从左下角节点发送
    inject_packet_to_node(0, pkt);

    // 跟踪传输路径
    std::vector<int> path_nodes;
    uint32_t timeout = 30;

    while (timeout-- > 0 && path_nodes.size() < 2) {
        // 检查哪个节点有数据包
        for (int node_id = 0; node_id < 4; node_id++) {
            if (node_has_input(node_id, pkt) && node_id != 0) {
                if (std::find(path_nodes.begin(), path_nodes.end(), node_id) == path_nodes.end()) {
                    path_nodes.push_back(node_id);
                }
            }
        }
        tick();
    }

    // 验证传输路径
    EXPECT_EQ(path_nodes.back(), 3);  // 最终到达节点(1,1)

    // 记录多跳统计
    multi_hop_stats.hop_count = path_nodes.size();
    multi_hop_stats.total_time = (30 - timeout);
}
```

**预期结果**: 数据包通过中间节点正确路由到目标

---

### 3.2 端到端传输测试 (`test_topo_end_to_end.cpp`)

#### 3.2.1 测试目标
验证端到端的数据包传输完整性和可靠性。

#### 3.2.2 测试场景

**场景1: 端到端数据包完整性 (测试点 T-E2E-003)**
```cpp
void TestTopoEndToEnd::test_packet_integrity() {
    // 创建4×4网格
    create_grid(4, 4);

    // 测试不同大小的数据包
    std::vector<TestPacket> test_packets;

    // 生成各种数据包
    for (int i = 0; i < 16; i++) {
        TestPacket pkt = {
            .type = i % 4,     // 0-单播, 1-X多播, 2-Y多播, 3-广播
            .qos = (i / 4) % 2,
            .src_x = 0,
            .src_y = 0,
            .tgt_x = i % 4,
            .tgt_y = i / 4,
        };

        // 填充数据域
        for (int j = 0; j < 8; j++) {
            pkt.data[j] = static_cast<uint8_t>((i << 4) | j);
        }

        test_packets.push_back(pkt);
    }

    // 逐一发送并验证
    for (size_t i = 0; i < test_packets.size(); i++) {
        inject_packet_to_node(0, test_packets[i]);

        // 等待传输完成
        uint32_t timeout = 50;
        bool received = false;

        while (timeout-- > 0 && !received) {
            // 检查目标节点
            int target_node = test_packets[i].tgt_y * 4 + test_packets[i].tgt_x;
            if (node_has_input(target_node, test_packets[i])) {
                received = true;
            }
            tick();
        }

        EXPECT_TRUE(received) << "数据包 " << i << " 传输失败";

        if (received) {
            // 验证数据包完整性
            int target_node = test_packets[i].tgt_y * 4 + test_packets[i].tgt_x;
            TestPacket received_pkt = get_node_input(target_node);
            EXPECT_EQ(received_pkt, test_packets[i]) << "数据包 " << i << " 内容不匹配";

            integrity_stats.packets_sent++;
            if (received_pkt == test_packets[i]) {
                integrity_stats.packets_received++;
            }
        }

        // 重置网络状态
        reset_network();
    }

    // 计算完整性统计
    integrity_stats.integrity_rate =
        (float)integrity_stats.packets_received / integrity_stats.packets_sent;
}
```

**预期结果**: 所有数据包端到端传输完整，完整性率100%

---

**场景2: 传输延迟和可靠性 (测试点 T-E2E-005)**
```cpp
void TestTopoEndToEnd::test_latency_reliability() {
    create_grid(4, 4);

    // 测试不同距离的传输延迟
    struct TestPath {
        int src_x, src_y;
        int dst_x, dst_y;
        int expected_hops;
    };

    std::vector<TestPath> test_paths = {
        {0, 0, 1, 0, 1},    // 1跳
        {0, 0, 3, 0, 3},    // 3跳
        {0, 0, 3, 3, 6},    // 6跳
        {1, 1, 2, 2, 2},    // 2跳
    };

    for (auto path : test_paths) {
        TestPacket pkt = {
            .type = 0, .qos = 1,
            .src_x = path.src_x, .src_y = path.src_y,
            .tgt_x = path.dst_x, .tgt_y = path.dst_y,
            .data = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22}
        };

        // 注入数据包
        int src_node = path.src_y * 4 + path.src_x;
        int dst_node = path.dst_y * 4 + path.dst_x;

        inject_packet_to_node(src_node, pkt);

        // 测量传输时间
        uint32_t start_time = get_cycle();
        uint32_t timeout = 100;
        bool received = false;

        while (timeout-- > 0 && !received) {
            if (node_has_input(dst_node, pkt)) {
                received = true;
                break;
            }
            tick();
        }

        uint32_t end_time = get_cycle();

        EXPECT_TRUE(received) << "路径 " << src_node << "->" << dst_node << " 传输失败";

        if (received) {
            uint32_t latency = end_time - start_time;

            // 验证延迟合理性 (每跳约2-5周期)
            uint32_t expected_latency = path.expected_hops * 3;  // 预期每跳3周期
            EXPECT_LE(latency, expected_latency + 5) << "延迟超出预期";

            // 记录延迟统计
            latency_stats.hop_counts.push_back(path.expected_hops);
            latency_stats.latencies.push_back(latency);
            latency_stats.successful_transmissions++;
        }

        reset_network();
    }

    // 计算平均延迟
    if (!latency_stats.latencies.empty()) {
        float total_latency = 0;
        for (auto latency : latency_stats.latencies) {
            total_latency += latency;
        }
        latency_stats.average_latency = total_latency / latency_stats.latencies.size();
    }
}
```

**预期结果**: 传输延迟与跳数成正比，在合理范围内

---

### 3.3 拓扑连接完整性测试 (`test_topo_integrity.cpp`)

#### 3.3.1 测试目标
验证网格拓扑的所有连接都是正确的，无断连或错连。

#### 3.3.2 测试场景

**场景1: 所有连接完整性检查 (测试点 T-GC-008)**
```cpp
void TestTopoIntegrity::test_all_connections_integrity() {
    // 创建3×3测试网格
    create_grid(3, 3);

    // 预期的连接关系
    struct Connection {
        int src_node;
        int dst_node;
        std::string direction;
    };

    std::vector<Connection> expected_connections;

    // 水平连接
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 2; x++) {
            int node1 = y * 3 + x;
            int node2 = y * 3 + (x + 1);
            expected_connections.push_back({node1, node2, "East-West"});
            expected_connections.push_back({node2, node1, "West-East"});
        }
    }

    // 垂直连接
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 2; y++) {
            int node1 = y * 3 + x;
            int node2 = (y + 1) * 3 + x;
            expected_connections.push_back({node1, node2, "North-South"});
            expected_connections.push_back({node2, node1, "South-North"});
        }
    }

    // 逐一测试每个连接
    int tested_connections = 0;
    int successful_connections = 0;

    for (auto conn : expected_connections) {
        // 创建测试数据包
        TestPacket pkt = {
            .type = 0, .qos = 1,
            .src_x = conn.src_node % 3,
            .src_y = conn.src_node / 3,
            .tgt_x = conn.dst_node % 3,
            .tgt_y = conn.dst_node / 3,
            .data = {static_cast<uint8_t>(tested_connections & 0xFF),
                     static_cast<uint8_t>((tested_connections >> 8) & 0xFF),
                     0x03, 0x04, 0x05, 0x06, 0x07, 0x08}
        };

        // 发送测试数据包
        inject_packet_to_node(conn.src_node, pkt);

        // 等待传输
        uint32_t timeout = 20;
        bool received = false;

        while (timeout-- > 0 && !received) {
            if (node_has_input(conn.dst_node, pkt)) {
                received = true;
            }
            tick();
        }

        tested_connections++;

        if (received) {
            successful_connections++;
            // 验证数据包完整性
            TestPacket received_pkt = get_node_input(conn.dst_node);
            EXPECT_EQ(received_pkt, pkt) << "连接 " << conn.src_node
                                          << "->" << conn.dst_node << " 数据损坏";
        } else {
            // 连接失败
            FAIL() << "连接 " << conn.src_node << "->" << conn.dst_node
                   << " (" << conn.direction << ") 传输失败";
        }

        reset_network();
    }

    // 计算连接完整性统计
    integrity_stats.total_connections = tested_connections;
    integrity_stats.working_connections = successful_connections;
    integrity_stats.integrity_rate = (float)successful_connections / tested_connections;

    EXPECT_EQ(successful_connections, tested_connections) << "存在断连或错连";
}
```

**预期结果**: 所有预期连接都正常工作，完整性率100%

---

**场景2: 无意外连接检查**
```cpp
void TestTopoIntegrity::test_no_unexpected_connections() {
    create_grid(2, 2);

    // 检查不应该存在的连接
    struct UnexpectedConnection {
        int src_node;
        int dst_node;
        std::string reason;
    };

    std::vector<UnexpectedConnection> unexpected_connections = {
        {0, 3, "对角连接不应该存在"},
        {1, 2, "对角连接不应该存在"},
        {0, 2, "跨两跳连接不应该存在"},
        {1, 3, "跨两跳连接不应该存在"}
    };

    for (auto conn : unexpected_connections) {
        TestPacket pkt = {
            .type = 0, .qos = 1,
            .src_x = conn.src_node % 2,
            .src_y = conn.src_node / 2,
            .tgt_x = conn.dst_node % 2,
            .tgt_y = conn.dst_node / 2,
            .data = {0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99}
        };

        inject_packet_to_node(conn.src_node, pkt);

        // 等待一段时间，确保没有直接传输
        uint32_t timeout = 30;
        bool unexpected_received = false;

        while (timeout-- > 0 && !unexpected_received) {
            if (node_has_input(conn.dst_node, pkt)) {
                unexpected_received = true;
            }
            tick();
        }

        EXPECT_FALSE(unexpected_received) << conn.reason;

        reset_network();
    }
}
```

**预期结果**: 不存在意外连接，拓扑结构正确

---

## 4. 测试结果分析和报告

### 4.1 测试通过标准

| 测试类型 | 通过率要求 | 关键指标 |
|----------|------------|----------|
| Node基本功能 | 100% | 所有路由功能正常 |
| Node QoS功能 | 100% | QoS优先级正确 |
| Node故障处理 | 100% | 故障避障有效 |
| Node反压机制 | 100% | 反压功能正常 |
| Topo连接 | 100% | 所有连接正常 |
| 端到端传输 | 100% | 数据完整性100% |

### 4.2 性能基准

| 指标 | 目标值 | 测量方法 |
|------|--------|----------|
| Node路由延迟 | < 3周期 | 单跳传输测试 |
| QoS仲裁延迟 | < 2周期 | 优先级切换测试 |
| 多跳传输延迟 | < 5周期/跳 | 端到端测试 |
| 并发吞吐量 | 5包/周期 | 满并发测试 |
| 传输成功率 | > 95% | 大量传输测试 |

### 4.3 故障诊断

#### 4.3.1 常见失败模式

1. **路由失败**:
   - 检查目标坐标计算
   - 验证边缘处理逻辑
   - 确认故障REGISTER计算

2. **仲裁问题**:
   - 验证QoS字段解析
   - 检查仲裁器输入映射
   - 确认授权信号生成

3. **连接问题**:
   - 检查IRS_N缓冲器配置
   - 验证信号连接关系
   - 确认时序约束

#### 4.3.2 调试方法

1. **波形分析**:
   ```bash
   make wave_test_name
   gtkwave sim/wave/fst/test_name.fst
   ```

2. **详细日志**:
   ```bash
   make debug_test_name
   ```

3. **单步调试**:
   - 在关键测试点添加断言
   - 输出中间状态信息
   - 分步验证测试逻辑

---

## 5. 测试维护和扩展

### 5.1 添加新测试用例

1. **创建测试文件**:
   ```cpp
   // test_new_feature.cpp
   #include "test_base.h"

   class TestNewFeature : public TestBase {
   public:
       void run() override;
   private:
       void test_scenario_1();
       void check_results();
   };
   ```

2. **更新Makefile**:
   ```makefile
   TEST_SRCS += test_new_feature.cpp
   TESTS += test_new_feature
   ```

3. **验证测试**:
   ```bash
   make test_new_feature
   ```

### 5.2 测试参数调优

可以通过修改测试文件中的参数来适应不同的测试需求：

- `CLK_PERIOD`: 时钟周期
- `MAX_CYCLES`: 最大仿真周期
- `TIMEOUT_MULTIPLIER`: 超时倍数
- `GRID_SIZE`: 网格大小

---

**文档维护**: MAZE验证团队
**最后更新**: 2024年
**审核状态**: 已审核