// ====================================================================
// MAZE Network Node - Packet Generation Utilities Implementation
// ====================================================================

#include "packet_generator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// ====================================================================
// PacketGenerator Constructor
// ====================================================================
PacketGenerator::PacketGenerator(uint32_t seed, const PacketGenConfig& config)
    : rng_(seed), config_(config), total_packets_generated_(0),
      byte_dist_(0, 255), coord_dist_(0, 7), type_dist_(0, 3), qos_dist_(0, 1),
      current_src_x_(0), current_src_y_(0) {

    // Initialize statistics
    packet_counts_[TrafficPattern::UNICAST] = 0;
    packet_counts_[TrafficPattern::X_MULTICAST] = 0;
    packet_counts_[TrafficPattern::Y_MULTICAST] = 0;
    packet_counts_[TrafficPattern::BROADCAST] = 0;
    packet_counts_[TrafficPattern::LOCAL_DELIVERY] = 0;
    packet_counts_[TrafficPattern::MIXED] = 0;
    packet_counts_[TrafficPattern::STRESS] = 0;
    packet_counts_[TrafficPattern::BURSTY] = 0;

    cout << "[PacketGen] Initialized with seed " << seed << endl;
}

// ====================================================================
// Main Packet Generation Methods
// ====================================================================

MazePacket PacketGenerator::generate_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;

    // Generate packet type based on configuration
    packet.type = get_random_packet_type();

    // Generate source coordinates
    tie(packet.src_x, packet.src_y) = get_random_coordinate();

    // Generate target coordinates based on packet type
    switch (packet.type) {
        case 0: // Unicast
            packet = generate_unicast_packet(test_id, cycle);
            break;
        case 1: // X-Multicast
            packet = generate_x_multicast_packet(test_id, cycle);
            break;
        case 2: // Y-Multicast
            packet = generate_y_multicast_packet(test_id, cycle);
            break;
        case 3: // Broadcast
            packet = generate_broadcast_packet(test_id, cycle);
            break;
        default:
            packet = generate_unicast_packet(test_id, cycle);
            break;
    }

    // Generate QoS level
    packet.qos = get_random_qos();

    // Generate random data payload
    packet.data = byte_dist_(rng_);

    // Set metadata
    packet.test_id = test_id;
    packet.inject_cycle = cycle;

    // Encode packet
    packet.encode_packet();

    // Verify constraints
    if (!verify_packet_constraints(packet)) {
        cout << "[WARNING] Generated packet violates constraints: " << packet.to_string() << endl;
    }

    // Update statistics
    TrafficPattern pattern = TrafficPattern::MIXED;
    switch (packet.type) {
        case 0: pattern = (packet.is_local_delivery()) ? TrafficPattern::LOCAL_DELIVERY : TrafficPattern::UNICAST; break;
        case 1: pattern = TrafficPattern::X_MULTICAST; break;
        case 2: pattern = TrafficPattern::Y_MULTICAST; break;
        case 3: pattern = TrafficPattern::BROADCAST; break;
    }
    update_statistics(pattern);

    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_unicast_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;
    packet.type = 0; // Unicast

    // Use current source position if set
    if (config_.enable_coordinate_constraints) {
        packet.src_x = current_src_x_;
        packet.src_y = current_src_y_;
    } else {
        tie(packet.src_x, packet.src_y) = get_random_coordinate();
    }

    // Generate target coordinate
    do {
        if (config_.prefer_nearby_targets && (byte_dist_(rng_) % 100) < (config_.nearby_probability * 100)) {
            tie(packet.tgt_x, packet.tgt_y) = get_nearby_coordinate(packet.src_x, packet.src_y);
        } else {
            tie(packet.tgt_x, packet.tgt_y) = get_random_coordinate();
        }
    } while ((packet.src_x == packet.tgt_x) && (packet.src_y == packet.tgt_y)); // Ensure source != target

    // Set metadata and encode
    packet.qos = get_random_qos();
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;
    packet.encode_packet();

    update_statistics(TrafficPattern::UNICAST);
    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_x_multicast_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;
    packet.type = 1; // X-Multicast

    // Generate source position
    if (config_.enable_coordinate_constraints) {
        packet.src_x = current_src_x_;
        packet.src_y = current_src_y_;
    } else {
        tie(packet.src_x, packet.src_y) = get_random_coordinate();
    }

    // X-Multicast: target X coordinate matches source X, Y can be anything
    packet.tgt_x = packet.src_x;
    packet.tgt_y = coord_dist_(rng_);

    // Set metadata and encode
    packet.qos = get_random_qos();
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;
    packet.encode_packet();

    update_statistics(TrafficPattern::X_MULTICAST);
    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_y_multicast_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;
    packet.type = 2; // Y-Multicast

    // Generate source position
    if (config_.enable_coordinate_constraints) {
        packet.src_x = current_src_x_;
        packet.src_y = current_src_y_;
    } else {
        tie(packet.src_x, packet.src_y) = get_random_coordinate();
    }

    // Y-Multicast: target Y coordinate matches source Y, X can be anything
    packet.tgt_y = packet.src_y;
    packet.tgt_x = coord_dist_(rng_);

    // Set metadata and encode
    packet.qos = get_random_qos();
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;
    packet.encode_packet();

    update_statistics(TrafficPattern::Y_MULTICAST);
    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_broadcast_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;
    packet.type = 3; // Broadcast

    // Generate source position
    if (config_.enable_coordinate_constraints) {
        packet.src_x = current_src_x_;
        packet.src_y = current_src_y_;
    } else {
        tie(packet.src_x, packet.src_y) = get_random_coordinate();
    }

    // Broadcast: target coordinates don't matter, but set to something reasonable
    packet.tgt_x = coord_dist_(rng_);
    packet.tgt_y = coord_dist_(rng_);

    // Set metadata and encode
    packet.qos = get_random_qos();
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;
    packet.encode_packet();

    update_statistics(TrafficPattern::BROADCAST);
    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_local_delivery_packet(const string& test_id, uint64_t cycle) {
    MazePacket packet;
    packet.type = 0; // Unicast (but with source = target)

    // Generate source position
    if (config_.enable_coordinate_constraints) {
        packet.src_x = current_src_x_;
        packet.src_y = current_src_y_;
    } else {
        tie(packet.src_x, packet.src_y) = get_random_coordinate();
    }

    // Local delivery: target equals source
    packet.tgt_x = packet.src_x;
    packet.tgt_y = packet.src_y;

    // Set metadata and encode
    packet.qos = get_random_qos();
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;
    packet.encode_packet();

    update_statistics(TrafficPattern::LOCAL_DELIVERY);
    total_packets_generated_++;

    return packet;
}

