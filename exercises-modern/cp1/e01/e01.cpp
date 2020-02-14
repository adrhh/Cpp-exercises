#include <iostream>
Sum of the numbers divisible by 3 or 5

using std::cin;
using std::cout;
using std::endl;

unsigned int sum_d3_d5(unsigned int end)
{
    unsigned int sum = 0;
    for(unsigned int i = 1; i <= end; ++i)
        if ( !(i % 3) || !(i % 5))
            sum += i;
    return sum;
}

int main()
{
    int end = 0;
    cout << "Podaj granice" << endl;
    cin >> end;
    cout << "Suma liczb podzielnych przez 3 lub 5 w zakresie <" << 1 << ", "
         << end << "> wynosi: " << sum_d3_d5(end) << endl;
    
    return 0;
}
