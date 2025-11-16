// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

void Vdebug_simple_test_pkt_out___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_out_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_rdy;
    vlSelfRef.pkt_out_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_valid;
    vlSelfRef.pkt_out_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                    >> 0x00000015U));
    vlSelfRef.pkt_out_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                   >> 8U));
    vlSelfRef.pkt_out_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                            >> 0x0000000fU));
    vlSelfRef.pkt_out_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                            >> 9U));
    vlSelfRef.pkt_out_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt);
}

void Vdebug_simple_test_pkt_out___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_out_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_o_pkt_out_rdy;
}

void Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0(Vdebug_simple_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_out_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                    >> 0x00000015U));
    vlSelfRef.pkt_out_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                   >> 8U));
    vlSelfRef.pkt_out_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                            >> 0x0000000fU));
    vlSelfRef.pkt_out_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt 
                                            >> 9U));
    vlSelfRef.pkt_out_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_pkt);
}

void Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__1(Vdebug_simple_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_out_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__b_out_valid;
}

std::string VL_TO_STRING(const Vdebug_simple_test_pkt_out* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
