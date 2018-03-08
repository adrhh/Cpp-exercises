#ifndef CAR_H_
#define CAR_H_

class Car
{
private:
	double fuel;
	double odmoter;
	double tankCap;
	double MPG;
	double speed;
public:
	Car(double f, double o, double t, double m);
	double addFuel(double gal);
	double drive(double s, int m);
	double getSpeed() const { return speed; }
	double getTankC() const { return tankCap; }
	double getMPG() const { return MPG; }
	double getFuel() const { return fuel; }
	double getOdo() const { return odmoter; }
	void status() const;
};
#endif // !CAR_H_
