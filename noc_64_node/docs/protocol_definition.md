# 64-Node Network-on-Chip Protocol Definition

## 📦 **Protocol Overview**

This document defines the packet formats, communication protocols, and interface specifications for the 64-node Network-on-Chip. The protocol ensures reliable, efficient data transfer between network nodes while supporting quality of service and various communication patterns.

---

## 🎯 **Protocol Objectives**

### **Primary Goals**
- **Universal Communication**: Support any-to-any data transfer
- **QoS Support**: Differentiated service levels for different traffic types
- **Efficiency**: Minimal overhead and maximum bandwidth utilization
- **Scalability**: Works efficiently from 2 to 64+ nodes
- **Reliability**: Error detection and recovery mechanisms

### **Design Principles**
- **Header-Based**: All routing information in packet header
- **Fixed Header Size**: Consistent header processing
- **Variable Payload**: Flexible payload sizes
- **Little Endian**: Standard byte ordering
- **Aligned Data**: 32-bit alignment for efficiency

---

## 📊 **Packet Structure**

### **Overall Packet Format**
```
┌─────────────┬─────────────┬─────────────┬─────────────┐
│   Header    │   Header    │   Header    │   Header    │
│   Word 0    │   Word 1    │   Word 2    │   Word 3    │
├─────────────┼─────────────┼─────────────┼─────────────┤
│   Payload   │   Payload   │   Payload   │   Payload   │
│   Word 0    │   Word 1    │   Word 2    │   ...        │
├─────────────┼─────────────┼─────────────┼─────────────┤
│    Tail     │    Tail     │             │             │
│   Word 0    │   Word 1    │             │             │
└─────────────┴─────────────┴─────────────┴─────────────┘
```

### **Packet Types**
- **Head Flit**: Contains routing and control information
- **Body Flit**: Contains payload data
- **Tail Flit**: Contains packet completion information

---

## 🎛️ **Header Format Definition**

### **Header Word 0 (Control & Routing)**
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  Flit Type │ QoS │  Reserved  │    Source Address (X)    │
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 31   29   28   27   24   23   16   15   8   7   0

Field Descriptions:
- Flit Type [31:29]: Packet type (000=Head, 001=Body, 010=Tail, 011=Single, 1XX=Reserved)
- QoS [28:27]: Quality of Service level (00=Low, 01=Medium, 10=High, 11=Critical)
- Reserved [23]: Future use (must be 0)
- Source X [22:16]: Source node X coordinate (0-7 for 8×8 mesh)
```

### **Header Word 1 (Source & Destination)**
```
┌─────────────────┬─────────────────┬─────────────────────────┐
│  Source Addr Y  │ Dest Addr X     │   Dest Addr Y (Partial) │
└─────────────────┴─────────────────┴─────────────────────────┘
 31             24 23             16 15                      0

Field Descriptions:
- Source Y [31:24]: Source node Y coordinate (0-7)
- Dest X [23:16]: Destination node X coordinate (0-7)
- Dest Y [15:8]: Destination node Y coordinate (0-7)
- Packet ID [7:0]: Unique packet identifier for flow tracking
```

### **Header Word 2 (Packet Information)**
```
┌─────────────────────────┬─────────────────────────────────────┐
│     Packet Length       │      Virtual Channel ID             │
└─────────────────────────┴─────────────────────────────────────┘
 31                     16 15                               0

Field Descriptions:
- Packet Length [31:16]: Total number of flits in packet (including header and tail)
- Virtual Channel [15:0]: Virtual channel identifier (0-1 for 2 VCs)
```

### **Header Word 3 (Protocol & Control)**
```
┌─────────────┬─────────────┬─────────────┬─────────────────────┐
│ Protocol ID │ Service ID  │ Reserved    │   Control Flags     │
└─────────────┴─────────────┴─────────────┴─────────────────────┘
 31         24 23         16 15         8  7                  0

