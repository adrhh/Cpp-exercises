#include <valarray>
#include <string>
#include "pair.h"

using std::string;
using std::valarray;

typedef valarray<int> ArrInt;
typedef Pair<ArrInt, ArrInt> PairArr;

class Wine
{
private:
	string label;
	PairArr yers_bottles;
	int years;
public:
	Wine();
	Wine(const char*l, int y, const int yr[], const int bot[]);
	int sum() const;
};