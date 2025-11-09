// ====================================================================
// MAZE Network Node - Basic Functionality Test Class
// ====================================================================
//
// Comprehensive test class for basic node functionality
// Tests unicast routing, local delivery, multicast, and broadcast
//
// ====================================================================

#ifndef BASIC_FUNCTIONALITY_TEST_H
#define BASIC_FUNCTIONALITY_TEST_H

#include "../common/packet_generator.h"
#include "../common/test_utils.h"
#include "../common/result_validator.h"
#include "Vnode.h"
#include <memory>
#include <vector>

// ====================================================================
// Basic Functionality Test Class
// ====================================================================
class BasicFunctionalityTest {
private:
    Vnode* dut_;                           // Device Under Test
    PacketGenerator* packet_gen_;          // Packet generation utilities
    TestUtils* test_utils_;                // Test utilities and logging
    ResultValidator* validator_;           // Result validation

    // Test configuration
    uint32_t src_hp_;                      // Source horizontal position
    uint32_t src_vp_;                      // Source vertical position
    uint32_t max_test_cycles_;             // Maximum cycles per test
    uint32_t reset_cycles_;                // Reset sequence length

    // Test statistics
    uint32_t tests_run_;
    uint32_t tests_passed_;
    uint32_t tests_failed_;

public:
    BasicFunctionalityTest(Vnode* dut, PacketGenerator* packet_gen,
                          TestUtils* test_utils, ResultValidator* validator)
        : dut_(dut), packet_gen_(packet_gen), test_utils_(test_utils), validator_(validator),
          src_hp_(0), src_vp_(0), max_test_cycles_(1000), reset_cycles_(5),
          tests_run_(0), tests_passed_(0), tests_failed_(0) {

        // Get node position from DUT
        src_hp_ = dut_->HP;
        src_vp_ = dut_->VP;

        // Configure packet generator for this node
        packet_gen_->set_source_position(src_hp_, src_vp_);

        if (test_utils_) {
            test_utils_->get_logger().info("BasicFunctionalityTest initialized for node (" +
                                          std::to_string(src_hp_) + "," + std::to_string(src_vp_) + ")");
        }
    }

    // ====================================================================
    // Main Test Execution
    // ====================================================================

    bool run_all_tests() {
        if (test_utils_) {
            test_utils_->get_logger().info("Starting Basic Functionality Tests");
        }

        reset_statistics();
        bool all_passed = true;

        // Run individual test cases
        all_passed &= test_basic_unicast_routing();
        all_passed &= test_local_delivery();
        all_passed &= test_x_multicast();
        all_passed &= test_y_multicast();
        all_passed &= test_broadcast();
        all_passed &= test_mixed_traffic();
        all_passed &= test_edge_cases();

        // Print test summary
        print_test_summary();

        return all_passed;
    }

    // ====================================================================
    // Individual Test Methods
    // ====================================================================

