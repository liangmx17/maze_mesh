// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbasic_test.h for the primary calling header

#ifndef VERILATED_VBASIC_TEST_PKT_CON_IF_H_
#define VERILATED_VBASIC_TEST_PKT_CON_IF_H_  // guard

#include "verilated.h"


class Vbasic_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbasic_test_pkt_con_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ni_vld;
    CData/*0:0*/ ni_qos;
    CData/*1:0*/ ni_type;
    CData/*5:0*/ ni_src;
    CData/*5:0*/ ni_tgt;
    CData/*7:0*/ ni_data;
    CData/*0:0*/ wi_vld;
    CData/*0:0*/ wi_qos;
    CData/*1:0*/ wi_type;
    CData/*5:0*/ wi_src;
    CData/*5:0*/ wi_tgt;
    CData/*7:0*/ wi_data;
    CData/*0:0*/ si_vld;
    CData/*0:0*/ si_qos;
    CData/*1:0*/ si_type;
    CData/*5:0*/ si_src;
    CData/*5:0*/ si_tgt;
    CData/*7:0*/ si_data;
    CData/*0:0*/ ei_vld;
    CData/*0:0*/ ei_qos;
    CData/*1:0*/ ei_type;
    CData/*5:0*/ ei_src;
    CData/*5:0*/ ei_tgt;
    CData/*7:0*/ ei_data;
    CData/*0:0*/ no_rdy;
    CData/*0:0*/ wo_rdy;
    CData/*0:0*/ so_rdy;
    CData/*0:0*/ eo_rdy;

    // INTERNAL VARIABLES
    Vbasic_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbasic_test_pkt_con_if(Vbasic_test__Syms* symsp, const char* v__name);
    ~Vbasic_test_pkt_con_if();
    VL_UNCOPYABLE(Vbasic_test_pkt_con_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vbasic_test_pkt_con_if* obj);

#endif  // guard
