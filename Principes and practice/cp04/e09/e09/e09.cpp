#include <iostream>
#include <limits.h>
#include <limits>

using std::cout;
using std::endl;


int main()
{
	
	short stot = 0;
	short sact = 2;
	int step = 1;

	cout << "short" << endl;
	while (stot >= 0)
	{
		cout << step << " " << sact << " " << stot << endl;
		stot += sact;
		sact *= 2;
		step++;
	}

	int itot = 0;
	int iact = 2;
	int itep = 1;

	cout << endl << "int" << endl;
	while (itot >= 0)
	{
		cout << itep << " " << iact << " " << itot << endl;
		itot += iact;
		iact *= 2;
		itep++;
	}
	double dtot = 0;
	double dact = 2;
	int dtep = 1;

	cout << endl << "double" << endl;
	while (dtot < DBL_MAX)
	{
		cout << dtep << " " << dact << " " << dtot << endl;
		dtot += dact;
		dact *= 2;
		dtep++;
	}

	long double ldtot = 0;
	long double ldact = 2;
	int ldtep = 1;

	cout << endl << "long double" << endl;
	while (ldtot < std::numeric_limits<long double>::max())
	{
		cout << ldtep << " " << ldact << " " << ldtot << endl;
		ldtot += ldact;
		ldact *= 2;
		ldtep++;
	}


	return 0;
}