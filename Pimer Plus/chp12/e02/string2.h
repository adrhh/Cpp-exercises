#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>

using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CLIM = 64;
public:
	String(const char* s);
	String();
	String(const String &);
	~String();
	int length() const
	{	return len;}
	String & operator=(const String &);
	String & operator=(const char*);
	String & operator+=(const char*);
	String & operator+=(const String &);
	int has(const char c);
	char operator[](int i);
	String & stringlow();
	String & stringup();
	const char & operator[](int i) const;
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend String operator+(const String& st1, const String& st2);
	friend String operator+(const char* s , const String& st);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	static int HowMany();
};

#endif // !STRING2_H_
