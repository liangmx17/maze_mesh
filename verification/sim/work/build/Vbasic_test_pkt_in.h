// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbasic_test.h for the primary calling header

#ifndef VERILATED_VBASIC_TEST_PKT_IN_H_
#define VERILATED_VBASIC_TEST_PKT_IN_H_  // guard

#include "verilated.h"


class Vbasic_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbasic_test_pkt_in final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pkt_in_vld;
    CData/*0:0*/ pkt_in_qos;
    CData/*1:0*/ pkt_in_type;
    CData/*5:0*/ pkt_in_src;
    CData/*5:0*/ pkt_in_tgt;
    CData/*7:0*/ pkt_in_data;

    // INTERNAL VARIABLES
    Vbasic_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbasic_test_pkt_in(Vbasic_test__Syms* symsp, const char* v__name);
    ~Vbasic_test_pkt_in();
    VL_UNCOPYABLE(Vbasic_test_pkt_in);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vbasic_test_pkt_in* obj);

#endif  // guard
