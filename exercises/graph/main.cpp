#include "graf.h"
	
int main()
{
	//gereuj graf randGraphGerator(i, j)
	//i - liczba wierzcholkow
	//j - liczba krawedzi
	Graph* test = randGraphGerator(17, 24);
	test->printGraph();

	clock_t start, end;

	start = clock();
	test->greedyColoring();
	end = clock();

	test->printGraphColors();

	double greedyCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;


	test->resetColors();
	start = clock();
	test->exactColoring();
	end = clock();

	test->printGraphColors();

	double exactCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;

	std::cout << "Czas dzialania algorytmu zachlannego: " << greedyCloroingTime << std::endl
		      << "Czas dzialania algorytmu dokladnego: " << exactCloroingTime << std::endl;

	delete test;
	return 0;
}
