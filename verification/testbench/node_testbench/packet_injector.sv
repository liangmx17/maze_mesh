// =============================================================================
// MAZE节点验证环境 - 包注入器
// =============================================================================
// 功能：提供5个方向的包注入接口，支持各种包类型和QoS级别

`timescale 1ns/1ps

class PacketInjector;
    // 事件系统
    event packet_injected[5];  // 0=N, 1=W, 2=S, 3=E, 4=A(B)端口注入事件

    // 统计信息
    integer injection_count[5];
    integer injection_success[5];
    integer injection_failures[5];

    // 虚拟接口
    virtual pkt_in pkt_i;
    virtual pkt_con_if pkt_con_in;

    function new(virtual pkt_in pkt_i_intf, virtual pkt_con_if pkt_con_intf);
        this.pkt_i = pkt_i_intf;
        this.pkt_con_in = pkt_con_intf;

        // 初始化统计
        for (integer i = 0; i < 5; i++) begin
            injection_count[i] = 0;
            injection_success[i] = 0;
            injection_failures[i] = 0;
        end

        $display("[PacketInjector] 包注入器初始化完成");
    endfunction

    // A端口（外部）包注入
    task automatic inject_packet_A(
        input [1:0] pkt_type,     // 包类型：00单播，01列多播，10行多播，11广播
        input pkt_qos,           // QoS优先级：0低，1高
        input [5:0] src_id,      // 源节点ID
        input [5:0] tgt_id,      // 目标节点ID
        input [7:0] data,        // 数据载荷
        input integer timeout    // 超时周期（默认100）
    );
        injection_count[4]++;

        $display("[PacketInjector] A端口注入包: 类型=%b, QoS=%b, 源=%h, 目标=%h, 数据=%h",
                 pkt_type, pkt_qos, src_id, tgt_id, data);

        // 等待ready信号
        fork
            begin
                integer timeout_count = 0;
                while (!pkt_i.pkt_in_rdy && timeout_count < timeout) begin
                    #1;
                    timeout_count++;
                end

                if (pkt_i.pkt_in_rdy) begin
                    // 注入数据包
                    pkt_i.pkt_in_vld <= 1'b1;
                    pkt_i.pkt_in_type <= pkt_type;
                    pkt_i.pkt_in_qos <= pkt_qos;
                    pkt_i.pkt_in_src <= src_id;
                    pkt_i.pkt_in_tgt <= tgt_id;
                    pkt_i.pkt_in_data <= data;

                    #1;
                    pkt_i.pkt_in_vld <= 1'b0;

                    injection_success[4]++;
                    ->packet_injected[4];
                    $display("[PacketInjector] ✓ A端口包注入成功");
                end else begin
                    injection_failures[4]++;
                    $display("[PacketInjector] ✗ A端口包注入超时失败");
                end
            end
        join_none
    endtask

    // 北方向包注入
    task automatic inject_packet_N(
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id,
        input [7:0] data, input integer timeout
    );
        inject_packet_direction(0, "北", pkt_type, pkt_qos, src_id, tgt_id, data, timeout);
    endtask

    // 西方向包注入
    task automatic inject_packet_W(
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id,
        input [7:0] data, input integer timeout
    );
        inject_packet_direction(1, "西", pkt_type, pkt_qos, src_id, tgt_id, data, timeout);
    endtask

    // 南方向包注入
    task automatic inject_packet_S(
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id,
        input [7:0] data, input integer timeout
    );
        inject_packet_direction(2, "南", pkt_type, pkt_qos, src_id, tgt_id, data, timeout);
    endtask

    // 东方向包注入
    task automatic inject_packet_E(
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id,
        input [7:0] data, input integer timeout
    );
        inject_packet_direction(3, "东", pkt_type, pkt_qos, src_id, tgt_id, data, timeout);
    endtask

    // 通用方向包注入
    task automatic inject_packet_direction(
        input integer direction,    // 0=N, 1=W, 2=S, 3=E
        input string dir_name,      // 方向名称
        input [1:0] pkt_type, input pkt_qos, input [5:0] src_id, input [5:0] tgt_id,
        input [7:0] data, input integer timeout
    );
        injection_count[direction]++;

        $display("[PacketInjector] %s端口注入包: 类型=%b, QoS=%b, 源=%h, 目标=%h, 数据=%h",
                 dir_name, pkt_type, pkt_qos, src_id, tgt_id, data);

        // 等待对应方向的ready信号
        fork
            begin
                integer timeout_count = 0;
                logic ready_signal;

                // 根据方向选择ready信号
                case (direction)
                    0: ready_signal = pkt_con_in.pkt_in_N_rdy;
                    1: ready_signal = pkt_con_in.pkt_in_W_rdy;
                    2: ready_signal = pkt_con_in.pkt_in_S_rdy;
                    3: ready_signal = pkt_con_in.pkt_in_E_rdy;
                    default: ready_signal = 0;
                endcase

                while (!ready_signal && timeout_count < timeout) begin
                    #1;
                    // 重新读取ready信号
                    case (direction)
                        0: ready_signal = pkt_con_in.pkt_in_N_rdy;
                        1: ready_signal = pkt_con_in.pkt_in_W_rdy;
                        2: ready_signal = pkt_con_in.pkt_in_S_rdy;
                        3: ready_signal = pkt_con_in.pkt_in_E_rdy;
                    endcase
                    timeout_count++;
                end

                if (ready_signal) begin
                    // 注入数据包到对应方向
                    case (direction)
                        0: begin // 北
                            pkt_con_in.pkt_in_N_vld <= 1'b1;
                            pkt_con_in.pkt_in_N_type <= pkt_type;
                            pkt_con_in.pkt_in_N_qos <= pkt_qos;
                            pkt_con_in.pkt_in_N_src <= src_id;
                            pkt_con_in.pkt_in_N_tgt <= tgt_id;
                            pkt_con_in.pkt_in_N_data <= data;
                        end
                        1: begin // 西
                            pkt_con_in.pkt_in_W_vld <= 1'b1;
                            pkt_con_in.pkt_in_W_type <= pkt_type;
                            pkt_con_in.pkt_in_W_qos <= pkt_qos;
                            pkt_con_in.pkt_in_W_src <= src_id;
                            pkt_con_in.pkt_in_W_tgt <= tgt_id;
                            pkt_con_in.pkt_in_W_data <= data;
                        end
                        2: begin // 南
                            pkt_con_in.pkt_in_S_vld <= 1'b1;
                            pkt_con_in.pkt_in_S_type <= pkt_type;
                            pkt_con_in.pkt_in_S_qos <= pkt_qos;
                            pkt_con_in.pkt_in_S_src <= src_id;
                            pkt_con_in.pkt_in_S_tgt <= tgt_id;
                            pkt_con_in.pkt_in_S_data <= data;
                        end
                        3: begin // 东
                            pkt_con_in.pkt_in_E_vld <= 1'b1;
                            pkt_con_in.pkt_in_E_type <= pkt_type;
                            pkt_con_in.pkt_in_E_qos <= pkt_qos;
                            pkt_con_in.pkt_in_E_src <= src_id;
                            pkt_con_in.pkt_in_E_tgt <= tgt_id;
                            pkt_con_in.pkt_in_E_data <= data;
                        end
                    endcase

                    #1;
                    // 清除valid信号
                    case (direction)
                        0: pkt_con_in.pkt_in_N_vld <= 1'b0;
                        1: pkt_con_in.pkt_in_W_vld <= 1'b0;
                        2: pkt_con_in.pkt_in_S_vld <= 1'b0;
                        3: pkt_con_in.pkt_in_E_vld <= 1'b0;
                    endcase

                    injection_success[direction]++;
                    ->packet_injected[direction];
                    $display("[PacketInjector] ✓ %s端口包注入成功", dir_name);
                end else begin
                    injection_failures[direction]++;
                    $display("[PacketInjector] ✗ %s端口包注入超时失败", dir_name);
                end
            end
        join_none
    endtask

    // 打印统计信息
    function void print_statistics();
        $display("=== 包注入器统计信息 ===");
        $display("端口  注入次数  成功次数  失败次数");
        $display("北    %0d        %0d        %0d", injection_count[0], injection_success[0], injection_failures[0]);
        $display("西    %0d        %0d        %0d", injection_count[1], injection_success[1], injection_failures[1]);
        $display("南    %0d        %0d        %0d", injection_count[2], injection_success[2], injection_failures[2]);
        $display("东    %0d        %0d        %0d", injection_count[3], injection_success[3], injection_failures[3]);
        $display("A    %0d        %0d        %0d", injection_count[4], injection_success[4], injection_failures[4]);
    endfunction

endclass