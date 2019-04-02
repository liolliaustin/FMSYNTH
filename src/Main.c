#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

// inputs order
// 1) Modulator Wave Int (integer)
// 2) Modulator Wave Phase (radians)
// 3) Scale Factor (integer)
// 4) Carrier Wave Int (integer)
// 5) Carrier Wave Phase (radians)

int main(int argc, char * argv[]) {

	if (argc != 6){
		printf("ERROR: Not Enough Arguments\n");
		return(-1);
	}

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

	float * carrier_wave;
	float * modulator_wave;
	float modulator_conversion;
	float carrier_conversion;

	float carrier_phase = atoi(argv[5]);
	float modulator_phase = atoi(argv[2]);
	float scale_factor = atoi(argv[3]);

	int mod_octave = 1 + atoi(argv[1])/12;
	int car_octave = 1 + atoi(argv[4])/12;

	int mod_size = sizes[atoi(argv[1])%12];
	int car_size = sizes[atoi(argv[4])%12];

	//Carrier Wave Definition
	carrier_wave = notes[atoi(argv[4])%12];
	carrier_conversion = Conversion[atoi(argv[4])%12];

	//Modulator Wave Definition
	modulator_wave = notes[atoi(argv[1])%12];
	modulator_conversion = Conversion[atoi(argv[1])%12];

	FM_Synth(modulator_wave, mod_octave, modulator_phase, modulator_conversion, mod_size, scale_factor, carrier_wave, car_octave, carrier_phase, carrier_conversion, car_size); 

	return 0;
}