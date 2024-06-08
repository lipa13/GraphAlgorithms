#ifndef AIZO_PROJEKT_2_PRIMALGORITHM_H
#define AIZO_PROJEKT_2_PRIMALGORITHM_H

#include "MSTAlgorithm.h"
#include "../PriorityQueue.h"

class PrimAlgorithm : public MSTAlgorithm
{
private:
    int* key; // tablica przechowująca klucze danych wierzchołków
    int r; // wierzchołek startowy
    void init() override;
    void start(); // metoda rozpoczynająca algorytm (ustawienia wartosci początkowych)

public:
    PrimAlgorithm(Graph& g);
    ~PrimAlgorithm();
    void runList() override;
    void runMatrix() override;
    void displayResult() override;
};


#endif //AIZO_PROJEKT_2_PRIMALGORITHM_H
