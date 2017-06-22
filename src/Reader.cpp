#include "Reader.h"

/**
 * Erzeugt einen neuen Reader und oeffnet die einzulesende Datei.
 *
 * @param path Pfad zur einzulesenden Datei
 */
Reader::Reader(const char* path) {
	file = fopen(path, "r");
}

/**
 * Schliesst die einzulesende Datei und loescht den Reader.
 */
Reader::~Reader() {
	fclose(file);
}

/**
 * Liest das Signal aus der einzulesenden Datei ein.
 * @return eingelesenes Signal
 */
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
