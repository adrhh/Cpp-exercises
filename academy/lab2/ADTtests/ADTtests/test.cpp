#include "pch.h"
#include "flass.h"

TEST(TestCaseName, randIntRange)
{
	const int MAX_RANGE = 10;
	const int MIN_RANGE = 0;
	const int TESTS_NR = 200000;
	int x = 0;
	for (int i = 0; i < TESTS_NR; i++)
	{
		x = getRandInt(MIN_RANGE, MAX_RANGE);
		EXPECT_LE(MIN_RANGE, x);
		EXPECT_GE(MAX_RANGE, x);
	}
}

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}