// =============================================================================
// MAZE网络节点模块 - 模块化实现
// =============================================================================
// 功能说明：
// 1. 非流水线直接路由架构，2时钟周期总延迟
// 2. 支持四方向网格连接和故障感知XY路由算法
// 3. 5个独立路由单元，每个输入端口对应一个路由器
// 4. 5个QoS仲裁器，每个输出端口对应一个4输入QoS仲裁器
// 5. IRS_N缓冲器用于输入输出流量控制和寄存器功能
// 6. 支持故障容错和时钟门控
// 7. 边缘节点特殊处理，防止越界访问
// 8. 关键设计：IRS_N内部提供寄存器功能，无需额外打拍
// =============================================================================

// =============================================================================
// MAZE网络节点主模块
// =============================================================================
`timescale 1ns/1ps
`include "param.v"
module NODE #(
    parameter HP = 0,                    // 水平坐标 (0-7)
    parameter VP = 0                     // 垂直坐标 (0-7)
) (
    // 时钟和复位
    input wire clk,
    input wire rst_n,

    // 故障容错配置
    input wire pg_en,                   // 故障使能信号
    input wire [5:0] pg_node,          // 故障节点坐标

    // 接口连接
    pkt_in.mst pkt_i,                    // A接口输入 - 外部数据包输入
    pkt_out.mst pkt_o,                   // B接口输出 - 外部数据包输出
    pkt_con_if.mst pkt_con               // C接口 - 四方向网格连接
);

    // 直接使用HP/VP作为当前节点坐标，使用pg_node位段作为故障节点坐标

    // 故障相对位置计算
    wire [3:0] fault_relative_pos;           // 故障相对位置（需要4位支持9种状态）
    wire [5:0] new_tgt;                  // 经过multi_packet_gen生成的新目标地址
    wire tgt_is_pg;
    wire cpy_mode;

    wire [4:0]  route_req_N;
    wire [4:0]  route_req_S;
    wire [4:0]  route_req_E;
    wire [4:0]  route_req_W;
    wire [4:0]  route_req_A;

    wire [4:0]  arb_req[4:0];   // arb_req[from_input][to_output]
    wire [4:0]  arb_gnt[4:0];   // arb_gnt[from_input][to_output]
    wire [`PKT_W-1:0]  pld_buf[4:0];
    wire [4:0]  obuf_rdy;
    wire pkt_in_qos_A_buffered;
    wire [1:0]  pkt_in_type_A_buffered;
    wire [5:0]  pkt_in_src_A_buffered;
    wire [5:0]  pkt_in_tgt_A_buffered;
    wire [7:0]  pkt_in_data_A_buffered;

    // 内部信号，用于解决多重驱动问题
    wire pkt_in_ctrl_rdy;
    wire pkt_in_data_rdy;

    assign pld_buf[`DIR_A] = {pkt_in_qos_A_buffered, pkt_in_type_A_buffered, pkt_in_src_A_buffered, pkt_in_tgt_A_buffered, pkt_in_data_A_buffered};

    // 组合pkt_in_rdy信号，避免多重驱动
    assign pkt_i.pkt_in_rdy = pkt_in_ctrl_rdy && pkt_in_data_rdy;

fault_relative_pos_detect#(
    .LOCAL_X ( HP ),
    .LOCAL_Y ( VP )
)u_fault_relative_pos_detect(
    .pg_en   ( pg_en   ),
    .pg_node ( pg_node ),
    .fault_relative_pos  ( fault_relative_pos  )
);

multi_packet_gen#(
    .LOCAL_X      ( HP ),
    .LOCAL_Y      ( VP )
)u_multi_packet_gen(
    .clk          ( clk          ),
    .rst_n        ( rst_n        ),
    .pkt_type_A   ( pkt_i.pkt_in_type   ),
    .tgt_A        ( pkt_i.pkt_in_tgt        ),
    .pkt_type_buf ( pkt_in_type_A_buffered ),
    .tgt_buf      ( pkt_in_tgt_A_buffered ),
    .pg_en        ( pg_en        ),
    .pg_node      ( pg_node      ),
    .vld          ( pkt_i.pkt_in_vld          ),
    .rdy          ( pkt_i.pkt_in_rdy          ),
    .new_tgt      ( new_tgt      ),
    .tgt_is_pg    ( tgt_is_pg    ),
    .cpy_mode     ( cpy_mode     )
);


