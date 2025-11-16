# MAZE节点基本路由功能测试指南

## 概述

本指南详细介绍如何使用MAZE网络节点基本路由功能测试环境。测试环境使用Verilator仿真器，验证节点的五个P0级别基本路由功能测试点。

## 🚀 快速开始

### 环境要求

- **仿真器**: Verilator 4.0+
- **操作系统**: Linux/macOS
- **依赖工具**: make, gcc/g++, git

### 安装依赖

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install verilator gtkwave
```

#### macOS
```bash
brew install verilator gtkwave
```

### 验证安装
```bash
verilator --version
```

## 📁 测试环境结构

```
verification/
├── testbench/node_basic_routing/    # 测试台文件
│   ├── simple_test.sv              # SystemVerilog测试台
│   ├── test_node_wrapper.sv        # 节点测试包装器
│   ├── packet_generator.h          # 数据包生成器
│   ├── result_checker.h            # 结果检查器
│   └── node_basic_routing_tb.cpp   # C++测试主程序
├── scripts/node_basic_routing/     # 构建脚本
│   └── build_simple_test.sh        # 编译脚本（仅支持Verilator）
├── sim/                            # 仿真输出
│   ├── build/                      # 编译产物
│   └── wave/fst/                   # 波形文件
└── Makefile                        # 顶层Makefile
```

## 🧪 测试用例说明

### P0级别基本路由功能测试

| 测试点 | 描述 | 输入 | 预期输出 |
|--------|------|------|----------|
| N-RF-001 | X方向正向路由 | A端口→目标X>当前X | C口_E |
| N-RF-002 | X方向反向路由 | A端口→目标X<当前X | C口_W |
| N-RF-003 | Y方向正向路由 | A端口→目标Y>当前Y | C口_N |
| N-RF-004 | Y方向反向路由 | A端口→目标Y<当前Y | C口_S |
| N-RF-005 | 本地路由 | A端口→目标=当前 | B口 |

### 测试参数配置

```bash
# 节点位置参数
NODE_X=3    # 节点X坐标 (0-7)
NODE_Y=3    # 节点Y坐标 (0-7)

# 仿真器参数
SIMULATOR=verilator    # 只能使用verilator
```

## 🛠️ 运行测试

### 方法1：使用Makefile（推荐）

```bash
# 进入验证目录
cd verification

# 快速测试（默认节点(3,3)）
make test-quick

# 测试指定节点
make test-node-basic NODE_X=2 NODE_Y=4

# 测试边缘节点
make test-edge-nodes

# 测试角落节点
make test-corner-nodes

# 完整测试套件
make test-all
```

### 方法2：直接使用构建脚本

```bash
# 基本测试
./scripts/node_basic_routing/build_simple_test.sh verilator 3 3
cd sim/build
./Vsimple_test

# 查看波形
gtkwave sim/wave/fst/simple_test_3_3.fst
```

### 自定义测试

```bash
# 测试任意节点位置
./scripts/node_basic_routing/build_simple_test.sh verilator [X坐标] [Y坐标]

# 示例：测试不同位置节点
./scripts/node_basic_routing/build_simple_test.sh verilator 0 0  # 左下角
./scripts/node_basic_routing/build_simple_test.sh verilator 0 7  # 左上角
./scripts/node_basic_routing/build_simple_test.sh verilator 7 0  # 右下角
./scripts/node_basic_routing/build_simple_test.sh verilator 7 7  # 右上角

# 边缘节点测试
./scripts/node_basic_routing/build_simple_test.sh verilator 3 0  # 南边缘
./scripts/node_basic_routing/build_simple_test.sh verilator 3 7  # 北边缘
./scripts/node_basic_routing/build_simple_test.sh verilator 0 3  # 西边缘
./scripts/node_basic_routing/build_simple_test.sh verilator 7 3  # 东边缘
```

## 📊 测试输出解读

### 成功示例
```
==============================================
MAZE节点基本路由功能测试
==============================================
仿真器: verilator
测试节点位置: (3, 3)
==============================================

