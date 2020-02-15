#include <iostream>
#include <numeric>
#include <cstdlib>
#include <functional>


int gcd(int a, int b) 
{ 
    return (!b) ? a : gcd(b, a % b);
} 

int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

template <typename T>
int lcmr(T first, T end)
{
    return std::accumulate(first, end, 1, lcm);
}

int main()
{
    int a;
    int b;
    
    std::cout << "Podaj dwie liczby" << std::endl;
    std::cin >> a >> b;
    std::cout << "Najmniejsza wspolna wielokrotnosc: " << std::endl;
    std::cout << lcm(a, b) << std::endl;
    std::cout << std::lcm(a, b) << std::endl;
    
    const size_t ARRS = 10;
    int arr[ARRS] = {1,2,3,4,5,6,7,8,9,10};
    int arr_lcm = lcmr(arr, arr + ARRS);
    std::cout << arr_lcm << std::endl;
    
    int sum = std::accumulate(arr, arr + ARRS, 0);
    std::cout << sum << std::endl;
    int sub = std::accumulate(arr, arr + ARRS, 0, std::minus<int>());
    std::cout << sub << std::endl;
    int fact = std::accumulate(arr, arr + ARRS, 1, std::multiplies<int>());
    std::cout << fact << std::endl;
    
    
    auto pow = [](int a, int b) -> int {
        int f = a;
        for(int i = 1; i < b; ++i)
            a *= f;
        return a;
    };
    
    long long powr = std::accumulate(arr, arr + 4, 2, [&pow](int a, int b){ return pow(a,b); });
    std::cout << powr << std::endl;
    
    return 0;
}
