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

TEST(Calc, 2OperandsAdd)
{
	Calc c("2 2 +");
	EXPECT_DOUBLE_EQ(4, c.eval());
}

TEST(Calc, 3OpreandsAdd)
{
	Calc c("2 2 + 2 +");
	EXPECT_DOUBLE_EQ(6, c.eval());
}

TEST(Calc, 5OpreandsAdd)
{
	Calc c("20 2 + 2 + 8 + 8 +");
	EXPECT_DOUBLE_EQ(40, c.eval());
}

TEST(Calc, 2OpreandsSub)
{
	Calc c("5 2 -");
	EXPECT_DOUBLE_EQ(3, c.eval());
}

TEST(Calc, 3OpreandsSub)
{
	Calc c("2 1 - 2 -");
	EXPECT_DOUBLE_EQ(-1, c.eval());
}