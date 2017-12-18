#include "tv.h"

int main()
{
	Tv tv_test;
	Remote r_test;

	tv_test.settings();
	r_test.settings();

	r_test.onoff(tv_test);
	r_test.chanup(tv_test);
	for (int i = 0; i < 5; i++)
		r_test.volup(tv_test);
	tv_test.set_rmode(r_test);

	tv_test.settings();
	r_test.settings();

	return 0;
}