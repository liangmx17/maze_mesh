// =============================================================================
// MAZE网络路由单元模块
// =============================================================================
// 功能说明：
// 1. 实现故障感知的XY路由算法
// 2. 支持5方向输出：北(N)、西(W)、南(S)、东(E)、本地(B)
// 3. 生成5-bit one-hot请求信号
// 4. 考虑边缘节点限制和故障节点位置
// 5. 支持单播、多播和广播路由
// =============================================================================
`timescale 1ns/1ps
module router_unit #(
    // 节点位置参数
    parameter logic [2:0] LOCAL_X = 3'd0,     // 当前节点X坐标 (0-7)
    parameter logic [2:0] LOCAL_Y = 3'd0      // 当前节点Y坐标 (0-7)
) (
    // 时钟和复位
    input logic clk,
    input logic rst_n,

    // 输入数据包接口
    input logic valid_in,                    // 输入有效信号
    input logic [22:0] pkt_in,               // 输入数据包 (23位)

    // 故障信息
    input logic [3:0] fault_register,        // 故障相对位置寄存器

    // 路由输出接口
    output logic [4:0] route_req,            // 5-bit one-hot路由请求 [N,W,S,E,B]
    output logic [22:0] pkt_out              // 输出数据包 (23位)
);

// =============================================================================
// 参数和内部信号定义
// =============================================================================

// 数据包位位置常量 (与node.v保持一致)
// 实际数据包格式: {TYPE[1:0], QOS[0], SRC[5:0], TGT[5:0], DATA[7:0]}
// 位位置:         [22:21], [20],   [19:14], [13:8], [7:0]
localparam QOS_POS      = 20;              // QoS位位置 (修复)
localparam TYPE_POS_HI  = 22;              // 类型位高位置
localparam TYPE_POS_LO  = 21;              // 类型位低位置
localparam SRC_POS_HI   = 19;              // 源ID高位置 (修复)
localparam SRC_POS_LO   = 14;              // 源ID低位置 (修复)
localparam TGT_POS_HI   = 13;              // 目标ID高位置 (修复)
localparam TGT_POS_LO   = 8;               // 目标ID低位置 (修复)
localparam PKT_W        = 23;              // 数据包总宽度

// 路由方向定义
localparam DIR_N    = 3'd0;                // 北方向
localparam DIR_W    = 3'd1;                // 西方向
localparam DIR_S    = 3'd2;                // 南方向
localparam DIR_E    = 3'd3;                // 东方向
localparam DIR_B    = 3'd4;                // 本地输出

// 故障相对位置类型定义
localparam NORMAL   = 4'd0;                // 正常状态，无故障影响
localparam N_OF_x   = 4'd1;                // 当前节点在故障节点北方
localparam NE_OF_x  = 4'd2;                // 当前节点在故障节点东北方
localparam E_OF_x   = 4'd3;                // 当前节点在故障节点东方
localparam SE_OF_x  = 4'd4;                // 当前节点在故障节点东南方
localparam S_OF_x   = 4'd5;                // 当前节点在故障节点南方
localparam SW_OF_x  = 4'd6;                // 当前节点在故障节点西南方
localparam W_OF_x   = 4'd7;                // 当前节点在故障节点西方
localparam NW_OF_x  = 4'd8;                // 当前节点在故障节点西北方

// 内部信号声明
logic [2:0] target_x, target_y;           // 目标节点坐标
logic [1:0] pkt_type;                     // 数据包类型
logic valid_route;                        // 路由有效信号

// 边缘判断信号 (内部计算)
logic is_north_edge;                      // 是否在北边缘 (Y=7)
logic is_south_edge;                      // 是否在南边缘 (Y=0)
logic is_west_edge;                       // 是否在西边缘 (X=0)
logic is_east_edge;                       // 是否在东边缘 (X=7)

// =============================================================================
// 边缘位置计算
// =============================================================================

always_comb begin
    // 根据参数计算边缘位置
    is_north_edge = (LOCAL_Y == 3'd7);     // 北边缘 (Y=7)
    is_south_edge = (LOCAL_Y == 3'd0);     // 南边缘 (Y=0)
    is_west_edge  = (LOCAL_X == 3'd0);     // 西边缘 (X=0)
    is_east_edge  = (LOCAL_X == 3'd7);     // 东边缘 (X=7)
end

// =============================================================================
// 输入数据包解析
// =============================================================================

always_comb begin
    if (valid_in) begin
        // 解析目标坐标
        target_x = pkt_in[TGT_POS_LO+2:TGT_POS_LO];      // 目标X坐标 (3位)
        target_y = pkt_in[TGT_POS_HI:TGT_POS_HI-2];      // 目标Y坐标 (3位)
        pkt_type = pkt_in[TYPE_POS_HI:TYPE_POS_LO];      // 数据包类型
        valid_route = 1'b1;
    end else begin
        target_x = LOCAL_X;
        target_y = LOCAL_Y;
        pkt_type = 2'b00;
        valid_route = 1'b0;
    end
end

// =============================================================================
// 故障感知XY路由算法实现
// =============================================================================

always_comb begin
    // 默认无请求，输出零数据包
    route_req = 5'b00000;
    pkt_out = pkt_in;

    if (valid_route) begin
        // 根据数据包类型进行路由
        case (pkt_type)
            2'b00: begin  // 单播路由 (Unicast)
                // 检查是否到达本地节点
                if (target_x == LOCAL_X && target_y == LOCAL_Y) begin
                    route_req[DIR_B] = 1'b1;  // 本地输出
                end else begin
                    // 实现故障感知XY路由
                    // X方向优先策略
                    if (target_x > LOCAL_X) begin
                        // 目标在东方
                        case (fault_register)
                            E_OF_x, NE_OF_x, SE_OF_x: begin
                                // 东方故障，选择绕行路径
                                if (target_y > LOCAL_Y && LOCAL_Y < 3'd7) begin
                                    route_req[DIR_N] = 1'b1;  // 向北绕行
                                end else if (LOCAL_Y > 3'd0) begin
                                    route_req[DIR_S] = 1'b1;  // 向南绕行
                                end
                            end
                            default: begin
                                // 东方无故障，直接向东
                                route_req[DIR_E] = 1'b1;
                            end
                        endcase
                    end else if (target_x < LOCAL_X) begin
                        // 目标在西方
                        case (fault_register)
                            W_OF_x, NW_OF_x, SW_OF_x: begin
                                // 西方故障，选择绕行路径
                                if (target_y > LOCAL_Y && LOCAL_Y < 3'd7) begin
                                    route_req[DIR_N] = 1'b1;  // 向北绕行
                                end else if (LOCAL_Y > 3'd0) begin
                                    route_req[DIR_S] = 1'b1;  // 向南绕行
                                end
                            end
                            default: begin
                                // 西方无故障，直接向西
                                route_req[DIR_W] = 1'b1;
                            end
                        endcase
                    end else begin
                        // X坐标相同，Y方向路由
                        if (target_y > LOCAL_Y) begin
                            // 目标在北方
                            case (fault_register)
                                N_OF_x, NW_OF_x, NE_OF_x: begin
                                    // 北方故障，选择东西绕行
                                    if (LOCAL_X < 3'd7) begin
                                        route_req[DIR_E] = 1'b1;  // 向东绕行
                                    end else if (LOCAL_X > 3'd0) begin
                                        route_req[DIR_W] = 1'b1;  // 向西绕行
                                    end
                                end
                                default: begin
                                    // 北方无故障，直接向北
                                    route_req[DIR_N] = 1'b1;
                                end
                            endcase
                        end else if (target_y < LOCAL_Y) begin
                            // 目标在南方
                            case (fault_register)
                                S_OF_x, SW_OF_x, SE_OF_x: begin
                                    // 南方故障，选择东西绕行
                                    if (LOCAL_X < 3'd7) begin
                                        route_req[DIR_E] = 1'b1;  // 向东绕行
                                    end else if (LOCAL_X > 3'd0) begin
                                        route_req[DIR_W] = 1'b1;  // 向西绕行
                                    end
                                end
                                default: begin
                                    // 南方无故障，直接向南
                                    route_req[DIR_S] = 1'b1;
                                end
                            endcase
                        end
                    end
                end
            end

            2'b01: begin  // X-Multicast (相同X坐标的所有节点)
                if (target_x == LOCAL_X) begin
                    // 当前节点在目标X列，本地输出
                    route_req[DIR_B] = 1'b1;
                end else begin
                    // 需要到达目标X列
                    if (target_x > LOCAL_X) begin
                        route_req[DIR_E] = 1'b1;  // 向东移动
                    end else if (target_x < LOCAL_X) begin
                        route_req[DIR_W] = 1'b1;  // 向西移动
                    end
                end
            end

            2'b10: begin  // Y-Multicast (相同Y坐标的所有节点)
                if (target_y == LOCAL_Y) begin
                    // 当前节点在目标Y行，本地输出
                    route_req[DIR_B] = 1'b1;
                end else begin
                    // 需要到达目标Y行
                    if (target_y > LOCAL_Y) begin
                        route_req[DIR_N] = 1'b1;  // 向北移动
                    end else if (target_y < LOCAL_Y) begin
                        route_req[DIR_S] = 1'b1;  // 向南移动
                    end
                end
            end

            2'b11: begin  // Broadcast (广播到所有节点)
                // 广播总是本地输出
                route_req[DIR_B] = 1'b1;
            end

            default: begin
                // 未知数据包类型，本地输出
                route_req[DIR_B] = 1'b1;
            end
        endcase

        // 边缘节点处理 - 确保不越界
        if (LOCAL_X == 3'd0) route_req[DIR_W] = 1'b0;     // 西边界，不能向西
        if (LOCAL_X == 3'd7) route_req[DIR_E] = 1'b0;     // 东边界，不能向东
        if (LOCAL_Y == 3'd0) route_req[DIR_S] = 1'b0;     // 南边界，不能向南
        if (LOCAL_Y == 3'd7) route_req[DIR_N] = 1'b0;     // 北边界，不能向北

        // 如果所有方向都被阻止，强制本地输出
        if (route_req == 5'b00000) begin
            route_req[DIR_B] = 1'b1;
        end
    end
end

// =============================================================================
// 输出寄存器 (可选，用于时序优化)
// =============================================================================

// 如果需要更好的时序，可以取消以下注释
/*
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        route_req <= 5'b00000;
        pkt_out <= 23'd0;
    end else begin
        route_req <= route_req_next;
        pkt_out <= (valid_in) ? pkt_in : 23'd0;
    end
end
*/

endmodule
