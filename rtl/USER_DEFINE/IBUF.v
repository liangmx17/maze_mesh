`timescale 1ns/1ps

module IBUF #(
    parameter PYLD_W = `PKT_W
)(
    input   clk,
    input   rst_n,
    input   ibuf_vld,
    output  reg     ibuf_rdy,
    input   [4:0]   route_req,
    input   [PYLD_W-1:0] payload_i,
    output  reg [4:0]   arb_req,
    input   [4:0]   arb_gnt,
    input   [4:0]   obuf_rdy,
    output  reg [PYLD_W-1:0] payload_o
);

    // 使用param.v中定义的宏，无需重复定义

    wire set = ibuf_vld & ibuf_rdy;
    wire [4:0]  clr = arb_gnt & obuf_rdy;

always@(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        arb_req <= 'b0;
    end
    else begin
        arb_req[`DIR_N] <=   set ? route_req[`DIR_N] : 
                            clr[`DIR_N] ?  0 : arb_req[`DIR_N];
        arb_req[`DIR_S] <=   set ? route_req[`DIR_S] : 
                            clr[`DIR_S] ?  0 : arb_req[`DIR_S];
        arb_req[`DIR_E] <=   set ? route_req[`DIR_E] : 
                            clr[`DIR_E] ?  0 : arb_req[`DIR_E];
        arb_req[`DIR_W] <=   set ? route_req[`DIR_W] : 
                            clr[`DIR_W] ?  0 : arb_req[`DIR_W];
        arb_req[`DIR_B] <=   set ? route_req[`DIR_B] : 
                            clr[`DIR_B] ?  0 : arb_req[`DIR_B];
    end
end

always@(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        ibuf_rdy <= 'b1;
    end
    else begin
        ibuf_rdy <=  ~|(arb_req & ~clr);
        payload_o <= set ? payload_i : payload_o;
    end
end

endmodule