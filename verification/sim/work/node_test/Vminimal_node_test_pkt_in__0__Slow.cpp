// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VL_ATTR_COLD void Vminimal_node_test_pkt_in___ctor_var_reset(Vminimal_node_test_pkt_in* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_in___ctor_var_reset\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->pkt_in_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13777517630569576598ull);
    vlSelf->pkt_in_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 788356834919828729ull);
    vlSelf->pkt_in_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3548017071178104907ull);
    vlSelf->pkt_in_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 13922763077560602174ull);
    vlSelf->pkt_in_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7721396656926619150ull);
    vlSelf->pkt_in_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8118410726889960845ull);
}
