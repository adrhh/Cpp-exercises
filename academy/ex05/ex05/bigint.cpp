#include "bigint.h"
#include <cctype>

bool BigInt::isInputOk(const std::string& sourceStr) const
{
	bool strIsNumber = true;
	for (int i=0; i < sourceStr.size(); i++)
		if (!isdigit(sourceStr[i]))
			strIsNumber = false;

	return strIsNumber;
}

BigInt::BigInt()
{
	bigIntAsString = "0";
}

BigInt::BigInt(const std::string& sourceStr)
{
	if (isInputOk(sourceStr))
		bigIntAsString = sourceStr;
	else
	{
		std::cerr << "argument konstruktora nie jest poprawny" << std::endl;
		//throw
	}
}

void BigInt::showBigInt() const
{
	std::cout << bigIntAsString;
}

BigInt BigInt::operator+(const BigInt& adderBigInt)
{
	int iterations = (this->bigIntAsString.size() < adderBigInt.bigIntAsString.size()) ?
						this->bigIntAsString.size() : adderBigInt.bigIntAsString.size();
	int biggerSize = (this->bigIntAsString.size() > adderBigInt.bigIntAsString.size()) ?
						this->bigIntAsString.size() : adderBigInt.bigIntAsString.size();

	std::string addResult = "";
	std::string rest = "";

	for (int i = 0; i <= biggerSize; i++)
		rest += '0';

	for (int i = 0; i < iterations; i++)
	{
		addResult += '0';
		char columnAdd = (this->bigIntAsString[i] - '0') + (adderBigInt.bigIntAsString[i] - '0');
		if (columnAdd > 9)
		{
			addResult[i] += (columnAdd % 10);
			rest[i] += (columnAdd / 10);
		}
		else
			addResult[i] += columnAdd;	
	}
	//todo
	//add rest to result and remaining digs form biger number;
	std::cout << addResult << std::endl;
	std::cout << rest << std::endl;

	return  BigInt(addResult);
}

//BigInt BigInt::operator*(const BigInt& multiperBigInt)
//{
//	std::string multipResult;
//
//
//}