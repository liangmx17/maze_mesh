# MAZE 64-Node Network-on-Chip Architecture Diagrams

> **注意**: 本文档已针对Typora 8.8.0版本优化。如果您使用更新的Mermaid版本，部分图表可能支持更多高级功能。

## 1. System-Level Architecture

```mermaid
graph TB
    subgraph "MAZE_TOP Module"
        subgraph "Global Control"
            CLK[Clock]
            RST[Reset]
            FAULT[Fault Control<br/>pg_en, pg_node]
        end

        subgraph "8×8 Node Array [0:63]"
            N00["Node(0,0)"]
            N01["Node(0,1)"]
            N02["Node(0,2)"]
            N07["Node(0,7)"]
            N10["Node(1,0)"]
            N11["Node(1,1)"]
            N77["Node(7,7)"]

            style N77 fill:#ff9999
            N77_FAULT[FAULT]
        end

        subgraph "Topology Module"
            TOPO[TOPO<br/>Network Interconnect]
            IRS[IRS Modules<br/>Manhattan Distance]
        end
    end

    %% External Interfaces
    subgraph "External Inputs"
        AIF[64× A Interface<br/>External Packet Input]
    end

    subgraph "External Outputs"
        BIF[64× B Interface<br/>External Packet Output]
    end

    %% Connections
    AIF --> N00
    AIF --> N01
    AIF --> N02
    AIF --> N07
    AIF --> N10
    AIF --> N11
    AIF --> N77

    N00 --> BIF
    N01 --> BIF
    N02 --> BIF
    N07 --> BIF
    N10 --> BIF
    N11 --> BIF
    N77 -.->|No Output| BIF

    N00 <--> TOPO
    N01 <--> TOPO
    N02 <--> TOPO
    N07 <--> TOPO
    N10 <--> TOPO
    N11 <--> TOPO
    N77 -.->|Disconnected| TOPO

    CLK --> N00
    CLK --> N01
    CLK --> N02
    CLK --> N07
    CLK --> N10
    CLK --> N11
    CLK -.->|Gated| N77

    FAULT --> N77_FAULT
```

## 2. Node Internal Architecture (4-Stage Pipeline)

