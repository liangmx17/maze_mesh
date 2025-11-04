// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_fifo.h for the primary calling header

#include "Vsimple_fifo__pch.h"

VL_ATTR_COLD void Vsimple_fifo___024root___eval_static(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_static\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vsimple_fifo___024root___eval_initial(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_initial\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsimple_fifo___024root___eval_final(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_final\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_fifo___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsimple_fifo___024root___eval_phase__stl(Vsimple_fifo___024root* vlSelf);

VL_ATTR_COLD void Vsimple_fifo___024root___eval_settle(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_settle\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsimple_fifo___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("simple_fifo.v", 2, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vsimple_fifo___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vsimple_fifo___024root___eval_triggers__stl(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_triggers__stl\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsimple_fifo___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vsimple_fifo___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_fifo___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsimple_fifo___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsimple_fifo___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vsimple_fifo___024root___stl_sequent__TOP__0(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___stl_sequent__TOP__0\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vsimple_fifo___024root___eval_stl(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_stl\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vsimple_fifo___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vsimple_fifo___024root___eval_phase__stl(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___eval_phase__stl\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsimple_fifo___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vsimple_fifo___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vsimple_fifo___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vsimple_fifo___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_fifo___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsimple_fifo___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsimple_fifo___024root___ctor_var_reset(Vsimple_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_fifo___024root___ctor_var_reset\n"); );
    Vsimple_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710928637576349896ull);
    vlSelf->wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12812822527505751231ull);
    vlSelf->full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6695099141381822181ull);
    vlSelf->rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3814484142505630662ull);
    vlSelf->rd_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17824471296722538975ull);
    vlSelf->empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3016723684638320966ull);
    vlSelf->count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10730142128712957955ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->simple_fifo__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5264026313143309304ull);
    }
    vlSelf->simple_fifo__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3392115844919339287ull);
    vlSelf->simple_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8662369732948829196ull);
    vlSelf->simple_fifo__DOT__rd_data_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3126837137548163131ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
