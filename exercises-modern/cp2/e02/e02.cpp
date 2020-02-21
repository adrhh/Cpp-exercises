#include <array>
#include <string>
#include <sstream>
#include <ostream>
#include <istream>
#include <iostream>

class ip4
{
private:
    std::array<unsigned char, 4> data;
public:
    constexpr ip4() : data{ {0} } {}
    constexpr ip4(unsigned char a, unsigned char b, unsigned char c, unsigned char d) :
        data {a,b,c,d} {}
    explicit constexpr ip4(unsigned long a) :
        data{ 
            static_cast<unsigned char>( (a>>24) & 0xFF),
            static_cast<unsigned char>( (a>>16) & 0xFF),
            static_cast<unsigned char>( (a>>8) & 0xFF),
            static_cast<unsigned char>( a & 0xFF),
        } {}
    ip4(const ip4& ip) noexcept : data(ip.data) {}
    ip4(const std::array<unsigned char, 4> arr) noexcept : data(arr) {} 
    ip4& operator=(const ip4& ip)
    {
        data = ip.data;
        return *this;
    }
    std::string to_string() const
    {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }
    constexpr unsigned long to_long() const noexcept
    {
        return (
            static_cast<unsigned long>(data[0] << 24) |
            static_cast<unsigned long>(data[1] << 16) |
            static_cast<unsigned long>(data[2] << 8) |
            static_cast<unsigned long>(data[3])
        );
    }
    friend std::ostream& operator<<(std::ostream& os, const ip4& ip)
    {
        os << static_cast<int>(ip.data[0]) << '.' 
           << static_cast<int>(ip.data[1]) << '.' 
           << static_cast<int>(ip.data[2]) << '.' 
           << static_cast<int>(ip.data[3]);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, ip4& ip)
    {
        char d1, d2, d3;
        int a, b, c, d;
        is >> a >> d1 >> b >> d2 >> c >> d3 >> d;
        if( d1 == '.' && d2 == '.' && d3 == '.')
            ip = ip4(a,b,c,d);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }
    //prefix
    ip4& operator++()
    {
        *this = ip4(1 + to_long());
        return *this;
    }
    //sufix
    ip4 operator++(int)
    {
        ip4 temp(*this);
        ++(*this);
        return temp;
    }
    friend bool operator==(const ip4& a, const ip4& b) noexcept
    {
        return a.to_long() == b.to_long();
    }
    friend bool operator!=(const ip4& a, const ip4& b) noexcept
    {
        return !(a == b);
    }
    friend bool operator<(const ip4& a, const ip4& b) noexcept
    {
        return a.to_long() < b.to_long();
    }
    friend bool operator>(const ip4& a, const ip4& b) noexcept
    {
        return b < a;
    }
    friend bool operator<=(const ip4& a, const ip4& b) noexcept
    {
        return !(a > b);
    }
    friend bool operator>=(const ip4& a, const ip4& b) noexcept
    {
        return !(a < b);
    }
    ip4& operator^=(const ip4& ip) noexcept
    {
        *this = ip4(to_long() ^ ip.to_long());
        return *this;
    }
    friend ip4 operator^(const ip4& a, const ip4& b) noexcept
    {
        return ip4(a.to_long() ^ b.to_long());
    }
    ip4& operator&=(const ip4& ip) noexcept
    {
        *this = ip4(to_long() & ip.to_long());
        return *this;
    }
    friend ip4 operator&(const ip4& a, const ip4& b) noexcept
    {
        return ip4(a.to_long() & b.to_long());
    }
};

int main()
{
    ip4 ip_1(0,2,3,4);
    ip4 ip_2 = ip_1;
    std::cout << ip_1 << ", " << ip_2 << std::endl;
    std::cout << ip_1.to_string() << ", " << ip_1.to_long() << std::endl;
    
    ip4 ip_3(255, 255, 129 , 0);
    std::cout << (ip_1 ^ ip_3) << std::endl;
    std::cout << (ip_1 & ip_3) << std::endl;
    std::cout << ip_1 <<   ' '<< ++ip_1 << ' ' << ip_1++ << ' ' << ip_1 << std::endl;
    std::cout << (ip_1 > ip_2) << std::endl;
    std::cout << (ip_1 == ip_1) << std::endl;
    return 0;
}
