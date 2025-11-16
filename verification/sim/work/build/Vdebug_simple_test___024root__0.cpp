// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

VL_ATTR_COLD void Vdebug_simple_test___024root___eval_initial__TOP(Vdebug_simple_test___024root* vlSelf);
VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__0(Vdebug_simple_test___024root* vlSelf);
VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__1(Vdebug_simple_test___024root* vlSelf);
VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__2(Vdebug_simple_test___024root* vlSelf);

void Vdebug_simple_test___024root___eval_initial(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_initial\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdebug_simple_test___024root___eval_initial__TOP(vlSelf);
    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__0(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__pkt_type;
    __Vtask_debug_simple_test__DOT__send_packet__0__pkt_type = 0;
    CData/*0:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__pkt_qos;
    __Vtask_debug_simple_test__DOT__send_packet__0__pkt_qos = 0;
    CData/*5:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__src_id;
    __Vtask_debug_simple_test__DOT__send_packet__0__src_id = 0;
    CData/*5:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__tgt_id;
    __Vtask_debug_simple_test__DOT__send_packet__0__tgt_id = 0;
    CData/*7:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__data;
    __Vtask_debug_simple_test__DOT__send_packet__0__data = 0;
    IData/*31:0*/ __Vtask_debug_simple_test__DOT__send_packet__0__timeout;
    __Vtask_debug_simple_test__DOT__send_packet__0__timeout = 0;
    CData/*5:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__1__Vfuncout;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__1__x;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__x = 0;
    IData/*31:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__1__y;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__y = 0;
    CData/*5:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__2__Vfuncout;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__2__x;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__x = 0;
    IData/*31:0*/ __Vfunc_debug_simple_test__DOT__calc_node_id__2__y;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__y = 0;
    // Body
    VL_WRITEF_NX("==============================================\nMAZE\350\212\202\347\202\271A\347\253\257\345\217\243IRS_N\350\260\203\350\257\225\346\265\213\350\257\225\n\346\265\213\350\257\225\350\212\202\347\202\271: (3, 3)\n==============================================\n",0);
    vlSelfRef.debug_simple_test__DOT__clk = 0U;
    vlSelfRef.debug_simple_test__DOT__rst_n = 0U;
    vlSelfRef.debug_simple_test__DOT__pg_en = 0U;
    vlSelfRef.debug_simple_test__DOT__pg_node = 0U;
    vlSelfRef.debug_simple_test__DOT__test_cycle = 0U;
    vlSelfRef.debug_simple_test__DOT__error_count = 0U;
    vlSelfRef.debug_simple_test__DOT__test_count = 0U;
    vlSelfRef.debug_simple_test__DOT__pass_count = 0U;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_rdy = 1U;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_rdy = 1U;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_rdy = 1U;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_rdy = 1U;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_rdy = 1U;
    co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge debug_simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                         414);
    co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge debug_simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                         415);
    vlSelfRef.debug_simple_test__DOT__rst_n = 1U;
    co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge debug_simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                         417);
    co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge debug_simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                         418);
    VL_WRITEF_NX("\345\244\215\344\275\215\345\256\214\346\210\220\357\274\214\345\274\200\345\247\213\350\260\203\350\257\225\346\265\213\350\257\225...\n\n=== \345\217\221\351\200\201\344\270\234\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225\346\225\260\346\215\256\345\214\205 ===\n",0);
    __Vtask_debug_simple_test__DOT__send_packet__0__data = 0xa5U;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__y = 3U;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__x = 4U;
    __Vfunc_debug_simple_test__DOT__calc_node_id__1__Vfuncout 
        = ((0x00000038U & (__Vfunc_debug_simple_test__DOT__calc_node_id__1__y 
                           << 3U)) | (7U & __Vfunc_debug_simple_test__DOT__calc_node_id__1__x));
    __Vtask_debug_simple_test__DOT__send_packet__0__tgt_id 
        = __Vfunc_debug_simple_test__DOT__calc_node_id__1__Vfuncout;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__y = 3U;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__x = 3U;
    __Vfunc_debug_simple_test__DOT__calc_node_id__2__Vfuncout 
        = ((0x00000038U & (__Vfunc_debug_simple_test__DOT__calc_node_id__2__y 
                           << 3U)) | (7U & __Vfunc_debug_simple_test__DOT__calc_node_id__2__x));
    __Vtask_debug_simple_test__DOT__send_packet__0__src_id 
        = __Vfunc_debug_simple_test__DOT__calc_node_id__2__Vfuncout;
    __Vtask_debug_simple_test__DOT__send_packet__0__pkt_qos = 0U;
    __Vtask_debug_simple_test__DOT__send_packet__0__pkt_type = 0U;
    __Vtask_debug_simple_test__DOT__send_packet__0__timeout = 0;
    VL_WRITEF_NX("--- \345\217\221\351\200\201\346\225\260\346\215\256\345\214\205 ---\n\345\217\221\351\200\201: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 2,__Vtask_debug_simple_test__DOT__send_packet__0__pkt_type,
                 1,(IData)(__Vtask_debug_simple_test__DOT__send_packet__0__pkt_qos),
                 6,__Vtask_debug_simple_test__DOT__send_packet__0__src_id,
                 6,(IData)(__Vtask_debug_simple_test__DOT__send_packet__0__tgt_id),
                 8,__Vtask_debug_simple_test__DOT__send_packet__0__data);
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_type 
        = __Vtask_debug_simple_test__DOT__send_packet__0__pkt_type;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_qos 
        = __Vtask_debug_simple_test__DOT__send_packet__0__pkt_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_src 
        = __Vtask_debug_simple_test__DOT__send_packet__0__src_id;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_tgt 
        = __Vtask_debug_simple_test__DOT__send_packet__0__tgt_id;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_data 
        = __Vtask_debug_simple_test__DOT__send_packet__0__data;
    __Vtask_debug_simple_test__DOT__send_packet__0__timeout = 0x00000064U;
    while (((~ (IData)(vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_rdy)) 
            & VL_LTS_III(32, 0U, __Vtask_debug_simple_test__DOT__send_packet__0__timeout))) {
        co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge debug_simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                             373);
        __Vtask_debug_simple_test__DOT__send_packet__0__timeout 
            = (__Vtask_debug_simple_test__DOT__send_packet__0__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_debug_simple_test__DOT__send_packet__0__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.debug_simple_test__DOT__error_count 
            = ((IData)(1U) + vlSelfRef.debug_simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge debug_simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                         383);
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("=== \350\247\202\345\257\237\350\212\202\347\202\271\350\241\214\344\270\272 ===\n",0);
    vlSelfRef.debug_simple_test__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000014U, vlSelfRef.debug_simple_test__DOT__unnamedblk1__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_hdf3acb90__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge debug_simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                                             430);
        vlSelfRef.debug_simple_test__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.debug_simple_test__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF_NX("\n==============================================\n\350\260\203\350\257\225\346\265\213\350\257\225\345\256\214\346\210\220\n==============================================\n\350\247\202\345\257\237\345\221\250\346\234\237\346\225\260: %0d\n\351\224\231\350\257\257\350\256\241\346\225\260: %0d\n",0,
                 32,vlSelfRef.debug_simple_test__DOT__debug_cycle,
                 32,vlSelfRef.debug_simple_test__DOT__error_count);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                         nullptr, "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                         441);
    VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 442, "");
}

VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__1(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x00000000001e8480ULL, 
                                         nullptr, "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                         447);
    VL_WRITEF_NX("ERROR: \346\265\213\350\257\225\350\266\205\346\227\266\357\274\201\n",0);
    VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 449, "");
}

VlCoroutine Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__2(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 
                                             277);
        vlSelfRef.debug_simple_test__DOT__clk = (1U 
                                                 & (~ (IData)(vlSelfRef.debug_simple_test__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdebug_simple_test___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vdebug_simple_test___024root___eval_triggers__ico(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_triggers__ico\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdebug_simple_test___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vdebug_simple_test___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___trigger_anySet__ico\n"); );
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

void Vdebug_simple_test___024root___ico_sequent__TOP__0(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___ico_sequent__TOP__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ni_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wi_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_si_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_ei_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_ready;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_ready;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_ready;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_ready;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_ready;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y 
        = (7U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node) 
                 >> 3U));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x 
        = (7U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_o;
    __VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y));
    __VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x) 
                                      < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x));
    __VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en)
            ? (((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                & (IData)(__VdfgRegularize_h6e95ff9d_0_1))
                ? 0U : (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y) 
                         > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y))
                         ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                             ? 8U : ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                      ? 1U : 2U)) : 
                        ((IData)(__VdfgRegularize_h6e95ff9d_0_2)
                          ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                              ? 7U : 3U) : ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                                             ? 6U : 
                                            ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                              ? 5U : 4U)))))
            : 0U);
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route = 1U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route = 0U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route = 1U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route = 0U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_out;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_out;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_out;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_out;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_out;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0 
        = ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
                  >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
                                   >> 8U)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S 
        = ((((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                    >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                     >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
                                      >> 8U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E 
        = ((((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                    >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                     >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
                                      >> 8U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                  >> 5U)) | ((4U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                    >> 6U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1 
        = ((4U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                  >> 6U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W 
        = ((((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
             | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                         | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                  >> 1U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                      >> 2U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                      >> 3U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B 
        = ((((4U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                              >> 4U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                  >> 5U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                           >> 4U)) | ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                             >> 5U)) 
                                      | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt 
        = (0x0000001fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B 
        = ((0x00000010U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                            : 0U)))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___ico_sequent__TOP__1(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___ico_sequent__TOP__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__pkt_con_ni_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wi_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_si_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_ei_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_type;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_src;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test_pkt_in___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf);
void Vdebug_simple_test_pkt_con_if___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_out___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf);

void Vdebug_simple_test___024root___eval_ico(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_ico\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vdebug_simple_test___024root___ico_sequent__TOP__0(vlSelf);
        Vdebug_simple_test_pkt_in___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i));
        Vdebug_simple_test_pkt_con_if___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test_pkt_out___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o));
        Vdebug_simple_test___024root___ico_sequent__TOP__1(vlSelf);
    }
}

bool Vdebug_simple_test___024root___eval_phase__ico(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_phase__ico\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdebug_simple_test___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vdebug_simple_test___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vdebug_simple_test___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdebug_simple_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vdebug_simple_test___024root___eval_triggers__act(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_triggers__act\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 6U) 
                                                        | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                            << 5U) 
                                                           | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                              << 4U))) 
                                                       | (((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                              << 2U)) 
                                                          | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0)))))) 
                                                      << 0x00000010U) 
                                                     | ((((((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))))) 
                                                          << 0x0000000cU) 
                                                         | ((((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))))) 
                                                            << 8U)) 
                                                        | (((((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))))) 
                                                            << 4U) 
                                                           | (((((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0)) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0))) 
                                                                  << 2U)) 
                                                              | ((((~ (IData)(vlSelfRef.debug_simple_test__DOT__rst_n)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__rst_n__0)) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.debug_simple_test__DOT__clk) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__clk__0))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n__0 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdebug_simple_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vdebug_simple_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___trigger_anySet__act\n"); );
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

