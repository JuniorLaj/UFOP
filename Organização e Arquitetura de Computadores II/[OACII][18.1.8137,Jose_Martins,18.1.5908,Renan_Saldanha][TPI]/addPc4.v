module addPc4(clock, ctrl, pc, pc4);
    
    input wire clock;
    input wire [31:0] pc;
    input wire ctrl;
    
    output reg [31:0] pc4;

    always @ (negedge clock)
        begin: SOMA4
        if(ctrl == 0)begin
            pc4 = pc + 4'b0100;
        end else begin
            pc4 = pc - 4'b1000;
        end
    end
endmodule