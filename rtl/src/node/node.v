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
module node #(
    parameter HP = 0,                    // 水平坐标 (0-7)
    parameter VP = 0                     // 垂直坐标 (0-7)
) (
    // 时钟和复位
    input logic clk,
    input logic rst_n,

    // 故障容错配置
    input logic pg_en,                   // 故障使能信号
    input logic [`ID_W-1:0] pg_node,     // 故障节点坐标

    // 接口连接
    pkt_in.mst pkt_i,                    // A接口输入 - 外部数据包输入
    pkt_out.mst pkt_o,                   // B接口输出 - 外部数据包输出
    pkt_con_if.mst pkt_con               // C接口 - 四方向网格连接
);

  // =============================================================================
    // 参数定义和内部信号声明
    // =============================================================================

    // 数据包格式定义 (23位总宽度)
    localparam PKT_W = `TYPE_W + `QOS_W + `SRCID_W + `TGTID_W + `FLIT_W;  // 2+1+6+6+8 = 23位

    // 数据包位位置常量
    // 实际数据包格式: {TYPE[1:0], QOS[0], SRC[5:0], TGT[5:0], DATA[7:0]}
    // 位位置:         [22:21], [20],   [19:14], [13:8], [7:0]
    localparam QOS_POS      = 20;          // QoS位位置 (修复)
    localparam TYPE_POS_HI  = 22;          // 类型位高位置
    localparam TYPE_POS_LO  = 21;          // 类型位低位置
    localparam SRC_POS_HI   = 19;          // 源ID高位置 (修复)
    localparam SRC_POS_LO   = 14;          // 源ID低位置 (修复)
    localparam TGT_POS_HI   = 13;          // 目标ID高位置 (修复)
    localparam TGT_POS_LO   = 8;           // 目标ID低位置 (修复)

    // 故障相对位置类型定义
    localparam NORMAL   = 4'd0;  // 正常状态，无故障影响
    localparam N_OF_x   = 4'd1;  // 当前节点在故障节点北方
    localparam NE_OF_x  = 4'd2;  // 当前节点在故障节点东北方
    localparam E_OF_x   = 4'd3;  // 当前节点在故障节点东方
    localparam SE_OF_x  = 4'd4;  // 当前节点在故障节点东南方
    localparam S_OF_x   = 4'd5;  // 当前节点在故障节点南方
    localparam SW_OF_x  = 4'd6;  // 当前节点在故障节点西南方
    localparam W_OF_x   = 4'd7;  // 当前节点在故障节点西方
    localparam NW_OF_x  = 4'd8;  // 当前节点在故障节点西北方

    // 路由方向定义
    localparam DIR_N    = 3'd0;   // 北方向
    localparam DIR_W    = 3'd1;   // 西方向
    localparam DIR_S    = 3'd2;   // 南方向
    localparam DIR_E    = 3'd3;   // 东方向
    localparam DIR_B    = 3'd4;   // 本地输出

  // =============================================================================
    // 故障感知REGISTER信号计算
    // =============================================================================

    // 故障节点坐标分解
    logic [`ID_W/2-1:0] fault_x, fault_y;    // 故障节点的X和Y坐标
    logic [`ID_W/2-1:0] local_x, local_y;    // 当前节点的X和Y坐标

    assign fault_x = pg_node[2:0];            // 低3位为X坐标
    assign fault_y = pg_node[5:3];            // 高3位为Y坐标
    assign local_x = HP[2:0];                 // 当前节点X坐标
    assign local_y = VP[2:0];                 // 当前节点Y坐标

    // 故障相对位置计算
    logic [3:0] fault_relative_pos;           // 故障相对位置（需要4位支持9种状态）

    // 边缘节点检测信号
    logic is_north_edge, is_south_edge;       // 南北边缘检测
    logic is_west_edge, is_east_edge;         // 东西边缘检测

    // 边缘检测逻辑
    assign is_north_edge = (VP == 7);          // Y坐标为7是北边缘
    assign is_south_edge = (VP == 0);          // Y坐标为0是南边缘
    assign is_west_edge = (HP == 0);           // X坐标为0是西边缘
    assign is_east_edge = (HP == 7);           // X坐标为7是东边缘

    always_comb begin
        if (!pg_en) begin
            fault_relative_pos = NORMAL;      // 无故障使能时为正常状态
        end else begin
            // 计算当前节点与故障节点的相对位置
            if (local_y == fault_y && local_x == fault_x) begin
                // 当前节点就是故障节点（不应该发生，因为故障节点会被时钟门控）
                fault_relative_pos = NORMAL;
            end else if (local_y > fault_y) begin
                // 当前节点在故障节点北方
                if (local_x < fault_x) fault_relative_pos = NW_OF_x;      // 西北方
                else if (local_x == fault_x) fault_relative_pos = N_OF_x; // 正北方
                else fault_relative_pos = NE_OF_x;                        // 东北方
            end else if (local_y == fault_y) begin
                // 当前节点与故障节点同一行
                if (local_x < fault_x) fault_relative_pos = W_OF_x;       // 西方
                else fault_relative_pos = E_OF_x;                         // 东方
            end else begin
                // 当前节点在故障节点南方
                if (local_x < fault_x) fault_relative_pos = SW_OF_x;      // 西南方
                else if (local_x == fault_x) fault_relative_pos = S_OF_x; // 正南方
                else fault_relative_pos = SE_OF_x;                        // 东南方
            end
        end
    end

    // =============================================================================
    // 输入IRS_N缓冲器 (寄存器输出模式RO_EN=1)
    // =============================================================================

    // A接口输入缓冲器
    logic a_in_valid, a_in_ready;
    logic [PKT_W-1:0] a_in_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_input_A (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(pkt_i.pkt_in_vld),
        .ready_i(a_in_ready),
        .valid_o(a_in_valid),
        .ready_o(pkt_i.pkt_in_rdy),
        .payload_i({pkt_i.pkt_in_type, pkt_i.pkt_in_qos, pkt_i.pkt_in_src, pkt_i.pkt_in_tgt, pkt_i.pkt_in_data}),
        .payload_o(a_in_pkt)
    );

    // C接口北方输入缓冲器
    logic n_in_valid, n_in_ready;
    logic [PKT_W-1:0] n_in_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_input_N (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(pkt_con.ni_vld),
        .ready_i(n_in_ready),
        .valid_o(n_in_valid),
        .ready_o(pkt_con.ni_rdy),
        .payload_i({pkt_con.ni_type, pkt_con.ni_qos, pkt_con.ni_src, pkt_con.ni_tgt, pkt_con.ni_data}),
        .payload_o(n_in_pkt)
    );

    // C接口西方输入缓冲器
    logic w_in_valid, w_in_ready;
    logic [PKT_W-1:0] w_in_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_input_W (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(pkt_con.wi_vld),
        .ready_i(w_in_ready),
        .valid_o(w_in_valid),
        .ready_o(pkt_con.wi_rdy),
        .payload_i({pkt_con.wi_type, pkt_con.wi_qos, pkt_con.wi_src, pkt_con.wi_tgt, pkt_con.wi_data}),
        .payload_o(w_in_pkt)
    );

    // C接口南方输入缓冲器
    logic s_in_valid, s_in_ready;
    logic [PKT_W-1:0] s_in_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_input_S (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(pkt_con.si_vld),
        .ready_i(s_in_ready),
        .valid_o(s_in_valid),
        .ready_o(pkt_con.si_rdy),
        .payload_i({pkt_con.si_type, pkt_con.si_qos, pkt_con.si_src, pkt_con.si_tgt, pkt_con.si_data}),
        .payload_o(s_in_pkt)
    );

    // C接口东方输入缓冲器
    logic e_in_valid, e_in_ready;
    logic [PKT_W-1:0] e_in_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_input_E (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(pkt_con.ei_vld),
        .ready_i(e_in_ready),
        .valid_o(e_in_valid),
        .ready_o(pkt_con.ei_rdy),
        .payload_i({pkt_con.ei_type, pkt_con.ei_qos, pkt_con.ei_src, pkt_con.ei_tgt, pkt_con.ei_data}),
        .payload_o(e_in_pkt)
    );

    // =============================================================================
    // 独立路由单元 (5个并行路由器)
    // =============================================================================

    // 路由单元接口信号
    logic [4:0] route_req_A, route_req_N, route_req_W, route_req_S, route_req_E;  // 5-bit one-hot请求信号
    logic [PKT_W-1:0] route_pkt_A, route_pkt_N, route_pkt_W, route_pkt_S, route_pkt_E; // 路由数据包

    // 输入ready信号连接逻辑
    // 基于路由单元可以处理新数据的能力来控制输入缓冲器的ready信号
    assign a_in_ready = 1'b1;  // A端口路由器始终可以接收新数据（非流水线设计）
    assign n_in_ready = 1'b1;  // 北端口路由器始终可以接收新数据
    assign w_in_ready = 1'b1;  // 西端口路由器始终可以接收新数据
    assign s_in_ready = 1'b1;  // 南端口路由器始终可以接收新数据
    assign e_in_ready = 1'b1;  // 东端口路由器始终可以接收新数据

    // A端口路由单元
    router_unit #(
        .LOCAL_X(HP),
        .LOCAL_Y(VP)
    ) u_router_A (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(a_in_valid),
        .pkt_in(a_in_pkt),
        .fault_register(fault_relative_pos),
        .route_req(route_req_A),
        .pkt_out(route_pkt_A)
    );

    // 北端口路由单元
    router_unit #(
        .LOCAL_X(HP),
        .LOCAL_Y(VP)
    ) u_router_N (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(n_in_valid),
        .pkt_in(n_in_pkt),
        .fault_register(fault_relative_pos),
        .route_req(route_req_N),
        .pkt_out(route_pkt_N)
    );

    // 西端口路由单元
    router_unit #(
        .LOCAL_X(HP),
        .LOCAL_Y(VP)
    ) u_router_W (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(w_in_valid),
        .pkt_in(w_in_pkt),
        .fault_register(fault_relative_pos),
        .route_req(route_req_W),
        .pkt_out(route_pkt_W)
    );

    // 南端口路由单元
    router_unit #(
        .LOCAL_X(HP),
        .LOCAL_Y(VP)
    ) u_router_S (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(s_in_valid),
        .pkt_in(s_in_pkt),
        .fault_register(fault_relative_pos),
        .route_req(route_req_S),
        .pkt_out(route_pkt_S)
    );

    // 东端口路由单元
    router_unit #(
        .LOCAL_X(HP),
        .LOCAL_Y(VP)
    ) u_router_E (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(e_in_valid),
        .pkt_in(e_in_pkt),
        .fault_register(fault_relative_pos),
        .route_req(route_req_E),
        .pkt_out(route_pkt_E)
    );

    // =============================================================================
    // QoS仲裁器 (5个仲裁器)
    // =============================================================================

    // 仲裁器请求信号映射
    logic [3:0] arb_req_N, arb_qos_N, arb_gnt_N;  // 北仲裁器：4个输入(A,W,S,E)，排除北输入
    logic [3:0] arb_req_W, arb_qos_W, arb_gnt_W;  // 西仲裁器：4个输入(A,N,S,E)，排除西输入
    logic [3:0] arb_req_S, arb_qos_S, arb_gnt_S;  // 南仲裁器：4个输入(A,N,W,E)，排除南输入
    logic [3:0] arb_req_E, arb_qos_E, arb_gnt_E;  // 东仲裁器：4个输入(A,N,W,S)，排除东输入
    logic [4:0] arb_req_B, arb_qos_B, arb_gnt_B;  // B仲裁器：支持所有4个输入(A,N,W,S,E)

    // 仲裁器输入映射 - 使用常量QOS_POS确保一致性
    // 北仲裁器：4个输入，排除来自北方的输入 [A,W,S,E]
    assign arb_req_N = {route_req_A[0], route_req_W[0], route_req_S[0], route_req_E[0]};
    assign arb_qos_N = {route_pkt_A[QOS_POS], route_pkt_W[QOS_POS], route_pkt_S[QOS_POS], route_pkt_E[QOS_POS]};

    // 西仲裁器：4个输入，排除来自西方的输入 [A,N,S,E]
    assign arb_req_W = {route_req_A[1], route_req_N[1], route_req_S[1], route_req_E[1]};
    assign arb_qos_W = {route_pkt_A[QOS_POS], route_pkt_N[QOS_POS], route_pkt_S[QOS_POS], route_pkt_E[QOS_POS]};

    // 南仲裁器：4个输入，排除来自南方的输入 [A,N,W,E]
    assign arb_req_S = {route_req_A[2], route_req_N[2], route_req_W[2], route_req_E[2]};
    assign arb_qos_S = {route_pkt_A[QOS_POS], route_pkt_N[QOS_POS], route_pkt_W[QOS_POS], route_pkt_E[QOS_POS]};

    // 东仲裁器：4个输入，排除来自东方的输入 [A,N,W,S]
    assign arb_req_E = {route_req_A[3], route_req_N[3], route_req_W[3], route_req_S[3]};
    assign arb_qos_E = {route_pkt_A[QOS_POS], route_pkt_N[QOS_POS], route_pkt_W[QOS_POS], route_pkt_S[QOS_POS]};

    // B仲裁器：支持所有4个输入 [A,N,W,S,E]
    assign arb_req_B = {route_req_A[4], route_req_N[4], route_req_W[4], route_req_S[4], route_req_E[4]};
    assign arb_qos_B = {route_pkt_A[QOS_POS], route_pkt_N[QOS_POS], route_pkt_W[QOS_POS], route_pkt_S[QOS_POS], route_pkt_E[QOS_POS]};

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

    logic [PKT_W-1:0] pkt_N, pkt_W, pkt_S, pkt_E, pkt_B;

    // 使用选择器信号进行数据选择
    // 注意：仲裁器输入映射 [A,W,S,E], [A,N,S,E], [A,N,W,E], [A,N,W,S], [A,N,W,S,E]
    always_comb begin
        // 北输出选择 - 映射：[A,W,S,E]
        if (arb_gnt_N[3]) begin pkt_N = route_pkt_A; end    // bit3: A输入
        else if (arb_gnt_N[2]) begin pkt_N = route_pkt_W; end  // bit2: W输入
        else if (arb_gnt_N[1]) begin pkt_N = route_pkt_S; end  // bit1: S输入
        else if (arb_gnt_N[0]) begin pkt_N = route_pkt_E; end  // bit0: E输入
        else begin pkt_N = {PKT_W{1'b0}}; end

        // 西输出选择 - 映射：[A,N,S,E]
        if (arb_gnt_W[3]) begin pkt_W = route_pkt_A; end    // bit3: A输入
        else if (arb_gnt_W[2]) begin pkt_W = route_pkt_N; end  // bit2: N输入
        else if (arb_gnt_W[1]) begin pkt_W = route_pkt_S; end  // bit1: S输入
        else if (arb_gnt_W[0]) begin pkt_W = route_pkt_E; end  // bit0: E输入
        else begin pkt_W = {PKT_W{1'b0}}; end

        // 南输出选择 - 映射：[A,N,W,E]
        if (arb_gnt_S[3]) begin pkt_S = route_pkt_A; end    // bit3: A输入
        else if (arb_gnt_S[2]) begin pkt_S = route_pkt_N; end  // bit2: N输入
        else if (arb_gnt_S[1]) begin pkt_S = route_pkt_W; end  // bit1: W输入
        else if (arb_gnt_S[0]) begin pkt_S = route_pkt_E; end  // bit0: E输入
        else begin pkt_S = {PKT_W{1'b0}}; end

        // 东输出选择 - 映射：[A,N,W,S]
        if (arb_gnt_E[3]) begin pkt_E = route_pkt_A; end    // bit3: A输入
        else if (arb_gnt_E[2]) begin pkt_E = route_pkt_N; end  // bit2: N输入
        else if (arb_gnt_E[1]) begin pkt_E = route_pkt_W; end  // bit1: W输入
        else if (arb_gnt_E[0]) begin pkt_E = route_pkt_S; end  // bit0: S输入
        else begin pkt_E = {PKT_W{1'b0}}; end

        // B输出选择（本地输出）- 映射：[A,N,W,S,E]
        if (arb_gnt_B[4]) begin pkt_B = route_pkt_A; end    // bit4: A输入
        else if (arb_gnt_B[3]) begin pkt_B = route_pkt_N; end  // bit3: N输入
        else if (arb_gnt_B[2]) begin pkt_B = route_pkt_W; end  // bit2: W输入
        else if (arb_gnt_B[1]) begin pkt_B = route_pkt_S; end  // bit1: S输入
        else if (arb_gnt_B[0]) begin pkt_B = route_pkt_E; end  // bit0: E输入
        else begin pkt_B = {PKT_W{1'b0}}; end
    end

    // =============================================================================
    // 输出IRS_N缓冲器 (寄存器输出模式RO_EN=1)
    // =============================================================================

    logic n_out_valid, n_out_ready;
    logic [PKT_W-1:0] n_out_pkt;

    IRS_N #(
        .PYLD_W(PKT_W),
        .IRS_DEEP(1),               // 1级深度缓冲
        .TYPE_RO_EN(1)              // Reg_Out寄存器输出模式
    ) irs_output_N (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_N),
        .ready_i(pkt_con.no_rdy),   // 连接到C接口北输出端口的ready信号
        .valid_o(n_out_valid),
        .ready_o(n_out_ready),      // 内部使用，告知上游是否ready
        .payload_i(pkt_N),
        .payload_o(n_out_pkt)
    );

    logic w_out_valid, w_out_ready;
    logic [PKT_W-1:0] w_out_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_output_W (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_W),
        .ready_i(pkt_con.wo_rdy),   // 连接到C接口西输出端口的ready信号
        .valid_o(w_out_valid),
        .ready_o(w_out_ready),      // 内部使用，告知上游是否ready
        .payload_i(pkt_W),
        .payload_o(w_out_pkt)
    );

    logic s_out_valid, s_out_ready;
    logic [PKT_W-1:0] s_out_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_output_S (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_S),
        .ready_i(pkt_con.so_rdy),   // 连接到C接口南输出端口的ready信号
        .valid_o(s_out_valid),
        .ready_o(s_out_ready),      // 内部使用，告知上游是否ready
        .payload_i(pkt_S),
        .payload_o(s_out_pkt)
    );

    logic e_out_valid, e_out_ready;
    logic [PKT_W-1:0] e_out_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_output_E (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_E),
        .ready_i(pkt_con.eo_rdy),   // 连接到C接口东输出端口的ready信号
        .valid_o(e_out_valid),
        .ready_o(e_out_ready),      // 内部使用，告知上游是否ready
        .payload_i(pkt_E),
        .payload_o(e_out_pkt)
    );

    logic b_out_valid, b_out_ready;
    logic [PKT_W-1:0] b_out_pkt;

        IRS_LP #(
          .PYLD_W (PKT_W)
          ,.RO_EN(1)
    ) irs_output_B (
        .clk(clk),
        .rst_n(rst_n),
        .valid_i(|arb_gnt_B),
        .ready_i(pkt_o.pkt_out_rdy), // 连接到B接口输出端口的ready信号
        .valid_o(b_out_valid),
        .ready_o(b_out_ready),       // 内部使用，告知上游是否ready
        .payload_i(pkt_B),
        .payload_o(b_out_pkt)
    );

    // =============================================================================
    // 直接组合逻辑输出 (IRS_N内部已提供寄存器功能)
    // =============================================================================

    // B接口输出 - 直接连接IRS_N输出
    assign pkt_o.pkt_out_vld = b_out_valid;
    assign pkt_o.pkt_out_qos = b_out_pkt[QOS_POS];
    assign pkt_o.pkt_out_type = b_out_pkt[TYPE_POS_HI:TYPE_POS_HI-1];
    assign pkt_o.pkt_out_src = b_out_pkt[SRC_POS_HI:SRC_POS_LO];
    assign pkt_o.pkt_out_tgt = b_out_pkt[TGT_POS_HI:TGT_POS_LO];
    assign pkt_o.pkt_out_data = b_out_pkt[7:0];

    // C接口北方向输出 - 直接连接IRS_N输出
    assign pkt_con.no_vld = n_out_valid;
    assign pkt_con.no_qos = n_out_pkt[QOS_POS];
    assign pkt_con.no_type = n_out_pkt[TYPE_POS_HI:TYPE_POS_HI-1];
    assign pkt_con.no_src = n_out_pkt[SRC_POS_HI:SRC_POS_LO];
    assign pkt_con.no_tgt = n_out_pkt[TGT_POS_HI:TGT_POS_LO];
    assign pkt_con.no_data = n_out_pkt[7:0];

    // C接口西方向输出 - 直接连接IRS_N输出
    assign pkt_con.wo_vld = w_out_valid;
    assign pkt_con.wo_qos = w_out_pkt[QOS_POS];
    assign pkt_con.wo_type = w_out_pkt[TYPE_POS_HI:TYPE_POS_HI-1];
    assign pkt_con.wo_src = w_out_pkt[SRC_POS_HI:SRC_POS_LO];
    assign pkt_con.wo_tgt = w_out_pkt[TGT_POS_HI:TGT_POS_LO];
    assign pkt_con.wo_data = w_out_pkt[7:0];

    // C接口南方向输出 - 直接连接IRS_N输出
    assign pkt_con.so_vld = s_out_valid;
    assign pkt_con.so_qos = s_out_pkt[QOS_POS];
    assign pkt_con.so_type = s_out_pkt[TYPE_POS_HI:TYPE_POS_HI-1];
    assign pkt_con.so_src = s_out_pkt[SRC_POS_HI:SRC_POS_LO];
    assign pkt_con.so_tgt = s_out_pkt[TGT_POS_HI:TGT_POS_LO];
    assign pkt_con.so_data = s_out_pkt[7:0];

    // C接口东方向输出 - 直接连接IRS_N输出
    assign pkt_con.eo_vld = e_out_valid;
    assign pkt_con.eo_qos = e_out_pkt[QOS_POS];
    assign pkt_con.eo_type = e_out_pkt[TYPE_POS_HI:TYPE_POS_HI-1];
    assign pkt_con.eo_src = e_out_pkt[SRC_POS_HI:SRC_POS_LO];
    assign pkt_con.eo_tgt = e_out_pkt[TGT_POS_HI:TGT_POS_LO];
    assign pkt_con.eo_data = e_out_pkt[7:0];


endmodule
