#ifndef AIZO_PROJEKT_2_INCIDENCEMATRIX_H
#define AIZO_PROJEKT_2_INCIDENCEMATRIX_H

class IncidenceMatrix
{
public:
    int** data; // dynamiczna tablica dwuwymiarowa reprezentująca macierz incydencji
    int* edgeWeigths;
    int& numV;
    int& numE;
    bool& directed;
    int edgeIndex;

    IncidenceMatrix(int& vertices, int& edges, bool& isDirected);
    void initMatrix();
    void clearMatrix();
    ~IncidenceMatrix();
    void addEdge(int start, int end, int weight);
    void display();
};

#endif //AIZO_PROJEKT_2_INCIDENCEMATRIX_H
