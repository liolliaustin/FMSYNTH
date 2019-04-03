// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.2
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XFM_SYNTH_H
#define XFM_SYNTH_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xfm_synth_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Ctrl_bus_BaseAddress;
} XFm_synth_Config;
#endif

typedef struct {
    u32 Ctrl_bus_BaseAddress;
    u32 IsReady;
} XFm_synth;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XFm_synth_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XFm_synth_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XFm_synth_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XFm_synth_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XFm_synth_Initialize(XFm_synth *InstancePtr, u16 DeviceId);
XFm_synth_Config* XFm_synth_LookupConfig(u16 DeviceId);
int XFm_synth_CfgInitialize(XFm_synth *InstancePtr, XFm_synth_Config *ConfigPtr);
#else
int XFm_synth_Initialize(XFm_synth *InstancePtr, const char* InstanceName);
int XFm_synth_Release(XFm_synth *InstancePtr);
#endif


void XFm_synth_Set_modulator_wave(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_modulator_wave(XFm_synth *InstancePtr);
void XFm_synth_Set_modulator_phase(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_modulator_phase(XFm_synth *InstancePtr);
void XFm_synth_Set_scale_factor(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_scale_factor(XFm_synth *InstancePtr);
void XFm_synth_Set_carrier_wave(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_carrier_wave(XFm_synth *InstancePtr);
void XFm_synth_Set_carrier_phase(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_carrier_phase(XFm_synth *InstancePtr);
void XFm_synth_Set_sync(XFm_synth *InstancePtr, u32 Data);
u32 XFm_synth_Get_sync(XFm_synth *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif