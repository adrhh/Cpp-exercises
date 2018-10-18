#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//Pointers:
	int i = 0;
	int* const const_ptr = &i;			//const_ptr++ is prohibited
	const int* ptr_to_const = &i;		// (*ptr_to_const)++ is prohibited	
	int* ptr = &i;						//val of ptr is i adress and val of *ptr is i
	int** pptr = &ptr;					//val of *ptr is i adress 
										//val of **ptr is i
	int tab[3] = { 0,1,2 };				//array of 3 ints;
	int* ptab[3] = { ptr, ptr, ptr };	//array of 3 ptr;
	
	//access to array element, tab is adress of tab[0], tab+1 of tab[1] ...
	cout << "tab[1] val: " << tab[1] << " and *(tab +1): " << *(tab + 1) << endl;
	ptab[0] = tab; ptab[1] = tab + 1; ptab[2] = tab + 2;
	for (unsigned int i = 0; i < sizeof(tab)/sizeof(int); ++i) 
	{
		cout << &tab[i] << " = " <<  ptab[i] << endl;    
		cout <<  tab[i] << " = " << *ptab[i] << endl;
	}				
	int arr2d[3][3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }; //2d array, first row is initialize by tab 
	int (*p2d)[3] = &arr2d[0];					     //pointer to element of 3 ints
	
	for(int i = 0; i < 3; ++i)						//2d array[n][m] is linear space n*m size
	{												//print using C cast;
		int* ptr = (int*)p2d;
		for (int j = 0; j < 3; ++j)
		{
			cout << *(ptr + j) << ' ';
		}
		p2d++;
		cout << endl;
	}
	for (int* ptr = &arr2d[0][0]; ptr != &arr2d[2][2 + 1]; ++ptr) //another way by casting
		cout << *ptr << ' ';

	return 0;
}