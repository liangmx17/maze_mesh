#!/bin/bash

# NoC 64-Node Network Build Script
# This script builds the simulation environment with proper configuration

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Project configuration
NOC_ROOT=$(pwd)
RTL_DIR="$NOC_ROOT/rtl"
OBJ_DIR="$RTL_DIR/obj_dir"
PKG_DIR="$RTL_DIR/pkg"
NODE_DIR="$RTL_DIR/node"
TOPO_DIR="$RTL_DIR/topo"

# Print functions
print_status() {
    echo -e "${BLUE}[$(date '+%Y-%m-%d %H:%M:%S')]${NC} $1"
}

print_success() {
    echo -e "${GREEN}✓${NC} $1"
}

print_error() {
    echo -e "${RED}✗${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}⚠${NC} $1"
}

# Check dependencies
check_dependencies() {
    print_status "Checking build dependencies..."

    local missing_deps=()

    if ! command -v verilator &> /dev/null; then
        missing_deps+=("verilator")
    fi

    if ! command -v make &> /dev/null; then
        missing_deps+=("make")
    fi

    if ! command -v python3 &> /dev/null; then
        missing_deps+=("python3")
    fi

    if [ ${#missing_deps[@]} -ne 0 ]; then
        print_error "Missing dependencies: ${missing_deps[*]}"
        echo ""
        echo "Please install the missing dependencies:"
        echo "  - Ubuntu/Debian: sudo apt-get install verilator make python3"
        echo "  - CentOS/RHEL:   sudo yum install verilator make python3"
        echo "  - macOS:         brew install verilator make python3"
        exit 1
    fi

    local verilator_version=$(verilator -version | head -n1)
    print_success "Verilator: $verilator_version"
    print_success "Dependencies check passed"
}

# Create build directories
create_directories() {
    print_status "Creating build directories..."

    mkdir -p "$OBJ_DIR"
    mkdir -p "$PKG_DIR"
    mkdir -p "$NODE_DIR"
    mkdir -p "$TOPO_DIR"
    mkdir -p "$RTL_DIR/tb"

    print_success "Directories created"
}

# Create network package
create_network_package() {
    local pkg_file="$PKG_DIR/noc_network_pkg.sv"

    print_status "Creating network package..."

    cat > "$pkg_file" << 'EOF'
// NoC 64-Node Network Package
// Contains common parameters, types, and definitions

package noc_network_pkg;

    // Network configuration parameters
    parameter int NODES_X = 8;              // Nodes in X dimension
    parameter int NODES_Y = 8;              // Nodes in Y dimension
    parameter int NUM_NODES = NODES_X * NODES_Y;  // Total nodes

    // Data path parameters
    parameter int DATA_WIDTH = 32;          // Data width in bits
    parameter int ADDR_WIDTH = 6;           // Address width (for 64 nodes)
    parameter int FLIT_WIDTH = 32;          // Flit width

    // Buffer and flow control
    parameter int NUM_VCS = 2;              // Virtual channels per port
    parameter int BUFFER_DEPTH = 8;         // Buffer depth per VC
    parameter int MAX_PACKET_LEN = 16;      // Maximum flits per packet

    // Router parameters
    parameter int NUM_PORTS = 5;            // 4 directions + local
    parameter int PIPELINE_STAGES = 4;      // Router pipeline stages

    // QoS parameters
    parameter int QOS_LEVELS = 4;           // Quality of Service levels
    parameter int QOS_WIDTH = 2;            // Bits for QoS encoding

    // Timing parameters
    parameter int CLOCK_PERIOD_NS = 5;      // 5ns = 200MHz
    parameter int SETUP_TIME_NS = 0;        // Setup time (for simulation)
    parameter int HOLD_TIME_NS = 0;         // Hold time (for simulation)

    // Coordinate types
    typedef struct packed {
        logic [$clog2(NODES_X)-1:0] x;
        logic [$clog2(NODES_Y)-1:0] y;
    } node_coord_t;

    // Direction encoding
    typedef enum logic [2:0] {
        DIR_NORTH = 3'b000,
        DIR_EAST  = 3'b001,
        DIR_SOUTH = 3'b010,
        DIR_WEST  = 3'b011,
        DIR_LOCAL = 3'b100,
        DIR_NONE  = 3'b111
    } direction_t;

    // QoS level encoding
    typedef enum logic [QOS_WIDTH-1:0] {
        QOS_LOW      = 2'b00,
        QOS_MEDIUM   = 2'b01,
        QOS_HIGH     = 2'b10,
        QOS_CRITICAL = 2'b11
    } qos_level_t;

    // Flit type encoding
    typedef enum logic [2:0] {
        FLIT_HEAD   = 3'b000,
        FLIT_BODY   = 3'b001,
        FLIT_TAIL   = 3'b010,
        FLIT_SINGLE = 3'b011,
        FLIT_RESERVED_4 = 3'b100,
        FLIT_RESERVED_5 = 3'b101,
        FLIT_RESERVED_6 = 3'b110,
        FLIT_RESERVED_7 = 3'b111
    } flit_type_t;

    // Packet header structure
    typedef struct packed {
        logic [2:0]              flit_type;    // Flit type
        logic [QOS_WIDTH-1:0]     qos_level;    // QoS level
        logic [22:16]             src_x;        // Source X coordinate
        logic [31:24]             src_y;        // Source Y coordinate
        logic [23:16]             dst_x;        // Destination X coordinate
        logic [15:8]              dst_y;        // Destination Y coordinate
        logic [7:0]               packet_id;    // Packet identifier
        logic [31:16]             packet_len;   // Packet length
        logic [15:0]              vc_id;        // Virtual channel ID
        logic [31:24]             protocol_id;  // Protocol identifier
        logic [23:16]             service_id;   // Service type
        logic [7:0]               control_flags;// Control flags
    } packet_header_t;

    // Valid/Ready interface
    interface VRChannel #(parameter WIDTH = FLIT_WIDTH);
        logic        valid;
        logic        ready;
        logic [WIDTH-1:0] data;

        modport master (
            output valid,
            input  ready,
            output data
        );

        modport slave (
            input  valid,
            output ready,
            input  data
        );
    endinterface

    // Router interface
    interface RouterLink;
        logic                       clk;
        logic                       rst_n;
        logic [NUM_VCS-1:0]         vc_valid;
        logic [NUM_VCS-1:0]         vc_ready;
        logic [NUM_VCS-1:0][FLIT_WIDTH-1:0] vc_data;
        logic [NUM_VCS-1:0]         vc_credit;
    endinterface

    // Node interface
    interface NodeInterface;
        logic                       clk;
        logic                       rst_n;
        logic                       tx_valid;
        logic                       tx_ready;
        logic [FLIT_WIDTH-1:0]      tx_data;
        logic                       rx_valid;
        logic                       rx_ready;
        logic [FLIT_WIDTH-1:0]      rx_data;
    endinterface

    // Calculate Manhattan distance between two nodes
    function automatic int manhattan_distance(node_coord_t a, node_coord_t b);
        return abs(int'(a.x) - int'(b.x)) + abs(int'(a.y) - int'(b.y));
    endfunction

    // Convert node ID to coordinates
    function automatic node_coord_t node_id_to_coord(input int [$clog2(NUM_NODES)-1:0] node_id);
        node_coord_t coord;
        coord.x = node_id % NODES_X;
        coord.y = node_id / NODES_X;
        return coord;
    endfunction

    // Convert coordinates to node ID
    function automatic int coord_to_node_id(input node_coord_t coord);
        return coord.y * NODES_X + coord.x;
    endfunction

endpackage
EOF

    print_success "Network package created: $pkg_file"
}

# Create template files
create_template_files() {
    print_status "Creating template RTL files..."

    # Create template router core
    local router_core_file="$NODE_DIR/node_router_core.sv"
    if [ ! -f "$router_core_file" ]; then
        cat > "$router_core_file" << 'EOF'
// Router Core Template
// Basic 5-port router implementation

`include "noc_network_pkg.sv"

module node_router_core #(
    parameter DATA_WIDTH = noc_network_pkg::DATA_WIDTH,
    parameter NUM_PORTS = noc_network_pkg::NUM_PORTS,
    parameter NUM_VCS = noc_network_pkg::NUM_VCS
) (
    input  logic                        clk,
    input  logic                        rst_n,

    // Input ports (N, S, E, W, Local)
    input  logic [NUM_PORTS-1:0]         in_valid,
    output logic [NUM_PORTS-1:0]         in_ready,
    input  logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] in_data,
    input  logic [NUM_PORTS-1:0][$clog2(NUM_VCS)-1:0] in_vc_id,

    // Output ports (N, S, E, W, Local)
    output logic [NUM_PORTS-1:0]         out_valid,
    input  logic [NUM_PORTS-1:0]         out_ready,
    output logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] out_data,
    output logic [NUM_PORTS-1:0][$clog2(NUM_VCS)-1:0] out_vc_id,

    // Control and status
    output logic [31:0]                 status,
    input  logic [31:0]                 config
);

    // TODO: Implement router core logic
    // - Input buffers
    // - Route computation
    // - Virtual channel allocation
    // - Switch allocation
    // - Crossbar switching

    // Placeholder implementation
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Reset state
            out_valid <= '0;
            out_data <= '0;
            out_vc_id <= '0;
            status <= '0;
        end else begin
            // Basic pass-through for now
            out_valid <= in_valid;
            out_data <= in_data;
            out_vc_id <= in_vc_id;
            status <= {32'h1};  // Ready status
        end
    end

    // Ready signals (placeholder)
    assign in_ready = out_ready;

endmodule
EOF
        print_success "Created router core template"
    fi

    # Create template testbench
    local tb_file="$RTL_DIR/tb/tb_node_router_core.sv"
    if [ ! -f "$tb_file" ]; then
        cat > "$tb_file" << 'EOF'
// Router Core Testbench Template

`include "noc_network_pkg.sv"

module tb_node_router_core;
    // Testbench parameters
    parameter DATA_WIDTH = noc_network_pkg::DATA_WIDTH;
    parameter NUM_PORTS = noc_network_pkg::NUM_PORTS;
    parameter NUM_VCS = noc_network_pkg::NUM_VCS;

    // Clock and reset
    logic clk;
    logic rst_n;

    // DUT signals
    logic [NUM_PORTS-1:0]         in_valid;
    logic [NUM_PORTS-1:0]         in_ready;
    logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] in_data;
    logic [NUM_PORTS-1:0][$clog2(NUM_VCS)-1:0] in_vc_id;

    logic [NUM_PORTS-1:0]         out_valid;
    logic [NUM_PORTS-1:0]         out_ready;
    logic [NUM_PORTS-1:0][DATA_WIDTH-1:0] out_data;
    logic [NUM_PORTS-1:0][$clog2(NUM_VCS)-1:0] out_vc_id;

    logic [31:0]                 status;
    logic [31:0]                 config;

    // Instantiate DUT
    node_router_core #(
        .DATA_WIDTH(DATA_WIDTH),
        .NUM_PORTS(NUM_PORTS),
        .NUM_VCS(NUM_VCS)
    ) dut (.*);

    // Clock generation
    initial begin
        clk = 0;
        forever #2.5 clk = ~clk;  // 200 MHz
    end

    // Test sequence
    initial begin
        // Initialize
        $display("=== Router Core Testbench ===");
        rst_n = 0;
        in_valid = '0;
        in_data = '0;
        in_vc_id = '0;
        out_ready = '1;
        config = '0;

        #100;
        rst_n = 1;
        #10;

        // Test 1: Basic functionality
        $display("Test 1: Basic functionality");
        in_valid[0] = 1;
        in_data[0] = 32'hDEADBEEF;
        in_vc_id[0] = 0;

        #10;
        if (out_valid[0] && out_data[0] == 32'hDEADBEEF) begin
            $display("✓ Basic functionality test passed");
        end else begin
            $display("✗ Basic functionality test failed");
        end

        in_valid[0] = 0;
        #10;

        // TODO: Add more tests
        $display("TODO: Add comprehensive tests");
        $display("All tests completed!");
        $finish;
    end

    // Timeout
    initial begin
        #1000;
        $display("ERROR: Testbench timeout");
        $finish;
    end

endmodule
EOF
        print_success "Created testbench template"
    fi
}

# Build individual module
build_module() {
    local module_name=$1
    local source_file=$2
    local testbench_file=$3

    print_status "Building module: $module_name"

    cd "$RTL_DIR"

    if [ ! -f "$source_file" ]; then
        print_warning "Source file not found: $source_file"
        return 1
    fi

    # Compile with Verilator
    local compile_cmd="verilator -Wall --cc --exe"
    if [ -n "$testbench_file" ] && [ -f "$testbench_file" ]; then
        compile_cmd="$compile_cmd --top $module_name $testbench_file"
    else
        compile_cmd="$compile_cmd --top $module_name $source_file"
    fi

    # Add include directories
    compile_cmd="$compile_cmd -I$PKG_DIR -I$NODE_DIR -I$TOPO_DIR"

    # Add all source files
    compile_cmd="$compile_cmd $source_file $PKG_DIR/noc_network_pkg.sv"

    if $compile_cmd > "$OBJ_DIR/${module_name}_compile.log" 2>&1; then
        # Build executable
        cd "$OBJ_DIR"
        if make -f "V${module_name}.mk" >> "${module_name}_compile.log" 2>&1; then
            print_success "Module $module_name built successfully"
            return 0
        else
            print_error "Module $module_name build failed"
            return 1
        fi
    else
        print_error "Module $module_name compilation failed"
        echo "Check log: $OBJ_DIR/${module_name}_compile.log"
        return 1
    fi
}

# Main build process
main() {
    local build_tests=false
    local build_all=false

    # Parse command line arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            --with-tests)
                build_tests=true
                shift
                ;;
            --all)
                build_all=true
                shift
                ;;
            --clean)
                print_status "Cleaning build files..."
                if [ -d "$OBJ_DIR" ]; then
                    rm -rf "$OBJ_DIR"
                    print_success "Build files cleaned"
                else
                    print_warning "No build files to clean"
                fi
                exit 0
                ;;
            --help|-h)
                echo "Usage: $0 [OPTIONS]"
                echo "Options:"
                echo "  --with-tests  Build with testbenches"
                echo "  --all         Build all modules and tests"
                echo "  --clean        Clean build files"
                echo "  --help, -h     Show this help message"
                exit 0
                ;;
            *)
                print_error "Unknown option: $1"
                exit 1
                ;;
        esac
    done

    # Start build
    print_status "Starting NoC 64-Node build process..."

    # Check dependencies
    check_dependencies

    # Create directories
    create_directories

    # Create network package
    create_network_package

    # Create template files if they don't exist
    create_template_files

    # Build modules
    local modules_built=0
    local modules_failed=0

    # Build router core
    if [ -f "$NODE_DIR/node_router_core.sv" ]; then
        if build_all || [ "$build_tests" = true ]; then
            if build_module "tb_node_router_core" \
                           "$NODE_DIR/node_router_core.sv" \
                           "$RTL_DIR/tb/tb_node_router_core.sv"; then
                ((modules_built++))
            else
                ((modules_failed++))
            fi
        else
            if build_module "node_router_core" \
                           "$NODE_DIR/node_router_core.sv"; then
                ((modules_built++))
            else
                ((modules_failed++))
            fi
        fi
    fi

    # TODO: Add more modules as they are created
    # - node_buffer_manager
    # - node_routing_unit
    # - node_switch_allocator
    # - node_crossbar
    # - topo_mesh_8x8

    # Print build summary
    echo ""
    echo -e "${BLUE}=====================================${NC}"
    echo -e "${BLUE}        Build Summary              ${NC}"
    echo -e "${BLUE}=====================================${NC}"
    echo -e "Modules Built: ${GREEN}$modules_built${NC}"
    echo -e "Build Failed:  ${RED}$modules_failed${NC}"
    echo ""

    if [ $modules_failed -eq 0 ]; then
        print_success "🎉 Build completed successfully!"
        echo -e "Executables are in: ${OBJ_DIR}/"
        echo ""
        echo -e "To run tests: ${YELLOW}./scripts/run_all_tests.sh${NC}"
        exit 0
    else
        print_error "❌ Build failed for $modules_failed module(s)"
        echo -e "Check build logs in: ${OBJ_DIR}/"
        exit 1
    fi
}

# Run main function
main "$@"