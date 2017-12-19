#ifndef E_MEAN_H_
#define E_MEAN_H

#include <stdexcept>
#include <string>
#include <iostream>

using std::string;
using std::cout;

class bad_mean : public std::logic_error
{
private:
	double var1;
	double var2;
public:
	bad_mean(double a = 0, double b = 0, const string& str = "Blad") : logic_error(str), var1(a), var2(b) {};
	virtual void msg() = 0;
	double g_var1() { return var1; }
	double g_var2() { return var2; }
};

class bad_hmean : public bad_mean
{
private:
	string fname;
public:
	bad_hmean(double a = 0, double b = 0, const string& str = "Argument b nie moze wynosic -a. ",
		const string fn = "hmean") : bad_mean(a, b, str), fname(fn) {}
	void msg();
};

class bad_gmean : public bad_mean
{
	string fname;
public:
	bad_gmean(double a = 0, double b = 0, const string& str = "Nie moze wystepowac jeden ujemny agument. ",
		const string fn = "gmean") : bad_mean(a, b, str), fname(fn) {}
	void msg();
};

void bad_gmean::msg()
{
	cout << what();
	cout << "Nieporawne arguemnty funkcji " << fname
		 << ": " << g_var1() << ", " << g_var2();
}

void bad_hmean::msg()
{
	cout << what();
	cout << "Nieporawne arguemnty funkcji " << fname 
		 << ": " << g_var1() << ", " << g_var2();
}

#endif // !E_MEAN_H_#pragma once
