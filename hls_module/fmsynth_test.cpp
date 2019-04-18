#include "HLS_FMSYNTH.h"
#include <iostream>
#include <hls_stream.h>

using namespace std;

int main() {
	hls::stream<float> results("results");

	int i = 2000;
	while (i --> 0) {

		FM_Synth(
			results,1,3,0,0,0,0,1,2,50,70,1,2000,2020
		);

		float tmp;
		results >> tmp;
		cout << tmp << "\t";
	}
}