void Vdebug_simple_test___024root___act_comb__TOP__0(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___act_comb__TOP__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y 
        = (7U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node) 
                 >> 3U));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x 
        = (7U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clk 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clk;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__rst_n;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__rst_n;
    __VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y));
    __VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x) 
                                      < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x));
    __VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en)
            ? (((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                & (IData)(__VdfgRegularize_h6e95ff9d_0_1))
                ? 0U : (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y) 
                         > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y))
                         ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                             ? 8U : ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                      ? 1U : 2U)) : 
                        ((IData)(__VdfgRegularize_h6e95ff9d_0_2)
                          ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                              ? 7U : 3U) : ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                                             ? 6U : 
                                            ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                              ? 5U : 4U)))))
            : 0U);
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W 
        = ((((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
             | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                         | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                  >> 1U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                      >> 2U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                      >> 3U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B 
        = ((((4U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                              >> 4U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt 
        = (0x0000001fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B 
        = ((0x00000010U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                            : 0U)))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___act_comb__TOP__1(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___act_comb__TOP__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test_pkt_in___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf);
void Vdebug_simple_test_pkt_out___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf);
void Vdebug_simple_test_pkt_con_if___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf);

void Vdebug_simple_test___024root___eval_act(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_act\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000400001ULL & vlSelfRef.__VactTriggered
         [0U])) {
        Vdebug_simple_test___024root___act_comb__TOP__0(vlSelf);
        Vdebug_simple_test_pkt_in___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i));
        Vdebug_simple_test_pkt_out___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o));
        Vdebug_simple_test_pkt_con_if___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___act_comb__TOP__1(vlSelf);
    }
}

