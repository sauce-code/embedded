#include "Reader.h"

#include <string>
#include <stdlib.h> // strtol

Reader::Reader(const char* path) {
//	file = open(path, O_RDONLY);
	this->path = path;
	file = fopen(path, "r");
}

Reader::~Reader() {
//	close(file);
	fclose(file);
}

long int* Reader::read() {
	char buffer[100000];
	fgets(buffer, sizeof(buffer), file);

	char** strings = new char*[COUNT];

	char* p = strtok(buffer, " ");
	int count = 0;
	while (p) {
//	    printf ("Token: %s\n", p);
	    p = strtok(NULL, " ");
	    strings[count] = p;
	    count++;
	}

	long int* result = new long int[COUNT];

	for (int i = 0; i < COUNT; i++) {
		result[i] = strtol(strings[i], NULL, 10);
	}

	delete strings;

	return result;
}

//void readFile(int * fileNumber, char * fileName){
//    int i = 0;
//    int counter = 0;
//    FILE* fptr = fopen (fileName, "r");
//    while (!feof (fptr) && counter < 1023) {
//        fscanf (fptr, "%d", &i);
//        fileNumber[counter] = i;
//        counter++;
//    }
//    fclose (fptr);
//}

