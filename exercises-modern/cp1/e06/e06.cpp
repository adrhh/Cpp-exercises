#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>


std::vector<unsigned int> get_divisors(unsigned int n)
{
    std::vector<unsigned int> vec;
    auto ins = std::back_inserter(vec);
    
    for(auto i = 2u; i <= static_cast<unsigned int>(sqrt(n)); ++i)
        if ( !(n % i) )
        {
            ins = i;
            if ( i != n / i)
                ins = n / i;
        }
    return vec;
}

int abundan_factor(unsigned int n)
{
    auto divs = get_divisors(n);
    auto div_sum = std::accumulate(divs.begin(), divs.end(), 1);
    for(auto d : divs)
        std::cout << d << ',';
    std::cout << '\n' << n << " , " << div_sum << std::endl;
    if(div_sum < n)
        return -1;
    return div_sum - n;
}

std::vector<unsigned int> get_abundan_numbers(unsigned int range)
{
    std::vector<unsigned int> abundans;
    for(unsigned int i = 2; i <= range; ++i)
        if (abundan_factor(i) >= 0 )
            abundans.push_back(i);
    return abundans;
}

int main()
{
    std::cout << "Podaj limit " << std::endl;
    unsigned int limit;
    std::cin >> limit;
    std::cout << "Liczby obfite w zakresie <2, " << limit << ">" << std::endl;
    for (const auto& n : get_abundan_numbers(limit))
        std::cout << n << std::endl;
}
