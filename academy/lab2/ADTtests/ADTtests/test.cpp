#include "pch.h"
#include "flass.h"
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

TEST(RandIntGenTest, randIntRange)
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

TEST_F(StackOCSCTest, pushTest)
{
	setUp();
	EXPECT_EQ(StackOCSCTest::SIZE, stack.getPosition());
}

TEST_F(StackOCSCTest, popTest)
{
	setUp();
	clear();
	EXPECT_EQ(0, stack.getPosition());
	EXPECT_EQ(true, stack.isEmpty());
}

TEST_F(StackOCSCTest, tryToPopEmpty)
{
	ASSERT_ANY_THROW(stack.pop());
}

TEST(IntList2Direct, ListTestPush)
{
	IntList2Direct list;
	const int SIZE = 1000;
	srand(time(0));
	int x;
	for (int i = 0; i < SIZE; i++)
	{
		x = getRandInt(0, SIZE);
		list.push_back(x);
		EXPECT_EQ(x, list[i]);
	}
}

TEST(IntList2Direct, ListTestPopFront)
{
	IntList2Direct list;
	vector<int> vec;
	const int SIZE = 1000;
	srand(time(0));
	int x = 0;
	for (int i = 0; i < SIZE; i++)
	{
		x = getRandInt(0, SIZE);
		list.push_back(x);
		vec.push_back(x);
	}
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(list.pop_front(), vec[i]);
}

TEST(IntListForward, ForwardListPushTest)
{
	IntListForward fl;
	const int n = 10;
	fl.push_back(n);
	EXPECT_EQ(n, fl[0]);
	fl.push_back(n);
	EXPECT_EQ(fl[0], fl[1]);
}

TEST(IntListForward, ForwardListReverseTest)
{
	IntListForward fl1, fl2;
	const int LIST_SIZE = 10;
	const int INT_SIZE = 1000;
	srand(time(0));
	int x = 0;
	for (int i = 0; i < 10; i++)
	{
		x = getRandInt(0, INT_SIZE);
		fl1.push_back(x);
		fl2.push_back(x);
	}
	//before reverse
	for (int i = 0; i < LIST_SIZE; i++)
	{
		EXPECT_EQ(fl1[i], fl2[i]);
	}
	//after reverse
	fl2.reverse();
	for (int i = 0; i < LIST_SIZE; i++)
	{
		EXPECT_EQ(fl1[i], fl2[LIST_SIZE - 1 - i]);
	}
}


TEST(IntListForward, ForwardListEmptyListReverseTest)
{
	IntListForward fl;
	fl.reverse();
}