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

	//funkcja dodajaca krawedz miedzy wierzcholkami 'u' i 'w'
	void addEdge(int u, int w)
	{
	//do tablicy saseidztwa wierzcholka u dodaj polaczenie z wierzcholkiem 'w'
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
	//dla kazdego elementu listy sasiedztwa wydrukuj elemnt
	//powtorz dla list wszytkich wierzcholkow
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
	//drukuj kazdy elemnt tablicy kolorow
	for (int i = 0; i < nrVerticles; i++)
		std::cout << "Wirzcholek nr: " << i << " ma kolor"
		<< vertColor[i] << std::endl;
}

//kolorowanie zachlanne
//zlozonosc w najgorszym przypadku wynosi:
//O(v^2 + e) = O(liczba wierzcholow^2 + liczba krawedzi)
//Najpierw pokoloruj pierwszy wierzcholek pierwszym kolorem
//Dla pozstolaych wierzcholkow:
// uzyj pierwszego dostepnego koloru
// jesli wszytkie uzyte dotychczas kolory sa zajete przez sadiadow
// uzyj kolejengo koloru


void Graph::greedyColoring()
{
   	//tablica dostepnosci kolorow
	std::vector<bool> available(nrVerticles, false);
	//pierwszy wierzcholek ustawiony na kolor 0
	vertColor[0] = 0;
	//pozstale kolory wierzcholkow na -1
	for (int i = 1; i < nrVerticles; i++)
		vertColor[i] = -1;

	//od 1 do liczby wierzcholkow (po kazdym wierzcholku)
	for (int u = 1; u < nrVerticles; u++)
	{
		//iterator 'i' do przechodzenia po liscie sasiedztwa
		std::list<int>::iterator i;
		//dla tego wierzcholka ustaw tablice dostepnosci kolorow
		//jesli sasiad ma kolor -1 znaczy nie byl uzyty
		//zmien wtedy flage dostepnosci kloru na true
		for (i = adjList[u].begin(); i != adjList[u].end(); ++i)
			if (vertColor[*i] != -1)
				available[vertColor[*i]] = true;

		int cr; //dostepny kolor
		//znajdz w tablicy dostepdnosci pierwszy dostepny kolor
		for (cr = 0; cr < nrVerticles; cr++)
			if (available[cr] == false)
				break;
		//ustaw kolor aktualnego wierzcholka na znelsizony
		//w kroku wszczeniej
		vertColor[u] = cr;

		//zresetuj tablcy dostepnosci dla koljnego wierzcholka
		// (dla koljengo kroku glownej petli)
		for (i = adjList[u].begin(); i != adjList[u].end(); ++i)
			if (vertColor[*i] != -1)
				available[vertColor[*i]] = false;
	}
}

//resetuj kolory, ustaw wszytkie na -1
void Graph::resetColors()
{
	for (int i = 0; i < vertColor.size(); i++)
		vertColor[i] = -1;
}

//kolorowanie dokladne bardzo wysoka zlozonosc
//alogrytm dokladny sprawdza wszytkie mozliwe pokolorwania i wybiera 
//te z najmniejsza ilosc kolorow
//najpierw koloruj wszystkimi mozliwymi kombinacjami 2 kolorw
//jesli sasiednie wierzcholki maja ten sam kolor przerwij petle
//i przej do kolejnej kombinacji
//jesli nie da sie pokolrowac 2 kolorami zwieksz liczbe kolorow
//powtarzaj do spelniania warunkow braku tego samu koloru dla sasiednich wierzcholkow

