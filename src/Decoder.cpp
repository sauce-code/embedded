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
	ChipSequence sequence3 = ChipSequence(9, 10);

	ChipSequence** sequences = new ChipSequence[SATELLITE_COUNT];
	sequences[0] = new ChipSequence(2, 6);
	sequences[1] = new ChipSequence(3, 7);
	sequences[2] = new ChipSequence(4, 8);
	sequences[3] = new ChipSequence(5, 9);
	sequences[4] = new ChipSequence(1, 9);
	sequences[5] = new ChipSequence(2, 10);
	sequences[6] = new ChipSequence(1, 8);
	sequences[7] = new ChipSequence(2, 9);
	sequences[8] = new ChipSequence(3, 10);
	sequences[9] = new ChipSequence(2, 3);
	sequences[10] = new ChipSequence(3, 4);
	sequences[11] = new ChipSequence(5, 6);
	sequences[12] = new ChipSequence(6, 7);
	sequences[13] = new ChipSequence(7, 8);
	sequences[14] = new ChipSequence(8, 9);
	sequences[15] = new ChipSequence(9, 10);
	sequences[16] = new ChipSequence(1, 4);
	sequences[17] = new ChipSequence(2, 5);
	sequences[18] = new ChipSequence(3, 6);
	sequences[19] = new ChipSequence(4, 7);
	sequences[20] = new ChipSequence(5, 8);
	sequences[21] = new ChipSequence(6, 9);
	sequences[22] = new ChipSequence(1, 3);
	sequences[23] = new ChipSequence(4, 6);


	printf("\n");

	int* a = Utilities::convertFromTo(sequence1.getSequence());
	int x = Utilities::scalarProduct(a, numbers);
	printf("\n%d\n", x);

	printf("\n");
	for (int i = 0; i < 1023; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
//	Utilities::rotation1023(a);
	for (int i = 0; i < 1023; i++) {
				printf("%d", a[i]);
			}
			printf("\n");
	for (int i = 0; i < 1023; i++) {
		x = Utilities::scalarProduct(a, numbers);
		printf("%d ", x);
		Utilities::rotation1023(a);
	}

	delete numbers;
	delete[] sequences;
	return "Satellit X sendet X";
}
