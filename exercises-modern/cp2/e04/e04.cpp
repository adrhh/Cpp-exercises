#include <iostream>


// simple unpack test
template <typename T>
void va_test(const T& arg)
{
    std::cout << arg << std::endl;
}

template <typename T1, typename ... T>
void va_test(T1 a, T ... args)
{
    std::cout << a << std::endl;
    return va_test(args ...);
}


template <typename T>
class test_less
{
public:
    constexpr bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};

// test specialization
template <>
class test_less<long>
{
public:
    constexpr bool operator()(const long& a, const long& b) const
    {
        return a > b; //!
    }
};

template <class Comp, typename T>
T va_min(Comp comp, const T a, const T b)
{
    return comp(a, b) ? a : b;
}

template <class Comp, typename T1, typename ... T>
T1 va_min(Comp comp, T1 a, T ... args)
{
    return va_min(comp, a, va_min(comp, args ...));
}


int main()
{
    // unpack va from simple tests
    va_test(1,2,3,6,5);
    std::cout << '\n';
    std::cout << va_min(test_less<int>(), 1,2,3,-4,0) << std::endl;
    std::cout << va_min(test_less<long>(), 15L,2L,3L,3L,30L) << std::endl;
}
