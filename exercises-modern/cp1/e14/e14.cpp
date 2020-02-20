#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <cctype>

class ISBN
{
protected:
    std::string isbn;
    unsigned int nation_code;
    unsigned int publisher_code;
    unsigned int book_nr;
    unsigned int control_sum;
    unsigned long int nr;
public:
    ISBN() : isbn{}, nation_code{0}, publisher_code{0},
             book_nr{0}, nr{0} {}
            
    virtual bool verify() const = 0;
    virtual std::string get_str() const = 0;
    virtual ~ISBN() = default;
};

class ISBN10 : protected ISBN
{
public:
    ISBN10(const std::string& str);
    virtual bool verify() const override;
    virtual std::string get_str() const { return isbn; }
};

class ISBN13 : protected ISBN
{
protected:
    unsigned int ean;
public:
    ISBN13(const std::string& str);
    virtual bool verify() const override;
    virtual std::string get_str() const { return isbn; }
};

bool ISBN10::verify() const 
{
    bool is_correct = false;
    unsigned int sum = 0;
    unsigned int temp_nr = nr / 10;
    if(temp_nr)
    {
        for(unsigned int i = 9; i; --i)
        {
            unsigned int dig = temp_nr % 10;
            temp_nr /= 10;
            sum += i * dig;
        }
        if( sum % 11 == nr % 10)
            is_correct = true;
    }
    return is_correct;
}

bool ISBN13::verify() const 
{
    bool is_correct = false;
    unsigned int sum = 0;
    unsigned long int temp_nr = nr / 10;
    if(temp_nr)
    {
        for(unsigned int i = 0; i < 12; ++i)
        {
            unsigned int dig = temp_nr % 10;
            temp_nr /= 10;
            sum += ( i%2 == 0 ) ? dig * 3: dig;
        }
        if( (sum / 10) % 10 == nr % 10)
            is_correct = true;
    }
    return is_correct;
}

ISBN10::ISBN10(const std::string& str)
{
    if ( str.length() == 13 &&
         std::count_if(str.begin(), str.end(), isdigit) == 10 &&
         std::count(str.begin(), str.end(), '-') == 3 &&
         str[0] != '-' &&
         str[str.length() - 1] != '-'
       )
    {
        std::vector<std::reference_wrapper<unsigned int>> file_vec {
            std::ref(nation_code), 
            std::ref(publisher_code), 
            std::ref(book_nr), 
            std::ref(control_sum)
        };
        unsigned int temp_nr = 0;
        unsigned int temp_counter = 0;
        for(auto c = str.begin(); c != str.end(); ++c)
        {
            if (isdigit(*c))
            {
                nr += *c - '0';
                nr *= 10;
                temp_nr += *c - '0';
                temp_nr *= 10;             
            }
            else
            {
                file_vec[temp_counter++].get() = temp_nr / 10;
                temp_nr = 0;
            }
        }
        nr /= 10;
        isbn = str;
    }
}

ISBN13::ISBN13(const std::string& str) : ean{0}
{
    if ( str.length() == 17 &&
         std::count_if(str.begin(), str.end(), isdigit) == 13 &&
         std::count(str.begin(), str.end(), '-') == 4 &&
         std::count_if(str.begin(), str.begin() + 3, isdigit) == 3 &&
         str[str.length() - 1] != '-'
       )
    {
        std::vector<std::reference_wrapper<unsigned int>> file_vec {
            std::ref(ean),
            std::ref(nation_code), 
            std::ref(publisher_code), 
            std::ref(book_nr), 
            std::ref(control_sum)
            
        };
        unsigned int temp_nr = 0;
        unsigned int temp_counter = 0;
        for(auto c = str.begin(); c != str.end(); ++c)
        {
            if (isdigit(*c))
            {
                nr += *c - '0';
                nr *= 10;
                temp_nr += *c - '0';
                temp_nr *= 10;             
            }
            else
            {
                file_vec[temp_counter++].get() = temp_nr / 10;
                temp_nr = 0;
            }
        }
        nr /= 10;
        isbn = str;
    }
}

int main()
{

    ISBN10 isbn10{"0-306-40615-2"};
    std::cout << isbn10.get_str() << std::endl;
    std::cout << isbn10.verify()  << std::endl;
    
    ISBN13 isbn13{"978-3-16-148410-0"};
    std::cout << isbn13.get_str() << std::endl;
    std::cout << isbn13.verify()  << std::endl;
    
    return 0;
}
