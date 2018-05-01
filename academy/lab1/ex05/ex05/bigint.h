#ifndef BIGINT_H_
#define BIGINT_H_

#include <string>
#include <iostream>

class BigInt
{
public:
	BigInt();
	BigInt(const std::string& sourceStr);
	BigInt operator*(const BigInt& multiperBigInt);
	BigInt operator+(const BigInt& adderBigInt);


	void showBigInt() const;
private:
	std::string bigIntAsString;

	bool isInputOk(const std::string& sourceStr) const;
};

#endif // !BIGINT_H_
