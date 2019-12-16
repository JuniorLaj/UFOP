module Or(clock, branch, jump, control);

    input wire clock;
    input wire branch;
    input wire jump;
    
    output reg control;

    always @ (negedge clock)
    begin: OR
        if((branch == 1) || (jump == 1))begin
            control = 1;
        end else begin
            control = 0;
        end
    end
endmodule