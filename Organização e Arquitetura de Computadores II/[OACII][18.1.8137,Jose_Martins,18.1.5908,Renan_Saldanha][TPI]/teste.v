`include "core.v"

module teste();

    reg clock;

    initial begin
        //$monitor(regDestMEMWB);
        //$monitor("clock = %b\nIF\nMUX branch: muxBranchOut =%b\nPC: saindaPC = %b\nPC+4: saidaPC4 = %b\nMemoria de Instrução: instructionMI = %b\nID\nRegistrador IFID opIFID = %b, functIFID = %b, rsIFID = %b, rtIFID = %b, rdIFID = %b, shamtIFID = %b, addressIFID = %b, pcIFID = %b, instructionIFID = %b\nUNidade de Controle: regWritectrl = %b, aluScrctrl = %b, branchctrl = %b, memReadctrl = %b, memWritectrl = %b,regDestctrl = %b, memToRegctrl = %b, jumpctrl = %b, aluOPctrl = %b\nBanco de registradores: readData1BR = %b, readData2BR = %b\nEX\nRegistrador IDEX aluScrIDEX = %b, aluOPIDEX = %b, regDestIDEX = %b, branchIDEX = %b, jumpIDEX = %b, memReadIDEX = %b, memWriteIDEX = %b, memToRegIDEX = %b, regWriteIDEX = %b, pcIDEX = %b, reg1IDEX = %b, reg2IDEX = %b, extendSignalIDEX = %b, rtIDEX = %b, rdIDEX = %b, instructionIDEX = %b\n Unidade Harzard: ctrlDH = %b\nMUXREGDEST: regDest = %b\nMUXREG1: muxreg1 = %b\nMUXREG2: muxreg2 = %b\n Forwarding: ctrlForwA = %b, ctrlForwB = %b\nAlu: zero = %b, aluOUT = %b\nMuxENDREG: aluIn2 = %b\njumpAddress = %b\nSomador endDesvioCondicional: endDesvioCondicional = %b, ctrlDesvio = %b\n"/*MEM\nREGISTRADOR EXMEM: pcDesvioOutEXMEM =%b, aluOutEXMEM= %b, reg2EXMEM = %b, zeroEXMEM = %b, regWriteEXMEM = %b, branchEXMEM = %b, jumpEXMEM = %b, memReadEXMEM = %b, memWriteEXMEM = %b, memToRegEXMEM = %b, regDestEXMEM = %b\nMEMORIA: dataMemoryOut = %b\nBRANCH: branchOut = %b\nWB\nALU: aluOutMEMWB = %b\nmemMEMWB = %b\nregWriteMEMWB = %b, memToRegMEMWB = %b, regDestMEMWB = %b\nMUXDADOREG: writeReg = %b\n"*/, clock, muxBranchOut, saidaPC, saidaPC4, instructionMI, opIFID, functIFID, rsIFID, rtIFID, rdIFID, shamtIFID, addressIFID, pcIFID, instructionIFID, regWritectrl, aluScrctrl, branchctrl, memReadctrl, memWritectrl, regDestctrl, memToRegctrl, jumpctrl, aluOPctrl, readData1BR, readData2BR, aluScrIDEX, aluOPIDEX, regDestIDEX, branchIDEX, jumpIDEX, memReadIDEX, memWriteIDEX, memToRegIDEX, regWriteIDEX, pcIDEX, reg1IDEX, reg2IDEX, extendSignalIDEX, rtIDEX, rdIDEX, instructionIDEX, ctrlDH, regDest, aluIn1, muxReg2Out, ctrlForwA, ctrlForwB, zero, aluOut, aluIn2, jumpAddress, endDesvioCondicional, ctrlDesvio, /*pcDesvioOutEXMEM, aluOutEXMEM, reg2EXMEM, zeroEXMEM, regWriteEXMEM, branchEXMEM, jumpEXMEM, memReadEXMEM, memWriteEXMEM, memToRegEXMEM, regDestEXMEM, dataMemoryOut, branchOut, aluOutMEMWB, memMEMWB, regWriteMEMWB, memToRegMEMWB, regDestMEMWB, writeReg*/);
        clock = 0;
        #200 clock = 0;
        $finish;
    end

    always begin
    #5 clock = ~clock;
    end

    core core(.clock(clock));
endmodule
    