#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::cerr;
using std::vector;
using std::runtime_error;
using std::exception;
using std::find;

void error(const string& s);

const char number = '8';		//token is number
const char koniec = 'q';		//quit
const char print = ';';			//print
const char name = 'a';			//user var
const char let = 'L';			//let, user var decalartion
const string declkey = "let";	//declaration keyword
const string prompt = "> ";		//prompt symbol
const string result = "= ";		//print symbol

template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(string("info loss"));
	return r;
}

class Token {
public:
    char kind;        // token kind
    double value;     // value for number
    string name;      // name  only for user's vars
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};

class Token_stream {
public:
	Token_stream() :full(false), buffer(0) {}  // default constructor
	Token get();      // get Token from stream
	void putback(Token t);    // putnack token to buffer
	void ignore(char c);      // ignore token to char c
private:
	bool full;        //is buffer full ?
	Token buffer;     // Przechowuje tokeny zwrócone przez funkcjê putback().
};

void Token_stream::putback(Token t)
{

	if (full) 
		error("buffor is full");
	buffer = t;      //copy token t to buffer
	full = true;     // set buffor to full
}

Token Token_stream::get() 
{
	//if buffer is full take Token from buffer and set buffer to empty
	if (full)
	{        
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;          
	//check token kind
	switch (ch)
	{
		case koniec:
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
			return Token(ch); //return token only with kind
		case '.':             
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':    
		{
			cin.putback(ch); //return number to stream and get next number
			double val;
			cin >> val;      
			return Token(number, val); //return number token with value
		}
	default:
		if (isalpha(ch)) 
		{   //check for strings
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
				s += ch;
			cin.putback(ch);
			if (s == declkey)      //is string kewrod let ?
				return Token(let); // return let keyword
			return Token(name, s);
		}
		error("bad token");
	}
}


void Token_stream::ignore(char c)
{
	//search for token kind = c in buffer
	//if is c in buffer, clear buffer
	if (full && c == buffer.kind) 
	{
		full = false;
		return;
	}
	full = false;

	//search for c in stream
	char ch = 0;
	while (cin >> ch)
		if (ch == c)
			return;
}

//struct for user's vars
//var name and var value
struct Variable
{
	string name;
	double value;
	bool is_const;
	Variable(string n, double v) :name(n), value(v) { }
};

Token_stream ts;
double expression();

//class fo
class Symbol_table
{
private:
	vector<Variable> var_table;
public:
	//Symbol_table(string s, double d);
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string s);
	double define();
};


double Symbol_table::get_value(string s)
{
	//if s is var name get var value
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
			return var_table[i].value;
	error("get: undefined name " + s);
}

void Symbol_table::set_value(string s, double d)
{
	//if is var with name == s
	//set var value to d
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s)
		{
			var_table[i].value = d;
			return;
		}
	error("set: undefined name " + s);
}

bool Symbol_table::is_declared(string s)
{
	//is already var with name == s ?
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
			return true;
	return false;
}

double Symbol_table::define()
//add var to vector
{
	//declar user var with name and value

	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");
	string var_name = t.name;

	if (is_declared(var_name)) 
		error(var_name + "is declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error(" = missing in declaration of " + var_name);

	double d = expression();

	var_table.push_back(Variable(var_name, d));

	return d;
}

Symbol_table names; //create object

//deal with (, ) , - and numbers
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':           
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') 
			error("')' expected");
		return d;
	}
	case number:
		return t.value;    
	case name:
		return names.get_value(t.name);
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("primary expected.");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get(); 

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(term());
			if (i2 == 0)
				error("% divide by zero");
			left = i1%i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     
			return left;
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
			ts.putback(t);
			return left; //return calucleted expression
		}
	}
}



//check for var decleartion
//Token kind let = 'L'
double statement()
{
	Token t = ts.get();
	switch (t.kind) 
	{
	case let:
		return names.define();
	default:
		ts.putback(t);
		return expression();
	}
}


//print = ';'
//ignore all Token after exeption
void clean_up_mess()
{
	ts.ignore(print);
}


void calculate()
{
	while (cin)
		try
		{
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print)
				t = ts.get(); 
			if (t.kind == koniec) 
				return;       
			ts.putback(t);
			cout << result << statement() << endl;
		}
	catch (exception& e)
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