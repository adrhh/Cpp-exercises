/* Modify Listing 8.14 so that it uses two template functions called  SumArray() to
return the sum of the array contents instead of displaying the contents.The pro-
gram now should report the total number of things and the sum of all the debts.*/

#include <iostream>

using namespace std;

template <typename T>
void show_array(T arr[], int n);

template <typename T>
void show_array(T* arr[], int n);

template <typename T>
T sum_array(T arr[], int n);

template <typename T>
T sum_array(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	int things[6] = { 12, 31, 103, 301, 210, 130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolf", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};

	double *pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	show_array(things, 6);
	cout << sum_array(things, 6) << " suma dlogow" << endl;
	show_array(pd, 3);
	cout << sum_array(pd, 3) << " suma dlogow" << endl;

	return 0;
}

template <typename T>
void show_array(T arr[], int n)
{
	cout << "Szablon A" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void show_array(T* arr[], int n)
{
	cout << "Szablon B" << endl;
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}

template <typename T>
T sum_array(T arr[], int n)
{
	T total = 0;
	for (int i = 0; i < n; i++)
		total += arr[i];

	return total;
}

template <typename T>
T sum_array(T* arr[], int n)
{
	T total = 0;
	for (int i = 0; i < n; i++)
		total += *arr[i];

	return total;
}