#include <iostream>
#include <iomanip>
#include "../../Headers/Graph/IncidenceMatrix.h"

using namespace std;

IncidenceMatrix::IncidenceMatrix(int& vertices, int& edges, bool& isDirected): numV(vertices), numE(edges), directed(isDirected), edgeIndex(0)
{
    data = nullptr;
}

void IncidenceMatrix::initMatrix()
{
    data = new int*[numV];
    edgeWeigths = new int[numE];

    for(int i=0; i<numV; i++)
    {
        data[i] = new int[numE]();
    }
}

void IncidenceMatrix::clearMatrix()
{
    for(int i=0; i<numV; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    edgeIndex=0;
}

IncidenceMatrix::~IncidenceMatrix()
{
    if(data!= nullptr)
    {
        clearMatrix();
    }
}

void IncidenceMatrix::addEdge(int start, int end, int weight)
{
    if(directed)
    {
        data[start][edgeIndex] = 1;
        data[end][edgeIndex] = -1;
    }
    else
    {
        data[start][edgeIndex] = 1;
        data[end][edgeIndex] = 1;
    }
    edgeWeigths[edgeIndex]=weight;
    edgeIndex++;
}

void IncidenceMatrix::display()
{
    cout << endl;
    cout << "Reperezentacja macierzowa\n";

    // Wyświetlanie nagłówków kolumn dla krawędzi
    cout << setw(4) << " "; // Ustawienie szerokości kolumny dla wyrównania
    for(int j = 0; j < numE; j++)
    {
        cout << setw(4) << "e" + to_string(j);
    }
    cout << endl;

    // Wyświetlanie wierszy dla wierzchołków
    for(int i = 0; i < numV; i++)
    {
        cout << setw(4) << "v" + to_string(i); // Wiersz wierzchołka
        for(int j = 0; j < numE; j++)
        {
            cout << setw(4) << data[i][j]; // Wartości macierzy
        }
        cout << endl;
    }
}