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
        bufp->chgIData(oldp+19,(((((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_type) 
                                   << 0x00000015U) 
                                  | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_qos) 
                                      << 0x00000014U) 
                                     | ((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_src) 
                                        << 0x0000000eU))) 
                                 | (((IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_tgt) 
                                     << 8U) | (IData)(vlSelfRef.simple_test__DOT__pkt_i_pkt_in_data)))),23);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgCData(oldp+20,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A),5);
        bufp->chgCData(oldp+21,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N),5);
        bufp->chgCData(oldp+22,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W),5);
        bufp->chgCData(oldp+23,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S),5);
        bufp->chgCData(oldp+24,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E),5);
        bufp->chgCData(oldp+25,(((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                          << 1U)) | 
                                   (1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W))) 
                                  << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                   << 1U)) 
                                            | (1U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E))))),4);
        bufp->chgCData(oldp+26,((0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)),4);
        bufp->chgCData(oldp+27,(((((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A)) 
                                   | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                            >> 1U))) 
                                  << 2U) | ((2U & (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S)) 
                                            | (1U & 
                                               ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                >> 1U))))),4);
        bufp->chgCData(oldp+28,((0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)),4);
        bufp->chgCData(oldp+29,(((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                          >> 1U)) | 
                                   (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                          >> 2U))) 
                                  << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                   >> 1U)) 
                                            | (1U & 
                                               ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                >> 2U))))),4);
        bufp->chgCData(oldp+30,((0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)),4);
        bufp->chgCData(oldp+31,(((((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                          >> 2U)) | 
                                   (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                          >> 3U))) 
                                  << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                                   >> 2U)) 
                                            | (1U & 
                                               ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                >> 3U))))),4);
        bufp->chgCData(oldp+32,((0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)),4);
        bufp->chgCData(oldp+33,(((((4U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A) 
                                          >> 2U)) | 
                                   ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N) 
                                           >> 3U)) 
                                    | (1U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W) 
                                             >> 4U)))) 
                                  << 2U) | ((2U & ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S) 
                                                   >> 3U)) 
                                            | (1U & 
                                               ((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E) 
                                                >> 4U))))),5);
        bufp->chgCData(oldp+34,((0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)),5);
        bufp->chgCData(oldp+35,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__),2);
        bufp->chgBit(oldp+36,((0U != (0x0000001fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
        bufp->chgCData(oldp+37,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+38,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+39,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_1))));
        bufp->chgCData(oldp+40,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+41,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+42,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_2))));
        bufp->chgCData(oldp+43,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+44,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+45,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_3))));
        bufp->chgCData(oldp+46,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+47,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
        bufp->chgBit(oldp+48,((0U != (0x0000000fU & vlSelfRef.__VdfgRegularize_hebeb780c_0_4))));
        bufp->chgCData(oldp+49,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__))),2);
        bufp->chgCData(oldp+50,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__))),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+51,(vlSelfRef.simple_test__DOT__last_output_pkt),23);
        bufp->chgCData(oldp+52,(vlSelfRef.simple_test__DOT__last_output_port),3);
        bufp->chgBit(oldp+53,(vlSelfRef.simple_test__DOT__last_output_valid));
        bufp->chgBit(oldp+54,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+55,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+56,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+57,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+58,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[4U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgCData(oldp+59,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
        bufp->chgCData(oldp+60,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
        bufp->chgCData(oldp+61,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
        bufp->chgCData(oldp+62,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
        bufp->chgCData(oldp+63,((((IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r) 
                                  << 1U) | (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r))),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+64,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgBit(oldp+65,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))));
        bufp->chgCData(oldp+66,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU))),6);
        bufp->chgCData(oldp+67,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 9U))),6);
        bufp->chgCData(oldp+68,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgCData(oldp+69,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgBit(oldp+70,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))));
        bufp->chgCData(oldp+71,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU))),6);
        bufp->chgCData(oldp+72,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 9U))),6);
        bufp->chgCData(oldp+73,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgCData(oldp+74,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgBit(oldp+75,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))));
        bufp->chgCData(oldp+76,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU))),6);
        bufp->chgCData(oldp+77,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 9U))),6);
        bufp->chgCData(oldp+78,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgCData(oldp+79,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgBit(oldp+80,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))));
        bufp->chgCData(oldp+81,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU))),6);
        bufp->chgCData(oldp+82,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 9U))),6);
        bufp->chgCData(oldp+83,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgCData(oldp+84,((3U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                       >> 0x00000015U))),2);
        bufp->chgBit(oldp+85,((1U & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                     >> 8U))));
        bufp->chgCData(oldp+86,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 0x0000000fU))),6);
        bufp->chgCData(oldp+87,((0x0000003fU & (vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r 
                                                >> 9U))),6);
        bufp->chgCData(oldp+88,((0x000000ffU & vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r)),8);
        bufp->chgIData(oldp+89,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+90,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+91,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+92,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+93,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgCData(oldp+94,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N),4);
        bufp->chgCData(oldp+95,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W),4);
        bufp->chgCData(oldp+96,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S),4);
        bufp->chgCData(oldp+97,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E),4);
        bufp->chgCData(oldp+98,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B),5);
        bufp->chgIData(oldp+99,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+100,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+101,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+102,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+103,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r),23);
        bufp->chgIData(oldp+104,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+105,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+106,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+107,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
        bufp->chgIData(oldp+108,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r),23);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+109,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+110,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+111,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+112,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+113,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+114,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r));
        bufp->chgBit(oldp+115,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+116,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+117,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+118,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+119,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+120,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+121,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+122,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+123,((1U & (~ (IData)(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r)))));
        bufp->chgBit(oldp+124,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+125,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+126,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r),2);
        bufp->chgBit(oldp+127,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+128,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r),2);
        bufp->chgBit(oldp+129,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+130,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r),2);
        bufp->chgBit(oldp+131,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgCData(oldp+132,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r),2);
        bufp->chgBit(oldp+133,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+134,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+135,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+136,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
        bufp->chgBit(oldp+137,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+138,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x),3);
        bufp->chgCData(oldp+139,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y),3);
        bufp->chgCData(oldp+140,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type),2);
        bufp->chgCData(oldp+141,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x),3);
        bufp->chgCData(oldp+142,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y),3);
        bufp->chgCData(oldp+143,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type),2);
        bufp->chgCData(oldp+144,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x),3);
        bufp->chgCData(oldp+145,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y),3);
        bufp->chgCData(oldp+146,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type),2);
        bufp->chgCData(oldp+147,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x),3);
        bufp->chgCData(oldp+148,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y),3);
        bufp->chgCData(oldp+149,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type),2);
        bufp->chgCData(oldp+150,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x),3);
        bufp->chgCData(oldp+151,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y),3);
        bufp->chgCData(oldp+152,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type),2);
    }
    bufp->chgBit(oldp+153,(vlSelfRef.simple_test__DOT__clk));
    bufp->chgIData(oldp+154,(vlSelfRef.simple_test__DOT__test_cycle),32);
    bufp->chgCData(oldp+155,(vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos),4);
    bufp->chgIData(oldp+156,(((8U & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                               : ((4U & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                   : ((2U & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                       : ((1U & vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                           : 0U))))),23);
    bufp->chgIData(oldp+157,(((8U & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                               : ((4U & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                   : ((2U & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                       : ((1U & vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                           : 0U))))),23);
    bufp->chgIData(oldp+158,(((8U & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                               : ((4U & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                   : ((2U & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                       : ((1U & vlSelfRef.__VdfgRegularize_hebeb780c_0_3)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                           : 0U))))),23);
    bufp->chgIData(oldp+159,(((8U & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                               : ((4U & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                   : ((2U & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                       : ((1U & vlSelfRef.__VdfgRegularize_hebeb780c_0_1)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                           : 0U))))),23);
    bufp->chgIData(oldp+160,(((0x00000010U & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)
                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                               : ((8U & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)
                                   ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                   : ((4U & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)
                                       ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                       : ((2U & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)
                                           ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                           : ((1U & vlSelfRef.__VdfgRegularize_hebeb780c_0_0)
                                               ? vlSelfRef.simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r
                                               : 0U)))))),23);
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
