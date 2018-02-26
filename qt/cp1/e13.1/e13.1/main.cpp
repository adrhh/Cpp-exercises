#include <QtWidgets>
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	double celc = QInputDialog::getDouble(0, "Przelicznik stopni", "Stopnie C", 1);
	double faren = celc * (9.0 / 5.0) + 32;
	QString respose = QString("%1 stopni C = %2 F").arg(celc).arg(faren);
	QMessageBox::information(0, "wynik", respose);
	
	//linker subsystem console
	for (int i = 0; i < 100; i += 5)
		std::cout << i << " C = " << i * (9.0 / 5.0) + 32 << " F" << std::endl;

	return EXIT_SUCCESS;
}
