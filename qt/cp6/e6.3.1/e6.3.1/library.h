#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <QString>

class RefItem
{
protected:
	RefItem(QString type, QString  isbn, QString title, int numCOpies = 1);
	RefItem(QString& proplist);
private:
	QString m_ItemType;
	QString m_ISBN;
	QString m_Title;
	int m_NUmberOfCopies;
public:
	virtual ~RefItem();
	QString getItemName() const;
	QString getISBN() const;
	QString getTitle() const;
	int getNumberOfCopies() const;
	virtual QString toString(QString sep = "[::]") const;
	void setNumberOfCopies(int newVal);
};

class Book : public RefItem
{
public:
	Book(QString type, QString isbn, QString title,
		QString author, QString pub, int year, int numCopies = 1);
	Book(QStringList& proplist);
	virtual QString toString(QString sep = "[::]") const;

};

#endif // !LIBRARY_H_
