/*
dyrektywa preprocesora (działa w pierwszym etapie kompilacji) 
#include  wkleja podane pliki nagłowkowe do kompilowanego pliku
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
	//tablica listy sasedztw utworzona za pomoca wskaznika
	std::list<int> *adjList;
//pola klasy publiczne, dostepe na zewnarz klasy	
public:
	//konstruktor domyslny, przyjmuje jako argument liczbe wierzcholkow tworzonego grafu
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
		//do tablicy saseidztwa wierzcholka u dodaj polaczenie z wierzcholkiem w
		//powtorz na odwrot
		adjList[u].push_back(w);
		adjList[w].push_back(u);
	}
	//sprawdza czy istnieje krawedz miedzy wierzcholkami
	//modyfikator const przy nawzie funkcji 
	//pokazuje, ze dana funkcja nie bedzie modyfikowac zawartosci obiektu tej klasy
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
	for (int i = 0; i < nrVerticles; i++)
	{
		std::cout << "Lista sasiedztwa wierzcholka nr (" << i << "): ";
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
		vertColor[i] = -1;
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


Graph* randGraphGerator(int ver, int edges)
{
	Graph* newGraph = new Graph(ver);
	srand(time(0));
	int actedges = 0;
	if (edges < ver - 1)
		std::cerr << "zbyt mala liczba wierzcholow, przyjeto: " << ver - 1 << std::endl;

	//najpierw generuj graf spojny 
	std::vector<int> simpleEdges;
	for (int i = 0; i < ver; i++)
		simpleEdges.push_back(i);

	while (true)
	{
		//parzysta
		if (!(ver % 2) && !simpleEdges.size())
			break;

		int i = simpleEdges[0];
		int j = i;
		int index;
		//nieparzysta ilosc wierzcholkow
		if (ver % 2 && simpleEdges.size() == 1)
		{
			while (j == i)
				j  = rand() % edges;
			newGraph->addEdge(i, j);
			std::cout << i << '\t' << j << '\n';
			actedges++;
			break;
		}
		while(j == i)
		{ 
			index = rand() % simpleEdges.size();
			j = simpleEdges[index];
		}
		newGraph->addEdge(i, j);
		actedges++;
		simpleEdges.erase(simpleEdges.begin() + index);
		simpleEdges.erase(simpleEdges.begin());
	}

	//dodaje pozsotale krawedzie

	int reaming = edges - actedges;
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

/*
//generuje losowy graf, parametrami sa ilosc wierzcholki i ilosc krawedzi
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
		//zacznij od peierwszego wierzcholka 
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
		//usun i j z poli wierzolkow, by stworzyc nastepne krawedzie dla pozstalych wierzcholkow
		simpleEdges.erase(simpleEdges.begin() + index);
		simpleEdges.erase(simpleEdges.begin());
	}

	//dodaje pozsotale krawedzie
	// ilosc pozstalych krawedzi do utworzenia
	//max krawedzi w grafie pelnym to n(n-1)/2
	//jest podana w wywolaniu ilosc krawedzi jest wieksza niz ilosc maksymalna
	//ustaw ilosc krawedzi n(n-1)/2
	//przy tworzeniu kolejnych krawedzi pomin te utworzone w poprzednim kroku
	
	//krawedzie do utworzenia = ilosc zadana w wywolaniu funkcji - krawedzie utworzone w kroku poprzendim
	//							       (te ktor tworza graf spojny)
	int reaming = edges - ver;
	if(edges > (ver*(ver-1))/2)
	{ 
		std::cerr << "zby doza ilosc wierzcholkow, przyjeto: " 
				  << (ver*(ver - 1)) / 2 << std::endl;
		reaming = (ver*(ver - 1)) / 2 - ver;
	}
	
	//petla od 0 do ilosci krwaedzi do utworzenia 
	for (int i = 0; i < reaming; i++)
	{
		while(true)
		{ 
			//losuj wierzcholek z ktorego wyjdzie krawedz
			int e = rand() % ver;
			int f = e;
			//losuj wierzcholek do ktorego dojdzie krawedz
			//powtarzaj krok dopuki bedzie inny od wychodzacego
			//by nie laczyc wierzcholka z zamym soba
			while(e == f)
				f = rand() % ver;
			//teraz sprawdz czy taka krawedz miedzy tymi wierzcholkami nie zostala utworzana wczesniej
			//jesli istnieje powtorz losowanie by wybrac nie istniejeaca krawedz
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
} */

int main()
{
	//gereuj graf randGraphGerator(i, j)
	//i - liczba wierzcholkow
	//j - liczba krawedzi
	Graph* test = randGraphGerator(10, 20);
	test->printGraph();

	clock_t start, end;
	//przed kolorwanie zacznij zliczanie (cykli) po zakonczeniu kolorowania 
	//zakoncz zliczanie
	start = clock();
	test->greedyColoring();
	end = clock();

	//wydrukuj kolory
	std::cout << "Kolorowanie:" << std::endl;
	test->printGraphColors();
	
	//czas kolorwoania to ilosc cykli zegara miedzy poczatkiem, a koncem kolorowania,
	//podzielona przez ilosc cykli na sekunde
	//static cast jest to rzutowanie na ty podstawowy zmiennoprzecinkowym double
	//poniewaz liczba cykli jest zmienna typu calkowitego potrzebne  jest rzutwoanie
	//by podac wynik w ulamkach sekund
	double greedyCloroingTime = (static_cast<double> (end - start)) / CLOCKS_PER_SEC;

	//powtorz kolorowanie i zliczanie dla pozstalych metod kolorowania
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
