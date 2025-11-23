// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VL_ATTR_COLD void Vminimal_node_test___024root___eval_static__TOP(Vminimal_node_test___024root* vlSelf);
VL_ATTR_COLD void Vminimal_node_test___024root____Vm_traceActivitySetAll(Vminimal_node_test___024root* vlSelf);

VL_ATTR_COLD void Vminimal_node_test___024root___eval_static(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_static\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vminimal_node_test___024root___eval_static__TOP(vlSelf);
    Vminimal_node_test___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
    vlSelfRef.__Vtrigprevexpr_h77c9d807__1 = (1U & 
                                              (~ (IData)(vlSelfRef.rst_n)));
}

VL_ATTR_COLD void Vminimal_node_test___024root___eval_static__TOP(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_static__TOP\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.minimal_node_test__DOT__pg_en = 0U;
    vlSelfRef.minimal_node_test__DOT__pg_node = 0U;
    vlSelfRef.minimal_node_test__DOT__test_count = 0U;
    vlSelfRef.minimal_node_test__DOT__passed_count = 0U;
    vlSelfRef.minimal_node_test__DOT__clk_counter = 0U;
}

VL_ATTR_COLD void Vminimal_node_test___024root___eval_final(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_final\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vminimal_node_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vminimal_node_test___024root___eval_phase__stl(Vminimal_node_test___024root* vlSelf);

VL_ATTR_COLD void Vminimal_node_test___024root___eval_settle(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_settle\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vminimal_node_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("minimal_node_test.sv", 16, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vminimal_node_test___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vminimal_node_test___024root___eval_triggers__stl(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_triggers__stl\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vminimal_node_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vminimal_node_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vminimal_node_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vminimal_node_test___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vminimal_node_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*0:0*/, 1024> Vminimal_node_test__ConstPool__TABLE_h14c994e7_0;

VL_ATTR_COLD void Vminimal_node_test___024root___stl_sequent__TOP__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___stl_sequent__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[0U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[1U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[2U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[3U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[4U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy)));
    minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy)));
    minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy)));
    minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy)));
    minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[0U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[1U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[2U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[3U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4U] 
        = ((0x007fc000U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           << 6U)) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy 
        = ((((4U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)) 
                    << 2U)) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)) 
                                      << 1U)) | (1U 
                                                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r))))) 
            << 2U) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)) 
                             << 1U)) | (1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S 
        = ((((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                    >> 0x0000000dU)) | (1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                              >> 0x00000014U))) 
            << 2U) | ((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                             >> 0x00000013U)) | (1U 
                                                 & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                                    >> 0x00000014U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E 
        = ((((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                    >> 0x0000000dU)) | (1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                              >> 0x00000014U))) 
            << 2U) | ((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                             >> 0x00000013U)) | (1U 
                                                 & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
                                                    >> 0x00000014U))));
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0 
        = ((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
                  >> 0x00000013U)) | (1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                            >> 0x00000014U)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [0U] & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [1U] & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [2U] & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [3U] & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S))
                           ? ((~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S))
                           : ((~ (((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                            >> 1U)) 
                                     | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                              >> 2U))) 
                                    << 2U) | ((2U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                >> 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                    >> 2U)))) 
                                  - (IData)(1U))) & 
                              ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 1U)) | (1U 
                                                   & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                      >> 2U))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                 >> 1U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 2U)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E))
                           ? ((~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E))
                           : ((~ (((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                            >> 2U)) 
                                     | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                              >> 3U))) 
                                    << 2U) | ((2U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                >> 2U)) 
                                              | (1U 
                                                 & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                    >> 3U)))) 
                                  - (IData)(1U))) & 
                              ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 2U)) | (1U 
                                                   & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                      >> 3U))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                 >> 2U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                   >> 3U)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                  >> 0x0000000bU)) | ((4U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                             >> 0x00000012U)) 
                                      | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0)));
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1 
        = ((4U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                  >> 0x00000012U)) | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0));
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = 0U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type));
    } else {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                     >> 0x0000000eU));
    }
    if (vlSelfRef.minimal_node_test__DOT__pg_en) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos 
            = ((IData)((0U == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                ? 0U : ((0U == (7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                      >> 3U))) ? ((0U 
                                                   < 
                                                   (7U 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                                   ? 7U
                                                   : 3U)
                         : ((0U < (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                             ? 6U : ((0U == (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                      ? 5U : 4U))));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt 
            = ((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                ? ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                      ? 0U : (7U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                     >> 3U) + (7U == 
                                               (7U 
                                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)))))) 
                    << 3U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
                : ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                    ? ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                          ? 0U : (7U & ((IData)(1U) 
                                        + ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                           >> 3U)))) 
                        << 3U) | (7U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)))
                    : ((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                        ? ((0x00000038U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)) 
                           | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
                        : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw))));
    } else {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos = 0U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
    }
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S 
        = ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [3U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E 
        = ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [2U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W))
                           ? ((~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W))
                           : ((~ (((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
                                     | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                              >> 1U))) 
                                    << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                              | (1U 
                                                 & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                    >> 1U)))) 
                                  - (IData)(1U))) & 
                              ((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
                                 | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                          >> 1U))) 
                                << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 1U)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                  >> 0x0000000bU)) | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           >> 0x0000000aU)) | ((8U 
                                                & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                   >> 0x00000011U)) 
                                               | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W 
        = ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [2U] : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [3U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N))
                           ? ((~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N))
                           : ((~ (((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                            << 1U)) 
                                     | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
                                    << 2U) | ((2U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                << 1U)) 
                                              | (1U 
                                                 & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)))) 
                                  - (IData)(1U))) & 
                              ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        << 1U)) | (1U 
                                                   & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                 << 1U)) 
                                          | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B 
        = (0x0000001fU & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B))
                           ? ((~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B))
                           : ((~ (((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                            >> 2U)) 
                                     | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                               >> 3U)) 
                                        | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                 >> 4U)))) 
                                    << 2U) | ((2U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                >> 3U)) 
                                              | (1U 
                                                 & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                    >> 4U)))) 
                                  - (IData)(1U))) & 
                              ((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 2U)) | (
                                                   (2U 
                                                    & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                       >> 3U)) 
                                                   | (1U 
                                                      & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                         >> 4U)))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                 >> 3U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 4U)))))));
    __Vtableidx6 = ((((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                      << 9U) | ((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                << 8U)) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt) 
                                            << 2U) 
                                           | (((1U 
                                                == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.minimal_node_test__DOT__pg_en))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode 
        = Vminimal_node_test__ConstPool__TABLE_h14c994e7_0
        [__Vtableidx6];
    vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt) 
           == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B 
        = ((0x00000010U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [2U] : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                           [3U] : 0U)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg)))));
}

