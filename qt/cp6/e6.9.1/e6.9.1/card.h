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

#endif // !CARD_H_
