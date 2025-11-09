// ====================================================================
// MAZE Network Node - Common Packet Utilities
// ====================================================================
//
// Shared packet generation and validation utilities for all focused tests
// Supports 23-bit MAZE packet format with comprehensive coverage
//
// Packet Format:
// [22:21] pkt_type    // 00=Unicast, 01=X-Multicast, 10=Y-Multicast, 11=Broadcast
// [20]    pkt_qos     // 0=Low Priority, 1=High Priority
// [19:14] src_y       // Source node Y coordinate (6 bits)
// [13:8]  src_x       // Source node X coordinate (6 bits)
// [7:2]   tgt_y       // Target node Y coordinate (6 bits)
// [1:0]   tgt_x       // Target node X coordinate (2 bits for local, extended for full target)
// [7:0]   pkt_data    // Data payload (when using full 23-bit format)
//
// ====================================================================

#ifndef PACKET_UTILS_H
#define PACKET_UTILS_H

#include <cstdint>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;

// ====================================================================
// Packet Structure and Constants
// ====================================================================

struct Packet {
    uint32_t data;           // 23-bit packet data
    string description;      // Human readable description
    uint32_t src_x, src_y;   // Source coordinates
    uint32_t tgt_x, tgt_y;   // Target coordinates
    uint32_t pkt_type;       // Packet type
    uint32_t pkt_qos;        // QoS level
    uint32_t pkt_data;       // Payload data

    Packet() : data(0), src_x(0), src_y(0), tgt_x(0), tgt_y(0),
               pkt_type(0), pkt_qos(0), pkt_data(0) {}

    bool operator==(const Packet& other) const {
        return data == other.data;
    }
};

// Packet type constants
enum PacketType {
    UNICAST     = 0x0,  // 00
    X_MULTICAST = 0x1,  // 01
    Y_MULTICAST = 0x2,  // 10
    BROADCAST   = 0x3   // 11
};

// QoS level constants
enum QoSLevel {
    QOS_LOW  = 0,
    QOS_HIGH = 1
};

// ====================================================================
// Packet Utility Class
// ====================================================================

class PacketUtils {
public:
    // =================================================================
    // Packet Construction Functions
    // =================================================================

    // Create unicast packet
    static uint32_t create_unicast_packet(uint32_t src_x, uint32_t src_y,
                                          uint32_t tgt_x, uint32_t tgt_y,
                                          uint32_t data = 0xA5, QoSLevel qos = QOS_LOW) {
        uint32_t pkt = 0;
        pkt |= ((UNICAST & 0x3) << 21);        // Packet type [22:21]
        pkt |= ((qos & 0x1) << 20);           // QoS [20]
        pkt |= ((src_y & 0x3F) << 14);        // Source Y [19:14]
        pkt |= ((src_x & 0x3F) << 8);         // Source X [13:8]
        pkt |= ((tgt_y & 0x3F) << 2);         // Target Y [7:2]
        pkt |= (tgt_x & 0x3);                 // Target X [1:0] - lower 2 bits
        pkt |= ((data & 0xFF) << 8);          // Data payload [15:8] (overlaps with source)
        return pkt;
    }

    // Create multicast packet (X-direction)
    static uint32_t create_x_multicast_packet(uint32_t src_x, uint32_t src_y,
                                              uint32_t x_coord, uint32_t data = 0x55,
                                              QoSLevel qos = QOS_LOW) {
        uint32_t pkt = 0;
        pkt |= ((X_MULTICAST & 0x3) << 21);
        pkt |= ((qos & 0x1) << 20);
        pkt |= ((src_y & 0x3F) << 14);
        pkt |= ((src_x & 0x3F) << 8);
        pkt |= ((src_y & 0x3F) << 2);  // Target Y = Source Y for X-multicast
        pkt |= (x_coord & 0x3);
        pkt |= ((data & 0xFF) << 8);
        return pkt;
    }

    // Create multicast packet (Y-direction)
    static uint32_t create_y_multicast_packet(uint32_t src_x, uint32_t src_y,
                                              uint32_t y_coord, uint32_t data = 0x66,
                                              QoSLevel qos = QOS_LOW) {
        uint32_t pkt = 0;
        pkt |= ((Y_MULTICAST & 0x3) << 21);
        pkt |= ((qos & 0x1) << 20);
        pkt |= ((src_y & 0x3F) << 14);
        pkt |= ((src_x & 0x3F) << 8);
        pkt |= ((y_coord & 0x3F) << 2);
        pkt |= (src_x & 0x3);  // Target X = Source X for Y-multicast
        pkt |= ((data & 0xFF) << 8);
        return pkt;
    }

