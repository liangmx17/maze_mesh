// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vminimal_node_test__pch.h"
#include "Vminimal_node_test.h"
#include "Vminimal_node_test___024root.h"
#include "Vminimal_node_test_pkt_in.h"
#include "Vminimal_node_test_pkt_out.h"
#include "Vminimal_node_test_pkt_con_if.h"

// FUNCTIONS
Vminimal_node_test__Syms::~Vminimal_node_test__Syms()
{
}

Vminimal_node_test__Syms::Vminimal_node_test__Syms(VerilatedContext* contextp, const char* namep, Vminimal_node_test* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__minimal_node_test__DOT__pkt_con{this, Verilated::catName(namep, "minimal_node_test.pkt_con")}
    , TOP__minimal_node_test__DOT__pkt_i{this, Verilated::catName(namep, "minimal_node_test.pkt_i")}
    , TOP__minimal_node_test__DOT__pkt_o{this, Verilated::catName(namep, "minimal_node_test.pkt_o")}
{
    // Check resources
    Verilated::stackCheck(292);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__minimal_node_test__DOT__pkt_con = &TOP__minimal_node_test__DOT__pkt_con;
    TOP.__PVT__minimal_node_test__DOT__pkt_i = &TOP__minimal_node_test__DOT__pkt_i;
    TOP.__PVT__minimal_node_test__DOT__pkt_o = &TOP__minimal_node_test__DOT__pkt_o;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__minimal_node_test__DOT__pkt_con.__Vconfigure(true);
    TOP__minimal_node_test__DOT__pkt_i.__Vconfigure(true);
    TOP__minimal_node_test__DOT__pkt_o.__Vconfigure(true);
}
