// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

std::string VL_TO_STRING(const Vminimal_node_test_pkt_con_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_con_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
