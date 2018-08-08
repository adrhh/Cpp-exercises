#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class Graph
{
private:
	const int nrVerticles;
	std::vector<int> vertColor;
	std::list<int> *adjList;
	
public:
	Graph(int size = 0) : nrVerticles(size)
	{
		adjList = new std::list<int>[size];
		vertColor.resize(size);
	}
	~Graph() { delete[] adjList; }

	void addEdge(int u, int w)
	{
		adjList[u].push_back(w);
		adjList[w].push_back(u);
	}
	bool haveEdge(int i, int j) const;
	void printGraph() const;
	void printGraphColors() const;
	void greedyColoring();
	void exactColoring();
	void resetColors();
};

Graph* randGraphGerator(int ver, int edges);


void Graph::printGraph() const
{
	for (int i = 0; i < nrVerticles; i++)
	{
		std::cout << "Lista sasiedztwa wierzcholka nr (" << i << "): " << i;
		for (auto j : adjList[i])
			std::cout << ' ' << j;
		std::cout << std::endl;
	}
}

void Graph::printGraphColors() const
{
	for (int i = 0; i < nrVerticles; i++)
		std::cout << "Wirzcholek nr: " << i << " ma kolor"
				  << vertColor[i] << std::endl;
}

void Graph::greedyColoring()
{
	std::vector<bool> available(nrVerticles, false);
	vertColor[0] = 0;

	for (int i = 1; i < nrVerticles; i++)
		vertColor[i] = -1;

	for (int u = 1; u < nrVerticles; u++)
	{

		std::list<int>::iterator i;
		for (i = adjList[u].begin(); i != adjList[u].end(); ++i)
			if (vertColor[*i] != -1)
				available[vertColor[*i]] = true;

		int cr;
		for (cr = 0; cr < nrVerticles; cr++)
			if (available[cr] == false)
				break;

		vertColor[u] = cr;

		for (i = adjList[u].begin(); i != adjList[u].end(); ++i)
			if (vertColor[*i] != -1)
				available[vertColor[*i]] = false;
	}
}

void Graph::resetColors()
{
	for (int i = 0; i < vertColor.size(); i++)
		vertColor[i] = 0;
}

void Graph::exactColoring()
{
	int counter = 0;
	int b = 0;
	int bc = 0;
	bool test;
	while (true)
	{
		if (bc)
		{
			test = true;
			counter++;
			for (int u = 0; u < nrVerticles; u++)
			{
				std::list<int>::iterator i;
				for (i = adjList[u].begin(); i != adjList[u].end(); i++)
					if (vertColor[u] == vertColor[*i])
					{
						test = false;
						break;
					}
				if (!test)
					break;
			}
			if (test)
				break;
		}

		while (true)
		{
			int i;
			for (i = 0; i < nrVerticles; i++)
			{
				vertColor[i]++;
				if (vertColor[i] == b - 1)
					bc++;
				if (vertColor[i] < b)
					break;
				vertColor[i] = 0;
				bc--;
			}
			if (i < nrVerticles)
				break;
			b++;
		}
	}
}

Graph* randGraphGerator(int ver, int edges)
{
	Graph* newGraph = new Graph(ver);
	srand(time(0));

	if (edges < ver - 1)
		std::cerr << "zbyt mala liczba wierzcholow, przyjeto: " << ver - 1 << std::endl;

	//najpierw generuj graf spojny 
	std::vector<int> simpleEdges;
	for (int i = 0; i < ver; i++)
		simpleEdges.push_back(i);

	while (true)
	{
		//nieparzysta ilosc wierzcholkow
		if (ver % 2 && simpleEdges.size() == 1)
			break;
		//parzysta
		if (!(ver % 2) && !simpleEdges.size())
			break;


		int i = simpleEdges[0];
		int j = i;
		int index;
		while(j == i)
		{ 
			index = rand() % simpleEdges.size();
			j = simpleEdges[index];
		}

		newGraph->addEdge(i, j);
		simpleEdges.erase(simpleEdges.begin() + index);
		simpleEdges.erase(simpleEdges.begin());
	}

	//dodaje pozsotale krawedzie

	int reaming = edges - ver;
	if(edges > (ver*(ver-1))/2)
	{ 
		std::cerr << "zby doza ilosc wierzcholkow, przyjeto: " 
				  << (ver*(ver - 1)) / 2 << std::endl;
		reaming = (ver*(ver - 1)) / 2 - ver;
	}
	for (int i = 0; i < reaming; i++)
	{
		while(true)
		{ 
			int e = rand() % ver;
			int f = e;
			while(e == f)
				f = rand() % ver;
			if (newGraph->haveEdge(e, f))
				continue;
			else
			{
				newGraph->addEdge(e, f);
				break;
			}
		}
	}

	return newGraph;
}

bool Graph::haveEdge(int i, int j) const
{
	bool isEdge = false;
	for (auto e : adjList[i])
		if (e == j)
		{
			isEdge = true;
			break;
		}
	return isEdge;
}
	
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
