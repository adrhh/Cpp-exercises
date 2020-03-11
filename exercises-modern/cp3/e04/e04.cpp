#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <iostream>

template <typename Iter>
std::string join_str(Iter beg, Iter end, const char* sep)
{
    std::ostringstream oss;
    std::copy(beg, end-1, std::ostream_iterator<std::string>(oss, sep));
    oss << *(end-1);
    return oss.str();
}

template <typename T>
std::string join_str(const T& t, const char* sep)
{
    if ( !std::size(t))
        return std::string{};
    return join_str(std::begin(t), std::end(t), sep);
}

int main()
{
    std::vector<std::string> v1{"aaa", "bbb", "ccc", "ddd"};
    std::string v2[]{"eee", "fff", "gg"};
    char* v3[]{"hhh", "iii", "jjjjj"}; // forbiden convert, only for test
    
    std::cout << join_str(v1, ";") << std::endl;
    std::cout << join_str(v2, " - ") << std::endl;
    std::cout << join_str(v3, ", ") << std::endl;
    
    return 0;
}
