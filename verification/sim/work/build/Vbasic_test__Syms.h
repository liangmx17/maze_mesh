// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBASIC_TEST__SYMS_H_
#define VERILATED_VBASIC_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbasic_test.h"

// INCLUDE MODULE CLASSES
#include "Vbasic_test___024root.h"
#include "Vbasic_test_pkt_in.h"
#include "Vbasic_test_pkt_out.h"
#include "Vbasic_test_pkt_con_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vbasic_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbasic_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbasic_test___024root          TOP;
    Vbasic_test_pkt_con_if         TOP__basic_test__DOT__pkt_con;
    Vbasic_test_pkt_in             TOP__basic_test__DOT__pkt_i;
    Vbasic_test_pkt_out            TOP__basic_test__DOT__pkt_o;

    // CONSTRUCTORS
    Vbasic_test__Syms(VerilatedContext* contextp, const char* namep, Vbasic_test* modelp);
    ~Vbasic_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
