#include "Vsimple_fifo.h"
#include "verilated.h"
#include <iostream>
#include <vector>
#include <iomanip>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vsimple_fifo* dut = new Vsimple_fifo;

    vluint64_t sim_time = 0;
    std::vector<uint8_t> written;
    std::vector<uint8_t> read;

    // Simple clock tick
    auto tick = [&]() {
        dut->clk = 1;
        dut->eval();
        dut->clk = 0;
        dut->eval();
        sim_time += 10;
    };

    // Reset
    dut->rst_n = 0;
    dut->wr_en = 0;
    dut->rd_en = 0;
    dut->wr_data = 0;
    for (int i = 0; i < 5; i++) tick();
    dut->rst_n = 1;

    std::cout << "=== SIMPLE FIFO TEST - FOCUS ON BASIC READ/WRITE ===" << std::endl;

    // Test 1: Write 3 items, read 3 items - step by step
    std::cout << "\nTest 1: Write 3, Read 3" << std::endl;

    // Write 3 items one by one
    for (int i = 0; i < 3; i++) {
        dut->wr_en = 1;
        dut->rd_en = 0;
        dut->wr_data = 0x10 + i;
        tick();
        written.push_back(0x10 + i);
        std::cout << "Wrote 0x" << std::hex << (0x10 + i) << ", count=" << (int)dut->count << std::endl;
    }
    dut->wr_en = 0;

    std::cout << "\nNow reading 3 items:" << std::endl;

    // Method: Read items by asserting rd_en, then capturing data on NEXT tick
    for (int i = 0; i < 3; i++) {
        // Assert rd_en
        dut->rd_en = 1;
        tick();  // This tick causes the data to be latched into rd_data_reg

        // Capture the data that just appeared
        uint8_t data = dut->rd_data;
        read.push_back(data);
        std::cout << "Read 0x" << std::hex << (int)data << ", count=" << (int)dut->count << std::endl;

        // Deassert rd_en for this cycle
        dut->rd_en = 0;
    }

    // Test 2: Simultaneous read/write
    std::cout << "\nTest 2: Simultaneous read/write" << std::endl;

    // Write 2 items first
    dut->wr_en = 1;
    dut->wr_data = 0x20; tick();
    dut->wr_data = 0x21; tick();
    dut->wr_en = 0;
    written.push_back(0x20);
    written.push_back(0x21);

    // Now do simultaneous read/write for 2 cycles
    std::cout << "Simultaneous operations:" << std::endl;
    for (int i = 0; i < 2; i++) {
        dut->wr_en = 1;
        dut->rd_en = 1;
        dut->wr_data = 0x30 + i;
        tick();

        uint8_t data = dut->rd_data;
        read.push_back(data);
        written.push_back(0x30 + i);

        std::cout << "Write 0x" << std::hex << (0x30 + i) << ", Read 0x" << (int)data << std::endl;
    }
    dut->wr_en = 0;
    dut->rd_en = 0;

    // Test 3: Read remaining items
    std::cout << "\nTest 3: Read remaining items" << std::endl;
    while (!dut->empty) {
        dut->rd_en = 1;
        tick();
        uint8_t data = dut->rd_data;
        read.push_back(data);
        std::cout << "Final read 0x" << std::hex << (int)data << std::endl;
        dut->rd_en = 0;
    }

    // Verification
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "VERIFICATION" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << "Written: " << written.size() << " items" << std::endl;
    std::cout << "Read:    " << read.size() << " items" << std::endl;

    bool success = true;
    size_t check_count = std::min(written.size(), read.size());

    for (size_t i = 0; i < check_count; i++) {
        std::cout << "[" << std::setw(2) << i << "] W:0x" << std::hex << std::setw(2) << std::setfill('0') << (int)written[i]
                  << " R:0x" << std::setw(2) << (int)read[i];
        if (written[i] == read[i]) {
            std::cout << " ✓" << std::endl;
        } else {
            std::cout << " ✗" << std::endl;
            success = false;
        }
    }

    std::cout << "\nRESULT: " << (success ? "✅ PASSED" : "❌ FAILED") << std::endl;

    dut->final();
    delete dut;
    return success ? 0 : 1;
}