Field Descriptions:
- Protocol ID [31:24]: Protocol identifier (0x00=Data, 0x01=Control, 0x02=Debug)
- Service ID [23:16]: Service type (0x00=Memory, 0x01=IO, 0x02=Network Mgmt)
- Reserved [15:8]: Future use (must be 0)
- Control Flags [7:0]: Bit field for control information
  - [7]: Acknowledgment Required
  - [6]: Fragmentation Flag
  - [5]: Compression Flag
  - [4:2]: Reserved
  - [1]: Endian Flag (0=Little, 1=Big)
  - [0]: Parity Flag (enable error detection)
```

---

## 📋 **Flit Types**

### **1. Head Flit (Type 000)**
- **Purpose**: Contains all routing and control information
- **Position**: First flit in packet
- **Processing**: Used for routing decisions
- **Fields**: Complete header as defined above

### **2. Body Flit (Type 001)**
- **Purpose**: Carries payload data
- **Position**: Middle flits in packet
- **Processing**: Simple data forwarding
- **Fields**: 32-bit payload data

### **3. Tail Flit (Type 010)**
- **Purpose**: Marks end of packet, contains completion info
- **Position**: Last flit in packet
- **Processing**: Buffer deallocation, flow control
- **Fields**: 32-bit payload + control information

### **4. Single Flit Packet (Type 011)**
- **Purpose**: Complete packet in one flit
- **Position**: Header and payload together
- **Processing**: Routing and data in one cycle
- **Fields**: Header + 16-bit payload

---

## 🔌 **Interface Protocol**

### **Valid/Ready Handshake**
```systemverilog
// Standard interface protocol
interface NetworkChannel;
    logic        clk;          // Clock
    logic        rst_n;        // Reset (active low)
    logic        valid;        // Data valid
    logic        ready;        // Ready to receive
    logic [31:0] data;         // Data payload
    logic [VCS-1:0] vc_id;     // Virtual channel ID
    logic        last;         // Last flit in packet
endinterface
```

### **Timing Diagram**
```
        ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐
Clock: ─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─
        ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐
Valid: ─┤ Header  ├─┤ Body 1  ├─┤ Body 2  ├─┤ Tail    ├─
        └───┬─────┘ └───┬─────┘ └───┬─────┘ └───┬─────┘
            │             │             │             │
        ┌───▼─────┐ ┌───▼─────┐ ┌───▼─────┐ ┌───▼─────┐
Ready: ──┤   1     ├─┤   1     ├─┤   1     ├─┤   1     ├─
        └─────────┘ └─────────┘ └─────────┘ └─────────┘

        ┌─────────┐ ┌─────────┐ ┌─────────┐ ┌─────────┐
Data:  ─┤ Header  ├─┤ Data 1  ├─┤ Data 2  ├─┤ Data 3  ├─
        └─────────┘ └─────────┘ └─────────┘ └─────────┘

        ┌─┐ ┌─┐ ┌─┐ ┌─┐
Last:  ─┘ └─┘ └─┘ └─┘ └─
```

---

## 🚦 **Flow Control Protocol**

### **Credit-Based Flow Control**

#### **Credit Encoding**
```systemverilog
// Credit information per virtual channel
typedef struct packed {
    logic [BUFFER_DEPTH_BITS-1:0] free_slots;  // Available buffer slots
    logic                         valid;       // Credit valid
} credit_info_t;
```

#### **Credit Update Timing**
```
Sender Node                    Receiver Node
    │                               │
    ├─ Send Flit ──────────────────►│
    │                               │
    │◄───────── Credit Update ──────┤
    │                               │
    ├─ Send Next Flit ─────────────►│
    │                               │
```

#### **Credit Management Rules**
1. **Initial Credits**: Each receiver starts with BUFFER_DEPTH credits
2. **Credit Consumption**: Sender decrements credits when sending flit
3. **Credit Return**: Receiver sends credit when buffer slot freed
4. **Backpressure**: Sender blocks when credits = 0

### **Virtual Channel Flow Control**
```systemverilog
// Virtual channel state management
typedef enum logic [1:0] {
    VC_IDLE,        // No packet in progress
    VC_ACTIVE,      // Packet transmission in progress
    VC_WAIT_CREDIT, // Waiting for credits
    VC_STALLED      // Stalled due to congestion
} vc_state_t;

