#include "../../../Headers/Algorithms/SPA/DijkstraAlgorithm.h"

#include <limits>

using namespace std;

DijkstraAlgorithm::DijkstraAlgorithm(Graph& g, int startV) : SPAlgorithm(g)
{
    init();
    s = startV;
}

void DijkstraAlgorithm::runList()
{
    start();
    PriorityQueue priorityQueue(numV);

    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, d[v]);
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

            if(priorityQueue.isInQueue(v) && d[u]!=numeric_limits<int>::max() && d[u]+w<d[v])
            {
                d[v] = d[u]+w;
                p[v] = u;
                priorityQueue.decreaseKey(v, d[v]);
            }
        }
    }
}

void DijkstraAlgorithm::runMatrix()
{
    start();
    PriorityQueue priorityQueue(numV);

    for(int v=0; v<numV; v++)
    {
        priorityQueue.insertKey(v, d[v]);
    }

    while(!priorityQueue.isEmpty())
    {
        HeapNode minNode = priorityQueue.extractMin();
        int u = minNode.v;

        for(int e=0; e<numE; e++)
        {
            if(graph.incidenceMatrix.data[u][e]==1)
            {
                int endV = -1;
                int w = graph.incidenceMatrix.edgeWeights[e];

                for(int i=0; i<graph.getNumV(); i++)
                {
                    if(i!=u && graph.incidenceMatrix.data[i][e]==-1)
                    {
                        endV = i;
                        break;
                    }
                }

                if(endV!=-1 && d[u]!=numeric_limits<int>::max() && d[u]+w<d[endV])
                {
                    d[endV] = d[u]+w;
                    p[endV] = u;
                    priorityQueue.decreaseKey(endV, d[endV]);
                }
            }
        }
    }
}
