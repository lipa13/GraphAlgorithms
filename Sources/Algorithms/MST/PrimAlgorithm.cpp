#include "../../../Headers/Algorithms/MST/PrimAlgorithm.h"

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void PrimAlgorithm::init()
{
    vParents = new int[numV];
    key = new int[numV];
    r = rand()%numV; // wylosowanie wierzchołka startowego
}

PrimAlgorithm::PrimAlgorithm(Graph& g) : MSTAlgorithm(g)
{
    init();
}

PrimAlgorithm::~PrimAlgorithm()
{
    delete[] vParents;
    delete[] key;
}

void PrimAlgorithm::start()
{
    // ustawienie domyślnych wartości w tablicach z wyjątkiem wierzchołka startowego dla którego key wynosi 0
    for(int i=0; i<numV; i++)
    {
        vParents[i] = -1;
        key[i] = numeric_limits<int>::max();
    }
    key[r] = 0;
}

void PrimAlgorithm::runList()
{
    start(); // ustawienie początkowych wartości
    PriorityQueue priorityQueue(numV); // inicjalizacja kolejki priorytetowej

    // wstawienie wszystkich wierzchołków do kolejki priorytetowej
    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, key[v]);
    }

    // pętla wykonujaca się dopóki kolejka nie będzie pusta
    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin(); // pobranie minimum z kolejki
        int u = minNode.v; // zapisanie w zmiennej wierzchołka z minimum

        Edge* uNeighbors = graph.adjacencyList.getNeighbors(u); // pobranie sąsiadów u
        for(int i=0; i<graph.adjacencyList.numberOfNeighbors[u]; i++) // pętla przechodząca przez wszystkich sasiadów u
        {
            int v = uNeighbors[i].endV; // zapisanie do zmiennej wierzchołka sąsiadującego
            int w = uNeighbors[i].weight; // zapisanine wagi krawędzi

            if(priorityQueue.isInQueue(v) && w<key[v]) // jeśli w<key[v] i v jest w kolejce
            {
                // to zmieniamy wartości klucza i rodzica dla v i aktualizujemy jego pozycję w kolejce
                key[v] = w;
                vParents[v] = u;
                priorityQueue.decreaseKey(v, w);
            }
        }
    }
}

void PrimAlgorithm::runMatrix()
{
    start(); // ustawienie początkowych wartości
    PriorityQueue priorityQueue(numV); // inicjalizacja kolejki priorytetowej

    // wstawienie wszystkich wierzchołków do kolejki priorytetowej
    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, key[v]);
    }

    // pętla wykonujaca się dopóki kolejka nie będzie pusta
    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin(); // pobranie minimum z kolejki
        int u = minNode.v; // zapisanie w zmiennej wierzchołka z minimum

        for(int e=0; e<graph.getNumE(); e++) // pętla przechodząca po wszystkich krawędziach z macierzy incydencji
        {
            if(graph.incidenceMatrix.data[u][e]==1) // jeśli wartość dla wierzchołka u jest równa 1 (czyli istnieje dana krawędź dla u)
            {
                int v=-1; // inicjalizujemy wartość końca krawędzi
                int w = graph.incidenceMatrix.edgeWeights[e]; // pobieramy wagę krawędzi

                for(int i=0; i<numV; i++) // szukamy końca krawędzi
                {
                    if(i!=u && graph.incidenceMatrix.data[i][e]==1) // jak go znaleźliśmy to aktualizujemy zmienną i kończymy pętlę
                    {
                        v = i;
                        break;
                    }
                }

                if(priorityQueue.isInQueue(v) && w<key[v]) // jeśli zmieniliśmy wartośc końca i v jest w kolejce
                {
                    // to zmieniamy wartości klucza i rodzica dla v i aktualizujemy jego pozycję w kolejce
                    key[v] = w;
                    vParents[v] = u;
                    priorityQueue.decreaseKey(v, w);
                }
            }
        }
    }
}

void PrimAlgorithm::displayResult()
{
    int mst=0;
    cout << "Edge     Weight\n";
    for(int i=0; i<graph.getNumV(); i++)
    {
        if(vParents[i]!=-1)
        {
            cout << left << setw(7) << to_string(vParents[i]) + " - " + to_string(i) << "   " << right << setw(3) << key[i] << endl;
            mst += key[i];
        }
    }
    cout << "MST = " << mst << endl;
}
