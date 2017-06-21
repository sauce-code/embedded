#ifndef DECODER_H_
#define DECODER_H_

#include <stdio.h>
#include <math.h>

#include "ChipSequence.h"
#include "Reader.h"

#define SATELLITE_COUNT 24
#define PEAK 1023
#define SATELLITE_NOISE_COUNT 3

class Decoder {
private:
	Reader* reader;
	ChipSequence** sequences;
	int scalarProduct(int*, int*);
	int* rotate(int*, int);
public:
	Decoder(const char*);
	virtual ~Decoder();
	void decode();
};

#endif /* DECODER_H_ */
