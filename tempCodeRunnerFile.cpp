module decoder_2x4(
    input [1:0] in_160,
    output [3:0] out_160,
    input en_160
);

always@(*)
begin

if(en_160){
    if(in_160 == 2'b00)
    out_160 = 4'b0001;
    else if(in_160 == 2'b01)
    out_160 = 4'b0010;
    else if(in_160 == 2'b10)
    out_160 = 4'b0100;
    else 
    out_160 = 4'b1000;
}
else out_160 = 4'b0000;
end
endmodule


module jkflipflip (
    input  j_160 , k_160 , clk,
    output reg q_160 , qbar_160
    );

    always@(posedge(clk))
    begin

    case({j_160 , k_160})
    2'b00 : q_160 = q_160;
    2'b01 : q_160 = 1'b0;
    2'b10 : q_160 = 1'b1;
    2'b11 : q_160 = qbar_160;
    endcase

    qbar_160 = ~q_bar; 

    end
    endmodule