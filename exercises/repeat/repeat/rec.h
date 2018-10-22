#ifndef REC_H_
#define REC_H_

class Test
{
private:
	static unsigned int counter;
	static unsigned int copies;
	static unsigned int assigments;
	int x;
	int y;
public:
	Test(int a, int b = 0) : x(a), y(b) { counter++; }
	Test(const Test& t);
	Test& operator=(const Test& t);
	Test by_val(Test t);
	static void show_counters();
};

void test();

#endif // !REC_H_
