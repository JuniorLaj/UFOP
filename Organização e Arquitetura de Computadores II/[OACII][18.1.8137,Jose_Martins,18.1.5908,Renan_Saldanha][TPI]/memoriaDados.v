module memoriaDados(clock, memWrite, memRead, address, writeData, readData);
    
    input wire clock; 
    input wire memWrite;
    input wire memRead;
    input wire[31:0] address;
    input wire [31:0] writeData;
    
    output reg[31:0] readData;
    reg[31:0] dadosMemoria[127:0];
    integer x;

    initial begin
        for(x = 0; x < 128; x=x+1)begin
            dadosMemoria[x] <= 10;
        end
    end

    always @(negedge clock)
    begin: ESCRITA
        if(memWrite == 1) begin
            $display("\n\n\nWRITE DADO = %d, ende = %d", writeData, (address/4));
            dadosMemoria[address/4] = writeData;
        end
    end

    always @(posedge clock)
    begin: LEITURA 
        if(memRead == 1) begin
            readData = dadosMemoria[address/4];
        end
    end
endmodule