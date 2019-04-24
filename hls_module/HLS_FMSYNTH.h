#ifndef __HLS_FMSYNTH_INCLUDED__
#define __HLS_FMSYNTH_INCLUDED__

#include <hls_stream.h>

void FM_Synth(

	hls::stream<float> & result,

	int press,
	int modulator_wave, 
	float modulator_phase, 
	float scale_factor,
	int carrier_wave, 
	float carrier_phase,
	int sync

);


#endif