pre_router#(
    .LOCAL_X              ( HP ),
    .LOCAL_Y              ( VP ),
    .router_id              ( `DIR_A )
)u_router_A(
    .tgt_x              ( new_tgt[2:0]              ),
    .tgt_y              ( new_tgt[5:3]              ),
    .src_x              ( pkt_i.pkt_in_src[2:0]              ),
    .src_y              ( pkt_i.pkt_in_src[5:3]              ),
    .pkt_type           ( pkt_i.pkt_in_type           ),
    .pg_en              ( pg_en              ),
    .fault_relative_pos ( fault_relative_pos ),
    .route_req          ( route_req_A          )
);

pre_router#(
    .LOCAL_X              ( HP ),
    .LOCAL_Y              ( VP ),
    .router_id              ( `DIR_N )
)u_router_N(
    .tgt_x              ( pkt_con.ni_tgt[2:0]              ),
    .tgt_y              ( pkt_con.ni_tgt[5:3]              ),
    .src_x              ( pkt_con.ni_src[2:0]              ),
    .src_y              ( pkt_con.ni_src[5:3]              ),
    .pkt_type           ( pkt_con.ni_type           ),
    .pg_en              ( pg_en              ),
    .fault_relative_pos ( fault_relative_pos ),
    .route_req          ( route_req_N          )
);


pre_router#(
    .LOCAL_X              ( HP ),
    .LOCAL_Y              ( VP ),
    .router_id            ( `DIR_S )
)u_router_S(
    .tgt_x              ( pkt_con.si_tgt[2:0]              ),
    .tgt_y              ( pkt_con.si_tgt[5:3]              ),
    .src_x              ( pkt_con.si_src[2:0]              ),
    .src_y              ( pkt_con.si_src[5:3]              ),
    .pkt_type           ( pkt_con.si_type           ),
    .pg_en              ( pg_en              ),
    .fault_relative_pos ( fault_relative_pos ),
    .route_req          ( route_req_S          )
);


pre_router#(
    .LOCAL_X              ( HP ),
    .LOCAL_Y              ( VP ),
    .router_id            ( `DIR_E )
)u_router_E(
    .tgt_x              ( pkt_con.ei_tgt[2:0]              ),
    .tgt_y              ( pkt_con.ei_tgt[5:3]              ),
    .src_x              ( pkt_con.ei_src[2:0]              ),
    .src_y              ( pkt_con.ei_src[5:3]              ),
    .pkt_type           ( pkt_con.ei_type           ),
    .pg_en              ( pg_en              ),
    .fault_relative_pos ( fault_relative_pos ),
    .route_req          ( route_req_E          )
);


