// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbasic_test.h for the primary calling header

#include "Vbasic_test__pch.h"

std::string VL_TO_STRING(const Vbasic_test_pkt_con_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vbasic_test_pkt_con_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
