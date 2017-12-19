#ifndef SALES_H_
#define SALES_H_

#include <string>
#include <stdexcept>

using std::string;

class Sales
{
public:
	enum { MONTHS = 12 };
private:
	double gross[MONTHS];
	int year;
public:
	class bad_index : public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix, const string& s = "Nieporawny indeks w obiekcie klasy Sales\n");
		int bi_val() const { return bi; }
		virtual ~bad_index() throw() {};
	};

	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year() const { return year; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
	
};

class LabeledSales : public Sales
{
private:
	string label;
public:
	class nbad_index : public Sales::bad_index
	{
	private:
		string lbl;
	public:
		nbad_index(const string& lb, int ix, const string& s = "Nieporawny indeks w obiekcie klasy LabeledSales\n");
		const string& lbl_val() const { return lbl; }
		virtual ~nbad_index() throw() {}
	};
	explicit LabeledSales(const string& lb = "brak", int yy = 0);
	LabeledSales(const string& lb, int yy, const double* gr, int n);
	const string& Label() const { return label; }
	virtual ~LabeledSales() {}
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
	
};

#endif // ! SALES_H_