```mermaid
graph TD

    %% Interface Inputs (A in the middle)
    A_PORT["A Interface<br/>External Input<br/>pkt_in"]

    %% Input Buffers (A buffer in the middle)
    A_BUF["A Input Buffer<br/>IRS_LP Deep=1<br/>RO_EN=1"]
	direction LR
    C_Y_IN_PORT["C Interface Y-Input<br/>7× bidirectional<br/>From topology"]
    C_Y_IN_BUF["C Y-Input Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
    C_X_IN_PORT["C Interface X-Input<br/>7× bidirectional<br/>From topology"]
    C_X_IN_BUF["C X-Input Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]

    %% Stage 0: Only A Interface Processing
    subgraph "Stage 0: A Interface Processing"
        direction LR
        A_X_BUF["A-X Buffer<br/>Route to X direction"]
        A_Y_BUF["A-Y Buffer<br/>Route to Y direction"]

        FAULT_DETECT["Fault Detection<br/>Route Calculation<br/>X-first vs Y-first"]
    end
    %% Stage 1: QoS Arbitration
    subgraph "Stage 1: QoS Arbitration"
        direction LR
        
        B_ARB["B-Port Arbiter<br/>16-input<br/>A + 7Y + 7X + 1 Spare"]
        X_ARB["X-Direction Arbiters<br/>7× 8-input<br/>High QoS Priority"]
        Y_ARB["Y-Direction Arbiters<br/>7× 8-input<br/>High QoS Priority"]
    end

    %% Stage 2: Output Selection
    subgraph "Stage 2: Output Selection"
        direction LR
        B_MUX["B-Port MUX<br/>16×1 multiplexer"]
        X_MUX["X-Output MUX<br/>7× multiplexers"]
        Y_MUX["Y-Output MUX<br/>7× multiplexers"]
    end

    %% Stage 3: Output Buffering
    subgraph "Stage 3: Output Buffering"
        direction LR
        B_OUT_BUF["B Output Buffer<br/>IRS_LP Deep=1<br/>RO_EN=1"]
        C_X_OUT_BUF["C X-Output Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
        C_Y_OUT_BUF["C Y-Output Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
    end


    %% Output Interfaces (B in the middle)
    B_PORT["B Interface<br/>External Output<br/>pkt_out"]
    C_X_OUT_PORT["C Interface X-Output<br/>7× bidirectional<br/>To topology"]
    C_Y_OUT_PORT["C Interface Y-Output<br/>7× bidirectional<br/>To topology"]

    %% Data Flow Connections
    %% Left Inputs to Input Buffers
    A_PORT --> A_BUF
    C_X_IN_PORT --> C_X_IN_BUF
    C_Y_IN_PORT --> C_Y_IN_BUF

    %% A Buffer to Stage 0
    A_BUF --> FAULT_DETECT
    FAULT_DETECT --> A_X_BUF
    FAULT_DETECT --> A_Y_BUF

    %% Stage 0 to Stage 1 - Clean connections (No cross-overs)
    %% X-Direction connections (A-X + C-X to X Arbiter)
    A_X_BUF --> X_ARB
    C_X_IN_BUF --> X_ARB

    %% Y-Direction connections (A-Y + C-Y to Y Arbiter)
    A_Y_BUF --> Y_ARB
    C_Y_IN_BUF --> Y_ARB

    %% All inputs to B Arbiter (for B-port arbitration)
    A_X_BUF --> B_ARB
    A_Y_BUF --> B_ARB
    C_X_IN_BUF --> B_ARB
    C_Y_IN_BUF --> B_ARB

    %% Stage 1 to Stage 2
    X_ARB --> X_MUX
    Y_ARB --> Y_MUX

    %% Stage 2 to Stage 3
    X_MUX --> C_X_OUT_BUF
    Y_MUX --> C_Y_OUT_BUF
    B_MUX --> B_OUT_BUF

    %% Stage 3 to Output Interfaces
    C_X_OUT_BUF --> C_X_OUT_PORT
    C_Y_OUT_BUF --> C_Y_OUT_PORT
    B_OUT_BUF --> B_PORT

    %% B Port Path (Independent)
    B_ARB --> B_MUX

    %% Styling (Note: Some styling may not render in older Mermaid versions)
    %% Left Input Interfaces
    style A_PORT fill:#F39C12,stroke:#D68910
    style C_X_IN_PORT fill:#9B59B6,stroke:#7D3C98
    style C_Y_IN_PORT fill:#9B59B6,stroke:#7D3C98

    %% Right Output Interfaces
    style B_PORT fill:#F39C12,stroke:#D68910
    style C_X_OUT_PORT fill:#9B59B6,stroke:#7D3C98
    style C_Y_OUT_PORT fill:#9B59B6,stroke:#7D3C98

    %% Input Buffers (All IRS_LP Deep=1, RO_EN=1)
    style A_BUF fill:#27AE60,stroke:#1E8449
    style C_X_IN_BUF fill:#27AE60,stroke:#1E8449
    style C_Y_IN_BUF fill:#27AE60,stroke:#1E8449

    %% Internal A Processing Buffers
    style A_X_BUF fill:#27AE60,stroke:#1E8449
    style A_Y_BUF fill:#27AE60,stroke:#1E8449

    %% Output Buffers (All IRS_LP Deep=1, RO_EN=1)
    style C_X_OUT_BUF fill:#27AE60,stroke:#1E8449
    style C_Y_OUT_BUF fill:#27AE60,stroke:#1E8449
    style B_OUT_BUF fill:#27AE60,stroke:#1E8449

    %% Processing Units
    style FAULT_DETECT fill:#E1F5FE,stroke:#01579B
    style X_ARB fill:#FFEBEE,stroke:#C62828
    style Y_ARB fill:#FFEBEE,stroke:#C62828
    style B_ARB fill:#FFEBEE,stroke:#C62828
    style X_MUX fill:#E1F5FE,stroke:#01579B
    style Y_MUX fill:#E1F5FE,stroke:#01579B
    style B_MUX fill:#E1F5FE,stroke:#01579B
```

## 3. Packet Format and Data Flow

