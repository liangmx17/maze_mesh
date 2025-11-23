// =============================================================================
// MAZE节点验证环境 - 包监控器
// =============================================================================
// 功能：监控5个输出端口，提供包检测和验证功能

`timescale 1ns/1ps

// 输出包结构
typedef struct packed {
    logic valid;
    logic [1:0] pkt_type;
    logic pkt_qos;
    logic [5:0] src_id;
    logic [5:0] tgt_id;
    logic [7:0] data;
    logic [2:0] port_id;     // 0=N, 1=W, 2=S, 3=E, 4=B
    integer timestamp;
} packet_output_t;

class PacketMonitor;
    // 事件系统
    event packet_detected[5];  // 0=N, 1=W, 2=S, 3=E, 4=B端口包检测事件

    // 统计信息
    integer detection_count[5];
    packet_output_t last_packet[5];
    packet_output_t packet_history[5][100];  // 每个端口存储100个历史包
    integer history_index[5];

    // 虚拟接口
    virtual pkt_out pkt_o;
    virtual pkt_con_if pkt_con_out;

    function new(virtual pkt_out pkt_o_intf, virtual pkt_con_if pkt_con_intf);
        this.pkt_o = pkt_o_intf;
        this.pkt_con_out = pkt_con_intf;

        // 初始化统计
        for (integer i = 0; i < 5; i++) begin
            detection_count[i] = 0;
            last_packet[i] = '{default:0};
            history_index[i] = 0;
            for (integer j = 0; j < 100; j++) begin
                packet_history[i][j] = '{default:0};
            end
        end

        $display("[PacketMonitor] 包监控器初始化完成");
    endfunction

    // 启动监控
    task automatic start_monitoring();
        $display("[PacketMonitor] 启动输出端口监控...");

        // 监控B端口（外部输出）
        fork
            forever begin
                wait (pkt_o.pkt_out_vld && pkt_o.pkt_out_rdy);
                capture_packet(4, "B", pkt_o.pkt_out_type, pkt_o.pkt_out_qos,
                              pkt_o.pkt_out_src, pkt_o.pkt_out_tgt, pkt_o.pkt_out_data);
            end
        join_none

        // 监控四个方向输出
        fork
            forever begin
                wait (pkt_con_out.pkt_out_N_vld && pkt_con_out.pkt_out_N_rdy);
                capture_packet(0, "北", pkt_con_out.pkt_out_N_type, pkt_con_out.pkt_out_N_qos,
                              pkt_con_out.pkt_out_N_src, pkt_con_out.pkt_out_N_tgt, pkt_con_out.pkt_out_N_data);
            end
        join_none

        fork
            forever begin
                wait (pkt_con_out.pkt_out_W_vld && pkt_con_out.pkt_out_W_rdy);
                capture_packet(1, "西", pkt_con_out.pkt_out_W_type, pkt_con_out.pkt_out_W_qos,
                              pkt_con_out.pkt_out_W_src, pkt_con_out.pkt_out_W_tgt, pkt_con_out.pkt_out_W_data);
            end
        join_none

        fork
            forever begin
                wait (pkt_con_out.pkt_out_S_vld && pkt_con_out.pkt_out_S_rdy);
                capture_packet(2, "南", pkt_con_out.pkt_out_S_type, pkt_con_out.pkt_out_S_qos,
                              pkt_con_out.pkt_out_S_src, pkt_con_out.pkt_out_S_tgt, pkt_con_out.pkt_out_S_data);
            end
        join_none

        fork
            forever begin
                wait (pkt_con_out.pkt_out_E_vld && pkt_con_out.pkt_out_E_rdy);
                capture_packet(3, "东", pkt_con_out.pkt_out_E_type, pkt_con_out.pkt_out_E_qos,
                              pkt_con_out.pkt_out_E_src, pkt_con_out.pkt_out_E_tgt, pkt_con_out.pkt_out_E_data);
            end
        join_none
    endtask

    // 捕获数据包
    task automatic capture_packet(
        input integer port, input string port_name,
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id, input [7:0] data
    );
        detection_count[port]++;

        // 记录包信息
        last_packet[port] = '{
            valid: 1'b1,
            pkt_type: pkt_type,
            pkt_qos: pkt_qos,
            src_id: src_id,
            tgt_id: tgt_id,
            data: data,
            port_id: port[2:0],
            timestamp: $time
        };

        // 存储到历史记录
        packet_history[port][history_index[port]] = last_packet[port];
        history_index[port] = (history_index[port] + 1) % 100;

        $display("[PacketMonitor] 检测到%s端口输出包: 类型=%b, QoS=%b, 源=%h, 目标=%h, 数据=%h",
                 port_name, pkt_type, pkt_qos, src_id, tgt_id, data);

        // 触发检测事件
        ->packet_detected[port];
    endtask

    // 等待任意输出端口的数据包
    task automatic wait_for_output_packet(
        output packet_output_t detected_packet,
        input integer timeout
    );
        fork
            begin
                // 等待任意端口的包检测事件
                wait (
                    packet_detected[0].triggered ||
                    packet_detected[1].triggered ||
                    packet_detected[2].triggered ||
                    packet_detected[3].triggered ||
                    packet_detected[4].triggered
                );

                // 确定是哪个端口的包
                if (packet_detected[0].triggered) detected_packet = last_packet[0];
                else if (packet_detected[1].triggered) detected_packet = last_packet[1];
                else if (packet_detected[2].triggered) detected_packet = last_packet[2];
                else if (packet_detected[3].triggered) detected_packet = last_packet[3];
                else detected_packet = last_packet[4];

                $display("[PacketMonitor] 检测到端口%0d的输出包", detected_packet.port_id);
            end
            begin
                // 超时处理
                #timeout;
                detected_packet = '{default:0};
                $display("[PacketMonitor] 等待输出包超时");
            end
        join_any
        disable fork;
    endtask

    // 等待特定输出端口的数据包
    task automatic wait_for_specific_port(
        input integer expected_port, output packet_output_t detected_packet, input integer timeout
    );
        fork
            begin
                @(packet_detected[expected_port]);
                detected_packet = last_packet[expected_port];
                $display("[PacketMonitor] 检测到端口%0d的输出包", expected_port);
            end
            begin
                #timeout;
                detected_packet = '{default:0};
                $display("[PacketMonitor] 等待端口%0d输出包超时", expected_port);
            end
        join_any
        disable fork;
    endtask

    // 验证特定数据包的输出
    task automatic verify_packet_output(
        input [22:0] expected_packet,     // 期望的编码数据包
        input [2:0] expected_port,        // 期望的输出端口
        output logic verification_result,
        input integer timeout
    );
        packet_output_t detected_pkt;
        verification_result = 1'b0;

        $display("[PacketMonitor] 等待期望包: 端口=%0d, 数据=%h", expected_port, expected_packet);

        fork
            begin
                wait_for_specific_port(expected_port, detected_pkt, timeout);

                // 验证包内容
                if (detected_pkt.valid) begin
                    logic [22:0] actual_packet = encode_packet(
                        detected_pkt.pkt_type, detected_pkt.pkt_qos,
                        detected_pkt.src_id, detected_pkt.tgt_id, detected_pkt.data
                    );

                    if (actual_packet === expected_packet) begin
                        verification_result = 1'b1;
                        $display("[PacketMonitor] ✓ 包验证成功: 端口%0d, 数据=%h", expected_port, actual_packet);
                    end else begin
                        $display("[PacketMonitor] ✗ 包验证失败: 期望=%h, 实际=%h", expected_packet, actual_packet);
                    end
                end else begin
                    $display("[PacketMonitor] ✗ 未检测到有效的输出包");
                end
            end
            begin
                #timeout;
                $display("[PacketMonitor] ✗ 包验证超时");
                verification_result = 1'b0;
            end
        join_any
        disable fork;
    endtask

    // 编码数据包（辅助函数）
    function automatic logic [22:0] encode_packet(
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id, input [7:0] data
    );
        return {pkt_type, pkt_qos, src_id, tgt_id, data};
    endfunction

    // 打印最后输出
    function void print_last_outputs();
        $display("=== 最近输出包 ===");
        for (integer i = 0; i < 5; i++) begin
            string port_name = (i == 0) ? "北" : (i == 1) ? "西" : (i == 2) ? "南" : (i == 3) ? "东" : "B";
            if (last_packet[i].valid) begin
                $display("%s端口: 类型=%b, QoS=%b, 源=%h, 目标=%h, 数据=%h, 时间=%0t",
                         port_name, last_packet[i].pkt_type, last_packet[i].pkt_qos,
                         last_packet[i].src_id, last_packet[i].tgt_id, last_packet[i].data,
                         last_packet[i].timestamp);
            end else begin
                $display("%s端口: 无输出", port_name);
            end
        end
    endfunction

    // 打印统计信息
    function void print_statistics();
        $display("=== 包监控器统计信息 ===");
        $display("端口  检测次数");
        $display("北    %0d", detection_count[0]);
        $display("西    %0d", detection_count[1]);
        $display("南    %0d", detection_count[2]);
        $display("东    %0d", detection_count[3]);
        $display("B    %0d", detection_count[4]);
    endfunction

endclass