// ====================================================================
// MAZE Network Node - Node Simulator Wrapper
// ====================================================================
//
// Common wrapper for Verilator node simulation
// Provides unified interface for all focused tests
//
// ====================================================================

#ifndef NODE_SIMULATOR_H
#define NODE_SIMULATOR_H

#include "Vnode.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "packet_utils.h"
#include <string>
#include <memory>
#include <chrono>

using namespace std;

// ====================================================================
// Simulation Configuration
// ====================================================================

struct NodeSimConfig {
    uint32_t hp = 3;               // Horizontal position [0-7]
    uint32_t vp = 2;               // Vertical position [0-7]
    bool enable_vcd = false;       // Enable VCD waveform generation
    string vcd_file = "node_sim.vcd";
    uint32_t reset_cycles = 5;     // Reset sequence length
    bool verbose = false;          // Enable verbose output
    uint64_t max_cycles = 10000;   // Maximum simulation cycles
};

// ====================================================================
// Simulation Statistics
// ====================================================================

struct SimStats {
    uint64_t cycles_run = 0;
    uint64_t packets_in = 0;
    uint64_t packets_out = 0;
    uint64_t errors = 0;
    double execution_time_ms = 0.0;

    void reset() {
        cycles_run = 0;
        packets_in = 0;
        packets_out = 0;
        errors = 0;
        execution_time_ms = 0.0;
    }

    string summary() const {
        stringstream ss;
        ss << "Simulation Stats: cycles=" << cycles_run
           << ", packets_in=" << packets_in
           << ", packets_out=" << packets_out
           << ", errors=" << errors
           << ", time=" << fixed << setprecision(2) << execution_time_ms << "ms";
        return ss.str();
    }
};

// ====================================================================
// Node Simulator Class
// ====================================================================

class NodeSimulator {
private:
    // Verilator components
    unique_ptr<VerilatedContext> context_;
    unique_ptr<Vnode> dut_;
    unique_ptr<VerilatedVcdC> vcd_;

    // Configuration and state
    NodeSimConfig config_;
    SimStats stats_;
    uint64_t sim_time_;
    bool reset_active_;
    bool initialized_;

public:
    NodeSimulator(const NodeSimConfig& config = NodeSimConfig())
        : config_(config), sim_time_(0), reset_active_(false), initialized_(false) {

        // Initialize Verilator context
        context_ = make_unique<VerilatedContext>();
        context_->commandArgs(0, nullptr);
        context_->debug(config_.verbose);

        // Create DUT instance
        dut_ = make_unique<Vnode>(context_.get(), "dut");

        if (config_.verbose) {
            cout << "[INIT] Node simulator created" << endl;
        }
    }

    ~NodeSimulator() {
        if (vcd_) {
            vcd_->close();
        }
    }

    // =================================================================
    // Initialization and Reset
    // =================================================================

    bool initialize() {
        if (initialized_) {
            return true;
        }

        // Set node position parameters
        dut_->HP = config_.hp;
        dut_->VP = config_.vp;

        // Initialize VCD if enabled
        if (config_.enable_vcd) {
            Verilated::traceEverOn(true);
            vcd_ = make_unique<VerilatedVcdC>();
            dut_->trace(vcd_.get(), 99);
            vcd_->open(config_.vcd_file.c_str());

            if (config_.verbose) {
                cout << "[INIT] VCD trace enabled: " << config_.vcd_file << endl;
            }
        }

        // Reset statistics
        stats_.reset();

        // Run reset sequence
        reset_sequence();

        initialized_ = true;

        if (config_.verbose) {
            cout << "[INIT] Node initialized at position (" << config_.hp
                 << ", " << config_.vp << ")" << endl;
        }

        return true;
    }

    void reset_sequence() {
        if (config_.verbose) {
            cout << "[RESET] Starting reset sequence..." << endl;
        }

        // Assert reset
        dut_->rst_n = 0;
        reset_active_ = true;

        // Clear all inputs
        clear_inputs();

        // Run reset cycles
        for (uint32_t i = 0; i < config_.reset_cycles; i++) {
            step();
        }

        // Deassert reset
        dut_->rst_n = 1;
        reset_active_ = false;

        if (config_.verbose) {
            cout << "[RESET] Reset sequence completed" << endl;
        }
    }

    // =================================================================
    // Simulation Control
    // =================================================================

    void step() {
        // Toggle clock
        dut_->clk = 0;
        dut_->eval();
        if (vcd_) vcd_->dump(sim_time_++);

        dut_->clk = 1;
        dut_->eval();
        if (vcd_) vcd_->dump(sim_time_++);

        stats_.cycles_run++;
    }

    void run_cycles(uint64_t cycles) {
        for (uint64_t i = 0; i < cycles && stats_.cycles_run < config_.max_cycles; i++) {
            step();

            if (context_->gotFinish()) {
                if (config_.verbose) {
                    cout << "[SIM] Verilator requested finish at cycle " << i << endl;
                }
                break;
            }
        }
    }

    void run_until_output_ready(uint64_t max_wait = 100) {
        for (uint64_t i = 0; i < max_wait && stats_.cycles_run < config_.max_cycles; i++) {
            step();
            if (dut_->pkt_out_valid) {
                break;
            }
        }
    }

