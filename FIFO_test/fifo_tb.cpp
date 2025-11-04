#include "Vsimple_fifo.h"
#include "verilated.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);

    // Create DUT instance
    Vsimple_fifo* dut = new Vsimple_fifo;

    // Simulation variables
    vluint64_t sim_time = 0;
    std::vector<uint8_t> expected_data;
    std::vector<uint8_t> actual_data;

    // Helper function: one clock cycle
    auto tick = [&]() {
        dut->clk = 1;
        dut->eval();
        dut->clk = 0;
        dut->eval();
        sim_time += 10;
    };

    // Helper function: reset sequence
    auto reset = [&]() {
        dut->rst_n = 0;
        dut->wr_en = 0;
        dut->rd_en = 0;
        dut->wr_data = 0;
        for (int i = 0; i < 5; i++) {
            tick();
        }
        dut->rst_n = 1;
    };

    reset();

    std::cout << "Starting FIFO simulation..." << std::endl;
    std::cout << "FIFO has registered read output (1-cycle latency)" << std::endl;

    // Test 1: Write 5 items, then read them back
    std::cout << "\n=== Test 1: Write 5 items, then read back ===" << std::endl;

    // Write 5 items (0x10, 0x11, 0x12, 0x13, 0x14)
    for (int i = 0; i < 5; i++) {
        dut->wr_en = 1;
        dut->rd_en = 0;
        dut->wr_data = 0x10 + i;
        tick();

        std::cout << "Write 0x" << std::hex << (0x10 + i)
                  << " -> Count=" << (int)dut->count << std::endl;

        expected_data.push_back(0x10 + i);
    }
    dut->wr_en = 0;

    // Read back 5 items with proper timing
    std::cout << "\nReading 5 items (with 1-cycle latency):" << std::endl;

    // Cycle 0: Trigger first read (no data available yet due to latency)
    dut->rd_en = 1;
    tick();  // rd_ptr increments, but rd_data still shows old/reset value

    // Cycle 1: First valid data appears
    tick();  // Now 0x10 appears on rd_data

    // Now capture the 5 items
    for (int i = 0; i < 5; i++) {
        if (!dut->empty) {
            uint8_t read_val = dut->rd_data;
            actual_data.push_back(read_val);

            std::cout << "Read 0x" << std::hex << (int)read_val
                      << " -> Count=" << (int)dut->count << std::endl;
        }

        // Keep rd_en high until the last read
        dut->rd_en = (i < 4);
        tick();
    }
    dut->rd_en = 0;

    // Test 2: Simultaneous read/write operations
    std::cout << "\n=== Test 2: Simultaneous read/write (3 items) ===" << std::endl;

    // First, write 2 items
    dut->wr_en = 1;
    dut->rd_en = 0;
    dut->wr_data = 0x20;
    tick();
    dut->wr_data = 0x21;
    tick();
    dut->wr_en = 0;

    expected_data.push_back(0x20);
    expected_data.push_back(0x21);

    // Now do simultaneous read/write for 3 cycles
    std::cout << "Simultaneous operations:" << std::endl;

    // Trigger first read (1-cycle latency)
    dut->rd_en = 1;
    tick();
    tick();  // First read data (0x20) appears

    // Now perform 3 cycles of simultaneous read/write
    for (int i = 0; i < 3; i++) {
        dut->wr_en = 1;
        dut->rd_en = 1;
        dut->wr_data = 0x22 + i;
        tick();

        uint8_t read_val = dut->rd_data;
        actual_data.push_back(read_val);
        expected_data.push_back(0x22 + i);

        std::cout << "Write 0x" << std::hex << (0x22 + i)
                  << ", Read 0x" << (int)read_val << std::endl;
    }
    dut->wr_en = 0;
    dut->rd_en = 0;

    // Test 3: Fill to capacity and empty
    std::cout << "\n=== Test 3: Fill to capacity, then empty ===" << std::endl;

    int write_count = 0;
    while (!dut->full && write_count < 8) {
        dut->wr_en = 1;
        dut->rd_en = 0;
        dut->wr_data = 0x30 + write_count;
        tick();

        if (!dut->full) {
            expected_data.push_back(0x30 + write_count);
            write_count++;
        }
    }
    dut->wr_en = 0;

    std::cout << "FIFO is full. Count=" << (int)dut->count << std::endl;
    std::cout << "Written " << write_count << " items to fill FIFO." << std::endl;

    // Empty the FIFO
    std::cout << "\nEmptying FIFO:" << std::endl;

    // Trigger first read
    dut->rd_en = 1;
    tick();  // rd_ptr increments
    tick();  // First valid data appears

    int read_count = 0;
    while (!dut->empty) {
        uint8_t read_val = dut->rd_data;
        actual_data.push_back(read_val);
        read_count++;

        std::cout << "Read " << read_count << ": 0x" << std::hex << (int)read_val << std::endl;

        // Keep rd_en high until empty
        dut->rd_en = !dut->empty;
        tick();
    }
    dut->rd_en = 0;

    // Test 4: Edge case - read from empty FIFO
    std::cout << "\n=== Test 4: Edge case - read from empty FIFO ===" << std::endl;

    std::cout << "FIFO empty: " << (dut->empty ? "YES" : "NO") << std::endl;
    std::cout << "Attempting to read from empty FIFO..." << std::endl;

    dut->rd_en = 1;
    tick();  // Should not increment rd_ptr
    tick();  // Should still show empty/no data

    std::cout << "After read attempt - FIFO empty: " << (dut->empty ? "YES" : "NO") << std::endl;
    std::cout << "Read data: 0x" << std::hex << (int)dut->rd_data << std::endl;

    dut->rd_en = 0;

    // Final verification
    std::cout << "\n=== FINAL VERIFICATION ===" << std::endl;
    std::cout << "Expected items: " << expected_data.size() << std::endl;
    std::cout << "Actual items: " << actual_data.size() << std::endl;

    bool test_passed = true;
    size_t check_count = std::min(expected_data.size(), actual_data.size());

    std::cout << "\nData integrity check:" << std::endl;
    for (size_t i = 0; i < check_count; i++) {
        std::cout << "Index " << std::dec << i << ": Expected 0x" << std::hex << (int)expected_data[i]
                  << ", Got 0x" << (int)actual_data[i];
        if (expected_data[i] == actual_data[i]) {
            std::cout << " ✓" << std::endl;
        } else {
            std::cout << " ✗" << std::endl;
            test_passed = false;
        }
    }

    if (expected_data.size() != actual_data.size()) {
        std::cout << "\n⚠️  Size mismatch!" << std::endl;
        std::cout << "Expected " << expected_data.size() << " items, got " << actual_data.size() << std::endl;
        test_passed = false;
    }

    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "SIMULATION RESULT: " << (test_passed ? "PASSED ✅" : "FAILED ❌") << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    // Cleanup
    dut->final();
    delete dut;

    return test_passed ? 0 : 1;
}