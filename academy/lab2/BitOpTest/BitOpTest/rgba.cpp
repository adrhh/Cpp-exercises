#include "pch.h"
#include "rgba.h"

int MyRGBA::toInt(unsigned int color) const
{
	unsigned int retInt = 0;
	switch(color)
	{
	case RED:
		retInt = rgba & RED;
		retInt >>= RED_SHIFT;
		break;
	case BLUE:
		retInt = rgba & BLUE;
		retInt >>= BLUE_SHIFT;
		break;
	case GREEN:
		retInt = rgba & GREEN;
		retInt >>= GREEN_SHIFT;
		break;
	case ALPHA:
		retInt = rgba & ALPHA;
		retInt >>= ALPHA_SHIFT;
		break;
	}
	return static_cast<int>(retInt);
}

void MyRGBA::setColorToZero(unsigned int color)
{
	unsigned int tempZeroColor = 0xFFFFFFFF;
	switch (color)
	{
	case RED:
		tempZeroColor ^= RED;
		break;
	case BLUE:
		tempZeroColor ^= BLUE;
		break;
	case GREEN:
		tempZeroColor ^= GREEN;
		break;
	case ALPHA:
		tempZeroColor ^= ALPHA;
		break;
	}
	rgba &= tempZeroColor;
}

void MyRGBA::changeRGBA(char val, unsigned int color)
{
	unsigned int tempColor = static_cast<unsigned int>(val);
	switch (color)
	{
	case RED:
		tempColor <<= RED_SHIFT;
		setColorToZero(RED);
		break;
	case BLUE:
		tempColor <<= BLUE_SHIFT;
		setColorToZero(BLUE);
		break;
	case GREEN:
		tempColor <<= GREEN_SHIFT;
		setColorToZero(GREEN);
		break;
	case ALPHA:
		tempColor <<= ALPHA_SHIFT;
		setColorToZero(ALPHA);
		break;
	}

	rgba |= tempColor;
}