#ifndef READER_H_
#define READER_H_

//#include <stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>
#include <stdio.h>

#define COUNT 1023

class Reader {
private:
	const char* filename;
	FILE* file;
public:
	Reader(const char*);
	virtual ~Reader();
	long int* read();
};

#endif /* READER_H_ */
