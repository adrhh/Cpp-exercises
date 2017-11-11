#include "vect.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{

	using namespace std;
	ofstream out;
	out.open("output.txt");
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
			out << steps << ": " << step << endl;
			steps++;
		}
		cout << "Potrzebne bylo krokow: " << steps << endl;
		out << "Potrzebne bylo krokow: " << steps << endl
			<< "dlugos kroku pozornego:" << result.magva() / steps << endl;
		cout << "Podaj dystans do przejscia: ";
		steps = 0;
		result.reset(0.0, 0.0);
	}
	out.close();

	return 0;
}