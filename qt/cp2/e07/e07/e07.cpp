#include "static.h"
#include <iostream>

using std::endl;
using std::cout;

int Client::SavedId(1000);

int main()
{
	Client cust1("Grzegorz");
	cout << cust1.getID() << endl;
	cout << Client::getSavedID() << endl;
}