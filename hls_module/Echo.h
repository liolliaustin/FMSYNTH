#ifndef __ECHO_INCLUDED__
#define __ECHO_INCLUDED__

int MAX_BUFFER_SIZE=48000;

void Echo(

	hls::stream<int> & change,
	hls::stream<float> & value_in,
	hls::stream<float> & value_out,

	int delay
	
	float scale1,
	float scale2,
	float scale3

);


#endif