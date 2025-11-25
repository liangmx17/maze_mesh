`timescale 1ns/1ps

module  fault_relative_pos_detect #
(   parameter LOCAL_X = 0,        // 当前节点的X坐标
    parameter LOCAL_Y = 0         // 当前节点的Y坐标
)
(
    input      pg_en,            // 故障使能信号
    input      [5:0] pg_node,    // 故障节点坐标(低3位X，高3位Y)
    output reg [3:0] fault_relative_pos // 当前节点相对于故障节点的位置
);

// 从pg_node中提取坐标
wire [2:0] fault_x = pg_node[2:0];    // 低3位为X坐标
wire [2:0] fault_y = pg_node[5:3];    // 高3位为Y坐标

    // 使用param.v中定义的宏，无需重复定义

        always_comb begin
        if (!pg_en) begin
            fault_relative_pos = `NORMAL;      // 无故障使能时为正常状态
        end else begin
            // 计算当前节点与故障节点的相对位置
            if (LOCAL_Y == fault_y && LOCAL_X == fault_x) begin
                // 当前节点就是故障节点（不应该发生，因为故障节点会被时钟门控）
                fault_relative_pos = `NORMAL;
            end else if (LOCAL_Y > fault_y) begin
                // 当前节点在故障节点北方
                if (LOCAL_X < fault_x) fault_relative_pos = `NW_OF_x;      // 西北方
                else if (LOCAL_X == fault_x) fault_relative_pos = `N_OF_x; // 正北方
                else fault_relative_pos = `NE_OF_x;                        // 东北方
            end else if (LOCAL_Y == fault_y) begin
                // 当前节点与故障节点同一行
                if (LOCAL_X < fault_x) fault_relative_pos = `W_OF_x;       // 西方
                else fault_relative_pos = `E_OF_x;                         // 东方
            end else begin
                // 当前节点在故障节点南方
                if (LOCAL_X < fault_x) fault_relative_pos = `SW_OF_x;      // 西南方
                else if (LOCAL_X == fault_x) fault_relative_pos = `S_OF_x; // 正南方
                else fault_relative_pos = `SE_OF_x;                        // 东南方
            end
        end
    end
endmodule