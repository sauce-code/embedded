#include "Decoder.h"

Decoder::Decoder(const char* path) {
	reader = new Reader(path);
}

Decoder::~Decoder() {
	delete reader;
}

char* Decoder::decode() {
	int* numbers = reader.read();
	// TODO
	return "Sattelit X sendet X";
}
