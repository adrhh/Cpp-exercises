#include <iostream>
#include <vector>
#include <string>

using namespace std;

//max 0-9
int get_str_int(const string str);
const vector<string> Digs = { "zero", "jeden", "dwa", "trzy",
"cztery", "piec", "szesc", "siedem",
"osiem", "dziewiec" };


int main()
{

	int in1;
	int in2;
	string sin1;
	string sin2;
	string sin;
	char operat;
	
	cout << "wpisz dwie cyfry (slownie lub liczbowo) i operator dzialnia" << endl;
	cout << "k- byz zakonczyc" << endl;
	while (cin >> sin1 >> sin2 >> sin)
	{
		if (sin1[0] == 'k')
			break;
		try
		{
			in1 = get_str_int(sin1);
			in2 = get_str_int(sin2);
		}
		catch (const char* s)
		{
			cout << "Wpisz: " << endl;
			for (int i = 0; i < Digs.size(); i++)
				cout << Digs[i] << ' ';
			cout << endl;
			continue;
		}

		operat = sin[0];

		switch (operat)
		{
		case '+':
			cout << in1 << " + " << in2 << " = " << in1 + in2 << endl;
			break;
		case '-':
			cout << in1 << " - " << in2 << " = " << in1 - in2 << endl;
			break;
		case '/':
			cout << in1 << " / " << in2 << " = " << in1 / in2 << endl;
			break;
		case '*':
			cout << in1 << " * " << in2 << " = " << in1 * in2 << endl;
			break;
		default:
			cout << "nie porawny operator " << endl;
		}
		cout << "wpisz dwie cyfry (slownie lub liczbowo) i operator dzialnia" << endl;
	}


	return 0;
}

int get_str_int(const string str)
{
	int answ = -1;
	if (isdigit(str[0]))
		answ = stoi(str);
	else
	{
		for (int i = 0; i < Digs.size(); i++)
			if (str == Digs[i])
				answ = i;
	}
	if (answ == -1)
		throw "Niepoprawna cyfra";

	return answ;
}