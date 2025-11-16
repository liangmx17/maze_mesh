// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_test.h for the primary calling header

#include "Vsimple_test__pch.h"

VL_ATTR_COLD void Vsimple_test___024root___eval_static__TOP(Vsimple_test___024root* vlSelf);
VL_ATTR_COLD void Vsimple_test___024root____Vm_traceActivitySetAll(Vsimple_test___024root* vlSelf);

VL_ATTR_COLD void Vsimple_test___024root___eval_static(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_static\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsimple_test___024root___eval_static__TOP(vlSelf);
    Vsimple_test___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 
        = vlSelfRef.simple_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 
        = vlSelfRef.simple_test__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr_h0cf981d0__1 = ((IData)(5U) 
                                              * (IData)(vlSelfRef.simple_test__DOT__clk));
}

VL_ATTR_COLD void Vsimple_test___024root___eval_static__TOP(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_static__TOP\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.simple_test__DOT__debug_cycle_counter = 0U;
    vlSelfRef.simple_test__DOT__first_10_cycles_debug = 1U;
}

VL_ATTR_COLD void Vsimple_test___024root___eval_final(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_final\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsimple_test___024root___eval_phase__stl(Vsimple_test___024root* vlSelf);

VL_ATTR_COLD void Vsimple_test___024root___eval_settle(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_settle\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsimple_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vsimple_test___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vsimple_test___024root___eval_triggers__stl(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_triggers__stl\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsimple_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vsimple_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsimple_test___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsimple_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vsimple_test___024root___stl_sequent__TOP__0(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___stl_sequent__TOP__0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2 = 0;
    CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0 = 0;
    // Body
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld) 
           | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i 
        = ((((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type) 
             << 0x00000015U) | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt) 
               << 8U) | (IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S 
        = ((((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                    >> 0x00000013U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                              >> 0x00000014U))) 
            << 2U) | ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                             >> 0x00000013U)) | (1U 
                                                 & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                                                    >> 0x00000014U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E 
        = ((((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                    >> 0x00000013U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                              >> 0x00000014U))) 
            << 2U) | ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                             >> 0x00000013U)) | (1U 
                                                 & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                                                    >> 0x00000014U))));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2 
        = ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                  >> 0x00000013U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                                            >> 0x00000014U)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.simple_test__DOT__pg_en)
            ? ((IData)((0x1bU == (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                ? 0U : ((3U > (7U & ((IData)(vlSelfRef.simple_test__DOT__pg_node) 
                                     >> 3U))) ? ((3U 
                                                  < 
                                                  (7U 
                                                   & (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                                                  ? 8U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                                                   ? 1U
                                                   : 2U))
                         : ((3U == (7U & ((IData)(vlSelfRef.simple_test__DOT__pg_node) 
                                          >> 3U))) ? 
                            ((3U < (7U & (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                              ? 7U : 3U) : ((3U < (7U 
                                                   & (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                                             ? 6U : 
                                            ((3U == 
                                              (7U & (IData)(vlSelfRef.simple_test__DOT__pg_node)))
                                              ? 5U : 4U)))))
            : 0U);
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                  >> 0x00000011U)) | ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                             >> 0x00000012U)) 
                                      | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2)));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3 
        = ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                  >> 0x00000012U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                     >> 8U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                     >> 0x0000000bU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                     >> 0x00000015U));
        if ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            } else if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            }
        } else if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                    = (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
            }
        } else if (((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y)))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = ((((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)))
                    : (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = ((((7U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)))
                    : (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = ((((1U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))
                    : (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = ((((5U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))
                    : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W)));
        }
        if ((0U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W));
        }
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                     >> 8U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                     >> 0x0000000bU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                     >> 0x00000015U));
        if ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            } else if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            }
        } else if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                    = (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
            }
        } else if (((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y)))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = ((((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)))
                    : (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = ((((7U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)))
                    : (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = ((((1U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S))
                    : (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = ((((5U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S))
                    : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)));
        }
        if ((0U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S));
        }
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                     >> 8U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                     >> 0x0000000bU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                     >> 0x00000015U));
        if ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            } else if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            }
        } else if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                    = (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
            }
        } else if (((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y)))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = ((((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)))
                    : (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = ((((7U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)))
                    : (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = ((((1U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))
                    : (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = ((((5U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))
                    : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)));
        }
        if ((0U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E));
        }
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                     >> 8U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                     >> 0x0000000bU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                     >> 0x00000015U));
        if ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            } else if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            }
        } else if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                    = (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
            }
        } else if (((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y)))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = ((((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)))
                    : (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = ((((7U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)))
                    : (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = ((((1U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N))
                    : (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = ((((5U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N))
                    : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N)));
        }
        if ((0U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N));
        }
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                     >> 8U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                     >> 0x0000000bU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                     >> 0x00000015U));
        if ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            } else if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            }
        } else if ((1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                    = (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
            }
        } else if (((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y)))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = ((((3U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)))
                    : (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = ((((7U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A))
                        : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)))
                    : (2U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)));
        } else if ((3U < (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = ((((1U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (8U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (2U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A))
                    : (1U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)));
        } else if ((3U > (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = ((((5U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)) 
                     || (6U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos))) 
                    || (4U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos)))
                    ? (8U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A))
                    : (4U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)));
        }
        if ((0U == (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A))) {
            vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
                = (0x00000010U | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A));
        }
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                  >> 0x00000011U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                           >> 0x00000010U)) | ((8U 
                                                & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                                   >> 0x00000011U)) 
                                               | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N 
        = ((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    << 1U)) | (1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             << 1U)) | (1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W 
        = ((((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
             | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                         | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                  >> 1U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S 
        = ((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                      >> 2U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E 
        = ((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                      >> 3U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B 
        = ((((4U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                              >> 4U))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N))
                                                 : 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W))
                                                 : 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S))
                                                 : 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E))
                                                 : 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B))
                                                 : 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i 
        = ((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)
            ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
            : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r
                : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)
                    ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r
                    : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)
                        ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r
                        : 0U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i 
        = ((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)
            ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
            : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r
                : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)
                    ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r
                    : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)
                        ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r
                        : 0U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i 
        = ((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
            ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
            : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r
                : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                    ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r
                    : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)
                        ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r
                        : 0U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r) 
            | (0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r) 
           & ((0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i 
        = ((0x00000010U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
            ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
            : ((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r
                : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                    ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r
                    : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                        ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r
                        : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                            ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r
                            : 0U)))));
}

