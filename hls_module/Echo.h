#ifndef __ECHO_INCLUDED__
#define __ECHO_INCLUDED__

int MAX_BUFFER_SIZE=48000;

void Echo(

	hls::stream<int> & change,
	hls::stream<float> & value_in,
	hls::stream<float> & value_out,

	int delay,
	int scale
	
);


#endif