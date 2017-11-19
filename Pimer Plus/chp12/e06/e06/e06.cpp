#include <iostream>
#include <cstdlib>            
#include <ctime>               
#include "qe.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x);

using namespace std;

int main()
{
	using std::cout;

	srand(time(0));

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	cout << "Podaj maksymalna dlugosc kolejki: ";
	int qs;
	cin >> qs;

	cout << "Podaj symulowany czas (w godzinach): ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	double perhour;
	double min_per_cust;
	double avrg_permin = 999.0;

	long turnaways = 0;
	long customers = 0;
	long all_people = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	long line_wait = 0;


	bool test = true;

	while (test)
	{
		for (perhour = 2000; perhour >= 1; perhour--)
		{
			if (avrg_permin <= 1.0)
			{
				test = false;
				break;
			}

			min_per_cust = MIN_PER_HR / perhour;
			Item temp;
			Queue line1(qs);
			Queue line2(qs);

			turnaways = 0;
			customers = 0;
			served = 0;
			sum_line = 0;
			line_wait = 0;
			wait_time1 = 0;
			wait_time2 = 0;
			all_people = 0;

			for (int cycle = 0; cycle < cyclelimit; cycle++)
			{
				if (newcustomer(min_per_cust))
				{
					all_people++;
					if (line1.isfull() && line2.isfull())
						turnaways++;
					else
					{
						temp.set(cycle);
						if(line1.isfull())
						{
							customers++;
							line2.enqueue(temp);
						}
						else if (line2.isfull())
						{
							customers++;
							line1.enqueue(temp);
						}
						else if (line1.qcount() < line2.qcount())
						{
							customers++;
							line1.enqueue(temp);
						}
						else
						{
							customers++;
							line2.enqueue(temp);
						}
					}

	
				}
				if (wait_time1 <= 0 && !line1.isempty())
				{
					line1.dequeue(temp);
					wait_time1 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}

				if (wait_time1 > 0)
					wait_time1--;

				if (wait_time2 <= 0 && !line2.isempty())
				{
					line2.dequeue(temp);
					wait_time2 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}

				if (wait_time2 > 0)
					wait_time2--;

				sum_line += line1.qcount() + line2.qcount();
			}

			avrg_permin = (double)line_wait / (double)served;


			if (customers > 0)
			{
				cout << "Wszytkich ludzi: " << all_people << endl;
				cout << "Kleintow na godzine: " << perhour << endl;
				cout << "liczba klientow przyjetych: " << customers << endl;
				cout << "liczba klientow obsluzonych: " << served << endl;
				cout << "liczba klientow odeslanych: " << turnaways << endl;
				cout << "srednia dlugosc kolejki: ";
				cout.precision(2);
				cout.setf(ios_base::fixed, ios_base::floatfield);
				cout.setf(ios_base::showpoint);
				cout << (double)sum_line / cyclelimit << endl;
				cout << "sredni czas oczekiwania: "
					<< avrg_permin << " minut\n";
			}
			else
				cout << "Brak klientow!\n";
			}
		
	}

	return 0;
}


bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}

