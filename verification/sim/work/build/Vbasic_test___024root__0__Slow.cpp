// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbasic_test.h for the primary calling header

#include "Vbasic_test__pch.h"

VL_ATTR_COLD void Vbasic_test___024root___eval_static(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_static\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__clk__0 
        = vlSelfRef.basic_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__basic_test__DOT__rst_n__0 
        = vlSelfRef.basic_test__DOT__rst_n;
}

VL_ATTR_COLD void Vbasic_test___024root___eval_initial__TOP(Vbasic_test___024root* vlSelf);

VL_ATTR_COLD void Vbasic_test___024root___eval_initial(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_initial\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbasic_test___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vbasic_test___024root___eval_initial__TOP(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_initial__TOP\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.basic_test__DOT__clk = 0U;
    vlSelfRef.basic_test__DOT__pg_en = 0U;
    vlSelfRef.basic_test__DOT__pg_node = 0U;
    vlSelfRef.basic_test__DOT__rst_n = 1U;
    VL_WRITEF_NX("=== \345\274\200\345\247\213MAZE\350\212\202\347\202\271\345\237\272\346\234\254\346\265\213\350\257\225 ===\n\346\265\213\350\257\225\350\212\202\347\202\271\344\275\215\347\275\256: (3, 3)\n\346\265\213\350\257\225\345\221\250\346\234\237 1: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 2: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 3: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 4: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 5: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 6: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 7: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 8: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 9: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 10: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 11: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 12: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n",0);
    VL_WRITEF_NX("\346\265\213\350\257\225\345\221\250\346\234\237 13: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 14: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 15: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 16: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 17: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 18: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 19: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n\346\265\213\350\257\225\345\221\250\346\234\237 20: \350\212\202\347\202\271\350\277\220\350\241\214\346\255\243\345\270\270\n=== \346\265\213\350\257\225\345\256\214\346\210\220 ===\n",0);
    VL_FINISH_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/basic_test.sv", 71, "");
}

VL_ATTR_COLD void Vbasic_test___024root___eval_final(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_final\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbasic_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbasic_test___024root___eval_phase__stl(Vbasic_test___024root* vlSelf);

VL_ATTR_COLD void Vbasic_test___024root___eval_settle(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_settle\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vbasic_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/basic_test.sv", 9, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vbasic_test___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vbasic_test___024root___eval_triggers__stl(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_triggers__stl\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbasic_test___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vbasic_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbasic_test___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vbasic_test___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vbasic_test___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*0:0*/, 1024> Vbasic_test__ConstPool__TABLE_h14c994e7_0;

VL_ATTR_COLD void Vbasic_test___024root___stl_sequent__TOP__0(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___stl_sequent__TOP__0\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ basic_test__DOT__u_dut__DOT__fault_relative_pos;
    basic_test__DOT__u_dut__DOT__fault_relative_pos = 0;
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
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h648903fc__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h648903fc__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h6c0f701e__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h6c0f701e__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_hdcba4fb4__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_hdcba4fb4__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4d6eac7b__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4d6eac7b__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h289a7c55__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h289a7c55__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h9af19460__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h9af19460__0 = 0;
    CData/*1:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0 = 0;
    CData/*2:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0 = 0;
    CData/*2:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h24e781b1__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h24e781b1__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h283cd3be__0;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h283cd3be__0 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_3;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_3 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_5;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_5 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1;
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_3;
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_3 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_5;
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_5 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1;
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_3;
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_3 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_5;
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_5 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1;
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_3;
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_3 = 0;
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_5;
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_5 = 0;
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
    CData/*0:0*/ basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0;
    basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_0;
    __VdfgRegularize_h4af1c392_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_1;
    __VdfgRegularize_h4af1c392_0_1 = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.no_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.so_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.eo_rdy));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy));
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[0U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[1U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[2U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[3U] 
        = vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o;
    vlSelfRef.basic_test__DOT__u_dut__DOT__pld_buf[4U] 
        = ((0x007fc000U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           << 6U)) | (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)));
    basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.no_rdy)));
    basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy)));
    basic_test__DOT__u_dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.so_rdy)));
    basic_test__DOT__u_dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.eo_rdy)));
    basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy)));
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_3 
        = ((3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_5 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                         >> 3U))) | (2U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_3 
        = ((3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_5 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                         >> 3U))) | (2U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_3 
        = ((3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_5 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                         >> 3U))) | (2U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))));
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy 
        = ((((4U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r)) 
                    << 2U)) | ((2U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r)) 
                                      << 1U)) | (1U 
                                                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r))))) 
            << 2U) | ((2U & ((~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r)) 
                             << 1U)) | (1U & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h24e781b1__0 
        = ((((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
             & (3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                            >> 3U)))) << 2U) | (((3U 
                                                  > 
                                                  (7U 
                                                   & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                                 << 1U) 
                                                | ((3U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                                   & (3U 
                                                      < 
                                                      (7U 
                                                       & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                                          >> 3U))))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h283cd3be__0 
        = (IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt)));
    basic_test__DOT__u_dut__DOT____VdfgRegularize_h7f89e92c_0_0 
        = ((2U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o 
                  >> 0x00000013U)) | (1U & (vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                            >> 0x00000014U)));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_5 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                         >> 3U))) | (2U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_3 
        = ((3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1 
        = ((3U <= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                         >> 3U))) | (4U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))));
    basic_test__DOT__u_dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_vld));
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ 
        = ((IData)(basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r));
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
    basic_test__DOT__u_dut__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.basic_test__DOT__pg_en)
            ? ((IData)((0x1bU == (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                ? 0U : ((3U > (7U & ((IData)(vlSelfRef.basic_test__DOT__pg_node) 
                                     >> 3U))) ? ((3U 
                                                  < 
                                                  (7U 
                                                   & (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                                                  ? 8U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                                                   ? 1U
                                                   : 2U))
                         : ((3U == (7U & ((IData)(vlSelfRef.basic_test__DOT__pg_node) 
                                          >> 3U))) ? 
                            ((3U < (7U & (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                              ? 7U : 3U) : ((3U < (7U 
                                                   & (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                                             ? 6U : 
                                            ((3U == 
                                              (7U & (IData)(vlSelfRef.basic_test__DOT__pg_node)))
                                              ? 5U : 4U)))))
            : 0U);
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h6c0f701e__0 
        = ((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1)) 
           & (1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h9af19460__0 
        = (((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_5)) 
            & (2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
           | (3U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4d6eac7b__0 
        = (((7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
            & (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                           >> 3U)))) | ((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_3)) 
                                        & (6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_hdcba4fb4__0 
        = (((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1)) 
            & (8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
           | ((3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                            >> 3U))) & (7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0 
        = (((1U != (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
            << 1U) | (1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0 
        = (((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
            << 1U) | (5U != (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
    __VdfgRegularize_h4af1c392_0_1 = ((8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                      | (7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
    __VdfgRegularize_h4af1c392_0_0 = ((3U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                      | (4U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)));
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
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h289a7c55__0 
        = ((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
           | ((IData)(__VdfgRegularize_h4af1c392_0_1) 
              | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                 | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                    | (((2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                        & (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_5)) 
                       | (4U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S = 0U;
    vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E = 0U;
    vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W = 0U;
    basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h648903fc__0 
        = ((2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
           | ((IData)(__VdfgRegularize_h4af1c392_0_0) 
              | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                 | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                     & (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1)) 
                    | (((8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                        & (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_1)) 
                       | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                          & (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgRegularize_hfefd5553_0_3)))))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r) 
            | (0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_W))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r) 
           & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_gnt_W)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wo_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r)))));
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B 
        = (0x0000001fU & ((0U != (IData)(basic_test__DOT__u_dut__DOT__arb_qos_B))
                           ? ((~ ((IData)(basic_test__DOT__u_dut__DOT__arb_qos_B) 
                                  - (IData)(1U))) & (IData)(basic_test__DOT__u_dut__DOT__arb_qos_B))
                           : ((~ (basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 
                                  - (IData)(1U))) & basic_test__DOT__u_dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0)));
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N = 0U;
    vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A = 0U;
    if (vlSelfRef.basic_test__DOT__pg_en) {
        vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
            = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
               | ((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                  << 4U));
        if ((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                   | (((((2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                         | ((IData)(__VdfgRegularize_h4af1c392_0_0) 
                            | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                               | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                   & (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1)) 
                                  | (((8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                      & (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1)) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        & (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_3))))))) 
                        << 3U) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1)) 
                                    & (8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                   | ((3U >= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                               >> 3U))) 
                                      & (7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))) 
                                  << 2U)) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_1)) 
                                               & (1U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                              << 1U) 
                                             | (((7U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                                 & (3U 
                                                    < 
                                                    (7U 
                                                     & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                                        >> 3U)))) 
                                                | ((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_3)) 
                                                   & (6U 
                                                      == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))))));
        } else if ((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                   | (((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_5)) 
                         & (2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                        | (3U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                       << 2U) | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                  | ((IData)(__VdfgRegularize_h4af1c392_0_1) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                           | (((2U 
                                                == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                               & (IData)(basic_test__DOT__u_dut__DOT__u_router_S__DOT____VdfgRegularize_h38c573ad_0_5)) 
                                              | (4U 
                                                 == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))))))) 
                                 << 1U)));
        } else if ((3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                   | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = (0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S));
        } else if ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                   | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0) 
                      << 1U));
        }
        vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
            = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
               | ((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                  << 4U));
        if ((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                   | (((((2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                         | ((IData)(__VdfgRegularize_h4af1c392_0_0) 
                            | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                               | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                   & (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1)) 
                                  | (((8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                      & (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1)) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        & (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_3))))))) 
                        << 3U) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1)) 
                                    & (8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                   | ((3U >= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                               >> 3U))) 
                                      & (7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))) 
                                  << 2U)) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_1)) 
                                               & (1U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                              << 1U) 
                                             | (((7U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                                 & (3U 
                                                    < 
                                                    (7U 
                                                     & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                                        >> 3U)))) 
                                                | ((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_3)) 
                                                   & (6U 
                                                      == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))))));
        } else if ((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                   | (((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_5)) 
                         & (2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                        | (3U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                       << 2U) | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                  | ((IData)(__VdfgRegularize_h4af1c392_0_1) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                           | (((2U 
                                                == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                               & (IData)(basic_test__DOT__u_dut__DOT__u_router_E__DOT____VdfgRegularize_haca47149_0_5)) 
                                              | (4U 
                                                 == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))))))) 
                                 << 1U)));
        } else if ((3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                   | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = (0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E));
        } else if ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                   | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0) 
                      << 1U));
        }
        vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
            = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
               | ((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                  << 4U));
        if ((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                   | (((((2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                         | ((IData)(__VdfgRegularize_h4af1c392_0_0) 
                            | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                               | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                   & (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1)) 
                                  | (((8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                      & (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1)) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        & (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_3))))))) 
                        << 3U) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1)) 
                                    & (8U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                   | ((3U >= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                               >> 3U))) 
                                      & (7U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))) 
                                  << 2U)) | ((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_1)) 
                                               & (1U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                                              << 1U) 
                                             | (((7U 
                                                  == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                                 & (3U 
                                                    < 
                                                    (7U 
                                                     & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                                        >> 3U)))) 
                                                | ((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_3)) 
                                                   & (6U 
                                                      == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)))))));
        } else if ((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                   | (((((~ (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_5)) 
                         & (2U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                        | (3U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))) 
                       << 2U) | (((1U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                  | ((IData)(__VdfgRegularize_h4af1c392_0_1) 
                                     | ((6U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                        | ((5U == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                           | (((2U 
                                                == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos)) 
                                               & (IData)(basic_test__DOT__u_dut__DOT__u_router_W__DOT____VdfgRegularize_h03d7eb62_0_5)) 
                                              | (4U 
                                                 == (IData)(basic_test__DOT__u_dut__DOT__fault_relative_pos))))))) 
                                 << 1U)));
        } else if ((3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                   | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = (0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W));
        } else if ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                   | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0) 
                      << 1U));
        }
        vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
            = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
               | ((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
            = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
               | ((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        if ((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                   | ((((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h648903fc__0) 
                        << 3U) | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_hdcba4fb4__0) 
                                  << 2U)) | (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h6c0f701e__0) 
                                              << 1U) 
                                             | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4d6eac7b__0))));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                   | ((((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h648903fc__0) 
                        << 3U) | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_hdcba4fb4__0) 
                                  << 2U)) | (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h6c0f701e__0) 
                                              << 1U) 
                                             | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4d6eac7b__0))));
        } else if ((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                   | (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h9af19460__0) 
                       << 2U) | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h289a7c55__0) 
                                 << 1U)));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = ((0x10U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                   | (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h9af19460__0) 
                       << 2U) | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h289a7c55__0) 
                                 << 1U)));
        } else if ((3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                   | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = (0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                   | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_he45ea23d__0));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = (0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A));
        } else if ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                >> 3U)))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                   | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0) 
                      << 1U));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                   | ((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h4cadd9e8__0) 
                      << 1U));
        }
    } else {
        if ((2U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_type))) {
            if ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_type))) {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x1eU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | (3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src) 
                                       >> 3U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | (((3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))) 
                           << 3U) | (((3U <= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src) 
                                               >> 3U))) 
                                      << 2U) | ((3U 
                                                 <= 
                                                 (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))) 
                                                << 1U))));
            } else {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | ((IData)(((0x18U == (0x38U 
                                              & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))) 
                                   & (3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))))) 
                          << 3U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | (((IData)(((0x18U == (0x38U 
                                               & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))) 
                                    & (3U <= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_src))))) 
                           << 1U) | (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                                 >> 3U)))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x1bU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                       >> 3U))) << 2U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                    = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S)) 
                       | ((3U == (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_S 
                = ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_type))
                    ? (((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                        << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                                   << 3U) | (((3U > 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                                              << 1U) 
                                             | (3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))))))
                    : ((((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                         << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                                    << 3U) | (((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                                               & (3U 
                                                  > 
                                                  (7U 
                                                   & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                                      >> 3U)))) 
                                              << 2U))) 
                       | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                           << 1U) | ((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt))) 
                                     & (3U < (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.si_tgt) 
                                               >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_type))) {
            if ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_type))) {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x1eU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | (3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src) 
                                       >> 3U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | (((3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))) 
                           << 3U) | (((3U <= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src) 
                                               >> 3U))) 
                                      << 2U) | ((3U 
                                                 <= 
                                                 (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))) 
                                                << 1U))));
            } else {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | ((IData)(((0x18U == (0x38U 
                                              & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))) 
                                   & (3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))))) 
                          << 3U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | (((IData)(((0x18U == (0x38U 
                                               & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))) 
                                    & (3U <= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_src))))) 
                           << 1U) | (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                                 >> 3U)))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x1bU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                       >> 3U))) << 2U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                    = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E)) 
                       | ((3U == (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_E 
                = ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_type))
                    ? ((((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                         << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                                    << 3U) | ((3U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                                              << 2U))) 
                       | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                           << 1U) | (3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt)))))
                    : ((((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                         << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                                    << 3U) | (((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                                               & (3U 
                                                  > 
                                                  (7U 
                                                   & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                                      >> 3U)))) 
                                              << 2U))) 
                       | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                           << 1U) | ((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt))) 
                                     & (3U < (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ei_tgt) 
                                               >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_type))) {
            if ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_type))) {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x1eU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | (3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src) 
                                       >> 3U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | (((3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))) 
                           << 3U) | (((3U <= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src) 
                                               >> 3U))) 
                                      << 2U) | ((3U 
                                                 <= 
                                                 (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))) 
                                                << 1U))));
            } else {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | ((IData)(((0x18U == (0x38U 
                                              & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))) 
                                   & (3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))))) 
                          << 3U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | (((IData)(((0x18U == (0x38U 
                                               & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))) 
                                    & (3U <= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_src))))) 
                           << 1U) | (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                                 >> 3U)))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x1bU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                       >> 3U))) << 2U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                    = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W)) 
                       | ((3U == (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_W 
                = ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_type))
                    ? ((((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                         << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                                    << 3U) | ((3U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                                              << 2U))) 
                       | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                           << 1U) | (3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt)))))
                    : ((((IData)((0x1bU == (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                         << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                                    << 3U) | (((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                                               & (3U 
                                                  > 
                                                  (7U 
                                                   & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                                      >> 3U)))) 
                                              << 2U))) 
                       | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                           << 1U) | ((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt))) 
                                     & (3U < (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.wi_tgt) 
                                               >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_type))) {
            if ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_type))) {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x1eU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | (3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src) 
                                       >> 3U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | (((3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                           << 3U) | (((3U <= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src) 
                                               >> 3U))) 
                                      << 2U) | ((3U 
                                                 <= 
                                                 (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                                << 1U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x1eU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | (3U >= (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src) 
                                       >> 3U))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x11U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | (((3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                           << 3U) | (((3U <= (7U & 
                                              ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src) 
                                               >> 3U))) 
                                      << 2U) | ((3U 
                                                 <= 
                                                 (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                                << 1U))));
            } else {
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | ((IData)(((0x18U == (0x38U 
                                              & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                   & (3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))))) 
                          << 3U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | (((IData)(((0x18U == (0x38U 
                                               & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                    & (3U <= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))))) 
                           << 1U) | (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                                 >> 3U)))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x1bU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                       >> 3U))) << 2U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                    = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N)) 
                       | ((3U == (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x17U & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | ((IData)(((0x18U == (0x38U 
                                              & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                   & (3U >= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))))) 
                          << 3U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x1cU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | (((IData)(((0x18U == (0x38U 
                                               & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))) 
                                    & (3U <= (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_src))))) 
                           << 1U) | (3U < (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                                 >> 3U)))));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x1bU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | ((3U > (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                       >> 3U))) << 2U));
                vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                    = ((0x0fU & (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A)) 
                       | ((3U == (7U & ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
            }
        } else if ((1U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_type))) {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = ((((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                     << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                << 3U) | ((3U == (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                          << 2U))) 
                   | ((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                      << 1U));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = ((((3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                     << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                << 3U) | ((3U == (7U 
                                                  & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                                          << 2U))) 
                   | (((3U > (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                       << 1U) | (3U == (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt)))));
        } else {
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_N 
                = (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h283cd3be__0) 
                    << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h24e781b1__0)));
            vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A 
                = (((IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h283cd3be__0) 
                    << 4U) | (((3U < (7U & (IData)(vlSymsp->TOP__basic_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(basic_test__DOT__u_dut__DOT__u_router_A__DOT____VdfgExtracted_h24e781b1__0)));
        }
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
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r) 
            | (0U != (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B))) 
           & (IData)(basic_test__DOT__u_dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r) 
           & ((0U != (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt_B)) 
              & ((~ (IData)(vlSymsp->TOP__basic_test__DOT__pkt_o.pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__basic_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.basic_test__DOT__u_dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__tgt_is_pg)))));
    vlSelfRef.basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.basic_test__DOT__u_dut__DOT__tgt_is_pg))))));
}

