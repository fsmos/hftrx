// megafunction wizard: %FIR Compiler v13.1%
// GENERATION: XML

// ============================================================
// Megafunction Name(s):
// 			fir_10ex_2ch_ast
// ============================================================
// Generated by FIR Compiler 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2017 Altera Corporation
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


module fir_10ex_2ch (
	clk,
	reset_n,
	ast_sink_data,
	ast_sink_valid,
	ast_source_ready,
	ast_sink_sop,
	ast_sink_eop,
	ast_sink_error,
	ast_source_data,
	ast_sink_ready,
	ast_source_valid,
	ast_source_sop,
	ast_source_eop,
	ast_source_channel,
	ast_source_error);


	input		clk;
	input		reset_n;
	input	[31:0]	ast_sink_data;
	input		ast_sink_valid;
	input		ast_source_ready;
	input		ast_sink_sop;
	input		ast_sink_eop;
	input	[1:0]	ast_sink_error;
	output	[31:0]	ast_source_data;
	output		ast_sink_ready;
	output		ast_source_valid;
	output		ast_source_sop;
	output		ast_source_eop;
	output		ast_source_channel;
	output	[1:0]	ast_source_error;


	fir_10ex_2ch_ast	fir_10ex_2ch_ast_inst(
		.clk(clk),
		.reset_n(reset_n),
		.ast_sink_data(ast_sink_data),
		.ast_sink_valid(ast_sink_valid),
		.ast_source_ready(ast_source_ready),
		.ast_sink_sop(ast_sink_sop),
		.ast_sink_eop(ast_sink_eop),
		.ast_sink_error(ast_sink_error),
		.ast_source_data(ast_source_data),
		.ast_sink_ready(ast_sink_ready),
		.ast_source_valid(ast_source_valid),
		.ast_source_sop(ast_source_sop),
		.ast_source_eop(ast_source_eop),
		.ast_source_channel(ast_source_channel),
		.ast_source_error(ast_source_error));
endmodule

