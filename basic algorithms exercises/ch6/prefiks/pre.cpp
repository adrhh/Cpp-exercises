#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kandydatNaLidera(vector<int>::iterator start, vector<int>::iterator koniec)
{
    auto index = start;
    int licznik = 1;
    for(auto it = start + 1; it != koniec; ++it)
    {
        if(*it == *index)
            licznik++;
        else
            licznik--;
        if(!licznik)
        {
            licznik = 1;
            index = it;
        }
    }
    return *index;
}

int zadanie(vector<int>& v)
{   
    vector<int> liderzy(v.size());
    for(auto it = v.begin(); it != v.end(); ++it)
        liderzy.push_back(kandydatNaLidera(v.begin(), it));
    int kandydat = kandydatNaLidera(liderzy.begin(), liderzy.end());
    
    int licznik = 0;
    for_each(liderzy.begin(), liderzy.end(), [&](int i){ if(i == kandydat) licznik++;});
    cout << licznik << endl;
    
    if(licznik > v.size() / 2)
        return licznik;
    else
        return -1;
}

int main()
{
    vector<int> test {3,4,5,3,3,1,3,3,3};
    cout << zadanie(test) << endl;
    
    return 0;
}
