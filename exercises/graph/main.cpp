#include "graf.h"
;
	
int main()
{
	Graph test(5);
	test.addEdge(0, 1);
	test.addEdge(0, 2);
	test.addEdge(0, 3);
	test.addEdge(0, 4);
	test.addEdge(1, 2);
	test.addEdge(1, 4);
	test.addEdge(3, 4);
	test.printGrpah();

	getchar();

	return 0;
}
