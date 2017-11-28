#include "wine.h"

Wine::Wine() : label("Brak"), years(0), yers_bottles(ArrInt(), ArrInt())
{
};

Wine::Wine(const char*l, int y, const int yr[], const int bot[]) : label(l), years(y), yers_bottles(ArrInt(yr,y), ArrInt(bot,y)) 
{
}

int Wine::sum() const
{
	return yers_bottles.second().sum();
}