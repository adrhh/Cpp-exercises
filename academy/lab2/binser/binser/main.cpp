#include <iostream>

using std::endl;
using std::cout;

template <class T> int binSerach(T arrPtr[], int arrSize, T val);
template <class T> void quickSort(T arrPtr[], int left, int right);

int main()
{
	const int ARRSize = 8;
	int arrTest[ARRSize] = { 1,4,6,2,0,10,3,1 };
	quickSort(arrTest, 0, ARRSize-1);

	for (int i = 0; i < ARRSize; i++)
		cout << arrTest[i] << " ";
	cout << endl;

	cout << "indeks elemntu o wartosi 10 = " << binSerach(arrTest, ARRSize, 10) << endl;
	cout << "indeks elemntu o wartosi 4 = " << binSerach(arrTest, ARRSize, 4) << endl;

	return 0;
}

template <class T> void quickSort(T arrPtr[], int left, int right)
{
	int i = left;
	int j = right;
	int x = arrPtr[(left + right) / 2];
	do
	{
		while (arrPtr[i] < x)
			i++;

		while (arrPtr[j] > x)
			j--;

		if (i <= j)
		{
			T temp = arrPtr[i];
			arrPtr[i] = arrPtr[j];
			arrPtr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) 
		quickSort(arrPtr, left, j);

	if (right > i) 
		quickSort(arrPtr, i, right);
}

template <class T> int binSerach(T arrPtr[], int arrSize, T val)
{
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;
	int index = -1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arrPtr[mid] == val)
		{
			index = mid;
			break;
		}
		else
		{
			if (arrPtr[mid] < val)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return index;
}