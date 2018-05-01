#include "pch.h"
#include "flass.h"


// [minrange, maxrange]
int getRandInt(int minrange, int maxrange)
{
	return rand() % (maxrange - minrange) + minrange;
}