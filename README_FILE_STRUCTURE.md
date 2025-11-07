# MAZE Project File Architecture

## Overview

This document describes the organized file structure for the MAZE 64-node network project, designed to support systematic development, verification, and maintenance.

## Directory Structure

```
maze/
├── 📁 Provided_Code/              # 🔒 Original reference files (DO NOT MODIFY)
│   ├── interface_a.sv             # Original A interface
│   ├── interface_b.sv             # Original B interface
│   ├── irs.v                      # Original IRS modules
│   ├── top_define.v               # Original global definitions
│   ├── node.v                     # Original node module
│   ├── topo.v                     # Original topo module
│   └── MAZE_TOP.v                 # Original top-level module
├── 📁 rtl/                        # ✅ Modifiable RTL code
│   ├── include/                   # Header files and interface definitions
│   │   ├── interfaces/
│   │   │   ├── interface_a.sv     # A interface (copied, modifiable)
│   │   │   ├── interface_b.sv     # B interface (copied, modifiable)
│   │   │   └── interface_c.sv     # C interface (custom, modifiable)
│   │   └── global_defines/
│   │       └── top_define.v       # Global parameters (copied, modifiable)
│   ├── src/                       # Core RTL source code
│   │   ├── node/
│   │   │   ├── node.v             # Node module with 4-stage pipeline
│   │   │   └── node_components/    # Node sub-modules
│   │   ├── topo/
│   │   │   ├── topo.v             # Topology connectivity module
│   │   │   └── topo_components/    # Topology sub-modules
│   │   └── system/
│   │       └── MAZE_TOP.v         # 64-node top-level module
│   └── lib/                       # Third-party IP and libraries
│       └── irs/
│           └── irs.v              # IRS module library (copied, modifiable)
├── 📁 testbench/                  # ✅ Test environment directory
│   ├── include/                   # Common test header files
│   ├── src/                       # Test source code
│   │   ├── unit_tests/            # Unit tests (individual modules)
│   │   ├── integration_tests/     # Integration tests (module interactions)
│   │   └── system_tests/          # System tests (full network)
│   ├── cpp/                       # C++ test code (Verilator)
│   └── python/                    # Python scripts (optional)
├── 📁 sim/                        # 🗂️ Temporary simulation files
│   ├── build/                     # Compilation output files
│   │   ├── obj_dir/               # Verilator generated files
│   │   └── work/                  # Simulator working directory
│   ├── run/                       # Runtime files
│   │   ├── logs/                  # Simulation logs
│   │   └── temp/                  # Temporary files
│   └── wave/                      # 📊 Waveform files directory
│       ├── fsdb/                  # FSDB waveform files (Verdi)
│       ├── vpd/                   # VPD waveform files (VCS)
│       ├── vcd/                   # VCD waveform files (GTKWave)
│       └── fst/                   # FST waveform files (Icarus)
├── 📁 reports/                    # 📄 Report files directory
│   ├── synthesis/                 # Synthesis reports
│   ├── simulation/                # Simulation reports
│   ├── coverage/                  # Code coverage reports
│   ├── timing/                    # Timing analysis reports
│   └── summary/                   # Summary reports
├── 📁 docs/                       # 📚 Project documentation
│   ├── design/                    # Design specifications
│   ├── verification/              # Verification plans and results
│   └── user_guide/                # User guides and tutorials
├── 📁 scripts/                    # 🔧 Utility scripts
│   ├── build/                     # Build scripts
│   ├── run/                       # Run scripts
│   └── utils/                     # Utility scripts
├── 📁 workspace/                  # 🗂️ Development workspace
│   ├── backup/                    # Backup files
│   └── scratch/                   # Draft and experimental files
├── 📁 maze_impl/                  # Legacy implementation (preserved)
│   └── (original implementation files)
├── 📄 CLAUDE.md                   # Claude Code guidance
├── 📄 MAZE_题目.md               # Original requirements (Chinese)
└── 📄 README_FILE_STRUCTURE.md    # This file
```

## File Classification Rules

### 🔒 Immutable Files (DO NOT MODIFY)

**Location**: `Provided_Code/`

These files serve as the original reference and should never be directly modified:
- All original interface definitions
- Original module implementations
- Original parameter definitions
- Original requirements documents

### ✅ Modifiable RTL Code

**Location**: `rtl/`

All RTL development should happen in this directory structure:
- **Interfaces**: `rtl/include/interfaces/` - Communication interfaces
- **Global Defines**: `rtl/include/global_defines/` - Project-wide parameters
- **Source Code**: `rtl/src/` - Core RTL implementations
- **Libraries**: `rtl/lib/` - Third-party IP and reusable components

### ✅ Test Environment

**Location**: `testbench/`

All verification code should be organized here:
- **Unit Tests**: Individual module testing
- **Integration Tests**: Multi-module interaction testing
- **System Tests**: Full network verification
- **C++ Tests**: Verilator-based C++ testbenches

### 🗂️ Temporary Files

**Location**: `sim/` and `workspace/`

Files that can be safely deleted:
- **Build Artifacts**: `sim/build/` - Compilation outputs
- **Runtime Files**: `sim/run/temp/` - Temporary runtime data
- **Waveform Files**: `sim/wave/` - Simulation waveforms
- **Development Files**: `workspace/scratch/` - Experimental code

### 📊 Waveform Files

**Location**: `sim/wave/`

Organized by waveform format:
- `sim/wave/vcd/` - VCD format (universal)
- `sim/wave/fsdb/` - FSDB format (Verdi)
- `sim/wave/vpd/` - VPD format (Synopsys VCS)
- `sim/wave/fst/` - FST format (Icarus/GTKWave)

### 📄 Report Files

**Location**: `reports/`

Organized by report type:
- `reports/simulation/` - Simulation results and analysis
- `reports/coverage/` - Code coverage analysis
- `reports/timing/` - Static timing analysis
- `reports/synthesis/` - Synthesis results and area/timing

## Development Workflow

### 1. RTL Development
```bash
# Work in rtl/src/ directory
cd rtl/src/node/
# Edit node.v
# Run simulation
```

### 2. Verification
```bash
# Create test in testbench/src/unit_tests/
# Run simulation from sim/build/
# Check waveforms in sim/wave/vcd/
```

### 3. Documentation
```bash
# Add design specs to docs/design/
# Update verification plans in docs/verification/
```

## Best Practices

1. **Never modify files in `Provided_Code/`** - always copy to `rtl/` first
2. **Keep test code separate from RTL** - use `testbench/` directory
3. **Clean temporary files regularly** - especially `sim/build/` and `sim/run/temp/`
4. **Document design decisions** - use `docs/design/` directory
5. **Version control important files** - focus on `rtl/` and `testbench/` directories
6. **Use appropriate waveform format** - choose based on available tools
7. **Generate reports regularly** - store in `reports/` with appropriate categorization

## Migration Status

✅ **Completed**:
- Directory structure created
- Original files copied to appropriate RTL directories
- README documentation created

⏳ **Next Steps**:
- Create initial testbench framework
- Set up build scripts in `scripts/build/`
- Create sample test cases in `testbench/src/`
- Generate initial documentation in `docs/`