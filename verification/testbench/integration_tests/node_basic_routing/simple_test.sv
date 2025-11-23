// =============================================================================
// MAZE节点基本路由功能简化测试台（SystemVerilog）
// =============================================================================
// 功能说明：
// 1. 简单的SystemVerilog测试台，便于快速验证
// 2. 实现N-RF-001到N-RF-005基本路由功能测试
// 3. 不依赖复杂的C++环境，可直接在仿真器中运行
// =============================================================================

`timescale 1ns/1ps

// 包含必要的定义文件
`include "rtl/top_define.v"

module simple_test;

    // 测试参数
    parameter TEST_NODE_X = 3;
    parameter TEST_NODE_Y = 3;
    parameter CLK_PERIOD = 10;  // 10ns时钟周期
    parameter TEST_TIMEOUT = 10000;  // 最大测试周期数

    // 计算节点ID，确保6位宽度
    // 节点ID格式: {Y坐标[2:0], X坐标[2:0]}
    function automatic [5:0] calc_node_id;
        input integer x;  // 水平坐标 (0-7)
        input integer y;  // 垂直坐标 (0-7)
        begin
            calc_node_id = {y[2:0], x[2:0]};  // 节点ID = {Y坐标, X坐标}
        end
    endfunction

    // 仿真信号
    reg clk;
    reg rst_n;

    // 故障容错配置
    reg pg_en;
    reg [5:0] pg_node;

    // 测试计数器
    integer test_cycle;
    integer error_count;
    integer test_count;
    integer pass_count;

    // 输出监控信号
    reg [22:0] last_output_pkt;
    reg [2:0] last_output_port;
    reg last_output_valid;

    // 接口信号
    logic pkt_i_pkt_in_vld;
    logic [1:0] pkt_i_pkt_in_type;
    logic pkt_i_pkt_in_qos;
    logic [5:0] pkt_i_pkt_in_src;
    logic [5:0] pkt_i_pkt_in_tgt;
    logic [7:0] pkt_i_pkt_in_data;
    logic pkt_i_pkt_in_rdy;

    logic pkt_o_pkt_out_vld;
    logic [1:0] pkt_o_pkt_out_type;
    logic pkt_o_pkt_out_qos;
    logic [5:0] pkt_o_pkt_out_src;
    logic [5:0] pkt_o_pkt_out_tgt;
    logic [7:0] pkt_o_pkt_out_data;
    logic pkt_o_pkt_out_rdy;

    // C接口信号（简化，只监控输出）
    logic pkt_con_no_vld;
    logic [1:0] pkt_con_no_type;
    logic pkt_con_no_qos;
    logic [5:0] pkt_con_no_src;
    logic [5:0] pkt_con_no_tgt;
    logic [7:0] pkt_con_no_data;
    logic pkt_con_no_rdy;

    logic pkt_con_wo_vld;
    logic [1:0] pkt_con_wo_type;
    logic pkt_con_wo_qos;
    logic [5:0] pkt_con_wo_src;
    logic [5:0] pkt_con_wo_tgt;
    logic [7:0] pkt_con_wo_data;
    logic pkt_con_wo_rdy;

    logic pkt_con_so_vld;
    logic [1:0] pkt_con_so_type;
    logic pkt_con_so_qos;
    logic [5:0] pkt_con_so_src;
    logic [5:0] pkt_con_so_tgt;
    logic [7:0] pkt_con_so_data;
    logic pkt_con_so_rdy;

    logic pkt_con_eo_vld;
    logic [1:0] pkt_con_eo_type;
    logic pkt_con_eo_qos;
    logic [5:0] pkt_con_eo_src;
    logic [5:0] pkt_con_eo_tgt;
    logic [7:0] pkt_con_eo_data;
    logic pkt_con_eo_rdy;

    // 用于调试的手动编码信号
    logic [22:0] manual_encoded;

    // C接口输入信号（固定为0）
    wire pkt_con_ni_vld = 0;
    wire [1:0] pkt_con_ni_type = 0;
    wire pkt_con_ni_qos = 0;
    wire [5:0] pkt_con_ni_src = 0;
    wire [5:0] pkt_con_ni_tgt = 0;
    wire [7:0] pkt_con_ni_data = 0;
    logic pkt_con_ni_rdy;

    wire pkt_con_wi_vld = 0;
    wire [1:0] pkt_con_wi_type = 0;
    wire pkt_con_wi_qos = 0;
    wire [5:0] pkt_con_wi_src = 0;
    wire [5:0] pkt_con_wi_tgt = 0;
    wire [7:0] pkt_con_wi_data = 0;
    logic pkt_con_wi_rdy;

    wire pkt_con_si_vld = 0;
    wire [1:0] pkt_con_si_type = 0;
    wire pkt_con_si_qos = 0;
    wire [5:0] pkt_con_si_src = 0;
    wire [5:0] pkt_con_si_tgt = 0;
    wire [7:0] pkt_con_si_data = 0;
    logic pkt_con_si_rdy;

    wire pkt_con_ei_vld = 0;
    wire [1:0] pkt_con_ei_type = 0;
    wire pkt_con_ei_qos = 0;
    wire [5:0] pkt_con_ei_src = 0;
    wire [5:0] pkt_con_ei_tgt = 0;
    wire [7:0] pkt_con_ei_data = 0;
    logic pkt_con_ei_rdy;

    // IRS_N状态监控信号
    typedef struct {
        logic input_valid, input_ready;
        logic output_valid, output_ready;
        logic [22:0] input_payload, output_payload;
        integer depth_count;  // 估算的内部包数量
    } irs_status_t;

    irs_status_t irs_status_a, irs_status_n, irs_status_w, irs_status_s, irs_status_e, irs_status_b;
    integer debug_cycle_counter = 0;
    logic last_b_irs_ready = 1'bX;  // 用于跟踪B端口IRS_N ready信号变化

    // 前10拍详细监控标志
    integer first_10_cycles_debug = 1;

    // 数据包编码函数
    function automatic [22:0] encode_packet;
        input [1:0] pkt_type;
        input pkt_qos;
        input [5:0] src_id;
        input [5:0] tgt_id;
        input [7:0] data;
        begin
            // 🔧 DEBUG: 添加函数内部调试
            $display("[ENCODE_DEBUG] Function inputs: type=%d, qos=%d, src=%d(0b%b), tgt=%d(0b%b), data=0x%02h",
                     pkt_type, pkt_qos, src_id, src_id, tgt_id, tgt_id, data);

            encode_packet = {pkt_type, pkt_qos, src_id, tgt_id, data};
            $display("[ENCODE_DEBUG] Function result: %h", encode_packet);
        end
    endfunction

    // 解码数据包函数
    function automatic void decode_packet;
        input [22:0] encoded;
        output [1:0] pkt_type;
        output pkt_qos;
        output [5:0] src_id;
        output [5:0] tgt_id;
        output [7:0] data;
        begin
            pkt_type = encoded[22:21];
            pkt_qos = encoded[20];
            src_id = encoded[19:14];
            tgt_id = encoded[13:8];
            data = encoded[7:0];
        end
    endfunction

    // 打印数据包信息
    task automatic print_packet;
        input [22:0] encoded;
        reg [1:0] pkt_type;
        reg pkt_qos;
        reg [5:0] src_id;
        reg [5:0] tgt_id;
        reg [7:0] data;
        begin
            decode_packet(encoded, pkt_type, pkt_qos, src_id, tgt_id, data);
            $display("Packet[%h]: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     encoded, pkt_type, pkt_qos, src_id, tgt_id, data);
        end
    endtask

    // 实例化被测试的节点模块
    test_node_wrapper #(
        .HP(TEST_NODE_X),
        .VP(TEST_NODE_Y)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .pg_en(pg_en),
        .pg_node(pg_node),

        .pkt_i_pkt_in_vld(pkt_i_pkt_in_vld),
        .pkt_i_pkt_in_type(pkt_i_pkt_in_type),
        .pkt_i_pkt_in_qos(pkt_i_pkt_in_qos),
        .pkt_i_pkt_in_src(pkt_i_pkt_in_src),
        .pkt_i_pkt_in_tgt(pkt_i_pkt_in_tgt),
        .pkt_i_pkt_in_data(pkt_i_pkt_in_data),
        .pkt_i_pkt_in_rdy(pkt_i_pkt_in_rdy),

        .pkt_o_pkt_out_vld(pkt_o_pkt_out_vld),
        .pkt_o_pkt_out_type(pkt_o_pkt_out_type),
        .pkt_o_pkt_out_qos(pkt_o_pkt_out_qos),
        .pkt_o_pkt_out_src(pkt_o_pkt_out_src),
        .pkt_o_pkt_out_tgt(pkt_o_pkt_out_tgt),
        .pkt_o_pkt_out_data(pkt_o_pkt_out_data),
        .pkt_o_pkt_out_rdy(pkt_o_pkt_out_rdy),

        // C接口北方向
        .pkt_con_ni_vld(pkt_con_ni_vld),
        .pkt_con_ni_type(pkt_con_ni_type),
        .pkt_con_ni_qos(pkt_con_ni_qos),
        .pkt_con_ni_src(pkt_con_ni_src),
        .pkt_con_ni_tgt(pkt_con_ni_tgt),
        .pkt_con_ni_data(pkt_con_ni_data),
        .pkt_con_ni_rdy(pkt_con_ni_rdy),

        .pkt_con_no_vld(pkt_con_no_vld),
        .pkt_con_no_type(pkt_con_no_type),
        .pkt_con_no_qos(pkt_con_no_qos),
        .pkt_con_no_src(pkt_con_no_src),
        .pkt_con_no_tgt(pkt_con_no_tgt),
        .pkt_con_no_data(pkt_con_no_data),
        .pkt_con_no_rdy(pkt_con_no_rdy),

        // C接口西方向
        .pkt_con_wi_vld(pkt_con_wi_vld),
        .pkt_con_wi_type(pkt_con_wi_type),
        .pkt_con_wi_qos(pkt_con_wi_qos),
        .pkt_con_wi_src(pkt_con_wi_src),
        .pkt_con_wi_tgt(pkt_con_wi_tgt),
        .pkt_con_wi_data(pkt_con_wi_data),
        .pkt_con_wi_rdy(pkt_con_wi_rdy),

        .pkt_con_wo_vld(pkt_con_wo_vld),
        .pkt_con_wo_type(pkt_con_wo_type),
        .pkt_con_wo_qos(pkt_con_wo_qos),
        .pkt_con_wo_src(pkt_con_wo_src),
        .pkt_con_wo_tgt(pkt_con_wo_tgt),
        .pkt_con_wo_data(pkt_con_wo_data),
        .pkt_con_wo_rdy(pkt_con_wo_rdy),

        // C接口南方向
        .pkt_con_si_vld(pkt_con_si_vld),
        .pkt_con_si_type(pkt_con_si_type),
        .pkt_con_si_qos(pkt_con_si_qos),
        .pkt_con_si_src(pkt_con_si_src),
        .pkt_con_si_tgt(pkt_con_si_tgt),
        .pkt_con_si_data(pkt_con_si_data),
        .pkt_con_si_rdy(pkt_con_si_rdy),

        .pkt_con_so_vld(pkt_con_so_vld),
        .pkt_con_so_type(pkt_con_so_type),
        .pkt_con_so_qos(pkt_con_so_qos),
        .pkt_con_so_src(pkt_con_so_src),
        .pkt_con_so_tgt(pkt_con_so_tgt),
        .pkt_con_so_data(pkt_con_so_data),
        .pkt_con_so_rdy(pkt_con_so_rdy),

        // C接口东方向
        .pkt_con_ei_vld(pkt_con_ei_vld),
        .pkt_con_ei_type(pkt_con_ei_type),
        .pkt_con_ei_qos(pkt_con_ei_qos),
        .pkt_con_ei_src(pkt_con_ei_src),
        .pkt_con_ei_tgt(pkt_con_ei_tgt),
        .pkt_con_ei_data(pkt_con_ei_data),
        .pkt_con_ei_rdy(pkt_con_ei_rdy),

        .pkt_con_eo_vld(pkt_con_eo_vld),
        .pkt_con_eo_type(pkt_con_eo_type),
        .pkt_con_eo_qos(pkt_con_eo_qos),
        .pkt_con_eo_src(pkt_con_eo_src),
        .pkt_con_eo_tgt(pkt_con_eo_tgt),
        .pkt_con_eo_data(pkt_con_eo_data),
        .pkt_con_eo_rdy(pkt_con_eo_rdy)
    );

    // 时钟生成
    always #(CLK_PERIOD/2) clk = ~clk;

    // 时钟周期计数器
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            test_cycle <= 0;
            debug_cycle_counter <= 0;
        end else begin
            test_cycle <= test_cycle + 1;
            debug_cycle_counter <= debug_cycle_counter + 1;
        end
    end

    // IRS_N状态监控任务
    task automatic monitor_irs_status;
        input string irs_name;
        inout irs_status_t status;
        input logic input_valid, input_ready;
        input logic output_valid, output_ready;
        input logic [22:0] input_payload, output_payload;
        begin
            status.input_valid = input_valid;
            status.input_ready = input_ready;
            status.output_valid = output_valid;
            status.output_ready = output_ready;
            status.input_payload = input_payload;
            status.output_payload = output_payload;

            // 估算深度：如果有valid但没ready，说明数据在缓冲中
            status.depth_count = (input_valid && !input_ready) ? 1 : 0;

            // 每个周期打印IRS状态（每50个周期打印一次详细信息）
            if (debug_cycle_counter % 50 == 0) begin
                $display("[IRS DEBUG] Cycle %0d - %s IRS_N Status:", test_cycle, irs_name);
                $display("  Input: vld=%d, rdy=%d, payload=0x%h",
                         status.input_valid, status.input_ready, status.input_payload);
                $display("  Output: vld=%d, rdy=%d, payload=0x%h, depth=%0d",
                         status.output_valid, status.output_ready, status.output_payload, status.depth_count);
            end
        end
    endtask

    // 前10拍详细内部信号监控
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // 复位时清零所有状态
            irs_status_a = '{0,0,0,0,23'b0,23'b0,0};
            irs_status_n = '{0,0,0,0,23'b0,23'b0,0};
            irs_status_w = '{0,0,0,0,23'b0,23'b0,0};
            irs_status_s = '{0,0,0,0,23'b0,23'b0,0};
            irs_status_e = '{0,0,0,0,23'b0,23'b0,0};
            irs_status_b = '{0,0,0,0,23'b0,23'b0,0};

            // 重置输出监控信号
            last_output_valid <= 0;
            last_output_pkt <= 0;
            last_output_port <= 0;
        end else begin
            // 前10拍详细监控所有内部信号
            if (first_10_cycles_debug == 1 && test_cycle <= 10) begin
                $display("=================================================================");
                $display("[INTERNAL DEBUG] Cycle %0d - Full Internal Signal Analysis:", test_cycle);
                $display("=================================================================");

                // 1. 监控5个输入口的IRS_N信号
                $display("=== IRS_N Input Signals ===");

                // A口输入IBUF (分为CTRL和DATA两个模块)
                if (u_dut.u_node.u_IBUF_A_CTRL.ibuf_vld !== 'x) begin
                    $display("  IBUF_A_CTRL: ibuf_vld=%d, ibuf_rdy=%d",
                             u_dut.u_node.u_IBUF_A_CTRL.ibuf_vld, u_dut.u_node.u_IBUF_A_CTRL.ibuf_rdy);
                end else $display("  IBUF_A_CTRL: Signal not accessible");

                // N口输入IBUF
                if (u_dut.u_node.u_IBUF_N.ibuf_vld !== 'x) begin
                    $display("  IBUF_N: ibuf_vld=%d, ibuf_rdy=%d",
                             u_dut.u_node.u_IBUF_N.ibuf_vld, u_dut.u_node.u_IBUF_N.ibuf_rdy);
                end else $display("  IBUF_N: Signal not accessible");

                // W口输入IBUF
                if (u_dut.u_node.u_IBUF_W.ibuf_vld !== 'x) begin
                    $display("  IBUF_W: ibuf_vld=%d, ibuf_rdy=%d",
                             u_dut.u_node.u_IBUF_W.ibuf_vld, u_dut.u_node.u_IBUF_W.ibuf_rdy);
                end else $display("  IBUF_W: Signal not accessible");

                // S口输入IBUF
                if (u_dut.u_node.u_IBUF_S.ibuf_vld !== 'x) begin
                    $display("  IBUF_S: ibuf_vld=%d, ibuf_rdy=%d",
                             u_dut.u_node.u_IBUF_S.ibuf_vld, u_dut.u_node.u_IBUF_S.ibuf_rdy);
                end else $display("  IBUF_S: Signal not accessible");

                // E口输入IBUF
                if (u_dut.u_node.u_IBUF_E.ibuf_vld !== 'x) begin
                    $display("  IBUF_E: ibuf_vld=%d, ibuf_rdy=%d",
                             u_dut.u_node.u_IBUF_E.ibuf_vld, u_dut.u_node.u_IBUF_E.ibuf_rdy);
                end else $display("  IBUF_E: Signal not accessible");

                // 2. 监控所有Router输出信号
                $display("=== Router Output Signals ===");

                if (u_dut.u_node.route_req_A !== 'x) begin
                    $display("  route_req_A=0b%05b (N,W,S,E,B)",
                             u_dut.u_node.route_req_A);
                end else $display("  Router A signals: not accessible");

                if (u_dut.u_node.route_req_N !== 'x) begin
                    $display("  route_req_N=0b%05b",
                             u_dut.u_node.route_req_N);
                end else $display("  Router N signals: not accessible");

                if (u_dut.u_node.route_req_W !== 'x) begin
                    $display("  route_req_W=0b%05b",
                             u_dut.u_node.route_req_W);
                end else $display("  Router W signals: not accessible");

                if (u_dut.u_node.route_req_S !== 'x) begin
                    $display("  route_req_S=0b%05b",
                             u_dut.u_node.route_req_S);
                end else $display("  Router S signals: not accessible");

                if (u_dut.u_node.route_req_E !== 'x) begin
                    $display("  route_req_E=0b%05b",
                             u_dut.u_node.route_req_E);
                end else $display("  Router E signals: not accessible");

                // 3. 监控所有Arbiter输入输出信号
                $display("=== Arbiter I/O Signals ===");

                // N仲裁器
                if (u_dut.u_node.arb_req_N !== 'x) begin
                    $display("  Arbiter_N: req=0b%04b(A,W,S,E), qos=0b%04b, gnt=0b%04b",
                             u_dut.u_node.arb_req_N, u_dut.u_node.arb_qos_N, u_dut.u_node.arb_gnt_N);
                end else $display("  Arbiter N: not accessible");

                // W仲裁器
                if (u_dut.u_node.arb_req_W !== 'x) begin
                    $display("  Arbiter_W: req=0b%04b(A,N,S,E), qos=0b%04b, gnt=0b%04b",
                             u_dut.u_node.arb_req_W, u_dut.u_node.arb_qos_W, u_dut.u_node.arb_gnt_W);
                end else $display("  Arbiter W: not accessible");

                // S仲裁器
                if (u_dut.u_node.arb_req_S !== 'x) begin
                    $display("  Arbiter_S: req=0b%04b(A,N,W,E), qos=0b%04b, gnt=0b%04b",
                             u_dut.u_node.arb_req_S, u_dut.u_node.arb_qos_S, u_dut.u_node.arb_gnt_S);
                end else $display("  Arbiter S: not accessible");

                // E仲裁器
                if (u_dut.u_node.arb_req_E !== 'x) begin
                    $display("  Arbiter_E: req=0b%04b(A,N,W,S), qos=0b%04b, gnt=0b%04b",
                             u_dut.u_node.arb_req_E, u_dut.u_node.arb_qos_E, u_dut.u_node.arb_gnt_E);
                end else $display("  Arbiter E: not accessible");

                // B仲裁器
                if (u_dut.u_node.arb_req_B !== 'x) begin
                    $display("  Arbiter_B: req=0b%05b(A,N,W,S,E), qos=0b%05b, gnt=0b%05b",
                             u_dut.u_node.arb_req_B, u_dut.u_node.arb_qos_B, u_dut.u_node.arb_gnt_B);
                end else $display("  Arbiter B: not accessible");

                // 4. 监控5个输出口IRS_N输入信号
                $display("=== Output IRS_N Input Signals ===");

                if (u_dut.u_node.irs_output_N.valid_i !== 'x) begin
                    $display("  irs_output_N: valid_i=%d, ready_o=%d, payload_i=0x%h,  valid_o=%d, ready_i=%d, payload_o=0x%h",
                             u_dut.u_node.irs_output_N.valid_i, u_dut.u_node.irs_output_N.ready_o, u_dut.u_node.irs_output_N.payload_i,
                             u_dut.u_node.irs_output_N.valid_o, u_dut.u_node.irs_output_N.ready_i, u_dut.u_node.irs_output_N.payload_o);
                end else $display("  irs_output_N: not accessible");

                if (u_dut.u_node.irs_output_W.valid_i !== 'x) begin
                    $display("  irs_output_W: valid_i=%d, ready_o=%d, payload_i=0x%h,  valid_o=%d, ready_i=%d, payload_o=0x%h",
                             u_dut.u_node.irs_output_W.valid_i, u_dut.u_node.irs_output_W.ready_o, u_dut.u_node.irs_output_W.payload_i,
                             u_dut.u_node.irs_output_W.valid_o, u_dut.u_node.irs_output_W.ready_i, u_dut.u_node.irs_output_W.payload_o);
                end else $display("  irs_output_W: not accessible");

                if (u_dut.u_node.irs_output_S.valid_i !== 'x) begin
                    $display("  irs_output_S: valid_i=%d, ready_o=%d, payload_i=0x%h,  valid_o=%d, ready_i=%d, payload_o=0x%h",
                             u_dut.u_node.irs_output_S.valid_i, u_dut.u_node.irs_output_S.ready_o, u_dut.u_node.irs_output_S.payload_i,
                             u_dut.u_node.irs_output_S.valid_o, u_dut.u_node.irs_output_S.ready_i, u_dut.u_node.irs_output_S.payload_o);
                end else $display("  irs_output_S: not accessible");

                if (u_dut.u_node.irs_output_E.valid_i !== 'x) begin
                    $display("  irs_output_E: valid_i=%d, ready_o=%d, payload_i=0x%h,  valid_o=%d, ready_i=%d, payload_o=0x%h",
                             u_dut.u_node.irs_output_E.valid_i, u_dut.u_node.irs_output_E.ready_o, u_dut.u_node.irs_output_E.payload_i,
                             u_dut.u_node.irs_output_E.valid_o, u_dut.u_node.irs_output_E.ready_i, u_dut.u_node.irs_output_E.payload_o);
                end else $display("  irs_output_E: not accessible");

                if (u_dut.u_node.irs_output_B.valid_i !== 'x) begin
                    $display("  irs_output_B: valid_i=%d, ready_o=%d, payload_i=0x%h,  valid_o=%d, ready_i=%d, payload_o=0x%h",
                             u_dut.u_node.irs_output_B.valid_i, u_dut.u_node.irs_output_B.ready_o, u_dut.u_node.irs_output_B.payload_i,
                             u_dut.u_node.irs_output_B.valid_o, u_dut.u_node.irs_output_B.ready_i, u_dut.u_node.irs_output_B.payload_o);
                end else $display("  irs_output_B: not accessible");

                $display("=================================================================");
            end

            // 🔧 新增：监控节点内部输出连接信号
            if (first_10_cycles_debug == 1 && test_cycle <= 10) begin
                $display("=== Node Internal Output Connections ===");
                // 检查节点内部输出信号（连接IRS_N到外部接口）
                if (u_dut.u_node.e_out_valid !== 'x) begin
                    $display("  Node.e_out_valid=%d, e_out_ready=%d, e_out_pkt=0x%h",
                             u_dut.u_node.e_out_valid, u_dut.u_node.e_out_ready,
                             u_dut.u_node.e_out_pkt);
                    $display("  External pkt_con_eo_vld=%d, pkt_con_eo_rdy=%d",
                             pkt_con_eo_vld, pkt_con_eo_rdy);
                    $display("  Connection match: vld=%b, rdy_match=%b",
                             u_dut.u_node.e_out_valid == pkt_con_eo_vld,
                             u_dut.u_node.e_out_ready == pkt_con_eo_rdy);
                end
                $display("=================================================================");
            end

            // 🔧 CRITICAL FIX: 实时监控输出端口更新last_output_*信号
            // 默认无效（如果没有检测到输出）
            if (!last_output_valid) begin
                last_output_valid <= 0;
            end

            // 监控B端口（LOCAL）输出
            if (pkt_o_pkt_out_vld && pkt_o_pkt_out_rdy) begin
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_o_pkt_out_type, pkt_o_pkt_out_qos,
                                             pkt_o_pkt_out_src, pkt_o_pkt_out_tgt,
                                             pkt_o_pkt_out_data);
                last_output_port <= 3'd4;  // LOCAL
                $display("[OUTPUT MONITOR] Cycle %0d: LOCAL(B) Output detected: pkt=%h",
                         test_cycle, last_output_pkt);
            end

            // 监控N端口输出
            if (pkt_con_no_vld && pkt_con_no_rdy) begin
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_no_type, pkt_con_no_qos,
                                             pkt_con_no_src, pkt_con_no_tgt,
                                             pkt_con_no_data);
                last_output_port <= 3'd0;  // NORTH
                $display("[OUTPUT MONITOR] Cycle %0d: NORTH Output detected: pkt=%h",
                         test_cycle, last_output_pkt);
            end

            // 监控W端口输出
            if (pkt_con_wo_vld && pkt_con_wo_rdy) begin
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_wo_type, pkt_con_wo_qos,
                                             pkt_con_wo_src, pkt_con_wo_tgt,
                                             pkt_con_wo_data);
                last_output_port <= 3'd1;  // WEST
                $display("[OUTPUT MONITOR] Cycle %0d: WEST Output detected: pkt=%h",
                         test_cycle, last_output_pkt);
            end

            // 监控S端口输出
            if (pkt_con_so_vld && pkt_con_so_rdy) begin
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_so_type, pkt_con_so_qos,
                                             pkt_con_so_src, pkt_con_so_tgt,
                                             pkt_con_so_data);
                last_output_port <= 3'd2;  // SOUTH
                $display("[OUTPUT MONITOR] Cycle %0d: SOUTH Output detected: pkt=%h",
                         test_cycle, last_output_pkt);
            end

            // 监控E端口输出
            if (pkt_con_eo_vld && pkt_con_eo_rdy) begin
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_eo_type, pkt_con_eo_qos,
                                             pkt_con_eo_src, pkt_con_eo_tgt,
                                             pkt_con_eo_data);
                last_output_port <= 3'd3;  // EAST

                // 🔧 DEBUG: 打印原始接口信号
                $display("[OUTPUT MONITOR] Cycle %0d: EAST Output detected:", test_cycle);
                $display("  Raw signals: vld=%d, rdy=%d, type=%d, qos=%d, src=%d, tgt=%d, data=0x%02h",
                         pkt_con_eo_vld, pkt_con_eo_rdy, pkt_con_eo_type, pkt_con_eo_qos,
                         pkt_con_eo_src, pkt_con_eo_tgt, pkt_con_eo_data);

                // 手动计算编码用于验证
                manual_encoded = {pkt_con_eo_type, pkt_con_eo_qos, pkt_con_eo_src, pkt_con_eo_tgt, pkt_con_eo_data};
                $display("  Manual encoded: %h", manual_encoded);
                $display("  Function result: %h", last_output_pkt);
                $display("  Match: %b", manual_encoded == last_output_pkt);
            end

            // 11拍后停止详细监控
            if (test_cycle > 10) begin
                first_10_cycles_debug = 0;
            end
        end
    end

    // 增强的发送数据包任务
    task automatic send_packet;
        input [1:0] pkt_type;
        input pkt_qos;
        input [5:0] src_id;
        input [5:0] tgt_id;
        input [7:0] data;
        integer timeout;
        integer wait_cycles;
        begin
            $display("==============================================");
            $display("[SEND DEBUG] Cycle %0d: STARTING PACKET SEND", test_cycle);
            $display("  Packet Info: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     pkt_type, pkt_qos, src_id, tgt_id, data);
            $display("  Target Direction: Expected output port calculation:");
            if (tgt_id == src_id) begin
                $display("    -> LOCAL (port 4) - Same node");
            end else begin
                // 提取源和目标的X,Y坐标
                logic [2:0] src_x = src_id[2:0];    // 源X坐标
                logic [2:0] src_y = src_id[5:3];    // 源Y坐标
                logic [2:0] tgt_x = tgt_id[2:0];    // 目标X坐标
                logic [2:0] tgt_y = tgt_id[5:3];    // 目标Y坐标

                if (src_y == tgt_y) begin
                    // 相同行：东西方向路由
                    if (tgt_x > src_x) begin
                        $display("    -> EAST (port 3) - X+ (%0d -> %0d)", src_x, tgt_x);
                    end else if (tgt_x < src_x) begin
                        $display("    -> WEST (port 1) - X- (%0d -> %0d)", src_x, tgt_x);
                    end
                end else if (src_x == tgt_x) begin
                    // 相同列：南北方向路由
                    if (tgt_y > src_y) begin
                        $display("    -> NORTH (port 0) - Y+ (%0d -> %0d)", src_y, tgt_y);
                    end else if (tgt_y < src_y) begin
                        $display("    -> SOUTH (port 2) - Y- (%0d -> %0d)", src_y, tgt_y);
                    end
                end else begin
                    $display("    -> COMPLEX ROUTING: Different X and Y (%0d,%0d -> %0d,%0d)",
                             src_x, src_y, tgt_x, tgt_y);
                end
            end
            $display("==============================================");

            // 检查初始状态
            $display("[SEND DEBUG] Cycle %0d: Before send - pkt_in_rdy=%d", test_cycle, pkt_i_pkt_in_rdy);

            // 设置数据包（使用阻塞赋值避免INITIALDLY警告）
            pkt_i_pkt_in_vld = 1;
            pkt_i_pkt_in_type = pkt_type;
            pkt_i_pkt_in_qos = pkt_qos;
            pkt_i_pkt_in_src = src_id;
            pkt_i_pkt_in_tgt = tgt_id;
            pkt_i_pkt_in_data = data;

            $display("[SEND DEBUG] Cycle %0d: Packet valid set - waiting for ready...", test_cycle);

            // 等待接收就绪
            timeout = 100;
            wait_cycles = 0;
            while (!pkt_i_pkt_in_rdy && timeout > 0) begin
                @(posedge clk);
                wait_cycles++;
                timeout--;

                // 每10个周期打印等待状态
                if (wait_cycles % 10 == 0) begin
                    $display("[SEND DEBUG] Cycle %0d: Still waiting for pkt_in_rdy (waited %0d cycles, timeout in %0d)",
                             test_cycle, wait_cycles, timeout);
                end
            end

            if (timeout == 0) begin
                $display("[SEND ERROR] Cycle %0d: TIMEOUT waiting for pkt_in_rdy after %0d cycles",
                         test_cycle, wait_cycles);
                $display("  Final status: pkt_i_pkt_in_vld=%d, pkt_i_pkt_in_rdy=%d",
                         pkt_i_pkt_in_vld, pkt_i_pkt_in_rdy);
                error_count++;
            end else begin
                $display("[SEND SUCCESS] Cycle %0d: Packet accepted after %0d cycles",
                         test_cycle, wait_cycles);
            end

            // 清除valid信号（使用阻塞赋值）
            @(posedge clk);
            pkt_i_pkt_in_vld = 0;
            $display("[SEND DEBUG] Cycle %0d: Valid signal cleared", test_cycle);
        end
    endtask

    // 验证输出任务
    task automatic verify_output;
        input [22:0] expected_pkt;
        input [2:0] expected_port;
        integer timeout;
        reg match_found;
        begin
            timeout = 50;  // 最多等待50个周期
            match_found = 0;

            $display("[Cycle %0d] Waiting for expected output on port %d: %h",
                     test_cycle, expected_port, expected_pkt);

            while (timeout > 0 && !match_found) begin
                @(posedge clk);
                if (last_output_valid && last_output_pkt == expected_pkt && last_output_port == expected_port) begin
                    match_found = 1;
                    $display("[Cycle %0d] PASS: Expected output found", test_cycle);
                    pass_count++;
                end
                timeout--;
            end

            if (!match_found) begin
                $display("ERROR: Expected output not found");
                $display("  Expected: Port=%d, Pkt=%h", expected_port, expected_pkt);
                error_count++;
            end

            test_count++;
        end
        $display("PASS = %d",test_count);
    endtask

    // 主测试序列
    initial begin
        // 初始化
        $display("==============================================");
        $display("MAZE节点基本路由功能测试 - DEBUG版本");
        $display("测试节点: (%0d, %0d)", TEST_NODE_X, TEST_NODE_Y);
        $display("==============================================");

        // 打印详细的节点和路由信息
        $display("DEBUG: 节点位置和路由信息分析");
        $display("测试节点坐标: (X=%0d, Y=%0d)", TEST_NODE_X, TEST_NODE_Y);
        $display("当前节点ID: %d (binary: %b)", calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y));
        $display("当前节点分解: Y坐标(bit5:3)=%b, X坐标(bit2:0)=%b",
                 calc_node_id(TEST_NODE_X, TEST_NODE_Y)[5:3], calc_node_id(TEST_NODE_X, TEST_NODE_Y)[2:0]);
        $display("邻居节点ID:");
        $display("  - 西侧节点(X=%0d, Y=%0d): ID=%d", TEST_NODE_X-1, TEST_NODE_Y, calc_node_id(TEST_NODE_X-1, TEST_NODE_Y));
        $display("  - 东侧节点(X=%0d, Y=%0d): ID=%d", TEST_NODE_X+1, TEST_NODE_Y, calc_node_id(TEST_NODE_X+1, TEST_NODE_Y));
        $display("  - 南侧节点(X=%0d, Y=%0d): ID=%d", TEST_NODE_X, TEST_NODE_Y-1, calc_node_id(TEST_NODE_X, TEST_NODE_Y-1));
        $display("  - 北侧节点(X=%0d, Y=%0d): ID=%d", TEST_NODE_X, TEST_NODE_Y+1, calc_node_id(TEST_NODE_X, TEST_NODE_Y+1));
        $display("预期路由端口映射:");
        $display("  - 向西路由(X-1): 端口1 (WEST)");
        $display("  - 向东路由(X+1): 端口3 (EAST)");
        $display("  - 向南路由(Y-1): 端口2 (SOUTH)");
        $display("  - 向北路由(Y+1): 端口0 (NORTH)");
        $display("  - 本地路由(相同坐标): 端口4 (LOCAL)");
        $display("==============================================");

        clk = 0;
        rst_n = 0;
        pg_en = 0;
        pg_node = 0;
        test_cycle = 0;
        error_count = 0;
        test_count = 0;
        pass_count = 0;
        debug_cycle_counter = 0;

        // 清除所有输入
        pkt_i_pkt_in_vld = 0;
        pkt_o_pkt_out_rdy = 1;
        pkt_con_no_rdy = 1;
        pkt_con_wo_rdy = 1;
        pkt_con_so_rdy = 1;
        pkt_con_eo_rdy = 1;

        $display("[INIT DEBUG] Reset phase starting...");

        // 复位序列
        @(posedge clk);
        @(posedge clk);
        rst_n = 1;
        @(posedge clk);
        @(posedge clk);

        $display("[INIT DEBUG] Reset completed. Testing node interfaces...");

        // 检查初始接口状态
        $display("[INIT DEBUG] Initial interface states:");
        $display("  A_PORT: vld=%d, rdy=%d", pkt_i_pkt_in_vld, pkt_i_pkt_in_rdy);
        $display("  B_PORT: vld=%d, rdy=%d", pkt_o_pkt_out_vld, pkt_o_pkt_out_rdy);
        $display("  N_PORT: out_vld=%d, out_rdy=%d", pkt_con_no_vld, pkt_con_no_rdy);
        $display("  W_PORT: out_vld=%d, out_rdy=%d", pkt_con_wo_vld, pkt_con_wo_rdy);
        $display("  S_PORT: out_vld=%d, out_rdy=%d", pkt_con_so_vld, pkt_con_so_rdy);
        $display("  E_PORT: out_vld=%d, out_rdy=%d", pkt_con_eo_vld, pkt_con_eo_rdy);

        $display("复位完成，开始基本路由功能测试...");
        $display("");

        // N-RF-001: X方向正向路由（向东）
        $display("--- N-RF-001: X方向正向路由测试 ---");
        if (TEST_NODE_X < 7) begin
            send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X+1, TEST_NODE_Y), 8'hA5);
            verify_output(encode_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X+1, TEST_NODE_Y), 8'hA5), 3'd3);
        end else begin
            $display("跳过：节点已在东边缘，无法向东路由");
        end
        @(posedge clk * 5);

        // N-RF-002: X方向反向路由（向西）
        $display("--- N-RF-002: X方向反向路由测试 ---");
        if (TEST_NODE_X > 0) begin
            send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X-1, TEST_NODE_Y), 8'h5A);
            verify_output(encode_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X-1, TEST_NODE_Y), 8'h5A), 3'd1);
        end else begin
            $display("跳过：节点已在西边缘，无法向西路由");
        end
        @(posedge clk * 5);

        // N-RF-003: Y方向正向路由（向北）
        $display("--- N-RF-003: Y方向正向路由测试 ---");
        if (TEST_NODE_Y < 7) begin
            send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y+1), 8'h33);
            verify_output(encode_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y+1), 8'h33), 3'd0);
        end else begin
            $display("跳过：节点已在北边缘，无法向北路由");
        end
        @(posedge clk * 5);

        // N-RF-004: Y方向反向路由（向南）
        $display("--- N-RF-004: Y方向反向路由测试 ---");
        if (TEST_NODE_Y > 0) begin
            send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y-1), 8'hCC);
            verify_output(encode_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y-1), 8'hCC), 3'd2);
        end else begin
            $display("跳过：节点已在南边缘，无法向南路由");
        end
        @(posedge clk * 5);

        // N-RF-005: 本地路由
        $display("--- N-RF-005: 本地路由测试 ---");
        send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y), 8'hFF);
        verify_output(encode_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X, TEST_NODE_Y), 8'hFF), 3'd4);
        // @(posedge clk * 10);
        $display("All finished");

        // 测试总结
        $display("");
        $display("==============================================");
        $display("测试总结");
        $display("==============================================");
        $display("总测试数: %0d", test_count);
        $display("通过测试: %0d", pass_count);
        $display("失败测试: %0d", error_count);
        $display("通过率: %0.2f%%", test_count > 0 ? (pass_count * 100.0 / test_count) : 0.0);

        if (error_count == 0) begin
            $display("✓ 所有基本路由功能测试通过！");
            $display("TEST_RESULT: PASS");
            #(CLK_PERIOD * 10);
            $finish;
        end else begin
            $display("✗ 部分基本路由功能测试失败");
            $display("失败测试数: %0d / %0d", error_count, test_count);
            $display("TEST_RESULT: FAIL");
            #(CLK_PERIOD * 10);
            $finish;
        end

        $display("==============================================");

        // 结束仿真
        #(CLK_PERIOD * 10);
        $finish;
    end

    // 测试超时保护
    initial begin
        #(CLK_PERIOD * TEST_TIMEOUT);
        $display("[IRS DEBUG] Cycle %0d:", test_cycle);
        $display("ERROR: 测试超时！");
        $finish;
    end

endmodule