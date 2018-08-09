/*
dyrektywa preprocesora (działa w pierwszym etapie kompilacji) #include  
wkleja podane pliki nagłowkowe do kompilowanego pliku

pliki nagłowkowe zawierają deklaracje klas i funkcji
*/

#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

//prosta klasa implementujaca graf
class Graph
{
//pola klasy prywatne, dostepne tylko wewnatrz klasy
private:
	//stala okreslajaca ilosc wierzcholkow
	const int nrVerticles;
	//tablica kolorow weirzcholkow, za pomoca konterna vector z biblioteki stl 
	std::vector<int> vertColor;
	//tablica listy sasedztw, za pomoca wskaźnika tworzona i usuwana dynamicznie
	std::list<int> *adjList;
	
public:
	//konstruktor domyslny, przyjmuje jago argument liczbe wierzcholkow tworzonego grafu
	Graph(int size = 0) : nrVerticles(size)
	{
		//dynamicznie tworzy tablice list sasiedztwa
		adjList = new std::list<int>[size];
		vertColor.resize(size);
	}
	//destruktor, usuwa dynamicznie utworzna liste sasiedztwa
	~Graph() { delete[] adjList; }

	//funkcja dodajaca krawedz miedzy wierzcholkami u i w
	void addEdge(int u, int w)
	{
		//do tablicy saseidztwa wierzcholka u dodaj w i na odwrot
		adjList[u].push_back(w);
		adjList[w].push_back(u);
	}
	//sprawdza czy istnieje krawedz miedzy wierzcholkami
	bool haveEdge(int i, int j) const;
	//drukuje liste sasiedztwa wierzcholkow
	void printGraph() const;
	//drukuje liste kolorow
	void printGraphColors() const;
	void greedyColoring();
	void exactColoring();
	void heurColoring();
	void resetColors();
};


void Graph::printGraph() const
{
	//dla kazdego elemntu listy sasiedztwa wydrukuj elemnt
	//powtorz dla list wszytkich wierzcholkow
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
	//drukuj kazdy elemnt tablicy kolorow
	for (int i = 0; i < nrVerticles; i++)
		std::cout << "Wirzcholek nr: " << i << " ma kolor"
				  << vertColor[i] << std::endl;
}

//kolrowanie zachlanne
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


//resetyj kolory, ustaw wszytkie na -1
void Graph::resetColors()
{
	for (int i = 0; i < vertColor.size(); i++)
		vertColor[i] = -1;
}

//kolorowanie dokladne
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


//kolorwanie heurystyczne (LF large first)
void Graph::heurColoring()
{
	std::vector<int> vertArr(nrVerticles);
	std::vector<int> vertGradeArr(nrVerticles);
	std::vector<bool> colors(nrVerticles,false);
	int d, i;
	for (int v = 0; v  < nrVerticles; v++) 
	{
		vertArr[v] = v;                   
		vertGradeArr[v] = 0;                 

		for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) // Przeglądamy kolejnych sąsiadów
			vertGradeArr[v]++;                    // Obliczamy stopień wyjściowy wierzchołka v

		d = vertGradeArr[v];

		for (i = v; (i > 0) && (vertGradeArr[i - 1] < d); i--)
		{
			vertArr[i] = vertArr[i - 1];
			vertGradeArr[i] = vertGradeArr[i - 1];
		}

		vertGradeArr[i] = d;
		vertArr[i] = v;
	}

	resetColors();

	vertColor[vertArr[0]] = 0;  

	for (int v = 1; v < nrVerticles; v++) 
	{

		for (auto p = adjList[vertArr[v]].begin(); p != adjList[vertArr[v]].end(); p++)
			if (vertColor[*p] > -1) 
				colors[vertColor[*p]] = true; 

		for (i = 0; colors[i]; i++);      
			vertColor[vertArr[v]] = i;     
	}
}

