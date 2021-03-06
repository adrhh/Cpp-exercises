#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
private:
	char title[40];

public:
	Classic(const char * s0, const char * s1, const char * s2, int n, double x);
	Classic(const char* s0, const Cd& cd);
	Classic();
	~Classic();
	void report() const;
};

#endif //!CLASSIC_H_


