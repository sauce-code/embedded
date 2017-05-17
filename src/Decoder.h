#ifndef DECODER_H_
#define DECODER_H_

#include "Reader.h"

class Decoder {
private:
	Reader* reader;
public:
	Decoder(const char*);
	virtual ~Decoder();
	char* decode();
};

#endif /* DECODER_H_ */