    // Create broadcast packet
    static uint32_t create_broadcast_packet(uint32_t src_x, uint32_t src_y,
                                            uint32_t data = 0xFF, QoSLevel qos = QOS_LOW) {
        uint32_t pkt = 0;
        pkt |= ((BROADCAST & 0x3) << 21);
        pkt |= ((qos & 0x1) << 20);
        pkt |= ((src_y & 0x3F) << 14);
        pkt |= ((src_x & 0x3F) << 8);
        pkt |= ((0x3F & 0x3F) << 2);  // All Y coordinates
        pkt |= (0x3);                 // All X coordinates (lower 2 bits)
        pkt |= ((data & 0xFF) << 8);
        return pkt;
    }

    // =================================================================
    // Packet Parsing Functions
    // =================================================================

    static Packet parse_packet(uint32_t packet_data) {
        Packet pkt;
        pkt.data = packet_data;

        pkt.pkt_type = (packet_data >> 21) & 0x3;
        pkt.pkt_qos = (packet_data >> 20) & 0x1;
        pkt.src_y = (packet_data >> 14) & 0x3F;
        pkt.src_x = (packet_data >> 8) & 0x3F;
        pkt.tgt_y = (packet_data >> 2) & 0x3F;
        pkt.tgt_x = packet_data & 0x3;
        pkt.pkt_data = (packet_data >> 8) & 0xFF;

        pkt.description = packet_to_string(pkt);

        return pkt;
    }

    // =================================================================
    // Validation Functions
    // =================================================================

    static bool is_valid_packet(uint32_t packet_data) {
        // Check if packet type is valid
        uint32_t pkt_type = (packet_data >> 21) & 0x3;
        if (pkt_type > BROADCAST) return false;

        // Check coordinate ranges
        uint32_t src_y = (packet_data >> 14) & 0x3F;
        uint32_t src_x = (packet_data >> 8) & 0x3F;
        uint32_t tgt_y = (packet_data >> 2) & 0x3F;
        uint32_t tgt_x = packet_data & 0x3;

        // For 8x8 network, coordinates should be 0-7
        const uint32_t MAX_COORD = 7;
        return (src_x <= MAX_COORD && src_y <= MAX_COORD &&
                tgt_x <= MAX_COORD && tgt_y <= MAX_COORD);
    }

    static bool is_unicast_packet(uint32_t packet_data) {
        return ((packet_data >> 21) & 0x3) == UNICAST;
    }

    static bool is_multicast_packet(uint32_t packet_data) {
        uint32_t type = (packet_data >> 21) & 0x3;
        return type == X_MULTICAST || type == Y_MULTICAST;
    }

    static bool is_broadcast_packet(uint32_t packet_data) {
        return ((packet_data >> 21) & 0x3) == BROADCAST;
    }

    static bool is_high_qos_packet(uint32_t packet_data) {
        return ((packet_data >> 20) & 0x1) == QOS_HIGH;
    }

    // =================================================================
    // Test Vector Generation
    // =================================================================

    static vector<Packet> generate_basic_test_vectors() {
        vector<Packet> packets;

        // Basic unicast packets
        packets.push_back(parse_packet(create_unicast_packet(0, 0, 1, 1, 0xAA)));
        packets.push_back(parse_packet(create_unicast_packet(3, 2, 4, 5, 0x55)));
        packets.push_back(parse_packet(create_unicast_packet(7, 7, 0, 0, 0xFF)));

        // Local delivery (source = target)
        packets.push_back(parse_packet(create_unicast_packet(2, 3, 2, 3, 0x33)));

        // QoS variations
        packets.push_back(parse_packet(create_unicast_packet(1, 1, 6, 6, 0x11, QOS_HIGH)));
        packets.push_back(parse_packet(create_unicast_packet(4, 4, 5, 5, 0x22, QOS_LOW)));

        // Multicast packets
        packets.push_back(parse_packet(create_x_multicast_packet(2, 3, 5, 0x77)));
        packets.push_back(parse_packet(create_y_multicast_packet(4, 1, 6, 0x88)));

        // Broadcast packet
        packets.push_back(parse_packet(create_broadcast_packet(0, 0, 0x99)));

        return packets;
    }

    static vector<Packet> generate_qos_test_vectors() {
        vector<Packet> packets;

        // High QoS packets
        for (int i = 0; i < 5; i++) {
            packets.push_back(parse_packet(create_unicast_packet(
                i % 8, (i * 2) % 8, (i + 3) % 8, (i + 1) % 8, 0x80 + i, QOS_HIGH)));
        }

        // Low QoS packets
        for (int i = 0; i < 5; i++) {
            packets.push_back(parse_packet(create_unicast_packet(
                (i + 1) % 8, (i + 3) % 8, (i + 2) % 8, i % 8, 0x10 + i, QOS_LOW)));
        }

        return packets;
    }

