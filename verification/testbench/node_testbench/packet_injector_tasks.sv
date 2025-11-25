// =============================================================================
// MAZE节点验证环境 - 数据包注入任务库
// =============================================================================
// 功能：提供可复用的数据包注入任务集合
// 作者：Claude Code Assistant
// =============================================================================

`timescale 1ns/1ps

// 端口类型定义
typedef enum logic [2:0] {
    PORT_A = 3'd0,   // A端口（外部输入）
    PORT_N = 3'd1,   // N端口（北输出）
    PORT_W = 3'd2,   // W端口（西输出）
    PORT_S = 3'd3,   // S端口（南输出）
    PORT_E = 3'd4,   // E端口（东输出）
    PORT_B = 3'd5    // B端口（外部输出）
} packet_port_t;

// =============================================================================
// 数据包注入任务模块
// =============================================================================

// 向指定端口注入随机数据包的主任务
task automatic rand_single_packet_inject(
    input packet_port_t port,
    input integer inject_delay_cycles = 0
);
    logic [1:0] packet_type;
    logic packet_qos;
    logic [5:0] packet_src;
    logic [5:0] packet_tgt;
    logic [7:0] packet_data_field;

    $display("时钟计数器=%0d: 开始随机数据包注入到端口 %s，延迟 %0d 个周期",
             clk_counter, port.name(), inject_delay_cycles);

    // 等待指定的延迟周期
    if (inject_delay_cycles > 0) begin
        repeat(inject_delay_cycles) @(posedge clk);
    end

    // 生成随机数据包 (type=00)
    packet_type = 2'b00;
    packet_qos = $urandom_range(0, 1);
    packet_src = $urandom_range(0, 63);
    packet_tgt = $urandom_range(0, 63);
    packet_data_field = $urandom_range(0, 255);

    $display("时钟计数器=%0d: 生成随机包: type=%b, qos=%b, src=%h, tgt=%h, data=%h",
             clk_counter, packet_type, packet_qos, packet_src, packet_tgt, packet_data_field);

    // 调用通用的数据包注入任务
    inject_packet_to_port(port, packet_type, packet_qos, packet_src, packet_tgt, packet_data_field);
endtask

// 向指定端口注入数据包的通用任务
task automatic inject_packet_to_port(
    input packet_port_t port,
    input [1:0] packet_type,
    input logic packet_qos,
    input [5:0] packet_src,
    input [5:0] packet_tgt,
    input [7:0] packet_data_field
);
    logic injection_complete;


    injection_complete = 0;

    // 等待时钟上升沿
    @(posedge clk);

    // 驱动对应端口的信号
    case (port)
        PORT_A: begin
            pkt_i.slv.pkt_in_vld = 1'b1;
            pkt_i.slv.pkt_in_type = packet_type;
            pkt_i.slv.pkt_in_qos = packet_qos;
            pkt_i.slv.pkt_in_src = packet_src;
            pkt_i.slv.pkt_in_tgt = packet_tgt;
            pkt_i.slv.pkt_in_data = packet_data_field;
        end

        PORT_N: begin
            pkt_con.slv.ni_vld = 1'b1;
            pkt_con.slv.ni_type = packet_type;
            pkt_con.slv.ni_qos = packet_qos;
            pkt_con.slv.ni_src = packet_src;
            pkt_con.slv.ni_tgt = packet_tgt;
            pkt_con.slv.ni_data = packet_data_field;
        end

        PORT_W: begin
            pkt_con.slv.wi_vld = 1'b1;
            pkt_con.slv.wi_type = packet_type;
            pkt_con.slv.wi_qos = packet_qos;
            pkt_con.slv.wi_src = packet_src;
            pkt_con.slv.wi_tgt = packet_tgt;
            pkt_con.slv.wi_data = packet_data_field;
        end

        PORT_S: begin
            pkt_con.slv.si_vld = 1'b1;
            pkt_con.slv.si_type = packet_type;
            pkt_con.slv.si_qos = packet_qos;
            pkt_con.slv.si_src = packet_src;
            pkt_con.slv.si_tgt = packet_tgt;
            pkt_con.slv.si_data = packet_data_field;
        end

        PORT_E: begin
            pkt_con.slv.ei_vld = 1'b1;
            pkt_con.slv.ei_type = packet_type;
            pkt_con.slv.ei_qos = packet_qos;
            pkt_con.slv.ei_src = packet_src;
            pkt_con.slv.ei_tgt = packet_tgt;
            pkt_con.slv.ei_data = packet_data_field;
        end

        default: $display("时钟计数器=%0d: 错误: 未知端口类型 %s", clk_counter, port.name());
    endcase
    $display("时钟计数器=%0d: 向端口 %s 注入包: qos=%b, src=%h, tgt=%h, data=%h",
             clk_counter, port.name(), packet_qos, packet_src, packet_tgt, packet_data_field);

    // 等待对应握手完成
    case (port)
        PORT_A: begin
            wait(pkt_i.slv.pkt_in_vld && pkt_i.slv.pkt_in_rdy);
            @(posedge clk);
            pkt_i.slv.pkt_in_vld = 1'b0;
        end

        PORT_N: begin
            wait(pkt_con.slv.ni_vld && pkt_con.slv.ni_rdy);
            @(posedge clk);
            pkt_con.slv.ni_vld = 1'b0;
        end

        PORT_W: begin
            wait(pkt_con.slv.wi_vld && pkt_con.slv.wi_rdy);
            @(posedge clk);
            pkt_con.slv.wi_vld = 1'b0;
        end

        PORT_S: begin
            wait(pkt_con.slv.si_vld && pkt_con.slv.si_rdy);
            @(posedge clk);
            pkt_con.slv.si_vld = 1'b0;
        end

        PORT_E: begin
            wait(pkt_con.slv.ei_vld && pkt_con.slv.ei_rdy);
            @(posedge clk);
            pkt_con.slv.ei_vld = 1'b0;
        end
    endcase

    injection_complete = 1;
    $display("时钟计数器=%0d: 端口 %s 数据包注入完成", clk_counter, port.name());
endtask