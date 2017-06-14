#include <stdlib.h>
#include <fstream>

#include "Reader.h"
#include "Decoder.h"
#include "ChipSequence.h"

using namespace std;

int main(int argc, char** argv) {

	// TODO Liste:
	//		Funktion zum Auflösen des Multiplex
	//		Funktion zur Autokorrelation
	// 		Funktion die die Verschiebung der Chipsequenz findet
	//		Funktion zur Ausgabe

	// waren die Eingabeparameter korrekt?
	if (argc != 2) {
		fprintf(stderr, "Parameter fehlerhaft");
		return EXIT_FAILURE;
	}

	// lese dateipfad aus parameter
	char* path = argv[1];

	// ueberpruefen, ob Eingabedatei geoeffnet werden kann
	ifstream fileTest(path);
	if (!fileTest.is_open()) {
		fprintf(stderr, "Datei %s kann nicht geoeffnet werden", path);
		return EXIT_FAILURE;
	}
	fileTest.close();

	// Programm ausfuehren
	Decoder* decoder = new Decoder(path);
	char* output = decoder->decode();
	printf("%s\n", output);


	// aufraeumen
	delete decoder;

	// ende
	return EXIT_SUCCESS;
}
