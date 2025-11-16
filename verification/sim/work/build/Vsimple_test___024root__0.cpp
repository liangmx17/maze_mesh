// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple_test.h for the primary calling header

#include "Vsimple_test__pch.h"

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__0(Vsimple_test___024root* vlSelf);
VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__1(Vsimple_test___024root* vlSelf);
VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__2(Vsimple_test___024root* vlSelf);

void Vsimple_test___024root___eval_initial(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vsimple_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsimple_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vsimple_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__0(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__13__pkt_type;
    __Vtask_simple_test__DOT__send_packet__13__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__13__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__13__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__13__src_id;
    __Vtask_simple_test__DOT__send_packet__13__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__13__tgt_id;
    __Vtask_simple_test__DOT__send_packet__13__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__13__data;
    __Vtask_simple_test__DOT__send_packet__13__data = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__13__timeout;
    __Vtask_simple_test__DOT__send_packet__13__timeout = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__13__wait_cycles;
    __Vtask_simple_test__DOT__send_packet__13__wait_cycles = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__14__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__14__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__14__x;
    __Vfunc_simple_test__DOT__calc_node_id__14__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__14__y;
    __Vfunc_simple_test__DOT__calc_node_id__14__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__x;
    __Vfunc_simple_test__DOT__calc_node_id__15__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__y;
    __Vfunc_simple_test__DOT__calc_node_id__15__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__16__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__16__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__16__expected_port;
    __Vtask_simple_test__DOT__verify_output__16__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__16__timeout;
    __Vtask_simple_test__DOT__verify_output__16__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__16__match_found;
    __Vtask_simple_test__DOT__verify_output__16__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__17__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__17__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__17__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__17__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__17__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__17__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__17__src_id;
    __Vfunc_simple_test__DOT__encode_packet__17__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__17__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__17__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__17__data;
    __Vfunc_simple_test__DOT__encode_packet__17__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__18__x;
    __Vfunc_simple_test__DOT__calc_node_id__18__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__18__y;
    __Vfunc_simple_test__DOT__calc_node_id__18__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__19__x;
    __Vfunc_simple_test__DOT__calc_node_id__19__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__19__y;
    __Vfunc_simple_test__DOT__calc_node_id__19__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__20__pkt_type;
    __Vtask_simple_test__DOT__send_packet__20__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__20__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__20__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__20__src_id;
    __Vtask_simple_test__DOT__send_packet__20__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__20__tgt_id;
    __Vtask_simple_test__DOT__send_packet__20__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__20__data;
    __Vtask_simple_test__DOT__send_packet__20__data = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__20__timeout;
    __Vtask_simple_test__DOT__send_packet__20__timeout = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__20__wait_cycles;
    __Vtask_simple_test__DOT__send_packet__20__wait_cycles = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__21__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__21__x;
    __Vfunc_simple_test__DOT__calc_node_id__21__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__21__y;
    __Vfunc_simple_test__DOT__calc_node_id__21__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__x;
    __Vfunc_simple_test__DOT__calc_node_id__22__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__y;
    __Vfunc_simple_test__DOT__calc_node_id__22__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__23__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__23__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__23__expected_port;
    __Vtask_simple_test__DOT__verify_output__23__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__23__timeout;
    __Vtask_simple_test__DOT__verify_output__23__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__23__match_found;
    __Vtask_simple_test__DOT__verify_output__23__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__24__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__24__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__24__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__24__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__24__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__24__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__24__src_id;
    __Vfunc_simple_test__DOT__encode_packet__24__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__24__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__24__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__24__data;
    __Vfunc_simple_test__DOT__encode_packet__24__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__25__x;
    __Vfunc_simple_test__DOT__calc_node_id__25__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__25__y;
    __Vfunc_simple_test__DOT__calc_node_id__25__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__26__x;
    __Vfunc_simple_test__DOT__calc_node_id__26__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__26__y;
    __Vfunc_simple_test__DOT__calc_node_id__26__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__27__pkt_type;
    __Vtask_simple_test__DOT__send_packet__27__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__27__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__27__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__27__src_id;
    __Vtask_simple_test__DOT__send_packet__27__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__27__tgt_id;
    __Vtask_simple_test__DOT__send_packet__27__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__27__data;
    __Vtask_simple_test__DOT__send_packet__27__data = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__27__timeout;
    __Vtask_simple_test__DOT__send_packet__27__timeout = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__27__wait_cycles;
    __Vtask_simple_test__DOT__send_packet__27__wait_cycles = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__28__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__28__x;
    __Vfunc_simple_test__DOT__calc_node_id__28__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__28__y;
    __Vfunc_simple_test__DOT__calc_node_id__28__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__x;
    __Vfunc_simple_test__DOT__calc_node_id__29__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__y;
    __Vfunc_simple_test__DOT__calc_node_id__29__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__30__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__30__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__30__expected_port;
    __Vtask_simple_test__DOT__verify_output__30__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__30__timeout;
    __Vtask_simple_test__DOT__verify_output__30__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__30__match_found;
    __Vtask_simple_test__DOT__verify_output__30__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__31__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__31__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__31__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__31__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__31__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__31__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__31__src_id;
    __Vfunc_simple_test__DOT__encode_packet__31__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__31__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__31__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__31__data;
    __Vfunc_simple_test__DOT__encode_packet__31__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__32__x;
    __Vfunc_simple_test__DOT__calc_node_id__32__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__32__y;
    __Vfunc_simple_test__DOT__calc_node_id__32__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__33__x;
    __Vfunc_simple_test__DOT__calc_node_id__33__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__33__y;
    __Vfunc_simple_test__DOT__calc_node_id__33__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__34__pkt_type;
    __Vtask_simple_test__DOT__send_packet__34__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__34__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__34__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__34__src_id;
    __Vtask_simple_test__DOT__send_packet__34__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__34__tgt_id;
    __Vtask_simple_test__DOT__send_packet__34__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__34__data;
    __Vtask_simple_test__DOT__send_packet__34__data = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__34__timeout;
    __Vtask_simple_test__DOT__send_packet__34__timeout = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__34__wait_cycles;
    __Vtask_simple_test__DOT__send_packet__34__wait_cycles = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__35__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__35__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__35__x;
    __Vfunc_simple_test__DOT__calc_node_id__35__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__35__y;
    __Vfunc_simple_test__DOT__calc_node_id__35__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__x;
    __Vfunc_simple_test__DOT__calc_node_id__36__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__y;
    __Vfunc_simple_test__DOT__calc_node_id__36__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__37__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__37__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__37__expected_port;
    __Vtask_simple_test__DOT__verify_output__37__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__37__timeout;
    __Vtask_simple_test__DOT__verify_output__37__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__37__match_found;
    __Vtask_simple_test__DOT__verify_output__37__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__38__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__38__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__38__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__38__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__38__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__38__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__38__src_id;
    __Vfunc_simple_test__DOT__encode_packet__38__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__38__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__38__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__38__data;
    __Vfunc_simple_test__DOT__encode_packet__38__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__39__x;
    __Vfunc_simple_test__DOT__calc_node_id__39__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__39__y;
    __Vfunc_simple_test__DOT__calc_node_id__39__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__40__x;
    __Vfunc_simple_test__DOT__calc_node_id__40__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__40__y;
    __Vfunc_simple_test__DOT__calc_node_id__40__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__41__pkt_type;
    __Vtask_simple_test__DOT__send_packet__41__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__41__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__41__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__41__src_id;
    __Vtask_simple_test__DOT__send_packet__41__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__41__tgt_id;
    __Vtask_simple_test__DOT__send_packet__41__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__41__data;
    __Vtask_simple_test__DOT__send_packet__41__data = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__41__timeout;
    __Vtask_simple_test__DOT__send_packet__41__timeout = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__41__wait_cycles;
    __Vtask_simple_test__DOT__send_packet__41__wait_cycles = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__42__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__42__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__42__x;
    __Vfunc_simple_test__DOT__calc_node_id__42__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__42__y;
    __Vfunc_simple_test__DOT__calc_node_id__42__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__x;
    __Vfunc_simple_test__DOT__calc_node_id__43__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__y;
    __Vfunc_simple_test__DOT__calc_node_id__43__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__44__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__44__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__44__expected_port;
    __Vtask_simple_test__DOT__verify_output__44__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__44__timeout;
    __Vtask_simple_test__DOT__verify_output__44__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__44__match_found;
    __Vtask_simple_test__DOT__verify_output__44__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__45__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__45__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__45__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__45__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__45__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__45__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__45__src_id;
    __Vfunc_simple_test__DOT__encode_packet__45__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__45__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__45__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__45__data;
    __Vfunc_simple_test__DOT__encode_packet__45__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__46__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__46__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__46__x;
    __Vfunc_simple_test__DOT__calc_node_id__46__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__46__y;
    __Vfunc_simple_test__DOT__calc_node_id__46__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__47__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__47__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__47__x;
    __Vfunc_simple_test__DOT__calc_node_id__47__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__47__y;
    __Vfunc_simple_test__DOT__calc_node_id__47__y = 0;
    // Body
    VL_WRITEF_NX("==============================================\nMAZE\350\212\202\347\202\271\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225 - DEBUG\347\211\210\346\234\254\n\346\265\213\350\257\225\350\212\202\347\202\271: (3, 3)\n==============================================\nDEBUG: \350\212\202\347\202\271\344\275\215\347\275\256\345\222\214\350\267\257\347\224\261\344\277\241\346\201\257\345\210\206\346\236\220\n\346\265\213\350\257\225\350\212\202\347\202\271\345\235\220\346\240\207: (X=3, Y=3)\n\345\275\223\345\211\215\350\212\202\347\202\271ID: 27 (binary: 011011)\n\345\275\223\345\211\215\350\212\202\347\202\271\345\210\206\350\247\243: Y\345\235\220\346\240\207(bit5:3)=011, X\345\235\220\346\240\207(bit2:0)=011\n\351\202\273\345\261\205\350\212\202\347\202\271ID:\n  - \350\245\277\344\276\247\350\212\202\347\202\271(X=2, Y=3): ID=26\n  - \344\270\234\344\276\247\350\212\202\347\202\271(X=4, Y=3): ID=28\n  - \345\215\227\344\276\247\350\212\202\347\202\271(X=3, Y=2): ID=19\n  - \345\214\227\344\276\247\350\212\202\347\202\271(X=3, Y=4): ID=35\n",0);
    VL_WRITEF_NX("\351\242\204\346\234\237\350\267\257\347\224\261\347\253\257\345\217\243\346\230\240\345\260\204:\n  - \345\220\221\350\245\277\350\267\257\347\224\261(X-1): \347\253\257\345\217\2431 (WEST)\n  - \345\220\221\344\270\234\350\267\257\347\224\261(X+1): \347\253\257\345\217\2433 (EAST)\n  - \345\220\221\345\215\227\350\267\257\347\224\261(Y-1): \347\253\257\345\217\2432 (SOUTH)\n  - \345\220\221\345\214\227\350\267\257\347\224\261(Y+1): \347\253\257\345\217\2430 (NORTH)\n  - \346\234\254\345\234\260\350\267\257\347\224\261(\347\233\270\345\220\214\345\235\220\346\240\207): \347\253\257\345\217\2434 (LOCAL)\n==============================================\n",0);
    vlSelfRef.simple_test__DOT__clk = 0U;
    vlSelfRef.simple_test__DOT__rst_n = 0U;
    vlSelfRef.simple_test__DOT__pg_en = 0U;
    vlSelfRef.simple_test__DOT__pg_node = 0U;
    vlSelfRef.simple_test__DOT__test_cycle = 0U;
    vlSelfRef.simple_test__DOT__error_count = 0U;
    vlSelfRef.simple_test__DOT__test_count = 0U;
    vlSelfRef.simple_test__DOT__pass_count = 0U;
    vlSelfRef.simple_test__DOT__debug_cycle_counter = 0U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_no_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_wo_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_so_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_eo_rdy = 1U;
    VL_WRITEF_NX("[INIT DEBUG] Reset phase starting...\n",0);
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         777);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         778);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__rst_n = 1U;
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         780);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         781);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("[INIT DEBUG] Reset completed. Testing node interfaces...\n[INIT DEBUG] Initial interface states:\n  A_PORT: vld=%1#, rdy=%1#\n  B_PORT: vld=%1#, rdy=%1#\n  N_PORT: out_vld=%1#, out_rdy=%1#\n  W_PORT: out_vld=%1#, out_rdy=%1#\n  S_PORT: out_vld=%1#, out_rdy=%1#\n  E_PORT: out_vld=%1#, out_rdy=%1#\n\345\244\215\344\275\215\345\256\214\346\210\220\357\274\214\345\274\200\345\247\213\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225...\n\n--- N-RF-001: X\346\226\271\345\220\221\346\255\243\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0,
                 1,vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))),
                 1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r),
                 1,vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy,
                 1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r),
                 1,vlSelfRef.simple_test__DOT__pkt_con_no_rdy,
                 1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r),
                 1,vlSelfRef.simple_test__DOT__pkt_con_wo_rdy,
                 1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r),
                 1,vlSelfRef.simple_test__DOT__pkt_con_so_rdy,
                 1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r),
                 1,vlSelfRef.simple_test__DOT__pkt_con_eo_rdy);
    __Vtask_simple_test__DOT__send_packet__13__data = 0xa5U;
    __Vfunc_simple_test__DOT__calc_node_id__14__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__14__x = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__14__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__14__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__14__x));
    __Vtask_simple_test__DOT__send_packet__13__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__14__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__15__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__15__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__15__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__15__x));
    __Vtask_simple_test__DOT__send_packet__13__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__13__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__13__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x = 0;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y = 0;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x = 0;
    __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y = 0;
    __Vtask_simple_test__DOT__send_packet__13__timeout = 0;
    __Vtask_simple_test__DOT__send_packet__13__wait_cycles = 0;
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: STARTING PACKET SEND\n  Packet Info: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n  Target Direction: Expected output port calculation:\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__13__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__13__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__13__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__13__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__13__data));
    if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__tgt_id) 
                      == (IData)(__Vtask_simple_test__DOT__send_packet__13__src_id))))) {
        VL_WRITEF_NX("    -> LOCAL (port 4) - Same node\n",0);
    } else {
        __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__13__src_id));
        __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__13__src_id) 
                     >> 3U));
        __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__13__tgt_id));
        __Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__13__tgt_id) 
                     >> 3U));
        if (((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y) 
             == (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> EAST (port 3) - X+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> WEST (port 1) - X- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x));
            }
        } else if (VL_LIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x) 
                               == (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x))))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> NORTH (port 0) - Y+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> SOUTH (port 2) - Y- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y));
            }
        } else {
            VL_WRITEF_NX("    -> COMPLEX ROUTING: Different X and Y (%0#,%0# -> %0#,%0#)\n",0,
                         3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__src_y),
                         3,__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__13__unnamedblk1__DOT__tgt_y));
        }
    }
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%1#\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__13__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__13__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__13__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__13__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__13__data;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__send_packet__13__timeout = 0x00000064U;
    __Vtask_simple_test__DOT__send_packet__13__wait_cycles = 0U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__13__timeout))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             666);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__13__wait_cycles 
            = ((IData)(1U) + __Vtask_simple_test__DOT__send_packet__13__wait_cycles);
        __Vtask_simple_test__DOT__send_packet__13__timeout 
            = (__Vtask_simple_test__DOT__send_packet__13__timeout 
               - (IData)(1U));
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, __Vtask_simple_test__DOT__send_packet__13__wait_cycles, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         32,__Vtask_simple_test__DOT__send_packet__13__wait_cycles,
                         32,__Vtask_simple_test__DOT__send_packet__13__timeout);
        }
    }
    if ((0U == __Vtask_simple_test__DOT__send_packet__13__timeout)) {
        VL_WRITEF_NX("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles\n  Final status: pkt_i_pkt_in_vld=%1#, pkt_i_pkt_in_rdy=%1#\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__13__wait_cycles,
                     1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                     1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    } else {
        VL_WRITEF_NX("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__13__wait_cycles);
    }
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         689);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Valid signal cleared\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__verify_output__16__expected_port = 3U;
    __Vfunc_simple_test__DOT__encode_packet__17__data = 0xa5U;
    __Vfunc_simple_test__DOT__calc_node_id__18__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__18__x = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__18__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__18__x));
    __Vfunc_simple_test__DOT__encode_packet__17__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__19__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__19__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__19__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__19__x));
    __Vfunc_simple_test__DOT__encode_packet__17__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__17__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__17__pkt_type = 0U;
    VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                 2,__Vfunc_simple_test__DOT__encode_packet__17__pkt_type,
                 1,(IData)(__Vfunc_simple_test__DOT__encode_packet__17__pkt_qos),
                 6,__Vfunc_simple_test__DOT__encode_packet__17__src_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__17__src_id),
                 6,__Vfunc_simple_test__DOT__encode_packet__17__tgt_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__17__tgt_id),
                 8,__Vfunc_simple_test__DOT__encode_packet__17__data);
    __Vfunc_simple_test__DOT__encode_packet__17__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__17__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__17__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__17__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__17__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__17__data)));
    VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                 23,__Vfunc_simple_test__DOT__encode_packet__17__Vfuncout);
    __Vtask_simple_test__DOT__verify_output__16__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__17__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__16__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__16__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__16__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__16__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__16__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__16__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__16__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__16__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             709);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__16__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__16__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__16__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__16__timeout 
            = (__Vtask_simple_test__DOT__verify_output__16__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__16__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__16__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__16__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    VL_WRITEF_NX("PASS = %11d\n",0,32,vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h98ce37a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         805);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-002: X\346\226\271\345\220\221\345\217\215\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__20__data = 0x5aU;
    __Vfunc_simple_test__DOT__calc_node_id__21__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__21__x = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__21__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__21__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__21__x));
    __Vtask_simple_test__DOT__send_packet__20__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__21__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__22__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__22__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__22__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__22__x));
    __Vtask_simple_test__DOT__send_packet__20__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__20__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__20__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x = 0;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y = 0;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x = 0;
    __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y = 0;
    __Vtask_simple_test__DOT__send_packet__20__timeout = 0;
    __Vtask_simple_test__DOT__send_packet__20__wait_cycles = 0;
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: STARTING PACKET SEND\n  Packet Info: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n  Target Direction: Expected output port calculation:\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__20__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__20__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__20__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__20__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__20__data));
    if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__tgt_id) 
                      == (IData)(__Vtask_simple_test__DOT__send_packet__20__src_id))))) {
        VL_WRITEF_NX("    -> LOCAL (port 4) - Same node\n",0);
    } else {
        __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__20__src_id));
        __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__20__src_id) 
                     >> 3U));
        __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__20__tgt_id));
        __Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__20__tgt_id) 
                     >> 3U));
        if (((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y) 
             == (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> EAST (port 3) - X+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> WEST (port 1) - X- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x));
            }
        } else if (VL_LIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x) 
                               == (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x))))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> NORTH (port 0) - Y+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> SOUTH (port 2) - Y- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y));
            }
        } else {
            VL_WRITEF_NX("    -> COMPLEX ROUTING: Different X and Y (%0#,%0# -> %0#,%0#)\n",0,
                         3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__src_y),
                         3,__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__20__unnamedblk1__DOT__tgt_y));
        }
    }
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%1#\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__20__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__20__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__20__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__20__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__20__data;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__send_packet__20__timeout = 0x00000064U;
    __Vtask_simple_test__DOT__send_packet__20__wait_cycles = 0U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__20__timeout))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             666);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__20__wait_cycles 
            = ((IData)(1U) + __Vtask_simple_test__DOT__send_packet__20__wait_cycles);
        __Vtask_simple_test__DOT__send_packet__20__timeout 
            = (__Vtask_simple_test__DOT__send_packet__20__timeout 
               - (IData)(1U));
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, __Vtask_simple_test__DOT__send_packet__20__wait_cycles, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         32,__Vtask_simple_test__DOT__send_packet__20__wait_cycles,
                         32,__Vtask_simple_test__DOT__send_packet__20__timeout);
        }
    }
    if ((0U == __Vtask_simple_test__DOT__send_packet__20__timeout)) {
        VL_WRITEF_NX("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles\n  Final status: pkt_i_pkt_in_vld=%1#, pkt_i_pkt_in_rdy=%1#\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__20__wait_cycles,
                     1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                     1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    } else {
        VL_WRITEF_NX("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__20__wait_cycles);
    }
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         689);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Valid signal cleared\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__verify_output__23__expected_port = 1U;
    __Vfunc_simple_test__DOT__encode_packet__24__data = 0x5aU;
    __Vfunc_simple_test__DOT__calc_node_id__25__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__25__x = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__25__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__25__x));
    __Vfunc_simple_test__DOT__encode_packet__24__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__26__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__26__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__26__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__26__x));
    __Vfunc_simple_test__DOT__encode_packet__24__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__24__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__24__pkt_type = 0U;
    VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                 2,__Vfunc_simple_test__DOT__encode_packet__24__pkt_type,
                 1,(IData)(__Vfunc_simple_test__DOT__encode_packet__24__pkt_qos),
                 6,__Vfunc_simple_test__DOT__encode_packet__24__src_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__24__src_id),
                 6,__Vfunc_simple_test__DOT__encode_packet__24__tgt_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__24__tgt_id),
                 8,__Vfunc_simple_test__DOT__encode_packet__24__data);
    __Vfunc_simple_test__DOT__encode_packet__24__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__24__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__24__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__24__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__24__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__24__data)));
    VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                 23,__Vfunc_simple_test__DOT__encode_packet__24__Vfuncout);
    __Vtask_simple_test__DOT__verify_output__23__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__24__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__23__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__23__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__23__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__23__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__23__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__23__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__23__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__23__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             709);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__23__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__23__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__23__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__23__timeout 
            = (__Vtask_simple_test__DOT__verify_output__23__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__23__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__23__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__23__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    VL_WRITEF_NX("PASS = %11d\n",0,32,vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h98ce37a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         815);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-003: Y\346\226\271\345\220\221\346\255\243\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__27__data = 0x33U;
    __Vfunc_simple_test__DOT__calc_node_id__28__y = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__28__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__28__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__28__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__28__x));
    __Vtask_simple_test__DOT__send_packet__27__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__28__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__29__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__29__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__29__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__29__x));
    __Vtask_simple_test__DOT__send_packet__27__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__27__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__27__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x = 0;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y = 0;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x = 0;
    __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y = 0;
    __Vtask_simple_test__DOT__send_packet__27__timeout = 0;
    __Vtask_simple_test__DOT__send_packet__27__wait_cycles = 0;
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: STARTING PACKET SEND\n  Packet Info: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n  Target Direction: Expected output port calculation:\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__27__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__27__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__27__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__27__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__27__data));
    if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__tgt_id) 
                      == (IData)(__Vtask_simple_test__DOT__send_packet__27__src_id))))) {
        VL_WRITEF_NX("    -> LOCAL (port 4) - Same node\n",0);
    } else {
        __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__27__src_id));
        __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__27__src_id) 
                     >> 3U));
        __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__27__tgt_id));
        __Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__27__tgt_id) 
                     >> 3U));
        if (((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y) 
             == (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> EAST (port 3) - X+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> WEST (port 1) - X- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x));
            }
        } else if (VL_LIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x) 
                               == (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x))))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> NORTH (port 0) - Y+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> SOUTH (port 2) - Y- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y));
            }
        } else {
            VL_WRITEF_NX("    -> COMPLEX ROUTING: Different X and Y (%0#,%0# -> %0#,%0#)\n",0,
                         3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__src_y),
                         3,__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__27__unnamedblk1__DOT__tgt_y));
        }
    }
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%1#\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__27__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__27__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__27__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__27__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__27__data;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__send_packet__27__timeout = 0x00000064U;
    __Vtask_simple_test__DOT__send_packet__27__wait_cycles = 0U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__27__timeout))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             666);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__27__wait_cycles 
            = ((IData)(1U) + __Vtask_simple_test__DOT__send_packet__27__wait_cycles);
        __Vtask_simple_test__DOT__send_packet__27__timeout 
            = (__Vtask_simple_test__DOT__send_packet__27__timeout 
               - (IData)(1U));
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, __Vtask_simple_test__DOT__send_packet__27__wait_cycles, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         32,__Vtask_simple_test__DOT__send_packet__27__wait_cycles,
                         32,__Vtask_simple_test__DOT__send_packet__27__timeout);
        }
    }
    if ((0U == __Vtask_simple_test__DOT__send_packet__27__timeout)) {
        VL_WRITEF_NX("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles\n  Final status: pkt_i_pkt_in_vld=%1#, pkt_i_pkt_in_rdy=%1#\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__27__wait_cycles,
                     1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                     1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    } else {
        VL_WRITEF_NX("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__27__wait_cycles);
    }
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         689);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Valid signal cleared\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__verify_output__30__expected_port = 0U;
    __Vfunc_simple_test__DOT__encode_packet__31__data = 0x33U;
    __Vfunc_simple_test__DOT__calc_node_id__32__y = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__32__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__32__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__32__x));
    __Vfunc_simple_test__DOT__encode_packet__31__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__33__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__33__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__33__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__33__x));
    __Vfunc_simple_test__DOT__encode_packet__31__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__31__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__31__pkt_type = 0U;
    VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                 2,__Vfunc_simple_test__DOT__encode_packet__31__pkt_type,
                 1,(IData)(__Vfunc_simple_test__DOT__encode_packet__31__pkt_qos),
                 6,__Vfunc_simple_test__DOT__encode_packet__31__src_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__31__src_id),
                 6,__Vfunc_simple_test__DOT__encode_packet__31__tgt_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__31__tgt_id),
                 8,__Vfunc_simple_test__DOT__encode_packet__31__data);
    __Vfunc_simple_test__DOT__encode_packet__31__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__31__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__31__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__31__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__31__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__31__data)));
    VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                 23,__Vfunc_simple_test__DOT__encode_packet__31__Vfuncout);
    __Vtask_simple_test__DOT__verify_output__30__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__31__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__30__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__30__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__30__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__30__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__30__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__30__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__30__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__30__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             709);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__30__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__30__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__30__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__30__timeout 
            = (__Vtask_simple_test__DOT__verify_output__30__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__30__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__30__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__30__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    VL_WRITEF_NX("PASS = %11d\n",0,32,vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h98ce37a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         825);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-004: Y\346\226\271\345\220\221\345\217\215\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__34__data = 0xccU;
    __Vfunc_simple_test__DOT__calc_node_id__35__y = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__35__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__35__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__35__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__35__x));
    __Vtask_simple_test__DOT__send_packet__34__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__35__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__36__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__36__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__36__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__36__x));
    __Vtask_simple_test__DOT__send_packet__34__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__34__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__34__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x = 0;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y = 0;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x = 0;
    __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y = 0;
    __Vtask_simple_test__DOT__send_packet__34__timeout = 0;
    __Vtask_simple_test__DOT__send_packet__34__wait_cycles = 0;
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: STARTING PACKET SEND\n  Packet Info: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n  Target Direction: Expected output port calculation:\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__34__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__34__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__34__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__34__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__34__data));
    if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__tgt_id) 
                      == (IData)(__Vtask_simple_test__DOT__send_packet__34__src_id))))) {
        VL_WRITEF_NX("    -> LOCAL (port 4) - Same node\n",0);
    } else {
        __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__34__src_id));
        __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__34__src_id) 
                     >> 3U));
        __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__34__tgt_id));
        __Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__34__tgt_id) 
                     >> 3U));
        if (((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y) 
             == (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> EAST (port 3) - X+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> WEST (port 1) - X- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x));
            }
        } else if (VL_LIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x) 
                               == (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x))))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> NORTH (port 0) - Y+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> SOUTH (port 2) - Y- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y));
            }
        } else {
            VL_WRITEF_NX("    -> COMPLEX ROUTING: Different X and Y (%0#,%0# -> %0#,%0#)\n",0,
                         3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__src_y),
                         3,__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__34__unnamedblk1__DOT__tgt_y));
        }
    }
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%1#\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__34__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__34__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__34__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__34__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__34__data;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__send_packet__34__timeout = 0x00000064U;
    __Vtask_simple_test__DOT__send_packet__34__wait_cycles = 0U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__34__timeout))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             666);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__34__wait_cycles 
            = ((IData)(1U) + __Vtask_simple_test__DOT__send_packet__34__wait_cycles);
        __Vtask_simple_test__DOT__send_packet__34__timeout 
            = (__Vtask_simple_test__DOT__send_packet__34__timeout 
               - (IData)(1U));
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, __Vtask_simple_test__DOT__send_packet__34__wait_cycles, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         32,__Vtask_simple_test__DOT__send_packet__34__wait_cycles,
                         32,__Vtask_simple_test__DOT__send_packet__34__timeout);
        }
    }
    if ((0U == __Vtask_simple_test__DOT__send_packet__34__timeout)) {
        VL_WRITEF_NX("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles\n  Final status: pkt_i_pkt_in_vld=%1#, pkt_i_pkt_in_rdy=%1#\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__34__wait_cycles,
                     1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                     1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    } else {
        VL_WRITEF_NX("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__34__wait_cycles);
    }
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         689);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Valid signal cleared\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__verify_output__37__expected_port = 2U;
    __Vfunc_simple_test__DOT__encode_packet__38__data = 0xccU;
    __Vfunc_simple_test__DOT__calc_node_id__39__y = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__39__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__39__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__39__x));
    __Vfunc_simple_test__DOT__encode_packet__38__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__40__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__40__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__40__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__40__x));
    __Vfunc_simple_test__DOT__encode_packet__38__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__38__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__38__pkt_type = 0U;
    VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                 2,__Vfunc_simple_test__DOT__encode_packet__38__pkt_type,
                 1,(IData)(__Vfunc_simple_test__DOT__encode_packet__38__pkt_qos),
                 6,__Vfunc_simple_test__DOT__encode_packet__38__src_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__38__src_id),
                 6,__Vfunc_simple_test__DOT__encode_packet__38__tgt_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__38__tgt_id),
                 8,__Vfunc_simple_test__DOT__encode_packet__38__data);
    __Vfunc_simple_test__DOT__encode_packet__38__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__38__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__38__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__38__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__38__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__38__data)));
    VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                 23,__Vfunc_simple_test__DOT__encode_packet__38__Vfuncout);
    __Vtask_simple_test__DOT__verify_output__37__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__38__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__37__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__37__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__37__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__37__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__37__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__37__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__37__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__37__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             709);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__37__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__37__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__37__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__37__timeout 
            = (__Vtask_simple_test__DOT__verify_output__37__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__37__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__37__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__37__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    VL_WRITEF_NX("PASS = %11d\n",0,32,vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h98ce37a2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         835);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-005: \346\234\254\345\234\260\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__41__data = 0xffU;
    __Vfunc_simple_test__DOT__calc_node_id__42__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__42__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__42__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__42__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__42__x));
    __Vtask_simple_test__DOT__send_packet__41__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__42__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__43__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__43__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__43__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__43__x));
    __Vtask_simple_test__DOT__send_packet__41__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__41__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__41__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x = 0;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y = 0;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x = 0;
    __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y = 0;
    __Vtask_simple_test__DOT__send_packet__41__timeout = 0;
    __Vtask_simple_test__DOT__send_packet__41__wait_cycles = 0;
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: STARTING PACKET SEND\n  Packet Info: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n  Target Direction: Expected output port calculation:\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__41__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__41__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__41__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__41__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__41__data));
    if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__tgt_id) 
                      == (IData)(__Vtask_simple_test__DOT__send_packet__41__src_id))))) {
        VL_WRITEF_NX("    -> LOCAL (port 4) - Same node\n",0);
    } else {
        __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__41__src_id));
        __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__41__src_id) 
                     >> 3U));
        __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x 
            = (7U & (IData)(__Vtask_simple_test__DOT__send_packet__41__tgt_id));
        __Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y 
            = (7U & ((IData)(__Vtask_simple_test__DOT__send_packet__41__tgt_id) 
                     >> 3U));
        if (((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y) 
             == (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> EAST (port 3) - X+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x))))) {
                VL_WRITEF_NX("    -> WEST (port 1) - X- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x));
            }
        } else if (VL_LIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x) 
                               == (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x))))) {
            if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y) 
                              > (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> NORTH (port 0) - Y+ (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y));
            } else if (VL_UNLIKELY((((IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y) 
                                     < (IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y))))) {
                VL_WRITEF_NX("    -> SOUTH (port 2) - Y- (%0# -> %0#)\n",0,
                             3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y,
                             3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y));
            }
        } else {
            VL_WRITEF_NX("    -> COMPLEX ROUTING: Different X and Y (%0#,%0# -> %0#,%0#)\n",0,
                         3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__src_y),
                         3,__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_x,
                         3,(IData)(__Vtask_simple_test__DOT__send_packet__41__unnamedblk1__DOT__tgt_y));
        }
    }
    VL_WRITEF_NX("==============================================\n[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%1#\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__41__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__41__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__41__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__41__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__41__data;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__send_packet__41__timeout = 0x00000064U;
    __Vtask_simple_test__DOT__send_packet__41__wait_cycles = 0U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__41__timeout))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             666);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__41__wait_cycles 
            = ((IData)(1U) + __Vtask_simple_test__DOT__send_packet__41__wait_cycles);
        __Vtask_simple_test__DOT__send_packet__41__timeout 
            = (__Vtask_simple_test__DOT__send_packet__41__timeout 
               - (IData)(1U));
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, __Vtask_simple_test__DOT__send_packet__41__wait_cycles, (IData)(0x0000000aU)))))) {
            VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         32,__Vtask_simple_test__DOT__send_packet__41__wait_cycles,
                         32,__Vtask_simple_test__DOT__send_packet__41__timeout);
        }
    }
    if ((0U == __Vtask_simple_test__DOT__send_packet__41__timeout)) {
        VL_WRITEF_NX("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles\n  Final status: pkt_i_pkt_in_vld=%1#, pkt_i_pkt_in_rdy=%1#\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__41__wait_cycles,
                     1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                     1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))));
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    } else {
        VL_WRITEF_NX("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles\n",0,
                     32,vlSelfRef.simple_test__DOT__test_cycle,
                     32,__Vtask_simple_test__DOT__send_packet__41__wait_cycles);
    }
    co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         689);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    VL_WRITEF_NX("[SEND DEBUG] Cycle %0d: Valid signal cleared\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    __Vtask_simple_test__DOT__verify_output__44__expected_port = 4U;
    __Vfunc_simple_test__DOT__encode_packet__45__data = 0xffU;
    __Vfunc_simple_test__DOT__calc_node_id__46__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__46__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__46__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__46__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__46__x));
    __Vfunc_simple_test__DOT__encode_packet__45__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__46__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__47__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__47__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__47__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__47__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__47__x));
    __Vfunc_simple_test__DOT__encode_packet__45__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__47__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__45__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__45__pkt_type = 0U;
    VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                 2,__Vfunc_simple_test__DOT__encode_packet__45__pkt_type,
                 1,(IData)(__Vfunc_simple_test__DOT__encode_packet__45__pkt_qos),
                 6,__Vfunc_simple_test__DOT__encode_packet__45__src_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__45__src_id),
                 6,__Vfunc_simple_test__DOT__encode_packet__45__tgt_id,
                 6,(IData)(__Vfunc_simple_test__DOT__encode_packet__45__tgt_id),
                 8,__Vfunc_simple_test__DOT__encode_packet__45__data);
    __Vfunc_simple_test__DOT__encode_packet__45__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__45__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__45__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__45__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__45__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__45__data)));
    VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                 23,__Vfunc_simple_test__DOT__encode_packet__45__Vfuncout);
    __Vtask_simple_test__DOT__verify_output__44__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__45__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__44__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__44__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__44__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__44__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__44__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__44__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__44__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__44__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hf3e272e8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             709);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__44__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__44__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__44__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__44__timeout 
            = (__Vtask_simple_test__DOT__verify_output__44__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__44__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__44__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__44__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    VL_WRITEF_NX("PASS = %11d\nAll finished\n\n==============================================\n\346\265\213\350\257\225\346\200\273\347\273\223\n==============================================\n\346\200\273\346\265\213\350\257\225\346\225\260: %0d\n\351\200\232\350\277\207\346\265\213\350\257\225: %0d\n\345\244\261\350\264\245\346\265\213\350\257\225: %0d\n\351\200\232\350\277\207\347\216\207: %0.2f%%\n",0,
                 32,vlSelfRef.simple_test__DOT__test_count,
                 32,vlSelfRef.simple_test__DOT__test_count,
                 32,vlSelfRef.simple_test__DOT__pass_count,
                 32,vlSelfRef.simple_test__DOT__error_count,
                 64,(VL_LTS_III(32, 0U, vlSelfRef.simple_test__DOT__test_count)
                      ? ((100.0 * VL_ISTOR_D_I(32, vlSelfRef.simple_test__DOT__pass_count)) 
                         / VL_ISTOR_D_I(32, vlSelfRef.simple_test__DOT__test_count))
                      : 0.0));
    if ((0U == vlSelfRef.simple_test__DOT__error_count)) {
        VL_WRITEF_NX("\342\234\223 \346\211\200\346\234\211\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225\351\200\232\350\277\207\357\274\201\nTEST_RESULT: PASS\n",0);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                             nullptr, 
                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                             857);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 858, "");
    } else {
        VL_WRITEF_NX("\342\234\227 \351\203\250\345\210\206\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225\345\244\261\350\264\245\n\345\244\261\350\264\245\346\265\213\350\257\225\346\225\260: %0d / %0d\nTEST_RESULT: FAIL\n",0,
                     32,vlSelfRef.simple_test__DOT__error_count,
                     32,vlSelfRef.simple_test__DOT__test_count);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                             nullptr, 
                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                             863);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 864, "");
    }
    VL_WRITEF_NX("==============================================\n",0);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                         nullptr, "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                         870);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 871, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__1(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000005f5e100ULL, 
                                         nullptr, "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                         876);
    VL_WRITEF_NX("[IRS DEBUG] Cycle %0d:\nERROR: \346\265\213\350\257\225\350\266\205\346\227\266\357\274\201\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle);
    VL_FINISH_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 879, "");
}

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__2(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                             298);
        vlSelfRef.simple_test__DOT__clk = (1U & (~ (IData)(vlSelfRef.simple_test__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsimple_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vsimple_test___024root___eval_triggers__act(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_triggers__act\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vtrigprevexpr_h0cf981d0__0;
    __Vtrigprevexpr_h0cf981d0__0 = 0;
    // Body
    __Vtrigprevexpr_h0cf981d0__0 = ((IData)(5U) * (IData)(vlSelfRef.simple_test__DOT__clk));
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 3U) 
                                                      | (4U 
                                                         & ((__Vtrigprevexpr_h0cf981d0__0 
                                                             & (~ vlSelfRef.__Vtrigprevexpr_h0cf981d0__1)) 
                                                            << 2U))) 
                                                     | ((((~ (IData)(vlSelfRef.simple_test__DOT__rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.simple_test__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 
        = vlSelfRef.simple_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 
        = vlSelfRef.simple_test__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr_h0cf981d0__1 = __Vtrigprevexpr_h0cf981d0__0;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsimple_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vsimple_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___trigger_anySet__act\n"); );
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

void Vsimple_test___024root___act_comb__TOP__0(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___act_comb__TOP__0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r) {
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
    }
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

void Vsimple_test___024root___eval_act(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_act\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000dULL & vlSelfRef.__VactTriggered
         [0U])) {
        Vsimple_test___024root___act_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vsimple_test___024root___nba_sequent__TOP__0(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_sequent__TOP__0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__0__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__0__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__0__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__0__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__0__src_id;
    __Vfunc_simple_test__DOT__encode_packet__0__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__0__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__0__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__0__data;
    __Vfunc_simple_test__DOT__encode_packet__0__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__1__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__1__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__1__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__1__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__1__src_id;
    __Vfunc_simple_test__DOT__encode_packet__1__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__1__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__1__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__1__data;
    __Vfunc_simple_test__DOT__encode_packet__1__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__2__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__2__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__2__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__2__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__2__src_id;
    __Vfunc_simple_test__DOT__encode_packet__2__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__2__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__2__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__2__data;
    __Vfunc_simple_test__DOT__encode_packet__2__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__3__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__3__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__3__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__3__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__3__src_id;
    __Vfunc_simple_test__DOT__encode_packet__3__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__3__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__3__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__3__data;
    __Vfunc_simple_test__DOT__encode_packet__3__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__4__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__4__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__4__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__4__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__4__src_id;
    __Vfunc_simple_test__DOT__encode_packet__4__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__4__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__4__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__4__data;
    __Vfunc_simple_test__DOT__encode_packet__4__data = 0;
    IData/*31:0*/ __Vdly__simple_test__DOT__test_cycle;
    __Vdly__simple_test__DOT__test_cycle = 0;
    IData/*31:0*/ __Vdly__simple_test__DOT__debug_cycle_counter;
    __Vdly__simple_test__DOT__debug_cycle_counter = 0;
    IData/*22:0*/ __Vdly__simple_test__DOT__last_output_pkt;
    __Vdly__simple_test__DOT__last_output_pkt = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r = 0;
    // Body
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r;
    __Vdly__simple_test__DOT__last_output_pkt = vlSelfRef.simple_test__DOT__last_output_pkt;
    if (vlSelfRef.simple_test__DOT__rst_n) {
        __Vdly__simple_test__DOT__debug_cycle_counter 
            = ((IData)(1U) + vlSelfRef.simple_test__DOT__debug_cycle_counter);
        vlSelfRef.simple_test__DOT__debug_cycle_counter 
            = __Vdly__simple_test__DOT__debug_cycle_counter;
        __Vdly__simple_test__DOT__test_cycle = ((IData)(1U) 
                                                + vlSelfRef.simple_test__DOT__test_cycle);
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r = 0U;
        }
    } else {
        __Vdly__simple_test__DOT__debug_cycle_counter = 0U;
        vlSelfRef.simple_test__DOT__debug_cycle_counter 
            = __Vdly__simple_test__DOT__debug_cycle_counter;
        __Vdly__simple_test__DOT__test_cycle = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r = 0U;
    }
    if (vlSelfRef.simple_test__DOT__rst_n) {
        if (VL_UNLIKELY((((1U == vlSelfRef.simple_test__DOT__first_10_cycles_debug) 
                          & VL_GTES_III(32, 0x0000000aU, vlSelfRef.simple_test__DOT__test_cycle))))) {
            VL_WRITEF_NX("=================================================================\n[INTERNAL DEBUG] Cycle %0d - Full Internal Signal Analysis:\n=================================================================\n=== IRS_N Input Signals ===\n  irs_input_A: valid_i=%1#, ready_i=1, valid_o=%1#, ready_o=%1#\n    payload_i=0x%x, payload_o=0x%x\n  irs_input_N: valid_i=0, ready_i=1, valid_o=%1#, ready_o=%1#\n    payload_i=0x000000, payload_o=0x%x\n  irs_input_W: valid_i=0, ready_i=1, valid_o=%1#, ready_o=%1#\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         1,(IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld),
                         1,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r,
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r))));
            VL_WRITEF_NX("    payload_i=0x000000, payload_o=0x%x\n  irs_input_S: valid_i=0, ready_i=1, valid_o=%1#, ready_o=%1#\n    payload_i=0x000000, payload_o=0x%x\n  irs_input_E: valid_i=0, ready_i=1, valid_o=%1#, ready_o=%1#\n    payload_i=0x000000, payload_o=0x%x\n=== Router Output Signals ===\n  route_req_A=0b%05b (N,W,S,E,B), route_pkt_A=0x%x\n  route_req_N=0b%05b, route_pkt_N=0x%x\n  route_req_W=0b%05b, route_pkt_W=0x%x\n  route_req_S=0b%05b, route_pkt_S=0x%x\n  route_req_E=0b%05b, route_pkt_E=0x%x\n",0,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r,
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r,
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r,
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r,
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r,
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r);
            VL_WRITEF_NX("=== Arbiter I/O Signals ===\n  Arbiter_N: req=0b%04b(A,W,S,E), qos=0b%04b, gnt=0b%04b\n  Arbiter_W: req=0b%04b(A,N,S,E), qos=0b%04b, gnt=0b%04b\n  Arbiter_S: req=0b%04b(A,N,W,E), qos=0b%04b, gnt=0b%04b\n  Arbiter_E: req=0b%04b(A,N,W,S), qos=0b%04b, gnt=0b%04b\n  Arbiter_B: req=0b%05b(A,N,W,S,E), qos=0b%05b, gnt=0b%05b\n=== Output IRS_N Input Signals ===\n  irs_output_N: valid_i=%1#, ready_o=%1#, payload_i=0x%x,  valid_o=%1#, ready_i=%1#, payload_o=0x%x\n",0,
                         4,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N,
                         4,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N),
                         4,(0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2),
                         4,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W),
                         4,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W,
                         4,(0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4),
                         4,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S),
                         4,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S,
                         4,(0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3),
                         4,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E),
                         4,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E,
                         4,(0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1),
                         5,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B),
                         5,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B,
                         5,(0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0),
                         1,(0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r))),
                         23,((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                              ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
                              : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                  ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r
                                  : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                      ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r
                                      : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                          ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r
                                          : 0U)))),
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_no_rdy,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            VL_WRITEF_NX("  irs_output_W: valid_i=%1#, ready_o=%1#, payload_i=0x%x,  valid_o=%1#, ready_i=%1#, payload_o=0x%x\n  irs_output_S: valid_i=%1#, ready_o=%1#, payload_i=0x%x,  valid_o=%1#, ready_i=%1#, payload_o=0x%x\n  irs_output_E: valid_i=%1#, ready_o=%1#, payload_i=0x%x,  valid_o=%1#, ready_i=%1#, payload_o=0x%x\n  irs_output_B: valid_i=%1#, ready_o=%1#, payload_i=0x%x,  valid_o=%1#, ready_i=%1#, payload_o=0x%x\n=================================================================\n",0,
                         1,(0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_wo_rdy,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r,
                         1,(0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_so_rdy,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r,
                         1,(0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_eo_rdy,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r,
                         1,(0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)),
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy,
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r);
        }
        if (VL_UNLIKELY((((1U == vlSelfRef.simple_test__DOT__first_10_cycles_debug) 
                          & VL_GTES_III(32, 0x0000000aU, vlSelfRef.simple_test__DOT__test_cycle))))) {
            VL_WRITEF_NX("=== Node Internal Output Connections ===\n  Node.e_out_valid=%1#, e_out_ready=%1#, e_out_pkt=0x%x\n  External pkt_con_eo_vld=%1#, pkt_con_eo_rdy=%1#\n  Connection match: vld=1, rdy_match=%b\n=================================================================\n",0,
                         1,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r,
                         1,(1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r))),
                         23,vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_eo_rdy,
                         1,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r))) 
                            == (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)));
        }
        if ((1U & (~ (IData)(vlSelfRef.simple_test__DOT__last_output_valid)))) {
            vlSelfRef.simple_test__DOT__last_output_valid = 0U;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy))))) {
            __Vfunc_simple_test__DOT__encode_packet__0__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r);
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__0__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                  >> 8U));
            vlSelfRef.simple_test__DOT__last_output_port = 4U;
            __Vfunc_simple_test__DOT__encode_packet__0__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                  >> 0x0000000eU));
            __Vfunc_simple_test__DOT__encode_packet__0__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                         >> 0x00000014U));
            __Vfunc_simple_test__DOT__encode_packet__0__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                         >> 0x00000015U));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                         2,__Vfunc_simple_test__DOT__encode_packet__0__pkt_type,
                         1,(IData)(__Vfunc_simple_test__DOT__encode_packet__0__pkt_qos),
                         6,__Vfunc_simple_test__DOT__encode_packet__0__src_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__0__src_id),
                         6,__Vfunc_simple_test__DOT__encode_packet__0__tgt_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__0__tgt_id),
                         8,__Vfunc_simple_test__DOT__encode_packet__0__data);
            __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__0__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__0__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__0__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__0__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__0__data)));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                         23,__Vfunc_simple_test__DOT__encode_packet__0__Vfuncout);
            __Vdly__simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout;
            VL_WRITEF_NX("[OUTPUT MONITOR] Cycle %0d: LOCAL(B) Output detected: pkt=%x\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,vlSelfRef.simple_test__DOT__last_output_pkt);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy))))) {
            __Vfunc_simple_test__DOT__encode_packet__1__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__1__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U));
            vlSelfRef.simple_test__DOT__last_output_port = 0U;
            __Vfunc_simple_test__DOT__encode_packet__1__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000eU));
            __Vfunc_simple_test__DOT__encode_packet__1__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000014U));
            __Vfunc_simple_test__DOT__encode_packet__1__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                         2,__Vfunc_simple_test__DOT__encode_packet__1__pkt_type,
                         1,(IData)(__Vfunc_simple_test__DOT__encode_packet__1__pkt_qos),
                         6,__Vfunc_simple_test__DOT__encode_packet__1__src_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__1__src_id),
                         6,__Vfunc_simple_test__DOT__encode_packet__1__tgt_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__1__tgt_id),
                         8,__Vfunc_simple_test__DOT__encode_packet__1__data);
            __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__1__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__1__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__1__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__1__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__1__data)));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                         23,__Vfunc_simple_test__DOT__encode_packet__1__Vfuncout);
            __Vdly__simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout;
            VL_WRITEF_NX("[OUTPUT MONITOR] Cycle %0d: NORTH Output detected: pkt=%x\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,vlSelfRef.simple_test__DOT__last_output_pkt);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy))))) {
            __Vfunc_simple_test__DOT__encode_packet__2__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r);
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__2__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                  >> 8U));
            vlSelfRef.simple_test__DOT__last_output_port = 1U;
            __Vfunc_simple_test__DOT__encode_packet__2__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                  >> 0x0000000eU));
            __Vfunc_simple_test__DOT__encode_packet__2__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                         >> 0x00000014U));
            __Vfunc_simple_test__DOT__encode_packet__2__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                         >> 0x00000015U));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                         2,__Vfunc_simple_test__DOT__encode_packet__2__pkt_type,
                         1,(IData)(__Vfunc_simple_test__DOT__encode_packet__2__pkt_qos),
                         6,__Vfunc_simple_test__DOT__encode_packet__2__src_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__2__src_id),
                         6,__Vfunc_simple_test__DOT__encode_packet__2__tgt_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__2__tgt_id),
                         8,__Vfunc_simple_test__DOT__encode_packet__2__data);
            __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__2__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__2__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__2__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__2__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__2__data)));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                         23,__Vfunc_simple_test__DOT__encode_packet__2__Vfuncout);
            __Vdly__simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout;
            VL_WRITEF_NX("[OUTPUT MONITOR] Cycle %0d: WEST Output detected: pkt=%x\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,vlSelfRef.simple_test__DOT__last_output_pkt);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy))))) {
            __Vfunc_simple_test__DOT__encode_packet__3__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r);
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__3__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                  >> 8U));
            vlSelfRef.simple_test__DOT__last_output_port = 2U;
            __Vfunc_simple_test__DOT__encode_packet__3__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                  >> 0x0000000eU));
            __Vfunc_simple_test__DOT__encode_packet__3__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                         >> 0x00000014U));
            __Vfunc_simple_test__DOT__encode_packet__3__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                         >> 0x00000015U));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                         2,__Vfunc_simple_test__DOT__encode_packet__3__pkt_type,
                         1,(IData)(__Vfunc_simple_test__DOT__encode_packet__3__pkt_qos),
                         6,__Vfunc_simple_test__DOT__encode_packet__3__src_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__3__src_id),
                         6,__Vfunc_simple_test__DOT__encode_packet__3__tgt_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__3__tgt_id),
                         8,__Vfunc_simple_test__DOT__encode_packet__3__data);
            __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__3__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__3__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__3__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__3__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__3__data)));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                         23,__Vfunc_simple_test__DOT__encode_packet__3__Vfuncout);
            __Vdly__simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout;
            VL_WRITEF_NX("[OUTPUT MONITOR] Cycle %0d: SOUTH Output detected: pkt=%x\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,vlSelfRef.simple_test__DOT__last_output_pkt);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy))))) {
            __Vfunc_simple_test__DOT__encode_packet__4__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r);
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__4__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                  >> 8U));
            vlSelfRef.simple_test__DOT__last_output_port = 3U;
            __Vfunc_simple_test__DOT__encode_packet__4__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                  >> 0x0000000eU));
            __Vfunc_simple_test__DOT__encode_packet__4__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                         >> 0x00000014U));
            __Vfunc_simple_test__DOT__encode_packet__4__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                         >> 0x00000015U));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function inputs: type=%1#, qos=%1#, src=%2#(0b%b), tgt=%2#(0b%b), data=0x%02x\n",0,
                         2,__Vfunc_simple_test__DOT__encode_packet__4__pkt_type,
                         1,(IData)(__Vfunc_simple_test__DOT__encode_packet__4__pkt_qos),
                         6,__Vfunc_simple_test__DOT__encode_packet__4__src_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__4__src_id),
                         6,__Vfunc_simple_test__DOT__encode_packet__4__tgt_id,
                         6,(IData)(__Vfunc_simple_test__DOT__encode_packet__4__tgt_id),
                         8,__Vfunc_simple_test__DOT__encode_packet__4__data);
            __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__4__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__4__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__4__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__4__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__4__data)));
            VL_WRITEF_NX("[ENCODE_DEBUG] Function result: %x\n",0,
                         23,__Vfunc_simple_test__DOT__encode_packet__4__Vfuncout);
            __Vdly__simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout;
            VL_WRITEF_NX("[OUTPUT MONITOR] Cycle %0d: EAST Output detected:\n  Raw signals: vld=%1#, rdy=%1#, type=%1#, qos=%1#, src=%2#, tgt=%2#, data=0x%02x\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         1,(IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r),
                         1,vlSelfRef.simple_test__DOT__pkt_con_eo_rdy,
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                  >> 0x00000014U)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                           >> 0x0000000eU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                           >> 8U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r));
            vlSelfRef.simple_test__DOT__manual_encoded 
                = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r;
            VL_WRITEF_NX("  Manual encoded: %x\n  Function result: %x\n  Match: %b\n",0,
                         23,vlSelfRef.simple_test__DOT__manual_encoded,
                         23,vlSelfRef.simple_test__DOT__last_output_pkt,
                         1,(vlSelfRef.simple_test__DOT__manual_encoded 
                            == vlSelfRef.simple_test__DOT__last_output_pkt));
        }
        if (VL_LTS_III(32, 0x0000000aU, vlSelfRef.simple_test__DOT__test_cycle)) {
            vlSelfRef.simple_test__DOT__first_10_cycles_debug = 0U;
        }
    } else {
        vlSelfRef.simple_test__DOT__irs_status_a = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__irs_status_n = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__irs_status_w = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__irs_status_s = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__irs_status_e = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__irs_status_b = 
            Vsimple_test_simple_test__DOT__irs_status_t__struct__0{
            .__PVT__input_valid = (CData)(0U), .__PVT__input_ready = (CData)(0U), 
            .__PVT__output_valid = (CData)(0U), .__PVT__output_ready = (CData)(0U), 
            .__PVT__input_payload = (IData)(0U), .__PVT__output_payload = (IData)(0U), 
            .__PVT__depth_count = (IData)(0U)};
        vlSelfRef.simple_test__DOT__last_output_valid = 0U;
        __Vdly__simple_test__DOT__last_output_pkt = 0U;
        vlSelfRef.simple_test__DOT__last_output_port = 0U;
    }
    vlSelfRef.simple_test__DOT__last_output_pkt = __Vdly__simple_test__DOT__last_output_pkt;
    vlSelfRef.simple_test__DOT__test_cycle = __Vdly__simple_test__DOT__test_cycle;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r;
}