// =========================================================
// FIR Compiler Wizard Data
// ===============================
// DO NOT EDIT FOLLOWING DATA
// @Altera, IP Toolbench@
// Warning: If you modify this section, FIR Compiler Wizard may not be able to reproduce your chosen configuration.
// 
// Retrieval info: <?xml version="1.0"?>
// Retrieval info: <MEGACORE title="FIR Compiler"  version="13.1"  build="182"  iptb_version="1.3.0 Build 182"  format_version="120" >
// Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.FIRModelClass"  active_core="fir_10ex_2ch_ast" >
// Retrieval info:   <STATIC_SECTION>
// Retrieval info:    <PRIVATES>
// Retrieval info:     <NAMESPACE name = "parameterization">
// Retrieval info:      <PRIVATE name = "use_mem" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "mem_type" value="M512"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_rate" value="Decimation"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_factor" value="10"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_type" value="Signed Binary Fractional"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="4194304.0"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="23"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Actual Coefficients"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="32"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="22"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_lsb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_msb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_input" value="Slave Sink"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_output" value="Master Source"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "device_family" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "structure" value="Distributed Arithmetic : Fully Serial Filter"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "pipeline_level" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "clocks_to_compute" value="1"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "number_of_serial_units" value="2"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "data_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_storage" value="Logic Cells"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "multiplier_storage" value="Logic Cells"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="1"  type="BOOLEAN"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="0"  type="BOOLEAN"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 729, 200.0, 9.1, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.03284E-6, -1.42535E-6, -1.76283E-6, -1.98931E-6, -2.05084E-6, -1.90262E-6, -1.51612E-6, 0.0, 0.0, 0.0, 2.12322E-6, 3.24472E-6, 4.24599E-6, 5.0052E-6, 5.40732E-6, 5.35723E-6, 4.79224E-6, 3.69293E-6, 2.09063E-6, 0.0, -2.22976E-6, -4.62859E-6, -6.91205E-6, -8.85171E-6, -1.02252E-5, -1.08383E-5, -1.05467E-5, -9.27543E-6, -7.03263E-6, -3.91794E-6, 0.0, 4.08202E-6, 8.3564E-6, 1.23235E-5, 1.55972E-5, 1.78177E-5, 1.86869E-5, 1.80014E-5, 1.56795E-5, 1.1779E-5, 6.5045E-6, 0.0, -6.66548E-6, -1.3539E-5, -1.98173E-5, -2.49013E-5, -2.82491E-5, -2.94288E-5, -2.81653E-5, -2.4377E-5, -1.81979E-5, -9.98145E-6, 0.0, 1.01592E-5, 2.05063E-5, 2.98541E-5, 3.7324E-5, 4.21379E-5, 4.36938E-5, 4.16302E-5, 3.58744E-5, 2.66679E-5, 1.45669E-5, 0.0, -1.47128E-5, -2.9585E-5, -4.29133E-5, -5.3459E-5, -6.01432E-5, -6.21508E-5, -5.90163E-5, -5.06864E-5, -3.75495E-5, -2.04291E-5, 0.0, 2.05954E-5, 4.12542E-5, 5.96542E-5, 7.41009E-5, 8.31379E-5, 8.56854E-5, 8.11543E-5, 6.95242E-5, 5.13776E-5, 2.78834E-5, 0.0, -2.79887E-5, -5.59327E-5, -8.06985E-5, -1.00022E-4, -1.11978E-4, -1.15164E-4, -1.08843E-4, -9.30445E-5, -6.86031E-5, -3.71262E-5, 0.0, 3.72706E-5, 7.4272E-5, 1.06931E-4, 1.32282E-4, 1.47823E-4, 1.51759E-4, 1.43181E-4, 1.22191E-4, 8.9941E-5, 4.85895E-5, 1.16504E-6, -4.86461E-5, -9.67795E-5, -1.39118E-4, -1.71834E-4, -1.91733E-4, -1.96541E-4, -1.85151E-4, -1.57763E-4, -1.15929E-4, -6.24883E-5, -1.38166E-6, 6.26258E-5, 1.2431E-4, 1.78405E-4, 2.20046E-4, 2.45195E-4, 2.51016E-4, 2.36166E-4, 2.00977E-4, 1.47497E-4, 7.93973E-5, 1.72991E-6, -7.94324E-5, -1.57464E-4, -2.25716E-4, -2.78076E-4, -3.09501E-4, -3.16485E-4, -2.97416E-4, -2.52796E-4, -1.8528E-4, -9.95471E-5, -1.9911E-6, 9.97433E-5, 1.9735E-4, 2.82527E-4, 3.47675E-4, 3.86556E-4, 3.94876E-4, 3.70714E-4, 3.14786E-4, 2.30483E-4, 1.23696E-4, 2.42601E-6, -1.23807E-4, -2.44695E-4, -3.49973E-4, -4.30279E-4, -4.77966E-4, -4.87813E-4, -4.57545E-4, -3.88144E-4, -2.83885E-4, -1.52109E-4, -2.72307E-6, 1.52525E-4, 3.00958E-4, 4.2999E-4, 5.28182E-4, 5.8623E-4, 5.97827E-4, 5.60294E-4, 4.74937E-4, 3.47086E-4, 1.85799E-4, 3.24111E-6, -1.86212E-4, -3.67091E-4, -5.24079E-4, -6.43294E-4, -7.13492E-4, -7.27096E-4, -6.8096E-4, -5.76784E-4, -4.21146E-4, -2.25129E-4, -3.55878E-6, 2.26099E-4, 4.45094E-4, 6.34905E-4, 7.78786E-4, 8.63218E-4, 8.79144E-4, 8.22873E-4, 6.96575E-4, 5.08298E-4, 2.71507E-4, 4.14837E-6, -2.72685E-4, -5.36394E-4, -7.64701E-4, -9.37503E-4, -0.00103861, -0.00105724, -9.89064E-4, -8.36794E-4, -6.10209E-4, -3.25564E-4, -4.46535E-6, 3.27741E-4, 6.43942E-4, 9.1745E-4, 0.00112422, 0.00124494, 0.00126677, 0.00118462, 0.00100186, 7.30279E-4, 3.89393E-4, 5.10696E-6, -3.9224E-4, -7.70229E-4, -0.00109698, -0.00134381, -0.00148769, -0.00151336, -0.00141484, -0.00119619, -8.71565E-4, -4.64318E-4, -5.3974E-6, 4.68969E-4, 9.20097E-4, 0.00130996, 0.00160436, 0.00177585, 0.00180627, 0.00168849, 0.0014274, 0.00103988, 5.53799E-4, 6.06465E-6, -5.60109E-4, -0.00109858, -0.00156397, -0.00191547, -0.00212031, -0.00215675, -0.00201624, -0.00170453, -0.0012417, -6.60952E-4, -6.30054E-6, 6.70671E-4, 0.00131483, 0.00187192, 0.00229305, 0.0025389, 0.00258329, 0.00241575, 0.00204294, 0.00148866, 7.92468E-4, 6.96227E-6, -8.06106E-4, -0.0015806, -0.00225127, -0.00275919, -0.00305677, -0.00311211, -0.0029121, -0.00246423, -0.00179664, -9.56569E-4, -7.11625E-6, 9.77335E-4, 0.00191684, 0.00273225, 0.00335174, 0.00371693, 0.00378823, 0.00354871, 0.00300636, 0.0021944, 0.00116942, 7.73933E-6, -0.00120017, -0.00235649, -0.00336378, -0.00413298, -0.00459097, -0.00468724, -0.00439887, -0.00373357, -0.00273025, -0.00145722, -7.78774E-6, 0.00150623, 0.00296284, 0.00423933, 0.00522222, 0.00581687, 0.00595604, 0.00560656, 0.00477363, 0.00350215, 0.00187503, 8.34022E-6, -0.00195647, -0.00386262, -0.0055499, -0.00686729, -0.0076856, -0.00790893, -0.00748418, -0.00640763, -0.00472805, -0.00254587, -8.26587E-6, 0.00269958, 0.00536671, 0.00777125, 0.009697, 0.0109506, 0.0113777, 0.0108782, 0.00941665, 0.00703067, 0.0038329, 8.72019E-6, -0.0041917, -0.00846613, -0.0124775, -0.015874, -0.0183119, -0.0194786, -0.0191144, -0.0170327, -0.0131357, -0.00742536, -8.5145E-6, 0.00890445, 0.0190074, 0.0299126, 0.0411696, 0.0522895, 0.0627712, 0.0721293, 0.0799216, 0.0857747, 0.0894047, 0.0906348, 0.0894047, 0.0857747, 0.0799216, 0.0721293, 0.0627712, 0.0522895, 0.0411696, 0.0299126, 0.0190074, 0.00890445, -8.5145E-6, -0.00742536, -0.0131357, -0.0170327, -0.0191144, -0.0194786, -0.0183119, -0.015874, -0.0124775, -0.00846613, -0.0041917, 8.72019E-6, 0.0038329, 0.00703067, 0.00941665, 0.0108782, 0.0113777, 0.0109506, 0.009697, 0.00777125, 0.00536671, 0.00269958, -8.26587E-6, -0.00254587, -0.00472805, -0.00640763, -0.00748418, -0.00790893, -0.0076856, -0.00686729, -0.0055499, -0.00386262, -0.00195647, 8.34022E-6, 0.00187503, 0.00350215, 0.00477363, 0.00560656, 0.00595604, 0.00581687, 0.00522222, 0.00423933, 0.00296284, 0.00150623, -7.78774E-6, -0.00145722, -0.00273025, -0.00373357, -0.00439887, -0.00468724, -0.00459097, -0.00413298, -0.00336378, -0.00235649, -0.00120017, 7.73933E-6, 0.00116942, 0.0021944, 0.00300636, 0.00354871, 0.00378823, 0.00371693, 0.00335174, 0.00273225, 0.00191684, 9.77335E-4, -7.11625E-6, -9.56569E-4, -0.00179664, -0.00246423, -0.0029121, -0.00311211, -0.00305677, -0.00275919, -0.00225127, -0.0015806, -8.06106E-4, 6.96227E-6, 7.92468E-4, 0.00148866, 0.00204294, 0.00241575, 0.00258329, 0.0025389, 0.00229305, 0.00187192, 0.00131483, 6.70671E-4, -6.30054E-6, -6.60952E-4, -0.0012417, -0.00170453, -0.00201624, -0.00215675, -0.00212031, -0.00191547, -0.00156397, -0.00109858, -5.60109E-4, 6.06465E-6, 5.53799E-4, 0.00103988, 0.0014274, 0.00168849, 0.00180627, 0.00177585, 0.00160436, 0.00130996, 9.20097E-4, 4.68969E-4, -5.3974E-6, -4.64318E-4, -8.71565E-4, -0.00119619, -0.00141484, -0.00151336, -0.00148769, -0.00134381, -0.00109698, -7.70229E-4, -3.9224E-4, 5.10696E-6, 3.89393E-4, 7.30279E-4, 0.00100186, 0.00118462, 0.00126677, 0.00124494, 0.00112422, 9.1745E-4, 6.43942E-4, 3.27741E-4, -4.46535E-6, -3.25564E-4, -6.10209E-4, -8.36794E-4, -9.89064E-4, -0.00105724, -0.00103861, -9.37503E-4, -7.64701E-4, -5.36394E-4, -2.72685E-4, 4.14837E-6, 2.71507E-4, 5.08298E-4, 6.96575E-4, 8.22873E-4, 8.79144E-4, 8.63218E-4, 7.78786E-4, 6.34905E-4, 4.45094E-4, 2.26099E-4, -3.55878E-6, -2.25129E-4, -4.21146E-4, -5.76784E-4, -6.8096E-4, -7.27096E-4, -7.13492E-4, -6.43294E-4, -5.24079E-4, -3.67091E-4, -1.86212E-4, 3.24111E-6, 1.85799E-4, 3.47086E-4, 4.74937E-4, 5.60294E-4, 5.97827E-4, 5.8623E-4, 5.28182E-4, 4.2999E-4, 3.00958E-4, 1.52525E-4, -2.72307E-6, -1.52109E-4, -2.83885E-4, -3.88144E-4, -4.57545E-4, -4.87813E-4, -4.77966E-4, -4.30279E-4, -3.49973E-4, -2.44695E-4, -1.23807E-4, 2.42601E-6, 1.23696E-4, 2.30483E-4, 3.14786E-4, 3.70714E-4, 3.94876E-4, 3.86556E-4, 3.47675E-4, 2.82527E-4, 1.9735E-4, 9.97433E-5, -1.9911E-6, -9.95471E-5, -1.8528E-4, -2.52796E-4, -2.97416E-4, -3.16485E-4, -3.09501E-4, -2.78076E-4, -2.25716E-4, -1.57464E-4, -7.94324E-5, 1.72991E-6, 7.93973E-5, 1.47497E-4, 2.00977E-4, 2.36166E-4, 2.51016E-4, 2.45195E-4, 2.20046E-4, 1.78405E-4, 1.2431E-4, 6.26258E-5, -1.38166E-6, -6.24883E-5, -1.15929E-4, -1.57763E-4, -1.85151E-4, -1.96541E-4, -1.91733E-4, -1.71834E-4, -1.39118E-4, -9.67795E-5, -4.86461E-5, 1.16504E-6, 4.85895E-5, 8.9941E-5, 1.22191E-4, 1.43181E-4, 1.51759E-4, 1.47823E-4, 1.32282E-4, 1.06931E-4, 7.4272E-5, 3.72706E-5, 0.0, -3.71262E-5, -6.86031E-5, -9.30445E-5, -1.08843E-4, -1.15164E-4, -1.11978E-4, -1.00022E-4, -8.06985E-5, -5.59327E-5, -2.79887E-5, 0.0, 2.78834E-5, 5.13776E-5, 6.95242E-5, 8.11543E-5, 8.56854E-5, 8.31379E-5, 7.41009E-5, 5.96542E-5, 4.12542E-5, 2.05954E-5, 0.0, -2.04291E-5, -3.75495E-5, -5.06864E-5, -5.90163E-5, -6.21508E-5, -6.01432E-5, -5.3459E-5, -4.29133E-5, -2.9585E-5, -1.47128E-5, 0.0, 1.45669E-5, 2.66679E-5, 3.58744E-5, 4.16302E-5, 4.36938E-5, 4.21379E-5, 3.7324E-5, 2.98541E-5, 2.05063E-5, 1.01592E-5, 0.0, -9.98145E-6, -1.81979E-5, -2.4377E-5, -2.81653E-5, -2.94288E-5, -2.82491E-5, -2.49013E-5, -1.98173E-5, -1.3539E-5, -6.66548E-6, 0.0, 6.5045E-6, 1.1779E-5, 1.56795E-5, 1.80014E-5, 1.86869E-5, 1.78177E-5, 1.55972E-5, 1.23235E-5, 8.3564E-6, 4.08202E-6, 0.0, -3.91794E-6, -7.03263E-6, -9.27543E-6, -1.05467E-5, -1.08383E-5, -1.02252E-5, -8.85171E-6, -6.91205E-6, -4.62859E-6, -2.22976E-6, 0.0, 2.09063E-6, 3.69293E-6, 4.79224E-6, 5.35723E-6, 5.40732E-6, 5.0052E-6, 4.24599E-6, 3.24472E-6, 2.12322E-6, 0.0, 0.0, 0.0, -1.51612E-6, -1.90262E-6, -2.05084E-6, -1.98931E-6, -1.76283E-6, -1.42535E-6, -1.03284E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="56"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="53"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="25"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="1964"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m512" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m4k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m144k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m9k" value="6"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m20k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "mlab" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "megaram" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "dsp_block" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_clock_period" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_clock_period" value="320"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "throughput" value="320"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "memory_units" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen_enable">
// Retrieval info:      <PRIVATE name = "matlab_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_simulation_clock_period" value="10.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "language" value="Verilog HDL"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "enabled" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen">
// Retrieval info:      <PRIVATE name = "filename" value="fir_10ex_2ch.vo"  type="STRING"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "quartus_settings">
// Retrieval info:      <PRIVATE name = "DEVICE" value="EP4CE22E22I7"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "FAMILY" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "serializer"/>
// Retrieval info:    </PRIVATES>
// Retrieval info:    <FILES/>
// Retrieval info:    <PORTS/>
// Retrieval info:    <LIBRARIES/>
// Retrieval info:   </STATIC_SECTION>
// Retrieval info:  </NETLIST_SECTION>
// Retrieval info: </MEGACORE>
// =========================================================
