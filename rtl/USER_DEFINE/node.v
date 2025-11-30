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

    localparam   LOC_X = HP;
    localparam   LOC_Y = VP;
    // 直接使用HP/VP作为当前节点坐标，使用pg_node位段作为故障节点坐标


    wire [6:0]  route_req_N;
    wire [6:0]  route_req_S;
    wire [6:0]  route_req_E;
    wire [6:0]  route_req_W;
    wire [6:0]  route_req_A;
    wire [6:0]  route_req_Q;
    wire [6:0]  route_req_R;


    wire [6:0]  arb_req[6:0];   // arb_req[from_input][to_output]
    wire [6:0]  arb_gnt[6:0];   // arb_gnt[from_input][to_output]
    wire [`PKT_W-1:0]  pld_buf[6:0];
    wire [6:0]  obuf_rdy;
    wire [`PKT_W-1:0] pkt_N, pkt_W, pkt_S, pkt_E, ,pkt_Q, pkt_R, pkt_B;


pre_router#(
    .LOC_X              ( HP ),
    .LOC_Y              ( VP ),
    .router_id            ( `DIR_A )
)u_router_A(
    .tgt_x              ( pkt_i.pkt_in_tgt[2:0]              ),
    .tgt_y              ( pkt_i.pkt_in_tgt[2:0]              ),
    .pkt_type           ( pkt_i.pkt_in_type           ),
    .pg_en              ( pg_en              ),
    .route_req          ( route_req_A          )
);

IBUF#(
    .PYLD_W    ( `PKT_W )
)u_IBUF_A(
    .clk       ( clk       ),
    .rst_n     ( rst_n     ),
    .ibuf_vld  ( pkt_i.pkt_in_vld  ),
    .ibuf_rdy  ( pkt_in_data_rdy  ),
    .route_req ( route_req_A ),
    .payload_i ( {pkt_i.pkt_in_qos, pkt_i.pkt_in_type, pkt_i.pkt_in_src, pkt_i.pkt_in_tgt, pkt_i.pkt_in_data} ),
    .arb_req   ( arb_req[`DIR_A]   ),
    .arb_gnt   ( arb_gnt[`DIR_A]   ),
    .obuf_rdy  ( obuf_rdy),
    .payload_o  ( pld_buf[`DIR_A]  )
);

`PRE_ROUTER(Q, `DIR_Q, q);
`PRE_ROUTER(W, `DIR_W, w);
`PRE_ROUTER(E, `DIR_E, e);
`PRE_ROUTER(R, `DIR_R, r);
`PRE_ROUTER(N, `DIR_N, n);
`PRE_ROUTER(S, `DIR_S, s);

`IBUF(Q, `DIR_Q, q);
`IBUF(W, `DIR_W, w);
`IBUF(E, `DIR_E, e);
`IBUF(R, `DIR_R, r);
`IBUF(N, `DIR_N, n);
`IBUF(S, `DIR_S, s);




// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_N(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.ni_vld  ),
//     .ibuf_rdy  ( pkt_con.ni_rdy  ),
//     .route_req ( route_req_N ),
//     .payload_i ( {pkt_con.ni_qos, pkt_con.ni_type, pkt_con.ni_src, pkt_con.ni_tgt, pkt_con.ni_data} ),
//     .arb_req   ( arb_req[`DIR_N]   ),
//     .arb_gnt   ( arb_gnt[`DIR_N]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_N]  )
// );


// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_W(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.wi_vld  ),
//     .ibuf_rdy  ( pkt_con.wi_rdy  ),
//     .route_req ( route_req_W ),
//     .payload_i ( {pkt_con.wi_qos, pkt_con.wi_type, pkt_con.wi_src, pkt_con.wi_tgt, pkt_con.wi_data} ),
//     .arb_req   ( arb_req[`DIR_W]   ),
//     .arb_gnt   ( arb_gnt[`DIR_W]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_W]  )
// );

// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_S(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.si_vld  ),
//     .ibuf_rdy  ( pkt_con.si_rdy  ),
//     .route_req ( route_req_S ),
//     .payload_i ( {pkt_con.si_qos, pkt_con.si_type, pkt_con.si_src, pkt_con.si_tgt, pkt_con.si_data} ),
//     .arb_req   ( arb_req[`DIR_S]   ),
//     .arb_gnt   ( arb_gnt[`DIR_S]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_S]  )
// );



// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_E(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.ei_vld  ),
//     .ibuf_rdy  ( pkt_con.ei_rdy  ),
//     .route_req ( route_req_E ),
//     .payload_i ( {pkt_con.ei_qos, pkt_con.ei_type, pkt_con.ei_src, pkt_con.ei_tgt, pkt_con.ei_data} ),
//     .arb_req   ( arb_req[`DIR_E]   ),
//     .arb_gnt   ( arb_gnt[`DIR_E]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_E]  )
// );

// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_Q(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.qi_vld  ),
//     .ibuf_rdy  ( pkt_con.qi_rdy  ),
//     .route_req ( route_req_Q ),
//     .payload_i ( {pkt_con.qi_qos, pkt_con.qi_type, pkt_con.qi_src, pkt_con.qi_tgt, pkt_con.qi_data} ),
//     .arb_req   ( arb_req[`DIR_Q]   ),
//     .arb_gnt   ( arb_gnt[`DIR_Q]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_Q]  )
// );


// IBUF#(
//     .PYLD_W    ( `PKT_W )
// )u_IBUF_R(
//     .clk       ( clk       ),
//     .rst_n     ( rst_n     ),
//     .ibuf_vld  ( pkt_con.ri_vld  ),
//     .ibuf_rdy  ( pkt_con.ri_rdy  ),
//     .route_req ( route_req_R ),
//     .payload_i ( {pkt_con.ri_qos, pkt_con.ri_type, pkt_con.ri_src, pkt_con.ri_tgt, pkt_con.ri_data} ),
//     .arb_req   ( arb_req[`DIR_R]   ),
//     .arb_gnt   ( arb_gnt[`DIR_R]   ),
//     .obuf_rdy  ( obuf_rdy),
//     .payload_o  ( pld_buf[`DIR_R]  )
// );

    // 仲裁器请求信号映射
    wire    [6:0]   arb_req_B, arb_req_Q, arb_req_W, arb_req_E, arb_req_R, arb_req_N, arb_req_S; 
    wire    [6:0]   arb_gnt_B, arb_gnt_Q, arb_gnt_W, arb_gnt_E, arb_gnt_R, arb_gnt_N, arb_gnt_S; 

    // {arb_req[`DIR_A][0], arb_req[`DIR_Q][0], arb_req[`DIR_W][0], arb_req[`DIR_E][0], arb_req[`DIR_R][0], arb_req[`DIR_N][0], arb_req[`DIR_S][0]}；
    assign arb_req_S = {arb_req[`DIR_A][0], arb_req[`DIR_Q][0], arb_req[`DIR_W][0], arb_req[`DIR_E][0], arb_req[`DIR_R][0], arb_req[`DIR_N][0], arb_req[`DIR_S][0]}；
    assign arb_req_N = {arb_req[`DIR_A][1], arb_req[`DIR_Q][1], arb_req[`DIR_W][1], arb_req[`DIR_E][1], arb_req[`DIR_R][1], arb_req[`DIR_N][1], arb_req[`DIR_S][1]}；
    assign arb_req_R = {arb_req[`DIR_A][2], arb_req[`DIR_Q][2], arb_req[`DIR_W][2], arb_req[`DIR_E][2], arb_req[`DIR_R][2], arb_req[`DIR_N][2], arb_req[`DIR_S][2]}；
    assign arb_req_E = {arb_req[`DIR_A][3], arb_req[`DIR_Q][3], arb_req[`DIR_W][3], arb_req[`DIR_E][3], arb_req[`DIR_R][3], arb_req[`DIR_N][3], arb_req[`DIR_S][3]}；
    assign arb_req_W = {arb_req[`DIR_A][4], arb_req[`DIR_Q][4], arb_req[`DIR_W][4], arb_req[`DIR_E][4], arb_req[`DIR_R][4], arb_req[`DIR_N][4], arb_req[`DIR_S][4]}；
    assign arb_req_Q = {arb_req[`DIR_A][5], arb_req[`DIR_Q][5], arb_req[`DIR_W][5], arb_req[`DIR_E][5], arb_req[`DIR_R][5], arb_req[`DIR_N][5], arb_req[`DIR_S][5]}；
    assign arb_req_B = {arb_req[`DIR_A][6], arb_req[`DIR_Q][6], arb_req[`DIR_W][6], arb_req[`DIR_E][6], arb_req[`DIR_R][6], arb_req[`DIR_N][6], arb_req[`DIR_S][6]}；
    assign arb_gnt_S = {arb_gnt[`DIR_A][0], arb_gnt[`DIR_Q][0], arb_gnt[`DIR_W][0], arb_gnt[`DIR_E][0], arb_gnt[`DIR_R][0], arb_gnt[`DIR_N][0], arb_gnt[`DIR_S][0]}；
    assign arb_gnt_N = {arb_gnt[`DIR_A][1], arb_gnt[`DIR_Q][1], arb_gnt[`DIR_W][1], arb_gnt[`DIR_E][1], arb_gnt[`DIR_R][1], arb_gnt[`DIR_N][1], arb_gnt[`DIR_S][1]}；
    assign arb_gnt_R = {arb_gnt[`DIR_A][2], arb_gnt[`DIR_Q][2], arb_gnt[`DIR_W][2], arb_gnt[`DIR_E][2], arb_gnt[`DIR_R][2], arb_gnt[`DIR_N][2], arb_gnt[`DIR_S][2]}；
    assign arb_gnt_E = {arb_gnt[`DIR_A][3], arb_gnt[`DIR_Q][3], arb_gnt[`DIR_W][3], arb_gnt[`DIR_E][3], arb_gnt[`DIR_R][3], arb_gnt[`DIR_N][3], arb_gnt[`DIR_S][3]}；
    assign arb_gnt_W = {arb_gnt[`DIR_A][4], arb_gnt[`DIR_Q][4], arb_gnt[`DIR_W][4], arb_gnt[`DIR_E][4], arb_gnt[`DIR_R][4], arb_gnt[`DIR_N][4], arb_gnt[`DIR_S][4]}；
    assign arb_gnt_Q = {arb_gnt[`DIR_A][5], arb_gnt[`DIR_Q][5], arb_gnt[`DIR_W][5], arb_gnt[`DIR_E][5], arb_gnt[`DIR_R][5], arb_gnt[`DIR_N][5], arb_gnt[`DIR_S][5]}；
    assign arb_gnt_B = {arb_gnt[`DIR_A][6], arb_gnt[`DIR_Q][6], arb_gnt[`DIR_W][6], arb_gnt[`DIR_E][6], arb_gnt[`DIR_R][6], arb_gnt[`DIR_N][6], arb_gnt[`DIR_S][6]}；

    // 实例化仲裁器 - 所有仲裁器都使用WIDTH=4
    // 北仲裁器：4输入仲裁器，排除北输入 [A,W,S,E]

    `ARB(S);
    `ARB(N);
    `ARB(R);
    `ARB(E);
    `ARB(W);
    `ARB(Q);
    `ARB(B);
    
    // arbiter #(.WIDTH(7)) u_arbiter_N (
    //     .req(arb_req_N),
    //     .qos(arb_qos_N),
    //     .gnt(arb_gnt_N)
    // );

    // // 西仲裁器：4输入仲裁器，排除西输入 [A,N,S,E]
    // arbiter #(.WIDTH(7)) u_arbiter_W (
    //     .req(arb_req_W),
    //     .qos(arb_qos_W),
    //     .gnt(arb_gnt_W)
    // );

    // // 南仲裁器：4输入仲裁器，排除南输入 [A,N,W,E]
    // arbiter #(.WIDTH(7)) u_arbiter_S (
    //     .req(arb_req_S),
    //     .qos(arb_qos_S),
    //     .gnt(arb_gnt_S)
    // );

    // // 东仲裁器：4输入仲裁器，排除东输入 [A,N,W,S]
    // arbiter #(.WIDTH(7)) u_arbiter_E (
    //     .req(arb_req_E),
    //     .qos(arb_qos_E),
    //     .gnt(arb_gnt_E)
    // );

    // // B仲裁器：5输入仲裁器，支持所有输入 [A,N,W,S,E]
    // arbiter #(.WIDTH(7)) u_arbiter_B (
    //     .req(arb_req_B),
    //     .qos(arb_qos_B),
    //     .gnt(arb_gnt_B)
    // );

    // =============================================================================
    // 仲裁胜出数据选择
    // =============================================================================


        `MUX(B);
        `MUX(Q);
        `MUX(W);
        `MUX(E);
        `MUX(R);
        `MUX(N);
        `MUX(S);

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
