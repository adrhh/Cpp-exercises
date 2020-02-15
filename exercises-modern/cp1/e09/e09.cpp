#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

std::vector<unsigned long long> get_prime_factors(unsigned long long n)
{
    std::vector<unsigned long long> vec; 
    while( !(n % 2) )
    {
        vec.push_back(2);
        n /= 2;
    }
    for(unsigned long long i = 3; i < ceil(sqrt(n)); i += 2)
        while ( !(n % i) )
        {
            vec.push_back(i);
            n /= i;
        }
    if( n > 2)
        vec.push_back(n);
    
    return vec;
}

int main()
{
    unsigned long long n;
    std::cout << "Wprowadz liczbe naturalna" << std::endl;
    std::cin >> n;
    auto primes = get_prime_factors(n);
    
    std::cout << "Czynniki perwsze liczby " << n << " to:" << std::endl;
    //kopiowanie do strumienia wyjsciowego
    std::ostream_iterator<unsigned long long> os(std::cout, ", ");
    std::copy(primes.begin(), primes.end(), os );
    
    return 0;
}
