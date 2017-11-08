#ifndef  AC_H_
#define AC_H_

#include <string>

using std::string;

class Bank_acc
{
private:
	string name;
	int nr;
	double total;
public:
	Bank_acc(const string str, const int n, const double val=0);
	void show() const;
	void pop(double n);
	void add(double n);
};

#endif // ! AC_H_
