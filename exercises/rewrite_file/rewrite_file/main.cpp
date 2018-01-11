#include <fstream>
#include <iostream>
#include <string>
#include <new>

using namespace std;

class cin_fail : public ios::failure
{
public:
	explicit cin_fail(const string& s = "user input fail") : ios::failure(s) {}
};

class open_fail : public ios::failure
{
private:
	string fname;
public:
	explicit open_fail(const string& f, const string& s = "cant open file") : ios::failure(s), fname(f)  {}
	string get_fname() { return fname; }
};

class read_fail : public ios::failure
{
private:
	string fname;
public:
	explicit read_fail(const string& f, const string& s = "reading file fail") : ios::failure(s), fname(f) {}
	string get_fname() { return fname; }
};

int main()
{
	char* buffer;
	string fname;
	streampos fbegin, fend, size;

	try 
	{
	cout << "Podaj sciezke i nazwe pliku do otwarcia" << endl;
	cin >> fname;
	if (cin.fail())
		throw cin_fail();

	//open file in binary mode
	ifstream inf(fname, ios::binary, ios::in);  //input file read only
	if (!inf.is_open())
		throw open_fail(fname);
	//begin position
	fbegin = inf.tellg();
	inf.seekg(0, ios::end);
	//end position
	fend = inf.tellg();
	//calcluate file size
	size = fend - fbegin;

	//test output 
	cout << size << endl;
	//alocate memeory

	buffer = new char[size];
	
	//read file to buffer
	inf.seekg(0, ios::beg);
	inf.read(buffer, size);
	if (!inf.good())
		throw read_fail(fname);

	inf.close();

	//open output file in binary mode
	cout << "Podaj sciezke i nazwe pliku do otwarcia" << endl;
	cin >> fname;
	ofstream of(fname, ios::binary, ios::out);  //output file
	//write buffer to file
	of.write(buffer, size);
	of.close();

	delete[] buffer;
	}

	//io catch
	catch (ios::failure& e)
	{
		ios::failure* er = &e;
		cin_fail* cf;
		open_fail* of;
		read_fail* rf;

		if (cf = dynamic_cast<cin_fail*> (er))
			cout << cf->what() << endl;
		else if (of = dynamic_cast<open_fail*> (er))
			cout << of->what() << of->get_fname() << endl;
		else if (rf = dynamic_cast<read_fail*> (er))
			cout << rf->what() << of->get_fname() << endl;
		else
			cout << "undefined cin error "  << endl;
	}

	//new catch
	catch (bad_alloc& e)
	{
		cout << "dynamic memmory alocation error " << e.what() << endl;
	}

	catch (...)
	{
		cout << "undefined error " << endl;
	}

	return 0;
}
