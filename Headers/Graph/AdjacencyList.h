#ifndef AIZO_PROJEKT_2_ADJACENCYLIST_H
#define AIZO_PROJEKT_2_ADJACENCYLIST_H

#include "Edge.h"

class AdjacencyList
{
public:
    Edge** data; // dynamiczna tablica dwuwymiarowa reprezentująca listę sąsiedztwa
    int* numberOfNeighbors;
    int& numV;
    bool& directed;

    AdjacencyList(int& vertices, bool& isDirected);
    ~AdjacencyList();

    void addEdge(int start, int end, int weight);
    Edge* getNeighbors(int V);
    void display();
};

#endif //AIZO_PROJEKT_2_ADJACENCYLIST_H
