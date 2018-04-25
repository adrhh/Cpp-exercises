#include "bigint.h"
#include <cctype>
#include <vector>

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

void BigInt::showBigInt() const
{
	std::cout << bigIntAsString;
}

BigInt BigInt::operator+(const BigInt& adderBigInt)
{
	std::string leftOp;
	std::string rightOp;


	if (this->bigIntAsString.size() > adderBigInt.bigIntAsString.size())
	{
		leftOp = reveseString(bigIntAsString);
		rightOp = reveseString(adderBigInt.bigIntAsString);
	}
	else
	{
		leftOp = reveseString(adderBigInt.bigIntAsString);
		rightOp = reveseString(bigIntAsString);
	}

	int biggerSize = leftOp.size();
	int smallerSize = rightOp.size();

	std::string addResult = "";

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
		else
		{
			columnAdd += (addResult[i] - CHAR_AS_NUM) + (leftOp[i] - CHAR_AS_NUM);
			if (columnAdd - CHAR_AS_NUM > MAX_DIG)
			{
				addResult[i] += (columnAdd - CHAR_AS_NUM) % 10;
				addResult[i + 1] += (columnAdd - CHAR_AS_NUM) / 10;
			}
			else
				addResult[i] += leftOp[i] - CHAR_AS_NUM;
		}
	}
	if (addResult.back() == CHAR_AS_NUM)
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

BigInt BigInt::operator*(const BigInt& multiperBigInt)
{
	std::string leftOp;
	std::string rightOp;

	if (this->bigIntAsString.size() > multiperBigInt.bigIntAsString.size())
	{
		leftOp = reveseString(bigIntAsString);
		rightOp = reveseString(multiperBigInt.bigIntAsString);
	}
	else
	{
		leftOp = reveseString(multiperBigInt.bigIntAsString);
		rightOp = reveseString(bigIntAsString);
	}

	int smallerSize = rightOp.size();
	int biggerSize = leftOp.size();

	const char CHAR_AS_NUM = '0';
	const int MAX_DIG = 9;

	std::vector<std::string> multList;

	for (int i = 0; i < smallerSize; i++)
	{
		std::string multResult = "";
		multList.push_back(std::string());
		for (int j = 0; j < biggerSize + 1; j++)
			multList[i] += CHAR_AS_NUM;
		for (int k = 0; k < biggerSize; k++)
		{
			int colMult = (rightOp[i] - CHAR_AS_NUM) * (leftOp[k] - CHAR_AS_NUM);
			if (colMult > MAX_DIG)
			{
				multList[i][k] += colMult % 10;
				multList[i][k + 1] += colMult / 10;
			}
			else
			{
				int colAdd = colMult + (multList[i][k] - CHAR_AS_NUM);
				if (colAdd > MAX_DIG)
				{
					multList[i][k] += colAdd % 10;
					multList[i][k + 1] += colAdd / 10;
				}
				else
					multList[i][k] += colAdd;
			}			
		}

		if (multList[i].back() == CHAR_AS_NUM)
			multList[i].pop_back();

		multList[i] = reveseString(multList[i]);
		for (int k = 0; k < i; k++)
			multList[i] += '0';
		std::cout << multList[i] << std::endl;
	}

	BigInt result("0");

	for (int i = 0; i < multList.size(); i++)
	{
		BigInt temp(multList[i]);
		result = temp + result;
	}

	return BigInt(result);
}