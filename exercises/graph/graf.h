#ifndef GRAF_F_
#define GRAF_F_

#include <list>
#include <iostream>

class Graph
{
private:
	int nrVerticles;
	std::list<int> *adjList;
public:
	Graph(int size = 0) : nrVerticles(size)
	{
		adjList = new std::list<int>[size];
	}
	~Graph() { delete[] adjList; }

	void addEdge(int u, int w)
	{
		adjList[u].push_back(w);
		adjList[w].push_back(u);
	}
	void printGrpah() const
	{
		for (int i = 0; i < nrVerticles; i++)
		{
			std::cout << "Lista sasiedztwa wierzcholka nr: " << i << std::endl;
			for (auto j : adjList[i])
				std::cout << ' ' << j;
			std::cout << std::endl;
		}
	}
}

#endif
