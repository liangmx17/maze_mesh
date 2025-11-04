# 64-Node Network-on-Chip Routing Strategies

## 🛣️ **Routing Overview**

This document defines the routing algorithms and strategies for the 64-node Network-on-Chip. Routing is a critical function that determines how packets traverse from source to destination nodes while maintaining network performance and reliability.

---

## 🎯 **Routing Objectives**

### **Primary Goals**
- **Correctness**: Every packet reaches its destination
- **Deadlock Freedom**: No circular dependencies or livelock
- **Performance**: Low latency and high throughput
- **Scalability**: Works efficiently across network sizes
- **QoS Support**: Handles different traffic classes appropriately

### **Design Constraints**
- **Local Decision Making**: No global routing state
- **Deterministic**: Same route for same source-destination pair
- **Minimal Path**: Shortest possible routes
- **Hardware Efficiency**: Simple implementation in RTL

---

## 🧭 **Primary Routing Algorithms**

### **1. XY Dimension-Order Routing (Default)**

#### **Algorithm Description**
- **Principle**: Route first in X dimension, then in Y dimension
- **Order**: East/West until correct X coordinate, then North/South
- **Nature**: Deterministic, minimal, deadlock-free
- **Complexity**: O(1) per hop decision time

#### **Routing Rules**
```
if current.x < destination.x:
    route East
else if current.x > destination.x:
    route West
else if current.y < destination.y:
    route North
else if current.y > destination.y:
    route South
else:
    route Local (destination reached)
```

#### **Properties**
- **Path Length**: Always minimal (Manhattan distance)
- **Deadlock**: Deadlock-free by construction
- **Livelock**: Impossible (deterministic)
- **Implementation**: Simple coordinate comparison

#### **Advantages**
- ✅ Guaranteed deadlock freedom
- ✅ Simple hardware implementation
- ✅ Predictable routing paths
- ✅ Minimal routing logic
- ✅ No routing tables required

#### **Disadvantages**
- ❌ Not adaptive to congestion
- ❌ Can create hotspots
- ❌ No load balancing
- ❌ Fixed path regardless of conditions

#### **Implementation in RTL**
```systemverilog
// XY routing logic
always_comb begin
    if (current_x < dest_x) begin
        route_direction = EAST;
    end else if (current_x > dest_x) begin
        route_direction = WEST;
    end else if (current_y < dest_y) begin
        route_direction = NORTH;
    end else if (current_y > dest_y) begin
        route_direction = SOUTH;
    end else begin
        route_direction = LOCAL;
    end
end
```

---

### **2. West-First Adaptive Routing**

#### **Algorithm Description**
- **Principle**: Route west if needed, otherwise choose between X and Y
- **Adaptation**: Select less congested dimension
- **Nature**: Minimal adaptive, deadlock-free
- **Complexity**: O(1) with congestion awareness

#### **Routing Rules**
```
if current.x > destination.x:
    // Must go west (non-adaptive)
    route West
else if current.x < destination.x and current.y != destination.y:
    // Choice between East and North/South (adaptive)
    if congestion(North/South) > congestion(East):
        route East
    else:
        if current.y < destination.y: route North
        else: route South
else:
    // Only one dimension remaining
    if current.x < destination.x: route East
    else if current.y < destination.y: route North
    else if current.y > destination.y: route South
    else: route Local
```

#### **Congestion Metrics**
- **Buffer Occupancy**: Number of filled buffer slots
- **Credit Availability**: Free buffer space in downstream node
- **Queue Delay**: Time packets wait in buffers
- **Channel Utilization**: Link usage statistics

#### **Advantages**
- ✅ Adaptive to congestion
- ✅ Still deadlock-free
- ✅ Better load balancing
- ✅ Improved performance under load

#### **Disadvantages**
- ❌ More complex implementation
- ❌ Requires congestion monitoring
- ❌ Potential for routing path variation
- ❌ Additional hardware for adaptation logic

---

### **3. Odd-Even Turn Model**

#### **Algorithm Description**
- **Principle**: Restrict certain turns to prevent deadlocks
- **Rules**: Odd rows cannot turn from North to East, even rows cannot turn from South to West
- **Nature**: Minimal adaptive, deadlock-free
- **Complexity**: O(1) with turn restrictions

#### **Turn Restrictions**
```
Row Parity = current.y % 2

if Row Parity == 0 (Even):
    // Forbidden: South → West turn
    // Allow: Other turns

if Row Parity == 1 (Odd):
    // Forbidden: North → East turn
    // Allow: Other turns
```

#### **Advantages**
- ✅ Full adaptivity except restricted turns
- ✅ Deadlock-free with minimal restrictions
- ✅ Better performance than pure XY
- ✅ No virtual channels needed

#### **Disadvantages**
- ❌ Complex turn restriction logic
- ❌ Non-intuitive routing behavior
- ❌ Potential path suboptimality
- ❌ Harder to verify

---

