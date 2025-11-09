# Mermaid 语法测试

请逐个复制这些代码块到Typora中测试，找到有问题的图表。

---

## 测试1: 基础图表

```mermaid
graph LR
    A[开始] --> B[结束]
```

---

## 测试2: System Architecture

```mermaid
graph TB
    subgraph "MAZE_TOP Module"
        CLK[Clock]
        N00["Node(0,0)"]
        N01["Node(0,1)"]
        TOPO[Topology Module]
    end
    CLK --> N00
    N00 --> N01
    N00 --> TOPO
```

---

## 测试3: Node Architecture (最复杂的一个)

```mermaid
graph LR
    subgraph "Node Module"
        subgraph "Stage 0"
            A_IN[A Interface]
            FAULT_DETECT[Fault Detection]
        end
        subgraph "Stage 1"
            X_ARB[X Arbiters]
            Y_ARB[Y Arbiters]
            B_ARB[B Arbiter]
        end
        subgraph "Stage 2"
            X_MUX[X Output MUX]
            Y_MUX[Y Output MUX]
        end
        subgraph "Stage 3"
            IRS_OUT[IRS Output]
            C_OUT[C Interface]
        end
    end
    A_IN --> FAULT_DETECT
    FAULT_DETECT --> X_ARB
    FAULT_DETECT --> Y_ARB
    FAULT_DETECT --> B_ARB
    X_ARB --> X_MUX
    Y_ARB --> Y_MUX
    B_ARB --> B_MUX
    X_MUX --> IRS_OUT
    Y_MUX --> IRS_OUT
    IRS_OUT --> C_OUT
```

---

## 测试4: 简化的连接图

```mermaid
graph TB
    R0C0["Node(0,0)"]
    R0C1["Node(0,1)"]
    R1C0["Node(1,0)"]

    R0C0 <--> R0C1
    R0C0 <--> R1C0
```

---

## 测试5: 带样式的图表

```mermaid
graph LR
    A[Start] --> B[End]
    style A fill:#ffcccc
    style B fill:#ccffcc
```

---

## 测试6: 复杂的故障处理图

```mermaid
graph TD
    subgraph "Fault Detection"
        PG_EN[pg_en]
        COMPARE{Compare}
        FAULT_DETECT[Fault Detected?]
        PG_EN --> COMPARE
        COMPARE --> FAULT_DETECT
    end
    subgraph "Fault Response"
        CLOCK_GATE[Clock Gating]
        ROUTE_AVOID[Route Avoidance]
        FAULT_DETECT -->|Yes| CLOCK_GATE
        FAULT_DETECT -->|Yes| ROUTE_AVOID
    end
```

---

## 调试步骤

1. **复制单个测试代码块**到Typora中
2. **查看是否报错**
3. **记录报错的测试编号**
4. **告诉我哪个测试失败了**

如果测试1-2正常，但测试3失败，问题可能在于嵌套层数过多。如果测试5失败，问题可能在于样式语法。

这样我就能精确定位问题所在！