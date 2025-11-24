// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vminimal_node_test.h for the primary calling header

#ifndef VERILATED_VMINIMAL_NODE_TEST___024UNIT_H_
#define VERILATED_VMINIMAL_NODE_TEST___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vminimal_node_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test___024unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    static VlUnpacked<std::string, 8> __Venumtab_enum_name3;

    // INTERNAL VARIABLES
    Vminimal_node_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vminimal_node_test___024unit(Vminimal_node_test__Syms* symsp, const char* v__name);
    ~Vminimal_node_test___024unit();
    VL_UNCOPYABLE(Vminimal_node_test___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
