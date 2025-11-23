// =============================================================================
// MAZE网络路由单元模块
// =============================================================================
// 功能说明：
// 1. 在输入buffer之前的router
// 2. 修改写入buffer_in的tgt_x, tgt_y
// 3. 实现无坏点模式下的单播、多播和广播
// 4. 实现有坏点模式下的单播
// 5. 配置参数LOCAL_X\LOCAL_Y
// 6. 输入端口tgt_x, tgt_y, pg_en, pg_node_x, pg_node_y，fault_relative_pos
// 7. 输出端口tgt_x_new, tgt_y_new, route_req
// 8. 纯组合逻辑
// 9. 考虑位于边缘的情况
// 10. 在行多播的情况下，src_y和tgt_x都没有用，这6bit用来传播多播五个方向的信息
// 11. 在列多播的情况下，src_x和tgt_y都没有用，这6bit用来传播多播五个方向的信息
// 12. 在广播的情况下，tgt_xy都没有用，这6bit用来传播多播五个方向的信息
// 13. 有坏点时，通过在A入口进行包复制实现多播、广播，利用对应的tgt_x/y作为计数器
// =============================================================================
`timescale 1ns/1ps
`include "param.v"
module pre_router #(
    // 节点位置参数
    parameter [2:0] LOCAL_X = 3'd0,     // 当前节点X坐标 (0-7)
    parameter [2:0] LOCAL_Y = 3'd0,      // 当前节点Y坐标 (0-7)
    parameter [2:0] router_id = 3'd0  // 当前router是NWSE的哪一个router NSWE 0123
) (
    // 输入数据包接口
    input wire [2:0] tgt_x,               // 包原始目标X坐标 (0-7)
    input wire [2:0] tgt_y,               // 包原始目标Y坐标 (0-7)
    input wire [2:0] src_x,               // 包原始目标X坐标 (0-7)
    input wire [2:0] src_y,               // 包原始目标Y坐标 (0-7)
    input wire [1:0] pkt_type,             //包类型：00 单播， 01 x相同的广播（列多播），10 y相同的多播（行多播），11 广播

    
    input wire       pg_en,                   // 坏点存在信号
    input wire [3:0] fault_relative_pos,               // 坏点Y坐标 (0-7)

    // 路由输出接口
    output reg [4:0] route_req            // 5-bit 路由请求 [N,W,S,E,B]，多播、广播模式下存在多bit 1
);

// =============================================================================
// 参数和内部信号定义
// =============================================================================

// 使用param.v中定义的宏，无需重复定义

localparam LYEQ1 = LOCAL_Y == 1;
localparam LYEQ0 = LOCAL_Y == 0;
localparam LXEQ1 = LOCAL_X == 1;
localparam LXEQ0 = LOCAL_X == 0;

wire xNE = fault_relative_pos==`NE_OF_x;
wire xSE = fault_relative_pos==`SE_OF_x;
wire xNW = fault_relative_pos==`NW_OF_x;
wire xSW = fault_relative_pos==`SW_OF_x;
wire xN = fault_relative_pos==`N_OF_x;
wire xS = fault_relative_pos==`S_OF_x;
wire xW = fault_relative_pos==`W_OF_x;
wire xE = fault_relative_pos==`E_OF_x;
wire tgt_y_eq_loc_y  = tgt_y == LOCAL_Y;
wire tgt_x_eq_loc_x  = tgt_x == LOCAL_X;
wire tgt_x_gt_loc_x = tgt_x > LOCAL_X;
wire tgt_x_gt_loc_x_p1 = tgt_x > (LOCAL_X + 1);
wire tgt_x_gt_loc_x_p2 = tgt_x > (LOCAL_X + 1);
wire tgt_x_ls_loc_x = tgt_x < LOCAL_X;
wire tgt_x_ls_loc_x_m1 = tgt_x < (LOCAL_X-1);
wire tgt_y_gt_loc_y = tgt_y > LOCAL_Y;
wire tgt_y_gt_loc_y_p1 = tgt_y > (LOCAL_Y+1);
wire tgt_y_ls_loc_y = tgt_y < LOCAL_Y;
wire src_y_eq_loc_y = src_y == LOCAL_Y;


