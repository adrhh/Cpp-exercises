#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>

using std::ostream;
using std::cout;

class Money
{
private:
	long int total;
public:
	Money(double n = 0);
	long int get_zl() const;
	int get_gr() const;
	friend ostream& operator<<(ostream& os, const Money& m);
};

long int Money::get_zl() const
{
	return total / 100;
}

int Money::get_gr() const
{
	return total % 100;
}

ostream& operator<<(ostream& os, const Money& m)
{
	os << m.get_zl() << ',' << m.get_gr();
	return os;
}

Money::Money(double n)
{
	double d_temp = n * 1000;
	long int t_temp = static_cast<long int> (d_temp);
	cout << t_temp << '\n';
	if (t_temp % 10 == 5)
		t_temp += 10;
	cout << t_temp << '\n';
	t_temp /= 10;
	total = t_temp;
}

#endif // !MONEY_H_
