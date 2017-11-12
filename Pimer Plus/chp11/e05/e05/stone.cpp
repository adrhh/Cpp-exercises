#include "stone.h"

Stone::Stone()
{
	stone = pds_left = punds = 0;
	mode = ST;
}


Stone::Stone(double lbs)
{
	stone = (int)lbs / Lbs_per_stn;
	pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
	punds = lbs;
	mode = ST;
}

Stone::Stone(int st, double lbs)
{
	stone = st;
	pds_left = lbs;
	punds = lbs + st*Lbs_per_stn;
	mode = ST;
}

std::ostream & operator<<(std::ostream & os, const Stone &s)
{
	switch (s.mode)
	{
	case ST:
		os << s.stone << " kamieni";
		if (s.pds_left)
			os << " " << s.pds_left << " funtow";
		break;
	case LBI:
		os << (int)(s.punds + 0.5) << " funtow";
		break;
	case LBF:
		os << s.punds << " funtow";
		break;
	default:
		os << "Blad wyjscia ";
		break;
	}
	return os;
}

Stone Stone::operator+(const Stone &s)
{
	double sum = punds + s.punds;

	return Stone(sum);
}

Stone Stone::operator-(const Stone &s)
{
	double dif = punds - s.punds;

	return Stone(dif);
}

Stone Stone::operator*(int n)
{
	return Stone(n * punds);
}

Stone operator*(int n, const Stone &s)
{
	return Stone(n * s.punds);
}

void Stone::set_mode(Mode n)
{
	mode = n;
}

bool Stone::operator<(const Stone &s)
{
	return punds < s.punds ? true : false;
}
bool Stone::operator<=(const Stone &s)
{
	return punds <= s.punds ? true : false;
}
bool Stone::operator>(const Stone &s)
{
	return punds > s.punds ? true : false;
}
bool Stone::operator>=(const Stone &s)
{
	return punds >= s.punds ? true : false;
}
bool Stone::operator==(const Stone &s)
{
	return punds == s.punds ? true : false;
}
bool Stone::operator!=(const Stone &s)
{
	return punds != s.punds ? true : false;
}