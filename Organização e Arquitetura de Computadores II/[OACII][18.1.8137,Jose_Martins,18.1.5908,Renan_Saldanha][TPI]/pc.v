module pc(clock, entrada, saida);

input wire clock;
input wire [31:0]entrada;
input wire ctrl;

output reg [31:0]saida = 0;


always @(posedge clock)
    begin: PC
        saida = entrada;
    end
    
endmodule