    static vector<Packet> generate_fault_test_vectors() {
        vector<Packet> packets;

        // Packets that would normally route through potentially faulty nodes
        packets.push_back(parse_packet(create_unicast_packet(0, 0, 7, 7, 0xAA)));
        packets.push_back(parse_packet(create_unicast_packet(7, 0, 0, 7, 0x55)));
        packets.push_back(parse_packet(create_unicast_packet(3, 3, 4, 4, 0x33)));

        // Packets from/to edge nodes
        packets.push_back(parse_packet(create_unicast_packet(0, 3, 7, 3, 0x66)));
        packets.push_back(parse_packet(create_unicast_packet(3, 0, 3, 7, 0x77)));

        return packets;
    }

    static vector<Packet> generate_performance_test_vectors(size_t count = 1000) {
        vector<Packet> packets;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> coord_dist(0, 7);
        uniform_int_distribution<> data_dist(0, 255);
        uniform_int_distribution<> qos_dist(0, 1);
        uniform_int_distribution<> type_dist(0, 3);

        for (size_t i = 0; i < count; i++) {
            uint32_t src_x = coord_dist(gen);
            uint32_t src_y = coord_dist(gen);
            uint32_t tgt_x = coord_dist(gen);
            uint32_t tgt_y = coord_dist(gen);
            uint32_t data = data_dist(gen);
            QoSLevel qos = static_cast<QoSLevel>(qos_dist(gen));
            uint32_t type = type_dist(gen);

            uint32_t packet_data;
            switch (type) {
                case UNICAST:
                    packet_data = create_unicast_packet(src_x, src_y, tgt_x, tgt_y, data, qos);
                    break;
                case X_MULTICAST:
                    packet_data = create_x_multicast_packet(src_x, src_y, tgt_x, data, qos);
                    break;
                case Y_MULTICAST:
                    packet_data = create_y_multicast_packet(src_x, src_y, tgt_y, data, qos);
                    break;
                case BROADCAST:
                    packet_data = create_broadcast_packet(src_x, src_y, data, qos);
                    break;
                default:
                    packet_data = create_unicast_packet(src_x, src_y, tgt_x, tgt_y, data, qos);
            }

            packets.push_back(parse_packet(packet_data));
        }

        return packets;
    }

    // =================================================================
    // String Conversion Utilities
    // =================================================================

    static string packet_to_string(const Packet& pkt) {
        stringstream ss;
        ss << "Packet[type=";

        switch (pkt.pkt_type) {
            case UNICAST: ss << "UNICAST"; break;
            case X_MULTICAST: ss << "X-MULTICAST"; break;
            case Y_MULTICAST: ss << "Y-MULTICAST"; break;
            case BROADCAST: ss << "BROADCAST"; break;
            default: ss << "UNKNOWN"; break;
        }

        ss << ", qos=" << (pkt.pkt_qos ? "HIGH" : "LOW")
           << ", src=(" << pkt.src_x << "," << pkt.src_y << ")"
           << ", tgt=(" << pkt.tgt_x << "," << pkt.tgt_y << ")"
           << ", data=0x" << hex << pkt.pkt_data << dec
           << ", raw=0x" << hex << pkt.data << dec << "]";

        return ss.str();
    }

    static string packet_to_binary_string(uint32_t packet_data) {
        stringstream ss;
        for (int i = 22; i >= 0; i--) {
            ss << ((packet_data >> i) & 1);
            if (i == 21 || i == 20 || i == 14 || i == 8 || i == 2) {
                ss << " ";
            }
        }
        return ss.str();
    }

    // =================================================================
    // Simulation Helper Functions
    // =================================================================

    static void print_packet_list(const vector<Packet>& packets, const string& title = "Packets") {
        cout << "\n" << title << " (" << packets.size() << " packets):" << endl;
        cout << string(80, '-') << endl;
        for (size_t i = 0; i < packets.size(); i++) {
            cout << "[" << setw(3) << i << "] " << packets[i].description << endl;
        }
        cout << string(80, '-') << endl;
    }

    static bool compare_packets(const Packet& sent, const Packet& received, bool exact_match = true) {
        if (exact_match) {
            return sent.data == received.data;
        } else {
            // For some scenarios, allow partial matching (e.g., data may change through routing)
            return (sent.pkt_type == received.pkt_type &&
                    sent.src_x == received.src_x &&
                    sent.src_y == received.src_y &&
                    sent.tgt_x == received.tgt_x &&
                    sent.tgt_y == received.tgt_y);
        }
    }
};

#endif // PACKET_UTILS_H