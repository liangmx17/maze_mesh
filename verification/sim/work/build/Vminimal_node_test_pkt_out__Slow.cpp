// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

void Vminimal_node_test_pkt_out___ctor_var_reset(Vminimal_node_test_pkt_out* vlSelf);

Vminimal_node_test_pkt_out::Vminimal_node_test_pkt_out(Vminimal_node_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vminimal_node_test_pkt_out___ctor_var_reset(this);
}

void Vminimal_node_test_pkt_out::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vminimal_node_test_pkt_out::~Vminimal_node_test_pkt_out() {
}
