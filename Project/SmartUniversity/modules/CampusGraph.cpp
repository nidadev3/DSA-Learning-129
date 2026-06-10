#include "CampusGraph.h"
#include <iostream>
using namespace std;

CampusGraph::CampusGraph() : graph(6) {}

void CampusGraph::setupCampus() {
    graph.addBuilding(0, "Main Gate");
    graph.addBuilding(1, "Library");
    graph.addBuilding(2, "CS Block");
    graph.addBuilding(3, "Cafeteria");
    graph.addBuilding(4, "Admin Block");
    graph.addBuilding(5, "Sports Ground");

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 4, 3);
    graph.addEdge(1, 2, 4);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 2, 7);
}

void CampusGraph::findShortestPath(int src) {
    graph.dijkstra(src);
}

void CampusGraph::exploreAll(int start) {
    graph.BFS(start);
    graph.DFS(start);
}

void CampusGraph::displayMap() {
    graph.display();
}