// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

void Vdebug_simple_test_pkt_in___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_in___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_in_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_type;
    vlSelfRef.pkt_in_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_qos;
    vlSelfRef.pkt_in_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_src;
    vlSelfRef.pkt_in_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_tgt;
    vlSelfRef.pkt_in_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_data;
    vlSelfRef.pkt_in_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_vld;
    vlSelfRef.pkt_in_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_o;
}

void Vdebug_simple_test_pkt_in___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_in___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_in_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_type;
    vlSelfRef.pkt_in_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_qos;
    vlSelfRef.pkt_in_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_src;
    vlSelfRef.pkt_in_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_tgt;
    vlSelfRef.pkt_in_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_data;
    vlSelfRef.pkt_in_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_i_pkt_in_vld;
}

void Vdebug_simple_test_pkt_in___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0(Vdebug_simple_test_pkt_in* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_in___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_in_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__ready_o;
}

std::string VL_TO_STRING(const Vdebug_simple_test_pkt_in* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_in::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
