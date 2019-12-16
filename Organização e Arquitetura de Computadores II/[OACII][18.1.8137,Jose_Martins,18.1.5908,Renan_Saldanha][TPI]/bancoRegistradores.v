module bancoRegistradores(clock, readRegister1, readRegister2, writeRegister, writeData, regWrite, readData1, readData2);

    input wire clock;
    input wire [4:0] readRegister1;
    input wire [4:0] readRegister2;
    input wire [4:0] writeRegister;
    input wire [31:0] writeData;
    input wire regWrite;

    output reg [31:0] readData1;
    output reg [31:0] readData2;

    reg [31:0] zero = 32'b00000000000000000000000000000000;
    reg [31:0] at = 4;
    reg [31:0] v0 = 4;
    reg [31:0] v1 = 4;
    reg [31:0] a0 = 4;
    reg [31:0] a1 = 4;
    reg [31:0] a2 = 4;
    reg [31:0] a3 = 4;
    reg [31:0] t0 = 4;
    reg [31:0] t1 = 4;
    reg [31:0] t2 = 4;
    reg [31:0] t3 = 4;
    reg [31:0] t4 = 4;
    reg [31:0] t5 = 4;
    reg [31:0] t6 = 4;
    reg [31:0] t7 = 4;
    reg [31:0] s0 = 4;
    reg [31:0] s1 = 4;
    reg [31:0] s2 = 4;
    reg [31:0] s3 = 4;
    reg [31:0] s4 = 4;
    reg [31:0] s5 = 4;
    reg [31:0] s6 = 4;
    reg [31:0] s7 = 4;
    reg [31:0] t8 = 4;
    reg [31:0] t9 = 4;
    reg [31:0] k0 = 4;
    reg [31:0] k1 = 4;
    reg [31:0] gp = 4;
    reg [31:0] sp = 4;
    reg [31:0] fp = 4;
    reg [31:0] ra = 4;

    always @ (posedge clock)
    begin: SALVADADO
        if(regWrite == 1) begin
            $display("\n\nWRITE DATA REG = %d   REG = %d", writeData, writeRegister);
            case (writeRegister)
                1: at <= writeData;
                2: v0 <= writeData;
                3: v1 <= writeData;
                4: a0 <= writeData;
                5: a1 <= writeData;
                6: a2 <= writeData;
                7: a3 <= writeData;
                8: t0 <= writeData;
                9: t1 <= writeData;
                10: t2 <= writeData;
                11: t3 <= writeData;
                12: t4 <= writeData;
                13: t5 <= writeData;
                14: t6 <= writeData;
                15: t7 <= writeData;
                16: s0 <= writeData;
                17: s1 <= writeData;
                18: s2 <= writeData;
                19: s3 <= writeData;
                20: s4 <= writeData;
                21: s5 <= writeData;
                22: s6 <= writeData;
                23: s7 <= writeData;
                24: t8 <= writeData;
                25: t9 <= writeData;
                26: k0 <= writeData;
                27: k1 <= writeData;
                28: gp <= writeData;
                29: sp <= writeData;
                30: fp <= writeData;
                31: ra <= writeData;
                default : zero <= 0;
            endcase
        end
    end

    always @ (negedge clock)
    begin: LEITURA
        case (readRegister1)
            0: readData1 <= zero;
            1: readData1 <= at;
            2: readData1 <= v0;
            3: readData1 <= v1;
            4: readData1 <= a0;
            5: readData1 <= a1;
            6: readData1 <= a2;
            7: readData1 <= a3;
            8: readData1 <= t0;
            9: readData1 <= t1;
            10: readData1 <= t2;
            11: readData1 <= t3;
            12: readData1 <= t4;
            13: readData1 <= t5;
            14: readData1 <= t6;
            15: readData1 <= t7;
            16: readData1 <= s0;
            17: readData1 <= s1;
            18: readData1 <= s2;
            19: readData1 <= s3;
            20: readData1 <= s4;
            21: readData1 <= s5;
            22: readData1 <= s6;
            23: readData1 <= s7;
            24: readData1 <= t8;
            25: readData1 <= t9;
            26: readData1 <= k0;
            27: readData1 <= k1;
            28: readData1 <= gp;
            29: readData1 <= sp;
            30: readData1 <= fp;
            31: readData1 <= ra;
            default : readData1 <= zero;
        endcase
        case (readRegister2)
            0: readData2 <= zero;
            1: readData2 <= at;
            2: readData2 <= v0;
            3: readData2 <= v1;
            4: readData2 <= a0;
            5: readData2 <= a1;
            6: readData2 <= a2;
            7: readData2 <= a3;
            8: readData2 <= t0;
            9: readData2 <= t1;
            10: readData2 <= t2;
            11: readData2 <= t3;
            12: readData2 <= t4;
            13: readData2 <= t5;
            14: readData2 <= t6;
            15: readData2 <= t7;
            16: readData2 <= s0;
            17: readData2 <= s1;
            18: readData2 <= s2;
            19: readData2 <= s3;
            20: readData2 <= s4;
            21: readData2 <= s5;
            22: readData2 <= s6;
            23: readData2 <= s7;
            24: readData2 <= t8;
            25: readData2 <= t9;
            26: readData2 <= k0;
            27: readData2 <= k1;
            28: readData2 <= gp;
            29: readData2 <= sp;
            30: readData2 <= fp;
            31: readData2 <= ra;
            default : readData2 <= 0;
        endcase
    end
endmodule