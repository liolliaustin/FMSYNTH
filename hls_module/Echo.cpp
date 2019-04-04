#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <hls_stream.h>
#include "Echo.h"

void Echo(

	hls::stream<int> & change,
	hls::stream<float> & value_in,
	hls::stream<float> & value_out,

	int delay
	
	float scale1,
	float scale2,
	float scale3

){

#pragma HLS PIPELINE II=1
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=delay bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=scale1 bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=scale2 bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=scale3 bundle=CTRL_BUS

#pragma HLS INTERFACE axis register both port=change
#pragma HLS INTERFACE axis register both port=value_in
#pragma HLS INTERFACE axis register both port=value_out

	static int initial = 0;
	static int delayCount = 0;
	static int writeBuffer = 0;

	float outAccumulate=0;

	float buffer[MAX_BUFFER_SIZE];

	static int readBuffer1 = 0;
	static int readBuffer2 = 0;
	static int readBuffer3 = 0;

	int changevalue >> change;

	//change is 0 when a note is being played or to be recorded for delay
	//change is 1 as long as a note is not being played or there is a note change

	if(changevalue == 1){
		delayCount = 0;
		initial = 0;
		readBuffer1 = 0;
		readBuffer2 = 0;
		readBuffer3 = 0;
		writeBuffer = 0;
	}

	else if(writeBuffer < MAX_BUFFER_SIZE){
		
		buffer[writeBuffer] >> value_in;
		writeBuffer++;
		initial++;

	}

	if(delayCount > delay){

		if(readBuffer1 <= initial){
			outAccumulate += scale1*buffer[readBuffer1];
			readBuffer1++;
		}

		if(readBuffer1 > delay){

			if(readBuffer2 <= initial){
				outAccumulate += scale2*buffer[readBuffer2];
				readBuffer2++;
			}

			if(readBuffer2 > delay){

				if(readBuffer3 <= initial){
					outAccumulate += scale3*buffer[readBuffer3];
					readBuffer3++;
				}

				if(readBuffer3 == initial){
					delayCount = 0;
					initial = 0;
					readBuffer1 = 0;
					readBuffer2 = 0;
					readBuffer3 = 0;
				}
			}
		}
	}

	delayCount++;

	value_out << value_in + outAccumulate;
}