#ifndef GRAPH_H
#define GRAPH_H

#include <string>
using namespace std;

struct EdgeNode {
    int dest;
    int weight;
    EdgeNode* next;
    EdgeNode(int d, int w) : dest(d), weight(w), next(nullptr) {}
};

class Graph {
private:
    EdgeNode** adjList;
    string* buildingNames;
    int vertices;
    void dijkstraHelper(int src);
public:
    Graph(int v);
    ~Graph();
    void addEdge(int src, int dest, int weight);
    void addBuilding(int id, string name);
    void BFS(int start);
    void DFS(int start);
    void dijkstra(int src);
    void display();
};

#endif