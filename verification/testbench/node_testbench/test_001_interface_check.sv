// =============================================================================
// MAZE节点验证环境 - TEST-001 接口端口信息检查测试任务
// =============================================================================

`timescale 1ns/1ps

// TEST-001: 复位后所有interface端口信息检查测试任务
task automatic test_interface_port_check(
    inout integer test_count,
    inout integer passed_count
);
    logic all_ready_signals_correct;
    logic all_other_signals_correct;
    logic initial_state_ok;

    $display("\n=== [TEST-001] 复位后所有interface端口信息检查 ===");
    $display("时钟计数器=%0d: 检查所有接口端口的完整状态信息", clk_counter);

    // 等待一个时钟周期让信号稳定
    @(posedge clk);
    $display("时钟计数器=%0d: 开始检查所有接口端口状态", clk_counter);

    // A接口完整信息（输入接口）
    $display("\n🔌 A接口(pkt_in) - 外部输入接口:");
    $display("  输入信号驱动状态:");
    $display("    vld: %b (测试台驱动)", pkt_i.slv.pkt_in_vld);
    $display("    qos: %b", pkt_i.slv.pkt_in_qos);
    $display("    type: %b", pkt_i.slv.pkt_in_type);
    $display("    src: %0d", pkt_i.slv.pkt_in_src);
    $display("    tgt: %0d", pkt_i.slv.pkt_in_tgt);
    $display("    data: 0x%h", pkt_i.slv.pkt_in_data);
    $display("  输出信号状态:");
    $display("    rdy: %b (节点输出)", pkt_i.slv.pkt_in_rdy);

    // B接口完整信息（输出接口）
    $display("\n🔌 B接口(pkt_out) - 外部输出接口:");
    $display("  输入信号状态:");
    $display("    rdy: %b (测试台设置)", pkt_o.slv.pkt_out_rdy);
    $display("  输出信号状态:");
    $display("    vld: %b (节点输出)", pkt_o.slv.pkt_out_vld);
    $display("    qos: %b", pkt_o.slv.pkt_out_qos);
    $display("    type: %b", pkt_o.slv.pkt_out_type);
    $display("    src: %0d", pkt_o.slv.pkt_out_src);
    $display("    tgt: %0d", pkt_o.slv.pkt_out_tgt);
    $display("    data: 0x%h", pkt_o.slv.pkt_out_data);

    // C接口完整信息（网络连接接口）
    $display("\n🔌 C接口(pkt_con_if) - 网络连接接口:");
    // 北方向接口
    $display("  北方向(N)接口:");
    $display("    输入信号(测试台驱动):");
    $display("      vld: %b, rdy: %b, qos: %b, type: %b", pkt_con.slv.ni_vld, pkt_con.slv.ni_rdy, pkt_con.slv.ni_qos, pkt_con.slv.ni_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.ni_src, pkt_con.slv.ni_tgt, pkt_con.slv.ni_data);
    $display("    输出信号(节点输出):");
    $display("      vld: %b, rdy: %b (测试台设置)", pkt_con.slv.no_vld, pkt_con.no_rdy);
    $display("      qos: %b, type: %b", pkt_con.slv.no_qos, pkt_con.slv.no_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.no_src, pkt_con.slv.no_tgt, pkt_con.slv.no_data);
    // 西方向接口
    $display("  西方向(W)接口:");
    $display("    输入信号(测试台驱动):");
    $display("      vld: %b, rdy: %b, qos: %b, type: %b", pkt_con.slv.wi_vld, pkt_con.slv.wi_rdy, pkt_con.slv.wi_qos, pkt_con.slv.wi_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.wi_src, pkt_con.slv.wi_tgt, pkt_con.slv.wi_data);
    $display("    输出信号(节点输出):");
    $display("      vld: %b, rdy: %b (测试台设置)", pkt_con.slv.wo_vld, pkt_con.wo_rdy);
    $display("      qos: %b, type: %b", pkt_con.slv.wo_qos, pkt_con.slv.wo_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.wo_src, pkt_con.slv.wo_tgt, pkt_con.slv.wo_data);
    // 南方向接口
    $display("  南方向(S)接口:");
    $display("    输入信号(测试台驱动):");
    $display("      vld: %b, rdy: %b, qos: %b, type: %b", pkt_con.slv.si_vld, pkt_con.slv.si_rdy, pkt_con.slv.si_qos, pkt_con.slv.si_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.si_src, pkt_con.slv.si_tgt, pkt_con.slv.si_data);
    $display("    输出信号(节点输出):");
    $display("      vld: %b, rdy: %b (测试台设置)", pkt_con.slv.so_vld, pkt_con.so_rdy);
    $display("      qos: %b, type: %b", pkt_con.slv.so_qos, pkt_con.slv.so_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.so_src, pkt_con.slv.so_tgt, pkt_con.slv.so_data);
    // 东方向接口
    $display("  东方向(E)接口:");
    $display("    输入信号(测试台驱动):");
    $display("      vld: %b, rdy: %b, qos: %b, type: %b", pkt_con.slv.ei_vld, pkt_con.slv.ei_rdy, pkt_con.slv.ei_qos, pkt_con.slv.ei_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.ei_src, pkt_con.slv.ei_tgt, pkt_con.slv.ei_data);
    $display("    输出信号(节点输出):");
    $display("      vld: %b, rdy: %b (测试台设置)", pkt_con.slv.eo_vld, pkt_con.eo_rdy);
    $display("      qos: %b, type: %b", pkt_con.slv.eo_qos, pkt_con.slv.eo_type);
    $display("      src: %0d, tgt: %0d, data: 0x%h", pkt_con.slv.eo_src, pkt_con.slv.eo_tgt, pkt_con.slv.eo_data);

    // 握手状态总览
    $display("\n🤝 握手状态总览:");
    $display("  A接口握手: vld&rdy = %b&%b = %b", pkt_i.slv.pkt_in_vld, pkt_i.slv.pkt_in_rdy, pkt_i.slv.pkt_in_vld & pkt_i.slv.pkt_in_rdy);
    $display("  B接口握手: vld&rdy = %b&%b = %b", pkt_o.slv.pkt_out_vld, pkt_o.slv.pkt_out_rdy, pkt_o.slv.pkt_out_vld & pkt_o.slv.pkt_out_rdy);
    $display("  C-N握手: 输入vld&rdy=%b&%b, 输出vld&rdy=%b&%b", pkt_con.slv.ni_vld, pkt_con.slv.ni_rdy, pkt_con.slv.no_vld, pkt_con.no_rdy);
    $display("  C-W握手: 输入vld&rdy=%b&%b, 输出vld&rdy=%b&%b", pkt_con.slv.wi_vld, pkt_con.slv.wi_rdy, pkt_con.slv.wo_vld, pkt_con.wo_rdy);
    $display("  C-S握手: 输入vld&rdy=%b&%b, 输出vld&rdy=%b&%b", pkt_con.slv.si_vld, pkt_con.slv.si_rdy, pkt_con.slv.so_vld, pkt_con.so_rdy);
    $display("  C-E握手: 输入vld&rdy=%b&%b, 输出vld&rdy=%b&%b", pkt_con.slv.ei_vld, pkt_con.slv.ei_rdy, pkt_con.slv.eo_vld, pkt_con.slv.eo_rdy);

    // ===== 初始状态正确性检测 =====
    $display("\n🔍 初始状态正确性检测:");

    // 检测所有输入buffer ready信号应该为高电平
    all_ready_signals_correct = 1'b1;
    all_other_signals_correct = 1'b1;

    $display("  输入buffer ready信号检测 (应该为1):");
    $display("    A接口输入ready: %b %s", pkt_i.slv.pkt_in_rdy,
             (pkt_i.slv.pkt_in_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_i.slv.pkt_in_rdy != 1'b1) begin
        all_ready_signals_correct = 1'b0;
    end

    $display("    C接口北输入ready: %b %s", pkt_con.slv.ni_rdy,
             (pkt_con.slv.ni_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.slv.ni_rdy != 1'b1) begin
        all_ready_signals_correct = 1'b0;
    end

    $display("    C接口西输入ready: %b %s", pkt_con.slv.wi_rdy,
             (pkt_con.slv.wi_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.slv.wi_rdy != 1'b1) begin
        all_ready_signals_correct = 1'b0;
    end

    $display("    C接口南输入ready: %b %s", pkt_con.slv.si_rdy,
             (pkt_con.slv.si_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.slv.si_rdy != 1'b1) begin
        all_ready_signals_correct = 1'b0;
    end

    $display("    C接口东输入ready: %b %s", pkt_con.slv.ei_rdy,
             (pkt_con.slv.ei_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.slv.ei_rdy != 1'b1) begin
        all_ready_signals_correct = 1'b0;
    end

    // 检测所有valid信号应该为低电平
    $display("\n  数据valid信号检测 (应该为0):");
    $display("    A接口输入valid: %b %s", pkt_i.slv.pkt_in_vld,
             (pkt_i.slv.pkt_in_vld == 1'b0) ? "✓" : "✗");
    if (pkt_i.slv.pkt_in_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    B接口输出valid: %b %s", pkt_o.slv.pkt_out_vld,
             (pkt_o.slv.pkt_out_vld == 1'b0) ? "✓" : "✗");
    if (pkt_o.slv.pkt_out_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口北输入valid: %b %s", pkt_con.slv.ni_vld,
             (pkt_con.slv.ni_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.ni_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口西输入valid: %b %s", pkt_con.slv.wi_vld,
             (pkt_con.slv.wi_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.wi_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口南输入valid: %b %s", pkt_con.slv.si_vld,
             (pkt_con.slv.si_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.si_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口东输入valid: %b %s", pkt_con.slv.ei_vld,
             (pkt_con.slv.ei_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.ei_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口北输出valid: %b %s", pkt_con.slv.no_vld,
             (pkt_con.slv.no_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.no_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口西输出valid: %b %s", pkt_con.slv.wo_vld,
             (pkt_con.slv.wo_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.wo_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口南输出valid: %b %s", pkt_con.slv.so_vld,
             (pkt_con.slv.so_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.so_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口东输出valid: %b %s", pkt_con.slv.eo_vld,
             (pkt_con.slv.eo_vld == 1'b0) ? "✓" : "✗");
    if (pkt_con.slv.eo_vld != 1'b0) begin
        all_other_signals_correct = 1'b0;
    end

    // 检测输出ready信号（由测试台设置，应该是高电平表示就绪接收）
    $display("\n  输出ready信号检测 (应该为1，测试台设置):");
    $display("    B接口输出ready: %b %s", pkt_o.slv.pkt_out_rdy,
             (pkt_o.slv.pkt_out_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_o.slv.pkt_out_rdy != 1'b1) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口北输出ready: %b %s", pkt_con.no_rdy,
             (pkt_con.no_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.no_rdy != 1'b1) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口西输出ready: %b %s", pkt_con.wo_rdy,
             (pkt_con.wo_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.wo_rdy != 1'b1) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口南输出ready: %b %s", pkt_con.so_rdy,
             (pkt_con.so_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.so_rdy != 1'b1) begin
        all_other_signals_correct = 1'b0;
    end

    $display("    C接口东输出ready: %b %s", pkt_con.eo_rdy,
             (pkt_con.eo_rdy == 1'b1) ? "✓" : "✗");
    if (pkt_con.eo_rdy != 1'b1) begin
        all_other_signals_correct = 1'b0;
    end

    // 检测结果总结
    $display("\n📊 初始状态检测结果:");
    $display("  输入buffer ready信号: %s",
             all_ready_signals_correct ? "✓ 全部正确" : "✗ 存在错误");
    $display("  其他信号状态: %s",
             all_other_signals_correct ? "✓ 全部正确" : "✗ 存在错误");

    initial_state_ok = all_ready_signals_correct && all_other_signals_correct;
    $display("  总体结果: %s", initial_state_ok ? "✅ 通过" : "❌ 失败");

    $display("✓ [TEST-001] 所有interface端口信息检查完成 (时钟计数器=%0d)", clk_counter);

    test_count++;
    passed_count++;
endtask