### **4. Fully Adaptive Routing with Virtual Channels**

#### **Algorithm Description**
- **Principle**: Use virtual channels to break deadlock cycles
- **Strategy**: Separate virtual networks for different directions
- **Nature**: Fully adaptive, requires VCs
- **Complexity**: O(1) with VC management

#### **Virtual Channel Allocation**
```
VC 0: Escape channel (XY routing only)
VC 1: Adaptive channel (any minimal direction)
```

#### **Routing Logic**
```
if packet in escape VC:
    use XY routing (deadlock escape path)
else if packet in adaptive VC:
    choose any minimal direction based on congestion
```

#### **Advantages**
- ✅ Maximum adaptivity
- ✅ Best performance under congestion
- ✅ Optimal load balancing
- ✅ Configurable adaptivity level

#### **Disadvantages**
- ❌ Requires multiple virtual channels
- ❌ Complex VC allocation logic
- ❌ Higher area and power cost
- ❌ Deadlock escape path overhead

---

## 🔄 **Adaptive Routing Implementation**

### **Congestion Detection**

#### **Buffer Occupancy Based**
```systemverilog
// Congestion metric based on buffer occupancy
logic [BUFFER_DEPTH_BITS-1:0] north_occupancy;
logic [BUFFER_DEPTH_BITS-1:0] south_occupancy;
logic [BUFFER_DEPTH_BITS-1:0] east_occupancy;
logic [BUFFER_DEPTH_BITS-1:0] west_occupancy;

// Compare occupancy for routing decision
always_comb begin
    if (north_occupancy < east_occupancy) begin
        preferred_direction = NORTH;
    end else begin
        preferred_direction = EAST;
    end
end
```

#### **Credit Based**
```systemverilog
// Congestion metric based on available credits
logic [CREDIT_BITS-1:0] north_credits;
logic [CREDIT_BITS-1:0] south_credits;
logic [CREDIT_BITS-1:0] east_credits;
logic [CREDIT_BITS-1:0] west_credits;

// Route to direction with most available credits
always_comb begin
    case (1'b1)
        (north_credits > south_credits) && (north_credits > east_credits) && (north_credits > west_credits):
            preferred_direction = NORTH;
        (east_credits > south_credits) && (east_credits > west_credits):
            preferred_direction = EAST;
        (south_credits > west_credits):
            preferred_direction = SOUTH;
        default:
            preferred_direction = WEST;
    endcase
end
```

### **Route Selection Logic**

#### **Priority-Based Selection**
```systemverilog
// Route selection with priorities
typedef enum logic [1:0] {
    PRIO_HIGH   = 2'b11,
    PRIO_MEDIUM = 2'b10,
    PRIO_LOW    = 2'b01,
    PRIO_MIN    = 2'b00
} route_priority_t;

// Route computation with congestion awareness
always_comb begin
    // Default XY routing
    xy_route = compute_xy_route(current_pos, destination);

    // Adaptive routing based on congestion
    adaptive_route = compute_adaptive_route(current_pos, destination, congestion_info);

    // Final route selection
    if (congestion_adaptive_enable && congestion_severity > ADAPT_THRESHOLD) begin
        selected_route = adaptive_route;
    end else begin
        selected_route = xy_route;
    end
end
```

---

## 📦 **Multicast Routing**

### **Multicast Tree Construction**

#### **XY-Based Multicast**
- **Algorithm**: Multiple unicast packets following XY paths
- **Duplication**: At branching points, create copies
- **Efficiency**: Simple but redundant

#### **Tree-Based Multicast**
- **Algorithm**: Construct minimal spanning tree
- **Branching**: Replicate packets at optimal points
- **Efficiency**: Minimal bandwidth usage

#### **Implementation**
```systemverilog
// Multicast routing table
typedef struct packed {
    logic [ADDR_WIDTH-1:0] destinations [MAX_DESTINATIONS];
    logic [NUM_DESTS-1:0]   valid_mask;
    logic [DEST_BITS-1:0]    num_destinations;
} multicast_header_t;

// Multicast route computation
always_comb begin
    for (int i = 0; i < MAX_DESTINATIONS; i++) begin
        if (multicast_hdr.valid_mask[i]) begin
            dest_routes[i] = compute_route(current_pos, multicast_hdr.destinations[i]);
        end
    end

    // Determine output ports for this router
    output_ports_north = has_destination(dest_routes, NORTH);
    output_ports_south = has_destination(dest_routes, SOUTH);
    output_ports_east  = has_destination(dest_routes, EAST);
    output_ports_west  = has_destination(dest_routes, WEST);
    output_ports_local = has_destination(dest_routes, LOCAL);
end
```

---

## 🚨 **Fault-Tolerant Routing**

### **Fault Detection**
- **Link Failure**: Timeout on credit return
- **Router Failure**: No response to control packets
- **Congestion Failure**: Persistent buffer overflow

### **Fault Recovery Strategies**

