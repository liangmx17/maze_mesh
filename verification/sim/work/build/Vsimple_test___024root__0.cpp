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
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__10__pkt_type;
    __Vtask_simple_test__DOT__send_packet__10__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__10__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__10__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__10__src_id;
    __Vtask_simple_test__DOT__send_packet__10__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__10__tgt_id;
    __Vtask_simple_test__DOT__send_packet__10__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__10__data;
    __Vtask_simple_test__DOT__send_packet__10__data = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__10__timeout;
    __Vtask_simple_test__DOT__send_packet__10__timeout = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__11__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__11__x;
    __Vfunc_simple_test__DOT__calc_node_id__11__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__11__y;
    __Vfunc_simple_test__DOT__calc_node_id__11__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__12__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__12__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__12__x;
    __Vfunc_simple_test__DOT__calc_node_id__12__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__12__y;
    __Vfunc_simple_test__DOT__calc_node_id__12__y = 0;
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__13__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__13__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__13__expected_port;
    __Vtask_simple_test__DOT__verify_output__13__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__13__timeout;
    __Vtask_simple_test__DOT__verify_output__13__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__13__match_found;
    __Vtask_simple_test__DOT__verify_output__13__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__14__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__14__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__14__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__14__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__14__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__14__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__14__src_id;
    __Vfunc_simple_test__DOT__encode_packet__14__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__14__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__14__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__14__data;
    __Vfunc_simple_test__DOT__encode_packet__14__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__x;
    __Vfunc_simple_test__DOT__calc_node_id__15__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__15__y;
    __Vfunc_simple_test__DOT__calc_node_id__15__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__16__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__16__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__16__x;
    __Vfunc_simple_test__DOT__calc_node_id__16__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__16__y;
    __Vfunc_simple_test__DOT__calc_node_id__16__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__17__pkt_type;
    __Vtask_simple_test__DOT__send_packet__17__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__17__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__17__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__17__src_id;
    __Vtask_simple_test__DOT__send_packet__17__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__17__tgt_id;
    __Vtask_simple_test__DOT__send_packet__17__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__17__data;
    __Vtask_simple_test__DOT__send_packet__17__data = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__17__timeout;
    __Vtask_simple_test__DOT__send_packet__17__timeout = 0;
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
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__20__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__20__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__20__expected_port;
    __Vtask_simple_test__DOT__verify_output__20__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__20__timeout;
    __Vtask_simple_test__DOT__verify_output__20__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__20__match_found;
    __Vtask_simple_test__DOT__verify_output__20__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__21__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__21__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__21__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__21__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__21__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__21__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__21__src_id;
    __Vfunc_simple_test__DOT__encode_packet__21__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__21__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__21__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__21__data;
    __Vfunc_simple_test__DOT__encode_packet__21__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__x;
    __Vfunc_simple_test__DOT__calc_node_id__22__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__22__y;
    __Vfunc_simple_test__DOT__calc_node_id__22__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__23__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__23__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__23__x;
    __Vfunc_simple_test__DOT__calc_node_id__23__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__23__y;
    __Vfunc_simple_test__DOT__calc_node_id__23__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__24__pkt_type;
    __Vtask_simple_test__DOT__send_packet__24__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__24__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__24__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__24__src_id;
    __Vtask_simple_test__DOT__send_packet__24__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__24__tgt_id;
    __Vtask_simple_test__DOT__send_packet__24__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__24__data;
    __Vtask_simple_test__DOT__send_packet__24__data = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__24__timeout;
    __Vtask_simple_test__DOT__send_packet__24__timeout = 0;
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
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__27__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__27__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__27__expected_port;
    __Vtask_simple_test__DOT__verify_output__27__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__27__timeout;
    __Vtask_simple_test__DOT__verify_output__27__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__27__match_found;
    __Vtask_simple_test__DOT__verify_output__27__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__28__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__28__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__28__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__28__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__28__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__28__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__28__src_id;
    __Vfunc_simple_test__DOT__encode_packet__28__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__28__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__28__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__28__data;
    __Vfunc_simple_test__DOT__encode_packet__28__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__x;
    __Vfunc_simple_test__DOT__calc_node_id__29__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__29__y;
    __Vfunc_simple_test__DOT__calc_node_id__29__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__30__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__30__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__30__x;
    __Vfunc_simple_test__DOT__calc_node_id__30__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__30__y;
    __Vfunc_simple_test__DOT__calc_node_id__30__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__31__pkt_type;
    __Vtask_simple_test__DOT__send_packet__31__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__31__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__31__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__31__src_id;
    __Vtask_simple_test__DOT__send_packet__31__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__31__tgt_id;
    __Vtask_simple_test__DOT__send_packet__31__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__31__data;
    __Vtask_simple_test__DOT__send_packet__31__data = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__31__timeout;
    __Vtask_simple_test__DOT__send_packet__31__timeout = 0;
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
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__34__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__34__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__34__expected_port;
    __Vtask_simple_test__DOT__verify_output__34__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__34__timeout;
    __Vtask_simple_test__DOT__verify_output__34__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__34__match_found;
    __Vtask_simple_test__DOT__verify_output__34__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__35__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__35__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__35__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__35__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__35__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__35__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__35__src_id;
    __Vfunc_simple_test__DOT__encode_packet__35__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__35__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__35__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__35__data;
    __Vfunc_simple_test__DOT__encode_packet__35__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__x;
    __Vfunc_simple_test__DOT__calc_node_id__36__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__36__y;
    __Vfunc_simple_test__DOT__calc_node_id__36__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__37__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__37__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__37__x;
    __Vfunc_simple_test__DOT__calc_node_id__37__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__37__y;
    __Vfunc_simple_test__DOT__calc_node_id__37__y = 0;
    CData/*1:0*/ __Vtask_simple_test__DOT__send_packet__38__pkt_type;
    __Vtask_simple_test__DOT__send_packet__38__pkt_type = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__send_packet__38__pkt_qos;
    __Vtask_simple_test__DOT__send_packet__38__pkt_qos = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__38__src_id;
    __Vtask_simple_test__DOT__send_packet__38__src_id = 0;
    CData/*5:0*/ __Vtask_simple_test__DOT__send_packet__38__tgt_id;
    __Vtask_simple_test__DOT__send_packet__38__tgt_id = 0;
    CData/*7:0*/ __Vtask_simple_test__DOT__send_packet__38__data;
    __Vtask_simple_test__DOT__send_packet__38__data = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__send_packet__38__timeout;
    __Vtask_simple_test__DOT__send_packet__38__timeout = 0;
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
    IData/*22:0*/ __Vtask_simple_test__DOT__verify_output__41__expected_pkt;
    __Vtask_simple_test__DOT__verify_output__41__expected_pkt = 0;
    CData/*2:0*/ __Vtask_simple_test__DOT__verify_output__41__expected_port;
    __Vtask_simple_test__DOT__verify_output__41__expected_port = 0;
    IData/*31:0*/ __Vtask_simple_test__DOT__verify_output__41__timeout;
    __Vtask_simple_test__DOT__verify_output__41__timeout = 0;
    CData/*0:0*/ __Vtask_simple_test__DOT__verify_output__41__match_found;
    __Vtask_simple_test__DOT__verify_output__41__match_found = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__42__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__42__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__42__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__42__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__42__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__42__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__42__src_id;
    __Vfunc_simple_test__DOT__encode_packet__42__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__42__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__42__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__42__data;
    __Vfunc_simple_test__DOT__encode_packet__42__data = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__x;
    __Vfunc_simple_test__DOT__calc_node_id__43__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__43__y;
    __Vfunc_simple_test__DOT__calc_node_id__43__y = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__calc_node_id__44__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__44__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__44__x;
    __Vfunc_simple_test__DOT__calc_node_id__44__x = 0;
    IData/*31:0*/ __Vfunc_simple_test__DOT__calc_node_id__44__y;
    __Vfunc_simple_test__DOT__calc_node_id__44__y = 0;
    // Body
    VL_WRITEF_NX("==============================================\nMAZE\350\212\202\347\202\271\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225\n\346\265\213\350\257\225\350\212\202\347\202\271: (3, 3)\n==============================================\n",0);
    vlSelfRef.simple_test__DOT__clk = 0U;
    vlSelfRef.simple_test__DOT__rst_n = 0U;
    vlSelfRef.simple_test__DOT__pg_en = 0U;
    vlSelfRef.simple_test__DOT__pg_node = 0U;
    vlSelfRef.simple_test__DOT__test_cycle = 0U;
    vlSelfRef.simple_test__DOT__error_count = 0U;
    vlSelfRef.simple_test__DOT__test_count = 0U;
    vlSelfRef.simple_test__DOT__pass_count = 0U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_no_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_wo_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_so_rdy = 1U;
    vlSelfRef.simple_test__DOT__pkt_con_eo_rdy = 1U;
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         462);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         463);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__rst_n = 1U;
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         465);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         466);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\345\244\215\344\275\215\345\256\214\346\210\220\357\274\214\345\274\200\345\247\213\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225...\n\n--- N-RF-001: X\346\226\271\345\220\221\346\255\243\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__10__data = 0xa5U;
    __Vfunc_simple_test__DOT__calc_node_id__11__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__11__x = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__11__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__11__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__11__x));
    __Vtask_simple_test__DOT__send_packet__10__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__11__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__12__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__12__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__12__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__12__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__12__x));
    __Vtask_simple_test__DOT__send_packet__10__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__12__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__10__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__10__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__10__timeout = 0;
    VL_WRITEF_NX("[Cycle %0d] Sending packet: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__10__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__10__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__10__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__10__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__10__data));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__10__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__10__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__10__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__10__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__10__data;
    __Vtask_simple_test__DOT__send_packet__10__timeout = 0x00000064U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__10__timeout))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             388);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__10__timeout 
            = (__Vtask_simple_test__DOT__send_packet__10__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_simple_test__DOT__send_packet__10__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         398);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    __Vtask_simple_test__DOT__verify_output__13__expected_port = 3U;
    __Vfunc_simple_test__DOT__encode_packet__14__data = 0xa5U;
    __Vfunc_simple_test__DOT__calc_node_id__15__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__15__x = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__15__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__15__x));
    __Vfunc_simple_test__DOT__encode_packet__14__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__15__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__16__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__16__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__16__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__16__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__16__x));
    __Vfunc_simple_test__DOT__encode_packet__14__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__16__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__14__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__14__pkt_type = 0U;
    __Vfunc_simple_test__DOT__encode_packet__14__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__14__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__14__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__14__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__14__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__14__data)));
    __Vtask_simple_test__DOT__verify_output__13__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__14__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__13__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__13__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__13__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__13__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__13__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__13__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__13__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__13__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             417);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__13__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__13__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__13__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__13__timeout 
            = (__Vtask_simple_test__DOT__verify_output__13__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__13__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__13__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__13__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h1cfde055__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         479);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-002: X\346\226\271\345\220\221\345\217\215\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__17__data = 0x5aU;
    __Vfunc_simple_test__DOT__calc_node_id__18__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__18__x = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__18__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__18__x));
    __Vtask_simple_test__DOT__send_packet__17__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__18__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__19__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__19__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__19__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__19__x));
    __Vtask_simple_test__DOT__send_packet__17__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__19__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__17__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__17__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__17__timeout = 0;
    VL_WRITEF_NX("[Cycle %0d] Sending packet: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__17__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__17__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__17__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__17__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__17__data));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__17__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__17__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__17__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__17__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__17__data;
    __Vtask_simple_test__DOT__send_packet__17__timeout = 0x00000064U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__17__timeout))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             388);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__17__timeout 
            = (__Vtask_simple_test__DOT__send_packet__17__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_simple_test__DOT__send_packet__17__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         398);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    __Vtask_simple_test__DOT__verify_output__20__expected_port = 1U;
    __Vfunc_simple_test__DOT__encode_packet__21__data = 0x5aU;
    __Vfunc_simple_test__DOT__calc_node_id__22__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__22__x = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__22__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__22__x));
    __Vfunc_simple_test__DOT__encode_packet__21__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__22__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__23__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__23__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__23__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__23__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__23__x));
    __Vfunc_simple_test__DOT__encode_packet__21__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__23__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__21__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__21__pkt_type = 0U;
    __Vfunc_simple_test__DOT__encode_packet__21__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__21__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__21__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__21__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__21__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__21__data)));
    __Vtask_simple_test__DOT__verify_output__20__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__21__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__20__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__20__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__20__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__20__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__20__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__20__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__20__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__20__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             417);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__20__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__20__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__20__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__20__timeout 
            = (__Vtask_simple_test__DOT__verify_output__20__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__20__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__20__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__20__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h1cfde055__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         489);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-003: Y\346\226\271\345\220\221\346\255\243\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__24__data = 0x33U;
    __Vfunc_simple_test__DOT__calc_node_id__25__y = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__25__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__25__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__25__x));
    __Vtask_simple_test__DOT__send_packet__24__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__25__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__26__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__26__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__26__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__26__x));
    __Vtask_simple_test__DOT__send_packet__24__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__26__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__24__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__24__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__24__timeout = 0;
    VL_WRITEF_NX("[Cycle %0d] Sending packet: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__24__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__24__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__24__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__24__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__24__data));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__24__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__24__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__24__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__24__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__24__data;
    __Vtask_simple_test__DOT__send_packet__24__timeout = 0x00000064U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__24__timeout))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             388);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__24__timeout 
            = (__Vtask_simple_test__DOT__send_packet__24__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_simple_test__DOT__send_packet__24__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         398);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    __Vtask_simple_test__DOT__verify_output__27__expected_port = 0U;
    __Vfunc_simple_test__DOT__encode_packet__28__data = 0x33U;
    __Vfunc_simple_test__DOT__calc_node_id__29__y = 4U;
    __Vfunc_simple_test__DOT__calc_node_id__29__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__29__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__29__x));
    __Vfunc_simple_test__DOT__encode_packet__28__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__29__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__30__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__30__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__30__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__30__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__30__x));
    __Vfunc_simple_test__DOT__encode_packet__28__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__30__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__28__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__28__pkt_type = 0U;
    __Vfunc_simple_test__DOT__encode_packet__28__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__28__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__28__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__28__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__28__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__28__data)));
    __Vtask_simple_test__DOT__verify_output__27__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__28__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__27__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__27__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__27__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__27__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__27__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__27__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__27__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__27__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             417);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__27__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__27__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__27__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__27__timeout 
            = (__Vtask_simple_test__DOT__verify_output__27__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__27__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__27__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__27__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h1cfde055__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         499);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-004: Y\346\226\271\345\220\221\345\217\215\345\220\221\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__31__data = 0xccU;
    __Vfunc_simple_test__DOT__calc_node_id__32__y = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__32__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__32__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__32__x));
    __Vtask_simple_test__DOT__send_packet__31__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__32__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__33__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__33__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__33__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__33__x));
    __Vtask_simple_test__DOT__send_packet__31__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__33__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__31__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__31__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__31__timeout = 0;
    VL_WRITEF_NX("[Cycle %0d] Sending packet: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__31__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__31__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__31__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__31__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__31__data));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__31__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__31__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__31__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__31__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__31__data;
    __Vtask_simple_test__DOT__send_packet__31__timeout = 0x00000064U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__31__timeout))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             388);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__31__timeout 
            = (__Vtask_simple_test__DOT__send_packet__31__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_simple_test__DOT__send_packet__31__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         398);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    __Vtask_simple_test__DOT__verify_output__34__expected_port = 2U;
    __Vfunc_simple_test__DOT__encode_packet__35__data = 0xccU;
    __Vfunc_simple_test__DOT__calc_node_id__36__y = 2U;
    __Vfunc_simple_test__DOT__calc_node_id__36__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__36__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__36__x));
    __Vfunc_simple_test__DOT__encode_packet__35__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__36__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__37__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__37__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__37__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__37__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__37__x));
    __Vfunc_simple_test__DOT__encode_packet__35__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__37__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__35__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__35__pkt_type = 0U;
    __Vfunc_simple_test__DOT__encode_packet__35__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__35__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__35__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__35__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__35__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__35__data)));
    __Vtask_simple_test__DOT__verify_output__34__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__35__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__34__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__34__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__34__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__34__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__34__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__34__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__34__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__34__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             417);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__34__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__34__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__34__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__34__timeout 
            = (__Vtask_simple_test__DOT__verify_output__34__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__34__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__34__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__34__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h1cfde055__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sh5 * simple_test.clk))", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         509);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("--- N-RF-005: \346\234\254\345\234\260\350\267\257\347\224\261\346\265\213\350\257\225 ---\n",0);
    __Vtask_simple_test__DOT__send_packet__38__data = 0xffU;
    __Vfunc_simple_test__DOT__calc_node_id__39__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__39__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__39__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__39__x));
    __Vtask_simple_test__DOT__send_packet__38__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__39__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__40__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__40__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__40__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__40__x));
    __Vtask_simple_test__DOT__send_packet__38__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__40__Vfuncout;
    __Vtask_simple_test__DOT__send_packet__38__pkt_qos = 0U;
    __Vtask_simple_test__DOT__send_packet__38__pkt_type = 0U;
    __Vtask_simple_test__DOT__send_packet__38__timeout = 0;
    VL_WRITEF_NX("[Cycle %0d] Sending packet: Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 2,(IData)(__Vtask_simple_test__DOT__send_packet__38__pkt_type),
                 1,__Vtask_simple_test__DOT__send_packet__38__pkt_qos,
                 6,(IData)(__Vtask_simple_test__DOT__send_packet__38__src_id),
                 6,__Vtask_simple_test__DOT__send_packet__38__tgt_id,
                 8,(IData)(__Vtask_simple_test__DOT__send_packet__38__data));
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type = __Vtask_simple_test__DOT__send_packet__38__pkt_type;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos = __Vtask_simple_test__DOT__send_packet__38__pkt_qos;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src = __Vtask_simple_test__DOT__send_packet__38__src_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt = __Vtask_simple_test__DOT__send_packet__38__tgt_id;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data = __Vtask_simple_test__DOT__send_packet__38__data;
    __Vtask_simple_test__DOT__send_packet__38__timeout = 0x00000064U;
    while (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            & VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__send_packet__38__timeout))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             388);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_simple_test__DOT__send_packet__38__timeout 
            = (__Vtask_simple_test__DOT__send_packet__38__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U == __Vtask_simple_test__DOT__send_packet__38__timeout)))) {
        VL_WRITEF_NX("ERROR: Timeout waiting for pkt_in_rdy\n",0);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge simple_test.clk)", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         398);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld = 0U;
    __Vtask_simple_test__DOT__verify_output__41__expected_port = 4U;
    __Vfunc_simple_test__DOT__encode_packet__42__data = 0xffU;
    __Vfunc_simple_test__DOT__calc_node_id__43__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__43__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__43__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__43__x));
    __Vfunc_simple_test__DOT__encode_packet__42__tgt_id 
        = __Vfunc_simple_test__DOT__calc_node_id__43__Vfuncout;
    __Vfunc_simple_test__DOT__calc_node_id__44__y = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__44__x = 3U;
    __Vfunc_simple_test__DOT__calc_node_id__44__Vfuncout 
        = ((0x00000038U & (__Vfunc_simple_test__DOT__calc_node_id__44__y 
                           << 3U)) | (7U & __Vfunc_simple_test__DOT__calc_node_id__44__x));
    __Vfunc_simple_test__DOT__encode_packet__42__src_id 
        = __Vfunc_simple_test__DOT__calc_node_id__44__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__42__pkt_qos = 0U;
    __Vfunc_simple_test__DOT__encode_packet__42__pkt_type = 0U;
    __Vfunc_simple_test__DOT__encode_packet__42__Vfuncout 
        = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__42__pkt_type) 
             << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__42__pkt_qos) 
                                 << 0x00000014U) | 
                                ((IData)(__Vfunc_simple_test__DOT__encode_packet__42__src_id) 
                                 << 0x0000000eU))) 
           | (((IData)(__Vfunc_simple_test__DOT__encode_packet__42__tgt_id) 
               << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__42__data)));
    __Vtask_simple_test__DOT__verify_output__41__expected_pkt 
        = __Vfunc_simple_test__DOT__encode_packet__42__Vfuncout;
    __Vtask_simple_test__DOT__verify_output__41__timeout = 0;
    __Vtask_simple_test__DOT__verify_output__41__match_found = 0;
    __Vtask_simple_test__DOT__verify_output__41__timeout = 0x00000032U;
    __Vtask_simple_test__DOT__verify_output__41__match_found = 0U;
    VL_WRITEF_NX("[Cycle %0d] Waiting for expected output on port %1#: %x\n",0,
                 32,vlSelfRef.simple_test__DOT__test_cycle,
                 3,(IData)(__Vtask_simple_test__DOT__verify_output__41__expected_port),
                 23,__Vtask_simple_test__DOT__verify_output__41__expected_pkt);
    while ((VL_LTS_III(32, 0U, __Vtask_simple_test__DOT__verify_output__41__timeout) 
            & (~ (IData)(__Vtask_simple_test__DOT__verify_output__41__match_found)))) {
        co_await vlSelfRef.__VtrigSched_hb092edad__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge simple_test.clk)", 
                                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                             417);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if (VL_UNLIKELY(((((IData)(vlSelfRef.simple_test__DOT__last_output_valid) 
                           & (vlSelfRef.simple_test__DOT__last_output_pkt 
                              == __Vtask_simple_test__DOT__verify_output__41__expected_pkt)) 
                          & ((IData)(vlSelfRef.simple_test__DOT__last_output_port) 
                             == (IData)(__Vtask_simple_test__DOT__verify_output__41__expected_port)))))) {
            __Vtask_simple_test__DOT__verify_output__41__match_found = 1U;
            VL_WRITEF_NX("[Cycle %0d] PASS: Expected output found\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle);
            vlSelfRef.simple_test__DOT__pass_count 
                = ((IData)(1U) + vlSelfRef.simple_test__DOT__pass_count);
        }
        __Vtask_simple_test__DOT__verify_output__41__timeout 
            = (__Vtask_simple_test__DOT__verify_output__41__timeout 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_simple_test__DOT__verify_output__41__match_found)))))) {
        VL_WRITEF_NX("ERROR: Expected output not found\n  Expected: Port=%1#, Pkt=%x\n",0,
                     3,__Vtask_simple_test__DOT__verify_output__41__expected_port,
                     23,__Vtask_simple_test__DOT__verify_output__41__expected_pkt);
        vlSelfRef.simple_test__DOT__error_count = ((IData)(1U) 
                                                   + vlSelfRef.simple_test__DOT__error_count);
    }
    vlSelfRef.simple_test__DOT__test_count = ((IData)(1U) 
                                              + vlSelfRef.simple_test__DOT__test_count);
    co_await vlSelfRef.__VtrigSched_h1d6373ea__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge (32'sha * simple_test.clk))", 
                                                         "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                                         515);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\n==============================================\n\346\265\213\350\257\225\346\200\273\347\273\223\n==============================================\n\346\200\273\346\265\213\350\257\225\346\225\260: %0d\n\351\200\232\350\277\207\346\265\213\350\257\225: %0d\n\345\244\261\350\264\245\346\265\213\350\257\225: %0d\n\351\200\232\350\277\207\347\216\207: %0.2f%%\n",0,
                 32,vlSelfRef.simple_test__DOT__test_count,
                 32,vlSelfRef.simple_test__DOT__pass_count,
                 32,vlSelfRef.simple_test__DOT__error_count,
                 64,(VL_LTS_III(32, 0U, vlSelfRef.simple_test__DOT__test_count)
                      ? ((100.0 * VL_ISTOR_D_I(32, vlSelfRef.simple_test__DOT__pass_count)) 
                         / VL_ISTOR_D_I(32, vlSelfRef.simple_test__DOT__test_count))
                      : 0.0));
    if ((0U == vlSelfRef.simple_test__DOT__error_count)) {
        VL_WRITEF_NX("\342\234\223 \346\211\200\346\234\211\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225\351\200\232\350\277\207\357\274\201\n",0);
    } else {
        VL_WRITEF_NX("\342\234\227 \351\203\250\345\210\206\345\237\272\346\234\254\350\267\257\347\224\261\345\212\237\350\203\275\346\265\213\350\257\225\345\244\261\350\264\245\n",0);
    }
    VL_WRITEF_NX("==============================================\n",0);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                         nullptr, "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                         536);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 537, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__1(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000005f5e100ULL, 
                                         nullptr, "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                         542);
    VL_WRITEF_NX("ERROR: \346\265\213\350\257\225\350\266\205\346\227\266\357\274\201\n",0);
    VL_FINISH_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 544, "");
}

