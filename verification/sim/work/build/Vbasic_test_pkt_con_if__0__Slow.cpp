// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbasic_test.h for the primary calling header

#include "Vbasic_test__pch.h"

VL_ATTR_COLD void Vbasic_test_pkt_con_if___ctor_var_reset(Vbasic_test_pkt_con_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vbasic_test_pkt_con_if___ctor_var_reset\n"); );
    Vbasic_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->ni_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12049530924799138151ull);
    vlSelf->ni_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3395440149745862324ull);
    vlSelf->ni_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3367749043492048025ull);
    vlSelf->ni_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1648452314160275568ull);
    vlSelf->ni_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6703682858523183617ull);
    vlSelf->ni_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 552954550650236475ull);
    vlSelf->wi_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14391603793984778466ull);
    vlSelf->wi_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6430804056240554497ull);
    vlSelf->wi_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 338535532803667033ull);
    vlSelf->wi_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9495046947543940693ull);
    vlSelf->wi_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10286102834002638218ull);
    vlSelf->wi_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3674728911997235699ull);
    vlSelf->si_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7608947948387535898ull);
    vlSelf->si_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1190400901885897561ull);
    vlSelf->si_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4457897691749820308ull);
    vlSelf->si_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 29201343262962102ull);
    vlSelf->si_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9320299600629785184ull);
    vlSelf->si_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16280739902935407465ull);
    vlSelf->ei_vld = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1770400713855634665ull);
    vlSelf->ei_qos = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2030885100661123525ull);
    vlSelf->ei_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5884894078193099120ull);
    vlSelf->ei_src = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15921218734267454498ull);
    vlSelf->ei_tgt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 4498718239485475058ull);
    vlSelf->ei_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 389030267335590235ull);
    vlSelf->no_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 894827853949844458ull);
    vlSelf->wo_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3094270333398098684ull);
    vlSelf->so_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5410803513933128331ull);
    vlSelf->eo_rdy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15850884250120967159ull);
}
