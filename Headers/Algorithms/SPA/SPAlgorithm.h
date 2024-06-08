#ifndef AIZO_PROJEKT_2_SPALGORITHM_H
#define AIZO_PROJEKT_2_SPALGORITHM_H

#include "../Algorithm.h"

class SPAlgorithm: public Algorithm
{
protected:
    int* d; // tablica przechowujaca długośc drogi od wierzchołka startowego do danego wierzchołka
    int* p; // tablica przechowująca rodziców danych wierzchołków
    int s; // wierzcholek startowy
    int t; // wierzchołek końcowy (target)
    void init();
    void start(); // metoda rozpoczynająca algorytm (ustawienia wartosci początkowych)
    void reconstructPath(int target, int*& path, int& pathLength); // metoda potrzebna do wyświetlenia wyników - odtworzenie ścieżki

public:
    SPAlgorithm(Graph& g, int startV, int target);
    virtual ~SPAlgorithm();
    virtual void runList() override = 0;
    virtual void runMatrix() override = 0;
    void displayResult() override;
};

#endif //AIZO_PROJEKT_2_SPALGORITHM_H
