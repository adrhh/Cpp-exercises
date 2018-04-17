#include <iostream>

using namespace std;

void f2()
{
    #define TBL_SIZE 2
    long i = 0;
    long lArr[TBL_SIZE] = {7, 15};
    for (i = 0; i <= TBL_SIZE; ++i) {
        *(&lArr[TBL_SIZE - 1] - i) = 0;
    }
    //test
    cout << "zakonczono zerowanie f2" << endl;
}

void f3()
{
    const long CTBL_SIZE = 2;
    long i = 0;
    long lArr[CTBL_SIZE] = {7, 15};
    for (i = 0; i <= CTBL_SIZE; ++i) {
        *(&lArr[CTBL_SIZE - 1] - i) = 0;
    }
    //test
    cout << "zakonczono zerowanie f3" << endl;
}


int main()
{

    f2();
    f3();
    return 0;
}
