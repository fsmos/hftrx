// megafunction wizard: %FIR Compiler v13.1%
// GENERATION: XML

// ============================================================
// Megafunction Name(s):
// 			fir_20_2ch_ast
// ============================================================
// Generated by FIR Compiler 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2019 Altera Corporation
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


module fir_20_2ch (
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


	fir_20_2ch_ast	fir_20_2ch_ast_inst(
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
// Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.FIRModelClass"  active_core="fir_20_2ch_ast" >
// Retrieval info:   <STATIC_SECTION>
// Retrieval info:    <PRIVATES>
// Retrieval info:     <NAMESPACE name = "parameterization">
// Retrieval info:      <PRIVATE name = "use_mem" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "mem_type" value="M512"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_rate" value="Decimation"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_factor" value="20"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_type" value="Signed Binary Fractional"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="1.6777216E7"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="25"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Actual Coefficients"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="32"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_lsb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_msb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_input" value="Slave Sink"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_output" value="Master Source"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "device_family" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "structure" value="Variable/Fixed Coefficient : Multi-Cycle"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "pipeline_level" value="3"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "clocks_to_compute" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_serial_units" value="2"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "data_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "multiplier_storage" value="DSP Blocks"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 959, 1920000.0, 42500.0, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.03764E-6, -1.43606E-6, -1.85244E-6, -2.27683E-6, -2.69799E-6, -3.10356E-6, -3.48037E-6, -3.81475E-6, -4.09285E-6, -4.30102E-6, -4.42625E-6, -4.45655E-6, -4.38138E-6, -4.19204E-6, -3.88208E-6, -3.44765E-6, -2.88779E-6, -2.20468E-6, -1.40388E-6, 0.0, 0.0, 1.5975E-6, 2.74478E-6, 3.93104E-6, 5.13139E-6, 6.31867E-6, 7.46397E-6, 8.53722E-6, 9.50786E-6, 1.03455E-5, 1.10207E-5, 1.15059E-5, 1.17758E-5, 1.18085E-5, 1.15861E-5, 1.10955E-5, 1.03287E-5, 9.28373E-6, 7.9647E-6, 6.38236E-6, 4.55409E-6, 2.504E-6, 0.0, -2.13284E-6, -4.64008E-6, -7.21121E-6, -9.79413E-6, -1.23333E-5, -1.47709E-5, -1.70478E-5, -1.91051E-5, -2.08851E-5, -2.23331E-5, -2.33985E-5, -2.4036E-5, -2.42073E-5, -2.38822E-5, -2.30395E-5, -2.16679E-5, -1.97673E-5, -1.73488E-5, -1.44355E-5, -1.1062E-5, -7.27508E-6, -3.13257E-6, 1.29698E-6, 5.93534E-6, 1.06958E-5, 1.54847E-5, 2.02029E-5, 2.47479E-5, 2.90158E-5, 3.29034E-5, 3.63104E-5, 3.91421E-5, 4.13109E-5, 4.27394E-5, 4.33618E-5, 4.31265E-5, 4.19972E-5, 3.99549E-5, 3.69988E-5, 3.31472E-5, 2.84382E-5, 2.29292E-5, 1.66974E-5, 9.83839E-6, 2.46512E-6, -5.29363E-6, -1.32953E-5, -2.1386E-5, -2.94033E-5, -3.7179E-5, -4.45427E-5, -5.13254E-5, -5.73625E-5, -6.24981E-5, -6.65882E-5, -6.95043E-5, -7.1137E-5, -7.13986E-5, -7.02262E-5, -6.75837E-5, -6.3464E-5, -5.78901E-5, -5.09159E-5, -4.26263E-5, -3.31366E-5, -2.25915E-5, -1.11632E-5, 0.0, 1.35326E-5, 2.63439E-5, 3.91336E-5, 5.16413E-5, 6.36017E-5, 7.47509E-5, 8.48311E-5, 9.35967E-5, 1.00819E-4, 1.06294E-4, 1.09842E-4, 1.1132E-4, 1.10619E-4, 1.07671E-4, 1.02453E-4, 9.49843E-5, 8.53331E-5, 7.36136E-5, 5.99866E-5, 4.46571E-5, 2.78727E-5, 9.91914E-6, -8.88377E-6, -2.81874E-5, -4.76206E-5, -6.67964E-5, -8.53193E-5, -1.02793E-4, -1.18829E-4, -1.33053E-4, -1.45116E-4, -1.547E-4, -1.61526E-4, -1.65362E-4, -1.66026E-4, -1.63397E-4, -1.57415E-4, -1.48085E-4, -1.35481E-4, -1.19746E-4, -1.0109E-4, -7.97882E-5, -5.61801E-5, -3.0662E-5, -3.68216E-6, 2.42671E-5, 5.26576E-5, 8.09351E-5, 1.08529E-4, 1.34866E-4, 1.59376E-4, 1.8151E-4, 2.00748E-4, 2.16612E-4, 2.28677E-4, 2.3658E-4, 2.40029E-4, 2.38816E-4, 2.32816E-4, 2.21998E-4, 2.06428E-4, 1.86267E-4, 1.61774E-4, 1.33304E-4, 1.01302E-4, 6.62967E-5, 2.88949E-5, -1.02308E-5, -5.0353E-5, -9.07015E-5, -1.30479E-4, -1.68874E-4, -2.0508E-4, -2.3831E-4, -2.67811E-4, -2.92884E-4, -3.12896E-4, -3.27299E-4, -3.35639E-4, -3.37571E-4, -3.32865E-4, -3.21421E-4, -3.03268E-4, -2.78571E-4, -2.47631E-4, -2.10881E-4, -1.68882E-4, -1.2232E-4, -7.19862E-5, -1.87744E-5, 3.63407E-5, 9.23184E-5, 1.48071E-4, 2.02484E-4, 2.54439E-4, 3.02833E-4, 3.46606E-4, 3.84758E-4, 4.16372E-4, 4.4064E-4, 4.56872E-4, 4.64524E-4, 4.63204E-4, 4.52689E-4, 4.32934E-4, 4.04076E-4, 3.66436E-4, 3.20518E-4, 2.67008E-4, 2.06757E-4, 1.40777E-4, 7.02187E-5, -3.64312E-6, -7.94345E-5, -1.55706E-4, -2.30959E-4, -3.03677E-4, -3.7235E-4, -4.35509E-4, -4.91759E-4, -5.39799E-4, -5.7846E-4, -6.06729E-4, -6.23769E-4, -6.28948E-4, -6.21848E-4, -6.02287E-4, -5.70325E-4, -5.26268E-4, -4.7067E-4, -4.0433E-4, -3.28278E-4, -2.43766E-4, -1.52245E-4, -5.53415E-5, 4.51686E-5, 1.47392E-4, 2.49353E-4, 3.4903E-4, 4.44395E-4, 5.33453E-4, 6.14284E-4, 6.8508E-4, 7.44188E-4, 7.90141E-4, 8.21697E-4, 8.37867E-4, 8.3794E-4, 8.21508E-4, 7.88475E-4, 7.39075E-4, 6.73867E-4, 5.93741E-4, 4.999E-4, 3.93851E-4, 2.77379E-4, 1.52519E-4, 2.15223E-5, -1.13181E-4, -2.49027E-4, -3.83368E-4, -5.13516E-4, -6.36803E-4, -7.50626E-4, -8.52508E-4, -9.40143E-4, -0.00101145, -0.00106462, -0.00109815, -0.0011109, -0.0011021, -0.00107139, -0.00101882, -9.44905E-4, -8.50559E-4, -7.37136E-4, -6.06398E-4, -4.6049E-4, -3.01909E-4, -1.33463E-4, 4.17789E-5, 2.20535E-4, 3.99375E-4, 5.74784E-4, 7.43226E-4, 9.01217E-4, 0.00104539, 0.00117257, 0.00127984, 0.00136459, 0.00142461, 0.00145809, 0.00146374, 0.00144074, 0.00138884, 0.00130834, 0.00120012, 0.00106561, 9.06806E-4, 7.2622E-4, 5.26858E-4, 3.12166E-4, 8.59799E-5, -1.47548E-4, -3.84015E-4, -6.18854E-4, -8.47415E-4, -0.00106505, -0.00126722, -0.00144957, -0.00160801, -0.00173885, -0.0018388, -0.00190513, -0.00193569, -0.00192896, -0.00188413, -0.0018011, -0.00168053, -0.0015238, -0.00133306, -0.00111118, -8.61693E-4, -5.8877E-4, -2.9715E-4, 7.94373E-6, 3.20888E-4, 6.35761E-4, 9.46449E-4, 0.00124676, 0.00153054, 0.00179179, 0.0020248, 0.00222426, 0.00238535, 0.0025039, 0.00257643, 0.00260026, 0.0025736, 0.00249557, 0.00236629, 0.00218686, 0.00195938, 0.00168696, 0.00137364, 0.00102438, 6.44983E-4, 2.41986E-4, -1.77427E-4, -6.05548E-4, -0.00103428, -0.00145528, -0.0018601, -0.00224039, -0.00258798, -0.00289513, -0.00315461, -0.00335993, -0.00350541, -0.00358636, -0.00359918, -0.00354149, -0.00341214, -0.00321136, -0.00294074, -0.00260325, -0.00220323, -0.00174637, -0.00123962, -6.91108E-4, -1.10043E-4, 4.93451E-4, 0.00110847, 0.00172353, 0.00232672, 0.00290595, 0.00344917, 0.00394453, 0.00438068, 0.00474697, 0.00503363, 0.00523203, 0.00533487, 0.00533632, 0.00523221, 0.00502018, 0.00469975, 0.00427243, 0.00374174, 0.00311325, 0.00239456, 0.00159522, 7.26701E-4, -1.97812E-4, -0.0011635, -0.00215413, -0.00315227, -0.00413949, -0.00509668, -0.0060043, -0.00684266, -0.00759225, -0.00823405, -0.0087498, -0.00912236, -0.00933598, -0.00937656, -0.00923196, -0.00889218, -0.00834964, -0.00759928, -0.00663878, -0.0054686, -0.0040921, -0.00251553, -7.48E-4, 0.00119853, 0.00330939, 0.00556737, 0.00795285, 0.0104441, 0.0130174, 0.0156475, 0.0183078, 0.0209709, 0.0236086, 0.0261926, 0.0286948, 0.0310875, 0.033344, 0.0354389, 0.0373483, 0.0390504, 0.0405255, 0.0417566, 0.0427293, 0.0434324, 0.0438576, 0.0439999, 0.0438576, 0.0434324, 0.0427293, 0.0417566, 0.0405255, 0.0390504, 0.0373483, 0.0354389, 0.033344, 0.0310875, 0.0286948, 0.0261926, 0.0236086, 0.0209709, 0.0183078, 0.0156475, 0.0130174, 0.0104441, 0.00795285, 0.00556737, 0.00330939, 0.00119853, -7.48E-4, -0.00251553, -0.0040921, -0.0054686, -0.00663878, -0.00759928, -0.00834964, -0.00889218, -0.00923196, -0.00937656, -0.00933598, -0.00912236, -0.0087498, -0.00823405, -0.00759225, -0.00684266, -0.0060043, -0.00509668, -0.00413949, -0.00315227, -0.00215413, -0.0011635, -1.97812E-4, 7.26701E-4, 0.00159522, 0.00239456, 0.00311325, 0.00374174, 0.00427243, 0.00469975, 0.00502018, 0.00523221, 0.00533632, 0.00533487, 0.00523203, 0.00503363, 0.00474697, 0.00438068, 0.00394453, 0.00344917, 0.00290595, 0.00232672, 0.00172353, 0.00110847, 4.93451E-4, -1.10043E-4, -6.91108E-4, -0.00123962, -0.00174637, -0.00220323, -0.00260325, -0.00294074, -0.00321136, -0.00341214, -0.00354149, -0.00359918, -0.00358636, -0.00350541, -0.00335993, -0.00315461, -0.00289513, -0.00258798, -0.00224039, -0.0018601, -0.00145528, -0.00103428, -6.05548E-4, -1.77427E-4, 2.41986E-4, 6.44983E-4, 0.00102438, 0.00137364, 0.00168696, 0.00195938, 0.00218686, 0.00236629, 0.00249557, 0.0025736, 0.00260026, 0.00257643, 0.0025039, 0.00238535, 0.00222426, 0.0020248, 0.00179179, 0.00153054, 0.00124676, 9.46449E-4, 6.35761E-4, 3.20888E-4, 7.94373E-6, -2.9715E-4, -5.8877E-4, -8.61693E-4, -0.00111118, -0.00133306, -0.0015238, -0.00168053, -0.0018011, -0.00188413, -0.00192896, -0.00193569, -0.00190513, -0.0018388, -0.00173885, -0.00160801, -0.00144957, -0.00126722, -0.00106505, -8.47415E-4, -6.18854E-4, -3.84015E-4, -1.47548E-4, 8.59799E-5, 3.12166E-4, 5.26858E-4, 7.2622E-4, 9.06806E-4, 0.00106561, 0.00120012, 0.00130834, 0.00138884, 0.00144074, 0.00146374, 0.00145809, 0.00142461, 0.00136459, 0.00127984, 0.00117257, 0.00104539, 9.01217E-4, 7.43226E-4, 5.74784E-4, 3.99375E-4, 2.20535E-4, 4.17789E-5, -1.33463E-4, -3.01909E-4, -4.6049E-4, -6.06398E-4, -7.37136E-4, -8.50559E-4, -9.44905E-4, -0.00101882, -0.00107139, -0.0011021, -0.0011109, -0.00109815, -0.00106462, -0.00101145, -9.40143E-4, -8.52508E-4, -7.50626E-4, -6.36803E-4, -5.13516E-4, -3.83368E-4, -2.49027E-4, -1.13181E-4, 2.15223E-5, 1.52519E-4, 2.77379E-4, 3.93851E-4, 4.999E-4, 5.93741E-4, 6.73867E-4, 7.39075E-4, 7.88475E-4, 8.21508E-4, 8.3794E-4, 8.37867E-4, 8.21697E-4, 7.90141E-4, 7.44188E-4, 6.8508E-4, 6.14284E-4, 5.33453E-4, 4.44395E-4, 3.4903E-4, 2.49353E-4, 1.47392E-4, 4.51686E-5, -5.53415E-5, -1.52245E-4, -2.43766E-4, -3.28278E-4, -4.0433E-4, -4.7067E-4, -5.26268E-4, -5.70325E-4, -6.02287E-4, -6.21848E-4, -6.28948E-4, -6.23769E-4, -6.06729E-4, -5.7846E-4, -5.39799E-4, -4.91759E-4, -4.35509E-4, -3.7235E-4, -3.03677E-4, -2.30959E-4, -1.55706E-4, -7.94345E-5, -3.64312E-6, 7.02187E-5, 1.40777E-4, 2.06757E-4, 2.67008E-4, 3.20518E-4, 3.66436E-4, 4.04076E-4, 4.32934E-4, 4.52689E-4, 4.63204E-4, 4.64524E-4, 4.56872E-4, 4.4064E-4, 4.16372E-4, 3.84758E-4, 3.46606E-4, 3.02833E-4, 2.54439E-4, 2.02484E-4, 1.48071E-4, 9.23184E-5, 3.63407E-5, -1.87744E-5, -7.19862E-5, -1.2232E-4, -1.68882E-4, -2.10881E-4, -2.47631E-4, -2.78571E-4, -3.03268E-4, -3.21421E-4, -3.32865E-4, -3.37571E-4, -3.35639E-4, -3.27299E-4, -3.12896E-4, -2.92884E-4, -2.67811E-4, -2.3831E-4, -2.0508E-4, -1.68874E-4, -1.30479E-4, -9.07015E-5, -5.0353E-5, -1.02308E-5, 2.88949E-5, 6.62967E-5, 1.01302E-4, 1.33304E-4, 1.61774E-4, 1.86267E-4, 2.06428E-4, 2.21998E-4, 2.32816E-4, 2.38816E-4, 2.40029E-4, 2.3658E-4, 2.28677E-4, 2.16612E-4, 2.00748E-4, 1.8151E-4, 1.59376E-4, 1.34866E-4, 1.08529E-4, 8.09351E-5, 5.26576E-5, 2.42671E-5, -3.68216E-6, -3.0662E-5, -5.61801E-5, -7.97882E-5, -1.0109E-4, -1.19746E-4, -1.35481E-4, -1.48085E-4, -1.57415E-4, -1.63397E-4, -1.66026E-4, -1.65362E-4, -1.61526E-4, -1.547E-4, -1.45116E-4, -1.33053E-4, -1.18829E-4, -1.02793E-4, -8.53193E-5, -6.67964E-5, -4.76206E-5, -2.81874E-5, -8.88377E-6, 9.91914E-6, 2.78727E-5, 4.46571E-5, 5.99866E-5, 7.36136E-5, 8.53331E-5, 9.49843E-5, 1.02453E-4, 1.07671E-4, 1.10619E-4, 1.1132E-4, 1.09842E-4, 1.06294E-4, 1.00819E-4, 9.35967E-5, 8.48311E-5, 7.47509E-5, 6.36017E-5, 5.16413E-5, 3.91336E-5, 2.63439E-5, 1.35326E-5, 0.0, -1.11632E-5, -2.25915E-5, -3.31366E-5, -4.26263E-5, -5.09159E-5, -5.78901E-5, -6.3464E-5, -6.75837E-5, -7.02262E-5, -7.13986E-5, -7.1137E-5, -6.95043E-5, -6.65882E-5, -6.24981E-5, -5.73625E-5, -5.13254E-5, -4.45427E-5, -3.7179E-5, -2.94033E-5, -2.1386E-5, -1.32953E-5, -5.29363E-6, 2.46512E-6, 9.83839E-6, 1.66974E-5, 2.29292E-5, 2.84382E-5, 3.31472E-5, 3.69988E-5, 3.99549E-5, 4.19972E-5, 4.31265E-5, 4.33618E-5, 4.27394E-5, 4.13109E-5, 3.91421E-5, 3.63104E-5, 3.29034E-5, 2.90158E-5, 2.47479E-5, 2.02029E-5, 1.54847E-5, 1.06958E-5, 5.93534E-6, 1.29698E-6, -3.13257E-6, -7.27508E-6, -1.1062E-5, -1.44355E-5, -1.73488E-5, -1.97673E-5, -2.16679E-5, -2.30395E-5, -2.38822E-5, -2.42073E-5, -2.4036E-5, -2.33985E-5, -2.23331E-5, -2.08851E-5, -1.91051E-5, -1.70478E-5, -1.47709E-5, -1.23333E-5, -9.79413E-6, -7.21121E-6, -4.64008E-6, -2.13284E-6, 0.0, 2.504E-6, 4.55409E-6, 6.38236E-6, 7.9647E-6, 9.28373E-6, 1.03287E-5, 1.10955E-5, 1.15861E-5, 1.18085E-5, 1.17758E-5, 1.15059E-5, 1.10207E-5, 1.03455E-5, 9.50786E-6, 8.53722E-6, 7.46397E-6, 6.31867E-6, 5.13139E-6, 3.93104E-6, 2.74478E-6, 1.5975E-6, 0.0, 0.0, -1.40388E-6, -2.20468E-6, -2.88779E-6, -3.44765E-6, -3.88208E-6, -4.19204E-6, -4.38138E-6, -4.45655E-6, -4.42625E-6, -4.30102E-6, -4.09285E-6, -3.81475E-6, -3.48037E-6, -3.10356E-6, -2.69799E-6, -2.27683E-6, -1.85244E-6, -1.43606E-6, -1.03764E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="57"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="55"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="25"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="729"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m512" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m4k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m144k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m9k" value="10"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m20k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "mlab" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "megaram" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "dsp_block" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_clock_period" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_clock_period" value="480"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "throughput" value="480"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "memory_units" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen_enable">
// Retrieval info:      <PRIVATE name = "matlab_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_simulation_clock_period" value="10.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "language" value="Verilog HDL"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "enabled" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen">
// Retrieval info:      <PRIVATE name = "filename" value="fir_20_2ch.vo"  type="STRING"  enable="1" />
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