MazePacket PacketGenerator::generate_directed_packet(uint32_t src_x, uint32_t src_y,
                                                    uint32_t tgt_x, uint32_t tgt_y,
                                                    uint32_t type, uint32_t qos,
                                                    const string& test_id, uint64_t cycle) {
    MazePacket packet;

    // Set coordinates and fields
    packet.src_x = clamp_coord(src_x);
    packet.src_y = clamp_coord(src_y);
    packet.tgt_x = clamp_coord(tgt_x);
    packet.tgt_y = clamp_coord(tgt_y);
    packet.type = type & 0x3;
    packet.qos = qos & 0x1;
    packet.data = byte_dist_(rng_);
    packet.test_id = test_id;
    packet.inject_cycle = cycle;

    // Encode packet
    packet.encode_packet();

    // Update statistics
    TrafficPattern pattern = TrafficPattern::MIXED;
    switch (packet.type) {
        case 0: pattern = (packet.is_local_delivery()) ? TrafficPattern::LOCAL_DELIVERY : TrafficPattern::UNICAST; break;
        case 1: pattern = TrafficPattern::X_MULTICAST; break;
        case 2: pattern = TrafficPattern::Y_MULTICAST; break;
        case 3: pattern = TrafficPattern::BROADCAST; break;
    }
    update_statistics(pattern);

    total_packets_generated_++;

    return packet;
}

vector<MazePacket> PacketGenerator::generate_packet_sequence(uint32_t count, TrafficPattern pattern,
                                                             const string& test_id) {
    vector<MazePacket> packets;
    packets.reserve(count);

    for (uint32_t i = 0; i < count; i++) {
        MazePacket packet;
        uint64_t cycle = i * get_inter_packet_gap();

        switch (pattern) {
            case TrafficPattern::UNICAST:
                packet = generate_unicast_packet(test_id, cycle);
                break;
            case TrafficPattern::X_MULTICAST:
                packet = generate_x_multicast_packet(test_id, cycle);
                break;
            case TrafficPattern::Y_MULTICAST:
                packet = generate_y_multicast_packet(test_id, cycle);
                break;
            case TrafficPattern::BROADCAST:
                packet = generate_broadcast_packet(test_id, cycle);
                break;
            case TrafficPattern::LOCAL_DELIVERY:
                packet = generate_local_delivery_packet(test_id, cycle);
                break;
            case TrafficPattern::STRESS:
                // Maximum intensity - minimal gap
                cycle = i;
                packet = generate_packet(test_id, cycle);
                break;
            case TrafficPattern::BURSTY:
                // Generate bursts with gaps
                if ((i % config_.burst_length) == 0) {
                    cycle += config_.max_inter_packet_gap; // Gap between bursts
                }
                packet = generate_packet(test_id, cycle);
                break;
            case TrafficPattern::MIXED:
            default:
                packet = generate_packet(test_id, cycle);
                break;
        }

        packets.push_back(packet);
    }

    update_statistics(pattern);
    return packets;
}

