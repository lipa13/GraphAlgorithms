#include "../Headers/Graph.h"

using namespace std;

// Definicje statycznych zmiennych członkowskich
int Graph::numV = 0;
int Graph::numE = 0;
bool Graph::directed = false;


Graph::Graph(bool isDirected)
{
    directed = isDirected;
    numV = 0;
    numE = 0;
}

bool Graph::isEdgeCorrect(int s, int e)
{
    bool correct = true;

    if(s==e)
    {
        correct=false;
    }
    else
    {
        for(int j=0; j<listGraph.numberOfNeighbors[j]; j++)
        {
            for(int k=0; k<listGraph.numberOfNeighbors[j]; k++)
            {
                if((listGraph.adjacencyList[j][k].startV==s && listGraph.adjacencyList[j][k].endV==e) ||
                   (listGraph.adjacencyList[j][k].endV==s && listGraph.adjacencyList[j][k].startV==e))
                {
                    correct=false;
                    break;
                }
            }

            if(!correct)
            {
                break;
            }
        }
    }

    return correct;
}

void Graph::loadFromFile(string& path)
{
    /*ifstream file(path);
    if(!file)
    {
        // komunikat o niepoprawnym wczytaniu pliku
        return;
    }

    file >> numE >> numV;

    if(adjacencyList!=nullptr)
    {
        for(int i=0; i<numV; i++)
        {
            delete[] adjacencyList[i];
        }
        delete[] adjacencyList;
        delete[] numberOfNeighbors;
    }

    adjacencyList = new Edge*[numV];
    numberOfNeighbors = new int[numV]();

    for(int i=0; i<numV; i++)
    {
        adjacencyList[i] = new Edge[numV];
    }

    int start, end, weight;

    while(file >> start >> end >> weight)
    {
        addEdge(start, end, weight);
    }

    file.close();*/
}

void Graph::generateRandom(int vertices, double d)
{
    numV = vertices;
    numE = static_cast<int>(d/100*vertices*(vertices-1)/2);

    cout << numE;

    if(listGraph.adjacencyList!=nullptr)
    {
        for(int i=0; i<numV; i++)
        {
            delete[] listGraph.adjacencyList[i];
        }
        delete[] listGraph.adjacencyList;
        delete[] listGraph.numberOfNeighbors;
    }

    listGraph.adjacencyList = new Edge*[numV];
    listGraph.numberOfNeighbors = new int[numV]();

    for(int i=0; i<numV; i++)
    {
        listGraph.adjacencyList[i] = new Edge[numV-1];
    }

    // Generowanie minimalnego drzewa rozpinającego
    for (int i=1; i<numV; i++)
    {
        bool correct;
        int start, end, w;

        do
        {
            start = i;
            end = rand()%i;
            w = rand()%numV;

            correct = isEdgeCorrect(start, end);

        }while(!correct);

        listGraph.listAddEdge(start, end, w);
    }

    // Dokładanie krawędzi do określonej gęstości
    for(int i=numV-1; i<numE; i++)
    {
        bool correct;
        int start, end, w;

        do
        {
            start = rand()%numV;
            end = rand()%numV;
            w = rand()%numV;

            correct = isEdgeCorrect(start, end);

        }while(!correct);

        listGraph.listAddEdge(start, end, w);
    }
}

int Graph::getNumV()
{
    return numV;
}

int Graph::getNumE()
{
    return numE;
}