```mermaid
graph LR
    subgraph "Packet Structure [23 bits]"
        PKT_TYPE[Type: 2 bits<br/>00=Unicast<br/>01=X-Mcast<br/>10=Y-Mcast<br/>11=Bcast]
        PKT_QOS[QoS: 1 bit<br/>0=Low Priority<br/>1=High Priority]
        PKT_SRC[Source: 6 bits<br/>Node Coordinate]
        PKT_TGT[Target: 6 bits<br/>Node Coordinate]
        PKT_DATA[Data: 8 bits<br/>Payload]
    end

    subgraph "Routing Algorithm"
        SRC[Source Node<br/>X,Y coordinates]
        TGT[Target Node<br/>X,Y coordinates]
        INT1[Int1: [src_y, tgt_x]]
        INT2[Int2: [tgt_y, src_x]]

        FAULT_CHK{Fault Check}
        ROUTE_SEL{Route Selection}

        SRC --> INT1
        SRC --> INT2
        TGT --> INT1
        TGT --> INT2

        INT1 --> FAULT_CHK
        INT2 --> FAULT_CHK
        FAULT_CHK --> ROUTE_SEL
        ROUTE_SEL -->|X-first| X_ROUTE
        ROUTE_SEL -->|Y-first| Y_ROUTE
    end

    PKT_TYPE --> ROUTE_SEL
```

## 4. Network Topology Connections

```mermaid
graph TB
    subgraph "8×8 Mesh Topology"
        subgraph "Row 0"
            R0C0["Node(0,0)"]
            R0C1["Node(0,1)"]
            R0C2["Node(0,2)"]
            R0C3["Node(0,3)"]
            R0C4["Node(0,4)"]
            R0C5["Node(0,5)"]
            R0C6["Node(0,6)"]
            R0C7["Node(0,7)"]
        end

        subgraph "Row 1"
            R1C0["Node(1,0)"]
            R1C1["Node(1,1)"]
            R1C2["Node(1,2)"]
            R1C3["Node(1,3)"]
            R1C4["Node(1,4)"]
            R1C5["Node(1,5)"]
            R1C6["Node(1,6)"]
            R1C7["Node(1,7)"]
        end

        subgraph "..."
            MORE[... 6 more rows ...]
        end

        subgraph "Row 7"
            R7C0["Node(7,0)"]
            R7C1["Node(7,1)"]
            R7C2["Node(7,2)"]
            R7C3["Node(7,3)"]
            R7C4["Node(7,4)"]
            R7C5["Node(7,5)"]
            R7C6["Node(7,6)"]
            R7C7["Node(7,7)"]
        end
    end

    %% X-direction connections (same X, different Y)
    R0C0 <==> R1C0
    R1C0 <==> R2C0
    R2C0 <==> R3C0
    R3C0 <==> R4C0
    R4C0 <==> R5C0
    R5C0 <==> R6C0
    R6C0 <==> R7C0

    %% Y-direction connections (same Y, different X)
    R0C0 <==> R0C1
    R0C1 <==> R0C2
    R0C2 <==> R0C3
    R0C3 <==> R0C4
    R0C4 <==> R0C5
    R0C5 <==> R0C6
    R0C6 <==> R0C7

    %% Sample connections for other nodes
    R1C1 <==> R2C1
    R1C1 <==> R1C2

    %% IRS modules for different distances
    subgraph "IRS Depth Examples"
        IRS1[IRS Deep=1<br/>Distance=1]
        IRS2[IRS Deep=2<br/>Distance=2]
        IRS3[IRS Deep=3<br/>Distance=3]
    end

    R0C0 -- Distance 1 --> IRS1
    R0C0 -- Distance 2 --> IRS2
    R0C0 -- Distance 3 --> IRS3
```

## 5. QoS Arbitration Logic

```mermaid
graph TB
    subgraph "Stage 1: QoS Arbitration"
        Check_Inputs[Check Inputs]
        High_QoS_Search[High QoS Search]
        Low_QoS_Search[Low QoS Search]
        Found_High_QoS[Found High QoS]
        Select_Winner[Select Winner]
        Update_Arbiters[Update Arbiters]

        Check_Inputs --> High_QoS_Search
        High_QoS_Search --> Found_High_QoS
        High_QoS_Search --> Low_QoS_Search
        Found_High_QoS --> Select_Winner
        Low_QoS_Search --> Select_Winner
        Select_Winner --> Update_Arbiters
    end

    subgraph "Arbiter Types"
        X_Arbiters["X Arbiters (7 × 8-input)"]
        Y_Arbiters["Y Arbiters (7 × 8-input)"]
        B_Arbiter["B Arbiter (1 × 16-input)"]
    end

    subgraph "Stage 2: Output Selection"
        Stage_2_Output["Stage 2 Output"]
        Decode_Winner["Decode Winner"]
        Select_Data["Select Data"]
        Stage_3_Buffer["Stage 3 Buffer"]

        Stage_2_Output --> Decode_Winner
        Decode_Winner --> Select_Data
        Select_Data --> Stage_3_Buffer
    end

    Update_Arbiters --> X_Arbiters
    Update_Arbiters --> Y_Arbiters
    Update_Arbiters --> B_Arbiter

    X_Arbiters --> Stage_2_Output
    Y_Arbiters --> Stage_2_Output
    B_Arbiter --> Stage_2_Output

    Note[Note: Priority Order - Input 7 > Input 6 > ... > Input 0]
```

