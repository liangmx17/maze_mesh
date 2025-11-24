// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vminimal_node_test__Syms.h"


void Vminimal_node_test___024root__trace_chg_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vminimal_node_test___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_chg_0\n"); );
    // Body
    Vminimal_node_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vminimal_node_test___024root*>(voidSelf);
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vminimal_node_test___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vminimal_node_test___024root__trace_chg_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_chg_0_sub_0\n"); );
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.minimal_node_test__DOT__pg_en));
        bufp->chgCData(oldp+1,(vlSelfRef.minimal_node_test__DOT__pg_node),6);
        bufp->chgIData(oldp+2,(vlSelfRef.minimal_node_test__DOT__test_count),32);
        bufp->chgIData(oldp+3,(vlSelfRef.minimal_node_test__DOT__passed_count),32);
        bufp->chgIData(oldp+4,(vlSelfRef.minimal_node_test__DOT__timeout_counter),32);
        bufp->chgIData(oldp+5,(vlSelfRef.minimal_node_test__DOT__test_packet_data),23);
        bufp->chgBit(oldp+6,(vlSelfRef.minimal_node_test__DOT__test_packet_valid));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld));
        bufp->chgCData(oldp+8,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_tgt),6);
        bufp->chgIData(oldp+9,((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos) 
                                 << 0x00000010U) | 
                                (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type) 
                                  << 0x0000000eU) | 
                                 (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src) 
                                   << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data))))),17);
        bufp->chgBit(oldp+10,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_vld));
        bufp->chgIData(oldp+11,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos) 
                                   << 0x00000016U) 
                                  | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type) 
                                      << 0x00000014U) 
                                     | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                        << 0x0000000eU))) 
                                 | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                     << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data)))),23);
        bufp->chgBit(oldp+12,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_vld));
        bufp->chgIData(oldp+13,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos) 
                                   << 0x00000016U) 
                                  | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type) 
                                      << 0x00000014U) 
                                     | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                        << 0x0000000eU))) 
                                 | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                     << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data)))),23);
        bufp->chgBit(oldp+14,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_vld));
        bufp->chgIData(oldp+15,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos) 
                                   << 0x00000016U) 
                                  | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type) 
                                      << 0x00000014U) 
                                     | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                        << 0x0000000eU))) 
                                 | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                     << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data)))),23);
        bufp->chgBit(oldp+16,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_vld));
        bufp->chgIData(oldp+17,(((((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos) 
                                   << 0x00000016U) 
                                  | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type) 
                                      << 0x00000014U) 
                                     | ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                        << 0x0000000eU))) 
                                 | (((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                     << 8U) | (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data)))),23);
        bufp->chgCData(oldp+18,((7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node))),3);
        bufp->chgCData(oldp+19,((7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+20,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type),2);
        bufp->chgCData(oldp+21,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt))),3);
        bufp->chgCData(oldp+22,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+23,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src))),3);
        bufp->chgCData(oldp+24,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+25,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_type),2);
        bufp->chgBit(oldp+26,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                            >> 3U)))));
        bufp->chgBit(oldp+27,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
        bufp->chgBit(oldp+28,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
        bufp->chgBit(oldp+29,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt)))));
        bufp->chgBit(oldp+30,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+31,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+32,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src) 
                                            >> 3U)))));
        bufp->chgCData(oldp+33,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt))),3);
        bufp->chgCData(oldp+34,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+35,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src))),3);
        bufp->chgCData(oldp+36,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+37,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_type),2);
        bufp->chgBit(oldp+38,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                            >> 3U)))));
        bufp->chgBit(oldp+39,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
        bufp->chgBit(oldp+40,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
        bufp->chgBit(oldp+41,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt)))));
        bufp->chgBit(oldp+42,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+43,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+44,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src) 
                                            >> 3U)))));
        bufp->chgCData(oldp+45,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt))),3);
        bufp->chgCData(oldp+46,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+47,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src))),3);
        bufp->chgCData(oldp+48,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+49,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_type),2);
        bufp->chgBit(oldp+50,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                            >> 3U)))));
        bufp->chgBit(oldp+51,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
        bufp->chgBit(oldp+52,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
        bufp->chgBit(oldp+53,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt)))));
        bufp->chgBit(oldp+54,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+55,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+56,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src) 
                                            >> 3U)))));
        bufp->chgCData(oldp+57,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt))),3);
        bufp->chgCData(oldp+58,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+59,((7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src))),3);
        bufp->chgCData(oldp+60,((7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+61,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_type),2);
        bufp->chgBit(oldp+62,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                            >> 3U)))));
        bufp->chgBit(oldp+63,((0U == (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
        bufp->chgBit(oldp+64,((0U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
        bufp->chgBit(oldp+65,((1U < (7U & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt)))));
        bufp->chgBit(oldp+66,((0U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+67,((1U < (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt) 
                                           >> 3U)))));
        bufp->chgBit(oldp+68,((0U == (7U & ((IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src) 
                                            >> 3U)))));
        bufp->chgBit(oldp+69,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos));
        bufp->chgCData(oldp+70,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src),6);
        bufp->chgCData(oldp+71,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data),8);
        bufp->chgBit(oldp+72,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_qos));
        bufp->chgCData(oldp+73,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_src),6);
        bufp->chgCData(oldp+74,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_tgt),6);
        bufp->chgCData(oldp+75,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ni_data),8);
        bufp->chgBit(oldp+76,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_qos));
        bufp->chgCData(oldp+77,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_src),6);
        bufp->chgCData(oldp+78,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_tgt),6);
        bufp->chgCData(oldp+79,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.wi_data),8);
        bufp->chgBit(oldp+80,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_qos));
        bufp->chgCData(oldp+81,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_src),6);
        bufp->chgCData(oldp+82,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_tgt),6);
        bufp->chgCData(oldp+83,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.si_data),8);
        bufp->chgBit(oldp+84,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_qos));
        bufp->chgCData(oldp+85,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_src),6);
        bufp->chgCData(oldp+86,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_tgt),6);
        bufp->chgCData(oldp+87,(vlSymsp->TOP__minimal_node_test__DOT__pkt_con.ei_data),8);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgCData(oldp+88,(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos),4);
        bufp->chgCData(oldp+89,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N),5);
        bufp->chgCData(oldp+90,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S),5);
        bufp->chgCData(oldp+91,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E),5);
        bufp->chgCData(oldp+92,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W),5);
        bufp->chgCData(oldp+93,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A),5);
        bufp->chgBit(oldp+94,((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+95,((4U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+96,((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+97,((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+98,((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+99,((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+100,((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+101,((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgCData(oldp+102,(vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt),6);
        bufp->chgBit(oldp+103,(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg));
        bufp->chgBit(oldp+104,(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode));
        bufp->chgCData(oldp+105,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req),5);
        bufp->chgBit(oldp+106,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set));
        bufp->chgCData(oldp+107,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr),5);
        bufp->chgBit(oldp+108,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set));
        bufp->chgBit(oldp+109,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set));
        bufp->chgBit(oldp+110,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set));
        bufp->chgBit(oldp+111,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set));
        bufp->chgCData(oldp+112,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x),3);
        bufp->chgCData(oldp+113,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type),2);
        bufp->chgCData(oldp+114,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw),6);
        bufp->chgBit(oldp+115,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+116,(vlSelfRef.minimal_node_test__DOT__clk_counter),32);
        bufp->chgIData(oldp+117,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+118,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r),23);
        bufp->chgIData(oldp+119,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r),23);
        bufp->chgIData(oldp+120,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r),23);
        bufp->chgIData(oldp+121,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),23);
        bufp->chgBit(oldp+122,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+123,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgCData(oldp+124,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+125,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+126,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r)),8);
        bufp->chgBit(oldp+127,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+128,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgCData(oldp+129,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+130,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+131,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgBit(oldp+132,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+133,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgCData(oldp+134,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+135,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+136,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r)),8);
        bufp->chgBit(oldp+137,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+138,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgCData(oldp+139,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+140,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+141,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r)),8);
        bufp->chgBit(oldp+142,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+143,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgCData(oldp+144,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+145,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+146,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r)),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+147,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[0]),5);
        bufp->chgCData(oldp+148,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[1]),5);
        bufp->chgCData(oldp+149,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[2]),5);
        bufp->chgCData(oldp+150,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[3]),5);
        bufp->chgCData(oldp+151,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[4]),5);
        bufp->chgIData(oldp+152,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[0]),23);
        bufp->chgIData(oldp+153,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[1]),23);
        bufp->chgIData(oldp+154,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[2]),23);
        bufp->chgIData(oldp+155,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[3]),23);
        bufp->chgIData(oldp+156,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4]),23);
        bufp->chgCData(oldp+157,(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy),5);
        bufp->chgBit(oldp+158,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                      >> 0x00000010U))));
        bufp->chgCData(oldp+159,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                        >> 0x0000000eU))),2);
        bufp->chgCData(oldp+160,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+161,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered),6);
        bufp->chgCData(oldp+162,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)),8);
        bufp->chgBit(oldp+163,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy));
        bufp->chgBit(oldp+164,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy));
        bufp->chgCData(oldp+165,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           << 1U)) 
                                    | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                               << 1U)) 
                                             | (1U 
                                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))))),4);
        bufp->chgCData(oldp+166,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N),4);
        bufp->chgCData(oldp+167,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N),4);
        bufp->chgCData(oldp+168,(((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
                                    | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                             >> 1U))) 
                                   << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 1U))))),4);
        bufp->chgCData(oldp+169,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W),4);
        bufp->chgCData(oldp+170,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W),4);
        bufp->chgCData(oldp+171,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           >> 1U)) 
                                    | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                             >> 2U))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                               >> 1U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 2U))))),4);
        bufp->chgCData(oldp+172,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S),4);
        bufp->chgCData(oldp+173,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S),4);
        bufp->chgCData(oldp+174,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           >> 2U)) 
                                    | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                             >> 3U))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                               >> 2U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                   >> 3U))))),4);
        bufp->chgCData(oldp+175,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E),4);
        bufp->chgCData(oldp+176,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E),4);
        bufp->chgCData(oldp+177,(((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           >> 2U)) 
                                    | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                              >> 3U)) 
                                       | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                                >> 4U)))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                               >> 3U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 4U))))),5);
        bufp->chgCData(oldp+178,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B),5);
        bufp->chgCData(oldp+179,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B),5);
        bufp->chgIData(oldp+180,(((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                   ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                  [4U] : ((4U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                           ? vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                          [1U] : ((2U 
                                                   & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                                   ? 
                                                  vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                                  [2U]
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
                                                    ? 
                                                   vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf
                                                   [3U]
                                                    : 0U))))),23);
        bufp->chgIData(oldp+181,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W),23);
        bufp->chgIData(oldp+182,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S),23);
        bufp->chgIData(oldp+183,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E),23);
        bufp->chgIData(oldp+184,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B),23);
        bufp->chgBit(oldp+185,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+186,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r));
        bufp->chgBit(oldp+187,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r));
        bufp->chgBit(oldp+188,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r));
        bufp->chgBit(oldp+189,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r));
        bufp->chgBit(oldp+190,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))));
        bufp->chgBit(oldp+191,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)))));
        bufp->chgBit(oldp+192,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r));
        bufp->chgCData(oldp+193,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__),2);
        bufp->chgCData(oldp+194,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r))),2);
        bufp->chgBit(oldp+195,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))));
        bufp->chgBit(oldp+196,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)))));
        bufp->chgBit(oldp+197,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r));
        bufp->chgCData(oldp+198,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__),2);
        bufp->chgCData(oldp+199,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r))),2);
        bufp->chgBit(oldp+200,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))));
        bufp->chgBit(oldp+201,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+202,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+203,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__),2);
        bufp->chgCData(oldp+204,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
        bufp->chgBit(oldp+205,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))));
        bufp->chgBit(oldp+206,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)))));
        bufp->chgBit(oldp+207,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r));
        bufp->chgCData(oldp+208,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__),2);
        bufp->chgCData(oldp+209,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r))),2);
        bufp->chgBit(oldp+210,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))));
        bufp->chgBit(oldp+211,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)))));
        bufp->chgBit(oldp+212,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r));
        bufp->chgCData(oldp+213,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__),2);
        bufp->chgCData(oldp+214,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r))),2);
        bufp->chgCData(oldp+215,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req),5);
        bufp->chgIData(oldp+216,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o),17);
        bufp->chgBit(oldp+217,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy));
        bufp->chgCData(oldp+218,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req),5);
        bufp->chgIData(oldp+219,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o),23);
        bufp->chgCData(oldp+220,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr),5);
        bufp->chgBit(oldp+221,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy));
        bufp->chgCData(oldp+222,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req),5);
        bufp->chgIData(oldp+223,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o),23);
        bufp->chgCData(oldp+224,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr),5);
        bufp->chgBit(oldp+225,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy));
        bufp->chgCData(oldp+226,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req),5);
        bufp->chgIData(oldp+227,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o),23);
        bufp->chgCData(oldp+228,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr),5);
        bufp->chgBit(oldp+229,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy));
        bufp->chgCData(oldp+230,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req),5);
        bufp->chgIData(oldp+231,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o),23);
        bufp->chgCData(oldp+232,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr),5);
        bufp->chgBit(oldp+233,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))));
    }
    bufp->chgBit(oldp+234,(vlSelfRef.clk));
    bufp->chgBit(oldp+235,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+236,((0x0000001fU & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                                             | (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg)))))),5);
    bufp->chgBit(oldp+237,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy) 
                            & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld))));
    bufp->chgCData(oldp+238,((vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [4U] & ((~ (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode)))) 
                                      & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy)))),5);
    bufp->chgCData(oldp+239,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                               ? 0U : (7U & ((IData)(1U) 
                                             + ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                                >> 3U))))),3);
    bufp->chgCData(oldp+240,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                               ? 0U : (7U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                              >> 3U) 
                                             + (7U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered))))))),3);
}

void Vminimal_node_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_cleanup\n"); );
    // Body
    Vminimal_node_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vminimal_node_test___024root*>(voidSelf);
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
