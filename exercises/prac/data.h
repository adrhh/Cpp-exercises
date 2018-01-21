#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <string>


using std::vector;
using std::string;


class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	vector<int> m_nMiesiace = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	enum {m_nMaxmiesiace= 12};
public:
	Data() {};
	~Data() {};
	int Dzien() const { return m_nDzien; }
	int Miesiac() const { return m_nMiesiac; }
	int Rok() const { return m_nRok; };
	void Ustaw(int d, int m, int r);
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	bool Porownaj(const Data& wzor) const;
	Data(const Data &wzorzec);
	Data & operator =(const Data & wzorzec);
	Data& operator ==(const Data & wzorzec);
};

#endif // !DATA_H_
