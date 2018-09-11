#include <iostream>
#include <string>
#include <queue>
#include <vector>

using std::vecotr;
using std::queue;
using std::endl;
using std::cout;

int zadanie(const vector<int>& v)
{
    queue<int> q;
    for(auto i : v)
        q.push(i);
    
    int suma = 0;
    
    while(q.size())
    {
        int skoki = 1;
        int min = q.front();
        q.pop();
        while(min > q.front() && q.size())
        {
            min = q.front();
            q.pop();
            skoki++;
        }
        suma += skoki * min;
    }
    return suma;
}

int main()
{
    vector<int> test {5,2,4,3};
    cout << zadanie(test) << endl;
    
    return 0;
}