void Vdebug_simple_test___024root___nba_sequent__TOP__0(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__debug_simple_test__DOT__test_cycle;
    __Vdly__debug_simple_test__DOT__test_cycle = 0;
    // Body
    if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__rst_n))) {
        VL_WRITEF_NX("==========================================\n[Cycle %0d] \350\257\246\347\273\206\347\212\266\346\200\201\347\233\221\346\216\247\n==========================================\nA\347\253\257\345\217\243\350\276\223\345\205\245: vld=%1#, rdy=%1#\n",0,
                     32,vlSelfRef.debug_simple_test__DOT__debug_cycle,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld),
                     1,vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_rdy);
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld))) {
            VL_WRITEF_NX("  \350\276\223\345\205\245\346\225\260\346\215\256\345\214\205: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_data);
        }
        VL_WRITEF_NX("\350\276\223\345\207\272\347\253\257\345\217\243\347\212\266\346\200\201:\n  Local: vld=%1#, rdy=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_vld,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_rdy));
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_vld))) {
            VL_WRITEF_NX("    \346\225\260\346\215\256: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_data);
        }
        VL_WRITEF_NX("  North: vld=%1#, rdy=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_no_vld,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_no_rdy));
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_con_no_vld))) {
            VL_WRITEF_NX("    \346\225\260\346\215\256: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_con_no_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_no_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_con_no_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_no_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_con_no_data);
        }
        VL_WRITEF_NX("  West: vld=%1#, rdy=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_wo_vld,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_wo_rdy));
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_con_wo_vld))) {
            VL_WRITEF_NX("    \346\225\260\346\215\256: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_con_wo_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_wo_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_con_wo_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_wo_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_con_wo_data);
        }
        VL_WRITEF_NX("  South: vld=%1#, rdy=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_so_vld,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_so_rdy));
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_con_so_vld))) {
            VL_WRITEF_NX("    \346\225\260\346\215\256: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_con_so_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_so_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_con_so_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_so_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_con_so_data);
        }
        VL_WRITEF_NX("  East: vld=%1#, rdy=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_eo_vld,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_eo_rdy));
        if (VL_UNLIKELY((vlSelfRef.debug_simple_test__DOT__pkt_con_eo_vld))) {
            VL_WRITEF_NX("    \346\225\260\346\215\256: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                         2,vlSelfRef.debug_simple_test__DOT__pkt_con_eo_type,
                         1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_eo_qos),
                         6,vlSelfRef.debug_simple_test__DOT__pkt_con_eo_src,
                         6,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_eo_tgt),
                         8,vlSelfRef.debug_simple_test__DOT__pkt_con_eo_data);
        }
        VL_WRITEF_NX("C\346\216\245\345\217\243\350\276\223\345\205\245\345\260\261\347\273\252\347\212\266\346\200\201: NI=%1#, WI=%1#, SI=%1#, EI=%1#\n",0,
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_ni_rdy,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_wi_rdy),
                     1,vlSelfRef.debug_simple_test__DOT__pkt_con_si_rdy,
                     1,(IData)(vlSelfRef.debug_simple_test__DOT__pkt_con_ei_rdy));
    } else {
        VL_WRITEF_NX("[Cycle %0d] \345\244\215\344\275\215\344\270\255...\n",0,
                     32,vlSelfRef.debug_simple_test__DOT__debug_cycle);
    }
    if (vlSelfRef.debug_simple_test__DOT__rst_n) {
        __Vdly__debug_simple_test__DOT__test_cycle 
            = ((IData)(1U) + vlSelfRef.debug_simple_test__DOT__test_cycle);
        vlSelfRef.debug_simple_test__DOT__debug_cycle 
            = ((IData)(1U) + vlSelfRef.debug_simple_test__DOT__debug_cycle);
    } else {
        __Vdly__debug_simple_test__DOT__test_cycle = 0U;
        vlSelfRef.debug_simple_test__DOT__debug_cycle = 0U;
    }
    vlSelfRef.debug_simple_test__DOT__test_cycle = __Vdly__debug_simple_test__DOT__test_cycle;
}

