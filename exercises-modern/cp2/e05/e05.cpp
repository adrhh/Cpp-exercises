#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>

template <typename ... Args>
void fold_print1(Args&&... args)
{
    (std::cout<< ... <<args);
}

template <typename ... Args>
void fold_print2(std::ostream& os, Args&&... args)
{
    (os << ...  <<  args);
}

template <typename ... Args>
auto fold_sum(Args&&... args)
{
    return (... + args);
}

template <class C, typename... Args>
void push_back(C& c, Args&&... args)
{
    (c.push_back(args), ...);
}

int main()
{
    std::vector<int> vec;
    
    push_back(vec, 1, 2, 3, 4, 5);
    
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<decltype(*vec.data())>(std::cout, " "));
    
    std::cout << '\n';
    fold_print1(1, 2, 3, 4, 5);
    std::cout << '\n';
    fold_print2(std::cout, 1, 2, 3, 4, 5);
    std::cout << '\n';
    std::cout << fold_sum(1, 2, 3, 4, 5);

}
