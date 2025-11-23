// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vminimal_node_test.h for the primary calling header

#ifndef VERILATED_VMINIMAL_NODE_TEST_PKT_IN_H_
#define VERILATED_VMINIMAL_NODE_TEST_PKT_IN_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vminimal_node_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test_pkt_in final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pkt_in_vld;
    CData/*0:0*/ pkt_in_qos;
    CData/*1:0*/ pkt_in_type;
    CData/*5:0*/ pkt_in_src;
    CData/*5:0*/ pkt_in_tgt;
    CData/*7:0*/ pkt_in_data;

    // INTERNAL VARIABLES
    Vminimal_node_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vminimal_node_test_pkt_in(Vminimal_node_test__Syms* symsp, const char* v__name);
    ~Vminimal_node_test_pkt_in();
    VL_UNCOPYABLE(Vminimal_node_test_pkt_in);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vminimal_node_test_pkt_in* obj);

#endif  // guard