// ====================================================================
// Constraint and Verification Methods
// ====================================================================

void PacketGenerator::set_faulted_node(uint32_t faulted_node) {
    config_.faulted_node = faulted_node;
    cout << "[PacketGen] Set faulted node to: " << faulted_node << endl;
}

void PacketGenerator::set_source_position(uint32_t src_x, uint32_t src_y) {
    current_src_x_ = clamp_coord(src_x);
    current_src_y_ = clamp_coord(src_y);
    cout << "[PacketGen] Set source position to: (" << current_src_x_ << "," << current_src_y_ << ")" << endl;
}

bool PacketGenerator::verify_packet_constraints(const MazePacket& packet) const {
    // Check coordinate ranges
    if (packet.src_x >= 8 || packet.src_y >= 8 || packet.tgt_x >= 8 || packet.tgt_y >= 8) {
        return false;
    }

    // Check type range
    if (packet.type >= 4) {
        return false;
    }

    // Check QoS range
    if (packet.qos >= 2) {
        return false;
    }

    // Check data range
    if (packet.data >= 256) {
        return false;
    }

    // Check fault avoidance if enabled
    if (config_.enable_fault_aware_routing && config_.faulted_node < 64) {
        if (!route_avoids_fault(packet, config_.faulted_node)) {
            // This is a warning, not a failure - sometimes we want to test fault scenarios
            cout << "[WARNING] Packet routes through faulted node: " << packet.to_string() << endl;
        }
    }

    return true;
}

pair<uint32_t, uint32_t> PacketGenerator::calculate_intermediate_node(const MazePacket& packet) const {
    if (packet.type != 0) { // Not unicast
        return make_pair(packet.src_x, packet.src_y);
    }

    // Calculate two intermediate nodes for unicast
    uint32_t int1_x = packet.tgt_x;
    uint32_t int1_y = packet.src_y;
    uint32_t int1_coord = (int1_y << 3) | int1_x;

    uint32_t int2_x = packet.src_x;
    uint32_t int2_y = packet.tgt_y;
    uint32_t int2_coord = (int2_y << 3) | int2_x;

    // Select intermediate node based on fault avoidance
    if (config_.enable_fault_aware_routing && config_.faulted_node < 64) {
        if (config_.faulted_node == int1_coord) {
            return make_pair(int2_x, int2_y);
        } else {
            return make_pair(int1_x, int1_y);
        }
    } else {
        // Default to first intermediate node
        return make_pair(int1_x, int1_y);
    }
}

bool PacketGenerator::route_avoids_fault(const MazePacket& packet, uint32_t faulted_node) const {
    if (packet.type != 0 || faulted_node >= 64) {
        return true; // Not applicable
    }

    // Extract faulted node coordinates
    uint32_t fault_x = faulted_node & 0x7;
    uint32_t fault_y = (faulted_node >> 3) & 0x7;

    // Check if source or target is faulted (not a routing issue, but system issue)
    if ((packet.src_x == fault_x && packet.src_y == fault_y) ||
        (packet.tgt_x == fault_x && packet.tgt_y == fault_y)) {
        return false;
    }

    // Calculate intermediate nodes
    auto intermediate = calculate_intermediate_node(packet);

    // Check if intermediate node is faulted
    if (intermediate.first == fault_x && intermediate.second == fault_y) {
        return false;
    }

    return true;
}

// ====================================================================
// Utility Methods
// ====================================================================

pair<uint32_t, uint32_t> PacketGenerator::get_random_coordinate() const {
    return make_pair(coord_dist_(rng_), coord_dist_(rng_));
}

pair<uint32_t, uint32_t> PacketGenerator::get_nearby_coordinate(uint32_t src_x, uint32_t src_y) const {
    // Generate nearby coordinates with preference for small Manhattan distances
    uniform_int_distribution<uint32_t> dist_dist(1, 3); // Distance 1-3
    uniform_int_distribution<uint32_t> direction_dist(0, 3); // 4 directions

    uint32_t distance = dist_dist(rng_);
    uint32_t direction = direction_dist(rng_);

    uint32_t tgt_x = src_x;
    uint32_t tgt_y = src_y;

    switch (direction) {
        case 0: tgt_x = (src_x + distance) % 8; break; // East
        case 1: tgt_x = (src_x + 8 - distance) % 8; break; // West
        case 2: tgt_y = (src_y + distance) % 8; break; // South
        case 3: tgt_y = (src_y + 8 - distance) % 8; break; // North
    }

    return make_pair(tgt_x, tgt_y);
}

