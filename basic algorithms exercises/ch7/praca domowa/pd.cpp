#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//alorytm Kadana
int maxSubArray(const vector<int> v)
{
    int koniec = v[0];
    int maxAtkualny = v[0];
    for(auto it = v.begin() + 1; it != v.end(); ++it)
    {
        koniec = max(*it, koniec + *it);
        maxAtkualny = max(maxAtkualny, koniec);
    }
    return maxAtkualny;
}

//zadanie nieskonczone
//zrobione: szukanie miejsc w ktorych rozpoczyna sie podciag 
int zadanie(vector<int> v)
{
    auto startPos = v.begin();
    auto nowyStart = startPos;
    auto koniecPos = v.end();
    int koniec = v[0];
    int maxAktualny = v[0];
    
    for(auto it = v.begin() + 1; it != v.end(); ++it)
    {
        if(*it < koniec + *it)
        {
            koniec = koniec + *it;
            koniecPos++;
        } 
        else
        {
            koniec = *it;
            nowyStart = it;
        }
        if( maxAktualny < koniec)
        {
            koniecPos = it;
            maxAktualny = koniec;
        }
        else
            startPos = nowyStart;
    }    
    //indeksy rozpoczynajace podciag
    cout <<  startPos - v.begin() << endl;
    cout << koniecPos - v.begin() << endl;
    return maxAktualny;
}

int main()
{
    vector<int> test {5, -7, 3, 5, -2, 4, -1};
    cout << zadanie(test) << endl;
    return 0;
}