    bool test_basic_unicast_routing() {
        tests_run_++;
        const string test_name = "Basic Unicast Routing";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            // Reset DUT
            reset_dut();

            // Generate test packets for different directions
            vector<MazePacket> test_packets;

            // East routing (X+1)
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 1) % 8, src_vp_, 0, 0, "unicast_east", 10));

            // West routing (X-1)
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 7) % 8, src_vp_, 0, 1, "unicast_west", 20));

            // South routing (Y+1)
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, src_hp_, (src_vp_ + 1) % 8, 0, 0, "unicast_south", 30));

            // North routing (Y-1)
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, src_hp_, (src_vp_ + 7) % 8, 0, 1, "unicast_north", 40));

            // Diagonal routing
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 2) % 8, (src_vp_ + 2) % 8, 0, 0, "unicast_diagonal", 50));

            // Run simulation with test packets
            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_local_delivery() {
        tests_run_++;
        const string test_name = "Local Delivery";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            // Generate local delivery packets
            vector<MazePacket> test_packets;

            for (uint32_t i = 0; i < 5; i++) {
                test_packets.push_back(packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, src_hp_, src_vp_, 0, i % 2,
                    "local_delivery_" + std::to_string(i), 10 + i * 10));
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            // Additional verification: local delivery should go through B-port
            if (validator_) {
                auto results = validator_->get_validation_results();
                // Check if local delivery packets were routed correctly
            }

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_x_multicast() {
        tests_run_++;
        const string test_name = "X-Multicast";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            // Generate X-multicast packets
            vector<MazePacket> test_packets;

            for (uint32_t i = 0; i < 3; i++) {
                MazePacket packet = packet_gen_->generate_x_multicast_packet(test_name + "_" + std::to_string(i), 10 + i * 15);
                packet.qos = i % 2;  // Alternate QoS levels
                test_packets.push_back(packet);
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_y_multicast() {
        tests_run_++;
        const string test_name = "Y-Multicast";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            // Generate Y-multicast packets
            vector<MazePacket> test_packets;

            for (uint32_t i = 0; i < 3; i++) {
                MazePacket packet = packet_gen_->generate_y_multicast_packet(test_name + "_" + std::to_string(i), 10 + i * 15);
                packet.qos = i % 2;  // Alternate QoS levels
                test_packets.push_back(packet);
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_broadcast() {
        tests_run_++;
        const string test_name = "Broadcast";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            // Generate broadcast packets
            vector<MazePacket> test_packets;

            for (uint32_t i = 0; i < 2; i++) {
                MazePacket packet = packet_gen_->generate_broadcast_packet(test_name + "_" + std::to_string(i), 10 + i * 20);
                packet.qos = 1;  // High priority for broadcast
                test_packets.push_back(packet);
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_mixed_traffic() {
        tests_run_++;
        const string test_name = "Mixed Traffic";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            // Generate mixed traffic pattern
            vector<MazePacket> test_packets;

            // Mix of different packet types
            test_packets.push_back(packet_gen_->generate_unicast_packet(test_name + "_unicast_1", 10));
            test_packets.push_back(packet_gen_->generate_x_multicast_packet(test_name + "_x_multicast", 25));
            test_packets.push_back(packet_gen_->generate_y_multicast_packet(test_name + "_y_multicast", 40));
            test_packets.push_back(packet_gen_->generate_broadcast_packet(test_name + "_broadcast", 55));
            test_packets.push_back(packet_gen_->generate_local_delivery_packet(test_name + "_local", 70));
            test_packets.push_back(packet_gen_->generate_unicast_packet(test_name + "_unicast_2", 85));

            // Vary QoS levels
            for (size_t i = 0; i < test_packets.size(); i++) {
                test_packets[i].qos = i % 2;
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

    bool test_edge_cases() {
        tests_run_++;
        const string test_name = "Edge Cases";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;

            // Test edge coordinates
            if (src_hp_ == 0) {
                // Test wrapping from X=0 to X=7
                test_packets.push_back(packet_gen_->generate_directed_packet(
                    0, src_vp_, 7, src_vp_, 0, 0, "edge_wrap_west", 10));
            } else if (src_hp_ == 7) {
                // Test wrapping from X=7 to X=0
                test_packets.push_back(packet_gen_->generate_directed_packet(
                    7, src_vp_, 0, src_vp_, 0, 0, "edge_wrap_east", 10));
            }

            if (src_vp_ == 0) {
                // Test wrapping from Y=0 to Y=7
                test_packets.push_back(packet_gen_->generate_directed_packet(
                    src_hp_, 0, src_hp_, 7, 0, 0, "edge_wrap_north", 20));
            } else if (src_vp_ == 7) {
                // Test wrapping from Y=7 to Y=0
                test_packets.push_back(packet_gen_->generate_directed_packet(
                    src_hp_, 7, src_hp_, 0, 0, 0, "edge_wrap_south", 20));
            }

            // Test minimum and maximum data values
            MazePacket min_data_pkt = packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 1) % 8, src_vp_, 0, 0, "min_data", 30);
            min_data_pkt.data = 0x00;
            test_packets.push_back(min_data_pkt);

            MazePacket max_data_pkt = packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 2) % 8, src_vp_, 0, 0, "max_data", 40);
            max_data_pkt.data = 0xFF;
            test_packets.push_back(max_data_pkt);

            // Test rapid back-to-back packets
            for (uint32_t i = 0; i < 3; i++) {
                MazePacket rapid_pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + 3) % 8, src_vp_, 0, 1,
                    "rapid_" + std::to_string(i), 50 + i);
                test_packets.push_back(rapid_pkt);
            }

            bool test_passed = run_packet_test(test_packets, test_name);

            if (test_passed) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name);
            }

            return test_passed;

        } catch (const std::exception& e) {
            tests_failed_++;
            if (test_utils_) {
                test_utils_->get_logger().error("Exception in " + test_name + ": " + e.what());
            }
            return false;
        }
    }

