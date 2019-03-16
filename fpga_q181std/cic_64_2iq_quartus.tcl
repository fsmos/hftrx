## ================================================================================
## Legal Notice: Copyright (C) 1991-2008 Altera Corporation
## Any megafunction design, and related net list (encrypted or decrypted),
## support information, device programming or simulation file, and any other
## associated documentation or information provided by Altera or a partner
## under Altera's Megafunction Partnership Program may be used only to
## program PLD devices (but not masked PLD devices) from Altera.  Any other
## use of such megafunction design, net list, support information, device
## programming or simulation file, or any other related documentation or
## information is prohibited for any other purpose, including, but not
## limited to modification, reverse engineering, de-compiling, or use with
## any other silicon devices, unless such use is explicitly licensed under
## a separate agreement with Altera or a megafunction partner.  Title to
## the intellectual property, including patents, copyrights, trademarks,
## trade secrets, or maskworks, embodied in any such megafunction design,
## net list, support information, device programming or simulation file, or
## any other related documentation or information provided by Altera or a
## megafunction partner, remains with Altera, the megafunction partner, or
## their respective licensors.  No other licenses, including any licenses
## needed under any third party's intellectual property, are provided herein.
## ================================================================================
##

## Generated by: CIC 13.1 Build 182 October, 2013
## Generated on: Feb 3, 2019 3:38:49 AM

package require ::quartus::project
package require ::quartus::flow
package require ::quartus::misc

project_new -overwrite -family "Cyclone IV E" cic_64_2iq
set_global_assignment -name SAVE_DISK_SPACE OFF
set_global_assignment -name FMAX_REQUIREMENT "350 MHz"
set_global_assignment -name DEVICE AUTO
set_global_assignment -name SPEED_DISK_USAGE_TRADEOFF SMART

set_global_assignment -name "USER_LIBRARIES"  c:/altera/13.1/ip/altera/cic/lib//

set_global_assignment -name "VHDL_FILE"  cic_64_2iq.vhd
set_global_assignment -name "VHDL_FILE"  cic_64_2iq_cic.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_cic_lib_pkg_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_differentiator_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_downsample_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_variable_downsample_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_integrator_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_upsample_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_math_pkg_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_lib_pkg_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_delay_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_fastadd_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_fastaddsub_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_avalon_streaming_sink_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_avalon_streaming_source_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_avalon_streaming_controller_cic_131.vhd
set_global_assignment -name "VHDL_FILE"  c:/altera/13.1/ip/altera/cic/lib//auk_dspip_roundsat_cic_131.vhd

execute_flow -compile
