#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Chel.h"
#include "Vertex.h"

class SocialGraph
{
public:
    SocialGraph();
    ~SocialGraph();
    void addVertex(Vertex*& v);
    void addEdge(Vertex*& v1, Vertex*& v2);
    void delVertex(Vertex*& v);
    void delEdge(Vertex*& v1, Vertex*& v2);
    void threeHandshakesForEverybody(int how_deep);
    void depth(Vertex*& start);
    int shortestPath(Vertex*& v1, Vertex*& v2);
private:
    bool isAlreadyHere(Vertex*& v);
    void depthInner(Vertex*& start, std::vector<Vertex*>& visited);
    void shortestPathInner(Vertex*& v1, Vertex*& v2, std::vector<Vertex*>& visited, std::vector<int>& pathes, int& path);
    void threeHandshakesForOne(Vertex*& v, std::vector<Pair*>& pairs, std::vector<Vertex*>& visited_global, int how_deep);
    std::vector<Vertex*> m_people;
};
