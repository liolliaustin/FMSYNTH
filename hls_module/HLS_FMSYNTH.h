#ifndef __HLS_FMSYNTH_INCLUDED__
#define __HLS_FMSYNTH_INCLUDED__

int MAX_ATTACK = 2;

float notes[][437] = {

		{
			#include "../WaveData/A2.txt"
		},
		{
			#include "../WaveData/A#2.txt"
		},
		{
			#include "../WaveData/B2.txt"
		},
		{
			#include "../WaveData/C3.txt"
		},
		{
			#include "../WaveData/C#3.txt"
		},
		{
			#include "../WaveData/D3.txt"
		},
		{
			#include "../WaveData/D#3.txt"
		},
		{
			#include "../WaveData/E3.txt"
		},
		{
			#include "../WaveData/F3.txt"
		},
		{
			#include "../WaveData/F#3.txt"
		},
		{
			#include "../WaveData/G3.txt"
		},
		{
			#include "../WaveData/G#3.txt"
		}
	};

float Conversion[] = {1/0.01439896633, 1/0.01525505033, 1/0.01616228993, 1/0.01712453358, 1/0.01814138858, 1/0.01922031621, 1/0.02036321453, 1/0.02157407597,
				 1/0.02285693224, 1/0.02421607685, 1/0.02565603894, 1/0.02718162251};

int sizes[] = {437,412,389,367,347,327,309,292,275,260,245,232};


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
	int sustainAmplitude, 
	int sustainDuration, 
	int releaseDuration

);

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

);

#endif
