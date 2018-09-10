// Example program
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::stack;
using std::vector;
using std::endl;
using std::cout;

struct Ryba
{
    int wielkosc;
    //0 z pradem
    //1 podprad
    bool kierunek;
};

int zadanie(const vector<Ryba>& v)
{
    int wynik = 0;
    stack<Ryba> ryby;
    for(auto ryba : v)
    {
        if(ryba.kierunek)
            ryby.push(ryba);
        else
        {
            bool czyZyje = true;
            while(czyZyje && ryby.size())
            {
                if(ryba.wielkosc > ryby.top().wielkosc)
                    ryby.pop();
                else
                    czyZyje = false;
            }
            if(czyZyje)
                wynik++;
        }
    }
    return wynik + ryby.size();
}

int main()
{
    vector<Ryba> tablicaRyb {{4,0}, {3,1}, {2,0}, {1,0}, {5,0}};
    cout << zadanie(tablicaRyb) << endl;
    
    return 0;
}
