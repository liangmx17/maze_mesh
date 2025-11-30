`define QOS_POS       20          // QoS位位置 (修复)
`define TYPE_POS_HI   22          // 类型位高位置
`define TYPE_POS_LO   21          // 类型位低位置
`define SRC_POS_HI    19          // 源ID高位置 (修复)
`define SRC_POS_LO    14          // 源ID低位置 (修复)
`define TGT_POS_HI    13          // 目标ID高位置 (修复)
`define TGT_POS_LO    8           // 目标ID低位置 (修复)

// 故障相对位置类型定义
`define NORMAL    4'd0  // 正常状态，无故障影响
`define N_OF_x    4'd1  // 当前节点在故障节点北方
`define NE_OF_x   4'd2  // 当前节点在故障节点东北方
`define E_OF_x    4'd3  // 当前节点在故障节点东方
`define SE_OF_x   4'd4  // 当前节点在故障节点东南方
`define S_OF_x    4'd5  // 当前节点在故障节点南方
`define SW_OF_x   4'd6  // 当前节点在故障节点西南方
`define W_OF_x    4'd7  // 当前节点在故障节点西方
`define NW_OF_x   4'd8  // 当前节点在故障节点西北方

// 路由方向定义
`define DIR_S     4'd0
`define DIR_N     4'd1   // 西方向
`define DIR_R     4'd2   // 东方向
`define DIR_E     4'd3   // 东方向
`define DIR_W     4'd4   // 北方向
`define DIR_Q     4'd5   // 南方向
`define DIR_B     4'd6   // 本地输出
`define DIR_A     4'd6   // 本地输入

`define PKT_W  23  // 2+1+6+6+8  23位

    .tgt_x              ( pkt_con.ni_tgt[2:0]              ),
    .tgt_y              ( pkt_con.ni_tgt[5:3]              ),

`define PRE_ROUTER(DIR_STR, DIR_ID, CONN_DIR) `"pre_router#(  \
                            .LOC_X              ( HP ), \
                            .LOC_Y              ( VP ), \
                            .router_id          ( ``DIR_ID`` )  \
                        )u_router_``DIR_STR``(                                \
                            .tgt_x              ( pkt_con.``CONN_DIR``i_tgt[2:0]              ), \
                            .tgt_y              ( pkt_con.``CONN_DIR``i_tgt[2:0]              ), \
                            .pkt_type           ( pkt_con.``CONN_DIR``i_type           ),        \
                            .pg_en              ( pg_en              ),                 \
                            .route_req          ( route_req_``DIR_STR``          )                \
                        );`"

`define IBUF(DIR_STR, DIR_ID, CONN_DIR)     `"  IBUF#(
                                                    .PYLD_W    ( `PKT_W )
                                                )u_IBUF_N(
                                                    .clk       ( clk       ),
                                                    .rst_n     ( rst_n     ),
                                                    .ibuf_vld  ( pkt_con.``CONN_DIR``i_vld  ),
                                                    .ibuf_rdy  ( pkt_con.``CONN_DIR``i_rdy  ),
                                                    .route_req ( route_req_``DIR_STR`` ),
                                                    .payload_i ( {pkt_con.``CONN_DIR``i_qos, pkt_con.``CONN_DIR``i_type, pkt_con.``CONN_DIR``i_src, pkt_con.``CONN_DIR``i_tgt, pkt_con.``CONN_DIR``i_data} ),
                                                    .arb_req   ( arb_req[`DIR_``DIR_STR``]   ),
                                                    .arb_gnt   ( arb_gnt[`DIR_``DIR_STR``]   ),
                                                    .obuf_rdy  ( obuf_rdy),
                                                    .payload_o  ( pld_buf[`DIR_``DIR_STR``]  )
                                                ); `"

`define ARB(DIR)    `"  arbiter #(.WIDTH(7)) u_arbiter_``DIR`` (
                            .req(arb_req_``DIR``),
                            .gnt(arb_gnt_``DIR``)
                        );`"

`define MUX(DIR)    `"assign    pkt_``DIR`` =   ({(`PKT_W){arb_gnt_``DIR``[`DIR_A]}} & pld_buf[`DIR_A]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_Q]}} & pld_buf[`DIR_Q]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_W]}} & pld_buf[`DIR_W]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_E]}} & pld_buf[`DIR_E]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_R]}} & pld_buf[`DIR_R]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_N]}} & pld_buf[`DIR_N]) | \
                                                ({(`PKT_W){arb_gnt_``DIR``[`DIR_S]}} & pld_buf[`DIR_S]) ; `"

`define OBUF(DIR,)     `"    OBUF #(
                                .PYLD_W(`PKT_W)
                            ) U_OBUF_``DIR`` (
                                .clk(clk),
                                .rst_n(rst_n),
                                .valid_i(|arb_gnt_``DIR``),
                                .ready_o(obuf_rdy[`DIR_``DIR``]),      // 内部使用，告知上游是否ready
                                .ready_i(pkt_con.no_rdy),   // 连接到C接口北输出端口的ready信号
                                .valid_o(n_out_valid),
                                .payload_i(pkt_``DIR``),
                                .payload_o(n_out_pkt)
                            );
