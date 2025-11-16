// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsimple_test.h for the primary calling header

#ifndef VERILATED_VSIMPLE_TEST___024ROOT_H_
#define VERILATED_VSIMPLE_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsimple_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsimple_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ simple_test__DOT__clk;
        CData/*0:0*/ simple_test__DOT__rst_n;
        CData/*0:0*/ simple_test__DOT__pg_en;
        CData/*5:0*/ simple_test__DOT__pg_node;
        CData/*2:0*/ simple_test__DOT__last_output_port;
        CData/*0:0*/ simple_test__DOT__last_output_valid;
        CData/*0:0*/ simple_test__DOT__pkt_i_pkt_in_vld;
        CData/*1:0*/ simple_test__DOT__pkt_i_pkt_in_type;
        CData/*0:0*/ simple_test__DOT__pkt_i_pkt_in_qos;
        CData/*5:0*/ simple_test__DOT__pkt_i_pkt_in_src;
        CData/*5:0*/ simple_test__DOT__pkt_i_pkt_in_tgt;
        CData/*7:0*/ simple_test__DOT__pkt_i_pkt_in_data;
        CData/*0:0*/ simple_test__DOT__pkt_o_pkt_out_rdy;
        CData/*0:0*/ simple_test__DOT__pkt_con_no_rdy;
        CData/*0:0*/ simple_test__DOT__pkt_con_wo_rdy;
        CData/*0:0*/ simple_test__DOT__pkt_con_so_rdy;
        CData/*0:0*/ simple_test__DOT__pkt_con_eo_rdy;
        CData/*3:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__fault_relative_pos;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_A;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_N;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_W;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_S;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__route_req_E;
        CData/*3:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_N;
        CData/*3:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_W;
        CData/*3:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_S;
        CData/*3:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_E;
        CData/*4:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__arb_qos_B;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_x;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__target_y;
        CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_A__DOT__pkt_type;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_x;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__target_y;
        CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_N__DOT__pkt_type;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_x;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__target_y;
        CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_W__DOT__pkt_type;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_x;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__target_y;
        CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_S__DOT__pkt_type;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_x;
        CData/*2:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__target_y;
        CData/*1:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__u_router_E__DOT__pkt_type;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
    };
    struct {
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ __Vdly__simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__simple_test__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__simple_test__DOT__rst_n__0;
        IData/*31:0*/ simple_test__DOT__test_cycle;
        IData/*31:0*/ simple_test__DOT__error_count;
        IData/*31:0*/ simple_test__DOT__test_count;
        IData/*31:0*/ simple_test__DOT__pass_count;
        IData/*22:0*/ simple_test__DOT__last_output_pkt;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_A__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_input_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_W__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_S__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_E__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ simple_test__DOT__u_dut__DOT__u_node__DOT__irs_output_B__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_0;
    };
    struct {
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_1;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_2;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_3;
        IData/*31:0*/ __VdfgRegularize_hebeb780c_0_4;
        IData/*31:0*/ __Vtrigprevexpr_hc94a28ed__1;
        IData/*31:0*/ __Vtrigprevexpr_hc954b698__1;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 9> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb092edad__0;
    VlTriggerScheduler __VtrigSched_h1cfde055__0;
    VlTriggerScheduler __VtrigSched_h1d6373ea__0;

    // INTERNAL VARIABLES
    Vsimple_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsimple_test___024root(Vsimple_test__Syms* symsp, const char* v__name);
    ~Vsimple_test___024root();
    VL_UNCOPYABLE(Vsimple_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
