// ====================================================================
// MAZE Network Node - QoS Arbitration Test Class
// ====================================================================
//
// Test class for QoS arbitration functionality
// Validates priority enforcement and arbitration fairness
//
// ====================================================================

#ifndef QOS_ARBITRATION_TEST_H
#define QOS_ARBITRATION_TEST_H

#include "../common/packet_generator.h"
#include "../common/test_utils.h"
#include "../common/result_validator.h"
#include "Vnode.h"
#include <memory>
#include <vector>

class QoSArbitrationTest {
private:
    Vnode* dut_;
    PacketGenerator* packet_gen_;
    TestUtils* test_utils_;
    ResultValidator* validator_;

    uint32_t src_hp_;
    uint32_t src_vp_;
    uint32_t max_test_cycles_;
    uint32_t reset_cycles_;

    uint32_t tests_run_;
    uint32_t tests_passed_;
    uint32_t tests_failed_;

public:
    QoSArbitrationTest(Vnode* dut, PacketGenerator* packet_gen,
                      TestUtils* test_utils, ResultValidator* validator)
        : dut_(dut), packet_gen_(packet_gen), test_utils_(test_utils), validator_(validator),
          src_hp_(0), src_vp_(0), max_test_cycles_(2000), reset_cycles_(5),
          tests_run_(0), tests_passed_(0), tests_failed_(0) {

        src_hp_ = dut_->HP;
        src_vp_ = dut_->VP;
        packet_gen_->set_source_position(src_hp_, src_vp_);

        if (test_utils_) {
            test_utils_->get_logger().info("QoSArbitrationTest initialized for node (" +
                                          std::to_string(src_hp_) + "," + std::to_string(src_vp_) + ")");
        }
    }

    bool run_all_tests() {
        if (test_utils_) {
            test_utils_->get_logger().info("Starting QoS Arbitration Tests");
        }

        reset_statistics();
        bool all_passed = true;

        all_passed &= test_qos_priority_enforcement();
        all_passed &= test_mixed_qos_scenarios();
        all_passed &= test_arbitration_fairness();
        all_passed &= test_qos_starvation_prevention();

        print_test_summary();
        return all_passed;
    }

    bool test_qos_priority_enforcement() {
        tests_run_++;
        const string test_name = "QoS Priority Enforcement";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;

            // Inject high priority packet followed by low priority packets
            MazePacket high_qos_pkt = packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 1) % 8, src_vp_, 0, 1, test_name + "_high", 10);
            test_packets.push_back(high_qos_pkt);

            // Multiple low priority packets
            for (uint32_t i = 0; i < 5; i++) {
                MazePacket low_qos_pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + 2) % 8, (src_vp_ + i) % 8, 0, 0,
                    test_name + "_low_" + std::to_string(i), 15 + i * 2);
                test_packets.push_back(low_qos_pkt);
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

    bool test_mixed_qos_scenarios() {
        tests_run_++;
        const string test_name = "Mixed QoS Scenarios";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;

            // Create mixed QoS traffic with different injection times
            for (uint32_t i = 0; i < 8; i++) {
                uint32_t qos = (i % 3 == 0) ? 1 : 0;  // Every 3rd packet is high priority
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i) % 8, (src_vp_ + i) % 8, 0, qos,
                    test_name + "_mixed_" + std::to_string(i), 10 + i * 5);
                test_packets.push_back(pkt);
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

    bool test_arbitration_fairness() {
        tests_run_++;
        const string test_name = "Arbitration Fairness";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;

            // Create multiple packets with same QoS level to test fairness
            for (uint32_t i = 0; i < 6; i++) {
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i) % 8, src_vp_, 0, 1,  // All high priority
                    test_name + "_fair_" + std::to_string(i), 10 + i);
                test_packets.push_back(pkt);
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

    bool test_qos_starvation_prevention() {
        tests_run_++;
        const string test_name = "QoS Starvation Prevention";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;

            // Continuous high priority traffic followed by low priority
            for (uint32_t i = 0; i < 10; i++) {
                uint32_t qos = (i < 7) ? 1 : 0;  // First 7 high, then 3 low
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i) % 8, (src_vp_ + i) % 8, 0, qos,
                    test_name + "_starve_" + std::to_string(i), 10 + i * 3);
                test_packets.push_back(pkt);
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
    void reset_statistics() {
        tests_run_ = 0;
        tests_passed_ = 0;
        tests_failed_ = 0;
    }

    void reset_dut() {
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
        if (validator_) {
            validator_->reset_validation();
        }

        // Track injected packets
        for (const auto& packet : test_packets) {
            if (validator_) {
                validator_->track_injected_packet(packet, packet.inject_cycle, "A");
            }
        }

        uint32_t cycle = 0;

        while (cycle < max_test_cycles_) {
            // Check for packet injection at this cycle
            for (const auto& packet : test_packets) {
                if (cycle == packet.inject_cycle) {
                    dut_->pkt_i->pkt_in_vld = 1;
                    dut_->pkt_i->pkt_in_qos = packet.qos;
                    dut_->pkt_i->pkt_in_type = packet.type;
                    dut_->pkt_i->pkt_in_src = packet.get_src_coord();
                    dut_->pkt_i->pkt_in_tgt = packet.get_tgt_coord();
                    dut_->pkt_i->pkt_in_data = packet.data;
                }
            }

            // Check for packet reception
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
            }

            // Clear A interface
            dut_->pkt_i->pkt_in_vld = 0;
            dut_->pkt_o->pkt_out_rdy = 1;
            dut_->pg_en = 0;
            dut_->pg_node = 0;

            // Default C interface
            for (int i = 0; i < 7; i++) {
                dut_->pkt_con->x_vld[i] = 0;
                dut_->pkt_con->y_vld[i] = 0;
            }

            cycle_dut();
            cycle++;
        }

        if (validator_) {
            return validator_->run_all_validations();
        }

        return true;
    }

    void print_test_summary() const {
        cout << "\n" << string(70, '-') << endl;
        cout << "QoS Arbitration Test Summary" << endl;
        cout << string(70, '-') << endl;
        cout << "Tests Run:    " << tests_run_ << endl;
        cout << "Tests Passed: " << tests_passed_ << endl;
        cout << "Tests Failed: " << tests_failed_ << endl;
        cout << "Success Rate: " << fixed << setprecision(1)
             << (tests_run_ > 0 ? (double)tests_passed_ / tests_run_ * 100.0 : 0.0) << "%" << endl;
        cout << string(70, '-') << endl;
    }
};

#endif // QOS_ARBITRATION_TEST_H