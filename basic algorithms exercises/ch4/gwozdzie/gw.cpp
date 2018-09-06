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

int zadanie(vector<int>& v, int k)
{
    selectionSort(v);
    int maksymalnePowtorzenie = INT_MIN;
    int ilePowtorzen = 0;
    for(unsigned int i = 0; i < v.size() - k - 1; ++i)
    {
        if(v[i] == v[i+1])
            ilePowtorzen++;
        else
            ilePowtorzen = 0;
        maksymalnePowtorzenie = maksymalnePowtorzenie > ilePowtorzen ? maksymalnePowtorzenie : ilePowtorzen;
    }
    return v.size() < maksymalnePowtorzenie ? v.size() : maksymalnePowtorzenie;
}

int main()
{
    vector<int> test {3, 3, 2, 3, 4, 5};
    int uderzenia = 2;

    cout << zadanie(test, uderzenia) << endl;

    return 0;
}
