#include <iostream>

const int MAXW = 5;
const int ILECHOMIK = 5;

//gerneruje sumy prefiksowa chomikow na podstawie ich wieku
int** presum(int* t, int n, int* s, int m);
//testowannie sumy prefiksowej
void poka(int** t, int n, int m);
void usun(int** t);

//0 - brack chomika, -1 blad, n-najmlodszy chomik z przedzialu {x..y}
int zadanie(int**t, int n, int m, int x, int y);

int main()
{
	
	int wiek[MAXW] = { 1,2,3,4,5 };
	int chomiki[ILECHOMIK] = { 2,3,4,3,1 };
	int** ilejest;
	ilejest = presum(wiek, MAXW, chomiki, ILECHOMIK);
	poka(ilejest, MAXW, ILECHOMIK); //test

	// wejscie zadania;
	int ileprob = 3;
	//proby z tresci 1,3; 2,5; 2,4
	std::cout << zadanie(ilejest, MAXW, ILECHOMIK, 1, 3) << std::endl;
	std::cout << zadanie(ilejest, MAXW, ILECHOMIK, 2, 5) << std::endl;
	std::cout << zadanie(ilejest, MAXW, ILECHOMIK, 2, 4) << std::endl;

	for (int i = 0; i < MAXW; i++)
		delete[] ilejest[i];
	delete[] ilejest;

	return 0;
}

int** presum(int* t, int n, int* s, int m)
{
	int** psum;
	psum = new int*[n];
	//alkocajca pamieci z zerowaniem
	for (int i = 0; i < n; i++)
		psum[i] = new int[m] {0};

	//tablica sum prefiksowych dla poszczegulnych wiekow (z t[i])
	for (int i = 0; i < n; i++)
	{
		psum[i][0] = (t[i] == s[0]) ? 1 : 0;

		for (int j = 1; j < m; j++)
		{
			if (s[j] == t[i])
				psum[i][j] = 1;
			psum[i][j] += psum[i][j - 1];
		}
	}
	return psum;
}

void poka(int** t, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << t[i][j] << " ";
		std::cout << std::endl;
	}
}


int zadanie(int**t, int n, int m, int x, int y)
{
	//x y okreslaja przedzial poszukiwan
	x -= 1, y -= 1; // Przesuniecie indeksow, na "od zera"

	//nieporawane dane wejscia, zapytanie poza zasieg tablicy
	if (y > m)
		return -1;

	int min=0;
	for (int i = n-1; i >= 0; i--)
	{ 
		//test
		//std::cout << std::endl << t[i][y] << " " << t[i][x] << " " << i << std::endl;
		if (t[i][y] - t[i][x])
			min = i+1;
	}
	return min;
}