void Graph::exactColoring()
{
	//licznik
	int counter = 0;
	//baza 'b'=2 minimum kolorow to 2
	int b = 0;
	//licznik najstarszych cyfr
	int bc = 0;
	//flaga pomocnicza
	bool test;
	while (true)
	{
		//gdy istnieje nasjtarsza cyfra
		if (bc)
		{
			//jesi test jest prawdizwy
			//ustaw flage na true
			test = true;
			//zwieksz licznik
			counter++;
			//petla po wszytkich wierzcholkach
			for (int u = 0; u < nrVerticles; u++)
			{
				//iterator listy sasiedztwa
				std::list<int>::iterator i;
				//dla wszytkich pozycji z listy sasiedztwa wierzcholka u
				//sprawdz sasiadow wierzcholka u
				for (i = adjList[u].begin(); i != adjList[u].end(); i++)
				//czy sadienie wierzcholki maja ten sam kolor
				// jesli tak - wyjdz z petli
			        // i ustaw flage test by wyjsc z wyzszej petli for 
					if (vertColor[u] == vertColor[*i])
					{
						test = false;
						break;
					}
				//wyjdz
				if (!test)
					break;
			}
			//jesli flaga ustawiona, kombinacja znaleziona
			if (test)
				break;
		}

		//zwiekszanie licznika
		while (true)
		{
			//zmienna pomocnicza do przechodzenia petli
			int i;
			//po wszytkich wierzcholkach
			for (i = 0; i < nrVerticles; i++)
			{
				//zwieksz kolor wierzcholka i o 1
				vertColor[i]++;
				//jesli kolor = baza -1, to zwieksz o 1
				//licznik najstarszy cyfr
				//jesli mniejszy od bazy to wyjdz z petli for
				if (vertColor[i] == b - 1)
					bc++;
				if (vertColor[i] < b)
					break;
				//zeruj kolor i zmniejsz licznik nastarszych cyfr
				vertColor[i] = 0;
				bc--;
			}
			//wyjdz z petli
			if (i < nrVerticles)
				break;
			//zwieksz baze
			b++;
		}
	}
}


//kolorwanie heurystyczne (LF large first)
//za wiki:
//Kolorowanie grafu za pomocą algorytmu LF można opisać następująco:
//
//    Uporządkuj wierzchołki grafu malejąco według ich stopni 
//    (liczby krawędzi z nich wychodzących).
//    Koloruj wierzchołki zachłannie, zgodnie z ustaloną wcześniej kolejnością 
//    (zaczynając od wierzchołka o największym stopniu).
//
//Algorytm LF jest algorytmem statycznym, gdyż raz ustalona kolejność 
//wierzchołków nie zmienia się w trakcie jego działania

void Graph::heurColoring()
{
	//pomocnicza tablica wierzcholkow potrzebna 
	//do posrtowania wierzcholkow wg ich stopnia
	std::vector<int> vertArr(nrVerticles);        
	//tablica stopni wierzcholkow				      
	std::vector<int> vertGradeArr(nrVerticles);
	//tablica dostepnosci kolorow
	std::vector<bool> colors(nrVerticles, false); 
	//zmienie pomocnicze
	int d, i; 
	//po wszytkich wierzcholkach
	for (int v = 0; v < nrVerticles; v++) 
	{
		//wypenij pomocnicza tablice wierzchookow
		vertArr[v] = v;   
		//zeruj tablice stopnie wierzcholkow
		vertGradeArr[v] = 0;  

		//oblicz stopien wierzcholka 'v'
		//dla wierzcholka 'v' przegldanij liste sasiedztwa
		//za kazdego sasiada zwieksz stopien tego wierzcholka
		for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) /
			vertGradeArr[v]++;                   

		//sortowanie wg stopni
		d = vertGradeArr[v];
		
		for (i = v; (i > 0) && (vertGradeArr[i - 1] < d); i--)
		{
			vertArr[i] = vertArr[i - 1];
			vertGradeArr[i] = vertGradeArr[i - 1];
		}

		vertGradeArr[i] = d;
		vertArr[i] = v;
	}
	//reset kolorow
	resetColors();
	//wierzcholek startu
	vertColor[vertArr[0]] = 0;
	//koloruj zachlannie zaczynajac od wierzcholka o nawyjzszym stopniu konczac
	//na najmniejszym stopniu
	for (int v = 1; v < nrVerticles; v++)
	{

		for (auto p = adjList[vertArr[v]].begin(); p != adjList[vertArr[v]].end(); p++)
			if (vertColor[*p] > -1)
				colors[vertColor[*p]] = true;

		for (i = 0; colors[i]; i++);
		vertColor[vertArr[v]] = i;
	}
}


