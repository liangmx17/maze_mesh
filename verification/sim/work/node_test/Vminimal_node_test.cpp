// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vminimal_node_test__pch.h"

//============================================================
// Constructors

Vminimal_node_test::Vminimal_node_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vminimal_node_test__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , __PVT__minimal_node_test__DOT__pkt_i{vlSymsp->TOP.__PVT__minimal_node_test__DOT__pkt_i}
    , __PVT__minimal_node_test__DOT__pkt_o{vlSymsp->TOP.__PVT__minimal_node_test__DOT__pkt_o}
    , __PVT__minimal_node_test__DOT__pkt_con{vlSymsp->TOP.__PVT__minimal_node_test__DOT__pkt_con}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vminimal_node_test::Vminimal_node_test(const char* _vcname__)
    : Vminimal_node_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vminimal_node_test::~Vminimal_node_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vminimal_node_test___024root___eval_debug_assertions(Vminimal_node_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vminimal_node_test___024root___eval_static(Vminimal_node_test___024root* vlSelf);
void Vminimal_node_test___024root___eval_initial(Vminimal_node_test___024root* vlSelf);
void Vminimal_node_test___024root___eval_settle(Vminimal_node_test___024root* vlSelf);
void Vminimal_node_test___024root___eval(Vminimal_node_test___024root* vlSelf);

void Vminimal_node_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vminimal_node_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vminimal_node_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vminimal_node_test___024root___eval_static(&(vlSymsp->TOP));
        Vminimal_node_test___024root___eval_initial(&(vlSymsp->TOP));
        Vminimal_node_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vminimal_node_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vminimal_node_test::eventsPending() { return false; }

uint64_t Vminimal_node_test::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vminimal_node_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vminimal_node_test___024root___eval_final(Vminimal_node_test___024root* vlSelf);

VL_ATTR_COLD void Vminimal_node_test::final() {
    Vminimal_node_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vminimal_node_test::hierName() const { return vlSymsp->name(); }
const char* Vminimal_node_test::modelName() const { return "Vminimal_node_test"; }
unsigned Vminimal_node_test::threads() const { return 1; }
void Vminimal_node_test::prepareClone() const { contextp()->prepareClone(); }
void Vminimal_node_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
