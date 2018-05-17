#include "pch.h"
#include <cctype>


void Calc::add()
{
	double f1 = stack.pop();
	double f2 = stack.pop();
	stack.push(f2 + f1);
}

void Calc::sub()
{
	double f1 = stack.pop();
	double f2 = stack.pop();
	stack.push(f2 - f1);
}

double Calc::eval()
{
	std::string tempStrD;
	for (int i=0; i < str.size(); i++)
	{	
		while (isdigit(str[i]))
		{
			tempStrD += str[i];
			i++;
		}
		if(tempStrD.size() > 0)
			stack.push(std::stod(tempStrD));
		tempStrD = "";

		if (str[i] == '+')
			add();
		if (str[i] == '-')
			sub();
	}
	return stack.pop();
}