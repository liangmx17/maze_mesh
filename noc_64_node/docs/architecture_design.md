# 64-Node Network-on-Chip Architecture Design

## 🏗️ **Architecture Overview**

This document describes the high-level architecture of the 64-node Network-on-Chip (NoC) system, including component organization, interfaces, and design decisions.

---

## 🎯 **Design Objectives**

### **Primary Goals**
- **Scalability**: Support 64 nodes with configurable expansion
- **Performance**: Low latency, high throughput communication
- **Modularity**: Clear separation of concerns and reusable components
- **Verifiability**: Design for comprehensive testing and validation
- **IRS Integration**: Seamless integration with register chain modules

### **Design Principles**
- **Hierarchical Design**: System → Network → Node → Router → Components
- **Parameterizable Architecture**: Configurable for different requirements
- **Standard Interfaces**: Consistent communication protocols
- **Timing-First Design**: Meet timing constraints from the start
- **Power Awareness**: Design for efficient power consumption

---

## 🌐 **System Architecture**

### **High-Level Block Diagram**
```
┌─────────────────────────────────────────────────────────────┐
│                    64-Node NoC System                       │
├─────────────────────────────────────────────────────────────┤
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐  │
│  │ Node 00 │─── │ Node 01 │─── │ Node 02 │─── │ Node 03 │  │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘  │
│       │              │              │              │       │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐  │
│  │ Node 04 │─── │ Node 05 │─── │ Node 06 │─── │ Node 07 │  │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘  │
│       ...              ...            ...            ...     │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐  │
│  │ Node 60 │─── │ Node 61 │─── │ Node 62 │─── │ Node 63 │  │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘  │
└─────────────────────────────────────────────────────────────┘
```

### **Network Topology**
**Primary Topology: 8×8 2D Mesh**
- **Nodes**: 64 routers arranged in 8×8 grid
- **Connections**: Each node connects to up to 4 neighbors (N,S,E,W)
- **Wraparound**: No wraparound (simpler timing, better for NoC)
- **Diameter**: 14 hops (maximum distance between any two nodes)
- **Bisection Bandwidth**: 8 links

**Alternative Topologies (Parameterizable)**
- **8×8 2D Torus**: Wraparound connections, higher bandwidth
- **4×4×4 3D Mesh**: 3D stacking, shorter paths
- **Fat Tree**: Hierarchical, good for client-server traffic

---

## 🏢 **Node Architecture**

### **Node Block Diagram**
```
┌─────────────────────────────────────────────────────────────┐
│                        Node (X,Y)                           │
├─────────────────────────────────────────────────────────────┤
│  ┌─────────────┐              ┌─────────────────────────────┐ │
│  │ Processing  │◄────────────►│      Network Interface       │ │
│  │   Element   │   Local      │                             │ │
│  │             │   Interface  │  ┌─────────────────────────┐ │ │
│  └─────────────┘              │  │      Router Core        │ │ │
│                                 │  │                         │ │ │
│  ┌─────────────┐              │  │  ┌─────┐ ┌─────┐ ┌─────┐ │ │ │
│  │   Network   │◄─────────────►  │  │ N,S ││ E,W ││Local│ │ │ │
│  │ Management  │   Control     │  │Ports││Ports││ Port│ │ │ │
│  │   & Config  │   Interface   │  └─────┘ └─────┘ └─────┘ │ │ │
│  └─────────────┘              │  └─────────────────────────┘ │ │
│                                 └─────────────────────────────┘ │
└─────────────────────────────────────────────────────────────┘
```

### **Node Components**

#### **1. Router Core**
- **Function**: Packet switching and routing
- **Ports**: 5 ports (North, South, East, West, Local)
- **Architecture**: Input-buffered router with virtual channels
- **Pipeline**: 4-stage (Route, VC Alloc, Switch Alloc, Crossbar)

#### **2. Network Interface**
- **Function**: Interface between processing element and network
- **Protocol**: Valid/Ready handshake with flow control
- **Features**: Packetization/depacketization, address translation
- **Buffering**: Transmit and receive FIFOs

