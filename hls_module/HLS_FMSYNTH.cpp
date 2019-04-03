#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <hls_stream.h>
#include "HLS_FMSYNTH.h"

void FM_Synth(

	hls::stream<float> & result,

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

){

#pragma HLS PIPELINE II=1
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=modulator_wave bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=modulator_phase bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=scale_factor bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=carrier_wave bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=carrier_phase bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=sync bundle=CTRL_BUS

#pragma HLS INTERFACE axis register both port=result

	static int position = 0;
	static int change = 1;

	static float * carrier_wave_values;
	static float * modulator_wave_values;
	static float modulator_conversion;
	static float carrier_conversion;

	static int mod_octave;
	static int car_octave;
	static int mod_size;
	static int car_size;

	static int attackSlope;
	static int decaySlope;
	static int releaseSlope;


	if (sync == 0){
		change = 1;
		return;
	}

	if (change == 1){

		mod_octave = 1 + modulator_wave/12;
		car_octave = 1 + carrier_wave/12;

		mod_size = sizes[modulator_wave%12];
		car_size = sizes[carrier_wave%12];

		//Carrier Wave Definition
		carrier_wave_values = notes[carrier_wave%12];
		carrier_conversion = Conversion[carrier_wave%12];

		//Modulator Wave Definition
		modulator_wave_values = notes[modulator_wave%12];
		modulator_conversion = Conversion[modulator_wave%12];

		position = 0;

		attackSlope = attackMaximum/attackDuration;
		decaySlope = (sustainAmplitude - MAX_ATTACK)/(decayDuration - attackDuration);
		releaseSlope = (-1)*sustainAmplitude/(releaseDuration - sustainDuration);

	}

	if(press == 1){
		sustainDuration += 1;
		releaseDuration += 1;
	}

	int amplitude = envelope(position, attackSlope, attackDuration, decaySlope, decayDuration, sustainAmplitude, sustainDuration, releaseSlope, releaseDuration);

	float modWaveResult, carrierWaveResult, cartest;
	int modRead, carRead;

	modRead = (int)ceil((mod_octave*(modulator_conversion*modulator_phase + position)))%mod_size;

	modWaveResult = modulator_wave_values[modRead];

	carRead = (int)ceil(car_octave*(scale_factor*modWaveResult*carrier_conversion + carrier_conversion*carrier_phase + position))%car_size;

	result << amplitude*carrier_wave_values[carRead];

	position++;

	change = 0;


}

//Duration variables are the time relative to 0 that portion of the envelope no longer used
//	ex) attackDuration = 4, decayDuration = 8, sustainDuration = 20, decayDuration = 25
//	
//	in actual time => decay duration is 4 samples long, sustain duration is 12 samples and decay duration is 5 samples
//
//Attack and sustain maximum values can not exceed **** in amplitude

int envelope(

	int time,
	int attackSlope, 
	int attackDuration, 
	int decaySlope, 
	int decayDuration, 
	int sustainAmplitude, 
	int sustainDuration, 
	int releaseSlope, 
	int releaseDuration

){

	int resultAmplitude;

	if(time < attackDuration){
		resultAmplitude = attackSlope*time;
	}

	else if(time < decayDuration){
		resultAmplitude =  decaySlope*attackDuration + attackSlope*attackDuration - decaySlope*time;
	}

	else if( time < sustainDuration){
		resultAmplitude = sustainAmplitude;
	}

	else if(time < releaseDuration){
		resultAmplitude = releaseSlope*sustainDuration + sustainAmplitude - releaseSlope*time;
	}

	else {
		resultAmplitude = 0;
	}

	return resultAmplitude;
}

