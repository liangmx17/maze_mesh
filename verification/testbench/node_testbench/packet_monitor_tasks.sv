// =============================================================================
// MAZE节点验证环境 - 数据包监控任务库
// =============================================================================
// 功能：提供数据包接收监控和打印功能
// 设计：通过fork启动全程监控，使用时钟沿同步和边沿检测
// =============================================================================

`timescale 1ns/1ps

// 注意：packet_port_t枚举已在packet_injector_tasks.sv中定义

// =============================================================================
// 全程数据包监控任务
// =============================================================================

// 全程数据包监控任务（通过fork启动）
task automatic packet_monitor();
    integer b_vld_prev = 0, n_vld_prev = 0, w_vld_prev = 0, s_vld_prev = 0, e_vld_prev = 0;
    logic [22:0] captured_packet;
    integer b_count = 0, n_count = 0, w_count = 0, s_count = 0, e_count = 0;

    $display("时钟计数器=%0d: 启动全程数据包监控", clk_counter);
    $display("监控端口: PORT_B (外部输出), PORT_N (北), PORT_W (西), PORT_S (南), PORT_E (东)");
    $display("========================================");

    while (1) begin
        @(posedge clk);  // 使用时钟沿同步

        // 检查B端口 (边沿检测，避免重复打印)
        if (pkt_o.slv.pkt_out_vld && pkt_o.slv.pkt_out_rdy && !b_vld_prev) begin
            captured_packet = {pkt_o.slv.pkt_out_type, pkt_o.slv.pkt_out_qos,
                              pkt_o.slv.pkt_out_src, pkt_o.slv.pkt_out_tgt,
                              pkt_o.slv.pkt_out_data};
            print_packet_info(PORT_B, captured_packet);
            b_count++;
        end
        b_vld_prev = pkt_o.slv.pkt_out_vld && pkt_o.slv.pkt_out_rdy;

        // 检查N端口
        if (pkt_con.slv.no_vld && pkt_con.slv.no_rdy && !n_vld_prev) begin
            captured_packet = {pkt_con.slv.no_type, pkt_con.slv.no_qos,
                              pkt_con.slv.no_src, pkt_con.slv.no_tgt,
                              pkt_con.slv.no_data};
            print_packet_info(PORT_N, captured_packet);
            n_count++;
        end
        n_vld_prev = pkt_con.slv.no_vld && pkt_con.slv.no_rdy;

        // 检查W端口
        if (pkt_con.slv.wo_vld && pkt_con.slv.wo_rdy && !w_vld_prev) begin
            captured_packet = {pkt_con.slv.wo_type, pkt_con.slv.wo_qos,
                              pkt_con.slv.wo_src, pkt_con.slv.wo_tgt,
                              pkt_con.slv.wo_data};
            print_packet_info(PORT_W, captured_packet);
            w_count++;
        end
        w_vld_prev = pkt_con.slv.wo_vld && pkt_con.slv.wo_rdy;

        // 检查S端口
        if (pkt_con.slv.so_vld && pkt_con.slv.so_rdy && !s_vld_prev) begin
            captured_packet = {pkt_con.slv.so_type, pkt_con.slv.so_qos,
                              pkt_con.slv.so_src, pkt_con.slv.so_tgt,
                              pkt_con.slv.so_data};
            print_packet_info(PORT_S, captured_packet);
            s_count++;
        end
        s_vld_prev = pkt_con.slv.so_vld && pkt_con.slv.so_rdy;

        // 检查E端口
        if (pkt_con.slv.eo_vld && pkt_con.slv.eo_rdy && !e_vld_prev) begin
            captured_packet = {pkt_con.slv.eo_type, pkt_con.slv.eo_qos,
                              pkt_con.slv.eo_src, pkt_con.slv.eo_tgt,
                              pkt_con.slv.eo_data};
            print_packet_info(PORT_E, captured_packet);
            e_count++;
        end
        e_vld_prev = pkt_con.slv.eo_vld && pkt_con.slv.eo_rdy;

        // 每隔100个时钟周期打印统计信息（可选）
        // if ((clk_counter % 100) == 0 && clk_counter > 0) begin
        //     $display("时钟计数器=%0d: 监控统计 - B:%0d, N:%0d, W:%0d, S:%0d, E:%0d",
        //              clk_counter, b_count, n_count, w_count, s_count, e_count);
        // end
    end
endtask

// =============================================================================
// 数据包信息打印任务
// =============================================================================

// 打印数据包详细信息
task automatic print_packet_info(
    input packet_port_t port,
    input logic [22:0] packet_data
);
    logic [1:0] pkt_type = packet_data[22:21];
    logic pkt_qos = packet_data[20];
    logic [5:0] src_node = packet_data[19:14];
    logic [5:0] tgt_node = packet_data[13:8];
    logic [7:0] data = packet_data[7:0];
    string type_str, qos_str;

    // 类型转换
    case (pkt_type)
        2'b00: type_str = "单播";
        2'b01: type_str = "X多播";
        2'b10: type_str = "Y多播";
        2'b11: type_str = "广播";
        default: type_str = "未知";
    endcase

    qos_str = pkt_qos ? "高" : "低";

    $display("时钟计数器=%0d: 端口 %s 检测到数据包", clk_counter, port.name());
    $display("  类型: %s (2'b%b), QoS: %s优先级 (%b)", type_str, pkt_type, qos_str, pkt_qos);
    $display("  源节点: 0x%02h (%0d), 目标节点: 0x%02h (%0d)", src_node, src_node, tgt_node, tgt_node);
    $display("  数据: 0x%02h (%0d)", data, data);
    $display("  完整数据包: 23'b%b", packet_data);
    $display("------------------------------------------------");
endtask

// =============================================================================
// 辅助任务
// =============================================================================

// 打印监控摘要（可选调用）
task automatic print_monitor_summary(
    input integer b_count, input integer n_count, input integer w_count,
    input integer s_count, input integer e_count
);
    integer total_count = b_count + n_count + w_count + s_count + e_count;

    $display("========================================");
    $display("📊 数据包监控摘要报告");
    $display("========================================");
    $display("监控时长: %0d 个时钟周期", clk_counter);
    $display("总数据包数: %0d", total_count);
    $display("  PORT_B (外部输出): %0d 个数据包", b_count);
    $display("  PORT_N (北向): %0d 个数据包", n_count);
    $display("  PORT_W (西向): %0d 个数据包", w_count);
    $display("  PORT_S (南向): %0d 个数据包", s_count);
    $display("  PORT_E (东向): %0d 个数据包", e_count);
    $display("========================================");
endtask