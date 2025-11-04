# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a 64-node Network-on-Chip (NoC) router network project implemented in SystemVerilog and simulated with Verilator. The design uses an 8×8 2D mesh topology with two main modules: `node` (individual routers) and `topo` (network topology). A key constraint is that custom IRS (Register Chain) modules must be used as the primary building blocks, especially in the `topo` module.

## Common Development Commands

### Building and Simulation
```bash
# Build simulation environment with testbenches
./scripts/build_simulation.sh --with-tests

# Build all modules
./scripts/build_simulation.sh --all

# Clean build files
./scripts/build_simulation.sh --clean

# Run all tests
./scripts/run_all_tests.sh

# Run tests with specific options
./scripts/run_all_tests.sh --skip-syntax  # Skip syntax checks
./scripts/run_all_tests.sh --syntax-only   # Run syntax checks only
```

### Single Test Execution
```bash
# Build specific module (example: router core)
cd rtl
verilator -Wall --cc --exe --top tb_node_router_core \
  tb/tb_node_router_core.sv \
  node/node_router_core.sv \
  pkg/noc_network_pkg.sv

cd obj_dir && make -f Vtb_node_router_core.mk && ./Vtb_node_router_core
```

### Project Setup
```bash
# The project structure is already created with:
# - docs/     : Comprehensive documentation (8 files)
# - rtl/      : RTL modules and testbenches
# - scripts/  : Build and test automation
# - irs_modules/ : Place your IRS modules here
```

## Architecture Overview

### Network Topology
- **8×8 2D Mesh**: 64 routers arranged in grid, each connecting to N/S/E/W neighbors
- **5-Port Router**: Each router has North, South, East, West, and Local ports
- **Hierarchical Design**: System → Network → Node → Router → Components

### Node Architecture
Each node contains:
- **Router Core**: 4-stage pipeline (Route, VC Alloc, Switch Alloc, Crossbar)
- **Network Interface**: Processing element communication
- **Network Management**: Configuration and monitoring
- **IRS Integration**: Register chain modules for buffers and state machines

### IRS Module Integration Constraint
- **Critical**: Only IRS modules can be used in `topo.v`
- **Standard Interfaces**: All IRS modules must use defined wrapper interfaces
- **Primary Uses**: Buffer management, state machines, control logic, configuration registers

### Protocol and Packet Structure
- **Header-Based Routing**: All routing information in packet header
- **Flit Types**: Head, Body, Tail, and Single flit packets
- **QoS Support**: 4 priority levels (Low, Medium, High, Critical)
- **Flow Control**: Credit-based backpressure system

## Key Design Patterns

### Incremental Development Process
The project follows a strict **Write-Test-Verify** cycle:
1. Write RTL module
2. Create dedicated testbench immediately
3. Run Verilator simulation
4. Verify functionality meets requirements
5. Document results
6. Only then proceed to next module

### Module Dependencies
```
noc_network_pkg.sv (shared definitions)
    ↓
node_router_core.sv (basic 5-port router)
    ↓
node_buffer_manager.sv (IRS-based buffers)
    ↓
node_routing_unit.sv (routing logic)
    ↓
node_switch_allocator.sv (arbitration)
    ↓
node_crossbar.sv (switch fabric)
    ↓
node.sv (complete node integration)
    ↓
topo_mesh_8x8.sv (8×8 topology using IRS modules)
    ↓
topo.sv (main topology module - IRS ONLY constraint)
```

### Interface Standards
- **Valid/Ready Handshake**: Standard protocol for all data channels
- **Credit-Based Flow Control**: Prevents buffer overflow
- **Virtual Channels**: Multiple VCs per physical channel for QoS
- **IRS Wrapper**: Standard interface for all IRS modules

## Critical Constraints

1. **IRS Module Constraint**: The `topo.v` module must only use IRS register chain modules - no custom RTL allowed
2. **Timing First**: All designs must meet 200 MHz (5ns) timing constraint
3. **Parameterization**: All modules must be configurable through parameters
4. **Immediate Testing**: Each RTL file must be tested immediately after creation

## Documentation Structure

The `docs/` directory contains comprehensive specifications:
- **project_plan.md**: Master development plan with progress tracking
- **constraints_template.md**: Template for user to fill with specific requirements
- **architecture_design.md**: Detailed network architecture
- **routing_strategies.md**: XY, adaptive, and multicast routing algorithms
- **protocol_definition.md**: Packet formats and communication protocols
- **irs_integration_plan.md**: Strategy for IRS module integration
- **testing_strategy.md**: Comprehensive verification approach
- **requirements_spec.md**: Functional and performance requirements

## Development Status

The project is in **Phase 1: Setup and Requirements**. All documentation and project structure is complete. The next phase requires:
1. User to fill the constraints template with specific requirements
2. User to provide IRS module files
3. Begin incremental RTL development starting with the network package

## File Organization Notes

- **Template files**: Some basic RTL templates exist in `rtl/node/` and `rtl/tb/` but need full implementation
- **Package File**: `rtl/pkg/noc_network_pkg.sv` contains all shared parameters, types, and interfaces
- **Testbenches**: Follow naming convention `tb_<module_name>.sv` in `rtl/tb/`
- **Build Output**: All Verilator output goes to `rtl/obj_dir/`
- **Test Results**: Automated test reports go to `test_results/`