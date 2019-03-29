#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FMSynth.h"

int main(int argc, char * argv[]) {

	// FILE *f = fopen("outresult.txt", "w");
	// if (f == NULL)
	// {
	//     printf("Error opening file!\n");
	//     exit(1);
	// }
	// FILE *f2 = fopen("outresult_2.txt", "w");
	// if (f2 == NULL)
	// {
	//     printf("Error opening file!\n");
	//     exit(1);
	// }

	if (argc != 6){
		printf("ERROR: Not Enough Arguments\n");
		return(-1);
	}
	
	float mod_freq = atof(argv[1]);
	float mod_phase = atof(argv[2]);
	float scale_factor = atof(argv[3]);
	float car_freq = atof(argv[4]);
	float car_phase = atof(argv[5]);

	FM_Synth(mod_freq, mod_phase, scale_factor, car_freq, car_phase); 

	//fclose(f);
	// fclose(f2);
	//printf("Different: %i\n", differnt);
	return 0;
}