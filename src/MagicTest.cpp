/*
 * MagicTest.cpp
 *
 *  Created on: 14.06.2017
 *      Author: Joachim Leiser
 */

#include "MagicTest.h"

MagicTest::MagicTest() {

}

bool equals(bool* b, int* k, int n) {
	for (int i = 0; i < n; i++) {
		if (b[i] != k[i]) {
			return false;
		}
	}
	return true;
}

bool equals(int* b, int* k, int n) {
	for (int i = 0; i < n; i++) {
		if (b[i] != k[i]) {
			return false;
		}
	}
	return true;
}

void MagicTest::testScalarProduct() {

}

void MagicTest::testConvertFromTo() {

}

void MagicTest::testRotation1023() {

}

void MagicTest::testChipSequence() {
	ChipSequence seq = ChipSequence(2, 6);
	int test1[] = {1, 1,  0,  0, 1,  0,  0,  0,  0,  0, 1, 1};
	int test2[] = {1, 1, -1, -1, 1, -1, -1, -1, -1, -1, 1, 1};

	if (!equals(seq.getSequence(), test1, 10)) {
		printf("Test ChipSequence Teil 1 failed!\n");
		for (int i=0; i<1023; i++) {
			printf("%d ", seq.getSequence()[i]);
		}
		printf("\n");
		for (int i=0; i<10; i++) {
			printf("%d ", test1[i]);
		}
		printf("\n\n");
	}

	if (!equals(seq.getIntSequence(), test2, 10)) {
		printf("Test ChipSequence Teil 2 failed, and it is right to fail!\n");
		for (int i=0; i<1023; i++) {
			printf("%d ", seq.getSequence()[i]);
		}
		printf("\n");
		for (int i=0; i<10; i++) {
			printf("%d ", test2[i]);
		}
		printf("\n\n");
	}

	int *test3 = seq.getIntSequence();

	for (int i=0; i<1023; i++) {
		Utilities::rotation1023(test3);
	}
	for (int i=0; i<1023; i++) {
		if (test3[i] != seq.getIntSequence()[i]) {
			printf("Fehler");
		}
	}
}


