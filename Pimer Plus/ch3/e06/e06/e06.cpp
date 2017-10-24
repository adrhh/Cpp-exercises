/*Write a program that asks how many miles you have driven and how many gallons
of gasoline you have used and then reports the miles per gallon your car has gotten.
Or, if you prefer, the program can request distance in kilometers and petrol in liters
and then report the result European style, in liters per 100 kilometers.*/

#include <iostream>

using namespace std;

int main()
{
	int distance_km;
	int used_l;

	cout << "Podaj przejachny dystans [km]: ";
	cin >> distance_km;
	cout << "Podaj zuzyte paliwo [l]: ";
	cin >> used_l;

	cout << "Zuzcie paliwa wynosi: "
		<< (100.0f * (float)used_l) / (float)distance_km
		<< " [l/100km]."
		<< endl;

	return 0;
}