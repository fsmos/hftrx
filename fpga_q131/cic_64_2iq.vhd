-- megafunction wizard: %CIC v13.1%
-- GENERATION: XML

-- ============================================================
-- Megafunction Name(s):
-- 			cic_64_2iq_cic
-- ============================================================
-- Generated by CIC 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
-- ************************************************************
-- THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
-- ************************************************************
-- Copyright (C) 1991-2017 Altera Corporation
-- Any megafunction design, and related net list (encrypted or decrypted),
-- support information, device programming or simulation file, and any other
-- associated documentation or information provided by Altera or a partner
-- under Altera's Megafunction Partnership Program may be used only to
-- program PLD devices (but not masked PLD devices) from Altera.  Any other
-- use of such megafunction design, net list, support information, device
-- programming or simulation file, or any other related documentation or
-- information is prohibited for any other purpose, including, but not
-- limited to modification, reverse engineering, de-compiling, or use with
-- any other silicon devices, unless such use is explicitly licensed under
-- a separate agreement with Altera or a megafunction partner.  Title to
-- the intellectual property, including patents, copyrights, trademarks,
-- trade secrets, or maskworks, embodied in any such megafunction design,
-- net list, support information, device programming or simulation file, or
-- any other related documentation or information provided by Altera or a
-- megafunction partner, remains with Altera, the megafunction partner, or
-- their respective licensors.  No other licenses, including any licenses
-- needed under any third party's intellectual property, are provided herein.

library IEEE;
use IEEE.std_logic_1164.all;

ENTITY cic_64_2iq IS
	PORT (
		clk	: IN STD_LOGIC;
		clken	: IN STD_LOGIC;
		reset_n	: IN STD_LOGIC;
		in0_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in1_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in2_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in3_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in_valid	: IN STD_LOGIC;
		out_ready	: IN STD_LOGIC;
		in_error	: IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		out_data	: OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
		out_channel	: OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
		out_startofpacket	: OUT STD_LOGIC;
		out_endofpacket	: OUT STD_LOGIC;
		in_ready	: OUT STD_LOGIC;
		out_valid	: OUT STD_LOGIC;
		out_error	: OUT STD_LOGIC_VECTOR (1 DOWNTO 0)
	);
END cic_64_2iq;

ARCHITECTURE SYN OF cic_64_2iq IS


	COMPONENT cic_64_2iq_cic
	PORT (
		clk	: IN STD_LOGIC;
		clken	: IN STD_LOGIC;
		reset_n	: IN STD_LOGIC;
		in0_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in1_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in2_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in3_data	: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		in_valid	: IN STD_LOGIC;
		out_ready	: IN STD_LOGIC;
		in_error	: IN STD_LOGIC_VECTOR (1 DOWNTO 0);
		out_data	: OUT STD_LOGIC_VECTOR (31 DOWNTO 0);
		out_channel	: OUT STD_LOGIC_VECTOR (1 DOWNTO 0);
		out_startofpacket	: OUT STD_LOGIC;
		out_endofpacket	: OUT STD_LOGIC;
		in_ready	: OUT STD_LOGIC;
		out_valid	: OUT STD_LOGIC;
		out_error	: OUT STD_LOGIC_VECTOR (1 DOWNTO 0)
	);

	END COMPONENT;

BEGIN

	cic_64_2iq_cic_inst : cic_64_2iq_cic
	PORT MAP (
		clk  =>  clk,
		clken  =>  clken,
		reset_n  =>  reset_n,
		in0_data  =>  in0_data,
		in1_data  =>  in1_data,
		in2_data  =>  in2_data,
		in3_data  =>  in3_data,
		out_data  =>  out_data,
		out_channel  =>  out_channel,
		out_startofpacket  =>  out_startofpacket,
		out_endofpacket  =>  out_endofpacket,
		in_valid  =>  in_valid,
		out_ready  =>  out_ready,
		in_ready  =>  in_ready,
		out_valid  =>  out_valid,
		in_error  =>  in_error,
		out_error  =>  out_error
	);


