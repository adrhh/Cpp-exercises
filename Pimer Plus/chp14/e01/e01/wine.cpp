#include "wine.h"

Wine::Wine() : label("Brak"), years(0), yers_bottles(ArrInt(), ArrInt())
{
}

Wine::Wine(const char*l, int y, const int yr[], const int bot[]) : label(l), years(y), yers_bottles(ArrInt(yr,y), ArrInt(bot,y)) 
{
}

int Wine::sum()
{
<<<<<<< HEAD
	ArrInt& botref = yers_bottles.second();
	return botref.sum();
}
=======
	return yers_bottles.second().sum();
}
>>>>>>> a54cdf6319b2130b454a7ff0c92a918dba70c9ed
