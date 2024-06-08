#include "../../../Headers/Algorithms/MST/KruskalAlgorithm.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

KruskalAlgorithm::KruskalAlgorithm(Graph& g): MSTAlgorithm(g)
{
    init();
}

KruskalAlgorithm::~KruskalAlgorithm()
{
    delete[] vParents;
    delete[] vRanks;
    delete[] edges;
    delete[] result;
}

void KruskalAlgorithm::init()
{
    // alokacja pamięci dla tablic
    vParents = new int[numV];
    vRanks = new int[numV];
    edges = new Edge[graph.getNumE()];
    result = new Edge[numV-1];
}

void KruskalAlgorithm::makeSets()
{
    edgesSize = 0;
    resultSize = 0;

    for(int i=0; i<numV; i++)
    {
        vParents[i] = i; // każdy wierzchołek jest swoim własnym rodzicem
        vRanks[i] = 0; // początkowa ranga każdego wierzchołka to 0
    }
}

int KruskalAlgorithm::findSet(int u)
{
    // znajdowanie korzenia zbioru wierzchołka u z kompresją ścieżki
    if(u!=vParents[u])
    {
        vParents[u] = findSet(vParents[u]); // rekurencyjne odnalezienie korzenia
    }
    return vParents[u];
}

void KruskalAlgorithm::unionSets(int u, int v)
{
    // łączenie zbiorów wierzchołków u i v
    int rootU = findSet(u);
    int rootV = findSet(v);

    if(rootU!=rootV)
    {
        // łączenie według rang, aby zbalansować drzewo
        if(vRanks[rootU]>vRanks[rootV])
        {
            vParents[rootV] = rootU;
        }
        else if(vRanks[rootU]<vRanks[rootV])
        {
            vParents[rootU] = rootV;
        }
        else
        {
            vParents[rootV] = rootU;
            vRanks[rootU]++;
        }
    }
}

void KruskalAlgorithm::sortEdges()
{
    // posortowanie wszystkich krawędzi według wagi
    for(int i=0; i<edgesSize-1; i++)
    {
        for(int j=0; j<edgesSize-i-1; j++)
        {
            if(edges[j].weight>edges[j+1].weight)
            {
                swap(edges[j], edges[j+1]);
            }
        }
    }
}

void KruskalAlgorithm::runKruskal()
{
    // właściwe dzialanie algorytmu Kruskala
    for(int i=0; i<edgesSize; i++)
    {
        int u = edges[i].startV;
        int v = edges[i].endV;
        if(findSet(u)!=findSet(v))
        {
            result[resultSize++] = edges[i];
            unionSets(u, v);
        }
    }
}

void KruskalAlgorithm::runList()
{
    makeSets(); // inicjalizacja zbiorów jednowierzchołkowych

    // pobranie wszystkich krawędzi z listy sąsiedztwa
    for(int u=0; u<graph.getNumV(); u++)
    {
        Edge* neighbors = graph.adjacencyList.getNeighbors(u);
        for(int i=0; i<graph.adjacencyList.numberOfNeighbors[u]; i++)
        {
            if(u<neighbors[i].endV)
            {
                edges[edgesSize++] = neighbors[i];
            }
        }
    }

    sortEdges(); // posortowanie krawędzi
    runKruskal(); // uruchomienie algorytmu kruskala
}

void KruskalAlgorithm::runMatrix()
{
    makeSets(); // inicjalizacja zbiorów jednowierzchołkowych

    // pobranie wszystkich krawędzi z macierzy incydencji
    for(int e=0; e<graph.getNumE(); e++)
    {
        int u=-1, v=-1;
        for(int i=0; i<graph.getNumV(); i++)
        {
            if(graph.incidenceMatrix.data[i][e]==1)
            {
                if(u==-1)
                {
                    u=i;
                }
                else
                {
                    v=i;
                    break;
                }
            }
        }

        edges[edgesSize++] = Edge(u, v, graph.incidenceMatrix.edgeWeights[e]);
    }

    sortEdges(); // posortowanie krawędzi
    runKruskal(); // uruchomienie algorytmu kruskala
}

void KruskalAlgorithm::displayResult()
{
    int mst=0;
    cout << "Edge     Weight\n";
    for(int i = 0; i < resultSize; i++)
    {
        cout << left << setw(7) << to_string(result[i].startV) + " - " + to_string(result[i].endV) << "   " << right << setw(3) << result[i].weight << endl;
        mst += result[i].weight;
    }
    cout << "MST = " << mst << endl;
}