VlCoroutine Vsimple_test___024root___eval_initial__TOP__Vtiming__2(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 
                                             274);
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
    IData/*31:0*/ __Vtrigprevexpr_hc94a28ed__0;
    __Vtrigprevexpr_hc94a28ed__0 = 0;
    IData/*31:0*/ __Vtrigprevexpr_hc954b698__0;
    __Vtrigprevexpr_hc954b698__0 = 0;
    // Body
    __Vtrigprevexpr_hc94a28ed__0 = ((IData)(5U) * (IData)(vlSelfRef.simple_test__DOT__clk));
    __Vtrigprevexpr_hc954b698__0 = ((IData)(0x0000000aU) 
                                    * (IData)(vlSelfRef.simple_test__DOT__clk));
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 4U) 
                                                     | ((((2U 
                                                           & ((__Vtrigprevexpr_hc954b698__0 
                                                               & (~ vlSelfRef.__Vtrigprevexpr_hc954b698__1)) 
                                                              << 1U)) 
                                                          | (1U 
                                                             & (__Vtrigprevexpr_hc94a28ed__0 
                                                                & (~ vlSelfRef.__Vtrigprevexpr_hc94a28ed__1)))) 
                                                         << 2U) 
                                                        | ((((~ (IData)(vlSelfRef.simple_test__DOT__rst_n)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0)) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.simple_test__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__clk__0 
        = vlSelfRef.simple_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0 
        = vlSelfRef.simple_test__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr_hc94a28ed__1 = __Vtrigprevexpr_hc94a28ed__0;
    vlSelfRef.__Vtrigprevexpr_hc954b698__1 = __Vtrigprevexpr_hc954b698__0;
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
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

void Vsimple_test___024root___eval_act(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___eval_act\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000001dULL & vlSelfRef.__VactTriggered
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
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__5__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__5__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__5__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__5__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__5__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__5__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__5__src_id;
    __Vfunc_simple_test__DOT__encode_packet__5__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__5__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__5__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__5__data;
    __Vfunc_simple_test__DOT__encode_packet__5__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__6__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__6__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__6__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__6__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__6__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__6__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__6__src_id;
    __Vfunc_simple_test__DOT__encode_packet__6__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__6__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__6__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__6__data;
    __Vfunc_simple_test__DOT__encode_packet__6__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__7__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__7__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__7__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__7__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__7__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__7__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__7__src_id;
    __Vfunc_simple_test__DOT__encode_packet__7__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__7__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__7__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__7__data;
    __Vfunc_simple_test__DOT__encode_packet__7__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__8__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__8__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__8__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__8__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__8__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__8__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__8__src_id;
    __Vfunc_simple_test__DOT__encode_packet__8__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__8__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__8__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__8__data;
    __Vfunc_simple_test__DOT__encode_packet__8__data = 0;
    IData/*22:0*/ __Vfunc_simple_test__DOT__encode_packet__9__Vfuncout;
    __Vfunc_simple_test__DOT__encode_packet__9__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_simple_test__DOT__encode_packet__9__pkt_type;
    __Vfunc_simple_test__DOT__encode_packet__9__pkt_type = 0;
    CData/*0:0*/ __Vfunc_simple_test__DOT__encode_packet__9__pkt_qos;
    __Vfunc_simple_test__DOT__encode_packet__9__pkt_qos = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__9__src_id;
    __Vfunc_simple_test__DOT__encode_packet__9__src_id = 0;
    CData/*5:0*/ __Vfunc_simple_test__DOT__encode_packet__9__tgt_id;
    __Vfunc_simple_test__DOT__encode_packet__9__tgt_id = 0;
    CData/*7:0*/ __Vfunc_simple_test__DOT__encode_packet__9__data;
    __Vfunc_simple_test__DOT__encode_packet__9__data = 0;
    IData/*31:0*/ __Vdly__simple_test__DOT__test_cycle;
    __Vdly__simple_test__DOT__test_cycle = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0;
    CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0;
    // Body
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    if (vlSelfRef.simple_test__DOT__rst_n) {
        __Vdly__simple_test__DOT__test_cycle = ((IData)(1U) 
                                                + vlSelfRef.simple_test__DOT__test_cycle);
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
            vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        }
        if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 1U;
        } else if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
            __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        }
    } else {
        __Vdly__simple_test__DOT__test_cycle = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
        __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r = 0U;
    }
    if (vlSelfRef.simple_test__DOT__rst_n) {
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy))))) {
            VL_WRITEF_NX("[Cycle %0d] Local Output: %x (Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,([&]() {
                            __Vfunc_simple_test__DOT__encode_packet__0__data 
                                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
                            __Vfunc_simple_test__DOT__encode_packet__0__tgt_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 9U));
                            __Vfunc_simple_test__DOT__encode_packet__0__src_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 0x0000000fU));
                            __Vfunc_simple_test__DOT__encode_packet__0__pkt_qos 
                                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 8U));
                            __Vfunc_simple_test__DOT__encode_packet__0__pkt_type 
                                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 0x00000015U));
                            __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout 
                                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__0__pkt_type) 
                                     << 0x00000015U) 
                                    | (((IData)(__Vfunc_simple_test__DOT__encode_packet__0__pkt_qos) 
                                        << 0x00000014U) 
                                       | ((IData)(__Vfunc_simple_test__DOT__encode_packet__0__src_id) 
                                          << 0x0000000eU))) 
                                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__0__tgt_id) 
                                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__0__data)));
                        }(), __Vfunc_simple_test__DOT__encode_packet__0__Vfuncout),
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U)),6,(0x0000003fU 
                                             & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                           >> 9U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r));
            __Vfunc_simple_test__DOT__encode_packet__1__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            __Vfunc_simple_test__DOT__encode_packet__1__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 9U));
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__1__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000fU));
            vlSelfRef.simple_test__DOT__last_output_port = 4U;
            __Vfunc_simple_test__DOT__encode_packet__1__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 8U));
            __Vfunc_simple_test__DOT__encode_packet__1__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__1__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__1__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__1__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__1__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__1__data)));
            vlSelfRef.simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__1__Vfuncout;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy))))) {
            VL_WRITEF_NX("[Cycle %0d] North Output: %x (Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,([&]() {
                            __Vfunc_simple_test__DOT__encode_packet__2__data 
                                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
                            __Vfunc_simple_test__DOT__encode_packet__2__tgt_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 9U));
                            __Vfunc_simple_test__DOT__encode_packet__2__src_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 0x0000000fU));
                            __Vfunc_simple_test__DOT__encode_packet__2__pkt_qos 
                                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 8U));
                            __Vfunc_simple_test__DOT__encode_packet__2__pkt_type 
                                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 0x00000015U));
                            __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout 
                                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__2__pkt_type) 
                                     << 0x00000015U) 
                                    | (((IData)(__Vfunc_simple_test__DOT__encode_packet__2__pkt_qos) 
                                        << 0x00000014U) 
                                       | ((IData)(__Vfunc_simple_test__DOT__encode_packet__2__src_id) 
                                          << 0x0000000eU))) 
                                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__2__tgt_id) 
                                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__2__data)));
                        }(), __Vfunc_simple_test__DOT__encode_packet__2__Vfuncout),
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U)),6,(0x0000003fU 
                                             & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                           >> 9U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r));
            __Vfunc_simple_test__DOT__encode_packet__3__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            __Vfunc_simple_test__DOT__encode_packet__3__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 9U));
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__3__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000fU));
            vlSelfRef.simple_test__DOT__last_output_port = 0U;
            __Vfunc_simple_test__DOT__encode_packet__3__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 8U));
            __Vfunc_simple_test__DOT__encode_packet__3__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__3__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__3__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__3__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__3__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__3__data)));
            vlSelfRef.simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__3__Vfuncout;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy))))) {
            VL_WRITEF_NX("[Cycle %0d] West Output: %x (Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,([&]() {
                            __Vfunc_simple_test__DOT__encode_packet__4__data 
                                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
                            __Vfunc_simple_test__DOT__encode_packet__4__tgt_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 9U));
                            __Vfunc_simple_test__DOT__encode_packet__4__src_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 0x0000000fU));
                            __Vfunc_simple_test__DOT__encode_packet__4__pkt_qos 
                                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 8U));
                            __Vfunc_simple_test__DOT__encode_packet__4__pkt_type 
                                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 0x00000015U));
                            __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout 
                                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__4__pkt_type) 
                                     << 0x00000015U) 
                                    | (((IData)(__Vfunc_simple_test__DOT__encode_packet__4__pkt_qos) 
                                        << 0x00000014U) 
                                       | ((IData)(__Vfunc_simple_test__DOT__encode_packet__4__src_id) 
                                          << 0x0000000eU))) 
                                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__4__tgt_id) 
                                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__4__data)));
                        }(), __Vfunc_simple_test__DOT__encode_packet__4__Vfuncout),
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U)),6,(0x0000003fU 
                                             & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                           >> 9U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r));
            __Vfunc_simple_test__DOT__encode_packet__5__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            __Vfunc_simple_test__DOT__encode_packet__5__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 9U));
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__5__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000fU));
            vlSelfRef.simple_test__DOT__last_output_port = 1U;
            __Vfunc_simple_test__DOT__encode_packet__5__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 8U));
            __Vfunc_simple_test__DOT__encode_packet__5__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            __Vfunc_simple_test__DOT__encode_packet__5__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__5__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__5__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__5__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__5__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__5__data)));
            vlSelfRef.simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__5__Vfuncout;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy))))) {
            VL_WRITEF_NX("[Cycle %0d] South Output: %x (Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,([&]() {
                            __Vfunc_simple_test__DOT__encode_packet__6__data 
                                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
                            __Vfunc_simple_test__DOT__encode_packet__6__tgt_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 9U));
                            __Vfunc_simple_test__DOT__encode_packet__6__src_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 0x0000000fU));
                            __Vfunc_simple_test__DOT__encode_packet__6__pkt_qos 
                                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 8U));
                            __Vfunc_simple_test__DOT__encode_packet__6__pkt_type 
                                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 0x00000015U));
                            __Vfunc_simple_test__DOT__encode_packet__6__Vfuncout 
                                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__6__pkt_type) 
                                     << 0x00000015U) 
                                    | (((IData)(__Vfunc_simple_test__DOT__encode_packet__6__pkt_qos) 
                                        << 0x00000014U) 
                                       | ((IData)(__Vfunc_simple_test__DOT__encode_packet__6__src_id) 
                                          << 0x0000000eU))) 
                                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__6__tgt_id) 
                                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__6__data)));
                        }(), __Vfunc_simple_test__DOT__encode_packet__6__Vfuncout),
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U)),6,(0x0000003fU 
                                             & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                           >> 9U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r));
            __Vfunc_simple_test__DOT__encode_packet__7__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            __Vfunc_simple_test__DOT__encode_packet__7__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 9U));
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__7__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000fU));
            vlSelfRef.simple_test__DOT__last_output_port = 2U;
            __Vfunc_simple_test__DOT__encode_packet__7__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 8U));
            __Vfunc_simple_test__DOT__encode_packet__7__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            __Vfunc_simple_test__DOT__encode_packet__7__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__7__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__7__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__7__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__7__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__7__data)));
            vlSelfRef.simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__7__Vfuncout;
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
                          & (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy))))) {
            VL_WRITEF_NX("[Cycle %0d] East Output: %x (Type=%1#, QoS=%1#, Src=%2#, Tgt=%2#, Data=0x%02x)\n",0,
                         32,vlSelfRef.simple_test__DOT__test_cycle,
                         23,([&]() {
                            __Vfunc_simple_test__DOT__encode_packet__8__data 
                                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
                            __Vfunc_simple_test__DOT__encode_packet__8__tgt_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 9U));
                            __Vfunc_simple_test__DOT__encode_packet__8__src_id 
                                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                  >> 0x0000000fU));
                            __Vfunc_simple_test__DOT__encode_packet__8__pkt_qos 
                                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 8U));
                            __Vfunc_simple_test__DOT__encode_packet__8__pkt_type 
                                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                         >> 0x00000015U));
                            __Vfunc_simple_test__DOT__encode_packet__8__Vfuncout 
                                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__8__pkt_type) 
                                     << 0x00000015U) 
                                    | (((IData)(__Vfunc_simple_test__DOT__encode_packet__8__pkt_qos) 
                                        << 0x00000014U) 
                                       | ((IData)(__Vfunc_simple_test__DOT__encode_packet__8__src_id) 
                                          << 0x0000000eU))) 
                                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__8__tgt_id) 
                                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__8__data)));
                        }(), __Vfunc_simple_test__DOT__encode_packet__8__Vfuncout),
                         2,(3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x00000015U)),
                         1,(1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 8U)),6,(0x0000003fU 
                                             & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU)),
                         6,(0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                           >> 9U)),
                         8,(0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r));
            __Vfunc_simple_test__DOT__encode_packet__9__data 
                = (0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r);
            __Vfunc_simple_test__DOT__encode_packet__9__tgt_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 9U));
            vlSelfRef.simple_test__DOT__last_output_valid = 1U;
            __Vfunc_simple_test__DOT__encode_packet__9__src_id 
                = (0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                  >> 0x0000000fU));
            vlSelfRef.simple_test__DOT__last_output_port = 3U;
            __Vfunc_simple_test__DOT__encode_packet__9__pkt_qos 
                = (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 8U));
            __Vfunc_simple_test__DOT__encode_packet__9__pkt_type 
                = (3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                         >> 0x00000015U));
            __Vfunc_simple_test__DOT__encode_packet__9__Vfuncout 
                = ((((IData)(__Vfunc_simple_test__DOT__encode_packet__9__pkt_type) 
                     << 0x00000015U) | (((IData)(__Vfunc_simple_test__DOT__encode_packet__9__pkt_qos) 
                                         << 0x00000014U) 
                                        | ((IData)(__Vfunc_simple_test__DOT__encode_packet__9__src_id) 
                                           << 0x0000000eU))) 
                   | (((IData)(__Vfunc_simple_test__DOT__encode_packet__9__tgt_id) 
                       << 8U) | (IData)(__Vfunc_simple_test__DOT__encode_packet__9__data)));
            vlSelfRef.simple_test__DOT__last_output_pkt 
                = __Vfunc_simple_test__DOT__encode_packet__9__Vfuncout;
        }
    } else {
        vlSelfRef.simple_test__DOT__last_output_valid = 0U;
        vlSelfRef.simple_test__DOT__last_output_pkt = 0U;
        vlSelfRef.simple_test__DOT__last_output_port = 0U;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
        = __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
    vlSelfRef.simple_test__DOT__test_cycle = __Vdly__simple_test__DOT__test_cycle;
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
    CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2 = 0;
    CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3;
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3 = 0;
    // Body
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
            = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)
                ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r
                : vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_i);
    }
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2 
        = ((2U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 7U)) | (1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                   >> 8U)));
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
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r 
            = vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_i;
    }
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 5U)) | ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                    >> 6U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2)));
    simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3 
        = ((4U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 6U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_2));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N 
        = ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                  >> 5U)) | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B 
        = ((0x00000010U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                           >> 4U)) | ((8U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                             >> 5U)) 
                                      | (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT____VdfgRegularize_h7f89e92c_0_3)));
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
        = vlSelfRef.__Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
    __Vtableidx5 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx5];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx5])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx5];
    }
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
    __Vtableidx2 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx2];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx2])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx2];
    }
    __Vtableidx3 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx3];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx3])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx3];
    }
    __Vtableidx4 = ((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                      << 4U) | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__) 
                        << 1U) | (IData)(vlSelfRef.simple_test__DOT__rst_n)));
    if ((1U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r 
            = Vsimple_test__ConstPool__TABLE_h3b34c9f4_0
            [__Vtableidx4];
    }
    if ((2U & Vsimple_test__ConstPool__TABLE_h28d0bcb6_0
         [__Vtableidx4])) {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r 
            = Vsimple_test__ConstPool__TABLE_h24174b10_0
            [__Vtableidx4];
    }
}

