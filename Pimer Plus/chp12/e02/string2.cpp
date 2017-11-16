#include <cstring>
#include <iostream>
#include "string2.h"

int::String::num_strings = 0;

using namespace std;

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	num_strings++;
}
String::String()
{
	len = 1;
	str = new char[len];
	str[0] = '\0';
	num_strings++;
}
String::String(const String & st)
{
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_strings;
}
String::~String()
{
	delete[] str;
	num_strings--;
}
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;

}
String & String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;

}
char String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i) const
{
	return str[i];
}
bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st)
{
	char temp[String::CLIM];
	is.get(temp, String::CLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
int String::HowMany()
{
	return num_strings;
}

String & String::operator+=(const String& st)
{
	char* tempc = new char[len + st.len + 1];
	strcpy(tempc, str);
	strcat(tempc, st.str);

	delete[] str;
	
	len = strlen(tempc);
	str = new char[len + 1];
	strcpy(str, tempc);

	delete[] tempc;
	return *this;
}

String & String::operator+=(const char* s)
{
	char* tempc = new char[len + strlen(s) + 1];
	strcpy(tempc, str);
	strcat(tempc, s);

	delete[] str;

	len = strlen(tempc);
	str = new char[len + 1];
	strcpy(str, tempc);

	delete[] tempc;
	return *this;
}

String operator+(const String& st1, const String& st2)
{
	char* tempc = new char[st1.len + st2.len + 1];
	strcpy(tempc, st1.str);
	strcat(tempc, st2.str);

	String temps(tempc);
	String::num_strings++;

	delete[] tempc;
	return temps;
}

String operator+(const char* s, const String& st)
{
	char* tempc = new char[strlen(s) + st.len + 1];
	strcpy(tempc, s);
	strcat(tempc, st.str);

	String temps(tempc);
	String::num_strings++;

	delete[] tempc;
	return temps;
}

int String::has(const char c)
{
	int total = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == c)
			total++;

	return total;
}

String & String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);

	return *this;
}

String & String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);

	return *this;
}