#include "../../../Headers/Algorithms/SPA/BellmanFordAlgorithm.h"

#include <iostream>
#include <limits>

using namespace std;

BellmanFordAlgorithm::BellmanFordAlgorithm(Graph& g, int startV, int target): SPAlgorithm(g, startV, target)
{
    init();
}

void BellmanFordAlgorithm::runList()
{
    start(); // ustawienie wartości początkowych w tablicach

    // relaksacja krawędzi V-1 razy
    for(int i=0; i<numV-1; i++)
    {
        for(int u=0; u<numV; u++)
        {
            Edge* uNeighbors = graph.adjacencyList.getNeighbors(u); // pobranie sąsiadów z listy
            for(int j=0; j<graph.adjacencyList.numberOfNeighbors[u]; j++)
            {
                int v = uNeighbors[j].endV;
                int w = uNeighbors[j].weight;

                if(d[u]+w<d[v]) // jeśli v jest w kolejce i nowa ścieżka jest mniejsza od poprzedniej
                {
                    d[v] = d[u]+w; // to aktualizujemy ścieżkę dla v
                    p[v] = u; // i zmieniamy rodzica
                }
            }
        }
    }
}

void BellmanFordAlgorithm::runMatrix()
{
    start(); // ustawienie wartości początkowych w tablicach

    // relaksacja krawędzi V-1 razy
    for(int i=0; i<numV-1; i++)
    {
        for(int e=0; e<numE; e++) // pętla pobierająca krawędzie z macierzy i wykonująca relaksację
        {
            int u=-1, v=-1, w=graph.incidenceMatrix.edgeWeights[e];

            for(int j=0; j<numV; j++)
            {
                if(graph.incidenceMatrix.data[j][e]==1)
                {
                    u = j;
                    if(u!=-1 && v!=-1)
                    {
                        break;
                    }
                }
                else if(graph.incidenceMatrix.data[j][e]==-1)
                {
                    v = j;
                    if(u!=-1 && v!=-1)
                    {
                        break;
                    }
                }
            }

            if(d[u]+w<d[v])
            {
                d[v] = d[u]+w;
                p[v] = u;
            }
        }
    }
}
