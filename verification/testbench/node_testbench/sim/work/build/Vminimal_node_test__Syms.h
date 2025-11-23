// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMINIMAL_NODE_TEST__SYMS_H_
#define VERILATED_VMINIMAL_NODE_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vminimal_node_test.h"

// INCLUDE MODULE CLASSES
#include "Vminimal_node_test___024root.h"
#include "Vminimal_node_test_pkt_in.h"
#include "Vminimal_node_test_pkt_out.h"
#include "Vminimal_node_test_pkt_con_if.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vminimal_node_test* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vminimal_node_test___024root   TOP;
    Vminimal_node_test_pkt_con_if  TOP__minimal_node_test__DOT__pkt_con;
    Vminimal_node_test_pkt_in      TOP__minimal_node_test__DOT__pkt_i;
    Vminimal_node_test_pkt_out     TOP__minimal_node_test__DOT__pkt_o;

    // CONSTRUCTORS
    Vminimal_node_test__Syms(VerilatedContext* contextp, const char* namep, Vminimal_node_test* modelp);
    ~Vminimal_node_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
