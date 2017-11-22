#include <iostream>
#include <cstring>
#include "dma.h"

using std::endl;
using std::cout;

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

void baseDMA::view() const
{
	cout << label << endl;
	cout << rating << endl;
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

lackDMA::lackDMA(const baseDMA& bd, const char* c) : baseDMA(bd)
{
	strcpy(color, c);
}

void lackDMA::view() const
{
	baseDMA::view();
	cout << color << endl;
}

hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const baseDMA& bd, const char* s) : baseDMA(bd)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hd) : baseDMA(hd)
{
	style = new char[strlen(hd.style) + 1];
	strcpy(style, hd.style);
}
hasDMA::~hasDMA()
{
	delete[] style;
}
hasDMA& hasDMA::operator=(const hasDMA& hd)
{
	if (this == &hd)
		return *this;
	delete[] style;
	baseDMA::operator=(hd);
	strcpy(style, hd.style);

	return *this;

}
void hasDMA::view() const
{
	baseDMA::view();
	cout << style << endl;
}