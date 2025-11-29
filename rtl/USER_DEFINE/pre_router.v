// =============================================================================
// MAZE网络路由单元模块
// =============================================================================
// 功能说明：
// 1. 在输入buffer之前的router
// 2. 根据tgt x y和src xy以及local_x,y产生route_req 
// 3. 实现无坏点模式下的单播、多播和广播
// 4. 实现有坏点模式下的串行多播
// 5. 配置参数LOCAL_X\LOCAL_Y
// 6. 输入端口tgt_x, tgt_y, pg_en, pg_node_x, pg_node_y，fault_relative_pos
// 7. 输出端口tgt_x_new, tgt_y_new, route_req
// 8. Route_Req包括B、NWSE、JW/Q、JE/R七个方向。
// - 先X后Y，能够跳点就跳点
// - 
// 9. 考虑位于边缘的情况
// 10. 在行多播的情况下，src_y和tgt_x都没有用，这6bit用来传播多播五个方向的信息
// 11. 在列多播的情况下，src_x和tgt_y都没有用，这6bit用来传播多播五个方向的信息
// 12. 在广播的情况下，tgt_xy都没有用，这6bit用来传播多播五个方向的信息
// 13. 有坏点时，通过在A入口进行包复制实现多播、广播，利用对应的tgt_x/y作为计数器
// =============================================================================
`timescale 1ns/1ps
module pre_router #(
    // 节点位置参数
    parameter [2:0] LOC_X = 3'd0,     // 当前节点X坐标 (0-7)
    parameter [2:0] LOC_Y = 3'd0,      // 当前节点Y坐标 (0-7)
    parameter [2:0] RT_ID = 3'd0,       //  当前ROUTER坐标
) (
    // 输入数据包接口
    input wire [2:0] tgt_x,               // 包原始目标X坐标 (0-7)
    input wire [2:0] tgt_y,               // 包原始目标Y坐标 (0-7)
    input wire [1:0] pkt_type,             //包类型：00 单播， 01 x相同的广播（列多播），10 y相同的多播（行多播），11 广播

    input   wire    pg_en,                   // 坏点存在信号
    // input   wire    [6:0]    pg_pos,             

    // 路由输出接口
    output reg [6:0] route_req            // 5-bit 路由请求 [N,W,S,E,B]，多播、广播模式下存在多bit 1
);

// =============================================================================
// 参数和内部信号定义
// =============================================================================

// 使用param.v中定义的宏，无需重复定义

wire tgt_y_eq_loc_y  = tgt_y == LOCAL_Y;
wire tgt_x_eq_loc_x  = tgt_x == LOCAL_X;
wire tgt_x_gt_loc_x = tgt_x > LOCAL_X;
wire tgt_x_gt_loc_x_p1 = tgt_x > (LOCAL_X + 1);
wire tgt_x_gt_loc_x_p2 = tgt_x > (LOCAL_X + 1);
wire tgt_x_ls_loc_x = tgt_x < LOCAL_X;
wire tgt_x_ls_loc_x_m1 = tgt_x < (LOCAL_X-1);
wire tgt_y_gt_loc_y = tgt_y > LOCAL_Y;
wire tgt_y_gt_loc_y_p1 = tgt_y > (LOCAL_Y+1);
wire tgt_y_ls_loc_y = tgt_y < LOCAL_Y;


wire pg_loc_reach   =   pkt_type == 2'b00   ?   tgt_y_eq_loc_y & tgt_x_eq_loc_x :
                        pkt_type == 2'b01   ?   tgt_x_eq_loc_x  :
                        pkt_type == 2'b10   ?   tgt_y_eq_loc_y  :
                        pkt_type == 2'b11   ?   1   :   0;
// wire pg_loc_reach = (pkt_type[0] | (~pkt_type[0] & tgt_x_eq_loc_x)) & (pkt_type[1] | (~pkt_type[1] & tgt_y_eq_loc_y)); 
// wire    pg_E_reach  =   ~(LOC_X < 7 ) ? 0 :
//                         pkt_type == 2'b00   ?   (tgt_x == LOC_X + 1) & (tgt_y == LOC_Y) :
//                         pkt_type == 2'b01   ?   (tgt_x == LOC_X + 1)    :
//                         pkt_type == 2'b10   ?   (tgt_y == LOC_Y)    :
//                         pkt_type == 2'b11   ?   1   :   0;
// wire    pg_R_reach  =   ~(LOC_X < 6 )   ?   0   :
//                         pkt_type == 2'b00   ?   (tgt_x == LOC_X + 2) & (tgt_y == LOC_Y) :
//                         pkt_type == 2'b01   ?   (tgt_x == LOC_X + 2)    :
//                         pkt_type == 2'b10   ?   (tgt_y == LOC_Y)    :
//                         pkt_type == 2'b11   ?   1   :   0;
// wire    pg_W_reach  =   ~(LOC_X > 0 ) ? 0 :
//                         pkt_type == 2'b00   ?   (tgt_x == LOC_X - 1) & (tgt_y == LOC_Y) :
//                         pkt_type == 2'b01   ?   (tgt_x == LOC_X - 1)    :
//                         pkt_type == 2'b10   ?   (tgt_y == LOC_Y)    :
//                         pkt_type == 2'b11   ?   1   :   0;
// wire    pg_Q_reach  =   ~(LOC_X > 1 )   ?   0   :
//                         pkt_type == 2'b00   ?   (tgt_x == LOC_X - 2) & (tgt_y == LOC_Y) :
//                         pkt_type == 2'b01   ?   (tgt_x == LOC_X - 2)    :
//                         pkt_type == 2'b10   ?   (tgt_y == LOC_Y)    :
//                         pkt_type == 2'b11   ?   1   :   0;
// wire    pg_N_reach  =   ~(LOC_Y < 7 )   ?   0   :
//                         pkt_type == 2'b00   ?   (tgt_y == LOC_Y + 1) & (tgt_x == LOC_X) :
//                         pkt_type == 2'b01   ?   (tgt_x == LOC_X)    :
//                         pkt_type == 2'b10   ?   (tgt_y == LOC_Y + 1)    :
//                         pkt_type == 2'b11   ?   1   :   0;

// wire    pg_is_Q = pg_pos[`DIR_Q];
// wire    pg_is_W = pg_pos[`DIR_W];
// wire    pg_is_E = pg_pos[`DIR_E];
// wire    pg_is_R = pg_pos[`DIR_R];
// wire    pg_is_N = pg_pos[`DIR_N];
// wire    pg_is_S = pg_pos[`DIR_S];

