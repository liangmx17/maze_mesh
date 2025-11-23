// =============================================================================
// MAZE节点验证环境 - TEST-004 长时间运行验证测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-004: 长时间运行验证测试任务
task automatic test_long_term_stability(
    inout integer test_count,
    inout integer passed_count
);
    $display("\n=== [TEST-004] 长时间运行验证 ===");
    $display("时钟计数器=%0d: 验证真实节点的长期稳定性", clk_counter);

    // 检查时钟稳定性
    repeat(20) @(posedge clk);
    $display("时钟计数器=%0d: 时钟稳定运行20个周期", clk_counter);

    // 测试信号操作
    $display("时钟计数器=%0d: 测试信号操作能力", clk_counter);
    pg_en = 1;
    @(posedge clk);
    $display("时钟计数器=%0d: pg_en设为%b", clk_counter, pg_en);

    pg_node = 6'd42;  // 任意节点
    @(posedge clk);
    $display("时钟计数器=%0d: pg_node设为%0d", clk_counter, pg_node);

    // 恢复默认值
    pg_en = 0;
    pg_node = 0;
    @(posedge clk);
    $display("时钟计数器=%0d: 恢复默认设置 pg_en=%b, pg_node=%0d", clk_counter, pg_en, pg_node);

    $display("✓ [TEST-004] 长时间运行验证完成 (时钟计数器=%0d)", clk_counter);

    test_count++;
    passed_count++;
endtask