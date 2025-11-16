// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdebug_simple_test.h for the primary calling header

#ifndef VERILATED_VDEBUG_SIMPLE_TEST_PKT_OUT_H_
#define VERILATED_VDEBUG_SIMPLE_TEST_PKT_OUT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdebug_simple_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdebug_simple_test_pkt_out final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pkt_out_vld;
    CData/*0:0*/ pkt_out_qos;
    CData/*1:0*/ pkt_out_type;
    CData/*5:0*/ pkt_out_src;
    CData/*5:0*/ pkt_out_tgt;
    CData/*7:0*/ pkt_out_data;
    CData/*0:0*/ pkt_out_rdy;

    // INTERNAL VARIABLES
    Vdebug_simple_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdebug_simple_test_pkt_out(Vdebug_simple_test__Syms* symsp, const char* v__name);
    ~Vdebug_simple_test_pkt_out();
    VL_UNCOPYABLE(Vdebug_simple_test_pkt_out);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vdebug_simple_test_pkt_out* obj);

#endif  // guard