void Vdebug_simple_test___024root___nba_comb__TOP__0(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_type 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_qos 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_src 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_tgt 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_data 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_data;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_vld 
        = vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_rdy 
        = vlSelfRef.debug_simple_test__DOT__pkt_con_eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_en;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pg_node;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y 
        = (7U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node) 
                 >> 3U));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x 
        = (7U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_node));
    __VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y));
    __VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x) 
                                      < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x));
    __VdfgRegularize_h6e95ff9d_0_1 = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_x) 
                                      == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_x));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos 
        = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pg_en)
            ? (((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                & (IData)(__VdfgRegularize_h6e95ff9d_0_1))
                ? 0U : (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__local_y) 
                         > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_y))
                         ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                             ? 8U : ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                      ? 1U : 2U)) : 
                        ((IData)(__VdfgRegularize_h6e95ff9d_0_2)
                          ? ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                              ? 7U : 3U) : ((IData)(__VdfgRegularize_h6e95ff9d_0_0)
                                             ? 6U : 
                                            ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                              ? 5U : 4U)))))
            : 0U);
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
}

void Vdebug_simple_test___024root___nba_comb__TOP__1(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_i 
        = ((((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_type) 
             << 0x00000015U) | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_tgt) 
               << 8U) | (IData)(vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_data)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_vld;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_rdy;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_i;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__6(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__6\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__7(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__7\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_data;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__8(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__8\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__9(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__9\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_data;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__10(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__10\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__11(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__11\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_data;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__12(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__12\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__13(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__13\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_data;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_type;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_src;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_data;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__14(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__14\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__15(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__15\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_type 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_type;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_qos 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_qos;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_src 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_src;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_tgt 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_tgt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_data 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_data;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_type 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_type;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_qos;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_src 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_src;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_tgt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_tgt;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_data 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_data;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__21(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__21\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_out;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__22(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__22\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_out;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__23(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__23\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_out;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__24(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__24\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_out;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__25(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__25\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i);
    }
    if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set))) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_i;
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_pkt 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_pkt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_out 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_out;
}

extern const VlUnpacked<CData/*1:0*/, 32> Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vdebug_simple_test__ConstPool__TABLE_h334335e5_0;

void Vdebug_simple_test___024root___nba_sequent__TOP__26(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__26\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    __Vtableidx6 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx6])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx6];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx6])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx6];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__27(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__27\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.no_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_no_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_vld;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__28(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__28\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    // Body
    __Vtableidx7 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx7])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx7];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx7])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx7];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__29(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__29\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wo_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wo_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_vld;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__30(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__30\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    // Body
    __Vtableidx8 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx8])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx8];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx8])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx8];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__31(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__31\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.so_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_so_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_vld;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__32(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__32\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    // Body
    __Vtableidx9 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx9])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx9];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx9])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx9];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__33(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__33\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.eo_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_con_eo_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_vld;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__34(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__34\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx10;
    __Vtableidx10 = 0;
    // Body
    __Vtableidx10 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                      << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                 << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx10])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx10];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx10])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx10];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_ready 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_o;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__35(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__35\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_vld 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o.pkt_out_vld;
    vlSelfRef.debug_simple_test__DOT__pkt_o_pkt_out_vld 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_vld;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__36(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__36\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx2 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx2])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx2];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx2])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx2];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_in;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__37(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__37\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ni_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_ni_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_rdy;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__38(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__38\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx3 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx3])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx3];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx3])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx3];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__39(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__39\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.wi_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_wi_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_rdy;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__40(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__40\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    __Vtableidx4 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx4])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx4];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx4])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx4];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__41(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__41\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.si_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_si_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_rdy;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__42(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__42\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    __Vtableidx5 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx5])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx5];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx5])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx5];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__43(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__43\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con.ei_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_con_ei_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_rdy;
}

