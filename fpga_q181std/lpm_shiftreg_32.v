// megafunction wizard: %LPM_SHIFTREG%
// GENERATION: STANDARD
// VERSION: WM1.0
// MODULE: LPM_SHIFTREG 

// ============================================================
// File Name: lpm_shiftreg_32.v
// Megafunction Name(s):
// 			LPM_SHIFTREG
//
// Simulation Library Files(s):
// 			lpm
// ============================================================
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//
// 18.1.0 Build 625 09/12/2018 SJ Standard Edition
// ************************************************************


//Copyright (C) 2018  Intel Corporation. All rights reserved.
//Your use of Intel Corporation's design tools, logic functions 
//and other software and tools, and its AMPP partner logic 
//functions, and any output files from any of the foregoing 
//(including device programming or simulation files), and any 
//associated documentation or information are expressly subject 
//to the terms and conditions of the Intel Program License 
//Subscription Agreement, the Intel Quartus Prime License Agreement,
//the Intel FPGA IP License Agreement, or other applicable license
//agreement, including, without limitation, that your use is for
//the sole purpose of programming logic devices manufactured by
//Intel and sold by Intel or its authorized distributors.  Please
//refer to the applicable agreement for further details.


// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module lpm_shiftreg_32 (
	clock,
	data,
	enable,
	load,
	shiftin,
	q,
	shiftout);

	input	  clock;
	input	[31:0]  data;
	input	  enable;
	input	  load;
	input	  shiftin;
	output	[31:0]  q;
	output	  shiftout;

	wire [31:0] sub_wire0;
	wire  sub_wire1;
	wire [31:0] q = sub_wire0[31:0];
	wire  shiftout = sub_wire1;

	lpm_shiftreg	LPM_SHIFTREG_component (
				.clock (clock),
				.data (data),
				.enable (enable),
				.load (load),
				.shiftin (shiftin),
				.q (sub_wire0),
				.shiftout (sub_wire1)
				// synopsys translate_off
				,
				.aclr (),
				.aset (),
				.sclr (),
				.sset ()
				// synopsys translate_on
				);
	defparam
		LPM_SHIFTREG_component.lpm_direction = "LEFT",
		LPM_SHIFTREG_component.lpm_type = "LPM_SHIFTREG",
		LPM_SHIFTREG_component.lpm_width = 32;


endmodule

// ============================================================
// CNX file retrieval info
// ============================================================
// Retrieval info: PRIVATE: ACLR NUMERIC "0"
// Retrieval info: PRIVATE: ALOAD NUMERIC "0"
// Retrieval info: PRIVATE: ASET NUMERIC "0"
// Retrieval info: PRIVATE: ASET_ALL1 NUMERIC "1"
// Retrieval info: PRIVATE: CLK_EN NUMERIC "1"
// Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Cyclone III"
// Retrieval info: PRIVATE: LeftShift NUMERIC "1"
// Retrieval info: PRIVATE: ParallelDataInput NUMERIC "1"
// Retrieval info: PRIVATE: Q_OUT NUMERIC "1"
// Retrieval info: PRIVATE: SCLR NUMERIC "0"
// Retrieval info: PRIVATE: SLOAD NUMERIC "1"
// Retrieval info: PRIVATE: SSET NUMERIC "0"
// Retrieval info: PRIVATE: SSET_ALL1 NUMERIC "1"
// Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "0"
// Retrieval info: PRIVATE: SerialShiftInput NUMERIC "1"
// Retrieval info: PRIVATE: SerialShiftOutput NUMERIC "1"
// Retrieval info: PRIVATE: nBit NUMERIC "32"
// Retrieval info: PRIVATE: new_diagram STRING "1"
// Retrieval info: LIBRARY: lpm lpm.lpm_components.all
// Retrieval info: CONSTANT: LPM_DIRECTION STRING "LEFT"
// Retrieval info: CONSTANT: LPM_TYPE STRING "LPM_SHIFTREG"
// Retrieval info: CONSTANT: LPM_WIDTH NUMERIC "32"
// Retrieval info: USED_PORT: clock 0 0 0 0 INPUT NODEFVAL "clock"
// Retrieval info: USED_PORT: data 0 0 32 0 INPUT NODEFVAL "data[31..0]"
// Retrieval info: USED_PORT: enable 0 0 0 0 INPUT NODEFVAL "enable"
// Retrieval info: USED_PORT: load 0 0 0 0 INPUT NODEFVAL "load"
// Retrieval info: USED_PORT: q 0 0 32 0 OUTPUT NODEFVAL "q[31..0]"
// Retrieval info: USED_PORT: shiftin 0 0 0 0 INPUT NODEFVAL "shiftin"
// Retrieval info: USED_PORT: shiftout 0 0 0 0 OUTPUT NODEFVAL "shiftout"
// Retrieval info: CONNECT: @clock 0 0 0 0 clock 0 0 0 0
// Retrieval info: CONNECT: @data 0 0 32 0 data 0 0 32 0
// Retrieval info: CONNECT: @enable 0 0 0 0 enable 0 0 0 0
// Retrieval info: CONNECT: @load 0 0 0 0 load 0 0 0 0
// Retrieval info: CONNECT: @shiftin 0 0 0 0 shiftin 0 0 0 0
// Retrieval info: CONNECT: q 0 0 32 0 @q 0 0 32 0
// Retrieval info: CONNECT: shiftout 0 0 0 0 @shiftout 0 0 0 0
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32.v TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32.inc FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32.cmp FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32.bsf TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32_inst.v FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_shiftreg_32_bb.v FALSE
// Retrieval info: LIB_FILE: lpm
