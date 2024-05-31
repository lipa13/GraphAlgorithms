#ifndef AIZO_PROJEKT_2_SPALGORITHM_H
#define AIZO_PROJEKT_2_SPALGORITHM_H

#include "../Algorithm.h"

class SPAlgorithm: public Algorithm
{
protected:
    int* d;
    int* p;
    int s;
    void init();
    void start();
    void reconstructPath(int target, int*& path, int& pathLength);

public:
    SPAlgorithm(Graph& g);
    virtual ~SPAlgorithm();
    virtual void runList() override = 0;
    virtual void runMatrix() override = 0;
    virtual void displayResult() override;
};

#endif //AIZO_PROJEKT_2_SPALGORITHM_H
