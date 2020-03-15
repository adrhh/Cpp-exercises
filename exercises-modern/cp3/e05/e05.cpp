#include <string>
#include <sstream>
#include <iostream>
#include <vector>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tss = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <typename Elem>
std::vector<tstring<Elem>> split(const tstring<Elem>& text, const Elem deli)
{
    auto ss = tss<Elem>{text};
    auto ret_vec = std::vector<tstring<Elem>>{};
    auto word = tstring<Elem>{};
    
    //istream& getline (istream&  is, string& str, char delim)
    while( std::getline(ss, word, deli))
    {
        if ( !word.empty())
            ret_vec.push_back(word);
    }
    
    return ret_vec;
}

int main()
{
    std::wstring test1{L"aaa,bbb,ccc,ddd"};
    auto test1_splited = split(test1, static_cast<wchar_t>(','));
    for(const auto& w: test1_splited)
        std::wcout << w << std::endl;
    return 0;
}
