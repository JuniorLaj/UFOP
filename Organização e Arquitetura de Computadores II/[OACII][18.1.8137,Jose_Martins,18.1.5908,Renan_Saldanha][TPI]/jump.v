module jump(clock, instruction, pc4, jumpAddress);
    
    input wire clock;
    input wire[25:0] instruction;
    input wire [31:0] pc4;
    
    output reg [31:0] jumpAddress;
    
    reg [27:0] aux;
    
    always @(negedge clock)
    begin
        aux = instruction << 2;
        //$display("\n\n%b", aux);
        jumpAddress = aux + pc4[31:28];
    end    
endmodule