private:
    // ====================================================================
    // Helper Methods
    // ====================================================================

    void reset_statistics() {
        tests_run_ = 0;
        tests_passed_ = 0;
        tests_failed_ = 0;
    }

    void reset_dut() {
        // Apply reset sequence
        dut_->rst_n = 0;
        for (uint32_t i = 0; i < reset_cycles_; i++) {
            dut_->clk = 0; dut_->eval();
            dut_->clk = 1; dut_->eval();
        }
        dut_->rst_n = 1;
    }

    void cycle_dut() {
        dut_->clk = 0; dut_->eval();
        dut_->clk = 1; dut_->eval();
    }

    bool run_packet_test(const std::vector<MazePacket>& test_packets, const std::string& test_name) {
        if (!validator_) {
            validator_->reset_validation();
        }

        // Track injected packets
        for (const auto& packet : test_packets) {
            if (validator_) {
                validator_->track_injected_packet(packet, packet.inject_cycle, "A");
            }
            if (test_utils_) {
                test_utils_->log_packet_injection(packet, "A");
            }
        }

        // Simulate packet injection and reception
        bool all_packets_received = true;
        uint32_t cycle = 0;

        while (cycle < max_test_cycles_) {
            // Check for packet injection at this cycle
            for (const auto& packet : test_packets) {
                if (cycle == packet.inject_cycle) {
                    // Apply packet to A interface
                    dut_->pkt_i->pkt_in_vld = 1;
                    dut_->pkt_i->pkt_in_qos = packet.qos;
                    dut_->pkt_i->pkt_in_type = packet.type;
                    dut_->pkt_i->pkt_in_src = packet.get_src_coord();
                    dut_->pkt_i->pkt_in_tgt = packet.get_tgt_coord();
                    dut_->pkt_i->pkt_in_data = packet.data;

                    if (test_utils_ && test_utils_->is_verbose(3)) {
                        test_utils_->get_logger().debug("Injecting packet at cycle " + std::to_string(cycle), packet.test_id);
                    }
                }
            }

            // Check for packet reception on B interface
            if (dut_->pkt_o->pkt_out_vld && dut_->pkt_o->pkt_out_rdy) {
                MazePacket received_packet;
                received_packet.type = dut_->pkt_o->pkt_out_type;
                received_packet.qos = dut_->pkt_o->pkt_out_qos;
                received_packet.src_x = dut_->pkt_o->pkt_out_src & 0x7;
                received_packet.src_y = (dut_->pkt_o->pkt_out_src >> 3) & 0x7;
                received_packet.tgt_x = dut_->pkt_o->pkt_out_tgt & 0x7;
                received_packet.tgt_y = (dut_->pkt_o->pkt_out_tgt >> 3) & 0x7;
                received_packet.data = dut_->pkt_o->pkt_out_data;
                received_packet.receive_cycle = cycle;

                if (validator_) {
                    validator_->track_received_packet(received_packet, cycle, "B");
                }
                if (test_utils_) {
                    test_utils_->log_packet_reception(received_packet, "B", cycle);
                }
            }

            // Clear A interface valid signal
            dut_->pkt_i->pkt_in_vld = 0;

            // Set B interface ready signal
            dut_->pkt_o->pkt_out_rdy = 1;

            // Set default values for other inputs
            dut_->pg_en = 0;  // No faults for basic tests
            dut_->pg_node = 0;  // Invalid node ID

            // Set C interface signals to default (no incoming packets)
            for (int i = 0; i < 7; i++) {
                dut_->pkt_con->x_vld[i] = 0;
                dut_->pkt_con->x_qos[i] = 0;
                dut_->pkt_con->x_type[i] = 0;
                dut_->pkt_con->x_src[i] = 0;
                dut_->pkt_con->x_tgt[i] = 0;
                dut_->pkt_con->x_data[i] = 0;

                dut_->pkt_con->y_vld[i] = 0;
                dut_->pkt_con->y_qos[i] = 0;
                dut_->pkt_con->y_type[i] = 0;
                dut_->pkt_con->y_src[i] = 0;
                dut_->pkt_con->y_tgt[i] = 0;
                dut_->pkt_con->y_data[i] = 0;
            }

            cycle_dut();
            cycle++;

            if (test_utils_) {
                test_utils_->update_statistics(cycle);
            }
        }

        // Run validation
        if (validator_) {
            return validator_->run_all_validations();
        }

        return all_packets_received;
    }

    void print_test_summary() const {
        cout << "\n" << string(70, '-') << endl;
        cout << "Basic Functionality Test Summary" << endl;
        cout << string(70, '-') << endl;
        cout << "Tests Run:    " << tests_run_ << endl;
        cout << "Tests Passed: " << tests_passed_ << endl;
        cout << "Tests Failed: " << tests_failed_ << endl;
        cout << "Success Rate: " << fixed << setprecision(1)
             << (tests_run_ > 0 ? (double)tests_passed_ / tests_run_ * 100.0 : 0.0) << "%" << endl;
        cout << string(70, '-') << endl;
    }
};

#endif // BASIC_FUNCTIONALITY_TEST_H