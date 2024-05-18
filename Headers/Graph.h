#ifndef AIZO_PROJEKT_2_GRAPH_H
#define AIZO_PROJEKT_2_GRAPH_H

#include <string>
#include <iostream>

using namespace std;

class Graph
{
    int numV; // ilość wierzchołków
    int numE; // ilość krawędzi
    bool directed;

    struct Edge
    {
        int startV;
        int endV;
        int weight;

        Edge(): startV(0), endV(0), weight(0){}
        Edge(int start, int end, int w): startV(start), endV(end), weight(w){}
    };

    struct ListGraph
    {
        Edge** adjacencyList; // dynamiczna tablica dwuwymiarowa reprezentująca listę sąsiedztwa
        int* numberOfNeighbors;
        int& numV;
        bool& directed;

        ListGraph(int& vertices, bool& isDirected) : numV(vertices), directed(isDirected)
        {
            adjacencyList = nullptr;
            numberOfNeighbors = nullptr;
        }

        ~ListGraph()
        {
            if(adjacencyList!=nullptr)
            {
                for(int i=0; i<numV; i++)
                {
                    delete[] adjacencyList[i];
                }
                delete[] adjacencyList;
                delete[] numberOfNeighbors;
            }
        }

        void listAddEdge(int start, int end, int weight)
        {
            adjacencyList[start][numberOfNeighbors[start]++] = Edge(start, end, weight);

            if(!directed)
            {
                adjacencyList[end][numberOfNeighbors[end]++] = Edge(end, start, weight);
            }
        }

        Edge* listGetNeighbors(int V)
        {
            return adjacencyList[V];
        }

        void listDisplay()
        {
            cout << endl;

            for(int i=0; i<numV; i++)
            {
                cout << i << ": ";
                for(int j=0; j<numberOfNeighbors[i]; j++)
                {
                    cout << adjacencyList[i][j].endV << "(" << adjacencyList[i][j].weight << "), ";
                }
                cout << endl;
            }
        }
    };

    struct MatrixGraph
    {

    };

public:
    ListGraph listGraph;

    Graph(bool isDirected);
    bool isEdgeCorrect(int s, int e);
    void loadFromFile(string& path);
    void generateRandom(int vertices, double d);
    int getNumV();
    int getNumE();
};

#endif //AIZO_PROJEKT_2_GRAPH_H
