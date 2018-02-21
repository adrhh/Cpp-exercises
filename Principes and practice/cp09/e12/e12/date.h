#ifndef DATE_H_
#define DATE_H

class Date
{
private:
	int days;
	//days from 1.1.1970
public:
	Date() : days(0) {}
	Date(int n) : days(n) {};
	void show() const;
};

#endif // !DATE_H_
