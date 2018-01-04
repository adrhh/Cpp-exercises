#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using std::queue;
using std::cin;
using std::endl;
using std::cout;
const int MIN_PER_HR = 60;

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime;  }
};

void Customer::set(long when)
{
	processtime = rand() % 3 + 1;
	arrive = when;
}

bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}

int main()
{
	typedef Customer Item;
	srand(time(0));

	cout << "Podaj masymalna dlugosc kolejki: " << endl;
	int qs;
	cin >> qs;

	cout << "Podaj symulowany czas: " << endl;
	int hours;
	cin >> hours;
	long cycle_limit = MIN_PER_HR * hours;

	cout << "Podaj srednia liczbe klinetow na godzine: " << endl;
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	queue<Item> line;
	int max_size = qs;

	for (int cycle = 0; cycle < cycle_limit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.size() >= max_size)
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;

		sum_line += line.size();
	}

	if (customers > 0)
	{
		cout << "przyjeci: " << customers << endl;
		cout << "obsluzeni: " << served << endl;
		cout << "odeslani: " << turnaways << endl;
		cout << "srednia: " << (double)sum_line / cycle_limit << endl;
		cout << "sredni czas: " << (double)line_wait / served << endl;
	}
	else
		cout << "brak klinetow" << endl;

	return 0;
}