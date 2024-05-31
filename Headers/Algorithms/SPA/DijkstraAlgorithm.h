#ifndef AIZO_PROJEKT_2_DIJKSTRAALGORITHM_H
#define AIZO_PROJEKT_2_DIJKSTRAALGORITHM_H

#include "SPAlgorithm.h"
#include "../PriorityQueue.h"

class DijkstraAlgorithm: public SPAlgorithm
{
public:
    DijkstraAlgorithm(Graph& g, int startV, int target);
    void runList() override;
    void runMatrix() override;
};

#endif //AIZO_PROJEKT_2_DIJKSTRAALGORITHM_H
