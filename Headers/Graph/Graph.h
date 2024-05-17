#ifndef AIZO_PROJEKT_2_GRAPH_H
#define AIZO_PROJEKT_2_GRAPH_H

#include <string>

#include "../Edge.h"

using namespace std;

class Graph
{
protected:
    int numV; // ilość wierzchołków
    int numE; // ilość krawędzi

public:
    Graph();
    virtual void addEdge(int start, int end, int weight) = 0;
    virtual int* getNeighbors(int V) = 0;
    virtual void display() = 0;
    virtual void loadFromFile(string& path) = 0;
    virtual void generateRandom(int vertices, int d) = 0;
    int getNumV();
    int getNumE();
    virtual bool isDirected() const = 0;
};

#endif //AIZO_PROJEKT_2_GRAPH_H
