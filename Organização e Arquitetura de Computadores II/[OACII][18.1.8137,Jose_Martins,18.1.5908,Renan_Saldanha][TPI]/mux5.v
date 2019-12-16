module mux5(controle, entrada0, entrada1,saida);

    input wire controle;
    input wire[4:0]entrada0,entrada1;
    
    output reg [4:0] saida;

    always @(*)
        begin: MUX5
            if(controle==0) begin
                saida = entrada1;
            end else begin
                saida = entrada0;
            end
        end
endmodule