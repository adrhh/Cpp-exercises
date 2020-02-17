#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const unsigned long long COLL_START = 2;

unsigned long  collatz_steps(unsigned long long n)
{
    auto steps = 0LU;
    while(n != 1)
    {
        if( !(n%2))
            n /=2;
        else
            n = 3*n + 1;
        steps++;
    }
    return steps;
}

std::vector<unsigned long> collatz_brute_force(unsigned long long limit)
{
    std::vector<unsigned long> steps(limit + 1, 0);
    for(auto i = COLL_START; i <= limit; ++i)
        steps[i] = collatz_steps(i);
    return steps;
}

std::pair<unsigned long long, unsigned long> collatz_longest(const unsigned long long limit)
{
    unsigned long max_len = 0;
    unsigned long long nr = 0;
    
    std::vector<unsigned long> cache(limit + 1);
    for(auto i = COLL_START; i <= limit; ++i)
    {
        auto n = i;
        unsigned long steps = 0;
        while( n != 1 && n >= i)
        {
            if ( !(n%2))
                n /= 2;
            else
                n = n*3 + 1;
            steps++;
        }
        cache[i] = steps + cache[n];
        if (cache[i] > max_len)
        {
            max_len = cache[i];
            nr = i;
        }
    }
    
    return std::make_pair(nr, max_len);
}

int main()
{
    unsigned long long limit = 0;
    std::cout << "Podaj limit" << std::endl;
    std::cin >> limit;
    
    auto collz = collatz_brute_force(limit);
    auto max_steps = std::max_element(collz.begin(), collz.end());
    std::cout << "max step: " << *max_steps << " at number: " << max_steps - collz.begin()<< std::endl;
    
    auto max_steps_nr = collatz_longest(limit);
    std::cout << "max step: " << max_steps_nr.second << " at number: " << max_steps_nr.first << std::endl;
    
    return 0;
}
