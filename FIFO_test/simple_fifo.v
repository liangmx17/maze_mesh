// Simple synchronous FIFO with parameterizable depth
module simple_fifo #(
    parameter DATA_WIDTH = 8,
    parameter ADDR_WIDTH = 4  // Depth = 2^ADDR_WIDTH = 16
) (
    input  logic                  clk,
    input  logic                  rst_n,

    // Write interface
    input  logic                  wr_en,
    input  logic [DATA_WIDTH-1:0] wr_data,
    output logic                  full,

    // Read interface
    input  logic                  rd_en,
    output logic [DATA_WIDTH-1:0] rd_data,
    output logic                  empty,

    // Status
    output logic [ADDR_WIDTH:0]   count
);

    localparam DEPTH = 1 << ADDR_WIDTH;

    // Internal memory and pointers
    logic [DATA_WIDTH-1:0]        mem [DEPTH-1:0];
    logic [ADDR_WIDTH:0]          wr_ptr, rd_ptr;  // Extra bit for overflow detection

    // Full/empty status
    assign full  = ((wr_ptr[ADDR_WIDTH] != rd_ptr[ADDR_WIDTH]) &&
                    (wr_ptr[ADDR_WIDTH-1:0] == rd_ptr[ADDR_WIDTH-1:0]));
    assign empty = (wr_ptr == rd_ptr);
    assign count = wr_ptr - rd_ptr;

    // Sequential logic for pointer updates and memory operations
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= '0;
            rd_ptr <= '0;
        end else begin
            // Write operation
            if (wr_en && !full) begin
                mem[wr_ptr[ADDR_WIDTH-1:0]] <= wr_data;
                wr_ptr <= wr_ptr + 1'b1;
            end

            // Read operation
            if (rd_en && !empty) begin
                rd_ptr <= rd_ptr + 1'b1;
            end
        end
    end

    // Read data output (registered)
    logic [DATA_WIDTH-1:0] rd_data_reg;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_data_reg <= '0;
        end else if (rd_en && !empty) begin
            rd_data_reg <= mem[rd_ptr[ADDR_WIDTH-1:0]];
        end
    end
    assign rd_data = rd_data_reg;

endmodule
