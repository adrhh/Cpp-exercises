#include <iostream>
#include <string>

using namespace std;

void printCharBinnary(char* chPtr)
{
    string binout;
    int number = static_cast<int> (*chPtr);
    int pow = 1;
    for(int i = 7; i >= 0 ; i--)
    {
        pow = 1 << i;
        if(number & pow)
            binout.push_back('1');
        else
            binout.push_back('0');
    }
    cout << binout << endl;
    //reverse

}

void printIntsFromRawMemBinnary(char* chPtr, int size)
{
    char* ptr = chPtr;
    for(int i =0 ; i < size; i++, ptr++)
        printCharBinnary(ptr);
}

void printIntsFromRawMem(char* chPtr, int size)
{
    char* ptr = chPtr;
    for(int i=0; i < size; i++, ptr++)
    {

        cout << static_cast<int> (*ptr);
    }

    cout << endl;
}

void castDemo2()
{
    int ia1[2] = {84281096, 16909060};
    cout << "int ia1[2] = {84281096, 16909060} as a byte stream = ";
    printIntsFromRawMem((char *) ia1, 8);

    int ia2[2] = {67305985, 134678021};
    cout << "int ia2[2] = {67305985, 134678021} as a byte stream = ";
    printIntsFromRawMem((char *) ia2, 8);
    cout << endl;
    printIntsFromRawMemBinnary((char *) ia2, 8);
}

void castDemo3()
{
    float dN = 1.5399896E-36;
    cout << dN << " as a byte stream = ";
    printIntsFromRawMem((char *) &dN, 4);
    cout << endl;
}

int main(int argc, char *argv[])
{
    castDemo2();
    castDemo3();
    return 0;
}
