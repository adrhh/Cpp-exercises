#include "move.h"
#include <iostream>

using std::cout;
using std::endl;

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "x: " << x
		<< " y: " << y << endl;
}

Move Move::add(const Move &m) const
{
	int tx = m.x + this->x;
	int ty = m.y + this->y;
	Move temp(tx, ty);

	return temp;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}