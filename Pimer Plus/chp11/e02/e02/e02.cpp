#include "vect.h"
#include <cstdlib>
#include <ctime>

int main()
{

	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Podaj dystans do przejscia: ";
	while (cin >> target)
	{
		cout << "Podaj dlugosc kroku:";
		if (!(cin >> dstep))
			break;
		while (result.magva() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			step.rect_mode();
			steps++;
		}
		cout << "Potrzebne bylo krokow: " << steps << endl;
		cout << "Podaj dystans do przejscia: ";
		steps = 0;
		result.reset(0.0, 0.0);
	}

	return 0;
}