always_comb begin
    // 默认无请求，输出零数据包
    route_req = 5'b00000;
    if(pg_en) begin
                route_req[`DIR_B] = (tgt_x == LOCAL_X) & (tgt_y == LOCAL_Y);
                if(tgt_x_gt_loc_x) begin
                    route_req[`DIR_E] = (xNE |xE |xSE |xS) |
                                        (xN & ( LYEQ1 | LXEQ0 | !tgt_y_ls_loc_y | tgt_x_gt_loc_x_p1)) |
                                        (xNW & (LYEQ1 | !tgt_y_ls_loc_y | tgt_x_gt_loc_x_p2)) |
                                        (xSW & (!tgt_y_gt_loc_y | tgt_x_gt_loc_x_p1));
                    route_req[`DIR_W] = (xN & !( LYEQ1 | LXEQ0 | !tgt_y_ls_loc_y | tgt_x_gt_loc_x_p1));
                    route_req[`DIR_S] = (xNW & !(LYEQ1 | !tgt_y_ls_loc_y | tgt_x_gt_loc_x_p2))  |
                                        (xW & !(LYEQ0 | tgt_y_gt_loc_y)) ;
                    route_req[`DIR_N] = (xW & (LYEQ0 | tgt_y_gt_loc_y))  |
                                        (xSW & !(!tgt_y_gt_loc_y | tgt_x_gt_loc_x_p1));
                end
                else if(tgt_x_ls_loc_x) begin
                    route_req[`DIR_W] =  (xN |xNW |xW |xSW |xS)   |
                                        (xNE & (tgt_x_ls_loc_x_m1 | !tgt_y_ls_loc_y))   |
                                        (xSE & !(LXEQ1 & tgt_y_gt_loc_y_p1))    ;
                    route_req[`DIR_S] =  (xNE & !(tgt_x_ls_loc_x_m1 | !tgt_y_ls_loc_y))  |
                                        (xE & !(LYEQ0 | (LOCAL_X==1 & tgt_y_gt_loc_y))) ;
                    route_req[`DIR_N] =  (xSE & (LXEQ1 & tgt_y_gt_loc_y_p1))     |
                                        (xE & (LYEQ0 | (LOCAL_X==1 & tgt_y_gt_loc_y)))  ;
                    route_req[`DIR_E] =  0;
                end
                else if(tgt_y_gt_loc_y) begin
                    route_req[`DIR_N] = !xS;
                    route_req[`DIR_W] = xS & !LXEQ0;
                    route_req[`DIR_E] = xS & LXEQ0;
                end
                else if(tgt_y_ls_loc_y) begin
                    route_req[`DIR_S] = !xN;
                    route_req[`DIR_W] = xN & !LXEQ0;
                    route_req[`DIR_E] = xN & LXEQ0;
                end
    end
    else begin
        case(pkt_type)
        2'b00: begin
            route_req[`DIR_E] = tgt_x_gt_loc_x;
            route_req[`DIR_W] = tgt_x_ls_loc_x;
            route_req[`DIR_N] = tgt_x_eq_loc_x & tgt_y_gt_loc_y;
            route_req[`DIR_S] = tgt_x_eq_loc_x & tgt_y_ls_loc_y;
            route_req[`DIR_B] = tgt_x_eq_loc_x & tgt_y_eq_loc_y;
        end
        2'b01: begin
            route_req[`DIR_E] = tgt_x_gt_loc_x;
            route_req[`DIR_W] = tgt_x_ls_loc_x;
            route_req[`DIR_N] = tgt_x_eq_loc_x & (router_id != `DIR_N);
            route_req[`DIR_S] = tgt_x_eq_loc_x & (router_id != `DIR_S);
            route_req[`DIR_B] = tgt_x_eq_loc_x;
        end
        2'b10: begin
            route_req[`DIR_E] = src_y_eq_loc_y & (LOCAL_X >= src_x) ;
            route_req[`DIR_W] = src_y_eq_loc_y & (LOCAL_X <= src_x) ;
            route_req[`DIR_N] = tgt_y_gt_loc_y;
            route_req[`DIR_S] = tgt_y_ls_loc_y;
            route_req[`DIR_B] = tgt_y_eq_loc_y;
        end
        2'b11: begin
            route_req[`DIR_B] = 1'b1;
            route_req[`DIR_N] = LOCAL_Y >= src_y;
            route_req[`DIR_S] = LOCAL_Y <= src_y;
            route_req[`DIR_E] = LOCAL_X >= src_x;
            route_req[`DIR_W] = LOCAL_X <= src_x;
        end
        endcase
    end
end


endmodule
