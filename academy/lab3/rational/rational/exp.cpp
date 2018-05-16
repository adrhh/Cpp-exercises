#include "pch.h"

void Literal::accept(Visitor* v) const
{
	v->visit(*this);
}

void Add::accept(Visitor* v) const
{
	v->visit(*this);
}

void Mult::accept(Visitor* v) const 
{
	v->visit(*this);
}