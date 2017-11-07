#ifndef GOLF_H_
#define GOLF_H_

const int ARRSIZE = 5;
const int LEN = 40;
struct golf
{
	char fullname[LEN];
	int handicap;
};

void setgolf(golf &g, const char* name, int hc);
void setgolf(golf &g);
void showgolf(const golf &g);

#endif 
