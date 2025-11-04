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
    int cycle = 0;

    // Helper function: one clock cycle with detailed debug
    auto tick_debug = [&](const std::string& description) {
        std::cout << "\n--- Cycle " << cycle << ": " << description << " ---" << std::endl;

        // Pre-clock evaluation
        std::cout << "Before clock: wr_en=" << dut->wr_en << ", rd_en=" << dut->rd_en
                  << ", wr_data=0x" << std::hex << (int)dut->wr_data
                  << ", rd_data=0x" << (int)dut->rd_data
                  << ", full=" << dut->full << ", empty=" << dut->empty
                  << ", count=" << (int)dut->count << std::endl;

        dut->clk = 1;
        dut->eval();
        dut->clk = 0;
        dut->eval();

        // Post-clock evaluation
        std::cout << "After clock:  rd_data=0x" << std::hex << (int)dut->rd_data
                  << ", full=" << dut->full << ", empty=" << dut->empty
                  << ", count=" << (int)dut->count << std::endl;

        sim_time += 10;
        cycle++;
    };

    // Reset
    std::cout << "=== RESET SEQUENCE ===" << std::endl;
    dut->rst_n = 0;
    dut->wr_en = 0;
    dut->rd_en = 0;
    dut->wr_data = 0;
    for (int i = 0; i < 3; i++) {
        tick_debug("Reset active");
    }
    dut->rst_n = 1;
    tick_debug("Reset released");

    // Test 1: Simple write and read with detailed timing
    std::cout << "\n=== TEST 1: SIMPLE WRITE + READ WITH DETAILED TIMING ===" << std::endl;

    // Write one item
    dut->wr_en = 1;
    dut->rd_en = 0;
    dut->wr_data = 0x55;
    tick_debug("Write 0x55");
    dut->wr_en = 0;

    // Write another item
    dut->wr_en = 1;
    dut->rd_en = 0;
    dut->wr_data = 0xAA;
    tick_debug("Write 0xAA");
    dut->wr_en = 0;

    // Read with detailed timing
    std::cout << "\n--- Starting read sequence ---" << std::endl;
    dut->rd_en = 1;
    tick_debug("Read enable asserted (1st cycle)");
    tick_debug("Read data should appear (2nd cycle)");
    tick_debug("Read enable still high (3rd cycle)");
    tick_debug("Read enable still high (4th cycle)");
    dut->rd_en = 0;
    tick_debug("Read enable deasserted");

    // Test 2: Step-by-step single read operation
    std::cout << "\n=== TEST 2: STEP-BY-STEP SINGLE READ OPERATION ===" << std::endl;

    // Reset the FIFO
    dut->rst_n = 0;
    for (int i = 0; i < 3; i++) {
        dut->clk = 1; dut->eval(); dut->clk = 0; dut->eval();
    }
    dut->rst_n = 1;
    for (int i = 0; i < 2; i++) {
        dut->clk = 1; dut->eval(); dut->clk = 0; dut->eval();
    }

    // Write 3 items
    uint8_t test_data[] = {0x11, 0x22, 0x33};
    for (int i = 0; i < 3; i++) {
        dut->wr_en = 1;
        dut->rd_en = 0;
        dut->wr_data = test_data[i];
        tick_debug("Write " + std::to_string(i));
        dut->wr_en = 0;
    }

    // Now read items one by one with detailed timing
    std::cout << "\n--- Reading items one by one ---" << std::endl;

    for (int read_idx = 0; read_idx < 3; read_idx++) {
        std::cout << "\nReading item " << read_idx << ":" << std::endl;

        // Assert rd_en
        dut->rd_en = 1;
        tick_debug("Assert rd_en");

        // Keep rd_en high for one more cycle
        tick_debug("Keep rd_en high (data should appear)");

        // Deassert rd_en
        dut->rd_en = 0;
        tick_debug("Deassert rd_en");
    }

    // Test 3: Different approach - continuous read
    std::cout << "\n=== TEST 3: CONTINUOUS READ APPROACH ===" << std::endl;

    // Reset and write 3 items
    dut->rst_n = 0;
    for (int i = 0; i < 3; i++) {
        dut->clk = 1; dut->eval(); dut->clk = 0; dut->eval();
    }
    dut->rst_n = 1;
    for (int i = 0; i < 2; i++) {
        dut->clk = 1; dut->eval(); dut->clk = 0; dut->eval();
    }

    // Write 3 items (0x99, 0xAA, 0xBB)
    dut->wr_en = 1;
    dut->wr_data = 0x99; tick_debug("Write 0x99");
    dut->wr_data = 0xAA; tick_debug("Write 0xAA");
    dut->wr_data = 0xBB; tick_debug("Write 0xBB");
    dut->wr_en = 0;

    // Continuous read
    std::cout << "\n--- Continuous read ---" << std::endl;
    dut->rd_en = 1;
    tick_debug("Start continuous read");
    tick_debug("Data 1 should appear");
    tick_debug("Data 2 should appear");
    tick_debug("Data 3 should appear");
    tick_debug("Should be empty now");
    dut->rd_en = 0;

    std::cout << "\n=== ANALYSIS COMPLETE ===" << std::endl;

    // Cleanup
    dut->final();
    delete dut;

    return 0;
}