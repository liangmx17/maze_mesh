// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

void Vdebug_simple_test_pkt_con_if___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___ico_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ni_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_type;
    vlSelfRef.ni_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_qos;
    vlSelfRef.ni_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_src;
    vlSelfRef.ni_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_tgt;
    vlSelfRef.ni_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_data;
    vlSelfRef.wi_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_type;
    vlSelfRef.wi_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_qos;
    vlSelfRef.wi_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_src;
    vlSelfRef.wi_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_tgt;
    vlSelfRef.wi_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_data;
    vlSelfRef.si_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_type;
    vlSelfRef.si_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_qos;
    vlSelfRef.si_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_src;
    vlSelfRef.si_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_tgt;
    vlSelfRef.si_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_data;
    vlSelfRef.ei_type = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_type;
    vlSelfRef.ei_qos = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_qos;
    vlSelfRef.ei_src = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_src;
    vlSelfRef.ei_tgt = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_tgt;
    vlSelfRef.ei_data = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_data;
    vlSelfRef.ni_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ni_vld;
    vlSelfRef.wi_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wi_vld;
    vlSelfRef.si_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_si_vld;
    vlSelfRef.ei_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_ei_vld;
    vlSelfRef.no_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_rdy;
    vlSelfRef.wo_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_rdy;
    vlSelfRef.so_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_rdy;
    vlSelfRef.eo_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_rdy;
    vlSelfRef.ni_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_o;
    vlSelfRef.wi_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_o;
    vlSelfRef.si_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_o;
    vlSelfRef.ei_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_o;
    vlSelfRef.no_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_valid;
    vlSelfRef.wo_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_valid;
    vlSelfRef.so_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_valid;
    vlSelfRef.eo_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_valid;
    vlSelfRef.no_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.no_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                              >> 8U));
    vlSelfRef.no_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.no_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                                       >> 9U));
    vlSelfRef.no_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt);
    vlSelfRef.wo_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.wo_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                              >> 8U));
    vlSelfRef.wo_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.wo_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                                       >> 9U));
    vlSelfRef.wo_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt);
    vlSelfRef.so_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.so_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                              >> 8U));
    vlSelfRef.so_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.so_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                                       >> 9U));
    vlSelfRef.so_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt);
    vlSelfRef.eo_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.eo_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                              >> 8U));
    vlSelfRef.eo_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.eo_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                                       >> 9U));
    vlSelfRef.eo_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt);
}

void Vdebug_simple_test_pkt_con_if___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___act_comb__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.no_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_no_rdy;
    vlSelfRef.wo_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_wo_rdy;
    vlSelfRef.so_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_so_rdy;
    vlSelfRef.eo_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__pkt_con_eo_rdy;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__0\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.no_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.no_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                              >> 8U));
    vlSelfRef.no_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.no_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt 
                                       >> 9U));
    vlSelfRef.no_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_pkt);
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__1(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__1\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.wo_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.wo_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                              >> 8U));
    vlSelfRef.wo_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.wo_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt 
                                       >> 9U));
    vlSelfRef.wo_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_pkt);
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__2(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__2\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.so_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.so_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                              >> 8U));
    vlSelfRef.so_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.so_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt 
                                       >> 9U));
    vlSelfRef.so_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_pkt);
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__3(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__3\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.eo_type = (3U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                               >> 0x00000015U));
    vlSelfRef.eo_qos = (1U & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                              >> 8U));
    vlSelfRef.eo_src = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                                       >> 0x0000000fU));
    vlSelfRef.eo_tgt = (0x0000003fU & (vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt 
                                       >> 9U));
    vlSelfRef.eo_data = (0x000000ffU & vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_pkt);
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__4(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__4\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.no_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__n_out_valid;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__5(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__5\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.wo_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__w_out_valid;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__6(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__6\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.so_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__s_out_valid;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__7(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__7\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.eo_vld = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__e_out_valid;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__8(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__8\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ni_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__ready_o;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__9(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__9\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.wi_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__ready_o;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__10(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__10\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.si_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__ready_o;
}

void Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__11(Vdebug_simple_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if___nba_sequent__TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con__11\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ei_rdy = vlSymsp->TOP.debug_simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__ready_o;
}

std::string VL_TO_STRING(const Vdebug_simple_test_pkt_con_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_con_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
