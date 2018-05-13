#include "pch.h"
#include <cmath>

TEST(RootTest, PositiveDelta)
{
	//x^2-3x+2  przykladowe rownanie
	//pierwiatki 1 i 2
	Solution s = roots(1, -3, 2);
	
	ASSERT_EQ(s.count, 2);
	ASSERT_NE(s.x1, s.x2);

	double x1 = std::min(s.x1, s.x2);
	double x2 = std::max(s.x1, s.x2);

	const double eps = 1e-5;
	EXPECT_NEAR(x1, 1.0, eps);
	EXPECT_NEAR(x2, 2.0, eps);
	EXPECT_DOUBLE_EQ(x1, 1.0);
	EXPECT_DOUBLE_EQ(x2, 2.0);
	
	EXPECT_TRUE(std::abs(s.x1 - 1.0) < eps || std::abs(s.x1 - 2.0) < eps);
	EXPECT_TRUE(std::abs(s.x2 - 1.0) < eps || std::abs(s.x2 - 2.0) < eps);

	EXPECT_FALSE(s.identity);
}

TEST(RootTest, ZeroDelta)
{
	//x^2 + 2x + 1
	//jeden pierwiastek -1
	Solution s = roots(1, 2, 1);
	ASSERT_EQ(s.count, 1);
	EXPECT_DOUBLE_EQ(s.x1, -1.0);
	EXPECT_TRUE(s.x1 == s.x2);
	EXPECT_TRUE(s.identity);
}

TEST(RootTest, DoubleParamaters)
{
	//0.5x^2 - 1.5x 
	//pierwiastki 1.5, -1.13;
	Solution s = roots(0.5, -1.5, 0);
	ASSERT_EQ(s.count, 2);

	double x1 = std::min(s.x1, s.x2);
	double x2 = std::max(s.x1, s.x2);
	EXPECT_DOUBLE_EQ(x1, 0.02);
	EXPECT_DOUBLE_EQ(x2, -1.13);
}