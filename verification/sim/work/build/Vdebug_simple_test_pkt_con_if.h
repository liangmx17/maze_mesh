// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdebug_simple_test.h for the primary calling header

#ifndef VERILATED_VDEBUG_SIMPLE_TEST_PKT_CON_IF_H_
#define VERILATED_VDEBUG_SIMPLE_TEST_PKT_CON_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdebug_simple_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdebug_simple_test_pkt_con_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ni_vld;
    CData/*0:0*/ ni_rdy;
    CData/*0:0*/ ni_qos;
    CData/*1:0*/ ni_type;
    CData/*5:0*/ ni_src;
    CData/*5:0*/ ni_tgt;
    CData/*7:0*/ ni_data;
    CData/*0:0*/ wi_vld;
    CData/*0:0*/ wi_rdy;
    CData/*0:0*/ wi_qos;
    CData/*1:0*/ wi_type;
    CData/*5:0*/ wi_src;
    CData/*5:0*/ wi_tgt;
    CData/*7:0*/ wi_data;
    CData/*0:0*/ si_vld;
    CData/*0:0*/ si_rdy;
    CData/*0:0*/ si_qos;
    CData/*1:0*/ si_type;
    CData/*5:0*/ si_src;
    CData/*5:0*/ si_tgt;
    CData/*7:0*/ si_data;
    CData/*0:0*/ ei_vld;
    CData/*0:0*/ ei_rdy;
    CData/*0:0*/ ei_qos;
    CData/*1:0*/ ei_type;
    CData/*5:0*/ ei_src;
    CData/*5:0*/ ei_tgt;
    CData/*7:0*/ ei_data;
    CData/*0:0*/ no_vld;
    CData/*0:0*/ no_rdy;
    CData/*0:0*/ no_qos;
    CData/*1:0*/ no_type;
    CData/*5:0*/ no_src;
    CData/*5:0*/ no_tgt;
    CData/*7:0*/ no_data;
    CData/*0:0*/ wo_vld;
    CData/*0:0*/ wo_rdy;
    CData/*0:0*/ wo_qos;
    CData/*1:0*/ wo_type;
    CData/*5:0*/ wo_src;
    CData/*5:0*/ wo_tgt;
    CData/*7:0*/ wo_data;
    CData/*0:0*/ so_vld;
    CData/*0:0*/ so_rdy;
    CData/*0:0*/ so_qos;
    CData/*1:0*/ so_type;
    CData/*5:0*/ so_src;
    CData/*5:0*/ so_tgt;
    CData/*7:0*/ so_data;
    CData/*0:0*/ eo_vld;
    CData/*0:0*/ eo_rdy;
    CData/*0:0*/ eo_qos;
    CData/*1:0*/ eo_type;
    CData/*5:0*/ eo_src;
    CData/*5:0*/ eo_tgt;
    CData/*7:0*/ eo_data;

    // INTERNAL VARIABLES
    Vdebug_simple_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdebug_simple_test_pkt_con_if(Vdebug_simple_test__Syms* symsp, const char* v__name);
    ~Vdebug_simple_test_pkt_con_if();
    VL_UNCOPYABLE(Vdebug_simple_test_pkt_con_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vdebug_simple_test_pkt_con_if* obj);

#endif  // guard
