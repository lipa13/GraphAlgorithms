#ifndef AIZO_PROJEKT_2_PRIMALGORITHM_H
#define AIZO_PROJEKT_2_PRIMALGORITHM_H

#include "MSTAlgorithm.h"

class PrimAlgorithm : public MSTAlgorithm
{
private:
    int* parent;
    int* key;
    bool* inMST;

public:
    PrimAlgorithm(Graph& g);
    ~PrimAlgorithm();
    void runList() override;
    void runMatrix() override;
    void displayResult() override;
};

#endif //AIZO_PROJEKT_2_PRIMALGORITHM_H
