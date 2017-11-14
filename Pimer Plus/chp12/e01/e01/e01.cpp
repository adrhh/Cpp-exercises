#include "cow.h"
#include <iostream>


int main()
{
	{
		Cow krowa1;
		Cow krowa2("Mucka", "Wypas", 1600);
		Cow krowa3 = krowa1;
		Cow krowa4;
		krowa4 = krowa2;
		krowa1.ShowCow();
		krowa2.ShowCow();
		krowa3.ShowCow();
		krowa4.ShowCow();
	}

	std::cout << "Koniec\n";

	return 0;
}