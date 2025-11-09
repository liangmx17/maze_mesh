// ====================================================================
// MAZE Network Node - Packet Generation Utilities
// ====================================================================
//
// Comprehensive packet generation for the 23-bit MAZE packet format
// Supports constrained random generation with various traffic patterns
//
// Packet Format: [22:21]=type, [20]=qos, [19:14]=src, [13:8]=tgt, [7:0]=data
//   - Type: 00=Unicast, 01=X-Multicast, 10=Y-Multicast, 11=Broadcast
//   - QoS: 0=Low Priority, 1=High Priority
//   - Src/Target: 6-bit coordinates [5:3]=Y, [2:0]=X
//   - Data: 8-bit payload
//
// ====================================================================

#ifndef PACKET_GENERATOR_H
#define PACKET_GENERATOR_H

#include <cstdint>
#include <vector>
#include <random>
#include <map>
#include <string>

using namespace std;

// ====================================================================
// Packet Structure Definition
// ====================================================================
struct MazePacket {
    uint32_t type;        // 2 bits: packet type
    uint32_t qos;         // 1 bit: quality of service
    uint32_t src_x;       // 3 bits: source X coordinate [0-7]
    uint32_t src_y;       // 3 bits: source Y coordinate [0-7]
    uint32_t tgt_x;       // 3 bits: target X coordinate [0-7]
    uint32_t tgt_y;       // 3 bits: target Y coordinate [0-7]
    uint32_t data;        // 8 bits: payload data
    uint32_t raw_23bit;   // Combined 23-bit packet

    // Timing and tracking information
    uint64_t inject_cycle;    // Cycle when packet was injected
    uint64_t receive_cycle;   // Cycle when packet was received
    string test_id;           // Associated test identifier

    MazePacket() : type(0), qos(0), src_x(0), src_y(0), tgt_x(0), tgt_y(0),
                   data(0), raw_23bit(0), inject_cycle(0), receive_cycle(0) {}

    // Construct from 23-bit packet
    MazePacket(uint32_t packet, const string& test_id = "", uint64_t cycle = 0)
        : raw_23bit(packet & 0x7FFFFF), test_id(test_id), inject_cycle(cycle), receive_cycle(0) {
        decode_packet();
    }

    // Get 6-bit source coordinate
    uint32_t get_src_coord() const { return (src_y << 3) | src_x; }

    // Get 6-bit target coordinate
    uint32_t get_tgt_coord() const { return (tgt_y << 3) | tgt_x; }

    // Check if this is local delivery (source = target)
    bool is_local_delivery() const { return (src_x == tgt_x) && (src_y == tgt_y); }

    // Check if this is unicast
    bool is_unicast() const { return type == 0; }

    // Check if this is multicast/broadcast
    bool is_multicast() const { return type > 0; }

    // Encode packet fields into 23-bit format
    void encode_packet() {
        raw_23bit = ((type & 0x3) << 21) |
                    ((qos & 0x1) << 20) |
                    ((get_src_coord() & 0x3F) << 14) |
                    ((get_tgt_coord() & 0x3F) << 8) |
                    (data & 0xFF);
    }

    // Decode 23-bit packet into fields
    void decode_packet() {
        type = (raw_23bit >> 21) & 0x3;
        qos = (raw_23bit >> 20) & 0x1;
        uint32_t src_coord = (raw_23bit >> 14) & 0x3F;
        uint32_t tgt_coord = (raw_23bit >> 8) & 0x3F;
        src_x = src_coord & 0x7;
        src_y = (src_coord >> 3) & 0x7;
        tgt_x = tgt_coord & 0x7;
        tgt_y = (tgt_coord >> 3) & 0x7;
        data = raw_23bit & 0xFF;
    }

    // Get string representation
    string to_string() const {
        return "Packet[type=" + std::to_string(type) +
               ", qos=" + std::to_string(qos) +
               ", src=(" + std::to_string(src_x) + "," + std::to_string(src_y) + ")" +
               ", tgt=(" + std::to_string(tgt_x) + "," + std::to_string(tgt_y) + ")" +
               ", data=0x" + std::to_string(data) + "]";
    }

    // Compare packets for equality (ignoring timing fields)
    bool equals(const MazePacket& other) const {
        return (type == other.type) && (qos == other.qos) &&
               (src_x == other.src_x) && (src_y == other.src_y) &&
               (tgt_x == other.tgt_x) && (tgt_y == other.tgt_y) &&
               (data == other.data);
    }
};

// ====================================================================
// Traffic Pattern Definitions
// ====================================================================
enum class TrafficPattern {
    UNICAST,           // Point-to-point unicast traffic
    X_MULTICAST,       // X-direction multicast
    Y_MULTICAST,       // Y-direction multicast
    BROADCAST,         // Network-wide broadcast
    LOCAL_DELIVERY,    // Source equals target
    MIXED,             // Mixed traffic patterns
    STRESS,            // High-intensity stress test
    BURSTY             // Bursty traffic pattern
};

// ====================================================================
// Packet Generator Configuration
// ====================================================================
struct PacketGenConfig {
    // Traffic pattern distribution
    double unicast_ratio = 0.6;
    double multicast_ratio = 0.2;
    double broadcast_ratio = 0.1;
    double local_delivery_ratio = 0.1;

    // QoS distribution
    double high_qos_ratio = 0.3;
    double low_qos_ratio = 0.7;

    // Spatial distribution preferences
    bool prefer_nearby_targets = true;     // Prefer nearby targets for unicast
    double nearby_probability = 0.7;       // Probability of choosing nearby target

