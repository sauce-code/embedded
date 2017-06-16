#ifndef READER_H_
#define READER_H_

#include <stdio.h>

#define SIGNAL_LENGTH 1023

class Reader {
private:
	FILE* file;
public:
	Reader(const char*);
	virtual ~Reader();
	int* read();
};

#endif /* READER_H_ */
