// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_fifo.h for the primary calling header

#include "Vsimple_fifo__pch.h"

void Vsimple_fifo___024root___ctor_var_reset(Vsimple_fifo___024root* vlSelf);

Vsimple_fifo___024root::Vsimple_fifo___024root(Vsimple_fifo__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsimple_fifo___024root___ctor_var_reset(this);
}

void Vsimple_fifo___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsimple_fifo___024root::~Vsimple_fifo___024root() {
}
