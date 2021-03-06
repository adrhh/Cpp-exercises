#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp() : fname("brak"), lname("brak"), job("brak") {}
	abstr_emp(const string& fn, const string& ln, const string& j)
		: fname(fn), lname(ln), job(j) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
public:
	employee() : abstr_emp() {}
	employee(const string& fn, const string& ln, const string& j)
		: abstr_emp(fn, ln, j) {}
	virtual void ShowAll() const
	{
		abstr_emp::ShowAll();
	}
	virtual void SetAll()
	{
		abstr_emp::SetAll();
	}
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager() : abstr_emp(), inchargeof(0) {}
	manager(const string& fn, const string& ln, const string& j, int ico = 0)
		: abstr_emp(fn, ln, j), inchargeof(ico) {}
	manager(const abstr_emp& e, int ico)
		: abstr_emp(e), inchargeof(ico) {}
	manager(const manager& m)
		: abstr_emp(m), inchargeof(m.inchargeof) {}
	virtual void ShowAll() const
	{
		abstr_emp::ShowAll();
		cout << "Zaradzani: " << inchargeof << endl;
	}
	virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink() : abstr_emp(), reportsto("brak") {}
	fink(const string& fn, const string& ln, const string& j, const string& rpo)
		: abstr_emp(fn, ln, j), reportsto(rpo) {}
	fink(const abstr_emp& e, const string& rpo)
		: abstr_emp(e), reportsto(rpo) {}
	fink(const fink& f) : abstr_emp(f), reportsto(f.reportsto) {}
	virtual void ShowAll() const
	{
		abstr_emp::ShowAll();
		cout << "Donosi do: " << reportsto << endl;
	}
	virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
	highfink() : abstr_emp(), manager(), fink() {}
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico)
		: abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}
	highfink(const abstr_emp& e, const string& rpo, int ico)
		: abstr_emp(e), fink(e,rpo), manager(e, ico) {}
	highfink(const fink& f, int ico)
		: abstr_emp(f), fink(f), manager(f, ico) {}
	highfink(const manager& m, const string& rpo)
		: abstr_emp(m), fink(m, rpo), manager(m) {}
	virtual void ShowAll() const;
	virtual void SetAll();
};


#endif // !EMP_H_
