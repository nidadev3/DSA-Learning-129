#include "../include/Graph.h"
#include <iostream>
#include <climits>
using namespace std;

Graph::Graph(int v) {
    vertices = v;
    adjList = new EdgeNode*[vertices];
    buildingNames = new string[vertices];
    for (int i = 0; i < vertices; i++) {
        adjList[i] = nullptr;
        buildingNames[i] = "";
    }
}

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        EdgeNode* curr = adjList[i];
        while (curr != nullptr) {
            EdgeNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] adjList;
    delete[] buildingNames;
}

void Graph::addBuilding(int id, string name) {
    buildingNames[id] = name;
}

void Graph::addEdge(int src, int dest, int weight) {
    EdgeNode* newNode = new EdgeNode(dest, weight);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void Graph::BFS(int start) {
    bool* visited = new bool[vertices]();
    int* queue = new int[vertices];
    int front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    cout << "BFS: ";
    while (front < rear) {
        int node = queue[front++];
        cout << buildingNames[node] << " ";
        EdgeNode* curr = adjList[node];
        while (curr != nullptr) {
            if (!visited[curr->dest]) {
                visited[curr->dest] = true;
                queue[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
    cout << endl;
    delete[] visited;
    delete[] queue;
}

void Graph::DFS(int start) {
    bool* visited = new bool[vertices]();
    int* stack = new int[vertices];
    int top = -1;
    stack[++top] = start;
    cout << "DFS: ";
    while (top >= 0) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = true;
            cout << buildingNames[node] << " ";
            EdgeNode* curr = adjList[node];
            while (curr != nullptr) {
                if (!visited[curr->dest]) {
                    stack[++top] = curr->dest;
                }
                curr = curr->next;
            }
        }
    }
    cout << endl;
    delete[] visited;
    delete[] stack;
}

void Graph::dijkstra(int src) {
    int* dist = new int[vertices];
    bool* visited = new bool[vertices]();
    for (int i = 0; i < vertices; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < vertices - 1; i++) {
        int u = -1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;
        }
        visited[u] = true;
        EdgeNode* curr = adjList[u];
        while (curr != nullptr) {
            if (dist[u] + curr->weight < dist[curr->dest]) {
                dist[curr->dest] = dist[u] + curr->weight;
            }
            curr = curr->next;
        }
    }
    cout << "Shortest distances from " << buildingNames[src] << ":" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << buildingNames[i] << " -> " << dist[i] << endl;
    }
    delete[] dist;
    delete[] visited;
}

void Graph::display() {
    for (int i = 0; i < vertices; i++) {
        cout << buildingNames[i] << ": ";
        EdgeNode* curr = adjList[i];
        while (curr != nullptr) {
            cout << buildingNames[curr->dest] << "(" << curr->weight << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
}