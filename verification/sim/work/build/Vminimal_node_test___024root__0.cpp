// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VlCoroutine Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(Vminimal_node_test___024root* vlSelf);
void Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i(Vminimal_node_test_pkt_in* vlSelf);
void Vminimal_node_test_pkt_con_if___eval_initial__TOP__minimal_node_test__DOT__pkt_con(Vminimal_node_test_pkt_con_if* vlSelf);

void Vminimal_node_test___024root___eval_initial(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_initial\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i((&vlSymsp->TOP__minimal_node_test__DOT__pkt_i));
    Vminimal_node_test_pkt_con_if___eval_initial__TOP__minimal_node_test__DOT__pkt_con((&vlSymsp->TOP__minimal_node_test__DOT__pkt_con));
}

VlCoroutine Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0;
    minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1;
    minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2;
    minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3;
    minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4;
    minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5;
    minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6;
    minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7;
    minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8;
    minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9;
    minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9 = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__0__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__0__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__1__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__1__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__2__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__2__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__3__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__3__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__4__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__4__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data = 0;
    CData/*2:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__5__port;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__5__port = 0;
    IData/*22:0*/ __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data;
    __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data = 0;
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    std::string __Vtemp_5;
    std::string __Vtemp_6;
    std::string __Vtemp_7;
    std::string __Vtemp_8;
    std::string __Vtemp_9;
    std::string __Vtemp_10;
    std::string __Vtemp_11;
    std::string __Vtemp_12;
    std::string __Vtemp_13;
    std::string __Vtemp_14;
    std::string __Vtemp_15;
    std::string __Vtemp_16;
    std::string __Vtemp_17;
    std::string __Vtemp_18;
    std::string __Vtemp_19;
    std::string __Vtemp_20;
    std::string __Vtemp_21;
    std::string __Vtemp_22;
    std::string __Vtemp_23;
    std::string __Vtemp_24;
    // Body
    minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             159);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_WRITEF_NX("========================================\n\360\237\232\200 MAZE\350\212\202\347\202\271\347\234\237\345\256\236\345\212\237\350\203\275\351\252\214\350\257\201\346\265\213\350\257\225\n========================================\n\345\210\235\345\247\213\347\212\266\346\200\201: rst_n=%b, pg_en=%b, pg_node=%0#\n\350\212\202\347\202\271\345\256\236\344\276\213\345\214\226\345\256\214\346\210\220: HP=0, VP=0\n\360\237\223\241 \345\267\262\345\220\257\345\212\250\346\225\260\346\215\256\345\214\205\347\233\221\346\216\247\357\274\214\345\260\206\345\256\236\346\227\266\346\230\276\347\244\272\346\211\200\346\234\211\350\276\223\345\207\272\347\253\257\345\217\243\346\264\273\345\212\250\n",0,
                 1,vlSelfRef.rst_n,1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en),
                 6,vlSelfRef.minimal_node_test__DOT__pg_node);
    minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 = 5U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             169);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\227\266\351\222\237\347\250\263\345\256\232\350\277\220\350\241\214\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-000] \345\244\215\344\275\215\346\227\266\345\272\217\347\255\211\345\276\205\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205C++\346\216\247\345\210\266\345\244\215\344\275\215\346\227\266\345\272\217\n\345\275\223\345\211\215rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    while (vlSelfRef.rst_n) {
        co_await vlSelfRef.__VtrigSched_hef7d95d9__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (~ rst_n))", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             179);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\265\213\345\210\260\345\244\215\344\275\215\345\274\200\345\247\213 rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    while ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        co_await vlSelfRef.__VtrigSched_h5a906ece__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( rst_n)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             183);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\265\213\345\210\260\345\244\215\344\275\215\347\273\223\346\235\237 rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 = 2U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             187);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\342\234\223 [TEST-000] \345\244\215\344\275\215\346\227\266\345\272\217\347\255\211\345\276\205\346\265\213\350\257\225\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-001] \345\244\215\344\275\215\345\220\216\350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\346\243\200\346\237\245 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\237\245\346\211\200\346\234\211\350\276\223\345\207\272\347\253\257\345\217\243\347\232\204\345\210\235\345\247\213\347\212\266\346\200\201\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         201);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\274\200\345\247\213\346\243\200\346\237\245\350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\nB\346\216\245\345\217\243\347\212\266\346\200\201:\n  vld: %b, rdy: 1, qos: %b\n  type: %b, src: %0#, tgt: %0#, data: 0x%x\nC\346\216\245\345\217\243\350\276\223\345\207\272\347\212\266\346\200\201:\n  N: vld=%b, rdy=1, type=%b, src=%0#, tgt=%0#, data=0x%x\n  W: vld=%b, rdy=1, type=%b, src=%0#, tgt=%0#, data=0x%x\n  S: vld=%b, rdy=1, type=%b, src=%0#, tgt=%0#, data=0x%x\n  E: vld=%b, rdy=1, type=%b, src=%0#, tgt=%0#, data=0x%x\nA\346\216\245\345\217\243\350\276\223\345\205\245\347\212\266\346\200\201:\n  rdy: %b\n\342\234\223 [TEST-001] \350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\346\243\200\346\237\245\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                 1,(1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                          >> 0x00000014U)),2,(3U & 
                                              (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                               >> 0x00000015U)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                   >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r),
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r),
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r),
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r),
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r),
                 1,((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                    & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)),
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-002] \346\225\260\346\215\256\345\214\205\344\274\240\350\276\223\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\205\215\347\275\256\346\225\205\351\232\234\344\277\241\345\217\267\345\271\266\344\273\216A\347\253\257\345\217\243\345\217\221\351\200\201\346\225\260\346\215\256\345\214\205\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__pg_en = 0U;
    vlSelfRef.minimal_node_test__DOT__pg_node = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\205\215\347\275\256\346\225\205\351\232\234\344\277\241\345\217\267\357\274\232pg_en=0, pg_node=0\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         243);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: PKT_W=23\344\275\215\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__test_packet_data = 0x000001aaU;
    vlSelfRef.minimal_node_test__DOT__test_packet_valid = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\224\237\346\210\220\346\265\213\350\257\225\346\225\260\346\215\256\345\214\205: 0x%x\n  \345\214\205\346\240\274\345\274\217\357\274\232[\347\261\273\345\236\213=%b, QoS=%b, \346\272\220=%0#, \347\233\256\346\240\207=%0#, \346\225\260\346\215\256=0x%x]\n  \345\214\205\347\261\273\345\236\213\357\274\232\345\215\225\346\222\255\357\274\214\346\272\220\350\212\202\347\202\271\357\274\2320\357\274\214\347\233\256\346\240\207\350\212\202\347\202\271\357\274\2321\357\274\214\346\225\260\346\215\256\357\274\2320xAA\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 23,vlSelfRef.minimal_node_test__DOT__test_packet_data,
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                          >> 0x15U)),1,(1U & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                                              >> 0x14U)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                                   >> 0x0eU)),6,(0x0000003fU 
                                                 & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                                                    >> 8U)),
                 8,(0x000000ffU & vlSelfRef.minimal_node_test__DOT__test_packet_data));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld 
        = vlSelfRef.minimal_node_test__DOT__test_packet_valid;
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
        = (1U & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                 >> 0x14U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type 
        = (3U & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                 >> 0x15U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
        = (0x0000003fU & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                          >> 0x0eU));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
        = (0x0000003fU & (vlSelfRef.minimal_node_test__DOT__test_packet_data 
                          >> 8U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
        = (0x000000ffU & vlSelfRef.minimal_node_test__DOT__test_packet_data);
    vlSelfRef.minimal_node_test__DOT__timeout_counter = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205A\346\216\245\345\217\243ready\344\277\241\345\217\267...\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    while (((~ ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                   & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)))) 
            & VL_GTS_III(32, 0x00000064U, vlSelfRef.minimal_node_test__DOT__timeout_counter))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             270);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.minimal_node_test__DOT__timeout_counter 
            = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__timeout_counter);
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.minimal_node_test__DOT__timeout_counter, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205\344\270\255... timeout_counter=%0d, valid=%b, rdy=%b\n",0,
                         32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                         32,vlSelfRef.minimal_node_test__DOT__timeout_counter,
                         1,(IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld),
                         1,((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)));
        }
    }
    if (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
         & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)))) {
        VL_WRITEF_NX("\342\234\223 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: A\346\216\245\345\217\243\346\217\241\346\211\213\346\210\220\345\212\237\357\274\214\346\225\260\346\215\256\345\214\205\350\242\253\346\216\245\346\224\266\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    } else {
        VL_WRITEF_NX("\342\234\227 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: A\346\216\245\345\217\243\346\217\241\346\211\213\350\266\205\346\227\266\357\274\201\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    }
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         285);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\225\260\346\215\256\345\214\205\345\217\221\351\200\201\345\256\214\346\210\220\357\274\214\346\222\244\351\224\200valid\344\277\241\345\217\267\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-003] \350\276\223\345\207\272\351\252\214\350\257\201\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\233\221\346\216\247\350\276\223\345\207\272\347\253\257\345\217\243\346\230\257\345\220\246\346\234\211\346\225\260\346\215\256\350\276\223\345\207\272\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__timeout_counter = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\274\200\345\247\213\347\233\221\346\216\247\350\276\223\345\207\272...\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    while (((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r)) 
            & VL_GTS_III(32, 0x00000064U, vlSelfRef.minimal_node_test__DOT__timeout_counter))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             300);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.minimal_node_test__DOT__timeout_counter 
            = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__timeout_counter);
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelfRef.minimal_node_test__DOT__timeout_counter, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\233\221\346\216\247\344\270\255... timeout_counter=%0d\n  B\346\216\245\345\217\243: vld=%b, data=0x%x, src=%0#, tgt=%0#\n  N\346\216\245\345\217\243: vld=%b\n  W\346\216\245\345\217\243: vld=%b\n  S\346\216\245\345\217\243: vld=%b\n  E\346\216\245\345\217\243: vld=%b\n",0,
                         32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                         32,vlSelfRef.minimal_node_test__DOT__timeout_counter,
                         1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                         8,(0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),
                         6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                           >> 0x0000000eU)),
                         6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                           >> 8U)),
                         1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r),
                         1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r,
                         1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r),
                         1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r);
        }
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) {
        VL_WRITEF_NX("\342\234\223 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: B\346\216\245\345\217\243\346\243\200\346\265\213\345\210\260\346\234\211\346\225\210\350\276\223\345\207\272\357\274\201\n  \350\276\223\345\207\272\346\225\260\346\215\256: 0x%x, valid=%b, qos=%b, type=%b\n  \346\272\220\350\212\202\347\202\271: %0#, \347\233\256\346\240\207\350\212\202\347\202\271: %0#\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                     8,(0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                     1,(1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                              >> 0x00000014U)),2,(3U 
                                                  & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                                     >> 0x00000015U)),
                     6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                       >> 0x0000000eU)),
                     6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                       >> 8U)));
        vlSelfRef.minimal_node_test__DOT__passed_count 
            = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    } else {
        VL_WRITEF_NX("\342\234\227 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: B\346\216\245\345\217\243\346\227\240\350\276\223\345\207\272\357\274\214\350\266\205\346\227\266\357\274\201\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    }
    minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             329);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\273\247\347\273\255\347\233\221\346\216\247 - B:%b N:%b W:%b S:%b E:%b\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                     1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r),
                     1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r));
        minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 
            = (minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 
               - (IData)(1U));
    }
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-004] \351\225\277\346\227\266\351\227\264\350\277\220\350\241\214\351\252\214\350\257\201 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\252\214\350\257\201\347\234\237\345\256\236\350\212\202\347\202\271\347\232\204\351\225\277\346\234\237\347\250\263\345\256\232\346\200\247\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4 = 0x00000014U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             342);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4 
            = (minimal_node_test__DOT__unnamedblk1_5__DOT____Vrepeat4 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\227\266\351\222\237\347\250\263\345\256\232\350\277\220\350\241\21420\344\270\252\345\221\250\346\234\237\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\265\213\350\257\225\344\277\241\345\217\267\346\223\215\344\275\234\350\203\275\345\212\233\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__pg_en = 1U;
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         348);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: pg_en\350\256\276\344\270\272%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en));
    vlSelfRef.minimal_node_test__DOT__pg_node = 0x2aU;
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         352);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: pg_node\350\256\276\344\270\272%0#\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 6,(IData)(vlSelfRef.minimal_node_test__DOT__pg_node));
    vlSelfRef.minimal_node_test__DOT__pg_en = 0U;
    vlSelfRef.minimal_node_test__DOT__pg_node = 0U;
    co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         358);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256 pg_en=%b, pg_node=%0#\n\342\234\223 [TEST-002] \344\273\277\347\234\237\347\216\257\345\242\203\347\250\263\345\256\232\346\200\247\351\252\214\350\257\201\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en),
                 6,vlSelfRef.minimal_node_test__DOT__pg_node,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    VL_WRITEF_NX("\342\234\223 [TEST-004] \351\225\277\346\227\266\351\227\264\350\277\220\350\241\214\351\252\214\350\257\201\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-005] \351\232\217\346\234\272\346\225\260\346\215\256\345\214\205\346\263\250\345\205\245\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\265\213\350\257\225rand_single_packet_inject task\345\212\237\350\203\275\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__0__port = 0U;
    __Vtemp_1 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_1),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))))) {
            __Vtemp_2 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_2));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))))) {
            __Vtemp_3 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_3));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__0__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_4 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__0__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_4));
    minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             375);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5 
            = (minimal_node_test__DOT__unnamedblk1_6__DOT____Vrepeat5 
               - (IData)(1U));
    }
    __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__1__port = 0U;
    __Vtemp_5 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_5),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))))) {
            __Vtemp_6 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_6));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))))) {
            __Vtemp_7 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_7));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__1__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_8 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__1__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_8));
    minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             377);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6 
            = (minimal_node_test__DOT__unnamedblk1_7__DOT____Vrepeat6 
               - (IData)(1U));
    }
    __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__2__port = 1U;
    __Vtemp_9 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_9),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))))) {
            __Vtemp_10 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_10));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))))) {
            __Vtemp_11 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_11));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__2__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_12 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__2__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_12));
    minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             379);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7 
            = (minimal_node_test__DOT__unnamedblk1_8__DOT____Vrepeat7 
               - (IData)(1U));
    }
    __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__3__port = 2U;
    __Vtemp_13 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_13),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))))) {
            __Vtemp_14 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_14));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))))) {
            __Vtemp_15 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_15));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__3__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_16 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__3__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_16));
    minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             381);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8 
            = (minimal_node_test__DOT__unnamedblk1_9__DOT____Vrepeat8 
               - (IData)(1U));
    }
    __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__4__port = 3U;
    __Vtemp_17 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_17),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))))) {
            __Vtemp_18 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_18));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))))) {
            __Vtemp_19 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_19));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__4__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_20 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__4__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_20));
    minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9)) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             383);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9 
            = (minimal_node_test__DOT__unnamedblk1_10__DOT____Vrepeat9 
               - (IData)(1U));
    }
    __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
        = (0x007fffffU & VL_URANDOM_RANGE_I(0U, 0x000000ffU));
    __Vtask_minimal_node_test__DOT__inject_simple_packet__5__port = 4U;
    __Vtemp_21 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\220\221\347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\214\205: data=0x%x, type=00, qos=%b, src=%x, tgt=%x\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_21),23,__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data,
                 1,(1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                          >> 0x14U)),6,(0x0000003fU 
                                        & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                           >> 0x0eU)),
                 6,(0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                   >> 8U)));
    if ((4U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))) {
        if (VL_UNLIKELY(((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))))) {
            __Vtemp_22 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_22));
        } else if (VL_UNLIKELY(((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))))) {
            __Vtemp_23 = Vminimal_node_test___024unit::__Venumtab_enum_name3
                [__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port];
            VL_WRITEF_NX("\351\224\231\350\257\257: \346\234\252\347\237\245\347\253\257\345\217\243\347\261\273\345\236\213 %@\n",0,
                         -1,&(__Vtemp_23));
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 492);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 500);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     502);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 504);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld = 0U;
        }
    } else if ((2U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))) {
        if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 475);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 483);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     485);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 487);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld = 0U;
        } else {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 458);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type = 0U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos 
                = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                         >> 0x14U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 0x0eU));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt 
                = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                                  >> 8U));
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data 
                = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data);
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 466);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy)))) {
                co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge clk)", 
                                                                     "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                     468);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 470);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
            vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld = 0U;
        }
    } else if ((1U & (IData)(__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port))) {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             441);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             449);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy)))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 451);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             453);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld = 0U;
    } else {
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             423);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type = 0U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
            = (1U & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                     >> 0x14U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                              >> 0x0eU));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
            = (0x0000003fU & (__Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data 
                              >> 8U));
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
            = (0x000000ffU & __Vtask_minimal_node_test__DOT__inject_simple_packet__5__packet_data);
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             432);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))))) {
            co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge clk)", 
                                                                 "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                                 434);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        co_await vlSelfRef.__VtrigSched_ha1013b2d__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             436);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    }
    __Vtemp_24 = Vminimal_node_test___024unit::__Venumtab_enum_name3
        [__Vtask_minimal_node_test__DOT__inject_simple_packet__5__port];
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\253\257\345\217\243 %@ \346\263\250\345\205\245\345\256\214\346\210\220\n\342\234\223 [TEST-005] \351\232\217\346\234\272\346\225\260\346\215\256\345\214\205\346\263\250\345\205\245\346\265\213\350\257\225\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 -1,&(__Vtemp_24),32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    VL_WRITEF_NX("\n========================================\n\360\237\223\212 \346\265\213\350\257\225\347\273\223\346\236\234\346\212\245\345\221\212\n========================================\n\346\234\200\347\273\210\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250: %0d\n\346\200\273\346\265\213\350\257\225\346\225\260: %0d\n\351\200\232\350\277\207: %0d\n\351\200\232\350\277\207\347\216\207: %0.1f%%\n========================================\n\360\237\216\211 MAZE\350\212\202\347\202\271\347\234\237\345\256\236\345\212\237\350\203\275\351\252\214\350\257\201\346\265\213\350\257\225\345\256\214\346\210\220\357\274\201\n\360\237\223\235 \346\234\254\347\211\210\346\234\254\345\214\205\345\220\253\347\234\237\345\256\236MAZE\350\212\202\347\202\271\346\250\241\345\235\227\345\256\236\344\276\213\345\214\226\n\360\237\224\247 \351\252\214\350\257\201\344\272\206\350\212\202\347\202\271\345\244\215\344\275\215\343\200\201\346\225\260\346\215\256\345\214\205\344\274\240\350\276\223\345\222\214\350\276\223\345\207\272\347\253\257\345\217\243\345\212\237\350\203\275\n========================================\n========================================\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 32,vlSelfRef.minimal_node_test__DOT__test_count,
                 32,vlSelfRef.minimal_node_test__DOT__passed_count,
                 64,((100.0 * VL_ISTOR_D_I(32, vlSelfRef.minimal_node_test__DOT__passed_count)) 
                     / VL_ISTOR_D_I(32, vlSelfRef.minimal_node_test__DOT__test_count)));
    VL_FINISH_MT("verification/testbench/node_testbench/minimal_node_test.sv", 404, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vminimal_node_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vminimal_node_test___024root___eval_triggers__act(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_triggers__act\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vtrigprevexpr_h77c9d807__0;
    __Vtrigprevexpr_h77c9d807__0 = 0;
    // Body
    __Vtrigprevexpr_h77c9d807__0 = (1U & (~ (IData)(vlSelfRef.rst_n)));
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.rst_n) 
                                                        != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                       << 3U) 
                                                      | (((IData)(__Vtrigprevexpr_h77c9d807__0) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h77c9d807__1)) 
                                                         << 2U)) 
                                                     | ((((~ (IData)(vlSelfRef.rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
    vlSelfRef.__Vtrigprevexpr_h77c9d807__1 = __Vtrigprevexpr_h77c9d807__0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered
                                         [0U]);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vminimal_node_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vminimal_node_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___trigger_anySet__act\n"); );
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

void Vminimal_node_test___024root___act_comb__TOP__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___act_comb__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_0;
    __VdfgRegularize_he50b618e_0_0 = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld));
    minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0 
        = (IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0 
        = ((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
           & (0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                          >> 3U))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0 
        = (((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                          >> 3U))) << 1U) | (0U < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                                      >> 3U))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
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
    vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en)
            ? ((IData)((0U == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                ? 0U : ((0U == (7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                      >> 3U))) ? ((0U 
                                                   < 
                                                   (7U 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                                   ? 7U
                                                   : 3U)
                         : ((0U < (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                             ? 6U : ((0U == (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                      ? 5U : 4U))))
            : 0U);
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0 
        = ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
           | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0)) 
              & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    __VdfgRegularize_he50b618e_0_0 = ((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                      | (4U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W = 0U;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0 
        = ((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
           | ((IData)(__VdfgRegularize_he50b618e_0_0) 
              | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                 | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                    | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                       | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                          & (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en)
            ? ((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
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
                        : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw))))
            : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw));
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
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0U;
    if (vlSelfRef.minimal_node_test__DOT__pg_en) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0) 
                       << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0) 
                       << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0)));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
    } else {
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                   << 3U) | (0U == 
                                             (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                   << 3U) | (((0U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                              << 2U) 
                                             | (0U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                   << 3U) | (((0U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                              << 2U) 
                                             | (0U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                                     >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))))) 
                           << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0)));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))))) 
                           << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0)));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
            }
        } else if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | ((0U == (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                                         << 2U)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (((0U == (7U 
                                                  & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                                          << 2U) | 
                                         (0U == (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))))));
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0)));
        }
    }
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg))))));
}

