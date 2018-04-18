#include "card.h"
#include <QTextStream>
#include <QtWidgets>
#include <QtGui>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextStream cout(stdout);
	CardDeck deck;
	CardHand hand;
	int hSize, pScore, progScore;
	cout << "ile kart dla jednego gracza?" << flush;
	hSize = QInputDialog::getInt(0, QString("getInt()"),
		QString("ile kart na rece?"), 1, 5);
	QMessageBox::StandardButton sb;
	do 
	{
		hand = deck.deal(hSize);
		cout << "Oto towje karty:" << endl;
		cout << hand.toString() << endl;
		pScore = hand.getValue();
		cout << QString("Twoj wynik to: %1").arg(pScore) << endl;

		hand = deck.deal(hSize);
		progScore = hand.getValue();
		cout << "Oto moje karty:" << endl;
		cout << hand.toString() << endl;
		progScore = hand.getValue();
		cout << QString("Moj wynik to: %1").arg(pScore) << endl;
		cout << QString("%1 wygrywa")
			.arg((pScore >= progScore) ? "Ty" : "Ja") << endl;
		sb = QMessageBox::question(0, QString("QMessageBox::question()"),
			QString("Kolejne rozdanie"), QMessageBox::Yes | QMessageBox::No);

	} while (sb == QMessageBox::Yes);

	return 0;
}
