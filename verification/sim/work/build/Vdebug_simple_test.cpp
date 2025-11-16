// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdebug_simple_test__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdebug_simple_test::Vdebug_simple_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdebug_simple_test__Syms(contextp(), _vcname__, this)}
    , __PVT__debug_simple_test__DOT__u_dut__DOT__pkt_i{vlSymsp->TOP.__PVT__debug_simple_test__DOT__u_dut__DOT__pkt_i}
    , __PVT__debug_simple_test__DOT__u_dut__DOT__pkt_o{vlSymsp->TOP.__PVT__debug_simple_test__DOT__u_dut__DOT__pkt_o}
    , __PVT__debug_simple_test__DOT__u_dut__DOT__pkt_con{vlSymsp->TOP.__PVT__debug_simple_test__DOT__u_dut__DOT__pkt_con}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vdebug_simple_test::Vdebug_simple_test(const char* _vcname__)
    : Vdebug_simple_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdebug_simple_test::~Vdebug_simple_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdebug_simple_test___024root___eval_debug_assertions(Vdebug_simple_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vdebug_simple_test___024root___eval_static(Vdebug_simple_test___024root* vlSelf);
void Vdebug_simple_test___024root___eval_initial(Vdebug_simple_test___024root* vlSelf);
void Vdebug_simple_test___024root___eval_settle(Vdebug_simple_test___024root* vlSelf);
void Vdebug_simple_test___024root___eval(Vdebug_simple_test___024root* vlSelf);

void Vdebug_simple_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdebug_simple_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdebug_simple_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdebug_simple_test___024root___eval_static(&(vlSymsp->TOP));
        Vdebug_simple_test___024root___eval_initial(&(vlSymsp->TOP));
        Vdebug_simple_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdebug_simple_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdebug_simple_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vdebug_simple_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vdebug_simple_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdebug_simple_test___024root___eval_final(Vdebug_simple_test___024root* vlSelf);

VL_ATTR_COLD void Vdebug_simple_test::final() {
    Vdebug_simple_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdebug_simple_test::hierName() const { return vlSymsp->name(); }
const char* Vdebug_simple_test::modelName() const { return "Vdebug_simple_test"; }
unsigned Vdebug_simple_test::threads() const { return 1; }
void Vdebug_simple_test::prepareClone() const { contextp()->prepareClone(); }
void Vdebug_simple_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdebug_simple_test::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdebug_simple_test___024root__trace_decl_types(VerilatedVcd* tracep);

void Vdebug_simple_test___024root__trace_init_top(Vdebug_simple_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdebug_simple_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdebug_simple_test___024root*>(voidSelf);
    Vdebug_simple_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vdebug_simple_test___024root__trace_decl_types(tracep);
    Vdebug_simple_test___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdebug_simple_test___024root__trace_register(Vdebug_simple_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdebug_simple_test::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdebug_simple_test::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdebug_simple_test___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