uint32_t PacketGenerator::manhattan_distance(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) const {
    uint32_t dx = abs((int)x1 - (int)x2);
    uint32_t dy = abs((int)y1 - (int)y2);
    return dx + dy;
}

uint32_t PacketGenerator::get_inter_packet_gap() const {
    uniform_int_distribution<uint32_t> gap_dist(config_.min_inter_packet_gap, config_.max_inter_packet_gap);
    return gap_dist(rng_);
}

uint32_t PacketGenerator::get_random_qos() const {
    if (config_.enable_qos_constraints) {
        double probability = (double)byte_dist_(rng_) / 255.0;
        return (probability < config_.high_qos_ratio) ? 1 : 0;
    } else {
        return qos_dist_(rng_);
    }
}

uint32_t PacketGenerator::get_random_packet_type() const {
    if (config_.enable_type_constraints) {
        double probability = (double)byte_dist_(rng_) / 255.0;

        if (probability < config_.unicast_ratio) {
            return 0; // Unicast
        } else if (probability < config_.unicast_ratio + config_.multicast_ratio) {
            return (byte_dist_(rng_) % 2) + 1; // X or Y multicast
        } else {
            return 3; // Broadcast
        }
    } else {
        return type_dist_(rng_);
    }
}

// ====================================================================
// Statistics and Reporting
// ====================================================================

void PacketGenerator::reset_statistics() {
    for (auto& count : packet_counts_) {
        count.second = 0;
    }
    total_packets_generated_ = 0;
    used_coord_pairs_.clear();
}

void PacketGenerator::print_statistics() const {
    cout << "\n" << string(60, '=') << endl;
    cout << "Packet Generator Statistics" << endl;
    cout << string(60, '=') << endl;

    cout << "Total packets generated: " << total_packets_generated_ << endl;
    cout << "Unique coordinate pairs used: " << used_coord_pairs_.size() << endl;

    cout << "\nPacket type distribution:" << endl;
    for (const auto& count : packet_counts_) {
        if (count.second > 0) {
            double percentage = (double)count.second / total_packets_generated_ * 100.0;
            cout << "  " << setw(15) << left;
            switch (count.first) {
                case TrafficPattern::UNICAST: cout << "Unicast"; break;
                case TrafficPattern::X_MULTICAST: cout << "X-Multicast"; break;
                case TrafficPattern::Y_MULTICAST: cout << "Y-Multicast"; break;
                case TrafficPattern::BROADCAST: cout << "Broadcast"; break;
                case TrafficPattern::LOCAL_DELIVERY: cout << "Local Delivery"; break;
                case TrafficPattern::MIXED: cout << "Mixed"; break;
                case TrafficPattern::STRESS: cout << "Stress"; break;
                case TrafficPattern::BURSTY: cout << "Bursty"; break;
            }
            cout << ": " << setw(8) << count.second
                 << " (" << fixed << setprecision(1) << percentage << "%)" << endl;
        }
    }
    cout << string(60, '=') << endl;
}

bool PacketGenerator::export_packets_to_file(const vector<MazePacket>& packets, const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << "# MAZE Network Packet Export" << endl;
    file << "# Format: Type,QoS,SrcX,SrcY,TgtX,TgtY,Data,TestID,Cycle" << endl;

    for (const auto& packet : packets) {
        file << packet.type << ","
             << packet.qos << ","
             << packet.src_x << ","
             << packet.src_y << ","
             << packet.tgt_x << ","
             << packet.tgt_y << ","
             << hex << "0x" << packet.data << dec << ","
             << packet.test_id << ","
             << packet.inject_cycle << endl;
    }

    file.close();
    return true;
}

vector<MazePacket> PacketGenerator::import_packets_from_file(const string& filename) {
    vector<MazePacket> packets;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "[ERROR] Cannot open packet file: " << filename << endl;
        return packets;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue; // Skip comments and empty lines

        stringstream ss(line);
        string field;
        vector<string> fields;

        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() >= 9) {
            MazePacket packet;
            packet.type = stoi(fields[0]);
            packet.qos = stoi(fields[1]);
            packet.src_x = stoi(fields[2]);
            packet.src_y = stoi(fields[3]);
            packet.tgt_x = stoi(fields[4]);
            packet.tgt_y = stoi(fields[5]);
            packet.data = stoi(fields[6]);
            packet.test_id = fields[7];
            packet.inject_cycle = stoull(fields[8]);

            packet.encode_packet();
            packets.push_back(packet);
        }
    }

    file.close();
    cout << "[PacketGen] Imported " << packets.size() << " packets from " << filename << endl;
    return packets;
}