//generuje losowy graf, parametrami sa ilosc wierzcholki i ilosc krawedzi
Graph* randGraphGerator(int ver, int edges)
{
	//dynamicznie tworzy graf o zadanej ilosci wierzcholkow
	Graph* newGraph = new Graph(ver);
	srand(time(0));

	//jezeli krawedzi jest zbyt malo, przyjmuje najmniejsza ilosc wierzcholkow by graf byl spojny
	//by graf mogl byc kolorwany musi istniec droga przez wszytkie wierzcholki

	//max krawedzi w grafie pelnym to n(n-1)/2
	//jest podana w wywolaniu ilosc krawedzi jest wieksza niz ilosc maksymalna
	//ustaw ilosc krawedzi n(n-1)/2
	//przy tworzeniu kolejnych krawedzi pomin te utworzone w poprzednim kroku

	int actedges = 0;
	int edgesNrMax = edges;
	if (edges < ver - 1)
	{
		std::cerr << "zbyt mala liczba krawedzi, przyjeto: " << ver - 1 << std::endl;
		edgesNrMax = ver - 1;
	}
	if (edges >(ver*(ver - 1)) / 2)
	{
		edgesNrMax = (ver*(ver - 1)) / 2 ;
		std::cerr << "zby doza ilosc krawedzi, przyjeto: "
			<< edgesNrMax << std::endl;
		
	}

	//najpierw generuj graf spojny 
	std::vector<int> simpleEdges;
	for (int i = 0; i < ver; i++)
		simpleEdges.push_back(i);

	//najpierw generuj graf spojny 
	//tablica wierzcholkow ktora posluzy do genrowania grafu spojnego
	//w grafie spojnym istniej co najmniej jedna krawedz do innego wierzcholka
	//z tej tablcy beda losowane wierzcholki, a po u zyciue usuwane
	//by wszytkie wierzcholki mogly miec krawedz

	while (true)
	{
		//warunek konca dla: parzysta liczba wierzcholkow
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

		//warunek konca dla: nieparzysta ilosc wierzcholkow
		if (ver % 2 && simpleEdges.size() == 1)
		{
			while (j == i)
				j = rand() % edges;
			newGraph->addEdge(i, j);
			std::cout << i << '\t' << j << '\n';
			actedges++;
			break;
		}
		while (j == i)
		{
			index = rand() % simpleEdges.size();
			j = simpleEdges[index];
		}
		newGraph->addEdge(i, j);
		actedges++;
		simpleEdges.erase(simpleEdges.begin() + index);
		simpleEdges.erase(simpleEdges.begin());
	}
	
	//krawedzie do utworzenia = ilosc zadana w wywolaniu funkcji - krawedzie utworzone w kroku poprzendim

	int reaming = edgesNrMax - actedges;

	//petla od 0 do ilosci krwaedzi do utworzenia 
	for (int i = 0; i < reaming; i++)
	{
		while (true)
		{
			//losuj wierzcholek z ktorego wyjdzie krawedz
			int e = rand() % ver;
			int f = e;
			//losuj wierzcholek do ktorego dojdzie krawedz
			//powtarzaj krok dopuki bedzie inny od wychodzacego
			//by nie laczyc wierzcholka z zamym soba
			while (e == f)
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
}


//sprawdza czy istnieje krawedz miedzy wierzcholkami 'i','j'
bool Graph::haveEdge(int i, int j) const
{
	bool isEdge = false;
	//dla listy sasiedztwa wierzcholka 'i' sprawdz czy jest na niej wierzcholek 'j'
	//jeslli jest zwroc prawde, jesli nie zwroc falsz
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
	Graph* test = randGraphGerator(4, 8);
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
