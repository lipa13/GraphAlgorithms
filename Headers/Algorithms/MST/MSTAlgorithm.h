#ifndef AIZO_PROJEKT_2_MSTALGORITHM_H
#define AIZO_PROJEKT_2_MSTALGORITHM_H

#include "../Algorithm.h"

class MSTAlgorithm: public Algorithm
{
public:
    MSTAlgorithm(Graph& g);
    virtual void runList() override = 0;
    virtual void runMatrix() override = 0;
    virtual void displayResult() override = 0;
};

#endif //AIZO_PROJEKT_2_MSTALGORITHM_H
