#include "car.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>


using std::cout;
using std::endl;
using std::setprecision;

double Car::fuelConsRate = 20;


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

double Car::higwayDrive(double d, double sl)
{	
	//d dest distance sl speed limit
	srand(time(0));
	double time = 0;
	double distance = 0;
	speed = sl;

	while (d > distance)
	{
		double cdistance = 0;
		double cfuel = 0;

		if (rand() % 2)
			speed += rand() % 6;
		else
			speed -= rand() % 6;
		//+40 limit max speed
		// +-20 radn new speed
		if (speed > sl + 40 || speed <= 0)
			if (rand() % 2)
				speed = sl + rand() % 21;
			else
				speed = sl - rand() % 21;
		//60 minutes in hour
		cdistance += speed * (1.0 / 60);
		distance += cdistance;

		//add fuel consumption when speed is difrent to fuelConsRate
		double multiper = abs(fuelConsRate - speed);
		cfuel = cdistance / MPG;
		if(multiper)
			cfuel *= (0.01 * multiper);
		fuel -= cfuel;
		if (fuel <= 0)
		{
			cout << "koniec paliwa";
			break;
		}

		cout << setprecision(3) << "przejachano: " << cdistance 
			<< " zuzyto paliwa: " << cfuel << " predkosc: " << speed << endl;
	}
	return distance;

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
