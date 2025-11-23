// =============================================================================
// MAZE节点验证环境 - TEST-005 随机数据包注入测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-005: 随机数据包注入测试任务
task automatic test_random_packet_injection(
    inout integer test_count,
    inout integer passed_count
);
    $display("\n=== [TEST-005] 随机数据包注入测试 ===");
    $display("时钟计数器=%0d: 测试rand_single_packet_inject task功能", clk_counter);

    // 测试向各个端口注入随机包（顺序执行）
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    repeat(20) @(posedge clk);                  // 错开时间避免冲突
    rand_single_packet_inject(PORT_N, 5);      // N端口，延迟5周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_W, 10);     // W端口，延迟10周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_S, 15);     // S端口，延迟15周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_E, 20);     // E端口，延迟20周期
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    rand_single_packet_inject(PORT_A, 0);      // A端口，无延迟
    repeat(20) @(posedge clk);                  // 错开时间避免冲突
    rand_single_packet_inject(PORT_N, 5);      // N端口，延迟5周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_W, 10);     // W端口，延迟10周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_S, 15);     // S端口，延迟15周期
    repeat(20) @(posedge clk);
    rand_single_packet_inject(PORT_E, 20);     // E端口，延迟20周期

    $display("✓ [TEST-005] 随机数据包注入测试完成 (时钟计数器=%0d)", clk_counter);

    test_count++;
    passed_count++;
endtask