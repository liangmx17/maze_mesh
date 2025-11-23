// 没有坏点的时候，正常工作
// 有坏点且进入了cpy mode的时候，ibuf_rdy拉低，直到离开cpy_mode下一拍再拉高
// （外部实现），在cpy mode的时候，如果目标节点是坏点，就在劫持route_req信号，让下游arbiter和buffer看到的是0，
//  同时劫持obuf_rdy和arb_gnt信号，让ibuf以为握手成功
// 正常情况下，rdy拉高，是因为arb_req都为0，不为0的那些，clr为1，即arb_req == 0 | (arb_req==1 & clr ==1)  arb_req^5'b0 | arb_req & clr 
// arb_req == 1 & clr == 0 有一个那就rdy拉低， ~|(arb_req & ~clr)
`timescale 1ns/1ps
module IBUF_A_CTRL #(
    parameter PYLD_W = 23
)(
    input   clk,
    input   rst_n,
    input   ibuf_vld,
    input   pg_en,
    input   cpy_mode,
    output  reg     ibuf_rdy,
    input   [4:0]   route_req,
    input   [PYLD_W-1:0] payload_i,
    output  reg [4:0]   arb_req,
    input   [4:0]   arb_gnt,
    input   [4:0]   obuf_rdy,
    output  reg [PYLD_W-1:0] payload_o
);
    localparam DIR_N    = 3'd0;   // 北方向
    localparam DIR_W    = 3'd1;   // 西方向
    localparam DIR_S    = 3'd2;   // 南方向
    localparam DIR_E    = 3'd3;   // 东方向
    localparam DIR_B    = 3'd4;   // 本地输出

    wire set = ibuf_vld & (ibuf_rdy | cpy_mode);
    wire [4:0]  clr = arb_gnt & obuf_rdy;

always@(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        arb_req <= 'b0;
    end
    else begin
        arb_req[DIR_N] <=   set ? route_req[DIR_N] : 
                            clr[DIR_N] ?  0 : arb_req[DIR_N];
        arb_req[DIR_S] <=   set ? route_req[DIR_S] : 
                            clr[DIR_S] ?  0 : arb_req[DIR_S];
        arb_req[DIR_E] <=   set ? route_req[DIR_E] : 
                            clr[DIR_E] ?  0 : arb_req[DIR_E];
        arb_req[DIR_W] <=   set ? route_req[DIR_W] : 
                            clr[DIR_W] ?  0 : arb_req[DIR_W];
        arb_req[DIR_B] <=   set ? route_req[DIR_B] : 
                            clr[DIR_B] ?  0 : arb_req[DIR_B];
    end
end

always@(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        ibuf_rdy <= 'b1;
        payload_o <= 'b0;
    end
    else begin
        ibuf_rdy <= (pg_en & cpy_mode) ? 
                    'b0:
                     ~|(arb_req & ~clr);
        payload_o <= set ? payload_i : payload_o;
    end
end

endmodule
