#include "pch.h"
#include "rgba.h"
#include <climits>

TEST(MyRGBA, PureWHite)
{
	const int ALLON = 0xFF;
	MyRGBA testOb(UINT_MAX);
	EXPECT_EQ(ALLON, testOb.getAlpha());
	EXPECT_EQ(ALLON, testOb.getBlue());
	EXPECT_EQ(ALLON, testOb.getGreen());
	EXPECT_EQ(ALLON, testOb.getRed());
}

TEST(MyRGBA, PureBlack)
{
	MyRGBA testOb(0);
	EXPECT_EQ(0, testOb.getAlpha());
	EXPECT_EQ(0, testOb.getBlue());
	EXPECT_EQ(0, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());
}