//generuje losowy graf parametrami sa ilosc wierzcholki i ilosc krawedzi
Graph* randGraphGerator(int ver, int edges)
{
	//dynamicznie tworzy graf o zadanej ilosci wierzcholkow
	Graph* newGraph = new Graph(ver);
	srand(time(0));

	//jezeli krawedzi jest zbyt malo, przyjmuje najmniejsza ilosc wierzcholkow by graf byl spojny
	//by graf mogl byc kolorwany musi istniec droga przez wszytkie wierzcholki
	if (edges < ver - 1)
		std::cerr << "zbyt mala liczba wierzcholow, przyjeto: " << ver - 1 << std::endl;

	//najpierw generuj graf spojny 
	
	//tablica wierzcholkow ktora posluzy do genrowania grafu spojnego
	//w grafie spojnym istniej co najmniej jedna krawedz do innego wierzcholka
	//z tej tablcy beda losowane wierzcholki, a po u zyciue usuwane
	//by wszytkie wierzcholki mogly miec krawedz
	
	std::vector<int> simpleEdges;
	for (int i = 0; i < ver; i++)
		simpleEdges.push_back(i);

	while (true)
	{
		//nieparzysta ilosc wierzcholkow
		//jezeli zostal jeden wierzcholek koncz
		if (ver % 2 && simpleEdges.size() == 1)
			break;
		//parzysta ilosc, jesli brak wierzcholkow koncz
		if (!(ver % 2) && !simpleEdges.size())
			break;

		//zmienne pomicnicze
		//zmienne i,j posluza do genrowania krawedzi miedzy wierzcholakmi i,j
		//zacznij od piwerszego wierzcholka 
		int i = simpleEdges[0];
		int j = i;
		int index;
		//losuj wierzcholek j doputy bedzie rozny od i
		//czyli omijaj krawedz miedzy soba samym
		while(j == i)
		{ 
			index = rand() % simpleEdges.size();
			j = simpleEdges[index];
		}
		//gdy i, j sa rozne tworz miedzy nimi krawedz
		newGraph->addEdge(i, j);
		//usun i j z poli wierzolkow, 
		simpleEdges.erase(simpleEdges.begin() + index);
		simpleEdges.erase(simpleEdges.begin());
	}

	//dodaje pozsotale krawedzie
	// ilosc pozstalych krawedzi do utworzenia
	//max krawedzi w grafie pelnym to n(n-1)/2
	//jest podana w wyloaniu ilosc krawedzi jest wieksza niz ilosc maksymalna
	//ustaw ilosc krawedzi n(n-1)/2
	//przy tworzeniu kolejnych krawedzi pomin te utworzone w koljenym kroku
	int reaming = edges - ver;
	if(edges > (ver*(ver-1))/2)
	{ 
		std::cerr << "zby doza ilosc wierzcholkow, przyjeto: " 
				  << (ver*(ver - 1)) / 2 << std::endl;
		reaming = (ver*(ver - 1)) / 2 - ver;
	}
	
	//od 0 do ilosci krwaedzi do utworzenia
	for (int i = 0; i < reaming; i++)
	{
		while(true)
		{ 
			//losuj wierzcholek z ktorego wyjdzie krawedz
			int e = rand() % ver;
			int f = e;
			//losuj wierzcholek do ktorego dojdzie krawedz
			//powtarzaj krok dopuki bedzie inny od wychodzacego
			//by nie laczyc wierzcholka s zamym soba
			while(e == f)
				f = rand() % ver;
			//teraz sprawdz czy taka krawedz miedzy tymi wierzcholkami nie istnieje
			//jesli istnieje powtorz losowanie
			if (newGraph->haveEdge(e, f))
				continue;
			//jesli ta krawedz nie istnieje, oraz laczy dwa rozne wiercholki
			//utworz ja
			else
			{
				newGraph->addEdge(e, f);
				break;
			}
		}
	}
	//zwraca wskaznik do utworzonego grafu
	//jest to zmienna dynamiczna
	//trzeba bedzie pamietac o jej usunieciu
	return newGraph;
}


//sprawdza czy istnieje krawedz miedzy wierzcholkami i,j
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
	Graph* test = randGraphGerator(10, 20);
	test->printGraph();

	clock_t start, end;

	start = clock();
	test->greedyColoring();
	end = clock();

	std::cout << "Kolorowanie:" << std::endl;
	test->printGraphColors();

	double greedyCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;


	test->resetColors();
	start = clock();
	test->exactColoring();
	end = clock();

	std::cout << "Kolorowanie:" << std::endl;
	test->printGraphColors();

	double exactCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;

	test->resetColors();
	start = clock();
	test->heurColoring();
	end = clock();
	double heurCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;

	std::cout << "Kolorowanie:" << std::endl;
	test->printGraphColors();

	std::cout << "Czas dzialania algorytmu zachlannego: " << greedyCloroingTime << std::endl
		<< "Czas dzialania algorytmu dokladnego: " << exactCloroingTime << std::endl
		<< "Czas dzialania algorytmu hwurystycznegi: " << heurCloroingTime << std::endl;

	delete test;
	return 0;
}

