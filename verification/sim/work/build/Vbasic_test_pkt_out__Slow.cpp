// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbasic_test.h for the primary calling header

#include "Vbasic_test__pch.h"

void Vbasic_test_pkt_out___ctor_var_reset(Vbasic_test_pkt_out* vlSelf);

Vbasic_test_pkt_out::Vbasic_test_pkt_out(Vbasic_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbasic_test_pkt_out___ctor_var_reset(this);
}

void Vbasic_test_pkt_out::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vbasic_test_pkt_out::~Vbasic_test_pkt_out() {
}
