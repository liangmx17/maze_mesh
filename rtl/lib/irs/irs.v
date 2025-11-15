// IRS_N - 插入式环形缓冲器模块
// 用于MAZE网络节点输入输出端口的缓冲和流量控制
// 支持可配置的缓冲深度和不同的工作模式

module IRS_N #(
    parameter PYLD_W = 1,           // 数据负载宽度
    parameter IRS_DEEP = 1,         // IRS缓冲深度（0表示直通）
    parameter TYPE_NO_READY = 0,    // 无ready信号模式标志
    parameter TYPE_HALF = 0,        // 半缓冲模式标志
    parameter TYPE_RO_EN = 1        // 只读使能模式标志（输出端使用）
)(
    input   clk,                    // 时钟信号
    input   rst_n,                  // 复位信号（低电平有效）
    input   valid_i,                // 输入数据有效信号
    input   ready_i,                // 输出就绪信号（来自下游）
    output  valid_o,                // 输出数据有效信号
    output  ready_o,                // 输入就绪信号（给上游）
    input   [PYLD_W-1:0] payload_i, // 输入数据负载
    output  [PYLD_W-1:0] payload_o  // 输出数据负载
);

genvar i;
generate
  // 缓冲深度为0时的直通模式
  if(IRS_DEEP == 0) begin:proc_irs_bypass
    assign valid_o  = valid_i;            // 直通传递有效信号
    assign payload_o= payload_i;          // 直通传递数据
    assign  ready_o = ready_i;            // 直通传递就绪信号
  end
  // 插入IRS缓冲器的模式
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

// IRS_HALF - 半缓冲器模块
// 简化的单级缓冲器，支持可选的ready信号握手协议

module IRS_HALF #(
    parameter PYLD_W = 1,           // 数据负载宽度
    parameter WITH_READY = 1        // 是否支持ready信号握手
)(
    input   clk,                    // 时钟信号
    input   rst_n,                  // 复位信号（低电平有效）
    input   valid_i,                // 输入数据有效信号
    output  ready_o,                // 输入就绪信号
    input   [PYLD_W-1:0] payload_i, // 输入数据负载
    output  valid_o,                // 输出数据有效信号
    input   ready_i,                // 输出就绪信号
    output  [PYLD_W-1:0] payload_o  // 输出数据负载
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

// IRS_LP - 纵向流水线缓冲器模块
// 支持两级缓冲的流水线结构，可用于只读模式

module IRS_LP #(
    parameter PYLD_W = 1,           // 数据负载宽度
    parameter RO_EN = 0              // 只读使能标志（用于输出端）
)(
    input   clk,                    // 时钟信号
    input   rst_n,                  // 复位信号（低电平有效）
    input   valid_i,                // 输入数据有效信号
    output  ready_o,                // 输入就绪信号
    input   [PYLD_W-1:0] payload_i, // 输入数据负载
    output  valid_o,                // 输出数据有效信号
    input   ready_i,                // 输出就绪信号
    output  [PYLD_W-1:0] payload_o  // 输出数据负载
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
