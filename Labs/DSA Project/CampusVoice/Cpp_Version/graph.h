#ifndef GRAPH_H
#define GRAPH_H
 
#include <string>
using namespace std;
 
// Campus departments as graph nodes
// Edges = complaint can be escalated between departments
 
const int MAX_DEPT = 6;
 
// Department indices:
// 0 = Student Affairs
// 1 = Lab
// 2 = Hostel
// 3 = Cafe
// 4 = IT Department
// 5 = Admin Office
 
class Graph {
private:
    int adjMatrix[MAX_DEPT][MAX_DEPT]; // Weighted adjacency matrix
    string departments[MAX_DEPT];
    int numDept;
 
    // Dijkstra helper
    int minDistance(int dist[], bool visited[]);
 
    // Kruskal helpers
    int findParent(int parent[], int i);
    void unionSets(int parent[], int rank[], int x, int y);
 
public:
    Graph();
    void addEdge(int src, int dest, int weight);
 
    // BFS — breadth first search
    void BFS(int start);
 
    // DFS — depth first search
    void DFS(int start);
    void DFSHelper(int node, bool visited[]);
 
    // Dijkstra — shortest escalation path
    void dijkstra(int src);
 
    // Kruskal — minimum spanning tree
    void kruskal();
 
    // Display
    void displayDepartments();
    void graphMenu();
};
 
#endif