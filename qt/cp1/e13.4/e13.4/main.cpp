#include <iostream>

using std::cout;
using std::endl;

struct Banknoty
{
	int zl50;
	int zl20;
	int zl10;
	int zl5;
	int zl2;
	int zl1;
	int gr50;
	int gr20;
	int gr10;
	int gr5;
	int gr2;
	int gr1;
	int total;
	void show() const;
	Banknoty(double n);
	Banknoty(int n);
};

int reszta(double wplata, double wyplata);

int main()
{
	Banknoty b1(179.99);
	b1.show();

	cout << reszta(200, 156.27);
	return 0;
}

int reszta(double wplata, double wyplata)
{
	Banknoty wp(wplata);
	Banknoty wy(wyplata);
	cout << wp.total - wy.total << endl;
	Banknoty reszta(wp.total - wy.total);
	//test show
	reszta.show();
	return reszta.total;
}

void Banknoty::show() const
{
	cout << "zl50 " << zl50
		<< " zl20 " << zl20
		<< " zl10 " << zl10
		<< " zl5 " << zl5
		<< " zl2 " << zl2
		<< " zl1 " << zl1
		<< " gr50 " << gr50
		<< " gr20 " << gr20
		<< " gr10 " << gr10
		<< " gr5 " << gr5
		<< " gr2 " << gr2
		<< " gr1 " << gr1;
	cout << endl;

}

Banknoty::Banknoty(double n) : zl50(0), zl20(0), zl10(0), zl5(0),
zl2(0), zl1(0), gr50(0), gr20(0),
gr10(0), gr5(0), gr2(0), gr1(0)
{
	double temp = n * 100;
	int tot = static_cast<int> (temp);
	total = tot;
	while (tot >= 50 * 100)
	{
		zl50 += 1;
		tot -= 50 * 100;
	}
	while (tot >= 20 * 100)
	{
		zl20 += 1;
		tot -= 20 * 100;
	}
	while (tot >= 10 * 100)
	{
		zl10 += 1;
		tot -= 10 * 100;
	}
	while (tot >= 5 * 100)
	{
		zl5 += 1;
		tot -= 5 * 100;
	}
	while (tot >= 2 * 100)
	{
		zl2 += 1;
		tot -= 2 * 100;
	}
	while (tot >= 1 * 100)
	{
		zl1 += 1;
		tot -= 1 * 100;
	}
	while (tot >= 50)
	{
		gr50 += 1;
		tot -= 50;
	}
	while (tot >= 20)
	{
		gr20 += 1;
		tot -= 20;
	}
	while (tot >= 10)
	{
		gr10 += 1;
		tot -= 10;
	}
	while (tot >= 5)
	{
		gr5 += 1;
		tot -= 5;
	}
	while (tot >= 2)
	{
		gr2 += 1;
		tot -= 2;
	}
	while (tot >= 1)
	{
		gr1 += 1;
		tot -= 1;
	}
}

Banknoty::Banknoty(int n) : zl50(0), zl20(0), zl10(0), zl5(0),
zl2(0), zl1(0), gr50(0), gr20(0),
gr10(0), gr5(0), gr2(0), gr1(0)
{
	int tot = n;
	total = tot;
	while (tot >= 50 * 100)
	{
		zl50 += 1;
		tot -= 50 * 100;
	}
	while (tot >= 20 * 100)
	{
		zl20 += 1;
		tot -= 20 * 100;
	}
	while (tot >= 10 * 100)
	{
		zl10 += 1;
		tot -= 10 * 100;
	}
	while (tot >= 5 * 100)
	{
		zl5 += 1;
		tot -= 5 * 100;
	}
	while (tot >= 2 * 100)
	{
		zl2 += 1;
		tot -= 2 * 100;
	}
	while (tot >= 1 * 100)
	{
		zl1 += 1;
		tot -= 1 * 100;
	}
	while (tot >= 50)
	{
		gr50 += 1;
		tot -= 50;
	}
	while (tot >= 20)
	{
		gr20 += 1;
		tot -= 20;
	}
	while (tot >= 10)
	{
		gr10 += 1;
		tot -= 10;
	}
	while (tot >= 5)
	{
		gr5 += 1;
		tot -= 5;
	}
	while (tot >= 2)
	{
		gr2 += 1;
		tot -= 2;
	}
	while (tot >= 1)
	{
		gr1 += 1;
		tot -= 1;
	}
}