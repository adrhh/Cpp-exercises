#include "vect.h"
#include <cstdlib>
#include <ctime>
#include <limits.h>

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
	int n, avrg, min = INT_MAX, max = 0,
		i = 0, total = 0;

	
	cout << "Podaj ilos prob: ";
	while (cin >> n)
	{
		cout << "Podaj dlugosc kroku: ";
		if (!(cin >> dstep))
			break;
		cout << "Podaj dystans do przejscia: ";
		if (!(cin >> target))
			break;
		while(i++ < n)
		{
			while (result.magva() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				step.rect_mode();
				steps++;
			}
			min = (steps < min) ? steps : min;
			max = (steps > max) ? steps : max;
			total += steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		avrg = total / n;
		cout << "w " << n << " probach:" << endl
			<< "srednia: " << avrg << endl
			<< "max: " << max << endl
			<< "min: " << min << endl;
		i = 0;
		total = 0;
		min = INT_MAX;
		max = 0;
		cout << "Podaj ilos prob: ";
	}

	return 0;
}