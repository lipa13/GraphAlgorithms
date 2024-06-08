#ifndef AIZO_PROJEKT_2_ALGORITHM_H
#define AIZO_PROJEKT_2_ALGORITHM_H

#include "../Graph/Graph.h"

class Algorithm
{
protected:
    Graph& graph;
    int numV;
    int numE;

public:
    Algorithm(Graph& g);
    virtual void runList() = 0; // uruchom algorytm dla reprezentacji listowej
    virtual void runMatrix() = 0; // uruchom algorytm dla reprezentacji macierzowej
    virtual void displayResult() = 0; // wyświetl wyniki
};

#endif //AIZO_PROJEKT_2_ALGORITHM_H
