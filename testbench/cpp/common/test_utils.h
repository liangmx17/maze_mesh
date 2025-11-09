// ====================================================================
// MAZE Network Node - Test Utilities
// ====================================================================
//
// Common utility functions for testbench operation
// Includes timing measurement, logging, waveform generation, etc.
//
// ====================================================================

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>
#include <map>
#include <mutex>

using namespace std;

// ====================================================================
// Timing and Measurement Utilities
// ====================================================================
class Timer {
private:
    chrono::high_resolution_clock::time_point start_time_;
    chrono::high_resolution_clock::time_point end_time_;
    bool running_;

public:
    Timer() : running_(false) {}

    void start() {
        start_time_ = chrono::high_resolution_clock::now();
        running_ = true;
    }

    void stop() {
        if (running_) {
            end_time_ = chrono::high_resolution_clock::now();
            running_ = false;
        }
    }

    double get_elapsed_ms() const {
        auto end = running_ ? chrono::high_resolution_clock::now() : end_time_;
        auto duration = chrono::duration<double, milli>(end - start_time_);
        return duration.count();
    }

    double get_elapsed_us() const {
        auto end = running_ ? chrono::high_resolution_clock::now() : end_time_;
        auto duration = chrono::duration<double, micro>(end - start_time_);
        return duration.count();
    }

    uint64_t get_elapsed_ns() const {
        auto end = running_ ? chrono::high_resolution_clock::now() : end_time_;
        auto duration = chrono::duration<uint64_t, nano>(end - start_time_);
        return duration.count();
    }

    void reset() {
        running_ = false;
    }
};

// ====================================================================
// Statistics Collection
// ====================================================================
struct TestStatistics {
    uint64_t packets_sent;
    uint64_t packets_received;
    uint64_t packets_dropped;
    uint64_t errors_detected;
    uint64_t warnings_issued;
    double average_latency;
    double min_latency;
    double max_latency;
    double throughput_mpps;  // Million packets per second
    uint64_t simulation_cycles;
    double execution_time_ms;

    map<string, uint64_t> error_counts;
    map<string, uint64_t> warning_counts;

    TestStatistics() : packets_sent(0), packets_received(0), packets_dropped(0),
                       errors_detected(0), warnings_issued(0), average_latency(0.0),
                       min_latency(0.0), max_latency(0.0), throughput_mpps(0.0),
                       simulation_cycles(0), execution_time_ms(0.0) {}

    void reset() {
        packets_sent = 0;
        packets_received = 0;
        packets_dropped = 0;
        errors_detected = 0;
        warnings_issued = 0;
        average_latency = 0.0;
        min_latency = 0.0;
        max_latency = 0.0;
        throughput_mpps = 0.0;
        simulation_cycles = 0;
        execution_time_ms = 0.0;
        error_counts.clear();
        warning_counts.clear();
    }
};

// ====================================================================
// Logger Class
// ====================================================================
enum class LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    FATAL = 4
};

class Logger {
private:
    LogLevel min_level_;
    bool enable_file_output_;
    string log_filename_;
    ofstream log_file_;
    mutex log_mutex_;

public:
    explicit Logger(LogLevel min_level = LogLevel::INFO, bool enable_file = false,
                   const string& filename = "testbench.log")
        : min_level_(min_level), enable_file_output_(enable_file), log_filename_(filename) {

        if (enable_file_output_) {
            log_file_.open(log_filename_, ios::app);
            if (log_file_.is_open()) {
                log_file_ << "\n" << string(80, '=') << endl;
                log_file_ << "Testbench Log Started at " << get_timestamp() << endl;
                log_file_ << string(80, '=') << endl;
            }
        }
    }

    ~Logger() {
        if (log_file_.is_open()) {
            log_file_ << string(80, '=') << endl;
            log_file_ << "Testbench Log Ended at " << get_timestamp() << endl;
            log_file_ << string(80, '=') << endl;
            log_file_.close();
        }
    }