pre_router#(
    .LOCAL_X              ( HP ),
    .LOCAL_Y              ( VP ),
    .router_id            ( `DIR_W )
)u_router_W(
    .tgt_x              ( pkt_con.wi_tgt[2:0]              ),
    .tgt_y              ( pkt_con.wi_tgt[5:3]              ),
    .src_x              ( pkt_con.wi_src[2:0]              ),
    .src_y              ( pkt_con.wi_src[5:3]              ),
    .pkt_type           ( pkt_con.wi_type           ),
    .pg_en              ( pg_en              ),
    .fault_relative_pos ( fault_relative_pos ),
    .route_req          ( route_req_W          )
);


IBUF_A_CTRL#(
    .PYLD_W    ( 6 )
)u_IBUF_A_CTRL(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_i.pkt_in_vld  ),
    .pg_en     ( pg_en     ),
    .cpy_mode  ( cpy_mode  ),
    .ibuf_rdy  ( pkt_in_ctrl_rdy  ),
    .route_req ( route_req_A & {5{~tgt_is_pg}} ),
    .payload_i ( pkt_i.pkt_in_tgt ),
    .arb_req   ( arb_req[`DIR_A]   ),
    .arb_gnt   ( arb_gnt[`DIR_A]   ),
    .obuf_rdy  ( obuf_rdy[4:0] | {5{tgt_is_pg}}  ),
    .payload_o  ( pkt_in_tgt_A_buffered  )
);

IBUF_A_DATA#(
    .PYLD_W    ( 17 )
)u_IBUF_A_DATA(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_i.pkt_in_vld  ),
    .pg_en     ( pg_en     ),
    .cpy_mode  ( cpy_mode  ),
    .ibuf_rdy  ( pkt_in_data_rdy    ),
    .payload_i ( {pkt_i.pkt_in_qos, pkt_i.pkt_in_type, pkt_i.pkt_in_src, pkt_i.pkt_in_data}  ),
    .arb_req   ( arb_req[`DIR_A]   ),
    .arb_gnt   ( arb_gnt[`DIR_A]   ),
    .obuf_rdy  ( {obuf_rdy[`DIR_B], obuf_rdy[`DIR_E], obuf_rdy[`DIR_S], obuf_rdy[`DIR_W], obuf_rdy[`DIR_N]} ),
    .payload_o  ( {pkt_in_qos_A_buffered, pkt_in_type_A_buffered, pkt_in_src_A_buffered, pkt_in_data_A_buffered}  )
);


IBUF#(
    .PYLD_W    ( `PKT_W )
)u_IBUF_N(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_con.ni_vld  ),
    .ibuf_rdy  ( pkt_con.ni_rdy  ),
    .route_req ( route_req_N ),
    .payload_i ( {pkt_con.ni_qos, pkt_con.ni_type, pkt_con.ni_src, pkt_con.ni_tgt, pkt_con.ni_data} ),
    .arb_req   ( arb_req[`DIR_N]   ),
    .arb_gnt   ( arb_gnt[`DIR_N]   ),
    .obuf_rdy  ( {obuf_rdy[`DIR_B], obuf_rdy[`DIR_E], obuf_rdy[`DIR_S], obuf_rdy[`DIR_W], obuf_rdy[`DIR_N]}),
    .payload_o  ( pld_buf[`DIR_N]  )
);


IBUF#(
    .PYLD_W    ( `PKT_W )
)u_IBUF_W(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_con.wi_vld  ),
    .ibuf_rdy  ( pkt_con.wi_rdy  ),
    .route_req ( route_req_W ),
    .payload_i ( {pkt_con.wi_qos, pkt_con.wi_type, pkt_con.wi_src, pkt_con.wi_tgt, pkt_con.wi_data} ),
    .arb_req   ( arb_req[`DIR_W]   ),
    .arb_gnt   ( arb_gnt[`DIR_W]   ),
    .obuf_rdy  ( {obuf_rdy[`DIR_B], obuf_rdy[`DIR_E], obuf_rdy[`DIR_S], obuf_rdy[`DIR_W], obuf_rdy[`DIR_N]}),
    .payload_o  ( pld_buf[`DIR_W]  )
);

