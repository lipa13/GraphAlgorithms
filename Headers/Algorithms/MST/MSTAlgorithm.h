#ifndef AIZO_PROJEKT_2_MSTALGORITHM_H
#define AIZO_PROJEKT_2_MSTALGORITHM_H

#include "../Algorithm.h"

class MSTAlgorithm: public Algorithm
{
protected:
    int* vParents; // tablica przechowująca rodziców danych wierzchołków

public:
    MSTAlgorithm(Graph& g);
    virtual void init() = 0; // inicjalizacja tablic użytych w algorytmie
    virtual void runList() override = 0;
    virtual void runMatrix() override = 0;
    virtual void displayResult() override = 0;
};

#endif //AIZO_PROJEKT_2_MSTALGORITHM_H
