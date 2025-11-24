// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

void Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i(Vminimal_node_test_pkt_in* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_in___eval_initial__TOP__minimal_node_test__DOT__pkt_i\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pkt_in_vld = 0U;
    vlSelfRef.pkt_in_qos = 0U;
    vlSelfRef.pkt_in_type = 0U;
    vlSelfRef.pkt_in_src = 0U;
    vlSelfRef.pkt_in_tgt = 0U;
    vlSelfRef.pkt_in_data = 0U;
}

std::string VL_TO_STRING(const Vminimal_node_test_pkt_in* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_in::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
