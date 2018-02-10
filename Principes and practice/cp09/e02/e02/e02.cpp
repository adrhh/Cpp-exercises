#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Name_pairs
{
private:
	vector<string> name;
	vector<double> age;
public:
	void read_names();
	void read_ages();
	void sort();
	void print() const;
};

void  Name_pairs::read_names()
{
	string temp;
	while (cin >> temp)
		name.push_back(temp);
}

void Name_pairs::read_ages()
{
	double temp;
	for (int i = 0; i < name.size(); i++)
	{
		cin >> temp;
		age.push_back(temp);
	}
}

void Name_pairs::sort()
{
	int i, j;
	string temp;


	for (j = name.size() - 2; j >= 0; j--)
	{
		temp = name[j];
		i = j + 1;
		while ((i < name.size()) && (temp > name[i]))
		{
			name[i - 1] = name[i];
			i++;
		}
		name[i - 1] = temp;
	}
}

void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << " : " << age[i] <<  endl;
}

int main()
{
	Name_pairs test;
	test.read_names();
	test.print();



	return 0;
}