#ifndef STOCK3_H_
#define STOCK3_H_

#include <iostream>

using std::ostream;

class Stock
{
	private:
		char* company;
		int shares;
		double share_val;
		double total_val;
		void set_tot() { total_val = shares * share_val;}
public:
	Stock();
	Stock(const char* s, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	friend ostream & operator<<(ostream& is, const Stock& st);
	const Stock & topval(const Stock& s) const;
	void update(double price);
};

#endif // !STOCK3_H_
