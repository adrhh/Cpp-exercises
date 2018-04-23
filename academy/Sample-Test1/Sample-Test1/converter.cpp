#include "converter.h"
#include "pch.h"
#include <algorithm>
#include <iostream>

using std::endl;
using std::cout;

using std::string;
using std::reverse;

void C10to2::doConvert(int x)
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

C10to2::C10to2(int x)
{
	doConvert(x);
}

void C2to10::doConvert(string x)
{
	int dec = 0;
	int pow = 0;
	for (int i = 0; i < x.size(); i++)
	{
		pow = 1 <<  x.size() - i - 1;
		if (x[i] == '1')
			dec += pow;
	}
	this->m_decimal = dec;
}

C2to10::C2to10(string x)
{
	doConvert(x);
}