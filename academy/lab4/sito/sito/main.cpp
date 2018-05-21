#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

class IntPrinter
{
public:
	void operator()(int n)
	{
		std::cout << n << ' ';
	}
};

int main()
{
	std::vector<int> vec;
	auto inserter = std::back_inserter(vec);
	const int LIMIT = 50;
	for (int i = 2; i <= LIMIT; i++)
		inserter = i;

	IntPrinter printer;

	const int FORLoopLimit = static_cast<int>( (sqrt(vec[vec.size()-1])) + 1);

	for (int i = vec[0]; i < FORLoopLimit; i++)
		std::for_each(vec.begin(), vec.end(), [i](int& v)
			{
				if (!(v % i) && v!=i)
					v = 0;
			}
		);

	std::remove(vec.begin(), vec.end(), 0);
	auto first0 = std::find(vec.begin(), vec.end(), 0);
	vec.erase(first0, vec.end());
	std::for_each(vec.begin(), vec.end(), printer);

	return 0;
}