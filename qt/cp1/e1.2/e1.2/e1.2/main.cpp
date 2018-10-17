#include <QtextStream>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QBuffer>

QTextStream cout(stdout);
QTextStream cerr(stderr);
QTextStream cin(stdin);

int main(int argc, char *argv[])
{
	QString str, newstr;
	QTextStream strbuf(&str);

	int luck(7);
	float pi(3.14);
	double e(2.71);

	cout << "Strumien w pamieci" << endl;
	strbuf << "szczeliwy: " << luck << endl
		<< "pi: " << pi << endl
		<< "e: " << e << endl;
	cout << str;

	QFileInfo isOk("my_data");
	bool writeToFile = true;
	if(isOk.exists())
	{ 
		char choice;
		cout << "Pilk istnieje, nadpias [Y\\N] ?" << endl;
		cin >> choice;
		cin.flush();
		if (choice == 'Y')
			writeToFile = true;
		else
			cout << "Pominieto zapis" << endl;
	}


	QFile data("my_data");
	data.open(QIODevice::WriteOnly);
	QTextStream out(&data);
	out << str;
	data.close();
	
	//czytaj do zmiennych o roznych typach
	//newstr czyta do string do spacji
	//kolejne wszytwane sa zmienne o zadanym tyype
	cout << "Odczyt z pliku, UWAGA na zmiane typow" << endl;
	if (data.open(QIODevice::ReadOnly))
	{
		QTextStream in(&data);
		int r_luck;
		in >> newstr >> r_luck;
		float r_pi;
		in >> newstr >> r_pi;
		double r_e;
		in >> newstr >> r_e;
		data.close();

		cout << r_luck << ", "  //!!
			<< r_pi << ", "
			<< r_e << endl;
	}

	//zle poniweaz wczyta zanki do liczby
	/* 
	if (data.open(QIODevice::ReadOnly))
	{
		QTextStream in(&data);
		int r_luck;
		in >> r_luck;
		float r_pi;
		in >> r_pi;
		double r_e;
		in >>  r_e;
		data.close();

		cout << r_luck << ", "  //!!
			<< r_pi << ", "
			<< r_e << endl;
	}*/

	//czytaj linia po lini
	cout << "Odczyt z pliku: " << endl;
	if (data.open(QIODevice::ReadOnly))
	{
		QTextStream in(&data);
		while (!in.atEnd())
		{
			newstr = in.readLine();
			cout << newstr << endl;
		}
		data.close();
	}
	return EXIT_SUCCESS;
}
