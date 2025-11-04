#include "Vsimple_fifo.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    // Initialize Verilator context
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    // Create FIFO instance
    Vsimple_fifo* fifo = new Vsimple_fifo{contextp, "FIFO"};

    // Simulation variables
    vluint64_t sim_time = 0;

    // Helper function for one clock cycle
    auto tick = [&]() {
        fifo->clk = 0;
        fifo->eval();
        fifo->clk = 1;
        fifo->eval();
        sim_time += 10;
    };

    // Helper function for reset
    auto reset = [&]() {
        std::cout << "\n--- Resetting FIFO ---" << std::endl;
        fifo->rst_n = 0;
        fifo->wr_en = 0;
        fifo->rd_en = 0;
        fifo->wr_data = 0;

        for (int i = 0; i < 3; i++) {
            tick();
        }

        fifo->rst_n = 1;
        std::cout << "Reset complete. Empty: " << (fifo->empty ? "YES" : "NO")
                  << ", Full: " << (fifo->full ? "YES" : "NO") << std::endl;
    };

    // Initialize and reset
    reset();

    // Test: Basic write and read
    std::cout << "\n=== Basic FIFO Test ===" << std::endl;

    // Write some data
    std::cout << "\nWriting data: ";
    for (int i = 0; i < 4; i++) {
        fifo->wr_en = 1;
        fifo->rd_en = 0;
        fifo->wr_data = 0x10 + i;
        tick();
        std::cout << "0x" << std::hex << (0x10 + i) << " ";
    }
    fifo->wr_en = 0;
    std::cout << "\nFIFO count: " << std::dec << (int)fifo->count << std::endl;

    // Read data back
    std::cout << "\nReading data: ";
    fifo->rd_en = 1;
    tick();  // First read data appears

    for (int i = 0; i < 4; i++) {
        uint8_t data = fifo->rd_data;
        std::cout << "0x" << std::hex << (int)data << " ";

        // Keep read enable high until last item
        fifo->rd_en = (i < 3);
        tick();
    }
    fifo->rd_en = 0;
    std::cout << "\nFIFO count: " << std::dec << (int)fifo->count << std::endl;

    // Test edge cases
    std::cout << "\n=== Edge Case Tests ===" << std::endl;

    // Test read from empty
    reset();
    std::cout << "\nRead from empty FIFO:" << std::endl;
    fifo->rd_en = 1;
    tick();
    std::cout << "Data: 0x" << std::hex << (int)fifo->rd_data
              << ", Empty: " << (fifo->empty ? "YES" : "NO") << std::endl;
    fifo->rd_en = 0;

    // Test fill to full
    std::cout << "\nFilling FIFO to capacity:" << std::endl;
    int items_written = 0;
    while (!fifo->full && items_written < 20) {
        fifo->wr_en = 1;
        fifo->rd_en = 0;
        fifo->wr_data = 0x20 + items_written;
        tick();
        items_written++;

        if (items_written % 4 == 0) {
            std::cout << "Written " << std::dec << items_written
                      << " items, Full: " << (fifo->full ? "YES" : "NO") << std::endl;
        }
    }
    fifo->wr_en = 0;

    std::cout << "FIFO is " << (fifo->full ? "FULL" : "NOT FULL")
              << " after writing " << std::dec << items_written << " items" << std::endl;

    std::cout << "\n=== Simulation Complete ===" << std::endl;
    std::cout << "Total simulation time: " << sim_time << " units" << std::endl;

    // Cleanup
    fifo->final();
    delete fifo;
    delete contextp;

    return 0;
}