void Vdebug_simple_test___024root___nba_comb__TOP__2(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__2\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0 
        = ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
                  >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
                                   >> 8U)));
}

void Vdebug_simple_test___024root___nba_sequent__TOP__44(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__44\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr) 
                     << 3U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set) 
                                << 1U) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__rst_n)));
    if ((1U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx1])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vdebug_simple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx1];
    }
    if ((2U & Vdebug_simple_test__ConstPool__TABLE_h1cad8683_0
         [__Vtableidx1])) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vdebug_simple_test__ConstPool__TABLE_h334335e5_0
            [__Vtableidx1];
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o 
        = (1U & (~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__ready_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_o 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__valid_irs_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_valid 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid_o;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_in 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__a_in_valid;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_in;
}

void Vdebug_simple_test___024root___nba_sequent__TOP__45(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_sequent__TOP__45\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_rdy 
        = vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i.pkt_in_rdy;
    vlSelfRef.debug_simple_test__DOT__pkt_i_pkt_in_rdy 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_rdy;
}

void Vdebug_simple_test___024root___nba_comb__TOP__3(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__3\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S 
        = ((((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                    >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                     >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E 
                                      >> 8U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S;
}

void Vdebug_simple_test___024root___nba_comb__TOP__4(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__4\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E 
        = ((((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                    >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                     >> 8U))) << 2U) 
           | ((2U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                     >> 7U)) | (1U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S 
                                      >> 8U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E;
}

void Vdebug_simple_test___024root___nba_comb__TOP__5(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__5\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__6(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__6\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__7(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__7\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__8(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__8\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__9(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__9\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0) 
             & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)) 
            << 1U) | ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__10(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__10\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
}

void Vdebug_simple_test___024root___nba_comb__TOP__11(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__11\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
}

void Vdebug_simple_test___024root___nba_comb__TOP__12(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__12\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
}

void Vdebug_simple_test___024root___nba_comb__TOP__13(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__13\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
}

void Vdebug_simple_test___024root___nba_comb__TOP__14(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__14\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                  >> 5U)) | ((4U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                    >> 6U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W;
}

void Vdebug_simple_test___024root___nba_comb__TOP__15(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__15\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1 
        = ((4U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W 
                  >> 6U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_0));
}

void Vdebug_simple_test___024root___nba_comb__TOP__16(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__16\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__17(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__17\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_in) {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 9U));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y 
            = (7U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 0x0cU));
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type 
            = (3U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_in 
                     >> 0x15U));
    } else {
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
}

void Vdebug_simple_test___024root___nba_comb__TOP__18(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__18\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__route_req;
}

void Vdebug_simple_test___024root___nba_comb__TOP__19(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__19\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__route_req;
}

void Vdebug_simple_test___024root___nba_comb__TOP__20(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__20\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__route_req;
}

void Vdebug_simple_test___024root___nba_comb__TOP__21(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__21\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__route_req;
}

void Vdebug_simple_test___024root___nba_comb__TOP__22(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__22\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                  >> 5U)) | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N;
}

void Vdebug_simple_test___024root___nba_comb__TOP__23(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__23\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A 
                           >> 4U)) | ((8U & (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N 
                                             >> 5U)) 
                                      | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_1)));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B;
}

