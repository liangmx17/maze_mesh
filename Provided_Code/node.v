`include "top_define.v"

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
    pkt_con_if.slv pkt_con_in, // C接口输入 (从拓扑)
    pkt_con_if.mst pkt_con_out // C接口输出 (到拓扑)
);

// 本节点坐标
localparam [`ID_W-1:0] NODE_COORD = {VP[2:0], HP[2:0]};

// 时钟门控 (故障节点)
wire node_clk;
assign node_clk = pg_en && (pg_node == NODE_COORD) ? 1'b0 : clk;

// 内部数据包定义
typedef struct packed {
    logic vld;
    logic qos;
    logic [`TYPE_W-1:0] type;
    logic [`ID_W-1:0] src;
    logic [`ID_W-1:0] tgt;
    logic [`FLIT_W-1:0] data;
    logic rdy;
} packet_t;

// Stage 0 信号 (输入预处理)
typedef struct packed {
    logic vld;
    logic qos;
    logic [`TYPE_W-1:0] type;
    logic [`ID_W-1:0] src;
    logic [`ID_W-1:0] tgt;
    logic [`FLIT_W-1:0] data;
    logic [`ID_W-1:0] intermediate_node; // 中间节点坐标
    logic [3:0] output_port;             // 输出端口编码
    logic is_failed;                     // 目标是否为故障节点
} stage0_data_t;

// Stage 1 信号 (仲裁)
typedef struct packed {
    logic vld;
    logic qos;
    logic [`TYPE_W-1:0] type;
    logic [`ID_W-1:0] src;
    logic [`ID_W-1:0] tgt;
    logic [`FLIT_W-1:0] data;
    logic [`ID_W-1:0] winner_coord;     // 获胜者坐标
    logic [3:0] input_port;             // 输入端口标识
} stage1_data_t;

