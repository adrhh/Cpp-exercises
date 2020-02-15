#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
// sexy prime numbers

std::vector<unsigned int> get_primes(unsigned int range)
{
    
    const unsigned int START_VAL = 2;
    const unsigned int NO_PRIME = 0;
    if(range < 2)
        return std::vector<unsigned int>(0);
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


std::vector<std::pair<unsigned int, unsigned int>> get_primes_6th(unsigned int range)
{
    
    std::vector<unsigned int> primes = get_primes(range);
    std::vector<std::pair<unsigned int, unsigned int>> primes_6th_pair;
    if(primes.size() < 2)
        return primes_6th_pair;
    for(auto itr = primes.begin(); itr != primes.end(); ++itr)
        for(auto itr6 = itr; itr6 != primes.end(); ++itr6)
        {
            if(*itr6 > *itr + 6)
                break;
            if(*itr6 - *itr == 6)
                primes_6th_pair.push_back(std::make_pair(*itr, *itr6));
        }
    
    return primes_6th_pair;
}

bool is_prime_6th(unsigned int n)
{
    if( is_prime(n) )
    {
        if(is_prime(n+6))
            return true;
        if(n > 6 && is_prime(n-6))
            return true;
    }
    return false;
}

int main()
{
    int limit;
    std::cout << "Podaj limit" << std::endl;
    std::cin >> limit;
    std::cout << "Liczby pierwsze szotskowe" << std::endl;
    for(const auto& item : get_primes_6th(limit))
        std::cout << item.first << ", " << item.second << std::endl;
    
    unsigned n;
    std::cout << "Podaj liczbe do sprawdzenia" << std::endl;
    std::cin >> n;
    std::cout << n << (is_prime_6th(n) ? " " : " nie ") << "jest liczba pierwsza szotkowa" << std::endl;
        
    return 0;
}
