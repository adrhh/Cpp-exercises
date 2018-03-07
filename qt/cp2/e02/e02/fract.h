#ifndef FRACT_H_
#define FRACT_H_

#include <QString>

int nwd(int a, int b);
int nww(int a, int b);

class Fraction
{
private:
	int numer;
	int deno;
public:
	Fraction(int a=1, int b=1) : numer(a), deno(b) {}
	void set(int n, int m);
	QString toString() const;
	double toDouble() const;
	Fraction add(const Fraction& fr);
	Fraction sub(const Fraction& fr);
	Fraction mult(const Fraction& fr);
	Fraction div(const Fraction& fr);
};

#endif // !FRACT_H_