`timescale 1ns/1ps
`include "param.v"

// 无坏点的情况下，直接透传pkt type和tgt
// 有坏点的情况下，根据当前pkt type去修改tgt
// 修改的方案：     1. 在第一个包，即握手的时候，使用A端口的pkt type，根据type类型去将tgt修改为起始节点（某个坐标为0），拉高cpy mode
//              2. 后续的包，根据上一个包的pkt type和tgt去+1，保持cpy mode高电平
//              3. 当到达边界时，cpy_mode拉低，同时产生最后一个tgt，直到下一个握手包到来
//              4. 当产生的tgt为坏点的时候，拉高tgt_is_pg信号，通知IBUF_A_CTRL劫持握手信号

module multi_packet_gen#(
    // 节点位置参数
    parameter LOCAL_X = 3'd0,     // 当前节点X坐标 (0-7)
    parameter LOCAL_Y = 3'd0      // 当前节点Y坐标 (0-7)
)(
    input   clk,
    input   rst_n,
    input   [1:0]   pkt_type_A,
    input   [5:0]   tgt_A,
    input   [1:0]   pkt_type_buf,
    input   [5:0]   tgt_buf,
    input   pg_en,
    input   [5:0] pg_node,
    input   vld,
    input   rdy,
    output  [5:0]   new_tgt,
    output  tgt_is_pg,
    output  reg cpy_mode
);

    // reg [1:0]   pkt_type_reg;
    // reg [5:0]   tgt_reg;
    wire [5:0]  gen_tgt;
    wire [2:0]  new_x;
    wire [2:0]  new_y_multi;
    wire [2:0]  new_y_broad;
    wire [1:0]  pkt_type;
    wire [5:0]  tgt_raw;
    wire clr;

    assign clr = vld & rdy;
    assign pkt_type = clr ? pkt_type_A : pkt_type_buf;
    assign tgt_raw = clr ? tgt_A : tgt_buf;
    assign tgt_is_pg = new_tgt == pg_node;

    assign new_x =  clr ? 'b0 :
                    tgt_buf[2:0] + 1'b1;
    assign new_y_multi =  clr ? 'b0:
                          tgt_buf[5:3] + 1'b1;
    assign new_y_broad =  clr ? 'b0:
                          tgt_buf[5:3] + {2'b0, (tgt_buf[2:0] == 3'b111)} ;

    assign new_tgt = pg_en ?    pkt_type == 2'b11 ?  {new_y_broad,new_x} :
                                pkt_type == 2'b01 ?  {new_y_multi,tgt_raw[2:0]} :
                                pkt_type == 2'b10 ?  {tgt_raw[5:3], new_x} :
                                                        tgt_raw:
                                tgt_raw;

    always_comb begin
        cpy_mode =  pg_en ? (pkt_type == 2'b01) ? ((new_tgt[5:3] == 3'b111) ? 'b0 : 'b1) :
                            (pkt_type == 2'b10) ? ((new_tgt[2:0] == 3'b111) ? 'b0 : 'b1) :
                            (pkt_type == 2'b11) ? ((new_tgt == 6'b111111) ? 'b0 : 'b1)   :
                                                    1'b0 :
                            1'b0;
    end

endmodule
