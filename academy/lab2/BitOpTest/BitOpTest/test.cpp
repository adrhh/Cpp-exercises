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

TEST(MyRGBA, ZeroTest)
{
	const int ALLON = 0xFF;
	MyRGBA testOb(UINT_MAX);

	testOb.setColorToZero(MyRGBA::RED);
	EXPECT_EQ(ALLON, testOb.getAlpha());
	EXPECT_EQ(ALLON, testOb.getBlue());
	EXPECT_EQ(ALLON, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());

	//once again
	testOb.setColorToZero(MyRGBA::RED);
	EXPECT_EQ(ALLON, testOb.getAlpha());
	EXPECT_EQ(ALLON, testOb.getBlue());
	EXPECT_EQ(ALLON, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());

	testOb.setColorToZero(MyRGBA::GREEN);
	EXPECT_EQ(ALLON, testOb.getAlpha());
	EXPECT_EQ(ALLON, testOb.getBlue());
	EXPECT_EQ(0, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());

	testOb.setColorToZero(MyRGBA::BLUE);
	EXPECT_EQ(ALLON, testOb.getAlpha());
	EXPECT_EQ(0, testOb.getBlue());
	EXPECT_EQ(0, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());

	testOb.setColorToZero(MyRGBA::ALPHA);
	EXPECT_EQ(0, testOb.getAlpha());
	EXPECT_EQ(0, testOb.getBlue());
	EXPECT_EQ(0, testOb.getGreen());
	EXPECT_EQ(0, testOb.getRed());
}

TEST(MyRGBA, ChangeColor)
{
	const int ALLON = 0xFF;
	MyRGBA testOb(UINT_MAX);

	testOb.setRed(1);
	testOb.setGreen(2);
	testOb.setBlue(3);
	testOb.setAlpha(4);
	EXPECT_EQ(4, testOb.getAlpha());
	EXPECT_EQ(3, testOb.getBlue());
	EXPECT_EQ(2, testOb.getGreen());
	EXPECT_EQ(1, testOb.getRed());
}
