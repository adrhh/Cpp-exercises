#include "vect.h"
#include <cmath>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR
{
	const double Rad_to_deg = 45 / atan(1.0);

	double Vector::get_mag(double n1, double n2) const
	{
		return sqrt(n1*n1 + n2*n2);
	}

	double Vector::get_ang(double n1, double n2) const
	{
		if (n1 == 0 && n2 == 0)
			return  0.0;
		else
			return atan2(n2, n1);
	}

	void Vector::set_x(double n1, double n2)
	{
		x = n1 * cos(n2 );
	}

	void Vector::set_y(double n1, double n2)
	{
		y = n1 * sin(n2 );
	}

	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1, n2 / Rad_to_deg);
			set_y(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "Nie porawny argument form, wektor wyzerowany" << endl;
			x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			set_x(n1, n2 / Rad_to_deg);
			set_y(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "Nie porawny argument form, wektor wyzerowany" << endl;
			x = y = 0.0;
			mode = RECT;
		}
	}


	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector &b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector &b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n* y);
	}

	Vector operator*(double n, Vector &a)
	{
		return a * n;
	}
	std::ostream & operator<<(std::ostream & os, const Vector &v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m,a) = (" << v.magva() << ", "
			<< v.angva() * Rad_to_deg << ")";
		else
			os << "nieprawidlowa reprezentacja wektora";
		return os;
	}
}