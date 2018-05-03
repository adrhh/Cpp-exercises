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

TEST(MyRGBAStruct, structCompareToMyRgba)
{
	const int ALLON = 0xFF;
	MyRGBA testObA(UINT_MAX);
	MyRGBAStruct testObB(ALLON, ALLON, ALLON, ALLON);

	testObA.setRed(1);
	testObA.setGreen(2);
	testObA.setBlue(3);
	testObA.setAlpha(4);
	testObB.setRed(1);
	testObB.setGreen(2);
	testObB.setBlue(3);
	testObB.setAlpha(4);
	EXPECT_EQ(testObB.getAlpha(), testObA.getAlpha());
	EXPECT_EQ(testObB.getBlue(), testObA.getBlue());
	EXPECT_EQ(testObB.getGreen(), testObA.getGreen());
	EXPECT_EQ(testObB.getRed(), testObA.getRed());
}

TEST(baseClass, poliBothTest)
{
	const int ALLON = 0xFF;
	MyRGBA* testObA = new MyRGBA(UINT_MAX);
	MyRGBAStruct* testObB = new MyRGBAStruct(ALLON, ALLON, ALLON, ALLON);

	Rgba* obA = testObA;
	Rgba* obB = testObB;

	obA->setRed(1);
	obA->setGreen(2);
	obA->setBlue(3);
	obA->setAlpha(4);
	obB->setRed(1);
	obB->setGreen(2);
	obB->setBlue(3);
	obB->setAlpha(4);
	EXPECT_EQ(obB->getAlpha(), obA->getAlpha());
	EXPECT_EQ(obB->getBlue(), obA->getBlue());
	EXPECT_EQ(obB->getGreen(), obA->getGreen());
	EXPECT_EQ(obB->getRed(), obA->getRed());

	delete testObA;
	delete testObB;
}