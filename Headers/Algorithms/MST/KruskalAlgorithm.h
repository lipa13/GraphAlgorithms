#ifndef AIZO_PROJEKT_2_KRUSKALALGORITHM_H
#define AIZO_PROJEKT_2_KRUSKALALGORITHM_H

#include "MSTAlgorithm.h"

class KruskalAlgorithm : public MSTAlgorithm
{
private:
    int* vParents;
    int* vRanks;
    Edge* edges;
    Edge* result;
    int edgesSize;
    int resultSize;
    int numV;
    void init();
    void makeSets();
    int findSet(int u);
    void unionSets(int u, int v);
    void sortEdges();
    void runKruskal();

public:
    KruskalAlgorithm(Graph& g);
    ~KruskalAlgorithm();
    void runList() override;
    void runMatrix() override;
    void displayResult() override;
};

#endif //AIZO_PROJEKT_2_KRUSKALALGORITHM_H
