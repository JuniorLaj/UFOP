module registradorEXMEM(clock, ctrlDesvio, pcDesvioIn, pcJumpIn, aluOutIn, reg2In, zeroIn, regWriteIn, branchIn, jumpIn, memReadIn, memWriteIn, memToRegIn, regDestIn, pcDesvioOut, pcJump, aluOut, reg2, zero, regWrite, branch, jump, memRead, memWrite, memToReg, regDest);

    input wire clock;
    input wire [31:0] pcDesvioIn;
    input wire [31:0] pcJumpIn;
    input wire [31:0] aluOutIn;
    input wire [31:0] reg2In;
    input wire zeroIn;
    input wire regWriteIn;
    input wire branchIn;
    input wire jumpIn;
    input wire memReadIn;
    input wire memWriteIn;
    input wire memToRegIn;
    input wire ctrlDesvio;
    input wire [4:0] regDestIn;

    output reg [31:0] pcDesvioOut;
    output reg [31:0] pcJump;
    output reg [31:0] aluOut;
    output reg [31:0] reg2;
    output reg zero;
    output reg regWrite;
    output reg branch;
    output reg jump;
    output reg memToReg;
    output reg memRead;
    output reg memWrite;
    output reg [4:0] regDest;

    always @ (posedge clock)
    begin: REGISTRADOREXMEM
        if(ctrlDesvio == 0)begin
            regDest <= regDestIn;
            regWrite <= regWriteIn;
            aluOut = aluOutIn;
            reg2 <= reg2In;
            zero <= zeroIn;
            branch <= branchIn;
            jump <= jumpIn;
            memRead <= memReadIn;
            memWrite <= memWriteIn;
            memToReg <= memToRegIn;
            pcDesvioOut <= pcDesvioIn;
            pcJump <= pcJumpIn;
        end else begin
            aluOut <= 0;
            reg2 <= 0;
            zero <= 0;
            regWrite <= 0;
            branch <= 0;
            jump <= 0;
            memRead <= 0;
            memWrite <= 0;
            regDest <= 0;
            memToReg <= 0;
            pcDesvioOut <= 0;
            pcJump <= 0;
        end
    end
endmodule