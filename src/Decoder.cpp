#include "Decoder.h"
#include <stdio.h>
#include "ChipSequence.h"
#include "Utilities.h"

Decoder::Decoder(const char* path) {
	reader = new Reader(path);
}

Decoder::~Decoder() {
	delete reader;
}

char* Decoder::decode() {
	int* numbers = reader->read();
	// TODO
	for (int i = 0; i < 1023; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

	ChipSequence sequence1 = ChipSequence(2, 6);
	printf("\n");
	sequence1.printSequence();
	printf("\n");
	ChipSequence sequence2 = ChipSequence(3, 7);
	sequence2.printSequence();
	printf("\n");
	ChipSequence sequence3 = ChipSequence(9, 10);
	sequence3.printSequence();

	printf("\n");

	int* a = Utilities::convertFromTo(sequence1.getSequence());
	int x = Utilities::scalarProduct(a, numbers);
	printf("\n%d\n", x);

	printf("\n");
	for (unsigned int i = 0; i < 1023; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
	for (unsigned int i = 0; i < 1023; i++) {
		printf("%d", numbers[i]);
	}
	printf("\n");

	delete numbers;
	return "Sattelit X sendet X";
}
