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

bool czyToLeader(vector<int>::iterator start, vector<int>::iterator koniec, int v)
{
    int licznik = 0;
    for(auto it = start; it != koniec; ++it)
        if(*it == v)
            licznik++;
    
    return licznik > (koniec - start) / 2;
}

int main()
{
    return 0;
}
