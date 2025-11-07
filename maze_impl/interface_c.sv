`include "top_define.v"

interface pkt_con_if;
    // 每个方向的连接数量
    localparam X_DIRECTION = 7;  // 相同x坐标的连接数
    localparam Y_DIRECTION = 7;  // 相同y坐标的连接数
    localparam TOTAL_CONNECTIONS = X_DIRECTION + Y_DIRECTION;

    // X方向连接 (相同x坐标，不同y坐标)
    wire [X_DIRECTION-1:0] x_vld;
    wire [X_DIRECTION-1:0] x_qos;
    wire [X_DIRECTION-1:0] x_type;
    wire [X_DIRECTION-1:0] x_src;
    wire [X_DIRECTION-1:0] x_tgt;
    wire [X_DIRECTION-1:0] x_data;
    wire [X_DIRECTION-1:0] x_rdy;

    // Y方向连接 (相同y坐标，不同x坐标)
    wire [Y_DIRECTION-1:0] y_vld;
    wire [Y_DIRECTION-1:0] y_qos;
    wire [Y_DIRECTION-1:0] y_type;
    wire [Y_DIRECTION-1:0] y_src;
    wire [Y_DIRECTION-1:0] y_tgt;
    wire [Y_DIRECTION-1:0] y_data;
    wire [Y_DIRECTION-1:0] y_rdy;

    // 辅助函数：获取特定方向的接口
    function automatic string get_direction_name(input int idx);
        if (idx < X_DIRECTION)
            return $sformatf("x_%0d", idx);
        else
            return $sformatf("y_%0d", idx - X_DIRECTION);
    endfunction

    // MST端：节点输出到拓扑
    modport mst(
        // X方向输出
        output x_vld,
        output x_qos,
        output x_type,
        output x_src,
        output x_tgt,
        output x_data,
        input  x_rdy,
        // Y方向输出
        output y_vld,
        output y_qos,
        output y_type,
        output y_src,
        output y_tgt,
        output y_data,
        input  y_rdy
    );

    // SLV端：拓扑输出到节点
    modport slv(
        // X方向输入
        input  x_vld,
        input  x_qos,
        input  x_type,
        input  x_src,
        input  x_tgt,
        input  x_data,
        output x_rdy,
        // Y方向输入
        input  y_vld,
        input  y_qos,
        input  y_type,
        input  y_src,
        input  y_tgt,
        input  y_data,
        output y_rdy
    );

endinterface : pkt_con_if