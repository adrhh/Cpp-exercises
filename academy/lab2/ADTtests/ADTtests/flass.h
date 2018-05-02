#ifndef FLASS_H_
#define FLASS_H_

#include "pch.h"
#include "stack.h"
#include <cstdlib>
#include <ctime>


int getRandInt(int minrange, int maxrange);

class StackOCSCTest : public testing::Test
{
public:
	static const int SIZE;
	
protected:
	IntStackOnArrConstSizeChange stack;
	virtual void setUp();
	virtual void clear();
};

#endif // !FLASS_H_
