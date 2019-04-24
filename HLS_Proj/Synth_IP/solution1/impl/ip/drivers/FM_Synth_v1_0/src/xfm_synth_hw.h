// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.2
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// CTRL_BUS
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of press
//        bit 31~0 - press[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of modulator_wave
//        bit 31~0 - modulator_wave[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of modulator_phase
//        bit 31~0 - modulator_phase[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of scale_factor
//        bit 31~0 - scale_factor[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of carrier_wave
//        bit 31~0 - carrier_wave[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of carrier_phase
//        bit 31~0 - carrier_phase[31:0] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of user_writing
//        bit 31~0 - user_writing[31:0] (Read/Write)
// 0x44 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFM_SYNTH_CTRL_BUS_ADDR_PRESS_DATA           0x10
#define XFM_SYNTH_CTRL_BUS_BITS_PRESS_DATA           32
#define XFM_SYNTH_CTRL_BUS_ADDR_MODULATOR_WAVE_DATA  0x18
#define XFM_SYNTH_CTRL_BUS_BITS_MODULATOR_WAVE_DATA  32
#define XFM_SYNTH_CTRL_BUS_ADDR_MODULATOR_PHASE_DATA 0x20
#define XFM_SYNTH_CTRL_BUS_BITS_MODULATOR_PHASE_DATA 32
#define XFM_SYNTH_CTRL_BUS_ADDR_SCALE_FACTOR_DATA    0x28
#define XFM_SYNTH_CTRL_BUS_BITS_SCALE_FACTOR_DATA    32
#define XFM_SYNTH_CTRL_BUS_ADDR_CARRIER_WAVE_DATA    0x30
#define XFM_SYNTH_CTRL_BUS_BITS_CARRIER_WAVE_DATA    32
#define XFM_SYNTH_CTRL_BUS_ADDR_CARRIER_PHASE_DATA   0x38
#define XFM_SYNTH_CTRL_BUS_BITS_CARRIER_PHASE_DATA   32
#define XFM_SYNTH_CTRL_BUS_ADDR_USER_WRITING_DATA    0x40
#define XFM_SYNTH_CTRL_BUS_BITS_USER_WRITING_DATA    32
