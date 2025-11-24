// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vminimal_node_test.h for the primary calling header

#ifndef VERILATED_VMINIMAL_NODE_TEST___024ROOT_H_
#define VERILATED_VMINIMAL_NODE_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vminimal_node_test___024unit;
class Vminimal_node_test_pkt_con_if;
class Vminimal_node_test_pkt_in;


class Vminimal_node_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test___024root final : public VerilatedModule {
  public:
    // CELLS
    Vminimal_node_test___024unit* __PVT____024unit;
    Vminimal_node_test_pkt_in* __PVT__minimal_node_test__DOT__pkt_i;
    Vminimal_node_test_pkt_con_if* __PVT__minimal_node_test__DOT__pkt_con;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        CData/*0:0*/ minimal_node_test__DOT__pg_en;
        CData/*5:0*/ minimal_node_test__DOT__pg_node;
        CData/*0:0*/ minimal_node_test__DOT__test_packet_valid;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__fault_relative_pos;
        CData/*5:0*/ minimal_node_test__DOT__dut__DOT__new_tgt;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__tgt_is_pg;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__cpy_mode;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_N;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_S;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_E;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_W;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_A;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__obuf_rdy;
        CData/*5:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__ibuf_rdy;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__ibuf_rdy;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__ibuf_rdy;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__ibuf_rdy;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_N;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_N;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_W;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_W;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_S;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_S;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_E;
        CData/*3:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_E;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__arb_qos_B;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__arb_gnt_B;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__n_out_ready;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__w_out_ready;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__s_out_ready;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__e_out_ready;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__b_out_ready;
        CData/*5:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__gen_tgt;
        CData/*2:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__new_x;
        CData/*1:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__pkt_type;
        CData/*5:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__tgt_raw;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_multi_packet_gen__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__;
    };
    struct {
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr_h77c9d807__1;
        CData/*0:0*/ __VactDidInit;
        IData/*31:0*/ minimal_node_test__DOT__test_count;
        IData/*31:0*/ minimal_node_test__DOT__passed_count;
        IData/*31:0*/ minimal_node_test__DOT__clk_counter;
        IData/*31:0*/ minimal_node_test__DOT__timeout_counter;
        IData/*22:0*/ minimal_node_test__DOT__test_packet_data;
        IData/*16:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__pkt_W;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__pkt_S;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__pkt_E;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__pkt_B;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__payload_irs_i;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload0_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__payload1_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload0_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__payload1_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload0_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__payload1_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload0_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__payload1_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload0_r;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__payload1_r;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*4:0*/, 5> minimal_node_test__DOT__dut__DOT__arb_req;
        VlUnpacked<CData/*4:0*/, 5> minimal_node_test__DOT__dut__DOT__arb_gnt;
        VlUnpacked<IData/*22:0*/, 5> minimal_node_test__DOT__dut__DOT__pld_buf;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };
    VlTriggerScheduler __VtrigSched_ha1013b2d__0;
    VlTriggerScheduler __VtrigSched_hef7d95d9__0;
    VlTriggerScheduler __VtrigSched_h5a906ece__0;

    // INTERNAL VARIABLES
    Vminimal_node_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vminimal_node_test___024root(Vminimal_node_test__Syms* symsp, const char* v__name);
    ~Vminimal_node_test___024root();
    VL_UNCOPYABLE(Vminimal_node_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
