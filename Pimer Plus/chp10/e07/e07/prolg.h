#ifndef PROLG_H_
#define PROLG_H_

#include <cstring>
#include <iostream>

using std::endl;
using std::cout;

class Prolg
{
private:
	char name[20];
	int satiety;
public:
	Prolg();
	Prolg(const char str[20], int x);
	void show() const;
	void change(int x);
};

#endif // !PROLG_H_