VL_ATTR_COLD void Vbasic_test___024root___eval_stl(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_stl\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vbasic_test___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vbasic_test___024root___eval_phase__stl(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___eval_phase__stl\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbasic_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vbasic_test___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vbasic_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vbasic_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbasic_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vbasic_test___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge basic_test.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge basic_test.rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbasic_test___024root___ctor_var_reset(Vbasic_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbasic_test___024root___ctor_var_reset\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->basic_test__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9109192488491237418ull);
    vlSelf->basic_test__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16715877323320967415ull);
    vlSelf->basic_test__DOT__pg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16971715722418295050ull);
    vlSelf->basic_test__DOT__pg_node = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11510774223382215231ull);
    vlSelf->basic_test__DOT__u_dut__DOT__tgt_is_pg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14237052287708821980ull);
    vlSelf->basic_test__DOT__u_dut__DOT__cpy_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9075062098025539663ull);
    vlSelf->basic_test__DOT__u_dut__DOT__route_req_N = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3627335611700067192ull);
    vlSelf->basic_test__DOT__u_dut__DOT__route_req_S = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6159807489777528418ull);
    vlSelf->basic_test__DOT__u_dut__DOT__route_req_E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1951512367055009571ull);
    vlSelf->basic_test__DOT__u_dut__DOT__route_req_W = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18296113396608490561ull);
    vlSelf->basic_test__DOT__u_dut__DOT__route_req_A = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8396700303093640410ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->basic_test__DOT__u_dut__DOT__arb_gnt[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13214292475679229175ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->basic_test__DOT__u_dut__DOT__pld_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 12104187573190814260ull);
    }
    vlSelf->basic_test__DOT__u_dut__DOT__obuf_rdy = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7385763291824528835ull);
    vlSelf->basic_test__DOT__u_dut__DOT__pkt_in_tgt_A_buffered = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 4026376665368302823ull);
    vlSelf->basic_test__DOT__u_dut__DOT__pkt_in_ctrl_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10051377983150152461ull);
    vlSelf->basic_test__DOT__u_dut__DOT__pkt_in_data_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14840688184394911420ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8159532899089435868ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11060394950722411552ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13435942900281201553ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 4005229292964376820ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17831899692875424849ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 843219963507284496ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 17786452455595823128ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7323309906022482213ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6527428943652289679ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 11328052706080450483ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3584674312377849861ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12840416036750663382ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__payload_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3154600750200854382ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__arb_req = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14601794018773027577ull);
    vlSelf->basic_test__DOT__u_dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17065418178432458536ull);
    vlSelf->basic_test__DOT__u_dut__DOT__arb_gnt_B = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9090568331835089886ull);
    vlSelf->basic_test__DOT__u_dut__DOT__pkt_B = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13478123705108945198ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5595958475786981467ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_A_CTRL__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2300868513168550805ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4086333635221916915ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_N__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16433475981266885593ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2509220310242936643ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_W__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 268696097831977086ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13949026454481807376ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_S__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7751604876341705368ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3336055661999468374ull);
    vlSelf->basic_test__DOT__u_dut__DOT__u_IBUF_E__DOT__clr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4519261376885320273ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11893463277613230054ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4114965545651536084ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10517720694491527070ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 981193156388588670ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3102598818542133397ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15997631192095105593ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10590619584473888666ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2371368032742358490ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10294503051989022916ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17137922431704818221ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11022759063271018778ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11932693233257532630ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2406175282356146804ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13342260720310930134ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11866415381369895385ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6671338205127654670ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13917777056943883797ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17217771357299908376ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3727223783848806752ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3933589352711225574ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5013969178657771159ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7897593238114999561ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17787205455124812282ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5698527298453246942ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9142470324101207959ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__valid1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9911724092906651525ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload0_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 2877120104680434369ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__payload1_r = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14374226655563724038ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16406713088657920494ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8783951011041898453ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4890745290473519061ull);
    vlSelf->basic_test__DOT__u_dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9408210009019677765ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__basic_test__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2004910989438475055ull);
    vlSelf->__Vtrigprevexpr___TOP__basic_test__DOT__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12095751535676474094ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
