// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.2
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xfm_synth.h"

extern XFm_synth_Config XFm_synth_ConfigTable[];

XFm_synth_Config *XFm_synth_LookupConfig(u16 DeviceId) {
	XFm_synth_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XFM_SYNTH_NUM_INSTANCES; Index++) {
		if (XFm_synth_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XFm_synth_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XFm_synth_Initialize(XFm_synth *InstancePtr, u16 DeviceId) {
	XFm_synth_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XFm_synth_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XFm_synth_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif
