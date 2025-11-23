// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vminimal_node_test.h for the primary calling header

#include "Vminimal_node_test__pch.h"

VL_ATTR_COLD void Vminimal_node_test___024unit___ctor_var_reset(Vminimal_node_test___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vminimal_node_test___024unit___ctor_var_reset\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi = 0; __Vi < 8; ++__Vi) {
        vlSelf->__Venumtab_enum_name3[__Vi] = ""s;
    }
    vlSelf->__Venumtab_enum_name3[0] = "PORT_A"s;
    vlSelf->__Venumtab_enum_name3[1] = "PORT_N"s;
    vlSelf->__Venumtab_enum_name3[2] = "PORT_W"s;
    vlSelf->__Venumtab_enum_name3[3] = "PORT_S"s;
    vlSelf->__Venumtab_enum_name3[4] = "PORT_E"s;
    vlSelf->__Venumtab_enum_name3[5] = "PORT_B"s;
}
