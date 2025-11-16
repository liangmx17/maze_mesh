# 验证脚本目录

## 说明
本目录包含用于自动化验证流程的各种脚本和工具。

## 脚本分类

### run_regression/
**回归测试脚本**
- `run_all_tests.sh`: 运行完整回归测试
- `run_unit_tests.sh`: 仅运行单元测试
- `run_integration_tests.sh`: 仅运行集成测试
- `run_system_tests.sh`: 仅运行系统测试
- `generate_regression_report.sh`: 生成回归测试报告

### run_simulation/
**仿真运行脚本**
- `run_single_test.sh`: 运行单个测试
- `run_batch_tests.sh`: 批量运行测试
- `run_with_coverage.sh`: 带覆盖率收集的仿真
- `run_with_debug.sh`: 调试模式仿真
- `cleanup_simulation.sh`: 清理仿真临时文件

### generate_waveforms/
**波形生成脚本**
- `convert_vcd_to_fst.sh`: VCD转FST格式
- `extract_waveform.sh`: 提取特定时间段波形
- `merge_waveforms.sh`: 合并多个波形文件
- `generate_waveview_scripts.sh`: 生成波形查看器脚本

### analyze_results/
**结果分析脚本**
- `parse_simulation_log.sh`: 解析仿真日志
- `extract_performance_metrics.sh`: 提取性能指标
- `compare_test_results.sh`: 比较测试结果
- `generate_summary_report.sh`: 生成总结报告

## 使用示例

### 运行回归测试
```bash
cd verification/scripts/run_regression
./run_all_tests.sh
```

### 带覆盖率运行测试
```bash
cd verification/scripts/run_simulation
./run_with_coverage.sh -test router_unit_basic -coverage
```

### 生成波形
```bash
cd verification/scripts/generate_waveforms
./convert_vcd_to_fst.sh input.vcd output.fst
```

### 分析结果
```bash
cd verification/scripts/analyze_results
./generate_summary_report.sh -report verification/reports/regression/
```

## 配置文件
- `config/default.conf`: 默认配置
- `config/simulation.conf`: 仿真参数配置
- `config/coverage.conf`: 覆盖率配置
- `config/performance.conf`: 性能测试配置