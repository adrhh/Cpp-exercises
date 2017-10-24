/*Write a program that asks you to enter an automobile gasoline consumption figure
in the European style (liters per 100 kilometers) and converts to the U.S. style of
miles per gallon. Note that in addition to using different units of measurement, the
U.S. approach (distance / fuel) is the inverse of the European approach (fuel / dis-
tance). Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.Thus, 19
mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.*/

#include <iostream>

using namespace std;

const float KM100_TO_MIL = 62.14;
const float L_TO_GALL = 1.0 / 3.875;

int main()
{
	float l_per_km;

	cout << "Podaj zuzice paliwa [l/100km]: ";
	cin >> l_per_km;

	float miles_per_gall = KM100_TO_MIL / (l_per_km * L_TO_GALL);

	cout << "Co odpiwada zuzyciu [mil/gallon]: "
		<< miles_per_gall << endl;

	return 0;
}