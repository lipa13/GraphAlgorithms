#include "../../Headers/Algorithms/Algorithm.h"

Algorithm::Algorithm(Graph& g) : graph(g), numV(g.getNumV()), numE(g.getNumE()) {}
