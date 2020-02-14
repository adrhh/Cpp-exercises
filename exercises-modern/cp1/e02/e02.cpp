#include <iostream>
#include <numeric>

unsigned int gcd_euk(unsigned int a, unsigned int b)
{
    while(b)
    {
        unsigned int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

unsigned int gcd_euk_r(unsigned int a, unsigned int b)
{
    return b == 0 ? a : gcd_euk_r(b, a % b);
}

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    
    std::cout << "Podaj dwie liczby naturalne" << std::endl;
    
    std::cin >> a >> b;
    std::cout << "Najwiekszy wspolny dzilenik " << a << " i " << b << endl;
    std::cout << std::gcd(a, b) << std::endl;
    std::cout << gcd_euk(a, b) << std::endl;
    std::cout << gcd_euk_r(a, b) << std::endl;
    
    return 0;
}
