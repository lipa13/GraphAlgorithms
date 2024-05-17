#ifndef AIZO_PROJEKT_2_GRAPH_H
#define AIZO_PROJEKT_2_GRAPH_H

#include <string>

using namespace std;

class Graph
{
protected:
    int numV; // ilość wierzchołków
    int numE; // ilość krawędzi

public:
    struct Edge
    {
        int startV;
        int endV;
        int weight;

        Edge(): startV(0), endV(0), weight(0){}
        Edge(int start, int end, int w): startV(start), endV(end), weight(w){}
    };

    Graph();
    virtual void addEdge(int start, int end, int weight) = 0;
    virtual Edge* getNeighbors(int V) = 0;
    virtual void display() = 0;
    virtual void loadFromFile(string& path) = 0;
    virtual void generateRandom(int vertices, int d) = 0;
    int getNumV();
    int getNumE();
    virtual bool isDirected() const = 0;
};

#endif //AIZO_PROJEKT_2_GRAPH_H