void Vsimple_test___024root___nba_comb__TOP__0(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

void Vsimple_test___024root___nba_sequent__TOP__1(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_sequent__TOP__1\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2 = 0;
    CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3 = 0;
    // Body
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload1_r
                : 0U);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload1_r
                : 0U);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload1_r
                : 0U);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload1_r
                : 0U);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i;
    }
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2 
        = ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r 
                  >> 0x00000013U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r 
                                            >> 0x00000014U)));
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                  >> 0x00000011U)) | ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                             >> 0x00000012U)) 
                                      | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2)));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3 
        = ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r 
                  >> 0x00000012U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_2));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                  >> 0x00000011U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r 
                           >> 0x00000010U)) | ((8U 
                                                & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r 
                                                   >> 0x00000011U)) 
                                               | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h1fa7bacc_0_3)));
}

extern const VlUnpacked<CData/*1:0*/, 32> Vsimple_test__ConstPool__TABLE_h28d0bcb6_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsimple_test__ConstPool__TABLE_h3b34c9f4_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vsimple_test__ConstPool__TABLE_h24174b10_0;

void Vsimple_test___024root___nba_sequent__TOP__2(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_sequent__TOP__2\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    // Body
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r;
    __Vtableidx1 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx1];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx1])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx1];
    }
    __Vtableidx2 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx2];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx2];
    }
    __Vtableidx3 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx3];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx3];
    }
    __Vtableidx4 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx4];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx4];
    }
    __Vtableidx5 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx5];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx5];
    }
}

