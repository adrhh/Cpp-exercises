#include <iostream>
#include <vector>
#include <initializer_list>
#include <iterator>

template <typename T, size_t R, size_t C>
class arr2d
{
private:
    typedef T value_type;
    typedef value_type* iterator;
    typedef const value_type*  const_iterator;
    std::vector<T> arr;

public:
    arr2d() : arr(R*C) {}
    explicit arr2d(std::initializer_list<T> list) : arr(list) {}
    constexpr T* data() noexcept 
    {
        // address to first vector element
        return arr.data();
    }
    constexpr const T* data() const noexcept
    {
        return arr.data();
    }
    constexpr T& at(const size_t r, const size_t c)
    {
        // reference to vector element
        // bounds checking
        return arr.at(r*C + c);
    }
    constexpr const T& at(const size_t r, const size_t c) const
    {
        return arr.at(r*C + c);
    }
    constexpr T& operator()(const size_t r, const size_t c)
    {
        return arr[r*C + c];
    }
    constexpr const T& operator()(const size_t r, const size_t c) const
    {
        return arr[r*C + c];
    }
    constexpr bool empty() const
    {
        return R == 0 || C == 0;
    }
    constexpr size_t rsize() const
    {
        return R;
    }
    constexpr size_t csize() const
    {
        return C;
    }
    void fill(const T& v)
    {
        std::fill(arr.begin(), arr.end(), v);
    }
    void swap(arr2d& other_arr) noexcept
    {
        arr.swap(other_arr);
    }
    const_iterator begin() const { return arr.data(); }
    const_iterator end() const { return arr.data() + arr.size(); }
    iterator begin()  { return arr.data(); }
    iterator end()  { return arr.data() + arr.size(); }
    typename std::vector<T>::reverse_iterator rend() 
    { 
        return arr.rend(); 
    }
    typename std::vector<T>::reverse_iterator rbegin() 
    { 
        return arr.rbegin(); 
    }
};

int main()
{
    arr2d<unsigned int, 4, 4> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    for(auto itr = a1.begin(); itr != a1.end(); ++itr)
        std::cout << " ["<< std::distance(a1.begin(), itr) << "] " << *itr << ' ';
    
    std::cout << std::endl;
    
    for(auto itr = a1.rbegin(); itr != a1.rend(); ++itr)
        std::cout << *itr << ' ';
    
    std::cout << std::endl;
    
    for(unsigned int i = 0; i < a1.rsize(); ++i)
    {
        for(unsigned j = 0; j < a1.csize(); ++j)
            std::cout << a1(i, j) << ' ';
        std::cout << '\n';
    }
    a1(0,0) = 100;
    std::cout << static_cast<unsigned int>(a1(0,0));
    std::cout << std::endl;
    a1.fill(0);
    for(unsigned int i = 0; i < a1.rsize(); ++i)
    {
        for(unsigned j = 0; j < a1.csize(); ++j)
            std::cout << a1(i, j) << ' ';
        std::cout << '\n';
    }
    return 0;
}
