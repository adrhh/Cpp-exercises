#include "emp.h"

int main()
{
	Employer empF("flota", "Chiny");
	Employer empR("ryby", "Wlochy");

	Position ryb1("rybak", "lowi ryby");
	Position ryb2("rybak", "lowi ryby");
	Position ryb3("rybak", "lowi ryby");
	Position mech("mechanik", "naprawia");
	Position kuch("kucharz", "gotuje");

	Person jan("Jan");
	Person adm("Adam");
	Person jul("Julia");
	Person mich("Michal");
	Person gorz("Malgorzata");

	empF.hire(jan, ryb1);
	empF.hire(adm, ryb2);
	empF.hire(jul, ryb3);
	empR.hire(mich, mech);
	empR.hire(gorz, kuch);

	std::cout << empF.employeesToString() << std::endl;
	std::cout << empR.employeesToString() << std::endl;


	return 0;
}