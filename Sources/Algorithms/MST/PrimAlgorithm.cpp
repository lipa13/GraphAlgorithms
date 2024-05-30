#include "../../../Headers/Algorithms/MST/PrimAlgorithm.h"

#include <iostream>
#include <limits>

using namespace std;

void PrimAlgorithm::init()
{
    numV = graph.getNumV();
    vParents = new int[numV];
    key = new int[numV];
    r = rand()%numV;
}

PrimAlgorithm::PrimAlgorithm(Graph& g) : MSTAlgorithm(g), vParents(nullptr), key(nullptr)
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
                int endV=-1, w=0;
                w = graph.incidenceMatrix.edgeWeights[e];

                for(int i=0; i<numV; i++)
                {
                    if(i!=u && graph.incidenceMatrix.data[i][e]==1)
                    {
                        endV = i;
                        break;
                    }
                }

                if(endV != -1 && priorityQueue.isInQueue(endV) && w<key[endV])
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
    cout << "Edge   Weight\n";
    for(int i=0; i<graph.getNumV(); i++)
    {
        if(i!=r)
        {
            cout << vParents[i] << " - " << i << "    " << key[i] << endl;
        }
    }
}
