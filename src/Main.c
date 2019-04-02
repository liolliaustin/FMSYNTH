#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

int main(int argc, char * argv[]) {

	if (argc != 8){
		printf("ERROR: Not Enough Arguments\n");
		return(-1);
	}

	float A[] = {
		#include "../WaveData/A2.txt"
	};
	float A_Sharp[] = {
		#include "../WaveData/A#2.txt"
	};
	float B[] = {
		#include "../WaveData/B2.txt"
	};
	float C[] = {
		#include "../WaveData/C3.txt"
	};
	float C_Sharp[] = {
		#include "../WaveData/C#3.txt"
	};
	float D[] = {
		#include "../WaveData/D3.txt"
	};
	float D_Sharp[] = {
		#include "../WaveData/D#3.txt"
	};
	float E[] = {
		#include "../WaveData/E3.txt"
	};
	float F[] = {
		#include "../WaveData/F3.txt"
	};
	float F_Sharp[] = {
		#include "../WaveData/F#3.txt"
	};
	float G[] = {
		#include "../WaveData/G3.txt"
	};
	float G_Sharp[] = {
		#include "../WaveData/G#3.txt"
	};

	float A_conversion = 1/0.01439896633;
	float A_Sharp_conversion = 1/0.01525505033;
	float B_conversion = 1/0.01616228993;
	float C_conversion = 1/0.01712453358;
	float C_Sharp_conversion = 1/0.01814138858;
	float D_conversion = 1/0.01922031621;
	float D_Sharp_conversion = 1/0.02036321453;
	float E_conversion = 1/0.02157407597;
	float F_conversion = 1/0.02285693224;
	float F_Sharp_conversion = 1/0.02421607685;
	float G_conversion = 1/0.02565603894;
	float G_Sharp_conversion = 1/0.02718162251;

	float * carrier_wave[];
	float * modulator_wave[];
	float modulator_conversion;
	float carrier_conversion;

	float mod_octave = argv[2];
	float mod_phase = atof(argv[3]);
	float scale_factor = atof(argv[4]);
	float car_octave = argv[6];
	float car_phase = atof(argv[7]);

	//Modulator Wave Definition

	if(argv[1] == 'A'){
		modulator_wave = A;
		modulator_conversion = A_conversion;
	}

	else if(argv[1] == 'A#' || argv[1] == 'Bb'){
		modulator_wave = A_Sharp;
		modulator_conversion = A_Sharp_conversion;
	}

	else if(argv[1] == 'B'){
		modulator_wave = B;
		modulator_conversion = B_conversion;
	}

	else if(argv[1] == 'C'){
		modulator_wave = C;
		modulator_conversion = C_conversion;
	}

	else if(argv[1] == 'C#' || argv[1] == 'Db'){
		modulator_wave = C_Sharp;
		modulator_conversion = C_Sharp_conversion;
	}

	else if(argv[1] == 'D'){
		modulator_wave = D;
		modulator_conversion = D_conversion;
	}

	else if(argv[1] == 'D#' || argv[1] == 'Eb'){
		modulator_wave = D_Sharp;
		modulator_conversion = D_Sharp_conversion;
	}

	else if(argv[1] == 'E'){
		modulator_wave = E;
		modulator_conversion = E_conversion;
	}

	else if(argv[1] == 'F'){
		modulator_wave = F;
		modulator_conversion = F_conversion;
	}

	else if(argv[1] == 'F#' || argv[1] == 'Gb'){
		modulator_wave = F_Sharp;
		modulator_conversion = F_Sharp_conversion;
	}

	else if(argv[1] == 'G'){
		modulator_wave = G;
		modulator_conversion = G_conversion;
	}

	else if(argv[1] == 'G#' || argv[1] == 'Ab'){
		modulator_wave = G_Sharp;
		modulator_conversion = G_Sharp_conversion;
	}

	//Carrier Wave Definition

	if(argv[5] == 'A'){
		carrier_wave = A;
		carrier_conversion = A_conversion;
	}

	else if(argv[5] == 'A#' || argv[5] == 'Bb'){
		carrier_wave = A_Sharp;
		carrier_conversion = A_Sharp_conversion;
	}

	else if(argv[5] == 'B'){
		carrier_wave = B;
		carrier_conversion = B_conversion;
	}

	else if(argv[5] == 'C'){
		carrier_wave = C;
		carrier_conversion = C_conversion;
	}

	else if(argv[5] == 'C#' || argv[5] == 'Db'){
		carrier_wave = C_Sharp;
		carrier_conversion = C_Sharp_conversion;
	}

	else if(argv[5] == 'D'){
		carrier_wave = D;
		carrier_conversion = D_conversion;
	}

	else if(argv[5] == 'D#' || argv[5] == 'Eb'){
		carrier_wave = D_Sharp;
		carrier_conversion = D_Sharp_conversion;
	}

	else if(argv[5] == 'E'){
		carrier_wave = E;
		carrier_conversion = E_conversion;
	}

	else if(argv[5] == 'F'){
		carrier_wave = F;
		carrier_conversion = F_conversion;
	}

	else if(argv[5] == 'F#' || argv[5] == 'Gb'){
		carrier_wave = F_Sharp;
		carrier_conversion = F_Sharp_conversion;
	}

	else if(argv[5] == 'G'){
		carrier_wave = G;
		carrier_conversion = G_conversion;
	}

	else if(argv[5] == 'G#' || argv[5] == 'Ab'){
		carrier_wave = G_Sharp;
		carrier_conversion = G_Sharp_conversion;
	}

	FM_Synth(modulator_wave, mod_octave, mod_phase, modulator_conversion, scale_factor, carrier_wave, car_octave, car_phase, carrier_conversion); 

	return 0;
}