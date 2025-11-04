// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_fifo.h for the primary calling header

#include "Vsimple_fifo__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_fifo___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vsimple_fifo___024root___eval_triggers__act(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_triggers__act\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsimple_fifo___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vsimple_fifo___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vsimple_fifo___024root___nba_sequent__TOP__0(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___nba_sequent__TOP__0\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vdly__simple_fifo__DOT__rd_ptr;
    __Vdly__simple_fifo__DOT__rd_ptr = 0;
    CData/*7:0*/ __VdlyVal__simple_fifo__DOT__mem__v0;
    __VdlyVal__simple_fifo__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__simple_fifo__DOT__mem__v0;
    __VdlyDim0__simple_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__simple_fifo__DOT__mem__v0;
    __VdlySet__simple_fifo__DOT__mem__v0 = 0;
    // Body
    __Vdly__simple_fifo__DOT__rd_ptr = vlSelfRef.simple_fifo__DOT__rd_ptr;
    __VdlySet__simple_fifo__DOT__mem__v0 = 0U;
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.rd_en) & (~ (IData)(vlSelfRef.empty)))) {
            __Vdly__simple_fifo__DOT__rd_ptr = (0x0000001fU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.simple_fifo__DOT__rd_ptr)));
            vlSelfRef.simple_fifo__DOT__rd_data_reg 
                = vlSelfRef.simple_fifo__DOT__mem[(0x0000000fU 
                                                   & (IData)(vlSelfRef.simple_fifo__DOT__rd_ptr))];
        }
        if (((IData)(vlSelfRef.wr_en) & (~ (IData)(vlSelfRef.full)))) {
            __VdlyVal__simple_fifo__DOT__mem__v0 = vlSelfRef.wr_data;
            __VdlyDim0__simple_fifo__DOT__mem__v0 = 
                (0x0000000fU & (IData)(vlSelfRef.simple_fifo__DOT__wr_ptr));
            __VdlySet__simple_fifo__DOT__mem__v0 = 1U;
            vlSelfRef.simple_fifo__DOT__wr_ptr = (0x0000001fU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.simple_fifo__DOT__wr_ptr)));
        }
    } else {
        __Vdly__simple_fifo__DOT__rd_ptr = 0U;
        vlSelfRef.simple_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.simple_fifo__DOT__rd_data_reg = 0U;
    }
    if (__VdlySet__simple_fifo__DOT__mem__v0) {
        vlSelfRef.simple_fifo__DOT__mem[__VdlyDim0__simple_fifo__DOT__mem__v0] 
            = __VdlyVal__simple_fifo__DOT__mem__v0;
    }
    vlSelfRef.simple_fifo__DOT__rd_ptr = __Vdly__simple_fifo__DOT__rd_ptr;
    vlSelfRef.rd_data = vlSelfRef.simple_fifo__DOT__rd_data_reg;
    vlSelfRef.full = (((1U & ((IData)(vlSelfRef.simple_fifo__DOT__wr_ptr) 
                              >> 4U)) != (1U & ((IData)(vlSelfRef.simple_fifo__DOT__rd_ptr) 
                                                >> 4U))) 
                      & ((0x0000000fU & (IData)(vlSelfRef.simple_fifo__DOT__wr_ptr)) 
                         == (0x0000000fU & (IData)(vlSelfRef.simple_fifo__DOT__rd_ptr))));
    vlSelfRef.empty = ((IData)(vlSelfRef.simple_fifo__DOT__rd_ptr) 
                       == (IData)(vlSelfRef.simple_fifo__DOT__wr_ptr));
    vlSelfRef.count = (0x0000001fU & ((IData)(vlSelfRef.simple_fifo__DOT__wr_ptr) 
                                      - (IData)(vlSelfRef.simple_fifo__DOT__rd_ptr)));
}

void Vsimple_fifo___024root___eval_nba(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_nba\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_fifo___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsimple_fifo___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsimple_fifo___024root___eval_phase__act(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_phase__act\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsimple_fifo___024root___eval_triggers__act(vlSelf);
    Vsimple_fifo___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vsimple_fifo___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsimple_fifo___024root___eval_phase__nba(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_phase__nba\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsimple_fifo___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vsimple_fifo___024root___eval_nba(vlSelf);
        Vsimple_fifo___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsimple_fifo___024root___eval(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsimple_fifo___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("simple_fifo.v", 2, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsimple_fifo___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("simple_fifo.v", 2, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vsimple_fifo___024root___eval_phase__act(vlSelf));
    } while (Vsimple_fifo___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vsimple_fifo___024root___eval_debug_assertions(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_debug_assertions\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.wr_en & 0xfeU)))) {
        Verilated::overWidthError("wr_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_en & 0xfeU)))) {
        Verilated::overWidthError("rd_en");
    }
}
#endif  // VL_DEBUG
