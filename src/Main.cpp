#include <iostream>
//#include <stdlib.h>
#include <stdlib.h>

#include "Reader.h"
#include "Decoder.h"

using namespace std;

#define PATH_DEFAULT "sequences/gps_sequence_20.txt"

int main() {
	Decoder* decoder = new Decoder(PATH_DEFAULT);
	char* output = decoder->decode();
	printf("%s\n", output);
	delete decoder;
	return EXIT_SUCCESS;
}
