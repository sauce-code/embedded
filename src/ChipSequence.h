#ifndef CHIPSEQUENCE_H_
#define CHIPSEQUENCE_H_

#include <stdlib.h>

#include "Reader.h"

#define REGISTER_LENGTH 10

class ChipSequence {
private:
	int* sequence;
	void rotate(int*);
public:
	ChipSequence(int, int);
	virtual ~ChipSequence();
	int* getSequence();
};

#endif /* CHIPSEQUENCE_H_ */
