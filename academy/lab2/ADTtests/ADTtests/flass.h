#ifndef FLASS_H_
#define FLASS_H_

#include "pch.h"
#include "stack.h"
#include <cstdlib>
#include <ctime>


int getRandInt(int minrange, int maxrange);

class StackTest : public testing::Test
{
public:
	virtual void setUp();
private:
	IntStackOnArrConstSizeChange stack;
};

#endif // !FLASS_H_