// Per-VC flow control
typedef struct packed {
    vc_state_t          state;
    logic [15:0]        packet_id;      // Current packet ID
    logic [7:0]         credits;        // Available credits
    logic [2:0]         flits_sent;     // Flits sent in current packet
    logic               last_received;  // Last flit received
} vc_flow_control_t;
```

---

## 🔐 **Error Detection & Handling**

### **CRC Calculation**
```systemverilog
// CRC-8 calculation for header integrity
function automatic logic [7:0] crc8(input logic [127:0] data);
    logic [7:0] crc;
    logic [7:0] poly = 8'h07;  // CRC-8 polynomial

    crc = 8'h00;
    for (int i = 127; i >= 0; i--) begin
        if (crc[7] != data[i]) begin
            crc = (crc << 1) ^ poly;
        end else begin
            crc = crc << 1;
        end
    end

    return crc;
endfunction
```

### **Parity Protection**
```systemverilog
// Even parity for 32-bit data
function automatic logic parity_check(input logic [31:0] data);
    logic parity;
    parity = ^data;  // XOR all bits
    return parity;
endfunction
```

### **Error Handling Protocol**
```
Error Detection → Error Reporting → Error Recovery → Normal Operation
      │                │                │                │
  CRC/Parity      NACK/Interrupt    Retry Route     Clear Error
```

---

## 📨 **Communication Patterns**

### **1. Unicast Communication**
- **Pattern**: One source to one destination
- **Routing**: Standard XY or adaptive routing
- **Flow Control**: Credit-based per virtual channel
- **QoS**: Priority-based virtual channel allocation

### **2. Multicast Communication**
- **Pattern**: One source to multiple destinations
- **Routing**: Tree-based replication at branching points
- **Flow Control**: Separate flow control per destination branch
- **Implementation**: Multiple unicast packets or true multicast

### **3. Broadcast Communication**
- **Pattern**: One source to all destinations
- **Routing**: Flood with sequence number to prevent loops
- **Flow Control:** Special broadcast virtual channel
- **Optimization**: Hardware broadcast tree

### **4. Collective Operations**
- **Pattern**: All-to-all, reduce, scatter, gather
- **Routing**: Multiple phases of unicast/multicast
- **Synchronization**: Barrier synchronization
- **Implementation**: Network-level collective operations

---

## 🏷️ **Quality of Service (QoS)**

### **QoS Levels**
```systemverilog
typedef enum logic [1:0] {
    QOS_LOW      = 2'b00,    // Best effort
    QOS_MEDIUM   = 2'b01,    // Better than best effort
    QOS_HIGH     = 2'b10,    // Guaranteed bandwidth
    QOS_CRITICAL = 2'b11     // Minimum latency, highest priority
} qos_level_t;
```

### **QoS Implementation**
```systemverilog
// QoS-aware virtual channel allocation
always_comb begin
    case (packet_qos)
        QOS_CRITICAL: begin
            // Use dedicated critical VC or preempt lower priority
            vc_id = CRITICAL_VC;
            priority_level = 3;
        end
        QOS_HIGH: begin
            // High priority VC with guaranteed service
            vc_id = HIGH_VC;
            priority_level = 2;
        end
        QOS_MEDIUM: begin
            // Medium priority, fair arbitration
            vc_id = MEDIUM_VC;
            priority_level = 1;
        end
        QOS_LOW: begin
            // Best effort, lowest priority
            vc_id = LOW_VC;
            priority_level = 0;
        end
    endcase
