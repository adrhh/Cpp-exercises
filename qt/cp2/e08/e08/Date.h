#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <vector>

using std::string;
using std::vector;



class Date
{
private:
	//days from start date 1.01.1900 
	static int start_year;
	static vector<string> days_names;
	static vector<string> month_names;

	int days_from_start;
	void is_ok(int y = 0, int m = 0, int d = 0);
	int ymd2dfs(int y, int m, int d);
public:
	
	Date();
	Date(int y, int m, int d);
	void getYMD(int& y, int& m, int& d);
	void set(int y, int m, int d);
	string toString(bool short_format);
	void setToToday();
	string getWeekDay() const;
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	int daysBetween(const Date& d);
	Date addDays(const Date& d);
	static bool leapYear(int y);
	string monthName(int m);
	int monthDays(int y, int m);
	int getDaysFromStart() const { return days_from_start; }
	class Invalid
	{//todo
	};
};

#endif // !DATE_H_
