// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_test.h for the primary calling header

#include "Vsimple_test__pch.h"

VL_ATTR_COLD void Vsimple_test___024root___eval_static(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_static\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 
        = vlSelfRef.simple_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 
        = vlSelfRef.simple_test__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr_hc94a28ed__1 = ((IData)(5U) 
                                              * (IData)(vlSelfRef.simple_test__DOT__clk));
    vlSelfRef.__Vtrigprevexpr_hc954b698__1 = ((IData)(0x0000000aU) 
                                              * (IData)(vlSelfRef.simple_test__DOT__clk));
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
            VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "Settle region did not converge after 100 tries");
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
    CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2 = 0;
    CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    // Body
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld) 
           | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S 
        = ((((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                    >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                      >> 8U))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E 
        = ((((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                    >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                      >> 8U))));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2 
        = ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                   >> 8U)));
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
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 5U)) | ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                    >> 6U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2)));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3 
        = ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 6U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 0x0000000cU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 9U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
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
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 0x0000000cU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 9U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
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
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 0x0000000cU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 9U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
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
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 0x0000000cU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 9U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
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
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 0x0000000cU));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x 
            = (7U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                     >> 9U));
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type 
            = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
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
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 5U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                           >> 4U)) | ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                             >> 5U)) 
                                      | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3)));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E))
                                                 : 
                                                ((~ 
                                                  (((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 2U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 3U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                           >> 2U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                             >> 3U)))) 
                                                   - (IData)(1U))) 
                                                 & ((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 2U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 3U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                           >> 2U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                             >> 3U))))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_3 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S))
                                                 : 
                                                ((~ 
                                                  (((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 2U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                           >> 1U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 2U)))) 
                                                   - (IData)(1U))) 
                                                 & ((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 2U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                           >> 1U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 2U))))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_4 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W))
                                                 : 
                                                ((~ 
                                                  (((((2U 
                                                       & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 1U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 1U)))) 
                                                   - (IData)(1U))) 
                                                 & ((((2U 
                                                       & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
                                                      | (1U 
                                                         & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                            >> 1U))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 1U))))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N))
                                                 : 
                                                ((~ 
                                                  (((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                           << 1U)) 
                                                       | (1U 
                                                          & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E)))) 
                                                   - (IData)(1U))) 
                                                 & ((((2U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                           << 1U)) 
                                                       | (1U 
                                                          & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = ((0U 
                                                 != (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B))
                                                 ? 
                                                ((~ 
                                                  ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B) 
                                                   - (IData)(1U))) 
                                                 & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B))
                                                 : 
                                                ((~ 
                                                  (((((4U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 2U)) 
                                                      | ((2U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                             >> 3U)) 
                                                         | (1U 
                                                            & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                               >> 4U)))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                           >> 3U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 4U)))) 
                                                   - (IData)(1U))) 
                                                 & ((((4U 
                                                       & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                                          >> 2U)) 
                                                      | ((2U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                                             >> 3U)) 
                                                         | (1U 
                                                            & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                               >> 4U)))) 
                                                     << 2U) 
                                                    | ((2U 
                                                        & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                           >> 3U)) 
                                                       | (1U 
                                                          & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                             >> 4U))))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
}

VL_ATTR_COLD void Vsimple_test___024root____Vm_traceActivitySetAll(Vsimple_test___024root* vlSelf);

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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge (32'sha * simple_test.clk))\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
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
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11254460776486513813ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13081373287797376598ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16616858881426719964ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13326655712222322745ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9584518446244980361ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7870945537144597115ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12781810604577241416ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9967420976757049045ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4932604462847751458ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14536980114624626133ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6150338907146505409ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1089174874232040093ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7091555665051363289ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1025147010146308895ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 7943471358899347566ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11520642189247582856ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16257813031463914489ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17195221620929261647ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12947686754182747241ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2099355703804800782ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12639000178172457137ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13565570681621924197ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9870080719815254165ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6945842169359987786ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6183485894504555942ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 18269180478443037943ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 170351022191059619ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13961285119292084999ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13286404394520533601ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9872946824730634576ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2967467735834474903ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 15195969461267049315ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8480889857776041837ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9786367438579075330ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12136387517538666895ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14679188819893139663ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1030738074196221749ull);
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
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 9250231574689193815ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15377548322672644413ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2361696459316684425ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3791597977440583765ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4337192363112597870ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1708941826660396554ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3084509759059299549ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15793807991782736278ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12090200686695318603ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10768308523913427156ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4296668322681016470ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17670404562600318748ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10664805668554463032ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3393639564240148230ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15401286225750606461ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17392433517931762571ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11263877305905420152ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6904804218251225730ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 7914000642027237740ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 592121600700367498ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3942363185265365745ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3543923810820061905ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 10323085726569846089ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10294566776041269628ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17147421804057316990ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14871940075372637914ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18044217391975453549ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2685316164489656416ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2327278193350754241ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15343130056706833818ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12405148017061611125ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 5467192469754156803ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5824861666365019502ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14718456785413880016ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3185360329468654089ull);
    vlSelf->simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18005478762643660775ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14076179427513946122ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4928662808602625550ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16982186896280056556ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1847445743451619274ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16779269038472826453ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7472017406314391251ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11474234502603507837ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6086527011601848547ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11941053636254740028ull);
    vlSelf->__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5843580603195640272ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15550655293891430499ull);
    vlSelf->__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10431402382041214113ull);
    vlSelf->__Vtrigprevexpr_hc94a28ed__1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13803955843587500311ull);
    vlSelf->__Vtrigprevexpr_hc954b698__1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15935344521958528840ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
