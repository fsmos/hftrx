// Generated by FIR Compiler
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2005 Altera Corporation
// Any megafunction design, and related net list (encrypted or decrypted),
// support information, device programming or simulation file, and any other
// associated documentation or information provided by Altera or a partner
// under Altera's Megafunction Partnership Program may be used only to
// program PLD devices (but not masked PLD devices) from Altera.  Any other
// use of such megafunction design, net list, support information, device
// programming or simulation file, or any other related documentation or
// information is prohibited for any other purpose, including, but not
// limited to modification, reverse engineering, de-compiling, or use with
// any other silicon devices, unless such use is explicitly licensed under
// a separate agreement with Altera or a megafunction partner.  Title to
// the intellectual property, including patents, copyrights, trademarks,
// trade secrets, or maskworks, embodied in any such megafunction design,
// net list, support information, device programming or simulation file, or
// any other related documentation or information provided by Altera or a
// megafunction partner, remains with Altera, the megafunction partner, or
// their respective licensors.  No other licenses, including any licenses
// needed under any third party's intellectual property, are provided herein.
  
  
module fir_10_2ch_st_wr(clk, rst, clk_en, input_ch_id,
output_ch_id,
rdy_to_ld, done, data_in, fir_result);
parameter OUT_WIDTH = 55;
parameter IN_WIDTH = 32;
parameter FACTOR = 10;
parameter ACCUM_WIDTH = 55;
parameter CH_WIDTH = 1;
parameter MSB_RM = 1;
parameter LSB_RM = 22;
parameter COEF_SET_WIDTH = 4;
                                                                     
input  clk, rst;                                                     
input  clk_en;                                                     
input  [IN_WIDTH - 1:0] data_in;                                     
output rdy_to_ld, done;                                           
output [OUT_WIDTH-MSB_RM-LSB_RM- 1:0] fir_result;                               
output [CH_WIDTH -1 :0]input_ch_id;
output [CH_WIDTH -1 :0]output_ch_id;
                                                                     
wire rdy_to_ld;                                                      
wire done;                                                           
wire done_int;                                                           
wire out_samp;                                                       
wire accum_load;                                                     
                                                                     
wire [OUT_WIDTH -1 :0] accum_out;									
wire [OUT_WIDTH -1 :0] accum_in;										
wire [OUT_WIDTH -1 :0] fir_result_poly;										
wire [OUT_WIDTH -1 :0] fir_int_res;										
wire [OUT_WIDTH-MSB_RM-LSB_RM- 1:0] fir_result;                               
wire [COEF_SET_WIDTH -1 :0] coef_set_cnt;                            
                                                                     
                                                                     
fir_10_2ch_st u0(.clk(clk),                                        
	    .rst(rst),                                                      
	    .clk_en(clk_en),                                                      
	    .data_in(data_in),                                              
	    .coef_set(coef_set_cnt),                                        
	    .done(done_int),                                                    
	    .rdy_to_ld(rdy_to_ld),                                          
	    .fir_result(fir_result_poly)                                         
	    );                                                              
                                                                     
mr_dnc_wr u1(.clk(clk),             
		.rst(rst),                           
		.cen(rdy_to_ld & clk_en),                     
		.cnt_out(coef_set_cnt)               
		);                                   
defparam u1.SIZE = FACTOR;        
defparam u1.OUT_WIDTH = COEF_SET_WIDTH;
											
mr_acc_ctrl_cen_wr	u2(.clk(clk),          
   	     .rst(rst),							
   	     .clk_en(clk_en),							
   	     .done(done_int),						
   	     .out_samp(out_samp),				
   	     .accum_load(accum_load),			
   	     .rdy_to_ld(rdy_to_ld),			
   	     .input_ch_id(input_ch_id),			
   	     .output_ch_id(output_ch_id),			
   	     .rdy_out(done)					
   	     );									
defparam u2.CNT_SIZE = FACTOR;				
defparam u2.CNT_WIDTH = 4;
defparam u2.STRUCT = 1;
defparam u2.NUM_CH = 2;
defparam u2.CH_WIDTH = 1;
defparam u2.DECI_FACT = 10;
defparam u2.DECI_WIDTH = 4;
												
assign accum_in = fir_result_poly;   	   			
												
mr_accum_wr u3(.clk(clk),                    
               .rst(rst),				
               .clk_en(clk_en),				
               .accum_load(accum_load),  
               .cen(done_int),           
               .ain(accum_in),       
               .accum_out(accum_out) 
                       );                    
defparam u3.WIDTH_A = OUT_WIDTH;          
defparam u3.STRUCT = 1;
                                             
mr_lcstore_wr u4(.clk(clk),                 
                 .rst(rst),                 
                 .ce(accum_load & clk_en),             
                 .data_in(accum_out),       
                 .q(fir_int_res));             
                                             
defparam u4.WIDTH = OUT_WIDTH;				
                                              
wire [54:0]fir_int_res_fill;
assign fir_int_res_fill =  fir_int_res[54 :0];
parameter TOT_WIDTH = ACCUM_WIDTH;
assign fir_result = fir_int_res_fill[TOT_WIDTH-MSB_RM-1:LSB_RM];
                                              
endmodule	                                 
////////////////////////////////////////////////////////////////////////////////////////