    void run_until_input_ready(uint64_t max_wait = 100) {
        for (uint64_t i = 0; i < max_wait && stats_.cycles_run < config_.max_cycles; i++) {
            step();
            if (dut_->pkt_in_ready) {
                break;
            }
        }
    }

    // =================================================================
    // Input/Output Interface
    // =================================================================

    void clear_inputs() {
        dut_->pkt_in_valid = 0;
        dut_->pkt_in_data = 0;
        dut_->pkt_out_ready = 0;

        // Clear C interface inputs
        for (int i = 0; i < 4; i++) {
            dut_->pkt_con_if[i].ready = 1;  // Assume ready to accept
            dut_->pkt_con_if[i].valid = 0;
            dut_->pkt_con_if[i].data = 0;
        }
    }

    bool send_packet(uint32_t packet_data) {
        // Wait for ready
        run_until_input_ready();

        if (!dut_->pkt_in_ready) {
            if (config_.verbose) {
                cout << "[ERROR] Input not ready for packet: 0x"
                     << hex << packet_data << dec << endl;
            }
            stats_.errors++;
            return false;
        }

        // Send packet
        dut_->pkt_in_valid = 1;
        dut_->pkt_in_data = packet_data;
        step();

        // Clear inputs
        dut_->pkt_in_valid = 0;
        dut_->pkt_in_data = 0;

        stats_.packets_in++;

        if (config_.verbose) {
            Packet pkt = PacketUtils::parse_packet(packet_data);
            cout << "[SEND] " << pkt.description << endl;
        }

        return true;
    }

    bool receive_packet(uint32_t& packet_data, uint64_t max_wait = 100) {
        // Wait for valid output
        for (uint64_t i = 0; i < max_wait && stats_.cycles_run < config_.max_cycles; i++) {
            step();
            if (dut_->pkt_out_valid) {
                dut_->pkt_out_ready = 1;
                packet_data = dut_->pkt_out_data;
                step();
                dut_->pkt_out_ready = 0;

                stats_.packets_out++;

                if (config_.verbose) {
                    Packet pkt = PacketUtils::parse_packet(packet_data);
                    cout << "[RECV] " << pkt.description << endl;
                }

                return true;
            }
        }

        if (config_.verbose) {
            cout << "[ERROR] Timeout waiting for output packet" << endl;
        }
        stats_.errors++;
        return false;
    }

    // =================================================================
    // Interface Status Methods
    // =================================================================

    bool is_input_ready() const {
        return dut_->pkt_in_ready;
    }

    bool is_output_valid() const {
        return dut_->pkt_out_valid;
    }

    bool is_reset_active() const {
        return reset_active_;
    }

    // =================================================================
    // Configuration Methods
    // =================================================================

    void set_node_position(uint32_t hp, uint32_t vp) {
        if (!initialized_) {
            config_.hp = hp % 8;
            config_.vp = vp % 8;
            dut_->HP = config_.hp;
            dut_->VP = config_.vp;
        }
    }

    void set_verbose(bool verbose) {
        config_.verbose = verbose;
        context_->debug(verbose);
    }

    // =================================================================
    // Statistics and Reporting
    // =================================================================

    const SimStats& get_stats() const {
        return stats_;
    }

    void print_stats() const {
        cout << stats_.summary() << endl;
    }

    string get_status() const {
        stringstream ss;
        ss << "Node(" << config_.hp << "," << config_.vp << ") "
           << "[clk=" << dut_->clk
           << ", rst=" << (dut_->rst_n ? "1" : "0")
           << ", in_ready=" << (dut_->pkt_in_ready ? "1" : "0")
           << ", out_valid=" << (dut_->pkt_out_valid ? "1" : "0")
           << ", cycles=" << stats_.cycles_run << "]";
        return ss.str();
    }

    // =================================================================
    // Utility Methods
    // =================================================================

    uint64_t get_simulation_time() const {
        return sim_time_;
    }

    void flush_vcd() {
        if (vcd_) {
            vcd_->flush();
        }
    }

    bool validate_node_state() {
        // Basic state validation
        if (dut_->HP >= 8 || dut_->VP >= 8) {
            if (config_.verbose) {
                cout << "[ERROR] Invalid node position: HP=" << dut_->HP
                     << ", VP=" << dut_->VP << endl;
            }
            return false;
        }

        if (reset_active_ && (dut_->pkt_in_ready || dut_->pkt_out_valid)) {
            if (config_.verbose) {
                cout << "[ERROR] Interface active during reset" << endl;
            }
            return false;
        }

        return true;
    }

    // =================================================================
    // Advanced Operations
    // =================================================================

    template<typename Func>
    void timed_operation(const string& operation_name, Func operation) {
        auto start = chrono::high_resolution_clock::now();

        if (config_.verbose) {
            cout << "[OP] Starting " << operation_name << "..." << endl;
        }

        operation();

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double, milli>(end - start);

        if (config_.verbose) {
            cout << "[OP] " << operation_name << " completed in "
                 << fixed << setprecision(2) << duration.count() << "ms" << endl;
        }

        stats_.execution_time_ms += duration.count();
    }

    bool simulate_packet_throughput(const vector<Packet>& packets) {
        return timed_operation("throughput_test", [&]() {
            for (const auto& pkt : packets) {
                if (!send_packet(pkt.data)) {
                    return;
                }

                // Allow some processing time
                run_cycles(5);
            }
        });
    }
};

#endif // NODE_SIMULATOR_H