always_comb begin
    // 默认无请求，输出零数据包
    route_req = 5'b00000;

    if(!pg_en) begin
        case(pkt_type)
        2'b00: begin
            //  单播，先X后Y
            //  所有口到达了目标点就从B端口输出
            //  A口Router可以往QWERNSB所有方向走
            //  Q口Router可以继续往ERNS走，W口可以继续往NS走（如果W可以继续往W走，那上一步应该是往Q而非W，如果可以往Q走，同上）
            //  E口Router可以继续往NS走，R口可以继续往QWNS走
            //  N口Router可以继续往S走（先X后Y所以不能走QWER）
            //  S口Router只可以继续往N走（同上）
            //  TODO 跑一个综合，看tgt_x <= (LOC_X-2) 的时序和性能好一些，还是(tgt_x !=(LOC_X-1)) & (tgt_x !=(LOC_X-2)) 好一些
            route_req[`DIR_Q] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X > 1) & (tgt_x <= (LOC_X - 2));   //  只有A口Router和R口Router可以继续往Q走
            route_req[`DIR_W] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X > 0) & (tgt_x == (LOC_X - 1));   //  只有A口Router和R口Router可以继续往W走
            route_req[`DIR_E] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X < 7) & (tgt_x == (LOC_X + 1));
            route_req[`DIR_R] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X < 6) & (tgt_x >= (LOC_X + 2));
            route_req[`DIR_N] = (((RT_ID == `DIR_E) | (RT_ID == `DIR_W)) & tgt_y_gt_loc_y) |                        // 如果是E口和W口的Router，并且没有到达，那肯定要拐弯
                                (((RT_ID == `DIR_Q) | (RT_ID == `DIR_R) | (RT_ID == `DIR_A)) & tgt_x_eq_loc_x & tgt_y_gt_loc_y) |    // 如果是A、Q、R口，可能继续走，所以需要判断x是否到达
                                ((RT_ID == `DIR_S) & (tgt_y != LOC_Y));                                             // 如果是S口的Router，没到达就继续向上走
            route_req[`DIR_S] = (((RT_ID == `DIR_E) | (RT_ID == `DIR_W)) & tgt_y_ls_loc_y) |                        // 如果是E口和W口的Router，并且没有到达，那肯定要拐弯
                                (((RT_ID == `DIR_Q) | (RT_ID == `DIR_R) | (RT_ID == `DIR_A)) & tgt_x_eq_loc_x & tgt_y_ls_loc_y) |    // 如果是A、Q、R口，可能继续走，所以需要判断x是否到达
                                ((RT_ID == `DIR_N) & (tgt_y != LOC_Y));                                             // 如果是N口的Router，没到达就继续向下走
            route_req[`DIR_B] = (((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_R)) & tgt_x_eq_loc_x & tgt_y_eq_loc_y) |   //  如果是A\Q\R口Router不一定到达，需要判断x和y
                                (((RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_N) | (RT_ID == `DIR_S)) & tgt_y_eq_loc_y); //  如果是WE这种拐弯点，或者NS这种Y向点，肯定x已经到达了，只需要判断Y                                                   //  任何口都可能到达
        end
        2'b01: begin
            //  先横向单播，然后纵向多播
            //  所有口，如果到达了目标X，就可以通过B输出，小于目标X就往E、R，大于目标X就往Q、W
            //  A口的Router可能往QWERNSB所有方向输出
            //  Q口的Router可能往ERNSB五个方向输出
            //  W口的Router一定往NSB三个口输出(如果没到目标X，就不会只走W而不走Q)
            //  E口的Router一定往NSB三个口输出（同上）
            //  R口的Router可能往QWNSB五个方向输出
            //  N口的Router只能往S口继续输出，并且一定往B口输出
            //  S口的Router只能往N口继续输出，并且一定往B口输出
            route_req[`DIR_Q] = ((RT_ID == `DIR_A | RT_ID == `DIR_R) & (LOC_X > 1) & (tgt_x <= (LOC_X - 2)));   //  只有A口router或者R口router才可能继续往左
            route_req[`DIR_W] = ((RT_ID == `DIR_A | RT_ID == `DIR_R) & (LOC_X > 0) & (tgt_x == (LOC_X - 1)));   //  只有A口router或者R口router才可能继续往左
            route_req[`DIR_E] = ((RT_ID == `DIR_A | RT_ID == `DIR_Q) & (LOC_X < 7) & (tgt_x == (LOC_X + 1)));   //  只有A口router或者R口router才可能继续往左
            route_req[`DIR_R] = ((RT_ID == `DIR_A | RT_ID == `DIR_Q) & (LOC_X < 6) & (tgt_x >= (LOC_X + 2)));   //  只有A口router或者R口router才可能继续往左
            route_req[`DIR_N] = (((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_R)) & (LOC_X < 7) & tgt_x_eq_loc_x)  |   //  A、Q、R的router不一定拐弯，所以要判断x是否到达
                                (((RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_S)) & (LOC_X < 7))  ;  //  如果是WE这种拐点router，或者s router，没到顶就继续网上
            route_req[`DIR_S] = (((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_R)) & (LOC_X > 0) & tgt_x_eq_loc_x)  |   //  A、Q、R的router不一定拐弯，所以要判断x是否到达
                                (((RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_N)) & (LOC_X > 0))  ;  //  如果是WE这种拐点router，或者s router，没到顶就继续网上
            route_req[`DIR_B] = (((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_R)) & tgt_x_eq_loc_x)  |   //  如果是A、Q、R的Router，必须判断是否X到达
                                ((RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_N) | (RT_ID == `DIR_S));    //  如果是WE这种拐点，或者是NS这种已到达router，直接输出
            
        end
        2'b10: begin
            //  先横向多播，然后每个包分别纵向单播
            //  所有口，如果到达了目标Y，就往B输出，小于目标Y就往N，大于目标Y就往S
            //  A口的Router会向QWRT四个方向多播（除非超出范围），
            //  Q口和R口的一定会继续向QW、ER口方向多播（除非超出范围）
            //  W口和E口的不会多播
            //  N口和S口不会进行QWRT多播（因为先X后Y），只会继续NS或者B
            route_req[`DIR_Q] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X > 1);
            route_req[`DIR_W] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X > 0);
            route_req[`DIR_E] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X < 7);
            route_req[`DIR_R] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X < 6);
            route_req[`DIR_N] = (RT_ID == `DIR_N) ? 0 : tgt_y_gt_loc_y;
            route_req[`DIR_S] = (RT_ID == `DIR_S) ? 0 : tgt_y_ls_loc_y;
            route_req[`DIR_B] = tgt_y_eq_loc_y;
        end
        2'b11: begin
            //  先横向多播，然后每个包分别纵向单播
            //  所有口都会往B端口输出
            //  A口会往所有端口输出（除非到达边界）
            //  W和E口会往N和S口输出（除非到达边界）
            //  Q和R口会往QW\ER方向输出，并且往NS方向输出（除非到达边界）
            //  N口和S口会继续往N和S口输出（除非到达边界）
            route_req[`DIR_Q] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X > 1);
            route_req[`DIR_W] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q)) & (LOC_X > 0);
            route_req[`DIR_E] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X < 7);
            route_req[`DIR_R] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_R)) & (LOC_X < 6);
            route_req[`DIR_N] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_R) | (RT_ID == `DIR_N)) & (LOC_Y < 7);
            route_req[`DIR_S] = ((RT_ID == `DIR_A) | (RT_ID == `DIR_Q) | (RT_ID == `DIR_W) | (RT_ID == `DIR_E) | (RT_ID == `DIR_R) | (RT_ID == `DIR_S)) & (LOC_Y > 0);
            route_req[`DIR_B] = 1'b1;
        end
        endcase
    end
    else begin
        //  先写一个只有NWSE的，看看能不能行，不行再改

        //  如果有坏点，就进行串链
        //  只要没到达，就按照固定的顺序去发
        //  即根据当前的X和Y去触发router_req(要利用上Q和R，上班的时候画一张串链的图)
        //  先写一个不管怎样都直接发的吧，然后到坏点自然湮灭
        //  如果要停止的话，要判断两个方向是否有剩余的点，那就
        //  1. 判断两条链是否有目标点，没有的话直接挂掉
        //  2. 判断每条链上最终节点在哪里
        //  3. 到达最终节点的时候不发qwerns
        //  A口的话先往两个方向去发
        //  到达了就往B口发
        //  不同类型到达的判断方式不一样
        //  单播：xy都相同
        //  横向多播：y相同
        //  纵向多播：x相同
        //  广播：直接发
        //  任何时候，如果左右点或者左右跳点是坏点，那就直接直接将该方向两个route req tie0
        route_req = 5'b00000;
        if (LOC_Y == 0) begin
            if(LOC_X == 0) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if(LOC_X == 7) begin 
                route_req[`DIR_W] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
            else begin
                route_req[`DIR_W] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
        end
        else if(LOC_Y == 1 | LOC_Y == 3 | LOC_Y == 5 ) begin
            if(LOC_X == 0) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if (LOC_X == 1) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if(LOC_X == 7 ) begin
                route_req[`DIR_W] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else begin
                route_req[`DIR_W] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
        end
        else if(LOC_Y == 2 | LOC_Y == 4 | LOC_Y == 6 ) begin
            if(LOC_X == 0) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if (LOC_X == 1) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if(LOC_X == 7 ) begin
                route_req[`DIR_W] = (RT_ID == `DIR_N) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
            else begin
                route_req[`DIR_W] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
        end
        else if (LOC_Y == 7) begin
            if(LOC_X == 0) begin
                route_req[`DIR_W] = 0;
                route_req[`DIR_E] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else if(LOC_X == 7) begin 
                route_req[`DIR_W] = (RT_ID == `DIR_S) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = 0;
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_B] = pg_loc_reach;
            end
            else begin
                route_req[`DIR_W] = (RT_ID == `DIR_E) | (RT_ID == `DIR_A);
                route_req[`DIR_E] = (RT_ID == `DIR_W) | (RT_ID == `DIR_A);
                route_req[`DIR_N] = 0;
                route_req[`DIR_S] = 0;
                route_req[`DIR_B] = pg_loc_reach;
            end
        end


                

        // if (LOC_Y == 0) begin
        //     if(LOC_X == 0) begin

        //         //  在[0,0], 只能从N口和E口和R口进来
        //         //  单播的时候：
        //         //      从N口进来的只能：1. 目标是[0,1]，只拉高E口；2. 目标不是[0,1]，是[0,0]，只拉高B口；3. 目标既不是[0,0]，也不是[0,1]，只拉高R口
        //         //      从E口进来只能：1. 目标是[0,0]，只拉高B口；2. 目标不是[0,0]，只拉高N口；
        //         //      从R口进来只能：1. 目标是[0,0]，只拉高B口；2. 目标不是[0,0]，只拉高N口；
        //         //  多播的时候：
        //         //      从N口进来的：   
        //         //                      1. 如果当前节点在多播目标中，拉高B口；
        //         //                      2. 如果是纵向多播，[0,1]不是目标节点，拉高R;[0,1]是目标节点，拉高E和R
        //         //                      3. 如果是横向多播，不是目标节点，拉高R；当前y是目标节点，那就拉高E和R；
        //         //                      4.广播拉高E和R
        //         //      从E口进来的：
        //         //                      1. 如果当前节点在多播目标中，拉高B口；
        //         //                      2. 不论如何，拉高N
        //         //      从R口进来的：   
        //         //                      1. 如果当前节点是多播目标，拉高B口；
        //         //                      2.  不论如何，拉高N
        //         route_req[`DIR_E] = (RT_ID == `DIR_N) & pg_E_reach;
        //         route_req[`DIR_R] = (RT_ID == `DIR_N);
        //         route_req[`DIR_N] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R));
        //         route_req[`DIR_B] = pg_loc_reach;
        //     else if(LOC_X == 7) begin
        //         route_req[`DIR_N] = (RT_ID == `DIR_W) | (RT_ID == `DIR_Q);
        //         route_req[`DIR_W] = (RT_ID == `DIR_N) & pg_W_reach;
        //         route_req[`DIR_Q] = (RT_ID == `DIR_N) ;
        //         route_req[`DIR_B] = pg_loc_reach;
        //     end
        //     else if(LOC_X == 1) begin
        //         route_req[`DIR_Q] = 'b0;
        //         route_req[`DIR_W] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R));    //  因为无法到达Q，只能到达W
        //         route_req[`DIR_E] = ((RT_ID == `DIR_W) | (RT_ID == `DIR_Q)) & pg_E_reach;
        //         route_req[`DIR_R] = ((RT_ID == `DIR_W) | (RT_ID == `DIR_Q));
        //         route_req[`DIR_N] = 'b0;
        //         route_req[`DIR_S] = 'b0;
        //         route_req[`DIR_B] = pg_loc_reach;
        //     end
        //     else if(LOC_X == 6) begin
        //         route_req[`DIR_Q] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R));
        //         route_req[`DIR_W] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R)) & pg_W_reach;
        //         route_req[`DIR_E] = ((RT_ID == `DIR_W) | (RT_ID == `DIR_Q));
        //         route_req[`DIR_R] = 'b0;
        //         route_req[`DIR_N] = 'b0;
        //         route_req[`DIR_S] = 'b0;
        //         route_req[`DIR_B] = pg_loc_reach;
        //     end
        //     else begin
        //         route_req[`DIR_Q] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R));
        //         route_req[`DIR_W] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R)) & pg_W_reach;
        //         route_req[`DIR_E] = ((RT_ID == `DIR_W) | (RT_ID == `DIR_Q)) & pg_E_reach;
        //         route_req[`DIR_R] = ((RT_ID == `DIR_W) | (RT_ID == `DIR_Q));
        //         route_req[`DIR_N] = 'b0;
        //         route_req[`DIR_S] = 'b0;
        //         route_req[`DIR_B] = pg_loc_reach;
        //     end
        // end
        // else if (LOC_Y == 7) begin
        //     if(LOC_X == 0) begin
        //         route_req[`DIR_Q] = 0;
        //         route_req[`DIR_W] = 0;
        //         route_req[`DIR_E] = (RT_ID == `DIR_S) & pg_E_reach;
        //         route_req[`DIR_R] = (RT_ID == `DIR_N);
        //         route_req[`DIR_N] = ((RT_ID == `DIR_E) | (RT_ID == `DIR_R));
        //         route_req[`DIR_B] = pg_loc_reach;
        //     end

        // end


        // route_req[`DIR_Q] = 

        // route_req[`DIR_B] = pkt_type == 2'b00 ? (tgt_y_eq_loc_y & tgt_x_eq_loc_x) :
        //                     pkt_type == 2'b01 ? tgt_x_eq_loc_x :
        //                     pkt_type == 2'b10 ? tgt_y_eq_loc_y :
        //                     pkt_type == 2'b11 ? 1 : 0;
    end
end


endmodule