✓ N-RF-001: X方向正向路由测试通过
✓ N-RF-002: X方向反向路由测试通过
✓ N-RF-003: Y方向正向路由测试通过
✓ N-RF-004: Y方向反向路由测试通过
✓ N-RF-005: 本地路由测试通过

测试总结: 5/5 测试通过
==============================================
```

### 输出端口映射
- **端口0**: C接口北方向输出
- **端口1**: C接口西方向输出
- **端口2**: C接口南方向输出
- **端口3**: C接口东方向输出
- **端口4**: B接口本地输出

## 🔍 调试和故障排除

### 常见问题

#### 1. 编译错误
```bash
# 检查依赖
verilator --version

# 检查文件路径
ls -la rtl/src/node/node.v

# 尝试简化的测试台
./scripts/node_basic_routing/build_simple_test.sh verilator 3 3
```

#### 2. 路由结果不正确
```bash
# 生成波形进行调试
make test-quick SIMULATOR=verilator
gtkwave sim/wave/fst/simple_test_3_3.fst

# 检查节点坐标设置
make test-node-basic NODE_X=3 NODE_Y=3 SIMULATOR=verilator
```

#### 3. 波形文件无法打开
```bash
# 检查波形文件是否存在
ls -la sim/wave/fst/

# 确保测试时生成了波形
make test-quick SIMULATOR=verilator
```

### 编译错误排查

#### 错误1: 找不到Verilator
```bash
# 安装Verilator
sudo apt-get install verilator  # Ubuntu/Debian
brew install verilator          # macOS

# 验证安装
verilator --version
```

#### 错误2: Verilator编译失败
```
%Error: 如下错误信息...
```

**解决方案**：
1. 检查SystemVerilog语法是否正确
2. 确认所有RTL文件路径正确
3. 检查Verilator版本兼容性

#### 错误3: 找不到RTL文件
```bash
# 检查项目结构
find . -name "*.v" -o -name "*.sv"

# 确保在正确的目录运行测试
cd /path/to/maze_mesh/verification
```

## 📈 测试结果分析

### 路由决策表

对于节点(3,3)的路由决策：

| 目标节点 | 期望输出端口 | 测试验证 |
|----------|--------------|----------|
| (5,3) | C口_E (东) | N-RF-001 |
| (1,3) | C口_W (西) | N-RF-002 |
| (3,5) | C口_N (北) | N-RF-003 |
| (3,1) | C口_S (南) | N-RF-004 |
| (3,3) | B口 (本地) | N-RF-005 |

### 边界条件测试

特殊节点位置的路由行为：

| 节点位置 | 限制方向 | 特殊处理 |
|----------|----------|----------|
| (0,0) | 无西向、南向输出 | 边界检查 |
| (7,7) | 无东向、北向输出 | 边界检查 |
| (0,y) | 无西向输出 | 边界检查 |
| (x,0) | 无南向输出 | 边界检查 |

## 📚 参考资料

### 项目文档
- **[MAZE网络架构文档](../../CLAUDE.md)** - 项目总体架构
- **[测试点分解文档](test_point_decomposition.md)** - 详细测试点说明
- **[节点实现规范](../../../rtl/src/node/node.v)** - 节点模块实现

### 技术标准
- **SystemVerilog IEEE 1800** - 验证语言标准
- **MAZE网络规范** - 项目内部技术规范
- **23位数据包格式** - 网络通信协议

### 工具文档
- **[Verilator用户手册](https://www.veripool.org/wiki/verilator)** - SystemVerilog编译器文档
- **[GTKWave手册](https://gtkwave.sourceforge.net/)** - 波形查看器文档

## 🤝 贡献指南

### 代码贡献
1. Fork项目仓库
2. 创建功能分支
3. 提交测试代码
4. 运行完整测试套件
5. 提交Pull Request

### 测试用例开发
- 遵循P0-P3优先级分类
- 包含完整的输入输出验证
- 提供清晰的测试描述
- 添加边界条件测试

### 问题报告
- 提供完整的错误信息
- 包含系统环境信息
- 附加相关日志文件
- 描述重现步骤

---

**注意：只能使用verilator，而不能使用iverilog或者任意其他仿真软件**

**文档维护**: MAZE验证团队
**最后更新**: 2024年
**版本**: v1.0