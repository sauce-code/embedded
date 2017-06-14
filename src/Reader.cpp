#include "Reader.h"

Reader::Reader(const char* path) {
	file = fopen(path, "r");
}

Reader::~Reader() {
	fclose(file);
}

int* Reader::read() {
	int* sequence = new int[COUNT];
	int i = 0;
	int counter = 0;
	while (!feof(file) && counter < COUNT) {
		fscanf(file, "%d", &i);
		sequence[counter] = i;
		counter++;
	}
	return sequence;
}
