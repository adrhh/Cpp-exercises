#include <string>
#include <sstream>
#include <memory>
#include <cctype>
#include <iostream>

// std::string is an instantion of tstring<char>
// std::char_traits is template for string operations with different char type
template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tsstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(const tstring<Elem>& text)
{
    tsstream<Elem> rettext;
    bool newWord = true;
    for(const auto ch : text)
    {
        if (std::isalnum(ch) && newWord)
        {
            newWord = false;
            rettext << static_cast<Elem>(std::toupper(ch));
        }
        else
        {
            rettext << ch;
            if (std::isspace(ch))
                newWord = true;
        }
    }
    return rettext.str();
}

int main()
{
    std::string test{"test nanana ododo o a"};
    std::wstring test2;
    // L is wchar_t literal
    test2 += L"ddd ooo aooad";
    std::cout << capitalize(test) << std::endl;
    std::wcout << capitalize(test2) << std::endl;
    
    return 0;
}
