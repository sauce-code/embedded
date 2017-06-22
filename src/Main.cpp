#include <stdlib.h>
#include <fstream>

#include "ChipSequence.h"
#include "Decoder.h"
#include "Reader.h"

using namespace std;

/**
 * Fuerht das gesamte Programm aus.
 *
 * @param argc Anzahl der Parameter
 * @param argv Liste der Parameter
 * @return EXIT_FAILURE, falls ein Fehler auftrat
 *         EXIT_SUCCESS, falls kein Fehler auftrat
 */
int main(int argc, char** argv) {

	// waren die Eingabeparameter korrekt?
	if (argc != 2) {
		fprintf(stderr, "parameters incorrect");
		return EXIT_FAILURE;
	}

	// lese dateipfad aus parameter
	char* path = argv[1];

	// ueberpruefen, ob Eingabedatei geoeffnet werden kann
	ifstream fileTest(path);
	if (!fileTest.is_open()) {
		fprintf(stderr, "file %s cannot be opened", path);
		return EXIT_FAILURE;
	}
	fileTest.close();

	// Programm ausfuehren
	Decoder* decoder = new Decoder(path);
	decoder->decode();

	// aufraeumen
	delete decoder;

	// ende
	return EXIT_SUCCESS;
}
