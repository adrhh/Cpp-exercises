#include "pch.h"
#include "flass.h"

const int StackOCSCTest::SIZE = 100;

// [minrange, maxrange]
int getRandInt(int minrange, int maxrange)
{
	return rand() % (maxrange - minrange) + minrange;
}

void StackOCSCTest::setUp()
{
	for (int i = 0; i < SIZE; i++)
		stack.push(getRandInt(0, SIZE));
}

void StackOCSCTest::clear()
{
	for (int i = 0; i < SIZE; i++)
		stack.pop();
}