VL_ATTR_COLD void Vsimple_test___024root___eval_stl(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_stl\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vsimple_test___024root___stl_sequent__TOP__0(vlSelf);
        Vsimple_test___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vsimple_test___024root___eval_phase__stl(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_phase__stl\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsimple_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vsimple_test___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vsimple_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vsimple_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsimple_test___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge simple_test.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge simple_test.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge (32'sh5 * simple_test.clk))\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsimple_test___024root____Vm_traceActivitySetAll(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root____Vm_traceActivitySetAll\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
}

VL_ATTR_COLD void Vsimple_test___024root___ctor_var_reset(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___ctor_var_reset\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->simple_test__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4099263053140583086ull);
    vlSelf->simple_test__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 681441767967128703ull);
    vlSelf->simple_test__DOT__pg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2257083013781974699ull);
    vlSelf->simple_test__DOT__pg_node = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 16377972549567714468ull);
    vlSelf->simple_test__DOT__test_cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12726969362492806379ull);
    vlSelf->simple_test__DOT__error_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10503949322184107493ull);
    vlSelf->simple_test__DOT__test_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 833753590202835575ull);
    vlSelf->simple_test__DOT__pass_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2529208110450985719ull);
    vlSelf->simple_test__DOT__last_output_pkt = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15046547261684983608ull);
    vlSelf->simple_test__DOT__last_output_port = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14493662357396544432ull);
    vlSelf->simple_test__DOT__last_output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1914542154484297872ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16406853425591798213ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4806707405002101452ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2781315707807364747ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 155003922938325749ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9148092177385659547ull);
    vlSelf->simple_test__DOT__pkt_i_pkt_in_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7598866681808985375ull);
    vlSelf->simple_test__DOT__pkt_o_pkt_out_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16667355337907686720ull);
    vlSelf->simple_test__DOT__pkt_con_no_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12823490427357530466ull);
    vlSelf->simple_test__DOT__pkt_con_wo_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12808349444519158894ull);
    vlSelf->simple_test__DOT__pkt_con_so_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5424307874136691938ull);
    vlSelf->simple_test__DOT__pkt_con_eo_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5444401007709320764ull);
    vlSelf->simple_test__DOT__manual_encoded = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17876178261211369774ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_a.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8467979269390142263ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_n.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2548979814490161445ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_w.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 945997001958554130ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_s.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6027430533048883311ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_e.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15151042496342213304ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__input_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__input_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__output_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__output_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__input_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__output_payload = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__irs_status_b.__PVT__depth_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15088114527374659312ull);
    vlSelf->simple_test__DOT__debug_cycle_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15833823064779682956ull);
    vlSelf->simple_test__DOT__first_10_cycles_debug = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 776131524730623365ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11254460776486513813ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16930774219568584699ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13081373287797376598ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16616858881426719964ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13326655712222322745ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9584518446244980361ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7870945537144597115ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7268893506613762633ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12781810604577241416ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5128635086841706536ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9967420976757049045ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18163262832146214505ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4932604462847751458ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1431781409523412575ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14536980114624626133ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8670325644214657016ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6150338907146505409ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17375499412868000743ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10212587528838500530ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9710897341428063480ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11829611934238511114ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8291381337561756851ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17140048336532415052ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1528619254889405688ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14565689421620801964ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 342122923609753289ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16395148774913263365ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8661738720850864473ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4639353801997398708ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1221875923799044240ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 460474959290659840ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6798892065867103327ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9568890766384450228ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 180126535685401960ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7940019376158153946ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1227639136557285788ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10288670337361406756ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 5267738129649386972ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3025759279095955156ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16115718877459599066ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7403417384046911988ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13398889842563435943ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12684553724723225274ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4083073289872843015ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11042456676804087760ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12171254059723606263ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3616208690711598518ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10693098761536746390ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5054163562161453618ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16439386464726736362ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6962746190072646802ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7031569449636144060ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5102419925717615930ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4920091670355547772ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8295931522404721095ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16585438968986188347ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 6839792701906736324ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9827445679491837825ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18115421137608441652ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6329991492692383962ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2655270206437626013ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15399579468759497233ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1983485618155392701ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15483889967700890583ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15017602924493280542ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13999887631188927243ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14398555004743402174ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4913715442484475206ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17830469566279622436ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15407418453476503717ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7079880139386867407ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8957529842206692509ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10681899638325693190ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6529521965366638353ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10609126626141744689ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16976178942900915547ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12722346660655802752ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17891401932694810774ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17415968849033520729ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8201525958631796212ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12259118121668801054ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17443108562955580574ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11104555528854548324ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14543137833199788474ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 5594801860638106522ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4192032946582980881ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1647103179646630169ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18344069821813203122ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3706174161756625371ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14181377206924205666ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11564827367729168977ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18095097372819863230ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11533053496573248688ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4654126641252571440ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16354836002591582842ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14265056185418972998ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13775482341512592920ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4467036280138786407ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5614032309088458142ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5905814147067497110ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12323489237842245601ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5436679966404447934ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3200168928706324905ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4185707202346762790ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2837017089376148540ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5560082585893594389ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5020618354447998976ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11397965001991416644ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15550655293891430499ull);
    vlSelf->__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10431402382041214113ull);
    vlSelf->__Vtrigprevexpr_h0cf981d0__1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10483559381875298649ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
