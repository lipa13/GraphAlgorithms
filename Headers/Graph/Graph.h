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
    bool directed; // flaga określająca, czy graf jest skierowany

public:
    AdjacencyList adjacencyList; // lista sąsiedztwa grafu
    IncidenceMatrix incidenceMatrix; // macierz incydencji grafu

    Graph(bool isDirected);
    bool isEdgeCorrect(int s, int e); // metoda sprawdzająca poprawność wylosowanej krawędzi
    void addEdge(int start, int end, int w); // metoda dodająca krawędzie do grafu
    bool loadFromFile(string& path); // wczytywanie danych z pliku
    void generateRandom(int vertices, double d); // generowanie losowego grafu
    int getNumV(); // metoda zwracająca ilość wierzchołków
    int getNumE(); // metoda zwracająca ilość krawędzi
};

#endif //AIZO_PROJEKT_2_GRAPH_H
