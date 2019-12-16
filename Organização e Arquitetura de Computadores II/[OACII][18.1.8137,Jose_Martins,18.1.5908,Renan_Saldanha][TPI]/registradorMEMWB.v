module registradorMEMWB(clock, aluOutIn, memOutIn, regWriteIn, memToRegIn, regDestIn, aluOut, memOut, regWrite, memToReg, regDest);

    input wire clock;
    input wire [31:0] aluOutIn;
    input wire [31:0] memOutIn;
    input wire regWriteIn;
    input wire memToRegIn;
    input wire [4:0] regDestIn;

    output reg [31:0] aluOut;
    output reg [31:0] memOut;
    output reg regWrite;
    output reg memToReg;
    output reg [4:0] regDest;

    always @ (posedge clock)
    begin: REGISTRADORMEMEB
        regDest = regDestIn;
        regWrite = regWriteIn;
        aluOut = aluOutIn;
        memOut = memOutIn;
        memToReg = memToRegIn;
    end
endmodule