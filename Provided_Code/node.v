module node #(
    parameter HP,  // 水平坐标 (0-7)
    parameter VP   // 垂直坐标 (0-7)
) (
    input clk,
    input rst_n,
    input pg_en,              // 故障使能信号
    input [`ID_W-1:0] pg_node, // 故障节点坐标
    pkt_in.mst pkt_i,         // A接口输入
    pkt_out.mst pkt_o,        // B接口输出
    pkt_con_if.mst pkt_con   // C接口(including both input and output, 28 port)
);

// User Define


endmodule
