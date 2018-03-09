#include "car.h"

int main()
{
	Car c1(20.0, 0, 30, 6);
	c1.drive(30, 10);
	c1.drive(50, 200);
	c1.addFuel(30);
	c1.drive(50, 200);
	c1.addFuel(30);
	c1.higwayDrive(100, 80);

	return 0;
}