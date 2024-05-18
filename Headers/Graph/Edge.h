#ifndef AIZO_PROJEKT_2_EDGE_H
#define AIZO_PROJEKT_2_EDGE_H

class Edge
{
public:
    int startV;
    int endV;
    int weight;

    Edge();
    Edge(int start, int end, int w);
};

#endif //AIZO_PROJEKT_2_EDGE_H
