#include "car.h"
#include <iostream>

using std::cout;
using std::endl;

Car::Car(double f, double o, double t, double m) : fuel(f), odmoter(o), tankCap(t), MPG(m), speed(0)
{
	if (f > t)
		fuel = o;
}

double Car::addFuel(double gal)
{
	double added = 0;
	if (fuel + gal <= tankCap)
	{
		added = gal;
		fuel += gal;
	}
	else
	{
		added = tankCap - fuel;
		fuel = tankCap;	
	}
	return added;
}

double Car::drive(double s, int m)
{
	const int minutes_in_hour = 60;
	double distance = 0;
	double	dest_distance = s * (m * 1.0 / minutes_in_hour);
	cout << dest_distance << endl;

	if(fuel > 0)
	{
		if (dest_distance / MPG > fuel)
		{
			distance = MPG * fuel;
			fuel = 0;
			cout << "koniec paliwa" << endl;
		}
		else
		{
			distance = dest_distance;
			fuel -=  distance / MPG;
		}
		odmoter += distance;
	}
	else

		cout << "brak paliwa" << endl;

	//test
	cout << "przejchano: " << distance << endl;
	status();

	return distance;
}

void Car::status() const
{
	cout << "Paliwo: " << fuel << " Licznik: " << odmoter
		<< " Pojemnosc baku: " << tankCap << endl;
}
