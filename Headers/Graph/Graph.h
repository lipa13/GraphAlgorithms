#ifndef AIZO_PROJEKT_2_GRAPH_H
#define AIZO_PROJEKT_2_GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include "AdjacencyList.h"
#include "Edge.h"
#include "IncidenceMatrix.h"

using namespace std;

class Graph
{
    int numV; // ilość wierzchołków
    int numE; // ilość krawędzi
    bool directed;

public:
    AdjacencyList adjacencyList;
    IncidenceMatrix incidenceMatrix;

    Graph(bool isDirected);
    bool isEdgeCorrect(int s, int e);
    void addEdge(int start, int end, int w);
    bool loadFromFile(string& path);
    void generateRandom(int vertices, double d);
    int getNumV();
    int getNumE();
};

#endif //AIZO_PROJEKT_2_GRAPH_H
