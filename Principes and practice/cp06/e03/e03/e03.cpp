#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::cerr;
using std::cin;
using std::string;

//------------------------------------------------------------------------------

void error(const string& s);
int factorial(const int n);

class Token
{
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream
{
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full)
		error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full)
	{				  // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch)
	{
	case ';':    // for "print"
	case 'q':    // for "quit"
	case '(': case ')': case '+': case '-':
	case '*': case '/': case '{': case '}':
	case '!':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double primary();

double fact()
{
	double left = primary();
	Token t = ts.get();

	if (t.kind == '!')
	{
		if ( (left - (int)left) == 0 && left > 0)
		{
				int dint = static_cast<int>(left);
				int temp = factorial(dint);
				left = static_cast<double>(temp);
		}
		else
			error("factorial needs natural number");
	}
	else
		ts.putback(t);
	return left;
}

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = fact();
	Token t = ts.get();        // get the next token from token stream

	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= fact();
			t = ts.get();
			break;
		case '/':
		{
			double d = fact();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}



//------------------------------------------------------------------------------

int main()
try
{
	cout << "Kalkulator obsluguje operatory: * / + -\n"
		<< "Wyraznie zakoncz znakiem ; by je wdrukowac\n";
	double val = 0;
	while (cin) {
		Token t = ts.get();

		if (t.kind == 'q') break; // 'q' for quit
		if (t.kind == ';')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
}
catch (std::exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}

int factorial(const int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return factorial(n - 1)*n;
}