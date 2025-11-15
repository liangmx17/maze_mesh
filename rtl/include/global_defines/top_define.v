// MAZE网络芯片全局参数定义
// 支持64节点网络的参数配置

`define QOS_W      1       // QoS服务质量宽度：0=低优先级，1=高优先级
`define ID_W       6       // 节点ID宽度：支持2^6=64个节点
`define TGTID_W    `ID_W   // 目标节点ID宽度（与ID_W相同）
`define SRCID_W    `ID_W   // 源节点ID宽度（与ID_W相同）
`define TYPE_W     2       // 数据包类型宽度：00=单播，01=X多播，10=Y多播，11=广播
`define FLIT_W     8       // 数据负载宽度 