#include <iostream>
#include "stcok3.h"

using std::cout;
using std::endl;
const int ST = 4;

int main()
{
	{
		Stock stocks[ST] =
		{
			Stock("NanoSmart", 12, 20.0),
			Stock("Buraki Ziemniaki", 200, 2.0),
			Stock("Gruz", 140, 3.25),
			Stock("Futra", 60, 6.5)
		};
		for (int i = 0; i < ST; i++)
			cout << stocks[i] << endl;
		const Stock *top = &stocks[0];
		for (int i = 0; i < ST; i++)
			top = &top->topval(stocks[i]);
		cout << "Najbogatsza spolka: " << endl
			<< *top << endl;
	}

	return 0;
}