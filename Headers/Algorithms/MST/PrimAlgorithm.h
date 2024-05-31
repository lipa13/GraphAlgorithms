#ifndef AIZO_PROJEKT_2_PRIMALGORITHM_H
#define AIZO_PROJEKT_2_PRIMALGORITHM_H

#include "MSTAlgorithm.h"
#include "../PriorityQueue.h"

class PrimAlgorithm : public MSTAlgorithm
{
private:
    int* key;
    int r; // wierzchołek startowy
    void init() override;
    void start();

public:
    PrimAlgorithm(Graph& g);
    ~PrimAlgorithm();
    void runList() override;
    void runMatrix() override;
    void displayResult() override;
};


#endif //AIZO_PROJEKT_2_PRIMALGORITHM_H
