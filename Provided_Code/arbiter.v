module arbiter #(
      parameter WIDTH = 4
  )(
      input [WIDTH-1:0] req,
      input [WIDTH-1:0] qos,
      output [WIDTH-1:0] gnt
  );
      assign gnt = (|qos) ? (qos & (~(qos-1))) : (req & (~(req-1)));
endmodule
