// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vminimal_node_test__Syms.h"


void Vminimal_node_test___024root__trace_chg_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vminimal_node_test___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vminimal_node_test___024root__trace_chg_0\n"); );
    // Body
    Vminimal_node_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vminimal_node_test___024root*>(voidSelf);
    Vminimal_node_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vminimal_node_test___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vminimal_node_test___024root__trace_chg_0_sub_0(Vminimal_node_test___024root* vlSelf, VerilatedFst::Buffer* bufp) {
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
        bufp->chgCData(oldp+10,((7U & (IData)(vlSelfRef.minimal_node_test__DOT__pg_node))),3);
        bufp->chgCData(oldp+11,((7U & ((IData)(vlSelfRef.minimal_node_test__DOT__pg_node) 
                                       >> 3U))),3);
        bufp->chgCData(oldp+12,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_type),2);
        bufp->chgBit(oldp+13,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_qos));
        bufp->chgCData(oldp+14,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_src),6);
        bufp->chgCData(oldp+15,(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_data),8);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgCData(oldp+16,(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos),4);
        bufp->chgCData(oldp+17,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_N),5);
        bufp->chgCData(oldp+18,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_S),5);
        bufp->chgCData(oldp+19,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_E),5);
        bufp->chgCData(oldp+20,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_W),5);
        bufp->chgCData(oldp+21,(vlSelfRef.minimal_node_test__DOT__dut__DOT__route_req_A),5);
        bufp->chgBit(oldp+22,((2U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+23,((4U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+24,((8U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+25,((6U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+26,((1U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+27,((5U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+28,((7U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
        bufp->chgBit(oldp+29,((3U == (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__fault_relative_pos))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [7U])))) {
        bufp->chgCData(oldp+30,(vlSelfRef.minimal_node_test__DOT__dut__DOT__new_tgt),6);
        bufp->chgBit(oldp+31,(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg));
        bufp->chgBit(oldp+32,(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode));
        bufp->chgCData(oldp+33,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req),5);
        bufp->chgBit(oldp+34,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set));
        bufp->chgCData(oldp+35,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr),5);
        bufp->chgCData(oldp+36,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x),3);
        bufp->chgCData(oldp+37,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type),2);
        bufp->chgCData(oldp+38,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw),6);
        bufp->chgBit(oldp+39,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+40,(vlSelfRef.minimal_node_test__DOT__clk_counter),32);
        bufp->chgIData(oldp+41,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+42,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r),23);
        bufp->chgIData(oldp+43,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r),23);
        bufp->chgIData(oldp+44,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r),23);
        bufp->chgIData(oldp+45,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r),23);
        bufp->chgIData(oldp+46,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r),23);
        bufp->chgIData(oldp+47,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r),23);
        bufp->chgIData(oldp+48,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+49,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r),23);
        bufp->chgIData(oldp+50,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r),23);
        bufp->chgBit(oldp+51,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                     >> 0x00000014U))));
        bufp->chgCData(oldp+52,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgCData(oldp+53,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                                >> 0x0000000eU))),6);
        bufp->chgCData(oldp+54,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r 
                                                >> 8U))),6);
        bufp->chgCData(oldp+55,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r)),8);
        bufp->chgBit(oldp+56,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 0x00000014U))));
        bufp->chgCData(oldp+57,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgCData(oldp+58,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000eU))),6);
        bufp->chgCData(oldp+59,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 8U))),6);
        bufp->chgCData(oldp+60,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgBit(oldp+61,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                     >> 0x00000014U))));
        bufp->chgCData(oldp+62,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgCData(oldp+63,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                >> 0x0000000eU))),6);
        bufp->chgCData(oldp+64,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r 
                                                >> 8U))),6);
        bufp->chgCData(oldp+65,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r)),8);
        bufp->chgBit(oldp+66,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                     >> 0x00000014U))));
        bufp->chgCData(oldp+67,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgCData(oldp+68,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                >> 0x0000000eU))),6);
        bufp->chgCData(oldp+69,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r 
                                                >> 8U))),6);
        bufp->chgCData(oldp+70,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r)),8);
        bufp->chgBit(oldp+71,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                     >> 0x00000014U))));
        bufp->chgCData(oldp+72,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgCData(oldp+73,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                                >> 0x0000000eU))),6);
        bufp->chgCData(oldp+74,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r 
                                                >> 8U))),6);
        bufp->chgCData(oldp+75,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r)),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+76,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[0]),5);
        bufp->chgCData(oldp+77,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[1]),5);
        bufp->chgCData(oldp+78,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[2]),5);
        bufp->chgCData(oldp+79,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[3]),5);
        bufp->chgCData(oldp+80,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_req[4]),5);
        bufp->chgIData(oldp+81,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[0]),23);
        bufp->chgIData(oldp+82,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[1]),23);
        bufp->chgIData(oldp+83,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[2]),23);
        bufp->chgIData(oldp+84,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[3]),23);
        bufp->chgIData(oldp+85,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pld_buf[4]),23);
        bufp->chgCData(oldp+86,(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy),5);
        bufp->chgBit(oldp+87,((1U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                     >> 0x00000010U))));
        bufp->chgCData(oldp+88,((3U & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                       >> 0x0000000eU))),2);
        bufp->chgCData(oldp+89,((0x0000003fU & (vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o 
                                                >> 8U))),6);
        bufp->chgCData(oldp+90,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered),6);
        bufp->chgCData(oldp+91,((0x000000ffU & vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o)),8);
        bufp->chgBit(oldp+92,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy));
        bufp->chgBit(oldp+93,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy));
        bufp->chgCData(oldp+94,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                          << 1U)) | 
                                   (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req))) 
                                  << 2U) | ((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                   << 1U)) 
                                            | (1U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req))))),4);
        bufp->chgCData(oldp+95,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_N),4);
        bufp->chgCData(oldp+96,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N),4);
        bufp->chgCData(oldp+97,(((((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req)) 
                                   | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                            >> 1U))) 
                                  << 2U) | ((2U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req)) 
                                            | (1U & 
                                               ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                >> 1U))))),4);
        bufp->chgCData(oldp+98,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_W),4);
        bufp->chgCData(oldp+99,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W),4);
        bufp->chgCData(oldp+100,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           >> 1U)) 
                                    | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                             >> 2U))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                               >> 1U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req) 
                                                   >> 2U))))),4);
        bufp->chgCData(oldp+101,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_S),4);
        bufp->chgCData(oldp+102,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S),4);
        bufp->chgCData(oldp+103,(((((2U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
                                           >> 2U)) 
                                    | (1U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req) 
                                             >> 3U))) 
                                   << 2U) | ((2U & 
                                              ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req) 
                                               >> 2U)) 
                                             | (1U 
                                                & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req) 
                                                   >> 3U))))),4);
        bufp->chgCData(oldp+104,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_E),4);
        bufp->chgCData(oldp+105,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E),4);
        bufp->chgCData(oldp+106,(((((4U & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req) 
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
        bufp->chgCData(oldp+107,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_qos_B),5);
        bufp->chgCData(oldp+108,(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B),5);
        bufp->chgIData(oldp+109,(((8U & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))
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
        bufp->chgIData(oldp+110,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_W),23);
        bufp->chgIData(oldp+111,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_S),23);
        bufp->chgIData(oldp+112,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_E),23);
        bufp->chgIData(oldp+113,(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_B),23);
        bufp->chgBit(oldp+114,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+115,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r));
        bufp->chgBit(oldp+116,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r));
        bufp->chgBit(oldp+117,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r));
        bufp->chgBit(oldp+118,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r));
        bufp->chgBit(oldp+119,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_B))));
        bufp->chgBit(oldp+120,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r)))));
        bufp->chgBit(oldp+121,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r));
        bufp->chgCData(oldp+122,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+123,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+124,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_E))));
        bufp->chgBit(oldp+125,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r)))));
        bufp->chgBit(oldp+126,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r));
        bufp->chgCData(oldp+127,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+128,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+129,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_N))));
        bufp->chgBit(oldp+130,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+131,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+132,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+133,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+134,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_S))));
        bufp->chgBit(oldp+135,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r)))));
        bufp->chgBit(oldp+136,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r));
        bufp->chgCData(oldp+137,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+138,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+139,((0U != (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt_W))));
        bufp->chgBit(oldp+140,((1U & (~ (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r)))));
        bufp->chgBit(oldp+141,(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r));
        bufp->chgCData(oldp+142,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+143,((((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__))),2);
        bufp->chgCData(oldp+144,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req),5);
        bufp->chgIData(oldp+145,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o),17);
        bufp->chgBit(oldp+146,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy));
        bufp->chgCData(oldp+147,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req),5);
        bufp->chgIData(oldp+148,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o),23);
        bufp->chgCData(oldp+149,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr),5);
        bufp->chgBit(oldp+150,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy));
        bufp->chgCData(oldp+151,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req),5);
        bufp->chgIData(oldp+152,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o),23);
        bufp->chgCData(oldp+153,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr),5);
        bufp->chgBit(oldp+154,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy));
        bufp->chgCData(oldp+155,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req),5);
        bufp->chgIData(oldp+156,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o),23);
        bufp->chgCData(oldp+157,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr),5);
        bufp->chgBit(oldp+158,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy));
        bufp->chgCData(oldp+159,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req),5);
        bufp->chgIData(oldp+160,(vlSelfRef.minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o),23);
        bufp->chgCData(oldp+161,(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr),5);
        bufp->chgBit(oldp+162,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy) 
                                & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy))));
    }
    bufp->chgBit(oldp+163,(vlSelfRef.clk));
    bufp->chgBit(oldp+164,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+165,((0x0000001fU & ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy) 
                                             | (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__tgt_is_pg)))))),5);
    bufp->chgBit(oldp+166,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy) 
                            & (IData)(vlSymsp->TOP__minimal_node_test__DOT__pkt_i.pkt_in_vld))));
    bufp->chgCData(oldp+167,((vlSelfRef.minimal_node_test__DOT__dut__DOT__arb_gnt
                              [4U] & ((~ (- (IData)((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__cpy_mode)))) 
                                      & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__obuf_rdy)))),5);
    bufp->chgCData(oldp+168,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                               ? 0U : (7U & ((IData)(1U) 
                                             + ((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                                >> 3U))))),3);
    bufp->chgCData(oldp+169,(((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr)
                               ? 0U : (7U & (((IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered) 
                                              >> 3U) 
                                             + (7U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSelfRef.minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered))))))),3);
}

void Vminimal_node_test___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
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
