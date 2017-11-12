#include "stone.h"

using namespace std;

int main()
{
	const int Arrs = 6;
	Stone sarr[Arrs] =
	{
	Stone(162),
	Stone(5, 7),
	Stone(150),
	};

	for (int i = 0; i < Arrs; i++)
	{
		double temp;
		if (!sarr[i].isempty())
			continue;
		else
		{
			cout << "Podaj wage w funatch:" << endl;
			if (!(cin >> temp))
				break;
			else
				sarr[i] = Stone(temp);
		}
	}

	for (int i = 0; i < Arrs; i++)
		cout << sarr[i] << endl;

	Stone s11(11, 0);
	Stone max, min, total;
	int n11 = 0;

	max = min = sarr[0];
	for (int i = 0; i < Arrs; i++)
	{
		if (min > sarr[i])
			min = sarr[i];
		if (max < sarr[i])
			max = sarr[i];
		if (s11 < sarr[i])
			n11++;
		total = total + sarr[i];
	}

	cout << "min: " << min
		<< " max: " << max
		<< " ilosc mas wiekszych od 11st: " << n11
		<< " suma wszytkich: " << total << endl;

	return 0;
}