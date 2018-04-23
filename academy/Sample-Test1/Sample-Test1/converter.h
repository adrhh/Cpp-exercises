#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>

using std::string;

class C10to2
{
public:
	C10to2(int x=0);
	string getBin() const {return m_binary;}
private:
	void doConvert(int x);
	string m_binary;
};

class C2to10
{
public:
	C2to10(string x);
	int getInt() const { return m_decimal; }
private:
	void doConvert(string x);
	int m_decimal;
};

#endif // !CONVERTER_H_
