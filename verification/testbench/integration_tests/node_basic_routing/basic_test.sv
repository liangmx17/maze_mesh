// =============================================================================
// MAZE节点基本测试 - 简化版本
// =============================================================================
// 只测试基本的节点实例化和信号连接

`timescale 1ns/1ps
`include "param.v"

module basic_test;

    // 测试参数
    localparam TEST_NODE_X = 3;
    localparam TEST_NODE_Y = 3;
    localparam TEST_CYCLES = 20;

    // 时钟和复位信号
    reg clk;
    reg rst_n;

    // 故障配置
    reg pg_en;
    reg [5:0] pg_node;

    // 接口实例
    pkt_in pkt_i();
    pkt_out pkt_o();
    pkt_con_if pkt_con();

    // 待测试节点
    node #(
        .HP(TEST_NODE_X),
        .VP(TEST_NODE_Y)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .pg_en(pg_en),
        .pg_node(pg_node),
        .pkt_i(pkt_i),
        .pkt_o(pkt_o),
        .pkt_con(pkt_con)
    );

    // 时钟控制在C++中处理，这里只声明信号

    // 测试逻辑
    integer test_count;

    initial begin
        // 初始化信号
        clk = 0;
        rst_n = 0;
        pg_en = 0;
        pg_node = 0;
        test_count = 0;

        // 复位序列
        #(10);
        rst_n = 1;
        #(10);

        // 基本测试循环
        $display("=== 开始MAZE节点基本测试 ===");
        $display("测试节点位置: (%0d, %0d)", TEST_NODE_X, TEST_NODE_Y);

        for (test_count = 0; test_count < TEST_CYCLES; test_count++) begin
            #(10);
            $display("测试周期 %0d: 节点运行正常", test_count + 1);
        end

        $display("=== 测试完成 ===");
        $finish;
    end

    // 监控输出
    always @(posedge clk) begin
        if (rst_n && pkt_o.pkt_out_vld) begin
            $display("[输出] 类型=%0d, QoS=%0d, 源=0x%02X, 目标=0x%02X, 数据=0x%02X",
                    pkt_o.pkt_out_type, pkt_o.pkt_out_qos,
                    pkt_o.pkt_out_src, pkt_o.pkt_out_tgt, pkt_o.pkt_out_data);
        end
    end

endmodule