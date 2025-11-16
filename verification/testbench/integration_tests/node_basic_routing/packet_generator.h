// =============================================================================
// MAZE网络数据包生成器
// =============================================================================
// 功能说明：
// 1. 生成符合MAZE网络规范的23位数据包
// 2. 支持单播、多播和广播数据包类型
// 3. 支持不同QoS等级的数据包生成
// 4. 支持故障感知路由测试数据包
// =============================================================================

#ifndef __MAZE_PACKET_GENERATOR_H__
#define __MAZE_PACKET_GENERATOR_H__

#include <vector>
#include <cstdint>
#include <string>
#include <random>
#include <sstream>

// 数据包结构体（23位格式）
struct MazePacket {
    uint8_t  pkt_type;    // 2位：数据包类型 (00=单播, 01=X多播, 10=Y多播, 11=广播)
    uint8_t  pkt_qos;     // 1位：QoS等级 (0=低优先级, 1=高优先级)
    uint8_t  src_x;       // 3位：源节点X坐标
    uint8_t  src_y;       // 3位：源节点Y坐标
    uint8_t  tgt_x;       // 3位：目标节点X坐标
    uint8_t  tgt_y;       // 3位：目标节点Y坐标
    uint8_t  pkt_data;    // 8位：数据负载

    // 构造函数
    MazePacket() : pkt_type(0), pkt_qos(0), src_x(0), src_y(0), tgt_x(0), tgt_y(0), pkt_data(0) {}

    // 获取完整的6位源ID
    uint8_t get_src_id() const { return (src_y << 3) | src_x; }

    // 获取完整的6位目标ID
    uint8_t get_tgt_id() const { return (tgt_y << 3) | tgt_x; }

    // 获取23位数据包编码
    uint32_t get_encoded_packet() const {
        return (pkt_type << 21) | (pkt_qos << 20) | (get_src_id() << 14) | (get_tgt_id() << 8) | pkt_data;
    }

    // 解析23位数据包编码
    void decode_packet(uint32_t encoded) {
        pkt_type = (encoded >> 21) & 0x3;
        pkt_qos = (encoded >> 20) & 0x1;
        uint8_t src_id = (encoded >> 14) & 0x3F;
        uint8_t tgt_id = (encoded >> 8) & 0x3F;
        pkt_data = encoded & 0xFF;

        src_x = src_id & 0x7;
        src_y = (src_id >> 3) & 0x7;
        tgt_x = tgt_id & 0x7;
        tgt_y = (tgt_id >> 3) & 0x7;
    }

    // 获取字符串描述
    std::string to_string() const {
        std::ostringstream oss;
        oss << "Packet["
            << "Type=" << (int)pkt_type
            << ", QoS=" << (int)pkt_qos
            << ", Src=(" << (int)src_x << "," << (int)src_y << ")"
            << ", Tgt=(" << (int)tgt_x << "," << (int)tgt_y << ")"
            << ", Data=0x" << std::hex << (int)pkt_data << std::dec
            << "]";
        return oss.str();
    }
};

// 数据包生成器类
class MazePacketGenerator {
private:
    std::mt19937 rng;

public:
    // 构造函数
    MazePacketGenerator(uint32_t seed = 42) : rng(seed) {}

    // 生成单播数据包
    MazePacket generate_unicast_packet(uint8_t src_x, uint8_t src_y,
                                      uint8_t tgt_x, uint8_t tgt_y,
                                      uint8_t qos = 0, uint8_t data = 0) {
        MazePacket pkt;
        pkt.pkt_type = 0b00;        // 单播类型
        pkt.pkt_qos = qos & 0x1;
        pkt.src_x = src_x & 0x7;
        pkt.src_y = src_y & 0x7;
        pkt.tgt_x = tgt_x & 0x7;
        pkt.tgt_y = tgt_y & 0x7;
        pkt.pkt_data = data;
        return pkt;
    }

    // 生成X多播数据包（相同X坐标的所有节点）
    MazePacket generate_x_multicast_packet(uint8_t src_x, uint8_t src_y,
                                          uint8_t tgt_x, uint8_t qos = 0, uint8_t data = 0) {
        MazePacket pkt;
        pkt.pkt_type = 0b01;        // X多播类型
        pkt.pkt_qos = qos & 0x1;
        pkt.src_x = src_x & 0x7;
        pkt.src_y = src_y & 0x7;
        pkt.tgt_x = tgt_x & 0x7;
        pkt.tgt_y = 0;              // Y坐标在X多播中不使用，设为0
        pkt.pkt_data = data;
        return pkt;
    }

    // 生成Y多播数据包（相同Y坐标的所有节点）
    MazePacket generate_y_multicast_packet(uint8_t src_x, uint8_t src_y,
                                          uint8_t tgt_y, uint8_t qos = 0, uint8_t data = 0) {
        MazePacket pkt;
        pkt.pkt_type = 0b10;        // Y多播类型
        pkt.pkt_qos = qos & 0x1;
        pkt.src_x = src_x & 0x7;
        pkt.src_y = src_y & 0x7;
        pkt.tgt_x = 0;              // X坐标在Y多播中不使用，设为0
        pkt.tgt_y = tgt_y & 0x7;
        pkt.pkt_data = data;
        return pkt;
    }

