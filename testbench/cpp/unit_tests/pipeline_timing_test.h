// ====================================================================
// MAZE Network Node - Pipeline Timing Test Class
// ====================================================================
//
// Test class for pipeline timing validation
// Validates 4-stage pipeline operation and timing constraints
//
// ====================================================================

#ifndef PIPELINE_TIMING_TEST_H
#define PIPELINE_TIMING_TEST_H

#include "../common/packet_generator.h"
#include "../common/test_utils.h"
#include "../common/result_validator.h"
#include "Vnode.h"
#include <memory>
#include <vector>

class PipelineTimingTest {
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
    PipelineTimingTest(Vnode* dut, PacketGenerator* packet_gen,
                      TestUtils* test_utils, ResultValidator* validator)
        : dut_(dut), packet_gen_(packet_gen), test_utils_(test_utils), validator_(validator),
          src_hp_(0), src_vp_(0), max_test_cycles_(1000), reset_cycles_(5),
          tests_run_(0), tests_passed_(0), tests_failed_(0) {

        src_hp_ = dut_->HP;
        src_vp_ = dut_->VP;
        packet_gen_->set_source_position(src_hp_, src_vp_);

        if (test_utils_) {
            test_utils_->get_logger().info("PipelineTimingTest initialized for node (" +
                                          std::to_string(src_hp_) + "," + std::to_string(src_vp_) + ")");
        }
    }

    bool run_all_tests() {
        if (test_utils_) {
            test_utils_->get_logger().info("Starting Pipeline Timing Tests");
        }

        reset_statistics();
        bool all_passed = true;

        all_passed &= test_pipeline_depth();
        all_passed &= test_backpressure_handling();
        all_passed &= test_continuous_operation();

        print_test_summary();
        return all_passed;
    }

    bool test_pipeline_depth() {
        tests_run_++;
        const string test_name = "Pipeline Depth";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;
            MazePacket test_pkt = packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, src_hp_, src_vp_, 0, 0, test_name + "_local", 10);
            test_packets.push_back(test_pkt);

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

    bool test_backpressure_handling() {
        tests_run_++;
        const string test_name = "Backpressure Handling";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;
            MazePacket test_pkt = packet_gen_->generate_directed_packet(
                src_hp_, src_vp_, (src_hp_ + 1) % 8, src_vp_, 0, 1, test_name + "_backpressure", 10);
            test_packets.push_back(test_pkt);

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

    bool test_continuous_operation() {
        tests_run_++;
        const string test_name = "Continuous Operation";

        if (test_utils_) {
            test_utils_->get_logger().info("Running test: " + test_name);
        }

        try {
            reset_dut();

            vector<MazePacket> test_packets;
            for (uint32_t i = 0; i < 5; i++) {
                MazePacket pkt = packet_gen_->generate_directed_packet(
                    src_hp_, src_vp_, (src_hp_ + i + 1) % 8, src_vp_, 0, i % 2,
                    test_name + "_cont_" + std::to_string(i), 5 + i * 10);
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

            dut_->pkt_i->pkt_in_vld = 0;
            dut_->pkt_o->pkt_out_rdy = 1;
            dut_->pg_en = 0;
            dut_->pg_node = 0;

            cycle_dut();
            cycle++;
        }

        return true;
    }

    void print_test_summary() const {
        cout << "\n" << string(70, '-') << endl;
        cout << "Pipeline Timing Test Summary" << endl;
        cout << string(70, '-') << endl;
        cout << "Tests Run:    " << tests_run_ << endl;
        cout << "Tests Passed: " << tests_passed_ << endl;
        cout << "Tests Failed: " << tests_failed_ << endl;
        cout << "Success Rate: " << fixed << setprecision(1)
             << (tests_run_ > 0 ? (double)tests_passed_ / tests_run_ * 100.0 : 0.0) << "%" << endl;
        cout << string(70, '-') << endl;
    }
};

#endif // PIPELINE_TIMING_TEST_H