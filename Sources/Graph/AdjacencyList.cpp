#include <iostream>
#include "../../Headers/Graph/AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(int& vertices, bool& isDirected) : numV(vertices), directed(isDirected)
{
    data = nullptr;
    numberOfNeighbors = nullptr;
}

void AdjacencyList::initList()
{
    // inicjalizacja tablic
    data = new Edge*[numV];
    numberOfNeighbors = new int[numV]();

    for(int i=0; i<numV; i++)
    {
        data[i] = new Edge[numV-1];
    }
}

void AdjacencyList::clearList()
{
    // czyszczenie pamięci zajmowanej przez tablice
    for(int i=0; i<numV; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    delete[] numberOfNeighbors;
}

AdjacencyList::~AdjacencyList()
{
    if(data!=nullptr)
    {
        clearList();
    }
}

void AdjacencyList::addEdge(int start, int end, int weight)
{
    data[start][numberOfNeighbors[start]++] = Edge(start, end, weight); // dodanie krawędzi do listy

    if(!directed) // dodanie krawędzi w obie strony dla grafu nieskierowanego
    {
        data[end][numberOfNeighbors[end]++] = Edge(end, start, weight);
    }
}

Edge* AdjacencyList::getNeighbors(int V)
{
    return data[V]; // pobieranie sąsiadów danego wierzchołka
}

void AdjacencyList:: display()
{
    cout << endl;
    cout << "Reperezentacja listowa\n";

    for(int i=0; i<numV; i++)
    {
        cout << i << ": ";
        for(int j=0; j<numberOfNeighbors[i]; j++)
        {
            cout << data[i][j].endV << "(" << data[i][j].weight << "), ";
        }
        cout << endl;
    }
}