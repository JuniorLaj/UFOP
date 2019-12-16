module bypass(clock, entrada, saida);

    input wire clock;
    input wire [31:0] entrada;

    output reg [31:0] saida;

    always @ (posedge clock)
    begin: MUX3IN
        saida = entrada;
    end
endmodule