// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VL_ATTR_COLD void Vminimal_node_test_pkt_out___ctor_var_reset(Vminimal_node_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vminimal_node_test_pkt_out___ctor_var_reset\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->pkt_out_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17367824492897152009ull);
}