    void log(LogLevel level, const string& message, const string& test_id = "") {
        if (level < min_level_) return;

        lock_guard<mutex> lock(log_mutex_);
        string level_str;
        string prefix;

        switch (level) {
            case LogLevel::DEBUG:    level_str = "DEBUG";    prefix = "[DBG] "; break;
            case LogLevel::INFO:     level_str = "INFO";     prefix = "[INFO] "; break;
            case LogLevel::WARNING:  level_str = "WARNING";  prefix = "[WRN] "; break;
            case LogLevel::ERROR:    level_str = "ERROR";    prefix = "[ERR] "; break;
            case LogLevel::FATAL:    level_str = "FATAL";    prefix = "[FATAL] "; break;
        }

        string timestamp = get_timestamp();
        string full_message = timestamp + " " + prefix;
        if (!test_id.empty()) {
            full_message += "[" + test_id + "] ";
        }
        full_message += message;

        // Console output
        cout << full_message << endl;

        // File output
        if (enable_file_output_ && log_file_.is_open()) {
            log_file_ << full_message << endl;
            log_file_.flush();
        }

        // Special handling for fatal errors
        if (level == LogLevel::FATAL) {
            cerr << "FATAL ERROR: " << message << endl;
        }
    }

    void debug(const string& message, const string& test_id = "") {
        log(LogLevel::DEBUG, message, test_id);
    }

    void info(const string& message, const string& test_id = "") {
        log(LogLevel::INFO, message, test_id);
    }

    void warning(const string& message, const string& test_id = "") {
        log(LogLevel::WARNING, message, test_id);
    }

    void error(const string& message, const string& test_id = "") {
        log(LogLevel::ERROR, message, test_id);
    }

    void fatal(const string& message, const string& test_id = "") {
        log(LogLevel::FATAL, message, test_id);
    }
};

// ====================================================================
// Test Utilities Class
// ====================================================================
class TestUtils {
private:
    Logger logger_;
    Timer global_timer_;
    TestStatistics stats_;
    int verbosity_;

public:
    explicit TestUtils(int verbosity = 1, LogLevel log_level = LogLevel::INFO,
                       bool enable_file_logging = false)
        : logger_(log_level, enable_file_logging), verbosity_(verbosity) {
        global_timer_.start();
        logger_.info("TestUtils initialized with verbosity " + to_string(verbosity_));
    }

    // ====================================================================
    // Timing and Cycle Management
    // ====================================================================

    void start_global_timer() {
        global_timer_.start();
    }

    void update_statistics(uint64_t cycles) {
        stats_.simulation_cycles = cycles;
        stats_.execution_time_ms = global_timer_.get_elapsed_ms();

        if (stats_.execution_time_ms > 0) {
            stats_.throughput_mpps = (double)stats_.packets_received / (stats_.execution_time_ms / 1000.0) / 1000000.0;
        }
    }

    // ====================================================================
    // Utility Functions
    // ====================================================================

    string get_timestamp() const {
        auto now = chrono::system_clock::now();
        auto time_t = chrono::system_clock::to_time_t(now);
        auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

        stringstream ss;
        ss << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S");
        ss << '.' << setfill('0') << setw(3) << ms.count();
        return ss.str();
    }

    string format_duration(double ms) const {
        if (ms < 1000.0) {
            return to_string((int)ms) + " ms";
        } else if (ms < 60000.0) {
            return to_string(ms / 1000.0, 2) + " s";
        } else {
            int minutes = (int)(ms / 60000.0);
            double seconds = (ms - minutes * 60000.0) / 1000.0;
            return to_string(minutes) + " min " + to_string(seconds, 1) + " s";
        }
    }

