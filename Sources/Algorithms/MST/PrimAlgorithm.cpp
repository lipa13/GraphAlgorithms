#include "../../../Headers/Algorithms/MST/PrimAlgorithm.h"

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void PrimAlgorithm::init()
{
    vParents = new int[numV];
    key = new int[numV];
    r = rand()%numV;
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
    for(int i=0; i<numV; i++)
    {
        vParents[i] = -1;
        key[i] = numeric_limits<int>::max();
    }
    key[r] = 0;
}

void PrimAlgorithm::runList()
{
    start();
    PriorityQueue priorityQueue(numV);

    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, key[v]);
    }

    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin();
        int u = minNode.v;

        Edge* uNeighbors = graph.adjacencyList.getNeighbors(u);
        for(int i=0; i<graph.adjacencyList.numberOfNeighbors[u]; i++)
        {
            int v = uNeighbors[i].endV;
            int w = uNeighbors[i].weight;

            if(priorityQueue.isInQueue(v) && w<key[v])
            {
                key[v] = w;
                vParents[v] = u;
                priorityQueue.decreaseKey(v, w);
            }
        }
    }
}

void PrimAlgorithm::runMatrix()
{
    start();
    PriorityQueue priorityQueue(numV);

    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, key[v]);
    }

    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin();
        int u = minNode.v;

        for(int e=0; e<graph.getNumE(); e++)
        {
            if(graph.incidenceMatrix.data[u][e]==1)
            {
                int endV=-1;
                int w = graph.incidenceMatrix.edgeWeights[e];

                for(int i=0; i<numV; i++)
                {
                    if(i!=u && graph.incidenceMatrix.data[i][e]==1)
                    {
                        endV = i;
                        break;
                    }
                }

                if(endV!=-1 && priorityQueue.isInQueue(endV) && w<key[endV])
                {
                    key[endV] = w;
                    vParents[endV] = u;
                    priorityQueue.decreaseKey(endV, w);
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
