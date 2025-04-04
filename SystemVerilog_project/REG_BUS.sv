interface REG_BUS #(
  /// The width of the address.
  parameter int ADDR_WIDTH = 2,
  /// The width of the data.
  parameter int DATA_WIDTH = 32
)(
  input logic clk_i
);

  logic [ADDR_WIDTH-1:0]   addr;
  logic                    write; // 0=read, 1=write
  logic [DATA_WIDTH-1:0]   rdata;
  logic [DATA_WIDTH-1:0]   wdata;
  logic [DATA_WIDTH/8-1:0] wstrb; // byte-wise strobe
  logic                    error; // 0=ok, 1=error
  logic                    valid;
  logic                    ready;

  modport in  (input  addr, write, wdata, wstrb, valid, output rdata, error, ready);
  modport out (output addr, write, wdata, wstrb, valid, input  rdata, error, ready);

endinterface