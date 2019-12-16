import sys
import os
import funcoes

file = open(sys.argv[1])
fileSaida = open("arquivoSaida.txt","w")
while(1):
    str = file.readline()
    if(not str):
        fileSaida.close()
        os.system("iverilog -o test teste.v")
        #fazer chamada pro arquivo verilog 
        break;
    instrucao = []
    str = str.split(" ")
    str[1] = str[1].split(",")

    #INSTRUÇÕES TIPO R
    shamt = "00000"
    if(str[0]=="add"):
        rd = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n")
        rt = funcoes.regs(str[1][2][0])
        op = "000000"
        funct = "100000"
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(rd)
        instrucao.append(shamt)
        instrucao.append(funct)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="addi"):
        op = "001000"
        rt = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n") 
        imm = bin(int(str[1][2][0])).replace("b","0")
        aux = "0"
        
        for x in range(15-len(imm)):
            aux = aux + "0"
        imm = aux+imm
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(imm)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="and"):
        rd = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n")
        rt = funcoes.regs(str[1][2][0])
        op = "000000"
        funct = "100100"
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(rd)
        instrucao.append(shamt)
        instrucao.append(funct)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="or"):
        op = "000000"
        funct = "100101"
        rd = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n")
        rt = funcoes.regs(str[1][2][0])
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(rd)
        instrucao.append(shamt)
        instrucao.append(funct)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="slt"):
        op = "000000"
        funct = "101010"
        rd = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n")
        rt = funcoes.regs(str[1][2][0])
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(rd)
        instrucao.append(shamt)
        instrucao.append(funct)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="slti"):
        op = "001010"
        rt = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n") 
        imm = bin(int(str[1][2][0])).replace("b","0")
        aux = "0"
        for x in range(15-len(imm)):
            aux = aux + "0"
        imm = aux+imm
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(imm)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")

    #INSTRUÇÕES TIPO I ( LW SW)
    elif(str[0]=="lw"):
        op = "100011"
        rt = funcoes.regs(str[1][0]) #definindo rt
        aux = str[1][1].split("(") #separando para pegar offset depois rs       
        offset = aux[0]   #definindo offset 
        rs = aux[1].split(")") #separando pra pegar rs 
        rs = funcoes.regs(rs[0]) #definindo rs
        offset = bin(int(offset)).replace("b","0")
        aux = "0"
        for x in range(15-len(offset)):
            aux = aux + "0"
        offset = aux+offset
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(offset)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
        
    elif(str[0]=="sw"):
        op = "101011"
        rt = funcoes.regs(str[1][0]) #definindo rt
        aux = str[1][1].split("(") #separando para pegar offset depois rs       
        offset = aux[0]   #definindo offset 
        rs = aux[1].split(")") #separando pra pegar rs 
        rs = funcoes.regs(rs[0]) #definindo rs
        offset = bin(int(offset)).replace("b","0")
        aux = "0"
        for x in range(15-len(offset)):
            aux = aux + "0"
        offset = aux+offset
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(offset)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")

        #INSTRUÇÕES TIPO J (DESVIOS)
    elif(str[0]=="beq"):
        op = "000100"
        rt = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n") 
        imm = bin(int(str[1][2][0])).replace("b","0")
        aux = "0"
        for x in range(15-len(imm)):
            aux = aux + "0"
        imm = aux+imm
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(imm)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="bne"):
        op = "000101"
        rt = funcoes.regs(str[1][0])
        rs = funcoes.regs(str[1][1])
        str[1][2] = str[1][2].split("\n") 
        imm = bin(int(str[1][2][0])).replace("b","0")
        aux = "0"
        for x in range(15-len(imm)):
            aux = aux + "0"
        imm = aux+imm
        instrucao.append(op)
        instrucao.append(rs)
        instrucao.append(rt)
        instrucao.append(imm)
        instrucao = ''.join(instrucao)
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    elif(str[0]=="j"):
        op = "000010"
        target = str[1][0]
        target = bin(int(target)).replace("b","0")
        aux = "0"
        for x in range(25-len(target)):
            aux = aux + "0"
        target = aux+target
        instrucao = op + target
        fileSaida.write(instrucao)
        fileSaida.write("\n")
    else:
        print("Sintaxe assembly incorreto ou função não suportada para esse processador!\n"+
        "Erro: ",str[0])