#include <iostream>

using std::cout;
using std::endl;

namespace A
{
	int var;
	void print();
};

namespace B
{
	int var;
	void print();
}

namespace C
{
	int var;
	void print();
}


int main()
{
	A::var = 7;
	A::print();
	using namespace B;
	var = 9;
	print();
	{
		using C::var;
		using C::print;
		var = 11;
		print();
	}
	print();
	A::print();

	return 0;
}

void A::print()
{
	cout << var << endl;
}

void B::print()
{
	cout << var << endl;
}

void C::print()
{
	cout << var << endl;
}