#ifndef CD_H_
#define CD_H_

class Cd
{
private:
	char perf[50];
	char label[20];
	int selections;
	double playtime;

public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void report() const;
};

#endif //!CD_H_

