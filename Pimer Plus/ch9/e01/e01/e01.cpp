#include <iostream>
#include "golf.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char temp[LEN];
	int temp_hc;
	golf test_arr[ARRSIZE];
	static int size;
	
	cout << "Podaj dane gracza: " << endl;
	cout << "Imie: " << endl;
	cin.getline(temp, LEN);
	while (temp[0] != '\0' && size < ARRSIZE)
	{
		cout << "Handicap: " << endl;
		cin >> temp_hc;
		cin.get();
		setgolf(test_arr[size], temp, temp_hc);
		size++;
		cout << "Podaj kolejnego gracza: " << endl;
		cin.getline(temp, LEN);
		
	}

	for (int i = 0; i < size; i++)
		showgolf(test_arr[i]);
	
	if(size < LEN)
	{
		cout << "Dodaj koljengoe gracza: " << endl;
		setgolf(test_arr[size++]);
	}

	for (int i = 0; i < size; i++)
		showgolf(test_arr[i]);

	return 0;
}