#ifndef ARGLIST_H_
#define ARGLIST_H_

#include <QStringList>

class Arglist : public QStringList
{
public:
	Arglist();
	Arglist(int argc, char* argv[]) 
	{ 
		agrsToList(argc, argv);
	}
	Arglist(const QStringList& ql) : QStringList(ql) {}
	bool getSwitch(QString option);
	QString getSwitchArg(QString option, QString defVal = QString());
	QList<QString> getSwitch2Arg(QString option, QString defVal1 = QString(), QString defVal2 = QString());
private:
	void agrsToList(int argc, char* argv[]);
};

#endif // !ARGLIS_H_
