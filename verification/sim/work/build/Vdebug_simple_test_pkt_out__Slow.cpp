// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

void Vdebug_simple_test_pkt_out___ctor_var_reset(Vdebug_simple_test_pkt_out* vlSelf);

Vdebug_simple_test_pkt_out::Vdebug_simple_test_pkt_out(Vdebug_simple_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdebug_simple_test_pkt_out___ctor_var_reset(this);
}

void Vdebug_simple_test_pkt_out::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdebug_simple_test_pkt_out::~Vdebug_simple_test_pkt_out() {
}
