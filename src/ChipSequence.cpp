/*
 * ChipSequence.cpp
 *
 *  Created on: 14.06.2017
 *      Author: Joachim Leiser
 */

#include "ChipSequence.h"
#include <stdio.h>
#include <stdlib.h>

ChipSequence::ChipSequence(int a, int b) {

	a = abs(a - 10);
	b = abs(b - 10);

	bool register1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	bool register2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	bool x = 0;

	for (int i = 0; i < 1023; i++) {

		x = register1[0] ^ (register2[a] ^ register2[b]);

		// Schieberegister
		rotation(register1);
		register1[9] = register1[7-1] ^ register1[9];
		rotation(register2);
		register2[9] = register2[8-1] ^ register2[7-1] ^ register2[4-1] ^ register2[2-1] ^ register2[1-1] ^ register2[9];

		sequence[i] = x;
	}
}

/** Imitiert ein Schieberegister
 *  Rotiert die Werte des Arrays eins weiter in der Form:
 *		reg[0] = reg[1];
 *  	reg[1] = reg[2];
 *  Das höchstwertige Bit wird in das erste zurückgeschrieben.
 */
void ChipSequence::rotation(bool* reg) {
//	int i = 0;
	bool carry = reg[0];
//	while (reg[i+1]) {
	for (int i = 0; i < 10; i++) {
//		printf("Penis\n");
		reg[i] = reg[i+1];
//		i++;
	}
	reg[9] = carry;
}

bool* ChipSequence::getSequence() {
	return sequence;
}

void ChipSequence::printSequence() {
	for (int i = 0; i < 1023; i++) {
		printf("%i", sequence[i]);
	}
}

