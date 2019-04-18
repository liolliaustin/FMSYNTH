#ifndef __HLS_FMSYNTH_INCLUDED__
#define __HLS_FMSYNTH_INCLUDED__

#include <hls_stream.h>

void FM_Synth(

	hls::stream<float> & result,
	//hls::stream<float> & newNote,

	int press,
	int modulator_wave, 
	float modulator_phase, 
	float scale_factor,
	int carrier_wave, 
	float carrier_phase,
	int sync,
	int attackMaximum, 
	int attackDuration,
	int decayDuration, 
	int sustainAmplitude, 
	int sustainDuration,
	int releaseDuration

);

float envelope(

	int time,
	float attackSlope,
	int attackDuration, 
	float decaySlope,
	int decayDuration, 
	int sustainAmplitude, 
	int sustainDuration, 
	float releaseSlope,
	int releaseDuration

);

#endif
