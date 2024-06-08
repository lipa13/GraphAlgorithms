#ifndef AIZO_PROJEKT_2_ADJACENCYLIST_H
#define AIZO_PROJEKT_2_ADJACENCYLIST_H

#include "Edge.h"

class AdjacencyList
{
public:
    Edge** data; // dynamiczna tablica dwuwymiarowa reprezentująca listę sąsiedztwa
    int* numberOfNeighbors; // tablica pomocnicza przechowująca liczbę sąsiadów dla każdego wierzchołka
    int& numV; // liczba wierzchołków grafu
    bool& directed; // flaga określająca, czy graf jest skierowany

    AdjacencyList(int& vertices, bool& isDirected);
    void initList(); // inicjalizacja listy sąsiedztwa
    void clearList(); // czyszczenie listy sąsiedztwa
    ~AdjacencyList();
    void addEdge(int start, int end, int weight); // dodanie krawędzi do listy sąsiedztwa
    Edge* getNeighbors(int V); // pobranie sąsiadów danego wierzchołka
    void display(); // wyświetlenie listy sąsiedztwa
};

#endif //AIZO_PROJEKT_2_ADJACENCYLIST_H
