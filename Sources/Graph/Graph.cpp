#include <chrono>
#include <random>
#include <algorithm>
#include "../../Headers/Graph/Graph.h"

using namespace std;

Graph::Graph(bool isDirected)
    :directed(isDirected), numV(0), numE(0), adjacencyList(numV, directed), incidenceMatrix(numV, numE, directed) {}

bool Graph::isEdgeCorrect(int s, int e)
{
    // sprawdzenie czy początek krawędzi jest równy końcowi
    if(s==e)
    {
        return false;
    }

    // sprawdzenie czy dana krawędź nie istnieje już w naszym grafie
    for(int i=0; i<adjacencyList.numberOfNeighbors[s]; i++)
    {
        if(adjacencyList.data[s][i].endV==e)
        {
            return false;
        }
    }

    return true;
}

void Graph::addEdge(int start, int end, int w)
{
    // dodawanie krawędzi do obu reprezentacji
    adjacencyList.addEdge(start, end, w);
    incidenceMatrix.addEdge(start, end, w);
}

bool Graph::loadFromFile(string& path)
{
    // sprawdzenie, czy dane już istnieją i czyszczenie listy sąsiedztwa oraz macierzy incydencji
    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    if(incidenceMatrix.data!= nullptr)
    {
        incidenceMatrix.clearMatrix();
    }

    ifstream file(path);

    // sprawdzenie, czy plik jest otwarty
    if(!file.is_open())
    {
        return false; // jeśli nie to zwrócenie false
    }

    // odczytanie z pliku ilości krawędzi i wierzchołków
    file >> numE >> numV;

    // inicjalizacja obu reprezentacji grafu
    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    int start, end, weight;

    // wczytanie krawędzi
    while(file >> start >> end >> weight)
    {
        addEdge(start, end, weight);
    }

    file.close();
    return true; // zwrócenie true, jeśli wczytanie danych się powiodło
}

void Graph::generateRandom(int vertices, double d)
{
    // sprawdzenie, czy dane już istnieją i czyszczenie listy sąsiedztwa oraz macierzy incydencji
    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    if(incidenceMatrix.data!=nullptr)
    {
        incidenceMatrix.clearMatrix();
    }

    // zapisanie ilości wierzchołków i obliczenie ilości krawędzi zgodnie z podaną gęstością
    numV = vertices;
    numE = static_cast<int>(d/100*vertices*(vertices-1)/(directed?1:2));

    // obliczenie minimalnej liczby krawedzi do utworzenia grafu spojnego skierowanego: V i nieskierowanwgo: V-1
    int minEdges = directed?vertices:vertices-1;

    // sprawdzenie, czy liczba krawedzi jest wystarczajaca do spojności
    if(numE<minEdges)
    {
        cout << "\nDla podanej gestosci i liczby wierzcholkow nie mozna utworzyc spojnego grafu.\n";
        cout << "Graf nie zostal utworzony. Sprobuj ponownie dla innych wartosci parametrow.\n";
        return;
    }

    // inicjalizacja obu reprezentacji grafu
    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    if(directed) // generowanie grafu spójnego z minimalną, konieczną ilością krawędzi dla grafu skierowanego
    {
        int* randomOrder = new int[numV]; // inicjalizacja tablicy dla wszystkich wierzchołków
        for(int i=0; i<numV; i++) // wypełnienie tablicy numerami wierzchołków
        {
            randomOrder[i] = i;
        }

        // przemieszanie tablicy z numerami wierzchołków, żeby cykl był w losowej kolejności
        shuffle(randomOrder, randomOrder+numV, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

        // dodanie krawędzi do grafu we wcześniej wylosowanej kolejności
        for(int i=0; i<numV; i++)
        {
            int start = randomOrder[i];
            int end = randomOrder[(i+1)%numV];
            int w = rand()%15+1;

            addEdge(start, end, w);
        }

        delete[] randomOrder;
    }
    else // generowanie grafu spójnego z minimalną, konieczną ilością krawędzi dla grafu nieskierowanego
    {
        for (int i=1; i<numV; i++)
        {
            bool correct;
            int start, end, w;

            // losowanie kolejnych krawędzi, tak żeby koniec krawędzi był jednym z wierzchołków dołączonych już do grafu
            do
            {
                start = i;
                end = rand()%i;
                w = rand()%15+1;

                correct = isEdgeCorrect(start, end); // sprawdzenie czy wylosowana krawedź już nie istnieje

            }while(!correct);

            addEdge(start, end, w);
        }
    }

    // dołożenie krawędzi do określonej gęstości
    for(int i=directed?numV:numV-1; i<numE; i++) // jeśli graf jest skierowany to od V krawędzi a nieskierowany V-1 krawędzi
    {
        bool correct;
        int start, end, w;

        do
        {
            start = rand()%numV;
            end = rand()%numV;
            w = rand()%15+1;

            correct = isEdgeCorrect(start, end); // sprawdzenie czy wylosowana krawedź już nie istnieje

        }while(!correct);

        addEdge(start, end, w);
    }

    //cout << "\nGraf zostal pomyslnie utworzony." << endl;
}

int Graph::getNumV()
{
    return numV;
}

int Graph::getNumE()
{
    return numE;
}
