#include "Decoder.h"

/**
 * Erzeugt einen neuen Decoder.
 *
 * @param path Pfad zur einzulesenden Datei
 */
Decoder::Decoder(const char* path) {
	reader = new Reader(path);
	sequences = new ChipSequence*[SATELLITE_COUNT];
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
}

/**
 * Loescht den Decoder und dessen Felder.
 */
Decoder::~Decoder() {
	delete reader;
	delete[] sequences;
}

/**
 * Fuehrt den decode Vorgang aus und gibt die gesendeten Bits auf der Konsole aus.
 */
void Decoder::decode() {

	/*
	 * Das hier sind die beiden wichtigen Grenzen
	 * 1023 - drei mal der Stoerwert
	 * -1023 + drei mal der Stoerwert
	 */
	double upperPeak = PEAK - (SATELLITE_NOISE_COUNT * (pow(-2, (REGISTER_LENGTH + 2) / 2) + 1));
	double lowerPeak = -PEAK + (SATELLITE_NOISE_COUNT * (pow(2, (REGISTER_LENGTH + 2) / 2) - 1));

	int* signal = reader->read();

	int** rotatedSignals = new int*[SIGNAL_LENGTH];

	for (int delta = 0; delta < SIGNAL_LENGTH; delta++) {
		rotatedSignals[delta] = rotate(signal, delta);
	}

	for (int sat = 0; sat < SATELLITE_COUNT; sat++) {
		int* seq = sequences[sat]->getSequence();

		for (int delta = 0; delta < SIGNAL_LENGTH; delta++) {
			int x = scalarProduct(seq, rotatedSignals[delta]);

			if (x >= upperPeak || x <= lowerPeak) {
				printf("satellite %d has sent bit %d (delta = %d)\n", sat + 1, (x > 0 ? 1 : 0), delta);
			}
		}
	}

	delete signal;
	delete[] rotatedSignals;
}

/**
 * Berechnet das Skalarprodukt von zwei Vektoren.
 */
int Decoder::scalarProduct(int* a, int* b) {
	int product = 0;
	for (int i = 0; i < SIGNAL_LENGTH; i++) {
		product += a[i] * b[i];
	}
	return product;
}

/**
 * Rotiert ein Signal um ein gegebenes delta und gibt ein neues Array zurueck.
 *
 * @param signal Signal, welches rotiert  werden soll
 * @param delta wert, um welchen das Signal rotiert werden soll
 * @return neues Array mit dem rotierten Signal
 */
int* Decoder::rotate(int* signal, int delta) {
	int* rotatedSignal = new int[SIGNAL_LENGTH];
	for (int i = 0; i < SIGNAL_LENGTH; i++) {
		rotatedSignal[i] = signal[(i + delta) % SIGNAL_LENGTH];
	}
	return rotatedSignal;
}
