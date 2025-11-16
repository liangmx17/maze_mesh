// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdebug_simple_test.h for the primary calling header

#include "Vdebug_simple_test__pch.h"

VL_ATTR_COLD void Vdebug_simple_test_pkt_out___ctor_var_reset(Vdebug_simple_test_pkt_out* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vdebug_simple_test_pkt_out___ctor_var_reset\n"); );
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->pkt_out_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7407018731686442402ull);
    vlSelf->pkt_out_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6919065457326809962ull);
    vlSelf->pkt_out_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4918461623558803909ull);
    vlSelf->pkt_out_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8315397509442463539ull);
    vlSelf->pkt_out_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7843107387022288657ull);
    vlSelf->pkt_out_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11231801808751840014ull);
    vlSelf->pkt_out_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17367824492897152009ull);
}
