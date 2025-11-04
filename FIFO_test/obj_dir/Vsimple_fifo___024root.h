// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsimple_fifo.h for the primary calling header

#ifndef VERILATED_VSIMPLE_FIFO___024ROOT_H_
#define VERILATED_VSIMPLE_FIFO___024ROOT_H_  // guard

#include "verilated.h"


class Vsimple_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsimple_fifo___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(wr_en,0,0);
    VL_IN8(wr_data,7,0);
    VL_OUT8(full,0,0);
    VL_IN8(rd_en,0,0);
    VL_OUT8(rd_data,7,0);
    VL_OUT8(empty,0,0);
    VL_OUT8(count,4,0);
    CData/*4:0*/ simple_fifo__DOT__wr_ptr;
    CData/*4:0*/ simple_fifo__DOT__rd_ptr;
    CData/*7:0*/ simple_fifo__DOT__rd_data_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> simple_fifo__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsimple_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsimple_fifo___024root(Vsimple_fifo__Syms* symsp, const char* v__name);
    ~Vsimple_fifo___024root();
    VL_UNCOPYABLE(Vsimple_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
