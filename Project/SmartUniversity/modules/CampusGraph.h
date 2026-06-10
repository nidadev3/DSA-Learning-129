#ifndef CAMPUSGRAPH_H
#define CAMPUSGRAPH_H

#include "../include/Graph.h"

class CampusGraph {
private:
    Graph graph;
public:
    CampusGraph();
    void setupCampus();
    void findShortestPath(int src);
    void exploreAll(int start);
    void displayMap();
};

#endif