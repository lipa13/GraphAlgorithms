#include "../../Headers/Graph/Graph.h"

using namespace std;

Graph::Graph():numV(0), numE(0) {}

int Graph::getNumV()
{
    return numV;
}

int Graph::getNumE()
{
    return numE;
}
