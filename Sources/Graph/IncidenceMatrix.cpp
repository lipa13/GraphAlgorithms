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
    // inicjalizacja tablic i wyzerowanie indeksu krawędzi
    data = new int*[numV];
    edgeWeights = new int[numE];
    edgeIndex=0;

    for(int i=0; i<numV; i++)
    {
        data[i] = new int[numE]();
    }
}

void IncidenceMatrix::clearMatrix()
{
    // czyszczenie pamięci zajmowanej przez tablice
    for(int i=0; i<numV; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    edgeIndex=0;
}

IncidenceMatrix::~IncidenceMatrix()
{
    if(data!=nullptr)
    {
        clearMatrix();
    }
}

void IncidenceMatrix::addEdge(int start, int end, int weight)
{
    // dodawanie krawędzi do macierzy incydencji
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
    edgeWeights[edgeIndex]=weight;
    edgeIndex++;
}

void IncidenceMatrix::display()
{
    cout << endl;
    cout << "Reperezentacja macierzowa\n";

    // wyświetlenie nagłówków kolumn dla krawędzi
    cout << setw(4) << " "; // ustawienie szerokości kolumny dla wyrównania
    for(int j=0; j<numE; j++)
    {
        cout << setw(4) << "e" + to_string(j);
    }
    cout << endl;

    // wyświetlenie wierszy dla wierzchołków
    for(int i=0; i<numV; i++)
    {
        cout << setw(4) << "v" + to_string(i); // wiersz wierzchołka
        for(int j=0; j<numE; j++)
        {
            cout << setw(4) << data[i][j]; // wartości macierzy
        }
        cout << endl;
    }
}