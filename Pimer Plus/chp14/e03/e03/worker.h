#ifndef WORKER_H_
#define WORKER_H_

#include <string>

using std::string;

class Worker
{
private:
	string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("bak"), id(0L) {}
	Worker(const string& s, long n) : fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();

};


#endif // !WORKER_H_
