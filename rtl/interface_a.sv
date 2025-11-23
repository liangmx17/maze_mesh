// A接口 - 数据包输入接口
// 用于外部数据包输入到MAZE网络节点
// 支持反压控制，确保数据包可靠传输

interface pkt_in();
    wire                    pkt_in_vld;      // 数据包有效信号
    wire                    pkt_in_qos;      // QoS服务质量信号：0=低优先级，1=高优先级
    wire [`TYPE_W -1:0]     pkt_in_type;     // 数据包类型：00=单播，01=X多播，10=Y多播，11=广播
    wire [`ID_W -1:0]       pkt_in_src;      // 源节点ID（6位，支持64个节点）
    wire [`ID_W -1:0]       pkt_in_tgt;      // 目标节点ID（6位，支持64个节点）
    wire [`FLIT_W -1:0]     pkt_in_data;     // 数据负载（8位）
    wire                    pkt_in_rdy;      // 接收就绪信号（反压控制）

    // 主机模式 - 数据发送方使用（如外部测试环境）
    modport mst(
        input   pkt_in_vld,                    // 发送数据包有效信号
        input   pkt_in_qos,                    // 发送QoS优先级
        input   pkt_in_type,                   // 发送数据包类型
        input   pkt_in_src,                    // 发送源节点ID
        input   pkt_in_tgt,                    // 发送目标节点ID
        input   pkt_in_data,                   // 发送数据负载
        output  pkt_in_rdy                     // 接收方就绪状态
    );

    // 从机模式 - 数据接收方使用（如MAZE节点）
    modport slv(
        output  pkt_in_vld,                    // 接收数据包有效信号
        output  pkt_in_qos,                    // 接收QoS优先级
        output  pkt_in_type,                   // 接收数据包类型
        output  pkt_in_src,                    // 接收源节点ID
        output  pkt_in_tgt,                    // 接收目标节点ID
        output  pkt_in_data,                   // 接收数据负载
        input   pkt_in_rdy                     // 发送接收就绪信号
    );
endinterface : pkt_in