END SYN;


-- =========================================================
-- CIC Wizard Data
-- ===============================
-- DO NOT EDIT FOLLOWING DATA
-- @Altera, IP Toolbench@
-- Warning: If you modify this section, CIC Wizard may not be able to reproduce your chosen configuration.
-- 
-- Retrieval info: <?xml version="1.0"?>
-- Retrieval info: <MEGACORE title="CIC"  version="13.1"  build="182"  iptb_version="1.3.0 Build 182"  format_version="120" >
-- Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.CICModel"  active_core="cic_64_2iq_cic" >
-- Retrieval info:   <STATIC_SECTION>
-- Retrieval info:    <PRIVATES>
-- Retrieval info:     <NAMESPACE name = "parameterization">
-- Retrieval info:      <PRIVATE name = "filter_type" value="Decimator"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "megawizard2" value="1"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "activate_atstartup" value="1"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "window_location" value="center"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Device Family" value="Cyclone IV E"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Number of Stages" value="11"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Rate Change Factor" value="64"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Differential Delay" value="1"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Input Bit Width" value="32"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Output Bit Width" value="32"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Hogenauer Pruning" value="1"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Support AST back pressure" value="1"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Full Output Resolution" value="0"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Map Integrator Registers Into" value="Logic Element"  type="STRING"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Map Differentiator Registers Into" value="Logic Element"  type="STRING"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Ram Type of Integrator Registers" value="AUTO"  type="STRING"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Ram Type of Differentiator Registers" value="AUTO"  type="STRING"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Number of channels per interface" value="1"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Number of interfaces" value="4"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Output Rounding Option" value="0"  type="INTEGER"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Integrator pipeline number" value="1"  type="INTEGER"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Use pipeline in integrator" value="0"  type="BOOLEAN"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Variable Rate Change Factor" value="0"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "Maximum Rate Change Factor" value="3"  type="INTEGER"  enable="0" />
-- Retrieval info:      <PRIVATE name = "Minimum Rate Change Factor" value="2"  type="INTEGER"  enable="0" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "simgen_enable">
-- Retrieval info:      <PRIVATE name = "language" value="VHDL"  type="STRING"  enable="1" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "hdl_generator">
-- Retrieval info:      <PRIVATE name = "report" value="1"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "blackbox" value="0"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "component" value="0"  type="BOOLEAN"  enable="1" />
-- Retrieval info:      <PRIVATE name = "symbol" value="0"  type="BOOLEAN"  enable="1" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "simgen">
-- Retrieval info:      <PRIVATE name = "filename" value="cic_64_2iq.vho"  type="STRING"  enable="1" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "greybox">
-- Retrieval info:      <PRIVATE name = "filename" value="cic_64_2iq_syn.v"  type="STRING"  enable="1" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "quartus_settings">
-- Retrieval info:      <PRIVATE name = "DEVICE" value="EP4CE22E22I7"  type="STRING"  enable="1" />
-- Retrieval info:      <PRIVATE name = "FAMILY" value="Cyclone IV E"  type="STRING"  enable="1" />
-- Retrieval info:     </NAMESPACE>
-- Retrieval info:     <NAMESPACE name = "serializer"/>
-- Retrieval info:    </PRIVATES>
-- Retrieval info:    <FILES/>
-- Retrieval info:    <PORTS>
-- Retrieval info:     <PORT name = "clock" direction="INPUT"  connect_to="clk"  default="NODEFVAL"  width="1"  description="" />
-- Retrieval info:     <PORT name = "reset" direction="INPUT"  connect_to="reset"  default="NODEFVAL"  width="1"  description="" />
-- Retrieval info:    </PORTS>
-- Retrieval info:    <LIBRARIES/>
-- Retrieval info:   </STATIC_SECTION>
-- Retrieval info:  </NETLIST_SECTION>
-- Retrieval info: </MEGACORE>
-- =========================================================
