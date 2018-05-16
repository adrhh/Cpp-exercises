#ifndef WYMIERNE_H_
#define WYMIERNE_H_

#include <ostream>

int gcd(int a, int b);

class Rational
{
private:
	int nominator;
	int denominator;

public:
	Rational(int nom, int den);
	Rational(int n) : nominator(n), denominator(1) {}
	int getNominator() const { return nominator; }
	int getDenomiator() const { return denominator; }
	Rational& operator+=(const Rational& r);
	Rational& operator-=(const Rational& r);
};

inline Rational operator-(Rational r);
inline Rational operator+(Rational a, Rational b)
{
	a += b;
	return a;
}
inline Rational operator*(Rational a, Rational b);
inline Rational operator/(Rational a, Rational b);
inline Rational operator-(Rational a, Rational b);
inline bool operator==(Rational a, Rational b);
inline bool operator!=(Rational a, Rational b);
inline bool operator<=(Rational a, Rational b);
inline bool operator>=(Rational a, Rational b);
inline bool operator<(Rational a, Rational b);
inline bool operator>(Rational a, Rational b);
std::ostream& operator<<(std::ostream& os, Rational a);

#endif // !WYMIERNE_H_
