#ifndef GRAF_F_
#define GRAF_F_

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


#endif
