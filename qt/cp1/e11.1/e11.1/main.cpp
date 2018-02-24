
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	int answer = 0;

	do
	{
		int factArg = 0;
		int fact(1);
		factArg = QInputDialog::getInt(
			0, "Kalkulator silni", "Silnia: ", 1
		);
		cout << "Uzytwkonik wprowadzil: " << factArg << endl;
		int i = 2;
		while (i <= factArg)
		{
			fact *= i;
			i++;
		}
		QString response = QString("%1 silnia to %2.\n%3")
			.arg(factArg).arg(fact)
			.arg("Kolejne obliczenie?");
		answer = QMessageBox::question(0, "Jeszcze raz?", response,
			QMessageBox::Yes | QMessageBox::No);
	} while (answer == QMessageBox::Yes);

	return EXIT_SUCCESS;
}
