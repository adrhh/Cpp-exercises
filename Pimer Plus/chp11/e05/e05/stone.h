#ifndef STONE_H_
#define STONE_H_

#include <iostream>

enum Mode { ST, LBI, LBF };

class Stone
{
private:
	enum { Lbs_per_stn = 14 };
	Mode mode;
	int stone;
	double pds_left;
	double punds;
public:
	Stone(double lbs);
	Stone(int st, double lbs);
	Stone();
	~Stone() {};
	void set_mode(Mode n);
	bool isempty() { return !punds ? true : false; }
	bool operator<(const Stone &s);
	bool operator<=(const Stone &s);
	bool operator>(const Stone &s);
	bool operator>=(const Stone &s);
	bool operator==(const Stone &s);
	bool operator!=(const Stone &s);
	Stone operator+(const Stone &s);
	Stone operator-(const Stone &s);
	Stone operator*(int n);
	friend Stone operator*(int n, const Stone &s);
	friend std::ostream & operator<<(std::ostream & os, const Stone &s);
};

#endif // !STONE_H_