IBUF#(
    .PYLD_W    ( `PKT_W )
)u_IBUF_S(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_con.si_vld  ),
    .ibuf_rdy  ( pkt_con.si_rdy  ),
    .route_req ( route_req_S ),
    .payload_i ( {pkt_con.si_qos, pkt_con.si_type, pkt_con.si_src, pkt_con.si_tgt, pkt_con.si_data} ),
    .arb_req   ( arb_req[`DIR_S]   ),
    .arb_gnt   ( arb_gnt[`DIR_S]   ),
    .obuf_rdy  ( {obuf_rdy[`DIR_B], obuf_rdy[`DIR_E], obuf_rdy[`DIR_S], obuf_rdy[`DIR_W], obuf_rdy[`DIR_N]}),
    .payload_o  ( pld_buf[`DIR_S]  )
);



IBUF#(
    .PYLD_W    ( `PKT_W )
)u_IBUF_E(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_con.ei_vld  ),
    .ibuf_rdy  ( pkt_con.ei_rdy  ),
    .route_req ( route_req_E ),
    .payload_i ( {pkt_con.ei_qos, pkt_con.ei_type, pkt_con.ei_src, pkt_con.ei_tgt, pkt_con.ei_data} ),
    .arb_req   ( arb_req[`DIR_E]   ),
    .arb_gnt   ( arb_gnt[`DIR_E]   ),
    .obuf_rdy  ( {obuf_rdy[`DIR_B], obuf_rdy[`DIR_E], obuf_rdy[`DIR_S], obuf_rdy[`DIR_W], obuf_rdy[`DIR_N]}),
    .payload_o  ( pld_buf[`DIR_E]  )
);


    // 仲裁器请求信号映射
    logic [3:0] arb_req_N, arb_qos_N, arb_gnt_N;  // 北仲裁器：4个输入(A,W,S,E)，排除北输入
    logic [3:0] arb_req_W, arb_qos_W, arb_gnt_W;  // 西仲裁器：4个输入(A,N,S,E)，排除西输入
    logic [3:0] arb_req_S, arb_qos_S, arb_gnt_S;  // 南仲裁器：4个输入(A,N,W,E)，排除南输入
    logic [3:0] arb_req_E, arb_qos_E, arb_gnt_E;  // 东仲裁器：4个输入(A,N,W,S)，排除东输入
    logic [4:0] arb_req_B, arb_qos_B, arb_gnt_B;  // B仲裁器：支持所有4个输入(A,N,W,S,E)

    // 仲裁器输入映射 - 使用常量`QOS_POS确保一致性
    // 北仲裁器：4个输入，排除来自北方的输入 [A,W,S,E]
    assign arb_req_N = {arb_req[`DIR_B][0], arb_req[`DIR_W][0], arb_req[`DIR_S][0], arb_req[`DIR_E][0]};
    assign arb_qos_N = {pld_buf[`DIR_A][`QOS_POS], pld_buf[`DIR_W][`QOS_POS], pld_buf[`DIR_S][`QOS_POS], pld_buf[`DIR_E][`QOS_POS]};

    // 西仲裁器：4个输入，排除来自西方的输入 [A,N,S,E]
    assign arb_req_W = {arb_req[`DIR_B][1], arb_req[`DIR_N][1], arb_req[`DIR_S][1], arb_req[`DIR_E][1]};
    assign arb_qos_W = {pld_buf[`DIR_A][`QOS_POS], pld_buf[`DIR_N][`QOS_POS], pld_buf[`DIR_S][`QOS_POS], pld_buf[`DIR_E][`QOS_POS]};

    // 南仲裁器：4个输入，排除来自南方的输入 [A,N,W,E]
    assign arb_req_S = {arb_req[`DIR_B][2], arb_req[`DIR_N][2], arb_req[`DIR_W][2], arb_req[`DIR_E][2]};
    assign arb_qos_S = {pld_buf[`DIR_A][`QOS_POS], pld_buf[`DIR_N][`QOS_POS], pld_buf[`DIR_W][`QOS_POS], pld_buf[`DIR_E][`QOS_POS]};

    // 东仲裁器：4个输入，排除来自东方的输入 [A,N,W,S]
    assign arb_req_E = {arb_req[`DIR_B][3], arb_req[`DIR_N][3], arb_req[`DIR_W][3], arb_req[`DIR_S][3]};
    assign arb_qos_E = {pld_buf[`DIR_A][`QOS_POS], pld_buf[`DIR_N][`QOS_POS], pld_buf[`DIR_W][`QOS_POS], pld_buf[`DIR_S][`QOS_POS]};

    // B仲裁器：支持所有5个输入 [A,N,W,S,E]
    assign arb_req_B = {arb_req[`DIR_B][4], arb_req[`DIR_N][4], arb_req[`DIR_W][4], arb_req[`DIR_S][4], arb_req[`DIR_E][4]};
    assign arb_qos_B = {pld_buf[`DIR_A][`QOS_POS], pld_buf[`DIR_N][`QOS_POS], pld_buf[`DIR_W][`QOS_POS], pld_buf[`DIR_S][`QOS_POS], pld_buf[`DIR_E][`QOS_POS]};

    assign arb_gnt[`DIR_A] = {arb_gnt_B[4], arb_gnt_E[3], arb_gnt_S[3], arb_gnt_W[3], arb_gnt_N[3]};
    assign arb_gnt[`DIR_E] = {arb_gnt_B[0], 1'b0, arb_gnt_S[0], arb_gnt_W[0], arb_gnt_N[0]};
    assign arb_gnt[`DIR_S] = {arb_gnt_B[1], arb_gnt_E[0], 1'b0, arb_gnt_W[1], arb_gnt_N[1]};
    assign arb_gnt[`DIR_W] = {arb_gnt_B[2], arb_gnt_E[1], arb_gnt_S[1], 1'b0, arb_gnt_N[2]};
    assign arb_gnt[`DIR_N] = {arb_gnt_B[3], arb_gnt_E[2], arb_gnt_S[2], arb_gnt_W[2], 1'b0};
    // 实例化仲裁器 - 所有仲裁器都使用WIDTH=4
    // 北仲裁器：4输入仲裁器，排除北输入 [A,W,S,E]
    arbiter #(.WIDTH(4)) u_arbiter_N (
        .req(arb_req_N),
        .qos(arb_qos_N),
        .gnt(arb_gnt_N)
    );

    // 西仲裁器：4输入仲裁器，排除西输入 [A,N,S,E]
    arbiter #(.WIDTH(4)) u_arbiter_W (
        .req(arb_req_W),
        .qos(arb_qos_W),
        .gnt(arb_gnt_W)
    );

    // 南仲裁器：4输入仲裁器，排除南输入 [A,N,W,E]
    arbiter #(.WIDTH(4)) u_arbiter_S (
        .req(arb_req_S),
        .qos(arb_qos_S),
        .gnt(arb_gnt_S)
    );

    // 东仲裁器：4输入仲裁器，排除东输入 [A,N,W,S]
    arbiter #(.WIDTH(4)) u_arbiter_E (
        .req(arb_req_E),
        .qos(arb_qos_E),
        .gnt(arb_gnt_E)
    );

    // B仲裁器：5输入仲裁器，支持所有输入 [A,N,W,S,E]
    arbiter #(.WIDTH(5)) u_arbiter_B (
        .req(arb_req_B),
        .qos(arb_qos_B),
        .gnt(arb_gnt_B)
    );

    // =============================================================================
    // 仲裁胜出数据选择
    // =============================================================================

    logic [`PKT_W-1:0] pkt_N, pkt_W, pkt_S, pkt_E, pkt_B;

    // 使用选择器信号进行数据选择
    // 注意：仲裁器输入映射 [A,W,S,E], [A,N,S,E], [A,N,W,E], [A,N,W,S], [A,N,W,S,E]
    always_comb begin
        // 北输出选择 - 映射：[A,W,S,E]
        if (arb_gnt_N[3]) begin pkt_N = pld_buf[`DIR_A]; end    // bit3: A输入
        else if (arb_gnt_N[2]) begin pkt_N = pld_buf[`DIR_W]; end  // bit2: W输入
        else if (arb_gnt_N[1]) begin pkt_N = pld_buf[`DIR_S]; end  // bit1: S输入
        else if (arb_gnt_N[0]) begin pkt_N = pld_buf[`DIR_E]; end  // bit0: E输入
        else begin pkt_N = {`PKT_W{1'b0}}; end

        // 西输出选择 - 映射：[A,N,S,E]
        if (arb_gnt_W[3]) begin pkt_W = pld_buf[`DIR_A]; end    // bit3: A输入
        else if (arb_gnt_W[2]) begin pkt_W = pld_buf[`DIR_N]; end  // bit2: N输入
        else if (arb_gnt_W[1]) begin pkt_W = pld_buf[`DIR_S]; end  // bit1: S输入
        else if (arb_gnt_W[0]) begin pkt_W = pld_buf[`DIR_E]; end  // bit0: E输入
        else begin pkt_W = {`PKT_W{1'b0}}; end

        // 南输出选择 - 映射：[A,N,W,E]
        if (arb_gnt_S[3]) begin pkt_S = pld_buf[`DIR_A]; end    // bit3: A输入
        else if (arb_gnt_S[2]) begin pkt_S = pld_buf[`DIR_N]; end  // bit2: N输入
        else if (arb_gnt_S[1]) begin pkt_S = pld_buf[`DIR_W]; end  // bit1: W输入
        else if (arb_gnt_S[0]) begin pkt_S = pld_buf[`DIR_E]; end  // bit0: E输入
        else begin pkt_S = {`PKT_W{1'b0}}; end

        // 东输出选择 - 映射：[A,N,W,S]
        if (arb_gnt_E[3]) begin pkt_E = pld_buf[`DIR_A]; end    // bit3: A输入
        else if (arb_gnt_E[2]) begin pkt_E = pld_buf[`DIR_N]; end  // bit2: N输入
        else if (arb_gnt_E[1]) begin pkt_E = pld_buf[`DIR_W]; end  // bit1: W输入
        else if (arb_gnt_E[0]) begin pkt_E = pld_buf[`DIR_S]; end  // bit0: S输入
        else begin pkt_E = {`PKT_W{1'b0}}; end

        // B输出选择（本地输出）- 映射：[A,N,W,S,E]
        if (arb_gnt_B[4]) begin pkt_B = pld_buf[`DIR_A]; end    // bit4: A输入
        else if (arb_gnt_B[3]) begin pkt_B = pld_buf[`DIR_N]; end  // bit3: N输入
        else if (arb_gnt_B[2]) begin pkt_B = pld_buf[`DIR_W]; end  // bit2: W输入
        else if (arb_gnt_B[1]) begin pkt_B = pld_buf[`DIR_S]; end  // bit1: S输入
        else if (arb_gnt_B[0]) begin pkt_B = pld_buf[`DIR_E]; end  // bit0: E输入
        else begin pkt_B = {`PKT_W{1'b0}}; end
    end

    // =============================================================================
    // 输出IRS_N缓冲器 (寄存器输出模式RO_EN=1)
    // =============================================================================

    logic n_out_valid, n_out_ready;
    logic [`PKT_W-1:0] n_out_pkt;


    OBUF #(
        .PYLD_W(`PKT_W)
    ) U_OBUF_N (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_N),
        .ready_o(obuf_rdy[`DIR_N]),      // 内部使用，告知上游是否ready
        .ready_i(pkt_con.no_rdy),   // 连接到C接口北输出端口的ready信号
        .valid_o(n_out_valid),
        .payload_i(pkt_N),
        .payload_o(n_out_pkt)
    );

    logic w_out_valid, w_out_ready;
    logic [`PKT_W-1:0] w_out_pkt;


    OBUF #(
        .PYLD_W (`PKT_W)
    ) U_OBUF_W (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_W),
        .ready_i(pkt_con.wo_rdy),   // 连接到C接口西输出端口的ready信号
        .valid_o(w_out_valid),
        .ready_o(obuf_rdy[`DIR_W]),      // 内部使用，告知上游是否ready
        .payload_i(pkt_W),
        .payload_o(w_out_pkt)
    );

    logic s_out_valid, s_out_ready;
    logic [`PKT_W-1:0] s_out_pkt;

    OBUF #(
          .PYLD_W (`PKT_W)
          ,.RO_EN(1)
    ) U_OBUF_S (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_S),
        .ready_i(pkt_con.so_rdy),   // 连接到C接口南输出端口的ready信号
        .valid_o(s_out_valid),
        .ready_o(obuf_rdy[`DIR_S]),      // 内部使用，告知上游是否ready
        .payload_i(pkt_S),
        .payload_o(s_out_pkt)
    );

    logic e_out_valid, e_out_ready;
    logic [`PKT_W-1:0] e_out_pkt;

    OBUF #(
          .PYLD_W (`PKT_W)
          ,.RO_EN(1)
    ) U_OBUF_E (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_E),
        .ready_i(pkt_con.eo_rdy),   // 连接到C接口东输出端口的ready信号
        .valid_o(e_out_valid),
        .ready_o(obuf_rdy[`DIR_E]),      // 内部使用，告知上游是否ready
        .payload_i(pkt_E),
        .payload_o(e_out_pkt)
    );

    logic b_out_valid, b_out_ready;
    logic [`PKT_W-1:0] b_out_pkt;

    OBUF #(
          .PYLD_W (`PKT_W)
          ,.RO_EN(1)
    ) U_OBUF_B (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_B),
        .ready_i(pkt_o.pkt_out_rdy), // 连接到B接口输出端口的ready信号
        .valid_o(b_out_valid),
        .ready_o(obuf_rdy[`DIR_B]),       // 内部使用，告知上游是否ready
        .payload_i(pkt_B),
        .payload_o(b_out_pkt)
    );

    // =============================================================================
    // 直接组合逻辑输出 (IRS_N内部已提供寄存器功能)
    // =============================================================================

    // B接口输出 - 直接连接IRS_N输出
    assign pkt_o.pkt_out_vld = b_out_valid;
    assign pkt_o.pkt_out_qos = b_out_pkt[`QOS_POS];
    assign pkt_o.pkt_out_type = b_out_pkt[`TYPE_POS_HI:`TYPE_POS_LO];
    assign pkt_o.pkt_out_src = b_out_pkt[`SRC_POS_HI:`SRC_POS_LO];
    assign pkt_o.pkt_out_tgt = b_out_pkt[`TGT_POS_HI:`TGT_POS_LO];
    assign pkt_o.pkt_out_data = b_out_pkt[7:0];

    // C接口北方向输出 - 直接连接IRS_N输出
    assign pkt_con.no_vld = n_out_valid;
    assign pkt_con.no_qos = n_out_pkt[`QOS_POS];
    assign pkt_con.no_type = n_out_pkt[`TYPE_POS_HI:`TYPE_POS_LO];
    assign pkt_con.no_src = n_out_pkt[`SRC_POS_HI:`SRC_POS_LO];
    assign pkt_con.no_tgt = n_out_pkt[`TGT_POS_HI:`TGT_POS_LO];
    assign pkt_con.no_data = n_out_pkt[7:0];

    // C接口西方向输出 - 直接连接IRS_N输出
    assign pkt_con.wo_vld = w_out_valid;
    assign pkt_con.wo_qos = w_out_pkt[`QOS_POS];
    assign pkt_con.wo_type = w_out_pkt[`TYPE_POS_HI:`TYPE_POS_LO];
    assign pkt_con.wo_src = w_out_pkt[`SRC_POS_HI:`SRC_POS_LO];
    assign pkt_con.wo_tgt = w_out_pkt[`TGT_POS_HI:`TGT_POS_LO];
    assign pkt_con.wo_data = w_out_pkt[7:0];

    // C接口南方向输出 - 直接连接IRS_N输出
    assign pkt_con.so_vld = s_out_valid;
    assign pkt_con.so_qos = s_out_pkt[`QOS_POS];
    assign pkt_con.so_type = s_out_pkt[`TYPE_POS_HI:`TYPE_POS_LO];
    assign pkt_con.so_src = s_out_pkt[`SRC_POS_HI:`SRC_POS_LO];
    assign pkt_con.so_tgt = s_out_pkt[`TGT_POS_HI:`TGT_POS_LO];
    assign pkt_con.so_data = s_out_pkt[7:0];

    // C接口东方向输出 - 直接连接IRS_N输出
    assign pkt_con.eo_vld = e_out_valid;
    assign pkt_con.eo_qos = e_out_pkt[`QOS_POS];
    assign pkt_con.eo_type = e_out_pkt[`TYPE_POS_HI:`TYPE_POS_LO];
    assign pkt_con.eo_src = e_out_pkt[`SRC_POS_HI:`SRC_POS_LO];
    assign pkt_con.eo_tgt = e_out_pkt[`TGT_POS_HI:`TGT_POS_LO];
    assign pkt_con.eo_data = e_out_pkt[7:0];


endmodule
