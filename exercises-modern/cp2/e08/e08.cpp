#include <ostream>
#include <iostream>
#include <cmath>

bool are_equal(const double a, const double b, const double epsilon=0.001)
{
    return std::fabs(a-b) < epsilon;
}

namespace temperature
{
    enum class Scale { celsius, farenhiet, kelvin };
    
    template <Scale S>
    class Quantity
    {
        const double amount;
    public:
        constexpr explicit Quantity(const double a) : amount{a} {}
        explicit operator double() const { return amount; }
        
    };
    
    
    std::ostream& operator<< (std::ostream& os, const Quantity<Scale::celsius> q)
    {
        os << static_cast<double>(q) << " C";
        return os;
    }
    
    std::ostream& operator<< (std::ostream& os, const Quantity<Scale::farenhiet> q)
    {
        os << static_cast<double>(q) << " F";
        return os;
    }
    
    std::ostream& operator<< (std::ostream& os, const Quantity<Scale::kelvin> q)
    {
        os << static_cast<double>(q) << " K";
        return os;
    }
 

    template <Scale S>
    inline bool operator==(const Quantity<S>& left, const Quantity<S>& right)
    { return are_equal(
        static_cast<double>(left), 
        static_cast<double>(right)); }
    
    template <Scale S>
    inline bool operator!=(const Quantity<S>& left, const Quantity<S>& right)
    { return !(left==right);}
    
    template <Scale S>
    inline bool operator<(const Quantity<S>& left, const Quantity<S>& right)
    { return static_cast<double>(left) < static_cast<double>(right); }
    
    template <Scale S>
    inline bool operator>(const Quantity<S>& left, const Quantity<S>& right)
    { return static_cast<double>(left) > static_cast<double>(right); }
    
    template <Scale S>
    inline bool operator<=(const Quantity<S>& left, const Quantity<S>& right)
    { return !(left > right); }
    
    template <Scale S>
    inline bool operator>=(const Quantity<S>& left, const Quantity<S>& right)
    { return !(left < right); }
    
    template <Scale S>
    inline Quantity<S> operator+(const Quantity<S>& left, const Quantity<S>& right)
    {
        return Quantity<S>(static_cast<double>(left) + static_cast<double>(right) );
    }
    
    template <Scale S>
    inline Quantity<S> operator-(const Quantity<S>& left, const Quantity<S>& right)
    {
        return Quantity<S>(static_cast<double>(left) - static_cast<double>(right) );
    }
    
    template <Scale S, Scale R>
    struct conversion
    {
      static double convert(const double val) = delete;  
    };
    
    template<>
    struct conversion<Scale::celsius, Scale::farenhiet>
    {
        static double convert(const double val)
        {
            return (val * 9) / 5 + 32;
        }
    };
    
    template<>
    struct conversion<Scale::celsius, Scale::kelvin>
    {
        static double convert(const double val)
        {
            return val + 273.15;
        }
    };
    
    template<>
    struct conversion<Scale::farenhiet, Scale::celsius>
    {
        static double convert(const double val)
        {
            return (val - 32) * 5 / 9;
        }
    };
    
    template<>
    struct conversion<Scale::farenhiet, Scale::kelvin>
    {
        static double convert(const double val)
        {
            return (val + 459.67) * 5 / 9;
        }
    };
    
    template<>
    struct conversion<Scale::kelvin, Scale::celsius>
    {
        static double convert(const double val)
        {
            return val - 273.15;
        }
    };
    
    template<>
    struct conversion<Scale::kelvin, Scale::farenhiet>
    {
        static double convert(const double val)
        {
            return (val - 273.15) * 9 / 5 + 32;
        }
    };
    
    template <Scale R, Scale S>
    constexpr Quantity<R> temperature_cast(const Quantity<S> q)
    {
        return Quantity<R>( conversion<S, R>::convert(static_cast<double>(q)) );
    };    
    
    // https://en.cppreference.com/w/cpp/language/user_literal
    namespace temperature_literalas
    {
        constexpr Quantity<Scale::celsius> operator "" _deg(const long double amount)
        { return Quantity<Scale::celsius>(amount); }
    }
    
    namespace temperature_literalas
    {
        constexpr Quantity<Scale::farenhiet> operator "" _f(const long double amount)
        { return Quantity<Scale::farenhiet>(amount); }
    }
    
    namespace temperature_literalas
    {
        constexpr Quantity<Scale::kelvin> operator "" _k(const long double amount)
        { return Quantity<Scale::kelvin>(amount); }
    }
};


int main()
{
    using namespace temperature;
    using namespace temperature_literalas;
    auto t1{ 100.0_deg };
    auto t1k = temperature_cast<Scale::kelvin>(t1);
    auto t1f = temperature_cast<Scale::farenhiet>(t1);
    auto t2 = temperature_cast<Scale::celsius>(t1k);
    
    std::cout << t1 << '\t' << t2 << '\t'  << (t1 == t2) << std::endl;
    std::cout << t1k << std::endl;
    std::cout << t1f << std::endl;
    
    return 0;
}
