// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbasic_test__pch.h"

//============================================================
// Constructors

Vbasic_test::Vbasic_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbasic_test__Syms(contextp(), _vcname__, this)}
    , __PVT__basic_test__DOT__pkt_i{vlSymsp->TOP.__PVT__basic_test__DOT__pkt_i}
    , __PVT__basic_test__DOT__pkt_o{vlSymsp->TOP.__PVT__basic_test__DOT__pkt_o}
    , __PVT__basic_test__DOT__pkt_con{vlSymsp->TOP.__PVT__basic_test__DOT__pkt_con}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbasic_test::Vbasic_test(const char* _vcname__)
    : Vbasic_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbasic_test::~Vbasic_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbasic_test___024root___eval_debug_assertions(Vbasic_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vbasic_test___024root___eval_static(Vbasic_test___024root* vlSelf);
void Vbasic_test___024root___eval_initial(Vbasic_test___024root* vlSelf);
void Vbasic_test___024root___eval_settle(Vbasic_test___024root* vlSelf);
void Vbasic_test___024root___eval(Vbasic_test___024root* vlSelf);

void Vbasic_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbasic_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbasic_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbasic_test___024root___eval_static(&(vlSymsp->TOP));
        Vbasic_test___024root___eval_initial(&(vlSymsp->TOP));
        Vbasic_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbasic_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbasic_test::eventsPending() { return false; }

uint64_t Vbasic_test::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbasic_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbasic_test___024root___eval_final(Vbasic_test___024root* vlSelf);

VL_ATTR_COLD void Vbasic_test::final() {
    Vbasic_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbasic_test::hierName() const { return vlSymsp->name(); }
const char* Vbasic_test::modelName() const { return "Vbasic_test"; }
unsigned Vbasic_test::threads() const { return 1; }
void Vbasic_test::prepareClone() const { contextp()->prepareClone(); }
void Vbasic_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