#### **3. Processing Element Interface**
- **Function**: Standard interface for external processing
- **Signals**: Clock, reset, data, valid, ready, interrupt
- **Configurability**: Parameterizable data width and protocol

#### **4. Network Management**
- **Function**: Configuration, monitoring, and debugging
- **Features**: Performance counters, error detection, config registers
- **Interface**: Simple register-based access

---

## 🔧 **Router Microarchitecture**

### **Router Pipeline Stages**
```
Input Buffer → Route Computation → VC Allocation → Switch Allocation → Crossbar → Output
     1 cycle          1 cycle           1 cycle          1 cycle        1 cycle
```

#### **Stage 1: Input Buffers**
- **Function**: Store incoming packets per virtual channel
- **Implementation**: IRS-based register chains
- **Depth**: Configurable (default 4 flits per VC)
- **Flow Control**: Credit-based backpressure

#### **Stage 2: Route Computation**
- **Function**: Determine output port for packet header
- **Algorithms**: XY routing, adaptive routing
- **Timing**: Combinational logic within clock cycle
- **Output**: Output port selection and virtual channel request

#### **Stage 3: Virtual Channel Allocation**
- **Function**: Allocate virtual channel on output port
- **Algorithm**: Round-robin with priority support
- **Arbitration**: Fair sharing among competing requests
- **Timing**: Single cycle allocation decision

#### **Stage 4: Switch Allocation**
- **Function**: Grant access to crossbar switch
- **Algorithm**: Round-robin with QoS priority
- **Considerations**: Head-of-line blocking avoidance
- **Timing**: Single cycle switch allocation

#### **Stage 5: Crossbar Switch**
- **Function**: Physical connection between inputs and outputs
- **Implementation**: 5×5 configurable switch matrix
- **Timing**: Single cycle traversal
- **Configuration**: Dynamic based on switch allocation

### **Router Component Details**

#### **Input Buffer Manager**
```
┌─────────────────────────────────────────────────────────────┐
│                Input Buffer Manager (Port X)                 │
├─────────────────────────────────────────────────────────────┤
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐ ┌───────┐ │
│  │    VC 0     │ │    VC 1     │ │    VC 2     ││  ...  │ │
│  │   Buffer    │ │   Buffer    │ │   Buffer    ││       │ │
│  │  (IRS Mod)  │ │  (IRS Mod)  │ │  (IRS Mod)  ││       │ │
│  └─────────────┘ └─────────────┘ └─────────────┘└───────┘ │
│         │               │               │                     │
│  ┌─────────────────────────────────────────────────────────┐ │
│  │           Credit-Based Flow Control Logic               │ │
│  └─────────────────────────────────────────────────────────┘ │
└─────────────────────────────────────────────────────────────┘
```

#### **Routing Unit**
```
┌─────────────────────────────────────────────────────────────┐
│                    Routing Unit                             │
├─────────────────────────────────────────────────────────────┤
│  ┌─────────────┐    ┌─────────────────────────────────────┐ │
│  │ Packet      │    │        Routing Computation           │ │
│  │ Header      │───►│                                     │ │
│  │ Parser      │    │  ┌─────────┐ ┌─────────────────────┐ │ │
│  └─────────────┘    │ │ XY Route│ │   Adaptive Route    │ │ │
│                     │ │ Engine  │ │      Engine         │ │ │
│  ┌─────────────┐    │ └─────────┘ └─────────────────────┘ │ │
│  │ Destination │    └─────────────────────────────────────┘ │
│  │ Address     │                                           │
│  └─────────────┘    ┌─────────────────────────────────────┐ │
│                     │      Output Port Selection          │ │
│                     │    (N/S/E/W/Local + VC)              │ │
│                     └─────────────────────────────────────┘ │
└─────────────────────────────────────────────────────────────┘
```

