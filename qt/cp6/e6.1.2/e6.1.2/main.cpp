#include <QtextStream>
#include <QApplication>
#include <QMessageBox>
#include "student.h"

QTextStream cout(stdout);
QTextStream cerr(stderr);
const int LICLIM = 3;

void finish(Student* stud)
{
	
	int year = stud->yearInt();
	QString tyt = year <= LICLIM ? "licencjat" : "magister";
	QString msg = QString("%1 wnioskuje o tytul: %2")
		.arg(stud->toString()).arg(tyt);
	QMessageBox::information(0, "Tytul", msg);

}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Undergrad us("Frodo", 5562, "Zlotnik", 3, 1220);
	GradStudent gs("Bilbo", 3092, "Historia", 5, GradStudent::fellowship);

	QMessageBox msg(QMessageBox::Information, "Dane studneta", us.toString());
	msg.exec();
	msg.setText(gs.toString());
	msg.exec();

	//poliformizm nie dziala nie ma funkcji wirtualnych
	//wiazanie satyczne, w czasie kompilacji
	//wywolywane sa metody z klasy bazowej
	cout << "Funkcja przyjmujaca wskaznik na klase bazowa: ";
	finish(&us);
	finish(&gs);
	
	return EXIT_SUCCESS;
}
