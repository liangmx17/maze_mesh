// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbasic_test.h for the primary calling header

#include "Vbasic_test__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbasic_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vbasic_test___024root___eval_triggers__act(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_triggers__act\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.basic_test__DOT__rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.basic_test__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__clk__0 
        = vlSelfRef.basic_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__rst_n__0 
        = vlSelfRef.basic_test__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbasic_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vbasic_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___trigger_anySet__act\n"); );
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

extern const VlUnpacked<CData/*1:0*/, 32> Vbasic_test__ConstPool__TABLE_h28d0bcb6_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vbasic_test__ConstPool__TABLE_h3b34c9f4_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vbasic_test__ConstPool__TABLE_h24174b10_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vbasic_test__ConstPool__TABLE_h14c994e7_0;

void Vbasic_test___024root___nba_sequent__TOP__0(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___nba_sequent__TOP__0\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ basic_test__DOT__u_dut__DOT__new_tgt;
    basic_test__DOT__u_dut__DOT__new_tgt = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_qos_N;
    basic_test__DOT__u_dut__DOT__arb_qos_N = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_gnt_N;
    basic_test__DOT__u_dut__DOT__arb_gnt_N = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_qos_W;
    basic_test__DOT__u_dut__DOT__arb_qos_W = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_gnt_W;
    basic_test__DOT__u_dut__DOT__arb_gnt_W = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_qos_S;
    basic_test__DOT__u_dut__DOT__arb_qos_S = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_gnt_S;
    basic_test__DOT__u_dut__DOT__arb_gnt_S = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_qos_E;
    basic_test__DOT__u_dut__DOT__arb_qos_E = 0;
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__arb_gnt_E;
    basic_test__DOT__u_dut__DOT__arb_gnt_E = 0;
    CData/*4:0*/ basic_test__DOT__u_dut__DOT__arb_qos_B;
    basic_test__DOT__u_dut__DOT__arb_qos_B = 0;
    CData/*1:0*/ basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0;
    basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0 = 0;
    CData/*2:0*/ basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_1;
    basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_1 = 0;
    CData/*2:0*/ basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x;
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x = 0;
    CData/*1:0*/ basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type;
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type = 0;
    CData/*5:0*/ basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr;
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr = 0;
    IData/*31:0*/ basic_test__DOT__u_dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0;
    basic_test__DOT__u_dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ basic_test__DOT__u_dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0;
    basic_test__DOT__u_dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ basic_test__DOT__u_dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0;
    basic_test__DOT__u_dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ basic_test__DOT__u_dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0;
    basic_test__DOT__u_dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0;
    basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*4:0*/ __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = 0;
    CData/*4:0*/ __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req = 0;
    CData/*4:0*/ __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req = 0;
    CData/*4:0*/ __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req = 0;
    CData/*4:0*/ __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req = 0;
    // Body
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req;
    __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    if (vlSelfRef.basic_test__DOT__rst_n) {
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1eU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                         ? (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W))
                         : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req))))));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1bU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (4U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x17U & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (8U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1dU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (2U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x0fU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1eU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                         ? (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S))
                         : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req))))));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1bU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (4U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x17U & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (8U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1dU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (2U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x0fU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1eU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                         ? (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E))
                         : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req))))));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1bU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (4U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x17U & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (8U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1dU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (2U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x0fU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1eU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                         ? (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N))
                         : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req))))));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1bU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (4U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x17U & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (8U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1dU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (2U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x0fU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set)
                ? ((((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_data)))
                : vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o);
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set)
                ? ((((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_data)))
                : vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o);
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set)
                ? ((((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_data)))
                : vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o);
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set)
                ? ((((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_data)))
                : vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o);
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1eU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                         ? (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req))
                         : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req))))));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1bU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (4U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x17U & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (8U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1dU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (2U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x0fU & (IData)(__Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set)
                ? (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_tgt)
                : (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered));
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
            = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_data_rdy) 
                & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_vld))
                ? (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_qos) 
                    << 0x00000010U) | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_type) 
                                        << 0x0000000eU) 
                                       | (((IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_src) 
                                           << 8U) | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_data))))
                : vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o);
    } else {
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req = 0U;
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req = 0U;
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req = 0U;
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req = 0U;
        __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = 0U;
        vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered = 0U;
        vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o = 0U;
    }
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.basic_test__DOT__rst_n))) 
           || (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                               & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.basic_test__DOT__rst_n))) 
           || (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                               & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.basic_test__DOT__rst_n))) 
           || (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                               & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.basic_test__DOT__rst_n))) 
           || (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                               & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr))))));
    __Vtableidx1 = ((((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.basic_test__DOT__rst_n)));
    if ((1U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vbasic_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx1];
    }
    if ((2U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vbasic_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx1];
    }
    __Vtableidx2 = ((((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.basic_test__DOT__rst_n)));
    if ((1U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r 
            = Vbasic_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx2];
    }
    if ((2U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r 
            = Vbasic_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx2];
    }
    __Vtableidx3 = ((((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.basic_test__DOT__rst_n)));
    if ((1U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r 
            = Vbasic_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx3];
    }
    if ((2U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r 
            = Vbasic_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx3];
    }
    __Vtableidx4 = ((((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.basic_test__DOT__rst_n)));
    if ((1U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r 
            = Vbasic_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx4];
    }
    if ((2U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r 
            = Vbasic_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx4];
    }
    vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy 
        = ((IData)(vlSelfRef.basic_test__DOT__rst_n) 
           && (((IData)(vlSelfRef.basic_test__DOT__pg_en) 
                & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode))
                ? 0U : (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr)))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req 
        = __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req;
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req 
        = __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req;
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req 
        = __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req;
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req 
        = __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[0U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[1U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[2U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[3U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o;
    basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0 
        = ((2U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o 
                  >> 0x00000013U)) | (1U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                            >> 0x00000014U)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[4U] 
        = ((0x007fc000U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           << 6U)) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)));
    basic_test__DOT__u_dut__DOT__arb_qos_S = ((((2U 
                                                 & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                    >> 0x0000000dU)) 
                                                | (1U 
                                                   & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                      >> 0x00000014U))) 
                                               << 2U) 
                                              | ((2U 
                                                  & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o 
                                                     >> 0x00000013U)) 
                                                 | (1U 
                                                    & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                                       >> 0x00000014U))));
    basic_test__DOT__u_dut__DOT__arb_qos_E = ((((2U 
                                                 & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                    >> 0x0000000dU)) 
                                                | (1U 
                                                   & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                      >> 0x00000014U))) 
                                               << 2U) 
                                              | ((2U 
                                                  & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o 
                                                     >> 0x00000013U)) 
                                                 | (1U 
                                                    & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o 
                                                       >> 0x00000014U))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_data_rdy 
        = ((IData)(vlSelfRef.basic_test__DOT__rst_n) 
           && (((IData)(vlSelfRef.basic_test__DOT__pg_en) 
                & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode))
                ? 0U : (1U & (~ (0U != ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        & (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
                                           [4U] & (
                                                   (~ 
                                                    (- (IData)((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode)))) 
                                                   & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy)))))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_vld));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_vld));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_vld));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_vld));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.no_rdy));
    basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.no_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy));
    basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.so_rdy));
    basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.so_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.eo_rdy));
    basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.eo_rdy)));
    basic_test__DOT__u_dut__DOT__arb_qos_W = ((8U & 
                                               (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                >> 0x0000000bU)) 
                                              | ((4U 
                                                  & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                     >> 0x00000012U)) 
                                                 | (IData)(basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0)));
    basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_1 
        = ((4U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o 
                  >> 0x00000012U)) | (IData)(basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
        = __Vdly__basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r));
    basic_test__DOT__u_dut__DOT__arb_qos_N = ((8U & 
                                               (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                >> 0x0000000bU)) 
                                              | (IData)(basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_1));
    basic_test__DOT__u_dut__DOT__arb_qos_B = ((0x00000010U 
                                               & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                  >> 0x0000000aU)) 
                                              | ((8U 
                                                  & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                     >> 0x00000011U)) 
                                                 | (IData)(basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_1)));
    basic_test__DOT__u_dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    << 1U)) | (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                             << 1U)) | (1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req))));
    basic_test__DOT__u_dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
             | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                         | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                  >> 1U))));
    basic_test__DOT__u_dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                      >> 2U))));
    basic_test__DOT__u_dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                      >> 3U))));
    basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 
        = ((((4U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                              >> 4U))));
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_vld));
    basic_test__DOT__u_dut__DOT__arb_gnt_N = (0x0000000fU 
                                              & ((0U 
                                                  != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_N))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_N) 
                                                    - (IData)(1U))) 
                                                  & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_N))
                                                  : 
                                                 ((~ 
                                                   (basic_test__DOT__u_dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 
                                                    - (IData)(1U))) 
                                                  & basic_test__DOT__u_dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0)));
    basic_test__DOT__u_dut__DOT__arb_gnt_W = (0x0000000fU 
                                              & ((0U 
                                                  != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_W))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_W) 
                                                    - (IData)(1U))) 
                                                  & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_W))
                                                  : 
                                                 ((~ 
                                                   (basic_test__DOT__u_dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 
                                                    - (IData)(1U))) 
                                                  & basic_test__DOT__u_dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0)));
    basic_test__DOT__u_dut__DOT__arb_gnt_S = (0x0000000fU 
                                              & ((0U 
                                                  != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_S))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_S) 
                                                    - (IData)(1U))) 
                                                  & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_S))
                                                  : 
                                                 ((~ 
                                                   (basic_test__DOT__u_dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 
                                                    - (IData)(1U))) 
                                                  & basic_test__DOT__u_dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0)));
    basic_test__DOT__u_dut__DOT__arb_gnt_E = (0x0000000fU 
                                              & ((0U 
                                                  != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_E))
                                                  ? 
                                                 ((~ 
                                                   ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_E) 
                                                    - (IData)(1U))) 
                                                  & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_E))
                                                  : 
                                                 ((~ 
                                                   (basic_test__DOT__u_dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 
                                                    - (IData)(1U))) 
                                                  & basic_test__DOT__u_dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B 
        = (0x0000001fU & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_B))
                           ? ((~ ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_B) 
                                  - (IData)(1U))) & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_B))
                           : ((~ (basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 
                                  - (IData)(1U))) & basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0)));
    if (basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr) {
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x = 0U;
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_tgt;
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_type));
    } else {
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered)));
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered;
        basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                     >> 0x0000000eU));
    }
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_N))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_N)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.no_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r) 
            | (0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_W))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r) 
           & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_W)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r) 
            | (0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_S))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r) 
           & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_S)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.so_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r) 
            | (0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_E))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r) 
           & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_E)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.eo_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r)))));
    basic_test__DOT__u_dut__DOT__new_tgt = ((IData)(vlSelfRef.basic_test__DOT__pg_en)
                                             ? ((3U 
                                                 == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                 ? 
                                                ((((IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr)
                                                    ? 0U
                                                    : 
                                                   (7U 
                                                    & (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered) 
                                                        >> 3U) 
                                                       + 
                                                       (7U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered)))))) 
                                                  << 3U) 
                                                 | (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x))
                                                 : 
                                                ((1U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                  ? 
                                                 ((((IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr)
                                                     ? 0U
                                                     : 
                                                    (7U 
                                                     & ((IData)(1U) 
                                                        + 
                                                        ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered) 
                                                         >> 3U)))) 
                                                   << 3U) 
                                                  | (7U 
                                                     & (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw)))
                                                  : 
                                                 ((2U 
                                                   == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                   ? 
                                                  ((0x00000038U 
                                                    & (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw)) 
                                                   | (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__new_x))
                                                   : (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw))))
                                             : (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__tgt_raw));
    __Vtableidx6 = ((((3U == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                      << 9U) | ((2U == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                << 8U)) | (((IData)(basic_test__DOT__u_dut__DOT__new_tgt) 
                                            << 2U) 
                                           | (((1U 
                                                == (IData)(basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.basic_test__DOT__pg_en))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode 
        = Vbasic_test__ConstPool__TABLE_h14c994e7_0
        [__Vtableidx6];
    vlSelfRef.basic_test__DOT__u_dut__DOT__tgt_is_pg 
        = ((IData)(basic_test__DOT__u_dut__DOT__new_tgt) 
           == (IData)(vlSelfRef.basic_test__DOT__pg_node));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__tgt_is_pg))))));
}

