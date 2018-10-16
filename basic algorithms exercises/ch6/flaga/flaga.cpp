#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kandydatNaLidera(const vector<int>& v)
{
    int index = 0;
    int licznik = 1;
    for(unsigned int i = 1; i < v.size() - 1; ++i)
    {
        if(v[i] == v[index])
            licznik++;
        else
            licznik--;
        if(!licznik)
        {
            licznik = 1;
            index = i;
        }
    }
    return v[index];
}

int zadanie(const vector<int>& v)
{   
    vector<int> parzyste;
    vector<int> nieparzyste;
    for(int i = 0; i < v.size(); ++i)
        if(i%2)
            nieparzyste.push_back(v[i]);
        else
            parzyste.push_back(v[i]);
    sort(parzyste.begin(), parzyste.end());
    sort(nieparzyste.begin(), nieparzyste.end());
    int liderP = kandydatNaLidera(parzyste);
    int liderN = kandydatNaLidera(nieparzyste);
    int kroki = 0;
    for(auto i : parzyste)
        if(i != liderP)
            kroki++;
    for(auto i : nieparzyste)
        if(i != liderN)
            kroki++;
    return kroki;
}

int main()
{
    vector<int> test {1,2,3,1,4,2};
    cout << zadanie(test) << endl;
    
    return 0;
}
