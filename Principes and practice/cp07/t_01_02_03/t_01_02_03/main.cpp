
/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include <iostream>
#include <string>
#include <exception>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::cerr;
using std::vector;
using std::runtime_error;
using std::exception;

void error(const string& s);

struct Token 
{
	char kind;										//token type
	double value;									//value for numbers
	string name;									//value for var names
	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, double val) : kind(ch), value(val) { }
	Token(char ch, string str) : kind(ch), name(str) { }
};

class Token_stream {
	bool full;										 //is buffer full ?
	Token buffer;									 //buffer for take token from stream
public:
	Token_stream() :full(0), buffer(0) { }            //default constructor
	Token get();									  //get Token from stream
	void unget(Token t) { buffer = t; full = true; }  //putback Token to buffer
	void ignore(char c);							  //ignore Tokens to c
};

//constant varibles for Token kind
//------------------------------------------------------------------------
const char let = 'L';								//user var decalaration 
const char quit = 'Q';								//quit 
const char print = ';';								//print expresion
const char number = '8';							//token in numeric
const char name = 'a';								//token is user var

Token Token_stream::get()
{
	if (full) 
	{ 
		//if buffer is full take Token from buffer and set buffer to empty
		full = false; 
		return buffer; 
	}
		//take Token kind from cin
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	//case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
		cin.unget();  //return number to stream and get next number
		double val;
		cin >> val;
		return Token(number, val);
		//return numeric Toekn
	}
	default:
		if (isalpha(ch)) //is letter ?
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
				s += ch;   //while is number or letter continnue red 
			cin.unget();
			if (s == "let") 
				return Token(let);
			if (s == "quit") 
				return Token(name);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	//search for c in buffer
	//if is c in buffer, clear buffer
	if (full && c == buffer.kind) 
	{
		full = false;
		return;
	}
	full = false;

	//search for c in stream
	char ch;
	while (cin >> ch)
		if (ch == c) 
			return;
}

//struct for user vars
//var name and var value
struct Variable 
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

//vector for user vars
vector<Variable> names;

double get_value(string s)
{
	//if s is var name get var value
	for (int i = 0; i <names.size(); ++i)
		if (names[i].name == s) 
			return names[i].value;
	error("get: undefined name " + s);
}

void set_value(string s, double d)
{
	//if is var with name == s
	//set var value to d
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) 
		{
			names[i].value = d;
			return;
		}
	error("set: undefined name " + s);
}

bool is_declared(string s)
{
	//is already var with name == s ?
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) 
			return true;
	return false;
}

//value for numbers
Token_stream ts;
double expression();

//deal with (, ) , - and numbers
double primary()
{
	Token t = ts.get();
	switch (t.kind) 
	{
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') 
			error("'(' expected");
		return d;
	}
	case '-':	  //deal with -
		return -primary();
	case number:  //return number value
		return t.value;
	case name:    //return var value
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

//deal with * and /
double term()
{
	double left = primary();
	while (true) 
	{
		Token t = ts.get();
		switch (t.kind) 
		{
		case '*':
			left *= primary();
			break;
		case '/':
		{	
			double d = primary();
			if (d == 0)  //can't divided by zero
				error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);  //puback token to stream
			return left;  //return calucleted term
		}
	}
}

//deal with + , -
double expression()
{
	double left = term();
	while (true) 
	{
		Token t = ts.get();
		switch (t.kind) 
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left; //return calucleted expression
		}
	}
}

double declaration()
{
	//declar user var with name and value
	Token t = ts.get();
	if (t.kind != 'a') 
		error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) 
		error(name + " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of " + name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

//check for var decleartion
//Token kind let = 'L'
double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//print = ';'
//ignore all Token after exeption
void clean_up_mess()
{
	ts.ignore(print);
}

//print promt and resul char  
const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try 
	{
		cout << prompt;				 //print >
		Token t = ts.get();			 //get Token
		while (t.kind == print)		 //while token = ';' get antoher Token
			t = ts.get();
		if (t.kind == quit)			 //if Token kind = q, quit calculator
			return;
		ts.unget(t);
		cout << result << statement() << endl;		//print results
	}
	catch (runtime_error& e) 
	{
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	try
	{
		calculate();
	}

	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c&& c != ';');
		return 1;
	}
	catch (...)			
	{
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
	return 0;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}