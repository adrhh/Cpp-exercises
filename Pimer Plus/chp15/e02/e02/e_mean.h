#ifndef E_MEAN_H_
#define E_MEAN_H

#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean() : std::logic_error("Nieporawny argument hmean()") {}
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean() : std::logic_error("Nieporawny argument gmean()") {}
};

#endif // !E_MEAN_H_
