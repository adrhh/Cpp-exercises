#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <regex>

const std::vector<std::pair<const std::string, unsigned int>> roman_int
{
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1},
};

std::string uint_to_roman(unsigned int n)
{
    std::string roman;
    for(auto const& item : roman_int)
    {
        while( n >= item.second)
        {
            roman += item.first;
            n -= item.second;
        }
    }
    
    return roman;
}

unsigned int roman_to_uint(std::string r)
{
    auto pattern = std::regex("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
    if ( ! std::regex_match(r, pattern))
        return 0;

    unsigned int n = 0;
    while(r.size())
        for(auto const& item : roman_int)
        {
            auto fp = r.find(item.first);
            if( fp != std::string::npos)
            {
                n += item.second;
                r.erase(r.begin() + fp, r.begin() + fp + item.first.length());
            }
        }

    return n;
}

int main()
{
    std::cout << "Wprowadz liczbe naturalna" << std::endl;
    int n;
    std::cin >> n;
    auto n_str_roman = uint_to_roman(n);
    std::cout << n_str_roman  << std::endl;
    std::cout << roman_to_uint(n_str_roman) << std::endl;
    
    return 0;
}
