module unidadeDeteccaoHarzard(clock, opCode, rtIFID, rtIDEX, rsIFID, memRead, ctrl);

    input wire clock;
    input wire [5:0]opCode;
    input wire [4:0]rtIFID;
    input wire [4:0]rtIDEX;
    input wire [4:0]rsIFID;
    input wire memRead;

    output reg ctrl = 0;

    always @ (posedge clock)
    begin: HARZARD
        if((memRead == 1) && ((rtIDEX == rsIFID) || (rtIDEX == rtIFID)))begin
            ctrl <= 1;
            $display("HAZARD rtIDEX = %b rsIFID = %b, rtIFID = %b", rtIDEX, rsIFID, rtIFID);
        end else begin
            ctrl <= 0;
        end
    end    
    
endmodule