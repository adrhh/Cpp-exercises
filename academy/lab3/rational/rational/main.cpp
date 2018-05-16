#include "pch.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

unique_ptr<Expression> random_expression()
{
	srand(2);
	static const int CMAX = 10;
	static const int LITMAX = 10;
	int choice = rand() % CMAX;

	switch (choice)
	{
	case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
		return unique_ptr<Expression> {new Literal{ static_cast<double>( rand() % LITMAX ) }};
	case 8:
		{
		auto e1 = random_expression();
		auto e2 = random_expression();
		return unique_ptr<Expression> {new Add{ move(e1), move(e2) }};
		}
	case 9:
		{
		auto e1 = random_expression();
		auto e2 = random_expression();
		return unique_ptr<Expression> {new Mult{ move(e1), move(e2) }};
		}
	}
}

int main()
{
	//Expression* l2 = new Literal{ 2.2 };
	//Expression* l3 = new Literal{ 1.5 };

	//Add* d = new Add{ l2, l2 };
	//cout << d->eval() << endl;
	//Mult* m = new Mult{ l2, l3 };
	//cout << m->eval() << endl;

	//Expression* old_ptr = new Literal{ 3 };
	//unique_ptr<Expression> p1{ old_ptr };
	//Expression* raw_ptr = p1.release();
	//unique_ptr<Expression> p2{ raw_ptr };
	//unique_ptr<Expression> p3 = move(p2);
	//unique_ptr<Expression> p4( new Literal{ 3 } );
	//cout << p4->eval() << endl;

	//unique_ptr<Expression> l4{ new Literal{5} };
	//unique_ptr<Expression> l5{ new Literal{2} };
	//Add a{std::move(l4), std::move(l5)};
	//cout << a.eval() << endl;

	unique_ptr<Expression> e1 = random_expression();
	auto e2 = random_expression();
	cout << e2->eval() << endl;

	return 0;
}
