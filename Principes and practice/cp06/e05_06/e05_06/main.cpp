#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::find;

vector<string> Conjuction = { "and", "or", "but" };
vector<string> Noun = { "birds", "fish", "C++" };
vector<string> Verb = { "rules", "fly", "swim" };

void error(const string& s)
{
	throw std::runtime_error(s);
}

class String_stream //string
{
private:
	bool full;
	string buffer;
public:
	String_stream() : full(false), buffer("") {}
	string get();
	void putback(string s);
};

string String_stream::get()
{
	string temp;
	cin >> temp;

	return temp;
}

void String_stream::putback(string s)
{
	if (full)
		error("putback() into a full buffer");
	buffer = s;       // copy t to buffer
	full = true;      // buffer is now full
}

String_stream str;
bool noun();

bool the()
{
	string word = str.get();
	if (word == "the")
		return noun();
	else
	{
		str.putback(word);
		return noun();
	}
}

bool noun()
{
	string s = str.get();
	vector<string>::iterator it;
	it = find(Noun.begin(), Noun.end(), s);
	if (it != Noun.end())
		return false;
	else
		return true;
}

bool verb()
{
	string s = str.get();
	vector<string>::iterator it;
	it = find(Verb.begin(), Verb.end(), s);
	if (it != Verb.end())
		return false;
	else
		return true;
}

bool conj()
{
	string s = str.get();
	vector<string>::iterator it;
	it = find(Conjuction.begin(), Conjuction.end(), s);
	if (it != Conjuction.end())
		return false;
	else
		return true;
}



bool sentence()
{
	return true;
}


int main()
{

	return 0;
}
