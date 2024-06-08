#include "../../../Headers/Algorithms/SPA/DijkstraAlgorithm.h"

#include <limits>

using namespace std;

DijkstraAlgorithm::DijkstraAlgorithm(Graph& g, int startV, int target): SPAlgorithm(g, startV, target)
{
    init();
}

void DijkstraAlgorithm::runList()
{
    start(); // ustawienie wartości początkowych w tablicach
    PriorityQueue priorityQueue(numV); // inicjalizacja kolejki priorytetowej

    // wypełenienie kolejki wszystkimi wierzchołkami
    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, d[v]);
    }

    // pętla wykonująca się dopóki kolejka nie będzie pusta
    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin(); // wyjęcie minimum z kolejki
        int u = minNode.v;

        Edge* uNeighbors = graph.adjacencyList.getNeighbors(u); // pobranie z listy sąsiadów u
        for(int i=0; i<graph.adjacencyList.numberOfNeighbors[u]; i++) // pętla przechodząca po każdym sąsiedzie u
        {
            int v = uNeighbors[i].endV;
            int w = uNeighbors[i].weight;

            if(priorityQueue.isInQueue(v) && d[u]+w<d[v]) // jeśli v jest w kolejce i nowa ścieżka jest mniejsza od poprzedniej
            {
                d[v] = d[u]+w; // to aktualizujemy ścieżkę dla v
                p[v] = u; // zmieniamy rodzica
                priorityQueue.decreaseKey(v, d[v]); // i zmieniamy wartość klucza w kolejce
            }
        }
    }
}

void DijkstraAlgorithm::runMatrix()
{
    start(); // ustawienie wartości początkowych w tablicach
    PriorityQueue priorityQueue(numV); // inicjalizacja kolejki priorytetowej

    // wypełenienie kolejki wszystkimi wierzchołkami
    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, d[v]);
    }

    // pętla wykonująca się dopóki kolejka nie będzie pusta
    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin(); // wyjęcie minimum z kolejki
        int u = minNode.v;

        for(int e=0; e<numE; e++) // pętla pobierająca sąsiadów dla u z macierzy i wykonujaca algorytm
        {
            if(graph.incidenceMatrix.data[u][e]==1) // jeśli istnieje krawędź dla u
            {
                int v = -1;
                int w = graph.incidenceMatrix.edgeWeights[e];

                for(int i=0; i<graph.getNumV(); i++) // szukamy końca krawędzi
                {
                    if(graph.incidenceMatrix.data[i][e]==-1)
                    {
                        v = i;
                        break;
                    }
                }

                if(priorityQueue.isInQueue(v) && d[u]+w<d[v]) // jeśli v jest w kolejce i nowa ścieżka jest mniejsza od poprzedniej
                {
                    d[v] = d[u]+w; // to aktualizujemy ścieżkę dla v
                    p[v] = u; // zmieniamy rodzica
                    priorityQueue.decreaseKey(v, d[v]); // i zmieniamy wartość klucza w kolejce
                }
            }
        }
    }
}
