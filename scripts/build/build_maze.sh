#!/bin/bash

# MAZE Network Build Script
# Usage: ./scripts/build/build_maze.sh [module_name] [wave_format]

set -e

# Default parameters
MODULE="MAZE_TOP"
WAVE_FORMAT="vcd"
BUILD_DIR="../../sim/build/obj_dir"
RTL_ROOT="../../rtl"

# Parse command line arguments
if [ $# -ge 1 ]; then
    MODULE="$1"
fi

if [ $# -ge 2 ]; then
    WAVE_FORMAT="$2"
fi

echo "=== MAZE Network Build Script ==="
echo "Module: $MODULE"
echo "Wave Format: $WAVE_FORMAT"
echo "Build Directory: $BUILD_DIR"
echo "RTL Root: $RTL_ROOT"
echo ""

# Create build directory
mkdir -p "$(dirname "$BUILD_DIR")"
cd "$(dirname "$BUILD_DIR")"
cd ../..

# Determine module path based on module name
if [ "$MODULE" = "MAZE_TOP" ]; then
    MODULE_PATH="$RTL_ROOT/src/system/$MODULE.v"
elif [ "$MODULE" = "node" ]; then
    MODULE_PATH="$RTL_ROOT/src/node/$MODULE.v"
elif [ "$MODULE" = "topo" ]; then
    MODULE_PATH="$RTL_ROOT/src/topo/$MODULE.v"
else
    echo "Error: Unknown module '$MODULE'"
    echo "Supported modules: MAZE_TOP, node, topo"
    exit 1
fi

# Verilator compilation command
echo "=== Compiling $MODULE with Verilator ==="
echo "Module path: $MODULE_PATH"

verilator --top-module "$MODULE" \
    --cc -f rtl.filelist \
    -I"$RTL_ROOT/include" \
    -Wno-fatal \
    --CFLAGS "-std=c++11" \
    --Mdir obj_dir \
    --trace \
    --trace-fst \
    --trace-structs \
    --trace-underscore

echo "=== Compilation completed ==="

# Build the executable
echo "=== Building executable ==="
cd obj_dir
make -f "V$MODULE.mk"

echo "=== Build completed successfully ==="
echo ""
echo "Executable: ./V$MODULE"
echo "Wave format: $WAVE_FORMAT"
echo ""
echo "Usage examples:"
echo "  ./V$MODULE                    # Run simulation"
echo "  ./V$MODULE +trace             # Run with trace output"
echo "  ./V$MODULE +verbose           # Run with verbose output"