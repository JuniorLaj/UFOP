module registradorIDEX(clock, ctrl, ctrlDesvio, pcIn, reg1In, reg2In, extendSignalIn, rsIn, rtIn, rdIn, aluScrIn, aluOPIn, regDestIn, branchIn, jumpIn, memReadIn, memWriteIn, memToRegIn, regWriteIn, functIn, instructionIn, pc, reg1, reg2, extendSignal, rs, rt, rd, aluScr, aluOP, regDest, branch, jump, memRead, memWrite, memToReg, regWrite, funct, instruction);

    input wire clock;
    input wire ctrl;
    input wire ctrlDesvio;
    //Dados entrada com 32 bits
    input wire [31:0] pcIn;
    input wire [31:0] reg1In;
    input wire [31:0] reg2In;
    input wire [31:0] extendSignalIn;
    //Dados com 6 bits
    input wire [5:0]functIn;
    //Dados entrada com 5 bits
    input wire [4:0] rtIn;
    input wire [4:0] rsIn;
    input wire [4:0] rdIn;
    //Dados entrada com 1 bit
    input wire aluScrIn;
    input wire regDestIn;
    input wire branchIn;
    input wire jumpIn;
    input wire memReadIn;
    input wire memWriteIn;
    input wire memToRegIn;
    input wire regWriteIn;
    //Dados entrada com 2 bits
    input wire[1:0] aluOPIn;
    //Dados entrada com 26 bits
    input wire [25:0]instructionIn;

    //Dados saída com 1 bit
    output reg aluScr;
    output reg regDest;
    output reg branch;
    output reg jump;
    output reg memRead;
    output reg memWrite;
    output reg memToReg;
    output reg regWrite;
    //Dados saída com 32 bits
    output reg [31:0] pc;
    output reg [31:0] reg1;
    output reg [31:0] reg2;
    output reg [31:0] extendSignal;
    //Dados saída com 5 bits
    output reg [4:0] rt;
    output reg [4:0] rs; 
    output reg [4:0]rd;
    //Dados saída com 2 bits
    output reg [1:0]aluOP;
    //Dados saída com 6 bits
    output reg [5:0]funct;
    //Dado saída com 26 bits
    output reg [25:0]instruction;

    always @ (posedge clock)
    begin: registradorIDEX
        if((ctrl == 0) && (ctrlDesvio == 0))begin
            rt <= rtIn;
            rd <= rdIn;
            rs <= rsIn;
            aluScr <= aluScrIn;
            aluOP <= aluOPIn;
            regDest <= regDestIn;
            branch <= branchIn;
            jump <= jumpIn;
            memRead <= memReadIn;
            memWrite <= memWriteIn;
            memToReg <= memToRegIn;
            regWrite <= regWriteIn;
            pc <= pcIn;
            reg1 <= reg1In;
            reg2 <= reg2In;
            extendSignal <= extendSignalIn;
            funct <= functIn;
            instruction <= instructionIn;
        end else begin
            aluScr = 0;
            aluOP = 2'bxx;
            regDest = 0;
            branch = 0;
            jump = 0;
            memRead = 0;
            memWrite = 0;
            memToReg = 0;
            regWrite = 0;
            pc = 0;
            reg1 = 0;
            reg2 = 0;
            extendSignal = 0;
            rt = 0;
            rs = 0;
            rd = 0;
            funct = 0;
            instruction = 0;
        end            
    end
endmodule