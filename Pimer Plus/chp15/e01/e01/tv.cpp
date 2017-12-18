#include "tv.h"
#include <iostream>

using std::cout;
using std::endl;

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	cout << "Telewizor jest: " << (state == Off ? "wylaczony" : "wlaczony") << endl;
	if (state == On)
	{
		cout << "glosnosc: " << volume << endl;
		cout << "kanal: " << channel << endl;
		cout << "tryb: " << (mode == Antenna ? "antena" : "kabel") << endl;
		cout << "wejscie: " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::set_rmode(Remote& r)
{
	if (state == On)
		r.r_mode = (r.r_mode == Remote::Normal) ? Remote::Inter : Remote::Normal;
}

void Remote::settings() const
{
	cout << "Pilot dziala w trybie: " << (r_mode == Normal ? "normalnym" : "interaktywnym") << endl;
}
