#include <iostream>

using namespace std;

void pswap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rswap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void xswap(int* a, int* b)
{
    *a ^= *b;
    *b = *a ^ *b;
    *a ^= *b;
}

int main()
{

    int x = 1;
    int y = 20;
    cout << x << '\t' << y << endl;
    pswap(&x,&y);
    cout << x << '\t' << y << endl;
    rswap(x,y);
    cout << x << '\t' << y << endl;
    swap(&x,&y);
    cout << x << '\t' << y << endl;
    xswap(&x,&y);
    cout << x << '\t' << y << endl;

    int& iref = x;
    cout << iref << "adress iref = " << &iref << " adress &x = " << &x << endl;

    return 0;
}
