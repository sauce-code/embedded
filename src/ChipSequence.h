/*
 * ChipSequence.h
 *
 *  Created on: 14.06.2017
 *      Author: Joachim Leiser
 */

#ifndef CHIPSEQUENCE_H_
#define CHIPSEQUENCE_H_

class ChipSequence {
private:
	bool sequence [1023];


public:
	/**
	 * Erzeugt die Chip-Sequenz.
	 *
	 * a und b sind die Werte der Registersumme
	 * Wertebereich: 0 < a <= 10
	 * Wertebereich: 0 < b <= 10
	 */
	ChipSequence(int a, int b);

	void rotation(bool* reg);

	bool* getSequence();

	void printSequence();

};



#endif /* CHIPSEQUENCE_H_ */
