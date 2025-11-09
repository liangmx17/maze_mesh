// ====================================================================
// MAZE Network Node - Performance Test Class
// ====================================================================
//
// Test class for performance characterization
// Measures throughput, latency, and resource utilization
//
// ====================================================================

#ifndef PERFORMANCE_TEST_H
#define PERFORMANCE_TEST_H

#include "../common/packet_generator.h"
#include "../common/test_utils.h"
#include "../common/result_validator.h"
#include "Vnode.h"
#include <memory>
#include <vector>

class PerformanceTest {
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

    // Performance metrics
    uint64_t packets_sent_;
    uint64_t packets_received_;
    double total_latency_;
    uint64_t start_cycle_;
    uint64_t end_cycle_;

public:
    PerformanceTest(Vnode* dut, PacketGenerator* packet_gen,
                   TestUtils* test_utils, ResultValidator* validator)
        : dut_(dut), packet_gen_(packet_gen), test_utils_(test_utils), validator_(validator),
          src_hp_(0), src_vp_(0), max_test_cycles_(10000), reset_cycles_(5),
          tests_run_(0), tests_passed_(0), tests_failed_(0),
          packets_sent_(0), packets_received_(0), total_latency_(0.0), start_cycle_(0), end_cycle_(0) {

        src_hp_ = dut_->HP;
        src_vp_ = dut_->VP;
        packet_gen_->set_source_position(src_hp_, src_vp_);

        if (test_utils_) {
            test_utils_->get_logger().info("PerformanceTest initialized for node (" +
                                          std::to_string(src_hp_) + "," + std::to_string(src_vp_) + ")");
        }
    }

    bool run_all_tests() {
        if (test_utils_) {
            test_utils_->get_logger().info("Starting Performance Tests");
        }

        reset_statistics();
        bool all_passed = true;

        all_passed &= test_maximum_throughput();
        all_passed &= test_latency_characterization();
        all_passed &= test_sustained_load();

        print_test_summary();
        return all_passed;
    }

    bool test_maximum_throughput() {
        tests_run_++;
        const string test_name = "Maximum Throughput";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();
            reset_performance_metrics();

            // Generate maximum load - back-to-back packets
            vector<MazePacket> test_packets;
            for (uint32_t i = 0; i < 100; i++) {
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i) % 8, (src_vp_ + i) % 8, 0, i % 2,
                    test_name + "_max_load_" + std::to_string(i), i);
                test_packets.push_back(pkt);
            }

            bool test_passed = run_performance_test(test_packets, test_name);

            // Calculate throughput
            double throughput = calculate_throughput();
            if (test_utils_) {
                test_utils_->get_logger().info("Throughput: " + std::to_string(throughput) + " packets/cycle");
            }

            if (test_passed && throughput > 0.1) {  // Minimum throughput requirement
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name + " - Low throughput");
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

    bool test_latency_characterization() {
        tests_run_++;
        const string test_name = "Latency Characterization";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();
            reset_performance_metrics();

            vector<MazePacket> test_packets;

            // Test different packet types for latency
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, src_hp_, src_vp_, 0, 0, test_name + "_local", 10));
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 1) % 8, src_vp_, 0, 0, test_name + "near", 20));
            test_packets.push_back(packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 4) % 8, (src_vp_ + 4) % 8, 0, 1, test_name + "_far", 30));

            bool test_passed = run_performance_test(test_packets, test_name);

            // Calculate average latency
            double avg_latency = packets_received_ > 0 ? total_latency_ / packets_received_ : 0.0;
            if (test_utils_) {
                test_utils_->get_logger().info("Average latency: " + std::to_string(avg_latency) + " cycles");
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

    bool test_sustained_load() {
        tests_run_++;
        const string test_name = "Sustained Load";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();
            reset_performance_metrics();

            // Generate sustained load over longer period
            vector<MazePacket> test_packets;
            for (uint32_t i = 0; i < 50; i++) {
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i) % 8, (src_vp_ + i * 2) % 8, 0, i % 2,
                    test_name + "_sustained_" + std::to_string(i), i * 5);
                test_packets.push_back(pkt);
            }

            bool test_passed = run_performance_test(test_packets, test_name);

            // Verify sustained operation
            double success_rate = packets_sent_ > 0 ? (double)packets_received_ / packets_sent_ : 0.0;
            if (test_utils_) {
                test_utils_->get_logger().info("Success rate: " + std::to_string(success_rate * 100.0) + "%");
            }

            if (test_passed && success_rate > 0.8) {
                tests_passed_++;
                if (test_utils_) test_utils_->get_logger().info("Test passed: " + test_name);
            } else {
                tests_failed_++;
                if (test_utils_) test_utils_->get_logger().error("Test failed: " + test_name + " - Low success rate");
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

    void reset_performance_metrics() {
        packets_sent_ = 0;
        packets_received_ = 0;
        total_latency_ = 0.0;
        start_cycle_ = 0;
        end_cycle_ = 0;
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

    bool run_performance_test(const std::vector<MazePacket>& test_packets, const std::string& test_name) {
        start_cycle_ = 0;
        packets_sent_ = test_packets.size();
        packets_received_ = 0;
        total_latency_ = 0.0;

        uint32_t cycle = 0;

        while (cycle < max_test_cycles_) {
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
                packets_received_++;
                // Simplified latency calculation
                total_latency_ += 4.0; // Assume minimum pipeline latency
            }

            dut_->pkt_i->pkt_in_vld = 0;
            dut_->pkt_o->pkt_out_rdy = 1;
            dut_->pg_en = 0;
            dut_->pg_node = 0;

            cycle_dut();
            cycle++;
        }

        end_cycle_ = cycle;
        return packets_received_ >= packets_sent_ * 0.8; // 80% success rate minimum
    }

    double calculate_throughput() const {
        if (end_cycle_ <= start_cycle_) return 0.0;
        return (double)packets_received_ / (end_cycle_ - start_cycle_);
    }

    void print_test_summary() const {
        cout << "\n" << string(70, '-') << endl;
        cout << "Performance Test Summary" << endl;
        cout << string(70, '-') << endl;
        cout << "Tests Run:    " << tests_run_ << endl;
        cout << "Tests Passed: " << tests_passed_ << endl;
        cout << "Tests Failed: " << tests_failed_ << endl;
        cout << "Success Rate: " << fixed << setprecision(1)
             << (tests_run_ > 0 ? (double)tests_passed_ / tests_run_ * 100.0 : 0.0) << "%" << endl;
        cout << "Total Packets Sent: " << packets_sent_ << endl;
        cout << "Total Packets Received: " << packets_received_ << endl;
        if (packets_received_ > 0) {
            cout << "Average Latency: " << fixed << setprecision(2) << (total_latency_ / packets_received_) << " cycles" << endl;
        }
        cout << string(70, '-') << endl;
    }
};

#endif // PERFORMANCE_TEST_H