#### **Switch Allocator**
```
┌─────────────────────────────────────────────────────────────┐
│                 Switch Allocator                            │
├─────────────────────────────────────────────────────────────┤
│  ┌─────────────────────────────────────────────────────────┐ │
│  │           Request Arbitration Matrix                    │ │
│  │                                                         │ │
│  │  Out Port N  ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐  │ │
│  │  Out Port S  │ Req│ │ Req│ │ Req│ │ Req│ │ Req│  │ │
│  │  Out Port E  │ Mtx │ │ Mtx │ │ Mtx │ │ Mtx │ │ Mtx │  │ │
│  │  Out Port W  │     │ │     │ │     │ │     │ │     │  │ │
│  │  Out Port L  └─────┘ └─────┘ └─────┘ └─────┘ └─────┘  │ │
│  └─────────────────────────────────────────────────────────┘ │
│                     │                                       │
│  ┌─────────────────────────────────────────────────────────┐ │
│  │              QoS Priority Logic                         │ │
│  │  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐       │ │
│  │  │   High      │ │  Medium     │ │    Low      │       │ │
│  │  │  Priority   │ │  Priority   │ │  Priority   │       │ │
│  │  └─────────────┘ └─────────────┘ └─────────────┘       │ │
│  └─────────────────────────────────────────────────────────┘ │
└─────────────────────────────────────────────────────────────┘
```

---

## 🔌 **Interface Specifications**

### **Inter-Router Interface**
```systemverilog
// Standard router-to-router link interface
interface RouterLink;
    logic        clk;          // Clock
    logic        rst_n;        // Reset
    logic [VCS-1:0] vc_valid;  // Virtual channel valid
    logic [VCS-1:0] vc_ready;  // Virtual channel ready
    logic [DW-1:0] vc_data;    // Data payload
    logic [VCS-1:0] vc_credit; // Credit return
endinterface
```

### **Node Interface**
```systemverilog
// Processing element to network interface
interface NodeInterface;
    logic        clk;          // Clock
    logic        rst_n;        // Reset
    logic        tx_valid;     // Transmit valid
    logic        tx_ready;     // Transmit ready
    logic [DW-1:0] tx_data;    // Transmit data
    logic        rx_valid;     // Receive valid
    logic        rx_ready;     // Receive ready
    logic [DW-1:0] rx_data;    // Receive data
endinterface
```

### **IRS Module Interface**
```systemverilog
// Standard wrapper for IRS register chain modules
interface IRSModule #(parameter DEPTH=4, WIDTH=8);
    logic        clk;          // Clock
    logic        rst_n;        // Reset
    logic        enable;       // Enable signal
    logic        write_en;     // Write enable
    logic [WIDTH-1:0] data_in; // Data input
    logic [WIDTH-1:0] data_out;// Data output
    logic        full;         // Buffer full
    logic        empty;        // Buffer empty
endinterface
```

---

## 📊 **Parameterization**

### **Global Parameters**
```systemverilog
package NetworkParams;
    // Network configuration
    parameter int NODES_X = 8;              // Nodes in X dimension
    parameter int NODES_Y = 8;              // Nodes in Y dimension
    parameter int DATA_WIDTH = 32;          // Data width in bits
    parameter int ADDR_WIDTH = 6;           // Address width
    parameter int VIRTUAL_CHANNELS = 2;      // Virtual channels per port
    parameter int BUFFER_DEPTH = 4;         // Buffer depth per VC
    parameter int MAX_PACKET_LEN = 8;       // Maximum flits per packet

    // Timing parameters
    parameter int PIPELINE_STAGES = 4;      // Router pipeline stages
    parameter int MAX_LATENCY = 20;         // Maximum network latency

    // QoS parameters
    parameter int PRIORITY_LEVELS = 3;      // Number of priority levels
    parameter int ARBITRATION fairness = 1; // Fair arbitration enabled
endpackage
```

### **Module Parameters**
- **Router**: Configurable port count, buffer sizes, pipeline depth
- **Buffer**: Depth, width, IRS module selection
- **Routing**: Algorithm selection, adaptive routing enable
- **Topology**: Grid dimensions, connection patterns

---

## ⏱️ **Timing Analysis**

### **Critical Paths**
1. **Route Computation**: Address decode + output port selection
2. **VC Allocation**: Arbitration + grant generation
3. **Switch Allocation**: Request matrix + priority resolution
4. **Crossbar**: Switch configuration + data traversal