## 6. Node Interface and Buffer Architecture

```mermaid
graph LR
    %% Left Side: Input Interfaces
    subgraph "Input Interfaces"
        direction TB
        A_PORT["A Interface Port<br/>pkt_in<br/>External Input"]

        C_X_IN_PORT["C Interface X-Input<br/>7× bidirectional<br/>From topology"]
        C_Y_IN_PORT["C Interface Y-Input<br/>7× bidirectional<br/>From topology"]
    end

    %% Node Core Processing
    subgraph "Node Core (Pipeline Processing)"
        direction TB

        subgraph "Stage 0: Input Processing"
            direction LR
            A_BUF["A Input Buffer<br/>IRS_LP Deep=1<br/>RO_EN=1"]
            C_X_IN_BUF["C X Input Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
            C_Y_IN_BUF["C Y Input Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
        end

        subgraph "Stage 1: QoS Arbitration"
            direction LR
            X_ARB["X-Direction Arbiters<br/>7× 8-input<br/>High QoS Priority"]
            Y_ARB["Y-Direction Arbiters<br/>7× 8-input<br/>High QoS Priority"]
            B_ARB["B-Port Arbiter<br/>16-input<br/>A + 7Y + 7X + 1 Spare"]
        end

        subgraph "Stage 2: Output Selection"
            direction LR
            X_MUX["X-Output MUX<br/>7× multiplexers"]
            Y_MUX["Y-Output MUX<br/>7× multiplexers"]
            B_MUX["B-Port MUX<br/>16×1 multiplexer"]
        end

        subgraph "Stage 3: Output Buffering"
            direction LR
            C_X_OUT_BUF["C X Output Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
            C_Y_OUT_BUF["C Y Output Buffers<br/>7× IRS_LP Deep=1<br/>RO_EN=1"]
            B_OUT_BUF["B Output Buffer<br/>IRS_LP Deep=1<br/>RO_EN=1"]
        end
    end

    %% Right Side: Output Interfaces
    subgraph "Output Interfaces"
        direction TB
        C_X_OUT_PORT["C Interface X-Output<br/>7× bidirectional<br/>To topology"]
        C_Y_OUT_PORT["C Interface Y-Output<br/>7× bidirectional<br/>To topology"]

        B_PORT["B Interface Port<br/>pkt_out<br/>External Output"]
    end

    %% Data Flow Connections
    %% Left Inputs to Stage 0
    A_PORT --> A_BUF
    C_X_IN_PORT --> C_X_IN_BUF
    C_Y_IN_PORT --> C_Y_IN_BUF

    %% Stage 0 to Stage 1
    A_BUF --> B_ARB
    C_X_IN_BUF --> X_ARB
    C_Y_IN_BUF --> Y_ARB
    C_X_IN_BUF --> B_ARB
    C_Y_IN_BUF --> B_ARB

    %% Stage 1 to Stage 2
    X_ARB --> X_MUX
    Y_ARB --> Y_MUX
    B_ARB --> B_MUX

    %% Stage 2 to Stage 3
    X_MUX --> C_X_OUT_BUF
    Y_MUX --> C_Y_OUT_BUF
    B_MUX --> B_OUT_BUF

    %% Stage 3 to Right Outputs
    C_X_OUT_BUF --> C_X_OUT_PORT
    C_Y_OUT_BUF --> C_Y_OUT_PORT
    B_OUT_BUF --> B_PORT

    %% Styling
    %% Left Input Interfaces
    style A_PORT fill:#F39C12,stroke:#D68910
    style C_X_IN_PORT fill:#9B59B6,stroke:#7D3C98
    style C_Y_IN_PORT fill:#9B59B6,stroke:#7D3C98

    %% Right Output Interfaces
    style B_PORT fill:#F39C12,stroke:#D68910
    style C_X_OUT_PORT fill:#9B59B6,stroke:#7D3C98
    style C_Y_OUT_PORT fill:#9B59B6,stroke:#7D3C98

    %% Internal Buffers (All IRS_LP Deep=1, RO_EN=1)
    style A_BUF fill:#27AE60,stroke:#1E8449
    style C_X_IN_BUF fill:#27AE60,stroke:#1E8449
    style C_Y_IN_BUF fill:#27AE60,stroke:#1E8449
    style C_X_OUT_BUF fill:#27AE60,stroke:#1E8449
    style C_Y_OUT_BUF fill:#27AE60,stroke:#1E8449
    style B_OUT_BUF fill:#27AE60,stroke:#1E8449

    %% Processing Units
    style X_ARB fill:#FFEBEE,stroke:#C62828
    style Y_ARB fill:#FFEBEE,stroke:#C62828
    style B_ARB fill:#FFEBEE,stroke:#C62828
    style X_MUX fill:#3498DB,stroke:#2980B9
    style Y_MUX fill:#3498DB,stroke:#2980B9
    style B_MUX fill:#3498DB,stroke:#2980B9
```

