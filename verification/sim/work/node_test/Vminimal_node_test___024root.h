// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vminimal_node_test.h for the primary calling header

#ifndef VERILATED_VMINIMAL_NODE_TEST___024ROOT_H_
#define VERILATED_VMINIMAL_NODE_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vminimal_node_test_pkt_con_if;
class Vminimal_node_test_pkt_in;
class Vminimal_node_test_pkt_out;


class Vminimal_node_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vminimal_node_test___024root final : public VerilatedModule {
  public:
    // CELLS
    Vminimal_node_test_pkt_in* __PVT__minimal_node_test__DOT__pkt_i;
    Vminimal_node_test_pkt_out* __PVT__minimal_node_test__DOT__pkt_o;
    Vminimal_node_test_pkt_con_if* __PVT__minimal_node_test__DOT__pkt_con;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        CData/*0:0*/ minimal_node_test__DOT__pg_en;
        CData/*5:0*/ minimal_node_test__DOT__pg_node;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__cpy_mode;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__route_req_A;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__obuf_rdy;
        CData/*5:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_tgt_A_buffered;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_ctrl_rdy;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__pkt_in_data_rdy;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_CTRL__arb_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellinp__u_IBUF_A_CTRL__route_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__arb_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__arb_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__arb_req;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_E__arb_req;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__set;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_A_CTRL__DOT__clr;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_N__DOT__clr;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_W__DOT__clr;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_S__DOT__clr;
        CData/*4:0*/ minimal_node_test__DOT__dut__DOT__u_IBUF_E__DOT__clr;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_N__DOT__proc_insert_irs__DOT__irs_gen__BRA__0__KET____DOT__irs_ro_en__DOT__U_LOOP_IRS__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_W__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_S__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_E__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid0_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__valid1_r;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__set__BRA__0__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__1__KET__;
        CData/*0:0*/ minimal_node_test__DOT__dut__DOT__irs_output_B__DOT__clr__BRA__0__KET__;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr_h08905649__1;
        CData/*0:0*/ __VactDidInit;
        IData/*31:0*/ minimal_node_test__DOT__test_count;
        IData/*31:0*/ minimal_node_test__DOT__passed_count;
        IData/*31:0*/ minimal_node_test__DOT__clk_counter;
        IData/*16:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_A_DATA__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_N__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_W__payload_o;
        IData/*22:0*/ minimal_node_test__DOT__dut__DOT____Vcellout__u_IBUF_S__payload_o;
    };
    struct {
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
        VlUnpacked<CData/*4:0*/, 5> minimal_node_test__DOT__dut__DOT__arb_gnt;
        VlUnpacked<IData/*22:0*/, 5> minimal_node_test__DOT__dut__DOT__pld_buf;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlTriggerScheduler __VtrigSched_h9ff589a2__0;
    VlTriggerScheduler __VtrigSched_h6037169b__0;
    VlTriggerScheduler __VtrigSched_ha9dae870__0;

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
