#include "card.h"
#include <cstdlib>
#include <ctime>

QStringList Card::s_Suits = { "pik", "kier", "karo", "trefl" };
QStringList Card::s_Faces = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};


Card::Card(int face, int suit)
{
	if (face > s_Faces.size() || suit > s_Suits.size())
	{
		qDebug() << "nie porawna wartosc karty" << endl;
		m_FaceNbr = m_SuitNbr = 0;
	}
	else
	{
		m_FaceNbr = face;
		m_SuitNbr = suit;
	}
}

QString Card::toString() const
{
	QString retString = QString("%1 : %2")
		.arg(s_Suits[m_SuitNbr])
		.arg(s_Faces[m_FaceNbr]);

	return retString;
}

QString Card::getFace() const
{
	return QString("%1").arg(s_Faces[m_FaceNbr]);
}
QString Card::getSuit() const
{
	return QString("%1").arg(s_Suits[m_SuitNbr]);
}
int Card::getValue() const
{
	//A = 4, K = 3, D = 2, J = 1, numbers = 0
	int value = 0;
	switch (m_FaceNbr)
	{
	//A=4
	case 0:
		value = 4;
		break;
	//K=3
	case 12:
		value = 3;
		break;
	//Q=2
	case 11:
		value = 2;
		break;
	//J=1
	case 10:
		value = 1;
		break;
	default:
		value = 0;
		break;
	}

	return value;
}

CardDeck::CardDeck(int suits, int faces) : m_faces(faces), m_suits(suits)
{
	for (int i = 0; i < suits; i++)
		for (int j = 0; j < faces; j++)
			this->append(Card(j, i));
}

void CardDeck::restoreDeck()
{
	clear();
	*this = CardDeck(m_suits, m_faces);
}

int CardDeck::getCardsLeft() const
{
	return size();
}

CardHand CardDeck::deal(int handSize)
{
	srand(time(0));
	CardHand Hand;
	if (handSize > getCardsLeft())
		qDebug() << "za malo kart" << endl;
	else
	{
		int rNbr = 0;
		for (int i = 0; i < handSize; i++)
		{
			rNbr = rand() % getCardsLeft();
			Hand << at(rNbr);
			removeAt(rNbr);
		}
	}

	return Hand;
}