void Vbasic_test___024root___nba_sequent__TOP__1(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___nba_sequent__TOP__1\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((((IData)(vlSelfRef.basic_test__DOT__rst_n) 
                      & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r))))) {
        VL_WRITEF_NX("[\350\276\223\345\207\272] \347\261\273\345\236\213=%0#, QoS=%0#, \346\272\220=0x%02x, \347\233\256\346\240\207=0x%02x, \346\225\260\346\215\256=0x%02x\n",0,
                     2,(3U & (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r 
                              >> 0x00000015U)),1,(1U 
                                                  & (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r 
                                                     >> 0x00000014U)),
                     6,(0x0000003fU & (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r 
                                       >> 0x0000000eU)),
                     6,(0x0000003fU & (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r 
                                       >> 8U)),8,(0x000000ffU 
                                                  & vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r));
    }
    if (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__0__KET__) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r 
            = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r)
                ? vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload1_r
                : vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_B);
    }
    if (vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__1__KET__) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload1_r 
            = vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_B;
    }
}

void Vbasic_test___024root___nba_sequent__TOP__2(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___nba_sequent__TOP__2\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_B = 
        ((0x00000010U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))
          ? vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf
         [4U] : ((8U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))
                  ? vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf
                 [0U] : ((4U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))
                          ? vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf
                         [1U] : ((2U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))
                                  ? vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf
                                 [2U] : ((1U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))
                                          ? vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf
                                         [3U] : 0U)))));
    __Vtableidx5 = ((((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.basic_test__DOT__rst_n)));
    if ((1U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r 
            = Vbasic_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx5];
    }
    if ((2U & Vbasic_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r 
            = Vbasic_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx5];
    }
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy));
    basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy 
        = ((((4U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r)) 
                    << 2U)) | ((2U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r)) 
                                      << 1U)) | (1U 
                                                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r))))) 
            << 2U) | ((2U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r)) 
                             << 1U)) | (1U & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [0U] & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [1U] & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [2U] & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [3U] & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__tgt_is_pg)))));
}

void Vbasic_test___024root___eval_nba(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_nba\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vbasic_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vbasic_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vbasic_test___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vbasic_test___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vbasic_test___024root___eval_phase__act(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_phase__act\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbasic_test___024root___eval_triggers__act(vlSelf);
    Vbasic_test___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vbasic_test___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vbasic_test___024root___eval_phase__nba(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_phase__nba\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vbasic_test___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vbasic_test___024root___eval_nba(vlSelf);
        Vbasic_test___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vbasic_test___024root___eval(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vbasic_test___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/basic_test.sv", 9, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vbasic_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/basic_test.sv", 9, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vbasic_test___024root___eval_phase__act(vlSelf));
    } while (Vbasic_test___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vbasic_test___024root___eval_debug_assertions(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_debug_assertions\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
