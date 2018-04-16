#include <iostream>

using namespace std;

void printIntsFromRawMem(char* chPtr, int size)
{
    char* ptr = chPtr;
    for(int i=0; i < size; i++, ptr++)
        cout << static_cast<int> (*ptr);

    cout << endl;
}

void castDemo1()
{
    long lN = 578437695752307201;
    cout << "adress od lN = " << &lN << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << lN << " as a byte stream = " << endl;

    printIntsFromRawMem((char *) &lN, sizeof(lN));
    cout << endl;
}

int main()
{
    char ch1 = 'a';
    char* chPtr = &ch1;
    int int1 = 11;
    int* intptr = &int1;

    cout << "ch1 = " << ch1 << endl;
    cout << "&ch1 = " <<  static_cast<void*> (&ch1)<< endl;
    cout << "chptr = " << static_cast<void*> (chPtr)<< endl;
    cout << "*chptr = " << *chPtr << endl;
    cout << "int1  = " << int1  << endl;
    cout << "&int1  = " <<  &int1  << endl;
    cout << "intptr = " << intptr << endl;
    cout << "*intptr = " << *intptr << endl;

    const int Size = 16;
    char cstring[Size] = "test stringa";
    for(int i = 0; i < Size; i++)
        cout << cstring + i << endl;

    chPtr = cstring;
    for(int i = 0; i < Size; i++)
    {
        cout << "znak :" << chPtr[i] << " po adresem"
             << static_cast<void*> (chPtr + i) << endl;
    }

    castDemo1();
    return 0;
}
