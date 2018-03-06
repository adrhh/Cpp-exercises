#ifndef FRACT_H_
#define FRACT_H_

#include <QString>

class Fraction
{
private:
	int numer;
	int deno;
public:
	void set(int n, int m);
	QString toString() const;
	double toDouble() const;
	Fraction add(const Fraction& fr);
	Fraction sub(const Fraction& fr);
	Fraction mult(const Fraction& fr);
	Fraction div(const Fraction& fr);
};

#endif // !FRACT_H_