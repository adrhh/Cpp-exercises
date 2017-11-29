#include <valarray>
#include <string>
#include "pair.h"

using std::string;
using std::valarray;



class Wine : private string, private Pair<valarray<int>, valarray<int>>
{
private:
	typedef valarray<int> ArrInt;
	typedef Pair<ArrInt, ArrInt> PairArr;
	int years;
public:
	Wine();
	Wine(const char*l, int y, const int yr[], const int bot[]);
	Wine(const char*l, int y);
	string& Label() { return (string)*this; };
	void GetBottles();
	void Show();
	int sum();
};