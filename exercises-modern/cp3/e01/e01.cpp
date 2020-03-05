#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>

template <class C>
std::string bytes_to_string(const C& container)
{
    std::stringstream ss;
    for(auto const c : container)
        ss << std::hex  << std::setfill('0') << static_cast<int>(c) ;
    return ss.str();
}


template <typename T>
std::string bytes_to_string_t(const T& arg)
{   
    std::stringstream ss;
    ss << std::hex  << std::setfill('0') << arg ;
    return ss.str();
}

template <typename T1, typename ... T>
std::string bytes_to_string_t(T1 a, T ... args)
{
    std::string str;
    str += bytes_to_string_t(a);
    str += bytes_to_string_t(args ...);
    return str;
}


int main()
{
    std::vector<unsigned int> vec{0xFF, 0x12, 0x0A, 0xB0, 0xD3, 0x31};
    std::array<unsigned int, 6> arr;
    std::copy(vec.begin(), vec.end(), arr.data());

    
    std::cout << bytes_to_string(vec) << std::endl;
    std::cout << bytes_to_string(arr) << std::endl;
    std::cout << bytes_to_string_t(0xFF, 0x12, 0x0A, 0xB0, 0xD3, 0x31) << std::endl;
     
    return 0;
}
