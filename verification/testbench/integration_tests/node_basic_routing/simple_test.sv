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
`include "rtl/include/global_defines/top_define.v"

module simple_test;

    // 测试参数
    parameter TEST_NODE_X = 3;
    parameter TEST_NODE_Y = 3;
    parameter CLK_PERIOD = 10;  // 10ns时钟周期
    parameter TEST_TIMEOUT = 10000;  // 最大测试周期数

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
        end else begin
            test_cycle <= test_cycle + 1;
        end
    end

    // 监控输出端口 - 修改为显示所有有效输出
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            last_output_valid <= 0;
            last_output_pkt <= 0;
            last_output_port <= 0;
        end else begin
            // 显示所有有效输出（用于调试）
            if (pkt_o_pkt_out_vld && pkt_o_pkt_out_rdy) begin
                $display("[Cycle %0d] Local Output: %h (Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h)",
                         test_cycle, encode_packet(pkt_o_pkt_out_type, pkt_o_pkt_out_qos,
                                                  pkt_o_pkt_out_src, pkt_o_pkt_out_tgt,
                                                  pkt_o_pkt_out_data),
                         pkt_o_pkt_out_type, pkt_o_pkt_out_qos, pkt_o_pkt_out_src,
                         pkt_o_pkt_out_tgt, pkt_o_pkt_out_data);
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_o_pkt_out_type, pkt_o_pkt_out_qos,
                                               pkt_o_pkt_out_src, pkt_o_pkt_out_tgt,
                                               pkt_o_pkt_out_data);
                last_output_port <= 3'd4;  // LOCAL
            end

            if (pkt_con_no_vld && pkt_con_no_rdy) begin
                $display("[Cycle %0d] North Output: %h (Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h)",
                         test_cycle, encode_packet(pkt_con_no_type, pkt_con_no_qos,
                                                  pkt_con_no_src, pkt_con_no_tgt,
                                                  pkt_con_no_data),
                         pkt_con_no_type, pkt_con_no_qos, pkt_con_no_src,
                         pkt_con_no_tgt, pkt_con_no_data);
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_no_type, pkt_con_no_qos,
                                               pkt_con_no_src, pkt_con_no_tgt,
                                               pkt_con_no_data);
                last_output_port <= 3'd0;  // NORTH
            end

            if (pkt_con_wo_vld && pkt_con_wo_rdy) begin
                $display("[Cycle %0d] West Output: %h (Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h)",
                         test_cycle, encode_packet(pkt_con_wo_type, pkt_con_wo_qos,
                                                  pkt_con_wo_src, pkt_con_wo_tgt,
                                                  pkt_con_wo_data),
                         pkt_con_wo_type, pkt_con_wo_qos, pkt_con_wo_src,
                         pkt_con_wo_tgt, pkt_con_wo_data);
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_wo_type, pkt_con_wo_qos,
                                               pkt_con_wo_src, pkt_con_wo_tgt,
                                               pkt_con_wo_data);
                last_output_port <= 3'd1;  // WEST
            end

            if (pkt_con_so_vld && pkt_con_so_rdy) begin
                $display("[Cycle %0d] South Output: %h (Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h)",
                         test_cycle, encode_packet(pkt_con_so_type, pkt_con_so_qos,
                                                  pkt_con_so_src, pkt_con_so_tgt,
                                                  pkt_con_so_data),
                         pkt_con_so_type, pkt_con_so_qos, pkt_con_so_src,
                         pkt_con_so_tgt, pkt_con_so_data);
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_so_type, pkt_con_so_qos,
                                               pkt_con_so_src, pkt_con_so_tgt,
                                               pkt_con_so_data);
                last_output_port <= 3'd2;  // SOUTH
            end

            if (pkt_con_eo_vld && pkt_con_eo_rdy) begin
                $display("[Cycle %0d] East Output: %h (Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h)",
                         test_cycle, encode_packet(pkt_con_eo_type, pkt_con_eo_qos,
                                                  pkt_con_eo_src, pkt_con_eo_tgt,
                                                  pkt_con_eo_data),
                         pkt_con_eo_type, pkt_con_eo_qos, pkt_con_eo_src,
                         pkt_con_eo_tgt, pkt_con_eo_data);
                last_output_valid <= 1;
                last_output_pkt <= encode_packet(pkt_con_eo_type, pkt_con_eo_qos,
                                               pkt_con_eo_src, pkt_con_eo_tgt,
                                               pkt_con_eo_data);
                last_output_port <= 3'd3;  // EAST
            end
        end
    end

    // 发送数据包任务（修复INITIALDLY警告：使用阻塞赋值）
    task automatic send_packet;
        input [1:0] pkt_type;
        input pkt_qos;
        input [5:0] src_id;
        input [5:0] tgt_id;
        input [7:0] data;
        integer timeout;
        begin
            $display("[Cycle %0d] Sending packet: Type=%d, QoS=%d, Src=%d, Tgt=%d, Data=0x%02h",
                     test_cycle, pkt_type, pkt_qos, src_id, tgt_id, data);

            // 设置数据包（使用阻塞赋值避免INITIALDLY警告）
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

            // 清除valid信号（使用阻塞赋值）
            @(posedge clk);
            pkt_i_pkt_in_vld = 0;
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
    endtask

    // 主测试序列
    initial begin
        // 初始化
        $display("==============================================");
        $display("MAZE节点基本路由功能测试");
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
        @(posedge clk * 10);

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
        $display("ERROR: 测试超时！");
        $finish;
    end

endmodule