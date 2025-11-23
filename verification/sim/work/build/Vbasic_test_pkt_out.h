// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbasic_test.h for the primary calling header

#ifndef VERILATED_VBASIC_TEST_PKT_OUT_H_
#define VERILATED_VBASIC_TEST_PKT_OUT_H_  // guard

#include "verilated.h"


class Vbasic_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbasic_test_pkt_out final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pkt_out_rdy;

    // INTERNAL VARIABLES
    Vbasic_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbasic_test_pkt_out(Vbasic_test__Syms* symsp, const char* v__name);
    ~Vbasic_test_pkt_out();
    VL_UNCOPYABLE(Vbasic_test_pkt_out);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vbasic_test_pkt_out* obj);

#endif  // guard
