module mux32(controle, entrada0, entrada1, saida);
   
    input wire controle;
    input wire[31:0]entrada0; 
    input wire[31:0]entrada1;
   
    output reg [31:0] saida;

    always @(*)
    begin: MUX32
        if(controle==1) begin
        saida = entrada1;
        end else begin
        saida = entrada0;
        end
    end
endmodule