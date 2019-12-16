module extensorSinal(clock, address, addressExtend);

    input wire clock;
    input wire [15:0] address;

    output reg [31:0] addressExtend;

    always @ (negedge clock)
    begin: EXTENSORSINAL
        addressExtend <= address;
    end

endmodule