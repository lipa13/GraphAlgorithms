#ifndef AIZO_PROJEKT_2_GRAPH_H
#define AIZO_PROJEKT_2_GRAPH_H

#include <string>

using namespace std;

class Graph
{
protected:
    int V; // ilość wierzchołków
    int E; // ilość krawędzi

public:
    Graph();
    virtual void addEdge(int start, int end, int weight) = 0;
    virtual int* getNeighbors(int vertex) = 0;
    virtual void display() = 0;
    virtual void loadFromFile(string& filename) = 0;
    virtual void generateRandom(int vertices, int d) = 0;
    int getV();
    int getE();
    virtual bool isDirected() const = 0;
};

#endif //AIZO_PROJEKT_2_GRAPH_H