void PacketGenerator::update_statistics(TrafficPattern pattern) {
    packet_counts_[pattern]++;
}

// ====================================================================
// Utility Functions
// ====================================================================

string packet_type_to_string(uint32_t type) {
    switch (type) {
        case 0: return "Unicast";
        case 1: return "X-Multicast";
        case 2: return "Y-Multicast";
        case 3: return "Broadcast";
        default: return "Unknown";
    }
}

string qos_to_string(uint32_t qos) {
    return (qos == 1) ? "High" : "Low";
}

bool validate_packet_format(const MazePacket& packet) {
    return (packet.type < 4) && (packet.qos < 2) &&
           (packet.src_x < 8) && (packet.src_y < 8) &&
           (packet.tgt_x < 8) && (packet.tgt_y < 8) &&
           (packet.data < 256);
}

uint32_t calculate_expected_latency(const MazePacket& packet, bool has_backpressure) {
    uint32_t base_latency = 4; // 4 pipeline stages

    if (packet.type == 0) { // Unicast
        base_latency += 2; // Two hops
        if (packet.is_local_delivery()) {
            base_latency = 4; // Local delivery is faster
        }
    } else { // Multicast/Broadcast
        base_latency += 1; // One hop for replication
    }

    if (has_backpressure) {
        base_latency += 2; // Additional latency due to backpressure
    }

    return base_latency;
}

vector<MazePacket> generate_basic_test_set(uint32_t src_x, uint32_t src_y) {
    PacketGenConfig config;
    config.enable_coordinate_constraints = true;
    PacketGenerator gen(54321, config);
    gen.set_source_position(src_x, src_y);

    vector<MazePacket> test_set;

    // Basic unicast to various directions
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+1)%8, src_y, 0, 0, "basic_unicast_east"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+7)%8, src_y, 0, 1, "basic_unicast_west"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, src_x, (src_y+1)%8, 0, 0, "basic_unicast_south"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, src_x, (src_y+7)%8, 0, 1, "basic_unicast_north"));

    // Local delivery
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, src_x, src_y, 0, 0, "local_delivery"));

    // Multicast tests
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, src_x, (src_y+2)%8, 1, 1, "x_multicast"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+3)%8, src_y, 2, 0, "y_multicast"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+1)%8, (src_y+1)%8, 3, 1, "broadcast"));

    return test_set;
}

vector<MazePacket> generate_qos_test_set(uint32_t src_x, uint32_t src_y) {
    PacketGenConfig config;
    config.enable_coordinate_constraints = true;
    PacketGenerator gen(54322, config);
    gen.set_source_position(src_x, src_y);

    vector<MazePacket> test_set;

    // High priority unicast
    for (int i = 0; i < 3; i++) {
        test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+1)%8, (src_y+i)%8, 0, 1, "high_qos_unicast"));
    }

    // Low priority unicast
    for (int i = 0; i < 3; i++) {
        test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+2)%8, (src_y+i)%8, 0, 0, "low_qos_unicast"));
    }

    // Mixed priority test
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+3)%8, (src_y+1)%8, 0, 1, "mixed_high"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (src_x+3)%8, (src_y+2)%8, 0, 0, "mixed_low"));

    return test_set;
}

vector<MazePacket> generate_fault_test_set(uint32_t src_x, uint32_t src_y, uint32_t faulted_node) {
    PacketGenConfig config;
    config.enable_coordinate_constraints = true;
    config.enable_fault_aware_routing = true;
    PacketGenerator gen(54323, config);
    gen.set_source_position(src_x, src_y);
    gen.set_faulted_node(faulted_node);

    vector<MazePacket> test_set;

    // Route that would normally go through faulted node
    uint32_t fault_x = faulted_node & 0x7;
    uint32_t fault_y = (faulted_node >> 3) & 0x7;

    // Test cases that need to avoid the faulted node
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, fault_x, fault_y, 0, 1, "route_to_faulted"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, (fault_x+1)%8, fault_y, 0, 0, "route_near_faulted"));
    test_set.push_back(gen.generate_directed_packet(src_x, src_y, fault_x, (fault_y+1)%8, 0, 1, "route_around_faulted"));

    return test_set;
}