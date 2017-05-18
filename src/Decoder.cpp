#include "Decoder.h"

Decoder::Decoder(const char* path) {
	reader = new Reader(path);
}

Decoder::~Decoder() {
	delete reader;
}

char* Decoder::decode() {
	long int* numbers = reader->read();
	// TODO
	delete numbers;
	return "Sattelit X sendet X";
}
