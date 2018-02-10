#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::ostream;

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
	string get_name(int i) const { return name[i]; }
	double get_age(int i) const { return age[i]; }
	int get_size() const { return name.size(); }
};

ostream& operator<<(ostream& os, const Name_pairs& n);
bool operator==(const Name_pairs& n1, const Name_pairs& n2);
bool operator!=(const Name_pairs& n1, const Name_pairs& n2);

int main()
{
	Name_pairs test;
	test.read_names();
	test.read_ages();
	cout << test << endl;
	test.sort();
	cout << test << endl;

	return 0;
}


void  Name_pairs::read_names()
{
	string temp;
	cout << "Podawaj imniona (Ctrl+d zakoncz)" << endl;
	while (cin >> temp)
		name.push_back(temp);
}

void Name_pairs::read_ages()
{
	double temp;
	for (int i = 0; i < name.size(); i++)
	{
		cin.clear();
		cout << "Podaj wiek dla: " << name[i] << endl;
		cin >> temp;
		cin.clear();
		while (cin.get() != '\n')
			continue;
		age.push_back(temp);
	}
}

void Name_pairs::sort()
{
	int i, j;
	string temp;
	double temp_age;


	for (j = name.size() - 2; j >= 0; j--)
	{
		temp = name[j];
		temp_age = age[j];
		i = j + 1;
		while ((i < name.size()) && (temp > name[i]))
		{
			name[i - 1] = name[i];
			age[i - 1] = age[i];
			i++;
		}
		name[i - 1] = temp;
		age[i - 1] = temp_age;
	}
}

void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << " : " << age[i] << endl;
}

ostream& operator<<(ostream& os, const Name_pairs& n)
{
	for (int i = 0; i < n.get_size(); i++)
		os << n.get_name(i) << " : " << n.get_age(i) << endl;

	return os;
}

bool operator==(const Name_pairs& n1, const Name_pairs& n2)
{
	bool answ = true;
	if (n1.get_size() != n2.get_size())
		answ = false;
	else
	{
		for(int i=0; i < n1.get_size(); i++)
			if (n1.get_age(i) != n2.get_age(i) ||
				n1.get_name(i) != n2.get_name(i))
			{
				answ = false;
				break;
			}
	}

	return answ;
}

bool operator!=(const Name_pairs& n1, const Name_pairs& n2)
{
	return !(n1 == n2);
}