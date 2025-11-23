// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VlCoroutine Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(Vminimal_node_test___024root* vlSelf);
void Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i(Vminimal_node_test_pkt_in* vlSelf);

void Vminimal_node_test___024root___eval_initial(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_initial\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i((&vlSymsp->TOP__minimal_node_test__DOT__pkt_i));
}

VlCoroutine Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ minimal_node_test__DOT__timeout_counter;
    minimal_node_test__DOT__timeout_counter = 0;
    IData/*22:0*/ minimal_node_test__DOT__test_packet_data;
    minimal_node_test__DOT__test_packet_data = 0;
    CData/*0:0*/ minimal_node_test__DOT__test_packet_valid;
    minimal_node_test__DOT__test_packet_valid = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0;
    minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1;
    minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2;
    minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3;
    minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0;
    // Body
    VL_WRITEF_NX("========================================\n\360\237\232\200 MAZE\350\212\202\347\202\271\347\234\237\345\256\236\345\212\237\350\203\275\351\252\214\350\257\201\346\265\213\350\257\225\n========================================\n\345\210\235\345\247\213\347\212\266\346\200\201: rst_n=%b, pg_en=%b, pg_node=%0#\n\350\212\202\347\202\271\345\256\236\344\276\213\345\214\226\345\256\214\346\210\220: HP=0, VP=0\n",0,
                 1,vlSelfRef.rst_n,1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en),
                 6,vlSelfRef.minimal_node_test__DOT__pg_node);
    Verilated::runFlushCallbacks();
    minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 5U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             123);
        minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (minimal_node_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\227\266\351\222\237\347\250\263\345\256\232\350\277\220\350\241\214\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-000] \345\244\215\344\275\215\346\227\266\345\272\217\347\255\211\345\276\205\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205C++\346\216\247\345\210\266\345\244\215\344\275\215\346\227\266\345\272\217\n\345\275\223\345\211\215rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    Verilated::runFlushCallbacks();
    while (vlSelfRef.rst_n) {
        co_await vlSelfRef.__VtrigSched_h6037169b__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (~ rst_n))", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             133);
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\265\213\345\210\260\345\244\215\344\275\215\345\274\200\345\247\213 rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    Verilated::runFlushCallbacks();
    while ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        co_await vlSelfRef.__VtrigSched_ha9dae870__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( rst_n)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             137);
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\265\213\345\210\260\345\244\215\344\275\215\347\273\223\346\235\237 rst_n=%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.rst_n));
    Verilated::runFlushCallbacks();
    minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             141);
        minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (minimal_node_test__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\342\234\223 [TEST-000] \345\244\215\344\275\215\346\227\266\345\272\217\347\255\211\345\276\205\346\265\213\350\257\225\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-001] \345\244\215\344\275\215\345\220\216\350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\346\243\200\346\237\245 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\243\200\346\237\245\346\211\200\346\234\211\350\276\223\345\207\272\347\253\257\345\217\243\347\232\204\345\210\235\345\247\213\347\212\266\346\200\201\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         151);
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\274\200\345\247\213\346\243\200\346\237\245\350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\nB\346\216\245\345\217\243\347\212\266\346\200\201:\n  vld: %b, rdy: %b, qos: %b\n  type: %b, src: %0#, tgt: %0#, data: 0x%x\nC\346\216\245\345\217\243\350\276\223\345\207\272\347\212\266\346\200\201:\n  N: vld=%b, rdy=%b, type=%b, src=%0#, tgt=%0#, data=0x%x\n  W: vld=%b, rdy=%b, type=%b, src=%0#, tgt=%0#, data=0x%x\n  S: vld=%b, rdy=%b, type=%b, src=%0#, tgt=%0#, data=0x%x\n  E: vld=%b, rdy=%b, type=%b, src=%0#, tgt=%0#, data=0x%x\nA\346\216\245\345\217\243\350\276\223\345\205\245\347\212\266\346\200\201:\n  rdy: %b\n\342\234\223 [TEST-001] \350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201\346\243\200\346\237\245\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                 1,vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy,
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
                 1,vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy,
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r),
                 1,vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy,
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r),
                 1,vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy,
                 2,(3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                          >> 0x00000015U)),6,(0x0000003fU 
                                              & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 0x0000000eU)),
                 6,(0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                   >> 8U)),8,(0x000000ffU 
                                              & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r),
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r),
                 1,vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy,
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
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-002] \346\225\260\346\215\256\345\214\205\344\274\240\350\276\223\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\205\215\347\275\256\346\225\205\351\232\234\344\277\241\345\217\267\345\271\266\344\273\216A\347\253\257\345\217\243\345\217\221\351\200\201\346\225\260\346\215\256\345\214\205\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__pg_en = 0U;
    vlSelfRef.minimal_node_test__DOT__pg_node = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\205\215\347\275\256\346\225\205\351\232\234\344\277\241\345\217\267\357\274\232pg_en=0, pg_node=0\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         193);
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: PKT_W=23\344\275\215\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    minimal_node_test__DOT__test_packet_data = 0x000001aaU;
    minimal_node_test__DOT__test_packet_valid = 1U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\224\237\346\210\220\346\265\213\350\257\225\346\225\260\346\215\256\345\214\205: 0x%x\n  \345\214\205\346\240\274\345\274\217\357\274\232[\347\261\273\345\236\213=%b, QoS=%b, \346\272\220=%0#, \347\233\256\346\240\207=%0#, \346\225\260\346\215\256=0x%x]\n  \345\214\205\347\261\273\345\236\213\357\274\232\345\215\225\346\222\255\357\274\214\346\272\220\350\212\202\347\202\271\357\274\2320\357\274\214\347\233\256\346\240\207\350\212\202\347\202\271\357\274\2321\357\274\214\346\225\260\346\215\256\357\274\2320xAA\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 23,minimal_node_test__DOT__test_packet_data,
                 2,(3U & (minimal_node_test__DOT__test_packet_data 
                          >> 0x15U)),1,(1U & (minimal_node_test__DOT__test_packet_data 
                                              >> 0x14U)),
                 6,(0x0000003fU & (minimal_node_test__DOT__test_packet_data 
                                   >> 0x0eU)),6,(0x0000003fU 
                                                 & (minimal_node_test__DOT__test_packet_data 
                                                    >> 8U)),
                 8,(0x000000ffU & minimal_node_test__DOT__test_packet_data));
    Verilated::runFlushCallbacks();
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld 
        = minimal_node_test__DOT__test_packet_valid;
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos 
        = (1U & (minimal_node_test__DOT__test_packet_data 
                 >> 0x14U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type 
        = (3U & (minimal_node_test__DOT__test_packet_data 
                 >> 0x15U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src 
        = (0x0000003fU & (minimal_node_test__DOT__test_packet_data 
                          >> 0x0eU));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt 
        = (0x0000003fU & (minimal_node_test__DOT__test_packet_data 
                          >> 8U));
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data 
        = (0x000000ffU & minimal_node_test__DOT__test_packet_data);
    minimal_node_test__DOT__timeout_counter = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205A\346\216\245\345\217\243ready\344\277\241\345\217\267...\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    while (((~ ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                   & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)))) 
            & VL_GTS_III(32, 0x00000064U, minimal_node_test__DOT__timeout_counter))) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             220);
        minimal_node_test__DOT__timeout_counter = ((IData)(1U) 
                                                   + minimal_node_test__DOT__timeout_counter);
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, minimal_node_test__DOT__timeout_counter, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\255\211\345\276\205\344\270\255... timeout_counter=%0d, valid=%b, rdy=%b\n",0,
                         32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                         32,minimal_node_test__DOT__timeout_counter,
                         1,(IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld),
                         1,((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)));
            Verilated::runFlushCallbacks();
        }
    }
    if (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
         & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)))) {
        VL_WRITEF_NX("\342\234\223 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: A\346\216\245\345\217\243\346\217\241\346\211\213\346\210\220\345\212\237\357\274\214\346\225\260\346\215\256\345\214\205\350\242\253\346\216\245\346\224\266\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
        Verilated::runFlushCallbacks();
    } else {
        VL_WRITEF_NX("\342\234\227 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: A\346\216\245\345\217\243\346\217\241\346\211\213\350\266\205\346\227\266\357\274\201\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
        Verilated::runFlushCallbacks();
    }
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         235);
    vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\225\260\346\215\256\345\214\205\345\217\221\351\200\201\345\256\214\346\210\220\357\274\214\346\222\244\351\224\200valid\344\277\241\345\217\267\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-003] \350\276\223\345\207\272\351\252\214\350\257\201\346\265\213\350\257\225 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\233\221\346\216\247\350\276\223\345\207\272\347\253\257\345\217\243\346\230\257\345\220\246\346\234\211\346\225\260\346\215\256\350\276\223\345\207\272\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    minimal_node_test__DOT__timeout_counter = 0U;
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \345\274\200\345\247\213\347\233\221\346\216\247\350\276\223\345\207\272...\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    while (((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r)) 
            & VL_GTS_III(32, 0x00000064U, minimal_node_test__DOT__timeout_counter))) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             250);
        minimal_node_test__DOT__timeout_counter = ((IData)(1U) 
                                                   + minimal_node_test__DOT__timeout_counter);
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, minimal_node_test__DOT__timeout_counter, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\233\221\346\216\247\344\270\255... timeout_counter=%0d\n  B\346\216\245\345\217\243: vld=%b, data=0x%x, src=%0#, tgt=%0#\n  N\346\216\245\345\217\243: vld=%b\n  W\346\216\245\345\217\243: vld=%b\n  S\346\216\245\345\217\243: vld=%b\n  E\346\216\245\345\217\243: vld=%b\n",0,
                         32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                         32,minimal_node_test__DOT__timeout_counter,
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
            Verilated::runFlushCallbacks();
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
        Verilated::runFlushCallbacks();
        vlSelfRef.minimal_node_test__DOT__passed_count 
            = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    } else {
        VL_WRITEF_NX("\342\234\227 \346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: B\346\216\245\345\217\243\346\227\240\350\276\223\345\207\272\357\274\214\350\266\205\346\227\266\357\274\201\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter);
        Verilated::runFlushCallbacks();
    }
    minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             279);
        VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \347\273\247\347\273\255\347\233\221\346\216\247 - B:%b N:%b W:%b S:%b E:%b\n",0,
                     32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r),
                     1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r),
                     1,vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r,
                     1,(IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r));
        Verilated::runFlushCallbacks();
        minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (minimal_node_test__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    vlSelfRef.minimal_node_test__DOT__test_count = 
        ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__test_count);
    VL_WRITEF_NX("\n=== [TEST-004] \351\225\277\346\227\266\351\227\264\350\277\220\350\241\214\351\252\214\350\257\201 ===\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \351\252\214\350\257\201\347\234\237\345\256\236\350\212\202\347\202\271\347\232\204\351\225\277\346\234\237\347\250\263\345\256\232\346\200\247\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0x00000014U;
    while (VL_LTS_III(32, 0U, minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3)) {
        co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                             292);
        minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 
            = (minimal_node_test__DOT__unnamedblk1_4__DOT____Vrepeat3 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\227\266\351\222\237\347\250\263\345\256\232\350\277\220\350\241\21420\344\270\252\345\221\250\346\234\237\n\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\265\213\350\257\225\344\277\241\345\217\267\346\223\215\344\275\234\350\203\275\345\212\233\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__pg_en = 1U;
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         298);
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: pg_en\350\256\276\344\270\272%b\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en));
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__pg_node = 0x2aU;
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         302);
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: pg_node\350\256\276\344\270\272%0#\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 6,(IData)(vlSelfRef.minimal_node_test__DOT__pg_node));
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__pg_en = 0U;
    vlSelfRef.minimal_node_test__DOT__pg_node = 0U;
    co_await vlSelfRef.__VtrigSched_h9ff589a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 
                                                         308);
    VL_WRITEF_NX("\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d: \346\201\242\345\244\215\351\273\230\350\256\244\350\256\276\347\275\256 pg_en=%b, pg_node=%0#\n\342\234\223 [TEST-002] \344\273\277\347\234\237\347\216\257\345\242\203\347\250\263\345\256\232\346\200\247\351\252\214\350\257\201\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 1,(IData)(vlSelfRef.minimal_node_test__DOT__pg_en),
                 6,vlSelfRef.minimal_node_test__DOT__pg_node,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    VL_WRITEF_NX("\342\234\223 [TEST-004] \351\225\277\346\227\266\351\227\264\350\277\220\350\241\214\351\252\214\350\257\201\345\256\214\346\210\220 (\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250=%0d)\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter);
    Verilated::runFlushCallbacks();
    vlSelfRef.minimal_node_test__DOT__passed_count 
        = ((IData)(1U) + vlSelfRef.minimal_node_test__DOT__passed_count);
    VL_WRITEF_NX("\n========================================\n\360\237\223\212 \346\265\213\350\257\225\347\273\223\346\236\234\346\212\245\345\221\212\n========================================\n\346\234\200\347\273\210\346\227\266\351\222\237\350\256\241\346\225\260\345\231\250: %0d\n\346\200\273\346\265\213\350\257\225\346\225\260: %0d\n\351\200\232\350\277\207: %0d\n\351\200\232\350\277\207\347\216\207: %0.1f%%\n========================================\n\360\237\216\211 MAZE\350\212\202\347\202\271\347\234\237\345\256\236\345\212\237\350\203\275\351\252\214\350\257\201\346\265\213\350\257\225\345\256\214\346\210\220\357\274\201\n\360\237\223\235 \346\234\254\347\211\210\346\234\254\345\214\205\345\220\253\347\234\237\345\256\236MAZE\350\212\202\347\202\271\346\250\241\345\235\227\345\256\236\344\276\213\345\214\226\n\360\237\224\247 \351\252\214\350\257\201\344\272\206\350\212\202\347\202\271\345\244\215\344\275\215\343\200\201\346\225\260\346\215\256\345\214\205\344\274\240\350\276\223\345\222\214\350\276\223\345\207\272\347\253\257\345\217\243\345\212\237\350\203\275\n========================================\n========================================\n",0,
                 32,vlSelfRef.minimal_node_test__DOT__clk_counter,
                 32,vlSelfRef.minimal_node_test__DOT__test_count,
                 32,vlSelfRef.minimal_node_test__DOT__passed_count,
                 64,((100.0 * VL_ISTOR_D_I(32, vlSelfRef.minimal_node_test__DOT__passed_count)) 
                     / VL_ISTOR_D_I(32, vlSelfRef.minimal_node_test__DOT__test_count)));
    Verilated::runFlushCallbacks();
    VL_FINISH_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 332, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vminimal_node_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vminimal_node_test___024root___eval_triggers__act(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_triggers__act\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vtrigprevexpr_h08905649__0;
    __Vtrigprevexpr_h08905649__0 = 0;
    // Body
    __Vtrigprevexpr_h08905649__0 = (1U & (~ (IData)(vlSelfRef.rst_n)));
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.rst_n) 
                                                        != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                       << 3U) 
                                                      | (((IData)(__Vtrigprevexpr_h08905649__0) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h08905649__1)) 
                                                         << 2U)) 
                                                     | ((((~ (IData)(vlSelfRef.rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
    vlSelfRef.__Vtrigprevexpr_h08905649__1 = __Vtrigprevexpr_h08905649__0;
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
    CData/*5:0*/ minimal_node_test__DOT__dut__DOT__new_tgt;
    minimal_node_test__DOT__dut__DOT__new_tgt = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__tgt_is_pg;
    minimal_node_test__DOT__dut__DOT__tgt_is_pg = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_N;
    minimal_node_test__DOT__dut__DOT__route_req_N = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_S;
    minimal_node_test__DOT__dut__DOT__route_req_S = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_E;
    minimal_node_test__DOT__dut__DOT__route_req_E = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_W;
    minimal_node_test__DOT__dut__DOT__route_req_W = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = 0;
    CData/*1:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type = 0;
    CData/*5:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    minimal_node_test__DOT__dut__DOT__route_req_N = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_S = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_E = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_W = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0U;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
    if (minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr) {
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = 0U;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type));
    } else {
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)));
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                     >> 0x0000000eU));
    }
    if (vlSelfRef.minimal_node_test__DOT__pg_en) {
        minimal_node_test__DOT__dut__DOT__route_req_N 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_N));
        minimal_node_test__DOT__dut__DOT__route_req_S 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_S));
        minimal_node_test__DOT__dut__DOT__route_req_E 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_E));
        minimal_node_test__DOT__dut__DOT__route_req_W 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_W));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A));
        minimal_node_test__DOT__dut__DOT__new_tgt = 
            ((3U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
              ? ((((IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                    ? 0U : (7U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                   >> 3U) + (7U == 
                                             (7U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)))))) 
                  << 3U) | (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
              : ((1U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                  ? ((((IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                        ? 0U : (7U & ((IData)(1U) + 
                                      ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                       >> 3U)))) << 3U) 
                     | (7U & (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)))
                  : ((2U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                      ? ((0x00000038U & (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)) 
                         | (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
                      : (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw))));
    } else {
        minimal_node_test__DOT__dut__DOT__route_req_N = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_S = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_E = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_W = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0x10U;
        minimal_node_test__DOT__dut__DOT__new_tgt = minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
    }
    __Vtableidx6 = ((((3U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                      << 9U) | ((2U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                << 8U)) | (((IData)(minimal_node_test__DOT__dut__DOT__new_tgt) 
                                            << 2U) 
                                           | (((1U 
                                                == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.minimal_node_test__DOT__pg_en))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode 
        = Vminimal_node_test__ConstPool__TABLE_h14c994e7_0
        [__Vtableidx6];
    minimal_node_test__DOT__dut__DOT__tgt_is_pg = ((IData)(minimal_node_test__DOT__dut__DOT__new_tgt) 
                                                   == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(minimal_node_test__DOT__dut__DOT__tgt_is_pg))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(minimal_node_test__DOT__dut__DOT__tgt_is_pg)))));
}

void Vminimal_node_test___024root___eval_act(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_act\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000dULL & vlSelfRef.__VactTriggered
         [0U])) {
        Vminimal_node_test___024root___act_comb__TOP__0(vlSelf);
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
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W;
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S;
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E;
    }
    if (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__) {
        vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B;
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
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_N;
    minimal_node_test__DOT__dut__DOT__arb_qos_N = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_N;
    minimal_node_test__DOT__dut__DOT__arb_gnt_N = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_W;
    minimal_node_test__DOT__dut__DOT__arb_qos_W = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_W;
    minimal_node_test__DOT__dut__DOT__arb_gnt_W = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_S;
    minimal_node_test__DOT__dut__DOT__arb_qos_S = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_S;
    minimal_node_test__DOT__dut__DOT__arb_gnt_S = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_E;
    minimal_node_test__DOT__dut__DOT__arb_qos_E = 0;
    CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_E;
    minimal_node_test__DOT__dut__DOT__arb_gnt_E = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_B;
    minimal_node_test__DOT__dut__DOT__arb_qos_B = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_B;
    minimal_node_test__DOT__dut__DOT__arb_gnt_B = 0;
    CData/*1:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_0;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_0 = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_1;
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_1 = 0;
    IData/*31:0*/ minimal_node_test__DOT__dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0;
    minimal_node_test__DOT__dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0;
    minimal_node_test__DOT__dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0;
    minimal_node_test__DOT__dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0;
    minimal_node_test__DOT__dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 = 0;
    IData/*31:0*/ minimal_node_test__DOT__dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0;
    minimal_node_test__DOT__dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0;
    minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 = 0;
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
    if (vlSelfRef.rst_n) {
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                   ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                  >> 2U))) << 2U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                  >> 3U))) << 3U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                  >> 1U))) << 1U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req)) 
               | (((0x00000010U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                  >> 4U))) << 4U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                   ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                  >> 2U))) << 2U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                  >> 3U))) << 3U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                  >> 1U))) << 1U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
               | (((0x00000010U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                  >> 4U))) << 4U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                   ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                  >> 2U))) << 2U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                  >> 3U))) << 3U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                  >> 1U))) << 1U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req)) 
               | (((0x00000010U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                  >> 4U))) << 4U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1eU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | ((1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                   ? 0U : (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req))));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1bU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                  >> 2U))) << 2U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x17U & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                  >> 3U))) << 3U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x1dU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                  >> 1U))) << 1U));
        __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req 
            = ((0x0fU & (IData)(__Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req)) 
               | (((0x00000010U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr))
                    ? 0U : (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                  >> 4U))) << 4U));
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o;
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o;
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o;
        vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o;
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
                                                         & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr)))))));
    __Vtableidx1 = ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
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
    __Vtableidx2 = ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
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
    __Vtableidx3 = ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
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
    __Vtableidx4 = ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
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
    __Vtableidx5 = ((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
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
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_0 
        = ((2U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
                  >> 0x00000013U)) | (1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                            >> 0x00000014U)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4U] 
        = ((0x007fc000U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                           << 6U)) | (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)));
    minimal_node_test__DOT__dut__DOT__arb_qos_S = (
                                                   (((2U 
                                                      & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                         >> 0x0000000dU)) 
                                                     | (1U 
                                                        & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                           >> 0x00000014U))) 
                                                    << 2U) 
                                                   | ((2U 
                                                       & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                                                          >> 0x00000013U)) 
                                                      | (1U 
                                                         & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o 
                                                            >> 0x00000014U))));
    minimal_node_test__DOT__dut__DOT__arb_qos_E = (
                                                   (((2U 
                                                      & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                         >> 0x0000000dU)) 
                                                     | (1U 
                                                        & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                           >> 0x00000014U))) 
                                                    << 2U) 
                                                   | ((2U 
                                                       & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                                                          >> 0x00000013U)) 
                                                      | (1U 
                                                         & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o 
                                                            >> 0x00000014U))));
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
                                                         & (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                                                            [4U] 
                                                            & ((~ 
                                                                (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode)))) 
                                                               & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy)))))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy));
    minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy));
    minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy));
    minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy));
    minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy));
    minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy)));
    minimal_node_test__DOT__dut__DOT__arb_qos_W = (
                                                   (8U 
                                                    & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                       >> 0x0000000bU)) 
                                                   | ((4U 
                                                       & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                          >> 0x00000012U)) 
                                                      | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_0)));
    minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_1 
        = ((4U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o 
                  >> 0x00000012U)) | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy 
        = ((((4U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)) 
                    << 2U)) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)) 
                                      << 1U)) | (1U 
                                                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r))))) 
            << 2U) | ((2U & ((~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)) 
                             << 1U)) | (1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req 
        = __Vdly__minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__ 
        = ((IData)(minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r));
    minimal_node_test__DOT__dut__DOT__arb_qos_N = (
                                                   (8U 
                                                    & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                       >> 0x0000000bU)) 
                                                   | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_1));
    minimal_node_test__DOT__dut__DOT__arb_qos_B = (
                                                   (0x00000010U 
                                                    & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                       >> 0x0000000aU)) 
                                                   | ((8U 
                                                       & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o 
                                                          >> 0x00000011U)) 
                                                      | (IData)(minimal_node_test__DOT__dut__DOT____VdfgRegularize_hf17376f8_0_1)));
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
    minimal_node_test__DOT__dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    << 1U)) | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                             << 1U)) | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))));
    minimal_node_test__DOT__dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
             | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                         | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                  >> 1U))));
    minimal_node_test__DOT__dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                      >> 2U))));
    minimal_node_test__DOT__dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 
        = ((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                      >> 3U))));
    minimal_node_test__DOT__dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 
        = ((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                              >> 4U))));
    minimal_node_test__DOT__dut__DOT__arb_gnt_N = (0x0000000fU 
                                                   & ((0U 
                                                       != (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_N))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(minimal_node_test__DOT__dut__DOT__arb_qos_N) 
                                                         - (IData)(1U))) 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_N))
                                                       : 
                                                      ((~ 
                                                        (minimal_node_test__DOT__dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0 
                                                         - (IData)(1U))) 
                                                       & minimal_node_test__DOT__dut__DOT__u_arbiter_N__DOT____VdfgRegularize_h9af96af7_0_0)));
    minimal_node_test__DOT__dut__DOT__arb_gnt_W = (0x0000000fU 
                                                   & ((0U 
                                                       != (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_W))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(minimal_node_test__DOT__dut__DOT__arb_qos_W) 
                                                         - (IData)(1U))) 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_W))
                                                       : 
                                                      ((~ 
                                                        (minimal_node_test__DOT__dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0 
                                                         - (IData)(1U))) 
                                                       & minimal_node_test__DOT__dut__DOT__u_arbiter_W__DOT____VdfgRegularize_h9af96af7_0_0)));
    minimal_node_test__DOT__dut__DOT__arb_gnt_S = (0x0000000fU 
                                                   & ((0U 
                                                       != (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_S))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(minimal_node_test__DOT__dut__DOT__arb_qos_S) 
                                                         - (IData)(1U))) 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_S))
                                                       : 
                                                      ((~ 
                                                        (minimal_node_test__DOT__dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0 
                                                         - (IData)(1U))) 
                                                       & minimal_node_test__DOT__dut__DOT__u_arbiter_S__DOT____VdfgRegularize_h9af96af7_0_0)));
    minimal_node_test__DOT__dut__DOT__arb_gnt_E = (0x0000000fU 
                                                   & ((0U 
                                                       != (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_E))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(minimal_node_test__DOT__dut__DOT__arb_qos_E) 
                                                         - (IData)(1U))) 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_E))
                                                       : 
                                                      ((~ 
                                                        (minimal_node_test__DOT__dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0 
                                                         - (IData)(1U))) 
                                                       & minimal_node_test__DOT__dut__DOT__u_arbiter_E__DOT____VdfgRegularize_h9af96af7_0_0)));
    minimal_node_test__DOT__dut__DOT__arb_gnt_B = (0x0000001fU 
                                                   & ((0U 
                                                       != (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_B))
                                                       ? 
                                                      ((~ 
                                                        ((IData)(minimal_node_test__DOT__dut__DOT__arb_qos_B) 
                                                         - (IData)(1U))) 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__arb_qos_B))
                                                       : 
                                                      ((~ 
                                                        (minimal_node_test__DOT__dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0 
                                                         - (IData)(1U))) 
                                                       & minimal_node_test__DOT__dut__DOT__u_arbiter_B__DOT____VdfgRegularize_h0a9aa7c4_0_0)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_N))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_N)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.no_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W 
        = ((8U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [2U] : ((1U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [3U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
            | (0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_W__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r) 
           & ((0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_W)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wo_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S 
        = ((8U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((1U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [3U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
            | (0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_S__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r) 
           & ((0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_S)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.so_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E 
        = ((8U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((4U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((2U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((1U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [2U] : 0U))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
            | (0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_E__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r) 
           & ((0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_E)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.eo_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B 
        = ((0x00000010U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))
            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
           [4U] : ((8U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                   [0U] : ((4U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                           [1U] : ((2U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                                    ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                   [2U] : ((1U & (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))
                                            ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                           [3U] : 0U)))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
            | (0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B))) 
           & (IData)(minimal_node_test__DOT__dut__DOT__irs_output_B__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r) 
           & ((0U != (IData)(minimal_node_test__DOT__dut__DOT__arb_gnt_B)) 
              & ((~ (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_o.pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)))));
}

void Vminimal_node_test___024root___nba_comb__TOP__0(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_comb__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_N;
    minimal_node_test__DOT__dut__DOT__route_req_N = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_S;
    minimal_node_test__DOT__dut__DOT__route_req_S = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_E;
    minimal_node_test__DOT__dut__DOT__route_req_E = 0;
    CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_W;
    minimal_node_test__DOT__dut__DOT__route_req_W = 0;
    // Body
    minimal_node_test__DOT__dut__DOT__route_req_N = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_S = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_E = 0U;
    minimal_node_test__DOT__dut__DOT__route_req_W = 0U;
    vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0U;
    if (vlSelfRef.minimal_node_test__DOT__pg_en) {
        minimal_node_test__DOT__dut__DOT__route_req_N 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_N));
        minimal_node_test__DOT__dut__DOT__route_req_S 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_S));
        minimal_node_test__DOT__dut__DOT__route_req_E 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_E));
        minimal_node_test__DOT__dut__DOT__route_req_W 
            = (0x00000010U | (IData)(minimal_node_test__DOT__dut__DOT__route_req_W));
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A 
            = (0x00000010U | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A));
    } else {
        minimal_node_test__DOT__dut__DOT__route_req_N = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_S = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_E = 0x10U;
        minimal_node_test__DOT__dut__DOT__route_req_W = 0x10U;
        vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A = 0x10U;
    }
}

void Vminimal_node_test___024root___nba_comb__TOP__1(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___nba_comb__TOP__1\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ minimal_node_test__DOT__dut__DOT__new_tgt;
    minimal_node_test__DOT__dut__DOT__new_tgt = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__tgt_is_pg;
    minimal_node_test__DOT__dut__DOT__tgt_is_pg = 0;
    CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = 0;
    CData/*1:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type = 0;
    CData/*5:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw = 0;
    CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr;
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr = 0;
    SData/*9:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr 
        = (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
            & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy)) 
           & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
    if (minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr) {
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x = 0U;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type));
    } else {
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)));
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw 
            = vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered;
        minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type 
            = (3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                     >> 0x0000000eU));
    }
    minimal_node_test__DOT__dut__DOT__new_tgt = ((IData)(vlSelfRef.minimal_node_test__DOT__pg_en)
                                                  ? 
                                                 ((3U 
                                                   == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                   ? 
                                                  ((((IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                                                      ? 0U
                                                      : 
                                                     (7U 
                                                      & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                                          >> 3U) 
                                                         + 
                                                         (7U 
                                                          == 
                                                          (7U 
                                                           & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered)))))) 
                                                    << 3U) 
                                                   | (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
                                                   : 
                                                  ((1U 
                                                    == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                    ? 
                                                   ((((IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                                                       ? 0U
                                                       : 
                                                      (7U 
                                                       & ((IData)(1U) 
                                                          + 
                                                          ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                                           >> 3U)))) 
                                                     << 3U) 
                                                    | (7U 
                                                       & (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)))
                                                    : 
                                                   ((2U 
                                                     == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type))
                                                     ? 
                                                    ((0x00000038U 
                                                      & (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw)) 
                                                     | (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x))
                                                     : (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw))))
                                                  : (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw));
    __Vtableidx6 = ((((3U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                      << 9U) | ((2U == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                << 8U)) | (((IData)(minimal_node_test__DOT__dut__DOT__new_tgt) 
                                            << 2U) 
                                           | (((1U 
                                                == (IData)(minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type)) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.minimal_node_test__DOT__pg_en))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode 
        = Vminimal_node_test__ConstPool__TABLE_h14c994e7_0
        [__Vtableidx6];
    minimal_node_test__DOT__dut__DOT__tgt_is_pg = ((IData)(minimal_node_test__DOT__dut__DOT__new_tgt) 
                                                   == (IData)(vlSelfRef.minimal_node_test__DOT__pg_node));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set 
        = ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld) 
           & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode) 
              | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy)));
    vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req 
        = ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A) 
           & (- (IData)((1U & (~ (IData)(minimal_node_test__DOT__dut__DOT__tgt_is_pg))))));
    vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr 
        = (vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
           [4U] & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                   | (- (IData)((IData)(minimal_node_test__DOT__dut__DOT__tgt_is_pg)))));
}

void Vminimal_node_test___024root___eval_nba(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___eval_nba\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vminimal_node_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vminimal_node_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vminimal_node_test___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vminimal_node_test___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vminimal_node_test___024root___timing_commit(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___timing_commit\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h9ff589a2__0.commit(
                                                   "@(posedge clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h6037169b__0.commit(
                                                   "@( (~ rst_n))");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_ha9dae870__0.commit(
                                                   "@( rst_n)");
    }
}

void Vminimal_node_test___024root___timing_resume(Vminimal_node_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root___timing_resume\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h9ff589a2__0.resume(
                                                   "@(posedge clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6037169b__0.resume(
                                                   "@( (~ rst_n))");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_ha9dae870__0.resume(
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
            VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 7, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vminimal_node_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/node_testbench/minimal_node_test.sv", 7, "", "Active region did not converge after 100 tries");
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
