#include <list>
#include <iostream>
#include <vector>
#include <cmath>

std::list<uint8_t> get_digs(unsigned int n)
{
    // returns digs list in order
    std::list<uint8_t> digs;
    auto ins = std::front_inserter(digs);
    while(n)
    {
        ins = n % 10;
        n /= 10;
    }
    return digs;
}

unsigned int pow_sum(int n)
{
    unsigned int sum = 0;
    auto digs = get_digs(n);
    for(const auto& d : digs)
        sum += ceil(pow(d, digs.size()));

    return sum;
}

std::vector<unsigned int> get_amstrong_numbers(const int limit)
{
    std::vector<unsigned int> vec;
    auto ins = std::back_inserter(vec);
    for(int i = 1; i < limit; ++i)
        if( i == pow_sum(i))
            ins = i;
  
    return vec;
}

int main()
{
    unsigned int n;
    std::cout << "Wprowadz grona granice" << std::endl;
    std::cin >> n;
    std::cout << "Liczby Amstronga w przedziale <1, " << n << ">" << std::endl;
    auto ams = get_amstrong_numbers(n);
    for(const auto& a : ams)
        std::cout << a << std::endl;
    
    return 0;
}
