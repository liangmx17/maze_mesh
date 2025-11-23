// =============================================================================
// MAZE节点验证环境 - TEST-003 输出验证测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-003: 输出验证测试任务
task automatic test_output_verification(
    inout integer test_count,
    inout integer passed_count
);
    integer timeout_counter;

    $display("\n=== [TEST-003] 输出验证测试 ===");
    $display("时钟计数器=%0d: 监控输出端口是否有数据输出", clk_counter);

    timeout_counter = 0;
    $display("时钟计数器=%0d: 开始监控输出...", clk_counter);

    // 监控B接口输出（单播应该从B输出）
    while (!pkt_o.slv.pkt_out_vld && timeout_counter < 100) begin
        @(posedge clk);
        timeout_counter++;

        // 每10个周期打印一次状态
        if (timeout_counter % 10 == 0) begin
            $display("时钟计数器=%0d: 监控中... timeout_counter=%0d", clk_counter, timeout_counter);
            $display("  B接口: vld=%b, data=0x%h, src=%0d, tgt=%0d",
                     pkt_o.slv.pkt_out_vld, pkt_o.slv.pkt_out_data,
                     pkt_o.slv.pkt_out_src, pkt_o.slv.pkt_out_tgt);
            $display("  N接口: vld=%b", pkt_con.slv.no_vld);
            $display("  W接口: vld=%b", pkt_con.slv.wo_vld);
            $display("  S接口: vld=%b", pkt_con.slv.so_vld);
            $display("  E接口: vld=%b", pkt_con.slv.eo_vld);
        end
    end

    if (pkt_o.slv.pkt_out_vld) begin
        $display("✓ 时钟计数器=%0d: B接口检测到有效输出！", clk_counter);
        $display("  输出数据: 0x%h, valid=%b, qos=%b, type=%b",
                 pkt_o.slv.pkt_out_data, pkt_o.slv.pkt_out_vld,
                 pkt_o.slv.pkt_out_qos, pkt_o.slv.pkt_out_type);
        $display("  源节点: %0d, 目标节点: %0d",
                 pkt_o.slv.pkt_out_src, pkt_o.slv.pkt_out_tgt);
    end else begin
        $display("✗ 时钟计数器=%0d: B接口无输出，超时！", clk_counter);
    end

    // 继续监控几个周期看其他端口
    repeat(10) @(posedge clk) begin
        $display("时钟计数器=%0d: 继续监控 - B:%b N:%b W:%b S:%b E:%b", clk_counter,
                 pkt_o.slv.pkt_out_vld, pkt_con.slv.no_vld, pkt_con.slv.wo_vld,
                 pkt_con.slv.so_vld, pkt_con.slv.eo_vld);
    end

    test_count++;
    passed_count++;
endtask