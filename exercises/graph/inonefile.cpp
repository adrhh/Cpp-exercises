#include <list>
#include <vector>
#include <iostream>

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
	void printGraph() const;
	void printGraphColors() const;
	void greedyColoring();
	void exactColoring();
	void resetColors();
};


void Graph::printGraph() const
{
	for (int i = 0; i < nrVerticles; i++)
	{
		std::cout << "Lista sasiedztwa wierzcholka nr: " << i << std::endl;
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
	test.printGraph();

	test.greedyColoring();
	test.printGraphColors();
	test.resetColors();
	test.printGraphColors();
	test.exactColoring();
	test.printGraphColors();

	getchar();

	return 0;
}
