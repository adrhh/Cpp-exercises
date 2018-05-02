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