VL_ATTR_COLD void Vminimal_node_test___024root___eval_stl(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_stl\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vminimal_node_test___024root___stl_sequent__TOP__0(vlSelf);
        Vminimal_node_test___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vminimal_node_test___024root___eval_phase__stl(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_phase__stl\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vminimal_node_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vminimal_node_test___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vminimal_node_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vminimal_node_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vminimal_node_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vminimal_node_test___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( (~ rst_n))\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vminimal_node_test___024root____Vm_traceActivitySetAll(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root____Vm_traceActivitySetAll\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
}

VL_ATTR_COLD void Vminimal_node_test___024root___ctor_var_reset(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___ctor_var_reset\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->minimal_node_test__DOT__pg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12261267854489903344ull);
    vlSelf->minimal_node_test__DOT__pg_node = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10526420684268110102ull);
    vlSelf->minimal_node_test__DOT__test_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16196149117036083703ull);
    vlSelf->minimal_node_test__DOT__passed_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7947716762559415981ull);
    vlSelf->minimal_node_test__DOT__clk_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9893156102420607876ull);
    vlSelf->minimal_node_test__DOT__timeout_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2882488170832787559ull);
    vlSelf->minimal_node_test__DOT__test_packet_data = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11249835836795017488ull);
    vlSelf->minimal_node_test__DOT__test_packet_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 444743110755025541ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__fault_relative_pos = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6068676877294349854ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__new_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14286647891524989564ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__tgt_is_pg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8749483144355087328ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__cpy_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10025647174722251968ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__route_req_N = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 125836083269101815ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__route_req_S = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11423826959722884693ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__route_req_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17690131630391634897ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__route_req_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7006181668421872801ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__route_req_A = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2902045584602226743ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->minimal_node_test__DOT__dut__DOT__arb_req[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15763682336665675479ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10944427193841556932ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->minimal_node_test__DOT__dut__DOT__pld_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11152941617626980966ull);
    }
    vlSelf->minimal_node_test__DOT__dut__DOT__obuf_rdy = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17671289442785268906ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13798201083248606068ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9980125269901605842ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15010625058806605938ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16459666668917485637ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 444870465022388424ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16733423494895611510ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16027301628163186621ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6296820050105956875ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8746379103893290490ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 18202328309610725832ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2462847072016145952ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16956703922501308424ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13956179715327433227ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17478045294920998653ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17090592711943799581ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12832028734478858919ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15885489110476320521ull);
    vlSelf->minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4059092343581173294ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_qos_N = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2080185429201841419ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt_N = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16528235062726501578ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_qos_W = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11226962026828640485ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt_W = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4267450407492086046ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_qos_S = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5742071662499789342ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt_S = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9625154379827913138ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_qos_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16793249375292445454ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17547722794931297796ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_qos_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17792974334732760885ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__arb_gnt_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12509899762853824986ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_W = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16523025001191600350ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_S = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 18132398783800072944ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_E = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2140117809775567323ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__pkt_B = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4229732303864680206ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__n_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5620650204509400317ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__w_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12288144931079113618ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__s_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8606277258268791194ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__e_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17758009866873860355ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__b_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 786698814930376255ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__gen_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13937869767945730246ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17366809724718091863ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1749350208941722937ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15660891690910853354ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1182148762637841020ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16575687209099660833ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6729948737314737081ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4060411377817915122ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3150565254118357387ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16796073750242445647ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15299515318084544023ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15862055895184672665ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16568510510808911737ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16793868525834061094ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12757443660436347573ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1122701966096808281ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11199496909195402424ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4477820639100649638ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7873780796082582549ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17642743361600986638ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13286823699191819647ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16429001028622518335ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 7365039238060230693ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 945871288314994520ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9258467641343686359ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5145894581624200488ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17858043992006722975ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17328665146688027784ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11547196519447336203ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7767029949977963012ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8548743498822140436ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9802190027348453792ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13071104472594938477ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14040475483219994820ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1995877690333217765ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8764654042306926478ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13773705914811917426ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5970274290138195943ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9838705698273157985ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4659437264072769280ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9275983505054144110ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2274684494233263816ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12011439969619864486ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16548649548779575096ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 470869221501634829ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5844632388868207568ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 7416697736644362218ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4207113800411733975ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15134756310664049203ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17683393714253850351ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15350015145877551166ull);
    vlSelf->minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17251978976637156708ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
    vlSelf->__Vtrigprevexpr_h77c9d807__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17807410857450674907ull);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
