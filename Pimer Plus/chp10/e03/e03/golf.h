#ifndef GOLF_H_
#define GOLF_H_

const int ARRSIZE = 5;
const int LEN = 40;

class Golf
{
private:
	char fullname[LEN];
	int handicap;
public:
	Golf();
	Golf(const char* name, int hc);
	void showGolf() const;
};

#endif // !GOLF_H_
