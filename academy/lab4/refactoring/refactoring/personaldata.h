#ifndef PERSONALDATA_H_
#define PERSONALDATA_H_

#include <string>
#include <cctype>
#include <exception>

class Pesel
{
private:
	std::string pesel;
public:
	Pesel(const std::string& str)
	{
		if (checkPesel(str))
			pesel = pesel;
		else
			throw std::exception("Wrong pesel");
	}
	bool checkPesel(const std::string& str) const;
};

class PersonData
{
private:
	Pesel pesel;
	std::string name;
	std::string surname;
	int age;
public: 
	PersonData(std::string name, std::string surname, std::string pesel, int age)
		: name(name), surname(surname), pesel(pesel), age(age) {}
};

bool Pesel::checkPesel(const std::string& str) const
{
	if (str.length() != 11) {
			return false;
	}
	for (char c : str) {
		if (!std::isdigit(c))
			return false;
	}
	int checksum = 0;
	int mults[] = { 9, 7, 3, 1, 9, 7, 3, 1, 9, 7 };
	for (int i = 0; i < 10; ++i) {
		checksum += mults[i] * (str[i] - '0');
	}
	checksum %= 10;
	if (checksum != (str[10] - '0'))
		return false;

	return true;
}

#endif // !PERSONALDATA_H_
