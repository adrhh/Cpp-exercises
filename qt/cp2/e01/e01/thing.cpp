#include <iostream>
#include "thing.h"

void Thing::show()
{
	std::cout << m_Number << '\t' << m_Char << std::endl;
}

void Thing::set(int num, char c)
{
	m_Number = num;
	m_Char = c;
}

void Thing::inc()
{
	m_Number++;
	m_Char++;
}