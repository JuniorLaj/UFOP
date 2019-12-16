module mux3In(ctrl, entrada0, entrada1, entrada2, saida);

    input wire [1:0]ctrl;
    input wire [31:0] entrada0;
    input wire [31:0] entrada1;
    input wire [31:0] entrada2;

    output reg [31:0] saida;

    always @ (*)
    begin: MUX3IN
        if(ctrl == 0)begin
            saida = entrada0;
        end else if(ctrl == 1)begin
            saida = entrada1;
        end else if(ctrl == 2)begin
            saida = entrada2;
        end else begin
            saida = 0;
        end
    end
endmodule
