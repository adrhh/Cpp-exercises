#include <QtWidgets>
#include "student.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);
	Undergrad us("Jan z Bagna", 453, "Bagnologia", 5, 100);
	GradStudent gs("Jan z jaskini", 455, "muzyka", 6, GradStudent::ra);

	QMessageBox::information(0, "undergrad", us.toString());
	QMessageBox::information(0, "undergrad", gs.toString());
	
	return EXIT_SUCCESS;
}
