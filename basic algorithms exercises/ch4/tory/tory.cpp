// Example program
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

class Dom
{
    private:
        int x;
        int y;
    public:
        Dom(int a, int b) : x(a), y(b) {}
        int getX() const {return x;}
        int getY() const {return y;}
        bool operator<(const Dom& h) const
        {
            return x < h.x;
        }
        int distance(const Dom& h) const
        {
            return getY() + h.getY() + abs(getX() - h.getX());
        }
};

void printDomArr(const std::vector<Dom> v)
{
    for_each(v.begin(), v.end(), [](const Dom& d) {std::cout << '(' << d.getX() << " ," << d.getY() << ") ";});
}

int zadanie(std::vector<Dom> v)
{
    std::sort(v.begin(), v.end());
    int min = INT_MAX;
    for(auto it = v.begin() + 1; it != v.end(); ++it)
    {
        int dist = it->distance(*(it-1));
        min = min < dist ? min : dist;
    }
    return min;
}

int main()
{
    std::vector<Dom> arr {Dom(6,3), Dom(2,5), Dom(4,1), Dom(1,2)};
    std::cout << zadanie(arr) << std::endl;
    //printDomArr(arr);
    return 0;
}
