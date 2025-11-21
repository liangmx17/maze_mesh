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
    wire [2:0]  new_y;
    wire [1:0]  pkt_type;
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
                          tgt_buf[5:3] + (tgt_buf[2:0] == 3'b111) ;

    assign new_tgt = pg_en ?    pkt_type_A == 2'b11 ?  {new_y_broad,new_x} :
                                pkt_type_A == 2'b01 ?  {new_y_multi,tgt_raw[2:0]} :
                                pkt_type_A == 2'b10 ?  {tgt_raw[5:3], new_x} :
                                tgt_raw;

    always@(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
//            pkt_type_reg <= 'b0;
//            tgt_reg <= 'b0;
            cpy_mode <= 'b0;
        end
        else begin
//            pkt_type_reg <= clr ? pkt_type_A : pkt_type_reg;
            // tgt_reg <= clr ? 'b0: 
            //             pkt_type == 2'b01 : tgt;
            cpy_mode <= pg_en ? (pkt_type == 2'b01) ? ((new_tgt[5:3] == 3'b111) ? 'b0 : 'b1) :
                                (pkt_type == 2'b10) ? ((new_tgt[2:0] == 3'b111) ? 'b0 : 'b1) :
                                (pkt_type == 2'b11) ? ((new_tgt == 6'b111111) ? 'b0 : 'b1)   :
                        1'b0;
        end
    end

endmodule
