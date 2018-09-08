#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using std::vector;
using std::cout;
using std::endl;

//zamiana
void intSwap(vector <int>::iterator a, vector <int>::iterator b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//sortowanie przez wybieranie O(n^2)
void selectionSort(vector<int>& v)
{
    for(unsigned int i = 0; i < v.size(); ++i)
    {
        unsigned int minPosition = i;
        for(unsigned int j =  i + 1; j < v.size(); ++j)
            if(v[j] > v[minPosition])
                minPosition = j;
        intSwap(v.begin() + i, v.begin() + minPosition);
    }
}

//drukowanie vectora int
void printVec(vector<int>& v)
{
    std::for_each(v.begin(), v.end(), [](int i){cout << i << ' ';});
}

int findLeader(vector<int>& v)
{
	vector<int> arrOfIdnex(v.size(), 0);
	for(auto it = v.begin(); it != v.end(); ++it)
		arrOfIdnex[*it]++;
	return *max_element(arrOfIdnex.begin(), arrOfIdnex.end());
}

int valueCount(vector<int>& v, int val)
{
	int counter = 0;
	for_each(v.begin(), v.end(), [&](int i){if(val == i)counter++;});
	return counter;
}

int zadanie(vector<int>& v, int k)
{
    selectionSort(v);
	int leader = findLeader(v);
	int leaderCount = valueCount(v, leader);
	int reaming = find(v.begin(), v.end(), leader) - v.begin();
	int addToReturn = reaming < k ? reaming : k;

	return leaderCount + addToReturn;
}

int main()
{
    vector<int> test {3, 3, 2, 3, 4, 5};
    int uderzenia = 2;

    //cout << findLeader(test) << endl;
	//cout << valueCount(test, findLeader(test)) << endl;
	
	cout << zadanie(test, uderzenia) << endl;

    return 0;
}
