#ifndef CRYPTO_H_
#define CRYPTO_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Crypto
{
private:
	unsigned short key;
	unsigned short charSize;
	string sequence;
	vector<int> perm;

	string shift(const string& s);
	string unshift(const string& s);
	string permute(const string& s);
	string unpermute(const string& s);
	int limitedRand(int max);
	vector<int> randomPerm(int n);
public:
	Crypto(unsigned short k, string s, unsigned short cs=1);
	string encrypt(const string& s);
	string decrypt(const string& s);
};

#endif // !CRYPTO_H_
