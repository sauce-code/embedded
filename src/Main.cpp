#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "Reader.h"
#include "Decoder.h"

using namespace std;

int main(int argc, char** argv) {

	// waren die Eingabeparameter korrekt?
	if (argc != 2) {
		cerr << "Fehler bei der Eingabe der Parameter" << endl;
		return EXIT_FAILURE;
	}

	// lese dateipfad aus parameter
	char* path = argv[1];

	// ueberpruefen, ob Eingabedatei geoeffnet werden kann
	ifstream fileTest(path);
	if (!fileTest.is_open()) {
		cerr << "Datei " << path << " kann nicht geoeffnet werden" << endl;
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
