// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

void Vminimal_node_test_pkt_con_if___eval_initial__TOP__minimal_node_test__DOT__pkt_con(Vminimal_node_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_con_if___eval_initial__TOP__minimal_node_test__DOT__pkt_con\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ni_data = 0U;
    vlSelfRef.wi_data = 0U;
    vlSelfRef.si_data = 0U;
    vlSelfRef.ei_data = 0U;
    vlSelfRef.ni_qos = 0U;
    vlSelfRef.wi_qos = 0U;
    vlSelfRef.si_qos = 0U;
    vlSelfRef.ei_qos = 0U;
    vlSelfRef.ni_type = 0U;
    vlSelfRef.wi_type = 0U;
    vlSelfRef.si_type = 0U;
    vlSelfRef.ei_type = 0U;
    vlSelfRef.ni_src = 0U;
    vlSelfRef.wi_src = 0U;
    vlSelfRef.si_src = 0U;
    vlSelfRef.ei_src = 0U;
    vlSelfRef.ni_tgt = 0U;
    vlSelfRef.wi_tgt = 0U;
    vlSelfRef.si_tgt = 0U;
    vlSelfRef.ei_tgt = 0U;
    vlSelfRef.ni_vld = 0U;
    vlSelfRef.wi_vld = 0U;
    vlSelfRef.si_vld = 0U;
    vlSelfRef.ei_vld = 0U;
}

std::string VL_TO_STRING(const Vminimal_node_test_pkt_con_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_con_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
