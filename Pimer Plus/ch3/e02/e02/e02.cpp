/*Write a short program that asks for your height in feet and inches and your weight
in pounds. (Use three variables to store the information.) Have the program report
your body mass index (BMI).To calculate the BMI, first convert your height in feet
and inches to your height in inches (1 foot = 12 inches).Then convert your height
in inches to your height in meters by multiplying by 0.0254.Then convert your
weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
your BMI by dividing your mass in kilograms by the square of your height in
meters. Use symbolic constants to represent the various conversion factors.*/

#include <iostream>

const int INCHES_IN_FOOT = 12;
const float INCHES_TO_METER = 0.0254;
const float POUNDS_TO_KG = 2.2;

using namespace::std;

int bmi_f(float, float);

int main()
{
	int inches, foots, total_inches, bmi;
	float pounds, kg, m;

	cout << "Podaj swoj rozmiar w stopach i calach: ";
	cin >> foots >> inches;
	cout << "Podaj swoja wage w funtach: ";
	cin >> pounds;

	total_inches = inches + foots * INCHES_IN_FOOT;
	m = total_inches * INCHES_TO_METER;
	kg = pounds / POUNDS_TO_KG;
	bmi = bmi_f(m, kg);

	cout << "Twoj wspolczynnik bmi wynosi: " << bmi << endl;

	return 0;
}

int bmi_f(float height, float weight)
{
	return weight / (height * height);
}