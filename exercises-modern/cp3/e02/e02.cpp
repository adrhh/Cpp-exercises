#include <string>
#include <iostream>
#include <vector>
#include <iterator>

std::vector<unsigned char> stoucv(const std::string& str)
{
    std::vector<unsigned char> ret_vec;
    if( str.length() % 2 == 0)
        for(unsigned int i=0; i <str.length(); i+=2)
        {
            std::string temp{str[i], str[i+1]};
            ret_vec.push_back(std::stoul(temp, nullptr, 16));
        }
        
    return ret_vec;
}

int main()
{
    std::string bstr{"01FF00A00B"};
    std::vector<unsigned char> bv = stoucv(bstr);
    std::ostream_iterator<unsigned int> os(std::cout, ", ");
    std::copy(bv.begin(), bv.end(), os );
    
    return 0; 
}
