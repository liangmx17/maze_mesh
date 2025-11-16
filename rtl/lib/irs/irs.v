`timescale 1ns/1ps
module IRS_N #(
    parameter PYLD_W = 1,
    parameter IRS_DEEP = 1,
    parameter TYPE_NO_READY = 0,
    parameter TYPE_HALF = 0,
    parameter TYPE_RO_EN = 1
)(
    input   clk,
    input   rst_n,
    input   valid_i,
    input   ready_i,
    output  valid_o,
    output  ready_o,
    input   [PYLD_W-1:0] payload_i,
    output  [PYLD_W-1:0] payload_o
);

genvar i;
generate 
  if(IRS_DEEP == 0) begin:proc_irs_bypass
    assign valid_o  = valid_i;
    assign payload_o= payload_i;
    assign  ready_o = ready_i;
  end
  else begin:proc_insert_irs
    wire  [IRS_DEEP-1:0]  ready_irs_i;
    wire  [IRS_DEEP-1:0]  valid_irs_i;
    wire  [IRS_DEEP*PYLD_W-1:0]  payload_irs_i;
    wire  [IRS_DEEP-1:0]  ready_irs_o;
    wire  [IRS_DEEP-1:0]  valid_irs_o;
    wire  [IRS_DEEP*PYLD_W-1:0]  payload_irs_o;

    assign ready_irs_i[IRS_DEEP-1] = ready_i;
    assign valid_irs_i[0] = valid_i;
    assign ready_o = ready_irs_o[0];
    assign valid_o = valid_irs_o[IRS_DEEP-1];
    assign payload_o = payload_irs_o[IRS_DEEP*PYLD_W-1:(IRS_DEEP-1)*PYLD_W];

    
    for (i=0; i<IRS_DEEP; i=i+1) begin:irs_gen
      if(TYPE_NO_READY) begin: irs_reg
        IRS_HALF #(
          .PYLD_W (PYLD_W)
          ,.WITH_READY(0)
        ) U_LOOP_IRS(
          .clk        (clk),
          .rst_n      (rst_n),
          .valid_i    (valid_irs_i[i]),
          .ready_o    (ready_irs_o[i]),
          .payload_i  (payload_irs_i[(i+1)*PYLD_W-1:i*PYLD_W]),
          .valid_o    (valid_irs_o[i]),
          .ready_i    (ready_irs_i[i]),
          .payload_o  (payload_irs_o[(i+1)*PYLD_W-1:i*PYLD_W])
        );
      end
      else if (TYPE_HALF) begin: irs_gen_half
        IRS_HALF #(
          .PYLD_W (PYLD_W)
          ,.WITH_READY(1)
        ) U_LOOP_IRS(
          .clk        (clk),
          .rst_n      (rst_n),
          .valid_i    (valid_irs_i[i]),
          .ready_o    (ready_irs_o[i]),
          .payload_i  (payload_irs_i[(i+1)*PYLD_W-1:i*PYLD_W]),
          .valid_o    (valid_irs_o[i]),
          .ready_i    (ready_irs_i[i]),
          .payload_o  (payload_irs_o[(i+1)*PYLD_W-1:i*PYLD_W])
        );
      end
      else if (TYPE_RO_EN) begin: irs_ro_en
        IRS_LP #(
          .PYLD_W (PYLD_W)
          ,.RO_EN(1)
        ) U_LOOP_IRS(
          .clk        (clk),
          .rst_n      (rst_n),
          .valid_i    (valid_irs_i[i]),
          .ready_o    (ready_irs_o[i]),
          .payload_i  (payload_irs_i[(i+1)*PYLD_W-1:i*PYLD_W]),
          .valid_o    (valid_irs_o[i]),
          .ready_i    (ready_irs_i[i]),
          .payload_o  (payload_irs_o[(i+1)*PYLD_W-1:i*PYLD_W])
        );
      end
      else begin: irs_normal
        IRS_LP #(
          .PYLD_W (PYLD_W)
          ,.RO_EN(0)
        ) U_LOOP_IRS(
          .clk        (clk),
          .rst_n      (rst_n),
          .valid_i    (valid_irs_i[i]),
          .ready_o    (ready_irs_o[i]),
          .payload_i  (payload_irs_i[(i+1)*PYLD_W-1:i*PYLD_W]),
          .valid_o    (valid_irs_o[i]),
          .ready_i    (ready_irs_i[i]),
          .payload_o  (payload_irs_o[(i+1)*PYLD_W-1:i*PYLD_W])
        );
      end

      if(i>0) begin
        assign ready_irs_i[i-1] = ready_irs_o[i];
        assign valid_irs_i[i]   = valid_irs_o[i-1];
        assign payload_irs_i[(i)*PYLD_W-1:(i-1)*PYLD_W] = payload_irs_o[(i)*PYLD_W-1:(i-1)*PYLD_W];
      end
    end
  end
endgenerate

endmodule

`timescale 1ns/1ps
module IRS_HALF #(
    parameter PYLD_W = 1,
    parameter WITH_READY = 1
)(
    input   clk,
    input   rst_n,
    input   valid_i,
    output  ready_o,
    input   [PYLD_W-1:0] payload_i,
    output  valid_o,
    input   ready_i,
    output  [PYLD_W-1:0] payload_o
);

reg        valid_r;
reg [PYLD_W-1:0] payload_r;

wire ready_r = WITH_READY ? ready_i : 1'b1;
assign ready_o = WITH_READY ? ~valid_r : 1'b1;

assign valid_o = valid_r;
assign payload_o = payload_r;

always@(posedge clk or negedge rst_n) begin
  if(!rst_n) begin
    valid_r <= 1'b0;
  end
  else begin
    if(ready_o && valid_i) begin
      valid_r <= 1'b1;
      payload_r <= payload_i;
    end
    else if(ready_r && valid_o) begin
      valid_r <= 1'b0;
    end
  end
end

endmodule

`timescale 1ns/1ps
module IRS_LP #(
    parameter PYLD_W = 1,
    parameter RO_EN = 0
)(
    input   clk,
    input   rst_n,
    input   valid_i,
    output  ready_o,
    input   [PYLD_W-1:0] payload_i,
    output  valid_o,
    input   ready_i,
    output  [PYLD_W-1:0] payload_o
);

reg        valid0_r, valid1_r;
reg [PYLD_W-1:0] payload0_r, payload1_r;
wire [1:0] set;
wire [1:0] clr;

assign set[0] = (valid_i | valid1_r) & (ready_i | ~valid0_r);
assign set[1] = valid_i & valid0_r & ~ready_i & ~valid1_r;
assign clr[0] = ready_i & valid0_r;
assign clr[1] = (ready_i | ~valid0_r) & valid1_r;

always@(posedge clk or negedge rst_n) begin
  if(!rst_n) begin
    valid0_r <= 1'b0;
    valid1_r <= 1'b0;
  end
  else begin
    if(set[0]) valid0_r <= 1'b1;
    else if(clr[0]) valid0_r <= 1'b0;

    if(set[1]) valid1_r <= 1'b1;
    else if(clr[1]) valid1_r <= 1'b0;
  end
end

always@(posedge clk) begin
  if(set[0]) payload0_r <= valid1_r ? payload1_r : payload_i;
  if(set[1]) payload1_r <= payload_i;
end

assign ready_o = ~valid1_r;
assign valid_o = valid0_r;
assign payload_o = payload0_r;

endmodule
