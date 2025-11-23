// 存放qos\type\src_pos\data
// 没有坏点的时候就正常工作
// 有坏点的时候，如果cpy_mode为低电平，就正常工作
// 有坏点的时候，如果cpy_mode为高电平，就不更新当前包的内容，即rdy信号为低电平，直到离开了cpy mode下一拍再拉高
`timescale 1ns/1ps
module IBUF_A_DATA #(
    parameter PYLD_W = 17
)(
    input   clk,
    input   rst_n,
    input   ibuf_vld,
    input   pg_en,
    input   cpy_mode,
    output  reg     ibuf_rdy,
    input   [PYLD_W-1:0] payload_i,
    input   [4:0]   arb_req,
    input   [4:0]   arb_gnt,
    input   [4:0]   obuf_rdy,
    output  reg [PYLD_W-1:0] payload_o
);


    wire set = ibuf_vld & ibuf_rdy; // in cpy mode only the first data store, and then ibuf_rdy force 0
    wire [4:0]  clr = (arb_gnt & obuf_rdy) & ~{5{cpy_mode}};


always@(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        ibuf_rdy <= 'b0;
        payload_o <= 'b0;
    end
    else begin
        ibuf_rdy <= (pg_en & cpy_mode) ? 
                    'b0:
                    ~|(arb_req & clr);
        payload_o <= set ? payload_i : payload_o;
    end
end

endmodule
