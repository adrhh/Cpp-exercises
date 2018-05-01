#include "pch.h"
#include "flass.h"
#include <iostream>

using std::endl;
using std::cout;

TEST(TestCaseName, randIntRange)
{
	srand(time(0));
	const int MAX_RANGE = 10;
	const int MIN_RANGE = -10;
	const int TESTS_NR = 100;
	int x = 0;
	for (int i = 0; i < TESTS_NR; i++)
	{
		x = getRandInt(MIN_RANGE, MAX_RANGE);
		EXPECT_LE(MIN_RANGE, x);
		EXPECT_GE(MAX_RANGE, x);
		EXPECT_GT(MAX_RANGE, x);
	}
}

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}