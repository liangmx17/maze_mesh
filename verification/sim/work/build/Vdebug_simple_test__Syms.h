// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDEBUG_SIMPLE_TEST__SYMS_H_
#define VERILATED_VDEBUG_SIMPLE_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdebug_simple_test.h"

// INCLUDE MODULE CLASSES
#include "Vdebug_simple_test___024root.h"
#include "Vdebug_simple_test_pkt_in.h"
#include "Vdebug_simple_test_pkt_out.h"
#include "Vdebug_simple_test_pkt_con_if.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vdebug_simple_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdebug_simple_test* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdebug_simple_test___024root   TOP;
    Vdebug_simple_test_pkt_con_if  TOP__debug_simple_test__DOT__u_dut__DOT__pkt_con;
    Vdebug_simple_test_pkt_in      TOP__debug_simple_test__DOT__u_dut__DOT__pkt_i;
    Vdebug_simple_test_pkt_out     TOP__debug_simple_test__DOT__u_dut__DOT__pkt_o;

    // SCOPE NAMES
    VerilatedScope __Vscope_debug_simple_test;
    VerilatedScope __Vscope_debug_simple_test__u_dut;
    VerilatedScope __Vscope_debug_simple_test__u_dut__pkt_con;
    VerilatedScope __Vscope_debug_simple_test__u_dut__pkt_i;
    VerilatedScope __Vscope_debug_simple_test__u_dut__pkt_o;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_A;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_A__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_A__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_E;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_E__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_E__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_N;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_N__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_N__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_S;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_S__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_S__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_W;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_W__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_input_W__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_B;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_B__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_B__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_E;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_E__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_E__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_N;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_N__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_N__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_S;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_S__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_S__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_W;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_W__proc_insert_irs;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__irs_output_W__proc_insert_irs__irs_gen__BRA__0__KET____irs_ro_en__U_LOOP_IRS;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_arbiter_B;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_arbiter_E;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_arbiter_N;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_arbiter_S;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_arbiter_W;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_router_A;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_router_E;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_router_N;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_router_S;
    VerilatedScope __Vscope_debug_simple_test__u_dut__u_node__u_router_W;
    VerilatedScope __Vscope_debug_simple_test__unnamedblk1;

    // CONSTRUCTORS
    Vdebug_simple_test__Syms(VerilatedContext* contextp, const char* namep, Vdebug_simple_test* modelp);
    ~Vdebug_simple_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
