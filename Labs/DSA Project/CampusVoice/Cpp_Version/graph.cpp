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
 
    // Add campus complaint (weighted)
    addEdge(0, 1, 2);  
    addEdge(0, 2, 3); 
    addEdge(0, 3, 1);
    addEdge(0, 5, 4);  
    addEdge(1, 4, 2);  
    addEdge(2, 5, 3);  
    addEdge(3, 5, 5);  
    addEdge(4, 5, 1);  
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

    else {
        cout << "Invalid choice!\n";
    }
}