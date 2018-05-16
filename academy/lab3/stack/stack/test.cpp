#include "pch.h"
#include <vector>

TEST(Stack, StackTesT) 
{
	const int VSIZE = 10;
	std::vector<int> tempVec;
	Stack<int> testStack;
	for (int i = 0; i < VSIZE; i++)
	{
		tempVec.push_back(i);
		testStack.push(i);
	}
	for (int i = 0; i < VSIZE; i++)
	{
		EXPECT_EQ(tempVec[VSIZE - 1 - i], testStack.pop());
	}
}