    // 生成广播数据包（所有节点）
    MazePacket generate_broadcast_packet(uint8_t src_x, uint8_t src_y,
                                       uint8_t qos = 0, uint8_t data = 0) {
        MazePacket pkt;
        pkt.pkt_type = 0b11;        // 广播类型
        pkt.pkt_qos = qos & 0x1;
        pkt.src_x = src_x & 0x7;
        pkt.src_y = src_y & 0x7;
        pkt.tgt_x = 0;              // 广播中目标坐标不使用
        pkt.tgt_y = 0;
        pkt.pkt_data = data;
        return pkt;
    }

    // 生成随机数据包（用于测试）
    MazePacket generate_random_packet() {
        std::uniform_int_distribution<uint32_t> dist(0, 0xFFFFFFFF);
        uint32_t encoded = dist(rng) & 0x7FFFFF;  // 限制在23位范围内

        MazePacket pkt;
        pkt.decode_packet(encoded);
        return pkt;
    }

    // 生成指定方向路由测试数据包
    MazePacket generate_direction_test_packet(uint8_t src_x, uint8_t src_y,
                                             std::string direction, uint8_t distance = 1) {
        uint8_t tgt_x = src_x;
        uint8_t tgt_y = src_y;

        if (direction == "NORTH" || direction == "N") {
            tgt_y = std::min(7, src_y + distance);
        } else if (direction == "SOUTH" || direction == "S") {
            tgt_y = src_y > distance ? src_y - distance : 0;
        } else if (direction == "EAST" || direction == "E") {
            tgt_x = std::min(7, src_x + distance);
        } else if (direction == "WEST" || direction == "W") {
            tgt_x = src_x > distance ? src_x - distance : 0;
        } else if (direction == "LOCAL") {
            // 本地路由，目标与源相同
            tgt_x = src_x;
            tgt_y = src_y;
        }

        // 生成递增的数据内容便于调试
        uint8_t data = (src_x << 4) | src_y;

        return generate_unicast_packet(src_x, src_y, tgt_x, tgt_y, 0, data);
    }

    // 生成测试序列（用于基本路由功能测试）
    std::vector<MazePacket> generate_basic_routing_test_sequence(uint8_t node_x, uint8_t node_y) {
        std::vector<MazePacket> test_packets;

        // N-RF-001: X方向正向路由（向东）
        if (node_x < 7) {
            test_packets.push_back(generate_direction_test_packet(node_x, node_y, "EAST", 1));
        }

        // N-RF-002: X方向反向路由（向西）
        if (node_x > 0) {
            test_packets.push_back(generate_direction_test_packet(node_x, node_y, "WEST", 1));
        }

        // N-RF-003: Y方向正向路由（向北）
        if (node_y < 7) {
            test_packets.push_back(generate_direction_test_packet(node_x, node_y, "NORTH", 1));
        }

        // N-RF-004: Y方向反向路由（向南）
        if (node_y > 0) {
            test_packets.push_back(generate_direction_test_packet(node_x, node_y, "SOUTH", 1));
        }

        // N-RF-005: 本地路由
        test_packets.push_back(generate_direction_test_packet(node_x, node_y, "LOCAL", 0));

        return test_packets;
    }

    // 生成QoS测试序列（高和低优先级对比）
    std::vector<MazePacket> generate_qos_test_sequence(uint8_t src_x, uint8_t src_y,
                                                      uint8_t tgt_x, uint8_t tgt_y) {
        std::vector<MazePacket> test_packets;

        // 生成高QoS数据包
        test_packets.push_back(generate_unicast_packet(src_x, src_y, tgt_x, tgt_y, 1, 0xA5));

        // 生成低QoS数据包
        test_packets.push_back(generate_unicast_packet(src_x, src_y, tgt_x, tgt_y, 0, 0x5A));

        return test_packets;
    }

    // 验证数据包有效性
    static bool is_valid_packet(const MazePacket& pkt) {
        return (pkt.src_x < 8 && pkt.src_y < 8 &&
                pkt.tgt_x < 8 && pkt.tgt_y < 8 &&
                pkt.pkt_type < 4 && pkt.pkt_qos < 2);
    }

    // 打印数据包信息（用于调试）
    static void print_packet(const MazePacket& pkt) {
        printf("Packet Details:\n");
        printf("  Type: %d (%s)\n", pkt.pkt_type,
               (pkt.pkt_type == 0) ? "Unicast" :
               (pkt.pkt_type == 1) ? "X-Multicast" :
               (pkt.pkt_type == 2) ? "Y-Multicast" : "Broadcast");
        printf("  QoS: %d (%s)\n", pkt.pkt_qos, pkt.pkt_qos ? "High" : "Low");
        printf("  Source: (%d, %d) [ID: %d]\n", pkt.src_x, pkt.src_y, pkt.get_src_id());
        printf("  Target: (%d, %d) [ID: %d]\n", pkt.tgt_x, pkt.tgt_y, pkt.get_tgt_id());
        printf("  Data: 0x%02X\n", pkt.pkt_data);
        printf("  Encoded: 0x%06X (23-bit)\n", pkt.get_encoded_packet());
    }
};

#endif // __MAZE_PACKET_GENERATOR_H__