#### **Static Detour Routing**
- **Pre-computed**: Alternative paths computed offline
- **Fast Response**: Immediate switch to backup path
- **Limitations**: Fixed number of fault scenarios

#### **Dynamic Rerouting**
- **Runtime**: Alternative paths computed at runtime
- **Flexible**: Handles multiple simultaneous faults
- **Complexity**: Higher computational overhead

#### **Implementation Example**
```systemverilog
// Fault-tolerant routing
always_comb begin
    // Check for link failures
    if (link_fault_north && xy_route == NORTH) begin
        // Try alternative direction
        if (can_go_east) route = EAST;
        else if (can_go_west) route = WEST;
        else route = SOUTH; // Last resort
    end else begin
        route = xy_route;
    end
end
```

---

## 📊 **Routing Performance Analysis**

### **Latency Analysis**

#### **XY Routing Latency**
- **Base Latency**: 4 cycles (router pipeline) × hop count
- **Network Diameter**: 14 hops maximum
- **Worst-case Latency**: 4 × 14 = 56 cycles
- **Average Latency**: ~4 × 7 = 28 cycles

#### **Adaptive Routing Latency**
- **Base Latency**: Same as XY routing
- **Additional Delay**: 0-1 cycles for congestion computation
- **Congestion Benefit**: Can reduce queuing delay significantly
- **Net Improvement**: 10-30% under high load

### **Throughput Analysis**

#### **Saturation Throughput**
- **Per Port**: 1 flit/cycle (ideal)
- **Network Aggregate**: 64 flits/cycle
- **Effective Throughput**: 0.6-0.9 flits/cycle depending on pattern

#### **Load Balance Effect**
- **XY Routing**: Can create hotspots, uneven utilization
- **Adaptive Routing**: Better load distribution, higher utilization
- **Improvement**: 15-25% better throughput under adversarial patterns

---

## ⚙️ **Routing Configuration**

### **Configuration Parameters**
```systemverilog
// Routing configuration
typedef struct packed {
    logic        adaptive_enable;        // Enable adaptive routing
    logic        congestion_threshold;  // Congestion threshold
    logic [1:0]  routing_algorithm;     // 00=XY, 01=WestFirst, 10=OddEven, 11=Adaptive
    logic        fault_tolerance_enable;// Enable fault tolerance
    logic        multicast_enable;       // Enable multicast routing
} routing_config_t;
```

### **Runtime Reconfiguration**
- **Algorithm Selection**: Switch between routing algorithms
- **Adaptation Level**: Adjust congestion sensitivity
- **Fault Recovery**: Enable/disable fault tolerance
- **QoS Support**: Priority-based routing decisions

---

## 🧪 **Routing Verification**

### **Test Scenarios**

#### **Correctness Tests**
- **Single Source-Destination**: Verify correct routing
- **All-Pairs Testing**: Test every source-destination pair
- **Boundary Conditions**: Edge nodes, corner cases
- **Random Traffic**: Monte Carlo testing

#### **Deadlock Tests**
- **Cycle Creation**: Intentionally create potential deadlocks
- **Resource Exhaustion**: Fill buffers to capacity
- **Concurrent Access**: Multiple competing flows
- **Stress Testing**: Sustained high load

#### **Performance Tests**
- **Latency Measurement**: End-to-end latency under various loads
- **Throughput Measurement**: Maximum sustainable throughput
- **Congestion Response**: Behavior under congested conditions
- **Fault Recovery**: Performance with failed components

### **Coverage Metrics**
- **Code Coverage**: >95% of routing logic
- **Functional Coverage**: All routing paths tested
- **Corner Case Coverage**: Edge conditions, error cases
- **Performance Coverage**: Wide range of traffic patterns

---

## 📈 **Routing Optimization**

### **Hardware Optimization**
- **Parallel Computation**: Compute multiple routes simultaneously
- **Pipeline Routing**: Route computation in pipeline stages
- **Pre-computed Tables**: Cache frequently used routes
- **Approximate Logic**: Simplify congestion metrics

### **Algorithm Optimization**
- **Hybrid Routing**: Combine deterministic and adaptive
- **Hierarchical Routing**: Different algorithms for different regions
- **Predictive Routing**: Use history to predict congestion
- **Machine Learning**: Advanced congestion prediction

---

## 📝 **Routing Decision Log**

| Algorithm | Status | Reason | Alternatives Considered |
|-----------|---------|---------|--------------------------|
| XY Routing | ✅ Primary | Deadlock-free, simple | Adaptive, hierarchical |
| West-First | ⏳ Option | Adaptive alternative | Odd-Even, fully adaptive |
| Multicast | ⏳ Planned | Group communication | Multiple unicast |
| Fault-Tolerance | ⏳ Future | Reliability requirement | Degraded operation |

---

**Document Version**: 1.0
**Last Updated**: 2025-11-04
**Next Review Date**: __/__/____
**Approved By**: ________________