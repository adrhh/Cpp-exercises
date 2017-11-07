#include <iostream>
#include <cstring>
#include "golf.h"

using std::cout;
using std::cin;
using std::endl;

void setgolf(golf &g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

void setgolf(golf &g)
{
	cout << "Podaj imie gracza:" << endl;
	cin.getline(g.fullname, LEN);
	cout << "Podaj handicap: " << endl;
	cin >> g.handicap; 
	cin.get();
}

void showgolf(const golf &g)
{
	cout << "Imie gracza: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
