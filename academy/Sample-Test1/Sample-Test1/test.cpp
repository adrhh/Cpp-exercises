#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using std::endl;
using std::cout;



TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(C10to2, IntTest)
{
	int x = 10;
	//binary 1010
	EXPECT_EQ(C10to2(10).getBin(), "1010");
}

TEST(C2to10, IntTest2)
{
	string x = "1010";
	//deciaml 10
	EXPECT_EQ(C2to10(x).getInt(), 10);
}

TEST(C10to2, rand)
{
	srand(time(0));
	int x = rand() % INTMAX_MAX;
	//string bin = C10to2(x).getBin();
	//int newx = C2to10(bin).getInt();
	//cout << x << "(10) = " << bin << " = " << newx << " ?" << endl;

	EXPECT_EQ(x, C2to10( C10to2(x).getBin() ).getInt() );
}