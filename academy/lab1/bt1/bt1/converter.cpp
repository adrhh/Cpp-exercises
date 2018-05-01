#include "converter.h"
#include <algorithm>

using std::string;
using std::reverse;

void C::doConvert(int x)
{
	string binar = "";
	while (x)
	{
		if (x % 2)
			binar += '1';
		else
			binar += '0';
		x /= 2;
	}
	reverse(binar.begin(), binar.end());

	this->m_binary = binar;
	return;
}

C::C(int x)
{
	doConvert(x);
}