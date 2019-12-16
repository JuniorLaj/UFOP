module Forwarding(clock, regWriteEXMEM, regWriteMEMWB, rdMEMWB, rdEXMEM, rsIDEX, rtIDEX, forwardingA, forwardingB);

    input wire clock;
    input wire regWriteEXMEM;
    input wire regWriteMEMWB;
    input wire [4:0]rdMEMWB;
    input wire [4:0]rdEXMEM;
    input wire [4:0]rsIDEX;
    input wire [4:0]rtIDEX;

    output reg [1:0]forwardingA;
    output reg [1:0]forwardingB;

    always @ (negedge clock)
    begin: FORWARDING
        if ((regWriteEXMEM == 1) && (rdEXMEM != 0) && (rdEXMEM == rsIDEX))begin
            assign forwardingA = 2'b10;
            $display("\nForwardingA2\n");
        end else if((regWriteMEMWB == 1) && (rdMEMWB != 0) && (rdMEMWB == rsIDEX))begin
            assign forwardingA = 2'b01;
            $display("\nForwardingA1\n");
        end else begin
            assign forwardingA = 2'b00;
        end
        if((regWriteEXMEM == 1) && (rdEXMEM != 0) && (rdEXMEM == rtIDEX))begin
            assign forwardingB = 2'b10;
            $display("\nForwardingB2\n");
        end else if((regWriteMEMWB == 1) && (rdMEMWB != 0) && (rdMEMWB == rtIDEX))begin
            assign forwardingB = 2'b01;
            $display("\nForwardingB1\n");
        end else begin
            assign forwardingB = 2'b00;
        end
    end

endmodule