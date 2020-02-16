#include <iostream>
#include <bitset>

unsigned int uint_to_gray(unsigned int n)
{
    return n ^ (n >> 1);
}

unsigned int gray_to_uint(unsigned int n)
{
    unsigned int mask = n >> 1;
    while(mask)
    {
        n ^= mask;
        mask >>= 1;
    }
    return n;
}

int main()
{
    std::cout << "Table for 0 to 255" << std::endl;
    std::cout << "Dec\t Bin\t\t GrayBin\t GrayToIntBin" << std::endl;
    for(unsigned int i = 0u; i <= 0xFF; ++i)
    {
        unsigned int gr = uint_to_gray(i);
        std::cout << i << '\t' << std::bitset<8>(i) << '\t' << std::bitset<8>(gr) << '\t' << std::bitset<8>(gray_to_uint(gr)) << std::endl;
    }
    return 0;
}
