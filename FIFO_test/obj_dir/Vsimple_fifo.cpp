// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsimple_fifo__pch.h"

//============================================================
// Constructors

Vsimple_fifo::Vsimple_fifo(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsimple_fifo__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , wr_en{vlSymsp->TOP.wr_en}
    , wr_data{vlSymsp->TOP.wr_data}
    , full{vlSymsp->TOP.full}
    , rd_en{vlSymsp->TOP.rd_en}
    , rd_data{vlSymsp->TOP.rd_data}
    , empty{vlSymsp->TOP.empty}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsimple_fifo::Vsimple_fifo(const char* _vcname__)
    : Vsimple_fifo(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsimple_fifo::~Vsimple_fifo() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsimple_fifo___024root___eval_debug_assertions(Vsimple_fifo___024root* vlSelf);
#endif  // VL_DEBUG
void Vsimple_fifo___024root___eval_static(Vsimple_fifo___024root* vlSelf);
void Vsimple_fifo___024root___eval_initial(Vsimple_fifo___024root* vlSelf);
void Vsimple_fifo___024root___eval_settle(Vsimple_fifo___024root* vlSelf);
void Vsimple_fifo___024root___eval(Vsimple_fifo___024root* vlSelf);

void Vsimple_fifo::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsimple_fifo::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsimple_fifo___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsimple_fifo___024root___eval_static(&(vlSymsp->TOP));
        Vsimple_fifo___024root___eval_initial(&(vlSymsp->TOP));
        Vsimple_fifo___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsimple_fifo___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsimple_fifo::eventsPending() { return false; }

uint64_t Vsimple_fifo::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsimple_fifo::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsimple_fifo___024root___eval_final(Vsimple_fifo___024root* vlSelf);

VL_ATTR_COLD void Vsimple_fifo::final() {
    Vsimple_fifo___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsimple_fifo::hierName() const { return vlSymsp->name(); }
const char* Vsimple_fifo::modelName() const { return "Vsimple_fifo"; }
unsigned Vsimple_fifo::threads() const { return 1; }
void Vsimple_fifo::prepareClone() const { contextp()->prepareClone(); }
void Vsimple_fifo::atClone() const {
    contextp()->threadPoolpOnClone();
}