end
```

---

## 🔄 **Congestion Management**

### **Congestion Detection**
```systemverilog
// Congestion metrics
typedef struct packed {
    logic [BUFFER_DEPTH_BITS-1:0] buffer_occupancy;
    logic                         buffer_full;
    logic [7:0]                   queue_delay;
    logic                         credit_starvation;
} congestion_info_t;
```

### **Congestion Response**
1. **Local Response**: Backpressure to upstream routers
2. **Route Adaptation**: Select less congested paths
3. **QoS Adjustment**: Prioritize critical traffic
4. **Throttling**: Rate limit low priority traffic

---

## 🛠️ **Protocol Configuration**

### **Configuration Parameters**
```systemverilog
// Protocol configuration structure
typedef struct packed {
    logic [7:0]   max_packet_length;     // Maximum packet size
    logic [2:0]   num_virtual_channels;   // Number of VCs
    logic         crc_enable;            // Enable CRC checking
    logic         parity_enable;         // Enable parity checking
    logic         qos_enable;            // Enable QoS support
    logic [1:0]   default_qos;           // Default QoS level
} protocol_config_t;
```

### **Runtime Reconfiguration**
- **Dynamic VC Allocation**: Adjust VC count based on traffic
- **QoS Parameter Update**: Change QoS weights and thresholds
- **Protocol Feature Enable/Disable**: Turn on/off features
- **Performance Monitoring**: Collect statistics for optimization

---

## 🧪 **Protocol Verification**

### **Test Scenarios**

#### **Correctness Tests**
- **Packet Integrity**: Verify header and payload integrity
- **Flow Control**: Test credit management under various conditions
- **Routing**: Verify packets reach correct destinations
- **QoS**: Test priority handling and service differentiation

#### **Performance Tests**
- **Latency**: Measure end-to-end latency for different packet sizes
- **Throughput**: Measure maximum sustainable throughput
- **Scalability**: Test with increasing numbers of flows
- **Congestion**: Verify behavior under saturated conditions

#### **Error Handling Tests**
- **CRC Errors**: Inject bit errors and verify detection
- **Parity Errors**: Test single-bit error detection
- **Credit Errors**: Test lost credit scenarios
- **Timeout Scenarios**: Test behavior with stuck packets

### **Protocol Compliance Checks**
- **Header Format Validation**: Verify all header fields
- **Interface Protocol Compliance**: Check valid/ready timing
- **Flow Control Correctness**: Verify no buffer overflow
- **QoS Compliance**: Verify priority ordering

---

## 📈 **Protocol Optimization**

### **Bandwidth Optimization**
- **Header Compression**: Reduce header overhead for small packets
- **Payload Packing**: Multiple small messages in one packet
- **Burst Transfer**: Send back-to-back flits when possible
- **Aggregation**: Combine multiple small packets

### **Latency Optimization**
- **Cut-Through Routing**: Start forwarding before full packet received
- **Speculative Execution**: Predict and pre-allocate resources
- **Priority Preemption**: Allow critical traffic to preempt
- **Path Optimization**: Select shortest physical paths

### **Power Optimization**
- **Clock Gating**: Disable idle components
- **Power Gating**: Power down unused routers
- **Voltage Scaling**: Adjust voltage based on load
- **Activity Monitoring**: Track and reduce unnecessary activity

---

## 📝 **Protocol Versioning**

### **Version Numbering**
- **Major Version**: Incompatible protocol changes
- **Minor Version**: Backward-compatible additions
- **Patch Version**: Bug fixes and optimizations

### **Version Negotiation**
- **Capability Exchange**: Nodes advertise supported features
- **Version Compatibility**: Ensure interoperability
- **Graceful Degradation**: Fall back to compatible version

---

## 📊 **Protocol Metrics**

### **Key Performance Indicators**
- **Packet Delivery Ratio**: Successfully delivered / total sent
- **Average Latency**: Mean end-to-end delay
- **Throughput**: Flits per second per port
- **Buffer Utilization**: Average buffer occupancy
- **Credit Efficiency**: Credit utilization rate

### **Quality Metrics**
- **Jitter**: Latency variation
- **Packet Loss Rate**: Lost packets / total packets
- **Error Rate**: Corrupted packets / total packets
- **QoS Compliance**: Priority adherence percentage

---

**Document Version**: 1.0
**Last Updated**: 2025-11-04
**Next Review Date**: __/__/____
**Approved By**: ________________