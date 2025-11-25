module OBUF #(
    parameter PYLD_W = 1
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

wire ready_r = ready_i;
assign ready_o = ~valid_r;

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