#include <vector>
#include <algorithm>
#include <iostream>

template <class C, typename T>
bool contain(C& c, const T& t)
{
    return std::find(c.begin(), c.end(), t) != c.end();
}


template <class C, typename... Args>
bool contain_any(C& c, Args&&... args)
{
    return ( ... || contain(c, args));
}

template <class C, typename... Args>
bool contain_all(C& c, Args&&... args)
{
    return ( ... && contain(c, args));
}


int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7};
    std::cout << contain(vec, 2) << std::endl;
    std::cout << contain_any(vec, 1, 2, 4) << std::endl;
    std::cout << contain_any(vec, 0, 2, 4) << std::endl;
    std::cout << contain_all(vec, 1, 2, 4) << std::endl;
    std::cout << contain_all(vec, 0, 2, 4) << std::endl;
    
    return 0;
}