### **Timing Budget**
- **Clock Period**: 5 ns (200 MHz target)
- **Setup Time**: 0.5 ns
- **Hold Time**: 0.1 ns
- **Clock Skew**: 0.2 ns
- **Logic Budget**: 4.2 ns

### **Timing Optimization Strategies**
- **Pipelining**: Break long combinatorial paths
- **Register Balancing**: Distribute logic across stages
- **Logic Optimization**: Minimize gate levels
- **Floorplanning**: Physical placement for timing

---

## 🏗️ **Physical Design Considerations**

### **Area Estimation**
- **Router Core**: ~8,000-12,000 gates
- **Buffers**: ~1,000 gates per VC × 2 VCs × 5 ports = 10,000 gates
- **Crossbar**: ~1,000 gates for 5×5 switch
- **Total per Node**: ~20,000-25,000 gates
- **64-Node Network**: ~1.3-1.6M gates

### **Power Estimation**
- **Dynamic Power**: Dominated by buffer switching
- **Static Power**: Leakage in large memory arrays
- **Clock Power**: Distribution network
- **I/O Power**: Driver/receiver power

### **Floorplanning**
- **Regular Grid**: Symmetric placement for regular timing
- **Clock Domain**: Single clock domain for simplicity
- **Power Grid**: Distributed power delivery
- **Signal Integrity**: Controlled impedance routing

---

## 🔄 **Design Flow**

### **Development Stages**
1. **Specification**: Requirements and architecture definition
2. **Microarchitecture**: Detailed component design
3. **RTL Implementation**: SystemVerilog coding
4. **Unit Testing**: Component-level verification
5. **Integration Testing**: System-level verification
6. **Performance Analysis**: Timing and power optimization
7. **Synthesis**: Technology mapping
8. **Physical Design**: Place and route

### **Verification Strategy**
- **Bottom-Up**: Unit → Integration → System testing
- **Assertion-Based**: Property checking throughout
- **Coverage-Driven**: Functional and code coverage
- **Performance Modeling**: Cycle-accurate simulation

---

## 📈 **Scalability Analysis**

### **Network Expansion**
- **Current**: 8×8 = 64 nodes
- **Expansion**: 16×16 = 256 nodes (parameterized)
- **Limitations**: Address width, timing, area
- **Solutions**: Hierarchical routing, network segmentation

### **Performance Scaling**
- **Latency**: O(√N) for mesh topology
- **Throughput**: Constant per port, scales with N
- **Area**: Linear with node count
- **Power**: Linear with node count

---

## 🎯 **Design Trade-offs**

### **Area vs. Performance**
- **Larger Buffers**: Better performance, more area
- **More Virtual Channels**: Better QoS, more complexity
- **Adaptive Routing**: Better load balancing, more logic

### **Latency vs. Throughput**
- **Deeper Pipeline**: Higher frequency, more latency
- **Wider Links**: More bandwidth, more area
- **Aggressive Arbitration**: Better utilization, more complexity

### **Complexity vs. Verifiability**
- **Feature Richness**: More functionality, harder verification
- **Parameterization**: More flexibility, more configurations
- **Optimization**: Better performance, less predictability

---

## 📝 **Architecture Decisions Log**

| Decision | Rationale | Alternatives Considered | Impact |
|----------|-----------|-------------------------|--------|
| 8×8 Mesh Topology | Simplicity, proven scalability | Torus, 3D Mesh, Fat Tree | Moderate latency, easy verification |
| XY Routing | Deadlock-free, simple implementation | Adaptive, West-First | Predictable paths, no congestion avoidance |
| Input-Buffered Router | Simpler timing, easier verification | Output-buffered, Combined | Area overhead, simpler control logic |
| Credit-based Flow Control | Prevents overflow, standard approach | On/Off, ACK/NACK | Requires credit management, proven reliable |

---

**Document Version**: 1.0
**Last Updated**: 2025-11-04
**Next Review Date**: __/__/____
**Approved By**: ________________