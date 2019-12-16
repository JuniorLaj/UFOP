module alu(clock, aluOp, funct, entrada0, entrada1, zero, saida);
    
    input wire clock;
    input wire[5:0]funct;
    input wire[1:0]aluOp;
    input wire[31:0]entrada0,entrada1;
    
    output reg zero;
    output reg[31:0]saida;

    always @(negedge clock)
        begin: OPERATION
            case (aluOp)
                2'b00:begin
                    saida = entrada0 + entrada1;
                    zero = 0;
                end
                2'b01: begin
                    saida = entrada0 - entrada1;
                    if(saida==0) begin
                        zero = 1;
                    end else if(saida!=0) begin
                        zero = 0;
                    end
                end
                2'b10:begin
                    if(funct==6'b100000) begin
                        saida = entrada0 + entrada1;
                        zero = 0;
                    end else if(funct==6'b100010) begin
                        saida = entrada0 - entrada1;
                        zero = 0;
                    end else if(funct==6'b100100) begin
                        saida = entrada0 & entrada1;
                        zero = 0;
                    end else if(funct==6'b100101) begin
                        saida = entrada0 | entrada1;
                        zero = 0;
                    end else if(funct==6'b101010) begin
                        saida = entrada0-entrada1;
                        if(saida < 0) begin 
                            saida = 1;
                            zero = 0;
                        end else if(saida > 0) begin
                            saida = 0;
                            zero = 0;
                        end
                    end
                end
                2'b11:begin
                    if(funct == 6'b000101) begin
                        if(entrada0 != entrada1) begin
                            zero = 1;
                        end else begin
                            zero = 0;
                        end
                    end else if(funct == 6'b001010) begin
                        if(entrada0 < entrada1) begin
                            saida = 1;
                            zero = 0;
                        end else begin
                            saida = 0;
                            zero = 0;
                        end
                    end else if(funct == 6'b001000) begin
                        saida = entrada0 + entrada1;
                        zero = 0;
                    end
                end
                default: begin
                        saida = 0;
                        zero = 0;
                    end
            endcase
        end
endmodule
        