    string format_number(uint64_t num, const string& suffix = "") const {
        if (num < 1000) {
            return to_string(num) + suffix;
        } else if (num < 1000000) {
            return to_string(num / 1000.0, 1) + "K" + suffix;
        } else if (num < 1000000000) {
            return to_string(num / 1000000.0, 1) + "M" + suffix;
        } else {
            return to_string(num / 1000000000.0, 1) + "G" + suffix;
        }
    }

    // ====================================================================
    // Packet Tracking and Validation
    // ====================================================================

    void packet_sent() {
        stats_.packets_sent++;
    }

    void packet_received() {
        stats_.packets_received++;
    }

    void packet_dropped() {
        stats_.packets_dropped++;
    }

    void error_detected(const string& error_type) {
        stats_.errors_detected++;
        stats_.error_counts[error_type]++;
        logger_.error("Error detected: " + error_type);
    }

    void warning_issued(const string& warning_type) {
        stats_.warnings_issued++;
        stats_.warning_counts[warning_type]++;
        logger_.warning("Warning: " + warning_type);
    }

    void record_latency(double latency_ms) {
        if (stats_.packets_received == 1) {
            stats_.min_latency = latency_ms;
            stats_.max_latency = latency_ms;
            stats_.average_latency = latency_ms;
        } else {
            stats_.min_latency = min(stats_.min_latency, latency_ms);
            stats_.max_latency = max(stats_.max_latency, latency_ms);
            stats_.average_latency = ((stats_.average_latency * (stats_.packets_received - 1)) + latency_ms) / stats_.packets_received;
        }
    }

    // ====================================================================
    // Statistics and Reporting
    // ====================================================================

    const TestStatistics& get_statistics() const {
        return stats_;
    }

    void reset_statistics() {
        stats_.reset();
    }

    void print_statistics() const {
        cout << "\n" << string(70, '=') << endl;
        cout << "Test Statistics Summary" << endl;
        cout << string(70, '=') << endl;

        cout << "Performance Metrics:" << endl;
        cout << "  Packets Sent:     " << format_number(stats_.packets_sent) << endl;
        cout << "  Packets Received: " << format_number(stats_.packets_received) << endl;
        cout << "  Packets Dropped:  " << format_number(stats_.packets_dropped) << endl;
        cout << "  Success Rate:     " << fixed << setprecision(2)
             << (stats_.packets_sent > 0 ? (double)stats_.packets_received / stats_.packets_sent * 100.0 : 0.0) << "%" << endl;

        if (stats_.packets_received > 0) {
            cout << "  Average Latency: " << fixed << setprecision(2) << stats_.average_latency << " cycles" << endl;
            cout << "  Min Latency:     " << fixed << setprecision(2) << stats_.min_latency << " cycles" << endl;
            cout << "  Max Latency:     " << fixed << setprecision(2) << stats_.max_latency << " cycles" << endl;
        }

        if (stats_.execution_time_ms > 0) {
            cout << "  Throughput:       " << fixed << setprecision(2) << stats_.throughput_mpps << " MPPS" << endl;
            cout << "  Sim Speed:        " << format_number((uint64_t)(stats_.simulation_cycles / (stats_.execution_time_ms / 1000.0))) << " cycles/sec" << endl;
        }

        cout << "\nExecution Details:" << endl;
        cout << "  Simulation Cycles: " << format_number(stats_.simulation_cycles) << endl;
        cout << "  Execution Time:    " << format_duration(stats_.execution_time_ms) << endl;

        if (stats_.errors_detected > 0) {
            cout << "\nError Summary (" << stats_.errors_detected << " total):" << endl;
            for (const auto& error : stats_.error_counts) {
                cout << "  " << setw(20) << left << error.first << ": " << error.second << endl;
            }
        }

        if (stats_.warnings_issued > 0) {
            cout << "\nWarning Summary (" << stats_.warnings_issued << " total):" << endl;
            for (const auto& warning : stats_.warning_counts) {
                cout << "  " << setw(20) << left << warning.first << ": " << warning.second << endl;
            }
        }

        cout << string(70, '=') << endl;
    }

