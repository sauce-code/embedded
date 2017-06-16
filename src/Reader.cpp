#include "Reader.h"

Reader::Reader(const char* path) {
	file = fopen(path, "r");
}

Reader::~Reader() {
	fclose(file);
}

int* Reader::read() {
	int* signal = new int[SIGNAL_LENGTH];
	int i = 0;
	int counter = 0;
	while (!feof(file) && counter < SIGNAL_LENGTH) {
		fscanf(file, "%d", &i);
		signal[counter] = i;
		counter++;
	}
	return signal;
}