void Vminimal_node_test___024root___eval_act(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_act\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000dULL & vlSelfRef.__VactTriggered
         [0U])) {
        Vminimal_node_test___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vminimal_node_test___024root___nba_sequent__TOP__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_sequent__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.minimal_node_test__DOT__clk_counter = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__clk_counter);
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)
                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r
                : vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W);
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)
                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r
                : vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S);
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)
                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r
                : vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E);
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)
                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r
                : vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B);
    }
}

extern const VlUnpacked<CData/*1:0*/, 32> Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vminimal_node_test__ConstPool__TABLE_h24174b10_0;

void Vminimal_node_test___024root___nba_sequent__TOP__1(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_sequent__TOP__1\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1 = 0;
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*4:0*/ __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = 0;
    CData/*4:0*/ __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req = 0;
    CData/*4:0*/ __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req = 0;
    CData/*4:0*/ __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req = 0;
    CData/*4:0*/ __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req = 0;
    // Body
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
    __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    __Vtableidx1 = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                     << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                                << 2U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx1];
    }
    if ((2U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vminimal_node_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx1];
    }
    __Vtableidx2 = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
                     << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r) 
                                << 2U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r 
            = Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx2];
    }
    if ((2U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r 
            = Vminimal_node_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx2];
    }
    __Vtableidx3 = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
                     << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r) 
                                << 2U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r 
            = Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx3];
    }
    if ((2U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r 
            = Vminimal_node_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx3];
    }
    __Vtableidx4 = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
                     << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r) 
                                << 2U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r 
            = Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx4];
    }
    if ((2U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r 
            = Vminimal_node_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx4];
    }
    __Vtableidx5 = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
                     << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) 
                                << 2U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r 
            = Vminimal_node_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx5];
    }
    if ((2U & Vminimal_node_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r 
            = Vminimal_node_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx5];
    }
    if (vlSelfRef.rst_n) {
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                         ? (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W))
                         : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (4U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (8U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (2U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                         ? (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S))
                         : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req))))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (4U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (8U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (2U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                         ? (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E))
                         : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (4U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (8U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (2U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                         ? (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N))
                         : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req))))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (4U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (8U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (2U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                         ? (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req))
                         : ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                             ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req))))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (4U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 2U)) : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 2U)))) 
                        << 2U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (8U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 3U)) : ((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 3U)))) 
                        << 3U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (2U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                          ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                   >> 1U)) : ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                               ? 0U
                                               : (1U 
                                                  & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                     >> 1U)))) 
                        << 1U)));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
               | (0x00000010U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                                   ? (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req) 
                                            >> 4U))
                                   : ((0x00000010U 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))
                                       ? 0U : (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                >> 4U)))) 
                                 << 4U)));
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set)
                ? ((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data)))
                : vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o);
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set)
                ? ((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data)))
                : vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o);
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set)
                ? ((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data)))
                : vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o);
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set)
                ? ((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos) 
                     << 0x00000016U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type) 
                                         << 0x00000014U) 
                                        | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                           << 0x0000000eU))) 
                   | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                       << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data)))
                : vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o);
        vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered 
            = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set)
                ? (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt)
                : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered));
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
            = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy) 
                & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld))
                ? (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos) 
                    << 0x00000010U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type) 
                                        << 0x0000000eU) 
                                       | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src) 
                                           << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data))))
                : vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o);
    } else {
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req = 0U;
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req = 0U;
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req = 0U;
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req = 0U;
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req = 0U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered = 0U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o = 0U;
    }
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (1U 
                                                   & (~ 
                                                      (0U 
                                                       != 
                                                       ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                        & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (1U 
                                                   & (~ 
                                                      (0U 
                                                       != 
                                                       ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                        & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (1U 
                                                   & (~ 
                                                      (0U 
                                                       != 
                                                       ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                        & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (1U 
                                                   & (~ 
                                                      (0U 
                                                       != 
                                                       ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                        & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (
                                                   ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en) 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & (~ 
                                                       (0U 
                                                        != 
                                                        ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                         & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr))))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[1U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[0U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[2U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[3U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0 
        = ((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
                  >> 0x00000013U)) | (1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                            >> 0x00000014U)));
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
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4U] 
        = ((0x007fc000U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           << 6U)) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy 
        = ((1U & (~ (IData)(vlSelfRef.rst_n))) || (
                                                   ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en) 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & (~ 
                                                       (0U 
                                                        != 
                                                        ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                                         & (~ 
                                                            (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                                                             [4U] 
                                                             & ((~ 
                                                                 (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode)))) 
                                                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy))))))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[1U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[2U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[3U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[0U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                  >> 0x0000000bU)) | ((4U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                             >> 0x00000012U)) 
                                      | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0)));
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1 
        = ((4U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                  >> 0x00000012U)) | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy 
        = ((((4U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)) 
                    << 2U)) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)) 
                                      << 1U)) | (1U 
                                                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r))))) 
            << 2U) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)) 
                             << 1U)) | (1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                  >> 0x0000000bU)) | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           >> 0x0000000aU)) | ((8U 
                                                & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                   >> 0x00000011U)) 
                                               | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hdeb9a56a_0_1)));
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
    vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[4U] 
        = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
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
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
           | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W)));
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
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
           | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S)));
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
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
           | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
           | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N)));
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
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
           | (0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B)));
}

