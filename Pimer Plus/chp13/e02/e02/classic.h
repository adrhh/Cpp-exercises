#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
private:
	char* title;

public:
	Classic(const char * s0, const char * s1, const char * s2, int n, double x);
	Classic(const char* s0, const Cd& cd);
	Classic();
	Classic(const Classic& c);
	~Classic();
	void report() const;
	Classic& operator=(const Classic& c);
};

#endif //!CLASSIC_H_