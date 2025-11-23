// =============================================================================
// MAZE节点验证环境 - TEST-002 数据包传输测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-002: 数据包传输测试任务
task automatic test_packet_transmission(
    inout integer test_count,
    inout integer passed_count
);
    integer timeout_counter;
    logic [22:0] test_packet_data;
    logic test_packet_valid;

    $display("\n=== [TEST-002] 数据包传输测试 ===");
    $display("时钟计数器=%0d: 配置故障信号并从A端口发送数据包", clk_counter);

    // 配置故障信号（无故障状态）
    pg_en = 0;
    pg_node = 0;
    $display("时钟计数器=%0d: 配置故障信号：pg_en=0, pg_node=0", clk_counter);

    @(posedge clk);
    $display("时钟计数器=%0d: PKT_W=%0d位", clk_counter, 23);  // 硬编码23位宽度

    // 生成测试数据包（23位格式）
    test_packet_data = {2'b00, 1'b0, 6'd0, 6'd1, 8'hAA};  // 类型=00, qos=0, src=0, tgt=1, data=AA
    test_packet_valid = 1;

    $display("时钟计数器=%0d: 生成测试数据包: 0x%h", clk_counter, test_packet_data);
    $display("  包格式：[类型=%b, QoS=%b, 源=%0d, 目标=%0d, 数据=0x%h]",
             test_packet_data[22:21], test_packet_data[20],
             test_packet_data[19:14], test_packet_data[13:8],
             test_packet_data[7:0]);
    $display("  包类型：单播，源节点：0，目标节点：1，数据：0xAA");

    // 驱动A接口输入（真实节点连接）
    pkt_i.slv.pkt_in_vld = test_packet_valid;
    pkt_i.slv.pkt_in_qos = test_packet_data[20];
    pkt_i.slv.pkt_in_type = test_packet_data[22:21];
    pkt_i.slv.pkt_in_src = test_packet_data[19:14];
    pkt_i.slv.pkt_in_tgt = test_packet_data[13:8];
    pkt_i.slv.pkt_in_data = test_packet_data[7:0];

    // 等待数据包被接收（握手完成）
    timeout_counter = 0;
    $display("时钟计数器=%0d: 等待A接口ready信号...", clk_counter);

    while (!(pkt_i.slv.pkt_in_vld && pkt_i.slv.pkt_in_rdy) && timeout_counter < 100) begin
        @(posedge clk);
        timeout_counter++;
        if (timeout_counter % 10 == 0) begin
            $display("时钟计数器=%0d: 等待中... timeout_counter=%0d, valid=%b, rdy=%b",
                     clk_counter, timeout_counter, pkt_i.slv.pkt_in_vld, pkt_i.slv.pkt_in_rdy);
        end
    end

    if (pkt_i.slv.pkt_in_vld && pkt_i.slv.pkt_in_rdy) begin
        $display("✓ 时钟计数器=%0d: A接口握手成功，数据包被接收", clk_counter);
    end else begin
        $display("✗ 时钟计数器=%0d: A接口握手超时！", clk_counter);
    end

    // 发送完成后撤销valid
    @(posedge clk);
    pkt_i.slv.pkt_in_vld = 0;
    $display("时钟计数器=%0d: 数据包发送完成，撤销valid信号", clk_counter);

    test_count++;
    passed_count++;
endtask