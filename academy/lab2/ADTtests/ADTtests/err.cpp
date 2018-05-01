#include "err.h"
#include "pch.h"

void error(const std::string& s)
{
	throw std::runtime_error(s);
}