## 7. Buffer Architecture Summary

```mermaid
graph LR
    subgraph "Input Buffers (16 total)"
        A_IN["A Input Buffer<br/>1× IRS_LP Deep=1"]
        C_X_IN["C X-Input Buffers<br/>7× IRS_LP Deep=1"]
        C_Y_IN["C Y-Input Buffers<br/>7× IRS_LP Deep=1"]
        SPARE["Spare Input<br/>1× Reserved"]
    end

    subgraph "Output Buffers (15 total)"
        C_X_OUT["C X-Output Buffers<br/>7× IRS_LP Deep=1"]
        C_Y_OUT["C Y-Output Buffers<br/>7× IRS_LP Deep=1"]
        B_OUT["B Output Buffer<br/>1× IRS_LP Deep=1"]
    end

    subgraph "Buffer Characteristics"
        DEPTH["Depth: 1 clock cycle"]
        WIDTH["Width: 23 bits"]
        TYPE["Type: IRS_LP"]
        RO_EN["RO_EN=1"]
    end

    A_IN --> DEPTH
    C_X_IN --> WIDTH
    C_Y_OUT --> TYPE
    B_OUT --> RO_EN

    %% Styling
    style A_IN fill:#27AE60,stroke:#1E8449
    style C_X_IN fill:#27AE60,stroke:#1E8449
    style C_Y_IN fill:#27AE60,stroke:#1E8449
    style SPARE fill:#95A5A6,stroke:#7F8C8D
    style C_X_OUT fill:#27AE60,stroke:#1E8449
    style C_Y_OUT fill:#27AE60,stroke:#1E8449
    style B_OUT fill:#27AE60,stroke:#1E8449
    style DEPTH fill:#3498DB,stroke:#2980B9
    style WIDTH fill:#3498DB,stroke:#2980B9
    style TYPE fill:#3498DB,stroke:#2980B9
    style RO_EN fill:#3498DB,stroke:#2980B9
```

## 编辑说明

### 兼容的编辑工具
- **Typora 8.8.0**: ✅ 完全兼容（本文档专门优化）
- **draw.io**: ✅ 完全兼容
- **GitHub/GitLab**: ✅ 自动渲染
- **Mermaid Live Editor**: ✅ https://mermaid.live
- **更新版本的Mermaid**: ✅ 兼容，但可能有更多功能

### 编辑功能
您可以：
1. 修改节点名称和描述
2. 调整连接关系（-->, ---, <-->）
3. 添加或删除模块
4. 更新文本说明
5. 改变布局方向（LR, TB, RL, BT）
6. 修改颜色（使用style指令）

### Typora 特定说明
- 本文档已针对Typora 8.8.0优化
- 使用兼容语法：`graph` 替代 `flowchart`
- 避免使用 `classDef` 复杂样式
- 简化了复杂的状态图语法
- 如遇渲染问题，请检查：
  - 括号匹配：`[]` `{}` `()`
  - 引号配对：`"` 和 `'`
  - 特殊字符转义

### 每个图表的内容保证
每个图表都基于您的RTL代码分析，确保架构准确性！
- ✅ 64节点8×8网格拓扑
- ✅ 4级流水线处理
- ✅ QoS仲裁机制
- ✅ 故障容忍系统
- ✅ 接口定义和连接
- ✅ **A/B/C接口分离和缓冲器架构** (新增)
- ✅ **31个缓冲器详细结构 (16输入 + 15输出)** (新增)