#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include <array>
#include <functional>

// 3.14159265358979323846
// random:
// std::mt19937 Mersenne Twister 19937 generator
// std::uniform_real_distribution P(i/a,b) = 1/(b-a)

unsigned long fact(unsigned long n)
{
    unsigned long res = 1;
    for(unsigned long i = 2; i <= n; ++i)
        res *= i;
    return res;
}

double long get_pi_chu(unsigned steps)
{
    //Chudovsky formula
    
    auto M = [](unsigned long k) -> unsigned long 
    {
        return fact(6*k) / (fact(3*k) * static_cast<unsigned long>(std::pow(fact(k),3)));
    };
    
    const double long C_ELEM = 426880 * sqrt(10005);
    const double long L_ELEM = 545140134;
    const double long X_ELEM = -262537412640768000;
    double long x;
    double long l = 13591409;
    double long sum = 0;
    for(int k=0; k <= steps; ++k)
    {
        l += k * L_ELEM;
        x = pow(X_ELEM, k);
        sum += M(k) * l / x;
    }
    
    return C_ELEM / sum;
}

template <typename E = std::mt19937, typename D = std::uniform_real_distribution<>>
double long get_pi_monte(E& engine, D& dist, const unsigned long samples)
{
    auto hit = 0UL;
    for( auto i = 0UL; i < samples; ++i)
    {
        auto x = dist(engine);
        auto y = dist(engine);
        if ( y <= std::sqrt( 1 - std::pow(x, 3)))
            hit += 1UL;
    }
    return 4.0DL * hit / samples;
}

int main()
{
    for(unsigned int i = 0; i <= 9; ++i)
        std::cout << std::setprecision(80) << get_pi_chu(i) << std::endl;
    
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto eng = std::mt19937 { seq };
    auto dist = std::uniform_real_distribution<> {0, 1};
    
    for(unsigned long i = 10; i < 100000000; i *= 10)
    {
        std::cout << "Samples: " << i << std::endl;
        for(auto j = 0u; j < 10; ++j)
            std::cout << std::setprecision(80) << get_pi_monte(eng, dist, i) << std::endl;
        std::cout << std::endl;
    }
    
}


