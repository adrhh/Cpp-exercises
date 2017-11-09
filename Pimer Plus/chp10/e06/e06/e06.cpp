#include "move.h"
#include <iostream>

using std::cin;

int main()
{
	Move m1(2, 2);
	m1.showmove();
	Move m2(1, 1);
	m2.showmove();
	Move m3 = m2.add(m1);
	m3.showmove();
	m3.reset();
	m3.showmove();

	return 0;
}