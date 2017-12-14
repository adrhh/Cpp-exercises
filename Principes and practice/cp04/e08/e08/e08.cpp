#include <iostream>

using std::cout;
using std::endl;


int main()
{
	long total = 0;
	long act = 2;
	int step = 1;
	long Max = 1000000000;
	while (total < Max)
	{
		cout << "W kroku: " << step << " dostaje " << act << " ziaren ryzu";
		cout << " lacznie mam: " << total << endl;
		total += act;
		act *= 2;
		step++;
	}
	cout << " w kroku: " << step << " dostaje " << act << " ziaren ryzu";
	cout << "lacznie mam: " << total << endl;

	return 0;
}