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
`define DIR_Q     4'd0
`define DIR_W     4'd1   // 西方向
`define DIR_E     4'd2   // 东方向
`define DIR_R     4'd3   // 东方向
`define DIR_N     4'd4   // 北方向
`define DIR_S     4'd5   // 南方向
`define DIR_B     4'd6   // 本地输出
`define DIR_A     4'd6   // 本地输入

`define PKT_W  23  // 2+1+6+6+8  23位
