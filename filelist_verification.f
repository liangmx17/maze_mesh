# MAZE网络RTL文件列表 - 验证专用
# 包含所有需要编译的RTL源文件，专门用于verification环境

# 全局参数定义 (必须最先包含)
rtl/top_define.v
rtl/USER_DEFINE/param.v

# 接口定义
rtl/interface_a.sv
rtl/interface_b.sv
rtl/USER_DEFINE/interface_port_c.sv

# 基础模块
rtl/irs.v

# 用户定义模块 (按依赖关系排序)
rtl/USER_DEFINE/arbiter.v
rtl/USER_DEFINE/fault_relative_pos_detect.v
rtl/USER_DEFINE/pre_router.v
rtl/USER_DEFINE/multi_packet_gen.v
rtl/USER_DEFINE/IBUF.v
rtl/USER_DEFINE/IBUF_A_CTRL.v
rtl/USER_DEFINE/IBUF_A_DATA.v
rtl/USER_DEFINE/OBUF.v
rtl/USER_DEFINE/node.v
rtl/USER_DEFINE/topo.v