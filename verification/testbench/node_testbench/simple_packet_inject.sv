// =============================================================================
// MAZE节点验证环境 - 简单数据包注入任务
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

// 向指定端口注入数据包的简单任务
task automatic inject_packet(
    input packet_port_t port,
    input logic [22:0] packet_data
);

    $display("时钟计数器=%0d: 向端口 %s 注入包: data=0x%h", clk_counter, port.name(), packet_data);

    case (port)
        PORT_A: begin
            @(posedge clk);
            pkt_i.pkt_in_vld = 1'b1;
            pkt_i.pkt_in_type = packet_data[22:21];  // 固定type=00
            pkt_i.pkt_in_qos = packet_data[20];
            pkt_i.pkt_in_src = packet_data[19:14];
            pkt_i.pkt_in_tgt = packet_data[13:8];
            pkt_i.pkt_in_data = packet_data[7:0];

            // 等待握手完成（rdy拉高一拍后拉低vld）
            @(posedge clk);
            while (!pkt_i.pkt_in_rdy) begin
                @(posedge clk);
            end
            @(posedge clk);
            pkt_i.pkt_in_vld = 1'b0;
        end

        PORT_N: begin
            @(posedge clk);
            pkt_con.ni_vld = 1'b1;
            pkt_con.ni_type = packet_data[22:21];
            pkt_con.ni_qos = packet_data[20];
            pkt_con.ni_src = packet_data[19:14];
            pkt_con.ni_tgt = packet_data[13:8];
            pkt_con.ni_data = packet_data[7:0];

            @(posedge clk);
            while (!pkt_con.ni_rdy) begin
                @(posedge clk);
            end
            @(posedge clk);
            pkt_con.ni_vld = 1'b0;
        end

        PORT_W: begin
            @(posedge clk);
            pkt_con.wi_vld = 1'b1;
            pkt_con.wi_type = packet_data[22:21];
            pkt_con.wi_qos = packet_data[20];
            pkt_con.wi_src = packet_data[19:14];
            pkt_con.wi_tgt = packet_data[13:8];
            pkt_con.wi_data = packet_data[7:0];

            @(posedge clk);
            while (!pkt_con.wi_rdy) begin
                @(posedge clk);
            end
            @(posedge clk);
            pkt_con.wi_vld = 1'b0;
        end

        PORT_S: begin
            @(posedge clk);
            pkt_con.si_vld = 1'b1;
            pkt_con.si_type = packet_data[22:21];
            pkt_con.si_qos = packet_data[20];
            pkt_con.si_src = packet_data[19:14];
            pkt_con.si_tgt = packet_data[13:8];
            pkt_con.si_data = packet_data[7:0];

            @(posedge clk);
            while (!pkt_con.si_rdy) begin
                @(posedge clk);
            end
            @(posedge clk);
            pkt_con.si_vld = 1'b0;
        end

        PORT_E: begin
            @(posedge clk);
            pkt_con.ei_vld = 1'b1;
            pkt_con.ei_type = packet_data[22:21];
            pkt_con.ei_qos = packet_data[20];
            pkt_con.ei_src = packet_data[19:14];
            pkt_con.ei_tgt = packet_data[13:8];
            pkt_con.ei_data = packet_data[7:0];

            @(posedge clk);
            while (!pkt_con.ei_rdy) begin
                @(posedge clk);
            end
            @(posedge clk);
            pkt_con.ei_vld = 1'b0;
        end

        default: $display("时钟计数器=%0d: 错误: 未知端口类型 %s", clk_counter, port.name());
    endcase

    $display("时钟计数器=%0d: 端口 %s 数据包注入完成", clk_counter, port.name());
endtask

// 随机数据包注入任务
task automatic rand_packet_inject(
    input packet_port_t port,
    input integer delay_cycles = 0
);
    logic [22:0] random_packet;

    // 等待指定的延迟周期
    if (delay_cycles > 0) begin
        repeat(delay_cycles) @(posedge clk);
    end

    // 生成随机数据包（type固定为00，其他随机）
    random_packet = {2'b00, $urandom_range(0, 1), $urandom_range(0, 63), $urandom_range(0, 63), $urandom_range(0, 255)};

    inject_packet(port, random_packet);
endtask