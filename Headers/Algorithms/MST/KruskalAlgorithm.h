#ifndef AIZO_PROJEKT_2_KRUSKALALGORITHM_H
#define AIZO_PROJEKT_2_KRUSKALALGORITHM_H

#include "MSTAlgorithm.h"

class KruskalAlgorithm : public MSTAlgorithm
{
private:
    int* vRanks; // tablica rang danych wierzchołków
    Edge* edges; // tablica wszystkich krawędzi grafu
    Edge* result; // tablica wynikowa z krawędziami należacymi do mst
    int edgesSize; // zmienna przechowująca liczbę krawędzi (rozmiar tablicy edges)
    int resultSize; // zmienna przechowująca rozmiar tablicy wynikowej
    void init() override;
    void makeSets(); // inicjalizacja zbiorów jednowierzchołkowych
    int findSet(int u); // znajdowanie korzenia zbioru wierzchołka u
    void unionSets(int u, int v); // łączenie zbiorów, do których należą dwa wierzchołki
    void sortEdges(); // sortowanie krawędzi według wagi
    void runKruskal(); // właściwa implementacja algorytmu Kruskala

public:
    KruskalAlgorithm(Graph& g);
    ~KruskalAlgorithm();
    void runList() override;
    void runMatrix() override;
    void displayResult() override;
};

#endif //AIZO_PROJEKT_2_KRUSKALALGORITHM_H
