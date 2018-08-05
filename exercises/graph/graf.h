#ifndef GRAF_F_
#define GRAF_F_

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
}

#endif
