#include <iostream>
#include <vector>
#include <cmath>
// prime numbers

std::vector<unsigned int> get_primes(unsigned int range)
{
    
    const unsigned int START_VAL = 2;
    const unsigned int NO_PRIME = 0;
    std::vector<unsigned int> vec(range-START_VAL);
    std::vector<unsigned int>primes;
    auto ins = std::back_inserter(primes);
    
    for(auto itr = vec.begin(); itr != vec.end(); ++itr)
    {
        *itr = itr - vec.begin() + START_VAL;
        for(auto i = START_VAL; i < *itr; ++i)
            if ( !(*itr % i) )
                *itr = NO_PRIME;
        if(*itr != NO_PRIME)
            ins = *itr;
    }
    
    return primes;
}

bool is_prime(unsigned int n)
{
    if(n <= 3)
        return n > 1;
    else if ( !(n % 2) || !(n % 3) )
        return false;
    else
        for (int i = 5; i*i <= n; i+=6)
            if( !(n % i) || !(n % (i +2)) )
                return false;
    return true;
}

int main()
{
    int n;
    std::cout << "Podaj liczbe pierwsza" << std::endl;
    std::cin >> n;
    if(is_prime(n))
        std::cout << "Najwiekasza libcza pierwsza mniejsza od " << n << '\n'
                  << *(get_primes(n).end() - 1) << std::endl;
    else
        std::cout << n << " nie jest liczba pierwsza" << std::endl;
    
    return 0;
}
