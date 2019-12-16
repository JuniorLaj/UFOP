module addDesvioCondicional(clock, entrada0, sl2, saida);

    input wire clock;
    input wire[31:0] entrada0;
    input wire[31:0] sl2;
    
    output reg [31:0] saida;

    always @ (negedge clock)
    begin: SOMA
        saida = entrada0 + (sl2 << 2);
    end
endmodule
