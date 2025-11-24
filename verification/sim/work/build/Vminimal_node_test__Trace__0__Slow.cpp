// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vminimal_node_test__Syms.h"


VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_i__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_o__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_con__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_init_sub__TOP__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("minimal_node_test", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"pg_node",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+3,0,"test_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+4,0,"passed_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+117,0,"clk_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+5,0,"timeout_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+6,0,"test_packet_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+7,0,"test_packet_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("pkt_i", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_i__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("pkt_o", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_o__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("pkt_con", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_con__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+242,0,"HP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"VP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"pg_node",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->pushPrefix("pkt_i", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_i__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("pkt_o", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_o__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("pkt_con", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_con__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+103,0,"new_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+104,0,"tgt_is_pg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"cpy_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"route_req_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+91,0,"route_req_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+92,0,"route_req_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+93,0,"route_req_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+94,0,"route_req_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("arb_req", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+148+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("arb_gnt", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+243+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 4,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("pld_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+153+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 22,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+159,0,"pkt_in_qos_A_buffered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"pkt_in_type_A_buffered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+161,0,"pkt_in_src_A_buffered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+162,0,"pkt_in_tgt_A_buffered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+163,0,"pkt_in_data_A_buffered",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+164,0,"pkt_in_ctrl_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"pkt_in_data_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"arb_req_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+167,0,"arb_qos_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+168,0,"arb_gnt_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+169,0,"arb_req_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+170,0,"arb_qos_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+171,0,"arb_gnt_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+172,0,"arb_req_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+173,0,"arb_qos_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+174,0,"arb_gnt_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+175,0,"arb_req_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+176,0,"arb_qos_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+177,0,"arb_gnt_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+178,0,"arb_req_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+179,0,"arb_qos_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+180,0,"arb_gnt_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+181,0,"pkt_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+182,0,"pkt_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+183,0,"pkt_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+184,0,"pkt_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+185,0,"pkt_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+186,0,"n_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"n_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"n_out_pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+187,0,"w_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"w_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"w_out_pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+188,0,"s_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"s_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"s_out_pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+189,0,"e_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"e_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"e_out_pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+190,0,"b_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"b_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"b_out_pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("irs_output_B", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+185,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+190,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+190,0,"valid0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"valid1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"payload0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+256,0,"payload1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+194,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+195,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("irs_output_E", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+189,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+189,0,"valid0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"valid1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"payload0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+257,0,"payload1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+199,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+200,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("irs_output_N", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"IRS_DEEP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"TYPE_NO_READY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"TYPE_HALF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"TYPE_RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+181,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+118,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("proc_insert_irs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+255,0,"ready_irs_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+201,0,"valid_irs_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+258,0,"payload_irs_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+202,0,"ready_irs_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+186,0,"valid_irs_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+118,0,"payload_irs_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("irs_gen[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("irs_ro_en", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("U_LOOP_IRS", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+258,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+186,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+186,0,"valid0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"valid1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"payload0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+259,0,"payload1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+204,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+205,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("irs_output_S", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+206,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+183,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+188,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+188,0,"valid0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"valid1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"payload0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+260,0,"payload1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+209,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+210,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("irs_output_W", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"RO_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+187,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+187,0,"valid0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"valid1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"payload0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+261,0,"payload1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+214,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+215,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_A_CTRL", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+262,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"cpy_mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"route_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+216,0,"arb_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+263,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+237,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+162,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+264,0,"DIR_N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+265,0,"DIR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+266,0,"DIR_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+267,0,"DIR_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+268,0,"DIR_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+107,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+108,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_A_DATA", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+269,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"cpy_mode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+216,0,"arb_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+263,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+217,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBit(c+238,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+239,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_E", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"route_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+219,0,"arb_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+270,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+220,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+109,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+221,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_N", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"route_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+223,0,"arb_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+271,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+224,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+110,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+225,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_S", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"route_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+16,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+227,0,"arb_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+272,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+228,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+111,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_IBUF_W", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+253,0,"PYLD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"ibuf_vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"ibuf_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"route_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+18,0,"payload_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+231,0,"arb_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+273,0,"arb_gnt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+158,0,"obuf_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+232,0,"payload_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBit(c+112,0,"set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+233,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_arbiter_B", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+274,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+179,0,"qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+180,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_arbiter_E", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+176,0,"qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+177,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_arbiter_N", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+167,0,"qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+168,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_arbiter_S", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+173,0,"qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+174,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_arbiter_W", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+170,0,"qos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+171,0,"gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_fault_relative_pos_detect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+242,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"pg_node",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+19,0,"fault_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+20,0,"fault_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_multi_packet_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+242,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"pkt_type_A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"tgt_A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+160,0,"pkt_type_buf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+162,0,"tgt_buf",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"pg_node",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+8,0,"vld",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+103,0,"new_tgt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+104,0,"tgt_is_pg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"cpy_mode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"gen_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+113,0,"new_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+240,0,"new_y_multi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+241,0,"new_y_broad",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+114,0,"pkt_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+115,0,"tgt_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+116,0,"clr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_router_A", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+264,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+268,0,"router_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+22,0,"tgt_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+23,0,"tgt_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+24,0,"src_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"src_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+26,0,"pkt_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+94,0,"route_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+277,0,"LYEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LYEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+277,0,"LXEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LXEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+95,0,"xNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"xSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"xNW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"xSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"xN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"xS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"xW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"xE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"tgt_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"tgt_x_eq_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"tgt_x_gt_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"tgt_x_gt_loc_x_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"tgt_x_gt_loc_x_p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_x_ls_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"tgt_x_ls_loc_x_m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"tgt_y_gt_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"tgt_y_gt_loc_y_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_y_ls_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"src_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_router_E", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+264,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+267,0,"router_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+34,0,"tgt_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+35,0,"tgt_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"src_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+37,0,"src_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+38,0,"pkt_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+92,0,"route_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+277,0,"LYEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LYEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+277,0,"LXEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LXEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+95,0,"xNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"xSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"xNW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"xSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"xN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"xS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"xW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"xE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"tgt_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"tgt_x_eq_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"tgt_x_gt_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"tgt_x_gt_loc_x_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"tgt_x_gt_loc_x_p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_x_ls_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"tgt_x_ls_loc_x_m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"tgt_y_gt_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"tgt_y_gt_loc_y_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_y_ls_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"src_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_router_N", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+264,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"router_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+22,0,"tgt_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+23,0,"tgt_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+24,0,"src_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"src_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+26,0,"pkt_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+90,0,"route_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+277,0,"LYEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LYEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+277,0,"LXEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LXEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+95,0,"xNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"xSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"xNW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"xSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"xN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"xS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"xW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"xE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"tgt_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"tgt_x_eq_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"tgt_x_gt_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"tgt_x_gt_loc_x_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"tgt_x_gt_loc_x_p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_x_ls_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"tgt_x_ls_loc_x_m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"tgt_y_gt_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"tgt_y_gt_loc_y_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_y_ls_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"src_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_router_S", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+264,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+266,0,"router_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+46,0,"tgt_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+47,0,"tgt_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+48,0,"src_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"src_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+50,0,"pkt_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+91,0,"route_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+277,0,"LYEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LYEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+277,0,"LXEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LXEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+95,0,"xNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"xSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"xNW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"xSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"xN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"xS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"xW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"xE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"tgt_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"tgt_x_eq_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"tgt_x_gt_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"tgt_x_gt_loc_x_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"tgt_x_gt_loc_x_p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_x_ls_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"tgt_x_ls_loc_x_m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"tgt_y_gt_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"tgt_y_gt_loc_y_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_y_ls_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"src_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_router_W", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+264,0,"LOCAL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+264,0,"LOCAL_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+265,0,"router_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+58,0,"tgt_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+59,0,"tgt_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+60,0,"src_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+61,0,"src_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+62,0,"pkt_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1,0,"pg_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"fault_relative_pos",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+93,0,"route_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+277,0,"LYEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LYEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+277,0,"LXEQ1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+278,0,"LXEQ0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+95,0,"xNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"xSE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"xNW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"xSW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"xN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"xS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"xW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"xE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"tgt_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"tgt_x_eq_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"tgt_x_gt_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"tgt_x_gt_loc_x_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"tgt_x_gt_loc_x_p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_x_ls_loc_x",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"tgt_x_ls_loc_x_m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"tgt_y_gt_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"tgt_y_gt_loc_y_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"tgt_y_ls_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"src_y_eq_loc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_i__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_i__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+8,0,"pkt_in_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"pkt_in_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"pkt_in_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+71,0,"pkt_in_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+9,0,"pkt_in_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+72,0,"pkt_in_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+234,0,"pkt_in_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_o__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_o__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+190,0,"pkt_out_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"pkt_out_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"pkt_out_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+125,0,"pkt_out_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+126,0,"pkt_out_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+127,0,"pkt_out_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+255,0,"pkt_out_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_con__0(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_init_sub__TOP__minimal_node_test__DOT__pkt_con__0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+13,0,"ni_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"ni_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"ni_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"ni_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+74,0,"ni_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+75,0,"ni_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+76,0,"ni_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+17,0,"wi_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"wi_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"wi_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"wi_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+78,0,"wi_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+79,0,"wi_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+80,0,"wi_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+15,0,"si_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"si_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"si_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"si_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+82,0,"si_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+83,0,"si_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+84,0,"si_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+11,0,"ei_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"ei_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"ei_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"ei_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+86,0,"ei_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+87,0,"ei_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+88,0,"ei_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+186,0,"no_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"no_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"no_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+129,0,"no_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+130,0,"no_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+131,0,"no_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+132,0,"no_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+187,0,"wo_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"wo_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"wo_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"wo_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+135,0,"wo_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+136,0,"wo_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+137,0,"wo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+188,0,"so_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"so_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"so_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+139,0,"so_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+140,0,"so_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+141,0,"so_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+142,0,"so_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+189,0,"eo_vld",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"eo_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"eo_qos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"eo_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+145,0,"eo_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+146,0,"eo_tgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+147,0,"eo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_init_top(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_init_top\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vminimal_node_test___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vminimal_node_test___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vminimal_node_test___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vminimal_node_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vminimal_node_test___024root__trace_register(Vminimal_node_test___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_register\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vminimal_node_test___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vminimal_node_test___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vminimal_node_test___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vminimal_node_test___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_const_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vminimal_node_test___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_const_0\n"); );
    // Body
    Vminimal_node_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vminimal_node_test___024root*>(voidSelf);
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vminimal_node_test___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_const_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_const_0_sub_0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+242,(0U),32);
    bufp->fullCData(oldp+243,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt[0]),5);
    bufp->fullCData(oldp+244,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt[1]),5);
    bufp->fullCData(oldp+245,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt[2]),5);
    bufp->fullCData(oldp+246,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt[3]),5);
    bufp->fullCData(oldp+247,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt[4]),5);
    bufp->fullBit(oldp+248,(vlSelfRef.minimal_node_test__DOT__dut__DOT__n_out_ready));
    bufp->fullBit(oldp+249,(vlSelfRef.minimal_node_test__DOT__dut__DOT__w_out_ready));
    bufp->fullBit(oldp+250,(vlSelfRef.minimal_node_test__DOT__dut__DOT__s_out_ready));
    bufp->fullBit(oldp+251,(vlSelfRef.minimal_node_test__DOT__dut__DOT__e_out_ready));
    bufp->fullBit(oldp+252,(vlSelfRef.minimal_node_test__DOT__dut__DOT__b_out_ready));
    bufp->fullIData(oldp+253,(0x00000017U),32);
    bufp->fullIData(oldp+254,(1U),32);
    bufp->fullBit(oldp+255,(1U));
    bufp->fullIData(oldp+256,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r),23);
    bufp->fullIData(oldp+257,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r),23);
    bufp->fullIData(oldp+258,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i),23);
    bufp->fullIData(oldp+259,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
    bufp->fullIData(oldp+260,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r),23);
    bufp->fullIData(oldp+261,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r),23);
    bufp->fullIData(oldp+262,(6U),32);
    bufp->fullCData(oldp+263,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [4U]),5);
    bufp->fullCData(oldp+264,(0U),3);
    bufp->fullCData(oldp+265,(1U),3);
    bufp->fullCData(oldp+266,(2U),3);
    bufp->fullCData(oldp+267,(3U),3);
    bufp->fullCData(oldp+268,(4U),3);
    bufp->fullIData(oldp+269,(0x00000011U),32);
    bufp->fullCData(oldp+270,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [3U]),5);
    bufp->fullCData(oldp+271,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [0U]),5);
    bufp->fullCData(oldp+272,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [2U]),5);
    bufp->fullCData(oldp+273,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [1U]),5);
    bufp->fullIData(oldp+274,(5U),32);
    bufp->fullIData(oldp+275,(4U),32);
    bufp->fullCData(oldp+276,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__gen_tgt),6);
    bufp->fullBit(oldp+277,(0U));
    bufp->fullBit(oldp+278,(1U));
    bufp->fullBit(oldp+279,(0U));
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_full_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vminimal_node_test___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_full_0\n"); );
    // Body
    Vminimal_node_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vminimal_node_test___024root*>(voidSelf);
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vminimal_node_test___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vminimal_node_test___024root__trace_full_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_full_0_sub_0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.minimal_node_test__DOT__pg_en));
    bufp->fullCData(oldp+2,(vlSelfRef.minimal_node_test__DOT__pg_node),6);
    bufp->fullIData(oldp+3,(vlSelfRef.minimal_node_test__DOT__test_count),32);
    bufp->fullIData(oldp+4,(vlSelfRef.minimal_node_test__DOT__passed_count),32);
    bufp->fullIData(oldp+5,(vlSelfRef.minimal_node_test__DOT__timeout_counter),32);
    bufp->fullIData(oldp+6,(vlSelfRef.minimal_node_test__DOT__test_packet_data),23);
    bufp->fullBit(oldp+7,(vlSelfRef.minimal_node_test__DOT__test_packet_valid));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
    bufp->fullCData(oldp+9,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt),6);
    bufp->fullIData(oldp+10,((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos) 
                               << 0x00000010U) | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type) 
                                                   << 0x0000000eU) 
                                                  | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src) 
                                                      << 8U) 
                                                     | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data))))),17);
    bufp->fullBit(oldp+11,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld));
    bufp->fullIData(oldp+12,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos) 
                                << 0x00000016U) | (
                                                   ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type) 
                                                    << 0x00000014U) 
                                                   | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                                      << 0x0000000eU))) 
                              | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                  << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data)))),23);
    bufp->fullBit(oldp+13,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld));
    bufp->fullIData(oldp+14,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos) 
                                << 0x00000016U) | (
                                                   ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type) 
                                                    << 0x00000014U) 
                                                   | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                                      << 0x0000000eU))) 
                              | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                  << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data)))),23);
    bufp->fullBit(oldp+15,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld));
    bufp->fullIData(oldp+16,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos) 
                                << 0x00000016U) | (
                                                   ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type) 
                                                    << 0x00000014U) 
                                                   | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                                      << 0x0000000eU))) 
                              | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                  << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data)))),23);
    bufp->fullBit(oldp+17,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld));
    bufp->fullIData(oldp+18,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos) 
                                << 0x00000016U) | (
                                                   ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type) 
                                                    << 0x00000014U) 
                                                   | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                                      << 0x0000000eU))) 
                              | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                  << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data)))),23);
    bufp->fullCData(oldp+19,((7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node))),3);
    bufp->fullCData(oldp+20,((7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+21,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type),2);
    bufp->fullCData(oldp+22,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))),3);
    bufp->fullCData(oldp+23,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+24,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))),3);
    bufp->fullCData(oldp+25,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+26,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type),2);
    bufp->fullBit(oldp+27,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                         >> 3U)))));
    bufp->fullBit(oldp+28,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
    bufp->fullBit(oldp+29,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
    bufp->fullBit(oldp+30,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
    bufp->fullBit(oldp+31,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+32,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+33,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                         >> 3U)))));
    bufp->fullCData(oldp+34,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))),3);
    bufp->fullCData(oldp+35,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+36,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))),3);
    bufp->fullCData(oldp+37,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+38,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type),2);
    bufp->fullBit(oldp+39,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                         >> 3U)))));
    bufp->fullBit(oldp+40,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
    bufp->fullBit(oldp+41,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
    bufp->fullBit(oldp+42,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
    bufp->fullBit(oldp+43,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+44,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+45,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                         >> 3U)))));
    bufp->fullCData(oldp+46,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))),3);
    bufp->fullCData(oldp+47,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+48,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))),3);
    bufp->fullCData(oldp+49,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+50,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type),2);
    bufp->fullBit(oldp+51,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                         >> 3U)))));
    bufp->fullBit(oldp+52,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
    bufp->fullBit(oldp+53,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
    bufp->fullBit(oldp+54,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
    bufp->fullBit(oldp+55,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+56,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+57,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                         >> 3U)))));
    bufp->fullCData(oldp+58,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))),3);
    bufp->fullCData(oldp+59,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+60,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))),3);
    bufp->fullCData(oldp+61,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                    >> 3U))),3);
    bufp->fullCData(oldp+62,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type),2);
    bufp->fullBit(oldp+63,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                         >> 3U)))));
    bufp->fullBit(oldp+64,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
    bufp->fullBit(oldp+65,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
    bufp->fullBit(oldp+66,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
    bufp->fullBit(oldp+67,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+68,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                        >> 3U)))));
    bufp->fullBit(oldp+69,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                         >> 3U)))));
    bufp->fullBit(oldp+70,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos));
    bufp->fullCData(oldp+71,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src),6);
    bufp->fullCData(oldp+72,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data),8);
    bufp->fullBit(oldp+73,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos));
    bufp->fullCData(oldp+74,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src),6);
    bufp->fullCData(oldp+75,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt),6);
    bufp->fullCData(oldp+76,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data),8);
    bufp->fullBit(oldp+77,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos));
    bufp->fullCData(oldp+78,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src),6);
    bufp->fullCData(oldp+79,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt),6);
    bufp->fullCData(oldp+80,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data),8);
    bufp->fullBit(oldp+81,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos));
    bufp->fullCData(oldp+82,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src),6);
    bufp->fullCData(oldp+83,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt),6);
    bufp->fullCData(oldp+84,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data),8);
    bufp->fullBit(oldp+85,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos));
    bufp->fullCData(oldp+86,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src),6);
    bufp->fullCData(oldp+87,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt),6);
    bufp->fullCData(oldp+88,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data),8);
    bufp->fullCData(oldp+89,(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos),4);
    bufp->fullCData(oldp+90,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N),5);
    bufp->fullCData(oldp+91,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S),5);
    bufp->fullCData(oldp+92,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E),5);
    bufp->fullCData(oldp+93,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W),5);
    bufp->fullCData(oldp+94,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A),5);
    bufp->fullBit(oldp+95,((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+96,((4U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+97,((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+98,((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+99,((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+100,((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+101,((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullBit(oldp+102,((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    bufp->fullCData(oldp+103,(vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt),6);
    bufp->fullBit(oldp+104,(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg));
    bufp->fullBit(oldp+105,(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode));
    bufp->fullCData(oldp+106,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req),5);
    bufp->fullBit(oldp+107,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set));
    bufp->fullCData(oldp+108,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr),5);
    bufp->fullBit(oldp+109,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set));
    bufp->fullBit(oldp+110,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set));
    bufp->fullBit(oldp+111,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set));
    bufp->fullBit(oldp+112,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set));
    bufp->fullCData(oldp+113,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x),3);
    bufp->fullCData(oldp+114,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type),2);
    bufp->fullCData(oldp+115,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw),6);
    bufp->fullBit(oldp+116,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr));
    bufp->fullIData(oldp+117,(vlSelfRef.minimal_node_test__DOT__clk_counter),32);
    bufp->fullIData(oldp+118,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
    bufp->fullIData(oldp+119,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r),23);
    bufp->fullIData(oldp+120,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r),23);
    bufp->fullIData(oldp+121,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r),23);
    bufp->fullIData(oldp+122,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),23);
    bufp->fullBit(oldp+123,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+124,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                     >> 0x00000015U))),2);
    bufp->fullCData(oldp+125,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                              >> 0x0000000eU))),6);
    bufp->fullCData(oldp+126,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                              >> 8U))),6);
    bufp->fullCData(oldp+127,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r)),8);
    bufp->fullBit(oldp+128,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+129,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 0x00000015U))),2);
    bufp->fullCData(oldp+130,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                              >> 0x0000000eU))),6);
    bufp->fullCData(oldp+131,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                              >> 8U))),6);
    bufp->fullCData(oldp+132,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
    bufp->fullBit(oldp+133,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+134,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                     >> 0x00000015U))),2);
    bufp->fullCData(oldp+135,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                              >> 0x0000000eU))),6);
    bufp->fullCData(oldp+136,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                              >> 8U))),6);
    bufp->fullCData(oldp+137,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r)),8);
    bufp->fullBit(oldp+138,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+139,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                     >> 0x00000015U))),2);
    bufp->fullCData(oldp+140,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                              >> 0x0000000eU))),6);
    bufp->fullCData(oldp+141,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                              >> 8U))),6);
    bufp->fullCData(oldp+142,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r)),8);
    bufp->fullBit(oldp+143,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+144,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                     >> 0x00000015U))),2);
    bufp->fullCData(oldp+145,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                              >> 0x0000000eU))),6);
    bufp->fullCData(oldp+146,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                              >> 8U))),6);
    bufp->fullCData(oldp+147,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r)),8);
    bufp->fullCData(oldp+148,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[0]),5);
    bufp->fullCData(oldp+149,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[1]),5);
    bufp->fullCData(oldp+150,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[2]),5);
    bufp->fullCData(oldp+151,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[3]),5);
    bufp->fullCData(oldp+152,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[4]),5);
    bufp->fullIData(oldp+153,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[0]),23);
    bufp->fullIData(oldp+154,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[1]),23);
    bufp->fullIData(oldp+155,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[2]),23);
    bufp->fullIData(oldp+156,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[3]),23);
    bufp->fullIData(oldp+157,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4]),23);
    bufp->fullCData(oldp+158,(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy),5);
    bufp->fullBit(oldp+159,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                   >> 0x00000010U))));
    bufp->fullCData(oldp+160,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                     >> 0x0000000eU))),2);
    bufp->fullCData(oldp+161,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                              >> 8U))),6);
    bufp->fullCData(oldp+162,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered),6);
    bufp->fullCData(oldp+163,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)),8);
    bufp->fullBit(oldp+164,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy));
    bufp->fullBit(oldp+165,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy));
    bufp->fullCData(oldp+166,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        << 1U)) | (1U 
                                                   & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                 << 1U)) 
                                          | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))))),4);
    bufp->fullCData(oldp+167,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N),4);
    bufp->fullCData(oldp+168,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N),4);
    bufp->fullCData(oldp+169,(((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
                                 | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                          >> 1U))) 
                                << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 1U))))),4);
    bufp->fullCData(oldp+170,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W),4);
    bufp->fullCData(oldp+171,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W),4);
    bufp->fullCData(oldp+172,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 1U)) | (1U 
                                                   & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                      >> 2U))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                 >> 1U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 2U))))),4);
    bufp->fullCData(oldp+173,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S),4);
    bufp->fullCData(oldp+174,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S),4);
    bufp->fullCData(oldp+175,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 2U)) | (1U 
                                                   & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                      >> 3U))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                 >> 2U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                   >> 3U))))),4);
    bufp->fullCData(oldp+176,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E),4);
    bufp->fullCData(oldp+177,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E),4);
    bufp->fullCData(oldp+178,(((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                        >> 2U)) | (
                                                   (2U 
                                                    & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                                       >> 3U)) 
                                                   | (1U 
                                                      & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                         >> 4U)))) 
                                << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                 >> 3U)) 
                                          | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 4U))))),5);
    bufp->fullCData(oldp+179,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B),5);
    bufp->fullCData(oldp+180,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B),5);
    bufp->fullIData(oldp+181,(((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                               [4U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                        ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                       [1U] : ((2U 
                                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                                ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                               [2U]
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                                    ? 
                                                   vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                                   [3U]
                                                    : 0U))))),23);
    bufp->fullIData(oldp+182,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W),23);
    bufp->fullIData(oldp+183,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S),23);
    bufp->fullIData(oldp+184,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E),23);
    bufp->fullIData(oldp+185,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B),23);
    bufp->fullBit(oldp+186,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    bufp->fullBit(oldp+187,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r));
    bufp->fullBit(oldp+188,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r));
    bufp->fullBit(oldp+189,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r));
    bufp->fullBit(oldp+190,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r));
    bufp->fullBit(oldp+191,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))));
    bufp->fullBit(oldp+192,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)))));
    bufp->fullBit(oldp+193,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r));
    bufp->fullCData(oldp+194,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__),2);
    bufp->fullCData(oldp+195,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
                                << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r))),2);
    bufp->fullBit(oldp+196,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))));
    bufp->fullBit(oldp+197,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)))));
    bufp->fullBit(oldp+198,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r));
    bufp->fullCData(oldp+199,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__),2);
    bufp->fullCData(oldp+200,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
                                << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r))),2);
    bufp->fullBit(oldp+201,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))));
    bufp->fullBit(oldp+202,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
    bufp->fullBit(oldp+203,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    bufp->fullCData(oldp+204,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__),2);
    bufp->fullCData(oldp+205,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
    bufp->fullBit(oldp+206,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))));
    bufp->fullBit(oldp+207,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)))));
    bufp->fullBit(oldp+208,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r));
    bufp->fullCData(oldp+209,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__),2);
    bufp->fullCData(oldp+210,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
                                << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r))),2);
    bufp->fullBit(oldp+211,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))));
    bufp->fullBit(oldp+212,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)))));
    bufp->fullBit(oldp+213,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r));
    bufp->fullCData(oldp+214,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__),2);
    bufp->fullCData(oldp+215,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
                                << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r))),2);
    bufp->fullCData(oldp+216,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req),5);
    bufp->fullIData(oldp+217,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o),17);
    bufp->fullBit(oldp+218,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy));
    bufp->fullCData(oldp+219,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req),5);
    bufp->fullIData(oldp+220,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o),23);
    bufp->fullCData(oldp+221,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr),5);
    bufp->fullBit(oldp+222,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy));
    bufp->fullCData(oldp+223,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req),5);
    bufp->fullIData(oldp+224,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o),23);
    bufp->fullCData(oldp+225,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr),5);
    bufp->fullBit(oldp+226,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy));
    bufp->fullCData(oldp+227,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req),5);
    bufp->fullIData(oldp+228,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o),23);
    bufp->fullCData(oldp+229,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr),5);
    bufp->fullBit(oldp+230,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy));
    bufp->fullCData(oldp+231,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req),5);
    bufp->fullIData(oldp+232,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o),23);
    bufp->fullCData(oldp+233,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr),5);
    bufp->fullBit(oldp+234,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                             & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))));
    bufp->fullBit(oldp+235,(vlSelfRef.clk));
    bufp->fullBit(oldp+236,(vlSelfRef.rst_n));
    bufp->fullCData(oldp+237,((0x0000001fU & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                                              | (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg)))))),5);
    bufp->fullBit(oldp+238,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy) 
                             & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld))));
    bufp->fullCData(oldp+239,((vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                               [4U] & ((~ (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode)))) 
                                       & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy)))),5);
    bufp->fullCData(oldp+240,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                                ? 0U : (7U & ((IData)(1U) 
                                              + ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                                 >> 3U))))),3);
    bufp->fullCData(oldp+241,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                                ? 0U : (7U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                               >> 3U) 
                                              + (7U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered))))))),3);
}