void Vminimal_node_test___024root___nba_comb__TOP__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_comb__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0;
    minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_0;
    __VdfgRegularize_he50b618e_0_0 = 0;
    // Body
    minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0 
        = (IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0 
        = ((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
           & (0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                          >> 3U))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0 
        = (((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                          >> 3U))) << 1U) | (0U < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                                      >> 3U))));
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0 
        = ((0U >= (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                         >> 3U))) | (1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en)
            ? ((IData)((0U == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                ? 0U : ((0U == (7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                      >> 3U))) ? ((0U 
                                                   < 
                                                   (7U 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                                   ? 7U
                                                   : 3U)
                         : ((0U < (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                             ? 6U : ((0U == (7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node)))
                                      ? 5U : 4U))))
            : 0U);
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0 
        = ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
           | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0)) 
              & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    __VdfgRegularize_he50b618e_0_0 = ((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                      | (4U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W = 0U;
    minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0 
        = ((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
           | ((IData)(__VdfgRegularize_he50b618e_0_0) 
              | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                 | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                    | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                       | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                          & (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgRegularize_h868da09b_0_0)))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0U;
    if (vlSelfRef.minimal_node_test__DOT__pg_en) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_S__DOT____VdfgRegularize_h65fd26fc_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_E__DOT____VdfgRegularize_h7d1059ad_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | ((((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                        | ((IData)(__VdfgRegularize_he50b618e_0_0) 
                           | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                              | ((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                    | ((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0))))))) 
                       << 3U) | ((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                                 | ((~ (IData)(minimal_node_test__DOT__dut__DOT__u_router_W__DOT____VdfgRegularize_hddd901b9_0_0)) 
                                    & (6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))))));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
            = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
               | ((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                  << 4U));
        if ((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0) 
                       << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hf4996540__0) 
                       << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_h99514060__0)));
        } else if ((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                >> 3U)))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x1cU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | (5U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = ((0x17U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                   | ((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos)) 
                      << 3U));
        }
    } else {
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                   << 3U) | (0U == 
                                             (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                   << 3U) | (((0U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                              << 2U) 
                                             | (0U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))))) 
                           << 3U) | (((0U == (7U & 
                                              ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                               >> 3U))) 
                                      << 1U) | (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                                      >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                        >> 3U))) << 4U));
            }
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W 
                = ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type))
                    ? (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                   << 3U) | (((0U == 
                                               (7U 
                                                & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                              << 2U) 
                                             | (0U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))))))
                    : (((IData)((0U == (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                        << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                   << 3U) | ((0U == 
                                              (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))) 
                                             & (0U 
                                                < (7U 
                                                   & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                                      >> 3U)))))));
        }
        if ((2U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
            if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                                     >> 3U))))));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | (6U | (((0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                 << 3U) | (0U >= (7U 
                                                  & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                                     >> 3U))))));
            } else {
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))))) 
                           << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0)));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x10U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | (((IData)(((0U == (0x38U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))) 
                                    & (0U >= (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))))) 
                           << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hd5e6a10b__0)));
                vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                    = ((0x0fU & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A)) 
                       | ((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U))) << 4U));
            }
        } else if ((1U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type))) {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | ((0U == (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                                         << 2U)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = (((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (((0U == (7U 
                                                  & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                                          << 2U) | 
                                         (0U == (7U 
                                                 & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))))));
        } else {
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N 
                = (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0)));
            vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
                = (((IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hb2d3db03__0) 
                    << 4U) | (((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))) 
                               << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_router_A__DOT____VdfgExtracted_hff2890c4__0)));
        }
    }
}

