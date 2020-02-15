#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
#include <utility>
#include <algorithm>

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

auto div_sum = [](const unsigned int n) {
    auto divs = get_divisors(n);
    return std::accumulate(divs.begin(), divs.end(), 1);
};

std::vector<std::pair<unsigned int, unsigned int>> get_amicable_numbers(unsigned int limit)
{
    std::vector<std::pair<unsigned int, unsigned int>> vec;
    for(auto i = 4u; i <= limit; i++)
    {
        auto sum = div_sum(i);
        if(sum <= limit)
            if ( div_sum(sum) == i && i != sum)
                if ( std::find_if(vec.begin(), vec.end(), [&i](auto p){ return i == p.second;} ) == vec.end())
                    vec.push_back(std::make_pair(i, sum));
    }
    return vec;
}

int main()
{
    unsigned int limit;
    std::cout << "Podaj limit" << std::endl;
    std::cin >> limit;
        
    auto amicables = get_amicable_numbers(limit);
    for(const auto& item: amicables)
        std::cout << item.first << ", " << item.second << std::endl;
    
    return 0;
}
