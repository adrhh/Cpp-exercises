/* Write a program that asks the user to enter the number of seconds as an integer
value (use type  long , or, if available, long long ) and that then displays the equiva-
lent time in days, hours, minutes, and seconds. Use symbolic constants to represent
the number of hours in the day, the number of minutes in an hour, and the number
of seconds in a minute.The output should look like this:
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds*/

#include <iostream>

using namespace std;

const int H_IN_DAY = 24;
const int MIN_IN_H = 60,
		  SEC_IN_MIN = 60;

int main()
{
	long long t_sec;

	cout << "Podaj liczbe skeund: ";
	cin >> t_sec;

	int sec = t_sec % SEC_IN_MIN;
	int t_min = t_sec / SEC_IN_MIN;
	int min = t_min % MIN_IN_H;
	int t_h = t_min / MIN_IN_H;
	int h = t_h % H_IN_DAY;
	int days = t_h / H_IN_DAY;

	cout << t_sec << " sekund to "
		<< days << " dni "
		<< h << " godzin "
		<< min << " minut "
		<< sec << " sekund" << endl;

	return 0;
}