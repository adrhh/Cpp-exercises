#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int randInt(int min, int max);
vector<int> randPerm(int n, int seed);
void vprint(const vector<int>& v);

int main()
{
	
	vector<int> v1 = randPerm(10, 9);
	vector<int> v2 = randPerm(10, 9);
	vector<int> v3 = randPerm(10, 13847328789);
	vprint(v1);
	cout << endl;
	vprint(v2);
	cout << endl;
	vprint(v3);

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
	for (int i=0; i<v.size(); i++)
		cout << v[i] << ' ';
}