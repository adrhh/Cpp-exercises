/*Write a program that asks the user to enter a latitude in degrees, minutes, and sec-
onds and that then displays the latitude in decimal format.There are 60 seconds of
arc to a minute and 60 minutes of arc to a degree; represent these values with sym-
bolic constants.You should use a separate variable for each input value.A sample
run should look like this:
Enter a latitude in degrees, minutes, and seconds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees*/

#include <iostream>

const int MIN_IN_DEGREE = 60, 
		  SEC_IN_MIN = 60;

using namespace std;

int main()
{
	int deg, min, sec;
	float deg_decimal;

	cout << "Podaj stopnie: ";
	cin >> deg;
	cout << "Podaj minuty: ";
	cin >> min;
	cout << "Podaj sekundy: " ;
	cin >> sec;

	deg_decimal = deg + ( (float) min + (float) sec / SEC_IN_MIN ) / MIN_IN_DEGREE;

	cout << deg << " stopni, "
		<< min << " minut, "
		<< sec << " sekund = "
		<< deg_decimal << " stopni."
		<< endl;

	return 0;
}