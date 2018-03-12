#include <QtWidgets>
#include "emp.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Position p1("sprzatacz", "sprzata"), p2("magazynier", "magazynuje"),
		p3("krawcowa", "szyje"), p4("mechanik", "naprawia");

	Employer e1("Dobre Budy");
	e1.addPosition(p1);
	e1.addPosition(p2);
	e1.addPosition(p3);
	e1.addPosition(p4);
	QList<Position> open_pos = e1.findJobs();
	show_plist(open_pos);


	return EXIT_SUCCESS;
}
