#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::cerr;
using std::cin;
using std::string;


void error(const string& s);

class Token
{
public:
	char kind;        
	long value;     
	Token(char ch)  
		:kind(ch), value(0) { }
	Token(char ch, long val) 
		:kind(ch), value(val) { }
};


class Token_stream
{
public:
	Token_stream(); 
	Token get(); 
	void putback(Token t); 
private:
	bool full; 
	Token buffer; 
};


Token_stream::Token_stream()
	:full(false), buffer(0)   
{
}


void Token_stream::putback(Token t)
{
	if (full)
		error("putback() into a full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{				  
					  
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    

	switch (ch)
	{
	case ';':  
	case 'q':   
	case '(': case ')': case '^': case '!': case '|': case '&':
		return Token(ch);        
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '9':
	{
		cin.putback(ch);        
		long val;
		cin >> val;              
		return Token('8', val);   
	}
	default:
		error("Bad token");
	}
}


Token_stream ts; 

long primary();
long and();
long xor();
long or ();

long nega()
{
	long negation;
	Token t = ts.get();

	if (t.kind == '!')
	{
		long right = primary();
		negation = !right;
	}
	else
	{
		ts.putback(t);
		negation = primary();
	}
	return negation;
}

long primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		long l = or();
		t = ts.get();
		if (t.kind != ')') 
			error("')' expected");
		return l;
	}
	case '8':
		return t.value;
	default:
		error("number or ( ) expected");
	}
}

long or()
{
	long left = xor();
	Token t = ts.get();

	while (true)
	{
		if (t.kind == '|')
		{
			left |= xor ();
			t = ts.get();
		}
		else
		{
			ts.putback(t);
			return left;
		}
	}
}

long xor()
{
	long left = and();
	Token t = ts.get();

	while (true)
	{
		if (t.kind == '^')
		{
			left ^= and();
			t = ts.get();
		}
		else
		{
			ts.putback(t);
			return left;
		}
	}
}

long and()
{
	long left = nega();
	Token t = ts.get();

	while (true)
	{
		if (t.kind == '&')
		{
			left &= nega();
			t = ts.get();
		}
		else
		{
			ts.putback(t);
			return left;
		}
	}
}

int main()
try
{
	cout << "Kalkulator obsluguje operatory: & ^ | !\n"
		<< "Wyraznie zakoncz znakiem ; by je wdrukowac\n";
	double val = 0;
	while (cin) {
		Token t = ts.get();

		if (t.kind == 'q') break; // 'q' for quit
		if (t.kind == ';')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = or();
	}
}
catch (std::exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}

void error(const string& s)
{
	throw std::runtime_error(s);
}