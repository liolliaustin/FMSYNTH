############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project HLS_FMSYNTH
set_top FM_Synth
add_files ../hls_module/HLS_FMSYNTH.cpp
add_files ../hls_module/HLS_FMSYNTH.h
open_solution "solution1"
set_part {xc7z100ffg900-2}
create_clock -period 10 -name default
#source "./HLS_FMSYNTH/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
