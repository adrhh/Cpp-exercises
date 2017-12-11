#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int in1, in2, in3, out1, out2, out3;
	cout << "Podaj 3 liczby calkowite" << endl;
	cin >> in1 >> in2 >> in3;

	//without functions
	if (in1 <= in2 && in1 <= in3)
	{
		out1 = in1;
		if (in2 <= in3)
		{
			out2 = in2;
			out3 = in3;
		}
		else
		{
			out2 = in3;
			out3 = in2;
		}
	}
	else if(in2 <= in3 && in2 <= in3)
	{
		out1 = in2;
		if (in1 <= in3)
		{
			out2 = in1;
			out3 = in3;
		}
		else
		{
			out2 = in3;
			out3 = in1;
		}
	}
	else
	{
		out1 = in3;
		if (in1 <= in2)
		{
			out2 = in1;
			out3 = in2;
		}
		else
		{
			out2 = in2;
			out3 = in1;
		}
	}

	cout << out1 << ' ' << out2 << ' ' << out3 << endl;

	string si1, si2, si3, so1, so2, so3;
	cout << "Podaj trzy slowa" << endl;
	cin >> si1 >> si2 >> si3;

	if (si1 <= si2 && si1 <= si3)
	{
		so1 = si1;
		if (si2 <= si3)
		{
			so2 = si2;
			so3 = si3;
		}
		else
		{
			so2 = si3;
			so3 = si2;
		}
	}
	else if (si2 <= si3 && si2 <= si3)
	{
		so1 = si2;
		if (si1 <= si3)
		{
			so2 = si1;
			so3 = si3;
		}
		else
		{
			so2 = si3;
			so3 = si1;
		}
	}
	else
	{
		so1 = si3;
		if (si1 <= si2)
		{
			so2 = si1;
			so3 = si2;
		}
		else
		{
			so2 = si2;
			so3 = si1;
		}
	}

	cout << so1 << ' ' << so2 << ' ' << so3 << endl;

	return 0;
}