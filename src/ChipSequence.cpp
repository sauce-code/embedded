#include "ChipSequence.h"

/**
 * Erzeugt die Chip-Sequenz.
 *
 * a und b sind die Werte der Registersumme
 * Wertebereich: 0 < a <= 10
 * Wertebereich: 0 < b <= 10
 */
ChipSequence::ChipSequence(int a, int b) {

	sequence = new int[SIGNAL_LENGTH];

	a = abs(a - 10);
	b = abs(b - 10);

	int register1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int register2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int x = 0;

	for (int i = 0; i < SIGNAL_LENGTH; i++) {
		x = register1[0] ^ (register2[a] ^ register2[b]);

		// Schieberegister
		rotate(register1);
		register1[9] = register1[7 - 1] ^ register1[9];
		rotate(register2);
		register2[9] = register2[8 - 1] ^ register2[7 - 1] ^ register2[4 - 1]
				^ register2[2 - 1] ^ register2[1 - 1] ^ register2[9];

		sequence[i] = x;
	}
}

ChipSequence::~ChipSequence() {
	delete sequence;
}

/** Imitiert ein Schieberegister
 *  Rotiert die Werte des Arrays eins weiter in der Form:
 *		reg[0] = reg[1];
 *  	reg[1] = reg[2];
 *  	...
 *  	reg[8] = reg[9];
 *  	reg[9] = reg[0];
 *  Das hoechstwertige Bit wird in das erste zurueckgeschrieben.
 */
void ChipSequence::rotate(int* reg) {
	int carry = reg[0];
	for (int i = 0; i < 9; i++) {
		reg[i] = reg[i + 1];
	}
	reg[9] = carry;
}

int* ChipSequence::getSequence() {
	int* converted = new int[SIGNAL_LENGTH];
	for(int i = 0; i < SIGNAL_LENGTH; i++) {
		converted[i] = (sequence[i] == 1 ? 1 : -1);
	}
	return converted;
}
