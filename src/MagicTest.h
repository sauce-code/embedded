/*
 * MagicTest.h
 *
 *  Created on: 14.06.2017
 *      Author: Joachim Leiser
 */

#ifndef MAGICTEST_H_
#define MAGICTEST_H_

#include "ChipSequence.h"
#include "Utilities.h"
#include <stdio.h>


class MagicTest {
public:
	//TODO Testroutine
	//TODO this static?
	MagicTest();
	void testScalarProduct();
	void testConvertFromTo();
	void testRotation1023();
	void testChipSequence();
};



#endif /* MAGICTEST_H_ */
