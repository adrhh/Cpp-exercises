#include <iostream>
#include <cstring>
#include "dma.h"

baseDMA::baseDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& bd)
{
	label = new char[strlen(bd.label) + 1];
	strcpy(label, bd.label);
	rating = bd.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;
}
baseDMA& baseDMA::operator=(const baseDMA& bd)
{
	if (this == &bd)
		return *this;

	delete[] label;
	label = new char[strlen(bd.label) + 1];
	strcpy(label, bd.label);
	rating = bd.rating;

	return *this;
}



lackDMA::lackDMA(const char* c, const char* l, int r) : baseDMA(l, r)
{
	strcpy(color, c);
}
lackDMA::lackDMA(const lackDMA& ld) : baseDMA(ld)
{
	strcpy(color, ld.color);
}
lackDMA& lackDMA::operator=(const lackDMA& ld)
{
	if (this == &ld)
		return *this;
	baseDMA::operator=(ld);
	strcpy(color, ld.color);
}

lackDMA::lackDMA(const baseDMA& bd, const char* c = "brak") : baseDMA(bd)
{
	strcpy(color, c);
}


void lackDMA::view() const
{

}

hasDMA::hasDMA(const char* s, const char* l, int r)
{

}
hasDMA::hasDMA(const char* s = "brak", const baseDMA* bd)
{

}
hasDMA::hasDMA(const hasDMA& hd)
{

}
hasDMA::~hasDMA()
{

}
hasDMA& hasDMA::operator=(const hasDMA& hd)
{

}
void hasDMA::view() const
{

}