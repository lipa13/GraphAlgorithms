#ifndef AIZO_PROJEKT_2_ALGORITHM_H
#define AIZO_PROJEKT_2_ALGORITHM_H

#include "../Graph/Graph.h"

class Algorithm
{
protected:
    Graph& graph;

public:
    Algorithm(Graph& g);
    virtual void runList() = 0;
    virtual void runMatrix() = 0;
    virtual void displayResult() = 0;
};

#endif //AIZO_PROJEKT_2_ALGORITHM_H