void Vsimple_test___024root___nba_comb__TOP__1(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__1\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i 
        = ((((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type) 
             << 0x00000015U) | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos) 
                                 << 0x00000014U) | 
                                ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src) 
                                 << 0x0000000eU))) 
           | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt) 
               << 8U) | (IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data)));
}

void Vsimple_test___024root___nba_comb__TOP__2(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__2\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
}

void Vsimple_test___024root___nba_comb__TOP__3(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__3\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld) 
           | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT____VdfgRegularize_h8f1dd18b_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r) {
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
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r) {
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
    }
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

void Vsimple_test___024root___eval_nba(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_nba\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_test___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vsimple_test___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_test___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_test___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vsimple_test___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_test___024root___nba_comb__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vsimple_test___024root___nba_comb__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
}

void Vsimple_test___024root___timing_commit(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___timing_commit\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_hf3e272e8__0.commit(
                                                   "@(posedge simple_test.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h98ce37a2__0.commit(
                                                   "@(posedge (32'sh5 * simple_test.clk))");
    }
}

void Vsimple_test___024root___timing_resume(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___timing_resume\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hf3e272e8__0.resume(
                                                   "@(posedge simple_test.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h98ce37a2__0.resume(
                                                   "@(posedge (32'sh5 * simple_test.clk))");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsimple_test___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsimple_test___024root___eval_phase__act(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_phase__act\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vsimple_test___024root___eval_triggers__act(vlSelf);
    Vsimple_test___024root___timing_commit(vlSelf);
    Vsimple_test___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vsimple_test___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vsimple_test___024root___timing_resume(vlSelf);
        Vsimple_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsimple_test___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsimple_test___024root___eval_phase__nba(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_phase__nba\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsimple_test___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vsimple_test___024root___eval_nba(vlSelf);
        Vsimple_test___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsimple_test___024root___eval(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsimple_test___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsimple_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/liangmx/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vsimple_test___024root___eval_phase__act(vlSelf));
    } while (Vsimple_test___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vsimple_test___024root___eval_debug_assertions(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_debug_assertions\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG

std::string VL_TO_STRING(const Vsimple_test_simple_test__DOT__irs_status_t__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{input_valid:" + VL_TO_STRING(obj.__PVT__input_valid);
    out += ", input_ready:" + VL_TO_STRING(obj.__PVT__input_ready);
    out += ", output_valid:" + VL_TO_STRING(obj.__PVT__output_valid);
    out += ", output_ready:" + VL_TO_STRING(obj.__PVT__output_ready);
    out += ", input_payload:" + VL_TO_STRING(obj.__PVT__input_payload);
    out += ", output_payload:" + VL_TO_STRING(obj.__PVT__output_payload);
    out += ", depth_count:" + VL_TO_STRING(obj.__PVT__depth_count);
    out += "}";
    return (out);
}
