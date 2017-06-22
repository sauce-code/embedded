#include "ChipSequence.h"

/**
 * Erzeugt die Chip-Sequenz.
 *
 * a und b sind die Werte der Registersumme
 *
 * @param a Wertebereich: 0 < a <= 10
 * @param b Wertebereich: 0 < b <= 10
 */
ChipSequence::ChipSequence(int a, int b) {

	a--;
	b--;

	sequence = new int[SIGNAL_LENGTH];

	int register1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int register2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	for (int i = 0; i < SIGNAL_LENGTH; i++) {
		int x = register1[9] ^ (register2[a] ^ register2[b]);
		sequence[i] = (x > 0 ? 1 : -1);

		// Schieberegister
		rotate(register1);
		register1[0] ^= register1[3];

		rotate(register2);
		register2[0] ^= register2[2] ^ register2[3] ^ register2[6] ^ register2[8] ^ register2[9];
	}
}

/**
 * Loescht die Chipsequenz.
 */
ChipSequence::~ChipSequence() {
	delete sequence;
}

/**
 * Imitiert ein Schieberegister
 * Rotiert die Werte des Arrays eins weiter in dieser Form:
 *		reg[9] = reg[8];
 *  	reg[8] = reg[7];
 *  	...
 *  	reg[1] = reg[0];
 *  	reg[0] = reg[9];
 * Das hoechstwertige Bit wird in das erste zurueckgeschrieben.
 *
 * @param reg Register, welches rotiert werden soll
 */
void ChipSequence::rotate(int* reg) {
	int carry = reg[9];
	for (int i = 9; i > 0; i--) {
		reg[i] = reg[i - 1];
	}
	reg[0] = carry;
}

/**
 * Liefert die sequenz.
 *
 * @return zugehoerige sequenz
 */
int* ChipSequence::getSequence() {
	return sequence;
}
