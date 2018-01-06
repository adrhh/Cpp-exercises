#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//functor
class Print
{
public:
	void operator()(int n) { cout << n << ' '; }
};

int main()
{
	vector<int> t1;
	for (int i = 0; i < 10; i++)
		t1.push_back(i);

	Print p;

	//labbda print
	for_each(t1.begin(), t1.end(), [](auto v) {cout << v << ' '; });
	//functor print
	for_each(t1.begin(), t1.end(), p);

	return 0;
}