// =============================================================================
// MAZE节点验证环境 - TEST-000 复位时序等待测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-000: 复位时序等待测试任务
task automatic test_reset_sequence_timing(
    inout integer test_count,
    inout integer passed_count
);
    $display("\n=== [TEST-000] 复位时序等待测试 ===");
    $display("时钟计数器=%0d: 等待C++控制复位时序", clk_counter);
    $display("当前rst_n=%b", rst_n);

    // 等待复位开始（等待rst_n变低）
    wait(rst_n == 0);
    $display("时钟计数器=%0d: 检测到复位开始 rst_n=%b", clk_counter, rst_n);

    // 等待复位结束（等待rst_n变高）
    wait(rst_n == 1);
    $display("时钟计数器=%0d: 检测到复位结束 rst_n=%b", clk_counter, rst_n);

    // 等待2个时钟周期让信号稳定
    repeat(2) @(posedge clk);
    $display("✓ [TEST-000] 复位时序等待测试完成 (时钟计数器=%0d)", clk_counter);

    test_count++;
    passed_count++;
endtask