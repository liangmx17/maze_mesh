#include "Vminimal_node_test.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vminimal_node_test* top = new Vminimal_node_test;

    // Initialize signals
    top->clk = 0;
    top->rst_n = 1;

    // Run simulation
    const uint64_t max_cycles = 5000;
    uint64_t cycle = 0;

    while (cycle < max_cycles && !Verilated::gotFinish()) {
        // Toggle clock
        top->clk = !top->clk;
        top->eval();

        // Handle reset sequence
        if (cycle == 5) {
            top->rst_n = 0;  // Start reset
        } else if (cycle == 15) {
            top->rst_n = 1;  // End reset
        }

        cycle++;

        // Dump waveform if trace is enabled
        #ifdef VM_TRACE
            if (top->contextp()->traceEnabled()) {
                top->contextp()->traceDump(cycle);
            }
        #endif
    }

    top->final();
    delete top;
    return 0;
}