#include "student.h"
#include <QtWidgets>

static QTextStream cout(stdout);

void show(Student* st);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Undergrad us("Jan z Bagna", 453, "Bagnologia", 5, 100);
	GradStudent gs("Jan z jaskini", 455, "muzyka", 6, GradStudent::ra);
	
	cout << us.toString() << endl;
	cout << gs.toString() << endl;
	show(&us);
	show(&gs);

	return 0;
}

void show(Student* st)
{
	cout << st->toString() << endl;
}