    // Timing patterns
    uint32_t min_inter_packet_gap = 1;     // Minimum cycles between packets
    uint32_t max_inter_packet_gap = 10;    // Maximum cycles between packets
    uint32_t burst_length = 3;             // Packets per burst for bursty traffic

    // Constraint settings
    bool enable_coordinate_constraints = true;
    bool enable_qos_constraints = true;
    bool enable_type_constraints = true;

    // Fault injection
    bool enable_fault_aware_routing = true;
    uint32_t faulted_node = 64;            // Invalid initial value (no fault)

    PacketGenConfig() {}
};

// ====================================================================
// Main Packet Generator Class
// ====================================================================
class PacketGenerator {
private:
    // Random number generation
    mt19937 rng_;
    uniform_int_distribution<uint32_t> byte_dist_;
    uniform_int_distribution<uint32_t> coord_dist_;
    uniform_int_distribution<uint32_t> type_dist_;
    uniform_int_distribution<uint32_t> qos_dist_;

    // Configuration
    PacketGenConfig config_;

    // Statistics tracking
    map<TrafficPattern, uint64_t> packet_counts_;
    uint64_t total_packets_generated_;

    // Used coordinate tracking for diversity
    vector<pair<uint32_t, uint32_t>> used_coord_pairs_;

public:
    explicit PacketGenerator(uint32_t seed = 12345, const PacketGenConfig& config = PacketGenConfig());

    // ====================================================================
    // Main Packet Generation Methods
    // ====================================================================

    // Generate single random packet
    MazePacket generate_packet(const string& test_id = "", uint64_t cycle = 0);

    // Generate packet with specific type
    MazePacket generate_unicast_packet(const string& test_id = "", uint64_t cycle = 0);
    MazePacket generate_x_multicast_packet(const string& test_id = "", uint64_t cycle = 0);
    MazePacket generate_y_multicast_packet(const string& test_id = "", uint64_t cycle = 0);
    MazePacket generate_broadcast_packet(const string& test_id = "", uint64_t cycle = 0);
    MazePacket generate_local_delivery_packet(const string& test_id = "", uint64_t cycle = 0);

    // Generate packet from specific source to specific target
    MazePacket generate_directed_packet(uint32_t src_x, uint32_t src_y,
                                       uint32_t tgt_x, uint32_t tgt_y,
                                       uint32_t type = 0, uint32_t qos = 0,
                                       const string& test_id = "", uint64_t cycle = 0);

    // Generate packet sequence
    vector<MazePacket> generate_packet_sequence(uint32_t count, TrafficPattern pattern,
                                               const string& test_id = "");

    // ====================================================================
    // Constraint and Verification Methods
    // ====================================================================

    // Set fault configuration for routing constraints
    void set_faulted_node(uint32_t faulted_node);

    // Set source node position (for coordinate-aware generation)
    void set_source_position(uint32_t src_x, uint32_t src_y);

    // Verify packet meets constraints
    bool verify_packet_constraints(const MazePacket& packet) const;

    // Calculate intermediate node for unicast routing
    pair<uint32_t, uint32_t> calculate_intermediate_node(const MazePacket& packet) const;

    // Check if route avoids faulted node
    bool route_avoids_fault(const MazePacket& packet, uint32_t faulted_node) const;

    // ====================================================================
    // Utility Methods
    // ====================================================================

    // Get random coordinate with constraints
    pair<uint32_t, uint32_t> get_random_coordinate() const;

    // Get nearby coordinate relative to source
    pair<uint32_t, uint32_t> get_nearby_coordinate(uint32_t src_x, uint32_t src_y) const;

    // Calculate Manhattan distance
    uint32_t manhattan_distance(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) const;

    // Generate timing pattern
    uint32_t get_inter_packet_gap() const;

    // Get random QoS level
    uint32_t get_random_qos() const;

    // Get random packet type based on configuration
    uint32_t get_random_packet_type() const;

    // ====================================================================
    // Statistics and Reporting
    // ====================================================================

    // Get generation statistics
    map<TrafficPattern, uint64_t> get_packet_counts() const { return packet_counts_; }
    uint64_t get_total_packets_generated() const { return total_packets_generated_; }

    // Reset statistics
    void reset_statistics();

    // Print statistics
    void print_statistics() const;

    // Export packet list to file
    bool export_packets_to_file(const vector<MazePacket>& packets, const string& filename) const;

    // Import packet list from file
    vector<MazePacket> import_packets_from_file(const string& filename);

private:
    uint32_t current_src_x_;
    uint32_t current_src_y_;

    // Helper methods
    uint32_t clamp_coord(uint32_t coord) const { return coord & 0x7; }
    bool is_valid_coordinate(uint32_t x, uint32_t y) const { return (x < 8) && (y < 8); }
    void update_statistics(TrafficPattern pattern);
};

// ====================================================================
// Utility Functions
// ====================================================================

// Convert packet type to string
string packet_type_to_string(uint32_t type);

// Convert QoS level to string
string qos_to_string(uint32_t qos);

// Validate packet format
bool validate_packet_format(const MazePacket& packet);

// Calculate expected latency for packet type
uint32_t calculate_expected_latency(const MazePacket& packet, bool has_backpressure = false);

// Generate test packet set for specific scenarios
vector<MazePacket> generate_basic_test_set(uint32_t src_x, uint32_t src_y);
vector<MazePacket> generate_qos_test_set(uint32_t src_x, uint32_t src_y);
vector<MazePacket> generate_fault_test_set(uint32_t src_x, uint32_t src_y, uint32_t faulted_node);

#endif // PACKET_GENERATOR_H