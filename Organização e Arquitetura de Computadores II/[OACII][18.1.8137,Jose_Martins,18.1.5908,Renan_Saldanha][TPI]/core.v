`include "pc.v"
`include "memoryInstruc.v"
`include "registradorIFID.v"
`include "addPc4.v"
`include "unidadeDeControle.v"
`include "bancoRegistradores.v"
`include "extensorSinal.v"
`include "registradorIDEX.v"
`include "unidadeDeteccaoHarzard.v"
`include "mux32.v"
`include "mux5.v"
`include "mux3in32.v"
`include "Forwarding.v"
`include "alu.v"
`include "addDesvioCondicional.v"
`include "registradorEXMEM.v"
`include "memoriaDados.v"
`include "branch.v"
`include "registradorMEMWB.v"
`include "Or.v"
`include "jump.v"
`include "byPass.v"

module core(clock);

    input wire clock;
    //PC
    wire [31:0]saidaPC;
    //PC4
    wire [31:0]saidaPC4;
    //Memoria de instruções
    wire [31:0]instructionMI;
    //Registrador IF/ID
    wire [5:0]opIFID;
    wire [5:0]functIFID;
    wire [4:0]rsIFID;
    wire [4:0]rtIFID;
    wire [25:0]instructionIFID;
    wire [4:0]rdIFID;
    wire [4:0]shamtIFID;
    wire [15:0]addressIFID;
    wire [31:0]pcIFID;
    //Unidade de Controle
    wire regWritectrl;
    wire aluScrctrl;
    wire branchctrl;
    wire memReadctrl;
    wire memWritectrl;
    wire regDestctrl;
    wire memToRegctrl;
    wire jumpctrl;
    wire [1:0]aluOPctrl;
    //Extensor de sinal
    wire [31:0]addressExtend;
    //Banco de Registradore
    wire [31:0]readData1BR;
    wire [31:0]readData2BR;
    //Registrador ID/EX
    wire aluScrIDEX;
    wire regDestIDEX;
    wire branchIDEX;
    wire jumpIDEX;
    wire memReadIDEX;
    wire memWriteIDEX;
    wire memToRegIDEX;
    wire regWriteIDEX;
    wire [1:0]aluOPIDEX;
    wire [31:0]pcIDEX;
    wire [31:0]reg1IDEX;
    wire [31:0]reg2IDEX;
    wire [31:0]extendSignalIDEX;
    wire [25:0]instructionIDEX;
    wire [4:0]rsIDEX;
    wire [4:0]rtIDEX;
    wire [4:0]rdIDEX;
    wire [5:0]functIDEX;
    //Unidade Controle de Hazard
    wire ctrlDH;
    //Multiplexador que define o registrador de destino
    wire [4:0]regDest;
    //Saídas registradores de forwarding
    wire [31:0]aluIn1;
    wire [31:0]muxReg2Out;
    //Saídas do Forwarding
    wire [1:0]ctrlForwA;
    wire [1:0]ctrlForwB;
    //Saídas ALU
    wire zero;
    wire [31:0]aluOut;
    //Saída do multiplexador que define se alu recebe endereço ou dado de registrador 2
    wire [31:0]aluIn2;
    //Saída do somador de desvio condicional
    wire [31:0]endDesvioCondicional;
    //Registrador EX/MEM
    wire [31:0]pcDesvioOutEXMEM;
    wire [31:0]aluOutEXMEM;
    wire [31:0]reg2EXMEM;
    wire zeroEXMEM;
    wire regWriteEXMEM;
    wire branchEXMEM;
    wire jumpEXMEM;
    wire memReadEXMEM;
    wire memWriteEXMEM;
    wire memToRegEXMEM;
    wire [31:0]jumpAddressEXMEM;
    wire [4:0]regDestEXMEM;
    //Saída memoria de dados
    wire[31:0]dataMemoryOut;
    //Saída da porta AND que define se vai ter ou não branch
    wire branchOut;
    //Saída mux que define se o endereço é o branch ou pc4
    wire [31:0]muxBranchOut;
    //Registrador MEM/WB
    wire [31:0]aluOutMEMWB;
    wire [31:0]memMEMWB;
    wire regWriteMEMWB;
    wire memToRegMEMWB;
    wire [4:0]regDestMEMWB;
    wire [31:0]writeReg;
    //Saída de porta OR que zera o pipe em caso de desvios
    wire ctrlDesvio;
    //Saída do somador de pc atual mais endereço de jump
    wire [31:0]jumpAddress;
    //Saída do mux que define se o próximo pc é o que vem do mux de branch ou o endereço de uma instrução jump
    wire [31:0]muxJumpOut;
    wire [31:0]forw;
    wire [31:0]byPassing;

    pc pci(.clock(clock), .entrada(muxJumpOut), .saida(saidaPC));
    
    addPc4 pc4(.clock(clock), .ctrl(ctrlDH), .pc(saidaPC), .pc4(saidaPC4));
    
    memoryInstruc mem (.clock(clock), .address(saidaPC), .instruc(instructionMI));
    
    registradorIFID regIFID(.clock(clock), .dado(instructionMI), .ctrl(ctrlDH), .ctrlDesvio(ctrlDesvio), .pc4(saidaPC4), .op(opIFID), .funct(functIFID), .rs(rsIFID), .rt(rtIFID), .rd(rdIFID), .shamt(shamtIFID), .adress(addressIFID), .pc(pcIFID), .instruction(instructionIFID));
    
    unidadeDeControle uc (.clock(clock), .op(opIFID), .regWrite(regWritectrl), .aluScr(aluScrctrl), .branch(branchctrl), .memRead(memReadctrl), .memWrite(memWritectrl), .regDest(regDestctrl), .memToReg(memToRegctrl), .jump(jumpctrl), .aluOP(aluOPctrl));
    
    extensorSinal ex(.clock(clock), .address(addressIFID), .addressExtend(addressExtend));
    
    bancoRegistradores br(.clock(clock), .readRegister1(rsIFID), .readRegister2(rtIFID), .writeRegister(regDestMEMWB), .writeData(writeReg), .regWrite(regWriteMEMWB), .readData1(readData1BR), .readData2(readData2BR));

    registradorIDEX regIDEX(.clock(clock), .ctrl(ctrlDH), .ctrlDesvio(ctrlDesvio), .pcIn(pcIFID), .reg1In(readData1BR), .reg2In(readData2BR), .extendSignalIn(addressExtend), .rsIn(rsIFID), .rtIn(rtIFID), .rdIn(rdIFID), .aluScrIn(aluScrctrl), .aluOPIn(aluOPctrl), .regDestIn(regDestctrl), .branchIn(branchctrl), .jumpIn(jumpctrl), .memReadIn(memReadctrl), .memWriteIn(memWritectrl), .memToRegIn(memToRegctrl), .regWriteIn(regWritectrl), .functIn(functIFID), .instructionIn(instructionIFID), .pc(pcIDEX), .reg1(reg1IDEX), .reg2(reg2IDEX), .extendSignal(extendSignalIDEX), .rs(rsIDEX), .rt(rtIDEX), .rd(rdIDEX), .aluScr(aluScrIDEX), .aluOP(aluOPIDEX), .regDest(regDestIDEX), .branch(branchIDEX), .jump(jumpIDEX), .memRead(memReadIDEX), .memWrite(memWriteIDEX), .memToReg(memToRegIDEX), .regWrite(regWriteIDEX), .funct(functIDEX), .instruction(instructionIDEX));

    unidadeDeteccaoHarzard DH(.clock(clock), .opCode(opIFID), .rtIFID(rtIFID), .rtIDEX(rtIDEX), .rsIFID(rsIFID), .memRead(memReadIDEX), .ctrl(ctrlDH));

    mux5 muxRegDest(.controle(regDestIDEX), .entrada0(rdIDEX), .entrada1(rtIDEX), .saida(regDest));

    mux32 muxEndReg(.controle(aluScrIDEX), .entrada0(muxReg2Out), .entrada1(extendSignalIDEX), .saida(aluIn2));

    mux3In muxReg1(.ctrl(ctrlForwA), .entrada0(reg1IDEX), .entrada1(writeReg), .entrada2(aluOutEXMEM), .saida(aluIn1));

    mux3In muxReg2(.ctrl(ctrlForwB), .entrada0(reg2IDEX), .entrada1(writeReg), .entrada2(aluOutEXMEM), .saida(muxReg2Out));

    Forwarding uForwarding(.clock(clock), .regWriteEXMEM(regWriteEXMEM), .regWriteMEMWB(regWriteMEMWB), .rdMEMWB(regDestMEMWB), .rdEXMEM(regDestEXMEM), .rsIDEX(rsIDEX), .rtIDEX(rtIDEX), .forwardingA(ctrlForwA), .forwardingB(ctrlForwB));

    alu alu(.clock(clock), .aluOp(aluOPIDEX), .funct(functIDEX), .entrada0(aluIn1), .entrada1(aluIn2), .zero(zero), .saida(aluOut));

    addDesvioCondicional pcDes(.clock(clock), .entrada0(pcIDEX), .sl2(extendSignalIDEX), .saida(endDesvioCondicional));

    registradorEXMEM regEXMEM(.clock(clock), .ctrlDesvio(ctrlDesvio), .pcDesvioIn(endDesvioCondicional), .pcJumpIn(jumpAddress), .aluOutIn(aluOut), .reg2In(muxReg2Out), .zeroIn(zero), .regWriteIn(regWriteIDEX), .branchIn(branchIDEX), .jumpIn(jumpIDEX), .memReadIn(memReadIDEX), .memWriteIn(memWriteIDEX), .memToRegIn(memToRegIDEX), .regDestIn(regDest), .pcDesvioOut(pcDesvioOutEXMEM), .pcJump(jumpAddressEXMEM), .aluOut(aluOutEXMEM), .reg2(reg2EXMEM), .zero(zeroEXMEM), .regWrite(regWriteEXMEM), .branch(branchEXMEM), .jump(jumpEXMEM), .memRead(memReadEXMEM), .memWrite(memWriteEXMEM), .memToReg(memToRegEXMEM), .regDest(regDestEXMEM));

    memoriaDados md (.clock(clock), .memWrite(memWriteEXMEM), .memRead(memReadEXMEM), .address(aluOutEXMEM), .writeData(reg2EXMEM), .readData(dataMemoryOut));

    branch branch(.branch(branchEXMEM), .zero(zeroEXMEM), .out(branchOut));

    mux32 muxBranch(.controle(branchOut), .entrada0(saidaPC4), .entrada1(pcDesvioOutEXMEM), .saida(muxBranchOut));

    mux32 muxJump(.controle(jumpEXMEM), .entrada0(muxBranchOut), .entrada1(jumpAddressEXMEM), .saida(muxJumpOut));

    registradorMEMWB MEMWB(.clock(clock), .aluOutIn(byPassing), .memOutIn(dataMemoryOut), .regWriteIn(regWriteEXMEM), .memToRegIn(memToRegEXMEM), .regDestIn(regDestEXMEM), .aluOut(aluOutMEMWB), .memOut(memMEMWB), .regWrite(regWriteMEMWB), .memToReg(memToRegMEMWB), .regDest(regDestMEMWB));

    mux32 muxwb(.controle(memToRegMEMWB), .entrada0(aluOutMEMWB), .entrada1(memMEMWB), .saida(writeReg));
    
    Or branchJump(.clock(clock), .branch(branchOut), .jump(jumpEXMEM), .control(ctrlDesvio));

    jump jump(.clock(clock), .instruction(instructionIDEX), .pc4(pcIDEX), .jumpAddress(jumpAddress));

    bypass bypass(.clock(clock), .entrada(aluOutEXMEM), .saida(byPassing));

endmodule