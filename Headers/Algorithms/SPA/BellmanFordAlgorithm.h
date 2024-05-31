#ifndef AIZO_PROJEKT_2_BELLMANFORDALGORITHM_H
#define AIZO_PROJEKT_2_BELLMANFORDALGORITHM_H

#include "SPAlgorithm.h"

class BellmanFordAlgorithm: public SPAlgorithm
{
public:
    BellmanFordAlgorithm(Graph& g, int startV);
    void runList() override;
    void runMatrix() override;
};

#endif //AIZO_PROJEKT_2_BELLMANFORDALGORITHM_H
