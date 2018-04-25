#include "bigint.h"
#include <cctype>

std::string reveseString(const std::string& sourceStr);

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

std::string BigInt::reverse() const
{
	std::string retStr;
	for (int i = bigIntAsString.size() - 1; i >= 0; i--)
		retStr += bigIntAsString[i];
	return retStr;
}

void BigInt::showBigInt() const
{
	std::cout << bigIntAsString;
}

BigInt BigInt::operator+(const BigInt& adderBigInt)
{
	int smallerSize = (this->bigIntAsString.size() < adderBigInt.bigIntAsString.size()) ?
						this->bigIntAsString.size() : adderBigInt.bigIntAsString.size();
	int biggerSize = (this->bigIntAsString.size() > adderBigInt.bigIntAsString.size()) ?
						this->bigIntAsString.size() : adderBigInt.bigIntAsString.size();

	std::string addResult = "";
	std::string leftOp = reveseString( bigIntAsString );
	std::string rightOp = reveseString( adderBigInt.bigIntAsString );

	const char CHAR_AS_NUM = '0';
	const int MAX_DIG = 9;

	for (int i = 0; i <= biggerSize; i++)
		addResult += CHAR_AS_NUM;

	for (int i = 0; i < biggerSize; i++)
	{
		char columnAdd = CHAR_AS_NUM;
		if (i < smallerSize)
		{
			columnAdd += (leftOp[i] - CHAR_AS_NUM) + (rightOp[i] - CHAR_AS_NUM);
			if (columnAdd - CHAR_AS_NUM > MAX_DIG)
			{
				addResult[i] += (columnAdd - CHAR_AS_NUM)  % 10;
				addResult[i+1] += (columnAdd - CHAR_AS_NUM) / 10;
			}
			else
			{
				int tempColumn = (addResult[i] - CHAR_AS_NUM) + (columnAdd - CHAR_AS_NUM);
				if (tempColumn > MAX_DIG)
				{
					addResult[i] += tempColumn % 10;
					addResult[i + 1] += tempColumn / 10;
				}
				else
					addResult[i] += columnAdd - CHAR_AS_NUM;
			}			
		}
	}
	if (addResult.back() == '0')
		addResult.pop_back();

	addResult = reveseString(addResult);

	return  BigInt(addResult);
}

std::string reveseString(const std::string& sourceStr)
{
	std::string retStr;
	for (int i = sourceStr.size() - 1; i >= 0; i--)
		retStr += sourceStr[i];
	return retStr;
}

//BigInt BigInt::operator*(const BigInt& multiperBigInt)
//{
//	std::string multipResult;
//
//
//}