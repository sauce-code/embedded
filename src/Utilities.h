/*
 * Utilities.h
 *
 *  Created on: 14.06.2017
 *      Author: Joachim Leiser
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stdio.h>

class Utilities {
public:
	static int scalarProduct(int* a, int* b) {
		int ret = 0;
		for (int i = 0; i < 1023; i++) {
			ret += a[i] * b[i];
		}
		return ret;
	}

	static int* convertFromTo(bool* from) {
		int* to = new int[1023];
		for (int i = 0; i < 1023; i++) {
			to[i] = from[i];
		}
		return to;
	}
};



#endif /* UTILITIES_H_ */
