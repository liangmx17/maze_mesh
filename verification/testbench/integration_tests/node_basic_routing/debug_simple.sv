// =============================================================================
// MAZE节点简单调试测试台
// =============================================================================
// 功能说明：
// 1. 极简化的测试台，只发送一个数据包
// 2. 详细监控每个阶段的数据内容
// 3. 帮助定位数据包丢失的具体位置
// =============================================================================

`timescale 1ns/1ps

// 包含必要的定义文件
`include "../../../rtl/include/global_defines/top_define.v"

module debug_simple;

    // 测试参数
    parameter TEST_NODE_X = 3;
    parameter TEST_NODE_Y = 3;
    parameter CLK_PERIOD = 10;

    // 仿真信号
    reg clk;
    reg rst_n;
    integer test_cycle;

    // 故障容错配置
    reg pg_en;
    reg [5:0] pg_node;

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

    // C接口输出信号
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

        // C接口
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
        end else begin
            test_cycle <= test_cycle + 1;
        end
    end

    // 监控输入信号
    always @(posedge clk) begin
        if (pkt_i_pkt_in_vld && pkt_i_pkt_in_rdy) begin
            $display("[Cycle %0d] INPUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_i_pkt_in_type, pkt_i_pkt_in_qos,
                     pkt_i_pkt_in_src, pkt_i_pkt_in_tgt, pkt_i_pkt_in_data);
        end
    end

    // 监控所有输出信号
    always @(posedge clk) begin
        if (pkt_o_pkt_out_vld && pkt_o_pkt_out_rdy) begin
            $display("[Cycle %0d] LOCAL_OUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_o_pkt_out_type, pkt_o_pkt_out_qos,
                     pkt_o_pkt_out_src, pkt_o_pkt_out_tgt, pkt_o_pkt_out_data);
        end

        if (pkt_con_no_vld && pkt_con_no_rdy) begin
            $display("[Cycle %0d] NORTH_OUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_con_no_type, pkt_con_no_qos,
                     pkt_con_no_src, pkt_con_no_tgt, pkt_con_no_data);
        end

        if (pkt_con_wo_vld && pkt_con_wo_rdy) begin
            $display("[Cycle %0d] WEST_OUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_con_wo_type, pkt_con_wo_qos,
                     pkt_con_wo_src, pkt_con_wo_tgt, pkt_con_wo_data);
        end

        if (pkt_con_so_vld && pkt_con_so_rdy) begin
            $display("[Cycle %0d] SOUTH_OUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_con_so_type, pkt_con_so_qos,
                     pkt_con_so_src, pkt_con_so_tgt, pkt_con_so_data);
        end

        if (pkt_con_eo_vld && pkt_con_eo_rdy) begin
            $display("[Cycle %0d] EAST_OUT: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_con_eo_type, pkt_con_eo_qos,
                     pkt_con_eo_src, pkt_con_eo_tgt, pkt_con_eo_data);
        end
    end

    // 主测试序列
    initial begin
        // 初始化
        $display("==============================================");
        $display("MAZE节点调试测试");
        $display("测试节点: (%0d, %0d)", TEST_NODE_X, TEST_NODE_Y);
        $display("==============================================");

        clk = 0;
        rst_n = 0;
        pg_en = 0;
        pg_node = 0;
        test_cycle = 0;

        // 清除所有输入
        pkt_i_pkt_in_vld = 0;
        pkt_i_pkt_in_type = 0;
        pkt_i_pkt_in_qos = 0;
        pkt_i_pkt_in_src = 0;
        pkt_i_pkt_in_tgt = 0;
        pkt_i_pkt_in_data = 0;

        // 设置输出ready信号
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

        $display("复位完成，发送测试数据包...");
        $display("");

        // 发送一个简单的本地路由数据包
        @(posedge clk);
        pkt_i_pkt_in_vld = 1;
        pkt_i_pkt_in_type = 2'b00;    // 单播
        pkt_i_pkt_in_qos = 1'b0;      // 低优先级
        pkt_i_pkt_in_src = 6'd27;     // 源节点 (3,3) = 011011
        pkt_i_pkt_in_tgt = 6'd27;     // 目标节点 (3,3) = 011011
        pkt_i_pkt_in_data = 8'hAA;    // 测试数据

        // 等待数据被接收
        wait(pkt_i_pkt_in_rdy);
        @(posedge clk);
        pkt_i_pkt_in_vld = 0;

        $display("数据包已发送，等待输出...");
        $display("");

        // 等待足够长的时间观察输出
        repeat (50) @(posedge clk);

        $display("测试完成");
        $finish;
    end

endmodule