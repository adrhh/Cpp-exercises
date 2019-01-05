#ifndef DATA_H_
#define DATA_H_

#include <iostream>

class dddata
{
public:
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t min;

	dddata(uint16_t y = 0, uint8_t mo = 0, uint8_t d = 0, uint8_t h = 0, uint8_t mi = 0)
		: year(y), month(mo), day(d), hour(h), min(mi) {}

	struct data_64
	{
		uint64_t y : 16,
				mo : 8,
				d  : 8,
				h  : 8,
				mi : 8,
				   : 0;
	};

	void from_64(uint64_t in)
	{
		union dc
		{
			data_64  d;
			uint64_t i;
		};
		dc dat;
		dat.i = in;
		year  = dat.d.y;
		month = dat.d.mo ;
		day   = dat.d.d;
		hour  = dat.d.h;
		min   = dat.d.mi;
	}

	uint64_t to_64() const
	{
		union dc
		{
			data_64  d;
			uint64_t i;
		};
		dc dat;
		dat.d.y  = year;
		dat.d.mo = month;
		dat.d.d  = day;
		dat.d.h  = hour;
		dat.d.mi = min;

		return dat.i;
	}
};

#endif // !DATA_H_
