#ifndef CARD_H_
#define CARD_H_

#include <QList>
#include <QString>
#include <QDebug>

class Card
{
private:
	int m_FaceNbr;
	int m_SuitNbr;
	static QStringList s_Faces;
	static QStringList s_Suits;
public:
	Card(int face = 0, int suit = 0);
	QString toString() const;
	QString getFace() const;
	QString getSuit() const;
	int getValue() const;
};

class CardHand : public QList<Card>
{
public:
	int getValue() const;
	QString toString() const;
};

class CardDeck : public QList<Card>
{
private:
	int m_suits;
	int m_faces;
public:
	//defalut deck 52 cards = 4 suit * 13 faces;
	CardDeck(int suits = 4, int faces = 13);
	void restoreDeck();
	CardHand deal(int handSize);
	int getCardsLeft() const;
};

#endif // !CARD_H_