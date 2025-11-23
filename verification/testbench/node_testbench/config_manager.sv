// =============================================================================
// MAZE节点验证环境 - 配置管理器
// =============================================================================
// 功能：管理节点配置、故障设置和测试参数

`timescale 1ns/1ps

class NodeConfig;
    // 节点位置
    logic [2:0] node_x;    // 节点X坐标 (0-7)
    logic [2:0] node_y;    // 节点Y坐标 (0-7)

    // 故障配置
    logic pg_en;           // 故障使能
    logic [2:0] pg_node_x; // 故障节点X坐标
    logic [2:0] pg_node_y; // 故障节点Y坐标

    // 测试参数
    integer test_timeout;  // 默认测试超时
    integer clock_period;  // 时钟周期

    function new();
        // 默认配置
        node_x = 3;
        node_y = 3;
        pg_en = 0;
        pg_node_x = 0;
        pg_node_y = 0;
        test_timeout = 100;
        clock_period = 10;

        $display("[ConfigManager] 配置管理器初始化完成");
        $display("[ConfigManager] 默认节点位置: (%0d, %0d)", node_x, node_y);
    endfunction

    // 设置节点位置
    function void set_position(integer x, integer y);
        if (x < 0 || x > 7 || y < 0 || y > 7) begin
            $error("[ConfigManager] 错误: 节点坐标超出范围 (%0d, %0d)，应在(0,0)到(7,7)之间", x, y);
            return;
        end

        node_x = x[2:0];
        node_y = y[2:0];
        $display("[ConfigManager] 节点位置设置为: (%0d, %0d)", node_x, node_y);
    endfunction

    // 设置故障节点
    function void set_fault(logic enable, integer fault_x, integer fault_y);
        if (fault_x < 0 || fault_x > 7 || fault_y < 0 || fault_y > 7) begin
            $error("[ConfigManager] 错误: 故障节点坐标超出范围 (%0d, %0d)，应在(0,0)到(7,7)之间", fault_x, fault_y);
            return;
        end

        pg_en = enable;
        pg_node_x = fault_x[2:0];
        pg_node_y = fault_y[2:0];

        if (enable) begin
            $display("[ConfigManager] 故障节点设置为: (%0d, %0d)", pg_node_x, pg_node_y);
        end else begin
            $display("[ConfigManager] 故障已禁用");
        end
    endfunction

    // 获取节点ID
    function automatic logic [5:0] get_node_id();
        return {node_y, node_x};
    endfunction

    // 获取故障节点ID
    function automatic logic [5:0] get_fault_node_id();
        if (pg_en) begin
            return {pg_node_y, pg_node_x};
        end else begin
            return 6'hFF; // 无效故障节点ID
        end
    endfunction

    // 计算两个节点间的曼哈顿距离
    function automatic integer calculate_manhattan_distance(logic [5:0] node1_id, logic [5:0] node2_id);
        logic [2:0] x1, y1, x2, y2;
        integer dx, dy;

        x1 = node1_id[2:0];
        y1 = node1_id[5:3];
        x2 = node2_id[2:0];
        y2 = node2_id[5:3];

        dx = (x1 > x2) ? (x1 - x2) : (x2 - x1);
        dy = (y1 > y2) ? (y1 - y2) : (y2 - y1);

        return dx + dy;
    endfunction

    // 判断是否需要绕行
    function automatic logic needs_detour(logic [5:0] src_id, logic [5:0] tgt_id);
        logic [2:0] src_x, src_y, tgt_x, tgt_y;

        if (!pg_en) begin
            return 1'b0; // 无故障，无需绕行
        end

        src_x = src_id[2:0];
        src_y = src_id[5:3];
        tgt_x = tgt_id[2:0];
        tgt_y = tgt_id[5:3];

        // 简单判断：如果故障节点在源和目标之间的直线路径上，可能需要绕行
        if (src_x == tgt_x && src_x == pg_node_x) begin
            // 垂直路径经过故障节点
            if ((src_y < pg_node_y && pg_node_y < tgt_y) || (tgt_y < pg_node_y && pg_node_y < src_y)) begin
                return 1'b1;
            end
        end

        if (src_y == tgt_y && src_y == pg_node_y) begin
            // 水平路径经过故障节点
            if ((src_x < pg_node_x && pg_node_x < tgt_x) || (tgt_x < pg_node_x && pg_node_x < src_x)) begin
                return 1'b1;
            end
        end

        return 1'b0;
    endfunction

    // 预测路由输出端口
    function automatic logic [2:0] predict_output_port(logic [5:0] src_id, logic [5:0] tgt_id);
        logic [2:0] src_x, src_y, tgt_x, tgt_y;
        logic [2:0] cur_x, cur_y;

        cur_x = node_x;
        cur_y = node_y;
        src_x = src_id[2:0];
        src_y = src_id[5:3];
        tgt_x = tgt_id[2:0];
        tgt_y = tgt_id[5:3];

        // 如果是本地节点
        if (cur_x == tgt_x && cur_y == tgt_y) begin
            return 3'd4; // B端口（本地）
        end

        // 简单XY路由预测（考虑故障）
        if (cur_x != tgt_x) begin
            // X方向优先
            if (cur_x < tgt_x) begin
                // 目标在东方
                if (pg_en && cur_x + 1 == pg_node_x && cur_y == pg_node_y) begin
                    // 东边节点故障，先向北或向南绕行
                    if (cur_y < 7) return 3'd0; // 向北
                    else return 3'd2; // 向南
                end else begin
                    return 3'd3; // 向东
                end
            end else begin
                // 目标在西方
                if (pg_en && cur_x - 1 == pg_node_x && cur_y == pg_node_y) begin
                    // 西边节点故障，先向北或向南绕行
                    if (cur_y < 7) return 3'd0; // 向北
                    else return 3'd2; // 向南
                end else begin
                    return 3'd1; // 向西
                end
            end
        end else if (cur_y != tgt_y) begin
            // Y方向次要
            if (cur_y < tgt_y) begin
                // 目标在北方
                if (pg_en && cur_y + 1 == pg_node_y && cur_x == pg_node_x) begin
                    // 北边节点故障，先向东或西绕行
                    if (cur_x < 7) return 3'd3; // 向东
                    else return 3'd1; // 向西
                end else begin
                    return 3'd0; // 向北
                end
            end else begin
                // 目标在南方
                if (pg_en && cur_y - 1 == pg_node_y && cur_x == pg_node_x) begin
                    // 南边节点故障，先向东或西绕行
                    if (cur_x < 7) return 3'd3; // 向东
                    else return 3'd1; // 向西
                end else begin
                    return 3'd2; // 向南
                end
            end
        end

        return 3'd4; // 默认本地
    endfunction

    // 重置配置
    function void reset_config();
        node_x = 3;
        node_y = 3;
        pg_en = 0;
        pg_node_x = 0;
        pg_node_y = 0;
        test_timeout = 100;
        clock_period = 10;

        $display("[ConfigManager] 配置已重置为默认值");
    endfunction

    // 打印配置信息
    function void print_config();
        $display("=== 节点配置信息 ===");
        $display("当前节点位置: (%0d, %0d)", node_x, node_y);
        $display("当前节点ID: %h", get_node_id());

        if (pg_en) begin
            $display("故障节点位置: (%0d, %0d)", pg_node_x, pg_node_y);
            $display("故障节点ID: %h", get_fault_node_id());
        end else begin
            $display("故障: 无");
        end

        $display("测试超时: %0d 周期", test_timeout);
        $display("时钟周期: %0d ns", clock_period);
    endfunction

    // 生成测试报告
    function void generate_test_report();
        $display("=== 测试配置报告 ===");
        $display("测试时间: %0t", $time);
        $display("节点位置: (%0d, %0d)", node_x, node_y);
        $display("故障状态: %s", pg_en ? "启用" : "禁用");

        if (pg_en) begin
            $display("故障位置: (%0d, %0d)", pg_node_x, pg_node_y);
            $display("当前到故障的距离: %0d",
                calculate_manhattan_distance(get_node_id(), get_fault_node_id()));
        end

        $display("================================");
    endfunction

endclass