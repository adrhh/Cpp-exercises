/* Write a template function  maxn() that takes as its arguments an array of items of
type T and an integer representing the number of elements in the array and that
returns the largest item in the array.Test it in a program that uses the function tem-
plate with an array of six  int value and an array of four  double values.The pro-
gram should also include a specialization that takes an array of pointers-to- char as
an argument and the number of pointers as a second argument and that returns the
address of the longest string. If multiple strings are tied for having the longest
length, the function should return the address of the first one tied for longest.Test
the specialization with an array of five string pointers.*/

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(T* t, int n);

template <> 
char* maxn<char* >(char** s, int n);


int main()
{
	double d_arr[4] = { 3.0, 3.5, 4.9, 1.001 };
	int i_arr[5] = { 3, 5, 1, 9, 2 };
	char* max;

	char* s_arr[5] =
	{	"tak",
		"nie",
		"6liter",
		"liter6",
		"!!"
	};

	cout << maxn(d_arr, 4) << endl;
	cout << maxn(i_arr, 5) << endl;
	max = maxn(s_arr, 5);
	cout << max << endl;

	return 0;
}

template <typename T>
T maxn(T* t, int n)
{
	int i = 0;
	T max = t[i];
	for (int i = 0; i < n; i++)
		if (max < t[i])
			max = t[i];
	return max;
}

template <>
char* maxn<char* >(char** s, int n)
{
	int m_len = strlen(s[0]);
	char* max = s[0];
	for (int i = 0; i < n; i++)
		if (strlen(s[i]) > m_len)
		{
			m_len = strlen(s[i]);
			max = s[i];
		}
	return max;
}