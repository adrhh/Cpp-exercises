#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int zadanie(const vector<int>& v)
{
    auto start = max_element(v.begin(), v.end());
    auto koniec = min_element(start, v.end());
    return *start - *koniec;
}

int main()
{
    vector<int> test {6,7,5,4,2};
    cout << zadanie(test) << endl;
    
    return 0;
}