    bool export_statistics(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            logger_.error("Cannot open statistics export file: " + filename);
            return false;
        }

        file << "# MAZE Network Node Test Statistics" << endl;
        file << "# Generated at: " << get_timestamp() << endl;
        file << endl;

        file << "[Performance]" << endl;
        file << "packets_sent=" << stats_.packets_sent << endl;
        file << "packets_received=" << stats_.packets_received << endl;
        file << "packets_dropped=" << stats_.packets_dropped << endl;
        file << "success_rate=" << fixed << setprecision(4)
             << (stats_.packets_sent > 0 ? (double)stats_.packets_received / stats_.packets_sent : 0.0) << endl;
        file << "average_latency=" << stats_.average_latency << endl;
        file << "min_latency=" << stats_.min_latency << endl;
        file << "max_latency=" << stats_.max_latency << endl;
        file << "throughput_mpps=" << stats_.throughput_mpps << endl;
        file << endl;

        file << "[Execution]" << endl;
        file << "simulation_cycles=" << stats_.simulation_cycles << endl;
        file << "execution_time_ms=" << stats_.execution_time_ms << endl;
        file << endl;

        if (!stats_.error_counts.empty()) {
            file << "[Errors]" << endl;
            for (const auto& error : stats_.error_counts) {
                file << error.first << "=" << error.second << endl;
            }
            file << endl;
        }

        if (!stats_.warning_counts.empty()) {
            file << "[Warnings]" << endl;
            for (const auto& warning : stats_.warning_counts) {
                file << warning.first << "=" << warning.second << endl;
            }
            file << endl;
        }

        file.close();
        logger_.info("Statistics exported to: " + filename);
        return true;
    }

    // ====================================================================
    // Test Helper Functions
    // ====================================================================

    bool compare_packets(const MazePacket& expected, const MazePacket& actual, const string& context = "") {
        bool equal = expected.equals(actual);

        if (!equal) {
            string error_msg = "Packet mismatch in " + context;
            error_msg += "\n  Expected: " + expected.to_string();
            error_msg += "\n  Actual:   " + actual.to_string();
            error_detected("packet_mismatch");
            logger_.error(error_msg);
        }

        return equal;
    }

    void log_packet_injection(const MazePacket& packet, const string& interface = "A") {
        if (verbosity_ >= 2) {
            string msg = "Packet injected on " + interface + " interface: " + packet.to_string();
            logger_.info(msg, packet.test_id);
        }
        packet_sent();
    }

    void log_packet_reception(const MazePacket& packet, const string& interface = "B", uint64_t latency = 0) {
        if (verbosity_ >= 2) {
            string msg = "Packet received on " + interface + " interface: " + packet.to_string();
            if (latency > 0) {
                msg += " (latency: " + to_string(latency) + " cycles)";
            }
            logger_.info(msg, packet.test_id);
        }
        packet_received();
        if (latency > 0) {
            record_latency(latency);
        }
    }

    // ====================================================================
    // Configuration and Verbosity
    // ====================================================================

    int get_verbosity() const { return verbosity_; }
    void set_verbosity(int level) { verbosity_ = level; }

    bool is_verbose(int level = 1) const { return verbosity_ >= level; }

    Logger& get_logger() { return logger_; }
};

// ====================================================================
// Utility Functions
// ====================================================================

// Convert string to lowercase
string to_lower(const string& str);

// Convert string to uppercase
string to_upper(const string& str);

// Convert value to string with specified precision
string to_string(double value, int precision = 2);

// Check if file exists
bool file_exists(const string& filename);

// Create directory if it doesn't exist
bool create_directory(const string& path);

// Generate unique test ID
string generate_test_id(const string& prefix = "test");

// Convert cycles to time based on frequency (MHz)
double cycles_to_time(uint64_t cycles, double frequency_mhz = 100.0);

#endif // TEST_UTILS_H