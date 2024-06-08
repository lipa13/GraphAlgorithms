#ifndef AIZO_PROJEKT_2_INCIDENCEMATRIX_H
#define AIZO_PROJEKT_2_INCIDENCEMATRIX_H

class IncidenceMatrix
{
public:
    int** data; // dynamiczna tablica dwuwymiarowa reprezentująca macierz incydencji
    int* edgeWeights; // tablica przechowująca wagi krawędzi
    int& numV; // liczba wierzchołków
    int& numE; // liczba krawędzi
    bool& directed; // flaga określająca, czy graf jest skierowany
    int edgeIndex; // aktualny indeks dodawanej krawędzi

    IncidenceMatrix(int& vertices, int& edges, bool& isDirected);
    void initMatrix(); // inicjalizacja macierzy incydencji
    void clearMatrix(); // czyszczenie macierzy incydencji
    ~IncidenceMatrix();
    void addEdge(int start, int end, int weight); // dodanie krawędzi do macierzy incydencji
    void display(); // wyświetlenie macierzy incydencji
};

#endif //AIZO_PROJEKT_2_INCIDENCEMATRIX_H
