module unidadeDeControle(clock, op, regWrite, aluScr, branch, memRead, memWrite, regDest, memToReg, jump, aluOP);

    input wire [5:0]op;
    input wire clock;

    output reg regWrite;
    output reg aluScr;
    output reg branch;
    output reg memRead;
    output reg memWrite;
    output reg regDest;
    output reg memToReg;
    output reg jump;
    output reg [1:0]aluOP;

    always @ (negedge clock)
    begin: CONTROLUNIT
        if(op == 6'b000000) //Instruções do tipo R (add, and, or, slt)
        begin
            regDest <= 1;
            aluScr <= 0;
            memToReg <= 0;
            regWrite <= 1;
            memRead <=0;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 2'b10;
            jump <= 0;
        end else if(op == 6'b001000) //Instrução addi
        begin
            regDest <= 0;
            aluScr <= 1;
            memToReg <= 0;
            regWrite <= 1;
            memRead <=0;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 2'b11;
            jump <= 0;
        end else if(op == 6'b000100) //Instrução beq
        begin
            regDest <= 1'bx;
            aluScr <= 0;
            memToReg <= 1'bx;
            regWrite <= 0;
            memRead <= 0;
            memWrite <= 0;
            branch <= 1;
            aluOP <= 2'b01;
            jump <= 0;
        end else if(op == 6'b000101) //Instruçao bne
        begin
            regDest <= 1'bx;
            aluScr <= 0;
            memToReg <= 1'bx;
            regWrite <= 0;
            memRead <= 0;
            memWrite <= 0;
            branch <= 1;
            aluOP <= 2'b11;
            jump <= 0;
        end else if(op == 6'b100011) //Instrução lw
        begin
            regDest <= 0;
            aluScr <= 1;
            memToReg <= 1;
            regWrite <= 1;
            memRead <= 1;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 2'b00;
            jump <= 0;
        end else if(op == 6'b101011) //Instrução sw
        begin
            regDest <= 1'bx;
            aluScr <= 1;
            memToReg <= 1'bx;
            regWrite <= 0;
            memRead <= 0;
            memWrite <= 1;
            branch <= 0;
            aluOP <= 2'b00;
            jump <= 0;
        end else if(op == 6'b001010) //Instruções slti
        begin
            regDest <= 1'b0;
            aluScr <= 1;
            memToReg <= 1'b0;
            regWrite <= 1;
            memRead <=0;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 2'b11;
            jump <= 0;
        end else if(op == 6'b000010) //Instrução jump
        begin
            regDest <= 0;
            aluScr <= 0;
            memToReg <= 0;
            regWrite <= 0;
            memRead <= 0;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 2'b00;
            jump <= 1;
        end else begin
            regDest <= 0;
            aluScr <= 0;
            memToReg <= 0;
            regWrite <= 0;
            memRead <= 0;
            memWrite <= 0;
            branch <= 0;
            aluOP <= 0;
            jump <= 0;
        end
    end
endmodule