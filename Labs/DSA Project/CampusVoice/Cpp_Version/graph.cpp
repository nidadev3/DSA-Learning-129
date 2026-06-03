#include <iostream>
#include "Graph.h"
 
using namespace std;
 
// ==================== CONSTRUCTOR ====================
Graph::Graph() {
    numDept = MAX_DEPT;
 
    departments[0] = "Student Affairs";
    departments[1] = "Lab";
    departments[2] = "Hostel";
    departments[3] = "Cafe";
    departments[4] = "IT Department";
    departments[5] = "Admin Office";
 
    // Initialize all edges to 0 (no connection)
    for (int i = 0; i < MAX_DEPT; i++)
        for (int j = 0; j < MAX_DEPT; j++)
            adjMatrix[i][j] = 0;
 
    // Add campus complaint escalation edges (weighted)
    // Weight = escalation cost/time
    addEdge(0, 1, 2);  // Student Affairs <-> Lab
    addEdge(0, 2, 3);  // Student Affairs <-> Hostel
    addEdge(0, 3, 1);  // Student Affairs <-> Cafe
    addEdge(0, 5, 4);  // Student Affairs <-> Admin Office
    addEdge(1, 4, 2);  // Lab <-> IT Department
    addEdge(2, 5, 3);  // Hostel <-> Admin Office
    addEdge(3, 5, 5);  // Cafe <-> Admin Office
    addEdge(4, 5, 1);  // IT Department <-> Admin Office
}
 
void Graph::addEdge(int src, int dest, int weight) {
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight; // Undirected graph
}
 
// ==================== DISPLAY DEPARTMENTS ====================
void Graph::displayDepartments() {
    cout << "\n--- Campus Departments ---\n";
    for (int i = 0; i < numDept; i++)
        cout << i << ": " << departments[i] << endl;
}
 
// ==================== BFS ====================
// Visit all departments level by level
void Graph::BFS(int start) {
    bool visited[MAX_DEPT] = {false};
    int queue[MAX_DEPT];
    int front = 0, rear = -1;
 
    visited[start] = true;
    queue[++rear] = start;
 
    cout << "\n--- BFS Traversal (Complaint Routing) ---\n";
    cout << "Starting from: " << departments[start] << endl;
 
    while (front <= rear) {
        int node = queue[front++];
        cout << "Visited: " << departments[node] << endl;
 
        for (int i = 0; i < numDept; i++) {
            if (adjMatrix[node][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}
 
// ==================== DFS ====================
// Visit departments depth first (follow one path completely)
void Graph::DFSHelper(int node, bool visited[]) {
    visited[node] = true;
    cout << "Visited: " << departments[node] << endl;
 
    for (int i = 0; i < numDept; i++) {
        if (adjMatrix[node][i] != 0 && !visited[i])
            DFSHelper(i, visited);
    }
}
 
void Graph::DFS(int start) {
    bool visited[MAX_DEPT] = {false};
    cout << "\n--- DFS Traversal (Deep Complaint Routing) ---\n";
    cout << "Starting from: " << departments[start] << endl;
    DFSHelper(start, visited);
}
 
// ==================== DIJKSTRA ====================
// Find shortest escalation path from one department to all others
int Graph::minDistance(int dist[], bool visited[]) {
    int min = 99999, minIndex = -1;
 
    for (int v = 0; v < numDept; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
 
void Graph::dijkstra(int src) {
    int dist[MAX_DEPT];
    bool visited[MAX_DEPT];
    int parent[MAX_DEPT];
 
    for (int i = 0; i < numDept; i++) {
        dist[i]    = 99999;
        visited[i] = false;
        parent[i]  = -1;
    }
 
    dist[src] = 0;
 
    for (int count = 0; count < numDept - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
 
        for (int v = 0; v < numDept; v++) {
            if (!visited[v] && adjMatrix[u][v] != 0 &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v]   = dist[u] + adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
 
    cout << "\n--- Dijkstra: Shortest Escalation Path from " << departments[src] << " ---\n";
    for (int i = 0; i < numDept; i++) {
        if (i != src) {
            cout << departments[src] << " -> " << departments[i]
                 << " | Cost: " << dist[i] << endl;
        }
    }
}
 
// ==================== KRUSKAL'S MST ====================
// Minimum cost to connect all departments
int Graph::findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return findParent(parent, parent[i]);
}
 
void Graph::unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);
 
    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}
 
void Graph::kruskal() {
    // Collect all edges
    int edges[MAX_DEPT * MAX_DEPT][3]; // [src, dest, weight]
    int edgeCount = 0;
 
    for (int i = 0; i < numDept; i++)
        for (int j = i + 1; j < numDept; j++)
            if (adjMatrix[i][j] != 0) {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = adjMatrix[i][j];
                edgeCount++;
            }
 
    // Sort edges by weight (bubble sort)
    for (int i = 0; i < edgeCount - 1; i++)
        for (int j = 0; j < edgeCount - i - 1; j++)
            if (edges[j][2] > edges[j + 1][2]) {
                int temp0 = edges[j][0]; edges[j][0] = edges[j+1][0]; edges[j+1][0] = temp0;
                int temp1 = edges[j][1]; edges[j][1] = edges[j+1][1]; edges[j+1][1] = temp1;
                int temp2 = edges[j][2]; edges[j][2] = edges[j+1][2]; edges[j+1][2] = temp2;
            }
 
    // Kruskal's algorithm
    int parent[MAX_DEPT], rank[MAX_DEPT];
    for (int i = 0; i < numDept; i++) {
        parent[i] = i;
        rank[i]   = 0;
    }
 
    cout << "\n--- Kruskal's MST: Minimum Network to Connect All Departments ---\n";
    int totalCost = 0;
 
    for (int i = 0; i < edgeCount; i++) {
        int src  = edges[i][0];
        int dest = edges[i][1];
        int wt   = edges[i][2];
 
        int xRoot = findParent(parent, src);
        int yRoot = findParent(parent, dest);
 
        if (xRoot != yRoot) {
            cout << departments[src] << " -- " << departments[dest]
                 << " | Cost: " << wt << endl;
            totalCost += wt;
            unionSets(parent, rank, xRoot, yRoot);
        }
    }
 
    cout << "Total Minimum Cost: " << totalCost << endl;
}
 
// ==================== GRAPH MENU ====================
void Graph::graphMenu() {
    int choice;
    displayDepartments();
 
    cout << "\n===== GRAPH OPERATIONS =====\n";
    cout << "1. BFS  (Breadth First Search)\n";
    cout << "2. DFS  (Depth First Search)\n";
    cout << "3. Dijkstra (Shortest Escalation Path)\n";
    cout << "4. Kruskal  (Minimum Spanning Tree)\n";
    cout << "Enter choice: ";
    cin >> choice;
 
    if (choice == 1) {
        int start;
        cout << "Enter starting department (0-5): ";
        cin >> start;
        BFS(start);
    }
    else if (choice == 2) {
        int start;
        cout << "Enter starting department (0-5): ";
        cin >> start;
        DFS(start);
    }
    else if (choice == 3) {
        int src;
        cout << "Enter source department (0-5): ";
        cin >> src;
        dijkstra(src);
    }
    else if (choice == 4) {
        kruskal();
    }
    else {
        cout << "Invalid choice!\n";
    }
}