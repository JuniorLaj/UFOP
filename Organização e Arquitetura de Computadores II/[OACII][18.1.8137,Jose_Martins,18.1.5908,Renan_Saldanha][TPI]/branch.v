module branch(branch, zero, out);

    input wire branch;
    input wire zero;
    
    output reg out;

    always @ (*)
    begin: BRANCH
        if(branch && zero)begin
            out <= 1;
        end else begin
            out <= 0;
        end
    end

endmodule