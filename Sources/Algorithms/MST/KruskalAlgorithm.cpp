#include "../../../Headers/Algorithms/MST/KruskalAlgorithm.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

KruskalAlgorithm::KruskalAlgorithm(Graph& g): MSTAlgorithm(g), vParents(nullptr), vRanks(nullptr), edges(nullptr), result(nullptr)
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
    numV = graph.getNumV();
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
        vParents[i] = i;
        vRanks[i] = 0;
    }
}

int KruskalAlgorithm::findSet(int u)
{
    if(u!=vParents[u])
    {
        vParents[u] = findSet(vParents[u]);
    }
    return vParents[u];
}

void KruskalAlgorithm::unionSets(int u, int v)
{
    int rootU = findSet(u);
    int rootV = findSet(v);

    if(rootU!=rootV)
    {
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
    // Posortowanie wszystkich krawędzi według wagi
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
    // Algorytm Kruskala
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
    makeSets();

    // Pobranie wszystkich krawędzi z listy sąsiedztwa
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

    sortEdges();
    runKruskal();
}

void KruskalAlgorithm::runMatrix()
{
    makeSets();

    // Pobranie wszystkich krawędzi z macierzy incydencji
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
        if(u!=-1 && v!=-1)
        {
            edges[edgesSize++] = Edge(u, v, graph.incidenceMatrix.edgeWeights[e]);
        }
    }

    sortEdges();
    runKruskal();
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