void Vdebug_simple_test___024root___nba_comb__TOP__24(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__24\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req = 0U;
    if (vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__valid_route) {
        if ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type))) {
            if ((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
                vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                    = (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
            }
        } else if (((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x)) 
                    & (3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y)))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((3U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((7U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))
                        ? (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                        : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)))
                    : (2U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U < (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((1U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (8U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (2U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (1U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        } else if ((3U > (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = ((((5U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)) 
                     || (6U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register))) 
                    || (4U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__fault_register)))
                    ? (8U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))
                    : (4U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req)));
        }
        if ((0U == (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req))) {
            vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req 
                = (0x00000010U | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req));
        }
    }
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__route_req;
}

void Vdebug_simple_test___024root___nba_comb__TOP__25(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__25\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             << 1U)) | (1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_N__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_N));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_N;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___nba_comb__TOP__26(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__26\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W 
        = ((((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
             | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                      >> 1U))) << 2U) | ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                         | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                  >> 1U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_W__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_W));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_W;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___nba_comb__TOP__27(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__27\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 2U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 1U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                      >> 2U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_S__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_S));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_S;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___nba_comb__TOP__28(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__28\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E 
        = ((((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                     >> 3U))) << 2U) 
           | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                     >> 2U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                      >> 3U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt 
        = (0x0000000fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_E__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E 
        = ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : 0U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_E));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_E;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___nba_comb__TOP__29(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__29\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B 
        = ((((4U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                    >> 2U)) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                      >> 3U)) | (1U 
                                                 & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                    >> 4U)))) 
            << 2U) | ((2U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                             >> 3U)) | (1U & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                              >> 4U))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt 
        = (0x0000001fU & ((0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           ? ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__qos))
                           : ((~ ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req) 
                                  - (IData)(1U))) & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__req))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__u_arbiter_B__DOT__gnt;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B 
        = ((0x00000010U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_A
            : ((8U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_N
                : ((4U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                    ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_W
                    : ((2U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                        ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_S
                        : ((1U & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B))
                            ? vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__route_pkt_E
                            : 0U)))));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i 
        = (0U != (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__arb_gnt_B));
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__pkt_B;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid_i;
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i 
        = vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__valid_irs_i;
}

void Vdebug_simple_test___024root___nba_comb__TOP__30(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__30\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__31(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__31\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__32(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__32\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__33(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__33\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test___024root___nba_comb__TOP__34(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___nba_comb__TOP__34\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set 
        = ((((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
             & ((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i) 
                & ((~ (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_i)) 
                   & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__ready_o)))) 
            << 1U) | (((IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                       | (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid_i)) 
                      & (IData)(vlSelfRef.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0)));
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__1(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__2(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__3(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__4(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__5(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__6(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__7(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__1(Vdebug_simple_test_pkt_out* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__8(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__9(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__10(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__11(Vdebug_simple_test_pkt_con_if* vlSelf);
void Vdebug_simple_test_pkt_in___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf);

void Vdebug_simple_test___024root___eval_nba(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_nba\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000400001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__0(vlSelf);
        Vdebug_simple_test_pkt_in___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i));
        Vdebug_simple_test_pkt_out___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o));
        Vdebug_simple_test_pkt_con_if___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__6(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__8(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__1((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__10(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__2((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__12(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__3((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__14(vlSelf);
        Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o));
        Vdebug_simple_test___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__22(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__23(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__24(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__26(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__4((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__27(vlSelf);
    }
    if ((0x000000000000c000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__28(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__5((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__29(vlSelf);
    }
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__30(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__6((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__31(vlSelf);
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__32(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__7((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__33(vlSelf);
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__34(vlSelf);
        Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__1((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o));
        Vdebug_simple_test___024root___nba_sequent__TOP__35(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__36(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__8((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__37(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__38(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__9((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__39(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__40(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__10((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__41(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__42(vlSelf);
        Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__11((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con));
        Vdebug_simple_test___024root___nba_sequent__TOP__43(vlSelf);
    }
    if ((0x0000000000000500ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_sequent__TOP__44(vlSelf);
        Vdebug_simple_test_pkt_in___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0((&vlSymsp->TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i));
        Vdebug_simple_test___024root___nba_sequent__TOP__45(vlSelf);
    }
    if ((0x0000000000000454ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x0000000000000154ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x0000000000403001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x000000000040c001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x0000000000430001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x00000000004c0001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x0000000000700001ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__9(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__10(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__11(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__12(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__13(vlSelf);
    }
    if ((0x0000000000000514ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__14(vlSelf);
    }
    if ((0x0000000000000540ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__15(vlSelf);
    }
    if ((0x000000000040000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__16(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__17(vlSelf);
    }
    if ((0x0000000000400031ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__18(vlSelf);
    }
    if ((0x00000000004000c1ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__19(vlSelf);
    }
    if ((0x0000000000400301ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__20(vlSelf);
    }
    if ((0x0000000000400c01ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__21(vlSelf);
    }
    if ((0x0000000000000544ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__22(vlSelf);
    }
    if ((0x0000000000000554ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__23(vlSelf);
    }
    if ((0x000000000040000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__24(vlSelf);
    }
    if ((0x0000000000400fcdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__25(vlSelf);
    }
    if ((0x0000000000400f3dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__26(vlSelf);
    }
    if ((0x0000000000400cfdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__27(vlSelf);
    }
    if ((0x00000000004003fdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__28(vlSelf);
    }
    if ((0x0000000000400ffdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__29(vlSelf);
    }
    if ((0x0000000000403fcdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__30(vlSelf);
    }
    if ((0x000000000040cf3dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__31(vlSelf);
    }
    if ((0x0000000000430cfdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__32(vlSelf);
    }
    if ((0x00000000004c03fdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__33(vlSelf);
    }
    if ((0x0000000000700ffdULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vdebug_simple_test___024root___nba_comb__TOP__34(vlSelf);
    }
}

void Vdebug_simple_test___024root___timing_commit(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___timing_commit\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_hdf3acb90__0.commit(
                                                   "@(posedge debug_simple_test.clk)");
    }
}

void Vdebug_simple_test___024root___timing_resume(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___timing_resume\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hdf3acb90__0.resume(
                                                   "@(posedge debug_simple_test.clk)");
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered
         [0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vdebug_simple_test___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vdebug_simple_test___024root___eval_phase__act(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_phase__act\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vdebug_simple_test___024root___eval_triggers__act(vlSelf);
    Vdebug_simple_test___024root___timing_commit(vlSelf);
    Vdebug_simple_test___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vdebug_simple_test___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vdebug_simple_test___024root___timing_resume(vlSelf);
        Vdebug_simple_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vdebug_simple_test___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vdebug_simple_test___024root___eval_phase__nba(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_phase__nba\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vdebug_simple_test___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vdebug_simple_test___024root___eval_nba(vlSelf);
        Vdebug_simple_test___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vdebug_simple_test___024root___eval(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vdebug_simple_test___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 15, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vdebug_simple_test___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdebug_simple_test___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 15, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdebug_simple_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/debug_simple_test.sv", 15, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vdebug_simple_test___024root___eval_phase__act(vlSelf));
    } while (Vdebug_simple_test___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vdebug_simple_test___024root___eval_debug_assertions(Vdebug_simple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdebug_simple_test___024root___eval_debug_assertions\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
