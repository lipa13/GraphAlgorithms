#include <chrono>
#include <random>
#include <algorithm>
#include "../../Headers/Graph/Graph.h"

using namespace std;

Graph::Graph(bool isDirected)
    :directed(isDirected), numV(0), numE(0), adjacencyList(numV, directed), incidenceMatrix(numV, numE, directed) {}

bool Graph::isEdgeCorrect(int s, int e)
{
    if(s==e)
    {
        return false;
    }

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
    adjacencyList.addEdge(start, end, w);
    incidenceMatrix.addEdge(start, end, w);
}

bool Graph::loadFromFile(string& path)
{
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
        return false; // jeśli nie to zwraca false
    }

    file >> numE >> numV;

    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    int start, end, weight;

    while(file >> start >> end >> weight)
    {
        addEdge(start, end, weight);
    }

    file.close();
    return true; // zwraca true, jeśli wczytanie danych się powiodło
}

void Graph::generateRandom(int vertices, double d)
{
    if(adjacencyList.data!=nullptr)
    {
        adjacencyList.clearList();
    }

    if(incidenceMatrix.data!=nullptr)
    {
        incidenceMatrix.clearMatrix();
    }

    numV = vertices;
    numE = static_cast<int>(d/100*vertices*(vertices-1)/(directed?1:2));

    // Obliczenie minimalnej liczby krawedzi do utworzenia grafu spojnego skierowanego: V i nieskierowanwgo: V-1
    int minEdges = directed?vertices:vertices-1;

    // Sprawdzenie, czy liczba krawedzi jest wystarczajaca do spojności
    if(numE<minEdges)
    {
        cout << "\nDla podanej gestosci i liczby wierzcholkow nie mozna utworzyc spojnego grafu.\n";
        cout << "Graf nie zostal utworzony. Sprobuj ponownie dla innych wartosci parametrow.\n";
        return;
    }

    adjacencyList.initList();
    incidenceMatrix.initMatrix();

    if(directed)
    {
        // Generowanie grafu spójnego dla grafu skierowanego
        int* randomOrder = new int[numV];
        for(int i=0; i<numV; i++)
        {
            randomOrder[i] = i;
        }

        shuffle(randomOrder, randomOrder+numV, default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

        for(int i=0; i<numV; i++)
        {
            int start = randomOrder[i];
            int end = randomOrder[(i+1)%numV];
            int w = rand()%15+1;

            addEdge(start, end, w);
        }

        delete[] randomOrder;
    }
    else
    {
        // Generowanie grafu spójnego dla grafu nieskierowanego
        for (int i=1; i<numV; i++)
        {
            bool correct;
            int start, end, w;

            do
            {
                start = i;
                end = rand()%i;
                w = rand()%15+1;

                correct = isEdgeCorrect(start, end);

            }while(!correct);

            addEdge(start, end, w);
        }
    }

    // Dokładanie krawędzi do określonej gęstości
    for(int i=directed?numV:numV-1; i<numE; i++)
    {
        bool correct;
        int start, end, w;

        do
        {
            start = rand()%numV;
            end = rand()%numV;
            w = rand()%15+1;

            correct = isEdgeCorrect(start, end);

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