void Vsimple_test___024root___nba_comb__TOP__1(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__1\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type = 0U;
    }
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
    } else {
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x = 3U;
        vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type = 0U;
    }
}

void Vsimple_test___024root___nba_comb__TOP__2(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___nba_comb__TOP__2\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld) 
           | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0 
        = (1U & ((~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r)) 
                 | (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A = 0U;
    if (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) {
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__ 
        = ((IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0) 
           & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
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
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_so_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_con_no_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__ 
        = ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r) 
           & ((0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
              & ((~ (IData)(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy)) 
                 & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__ 
        = (((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
            | (0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
           & (IData)(simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT____VdfgRegularize_hcd180cb9_0_0));
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
    if ((0x000000000000001dULL & vlSelfRef.__VnbaTriggered
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
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsimple_test___024root___nba_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((0x000000000000001fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vsimple_test___024root___nba_comb__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
}

void Vsimple_test___024root___timing_commit(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___timing_commit\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_hb092edad__0.commit(
                                                   "@(posedge simple_test.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h1cfde055__0.commit(
                                                   "@(posedge (32'sh5 * simple_test.clk))");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h1d6373ea__0.commit(
                                                   "@(posedge (32'sha * simple_test.clk))");
    }
}

void Vsimple_test___024root___timing_resume(Vsimple_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root___timing_resume\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb092edad__0.resume(
                                                   "@(posedge simple_test.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h1cfde055__0.resume(
                                                   "@(posedge (32'sh5 * simple_test.clk))");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h1d6373ea__0.resume(
                                                   "@(posedge (32'sha * simple_test.clk))");
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered
         [0U])) {
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
            VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsimple_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/liangmx17/Documents/maze_mesh/verification/testbench/integration_tests/node_basic_routing/simple_test.sv", 15, "", "Active region did not converge after 100 tries");
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
