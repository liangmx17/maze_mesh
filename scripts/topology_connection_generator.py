#!/usr/bin/env python3
"""
MAZE 8x8网格拓扑连接生成脚本
生成64个节点之间的NWSE方向连接关系
"""

GRID_SIZE = 8
TOTAL_NODES = GRID_SIZE * GRID_SIZE

def get_x_coord(node_id):
    """获取节点的X坐标"""
    return node_id % GRID_SIZE

def get_y_coord(node_id):
    """获取节点的Y坐标"""
    return node_id // GRID_SIZE

def coord_to_node_id(x, y):
    """将坐标转换为节点ID"""
    return y * GRID_SIZE + x

def get_neighbor_node(node_id, direction):
    """获取指定方向的邻居节点ID，如果无邻居则返回None"""
    x, y = get_x_coord(node_id), get_y_coord(node_id)

    if direction == "north":
        if y < GRID_SIZE - 1:
            return coord_to_node_id(x, y + 1)
    elif direction == "south":
        if y > 0:
            return coord_to_node_id(x, y - 1)
    elif direction == "west":
        if x > 0:
            return coord_to_node_id(x - 1, y)
    elif direction == "east":
        if x < GRID_SIZE - 1:
            return coord_to_node_id(x + 1, y)

    return None

def generate_connections():
    """生成所有节点的连接关系"""
    connections = []

    for node_id in range(TOTAL_NODES):
        x, y = get_x_coord(node_id), get_y_coord(node_id)
        print(f"\n// Node {node_id} ({y},{x}) connections:")

        # 北方输入：来自上方节点的南方输出
        north_neighbor = get_neighbor_node(node_id, "north")
        if north_neighbor is not None:
            print(f"// North connection from Node {north_neighbor}")
            connections.extend([
                f"assign pkt_con_if_{node_id}.ni_vld = pkt_con_if_{north_neighbor}.so_vld;",
                f"assign pkt_con_if_{node_id}.ni_qos = pkt_con_if_{north_neighbor}.so_qos;",
                f"assign pkt_con_if_{node_id}.ni_type = pkt_con_if_{north_neighbor}.so_type;",
                f"assign pkt_con_if_{node_id}.ni_src = pkt_con_if_{north_neighbor}.so_src;",
                f"assign pkt_con_if_{node_id}.ni_tgt = pkt_con_if_{north_neighbor}.so_tgt;",
                f"assign pkt_con_if_{node_id}.ni_data = pkt_con_if_{north_neighbor}.so_data;",
                f"assign pkt_con_if_{north_neighbor}.so_rdy = pkt_con_if_{node_id}.ni_rdy;"
            ])
        else:
            print(f"// North boundary - tie to 0")
            connections.extend([
                f"assign pkt_con_if_{node_id}.ni_vld = 1'b0;",
                f"assign pkt_con_if_{node_id}.ni_qos = 1'b0;",
                f"assign pkt_con_if_{node_id}.ni_type = 2'b00;",
                f"assign pkt_con_if_{node_id}.ni_src = 6'b000000;",
                f"assign pkt_con_if_{node_id}.ni_tgt = 6'b000000;",
                f"assign pkt_con_if_{node_id}.ni_data = 8'b00000000;",
                f"assign pkt_con_if_{node_id}.no_rdy = 1'b0;  // North boundary"
            ])

        # 南方输入：来自下方节点的北方输出
        south_neighbor = get_neighbor_node(node_id, "south")
        if south_neighbor is not None:
            print(f"// South connection from Node {south_neighbor}")
            connections.extend([
                f"assign pkt_con_if_{node_id}.si_vld = pkt_con_if_{south_neighbor}.no_vld;",
                f"assign pkt_con_if_{node_id}.si_qos = pkt_con_if_{south_neighbor}.no_qos;",
                f"assign pkt_con_if_{node_id}.si_type = pkt_con_if_{south_neighbor}.no_type;",
                f"assign pkt_con_if_{node_id}.si_src = pkt_con_if_{south_neighbor}.no_src;",
                f"assign pkt_con_if_{node_id}.si_tgt = pkt_con_if_{south_neighbor}.no_tgt;",
                f"assign pkt_con_if_{node_id}.si_data = pkt_con_if_{south_neighbor}.no_data;",
                f"assign pkt_con_if_{south_neighbor}.no_rdy = pkt_con_if_{node_id}.si_rdy;"
            ])
        else:
            print(f"// South boundary - tie to 0")
            connections.extend([
                f"assign pkt_con_if_{node_id}.si_vld = 1'b0;",
                f"assign pkt_con_if_{node_id}.si_qos = 1'b0;",
                f"assign pkt_con_if_{node_id}.si_type = 2'b00;",
                f"assign pkt_con_if_{node_id}.si_src = 6'b000000;",
                f"assign pkt_con_if_{node_id}.si_tgt = 6'b000000;",
                f"assign pkt_con_if_{node_id}.si_data = 8'b00000000;",
                f"assign pkt_con_if_{node_id}.so_rdy = 1'b0;  // South boundary"
            ])

        # 西方输入：来自左侧节点的东方输出
        west_neighbor = get_neighbor_node(node_id, "west")
        if west_neighbor is not None:
            print(f"// West connection from Node {west_neighbor}")
            connections.extend([
                f"assign pkt_con_if_{node_id}.wi_vld = pkt_con_if_{west_neighbor}.eo_vld;",
                f"assign pkt_con_if_{node_id}.wi_qos = pkt_con_if_{west_neighbor}.eo_qos;",
                f"assign pkt_con_if_{node_id}.wi_type = pkt_con_if_{west_neighbor}.eo_type;",
                f"assign pkt_con_if_{node_id}.wi_src = pkt_con_if_{west_neighbor}.eo_src;",
                f"assign pkt_con_if_{node_id}.wi_tgt = pkt_con_if_{west_neighbor}.eo_tgt;",
                f"assign pkt_con_if_{node_id}.wi_data = pkt_con_if_{west_neighbor}.eo_data;",
                f"assign pkt_con_if_{west_neighbor}.eo_rdy = pkt_con_if_{node_id}.wi_rdy;"
            ])
        else:
            print(f"// West boundary - tie to 0")
            connections.extend([
                f"assign pkt_con_if_{node_id}.wi_vld = 1'b0;",
                f"assign pkt_con_if_{node_id}.wi_qos = 1'b0;",
                f"assign pkt_con_if_{node_id}.wi_type = 2'b00;",
                f"assign pkt_con_if_{node_id}.wi_src = 6'b000000;",
                f"assign pkt_con_if_{node_id}.wi_tgt = 6'b000000;",
                f"assign pkt_con_if_{node_id}.wi_data = 8'b00000000;",
                f"assign pkt_con_if_{node_id}.wo_rdy = 1'b0;  // West boundary"
            ])

        # 东方输入：来自右侧节点的西方输出
        east_neighbor = get_neighbor_node(node_id, "east")
        if east_neighbor is not None:
            print(f"// East connection from Node {east_neighbor}")
            connections.extend([
                f"assign pkt_con_if_{node_id}.ei_vld = pkt_con_if_{east_neighbor}.wo_vld;",
                f"assign pkt_con_if_{node_id}.ei_qos = pkt_con_if_{east_neighbor}.wo_qos;",
                f"assign pkt_con_if_{node_id}.ei_type = pkt_con_if_{east_neighbor}.wo_type;",
                f"assign pkt_con_if_{node_id}.ei_src = pkt_con_if_{east_neighbor}.wo_src;",
                f"assign pkt_con_if_{node_id}.ei_tgt = pkt_con_if_{east_neighbor}.wo_tgt;",
                f"assign pkt_con_if_{node_id}.ei_data = pkt_con_if_{east_neighbor}.wo_data;",
                f"assign pkt_con_if_{east_neighbor}.wo_rdy = pkt_con_if_{node_id}.ei_rdy;"
            ])
        else:
            print(f"// East boundary - tie to 0")
            connections.extend([
                f"assign pkt_con_if_{node_id}.ei_vld = 1'b0;",
                f"assign pkt_con_if_{node_id}.ei_qos = 1'b0;",
                f"assign pkt_con_if_{node_id}.ei_type = 2'b00;",
                f"assign pkt_con_if_{node_id}.ei_src = 6'b000000;",
                f"assign pkt_con_if_{node_id}.ei_tgt = 6'b000000;",
                f"assign pkt_con_if_{node_id}.ei_data = 8'b00000000;",
                f"assign pkt_con_if_{node_id}.eo_rdy = 1'b0;  // East boundary"
            ])

    return connections

def main():
    """主函数：生成完整的拓扑连接代码"""
    print("// ====================================================================")
    print("// MAZE 8x8 Mesh Topology Auto-Generated Connections")
    print("// ====================================================================")
    print("// Grid Size:", GRID_SIZE, "x", GRID_SIZE)
    print("// Total Nodes:", TOTAL_NODES)
    print("// Coordinate System: [y,x] where (0,0) is bottom-left corner")
    print("// Connection Rules:")
    print("//   - North input (ni) comes from neighbor's South output (so)")
    print("//   - South input (si) comes from neighbor's North output (no)")
    print("//   - West input (wi) comes from neighbor's East output (eo)")
    print("//   - East input (ei) comes from neighbor's West output (wo)")
    print("//   - Boundary inputs tie to 0, boundary output ready signals tie to 0")
    print("// ====================================================================")

    # 生成所有连接（包括边界ready信号）
    connections = generate_connections()

    print("\n// ====================================================================")
    print("// All Node Input Connections and Boundary Output Ready Signals")
    print("// ====================================================================")
    for conn in connections:
        print(conn)

    print(f"\n// Total connections generated: {len(connections)}")

if __name__ == "__main__":
    main()