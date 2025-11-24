// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vminimal_node_test.h for the primary calling header

#ifndef VERILATED_VMINIMAL_NODE_TEST_PKT_CON_IF_H_
#define VERILATED_VMINIMAL_NODE_TEST_PKT_CON_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vminimal_node_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test_pkt_con_if final : public VerilatedModule {
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

    // INTERNAL VARIABLES
    Vminimal_node_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vminimal_node_test_pkt_con_if(Vminimal_node_test__Syms* symsp, const char* v__name);
    ~Vminimal_node_test_pkt_con_if();
    VL_UNCOPYABLE(Vminimal_node_test_pkt_con_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vminimal_node_test_pkt_con_if* obj);

#endif  // guard
