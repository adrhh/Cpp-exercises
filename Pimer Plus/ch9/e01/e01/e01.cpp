/*
Here is a header file:
// golf.h -- for pe9-1.cpp
const int Len = 40;
struct golf
{
char fullname[Len];
int handicap;
};
// non-interactive version:
//  function sets golf structure to provided name, handicap
//  using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc);
// interactive version:
//  function solicits name and handicap from user
//  and sets the members of g to the values entered
//  returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g);
// function resets handicap to new value
void handicap(golf & g, int hc);
// function displays contents of golf structure
void showgolf(const golf & g);
Note that setgolf() is overloaded. Using the first version of setgolf() would
look like this:
golf ann;
setgolf(ann, "Ann Birdfree", 24);
The function call provides the information that’s stored in the  ann structure. Using
the second version of  setgolf() would look like this:
golf andy;
setgolf(andy);
The function would prompt the user to enter the name and handicap and store
them in the  andy structure.This function could (but doesn’t need to) use the first
version internally.
Put together a multifile program based on this header. One file, named  golf.cpp ,
should provide suitable function definitions to match the prototypes in the header
file.A second file should contain  main() and demonstrate all the features of the
prototyped functions. For example, a loop should solicit input for an array of golf
structures and terminate when the array is full or the user enters an empty string
for the golfer’s name.The  main() function should use only the prototyped func-
tions to access the golf structures. */



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
