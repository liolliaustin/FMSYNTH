#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

//void FM_Synth(char * mod_freq, float mod_octave, float mod_phase, float scale_factor, char * car_freq, float car_octave, float car_phase){
void FM_Synth(float *modulator_wave, int mod_octave, float modulator_phase, float modulator_conversion, int mod_size, float scale_factor, float *carrier_wave, int car_octave, float carrier_phase, float carrier_conversion, int car_size){

	FILE *f = fopen("outresult.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	float modWaveResult, carrierWaveResult, cartest;

	int i, differnt=0;
	for (i = 0; i < 3000; i++){
		int modRead = (int)ceil((mod_octave*(modulator_conversion*modulator_phase + i)))%mod_size;

		modWaveResult = modulator_wave[modRead];

		int carRead = (int)ceil(car_octave*(scale_factor*modWaveResult*carrier_conversion + carrier_conversion*carrier_phase + i))%car_size;

		carrierWaveResult = carrier_wave[carRead];

		fprintf(f, "%f\n", carrierWaveResult);
	}

	fclose(f);
}

