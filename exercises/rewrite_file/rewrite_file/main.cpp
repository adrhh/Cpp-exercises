#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char* buffer;
	string fname;
	streampos fbegin, fend, size;

	cout << "Podaj sciezke i nazwe pliku do otwarcia" << endl;
	cin >> fname;

	//open file in binary mode
	ifstream inf(fname, ios::binary);  //input file
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
	inf.close();


	//open output file in binary mode
	cout << "Podaj sciezke i nazwe pliku do otwarcia" << endl;
	cin >> fname;
	ofstream of(fname, ios::binary);  //output file
	//write buffer to file
	of.write(buffer, size);
	of.close();

	delete[] buffer;

	return 0;
}