void Vminimal_node_test___024root___nba_comb__TOP__1(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_comb__TOP__1\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
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
    vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en)
            ? ((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
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
                        : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw))))
            : (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw));
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

void Vminimal_node_test___024root___eval_nba(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_nba\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vminimal_node_test___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vminimal_node_test___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vminimal_node_test___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vminimal_node_test___024root___nba_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
}

void Vminimal_node_test___024root___timing_commit(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___timing_commit\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_ha1013b2d__0.commit(
                                                   "@(posedge clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_hef7d95d9__0.commit(
                                                   "@( (~ rst_n))");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h5a906ece__0.commit(
                                                   "@( rst_n)");
    }
}

void Vminimal_node_test___024root___timing_resume(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___timing_resume\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_ha1013b2d__0.resume(
                                                   "@(posedge clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hef7d95d9__0.resume(
                                                   "@( (~ rst_n))");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h5a906ece__0.resume(
                                                   "@( rst_n)");
    }
}

void Vminimal_node_test___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vminimal_node_test___024root___eval_phase__act(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_phase__act\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vminimal_node_test___024root___eval_triggers__act(vlSelf);
    Vminimal_node_test___024root___timing_commit(vlSelf);
    Vminimal_node_test___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vminimal_node_test___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vminimal_node_test___024root___timing_resume(vlSelf);
        Vminimal_node_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vminimal_node_test___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vminimal_node_test___024root___eval_phase__nba(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_phase__nba\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vminimal_node_test___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vminimal_node_test___024root___eval_nba(vlSelf);
        Vminimal_node_test___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vminimal_node_test___024root___eval(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vminimal_node_test___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("verification/testbench/node_testbench/minimal_node_test.sv", 31, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vminimal_node_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("verification/testbench/node_testbench/minimal_node_test.sv", 31, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vminimal_node_test___024root___eval_phase__act(vlSelf));
    } while (Vminimal_node_test___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vminimal_node_test___024root___eval_debug_assertions(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_debug_assertions\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
}
#endif  // VL_DEBUG
