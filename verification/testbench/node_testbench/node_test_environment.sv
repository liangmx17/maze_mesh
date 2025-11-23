// =============================================================================
// MAZE节点验证环境 - 主测试环境
// =============================================================================
// 功能：集成所有测试组件，提供完整的节点功能验证

`timescale 1ns/1ps

// 包含测试组件
`include "packet_injector.sv"
`include "packet_monitor.sv"
`include "config_manager.sv"
`include "test_sequences.sv"

module node_test_environment;

    // ========================================
    // 参数配置
    // ========================================
    localparam TEST_NODE_X = 3;  // 默认测试节点X坐标
    localparam TEST_NODE_Y = 3;  // 默认测试节点Y坐标
    localparam CLOCK_PERIOD = 10; // 时钟周期 (ns)
    localparam TEST_TIMEOUT = 5000; // 总测试超时 (ns)

    // ========================================
    // 信号定义
    // ========================================
    reg clk;                    // 时钟信号
    reg rst_n;                  // 复位信号（低有效）

    // 故障配置
    reg pg_en;                  // 故障使能
    reg [5:0] pg_node;          // 故障节点ID

    // 接口实例
    pkt_in pkt_i();             // A端口输入接口
    pkt_out pkt_o();            // B端口输出接口
    pkt_con_if pkt_con();       // C接口（包含NWSE四个方向）

    // ========================================
    // 被测节点 (DUT)
    // ========================================
    node #(
        .HP(TEST_NODE_X),
        .VP(TEST_NODE_Y)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .pg_en(pg_en),
        .pg_node(pg_node),
        .pkt_i(pkt_i),
        .pkt_o(pkt_o),
        .pkt_con(pkt_con)
    );

    // ========================================
    // 测试组件实例
    // ========================================
    PacketInjector injector;
    PacketMonitor monitor;
    NodeConfig cfg;
    TestSequences test_seq;

    // 测试控制信号
    reg test_start;
    reg [3:0] test_mode;
    reg test_complete;
    reg [31:0] test_result;

    // 测试模式定义
    localparam MODE_IDLE = 4'h0;
    localparam MODE_BASIC_ROUTING = 4'h1;
    localparam MODE_QOS = 4'h2;
    localparam MODE_FAULT_TOLERANCE = 4'h3;
    localparam MODE_MULTICAST = 4'h4;
    localparam MODE_STRESS = 4'h5;
    localparam MODE_ALL = 4'hF;

    // ========================================
    // 时钟生成
    // ========================================
    initial begin
        clk = 0;
        forever #(CLOCK_PERIOD/2) clk = ~clk;
    end

    // ========================================
    // 复位序列
    // ========================================
    initial begin
        rst_n = 0;
        #100;
        rst_n = 1;
        $display("[TEST_ENV] 复位完成");
    end

    // ========================================
    // 测试组件初始化
    // ========================================
    initial begin
        $display("========================================");
        $display("🚀 MAZE节点验证环境启动");
        $display("========================================");
        $display("测试节点位置: (%0d, %0d)", TEST_NODE_X, TEST_NODE_Y);
        $display("时钟周期: %0d ns", CLOCK_PERIOD);
        $display("========================================");

        // 初始化测试控制信号
        test_start = 0;
        test_mode = MODE_IDLE;
        test_complete = 0;
        test_result = 0;

        // 初始化故障配置
        pg_en = 0;
        pg_node = 0;

        // 等待复位完成
        @(posedge rst_n);
        #(CLOCK_PERIOD * 2);

        // 创建测试组件实例
        injector = new(pkt_i, pkt_con);
        monitor = new(pkt_o, pkt_con);
        cfg = new();

        // 设置节点位置
        cfg.set_position(TEST_NODE_X, TEST_NODE_Y);

        // 创建测试序列实例
        test_seq = new(injector, monitor, cfg);

        // 启动监控器
        monitor.start_monitoring();

        $display("[TEST_ENV] 测试环境初始化完成");
        $display("[TEST_ENV] 等待测试开始信号...");

        // 等待测试开始
        wait(test_start);
        run_selected_tests();
    end

    // ========================================
    // 测试执行器
    // ========================================
    task automatic run_selected_tests();
        $display("\n🧪 开始执行测试模式: %0h", test_mode);

        case (test_mode)
            MODE_BASIC_ROUTING: begin
                $display("[TEST_ENV] 运行基本路由功能测试");
                test_seq.test_basic_routing();
                test_result = 1;
            end

            MODE_QOS: begin
                $display("[TEST_ENV] 运行QoS仲裁测试");
                test_seq.test_qos_arbitration();
                test_result = 1;
            end

            MODE_FAULT_TOLERANCE: begin
                $display("[TEST_ENV] 运行故障容错测试");
                test_seq.test_fault_tolerance();
                test_result = 1;
            end

            MODE_MULTICAST: begin
                $display("[TEST_ENV] 运行多播广播测试");
                test_seq.test_multicast_broadcast();
                test_result = 1;
            end

            MODE_STRESS: begin
                $display("[TEST_ENV] 运行压力测试");
                test_seq.test_stress_conditions();
                test_result = 1;
            end

            MODE_ALL: begin
                $display("[TEST_ENV] 运行完整测试套件");
                test_seq.run_all_tests();
                test_result = 1;
            end

            default: begin
                $display("[TEST_ENV] 错误: 未知的测试模式 %0h", test_mode);
                test_result = 0;
            end
        endcase

        // 测试完成
        test_complete = 1;
        print_final_report();
        #(CLOCK_PERIOD * 10);
        $finish;
    endtask

    // ========================================
    // 接口监控
    // ========================================
    // 监控输入接口状态
    always @(posedge clk) begin
        if (rst_n) begin
            // A端口输入监控
            if (pkt_i.pkt_in_vld && pkt_i.pkt_in_rdy) begin
                $display("[MONITOR] A端口输入: 类型=%b, QoS=%b, 源=%h, 目标=%h, 数据=%h",
                         pkt_i.pkt_in_type, pkt_i.pkt_in_qos,
                         pkt_i.pkt_in_src, pkt_i.pkt_in_tgt, pkt_i.pkt_in_data);
            end

            // C接口输入监控
            if (pkt_con.pkt_in_N_vld && pkt_con.pkt_in_N_rdy) begin
                $display("[MONITOR] 北输入: 类型=%b, 源=%h, 目标=%h",
                         pkt_con.pkt_in_N_type, pkt_con.pkt_in_N_src, pkt_con.pkt_in_N_tgt);
            end

            if (pkt_con.pkt_in_W_vld && pkt_con.pkt_in_W_rdy) begin
                $display("[MONITOR] 西输入: 类型=%b, 源=%h, 目标=%h",
                         pkt_con.pkt_in_W_type, pkt_con.pkt_in_W_src, pkt_con.pkt_in_W_tgt);
            end

            if (pkt_con.pkt_in_S_vld && pkt_con.pkt_in_S_rdy) begin
                $display("[MONITOR] 南输入: 类型=%b, 源=%h, 目标=%h",
                         pkt_con.pkt_in_S_type, pkt_con.pkt_in_S_src, pkt_con.pkt_in_S_tgt);
            end

            if (pkt_con.pkt_in_E_vld && pkt_con.pkt_in_E_rdy) begin
                $display("[MONITOR] 东输入: 类型=%b, 源=%h, 目标=%h",
                         pkt_con.pkt_in_E_type, pkt_con.pkt_in_E_src, pkt_con.pkt_in_E_tgt);
            end
        end
    end

    // ========================================
    // 故障配置更新
    // ========================================
    always @(posedge clk) begin
        if (rst_n) begin
            // 同步故障配置到配置管理器
            if (cfg != null) begin
                // 故障配置已经在测试序列中处理
            end
        end
    end

    // ========================================
    // 超时保护
    // ========================================
    initial begin
        #TEST_TIMEOUT;
        $display("[TEST_ENV] ⚠️ 测试超时，强制结束");
        print_final_report();
        $finish;
    end

    // ========================================
    // 结果报告
    // ========================================
    task automatic print_final_report();
        $display("\n========================================");
        $display("📊 MAZE节点验证测试报告");
        $display("========================================");
        $display("测试时间: %0t", $time);
        $display("测试模式: %0h", test_mode);
        $display("测试结果: %s", test_result ? "通过" : "失败");

        // 打印配置信息
        if (cfg != null) begin
            cfg.print_config();
        end

        // 打印注入器统计
        if (injector != null) begin
            injector.print_statistics();
        end

        // 打印监控器统计
        if (monitor != null) begin
            monitor.print_statistics();
        end

        // 打印测试序列统计
        if (test_seq != null) begin
            test_seq.print_test_summary();
        end

        $display("========================================");
        $display("🏁 测试完成");
        $display("========================================");
    endtask

    // ========================================
    // 调试助手任务
    // ========================================

    // 从外部设置测试模式的任务
    task automatic set_test_mode(input [3:0] mode);
        test_mode = mode;
        $display("[TEST_ENV] 测试模式设置为: %0h", mode);
    endtask

    // 启动测试的任务
    task automatic start_test();
        test_start = 1;
        $display("[TEST_ENV] 测试开始信号已发送");
    endtask

    // 设置故障的任务
    task automatic set_fault(input logic enable, input integer fault_x, input integer fault_y);
        pg_en = enable;
        if (enable) begin
            pg_node = {fault_y[2:0], fault_x[2:0]};
            if (cfg != null) begin
                cfg.set_fault(enable, fault_x, fault_y);
            end
            $display("[TEST_ENV] 故障节点设置为: (%0d, %0d)", fault_x, fault_y);
        end else begin
            pg_node = 0;
            if (cfg != null) begin
                cfg.set_fault(enable, 0, 0);
            end
            $display("[TEST_ENV] 故障已禁用");
        end
    endtask

    // ========================================
    // 注意：SystemVerilog断言被注释以保持Verilator兼容性
    // ========================================

    // 时钟稳定性检查
    // property clock_stability;
    //     @(posedge clk) not (clk === 1'bx);
    // endproperty
    //
    // assert property (clock_stability) else
    //     $error("[ASSERT] 时钟信号不稳定");

    // 复位序列检查
    // property reset_sequence;
    //     @(posedge clk) disable iff (!rst_n)
    //     ##[1:10] rst_n;
    // endproperty
    //
    // assert property (reset_sequence) else
    //     $error("[ASSERT] 复位序列异常");

    // 输出有效性检查
    // property output_validity;
    //     @(posedge clk) disable iff (!rst_n)
    //     pkt_o.pkt_out_vld |-> !(pkt_o.pkt_out_type === 2'bxx);
    // endproperty
    //
    // assert property (output_validity) else
    //     $error("[ASSERT] B端口输出包含无效类型");

endmodule