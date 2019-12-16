module memoryInstruc(clock, address, instruc);
    //Parâmetros
    input wire[31:0] address;
    input wire clock;
    integer file, scan_file;
    
    output reg[31:0] instruc;

    //Variáveis internas
    //instruc = instrução de saída da memória de instruções
    //instrucoes[] = todas as instruções do código
    reg [31:0] instrucoes[31:0];
    integer i = 0;
    reg[31:0] pc;

    initial begin
        i <= 0;
        file = $fopenr("arquivoSaida.txt");
        while(!$feof(file)) begin
        scan_file = $fscanf(file,"%b",instrucoes[i]);
        i = i +1;
        end
    end

    always @ (negedge clock)
    begin: LEITURA
        instruc <= instrucoes[address/4];
        /*for(i=0;i<50; i++) begin
            if(i!=0) begin
                pc <= i << 2;
            end
            if(pc==address) begin
                instruc = instrucoes[i];
                disable LEITURA;
            end
        end*/ 
    end
endmodule
