module registradorIFID(clock, dado, ctrl, ctrlDesvio, pc4, op, funct, rs, rt, rd, shamt, adress, pc, instruction);

    input wire clock;
    input wire [31:0]dado;
    input wire [31:0]pc4;
    input wire ctrl;
    input wire ctrlDesvio;
    
    output reg [5:0]op; 
    output reg [5:0]funct;
    output reg [4:0]rs;
    output reg [4:0]rt; 
    output reg [4:0]rd; 
    output reg [4:0]shamt;
    output reg [15:0]adress;
    output reg [31:0] pc;
    output reg [25:0] instruction;

    always @(posedge clock)
    begin:REGISTERIFID
        if ((ctrl == 0) && (ctrlDesvio == 0)) begin
            op <= dado[31:26];
            rs <= dado[25:21];
            rt <= dado[20:16];
            rd <= dado[15:11];
            shamt <= dado[10:6];
            adress <= dado[15:0];
            pc <= pc4;
            instruction <= dado[25:0];
            case(dado[31:26])
                6'b000101: begin
                    funct <= 6'b000101;
                end
                6'b001010: begin
                    funct <= 6'b001010;
                end
                6'b001000: begin
                    funct <= 6'b001000;
                end
                default: begin
                    funct <= dado[5:0];
                end
            endcase
        end else begin
            op = 0;
            rs = 0;
            rt = 0;
            rd = 0;
            shamt = 0;
            funct = 0;
            adress = 0;
            pc = 0;
            instruction = 0;
        end
    end
endmodule