#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>

using std::string;

class C
{
public:
	C(int x=0);
	string getBin() const {return m_binary;}
private:
	void doConvert(int x);
	int m_decimal;
	string m_binary;
};

#endif // !CONVERTER_H_
