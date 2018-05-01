#include "pch.h"
#include "flass.h"

int getRandInt(int minrange, int maxrange)
{
	srand(time(0));
	return rand() % (maxrange - minrange) + minrange;
}