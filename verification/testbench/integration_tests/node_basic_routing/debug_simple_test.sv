// =============================================================================
// MAZE节点A端口IRS_N调试测试台（SystemVerilog版本）
// =============================================================================
// 功能说明：
// 1. 每个周期打印A端口IRS_N的输出信息
// 2. 详细显示节点的内部状态和路由决策过程
// 3. 便于调试路由功能问题
// =============================================================================

`timescale 1ns/1ps

// 包含必要的定义文件
`include "rtl/include/global_defines/top_define.v"

module debug_simple_test;

    // 测试参数
    parameter TEST_NODE_X = 3;
    parameter TEST_NODE_Y = 3;
    parameter CLK_PERIOD = 10;  // 10ns时钟周期
    parameter TEST_TIMEOUT = 200;  // 最大测试周期数（减少用于调试）

    // 计算节点ID，确保6位宽度
    function automatic [5:0] calc_node_id;
        input integer x;
        input integer y;
        begin
            calc_node_id = {y[2:0], x[2:0]};  // 只取低3位，确保6位总宽度
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

    // 调试计数器
    integer debug_cycle;

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

    // 数据包编码函数
    function automatic [22:0] encode_packet;
        input [1:0] pkt_type;
        input pkt_qos;
        input [5:0] src_id;
        input [5:0] tgt_id;
        input [7:0] data;
        begin
            encode_packet = {pkt_type, pkt_qos, src_id, tgt_id, data};
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
            $display("Packet[0x%06h]: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
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
            debug_cycle <= 0;
        end else begin
            test_cycle <= test_cycle + 1;
            debug_cycle <= debug_cycle + 1;
        end
    end

    // 每个周期的详细调试输出
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            $display("[Cycle %0d] 复位中...", debug_cycle);
        end else begin
            $display("==========================================");
            $display("[Cycle %0d] 详细状态监控", debug_cycle);
            $display("==========================================");

            // A端口输入状态
            $display("A端口输入: vld=%d, rdy=%d", pkt_i_pkt_in_vld, pkt_i_pkt_in_rdy);
            if (pkt_i_pkt_in_vld) begin
                $display("  输入数据包: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_i_pkt_in_type, pkt_i_pkt_in_qos,
                         pkt_i_pkt_in_src, pkt_i_pkt_in_tgt, pkt_i_pkt_in_data);
            end

            // 输出端口状态
            $display("输出端口状态:");
            $display("  Local: vld=%d, rdy=%d", pkt_o_pkt_out_vld, pkt_o_pkt_out_rdy);
            if (pkt_o_pkt_out_vld) begin
                $display("    数据: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_o_pkt_out_type, pkt_o_pkt_out_qos,
                         pkt_o_pkt_out_src, pkt_o_pkt_out_tgt, pkt_o_pkt_out_data);
            end

            $display("  North: vld=%d, rdy=%d", pkt_con_no_vld, pkt_con_no_rdy);
            if (pkt_con_no_vld) begin
                $display("    数据: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_con_no_type, pkt_con_no_qos,
                         pkt_con_no_src, pkt_con_no_tgt, pkt_con_no_data);
            end

            $display("  West: vld=%d, rdy=%d", pkt_con_wo_vld, pkt_con_wo_rdy);
            if (pkt_con_wo_vld) begin
                $display("    数据: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_con_wo_type, pkt_con_wo_qos,
                         pkt_con_wo_src, pkt_con_wo_tgt, pkt_con_wo_data);
            end

            $display("  South: vld=%d, rdy=%d", pkt_con_so_vld, pkt_con_so_rdy);
            if (pkt_con_so_vld) begin
                $display("    数据: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_con_so_type, pkt_con_so_qos,
                         pkt_con_so_src, pkt_con_so_tgt, pkt_con_so_data);
            end

            $display("  East: vld=%d, rdy=%d", pkt_con_eo_vld, pkt_con_eo_rdy);
            if (pkt_con_eo_vld) begin
                $display("    数据: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                         pkt_con_eo_type, pkt_con_eo_qos,
                         pkt_con_eo_src, pkt_con_eo_tgt, pkt_con_eo_data);
            end

            $display("C接口输入就绪状态: NI=%d, WI=%d, SI=%d, EI=%d",
                     pkt_con_ni_rdy, pkt_con_wi_rdy, pkt_con_si_rdy, pkt_con_ei_rdy);
        end
    end

    // 发送数据包任务
    task automatic send_packet;
        input [1:0] pkt_type;
        input pkt_qos;
        input [5:0] src_id;
        input [5:0] tgt_id;
        input [7:0] data;
        integer timeout;
        begin
            $display("--- 发送数据包 ---");
            $display("发送: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     pkt_type, pkt_qos, src_id, tgt_id, data);

            // 设置数据包
            pkt_i_pkt_in_vld = 1;
            pkt_i_pkt_in_type = pkt_type;
            pkt_i_pkt_in_qos = pkt_qos;
            pkt_i_pkt_in_src = src_id;
            pkt_i_pkt_in_tgt = tgt_id;
            pkt_i_pkt_in_data = data;

            // 等待接收就绪
            timeout = 100;
            while (!pkt_i_pkt_in_rdy && timeout > 0) begin
                @(posedge clk);
                timeout--;
            end

            if (timeout == 0) begin
                $display("ERROR: Timeout waiting for pkt_in_rdy");
                error_count++;
            end

            // 清除valid信号
            @(posedge clk);
            pkt_i_pkt_in_vld = 0;
        end
    endtask

    // 主测试序列
    initial begin
        // 初始化
        $display("==============================================");
        $display("MAZE节点A端口IRS_N调试测试");
        $display("测试节点: (%0d, %0d)", TEST_NODE_X, TEST_NODE_Y);
        $display("==============================================");

        clk = 0;
        rst_n = 0;
        pg_en = 0;
        pg_node = 0;
        test_cycle = 0;
        error_count = 0;
        test_count = 0;
        pass_count = 0;

        // 清除所有输入
        pkt_i_pkt_in_vld = 0;
        pkt_o_pkt_out_rdy = 1;
        pkt_con_no_rdy = 1;
        pkt_con_wo_rdy = 1;
        pkt_con_so_rdy = 1;
        pkt_con_eo_rdy = 1;

        // 复位序列
        @(posedge clk);
        @(posedge clk);
        rst_n = 1;
        @(posedge clk);
        @(posedge clk);

        $display("复位完成，开始调试测试...");
        $display("");

        // 发送一个测试数据包并详细观察
        $display("=== 发送东向路由测试数据包 ===");
        send_packet(2'b00, 1'b0, calc_node_id(TEST_NODE_X, TEST_NODE_Y), calc_node_id(TEST_NODE_X+1, TEST_NODE_Y), 8'hA5);

        // 观察多个周期的行为
        $display("=== 观察节点行为 ===");
        for (integer i = 0; i < 20; i++) begin
            @(posedge clk);
        end

        // 测试总结
        $display("");
        $display("==============================================");
        $display("调试测试完成");
        $display("==============================================");
        $display("观察周期数: %0d", debug_cycle);
        $display("错误计数: %0d", error_count);

        #(CLK_PERIOD * 10);
        $finish;
    end

    // 测试超时保护
    initial begin
        #(CLK_PERIOD * TEST_TIMEOUT);
        $display("ERROR: 测试超时！");
        $finish;
    end

endmodule