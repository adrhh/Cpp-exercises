#ifndef CALC_H_
#define CALC_H_
#include "pch.h"
#include <string>

class Calc
{
private:
	std::string str;
	Stack<double> stack;
	void add();
	void sub();
public:
	Calc(std::string s) : str(s) {}
	double eval();
};

#endif // !CALC_H_