// Stage 2 信号 (输出选择)
typedef struct packed {
    logic vld;
    logic qos;
    logic [`TYPE_W-1:0] type;
    logic [`ID_W-1:0] src;
    logic [`ID_W-1:0] tgt;
    logic [`FLIT_W-1:0] data;
    logic [`ID_W-1:0] output_coord;     // 输出坐标
    logic [3:0] output_port;            // 输出端口
} stage2_data_t;

// Stage 3 信号 (输出缓冲)
typedef struct packed {
    logic vld;
    logic qos;
    logic [`TYPE_W-1:0] type;
    logic [`ID_W-1:0] src;
    logic [`ID_W-1:0] tgt;
    logic [`FLIT_W-1:0] data;
    logic [3:0] output_port;            // 输出端口
} stage3_data_t;

// 流水线寄存器
stage0_data_t stage0_in, stage0_out;
stage1_data_t stage1_in, stage1_out;
stage2_data_t stage2_in, stage2_out;
stage3_data_t stage3_in, stage3_out;

// 输入准备信号
wire a_port_rdy, c_ports_rdy;

// ====================================================================
// Stage 0: 输入预处理和中间节点计算
// ====================================================================

// A口输入数据组装
assign stage0_in.vld   = pkt_i.pkt_in_vld;
assign stage0_in.qos   = pkt_i.pkt_in_qos;
assign stage0_in.type  = pkt_i.pkt_in_type;
assign stage0_in.src   = pkt_i.pkt_in_src;
assign stage0_in.tgt   = pkt_i.pkt_in_tgt;
assign stage0_in.data  = pkt_i.pkt_in_data;

// 检查是否为单播包 (type = 00)
wire is_unicast = (stage0_in.type == 2'b00);

// 提取源和目标坐标
logic [2:0] src_x, src_y, tgt_x, tgt_y;
assign src_x = stage0_in.src[2:0];
assign src_y = stage0_in.src[5:3];
assign tgt_x = stage0_in.tgt[2:0];
assign tgt_y = stage0_in.tgt[5:3];

// 计算两个可能的中间节点
logic [`ID_W-1:0] intermediate1, intermediate2;
assign intermediate1 = {src_y, tgt_x}; // [src_y, tgt_x]
assign intermediate2 = {tgt_y, src_x}; // [tgt_y, src_x]

// 检查中间节点是否为故障节点
wire is_intermediate1_failed = pg_en && (intermediate1 == pg_node);
wire is_intermediate2_failed = pg_en && (intermediate2 == pg_node);

// 检查目标节点是否为故障节点 (单播不应该发生)
wire is_target_failed = pg_en && (stage0_in.tgt == pg_node);

// 简化的拥塞检测 (基于输出ready信号)
// 这里需要根据实际的C接口连接来实现
wire congestion1, congestion2;
assign congestion1 = 1'b0; // 暂时设为无拥塞
assign congestion2 = 1'b0;

// 中间节点选择逻辑
logic select_intermediate1;
always_comb begin
    if (!is_unicast) begin
        select_intermediate1 = 1'b0; // 非单播暂不处理
    end else if (is_intermediate1_failed && !is_intermediate2_failed) begin
        select_intermediate1 = 1'b0; // 选择intermediate2
    end else if (!is_intermediate1_failed && is_intermediate2_failed) begin
        select_intermediate1 = 1'b1; // 选择intermediate1
    end else if (!congestion1 && congestion2) begin
        select_intermediate1 = 1'b1; // 选择无拥塞的端口
    end else if (congestion1 && !congestion2) begin
        select_intermediate1 = 1'b0; // 选择无拥塞的端口
    end else begin
        select_intermediate1 = 1'b1; // 默认选择intermediate1
    end
end

// Stage 0 输出组装
assign stage0_out.intermediate_node = select_intermediate1 ? intermediate1 : intermediate2;
assign stage0_out.is_failed = is_target_failed;
assign stage0_out.output_port = 4'b0000; // 暂时设为0，需要根据实际连接设置

// Stage 0 数据传递
assign stage0_out.vld   = stage0_in.vld && is_unicast && !is_target_failed;
assign stage0_out.qos   = stage0_in.qos;
assign stage0_out.type  = stage0_in.type;
assign stage0_out.src   = stage0_in.src;
assign stage0_out.tgt   = stage0_in.tgt;
assign stage0_out.data  = stage0_in.data;

// A口ready信号
assign pkt_i.pkt_in_rdy = a_port_rdy;

// ====================================================================
// Stage 1: QoS仲裁和XY交换
// ====================================================================

// 暂时简化Stage 1实现 (只处理A口输入)
assign stage1_in = '0;
assign stage1_in.vld   = stage0_out.vld;
assign stage1_in.qos   = stage0_out.qos;
assign stage1_in.type  = stage0_out.type;
assign stage1_in.src   = stage0_out.src;
assign stage1_in.tgt   = stage0_out.tgt;
assign stage1_in.data  = stage0_out.data;
assign stage1_in.winner_coord = stage0_out.intermediate_node;
assign stage1_in.input_port = 4'b0001; // 标识来自A口

// Stage 1 输出 (暂无仲裁，直接传递)
assign stage1_out = stage1_in;

// ====================================================================
// Stage 2: 输出选择和缓冲
// ====================================================================

assign stage2_in = '0;
assign stage2_in.vld   = stage1_out.vld;
assign stage2_in.qos   = stage1_out.qos;
assign stage2_in.type  = stage1_out.type;
assign stage2_in.src   = stage1_out.src;
assign stage2_in.tgt   = stage1_out.tgt;
assign stage2_in.data  = stage1_out.data;
assign stage2_in.output_coord = stage1_out.winner_coord;
assign stage2_in.output_port = 4'b0000;

// Stage 2 输出 (直接传递)
assign stage2_out = stage2_in;

// ====================================================================
// Stage 3: 输出到拓扑连接
// ====================================================================

assign stage3_in = '0;
assign stage3_in.vld   = stage2_out.vld;
assign stage3_in.qos   = stage2_out.qos;
assign stage3_in.type  = stage2_out.type;
assign stage3_in.src   = stage2_out.src;
assign stage3_in.tgt   = stage2_out.tgt;
assign stage3_in.data  = stage2_out.data;
assign stage3_in.output_port = stage2_out.output_port;

// 输出缓冲 (简化为寄存器)
always @(posedge node_clk or negedge rst_n) begin
    if (!rst_n) begin
        stage3_out.vld <= 1'b0;
        stage3_out.qos <= 1'b0;
        stage3_out.type <= 2'b00;
        stage3_out.src <= 6'b000000;
        stage3_out.tgt <= 6'b000000;
        stage3_out.data <= 8'b00000000;
        stage3_out.output_port <= 4'b0000;
    end else begin
        stage3_out.vld <= stage3_in.vld;
        stage3_out.qos <= stage3_in.qos;
        stage3_out.type <= stage3_in.type;
        stage3_out.src <= stage3_in.src;
        stage3_out.tgt <= stage3_in.tgt;
        stage3_out.data <= stage3_in.data;
        stage3_out.output_port <= stage3_in.output_port;
    end
end

// ====================================================================
// 输出连接
// ====================================================================

// B口输出 (仅当目标节点是本节点时)
assign pkt_o.pkt_out_vld = stage3_out.vld && (stage3_out.tgt == NODE_COORD);
assign pkt_o.pkt_out_qos = stage3_out.qos;
assign pkt_o.pkt_out_type = stage3_out.type;
assign pkt_o.pkt_out_src = stage3_out.src;
assign pkt_o.pkt_out_tgt = stage3_out.tgt;
assign pkt_o.pkt_out_data = stage3_out.data;

// B口ready信号 (假设总是准备好)
wire b_port_rdy = 1'b1;
assign pkt_o.pkt_out_rdy = b_port_rdy;

// C接口输出 (需要根据实际连接实现)
assign pkt_con_out.x_vld = '0;
assign pkt_con_out.x_qos = '0;
assign pkt_con_out.x_type = '0;
assign pkt_con_out.x_src = '0;
assign pkt_con_out.x_tgt = '0;
assign pkt_con_out.x_data = '0;
assign pkt_con_out.y_vld = '0;
assign pkt_con_out.y_qos = '0;
assign pkt_con_out.y_type = '0;
assign pkt_con_out.y_src = '0;
assign pkt_con_out.y_tgt = '0;
assign pkt_con_out.y_data = '0;

// 反压信号
assign a_port_rdy = 1'b1;  // 暂时设为总是准备好
assign c_ports_rdy = 1'b1; // 暂时设为总是准备好

endmodule