#include "crypto.h"
#include <cstdlib>
#include <algorithm>

using std::sort;
using std::pair;

string Crypto::shift(const string& s)
{
	string shifted;
	char ch;
	for (int i = 0; i < s.size(); i++)
	{
		int rnd = rand() % s.size();
		rnd += static_cast<int> (s[i]);
		rnd %= 128;
		ch = static_cast<char> (rnd);

		shifted += ch;
	}

	return shifted;
}
string Crypto::unshift(const string& s)
{

	string unshifted;
	char ch;
	for (int i = 0; i < s.size(); i++)
	{
		int rnd = static_cast<int> (s[i]) - rand() % s.size();
		rnd %= 128;

		ch = static_cast<char> (rnd);
		unshifted += ch;
	}

	return unshifted;
}
string Crypto::permute(const string& s)
{
	vector<int> pt = randomPerm(s.size());
	string permuted;

	for (int i = 0; i < s.size(); i++)
		permuted += s[pt[i]];

	return permuted;
}
string Crypto::unpermute(const string& s)
{
	vector<int> pt = randomPerm(s.size());
	string unpermuted;

	vector<pair<int, int>> pairs;
	for (int i = 0; i < pt.size(); i++)
	{
		pair<int, int> temp(pt[i], i);
		pairs.push_back(temp);
	}

	sort(pairs.begin(), pairs.end());

	for (int i = 0; i < s.size(); i++)
		unpermuted += s[pairs[i].second];

	return unpermuted;
}
int Crypto::limitedRand(int max)
{
	return rand() % max;
}
vector<int> Crypto::randomPerm(int n)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
		nums.push_back(i);

	vector<int> perm;
	while (nums.size() > 0)
	{
		int i = limitedRand(nums.size());
		int x = nums[i];

		nums.erase(nums.begin() + i);
		perm.push_back(x);
	}

	return perm;
}

Crypto::Crypto(unsigned short k, string s, unsigned short cs) : key(k), sequence(s), charSize(cs)
{

}

string Crypto::encrypt(const string& s)
{
	string enc = s;
	for (auto i : sequence)
	{
		if (i == 's')
			enc = shift(enc);
		else
			enc = permute(enc);
	}

	return enc;
}

string Crypto::decrypt(const string& s)
{
	string dec = s;
	string rsq;
	rsq.resize(sequence.size());
	std::reverse_copy(sequence.begin(), sequence.end(), rsq.begin());

	for (auto i : rsq)
	{
		if (i == 's')
			dec = unshift(dec);
		else
			dec = unpermute(dec);
	}

	return dec;
}
