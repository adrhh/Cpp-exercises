#include <QtWidgets>
#include "fract.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	Fraction f1(1, 2), f2(1, 3), temp;
	cout << f1.toString() << "   " << f2.toString() << endl;
	temp = f1.add(f2);
	cout << temp.toString() << "   " << f1.toString() << endl;
	temp = f1.sub(f2);
	cout << temp.toString() << "   " << f1.toString() << endl;
	temp = f1.mult(f2);
	cout << temp.toString() << "   " << f1.toString() << endl;
	temp = f1.div(f2);
	cout << temp.toString() << "   " << f1.toString() << endl;

	return 0;
}
