#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int randInt(int min, int max);
vector<int> randPerm(int n, int seed);
void vprint(const vector<int>& v);
string shift(const string& text, int key);
string unshift(const string& crypttext, int key);

int main()
{
	const int key = 11;
	string s1("kalarepa"), s2, s3;
	s2 = shift(s1, key);
	cout << s1 << endl << s2 << endl;
	s3 = unshift(s2, key);
	cout << s1 << endl << s2 << endl << s3 << endl;

	return 0;
}

int randInt(int min, int max)
{
	return min + rand() % (max - min);
}

vector<int> randPerm(int n, int seed)
{
	srand(seed);

	vector<int> nums;
	for (int i = 0; i < n; i++)
		nums.push_back(i);

	vector<int> perm;

	while (nums.size() > 0)
	{
		int i = randInt(0, nums.size());
		int x = nums[i];

		nums.erase(nums.begin() + i);
		perm.push_back(x);
	}

	return perm;
}

void vprint(const vector<int>& v)
{
	for (int i = 0; i<v.size(); i++)
		cout << v[i] << ' ';
}

string shift(const string& text, int key)
{
	srand(key);

	string shifted;
	char ch;
	for (int i = 0; i < text.size(); i++)
	{
		int rnd = rand() % text.size();
		rnd += static_cast<int> (text[i]);
		rnd %= 128;
		ch = static_cast<char> (rnd);

		shifted += ch;
	}

	return shifted;
}

string unshift(const string& crypttext, int key)
{
	srand(key);

	string unshifted;
	char ch;
	for (int i = 0; i < crypttext.size(); i++)
	{
		
		int rnd = static_cast<int> (crypttext[i]) - rand() % crypttext.size(); 
		rnd %= 128;
		
		ch = static_cast<char> (rnd);

		unshifted += ch;
	}

	return unshifted;
}