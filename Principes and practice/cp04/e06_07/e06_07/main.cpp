#include <iostream>
#include <vector>
#include <string>

using namespace std;

//max 0-9
int get_str_int(const string str);

int main()
{
	const vector<string> Digs = { "zero", "jeden", "dwa", "trzy",
							"cztery", "piec", "szesc", "siedem",
							"osiem", "dziewiec" };

	int in1;
	int in2;
	string in;
	



	return 0;
}

int get_str_int(const string str)
{
	int answ;
	char temp= str[0];
	if (isdigit(temp))
		answ = atoi(temp);
	else
	{

	}


}