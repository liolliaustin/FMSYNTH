#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

//void FM_Synth(char * mod_freq, float mod_octave, float mod_phase, float scale_factor, char * car_freq, float car_octave, float car_phase){
void FM_Synth(float * modulator_wave[], float mod_octave, float mod_phase, float modulator_conversion, float scale_factor, float * carrier_wave[], float car_octave, float car_phase, float carrier_conversion){

	FILE *f = fopen("outresult.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	float modWaveResult, carrierWaveResult, cartest;

	int i, differnt=0;
	for (i = 0; i < 5000; i++){
		int modRead = (int)(mod_octave*(D_conversion*mod_phase + i))%(int)(sizeof(modulator_wave)/sizeof(*modulator_wave));

		modWaveResult = modulator_wave[modRead];

		//modWaveResult *= D_conversion;

		//printf("%f\n", modWaveResult);

		int carRead = (int)ceil(car_octave*(scale_factor*modWaveResult*carrier_conversion + carrier_conversion*car_phase + i))%((int)(sizeof(carrier_wave)/sizeof(*carrier_wave)));
		//int carRead_nomod = (int)(car_phase + i)%(int)(sizeof(C3)/sizeof(*C3));

		//printf("Mod = %i 	NoMod = %i\n", carRead, carRead_nomod);

		carrierWaveResult = carrier_wave[carRead];
		//cartest = C3[carRead_nomod];

		//if(carrierWaveResult != cartest) differnt++;

		fprintf(f, "%f\n", carrierWaveResult);
	
	}

	fclose(f);
}

