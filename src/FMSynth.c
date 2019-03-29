#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

void FM_Synth(float mod_freq, float mod_phase, float scale_factor, float car_freq, float car_phase){

	FILE *f = fopen("outresult.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}


	float A2[] = {
		#include "../WaveData/A2.txt"
	};
	float A_Sharp_2[] = {
		#include "../WaveData/A#2.txt"
	};
	float B2[] = {
		#include "../WaveData/B2.txt"
	};
	float C3[] = {
		#include "../WaveData/C3.txt"
	};
	float C_Sharp_3[] = {
		#include "../WaveData/C#3.txt"
	};
	float D3[] = {
		#include "../WaveData/D3.txt"
	};
	float D_Sharp_3[] = {
		#include "../WaveData/D#3.txt"
	};
	float E3[] = {
		#include "../WaveData/E3.txt"
	};
	float F3[] = {
		#include "../WaveData/F3.txt"
	};
	float F_Sharp_3[] = {
		#include "../WaveData/F#3.txt"
	};
	float G3[] = {
		#include "../WaveData/G3.txt"
	};
	float G_Sharp_3[] = {
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
		
	float modWaveResult, carrierWaveResult, cartest;

	int i, differnt=0;
	for (i = 0; i < 5000; i++){
		int modRead = (int)(D_conversion*mod_phase + i)%(int)(sizeof(D3)/sizeof(*D3));

		modWaveResult = D3[modRead];

		modWaveResult *= D_conversion;

		//printf("%f\n", modWaveResult);

		int carRead = (int)ceil(2*(scale_factor*modWaveResult + C_conversion*car_phase + i))%((int)(sizeof(C3)/sizeof(*C3)));
		//int carRead_nomod = (int)(car_phase + i)%(int)(sizeof(C3)/sizeof(*C3));

		//printf("Mod = %i 	NoMod = %i\n", carRead, carRead_nomod);

		carrierWaveResult = C3[carRead];
		//cartest = C3[carRead_nomod];

		//if(carrierWaveResult != cartest) differnt++;

		fprintf(f, "%f\n", carrierWaveResult);
	
	}

	fclose(f);
}