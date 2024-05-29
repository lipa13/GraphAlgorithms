#include "../../../Headers/Algorithms/MST/PrimAlgorithm.h"

#include <iostream>
#include <limits>

using namespace std;

struct MinHeapNode
{
    int v;
    int key;
};

class MinHeap
{
    MinHeapNode* heap;
    int* pos;
    int size;

public:
    MinHeap(int capacity)
    {
        heap = new MinHeapNode[capacity];
        pos = new int[capacity];
        size = 0;
    }

    ~MinHeap()
    {
        delete[] heap;
        delete[] pos;
    }

    void insertKey(int v, int key)
    {
        size++;
        int i = size - 1;
        heap[i].v = v;
        heap[i].key = key;
        pos[v] = i;

        while (i && heap[i].key < heap[(i - 1) / 2].key)
        {
            pos[heap[i].v] = (i - 1) / 2;
            pos[heap[(i - 1) / 2].v] = i;
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void decreaseKey(int v, int key)
    {
        int i = pos[v];
        heap[i].key = key;

        while (i && heap[i].key < heap[(i - 1) / 2].key)
        {
            pos[heap[i].v] = (i - 1) / 2;
            pos[heap[(i - 1) / 2].v] = i;
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    MinHeapNode extractMin()
    {
        if (size == 0)
            return { -1, std::numeric_limits<int>::max() };

        MinHeapNode root = heap[0];

        MinHeapNode lastNode = heap[size - 1];
        heap[0] = lastNode;
        pos[lastNode.v] = 0;
        size--;

        minHeapify(0);

        return root;
    }

    void minHeapify(int idx)
    {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heap[left].key < heap[smallest].key)
            smallest = left;

        if (right < size && heap[right].key < heap[smallest].key)
            smallest = right;

        if (smallest != idx)
        {
            pos[heap[smallest].v] = idx;
            pos[heap[idx].v] = smallest;
            std::swap(heap[smallest], heap[idx]);
            minHeapify(smallest);
        }
    }

    bool isInMinHeap(int v)
    {
        return pos[v] < size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

PrimAlgorithm::PrimAlgorithm(Graph& g)
        : MSTAlgorithm(g)
{
    int V = g.getNumV();
    parent = new int[V];
    key = new int[V];
    inMST = new bool[V];

    for (int i = 0; i < V; ++i)
    {
        parent[i] = -1;
        key[i] = std::numeric_limits<int>::max();
        inMST[i] = false;
    }
}

PrimAlgorithm::~PrimAlgorithm()
{
    delete[] parent;
    delete[] key;
    delete[] inMST;
}

void PrimAlgorithm::runList()
{
    int V = graph.getNumV();
    key[0] = 0;
    parent[0] = -1;

    MinHeap minHeap(V);

    for (int v = 0; v < V; ++v)
    {
        minHeap.insertKey(v, key[v]);
    }

    while (!minHeap.isEmpty())
    {
        MinHeapNode minNode = minHeap.extractMin();
        int u = minNode.v;

        inMST[u] = true;

        Edge* neighbors = graph.adjacencyList.getNeighbors(u);
        for (int i = 0; i < graph.adjacencyList.numberOfNeighbors[u]; ++i)
        {
            int v = neighbors[i].endV;
            int weight = neighbors[i].weight;

            if (minHeap.isInMinHeap(v) && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                minHeap.decreaseKey(v, weight);
            }
        }
    }
}

void PrimAlgorithm::runMatrix()
{
    int V = graph.getNumV();
    key[0] = 0;
    parent[0] = -1;

    MinHeap minHeap(V);

    for (int v = 0; v < V; ++v)
    {
        minHeap.insertKey(v, key[v]);
    }

    while (!minHeap.isEmpty())
    {
        MinHeapNode minNode = minHeap.extractMin();
        int u = minNode.v;

        inMST[u] = true;

        for (int e = 0; e < graph.getNumE(); ++ e)
        {
            int startV = -1;
            int endV = -1;
            int weight = 0;

            for (int i = 0; i < V; ++i)
            {
                if (graph.incidenceMatrix.data[i][e] == 1)
                {
                    startV = i;
                    weight = graph.incidenceMatrix.edgeWeigths[e];
                }
                else if (graph.incidenceMatrix.data[i][e] == -1)
                {
                    endV = i;
                }
            }

            if (startV != -1 && endV != -1 && !inMST[endV] && weight < key[endV])
            {
                key[endV] = weight;
                parent[endV] = startV;
                minHeap.decreaseKey(endV, weight);
            }
        }
    }
}

void PrimAlgorithm::displayResult()
{
    std::cout << "Edge   Weight\n";
    for (int i = 1; i < graph.getNumV(); ++i)
        std::cout << parent[i] << " - " << i << "    " << key[i] << std::endl;
}
