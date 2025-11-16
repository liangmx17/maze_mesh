// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsimple_test__Syms.h"


void Vsimple_test___024root__trace_chg_0_sub_0(Vsimple_test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsimple_test___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root__trace_chg_0\n"); );
    // Body
    Vsimple_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsimple_test___024root*>(voidSelf);
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vsimple_test___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsimple_test___024root__trace_chg_0_sub_0(Vsimple_test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root__trace_chg_0_sub_0\n"); );
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.simple_test__DOT__rst_n));
        bufp->chgBit(oldp+1,(vlSelfRef.simple_test__DOT__pg_en));
        bufp->chgCData(oldp+2,(vlSelfRef.simple_test__DOT__pg_node),6);
        bufp->chgIData(oldp+3,(vlSelfRef.simple_test__DOT__error_count),32);
        bufp->chgIData(oldp+4,(vlSelfRef.simple_test__DOT__test_count),32);
        bufp->chgIData(oldp+5,(vlSelfRef.simple_test__DOT__pass_count),32);
        bufp->chgBit(oldp+6,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_vld));
        bufp->chgCData(oldp+7,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type),2);
        bufp->chgBit(oldp+8,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos));
        bufp->chgCData(oldp+9,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src),6);
        bufp->chgCData(oldp+10,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt),6);
        bufp->chgCData(oldp+11,(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data),8);
        bufp->chgBit(oldp+12,(vlSelfRef.simple_test__DOT__pkt_o_pkt_out_rdy));
        bufp->chgBit(oldp+13,(vlSelfRef.simple_test__DOT__pkt_con_no_rdy));
        bufp->chgBit(oldp+14,(vlSelfRef.simple_test__DOT__pkt_con_wo_rdy));
        bufp->chgBit(oldp+15,(vlSelfRef.simple_test__DOT__pkt_con_so_rdy));
        bufp->chgBit(oldp+16,(vlSelfRef.simple_test__DOT__pkt_con_eo_rdy));
        bufp->chgCData(oldp+17,((7U & (IData)(vlSelfRef.simple_test__DOT__pg_node))),3);
        bufp->chgCData(oldp+18,((7U & ((IData)(vlSelfRef.simple_test__DOT__pg_node) 
                                       >> 3U))),3);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgCData(oldp+19,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A),5);
        bufp->chgCData(oldp+20,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N),5);
        bufp->chgCData(oldp+21,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W),5);
        bufp->chgCData(oldp+22,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S),5);
        bufp->chgCData(oldp+23,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E),5);
        bufp->chgCData(oldp+24,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_N),4);
        bufp->chgCData(oldp+25,((0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)),4);
        bufp->chgCData(oldp+26,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_W),4);
        bufp->chgCData(oldp+27,((0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)),4);
        bufp->chgCData(oldp+28,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_S),4);
        bufp->chgCData(oldp+29,((0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)),4);
        bufp->chgCData(oldp+30,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_E),4);
        bufp->chgCData(oldp+31,((0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1)),4);
        bufp->chgCData(oldp+32,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_req_B),5);
        bufp->chgCData(oldp+33,((0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)),5);
        bufp->chgIData(oldp+34,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload_i),23);
        bufp->chgIData(oldp+35,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload_i),23);
        bufp->chgIData(oldp+36,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload_i),23);
        bufp->chgIData(oldp+37,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload_i),23);
        bufp->chgCData(oldp+38,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__set__BRA__0__KET__),2);
        bufp->chgBit(oldp+39,((0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))));
        bufp->chgCData(oldp+40,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+41,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+42,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1))));
        bufp->chgCData(oldp+43,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+44,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+45,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2))));
        bufp->chgCData(oldp+46,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+47,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+48,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))));
        bufp->chgCData(oldp+49,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+50,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+51,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))));
        bufp->chgCData(oldp+52,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+53,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__clr__BRA__0__KET__))),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+54,(vlSelfRef.simple_test__DOT__last_output_pkt),23);
        bufp->chgCData(oldp+55,(vlSelfRef.simple_test__DOT__last_output_port),3);
        bufp->chgBit(oldp+56,(vlSelfRef.simple_test__DOT__last_output_valid));
        bufp->chgIData(oldp+57,(vlSelfRef.simple_test__DOT__manual_encoded),23);
        bufp->chgBit(oldp+58,(vlSelfRef.simple_test__DOT__irs_status_a
                              .__PVT__input_valid));
        bufp->chgBit(oldp+59,(vlSelfRef.simple_test__DOT__irs_status_a
                              .__PVT__input_ready));
        bufp->chgBit(oldp+60,(vlSelfRef.simple_test__DOT__irs_status_a
                              .__PVT__output_valid));
        bufp->chgBit(oldp+61,(vlSelfRef.simple_test__DOT__irs_status_a
                              .__PVT__output_ready));
        bufp->chgIData(oldp+62,(vlSelfRef.simple_test__DOT__irs_status_a
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+63,(vlSelfRef.simple_test__DOT__irs_status_a
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+64,(vlSelfRef.simple_test__DOT__irs_status_a
                                .__PVT__depth_count),32);
        bufp->chgBit(oldp+65,(vlSelfRef.simple_test__DOT__irs_status_n
                              .__PVT__input_valid));
        bufp->chgBit(oldp+66,(vlSelfRef.simple_test__DOT__irs_status_n
                              .__PVT__input_ready));
        bufp->chgBit(oldp+67,(vlSelfRef.simple_test__DOT__irs_status_n
                              .__PVT__output_valid));
        bufp->chgBit(oldp+68,(vlSelfRef.simple_test__DOT__irs_status_n
                              .__PVT__output_ready));
        bufp->chgIData(oldp+69,(vlSelfRef.simple_test__DOT__irs_status_n
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+70,(vlSelfRef.simple_test__DOT__irs_status_n
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+71,(vlSelfRef.simple_test__DOT__irs_status_n
                                .__PVT__depth_count),32);
        bufp->chgBit(oldp+72,(vlSelfRef.simple_test__DOT__irs_status_w
                              .__PVT__input_valid));
        bufp->chgBit(oldp+73,(vlSelfRef.simple_test__DOT__irs_status_w
                              .__PVT__input_ready));
        bufp->chgBit(oldp+74,(vlSelfRef.simple_test__DOT__irs_status_w
                              .__PVT__output_valid));
        bufp->chgBit(oldp+75,(vlSelfRef.simple_test__DOT__irs_status_w
                              .__PVT__output_ready));
        bufp->chgIData(oldp+76,(vlSelfRef.simple_test__DOT__irs_status_w
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+77,(vlSelfRef.simple_test__DOT__irs_status_w
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+78,(vlSelfRef.simple_test__DOT__irs_status_w
                                .__PVT__depth_count),32);
        bufp->chgBit(oldp+79,(vlSelfRef.simple_test__DOT__irs_status_s
                              .__PVT__input_valid));
        bufp->chgBit(oldp+80,(vlSelfRef.simple_test__DOT__irs_status_s
                              .__PVT__input_ready));
        bufp->chgBit(oldp+81,(vlSelfRef.simple_test__DOT__irs_status_s
                              .__PVT__output_valid));
        bufp->chgBit(oldp+82,(vlSelfRef.simple_test__DOT__irs_status_s
                              .__PVT__output_ready));
        bufp->chgIData(oldp+83,(vlSelfRef.simple_test__DOT__irs_status_s
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+84,(vlSelfRef.simple_test__DOT__irs_status_s
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+85,(vlSelfRef.simple_test__DOT__irs_status_s
                                .__PVT__depth_count),32);
        bufp->chgBit(oldp+86,(vlSelfRef.simple_test__DOT__irs_status_e
                              .__PVT__input_valid));
        bufp->chgBit(oldp+87,(vlSelfRef.simple_test__DOT__irs_status_e
                              .__PVT__input_ready));
        bufp->chgBit(oldp+88,(vlSelfRef.simple_test__DOT__irs_status_e
                              .__PVT__output_valid));
        bufp->chgBit(oldp+89,(vlSelfRef.simple_test__DOT__irs_status_e
                              .__PVT__output_ready));
        bufp->chgIData(oldp+90,(vlSelfRef.simple_test__DOT__irs_status_e
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+91,(vlSelfRef.simple_test__DOT__irs_status_e
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+92,(vlSelfRef.simple_test__DOT__irs_status_e
                                .__PVT__depth_count),32);
        bufp->chgBit(oldp+93,(vlSelfRef.simple_test__DOT__irs_status_b
                              .__PVT__input_valid));
        bufp->chgBit(oldp+94,(vlSelfRef.simple_test__DOT__irs_status_b
                              .__PVT__input_ready));
        bufp->chgBit(oldp+95,(vlSelfRef.simple_test__DOT__irs_status_b
                              .__PVT__output_valid));
        bufp->chgBit(oldp+96,(vlSelfRef.simple_test__DOT__irs_status_b
                              .__PVT__output_ready));
        bufp->chgIData(oldp+97,(vlSelfRef.simple_test__DOT__irs_status_b
                                .__PVT__input_payload),23);
        bufp->chgIData(oldp+98,(vlSelfRef.simple_test__DOT__irs_status_b
                                .__PVT__output_payload),23);
        bufp->chgIData(oldp+99,(vlSelfRef.simple_test__DOT__irs_status_b
                                .__PVT__depth_count),32);
        bufp->chgIData(oldp+100,(vlSelfRef.simple_test__DOT__first_10_cycles_debug),32);
        bufp->chgBit(oldp+101,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r));
        bufp->chgBit(oldp+102,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r));
        bufp->chgBit(oldp+103,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r));
        bufp->chgBit(oldp+104,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r));
        bufp->chgBit(oldp+105,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[4U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgCData(oldp+106,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid0_r))),2);
        bufp->chgCData(oldp+107,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid0_r))),2);
        bufp->chgCData(oldp+108,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid0_r))),2);
        bufp->chgCData(oldp+109,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid0_r))),2);
        bufp->chgCData(oldp+110,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r) 
                                   << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid0_r))),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+111,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgBit(oldp+112,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+113,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+114,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+115,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r)),8);
        bufp->chgCData(oldp+116,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgBit(oldp+117,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+118,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+119,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+120,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgCData(oldp+121,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgBit(oldp+122,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+123,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+124,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+125,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r)),8);
        bufp->chgCData(oldp+126,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgBit(oldp+127,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+128,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+129,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+130,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r)),8);
        bufp->chgCData(oldp+131,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                        >> 0x00000015U))),2);
        bufp->chgBit(oldp+132,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                      >> 0x00000014U))));
        bufp->chgCData(oldp+133,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                                 >> 0x0000000eU))),6);
        bufp->chgCData(oldp+134,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r 
                                                 >> 8U))),6);
        bufp->chgCData(oldp+135,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r)),8);
        bufp->chgIData(oldp+136,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r),23);
        bufp->chgIData(oldp+137,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__payload0_r),23);
        bufp->chgIData(oldp+138,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r),23);
        bufp->chgIData(oldp+139,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r),23);
        bufp->chgIData(oldp+140,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r),23);
        bufp->chgCData(oldp+141,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N),4);
        bufp->chgCData(oldp+142,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W),4);
        bufp->chgCData(oldp+143,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S),4);
        bufp->chgCData(oldp+144,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E),4);
        bufp->chgCData(oldp+145,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B),5);
        bufp->chgIData(oldp+146,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+147,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload0_r),23);
        bufp->chgIData(oldp+148,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload0_r),23);
        bufp->chgIData(oldp+149,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload0_r),23);
        bufp->chgIData(oldp+150,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload0_r),23);
        bufp->chgIData(oldp+151,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__payload1_r),23);
        bufp->chgIData(oldp+152,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__payload1_r),23);
        bufp->chgIData(oldp+153,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+154,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__payload1_r),23);
        bufp->chgIData(oldp+155,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__payload1_r),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+156,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r)))));
        bufp->chgBit(oldp+157,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid0_r));
        bufp->chgBit(oldp+158,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+159,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid0_r));
        bufp->chgBit(oldp+160,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid0_r));
        bufp->chgBit(oldp+161,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid0_r));
        bufp->chgBit(oldp+162,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r)))));
        bufp->chgBit(oldp+163,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r)))));
        bufp->chgBit(oldp+164,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r)))));
        bufp->chgBit(oldp+165,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r)))));
        bufp->chgBit(oldp+166,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+167,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r)))));
        bufp->chgBit(oldp+168,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r)))));
        bufp->chgBit(oldp+169,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r)))));
        bufp->chgBit(oldp+170,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r)))));
        bufp->chgBit(oldp+171,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__valid1_r));
        bufp->chgBit(oldp+172,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r));
        bufp->chgCData(oldp+173,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__valid1_r),2);
        bufp->chgBit(oldp+174,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r));
        bufp->chgCData(oldp+175,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__valid1_r),2);
        bufp->chgBit(oldp+176,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r));
        bufp->chgCData(oldp+177,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__valid1_r),2);
        bufp->chgBit(oldp+178,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r));
        bufp->chgCData(oldp+179,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__valid1_r),2);
        bufp->chgBit(oldp+180,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__valid1_r));
        bufp->chgBit(oldp+181,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__valid1_r));
        bufp->chgBit(oldp+182,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+183,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__valid1_r));
        bufp->chgBit(oldp+184,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__valid1_r));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+185,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x),3);
        bufp->chgCData(oldp+186,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y),3);
        bufp->chgCData(oldp+187,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type),2);
        bufp->chgCData(oldp+188,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x),3);
        bufp->chgCData(oldp+189,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y),3);
        bufp->chgCData(oldp+190,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type),2);
        bufp->chgCData(oldp+191,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x),3);
        bufp->chgCData(oldp+192,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y),3);
        bufp->chgCData(oldp+193,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type),2);
        bufp->chgCData(oldp+194,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x),3);
        bufp->chgCData(oldp+195,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y),3);
        bufp->chgCData(oldp+196,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type),2);
        bufp->chgCData(oldp+197,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x),3);
        bufp->chgCData(oldp+198,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y),3);
        bufp->chgCData(oldp+199,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type),2);
    }
    bufp->chgBit(oldp+200,(vlSelfRef.simple_test__DOT__clk));
    bufp->chgIData(oldp+201,(vlSelfRef.simple_test__DOT__test_cycle),32);
    bufp->chgIData(oldp+202,(vlSelfRef.simple_test__DOT__debug_cycle_counter),32);
    bufp->chgCData(oldp+203,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos),4);
    bufp->chgIData(oldp+204,(((8U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__payload0_r
                               : ((4U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__payload0_r
                                   : ((2U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__payload0_r
                                       : ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__payload0_r
                                           : 0U))))),23);
    bufp->chgIData(oldp+205,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT____Vcellinp__irs_input_A__payload_i),23);
}

void Vsimple_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimple_test___024root__trace_cleanup\n"); );
    // Body
    Vsimple_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsimple_test___024root*>(voidSelf);
    Vsimple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
}
